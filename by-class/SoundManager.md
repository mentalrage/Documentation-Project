*** UID:0000DG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000NV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
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
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# SoundManager

## UID0001IC Driver And Miles Callback Source Integration - 2026-07-24

- UID0003D9 complete-header reconciliation adds `friend class Application` because comparative vtable proof now owns `OnActivate`/`OnDeactivate` on `Application`; those exact bodies directly access private music runtime fields. `friend class BaramApp` remains for dated derived-source compatibility and other BaramApp consumers, but it no longer substitutes for the current Application-owned access route.

- The complete `SoundManager` declaration emits only through `RECONSTRUCTION_H CODE`; the CPP channel is exactly blank. UID0004UF opens the shared guard and supplies all complete prerequisites before this position-10 class tail; this page closes the guard after one class definition while exact by-memory children remain the sole out-of-line CPP definitions.
- `ReinitializeAudioDriverAndResumeMusic()` and `ShutdownAudioDriver()` are retained private methods. Their raw bodies at `[0x0057afd0,0x0057b011)` and `[0x0057b5f0,0x0057b62a)` have complete, unique SoundManager behavior despite no direct xrefs or address-pointer route, so zero-route evidence limits original-name confidence rather than suppressing source.
- The existing public `ReinitializeAudioDriver()` declaration remains the exact modeled `[0x0057b490,0x0057b5f0)` method. The private resume bridge precedes the Redbook group in binary address order but is emitted at source position `390`; the public reinitializer and private shutdown method emit at positions `500` and `510` after the Redbook children.
- The Miles open/close/seek/read callbacks remain file-static and are declared by [UID:0004WV][SoundManagerMilesCallbackDeclarations](by-item/SoundManagerMilesCallbackDeclarations.md) before all uses. The stream-completion callback is instead the private static `SoundManager::AILStreamEndCallback(HSTREAM)` declared here: this preserves the Miles no-`this` `void __stdcall(HSTREAM)` ABI while legally permitting its direct read of private `m_zonePlaylistActive`. UID0004WV remains canonically file-owned at position `15`, before constructor position `20`; exact callback by-memory pages own the sole definitions.
- The former H-channel `[[CHILDREN]]` marker is superseded by the deterministic split: UID0004UF opens the standalone header, this page emits the complete class and closes `#endif`, and CPP children retain their established emitter positions without duplicating declarations.

## Current Complete Declaration And Source Union

- Current score/route: `93/94`, canonical owner [UID:0000NV][SoundManager](by-file/SoundManager.md), emitter UID0000NV, position `10`, reconstructable true.
- The managed declaration is the authoritative natural-alignment x86 source shape. Constructor allocation `0x10ac`, field extents, vtable, both vector triplets, eight sample slots, 1000 payload pointers, Redbook order storage, and final bytes converge on `sizeof(SoundManager)==0x10ac` without explicit reserved/padding fields.
- `SoundManager` directly derives from `Singleton<SoundManager>` then `TimerHandler`; old-MSVC EBO places the empty Singleton view at `+0x04` while polymorphic TimerHandler remains the primary physical base at `+0x00`. Vtable slot `0x0062ce80` routes to [UID:0004SH][0x0057a800-0x0057a88e.SoundManagerOnTimer](by-memory/0x0057a800-0x0057a88e.SoundManagerOnTimer.md) with exact `OnTimer(int,int,int)` contract.
- `friend class Application` is required because current UID0002GJ/UID0002GK comparative-vtable ownership places the caller-owned focus chunks on `Application`, where they directly access private SoundManager state. `friend class BaramApp` remains for derived app-shell compatibility and historical source shape. The app chunks stay Application.cpp source and are not duplicate SoundManager children.
- `PlaySample` is the sole out-of-line SFX body. The inline `PlayEffect` forwarding alias preserves accepted UI caller vocabulary while producing the same direct call and no duplicate binary method.
- Private `SetDigitalAudioMuted` emits through UID0004SF with explicit zero-route provenance. Private `StopRedbookAndCancelTrackTimer` remains the accepted retained UID0003ZH body.

## Standalone Header Dependency Closure

- UID0004UF's position-zero H preamble includes exactly `<windows.h>`, `<dsound.h>`, `<string.h>`, `<vector>`, `../util/Singleton.h`, `../util/StringBase.h`, and `../util/TimerHandler.h`. This page therefore uses complete bases, complete `StringBase`/traits, and complete `std::vector<SoundPathString>` member types rather than its former incomplete template forward substitutes.
- The same preamble supplies era-compatible `S32`/`U32`, four opaque Miles handles, guarded `AILCALL`/`AILCALLBACK`, five callback procedure types, and all 37 observed `extern "C"` AIL declarations. Windows SDK types provide `HWND` and DirectSound pointers.
- This class tail uses `unsigned short` for `OpenRedbookDrive` and `unsigned int` for `PlayRedbookTrack`, avoiding undeclared fixed-width typedef assumptions while retaining exact x86 widths.
- Repository and import inspection rejects an unavailable Miles SDK header, a new unowned shim, copied proprietary source, implicit declarations, and PCH-only type availability. The local declaration block is limited to the executable-observed ABI; unconsumed return spellings remain the reason dependency confidence is strong rather than original-proof.

### Exact Natural-Alignment Layout

