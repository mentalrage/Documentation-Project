*** UID:00008A | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:66 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MidiPlayer

## Status

- Confidence: strong for behavior and ownership; medium for final field names.
- Likely source file: [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md)
- Current generated file: `source-3/simroot_v2/class_MidiPlayer.cpp`
- Imported source hint: `MidiPlayer.cpp`
- Main address doc: [UID:0001CF][0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers](by-memory/0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers.md)

## Class Purpose

`MidiPlayer` is the process MIDI playback controller. It tracks whether MIDI playback is enabled, manages the selected MIDI track sentinel, owns the process singleton [UID:0000RM][g_pMidiPlayer](by-global/g_pMidiPlayer.md), and coordinates WinMM stream shutdown through `MidiPlayer_ResetStream`.

This class is a sibling audio subsystem to [UID:0000DG][SoundManager](by-class/SoundManager.md). `SoundManager` manages Miles/MP3/WAV/Redbook audio policy; `MidiPlayer` owns WinMM MIDI state and buffering.

## Layout Notes

Current evidence suggests a compact 12-byte object allocated by `Application`:

| Offset | Field | Evidence |
| --- | --- | --- |
| `0x00` | `LObject`/vtable base | Constructor calls `LObject::LObject` and installs `MidiPlayer_vtable`. |
| `0x04` | `m_playbackEnabled` | `IsPlaybackEnabled`, `EnableMidiPlayback`, and `DisableMidiPlayback` read/write this dword. |
| `0x08` | `m_selectedTrackId` or device/track sentinel | Constructor and stop/disable paths store `-1`; generated names vary between selected device and selected track. |

The exact field names should stay provisional until the missing start/select helpers around `0x00526100` and `0x00526240` are restored or reviewed.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `MidiPlayer` | `0x00525dc0-0x00525ea6` | Constructs `LObject`, assigns `g_pMidiPlayer`, initializes playback flags and WinMM global state, creates the buffer-return event. |
| `~MidiPlayer` | `0x00525eb0-0x00525f3d` | Resets stream if open, releases MIDI buffers, closes stream/event handles, clears singleton, destroys `LObject`. |
| `IsPlaybackEnabled` | `0x005260a0-0x005260a4` | Returns the playback-enabled field. |
| `EnableMidiPlayback` | `0x005260b0-0x005260ca` | Sets config music flag and object playback flag if currently disabled. |
| `DisableMidiPlayback` | `0x005260d0-0x005260ff` | Clears config flag, clears selected-track sentinel, resets stream, and marks playback disabled. |
| select track helper | `0x00526100-0x00526233` | Selects a requested MIDI track, resets the current stream, resolves the DAT/config filename, and starts playback. |
| start selected path helper | `0x00526240-0x00526332` | Copies a selected path, opens/primes stream buffers, restarts WinMM playback, and reapplies volume. |
| `StopPlayback` | `0x00526340-0x00526350` | Clears selected-track sentinel and calls `MidiPlayer_ResetStream(0)`. |
| `ScalarDeletingDestructor` | `0x00526580-0x0052664b` | Calls destructor and conditionally frees heap storage. |

## Related Free Helpers

- `ReleaseMidiBuffers_525B10` at `0x00525b10-0x00525b98` unprepares headers and frees backing buffers.
- `MidiPlayer_ResetStream` at `0x00526460-0x00526569` stops and resets the active stream, optionally reopening playback depending on flags.
- [UID:0001CE][0x00525920-0x00525b0d.MidiStreamOpenAndPrimeBuffers](by-memory/0x00525920-0x00525b0d.MidiStreamOpenAndPrimeBuffers.md) opens the WinMM stream and primes the two MIDI buffers.
- [UID:0001CG][0x00525be0-0x00525dbb.MidiStreamCallback](by-memory/0x00525be0-0x00525dbb.MidiStreamCallback.md) is the IDA-confirmed WinMM callback passed to `midiStreamOpen`.
- [UID:00023B][0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers](by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md) owns the file/adapter-backed Standard MIDI File reader, track event decoder, and stream-event encoder helpers.
- [UID:0001CI][0x005270e0-0x005271a3.MidiDocumentRelease](by-memory/0x005270e0-0x005271a3.MidiDocumentRelease.md) releases MIDI document/parser resources used by reset/callback paths.
- [UID:00023C][0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers](by-memory/0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers.md) loads the SMF track table and fills WinMM stream buffers from parsed track events.

## Data Caveats

- Active generated output duplicates marker-only global-data rows for several MIDI globals.
- `MidiPlayer_ResetStream` still uses raw `DAT_0069B508`-style stream-state globals; see [UID:0000T9][MidiPlayerWinMMState](by-global/MidiPlayerWinMMState.md).
- `0x00525be0`, `0x00525920`, `0x00526100`, `0x00526240`, `0x00526650-0x005270d5`, and `0x005270e0` are IDA-confirmed source-family members but are not yet fully represented in active generated output.
- 2026-05-26 recheck: current `.cpp` output still emits only the class methods plus recovered `ReleaseMidiBuffers` and `MidiPlayer_ResetStream` globals. IDA MCP still resolves the omitted starts with the same MIDI-family callers, so do not infer separate original files from the missing active class output.
- 2026-05-28 recheck: the former unknown span after `0x0052664b` is MIDI reader/parser code plus alignment padding, not an unrelated subsystem or arbitrary gap.
- 2026-05-28 recheck: the former unknown span after `0x005271a3` is the matching SMF load/stream-fill helper island plus alignment padding before `MiscWorkThread`.
- 2026-05-30 recheck: [UID:00023B][0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers](by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md) is now nested into exact child pages for the file/adapter reader, event reader, stream-event encoder, track-buffer helpers, and parser wrapper. Treat those as private helper routines tied to this MIDI subsystem unless later source evidence proves a separate owner.
- 2026-05-30 recheck: [UID:00023C][0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers](by-memory/0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers.md) is now nested into exact child pages for stream-buffer fill and SMF document load. These remain private MIDI helper routines unless later source evidence proves a separate owner.

## Cross-References

- [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md)
- [UID:0001CF][0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers](by-memory/0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers.md)
- [UID:0001CE][0x00525920-0x00525b0d.MidiStreamOpenAndPrimeBuffers](by-memory/0x00525920-0x00525b0d.MidiStreamOpenAndPrimeBuffers.md)
- [UID:0001CG][0x00525be0-0x00525dbb.MidiStreamCallback](by-memory/0x00525be0-0x00525dbb.MidiStreamCallback.md)
- [UID:0001CH][0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers](by-memory/0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers.md)
- [UID:00023B][0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers](by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md)
- [UID:0001CI][0x005270e0-0x005271a3.MidiDocumentRelease](by-memory/0x005270e0-0x005271a3.MidiDocumentRelease.md)
- [UID:00023C][0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers](by-memory/0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers.md)
- [UID:0000T9][MidiPlayerWinMMState](by-global/MidiPlayerWinMMState.md)
- [UID:0000RM][g_pMidiPlayer](by-global/g_pMidiPlayer.md)
- [UID:0000DG][SoundManager](by-class/SoundManager.md)
- [UID:0000DJ][SoundStatusPane](by-class/SoundStatusPane.md)
- [UID:0001Q8][client_audio](by-meta/client_audio.md)

## Changes

- 2026-05-30: Previously this class page linked only to aggregate MIDI reader/parser and stream-fill helper spans. It now records that both aggregates have exact child by-memory pages while keeping the helpers associated with the `MidiPlayer` subsystem. Evidence: IDA MCP function-boundary and call/import checks for the split child ranges.
