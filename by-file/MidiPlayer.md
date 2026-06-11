*** UID:0000LD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/audio/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# MidiPlayer

## Status

- Confidence: strong for WinMM MIDI behavior, source-family membership, and separation from `SoundManager`; medium for exact private SMF helper split and final source-facing helper/global names.
- Proposed module: `audio/MidiPlayer.cpp`
- Proposed header: `audio/MidiPlayer.h`
- Related omitted helpers confirmed by IDA: [UID:0001CE][0x00525920-0x00525b0d.MidiStreamOpenAndPrimeBuffers](by-memory/0x00525920-0x00525b0d.MidiStreamOpenAndPrimeBuffers.md), [UID:0001CG][0x00525be0-0x00525dbb.MidiStreamCallback](by-memory/0x00525be0-0x00525dbb.MidiStreamCallback.md), [UID:0001CH][0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers](by-memory/0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers.md), [UID:00023B][0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers](by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md), [UID:00023C][0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers](by-memory/0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers.md), and [UID:0001CI][0x005270e0-0x005271a3.MidiDocumentRelease](by-memory/0x005270e0-0x005271a3.MidiDocumentRelease.md)
- Main address doc: [UID:0001CF][0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers](by-memory/0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers.md)
- Evidence basis: existing by-class/by-memory/by-global documentation plus IDA MCP import, function-boundary, caller/callee, and data-xref checks showing the WinMM MIDI API import set and parser-state ownership.

## File Role

`MidiPlayer.cpp` should own the WinMM MIDI stream controller, MIDI buffer/header lifetime, the active MIDI singleton, and the small public playback-toggle surface used by UI and application code.

This is related to but distinct from [UID:0000NV][SoundManager](by-file/SoundManager.md). `SoundManager` owns Miles Sound System, MP3/WAV/Redbook policy, and DAT-backed audio resource selection. `MidiPlayer` owns the legacy MIDI stream path and WinMM-specific state such as `midiStreamStop`, `midiOutReset`, `midiOutUnprepareHeader`, and the "Wait For Buffer Return" event.

## Runtime Boundary

`MidiPlayer` uses Windows `WINMM`, not RAD Miles. IDA import evidence includes `midiStreamOpen`, `midiStreamOut`, `midiStreamStop`, `midiStreamRestart`, `midiStreamPause`, `midiStreamClose`, `midiOutPrepareHeader`, `midiOutUnprepareHeader`, `midiOutReset`, `midiOutShortMsg`, and timing APIs such as `timeGetTime`.

Rebuild guidance:

- Link against the Windows SDK `winmm.lib`.
- Keep WinMM stream-buffer state in this module or its private helpers.
- Do not merge MIDI stream code into [UID:0000NV][SoundManager](by-file/SoundManager.md) just because UI controls expose sound/music options together.
- Do not treat WinMM imports as third-party source to vendor; they are system APIs.

## Proposed Contents

| Entity | Documentation status | Address evidence | Role |
| --- | --- | --- | --- |
| `MidiStreamOpenAndPrimeBuffers` | exact by-memory helper page | `0x00525920-0x00525b0d` | Opens WinMM stream, allocates two buffers, primes `midiStreamOut`. |
| `MidiPlayer` | class page plus exact method/helper island | `0x00525dc0-0x0052664a` sparse method island | Singleton MIDI playback controller. |
| `ReleaseMidiBuffers_525B10` | exact helper range inside the main island | `0x00525b10-0x00525b98` | Unprepares two MIDI headers and frees backing `GlobalAlloc` buffers. |
| MIDI callback | exact callback page | `0x00525be0-0x00525dbb` | WinMM callback passed to `midiStreamOpen`; handles buffer returns, refill, stop/reset events, and volume controller messages. |
| track selection/start helpers | exact by-memory helper page | `0x00526100-0x00526332` | Selects DAT/config MIDI track paths, resets active stream, starts/restarts playback. |
| `MidiPlayer_ResetStream` | exact helper range inside the main island | `0x00526460-0x00526569` | Shared stop/reset/wait/cleanup/reopen helper used by destructor, disable, stop, and callback paths. |
| MIDI file reader / SMF parser helpers | exact aggregate plus child helper pages | `0x00526650-0x005270d5` | Reads file/adapter-backed MIDI data, decodes track events, and emits WinMM stream event records. |
| MIDI document release | exact by-memory helper page | `0x005270e0-0x005271a3` | Releases parser/file/global-memory document state used by the MIDI stream. |
| SMF document load / stream fill helpers | exact aggregate plus child helper pages | `0x005271b0-0x005277bb` | Loads `MThd`/`MTrk` track tables and fills WinMM stream buffers from parsed track events. |
| `g_pMidiPlayer` | singleton global docs | `0x0067ab4c` | Active MIDI singleton pointer. |
| [UID:0000T9][MidiPlayerWinMMState](by-global/MidiPlayerWinMMState.md) | WinMM/global state map with exact by-memory children | `0x0069b500+` state family | Stream handle, callback event, header buffers, stream state, volume, current path, parser state. |

