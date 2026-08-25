// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000NV
// Source by-file doc: by-file/SoundManager.md
// UID:0004UF | by-global/g_pSoundManager.md | Completion:93 | Confidence:94
class SoundManager;

SoundManager *g_pSoundManager = 0;


// UID:0004WV | by-item/SoundManagerMilesCallbackDeclarations.md | Completion:93 | Confidence:94
#include "SoundManager.h"

static U32 AILCALLBACK AILFileOpenCallback(const char *filename, U32 *fileHandle);
static void AILCALLBACK AILFileCloseCallback(U32 fileHandle);
static S32 AILCALLBACK AILFileSeekCallback(U32 fileHandle, S32 offset, U32 origin);
static U32 AILCALLBACK AILFileReadCallback(U32 fileHandle, void *buffer, U32 bytes);

// UID:0004UG | by-memory/0x00579a30-0x00579ca5.SoundManagerConstructor.md | Completion:92 | Confidence:94
SoundManager::SoundManager()
    : m_digitalDriver(0),
      m_stream(0),
      m_redbookHandle(0),
      m_redbookTrackCount(0),
      m_redbookOrderIndex(0),
      m_currentRedbookTrack(0),
      m_currentTrackIndex(0),
      m_pendingTrackIndex(-1)
{
    m_musicPlaybackEnabled = g_pConfig->m_musicEnabled;
    m_musicOptionEnabled = m_musicPlaybackEnabled;
    m_soundEffectsOptionEnabled = m_soundEffectsEnabled;
    m_streamVolume = 100;
    m_soundEffectsEnabled = g_pConfig->m_soundEffectsEnabled;
    m_soundEffectVolume = 100;
    m_currentTrackVolumeScale = 100;
    m_musicAdvanceRequested = false;

    ReinitializeAudioDriver();

    if (m_digitalDriver != 0) {
        m_musicPlaybackEnabled = g_pConfig->m_musicEnabled;
        m_streamVolume = g_pConfig->m_musicVolume;
        m_soundEffectsEnabled = g_pConfig->m_soundEffectsEnabled;
        m_soundEffectVolume = g_pConfig->m_soundVolume;
        m_currentTrackVolumeScale = 100;
        AIL_set_preference(42, g_pConfig->m_soundFrequency);
    }

    m_zonePlaylistActive = false;
    m_currentMusicZoneId = 0;
    m_zoneMusicTracks.clear();

    if (m_digitalDriver != 0) {
        for (int sampleId = 0; sampleId < 1000; ++sampleId) {
            SimpleUString sampleName(L"%03d.wav", sampleId);

            if (HasDATEntry(sampleName.c_str())) {
                DATFile sampleFile;
                sampleFile.Open(sampleName.c_str());
                m_samplePayloads[sampleId] = sampleFile.GetDataPointer();
                sampleFile.Close();
            } else {
                m_samplePayloads[sampleId] = 0;
            }
        }
    }

    ScanMusicDirectory(g_pConfig->m_musicFolderPath,
                       g_pConfig->m_randomizeMusicOrder != 0,
                       true);
}

// UID:0004UH | by-memory/0x00579cb0-0x00579dbf.SoundManagerDestructor.md | Completion:92 | Confidence:94
SoundManager::~SoundManager()
{
    enum { kRedbookTrackEndedTimer = 0x504e4354 };

    if (m_digitalDriver != 0) {
        for (int slot = 0; slot < 8; ++slot) {
            if (m_sampleSlots[slot].handle != 0)
                AIL_release_sample_handle(m_sampleSlots[slot].handle);
        }
    }

    if (m_stream != 0) {
        AIL_close_stream(m_stream);
        m_stream = 0;
    }

    if (m_digitalDriver != 0) {
        AIL_close_digital_driver(m_digitalDriver);
        m_digitalDriver = 0;
    }

    AIL_release_all_timers();
    AIL_shutdown();

    if (m_redbookHandle != 0) {
        AIL_redbook_stop(m_redbookHandle);
        CancelTimer(kRedbookTrackEndedTimer);
        AIL_redbook_close(m_redbookHandle);
        m_redbookHandle = 0;
        m_redbookTrackCount = 0;
        m_redbookOrderIndex = 0;
        m_currentRedbookTrack = 0;
        CancelTimer(kRedbookTrackEndedTimer);
    }
}