| Offset | Source member / region | Evidence |
| --- | --- | --- |
| `+0x0000` | primary TimerHandler physical base | constructor and vtable route; source declaration follows Singleton |
| `+0x0004` | empty Singleton source-base view under old-MSVC EBO | RTTI PMD `+4`; overlaps the first derived-state byte without adding object size |
| `+0x0004/+0x0005` | music/SFX option or deferred mirrors | constructor, app-focus, settings paths |
| `+0x0006-0x0007` | natural alignment only | next pointer at +0x08 |
| `+0x0008` | m_digitalDriver | Miles driver calls |
| `+0x000c` | m_musicPlaybackEnabled | runtime music gates |
| `+0x0010/+0x0014/+0x0018` | stream volume, stream, Redbook handle | playback methods |
| `+0x001c-0x003c` | Redbook/current/pending integer tuples | selection, stop, timer, restart |
| `+0x0040/+0x0041` | advance/runtime SFX bytes | next-track and sample gates |
| `+0x0044` | master SFX volume | getter/setter/formula |
| `+0x0048-0x0087` | SoundSampleSlot[8] | PlaySample/raw rotation/driver setup |
| `+0x0088-0x1027` | m_samplePayloads[1000] | DAT payload lookup |
| `+0x1028-0x1033` | m_localMusicPaths vector | scanner/local selection |
| `+0x1034-0x1097` | m_redbookOrder[100] | Redbook track ordering |
| `+0x1098` | current music zone ID | playlist selection |
| `+0x109c-0x10a7` | m_zoneMusicTracks vector | zone playlist |
| `+0x10a8/+0x10a9` | randomize/active playlist bytes | playlist next |
| `+0x10aa-0x10ab` | natural tail alignment | total 0x10ac |

### Current Child Source Order

- Playback children [UID:0004RW][0x0057a260-0x0057a330.SoundManagerStopStream](by-memory/0x0057a260-0x0057a330.SoundManagerStopStream.md) through [UID:0004SH][0x0057a800-0x0057a88e.SoundManagerOnTimer](by-memory/0x0057a800-0x0057a88e.SoundManagerOnTimer.md) occupy positions `100-290` in exact address order.
- Scanner [UID:0001IA][0x0057a890-0x0057afce.SoundManagerMusicDirectoryScan](by-memory/0x0057a890-0x0057afce.SoundManagerMusicDirectoryScan.md) occupies position `300` and closes the playback parent indentation with `Nested:-4`.
- Redbook children UID0003ZB-UID0003ZI occupy positions `400-470` in address order. Their accepted bodies/scores remain unchanged.
- Broad UID0001I7/UID0001I8/UID0001IB/UID0001IC pages remain aggregate/index documentation and do not duplicate these exact source bodies.

## Historical Pre-Declaration Status

- Confidence: strong for class ownership, audio source placement, current IDA method anchors, non-emitting aggregate/index separation, standard `std::vector<SoundPathString>`/`std::deque<SoundPathString>` source cause, and explicit MidiPlayer/timer-wrapper exclusions; medium-high for exact field names.
- Likely source module: [UID:0000NV][SoundManager](by-file/SoundManager.md)
- Current relevant range: `0x005797b0-0x0057bf6e`
- Main address doc: [UID:0001I8][0x005797b0-0x0057bf6e.SoundManagerAudioHelperCluster](by-memory/0x005797b0-0x0057bf6e.SoundManagerAudioHelperCluster.md)
- Evidence basis: live IDA MCP checks against `NexusTK.exe` plus linked project documentation.

## Responsibility

`SoundManager` is the client audio manager. It initializes Miles Sound System state, caches DAT-backed WAV sound effects, selects zone music from DAT-backed `.LST`, `.LSR`, and `.MP3` entries, supports user music-directory scanning, and manages stream/CD playback state.

## Key Data

Current IDA-backed docs identify:

- `m_digitalDriver` / `this+0x8`: Miles AIL digital driver handle, returned by `GetDigitalDriver`.
- `m_musicEnabled` or `m_streamPlaybackEnabled` / `this+0xc`: stream/music playback enable flag; exact config-label spelling remains tied to config-layout cleanup.
- `m_musicVolume` / `this+0x10`: stream/music volume or stream-control value.
- `m_stream` / `this+0x14`: active AIL stream handle.
- `m_redbookHandle` / `this+0x18`: Miles Redbook/CD handle (`HREDBOOK` working type).
- `m_redbookTrackCount` / `this+0x1c`: count from `AIL_redbook_tracks`.
- `m_redbookOrderIndex` / `this+0x20`: current index into the Redbook play-order table.
- `m_currentRedbookTrack` / `this+0x24`: currently playing Redbook track number used by timer/resume paths.
- `m_lastFadeOutMillis`, `m_currentTrackIndex`, `m_currentLoopCount`, `m_pendingTrackIndex`, `m_pendingFadeOutMillis`, and `m_pendingLoopCount` / `this+0x28-0x3c`: stream fade/current/pending restart tuple.
- `m_musicAdvanceRequested` / `this+0x40`: next-track/advance request flag used by UI and local/stream playback paths; exact final source spelling remains open.
- `m_soundEffectsEnabled` / `this+0x41`: inferred source-facing name for the sound-effect enabled flag. `PlaySample` gates on this byte at `0x0057a5c9` and rechecks before `AIL_start_sample`; older docs may still call this `mbr_0x41`.
- `m_soundEffectVolume` / `this+0x44`: inferred source-facing name for the sound-effect volume. `PlaySample` multiplies this value by the per-play slot scale and `0x7f`, then divides by `0x2710` / 10000 before `AIL_set_sample_volume`; `m_sampleVolume` remains an acceptable alternate spelling if later source evidence prefers it. Older docs may still call this `mbr_0x44`.
- `m_sampleSlots` / `this+0x48-0x87`: eight 8-byte `SoundSampleSlot` entries, total `0x40` / 64 bytes. Slot dword 0 is a Miles `HSAMPLE handle`; slot dword 1 is inferred `playVolumeScale` / `volumeScale`, with `playVolumeScale` preferred because live `PlaySample` writes the per-play scale to `this+0x4c` before computing volume. [UID:0001IC][0x0057b490-0x0057b5f0.SoundManagerReinitializeAudioDriver](by-memory/0x0057b490-0x0057b5f0.SoundManagerReinitializeAudioDriver.md) clears this 64-byte array at `0x0057b5a1-0x0057b5b0` and allocates eight `HSAMPLE` handles at `0x0057b5be-0x0057b5d4`; [UID:0001I9][0x0057a260-0x0057a88e.SoundManagerPlaybackControls](by-memory/0x0057a260-0x0057a88e.SoundManagerPlaybackControls.md) and raw no-entry [UID:0003ZJ][0x0057b3f0-0x0057b48d.SoundManagerRotateReusableSampleSlotRaw](by-memory/0x0057b3f0-0x0057b48d.SoundManagerRotateReusableSampleSlotRaw.md) rotate/reinitialize the same slots.
- `m_samplePayloads` / `this+0x88 + 4*sampleId`: inferred DAT-backed sample payload pointer table for IDs `0..999`; `m_sampleData` remains an acceptable alternate. This table is separate from `m_sampleSlots`, and raw [UID:0003ZJ][0x0057b3f0-0x0057b48d.SoundManagerRotateReusableSampleSlotRaw](by-memory/0x0057b3f0-0x0057b48d.SoundManagerRotateReusableSampleSlotRaw.md) does not access it.
- `m_redbookOrder` / `this+0x1034`: 100-byte Redbook play-order table filled sequentially or randomly from `g_pConfig->randomizeMusicOrder`.
- `m_localMusicPaths` / `this+0x1028-0x1030`: `std::vector<SoundPathString>` used by source-ready [UID:0001IA][0x0057a890-0x0057afce.SoundManagerMusicDirectoryScan](by-memory/0x0057a890-0x0057afce.SoundManagerMusicDirectoryScan.md) for scanned loose local music paths. `SoundPathString` is the ANSI project `StringBase` specialization; the adjacent `SoundPathVector` pages document compiler-generated vector instantiations, not a handwritten member type.
- `m_currentMusicZoneId` / `this+0x1098`: current DAT zone/playlist ID.
- `m_zoneMusicTracks` / `this+0x109c-0x10a4`: distinct `std::vector<SoundPathString>` filled from `.LST`/`.LSR` DAT entries. The calls at `0x00579f9a` and `0x0057a214` are compiler lowering of `m_zoneMusicTracks.clear()` documented by non-emitting [UID:0001IF][0x0057bf40-0x0057bf6e.SoundPathVectorClear](by-memory/0x0057bf40-0x0057bf6e.SoundPathVectorClear.md), not calls to a custom source method.
- `m_randomizeZonePlaylist` / `this+0x10a8`: `.LSR` randomized playlist selector flag.
- `m_zonePlaylistActive` / `this+0x10a9`: active DAT playlist mode flag; the direct `%08d.MP3` paths at `0x00579f93` and `0x0057a20d` clear this byte before the compiler-emitted `m_zoneMusicTracks.clear()` path.

