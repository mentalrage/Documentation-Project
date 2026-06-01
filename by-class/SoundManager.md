*** UID:0000DG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SoundManager

## Status

- Confidence: strong for class ownership and core audio role, medium for exact field names.
- Current Wave3 file: `class_SoundManager.cpp`
- Likely source module: [UID:0000NV][SoundManager](by-file/SoundManager.md)
- Current relevant range: `0x005797b0-0x0057bc58`
- Main address doc: [UID:0001I8][0x005797b0-0x0057bc58.SoundManager](by-memory/0x005797b0-0x0057bc58.SoundManager.md)
- Evidence basis: `simroot_v2` generated source, Wave3 metadata, and targeted IDA MCP decompilation/lookup checks on 2026-05-22, 2026-05-23, and 2026-05-24.

## Responsibility

`SoundManager` is the client audio manager. It initializes Miles Sound System state, caches DAT-backed WAV sound effects, selects zone music from DAT-backed `.LST`, `.LSR`, and `.MP3` entries, supports user music-directory scanning, and manages stream/CD playback state.

## Key Data

Current Wave3 notes identify:

- `mbr_0x8`: Miles AIL digital driver.
- `mbr_0xc`: enabled/playback flag.
- `mbr_0x10`: stream volume or stream-control value.
- `mbr_0x14`: AIL stream handle.
- `mbr_0x18`: Redbook/CD handle.
- `mbr_0x41`: sound-effect enabled flag.
- `mbr_0x44`: sound-effect volume.
- `mbr_0x48-0x87`: sample-slot state.
- `mbr_0x1098`: current zone or playlist ID.
- `mbr_0x1028` and `mbr_0x109c-0x10a4`: [UID:0000DI][SoundPathVector](by-class/SoundPathVector.md)-style path vectors used by scanned music paths and zone playlist storage.

Field names above should be treated as working names until the class layout is reviewed as a whole.

## DAT-Backed Resources

The constructor at `0x00579a30` scans `%03d.wav` entries for IDs `0..999` through [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md), opens matching entries with `DATFile`, and caches data pointers from `DATFile::GetDataPointer`.

`PlayMusicByZone` at `0x0057a0b0` checks `%08d.LST`, `%08d.LSR`, and `%08d.MP3` through [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md). `LoadTrackListFromFile` at `0x005797b0` opens playlist files through `DATFile` and converts line-based track IDs into `%08d.MP3` names.

The DAT-backed path coexists with local music-directory scanning through `FindFirstFileA` and `g_strMusicExtension`.

## Important Methods

| Address | Current name | Notes |
| --- | --- | --- |
| `0x005797b0` | `LoadTrackListFromFile` | Reads DAT-backed `.LST`/`.LSR` playlist files into the playlist vector. |
| `0x00579950` | `StopStreamAndReset` | Stops stream playback and posts/reset stream events. |
| `0x00579a30` | constructor | Initializes audio state, Miles driver state, and DAT-backed sound-effect pointer table. |
| `0x0057a0b0` | `PlayMusicByZone` | Selects zone music from DAT-backed playlists or direct MP3 entries. |
| `0x0057a260-0x0057a88e` | playback controls | Stream stop, volume, mute/unmute, pause, next track, sample playback, SFX state, DirectSound access, and timer dispatch. |
| `0x0057a890` | `ScanMusicDirectory` | Recursively scans loose local music files with `FindFirstFileA`. |
| `0x0057b020-0x0057b48a` | Redbook helpers | Opens/closes/plays/advances/rewinds/pauses Redbook/CD playback and restarts music mode. |
| `0x0057b490` | `ReinitializeAudioDriver` | Restarts Miles, configures DirectSound HWND, registers file callbacks, and allocates sample handles. |
| `0x0057bb30` | `ScalarDeletingDestructor` | Compiler-generated deleting destructor wrapper for `SoundManager`. |

## Ownership Notes

- This class should stay in an audio module, not the archive module.
- DAT dependencies are API-level resource lookups, similar to rendering callers of [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md).
- Application activation and options/config UI call into `SoundManager`, but those callers should remain in their feature modules.
- [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md) is a HUD/UI consumer for hotkeys and status text; it should not be folded into the audio engine source.
- [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md) owns the WinMM MIDI singleton and [UID:0000RM][g_pMidiPlayer](by-global/g_pMidiPlayer.md). `SoundManager` can call MIDI pause/resume behavior, but should not absorb MIDI buffer/reset implementation.
- [UID:0000DI][SoundPathVector](by-class/SoundPathVector.md) is an audio path-vector helper used by SoundManager path storage; keep it with audio path management unless broader non-audio callers are found. IDA confirms [UID:0001IF][0x0057bf40-0x0057bf6e.SoundPathVectorClear](by-memory/0x0057bf40-0x0057bf6e.SoundPathVectorClear.md) is called from track selection and zone-music fallback paths.
- Active `simroot_v2` still emits timer wrappers `0x00597610` and `0x00597630` as `SoundManager` methods. IDA decompilation and callers show these are generic [UID:0001K9][0x00597610-0x00597645.TimerHandlerWrappers](by-memory/0x00597610-0x00597645.TimerHandlerWrappers.md), so they should not be migrated with this class.

## Open Questions

- Confirm the exact Miles AIL sample path for cached DAT-backed WAV pointers.
- Confirm which fields correspond to music mode, current stream path, and Redbook fallback state.

## Cross-References

- [UID:0000NV][SoundManager](by-file/SoundManager.md)
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
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)
- [UID:0001Q8][client_audio](by-meta/client_audio.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md)
- [UID:00012E][0x0049c700-0x0049c71d.HasDATEntry](by-memory/0x0049c700-0x0049c71d.HasDATEntry.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `86`, confidence `80`.
- Evidence: the page documents the audio-manager responsibility, DAT/resource paths, major methods, playback subsystems, owned helper relationships, generic timer-wrapper exclusion, and cross-subsystem references; confidence remains capped by exact field names and unresolved Miles/sample-path details.
