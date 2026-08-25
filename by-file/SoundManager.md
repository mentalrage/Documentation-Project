*** UID:0000NV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/audio/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# SoundManager

## UID0001IC Driver And Miles Callback Integration - 2026-07-24

- The source root remains `NexusTK/audio/SoundManager.cpp` plus generated `SoundManager.h`, with score `92/93` unchanged. [UID:0000DG][SoundManager](by-class/SoundManager.md) emits its complete class declaration only through H at position `10`; its CPP channel is blank, and private scope now contains the sole `static void AILCALLBACK AILStreamEndCallback(HSTREAM)` declaration.
- [UID:0004WV][SoundManagerMilesCallbackDeclarations](by-item/SoundManagerMilesCallbackDeclarations.md) emits `#include "SoundManager.h"` and exactly four file-static Miles open/close/seek/read prototypes at position `15`, before constructor position `20`, driver registration, and every free-callback definition. Its H channel remains blank because those four callbacks are translation-unit-private. The stream callback is not repeated there; UID0000DG declares it and UID0004X0 owns its sole qualified definition.
- Driver/callback source order is now exact: retained private [UID:0004X1][0x0057afd0-0x0057b011.SoundManagerReinitializeAudioDriverAndResumeMusicRaw](by-memory/0x0057afd0-0x0057b011.SoundManagerReinitializeAudioDriverAndResumeMusicRaw.md) at `390`; Redbook children remain `400-470`; public [UID:0001IC][0x0057b490-0x0057b5f0.SoundManagerReinitializeAudioDriver](by-memory/0x0057b490-0x0057b5f0.SoundManagerReinitializeAudioDriver.md) at `500`; private [UID:0004WW][0x0057b5f0-0x0057b62a.SoundManagerShutdownAudioDriverRaw](by-memory/0x0057b5f0-0x0057b62a.SoundManagerShutdownAudioDriverRaw.md) at `510`; open [UID:0000TU][0x0057b630-0x0057b72b.AILFileOpenCallback](by-memory/0x0057b630-0x0057b72b.AILFileOpenCallback.md), close [UID:0004WX][0x0057b730-0x0057b74a.AILFileCloseCallback](by-memory/0x0057b730-0x0057b74a.AILFileCloseCallback.md), seek [UID:0004WY][0x0057b750-0x0057b793.AILFileSeekCallback](by-memory/0x0057b750-0x0057b793.AILFileSeekCallback.md), read [UID:0004WZ][0x0057b7a0-0x0057b7e8.AILFileReadCallback](by-memory/0x0057b7a0-0x0057b7e8.AILFileReadCallback.md), and stream [UID:0004X0][0x0057b7f0-0x0057b853.AILStreamEndCallback](by-memory/0x0057b7f0-0x0057b853.AILStreamEndCallback.md) at `520-560`.
- The reinitializer preserves Miles close/release/shutdown, current-directory redist setup, restart, 22050/44100 selection, mode-1 then mode-0 driver fallback, HWND binding in observed order, callback registration, eight-slot zero/allocation, and existing unchecked failure behavior.
- The four file-static callbacks preserve DAT-first open with loose `StdioFile` fallback; void null-safe close; seek-origin mapping with unknown-value pass-through and ignored seek result; and unsigned remaining-byte clamp with ignored short-read return. The private static stream callback preserves the no-`this` Miles ABI, independent mode tests, direct legal access to private zone-playlist state, and asynchronous `0x407/0x408` main-window posts.
- Generic File/DATFile/StdioFile remain project dependencies; the needed Miles boundary is now supplied by the bounded local declarations in `SoundManager.h`, not an unavailable SDK header. Canonical source placement stays here because all address-taking/registration and NexusTK policy originate in SoundManager; class ownership for UID0004X0 supplies C++ access legality without creating duplicate FileIO, public-field/accessor, friend-wrapper, or third-party source.
- Exact all-`0xcc` gaps remain compiler/linker alignment in `by-memory/-ignored.md`. The `[0x0057b860,0x0057bf6e)` UID0001ID exact-child/compiler decisions remain unchanged and non-duplicated.

### Generated One-Definition Contract

- `SoundManager.h`: UID0004UF position zero opens one guard, supplies seven direct includes, the bounded local Miles compatibility block, all 37 API declarations, and `g_pSoundManager` extern. UID0000DG position ten emits exactly one complete class declaration, including private `ReinitializeAudioDriverAndResumeMusic()`, `ShutdownAudioDriver()`, and static `AILStreamEndCallback(HSTREAM)`, then closes the guard.
- `SoundManager.cpp`: exactly one position-15 include/four-free-prototype preamble; one qualified `SoundManager::AILStreamEndCallback` definition at position `560`; and one definition per other exact body at positions `390` and `500-550`. No callback declaration or class body is repeated on a body page, and no free function accesses a private SoundManager member.
- Broad [UID:0001I8][0x005797b0-0x0057bf6e.SoundManagerAudioHelperCluster](by-memory/0x005797b0-0x0057bf6e.SoundManagerAudioHelperCluster.md) remains the sole non-emitting physical index. UID0001IC is no longer a broad blank emitter; it is the exact emitted reinitializer method.

### Standalone Header And Miles Compatibility Audit

- Direct header prerequisites are exactly `<windows.h>`, `<dsound.h>`, `<string.h>`, `<vector>`, `../util/Singleton.h`, `../util/StringBase.h`, and `../util/TimerHandler.h`. They supply `HWND`/DirectSound pointers, `_strlwr_s`, vector, both complete bases, and complete StringBase/vector-element definitions without PCH assumptions.
- The local compatibility boundary declares `S32`/`U32` as signed/unsigned long, opaque `HSAMPLE`/`HDIGDRIVER`/`HSTREAM`/`HREDBOOK` pointer handles, guarded `AILCALL`/`AILCALLBACK` as `__stdcall`, and five callback procedure types matching UID0004WV and the stream callback.
- The complete 37-name `extern "C"` inventory is: `AIL_sample_status`, `AIL_set_sample_volume`, `AIL_start_sample`, `AIL_set_sample_file`, `AIL_set_DirectSound_HWND`, `AIL_release_sample_handle`, `AIL_allocate_sample_handle`, `AIL_set_redist_directory`, `AIL_close_digital_driver`, `AIL_open_digital_driver`, `AIL_release_all_timers`, `AIL_last_error`, `AIL_set_preference`, `AIL_shutdown`, `AIL_get_DirectSound_info`, `AIL_redbook_close`, `AIL_redbook_tracks`, `AIL_init_sample`, `AIL_redbook_track_info`, `AIL_redbook_position`, `AIL_redbook_play`, `AIL_redbook_stop`, `AIL_redbook_pause`, `AIL_redbook_resume`, `AIL_set_file_callbacks`, `AIL_register_stream_callback`, `AIL_stream_status`, `AIL_set_stream_loop_count`, `AIL_set_stream_volume`, `AIL_startup`, `AIL_set_digital_master_volume`, `AIL_pause_stream`, `AIL_start_stream`, `AIL_close_stream`, `AIL_open_stream`, `AIL_redbook_open_drive`, and `AIL_redbook_set_volume`.
- Decorated import suffixes establish `__stdcall` arities; current IDB/callsites establish four-byte handles, consumed return categories, and callback signatures. The block exposes no proprietary structure layout and imports no third-party source.
- Repository search found no Miles SDK/header/shim/import library. Reject `<mss.h>`, a new unowned compatibility file, copied SDK source, implicit function declarations, and PCH-only availability. Keeping the declarations local to `SoundManager.h` is the smallest source-complete route supported by the executable and existing UIDs.

## Current Source Union And Order

