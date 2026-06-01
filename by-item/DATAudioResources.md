*** UID:0000UB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DAT Audio Resources

## Status

- Confidence: strong for DAT-backed sound-effect and zone-music resource selection, medium for exact decoded audio payload handling.
- Entity kind: resource-use pattern spanning DAT archive helpers and `SoundManager`.
- Primary owner: [UID:0000DG][SoundManager](by-class/SoundManager.md)
- Main address doc: [UID:0001I8][0x005797b0-0x0057bc58.SoundManager](by-memory/0x005797b0-0x0057bc58.SoundManager.md)
- Archive dependency: [UID:0000IM][DATArchive](by-file/DATArchive.md)

## Behavior

`SoundManager` uses DAT archive lookups for both sound effects and zone music selection.

Sound effects:

- `SoundManager::SoundManager` at `0x00579a30` formats names as `%03d.wav` for IDs `0..999`.
- For each generated name, it calls [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md).
- If the entry exists, it constructs a `DATFile`, opens the entry, stores `DATFile::GetDataPointer()` into the sound-effect pointer table, then closes and destroys the `DATFile`.
- This points to raw DAT payload memory being handed to the Miles Sound System sample path, but the exact WAV handoff and lifetime contract still need a deeper method review.

Zone music:

- `SoundManager::PlayMusicByZone` at `0x0057a0b0` builds `%08d.LST`, `%08d.LSR`, and `%08d.MP3` names for a zone ID.
- IDA MCP decompilation confirms those existence checks call [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md), even though current generated source labels them generically as `FileExists`.
- `.LST` selects a sequential playlist; `.LSR` selects a randomized playlist; direct `.MP3` falls back to a single track.
- `SoundManager::LoadTrackListFromFile` at `0x005797b0` opens the `.LST` or `.LSR` file through `DATFile`, reads the first line as a track count, then converts each track ID line to `%08d.MP3`.

The class also has a separate local music-directory scan path using `FindFirstFileA` and `g_strMusicExtension`. DAT-backed zone music and user-selected loose music files should therefore be documented as separate input modes inside the same audio manager.

## Source-Structure Implication

This evidence should not move audio code into the DAT archive module. `DATFile`, `DATFileMgr`, and [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md) remain archive-layer services. `SoundManager` is the audio owner and should keep the `.wav`, `.lst`, `.lsr`, and `.mp3` policy, with a dependency on the archive API.

## Open Questions

- Confirm whether Miles AIL consumes the DAT-backed WAV payload directly or copies/decodes it into sample objects first.
- Confirm the exact stream path for DAT-backed MP3 payloads versus loose music-directory MP3 files.
- Confirm whether `.LST` and `.LSR` payload lines are always ASCII decimal track IDs with a decimal count on the first line.

## Cross-References

- [UID:0000DG][SoundManager](by-class/SoundManager.md)
- [UID:0000NV][SoundManager](by-file/SoundManager.md)
- [UID:0001I8][0x005797b0-0x0057bc58.SoundManager](by-memory/0x005797b0-0x0057bc58.SoundManager.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md)
- [UID:00012E][0x0049c700-0x0049c71d.HasDATEntry](by-memory/0x0049c700-0x0049c71d.HasDATEntry.md)
- [UID:0000UC][DATEntryRecord](by-item/DATEntryRecord.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `72/82`.
  - Before: page documented DAT-backed sound effect and zone music selection behavior with open decoded-payload questions but remained unevaluated.
  - After: score reflects documented SoundManager DAT lookup policy, `.wav`/`.LST`/`.LSR`/`.MP3` naming behavior, DAT archive dependency, and separate loose-file music mode, with lower completion for unresolved payload handoff details.
  - Evidence: IDA notes in linked SoundManager/DAT pages confirm `%03d.wav` sound scanning, zone playlist existence checks through [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md), and `DATFile` reads for track-list payloads.
