*** UID:0000RM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pMidiPlayer

## Status

- Confidence: strong for identity and role; medium for final declaration owner.
- Symbol kind: global singleton pointer.
- Address: [UID:00029A][0x0067ab4c-0x0067ab50.g_pMidiPlayer](by-memory/0x0067ab4c-0x0067ab50.g_pMidiPlayer.md)
- Likely owner: [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md)
- Current generated references: `audio/MidiPlayer.cpp`, `class_SoundManager.cpp`, `class_SoundStatusPane.cpp`, `class_BaramApp.cpp`, `class_MainMenuPane.cpp`, and unresolved legacy `dword_67AB4C` uses in `class_NewOptionPane.cpp`.

## Role

`g_pMidiPlayer` stores the active [UID:00008A][MidiPlayer](by-class/MidiPlayer.md) singleton. The `MidiPlayer` constructor assigns it, and the destructor clears it after stopping/resetting playback, releasing MIDI buffers, closing the stream, and closing the buffer-return event.

UI and application code use this global to pause/resume/stop MIDI playback or to pair MIDI toggles with broader music/sound state changes.

## Evidence

- [UID:00029A][0x0067ab4c-0x0067ab50.g_pMidiPlayer](by-memory/0x0067ab4c-0x0067ab50.g_pMidiPlayer.md) documents the exact four-byte `.data` slot as `MidiPlayer *g_pMidiPlayer;`.
- `source-3/simroot_v2/audio/MidiPlayer.cpp` assigns `g_pMidiPlayer = this;` in the `0x00525dc0` constructor and clears it in the `0x00525eb0` destructor after stream reset, MIDI buffer release, stream close, and event close.
- `audio/MidiPlayer.cpp.source_map.json` reports zero missing memory-range lines for the constructor, destructor, `StopPlayback` at `0x00526340`, and `MidiPlayer_ResetStream` at `0x00526460`.
- `class_SoundStatusPane.cpp.source_map.json` maps the hotkey handler `0x0057c080` fully, including `g_pMidiPlayer` use for MIDI start/stop decisions, but its generated `global-data:g_pMidiPlayer` declaration marker has no memory range. Treat that as a consumer-marker artifact, not ownership evidence.
- `class_NewOptionPane.cpp` still uses unresolved `dword_67AB4C` at the music-toggle call sites. This is the same storage address by generated metadata, but the current source-map global-data marker is unresolved and should be renamed only when the surrounding pane method is reviewed.
- Live IDA MCP was unavailable during the 2026-05-30 review, so the page keeps confidence below the exact storage page until direct xref counts can be refreshed.

## Known Users

- [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md): constructor/destructor ownership and playback methods.
- [UID:0000NV][SoundManager](by-file/SoundManager.md): pause/resume calls during broader music playback transitions.
- [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md): hotkey handling and status refresh for music/MIDI state.
- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md): stops current MIDI playback when menu actions require it.
- [UID:00000V][BaramApp](by-class/BaramApp.md): activation/deactivation paths call MIDI enable/disable helpers in generated output.

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

- 2026-05-30: Previously this page carried a stale `0/0` completion/confidence score and cited only generated references for `0x0067ab4c`. It now links the exact singleton storage page, records constructor/destructor ownership from `audio/MidiPlayer.cpp`, notes source-map coverage for the core MIDI methods, and calls out unresolved consumer marker caveats in `SoundStatusPane` and `NewOptionPane`. Score changed to `78/80` because exact storage and lifecycle are well supported, but live IDA MCP was unavailable and some consumer declarations remain generated/unresolved.
