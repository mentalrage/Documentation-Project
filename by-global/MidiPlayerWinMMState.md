*** UID:0000T9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LD | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MidiPlayer WinMM State

## Status

- Confidence: medium for names; strong for ownership.
- Entity kind: global state group.
- Proposed owner: [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md)

## Purpose

These globals hold the process-wide WinMM MIDI stream, prepared headers, parser/document state, volume scaling, and two-buffer playback bookkeeping used by `MidiPlayer`.

## Current Name Map

| Current name surface | Better provisional name | Evidence |
| --- | --- | --- |
| `hms` / `g_hMidiStream` | `g_hMidiStream` | Stream handle used by `midiStreamOpen`, `midiStreamStop`, `midiOutReset`, `midiStreamOut`, `midiStreamRestart`, and `midiStreamClose`. |
| `hObject` / `g_hMidiBufferEvent` | `g_hMidiBufferEvent` | Created as "Wait For Buffer Return"; signaled by the callback and waited on by reset. |
| `dword_69B508` / `DAT_0069B508` | `g_midiStreamState` | Values `100`, `200`, and `300` gate stopping/stopped/flushing behavior in reset and callback code. |
| `dword_69B50C` / `DAT_0069B50C` | `g_midiRestartPending` | Set/cleared around restart paths in `0x00526240` and reset. |
| `dword_69B514` / `DAT_0069B514` | `g_midiDocumentLoaded` | Tracks whether a MIDI document/stream payload is loaded and needs release. |
| `dword_69B518` / `DAT_0069B518` | `g_midiStreamRunning` | Guards callback refill and restart behavior. |
| `dword_69B520` / `g_midiHeadersPrepared` | `g_midiHeadersPrepared` | Controls unprepare of the two `MIDIHDR` slots. |
| `dword_69B524` | `g_midiVolumeScale` | Used when applying volume with `midiOutShortMsg` and `0x00525ff0`. |
| `dword_69B610` | `g_midiActiveHeaderIndex` | Rotates between the two prepared MIDI buffers. |
| `dword_69B614` | `g_midiPendingBufferCount` | Counts returned/submitted stream buffers during callback/reset. |
| `pmh` / `g_midiHeadersRaw` | `g_midiHeaders` | Two 84-byte `MIDIHDR`-sized records with buffer pointers and recorded-byte counts. |
| `dword_69B828` / `DAT_0069B828` | `g_midiDocumentState` | Passed to MIDI document parse/read/release helpers. |
| `Destination` | `g_midiCurrentPath` | Copied by track-start helper and opened by stream setup. |

## State Families

| Family | Globals | Evidence |
| --- | --- | --- |
| WinMM stream and reset control | `hms`, `hObject`, `dword_69B508`, `dword_69B50C`, `dword_69B518` | Stream setup opens the `HMIDISTRM`, reset/close stops and waits on the event, and the callback gates refill/restart behavior through the same state words. |
| Two-buffer stream headers | `pmh`, `dword_69B520`, `dword_69B610`, `dword_69B614` | The helper pages document two `MIDIHDR` slots, prepared-header lifetime, active-slot rotation, and pending-buffer accounting across callback and reset. |
| Document and SMF parser state | `dword_69B514`, `dword_69B828`, `dword_69B870`, `dword_69B874`, `dword_69B878`, `dword_69B87C`, `xmmword_69B880` | Reader/parser helpers load and release the document state; the stream-fill helper uses the scratch range to pick the next track event, track parse flags, and replay pending output. |
| Volume and channel output | `dword_69B524`, channel-volume table at `0x0069b5d0` | The callback and volume helpers scale channel volume before sending `midiOutShortMsg` control changes through the WinMM stream. |
| Current file path | `Destination` | Track-start and stream-open paths copy/open the current MIDI path as part of the same playback setup boundary. |

## Behavior Evidence

| Range | Contribution |
| --- | --- |
| `0x00525920-0x00525b0d` | Opens the WinMM stream, creates the callback/event boundary, and primes the two-buffer playback state. |
| `0x00525be0-0x00525dbb` | Callback consumes returned headers, updates pending counts/state flags, refills stream buffers, applies volume state, and signals reset waits. |
| `0x00526460-0x00526569` | Reset helper stops and resets the stream, waits for pending buffer return, unprepares headers, and conditionally reopens/restarts playback. |
| `0x005270e0-0x005271a3` | Releases document/parser state guarded by the loaded-document flag. |
| `0x005271b0-0x005273a0` | Stream-fill helper consumes the parser scratch globals to emit packed MIDI stream events into WinMM buffers. |
| `0x005273a0-0x005277bb` | SMF load helpers populate document/track state used by the callback refill path. |
| `0x0060c26a-0x0060c320` | Static lifetime wrapper constructs and tears down the document-state object attached to the same global-state family. |