The key offsets above were rechecked with `tools/int_convert.py` on 2026-06-13: `0x1028` is 4136, `0x1098` is 4248, `0x109c` is 4252, `0x10a4` is 4260, and `0x10a9` is 4265 (Verified with int_convert.py).

Field names above are the best current source-facing names from the B002 SoundManager music-selection pass. They remain working names only where the final config layout, Miles typedef layer, or full class-layout pass may choose a more exact original spelling.

## DAT-Backed Resources

The constructor at `0x00579a30` scans `%03d.wav` entries for IDs `0..999` through [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md), opens matching entries with `DATFile`, and caches data pointers from `DATFile::GetDataPointer`.

`PlayMusicByZone` at `0x0057a0b0` checks `%08d.LST`, `%08d.LSR`, and `%08d.MP3` through [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md). `.LST` is the sequential playlist path, `.LSR` is the randomized playlist path, and direct `.MP3` is the single-track fallback. `LoadTrackListFromFile` at `0x005797b0` opens playlist files through `DATFile` and converts line-based track IDs into `%08d.MP3` names.

The DAT-backed path coexists with local music-directory scanning through `FindFirstFileA` and `g_strMusicExtension`.

## Important Methods

| Address | Current name | Notes |
| --- | --- | --- |
| `0x005797b0` | `LoadTrackListFromFile` | Reads DAT-backed `.LST`/`.LSR` playlist files into the playlist vector. |
| `0x00579950` | `StopStreamAndResetZone` | Stops stream playback and resets current zone/music-selection state for map/effect transitions. |
| `0x00579a30` | constructor | Initializes audio state, Miles driver state, and DAT-backed sound-effect pointer table. |
| `0x00579dc0` | `GetDigitalDriver` | Four-byte accessor returning `this+0x8`, used by startup-logo/Bink audio setup. |
| `0x0057a0b0` | `PlayMusicByZone` | Selects zone music from DAT-backed playlists or direct MP3 entries. |
| `0x0057a260-0x0057a88e` | playback controls | Stream stop, volume, mute/unmute, pause, next track, sample playback, SFX state, DirectSound access, and timer dispatch. |
| `0x0057a890-0x0057afce` | `ScanMusicDirectory(const WideStringBase&, bool randomize, bool recursive)` | Clears `m_localMusicPaths`, converts the wide root to ANSI `SoundPathString`, scans loose local `.mp3` files with `FindFirstFileA`/`FindNextFileA`, optionally recurses through `std::deque`, then random-extracts or swaps a `std::vector` result. The original body has no `FindClose` call. |
| `0x0057b020-0x0057b48d` | Redbook and adjacent sample-slot helpers | Split across [UID:0003ZB][0x0057b020-0x0057b152.SoundManagerOpenRedbookDrive](by-memory/0x0057b020-0x0057b152.SoundManagerOpenRedbookDrive.md), [UID:0003ZC][0x0057b160-0x0057b1b0.SoundManagerCloseRedbookDevice](by-memory/0x0057b160-0x0057b1b0.SoundManagerCloseRedbookDevice.md), [UID:0003ZD][0x0057b1b0-0x0057b23f.SoundManagerPlayRedbookTrack](by-memory/0x0057b1b0-0x0057b23f.SoundManagerPlayRedbookTrack.md), [UID:0003ZE][0x0057b240-0x0057b2b7.SoundManagerAdvanceRedbookTrack](by-memory/0x0057b240-0x0057b2b7.SoundManagerAdvanceRedbookTrack.md), [UID:0003ZF][0x0057b2c0-0x0057b2df.SoundManagerRewindRedbookTrack](by-memory/0x0057b2c0-0x0057b2df.SoundManagerRewindRedbookTrack.md), [UID:0003ZG][0x0057b2e0-0x0057b34a.SoundManagerSetRedbookPaused](by-memory/0x0057b2e0-0x0057b34a.SoundManagerSetRedbookPaused.md), raw/unpromoted but emitted private [UID:0003ZH][0x0057b350-0x0057b36a.SoundManagerStopRedbookAndCancelTrackTimerRaw](by-memory/0x0057b350-0x0057b36a.SoundManagerStopRedbookAndCancelTrackTimerRaw.md), [UID:0003ZI][0x0057b370-0x0057b3ec.SoundManagerRestartMusic](by-memory/0x0057b370-0x0057b3ec.SoundManagerRestartMusic.md), and raw no-entry [UID:0003ZJ][0x0057b3f0-0x0057b48d.SoundManagerRotateReusableSampleSlotRaw](by-memory/0x0057b3f0-0x0057b48d.SoundManagerRotateReusableSampleSlotRaw.md). The `0003ZH` helper emits as `SoundManager::StopRedbookAndCancelTrackTimer()` while preserving zero-route evidence; the last helper is sample/SFX behavior despite physical adjacency and remains non-emitting. |
| `0x0057b490` | `ReinitializeAudioDriver` | Restarts Miles, configures DirectSound HWND, registers file callbacks, and allocates sample handles. |
| `0x0057bb30` | `ScalarDeletingDestructor` | Compiler-generated deleting destructor wrapper for `SoundManager`. |