- Current score/source root: `92/93`, direct file root, `NexusTK/audio/SoundManager.cpp`.
- [UID:0004UF][g_pSoundManager](by-global/g_pSoundManager.md) emits the sole external pointer definition at position `0`. Physical [UID:00028R][0x0067a7d0-0x0067a7d4.g_pSoundManager](by-memory/0x0067a7d0-0x0067a7d4.g_pSoundManager.md) is non-emitting exact binary evidence.
- [UID:0000DG][SoundManager](by-class/SoundManager.md) emits the complete natural-alignment `0x10ac` declaration at position `10`, including direct `Singleton<SoundManager>` then TimerHandler inheritance, Application/BaramApp friendship, exact public/private playback surface, eight sample slots, 1000 DAT payload pointers, local/zone vectors, and Redbook storage; it closes the guard opened by UID0004UF.
- [UID:0004UG][0x00579a30-0x00579ca5.SoundManagerConstructor](by-memory/0x00579a30-0x00579ca5.SoundManagerConstructor.md) and [UID:0004UH][0x00579cb0-0x00579dbf.SoundManagerDestructor](by-memory/0x00579cb0-0x00579dbf.SoundManagerDestructor.md) emit exact authored lifecycle bodies at positions `20` and `30`.
- Playback definitions are the twenty exact children UID0004RW-UID0004SH at positions `100-290`; [UID:0001IA][0x0057a890-0x0057afce.SoundManagerMusicDirectoryScan](by-memory/0x0057a890-0x0057afce.SoundManagerMusicDirectoryScan.md) is position `300`; accepted Redbook definitions UID0003ZB-UID0003ZI are positions `400-470`.
- UID0001I9 is now a non-emitting split index. UID0001I7, UID0001I8, and UID0001IB remain bounded aggregate/index pages and do not duplicate exact child bodies. UID0001IC is the exact emitted reinitializer method; UID0003ZJ remains a no-entry duplicated rotation subset; UID0004SF and the new UID0004X1/UID0004WW methods are distinct unique retained private source.

### Playback Child Inventory

| UID | Source method | Position |
| --- | --- | ---: |
| 0004RW | `SoundManager::StopStream` | 100 |
| 0004RX | `SoundManager::GetStreamVolume` | 110 |
| 0004RY | `SoundManager::SetStreamVolume` | 120 |
| 0004RZ | `SoundManager::IsPlaybackEnabled` | 130 |
| 0004S1 | `SoundManager::MuteMusic` | 140 |
| 0004S3 | `SoundManager::UnmuteMusic` | 150 |
| 0004S4 | `SoundManager::SetStreamPaused` | 160 |
| 0004S5 | `SoundManager::PlayNextTrack` | 170 |
| 0004S6 | `SoundManager::PlayNextPlaylistTrack` | 180 |
| 0004S7 | `SoundManager::PlaySample` | 190 |
| 0004S8 | `SoundManager::GetSampleVolume` | 200 |
| 0004S9 | `SoundManager::SetSampleVolume` | 210 |
| 0004SA | `SoundManager::IsSoundEffectsEnabled` | 220 |
| 0004SB | `SoundManager::EnableSoundEffects` | 230 |
| 0004SC | `SoundManager::DisableSoundEffects` | 240 |
| 0004SD | `SoundManager::SuspendSoundEffectsForApplicationDeactivate` | 250 |
| 0004SE | `SoundManager::RestoreSoundEffectsAfterAppFocus` | 260 |
| 0004SF | private `SoundManager::SetDigitalAudioMuted` | 270 |
| 0004SG | `SoundManager::GetDirectSound` | 280 |
| 0004SH | virtual `SoundManager::OnTimer` | 290 |

### Complete Playback Integration

- Exact timer values remain `0x504e4354` Redbook track-ended, `0x534d736d` stream stop/restart, and `0x534d7374` stream fade-step. TimerHandler wrappers stay owned by TimerMgr and are not emitted here.
- Stream and Redbook volume preserve unsigned clamping and integer scaling. Sample playback preserves the unsigned ID `<=999` gate, eight-slot rotation, DAT payload table, per-play scale, master scale, and final runtime-enabled recheck.
- Music option/runtime bytes and SFX option/runtime bytes remain distinct. The BaramApp activation/deactivation tail chunks are emitted in Application.cpp and use `friend class BaramApp`; they are not duplicated in this file.
- Miles, DirectSound, DATFile, Config, MidiPlayer, MemoryMan, Bink, STL/Dinkumware lowering, callbacks, compiler wrappers, and vtable/RTTI pages retain their existing source boundaries. The semantic singleton global now has one source definition here; compiler publication/clear remains excluded.
- Historical `m_lastFadeOutMillis`, `m_restoreMusicOnActivate`, `OnTimerEvent`, separate out-of-line `PlayEffect`, aggregate-emitter, and unresolved-blank-body conclusions are superseded. `PlayEffect` is an inline class alias forwarding to the sole out-of-line `PlaySample`.
- Generated acceptance requires one standalone header guard, seven direct includes, one local Miles block with all 37 declarations, one external global declaration, one complete class, each playback/scanner/Redbook body once in position order, no UID0001I9 empty marker or aggregate body, and no BaramApp app-tail duplicate.

## Historical Pre-Playback-Split Status

- Confidence: strong for audio source ownership, exact-child output routing, non-emitting aggregate/index separation, and the standard-container/StringBase instantiation split; medium for exact original folder/global split.
- Proposed module: `audio/SoundManager.cpp`
- Historical generated lead: `class_SoundManager.cpp`; Wave-era generated source is not current source authority.
- Main class: [UID:0000DG][SoundManager](by-class/SoundManager.md)
- Main address doc: [UID:0001I8][0x005797b0-0x0057bf6e.SoundManagerAudioHelperCluster](by-memory/0x005797b0-0x0057bf6e.SoundManagerAudioHelperCluster.md)
- Evidence basis: `simroot_v2` generated source, Wave3 metadata, read-only Wave3 class inspection while status was `OPERATIONAL`, IDA MCP decompilation/lookup/import checks on 2026-05-22 through 2026-05-25, and local runtime file metadata recorded in [UID:0001QE][client_libraries](by-meta/client_libraries.md).

## Hypothesis

The original client likely had a dedicated audio source file for the `SoundManager` class rather than scattering music, sound-effect, and resource-selection logic across archive or UI files. The class owns Miles Sound System initialization, DAT-backed sound-effect preloading, DAT-backed zone music selection, loose music-directory scanning, and playback state transitions.

## Contents

Likely source-level contents:

Historical pre-UID0001IA callback inventory follows. It preserves the exact child reports, ranges, callers, EH paths, and former custom `SoundPathVector`/helper emission assumptions as provenance, but all claims that those vector children currently emit handwritten methods are superseded by the current standard-container correction below.

