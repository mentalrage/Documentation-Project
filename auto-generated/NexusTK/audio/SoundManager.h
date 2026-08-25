// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000NV
// Source by-file doc: by-file/SoundManager.md
// UID:0004UF | by-global/g_pSoundManager.md | Completion:93 | Confidence:94
#ifndef NEXUSTK_AUDIO_SOUNDMANAGER_H
#define NEXUSTK_AUDIO_SOUNDMANAGER_H

#include <windows.h>
#include <dsound.h>
#include <string.h>
#include <vector>

#include "../util/Singleton.h"
#include "../util/StringBase.h"
#include "../util/TimerHandler.h"

typedef signed long S32;
typedef unsigned long U32;

typedef void *HSAMPLE;
typedef void *HDIGDRIVER;
typedef void *HSTREAM;
typedef void *HREDBOOK;

#ifndef AILCALL
#define AILCALL __stdcall
#endif

#ifndef AILCALLBACK
#define AILCALLBACK __stdcall
#endif

typedef U32 (AILCALLBACK *AILFileOpenCallbackProc)(const char *, U32 *);
typedef void (AILCALLBACK *AILFileCloseCallbackProc)(U32);
typedef S32 (AILCALLBACK *AILFileSeekCallbackProc)(U32, S32, U32);
typedef U32 (AILCALLBACK *AILFileReadCallbackProc)(U32, void *, U32);
typedef void (AILCALLBACK *AILStreamCallbackProc)(HSTREAM);

extern "C"
{
U32 AILCALL AIL_sample_status(HSAMPLE sample);
void AILCALL AIL_set_sample_volume(HSAMPLE sample, S32 volume);
void AILCALL AIL_start_sample(HSAMPLE sample);
S32 AILCALL AIL_set_sample_file(HSAMPLE sample, const void *fileImage,
                                S32 block);
void AILCALL AIL_set_DirectSound_HWND(HDIGDRIVER driver, HWND window);
void AILCALL AIL_release_sample_handle(HSAMPLE sample);
HSAMPLE AILCALL AIL_allocate_sample_handle(HDIGDRIVER driver);
void AILCALL AIL_set_redist_directory(const char *directory);
void AILCALL AIL_close_digital_driver(HDIGDRIVER driver);
HDIGDRIVER AILCALL AIL_open_digital_driver(U32 frequency, S32 bits,
                                            S32 channels, U32 flags);
void AILCALL AIL_release_all_timers();
const char *AILCALL AIL_last_error();
S32 AILCALL AIL_set_preference(U32 preference, S32 value);
void AILCALL AIL_shutdown();
S32 AILCALL AIL_get_DirectSound_info(
    HDIGDRIVER driver,
    LPDIRECTSOUND *directSound,
    LPDIRECTSOUNDBUFFER *primaryBuffer);
void AILCALL AIL_redbook_close(HREDBOOK redbook);
U32 AILCALL AIL_redbook_tracks(HREDBOOK redbook);
void AILCALL AIL_init_sample(HSAMPLE sample);
void AILCALL AIL_redbook_track_info(HREDBOOK redbook, U32 track,
                                     U32 *start, U32 *end);
U32 AILCALL AIL_redbook_position(HREDBOOK redbook);
U32 AILCALL AIL_redbook_play(HREDBOOK redbook, U32 start, U32 end);
void AILCALL AIL_redbook_stop(HREDBOOK redbook);
void AILCALL AIL_redbook_pause(HREDBOOK redbook);
void AILCALL AIL_redbook_resume(HREDBOOK redbook);
void AILCALL AIL_set_file_callbacks(
    AILFileOpenCallbackProc openCallback,
    AILFileCloseCallbackProc closeCallback,
    AILFileSeekCallbackProc seekCallback,
    AILFileReadCallbackProc readCallback);
AILStreamCallbackProc AILCALL AIL_register_stream_callback(
    HSTREAM stream, AILStreamCallbackProc callback);
U32 AILCALL AIL_stream_status(HSTREAM stream);
void AILCALL AIL_set_stream_loop_count(HSTREAM stream, S32 loopCount);
void AILCALL AIL_set_stream_volume(HSTREAM stream, S32 volume);
void AILCALL AIL_startup();
void AILCALL AIL_set_digital_master_volume(HDIGDRIVER driver, S32 volume);
void AILCALL AIL_pause_stream(HSTREAM stream, S32 paused);
void AILCALL AIL_start_stream(HSTREAM stream);
void AILCALL AIL_close_stream(HSTREAM stream);
HSTREAM AILCALL AIL_open_stream(HDIGDRIVER driver, const char *filename,
                                S32 streamMemory);
HREDBOOK AILCALL AIL_redbook_open_drive(S32 drive);
S32 AILCALL AIL_redbook_set_volume(HREDBOOK redbook, S32 volume);
}