[UID:0001I8][0x005797b0-0x0057bf6e.SoundManagerAudioHelperCluster](by-memory/0x005797b0-0x0057bf6e.SoundManagerAudioHelperCluster.md) is the broad non-emitting class-family index for the rows above and adjacent helper islands. It is not itself a method body or class C++ emitter.

## Ownership Notes

- This class should stay in an audio module, not the archive module.
- DAT dependencies are API-level resource lookups, similar to rendering callers of [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md).
- Application activation and options/config UI call into `SoundManager`, but those callers should remain in their feature modules.
- [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md) is a HUD/UI consumer for hotkeys and status text; it should not be folded into the audio engine source.
- [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md) owns the WinMM MIDI singleton and [UID:0000RM][g_pMidiPlayer](by-global/g_pMidiPlayer.md). `SoundManager` can call MIDI pause/resume behavior, but should not absorb MIDI buffer/reset implementation. Current IDA `analyze_function 0x00525b10` shows WinMM cleanup with `midiOutUnprepareHeader`, `GlobalUnlock`, and `GlobalFree`, with callers inside the MIDI reset/destructor family rather than SoundManager.
- [UID:0000DI][SoundPathVector](by-class/SoundPathVector.md) is retained as a non-emitting documentation projection for old-MSVC `std::vector<SoundPathString>` instantiations caused by this translation unit. Its exact children preserve reserve/grow/copy/destroy/clear binary evidence, but the human source is typed container use in SoundManager policy. [UID:0001IF][0x0057bf40-0x0057bf6e.SoundPathVectorClear](by-memory/0x0057bf40-0x0057bf6e.SoundPathVectorClear.md) is therefore compiler lowering of `m_zoneMusicTracks.clear()` at `0x00579f9a` and `0x0057a214`, not a source-authored class method.
- Current IDA `analyze_function 0x00597610` confirms a 22-byte (`0x16`) wrapper (Verified with int_convert.py) forwarding to `sub_597B80`, with broad non-audio callers. These generic [UID:0001K9][0x00597610-0x00597645.TimerHandlerWrappers](by-memory/0x00597610-0x00597645.TimerHandlerWrappers.md) attach to TimerMgr behavior and should not be migrated with this class.

## Live IDA Evidence