- `SoundManager` class implementation.
- [UID:0001I8][0x005797b0-0x0057bf6e.SoundManagerAudioHelperCluster](by-memory/0x005797b0-0x0057bf6e.SoundManagerAudioHelperCluster.md) as a reviewed non-emitting SoundManager audio-family index/container. It should not contribute a parent source body; exact child pages provide SoundManager methods, raw-helper decisions, SoundPathVector helper routing, and no-code proofs.
- [UID:0000DI][SoundPathVector](by-class/SoundPathVector.md) as a private or neighboring audio path-vector helper for playlist and scanned-file storage.
- [UID:0001ID][0x0057b860-0x0057bf6e.SoundPathVector](by-memory/0x0057b860-0x0057bf6e.SoundPathVector.md) is now a reviewed non-emitting SoundPathVector split/index, not a source-body emitter. Exact child pages route through [UID:0000DI][SoundPathVector](by-class/SoundPathVector.md) into this source root only when source-ready. Source-ready children now include [UID:0004FK][0x0057bac0-0x0057bb2a.SoundPathVectorDestructor](by-memory/0x0057bac0-0x0057bb2a.SoundPathVectorDestructor.md), [UID:0004FL][0x0057bd90-0x0057be52.SoundPathVectorReallocate](by-memory/0x0057bd90-0x0057be52.SoundPathVectorReallocate.md), [UID:0004FM][0x0057bc60-0x0057bcdc.SoundPathStringPrepareHelper](by-memory/0x0057bc60-0x0057bcdc.SoundPathStringPrepareHelper.md), [UID:0004FN][0x0057bce0-0x0057bd53.SoundPathVectorReplaceStorage](by-memory/0x0057bce0-0x0057bd53.SoundPathVectorReplaceStorage.md), [UID:0004FP][0x0057be60-0x0057becf.SoundPathStringCopyConstructRange](by-memory/0x0057be60-0x0057becf.SoundPathStringCopyConstructRange.md), and existing [UID:0001IF][0x0057bf40-0x0057bf6e.SoundPathVectorClear](by-memory/0x0057bf40-0x0057bf6e.SoundPathVectorClear.md). Non-emitting reconstructable children remain [UID:0004FJ][0x0057b860-0x0057b99a.SoundPathVectorGrowAndInsert](by-memory/0x0057b860-0x0057b99a.SoundPathVectorGrowAndInsert.md), [UID:0004FO][0x0057bd60-0x0057bd84.SoundPathStringDestroyRange](by-memory/0x0057bd60-0x0057bd84.SoundPathStringDestroyRange.md), and [UID:0004FQ][0x0057bed0-0x0057bf3e.SoundPathStringCopyConstructRangeTail](by-memory/0x0057bed0-0x0057bf3e.SoundPathStringCopyConstructRangeTail.md). UID0004FK emits first-draft `SoundPathVector::~SoundPathVector()` through UID0000DI into `NexusTK/audio/SoundManager.cpp` after B003's dated `6a4af54d` pass: exact `0x0057bac0-0x0057bb2a` / `0x6a` body, normal callers `0x00579d8c`/`0x00579d97`/`0x0057afa6`/`0x0057bc0e`/`0x0057bc19`, EH/unwind refs `0x00608332`/`0x00608340`/`0x00608407`, entry release through `0x00582b30 -> 0x005832f0`, storage free through `0x005c7526`, triplet reset, padding on both sides, and rejected direct SoundManager/parent aggregate/raw naming routes. UID0004FL emits first-draft `SoundPathVector::Reallocate(int newCapacity)` through UID0000DI after B010's dated `aa3930bd` pass: exact `0x0057bd90-0x0057be52` / `0xc2` body, one local-music scan caller `0x0057aea5`, allocator `0x00421520`, `SoundPathString` copy construction through `0x005829f0`, commit through UID0004FN `ChangeArray()` at `0x0057be1b`, copy-failure cleanup through `0x006085f3 -> 0x0057b9b0`, free wrapper `0x00423e00`, and rejected direct SoundManager/parent aggregate/broad aggregate/generic-container/raw-label/plain `operator new[]` routes; exact allocator/free helper spelling remains inferred. UID0004FJ remains non-emitting after B007's accepted pass: historical B007 evidence gathered while MCP session `fef9a7c2` was active proves exact range `0x0057b860-0x0057b99a`, callers `0x005798e9`/`0x0057acab`/`0x0057aef5`, 1.5x growth, append/middle-insert branches, storage commit, cleanup/free/rethrow path, and padding before `0x0057b9a0`; supervisor-verified dated MCP session for that UID0004FJ pass was `6a4af54d`. Accepted field/type names are still not enough to finalize the integrated allocator/copy/destroy/replace helper contracts and EH cleanup source shape. UID0004FQ remains non-emitting after B006's accepted pass: historical B006 MCP evidence from now-stale session `fef9a7c2` proves `sub_57BED0` size `0x6e` / 110 bytes, final return byte at `0x0057bf3d`, padding `0x0057bf3e-0x0057bf40`, one caller `0x0057b927`, and one callee `0x005829f0`, but the caller-ignored return and raw `0x0057b9b0` EH cleanup keep formal C++ unsafe.
- [UID:0001IF][0x0057bf40-0x0057bf6e.SoundPathVectorClear](by-memory/0x0057bf40-0x0057bf6e.SoundPathVectorClear.md) as source-ready `SoundPathVector::Clear()`, the track-filename/path-vector clear helper used by music-selection direct `%08d.MP3` fallback paths. It routes through [UID:0000DI][SoundPathVector](by-class/SoundPathVector.md) and emits into this `NexusTK/audio/SoundManager.cpp` source family.
- Current UID0001IA source-category correction: [UID:0001IA][0x0057a890-0x0057afce.SoundManagerMusicDirectoryScan](by-memory/0x0057a890-0x0057afce.SoundManagerMusicDirectoryScan.md) is a source-ready SoundManager method emitted here. Its `m_localMusicPaths` and `m_zoneMusicTracks` storage is `std::vector<SoundPathString>`, and its pending-directory queue is `std::deque<SoundPathString>`. UID0000DI/UID0001ID and vector children UID0004FJ/0004FK/0004FN/0004FO/0004FL/0004FP/0004FQ/0001IF are retained as non-emitting binary documentation for compiler/STL instantiations; their exact historical ranges, calls, allocations, copies, cleanup, EH, and rejected routes remain documented, but no custom vector C++ is routed into this file.
- UID0004FM is not part of that compiler-only vector set. It is source-authored ANSI StringBase lowercase-copy template behavior with hidden-result ABI, owned/emitted through [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md) as a header-visible inline specialization in `StringBase.h` or an included `.inl`. Its modeled placement near SoundManager is consumer-TU/COMDAT template instantiation, not SoundManager-authored source, SoundPathVector ownership, or proof of `StringBase.cpp` placement.
- Playlist loading from `.LST` and `.LSR` DAT entries, where `.LST` is sequential and `.LSR` is randomized.
- `%03d.wav` sound-effect lookup/preload policy.
- `%08d.MP3` zone-track naming policy and direct single-track fallback.
- Local music directory scanning and randomization through source-ready UID0001IA: UTF-16 StringBase input, one ANSI conversion, `FindFirstFileA`/`FindNextFileA`, lowercase `.mp3` filtering, optional non-dot directory recursion, reserve, unseeded `rand()` extraction or swap, and the observed absence of `FindClose`.
- Redbook/CD and stream control helpers, including the raw/unpromoted but emitted private [UID:0003ZH][0x0057b350-0x0057b36a.SoundManagerStopRedbookAndCancelTrackTimerRaw](by-memory/0x0057b350-0x0057b36a.SoundManagerStopRedbookAndCancelTrackTimerRaw.md) stop/timer helper.
- Sample/SFX slot management, including raw no-entry [UID:0003ZJ][0x0057b3f0-0x0057b48d.SoundManagerRotateReusableSampleSlotRaw](by-memory/0x0057b3f0-0x0057b48d.SoundManagerRotateReusableSampleSlotRaw.md) as documented `SoundManager::RotateReusableSampleSlot()` behavior only; it stays out of generated C++ until a live route is recovered.
- Miles AIL file callbacks at `0x0057b630-0x0057b7e7`; see [UID:0000TU][0x0057b630-0x0057b72b.AILFileOpenCallback](by-memory/0x0057b630-0x0057b72b.AILFileOpenCallback.md).
- Audio-specific globals such as `g_pSoundManager`, `g_strBackslash`, `g_strBackslashStar`, and `g_strMusicExtension`, pending global ownership review.
- UI consumers such as [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md) and [UID:0000LN][MusicControlDialog](by-file/MusicControlDialog.md) should call into this module, but should not be merged into the audio implementation.

Not owned here:

- Timer wrapper helpers `0x00597610` and `0x00597630`. Active `simroot_v2` emits them as `SoundManager` methods, but IDA body/caller evidence now resolves them as generic [UID:0001K9][0x00597610-0x00597645.TimerHandlerWrappers](by-memory/0x00597610-0x00597645.TimerHandlerWrappers.md) forwarding to [UID:0000SI][g_pTimerMgr](by-global/g_pTimerMgr.md).
- [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md) and [UID:0000RM][g_pMidiPlayer](by-global/g_pMidiPlayer.md). `SoundManager` consumes MIDI pause/resume behavior, but `MidiPlayer` owns the WinMM stream singleton and buffer lifetime.