## Ownership Reasoning

- The class and memory pages consistently tie this source family to `MidiPlayer.cpp` and document it as the WinMM MIDI playback controller.
- `Application` constructs `MidiPlayer` as a 12-byte application object and `MidiPlayer` construction assigns [UID:0000RM][g_pMidiPlayer](by-global/g_pMidiPlayer.md).
- The release/reset helpers are used only by MIDI stream teardown/reset paths and should stay with `MidiPlayer`, not generic audio or application code.
- UI classes such as [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md), [UID:0000LN][MusicControlDialog](by-file/MusicControlDialog.md), [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md), and activation handling in [UID:00000V][BaramApp](by-class/BaramApp.md) are consumers. They should not own the WinMM implementation.

## Evidence Notes

- The class page covers constructor, destructor, playback enable/disable, stop, and scalar deleting destructor methods.
- The release-buffer helper unprepares two `0x54`-byte MIDI header slots and frees non-null `lpData` blocks.
- IDA MCP recheck on 2026-05-25 confirms live starts/sizes for `0x00525920`, `0x00525b10`, `0x00525be0`, `0x00525dc0`, `0x00526100`, `0x00526240`, `0x00526460`, `0x00526580`, and `0x005270e0`.
- IDA MCP confirms `0x00525be0` has a data xref from `0x00525939`, where it is passed as the `midiStreamOpen` callback.
- IDA MCP confirms `MidiPlayer_ResetStream` callers from the MIDI callback, destructor, disable/stop paths, track selection/start helpers, and scalar deleting destructor.
- 2026-05-25/2026-05-26 IDA-backed review kept the helper split as source-layout guidance: `0x00525920`, `0x00525be0`, `0x00526100`, `0x00526240`, and `0x005270e0` are all MIDI stream/open/callback/select/reset/document-cleanup family members even though their final class-method-versus-file-scope shape remains open.
- 2026-05-26 IDA MCP revalidated that `0x00525be0` has no normal callers and is data-referenced from `0x00525939` as the `midiStreamOpen` callback; this is expected callback behavior, not dead code.
- 2026-05-28 IDA MCP resolves the former `0x0052664b-0x005270e0` unknown gap as boundary padding plus a coherent SMF reader/parser helper island at `0x00526650-0x005270d5`; keep it with this file unless later source evidence proves a separate MIDI document module.
- 2026-05-28 IDA MCP resolves the former `0x005271a3-0x005277c0` unknown gap as stream-fill and SMF document-load helpers at `0x005271b0-0x005277bb`, with boundary padding around it.
- 2026-05-30 IDA MCP recheck split [UID:00023B][0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers](by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md) into exact child pages for each modeled function or function-shaped raw body. Keep those children nested under the MIDI file-reader aggregate unless later source evidence proves an original separate MIDI parser source file.
- 2026-05-30 IDA MCP recheck split [UID:00023C][0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers](by-memory/0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers.md) into the stream-buffer fill helper and SMF document load helper. Keep both as private MIDI source-family helpers unless later evidence proves a separate original SMF parser file.
- 2026-06-01 IDA MCP recheck confirms the source-family boundaries across the low-score cluster: `0x00525920` size `0x1ed`, `0x00525b10` size `0x88`, `0x00525be0` size `0x1db`, `0x00525dc0` size `0xe6`, `0x00525eb0` size `0x8d`, `0x00525ff0` size `0x6a`, `0x005260a0` size `0x4`, `0x005260b0` size `0x1a`, `0x005260d0` size `0x2f`, `0x00526100` size `0x133`, `0x00526240` size `0xf2`, `0x00526340` size `0x10`, `0x00526460` size `0x109`, `0x00526570` size `0xb`, `0x00526580` size `0xcb`, `0x005270e0` size `0xc3`, with MIDI parser continuations at `0x00526650`, `0x005271b0`, and `0x005273a0`.
- 2026-06-01 IDA MCP caller/callee checks confirm `MidiPlayer_ResetStream` fan-in from callback, destructor, disable, select/start, stop, and scalar-deleting destructor paths; `MidiDocumentRelease` fan-in from stream-open failure, callback end/error, and reset; and `g_pMidiPlayer` xrefs from constructor/destructor/scalar-delete plus application, main-menu, music-control, sound-status, and audio-control consumers.
- 2026-06-06 live IDA evidence for [UID:0002B2][0x0069b870-0x0069b890.MidiSMFParserScratchGlobals](by-memory/0x0069b870-0x0069b890.MidiSMFParserScratchGlobals.md) confirms the parser scratch block is initialized to `0xffffffff`, bounded by separate data at `0x0069b86c` and `0x0069b890`, referenced only by `sub_5271B0`, and used for stream-fill state bits, selected-track pointer, best pending delta, and parsed-event scratch storage.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 80 | The page has a valid projected path, source-role summary, WinMM import boundary, proposed contents, ownership reasoning, and cross-links to the main class, global-state, singleton, parser, callback, reset, and helper pages. Completion stays at 80 because final helper/global names, raw helper splits, and possible private SMF document source split remain open. |
| Confidence | 86 | Confidence is strong for keeping the module in `NexusTK/audio/` and separate from `SoundManager`, based on repeated IDA function/caller/import checks and current scratch-state evidence. It remains below final-audit confidence because some private helper boundaries are still source-shape decisions rather than proven original declarations. |