Checked on 2026-06-13 through IDA MCP session `a001_goal2_0002UM` against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`:

- Server health reported image base `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
- `lookup_funcs` reconfirmed the representative SoundManager method anchors: `0x005797b0`, `0x00579950`, `0x00579a30`, `0x00579cb0`, `0x00579dc0`, `0x00579e30`, `0x0057a0b0`, `0x0057a260`, `0x0057a800`, `0x0057a890`, `0x0057b020`, `0x0057b490`, `0x0057b630`, `0x0057b7f0`, `0x0057b860`, `0x0057bb30`, `0x0057bd90`, and `0x0057bf40`.
- `xrefs_to 0x0062ce7c` confirms the `SoundManager` vtable is written only from the constructor at `0x00579a86`, destructor at `0x00579cdb`, and scalar deleting destructor at `0x0057bb62`.
- `analyze_function 0x005797b0` confirms DAT-backed playlist loading, `%08d.MP3` formatting, and `SoundPathVector::GrowAndInsert` at `0x005798e9`; callers are `PlayMusicByZone` at `0x0057a178` and `0x0057a1cc`.
- `analyze_function 0x00579a30` confirms singleton publication to `g_pSoundManager`, vtable install, Miles driver initialization through `0x0057b490`, DAT-backed `%03d.wav` probing through `HasDATEntry`, and local music-directory scanning.
- B002's 2026-06-17 source-quality pass confirms `0x00579dc0-0x00579dc4` is `SoundManager::GetDigitalDriver() const`, a four-byte accessor returning `[ecx+8]`, with a startup-logo/Bink caller. It is not destructor tail and not the later DirectSound bridge.
- `analyze_function 0x0057a0b0` confirms `%08d.MP3`, `%08d.LST`, and `%08d.LSR` zone selection through `HasDATEntry`, with `SoundPathVector::Clear` at `0x0057a214`.
- `analyze_function 0x0057a800` confirms the timer event dispatch belongs to SoundManager behavior, while the timer cancellation wrappers themselves remain generic TimerMgr wrappers.
- `analyze_function 0x0057a890` reconfirmed the local music-directory scanner as a `0x73e` / 1854-byte function (Verified with int_convert.py), exact half-open end `0x0057afce`, using a wide input, ANSI StringBase path entries, Win32 `FindFirstFileA`/`FindNextFileA`, standard deque/vector lowering, optional recursion, unseeded `rand()` extraction, and a nonrandom swap. Target callee/xref/EH checks found no `FindClose` call, which the source-ready method intentionally preserves.
- `analyze_function 0x0057b630` confirms the Miles file-open callback bridges incoming paths to `DATFile` when `HasDATEntry` succeeds and to loose-file handling otherwise.
- `analyze_function 0x0057bf40` confirms the path-vector clear helper is a `0x2e` / 46-byte helper (Verified with int_convert.py) called only from `0x00579f9a` and `0x0057a214` in SoundManager music-selection paths.
- B004's 2026-06-27 live MCP support pass on session `80de0a67` confirms the broad UID0001I8 aggregate has 53 modeled functions before `0x0057bf70`, while the class-owned evidence remains exact-child based: constructor `0x00579a30` publishes `g_pSoundManager`, installs the vtable, calls `ReinitializeAudioDriver`, preloads `%03d.wav`, and calls local music scanning; destructor `0x00579cb0` releases sample/stream/digital/Redbook/Miles state and destroys two path vectors; scalar deleting destructor `0x0057bb30` is compiler glue referenced from the SoundManager vtable.
- The same B004 pass rechecked sample and driver evidence: live `PlaySample` gates on `this+0x41`, rejects IDs above `999`, rotates eight `this+0x48-0x87` slots, loads payloads from `this+0x88 + 4*sampleId`, stores the per-play scale at `this+0x4c`, computes volume from `this+0x44`, and calls `AIL_start_sample`; `ReinitializeAudioDriver` closes/restarts Miles state, registers callbacks `0x57b630`, `0x57b730`, `0x57b750`, and `0x57b7a0`, clears the sample-slot array, and allocates eight sample handles.
- B013's 2026-06-28 current MCP pass for [UID:0001IF][0x0057bf40-0x0057bf6e.SoundPathVectorClear](by-memory/0x0057bf40-0x0057bf6e.SoundPathVectorClear.md) confirms the direct `%08d.MP3` fallback route: `PlayTrackByIndex` clears `m_zonePlaylistActive` at `0x00579f93` and calls `SoundPathVector::Clear()` at `0x00579f9a`; `PlayMusicByZone` clears the same flag at `0x0057a20d`, clears `m_zoneMusicTracks` at `0x0057a214`, then delegates to `PlayTrackByIndex`.

## Source-Quality Decisions And Remaining Limits

- B002's SoundManager music-selection pass resolves the major generated-name issue in this class: `0x00579dc0` is a digital-driver accessor and should be documented as `SoundManager::GetDigitalDriver() const`.
- `m_digitalDriver`, `m_stream`, `m_musicVolume`, `m_currentTrackIndex`, `m_currentMusicZoneId`, `m_localMusicPaths`, `m_zoneMusicTracks`, `m_randomizeZonePlaylist`, and `m_zonePlaylistActive` are the best current source-facing field names for the music-selection path. Exact config field spelling and final Miles typedef aliases remain synchronized with config/import-layer cleanup, so class confidence stays below final-audit level.
- B003's 2026-06-18 Redbook split resolves the major Redbook/source-shape issue: the historical [UID:0001IB][0x0057b020-0x0057b48a.SoundManagerRedbookPlayback](by-memory/0x0057b020-0x0057b48a.SoundManagerRedbookPlayback.md) range is a non-emitting family index, while seven exact child methods emit first-draft C++ through this class. B015's target-specific reanalysis promotes raw `0x0057b350` to an emitted private `SoundManager::StopRedbookAndCancelTrackTimer()` helper despite no recovered entry route; it preserves zero relative/VA/RVA/raw pointer/vtable/jump-table/timer-callback route evidence as a confidence cap. Raw `0x0057b3f0` remains no-entry sample/SFX slot rotation with blank formal C++.
- The Redbook/playback pass also resolves `this+0x48-0x87` as eight 8-byte `SoundSampleSlot` entries, with `HSAMPLE` in dword 0 and per-play volume/scale in dword 1; payload pointers are separate at `this+0x88 + 4*sampleId`. This replaces the older generic `sample-slot state` wording.
- B009's 2026-06-19 [UID:0003ZJ][0x0057b3f0-0x0057b48d.SoundManagerRotateReusableSampleSlotRaw](by-memory/0x0057b3f0-0x0057b48d.SoundManagerRotateReusableSampleSlotRaw.md) source-quality implementation keeps the raw helper SoundManager-owned but non-emitting: the exact `0x0057b3f0-0x0057b48d` body is `0x9d` / 157 bytes between `0x0057b3ec-0x0057b3f0` four `0xcc` bytes and `0x0057b48d-0x0057b490` three `0xcc` bytes, has no direct rel32/rel8 branch, VA/RVA/file-offset pointer, vtable, jump-table, or interior-entry route, and duplicates only the slot-selection/rotation/`AIL_init_sample` subset of live `PlaySample`. The best descriptive method name is `SoundManager::RotateReusableSampleSlot()`, but formal C++ stays blank because no caller route proves it should appear in generated output.
- B009 rejected Redbook/CD, `RestartMusic`, `ReinitializeAudioDriver`, `PlaySample`, MemoryMan/util, padding, and compiler/runtime-artifact ownership for [UID:0003ZJ][0x0057b3f0-0x0057b48d.SoundManagerRotateReusableSampleSlotRaw](by-memory/0x0057b3f0-0x0057b48d.SoundManagerRotateReusableSampleSlotRaw.md). Physical Redbook adjacency is weaker than the sample-slot evidence; `RestartMusic` is separated by four `0xcc` bytes and has no call/fallthrough; `ReinitializeAudioDriver` is separated by three `0xcc` bytes and only allocates the `HSAMPLE` handles consumed later; MemoryMan helpers are incidental copy wrappers.
- Historical custom `SoundPathVector` ownership/emission is superseded. The helper island remains documented under [UID:0000DI][SoundPathVector](by-class/SoundPathVector.md), but its vector exact children are non-reconstructable compiler/STL lowering with blank emitters and bodies. SoundManager owns the policy methods and the two typed vector fields; the compiler regenerates reserve, growth, copy, destruction, erase, and clear support from those methods.
- UID0001IA source placement is `NexusTK/audio/SoundManager.cpp` through file UID0000NV, while direct semantic ownership is this class. Its method accepts a const UTF-16 StringBase reference, uses ANSI StringBase entries, preserves the binary's missing `FindClose`, and leaves SEH/security-cookie/container cleanup to the compiler.
- B004's UID0001I8 implementation makes the broad aggregate's source-output policy explicit: the aggregate is `RECONSTRUCTABLE:FALSE` with blank emitters because one C++ block would duplicate exact SoundManager child methods, include raw helper children with different output decisions, cross the direct SoundPathVector owner boundary, and hand-port AIL callback/deleting-destructor/helper interleaves. This does not weaken SoundManager class ownership; it prevents the class source from being polluted by an overbroad parent emitter.