## Archive Dependency

`SoundManager` should depend on the DAT archive API, but it should not own DAT parsing.

Confirmed archive interactions:

- Constructor `0x00579a30`: checks `%03d.wav` entries with [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md), opens them with `DATFile`, and caches payload pointers for sound effects.
- `LoadTrackListFromFile` `0x005797b0`: opens `.LST` or `.LSR` through `DATFile`, reads line-based track IDs, and formats `%08d.MP3`.
- `PlayMusicByZone` `0x0057a0b0`: checks `%08d.LST`, `%08d.LSR`, and `%08d.MP3` through [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md). `.LST` fills a sequential zone playlist, `.LSR` fills a randomized playlist, and direct `.MP3` is the single-track fallback.
- `GetDigitalDriver` `0x00579dc0`: returns the Miles digital driver handle at `SoundManager+0x8`; this is a real tiny accessor, not destructor tail.
- `ReinitializeAudioDriver` `0x0057b490`: registers Miles AIL file callbacks that open audio resources through `DATFile` first, with [UID:0000E6][StdioFile](by-class/StdioFile.md) as the loose-file fallback.

This gives a clean original-file split:

```text
archive/DATFile.cpp       // DAT parsing, mapping, index, lookup helpers
audio/SoundManager.cpp    // audio policy, Miles AIL calls, DAT resource names
```

## Middleware Dependency

`SoundManager` is the project-owned wrapper around RAD Miles Sound System and DirectSound, not a replacement for the Miles runtime.

Observed external runtime evidence:

- IDA imports 37 Miles `_AIL_*` functions from `mss32`, including `_AIL_startup@0`, `_AIL_shutdown@0`, `_AIL_open_digital_driver@16`, `_AIL_set_DirectSound_HWND@8`, `_AIL_allocate_sample_handle@4`, `_AIL_set_sample_file@12`, `_AIL_start_sample@4`, `_AIL_open_stream@12`, `_AIL_start_stream@4`, Redbook helpers, and `_AIL_set_file_callbacks@16`.
- Local runtime copies are staged under [UID:0001QX][README](by-meta/obtained_thirdparty_files/README.md): `Mss32.dll` and `Mp3dec.asi`, both Miles `6.1c`.
- [UID:0000P4][VideoPlayerPane](by-file/VideoPlayerPane.md) / [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md) use Bink Video, but the audio coupling is narrow. B002 confirms the tiny `0x00579dc0` helper is `SoundManager::GetDigitalDriver() const` returning the Miles digital driver; the separate DirectSound bridge remains the later `0x0057a7e0` helper used for DirectSound setup.

Rebuild guidance:

- Link/import Miles as external middleware and ship the runtime DLL/ASI; do not recover `_AIL_*` implementations into NexusTK source.
- Keep `SoundManager` responsible for configuring Miles, choosing DAT/loose audio resources, and registering the file callbacks.
- Keep Bink playback logic out of `SoundManager`; only the DirectSound bridge helper belongs here.

## Evidence

- Wave3 metadata reports `SoundManager` has 35 included methods and no excluded methods.
- Current generated source shows one `class_SoundManager.cpp` file with `LoadTrackListFromFile`, constructor, `PlayMusicByZone`, stream helpers, and directory scanning.
- IDA MCP decompilation confirms the generated `FileExists`-style checks in `PlayMusicByZone` are calls to [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md).
- IDA MCP recheck on 2026-05-25 confirms `0x0057bf40` clears the path-vector at `SoundManager +0x109c` from the `PlayTrackByIndex` and `PlayMusicByZone` paths.
- 2026-05-26 recheck confirms current `class_SoundPathVector.cpp` still omits the `0x0057bf40` clear helper, while IDA MCP callers remain `0x00579f9a` and `0x0057a214` from SoundManager track-selection and zone-music fallback paths.
- 2026-06-11 A002 Batch190 live IDA MCP refresh reconfirmed the SoundPathVector helper family as SoundManager-local audio path management: grow/insert callers at `0x005798e9`, `0x0057acab`, and `0x0057aef5`; destructor callers at `0x00579d8c`, `0x00579d97`, `0x0057afa6`, `0x0057bc0e`, and `0x0057bc19`; reallocate caller at `0x0057aea5`; clear callers at `0x00579f9a` and `0x0057a214`.
- 2026-06-13 C001 Goal 2 barrier repair confirmed the old `0x005797b0-0x0057bc58` aggregate endpoint was stale for the audio helper cluster. The corrected aggregate [UID:0001I8][0x005797b0-0x0057bf6e.SoundManagerAudioHelperCluster](by-memory/0x005797b0-0x0057bf6e.SoundManagerAudioHelperCluster.md) now contains the full SoundPathVector/string-helper tail through `0x0057bf6e` instead of crossing [UID:0001ID][0x0057b860-0x0057bf6e.SoundPathVector](by-memory/0x0057b860-0x0057bf6e.SoundPathVector.md).
- 2026-06-17 B002 source-quality pass corrected the music-selection child [UID:0001I7][0x005797b0-0x0057a25c.SoundManagerMusicSelection](by-memory/0x005797b0-0x0057a25c.SoundManagerMusicSelection.md): it now routes directly through the [UID:0000DG][SoundManager](by-class/SoundManager.md) class, identifies `0x00579dc0` as `GetDigitalDriver`, confirms `.LST` sequential playlist versus `.LSR` randomized playlist semantics, and records that `auto-generated/NexusTK/audio/SoundManager.cpp` remains empty until formal C++ is safely populated.
- 2026-06-27 B004 source-quality implementation confirms [UID:0001I8][0x005797b0-0x0057bf6e.SoundManagerAudioHelperCluster](by-memory/0x005797b0-0x0057bf6e.SoundManagerAudioHelperCluster.md) is a non-emitting index, not a source-body emitter. Its live MCP-backed inventory covers 53 modeled functions plus raw helper bodies, but the range crosses exact child SoundManager methods, raw helpers with different output decisions, AIL callback glue, compiler deleting-destructor glue, SoundPathVector direct ownership, and Deque interleave. Those facts strengthen this file as the source-family root while keeping the aggregate itself out of generated C++.
- 2026-06-28 B013 implementation for [UID:0001IF][0x0057bf40-0x0057bf6e.SoundPathVectorClear](by-memory/0x0057bf40-0x0057bf6e.SoundPathVectorClear.md) resolves the stale generated empty-emitter state for the exact clear child. The dated callback MCP session `supervisor_20260628_resume` confirms the exact `0x2e` body, caller pair `0x00579f9a`/`0x0057a214`, SoundManager `+0x109c` route, `m_zonePlaylistActive` clear before direct `%08d.MP3` fallback, `0x00582b30 -> 0x005832f0` ANSI `StringBase` release semantics, and two-byte padding before `0x0057bf70`. This file remains the generated source root while [UID:0000DI][SoundPathVector](by-class/SoundPathVector.md) remains the direct semantic owner/emitter for the helper method.
- 2026-07-03 B005 UID0001ID implementation on MCP session `c9ac3d5b` removes the broad SoundPathVector aggregate from source emission. [UID:0001ID][0x0057b860-0x0057bf6e.SoundPathVector](by-memory/0x0057b860-0x0057bf6e.SoundPathVector.md) is now a non-emitting index/container; exact SoundPathVector child pages route through [UID:0000DI][SoundPathVector](by-class/SoundPathVector.md) into this `NexusTK/audio/SoundManager.cpp` source family when each child becomes source-ready. The split preserves GrowAndInsert callers `0x005798e9`, `0x0057acab`, `0x0057aef5`, destructor callers `0x00579d8c`, `0x00579d97`, `0x0057afa6`, `0x0057bc0e`, `0x0057bc19`, Reallocate caller `0x0057aea5`, raw `0x0057b9b0` no-entry evidence, SoundManager scalar deleting destructor exclusion at `0x0057bb30-0x0057bc59`, and padding windows through the `0x0057bf6e-0x0057bf70` SoundStatusPane boundary. This page remains the source root; generated output should be refreshed by validators rather than edited by hand.
- Historical 2026-07-03 B003 UID0004FM implementation support used dated MCP session `fef9a7c2` and interpreted [UID:0004FM][0x0057bc60-0x0057bcdc.SoundPathStringPrepareHelper](by-memory/0x0057bc60-0x0057bcdc.SoundPathStringPrepareHelper.md) as a `PrepareLowercaseSoundPathString(...)` helper routed through SoundPathVector into this audio source root. Its exact `0x7c` body, caller at `0x57abb5`, `.mp3` scan context, StringBase copy/detach/lower behavior, signature, and padding remain valid evidence. The ownership/placement conclusion is superseded: the body is `StringBase<char>::ToLower() const`, defined inline in `StringBase.h` or an included `.inl`, and its SoundManager-adjacent instance is consumer-TU/COMDAT output rather than authored SoundManager source.

