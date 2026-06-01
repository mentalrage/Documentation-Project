*** UID:0000NV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# SoundManager

## Status

- Confidence: medium to strong
- Proposed module: `audio/SoundManager.cpp`
- Current Wave3 file: `class_SoundManager.cpp`
- Main class: [UID:0000DG][SoundManager](by-class/SoundManager.md)
- Main address doc: [UID:0001I8][0x005797b0-0x0057bc58.SoundManager](by-memory/0x005797b0-0x0057bc58.SoundManager.md)
- Evidence basis: `simroot_v2` generated source, Wave3 metadata, read-only Wave3 class inspection while status was `OPERATIONAL`, IDA MCP decompilation/lookup/import checks on 2026-05-22 through 2026-05-25, and local runtime file metadata recorded in [UID:0001QE][client_libraries](by-meta/client_libraries.md).

## Hypothesis

The original client likely had a dedicated audio source file for the `SoundManager` class rather than scattering music, sound-effect, and resource-selection logic across archive or UI files. The class owns Miles Sound System initialization, DAT-backed sound-effect preloading, DAT-backed zone music selection, loose music-directory scanning, and playback state transitions.

## Contents

Likely source-level contents:

- `SoundManager` class implementation.
- [UID:0000DI][SoundPathVector](by-class/SoundPathVector.md) as a private or neighboring audio path-vector helper for playlist and scanned-file storage.
- [UID:0001IF][0x0057bf40-0x0057bf6e.SoundPathVectorClear](by-memory/0x0057bf40-0x0057bf6e.SoundPathVectorClear.md) as the track-filename/path-vector clear helper used by music selection fallback paths.
- Playlist loading from `.LST` and `.LSR` DAT entries.
- `%03d.wav` sound-effect lookup/preload policy.
- `%08d.MP3` zone-track naming policy.
- Local music directory scanning and randomization.
- Redbook/CD and stream control helpers.
- Miles AIL file callbacks at `0x0057b630-0x0057b7e7`; see [UID:0000TU][AILFileOpenCallback_0057B630](by-item/AILFileOpenCallback_0057B630.md).
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
- `PlayMusicByZone` `0x0057a0b0`: checks `%08d.LST`, `%08d.LSR`, and `%08d.MP3` through [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md).
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
- [UID:0000P4][VideoPlayerPane](by-file/VideoPlayerPane.md) / [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md) use Bink Video, but the audio coupling is narrow: Bink setup asks `SoundManager::GetDirectSound` for the DirectSound object and passes it to `BinkSetSoundSystem(BinkOpenDirectSound, ...)`.

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

## Open Questions

- Whether the original project used `sound/` instead of `audio/` for this folder.
- Whether Redbook helpers were part of `SoundManager.cpp`; current evidence favors a separate [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md) file for WinMM MIDI state.
- Which globals should be declared with `SoundManager` versus app/config modules.

## Cross-References

- [UID:0000DG][SoundManager](by-class/SoundManager.md)
- [UID:0001I8][0x005797b0-0x0057bc58.SoundManager](by-memory/0x005797b0-0x0057bc58.SoundManager.md)
- [UID:0001I7][0x005797b0-0x0057a25c.SoundManagerMusicSelection](by-memory/0x005797b0-0x0057a25c.SoundManagerMusicSelection.md)
- [UID:0001I9][0x0057a260-0x0057a88e.SoundManagerPlaybackControls](by-memory/0x0057a260-0x0057a88e.SoundManagerPlaybackControls.md)
- [UID:0001IA][0x0057a890-0x0057afcd.SoundManagerMusicDirectoryScan](by-memory/0x0057a890-0x0057afcd.SoundManagerMusicDirectoryScan.md)
- [UID:0001IB][0x0057b020-0x0057b48a.SoundManagerRedbookPlayback](by-memory/0x0057b020-0x0057b48a.SoundManagerRedbookPlayback.md)
- [UID:0001IC][0x0057b490-0x0057bc58.SoundManagerDriverAndDestructor](by-memory/0x0057b490-0x0057bc58.SoundManagerDriverAndDestructor.md)
- [UID:0000DI][SoundPathVector](by-class/SoundPathVector.md)
- [UID:0001ID][0x0057b860-0x0057bf6e.SoundPathVector](by-memory/0x0057b860-0x0057bf6e.SoundPathVector.md)
- [UID:0001IF][0x0057bf40-0x0057bf6e.SoundPathVectorClear](by-memory/0x0057bf40-0x0057bf6e.SoundPathVectorClear.md)
- [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md)
- [UID:0000RM][g_pMidiPlayer](by-global/g_pMidiPlayer.md)
- [UID:0001K9][0x00597610-0x00597645.TimerHandlerWrappers](by-memory/0x00597610-0x00597645.TimerHandlerWrappers.md)
- [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md)
- [UID:0000LN][MusicControlDialog](by-file/MusicControlDialog.md)
- [UID:0000UB][DATAudioResources](by-item/DATAudioResources.md)
- [UID:0000TU][AILFileOpenCallback_0057B630](by-item/AILFileOpenCallback_0057B630.md)
- [UID:0000JD][FileIO](by-file/FileIO.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)
- [UID:0001Q8][client_audio](by-meta/client_audio.md)
- [UID:0001QE][client_libraries](by-meta/client_libraries.md)
- [UID:0001QX][README](by-meta/obtained_thirdparty_files/README.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)

## Changes

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `90` and confidence to `82`.
  - Evidence: document covers audio module hypothesis, source contents, archive and middleware dependencies, Miles/Bink/MIDI split, IDA/import evidence, proposed placement, open questions, and cross-references; confidence is capped by exact folder/source split and global ownership questions.
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)