class SoundManager;

extern SoundManager *g_pSoundManager;

// UID:0000DG | by-class/SoundManager.md | Completion:93 | Confidence:94
typedef mystr::StringBase<char, mystr::mychar_traits<char> > SoundPathString;

class SimpleUString;
class Application;
class BaramApp;

struct SoundSampleSlot
{
    HSAMPLE handle;
    int playVolumeScale;
};

class SoundManager : public Singleton<SoundManager>, public TimerHandler
{
public:
    SoundManager();
    virtual ~SoundManager();
    virtual bool OnTimer(int timerId, int arg0, int arg1);

    void LoadTrackListFromFile(const SimpleUString &playlistName);
    void StopStreamAndResetZone(int fadeOutMilliseconds);
    HDIGDRIVER GetDigitalDriver() const;
    void PlayTrackByIndex(int trackIndex, int volumeScale, int loopCount);
    void PlayMusicByZone(int zoneId, int fallbackTrackIndex,
                         int volumeScale, int loopCount);
    void StopStream(int fadeOutMilliseconds);
    int GetStreamVolume() const;
    void SetStreamVolume(unsigned int volume);
    bool IsPlaybackEnabled() const;
    void MuteMusic();
    void UnmuteMusic();
    void SetStreamPaused(bool paused);
    void PlayNextTrack();
    void PlayNextPlaylistTrack();
    void PlaySample(unsigned int sampleId, int playVolumeScale);
    void PlayEffect(unsigned int sampleId, int playVolumeScale)
    {
        PlaySample(sampleId, playVolumeScale);
    }
    int GetSampleVolume() const;
    void SetSampleVolume(unsigned int volume);
    bool IsSoundEffectsEnabled() const;
    void EnableSoundEffects();
    void DisableSoundEffects();
    void SuspendSoundEffectsForApplicationDeactivate();
    void RestoreSoundEffectsAfterAppFocus();
    LPDIRECTSOUND GetDirectSound();
    void ScanMusicDirectory(
        const mystr::StringBase<wchar_t,
                                mystr::mychar_traits<wchar_t> > &directoryPath,
        bool randomize,
        bool recursive);
    void OpenRedbookDrive(unsigned short driveLetter);
    void CloseRedbookDevice();
    void PlayRedbookTrack(unsigned int trackNumber);
    bool AdvanceRedbookTrack();
    bool RewindRedbookTrack();
    void SetRedbookPaused(bool paused);
    void RestartMusic(int fadeOutMilliseconds);
    void ReinitializeAudioDriver();

private:
    friend class Application;
    friend class BaramApp;

    void SetDigitalAudioMuted(bool muted);
    void StopRedbookAndCancelTrackTimer();
    void ReinitializeAudioDriverAndResumeMusic();
    void ShutdownAudioDriver();
    static void AILCALLBACK AILStreamEndCallback(HSTREAM stream);

    bool m_musicOptionEnabled;
    bool m_soundEffectsOptionEnabled;
    HDIGDRIVER m_digitalDriver;
    bool m_musicPlaybackEnabled;
    int m_streamVolume;
    HSTREAM m_stream;
    HREDBOOK m_redbookHandle;
    int m_redbookTrackCount;
    int m_redbookOrderIndex;
    int m_currentRedbookTrack;
    int m_currentTrackVolumeScale;
    int m_currentTrackIndex;
    int m_currentLoopCount;
    int m_pendingTrackIndex;
    int m_pendingTrackVolumeScale;
    int m_pendingLoopCount;
    bool m_musicAdvanceRequested;
    bool m_soundEffectsEnabled;
    int m_soundEffectVolume;
    SoundSampleSlot m_sampleSlots[8];
    void *m_samplePayloads[1000];
    std::vector<SoundPathString> m_localMusicPaths;
    unsigned char m_redbookOrder[100];
    int m_currentMusicZoneId;
    std::vector<SoundPathString> m_zoneMusicTracks;
    bool m_randomizeZonePlaylist;
    bool m_zonePlaylistActive;
};

#endif