All named MCP sessions in this page are dated evidence snapshots, not permanent current authority. Any future IDA-dependent decision requires a fresh supervisor `idb_list`, health/canonical-disk identity, and target-prestate readback.
- 2026-07-03 B005 UID0004FP implementation support uses dated callback MCP session `fef9a7c2` to resolve [UID:0004FP][0x0057be60-0x0057becf.SoundPathStringCopyConstructRange](by-memory/0x0057be60-0x0057becf.SoundPathStringCopyConstructRange.md) as source-ready `CopyConstructSoundPathStringRange(...)` emitted through [UID:0000DI][SoundPathVector](by-class/SoundPathVector.md) into this audio source root. Evidence proves the exact `0x70` / 112-byte body, two `SoundPathVector::GrowAndInsert` call sites at `0x57b933` and `0x57b946`, four-byte ANSI `SoundPathString` copy construction through `0x005829f0`, cleanup of the partially constructed destination range through the raw `0x0057b9b0` landing path, exact boundary bytes, and rejection of direct SoundManager, parent aggregate, or sibling-merge ownership. This file remains the generated source root; generated output should be refreshed by validators rather than edited by hand.
- 2026-07-03 B003 UID0004FK implementation support uses dated callback MCP session `6a4af54d` to resolve [UID:0004FK][0x0057bac0-0x0057bb2a.SoundPathVectorDestructor](by-memory/0x0057bac0-0x0057bb2a.SoundPathVectorDestructor.md) as source-ready `SoundPathVector::~SoundPathVector()` emitted through [UID:0000DI][SoundPathVector](by-class/SoundPathVector.md) into this audio source root. Evidence proves the exact `0x6a` / 106-byte body, predecessor padding `0x0057bab5-0x0057bac0`, successor padding `0x0057bb2a-0x0057bb30`, five normal callers from SoundManager setup, directory-scan cleanup, and scalar deleting destructor cleanup, EH/unwind refs, `SoundManager+0x109c` and `+0x1028` vector destruction contexts, `[m_begin,m_end)` `SoundPathString` release through `0x00582b30 -> 0x005832f0`, storage cleanup through `0x005c7526`, and triplet zeroing. This file remains the source-family root rather than direct canonical owner; exact field names, `SoundPathString` typedef/header spelling, and storage-helper/source spelling remain confidence caps.
- IDA MCP import checks confirm the binary imports Miles from dynamic module `mss32` and Bink/WinMM separately. This supports keeping Miles as runtime middleware, MIDI as [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md), and Bink playback in video/startup modules.
- The constructor's `%03d.wav` loop uses DAT lookups for 1000 sound-effect slots.
- The class references `FindFirstFileA`, `FindNextFileA`, and `g_strMusicExtension` for loose-file music scanning, separate from DAT-backed zone tracks.

## Proposed Placement

```text
audio/
  SoundManager.h
  SoundManager.cpp
  MidiPlayer.h
  MidiPlayer.cpp
```

The project tree should eventually gain an `audio/` folder alongside `archive/`, `render/`, `ui/`, `map/`, and `network/`. Keeping audio as a first-class module avoids hiding Miles/Redbook/music policy inside generic resource loading.

## Source-Quality Decisions And Remaining Limits

- `NexusTK/audio/SoundManager.cpp` remains the best current route. A historical folder spelling such as `sound/` is not ruled out, but it no longer blocks ownership, emitter routing, or documentation confidence.
- Redbook/CD helpers remain in the SoundManager audio source family unless a later child-level split proves a distinct Redbook file. [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md) remains the separate WinMM MIDI owner and should not absorb SoundManager Redbook/stream code.
- B003's 2026-06-18 Redbook pass keeps Redbook/CD playback in `NexusTK/audio/SoundManager.cpp`; MusicControlDialog remains a consumer, TimerMgr owns only generic timer wrappers, MidiPlayer remains separate WinMM MIDI code, and no RTTI/vtable/global/namespace/string-island evidence supports a distinct Redbook source file. The historical [UID:0001IB][0x0057b020-0x0057b48a.SoundManagerRedbookPlayback](by-memory/0x0057b020-0x0057b48a.SoundManagerRedbookPlayback.md) aggregate is now a non-emitting index, while exact SoundManager child pages [UID:0003ZB][0x0057b020-0x0057b152.SoundManagerOpenRedbookDrive](by-memory/0x0057b020-0x0057b152.SoundManagerOpenRedbookDrive.md)-[UID:0003ZG][0x0057b2e0-0x0057b34a.SoundManagerSetRedbookPaused](by-memory/0x0057b2e0-0x0057b34a.SoundManagerSetRedbookPaused.md), [UID:0003ZH][0x0057b350-0x0057b36a.SoundManagerStopRedbookAndCancelTrackTimerRaw](by-memory/0x0057b350-0x0057b36a.SoundManagerStopRedbookAndCancelTrackTimerRaw.md), and [UID:0003ZI][0x0057b370-0x0057b3ec.SoundManagerRestartMusic](by-memory/0x0057b370-0x0057b3ec.SoundManagerRestartMusic.md) provide first-draft source bodies. `0003ZH` still has no recovered live entry route; B015 treats that as a confidence cap rather than a blank-C++ blocker.
- Generated `auto-generated/NexusTK/audio/SoundManager.cpp` is validator-owned and may lag scoped edits; it must not be edited by hand. Current expected output includes the one UID0001IA scanner body and excludes custom compiler-only vector/deque helper bodies. UID0001I8 aggregate output remains absent by design, and unrelated SoundManager child debt keeps file-level confidence below final audit.
- B009's 2026-06-19 [UID:0003ZJ][0x0057b3f0-0x0057b48d.SoundManagerRotateReusableSampleSlotRaw](by-memory/0x0057b3f0-0x0057b48d.SoundManagerRotateReusableSampleSlotRaw.md) pass keeps the helper in `NexusTK/audio/SoundManager.cpp` as a SoundManager sample/SFX concern despite physical adjacency to Redbook helpers. Direct PE/Capstone evidence shows the exact `0x0057b3f0-0x0057b48d` body between `0x0057b3ec-0x0057b3f0` and `0x0057b48d-0x0057b490` padding; no rel32/rel8 branch, VA/RVA/file-offset pointer, vtable, jump-table, or interior-entry route exists; the body rotates eight `SoundSampleSlot` entries at `this+0x48`, calls `AIL_sample_status` and `AIL_init_sample`, and uses project copy helpers `GetMemoryMan`, `MemmoveWrapper`, and `Memmove0Wrapper`.
- Do not generate `SoundManager::RotateReusableSampleSlot()` into active `SoundManager.cpp` from current evidence. The helper is source-shaped and reconstructable, but the nonblank emitter route is missing and live `PlaySample` already contains the same rotation/reinit subset before payload lookup, volume, and `AIL_start_sample`.
- Rejected owner/source routes for [UID:0003ZJ][0x0057b3f0-0x0057b48d.SoundManagerRotateReusableSampleSlotRaw](by-memory/0x0057b3f0-0x0057b48d.SoundManagerRotateReusableSampleSlotRaw.md): separate Redbook source file, `MusicControlDialog`, `TimerMgr`, `MidiPlayer`, archive/DAT code, MemoryMan/util code, `RestartMusic` tail, `ReinitializeAudioDriver` head/tail, padding, and compiler/runtime artifact. These are weaker than the SoundManager sample-slot evidence.
- Which globals should be declared with `SoundManager` versus app/config modules.

