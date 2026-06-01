*** UID:0001Q8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Client Audio

## Status

- Confidence: strong for current source-family split; medium for exact original folder name.
- Scope: audio source ownership, resource paths, and UI consumers.
- Evidence basis: Wave3 read-only class inspection for `SoundManager`, `MidiPlayer`, and `SoundPathVector`; `simroot_v2`; IDA MCP import/string checks; and local runtime file metadata recorded in [UID:0001QE][client_libraries](by-meta/client_libraries.md) and [UID:0001QX][README](by-meta/obtained_thirdparty_files/README.md). Wave3 status was `OPERATIONAL` when read-only checks were run on 2026-05-25.

## Current Findings

The client audio subsystem is split across at least two implementation families:

- [UID:0000NV][SoundManager](by-file/SoundManager.md) owns Miles Sound System setup, DAT-backed `%03d.wav` sound-effect caching, DAT-backed `%08d.LST`/`%08d.LSR`/`%08d.MP3` zone music selection, loose music-directory scanning, Redbook/CD fallback, and Miles file callbacks.
- [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md) owns WinMM MIDI stream state, MIDI buffer/header lifetime, MIDI stop/reset behavior, and the [UID:0000RM][g_pMidiPlayer](by-global/g_pMidiPlayer.md) singleton.

Audio path storage uses [UID:0000DI][SoundPathVector](by-class/SoundPathVector.md), a three-pointer vector restored from missing-reference data and used by SoundManager playlist/scanned-path storage. Current evidence favors keeping this helper with `audio/SoundManager.cpp` or a small neighboring audio helper file rather than a generic container module.

## Runtime And Middleware Boundary

Audio rebuild work should separate NexusTK-owned source from external runtimes:

| Layer | Evidence | Rebuild owner |
| --- | --- | --- |
| Miles Sound System | IDA imports 37 `_AIL_*` APIs from `mss32`, including sample, stream, Redbook, file-callback, DirectSound, and startup/shutdown functions. Local runtime files are `Mss32.dll` and `Mp3dec.asi`, both version `6.1c`. | External runtime/import library. Use files in [UID:0001QX][README](by-meta/obtained_thirdparty_files/README.md) or a licensed Miles SDK. Keep local wrapper logic in [UID:0000NV][SoundManager](by-file/SoundManager.md). |
| Bink audio bridge | IDA imports `_BinkSetSoundSystem@8`, `_BinkOpenDirectSound@4`, and `_BinkOpenMiles@4` from `binkw32`; `OpenBinkVideo` obtains DirectSound through [UID:0000NV][SoundManager](by-file/SoundManager.md). Local `binkw32.dll` version is `1.0s`. | External Bink runtime. Keep video playback in [UID:0000P4][VideoPlayerPane](by-file/VideoPlayerPane.md) / [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md), with only the DirectSound bridge touching audio source. |
| WinMM MIDI | IDA imports `midiStreamOpen`, `midiStreamOut`, `midiStreamStop`, `midiStreamRestart`, `midiStreamPause`, `midiStreamClose`, `midiOutPrepareHeader`, `midiOutUnprepareHeader`, `midiOutReset`, and related timer APIs from `WINMM`. | Windows SDK/system import library. Keep stream control and callback state in [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md). |
| DAT/loose file audio resources | `%03d.wav`, `%08d.LST`, `%08d.LSR`, `%08d.MP3`, Miles file callbacks, `DATFile`, and `StdioFile` evidence. | NexusTK source in [UID:0000NV][SoundManager](by-file/SoundManager.md), using archive and file-IO services as dependencies. |

Do not reconstruct Miles or Bink internals as NexusTK source. Do not place WinMM MIDI stream implementation under `SoundManager` just because the UI presents both music systems together. Do not move `DATFile` or `StdioFile` into audio; only the Miles callback glue belongs in `SoundManager`.

IDA MCP recheck on 2026-05-25 confirms the MIDI omitted-helper family and SoundPathVector boundary caveats: `0x00525be0` is the WinMM MIDI callback, `0x00525920` opens/primes the MIDI stream, `0x00526100-0x00526332` selects/starts MIDI tracks, `0x005270e0` releases MIDI document resources, `SoundPathVector::GrowAndInsert` is `0x0057b860-0x0057b99a`, `SoundPathVector::Reallocate` is `0x0057bd90-0x0057be52`, and `0x0057bf40` is a vector clear helper used by SoundManager track filename storage.

IDA MCP recheck on 2026-05-26 confirms those ownership decisions remain current. `simroot_v2` still omits active `.cpp` bodies for the MIDI open/callback/select/start/document helpers and for `SoundPathVector::Clear`, but IDA callers keep them inside the `MidiPlayer` and SoundManager path-vector source families rather than separate original files.