// UID:0004RW | by-memory/0x0057a260-0x0057a330.SoundManagerStopStream.md | Completion:92 | Confidence:94
void SoundManager::StopStream(int fadeOutMilliseconds)
{
    enum {
        kRedbookTrackEndedTimer = 0x504e4354,
        kStreamStopTimer = 0x534d736d,
        kStreamFadeStepTimer = 0x534d7374
    };

    if (m_digitalDriver != 0) {
        RemovePendingTimers();

        if (m_stream != 0) {
            if (fadeOutMilliseconds <= 0) {
                m_currentTrackIndex = 0;
                AIL_close_stream(m_stream);
                m_stream = 0;
            } else {
                m_currentTrackIndex = -abs(m_currentTrackIndex);

                if (m_streamVolume != 0) {
                    const int stepCount = fadeOutMilliseconds / m_streamVolume;
                    int accumulatedDelay = fadeOutMilliseconds;

                    for (int step = 1; step <= stepCount; ++step) {
                        ScheduleTimer(kStreamFadeStepTimer,
                                      accumulatedDelay / stepCount,
                                      m_streamVolume - m_streamVolume * step / stepCount,
                                      0);
                        accumulatedDelay += fadeOutMilliseconds;
                    }
                }

                ScheduleTimer(kStreamStopTimer, fadeOutMilliseconds + 200, 0, 0);
            }
        }
    }

    if (m_redbookHandle != 0) {
        AIL_redbook_stop(m_redbookHandle);
        CancelTimer(kRedbookTrackEndedTimer);
    }
}

// UID:0004RX | by-memory/0x0057a330-0x0057a334.SoundManagerGetStreamVolume.md | Completion:92 | Confidence:94
int SoundManager::GetStreamVolume() const
{
    return m_streamVolume;
}

// UID:0004RY | by-memory/0x0057a340-0x0057a3ce.SoundManagerSetStreamVolume.md | Completion:92 | Confidence:94
void SoundManager::SetStreamVolume(unsigned int volume)
{
    const unsigned int boundedVolume = volume <= 100 ? volume : 100;
    m_streamVolume = boundedVolume;
    g_pConfig->m_musicVolume = boundedVolume;

    if (m_digitalDriver != 0 && m_stream != 0) {
        const unsigned int streamVolume = m_musicPlaybackEnabled
            ? 127 * boundedVolume * m_currentTrackVolumeScale / 10000
            : 0;
        AIL_set_stream_volume(m_stream, streamVolume);
    }

    if (m_redbookHandle != 0) {
        AIL_redbook_set_volume(
            m_redbookHandle,
            m_musicPlaybackEnabled ? 127 * boundedVolume / 100 : 0);
    }
}

// UID:0004RZ | by-memory/0x0057a3d0-0x0057a3d4.SoundManagerIsPlaybackEnabled.md | Completion:92 | Confidence:94
bool SoundManager::IsPlaybackEnabled() const
{
    return m_musicPlaybackEnabled;
}

// UID:0004S1 | by-memory/0x0057a3e0-0x0057a3fe.SoundManagerMuteMusic.md | Completion:92 | Confidence:94
void SoundManager::MuteMusic()
{
    g_pMidiPlayer->DisableMidiPlayback();
    m_musicPlaybackEnabled = false;
    SetStreamVolume(m_streamVolume);
}

// UID:0004S3 | by-memory/0x0057a400-0x0057a44e.SoundManagerUnmuteMusic.md | Completion:92 | Confidence:94
void SoundManager::UnmuteMusic()
{
    g_pMidiPlayer->EnableMidiPlayback();
    m_musicPlaybackEnabled = true;
    m_musicOptionEnabled = true;

    if (m_currentTrackIndex != 0 && AIL_stream_status(m_stream) != 4) {
        const int trackIndex = m_currentTrackIndex;
        const int volumeScale = m_currentTrackVolumeScale;
        const int loopCount = m_currentLoopCount;
        m_currentTrackIndex = 0;
        PlayTrackByIndex(trackIndex, volumeScale, loopCount);
    }

    SetStreamVolume(m_streamVolume);
}