## Cross-References

- [UID:0000DG][SoundManager](by-class/SoundManager.md)
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
- [UID:0000TU][0x0057b630-0x0057b72b.AILFileOpenCallback](by-memory/0x0057b630-0x0057b72b.AILFileOpenCallback.md)
- [UID:0000JD][FileIO](by-file/FileIO.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)
- [UID:0001Q8][client_audio](by-meta/client_audio.md)
- [UID:0001QE][client_libraries](by-meta/client_libraries.md)
- [UID:0001QX][README](by-meta/obtained_thirdparty_files/README.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)

## Changes

- 2026-08-24 B009 UID0000NX callback: Kept file score `92/93` and source root unchanged. Added the complete standalone SoundManager header route, exact guard ownership split, seven direct dependencies, local Miles aliases/handles/calling conventions/callback types, all 37 API names, platform/type provenance, and rejection of unavailable SDK/new-shim/PCH/implicit-declaration/source-import alternatives.
- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `90` and confidence to `82`.
  - Evidence: document covers audio module hypothesis, source contents, archive and middleware dependencies, Miles/Bink/MIDI split, IDA/import evidence, proposed placement, open questions, and cross-references; confidence is capped by exact folder/source split and global ownership questions.
- 2026-06-01: Set `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/audio/"`.
  - Before: the page proposed `audio/SoundManager.cpp` in prose but left the validator path blank.
  - After: the by-file root stages under `auto-generated/NexusTK/audio/SoundManager.cpp`.
  - Evidence: this page, [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md), and [UID:0001Q8][client_audio](by-meta/client_audio.md) all place SoundManager in the audio module.
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)
- 2026-06-11 A002 Batch190 parent-gate refresh:
  - Changed confidence from `82` to `85`.
  - Evidence: live IDA MCP reconfirmed SoundPathVector method boundaries and caller sets entirely within SoundManager playlist loading, track selection, directory scanning, setup/destruction, and driver cleanup paths. This clears the direct file-parent side for SoundPathVector while leaving exact folder/global naming below final confidence.
- 2026-06-13 C001 Goal 2 barrier repair:
  - Kept score at `90/85`.
  - Evidence: live IDA MCP confirmed the SoundManager audio helper aggregate should extend through the contained path/string helper tail to `0x0057bf6e`; this is a by-memory aggregate endpoint fix, not a change to the proposed `NexusTK/audio/` source root.
- 2026-06-17 B002 SoundManager music-selection execution:
  - Score unchanged at `90/85`.
  - Evidence: B002 corrected `0x00579dc0` to `SoundManager::GetDigitalDriver() const`, refined DAT/local music-selection policy, and confirmed the class-to-file route `[UID:0001I7][0x005797b0-0x0057a25c.SoundManagerMusicSelection](by-memory/0x005797b0-0x0057a25c.SoundManagerMusicSelection.md) -> [UID:0000DG][SoundManager](by-class/SoundManager.md) -> [UID:0000NV] -> NexusTK/audio/SoundManager.cpp`.
- 2026-06-18 B003 Redbook source-quality execution:
  - Score unchanged at `90/85`.
  - Evidence: supervisor applied B003's Redbook split, created exact child pages [UID:0003ZB][0x0057b020-0x0057b152.SoundManagerOpenRedbookDrive](by-memory/0x0057b020-0x0057b152.SoundManagerOpenRedbookDrive.md)-[UID:0003ZJ][0x0057b3f0-0x0057b48d.SoundManagerRotateReusableSampleSlotRaw](by-memory/0x0057b3f0-0x0057b48d.SoundManagerRotateReusableSampleSlotRaw.md), generated `auto-generated/NexusTK/audio/SoundManager.cpp` with seven Redbook/restart method bodies, preserved raw no-entry helper bodies for later target-specific review, and documented that MusicControlDialog, TimerMgr, MidiPlayer, DAT/resource callbacks, and a separate Redbook file are weaker owner/source-placement alternatives.
- 2026-06-19 B009 [UID:0003ZJ][0x0057b3f0-0x0057b48d.SoundManagerRotateReusableSampleSlotRaw](by-memory/0x0057b3f0-0x0057b48d.SoundManagerRotateReusableSampleSlotRaw.md) implementation:
  - Score unchanged at `90/85`.
  - Evidence: incorporated the accepted source-quality decision that `0x0057b3f0-0x0057b48d` is sample/SFX slot management in the SoundManager audio source, not Redbook, `RestartMusic`, driver reinitialization, MemoryMan utility code, or generated runtime code; formal generated C++ remains blocked by absent entry route.
- 2026-06-22 Rule 26 incorporation of B015 [UID:0003ZH][0x0057b350-0x0057b36a.SoundManagerStopRedbookAndCancelTrackTimerRaw](by-memory/0x0057b350-0x0057b36a.SoundManagerStopRedbookAndCancelTrackTimerRaw.md) source-quality report:
  - Score unchanged at `90/85`.
  - Evidence: incorporated the target-specific decision that raw `0x0057b350-0x0057b36a` emits through `SoundManager` as `StopRedbookAndCancelTrackTimer()`: exact 26-byte method body, no direct branch/pointer/vtable/jump-table/timer-callback route, `AIL_redbook_stop(m_redbookHandle)`, `CancelTimer(0x504e4354)`, no `AIL_redbook_close`, no state clears, rejected non-SoundManager owners, and retained no-entry evidence as a confidence cap.
- 2026-06-27 B004 [UID:0001I8][0x005797b0-0x0057bf6e.SoundManagerAudioHelperCluster](by-memory/0x005797b0-0x0057bf6e.SoundManagerAudioHelperCluster.md) implementation:
  - Score unchanged at `90/85`.
  - Evidence: incorporated the accepted decision that UID0001I8 is a non-emitting audio-family index/container. Live MCP session `80de0a67` confirmed 53 modeled functions inside the corrected range, mixed child ownership and output decisions, SoundManager vtable/singleton lifecycle, sample-slot and Redbook evidence, driver/callback registration, and SoundPathVector/Deque interleave; exact children, not the broad aggregate, own generated source bodies.
- 2026-06-28 B013 [UID:0001IF][0x0057bf40-0x0057bf6e.SoundPathVectorClear](by-memory/0x0057bf40-0x0057bf6e.SoundPathVectorClear.md) implementation support:
  - Score unchanged at `90/85`.
  - Evidence: added current-session proof that `SoundPathVector::Clear()` now emits through the [UID:0000DI][SoundPathVector](by-class/SoundPathVector.md) route into this audio source root. The body destroys ANSI `SoundPathString` entries for the SoundManager `+0x109c` zone-music vector, and generated `SoundManager.cpp` should be refreshed by validators rather than hand-edited.