## Open Questions

- Final source-facing names for [UID:0000T9][MidiPlayerWinMMState](by-global/MidiPlayerWinMMState.md) globals.
- Whether active output should materialize `0x00525be0`, `0x00525920`, `0x00526100`, `0x00526240`, and `0x005270e0` as `MidiPlayer` methods or private file-scope helpers.
- Whether the original source folder was named `audio/`, `sound/`, or a flatter VC6-era root.

## Cross-References

- [UID:00008A][MidiPlayer](by-class/MidiPlayer.md)
- [UID:0001CF][0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers](by-memory/0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers.md)
- [UID:0001CE][0x00525920-0x00525b0d.MidiStreamOpenAndPrimeBuffers](by-memory/0x00525920-0x00525b0d.MidiStreamOpenAndPrimeBuffers.md)
- [UID:0001CG][0x00525be0-0x00525dbb.MidiStreamCallback](by-memory/0x00525be0-0x00525dbb.MidiStreamCallback.md)
- [UID:0001CH][0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers](by-memory/0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers.md)
- [UID:00023B][0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers](by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md)
- [UID:00023C][0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers](by-memory/0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers.md)
- [UID:0001CI][0x005270e0-0x005271a3.MidiDocumentRelease](by-memory/0x005270e0-0x005271a3.MidiDocumentRelease.md)
- [UID:0000T9][MidiPlayerWinMMState](by-global/MidiPlayerWinMMState.md)
- [UID:0000RM][g_pMidiPlayer](by-global/g_pMidiPlayer.md)
- [UID:0000NV][SoundManager](by-file/SoundManager.md)
- [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md)
- [UID:0000LN][MusicControlDialog](by-file/MusicControlDialog.md)
- [UID:0001Q8][client_audio](by-meta/client_audio.md)
- [UID:0001QE][client_libraries](by-meta/client_libraries.md)

## Changes

- 2026-05-30: Previously this file page treated the MIDI reader/parser and SMF stream-fill spans as broad omitted helper islands. It now records exact child by-memory pages under [UID:00023B][0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers](by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md) and [UID:00023C][0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers](by-memory/0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers.md), while preserving `MidiPlayer.cpp` as the proposed owner. Evidence: IDA MCP boundary/callee checks for the child functions and raw function-shaped helper starts.
- 2026-06-01: Changed grading from `62/78` to `80/84` and set `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/audio/"`. Evidence: current IDA MCP confirms the WinMM MIDI source-family boundaries, callback pointer, reset/document-release callers, singleton xrefs, and parser/helper adjacency; confidence remains below very high because final helper/global names and exact original split from a possible private MIDI document file remain open.
- 2026-06-06: Raised confidence from `84` to `86` and removed stale provenance wording.
  - Summary/evidence: linked [UID:0002B2][0x0069b870-0x0069b890.MidiSMFParserScratchGlobals](by-memory/0x0069b870-0x0069b890.MidiSMFParserScratchGlobals.md) now records live IDA-confirmed parser-scratch initialization, boundaries, xref confinement to `sub_5271B0`, state-bit roles, and parent attachment to [UID:0000T9][MidiPlayerWinMMState](by-global/MidiPlayerWinMMState.md). The source file still stays below final-audit confidence because helper/global names and the possible private SMF helper split remain unresolved.