// UID:0004S4 | by-memory/0x0057a4e0-0x0057a506.SoundManagerSetStreamPaused.md | Completion:92 | Confidence:94
void SoundManager::SetStreamPaused(bool paused)
{
    AIL_pause_stream(m_stream, paused ? 1 : 0);
}

// UID:0004S5 | by-memory/0x0057a510-0x0057a555.SoundManagerPlayNextTrack.md | Completion:92 | Confidence:94
void SoundManager::PlayNextTrack()
{
    int nextTrackIndex = m_currentTrackIndex;
    const int trackCount = static_cast<int>(m_localMusicPaths.size());

    if (m_musicAdvanceRequested || !g_pConfig->m_repeatMusic)
        ++nextTrackIndex;

    if (trackCount < nextTrackIndex)
        nextTrackIndex = 1;

    PlayTrackByIndex(nextTrackIndex, 100, 1);
    m_musicAdvanceRequested = false;
}

// UID:0004S6 | by-memory/0x0057a560-0x0057a5b1.SoundManagerPlayNextPlaylistTrack.md | Completion:92 | Confidence:93
void SoundManager::PlayNextPlaylistTrack()
{
    if (!m_zonePlaylistActive)
        return;

    const int trackCount = static_cast<int>(m_zoneMusicTracks.size());
    const int currentIndex = m_randomizeZonePlaylist
        ? rand() % trackCount
        : m_currentTrackIndex;

    PlayTrackByIndex(trackCount >= currentIndex + 1 ? currentIndex + 1 : 1,
                     100,
                     1);
}

// UID:0004S7 | by-memory/0x0057a5c0-0x0057a6bf.SoundManagerPlaySample.md | Completion:92 | Confidence:94
void SoundManager::PlaySample(unsigned int sampleId, int playVolumeScale)
{
    if (!m_soundEffectsEnabled || sampleId > 999 || m_digitalDriver == 0)
        return;

    int selectedSlot = 0;
    while (selectedSlot < 8) {
        const HSAMPLE handle = m_sampleSlots[selectedSlot].handle;
        if (handle != 0 && AIL_sample_status(handle) == 2)
            break;
        ++selectedSlot;
    }

    if (selectedSlot >= 8)
        selectedSlot = 7;

    SoundSampleSlot selected;
    GetMemoryMan()->MemmoveWrapper(
        &selected, &m_sampleSlots[selectedSlot], sizeof(SoundSampleSlot));
    GetMemoryMan()->MoveBufferMemory(
        &m_sampleSlots[1],
        &m_sampleSlots[0],
        selectedSlot * sizeof(SoundSampleSlot));
    GetMemoryMan()->MemmoveWrapper(
        &m_sampleSlots[0], &selected, sizeof(SoundSampleSlot));

    if (m_sampleSlots[0].handle == 0)
        return;

    AIL_init_sample(m_sampleSlots[0].handle);
    if (m_sampleSlots[0].handle == 0 || m_samplePayloads[sampleId] == 0)
        return;

    AIL_set_sample_file(m_sampleSlots[0].handle, m_samplePayloads[sampleId], 0);
    m_sampleSlots[0].playVolumeScale = playVolumeScale;
    AIL_set_sample_volume(
        m_sampleSlots[0].handle,
        127 * playVolumeScale * m_soundEffectVolume / 10000);

    if (m_soundEffectsEnabled)
        AIL_start_sample(m_sampleSlots[0].handle);
}

// UID:0004S8 | by-memory/0x0057a6c0-0x0057a6c4.SoundManagerGetSampleVolume.md | Completion:92 | Confidence:94
int SoundManager::GetSampleVolume() const
{
    return m_soundEffectVolume;
}