- 2026-07-03 B005 [UID:0001ID][0x0057b860-0x0057bf6e.SoundPathVector](by-memory/0x0057b860-0x0057bf6e.SoundPathVector.md) implementation support:
  - Score unchanged at `90/85`.
  - Evidence: incorporated the accepted split-first decision that UID0001ID is no longer an emitting aggregate. Exact children [UID:0004FJ][0x0057b860-0x0057b99a.SoundPathVectorGrowAndInsert](by-memory/0x0057b860-0x0057b99a.SoundPathVectorGrowAndInsert.md), [UID:0004FK][0x0057bac0-0x0057bb2a.SoundPathVectorDestructor](by-memory/0x0057bac0-0x0057bb2a.SoundPathVectorDestructor.md), [UID:0004FL][0x0057bd90-0x0057be52.SoundPathVectorReallocate](by-memory/0x0057bd90-0x0057be52.SoundPathVectorReallocate.md), helper-tail children [UID:0004FM][0x0057bc60-0x0057bcdc.SoundPathStringPrepareHelper](by-memory/0x0057bc60-0x0057bcdc.SoundPathStringPrepareHelper.md)-[UID:0004FQ][0x0057bed0-0x0057bf3e.SoundPathStringCopyConstructRangeTail](by-memory/0x0057bed0-0x0057bf3e.SoundPathStringCopyConstructRangeTail.md), and existing [UID:0001IF][0x0057bf40-0x0057bf6e.SoundPathVectorClear](by-memory/0x0057bf40-0x0057bf6e.SoundPathVectorClear.md) route through [UID:0000DI][SoundPathVector](by-class/SoundPathVector.md) into this file when source-ready.
- 2026-07-03 B003 [UID:0004FM][0x0057bc60-0x0057bcdc.SoundPathStringPrepareHelper](by-memory/0x0057bc60-0x0057bcdc.SoundPathStringPrepareHelper.md) implementation support:
  - Score unchanged at `90/85`.
  - Historical evidence: the 2026-07-03 pass correctly recovered the ANSI StringBase copy/detach/lower body and SoundManager directory-scan `.mp3` consumer but incorrectly routed it through SoundPathVector into `SoundManager.cpp`. The superseding placement is an inline `StringBase<char>::ToLower() const` specialization in `StringBase.h` or an included `.inl`; the outlined audio-near body is consumer-TU/COMDAT output. Exact public spelling and `.h`-versus-`.inl` organization remain confidence caps.
- 2026-07-03 B005 [UID:0004FP][0x0057be60-0x0057becf.SoundPathStringCopyConstructRange](by-memory/0x0057be60-0x0057becf.SoundPathStringCopyConstructRange.md) implementation support:
  - Score unchanged at `90/85`.
  - Evidence: incorporated the accepted source-ready decision that UID0004FP now emits through [UID:0000DI][SoundPathVector](by-class/SoundPathVector.md) into `NexusTK/audio/SoundManager.cpp`. The helper copy-constructs ANSI `SoundPathString` ranges for `SoundPathVector::GrowAndInsert`, returns the advanced destination pointer, and cleans up `[dest,out)` if construction fails. Exact helper spelling, `SoundPathString` typedef/header spelling, and helper/template provenance remain confidence caps; [UID:0004FQ][0x0057bed0-0x0057bf3e.SoundPathStringCopyConstructRangeTail](by-memory/0x0057bed0-0x0057bf3e.SoundPathStringCopyConstructRangeTail.md) remains a separate non-emitting child after B006's accepted pass.
- 2026-07-03 B003 [UID:0004FK][0x0057bac0-0x0057bb2a.SoundPathVectorDestructor](by-memory/0x0057bac0-0x0057bb2a.SoundPathVectorDestructor.md) implementation support:
  - Score unchanged at `90/85`.
  - Evidence: incorporated the accepted source-ready decision that UID0004FK now emits through [UID:0000DI][SoundPathVector](by-class/SoundPathVector.md) into `NexusTK/audio/SoundManager.cpp`. The destructor destroys ANSI `SoundPathString` entries in `[m_begin,m_end)`, frees the vector backing allocation, and zeroes the `m_begin`/`m_end`/`m_capacity` triplet. The dated callback MCP session `6a4af54d` replaces stale-session evidence and proves exact range/size, padding, caller/xref split, scalar-deleting-destructor and directory-scan caller contexts, body/callee semantics, rejected direct SoundManager/parent aggregate/raw naming routes, and confidence caps for final field/typedef/helper spelling.
- 2026-07-03 B006 [UID:0004FQ][0x0057bed0-0x0057bf3e.SoundPathStringCopyConstructRangeTail](by-memory/0x0057bed0-0x0057bf3e.SoundPathStringCopyConstructRangeTail.md) implementation support:
  - Score unchanged at `90/85`.
  - Evidence: incorporated the accepted range/no-code decision that UID0004FQ remains SoundPathVector-owned and non-emitting while its target range is corrected to `0x0057bed0-0x0057bf3e`. Historical B006 MCP evidence from now-stale session `fef9a7c2` proves modeled `sub_57BED0`, size `0x6e` / 110 bytes, byte `0x0057bf3d` as the final `00` of `retn 0Ch`, two-byte padding `0x0057bf3e-0x0057bf40`, one `GrowAndInsert` caller at `0x0057b927`, one StringBase share/copy callee at `0x005829f0`, and four-byte ANSI `SoundPathString` range advancement. SoundManager remains the source-file route only; SoundPathVector remains the owner.
- 2026-07-03 B007 [UID:0004FJ][0x0057b860-0x0057b99a.SoundPathVectorGrowAndInsert](by-memory/0x0057b860-0x0057b99a.SoundPathVectorGrowAndInsert.md) implementation support:
  - Score unchanged at `90/85`.
  - Evidence: incorporated the accepted no-code/source-quality decision that UID0004FJ remains SoundPathVector-owned and non-emitting while this file remains the eventual source root. Historical B007 evidence gathered while MCP session `fef9a7c2` was active proves exact `0x13a` range `0x0057b860-0x0057b99a`, full-vector callers `0x005798e9`, `0x0057acab`, and `0x0057aef5`, max-size guard `0x3fffffff`, 1.5x growth, inserted-entry construction, append and middle-insert branches, storage commit, cleanup/free/rethrow path, and padding before `0x0057b9a0`; the supervisor-verified dated MCP session for that UID0004FJ pass was `6a4af54d`. The child should stay absent from generated `SoundManager.cpp` until a future pass accepts the integrated helper contracts and exception-cleanup source shape.
- 2026-07-03 B004 [UID:0004FO][0x0057bd60-0x0057bd84.SoundPathStringDestroyRange](by-memory/0x0057bd60-0x0057bd84.SoundPathStringDestroyRange.md) implementation support:
  - Score unchanged at `90/85`.
  - Evidence: incorporated the accepted no-code/source-quality decision that UID0004FO remains a SoundPathVector-owned, non-emitting EH cleanup helper while this file remains only the audio source-family route. Historical B004 MCP evidence gathered while session `fef9a7c2` was active proves modeled `sub_57BD60`, size `0x24`, end `0x0057bd84` not a function, four-byte `[first,last)` ANSI `SoundPathString` destruction through `0x00582b30 -> 0x005832f0`, exactly one code xref at `0x0057b979` from `GrowAndInsert` cleanup/free/rethrow flow, no xref to the end address, and a non-unique signature. It should not appear as a standalone formal helper in generated `SoundManager.cpp`; rejected routes remain `Clear()`, raw `0x0057b9b0`, direct SoundManager ownership, StringBase ownership, public helper/API, and exact original helper-name proof. The supervisor-verified dated MCP session for that UID0004FO pass was `6a4af54d`.
- 2026-07-03 B008 [UID:0004FN][0x0057bce0-0x0057bd53.SoundPathVectorReplaceStorage](by-memory/0x0057bce0-0x0057bd53.SoundPathVectorReplaceStorage.md) implementation support:
  - Score unchanged at `90/85`.
  - Evidence: incorporated the accepted source-ready decision that UID0004FN emits through [UID:0000DI][SoundPathVector](by-class/SoundPathVector.md) into `NexusTK/audio/SoundManager.cpp`, while this file remains only the source root and not the direct canonical owner. The helper is first-draft `SoundPathVector::ChangeArray()`: exact `0x0057bce0-0x0057bd53` body, callers `0x0057b952` from `GrowAndInsert` and `0x0057be1b` from `Reallocate`, destruction of old ANSI `SoundPathString` entries, MSVC large-allocation guard/free behavior, and replacement of the `m_begin`/`m_end`/`m_capacity` triplet. Direct SoundManager-method ownership, generic container ownership, parent aggregate output, and blank/no-code state are rejected; exact original helper spelling remains inferred.
