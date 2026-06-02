*** UID:00008A | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MidiPlayer

## Status

- Confidence: strong for behavior, WinMM ownership, source-family placement, and singleton lifecycle; medium for final field/global/helper names.
- Likely source file: [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md)
- Current generated file: `source-3/simroot_v2/class_MidiPlayer.cpp`
- Imported source hint: `MidiPlayer.cpp`
- Main address doc: [UID:0001CF][0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers](by-memory/0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers.md)
- Autogen status: the owning file is projected to `NexusTK/audio/`; this class page stays non-reconstructable because class declaration, helper split, and global state names are not final-source quality.

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

## Source Placement And Runtime Boundary

`MidiPlayer` belongs in the audio source family as the WinMM MIDI controller. It should remain separate from [UID:0000DG][SoundManager](by-class/SoundManager.md), which owns the broader Miles/MP3/WAV/Redbook policy. The MIDI pages consistently tie this class to Windows `WINMM` stream APIs, two prepared MIDI buffers, a stream callback, a document/parser state block, and a process singleton.

The file-level owner [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md) is projected to `NexusTK/audio/`. Treat [UID:0000T9][MidiPlayerWinMMState](by-global/MidiPlayerWinMMState.md) as a documentation map for related globals, not proof of a single original struct.

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
- volume apply helper at `0x00525ff0-0x0052605a` applies the current MIDI volume scale across 16 channels using `midiOutShortMsg` when playback is running.
- `MidiPlayer_ResetStream` at `0x00526460-0x00526569` stops and resets the active stream, optionally reopening playback depending on flags.
- singleton clear helper at `0x00526570-0x0052657b` stores null to [UID:0000RM][g_pMidiPlayer](by-global/g_pMidiPlayer.md) in constructor/destructor cleanup context.
- [UID:0001CE][0x00525920-0x00525b0d.MidiStreamOpenAndPrimeBuffers](by-memory/0x00525920-0x00525b0d.MidiStreamOpenAndPrimeBuffers.md) opens the WinMM stream and primes the two MIDI buffers.
- [UID:0001CG][0x00525be0-0x00525dbb.MidiStreamCallback](by-memory/0x00525be0-0x00525dbb.MidiStreamCallback.md) is the IDA-confirmed WinMM callback passed to `midiStreamOpen`.
- [UID:00023B][0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers](by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md) owns the file/adapter-backed Standard MIDI File reader, track event decoder, and stream-event encoder helpers.
- [UID:0001CI][0x005270e0-0x005271a3.MidiDocumentRelease](by-memory/0x005270e0-0x005271a3.MidiDocumentRelease.md) releases MIDI document/parser resources used by reset/callback paths.
- [UID:00023C][0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers](by-memory/0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers.md) loads the SMF track table and fills WinMM stream buffers from parsed track events.

## Touched State

| State/global | Access pattern | Evidence |
| --- | --- | --- |
| [UID:0000RM][g_pMidiPlayer](by-global/g_pMidiPlayer.md) / `0x0067ab4c` | Constructor assigns the active singleton; destructor/scalar-delete cleanup clears it; application, main-menu, music-control, sound-status, and audio-control consumers read it. | [UID:0000RM][g_pMidiPlayer](by-global/g_pMidiPlayer.md) and [UID:0001CF][0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers](by-memory/0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers.md). |
| `this+0x04` | Playback-enabled flag used by enable/disable/select helpers. | Class methods and [UID:0001CH][0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers](by-memory/0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers.md). |
| `this+0x08` | Selected MIDI track/device sentinel; constructor, disable, and stop paths store `-1`. | Class methods and [UID:0001CH][0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers](by-memory/0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers.md). |
| [UID:0000T9][MidiPlayerWinMMState](by-global/MidiPlayerWinMMState.md) | Stream handle, callback event, prepared headers, stream state flags, volume, current path, and parser/document state. | State map plus stream open/callback/reset/parser pages. |
| config music flag at `g_pConfig + 2124` | Enable/disable/select logic checks or updates the global music setting before stream work. | [UID:0001CH][0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers](by-memory/0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers.md). |

## Boundary And Helper Map

