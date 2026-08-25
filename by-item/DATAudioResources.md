*** UID:0000UB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DAT Audio Resources

## Status

- Queue status: ignored/not scored for source-coverage work.
- Entity kind: resource-use pattern spanning DAT archive helpers and `SoundManager`.
- Rebuild handling: not reconstructable as a standalone item. The source-authored behavior belongs to the linked `SoundManager`, DAT archive, and helper pages.
- Primary owner: [UID:0000DG][SoundManager](by-class/SoundManager.md)
- Main address doc: [UID:0001I8][0x005797b0-0x0057bf6e.SoundManagerAudioHelperCluster](by-memory/0x005797b0-0x0057bf6e.SoundManagerAudioHelperCluster.md)
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
- IDA MCP decompilation confirms those existence checks call [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md), so document them as DAT archive probes rather than generic filesystem checks.
- `.LST` selects a sequential playlist; `.LSR` selects a randomized playlist; direct `.MP3` falls back to a single track.
- `SoundManager::LoadTrackListFromFile` at `0x005797b0` opens the `.LST` or `.LSR` file through `DATFile`, reads the first line as a track count, then converts each track ID line to `%08d.MP3`.
- B002's 2026-06-17 source-quality pass confirms this policy from current IDA evidence and distinguishes DAT stream mode from local-directory mode: DAT playlists/direct entries use DATArchive lookup/open/read, while local user music uses scanned loose MP3 paths owned by SoundManager.

The class also has a separate local music-directory scan path using `FindFirstFileA` and `g_strMusicExtension`. DAT-backed zone music and user-selected loose music files should therefore be documented as separate input modes inside the same audio manager.

## Coverage Handling

This page is retained as a resource-policy ledger only. It documents how the audio manager chooses DAT-backed names and archive services, but it is not a source function, class, type, global, memory range, standalone data declaration, or source file. Keep `RECONSTRUCTABLE:FALSE`, `AUTOGEN_PARENT_UID` blank, and C++ blank.

Use the linked `SoundManager` and DAT archive pages for reconstructable code coverage. Payload handoff details should raise or refine those owning pages, not make this ledger emit code or appear in the low-completion queue.

## Source-Structure Implication

This evidence should not move audio code into the DAT archive module. `DATFile`, `DATFileMgr`, and [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md) remain archive-layer services. `SoundManager` is the audio owner and should keep the `.wav`, `.lst`, `.lsr`, and `.mp3` policy, with a dependency on the archive API.

## Source-Quality Decisions And Remaining Limits

- `.LST` and `.LSR` playlist semantics are no longer open at the policy level: `.LST` is sequential, `.LSR` is randomized, and `LoadTrackListFromFile` reads a first-line count followed by decimal track IDs that are expanded to `%08d.MP3`.
- DAT-backed MP3 and loose music-directory MP3 paths share SoundManager stream-opening policy, but their source of path data differs. DAT mode probes `%08d.LST`, `%08d.LSR`, and `%08d.MP3` through archive helpers; local-directory mode consumes the scanned `m_localMusicPaths` vector.
- The exact lifetime contract between DAT-backed WAV payload pointers and Miles AIL sample objects remains child-method evidence work for SoundManager constructor/sample pages. It does not make this resource-policy ledger reconstructable or move ownership into DATArchive.

## Cross-References

- [UID:0000DG][SoundManager](by-class/SoundManager.md)
- [UID:0000NV][SoundManager](by-file/SoundManager.md)
- [UID:0001I8][0x005797b0-0x0057bf6e.SoundManagerAudioHelperCluster](by-memory/0x005797b0-0x0057bf6e.SoundManagerAudioHelperCluster.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md)
- [UID:00012E][0x0049c700-0x0049c71d.HasDATEntry](by-memory/0x0049c700-0x0049c71d.HasDATEntry.md)
- [UID:0000UC][DATEntryRecord](by-item/DATEntryRecord.md)

## Changes

- 2026-06-05: Reconstructable metadata changed from blank to `FALSE`.
  - Before: the DAT audio resource-use note was unclassified in autogen coverage.
  - After: it is explicitly marked non-reconstructable as a standalone item because it is a resource-policy ledger; the source-authored behavior belongs to the linked SoundManager and DAT archive pages.
  - Evidence: the page documents `.wav`/`.LST`/`.LSR`/`.MP3` naming policy and archive dependencies, not a distinct source function, data declaration, or type that should emit C++ from this item.

- 2026-05-30: Grading changed from `0/0` to `72/82`.
  - Before: page documented DAT-backed sound effect and zone music selection behavior with open decoded-payload questions but remained unevaluated.
  - After: score reflects documented SoundManager DAT lookup policy, `.wav`/`.LST`/`.LSR`/`.MP3` naming behavior, DAT archive dependency, and separate loose-file music mode, with lower completion for unresolved payload handoff details.
  - Evidence: IDA notes in linked SoundManager/DAT pages confirm `%03d.wav` sound scanning, zone playlist existence checks through [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md), and `DATFile` reads for track-list payloads.
- 2026-06-06: Changed completion/confidence from `72/82` to `-1/-1`.
  - Before: the page appeared in the low-completion queue even though `RECONSTRUCTABLE:FALSE` already identified it as a non-code resource-policy ledger.
  - After: marked ignored/not scored so source-coverage work stays focused on reconstructable `SoundManager`, DAT archive, and helper pages.
  - Evidence: this page has no standalone source owner, address range, type, global, or data declaration to emit; it summarizes naming/resource policy that must be reconstructed through the linked owning source pages.
- 2026-06-17 B002 SoundManager music-selection execution:
  - Score remains ignored/not scored at `-1/-1`.
  - Evidence: B002's current IDA pass confirms `.LST` sequential playlist, `.LSR` randomized playlist, direct `%08d.MP3` fallback, local-directory mode separation, and SoundManager ownership of resource naming policy.