## Cross-References

- [UID:0000NV][SoundManager](by-file/SoundManager.md)
- [UID:0001I8][0x005797b0-0x0057bf6e.SoundManagerAudioHelperCluster](by-memory/0x005797b0-0x0057bf6e.SoundManagerAudioHelperCluster.md)
- [UID:0001I7][0x005797b0-0x0057a25c.SoundManagerMusicSelection](by-memory/0x005797b0-0x0057a25c.SoundManagerMusicSelection.md)
- [UID:0001I9][0x0057a260-0x0057a88e.SoundManagerPlaybackControls](by-memory/0x0057a260-0x0057a88e.SoundManagerPlaybackControls.md)
- [UID:0001IA][0x0057a890-0x0057afce.SoundManagerMusicDirectoryScan](by-memory/0x0057a890-0x0057afce.SoundManagerMusicDirectoryScan.md)
- [UID:0001IB][0x0057b020-0x0057b48a.SoundManagerRedbookPlayback](by-memory/0x0057b020-0x0057b48a.SoundManagerRedbookPlayback.md)
- [UID:0001IC][0x0057b490-0x0057b5f0.SoundManagerReinitializeAudioDriver](by-memory/0x0057b490-0x0057b5f0.SoundManagerReinitializeAudioDriver.md)
- [UID:0000DI][SoundPathVector](by-class/SoundPathVector.md)
- [UID:0001ID][0x0057b860-0x0057bf6e.SoundPathVector](by-memory/0x0057b860-0x0057bf6e.SoundPathVector.md)
- [UID:0001IF][0x0057bf40-0x0057bf6e.SoundPathVectorClear](by-memory/0x0057bf40-0x0057bf6e.SoundPathVectorClear.md)
- [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md)
- [UID:0000RM][g_pMidiPlayer](by-global/g_pMidiPlayer.md)
- [UID:0001K9][0x00597610-0x00597645.TimerHandlerWrappers](by-memory/0x00597610-0x00597645.TimerHandlerWrappers.md)
- [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md)
- [UID:0000LN][MusicControlDialog](by-file/MusicControlDialog.md)
- [UID:0000UB][DATAudioResources](by-item/DATAudioResources.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)
- [UID:0001Q8][client_audio](by-meta/client_audio.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md)
- [UID:00012E][0x0049c700-0x0049c71d.HasDATEntry](by-memory/0x0049c700-0x0049c71d.HasDATEntry.md)

## Changes

- 2026-08-24 B009 UID0000NX callback: Raised completion `92` to `93`, preserved confidence `94`, replaced incomplete StringBase forward substitutes with the complete UID0004UF prerequisites, changed Redbook parameter spellings to era-compatible built-in integer types, removed the obsolete H child marker, emitted the complete class tail, and closed the standalone SoundManager header guard. Added the exact seven-include/local-Miles dependency rationale and rejected unavailable SDK/shim/PCH routes.
- 2026-06-13 A003 Goal 2 class-quality pass: Raised confidence from `80` to `86`; completion remains `86`.
  - Before: the class page relied on stale generated-source provenance and kept confidence capped despite the parent file, SoundPathVector helper, and major memory children clearing the 85/85 gate.
  - After: the page records current-session IDA evidence for method anchors, vtable writes, DAT-backed music/sample policy, SoundPathVector callers, local music scanning, Miles file callbacks, MidiPlayer separation, and TimerMgr wrapper exclusion. Direct parent [UID:0000NV][SoundManager](by-file/SoundManager.md) remains correct and already clears `90/85`.
  - Evidence: IDA MCP `server_health`, `lookup_funcs`, `xrefs_to`, and `analyze_function` on 2026-06-13 against session `a001_goal2_0002UM`; key offset and size conversions were verified with `tools/int_convert.py`.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `86`, confidence `80`.
- Evidence: the page documents the audio-manager responsibility, DAT/resource paths, major methods, playback subsystems, owned helper relationships, generic timer-wrapper exclusion, and cross-subsystem references; confidence remains capped by exact field names and unresolved Miles/sample-path details.
- 2026-06-05: Marked reconstructable and attached to [UID:0000NV][SoundManager](by-file/SoundManager.md).
- Evidence: live IDA MCP `lookup_funcs` confirms representative audio-manager method anchors from `0x005797b0` through `0x0057bb30`, including playlist loading, construction, zone music selection, playback controls, directory scanning, driver reinitialization, and destructor paths. The class (`86/80`) and parent file (`90/82`) meet the 80/80 parent gate; C++ remains blank under the final-code threshold.
- 2026-06-13 C001 Goal 2 barrier repair:
  - Score unchanged at `86/80`.
  - Evidence: live IDA MCP confirmed the by-memory aggregate endpoint for the contiguous audio helper cluster extends through `0x0057bf6e` so it contains the SoundPathVector helper range. This does not change the class's core method ownership or unresolved field-name caveats.