IDA MCP recheck on 2026-05-28 resolves the former `0x0052664b-0x005270e0` unknown range as boundary padding plus [UID:00023B][0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers](by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md), a Standard MIDI File reader/parser helper island that should stay with the WinMM `MidiPlayer` module.

The same 2026-05-28 pass resolves the former `0x005271a3-0x005277c0` unknown range as boundary padding plus [UID:00023C][0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers](by-memory/0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers.md), which loads `MThd`/`MTrk` track tables and fills WinMM stream buffers.

UI consumers remain outside the audio engine:

- [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md) owns HUD text and hotkeys for sound/music toggles.
- [UID:0000LN][MusicControlDialog](by-file/MusicControlDialog.md) owns the user-facing music-control dialog and folder selection policy.
- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md), [UID:00000V][BaramApp](by-class/BaramApp.md), and application startup/shutdown paths call into the audio singletons but should not own playback implementation.

## DAT And Local Files

DAT-backed audio resources belong to `SoundManager` as policy over the archive API:

- `%03d.wav` sound effects are checked and cached during `SoundManager` construction.
- `%08d.LST`, `%08d.LSR`, and `%08d.MP3` zone music paths are checked by `SoundManager::PlayMusicByZone` and `LoadTrackListFromFile`.
- Miles file callbacks installed by `SoundManager::ReinitializeAudioDriver` open DAT entries first and fall back to loose files.

Loose user music is separate from DAT-backed zone music and is scanned through Win32 file enumeration and `g_strMusicExtension`.

## Source-Structure Guidance

Current proposed layout:

```text
audio/
  SoundManager.cpp
  MidiPlayer.cpp
```

`SoundPathVector` can start as a private helper documented under `SoundManager`; promote it to `audio/SoundPathVector.cpp` only if later evidence shows a standalone original file or broader non-SoundManager callers.

External and system dependencies should sit outside this source folder:

```text
third_party_or_runtime/
  mss32.dll
  Mp3dec.asi
  binkw32.dll
windows_sdk/
  winmm.lib
```

The current documentation stash keeps obtained runtime copies under [UID:0001QX][README](by-meta/obtained_thirdparty_files/README.md), but the proposed source tree should model them as runtime dependencies, not `.cpp` source files.

## Open Questions

- Whether the original folder was named `audio`, `sound`, or kept flat in the Visual C++ project.
- Exact final names for the raw MIDI stream-state globals grouped in [UID:0000T9][MidiPlayerWinMMState](by-global/MidiPlayerWinMMState.md).
- Whether active generated output should materialize omitted MIDI helpers as private `MidiPlayer.cpp` functions or class methods.
- Whether generated `SoundPathVector` metadata should adopt the IDA-confirmed longer ranges and the omitted `Clear` helper.
- Whether the final build should link Miles by import library only or keep the current late-bound/imported DLL arrangement exactly as observed.
- Whether Bink should continue using `BinkOpenDirectSound` through `SoundManager::GetDirectSound` or switch to the imported `BinkOpenMiles` path in a compatibility rebuild. The observed video helper uses DirectSound.

## Cross-References

- [UID:0000NV][SoundManager](by-file/SoundManager.md)
- [UID:0000DG][SoundManager](by-class/SoundManager.md)
- [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md)
- [UID:00008A][MidiPlayer](by-class/MidiPlayer.md)
- [UID:0000DI][SoundPathVector](by-class/SoundPathVector.md)
- [UID:0000RM][g_pMidiPlayer](by-global/g_pMidiPlayer.md)
- [UID:0000T9][MidiPlayerWinMMState](by-global/MidiPlayerWinMMState.md)
- [UID:0001I8][0x005797b0-0x0057bc58.SoundManager](by-memory/0x005797b0-0x0057bc58.SoundManager.md)
- [UID:0001CF][0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers](by-memory/0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers.md)
- [UID:0001CG][0x00525be0-0x00525dbb.MidiStreamCallback](by-memory/0x00525be0-0x00525dbb.MidiStreamCallback.md)
- [UID:00023B][0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers](by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md)
- [UID:00023C][0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers](by-memory/0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers.md)
- [UID:0001ID][0x0057b860-0x0057bf6e.SoundPathVector](by-memory/0x0057b860-0x0057bf6e.SoundPathVector.md)
- [UID:0000UB][DATAudioResources](by-item/DATAudioResources.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)
- [UID:0001QE][client_libraries](by-meta/client_libraries.md)
- [UID:0001QX][README](by-meta/obtained_thirdparty_files/README.md)