// UID:0004S9 | by-memory/0x0057a6d0-0x0057a749.SoundManagerSetSampleVolume.md | Completion:92 | Confidence:94
void SoundManager::SetSampleVolume(unsigned int volume)
{
    const unsigned int boundedVolume = volume <= 100 ? volume : 100;
    if (m_digitalDriver == 0 || boundedVolume == static_cast<unsigned int>(m_soundEffectVolume))
        return;

    m_soundEffectVolume = boundedVolume;
    g_pConfig->m_soundVolume = boundedVolume;

    for (int i = 0; i < 8; ++i) {
        if (m_sampleSlots[i].handle != 0) {
            const unsigned int sampleVolume = m_soundEffectsEnabled
                ? 127 * m_sampleSlots[i].playVolumeScale * m_soundEffectVolume / 10000
                : 0;
            AIL_set_sample_volume(m_sampleSlots[i].handle, sampleVolume);
        }
    }
}

// UID:0004SA | by-memory/0x0057a750-0x0057a754.SoundManagerIsSoundEffectsEnabled.md | Completion:92 | Confidence:94
bool SoundManager::IsSoundEffectsEnabled() const
{
    return m_soundEffectsEnabled;
}

// UID:0004SB | by-memory/0x0057a760-0x0057a76f.SoundManagerEnableSoundEffects.md | Completion:92 | Confidence:94
void SoundManager::EnableSoundEffects()
{
    if (!m_soundEffectsEnabled) {
        m_soundEffectsEnabled = true;
        m_soundEffectsOptionEnabled = true;
    }
}

// UID:0004SC | by-memory/0x0057a770-0x0057a775.SoundManagerDisableSoundEffects.md | Completion:92 | Confidence:94
void SoundManager::DisableSoundEffects()
{
    m_soundEffectsEnabled = false;
}

// UID:0004SD | by-memory/0x0057a780-0x0057a78f.SoundManagerSuspendSoundEffectsForApplicationDeactivate.md | Completion:92 | Confidence:94
void SoundManager::SuspendSoundEffectsForApplicationDeactivate()
{
    const bool wasEnabled = m_soundEffectsEnabled;
    m_soundEffectsEnabled = false;
    if (wasEnabled)
        m_soundEffectsOptionEnabled = true;
}

// UID:0004SE | by-memory/0x0057a790-0x0057a7a9.SoundManagerRestoreSoundEffectsAfterAppFocus.md | Completion:92 | Confidence:94
void SoundManager::RestoreSoundEffectsAfterAppFocus()
{
    if (m_soundEffectsOptionEnabled) {
        m_soundEffectsOptionEnabled = false;
        if (!m_soundEffectsEnabled) {
            m_soundEffectsEnabled = true;
            m_soundEffectsOptionEnabled = true;
        }
    }
}

// UID:0004SF | by-memory/0x0057a7b0-0x0057a7d3.SoundManagerSetDigitalAudioMutedRaw.md | Completion:91 | Confidence:92
void SoundManager::SetDigitalAudioMuted(bool muted)
{
    if (m_digitalDriver != 0)
        AIL_set_digital_master_volume(m_digitalDriver, muted ? 0 : 127);
}

// UID:0004SG | by-memory/0x0057a7e0-0x0057a7f9.SoundManagerGetDirectSound.md | Completion:92 | Confidence:94
LPDIRECTSOUND SoundManager::GetDirectSound()
{
    LPDIRECTSOUND directSound;
    AIL_get_DirectSound_info(0, &directSound, 0);
    return directSound;
}

// UID:0004SH | by-memory/0x0057a800-0x0057a88e.SoundManagerOnTimer.md | Completion:92 | Confidence:94
bool SoundManager::OnTimer(int timerId, int arg0, int arg1)
{
    enum {
        kRedbookTrackEndedTimer = 0x504e4354,
        kStreamStopTimer = 0x534d736d,
        kStreamFadeStepTimer = 0x534d7374
    };

    if (timerId == kRedbookTrackEndedTimer) {
        PlayRedbookTrack(m_currentRedbookTrack + 1);
        return true;
    }

    if (timerId == kStreamStopTimer) {
        m_currentTrackIndex = 0;
        if (m_stream != 0) {
            AIL_close_stream(m_stream);
            m_stream = 0;
        }

        if (m_pendingTrackIndex != -1) {
            PlayTrackByIndex(m_pendingTrackIndex,
                             m_pendingTrackVolumeScale,
                             m_pendingLoopCount);
            m_pendingTrackIndex = -1;
        }
        return true;
    }

    if (timerId == kStreamFadeStepTimer && m_stream != 0) {
        const int storedVolume = m_streamVolume;
        SetStreamVolume(m_musicPlaybackEnabled ? arg0 : 0);
        m_streamVolume = storedVolume;
    }

    (void)arg1;
    return true;
}