- 2026-06-17 B002 SoundManager music-selection execution:
  - Score unchanged at `86/86`.
  - Evidence: B002's current IDA pass corrected `0x00579dc0` to `GetDigitalDriver`, refined music-selection field names and DAT `.LST`/`.LSR` semantics, confirmed [UID:0001I7][0x005797b0-0x0057a25c.SoundManagerMusicSelection](by-memory/0x005797b0-0x0057a25c.SoundManagerMusicSelection.md) should route directly through this class, and bounded the remaining config/Miles/string naming limits.
- 2026-06-18 B003 Redbook source-quality execution:
  - Raised `86/86 -> 87/88`.
  - Evidence: B003's direct PE/Capstone pass split [UID:0001IB][0x0057b020-0x0057b48a.SoundManagerRedbookPlayback](by-memory/0x0057b020-0x0057b48a.SoundManagerRedbookPlayback.md) into exact child methods [UID:0003ZB][0x0057b020-0x0057b152.SoundManagerOpenRedbookDrive](by-memory/0x0057b020-0x0057b152.SoundManagerOpenRedbookDrive.md)-[UID:0003ZG][0x0057b2e0-0x0057b34a.SoundManagerSetRedbookPaused](by-memory/0x0057b2e0-0x0057b34a.SoundManagerSetRedbookPaused.md) and [UID:0003ZI][0x0057b370-0x0057b3ec.SoundManagerRestartMusic](by-memory/0x0057b370-0x0057b3ec.SoundManagerRestartMusic.md) with first-draft C++, retained raw no-entry helpers [UID:0003ZH][0x0057b350-0x0057b36a.SoundManagerStopRedbookAndCancelTrackTimerRaw](by-memory/0x0057b350-0x0057b36a.SoundManagerStopRedbookAndCancelTrackTimerRaw.md) and [UID:0003ZJ][0x0057b3f0-0x0057b48d.SoundManagerRotateReusableSampleSlotRaw](by-memory/0x0057b3f0-0x0057b48d.SoundManagerRotateReusableSampleSlotRaw.md) with blank formal C++, confirmed Redbook config fields `g_pConfig+0x291908/+0x291910/+0x291912/+0x291913/+0x291914`, timer token `0x504e4354`, and resolved `m_sampleSlots` as eight 8-byte `HSAMPLE`/volume-scale entries.
- 2026-06-19 B009 [UID:0003ZJ][0x0057b3f0-0x0057b48d.SoundManagerRotateReusableSampleSlotRaw](by-memory/0x0057b3f0-0x0057b48d.SoundManagerRotateReusableSampleSlotRaw.md) implementation:
  - Score unchanged at `87/88`.
  - Evidence: B009 incorporated the accepted source-quality reanalysis for raw `0x0057b3f0-0x0057b48d`: exact `0x9d` / 157-byte body, padding on both sides, no route to start or interior, import-resolved `AIL_sample_status`/`AIL_init_sample` behavior, resolved helper names `GetMemoryMan`/`MemmoveWrapper`/`Memmove0Wrapper`, sample-slot field names, relationship to `PlaySample` and `ReinitializeAudioDriver`, and target-specific non-emitting policy.
- 2026-06-22 Rule 26 incorporation of B015 [UID:0003ZH][0x0057b350-0x0057b36a.SoundManagerStopRedbookAndCancelTrackTimerRaw](by-memory/0x0057b350-0x0057b36a.SoundManagerStopRedbookAndCancelTrackTimerRaw.md) source-quality report:
  - Score unchanged at `87/88`.
  - Evidence: accepted `0003ZH` as a source-shaped raw/unpromoted private SoundManager method with first-draft C++, exact 26-byte Redbook stop plus timer-cancel body, no null guard, no close/clear side effects, no recovered live entry route, and rejected TimerMgr, MusicControlDialog, MidiPlayer, DAT/archive, and standalone Redbook owners.
- 2026-06-27 B004 [UID:0001I8][0x005797b0-0x0057bf6e.SoundManagerAudioHelperCluster](by-memory/0x005797b0-0x0057bf6e.SoundManagerAudioHelperCluster.md) implementation:
  - Score unchanged at `87/88`.
  - Evidence: incorporated live MCP session `80de0a67` support proof for the broad aggregate's non-emitting index disposition, the SoundManager vtable/singleton lifecycle, PlaySample/sample-slot layout, driver/callback registration, exact child/source-output boundaries, and rejection of aggregate C++.
- 2026-06-28 B013 [UID:0001IF][0x0057bf40-0x0057bf6e.SoundPathVectorClear](by-memory/0x0057bf40-0x0057bf6e.SoundPathVectorClear.md) implementation support:
  - Score unchanged at `87/88`.
  - Evidence: added current-session support that direct `%08d.MP3` paths clear `m_zonePlaylistActive` and call source-ready `SoundPathVector::Clear()` on `m_zoneMusicTracks` at `SoundManager +0x109c`. This preserves SoundManager as policy owner while [UID:0000DI][SoundPathVector](by-class/SoundPathVector.md) owns/emits the clear helper.
- 2026-07-13 B004 UID0001IA callback:
  - Score unchanged at `87/88`; this support page was not inflated by the scanner-specific pass.
  - Corrected `m_localMusicPaths` and `m_zoneMusicTracks` to distinct `std::vector<SoundPathString>` fields, updated the scanner to exact range/signature/source behavior, preserved the observed no-`FindClose` side effect, and historicalized custom SoundPathVector method emission as old-MSVC compiler/STL lowering.
  - Historical B013/custom-container wording above remains provenance for the prior classification; the current source-category decision is the non-emitting standard-container disposition documented in UID0001IA and UID0000DI.

## UID0003UL Sound-Effects Option Mirror Synchronization - 2026-07-15