## Reconstruction Caveats

- This is a documentation grouping, not evidence of a single original global struct.
- Final names should be checked against the C++ rewrite and any recovered symbol names before applying them to source. The stream-state constants `100`, `200`, and `300`, negative/parser status values, and class-vs-file helper split still need final declaration decisions.
- The WinMM imports are external system APIs; the reconstructable surface is the NexusTK-owned global state and helper logic, likely under the private MIDI player implementation rather than a SoundManager owner.
- 2026-05-26 current-state recheck: the reset/callback paths expose raw `DAT_0069B508`, `DAT_0069B50C`, `DAT_0069B514`, and `DAT_0069B518` names in analysis, while buffer-release paths use named `g_midiHeadersPrepared` and `g_midiHeadersRaw`. Keep this page as the cross-name map until global-data names are normalized.
- 2026-05-28 MIDI reader/parser recheck: [UID:00023B][0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers](by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md) consumes the document/track state around `dword_69B828` and the parser scratch globals used by the next SMF load range.
- 2026-05-28 SMF load/fill recheck: [UID:00023C][0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers](by-memory/0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers.md) uses the parser scratch globals `dword_69B870`, `dword_69B874`, `dword_69B878`, `dword_69B87C`, and `xmmword_69B880` while filling WinMM stream buffers.
- 2026-05-28 static lifetime recheck: [UID:00024G][0x0060c26a-0x0060c320.StaticDestructorWrappersBeforePoolAllocators](by-memory/0x0060c26a-0x0060c320.StaticDestructorWrappersBeforePoolAllocators.md) records startup construction at `0x0041a010` for `dword_69B828` and paired cleanup wrapper `0x0060c300`, which calls `sub_49C160(dword_69B840)`.
- 2026-06-05 IDA MCP recheck confirmed MIDI state xrefs around `0x0069b508`, `0x0069b514`, `0x0069b610`, and `0x0069b828` in the callback/reset/parser helper ranges, matching the documented WinMM and SMF parser ownership.

## Cross-References

- [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md)
- [UID:00008A][MidiPlayer](by-class/MidiPlayer.md)
- [UID:0000RM][g_pMidiPlayer](by-global/g_pMidiPlayer.md)
- [UID:0001CF][0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers](by-memory/0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers.md)
- [UID:0001CG][0x00525be0-0x00525dbb.MidiStreamCallback](by-memory/0x00525be0-0x00525dbb.MidiStreamCallback.md)
- [UID:0001CH][0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers](by-memory/0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers.md)
- [UID:00023B][0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers](by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md)
- [UID:00023C][0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers](by-memory/0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers.md)
- [UID:00024G][0x0060c26a-0x0060c320.StaticDestructorWrappersBeforePoolAllocators](by-memory/0x0060c26a-0x0060c320.StaticDestructorWrappersBeforePoolAllocators.md)
- [UID:0002B2][0x0069b870-0x0069b890.MidiSMFParserScratchGlobals](by-memory/0x0069b870-0x0069b890.MidiSMFParserScratchGlobals.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `80/82`.
  - Before: page documented the MIDI WinMM global-state map, current/proposed names, parser/static-lifetime caveats, and cross-references but remained unevaluated.
  - After: score reflects documented stream/event/header/document/parser state ownership and use across playback/reset/callback/parser ranges, while preserving medium confidence for final names.
  - Evidence: linked MIDI helper pages cover WinMM stream helpers, callback/reset paths, SMF reader/parser helpers, stream fill helpers, and static construction/destruction of document state.
- 2026-06-05: Marked reconstructable and attached to [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md).
  - Reason: live IDA MCP recheck confirms these source-declared globals are referenced from the MIDI callback, reset, stream-buffer, parser, and document-state helper ranges owned by MidiPlayer.
- 2026-06-06: Raised grading from `80/82` to `86/88`.
  - Before: page listed the provisional name map and several caveats, but did not separate stream-control, two-buffer header, parser scratch, volume, and static-document families.
  - After: added state-family and behavior-evidence tables tying the globals to stream setup, callback refill, reset/unprepare, SMF load/fill, static lifetime, channel-volume, and current-path behavior.
  - Evidence: existing by-memory pages cover the WinMM helper ranges, callback, reader/parser, stream-fill helper, static destructor wrapper, and parser scratch block, with [UID:0002B2][0x0069b870-0x0069b890.MidiSMFParserScratchGlobals](by-memory/0x0069b870-0x0069b890.MidiSMFParserScratchGlobals.md) now linked directly.