// UID:0001IA | by-memory/0x0057a890-0x0057afce.SoundManagerMusicDirectoryScan.md | Completion:92 | Confidence:94
typedef mystr::StringBase<char, mystr::mychar_traits<char> > SoundPathString;

void SoundManager::ScanMusicDirectory(
    const mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > &directoryPath,
    bool randomize,
    bool recursive)
{
    m_localMusicPaths.clear();

    if (directoryPath.length() == 0)
        return;

    std::vector<SoundPathString> musicPaths;
    SoundPathString rootDirectory(directoryPath);
    std::deque<SoundPathString> directories;
    directories.push_back(rootDirectory);

    while (!directories.empty()) {
        SoundPathString currentDirectory;
        currentDirectory = directories.front();
        directories.pop_front();

        WIN32_FIND_DATAA findData;
        SoundPathString searchPath = currentDirectory + "\\*";
        HANDLE findHandle = FindFirstFileA(searchPath.c_str(), &findData);

        if (findHandle != INVALID_HANDLE_VALUE) {
            do {
                SoundPathString fileName(findData.cFileName);

                if (fileName.ToLower().EndsWithAnsi(".mp3") &&
                    (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0) {
                    musicPaths.push_back(currentDirectory + "/" + fileName);
                }

                if (recursive &&
                    fileName.c_str()[0] != '.' &&
                    (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0) {
                    directories.push_back(currentDirectory + "/" + fileName);
                }
            } while (FindNextFileA(findHandle, &findData));
        }
    }

    m_localMusicPaths.reserve(musicPaths.size());

    if (randomize) {
        while (!musicPaths.empty()) {
            const std::vector<SoundPathString>::size_type index =
                rand() % musicPaths.size();
            m_localMusicPaths.push_back(musicPaths[index]);
            musicPaths.erase(musicPaths.begin() + index);
        }
    } else {
        m_localMusicPaths.swap(musicPaths);
    }
}

// UID:0004X1 | by-memory/0x0057afd0-0x0057b011.SoundManagerReinitializeAudioDriverAndResumeMusicRaw.md | Completion:90 | Confidence:91
void SoundManager::ReinitializeAudioDriverAndResumeMusic()
{
    ReinitializeAudioDriver();

    if (g_pConfig->m_musicSourceMode == 1) {
        const int trackIndex = m_currentTrackIndex;
        m_currentTrackIndex = 0;
        PlayTrackByIndex(trackIndex, 100, 1);
    } else if (g_pConfig->m_musicSourceMode == 0) {
        PlayMusicByZone(g_activeMapPane->m_zoneMusicId,
                        g_activeMapPane->m_zoneMusicFallbackTrackIndex,
                        g_activeMapPane->m_zoneMusicVolumeScale,
                        0);
    }
}

// UID:0003ZB | by-memory/0x0057b020-0x0057b152.SoundManagerOpenRedbookDrive.md | Completion:88 | Confidence:92
void SoundManager::OpenRedbookDrive(uint16_t driveLetter)
{
    enum { kRedbookTrackEndedTimer = 0x504e4354, kMaxRedbookTracks = 100 };

    if (m_redbookHandle != NULL) {
        AIL_redbook_stop(m_redbookHandle);
        CancelTimer(kRedbookTrackEndedTimer);
        AIL_redbook_close(m_redbookHandle);

        m_redbookHandle = NULL;
        m_redbookTrackCount = 0;
        m_redbookOrderIndex = 0;
        m_currentRedbookTrack = 0;

        CancelTimer(kRedbookTrackEndedTimer);
    }

    m_redbookHandle = AIL_redbook_open_drive(driveLetter);
    SetStreamVolume(m_musicVolume);

    if (m_redbookHandle == NULL)
        return;

    m_redbookTrackCount = AIL_redbook_tracks(m_redbookHandle);
    memset(m_redbookOrder, 0, sizeof(m_redbookOrder));

    const int trackCount = m_redbookTrackCount;
    if (g_pConfig->randomizeMusicOrder) {
        uint8_t remaining[kMaxRedbookTracks] = {0};
        for (int index = 0; index < trackCount && index < kMaxRedbookTracks; ++index)
            remaining[index] = static_cast<uint8_t>(index + 1);

        int remainingCount = trackCount;
        for (int outputIndex = 0; outputIndex < trackCount && outputIndex < kMaxRedbookTracks; ++outputIndex) {
            int selectedRemaining = rand() % remainingCount;
            for (int index = 0; index < trackCount && index < kMaxRedbookTracks; ++index) {
                if (remaining[index] == 0)
                    continue;

                if (selectedRemaining-- == 0) {
                    m_redbookOrder[outputIndex] = remaining[index];
                    remaining[index] = 0;
                    --remainingCount;
                    break;
                }
            }
        }
    } else {
        for (int index = 0; index < trackCount && index < kMaxRedbookTracks; ++index)
            m_redbookOrder[index] = static_cast<uint8_t>(index + 1);
    }
}

// UID:0003ZC | by-memory/0x0057b160-0x0057b1b0.SoundManagerCloseRedbookDevice.md | Completion:88 | Confidence:92
void SoundManager::CloseRedbookDevice()
{
    enum { kRedbookTrackEndedTimer = 0x504e4354 };

    if (m_redbookHandle == NULL)
        return;

    AIL_redbook_stop(m_redbookHandle);
    CancelTimer(kRedbookTrackEndedTimer);
    AIL_redbook_close(m_redbookHandle);

    m_redbookHandle = NULL;
    m_redbookTrackCount = 0;
    m_redbookOrderIndex = 0;
    m_currentRedbookTrack = 0;

    CancelTimer(kRedbookTrackEndedTimer);
}

// UID:0003ZD | by-memory/0x0057b1b0-0x0057b23f.SoundManagerPlayRedbookTrack.md | Completion:88 | Confidence:92
void SoundManager::PlayRedbookTrack(uint32_t trackNumber)
{
    enum { kRedbookTrackEndedTimer = 0x504e4354 };

    CancelTimer(kRedbookTrackEndedTimer);

    if (trackNumber <= m_redbookTrackCount) {
        uint32_t start = 0;
        uint32_t end = 0;

        m_currentRedbookTrack = trackNumber;
        AIL_redbook_track_info(m_redbookHandle, trackNumber, &start, &end);
        AIL_redbook_play(m_redbookHandle, start, end);
        ScheduleTimer(kRedbookTrackEndedTimer, end - start, 0, 0);
        return;
    }

    if (m_redbookTrackCount != 0 && g_pConfig->repeatMusic) {
        PlayRedbookTrack(1);
        return;
    }

    m_currentRedbookTrack = 0;
}

// UID:0003ZE | by-memory/0x0057b240-0x0057b2b7.SoundManagerAdvanceRedbookTrack.md | Completion:88 | Confidence:92
bool SoundManager::AdvanceRedbookTrack()
{
    enum { kRedbookTrackEndedTimer = 0x504e4354 };

    ++m_redbookOrderIndex;

    if (g_pConfig->repeatMusic) {
        if (m_redbookTrackCount != 0) {
            m_redbookOrderIndex %= m_redbookTrackCount;
            PlayRedbookTrack(m_redbookOrder[m_redbookOrderIndex]);
            return true;
        }

        m_redbookOrderIndex = 0;
    } else {
        if (m_redbookOrderIndex < m_redbookTrackCount) {
            PlayRedbookTrack(m_redbookOrder[m_redbookOrderIndex]);
            return true;
        }

        m_redbookOrderIndex = m_redbookTrackCount;
    }

    AIL_redbook_stop(m_redbookHandle);
    CancelTimer(kRedbookTrackEndedTimer);
    return false;
}

// UID:0003ZF | by-memory/0x0057b2c0-0x0057b2df.SoundManagerRewindRedbookTrack.md | Completion:88 | Confidence:92
bool SoundManager::RewindRedbookTrack()
{
    if (m_redbookOrderIndex == 0)
        return false;

    --m_redbookOrderIndex;
    PlayRedbookTrack(m_redbookOrder[m_redbookOrderIndex]);
    return true;
}

// UID:0003ZG | by-memory/0x0057b2e0-0x0057b34a.SoundManagerSetRedbookPaused.md | Completion:88 | Confidence:92
void SoundManager::SetRedbookPaused(bool paused)
{
    enum { kRedbookTrackEndedTimer = 0x504e4354 };

    if (paused) {
        CancelTimer(kRedbookTrackEndedTimer);
        AIL_redbook_pause(m_redbookHandle);
        return;
    }

    uint32_t start = 0;
    uint32_t end = 0;
    AIL_redbook_track_info(m_redbookHandle, m_currentRedbookTrack, &start, &end);
    AIL_redbook_resume(m_redbookHandle);

    const uint32_t position = AIL_redbook_position(m_redbookHandle);
    ScheduleTimer(kRedbookTrackEndedTimer, end - position, 0, 0);
}

// UID:0003ZH | by-memory/0x0057b350-0x0057b36a.SoundManagerStopRedbookAndCancelTrackTimerRaw.md | Completion:88 | Confidence:90
void SoundManager::StopRedbookAndCancelTrackTimer()
{
    enum { kRedbookTrackEndedTimer = 0x504e4354 };

    AIL_redbook_stop(m_redbookHandle);
    CancelTimer(kRedbookTrackEndedTimer);
}

// UID:0003ZI | by-memory/0x0057b370-0x0057b3ec.SoundManagerRestartMusic.md | Completion:87 | Confidence:91
void SoundManager::RestartMusic(int fadeOutMilliseconds)
{
    enum {
        kMusicSourceDisabled = 0,
        kMusicSourceStream = 1,
        kMusicSourceRedbook = 2
    };

    StopStream(fadeOutMilliseconds);

    switch (g_pConfig->musicSourceMode) {
    case kMusicSourceRedbook:
        if (m_redbookTrackCount != 0)
            PlayRedbookTrack(m_redbookOrder[0]);
        break;

    case kMusicSourceStream:
        CloseRedbookDevice();
        PlayTrackByIndex(1, 100, true);
        break;

    case kMusicSourceDisabled:
    default:
        CloseRedbookDevice();
        if (m_zonePlaylistActive)
            PlayTrackByIndex(1, 100, true);
        break;
    }
}

// UID:0001IC | by-memory/0x0057b490-0x0057b5f0.SoundManagerReinitializeAudioDriver.md | Completion:93 | Confidence:94
void SoundManager::ReinitializeAudioDriver()
{
    if (m_stream != NULL) {
        AIL_close_stream(m_stream);
        m_stream = NULL;
    }

    if (m_digitalDriver != NULL) {
        AIL_close_digital_driver(m_digitalDriver);
        m_digitalDriver = NULL;
    }

    AIL_release_all_timers();
    AIL_shutdown();

    char *currentDirectory = _getcwd(NULL, 256);
    SoundPathString milesDirectory(currentDirectory);
    free(currentDirectory);
    AIL_set_redist_directory(milesDirectory.c_str());

    AIL_startup();

    const int sampleRate = g_pConfig->m_soundFrequency == 1 ? 22050 : 44100;
    m_digitalDriver = AIL_open_digital_driver(sampleRate, 16, 2, 1);
    if (m_digitalDriver == NULL)
        m_digitalDriver = AIL_open_digital_driver(sampleRate, 16, 2, 0);

    AIL_set_DirectSound_HWND(m_digitalDriver,
                             g_pApplication->GetMainWindowHandle());

    if (m_digitalDriver != NULL) {
        AIL_set_file_callbacks(AILFileOpenCallback,
                               AILFileCloseCallback,
                               AILFileSeekCallback,
                               AILFileReadCallback);
        m_stream = NULL;
        memset(m_sampleSlots, 0, sizeof(m_sampleSlots));

        for (int slot = 0; slot < 8; ++slot)
            m_sampleSlots[slot].handle = AIL_allocate_sample_handle(m_digitalDriver);
    }
}

// UID:0004WW | by-memory/0x0057b5f0-0x0057b62a.SoundManagerShutdownAudioDriverRaw.md | Completion:91 | Confidence:92
void SoundManager::ShutdownAudioDriver()
{
    if (m_stream != NULL) {
        AIL_close_stream(m_stream);
        m_stream = NULL;
    }

    if (m_digitalDriver != NULL) {
        AIL_close_digital_driver(m_digitalDriver);
        m_digitalDriver = NULL;
    }

    AIL_release_all_timers();
    AIL_shutdown();
}

// UID:0000TU | by-memory/0x0057b630-0x0057b72b.AILFileOpenCallback.md | Completion:93 | Confidence:94
static U32 AILCALLBACK AILFileOpenCallback(const char *filename, U32 *fileHandle)
{
    SoundPathString ansiPath(filename);
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > path(ansiPath);
    File *file;

    if (HasDATEntry(path.c_str())) {
        file = new DATFile;
    } else {
        if (!PathExistsViaStat(path.c_str()))
            return 0;
        file = new StdioFile;
    }

    file->Open(path.c_str());
    *fileHandle = reinterpret_cast<U32>(file);
    return 1;
}

// UID:0004WX | by-memory/0x0057b730-0x0057b74a.AILFileCloseCallback.md | Completion:92 | Confidence:94
static void AILCALLBACK AILFileCloseCallback(U32 fileHandle)
{
    delete reinterpret_cast<File *>(fileHandle);
}

// UID:0004WY | by-memory/0x0057b750-0x0057b793.AILFileSeekCallback.md | Completion:93 | Confidence:94
static S32 AILCALLBACK AILFileSeekCallback(U32 fileHandle, S32 offset, U32 origin)
{
    File *file = reinterpret_cast<File *>(fileHandle);
    int seekOrigin;

    switch (origin) {
    case 0: seekOrigin = SEEK_SET; break;
    case 1: seekOrigin = SEEK_CUR; break;
    case 2: seekOrigin = SEEK_END; break;
    default: seekOrigin = origin; break;
    }

    file->Seek(offset, seekOrigin);
    return file->GetPosition();
}

// UID:0004WZ | by-memory/0x0057b7a0-0x0057b7e8.AILFileReadCallback.md | Completion:93 | Confidence:94
static U32 AILCALLBACK AILFileReadCallback(U32 fileHandle, void *buffer, U32 bytes)
{
    File *file = reinterpret_cast<File *>(fileHandle);
    const U32 remaining = static_cast<U32>(file->GetSize() - file->GetPosition());

    if (bytes >= remaining)
        bytes = remaining;

    file->Read(buffer, bytes);
    return bytes;
}

// UID:0004X0 | by-memory/0x0057b7f0-0x0057b853.AILStreamEndCallback.md | Completion:92 | Confidence:93
void AILCALLBACK SoundManager::AILStreamEndCallback(HSTREAM stream)
{
    enum {
        kPlayNextTrackMessage = 0x407,
        kPlayNextPlaylistTrackMessage = 0x408
    };

    if (g_pConfig->m_musicSourceMode == 1) {
        PostMessageA(g_pApplication->GetMainWindowHandle(),
                     kPlayNextTrackMessage, 0, 0);
    }

    if (g_pConfig->m_musicSourceMode == 0 &&
        g_pSoundManager->m_zonePlaylistActive) {
        PostMessageA(g_pApplication->GetMainWindowHandle(),
                     kPlayNextPlaylistTrackMessage, 0, 0);
    }
}

// UID:0000DG | by-class\SoundManager.md | Completion:93 | Confidence:94 | Empty Emitter Marker

// UID:0001I7 | by-memory\0x005797b0-0x0057a25c.SoundManagerMusicSelection.md | Completion:88 | Confidence:91 | Empty Emitter Marker
