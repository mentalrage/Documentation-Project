*** UID:0000T9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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

| Current/generated name | Better provisional name | Evidence |
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

## Caveats

- This is a documentation grouping, not evidence of a single original global struct.
- Final names should be checked against the C++ rewrite and any recovered symbol names before applying them to generated code.
- 2026-05-26 current-state recheck: `MidiPlayer_ResetStream_00526460.cpp` still exposes raw `DAT_0069B508`, `DAT_0069B50C`, `DAT_0069B514`, and `DAT_0069B518` names, while `ReleaseMidiBuffers_00525B10.cpp` uses named `g_midiHeadersPrepared` and `g_midiHeadersRaw`. Keep this page as the cross-name map until generated global-data names are normalized.
- 2026-05-28 MIDI reader/parser recheck: [UID:00023B][0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers](by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md) consumes the document/track state around `dword_69B828` and the parser scratch globals used by the next SMF load range.
- 2026-05-28 SMF load/fill recheck: [UID:00023C][0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers](by-memory/0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers.md) uses the parser scratch globals `dword_69B870`, `dword_69B874`, `dword_69B878`, `dword_69B87C`, and `xmmword_69B880` while filling WinMM stream buffers.
- 2026-05-28 static lifetime recheck: [UID:00024G][0x0060c26a-0x0060c320.StaticDestructorWrappersBeforePoolAllocators](by-memory/0x0060c26a-0x0060c320.StaticDestructorWrappersBeforePoolAllocators.md) records startup construction at `0x0041a010` for `dword_69B828` and paired cleanup wrapper `0x0060c300`, which calls `sub_49C160(dword_69B840)`.

## Cross-References

- [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md)
- [UID:00008A][MidiPlayer](by-class/MidiPlayer.md)
- [UID:0001CF][0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers](by-memory/0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers.md)
- [UID:0001CG][0x00525be0-0x00525dbb.MidiStreamCallback](by-memory/0x00525be0-0x00525dbb.MidiStreamCallback.md)
- [UID:0001CH][0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers](by-memory/0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers.md)
- [UID:00023B][0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers](by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md)
- [UID:00023C][0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers](by-memory/0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers.md)
- [UID:00024G][0x0060c26a-0x0060c320.StaticDestructorWrappersBeforePoolAllocators](by-memory/0x0060c26a-0x0060c320.StaticDestructorWrappersBeforePoolAllocators.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `80/82`.
  - Before: page documented the MIDI WinMM global-state map, current/proposed names, parser/static-lifetime caveats, and cross-references but remained unevaluated.
  - After: score reflects documented stream/event/header/document/parser state ownership and use across playback/reset/callback/parser ranges, while preserving medium confidence for final names.
  - Evidence: linked MIDI helper pages cover WinMM stream helpers, callback/reset paths, SMF reader/parser helpers, stream fill helpers, and static construction/destruction of document state.