- 2026-07-04 B010 [UID:0004FL][0x0057bd90-0x0057be52.SoundPathVectorReallocate](by-memory/0x0057bd90-0x0057be52.SoundPathVectorReallocate.md) implementation support:
  - Score unchanged at `90/85`.
  - Evidence: incorporated the accepted source-ready decision that UID0004FL emits through [UID:0000DI][SoundPathVector](by-class/SoundPathVector.md) into `NexusTK/audio/SoundManager.cpp`, while this file remains only the source root and not the direct canonical owner. The helper is first-draft `SoundPathVector::Reallocate(int newCapacity)`: dated callback MCP session `aa3930bd` proves exact `0x0057bd90-0x0057be52` / `0xc2` body, one caller `0x0057aea5` from local music scanning, allocator `0x00421520`, `SoundPathString` copy constructor `0x005829f0`, commit call `0x0057be1b` to UID0004FN `ChangeArray()`, cleanup xref `0x006085f3 -> 0x0057b9b0`, free wrapper `0x00423e00`, generated pre-callback non-emitting state, and rejected direct SoundManager/parent aggregate/broad aggregate/generic-container/raw-label/plain `operator new[]` routes. Exact `AllocateSoundPathStringStorage` / `FreeSoundPathStringStorage` spelling remains inferred.
- 2026-07-13 B004 UID0001IA callback:
  - Score unchanged at `90/85`; this page remains the established `NexusTK/audio/` source root.
  - Added source-ready UID0001IA with exact half-open range, wide-input/ANSI-entry signature, standard vector/deque source shape, no-`FindClose` behavior, random/swap paths, and compiler EH disposition.
  - Reclassified UID0000DI/UID0001ID and all vector exact children as non-emitting compiler/STL documentation while preserving their earlier custom-emitter reports above as explicitly historical provenance.
  - Corrected UID0004FM from SoundPathVector-owned free-helper output to StringBase template-member ownership through UID0001WS; the final placement refinement makes it a header-visible inline specialization and treats the SoundManager body as consumer-TU/COMDAT output. No custom UID0004FM/SoundPathVector or authored SoundManager emitter claim remains active on this file page.

- 2026-08-06 B003 UID0001NW placement callback: propagated header-visible StringBase ownership for UID0004FM, retained the exact SoundManager consumer body as COMDAT/template-instantiation evidence, historicalized the former custom-helper/audio-source route, and converted named MCP sessions to dated evidence snapshots without deleting their findings.

## 2026-07-20 UID00028R Source Order And Lifecycle Split

- File score/path/root remain `92/93`, direct file owner, `NexusTK/audio/SoundManager.cpp`. No unrelated source inventory, accepted child, method body, score, or historical evidence was removed.
- Exact current source order is semantic global [UID:0004UF][g_pSoundManager](by-global/g_pSoundManager.md) at `0`; complete class [UID:0000DG][SoundManager](by-class/SoundManager.md) at `10`; constructor [UID:0004UG][0x00579a30-0x00579ca5.SoundManagerConstructor](by-memory/0x00579a30-0x00579ca5.SoundManagerConstructor.md) at `20`; destructor [UID:0004UH][0x00579cb0-0x00579dbf.SoundManagerDestructor](by-memory/0x00579cb0-0x00579dbf.SoundManagerDestructor.md) at `30`; playback UID0004RW-UID0004SH at `100-290`; scanner UID0001IA at `300`; Redbook UID0003ZB-UID0003ZI at `400-470`.
- At the 2026-07-20 lifecycle callback, the position-zero global destination contained a local `class SoundManager;` forward declaration and the sole `SoundManager *g_pSoundManager = 0;` module definition; the matching extern was still future work then. The 2026-08-24 header callback now emits that extern and all prerequisites in UID0004UF H without duplicating the CPP definition.

### Exact Authored Lifecycle Source

- Constructor `[0x00579a30,0x00579ca5)` follows the sole startup allocation of exact size `0x10ac`. It preserves the observed legacy Config option order, calls `ReinitializeAudioDriver`, reapplies music/SFX volume/output settings on driver success, caches 1000 `%03d.wav` DAT payload pointers, resets zone state, and scans the configured local music directory.
- Destructor `[0x00579cb0,0x00579dbf)` releases eight non-null sample handles when the driver exists, closes stream and driver, releases Miles timers/runtime, then stops/closes/resets Redbook state with timer token `0x504e4354` cancelled twice in observed order.
- Constructor/destructor source omits direct singleton writes, vptr stores, raw offsets, vector member construction/destruction, TimerHandler base mechanics, EH funclets, scalar flags/free, and decompiler labels.

### Compiler-Only Children And One-Definition Policy

- [UID:0004UI][0x0057b9a0-0x0057b9ab.SoundManagerConstructorUnwindSingletonClear](by-memory/0x0057b9a0-0x0057b9ab.SoundManagerConstructorUnwindSingletonClear.md) is an exact 11-byte constructor EH direct-base cleanup and emits no source.
- [UID:0004UJ][0x0057bb30-0x0057bc59.SoundManagerScalarDeletingDestructor](by-memory/0x0057bb30-0x0057bc59.SoundManagerScalarDeletingDestructor.md) is the vtable-only scalar wrapper, including repeated cleanup, delete flag test, and conditional free; it emits no source.
- [UID:0004UK][0x0062ce78-0x0062ce84.SoundManagerVtableData](by-memory/0x0062ce78-0x0062ce84.SoundManagerVtableData.md) is compiler-generated COL/vtable data and emits no source.
- Direct `Singleton<SoundManager>` inheritance explains publication `0x00579a67`, fallback clear `0x00579a6e`, ordinary clear `0x00579da3`, EH clear `0x0057b9a0`, and scalar clear `0x0057bc29`. The physical backing page remains false/non-emitting so only UID0004UF defines storage.

### Existing Union Preservation

- Historical lifecycle-pass state left UID0001I7 and UID0001IC as broad blank-formal emitters. UID0001IC is now superseded by its exact method page plus exact driver/callback children; UID0001I7 remains outside this callback's scope.
- UID0001I8 remains a false/non-emitting 53-function audio-family index. UID00026I remains a false/non-emitting mixed `.rdata` index. Existing playback, scanner, Redbook, sample-slot, callback, DAT, Config, Application, TimerHandler, DirectSound, standard-container, and StringBase facts remain unchanged.
- Physical predecessor/successor globals, Application shutdown, Config, DATFile/DATFileMgr, TimerMgr, consumer panes, ignored padding, and all other report dependencies were verify-only unless a contradiction appeared; no contradiction required broader edits.

### Generated Requirements

- Generated `SoundManager.cpp` must contain one semantic pointer definition before use, one class with `Singleton<SoundManager>, public TimerHandler`, one constructor at position 20, and one ordinary destructor at position 30.
- It must contain zero UID00028R/UID0004UI/UID0004UJ/UID0004UK empty markers or definitions and no duplicate global/lifecycle body.
- Existing playback/scanner/Redbook definitions remain intact. The historical UID0001IC aggregate marker is intentionally eliminated by its exact method formal and child split; UID0001I7 remains unchanged.
- No compiler/decompiler-shaped source is allowed: no cookie, raw label, vptr, explicit Singleton publication/clear, EH label, scalar flag/free, vector/base teardown, or address constant.

## 2026-07-20 UID00028R Change Log

- Preserved score `92/93`, path/root, and complete current source inventory.
- Added semantic global UID0004UF at position 0, class direct-Singleton relationship at 10, exact source constructor/destructor UID0004UG/UID0004UH at 20/30, compiler-only UID0004UI/UID0004UJ/UID0004UK inventory, exact source/compiler separation, and generated uniqueness rules.
