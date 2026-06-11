*** UID:0000RM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LD | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pMidiPlayer

## Status

- Confidence: strong for identity, owner, lifecycle writes, and representative consumers.
- Symbol kind: global singleton pointer.
- Address: [UID:00029A][0x0067ab4c-0x0067ab50.g_pMidiPlayer](by-memory/0x0067ab4c-0x0067ab50.g_pMidiPlayer.md)
- Likely owner: [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md)

## Role

`g_pMidiPlayer` stores the active [UID:00008A][MidiPlayer](by-class/MidiPlayer.md) singleton. The `MidiPlayer` constructor assigns it, and the destructor clears it after stopping/resetting playback, releasing MIDI buffers, closing the stream, and closing the buffer-return event.

UI and application code use this global to pause/resume/stop MIDI playback or to pair MIDI toggles with broader music/sound state changes.

## Evidence

- [UID:00029A][0x0067ab4c-0x0067ab50.g_pMidiPlayer](by-memory/0x0067ab4c-0x0067ab50.g_pMidiPlayer.md) documents the exact four-byte `.data` slot as `MidiPlayer *g_pMidiPlayer;`.
- Live IDA MCP on 2026-06-06 reports 18 xrefs to `0x0067ab4c` and confirms the slot is initialized to `0xffffffff`.
- Constructor refs at `0x00525dff` and `0x00525e06` publish or clear the slot during construction, and the destructor ref at `0x00525f1e` clears it during teardown.
- Consumer refs cover Application cleanup, main-menu/music-control paths, BaramApp activation/deactivation helpers, SoundStatusPane/music status code, and MIDI playback helpers at `0x00526570` and `0x00526580`.
- Unreviewed consumer-side references should be renamed only after the surrounding methods are reviewed, but they do not change owner placement.

## Known Users

- [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md): constructor/destructor ownership and playback methods.
- [UID:0000NV][SoundManager](by-file/SoundManager.md): pause/resume calls during broader music playback transitions.
- [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md): hotkey handling and status refresh for music/MIDI state.
- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md): stops current MIDI playback when menu actions require it.
- [UID:00000V][BaramApp](by-class/BaramApp.md): activation/deactivation paths call MIDI enable/disable helpers.

## Ownership Guidance

Declare this with `audio/MidiPlayer.cpp` or its header. Do not assign the storage to `SoundStatusPane`; that pane is a UI consumer. Do not assign it to `SoundManager` unless later evidence shows a monolithic original audio file, because `MidiPlayer` is the constructor/destructor owner.

## Cross-References

- [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md)
- [UID:00008A][MidiPlayer](by-class/MidiPlayer.md)
- [UID:00029A][0x0067ab4c-0x0067ab50.g_pMidiPlayer](by-memory/0x0067ab4c-0x0067ab50.g_pMidiPlayer.md)
- [UID:0001CF][0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers](by-memory/0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers.md)
- [UID:0000NV][SoundManager](by-file/SoundManager.md)
- [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md)
- [UID:0001Q8][client_audio](by-meta/client_audio.md)

## Changes

- 2026-05-30: Previously this page carried a stale `0/0` completion/confidence score and cited only weak references for `0x0067ab4c`. It now links the exact singleton storage page, records constructor/destructor ownership, and calls out unresolved consumer-name caveats. Score changed to `78/80` because exact storage and lifecycle are well supported, but some consumer declarations remain unresolved.

- 2026-06-05 autogen classification:
  - What existed before: autogen metadata was blank, so the singleton was reported as unclassified.
  - Changed to: `RECONSTRUCTABLE:TRUE` with `AUTOGEN_PARENT_UID:0000LD`; `RECONSTRUCTION_CPP CODE` remains empty.
  - Summary/evidence: live IDA MCP `xrefs_to 0x0067ab4c` and decompilation of `0x00525dc0` / `0x00525eb0` prove NexusTK-owned `MidiPlayer` singleton storage owned by [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md). No final C++ body was added because the page is below the 95/95 reconstruction gate.
- 2026-06-06 source-facing cleanup:
  - What existed before: score `78/80`, raw storage labels in evidence, and stale coverage-row caveats.
  - Changed to: score `84/88`, refreshed live xref/byte evidence, source-facing singleton wording, and synced the manual by-global coverage row.
  - Summary/evidence: current IDA MCP confirms initialized storage, constructor publish/fallback clear, destructor clear, Application/main-menu/music-control/BaramApp/SoundStatusPane/playback-helper consumers, and file-parent ownership through [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md). C++ remains blank under the final-code gate.