- [UID:0003UL][0x005aa480-0x005aa702.UserPaneParsePlayerSettingsPacket](by-memory/0x005aa480-0x005aa702.UserPaneParsePlayerSettingsPacket.md) is a direct external caller of `EnableSoundEffects()` at `0x0057a760` and `DisableSoundEffects()` at `0x0057a770`, selected from RegistryConfig sound option byte `+0x28de48`.
- After either helper call, the parser writes the same requested state directly to SoundManager byte `+0x05`. The conservative source-facing name is `m_soundEffectsOptionEnabled`: it records the requested/server option and supplies the app-focus deferred-restore contract already observed at `0x0057a780/0x0057a790`.
- Byte `+0x05` is distinct from runtime playback gate byte `+0x41`, whose accepted name remains `m_soundEffectsEnabled`. `PlaySample` tests `+0x41`; the target's direct mirror to `+0x05` does not collapse or rename that runtime field.
- The target's helper calls plus explicit mirror store are observable and must remain separate in source. Generic `EnableSound`/`DisableSound` names and a single hidden state setter are rejected for this consumer.
- Class score `87/88`, owner/emitter, source route, formal block, playback/resource inventory, standard-container corrections, and all unrelated SoundManager evidence remain unchanged. The exact original lexical spelling of the `+0x05` field is still capped at descriptive confidence.

## 2026-07-20 UID00028R Direct Singleton And Lifecycle Closure

- At the 2026-07-20 UID00028R callback, the class score/route remained `92/94`, owner/emitter [UID:0000NV][SoundManager](by-file/SoundManager.md), position `10`, reconstructable true. That callback changed no field offset, size, method signature, friend declaration, child body, or unrelated historical evidence; the 2026-08-24 standalone-header callback later raised completion to `93` without changing those layout facts.
- Live RTTI names exact `SoundManager`, `Singleton<SoundManager>`, and `TimerHandler`. The class hierarchy descriptor at `0x006504a4` and base array at `0x006504b4` list source bases in order Singleton then TimerHandler.
- Singleton base PMD is `mdisp=4,pdisp=-1,vdisp=0`; TimerHandler PMD is `0,-1,0`. Old-MSVC empty-base optimization explains why the source-first empty Singleton base has a `+4` view while TimerHandler remains the primary vptr-bearing physical base at offset zero.
- Constructor allocation remains exact `0x10ac`. Adding the empty source base does not change any accepted member offset or class size and requires no reserved/padding field.

### Exact Lifecycle Children

- [UID:0004UG][0x00579a30-0x00579ca5.SoundManagerConstructor](by-memory/0x00579a30-0x00579ca5.SoundManagerConstructor.md), position `20`, owns Config/Miles/DAT/scanner authored construction policy.
- [UID:0004UH][0x00579cb0-0x00579dbf.SoundManagerDestructor](by-memory/0x00579cb0-0x00579dbf.SoundManagerDestructor.md), position `30`, owns authored sample/stream/driver/Miles/Redbook cleanup.
- [UID:0004UI][0x0057b9a0-0x0057b9ab.SoundManagerConstructorUnwindSingletonClear](by-memory/0x0057b9a0-0x0057b9ab.SoundManagerConstructorUnwindSingletonClear.md) is exact compiler EH direct-base cleanup with blank source.
- [UID:0004UJ][0x0057bb30-0x0057bc59.SoundManagerScalarDeletingDestructor](by-memory/0x0057bb30-0x0057bc59.SoundManagerScalarDeletingDestructor.md) is the vtable-only compiler wrapper with blank source.
- [UID:0004UK][0x0062ce78-0x0062ce84.SoundManagerVtableData](by-memory/0x0062ce78-0x0062ce84.SoundManagerVtableData.md) is exact compiler-generated COL/vtable data with blank source.
- [UID:0004UF][g_pSoundManager](by-global/g_pSoundManager.md) supplies the sole position-zero external pointer definition; physical [UID:00028R][0x0067a7d0-0x0067a7d4.g_pSoundManager](by-memory/0x0067a7d0-0x0067a7d4.g_pSoundManager.md) is non-emitting evidence.

### Source Versus Compiler Policy

- Constructor publication/fallback clear at `0x00579a67/0x00579a6e`, ordinary reverse-base clear at `0x00579da3`, EH clear at `0x0057b9a0`, and scalar-wrapper clear at `0x0057bc29` are direct Singleton lowering around one semantic global.
- The class declaration and ordinary source constructor/destructor are the human source. Do not handwrite global publication/clear, `this+4`/`this-4`, vptr stores, EH funclets, scalar flags/free, standard-vector teardown, TimerHandler destruction, RTTI, or vtable arrays.
- Exact vtable child contains COL pointer at `0x0062ce78`, scalar wrapper at `0x0062ce7c`, and `OnTimer` at `0x0062ce80`, ending before `%03d.wav` at `0x0062ce84`.
- Application shutdown reads/checks the global at `0x00464b14`, supplies scalar-delete flag `1`, and calls virtual slot zero at `0x00464b22`; this confirms the virtual destructor route without adding a source method.

### No-Loss And Rejected Alternatives

- The complete managed declaration is preserved byte-for-byte from the accepted current union except the direct Singleton inheritance insertion. All playback, scanner, Redbook, DirectSound, sample-slot, payload, vector, BaramApp friend, inline PlayEffect, and private helper content remains authoritative.
- Reject class-static/template-static storage, a handwritten Singleton field, explicit offset/padding members, duplicate global definitions, raw `dword_67A7D0`, Boost-polluted destructor labels, and compiler-shaped lifecycle methods.
- Historical TimerHandler-only declaration was layout-correct but source-incomplete. RTTI/PMD evidence now supersedes it without changing the accepted natural-alignment layout.

### Generated Acceptance

- Generated `SoundManager.h` must contain the one complete class declaration with `Singleton<SoundManager>, public TimerHandler`; generated `SoundManager.cpp` must contain the out-of-line constructor, ordinary destructor, and existing method-definition union against that header declaration. A class declaration in CPP is rejected as a duplicate source route.
- Compiler-only UID00028R/UID0004UI/UID0004UJ/UID0004UK must produce no source marker/body. Existing broad UID0001I7/UID0001IC markers remain for their independent unsplit methods and are not class-target regressions.