| Range | Kind | Notes |
| --- | --- | --- |
| `0x00525920-0x00525b0d` | stream open/prime helper | Opens WinMM stream and primes two buffers before playback. |
| `0x00525b0d-0x00525b10` | alignment | Boundary padding before `ReleaseMidiBuffers_525B10`. |
| `0x00525b10-0x0052664b` | main sparse class/helper island | Release buffers, callback, constructor/destructor, toggles, track select/start, stop/reset, singleton clear, scalar deleting destructor. |
| `0x00526332-0x00526340` | alignment | Padding before `StopPlayback`. |
| `0x0052664b-0x00526650` | alignment | Padding before the SMF reader/parser island. |
| `0x00526650-0x005270d5` | MIDI file reader/parser helpers | Standard MIDI File reader, track event decoder, and stream-event encoder helpers. |
| `0x005270e0-0x005271a3` | MIDI document release | Releases document/parser resources used by callback/open/reset paths. |
| `0x005271b0-0x005277bb` | SMF load/fill helpers | Loads track tables and fills WinMM stream buffers from parsed events. |

## Data Caveats

- Active generated output duplicates marker-only global-data rows for several MIDI globals.
- `MidiPlayer_ResetStream` still uses raw `DAT_0069B508`-style stream-state globals; see [UID:0000T9][MidiPlayerWinMMState](by-global/MidiPlayerWinMMState.md).
- `0x00525be0`, `0x00525920`, `0x00526100`, `0x00526240`, `0x00526650-0x005270d5`, and `0x005270e0` are IDA-confirmed source-family members but are not yet fully represented in active generated output.
- 2026-05-26 recheck: current `.cpp` output still emits only the class methods plus recovered `ReleaseMidiBuffers` and `MidiPlayer_ResetStream` globals. IDA MCP still resolves the omitted starts with the same MIDI-family callers, so do not infer separate original files from the missing active class output.
- 2026-05-28 recheck: the former unknown span after `0x0052664b` is MIDI reader/parser code plus alignment padding, not an unrelated subsystem or arbitrary gap.
- 2026-05-28 recheck: the former unknown span after `0x005271a3` is the matching SMF load/stream-fill helper island plus alignment padding before `MiscWorkThread`.
- 2026-05-30 recheck: [UID:00023B][0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers](by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md) is now nested into exact child pages for the file/adapter reader, event reader, stream-event encoder, track-buffer helpers, and parser wrapper. Treat those as private helper routines tied to this MIDI subsystem unless later source evidence proves a separate owner.
- 2026-05-30 recheck: [UID:00023C][0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers](by-memory/0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers.md) is now nested into exact child pages for stream-buffer fill and SMF document load. These remain private MIDI helper routines unless later source evidence proves a separate owner.
- 2026-06-01 recheck: [UID:0001CF][0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers](by-memory/0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers.md) records current IDA function sizes across the sparse class/helper island, reset fan-in from callback/destructor/disable/select/start/stop/scalar-delete paths, WinMM callees, and boundary padding at `0x00525b0d`, `0x00526332`, and `0x0052664b`.
- 2026-06-01 recheck: [UID:0001CH][0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers](by-memory/0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers.md) confirms the select helper checks config music state, object playback state, requested track id, and selected-track field before resolving configured/fallback paths and starting stream playback.

## Open Questions

- Final names for the WinMM state globals and whether some belong as file-scope globals versus a recovered private state object.
- Whether `0x00525be0`, `0x00525920`, `0x00526100`, `0x00526240`, and `0x005270e0` should be final class methods or private file-scope helpers.
- The small raw/function-shaped material between `0x00525f40` and `0x0052609a` still needs naming or splitting before near-final confidence.

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
- 2026-06-02: Raised the class page from `66/78` to `74/84`.
  - Before: the class page summarized behavior and helper links but did not carry over the current file-owner score, WinMM boundary notes, touched-state table, helper map, reset fan-in, or track-selection evidence.
  - After: the page records `NexusTK/audio/` placement, separate `SoundManager` boundary, singleton/config/object-field/global-state accesses, helper/padding ranges, and remaining reconstruction blockers.
  - Evidence: existing IDA-backed [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md), [UID:0001CF][0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers](by-memory/0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers.md), [UID:0001CH][0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers](by-memory/0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers.md), [UID:0000RM][g_pMidiPlayer](by-global/g_pMidiPlayer.md), and [UID:0000T9][MidiPlayerWinMMState](by-global/MidiPlayerWinMMState.md).
