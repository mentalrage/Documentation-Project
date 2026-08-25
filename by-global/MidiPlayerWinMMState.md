*** UID:0000T9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LD | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LD | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// MidiPlayerWinMMState is the documentation owner for the WinMM/static MIDI
// state family. It intentionally does not duplicate storage definitions here;
// exact data declarations belong to the child data pages that cover the concrete
// addresses, currently [UID:0002B1][0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals](by-memory/0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals.md) and [UID:0002B2][0x0069b870-0x0069b890.MidiSMFParserScratchGlobals](by-memory/0x0069b870-0x0069b890.MidiSMFParserScratchGlobals.md).
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

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
| `dword_69B510` / `DAT_0069B510` | `g_midiAllowEndReplay` / `g_midiFillReplayMode` | `MidiPlayer::SelectTrack` writes this before configured/fallback starts, and open/callback paths pass it into the stream-fill helper. Earlier docs called it a fill budget/limit; the current best name is an end-replay/fill-mode role. Prefer this over generated `g_midiUseLooseFile` until live decompile confirms exact semantics. |
| `dword_69B514` / `DAT_0069B514` | `g_midiDocumentLoaded` | Tracks whether a MIDI document/stream payload is loaded and needs release. Prefer this over generated `g_midiStreamOpen`, which overstates the flag as a stream-handle/open-state value. |
| `dword_69B518` / `DAT_0069B518` | `g_midiStreamRunning` | Guards callback refill and restart behavior. |
| `unk_69B51C` / `0x0069b51c` | `g_midiCallbackStreamOpen` | Inferred source-facing name. Constructor clears it and [UID:00041K][0x00525f40-0x0052609a.MidiPlayerRawVolumeAndStreamLocalHelpers](by-memory/0x00525f40-0x0052609a.MidiPlayerRawVolumeAndStreamLocalHelpers.md) sets it after successful callback-only `midiStreamOpen`; no other writer was found in the accepted [UID:0001CF][0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers](by-memory/0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers.md) pass. |
| `dword_69B520` / `g_midiHeadersPrepared` | `g_midiHeadersPrepared` | Controls unprepare of the two `MIDIHDR` slots. |
| `dword_69B524` | `g_midiVolumeScale` | Used when applying volume with `midiOutShortMsg` and `0x00525ff0`. |
| `dword_69B610` | `g_midiActiveHeaderIndex` | Rotates between the two prepared MIDI buffers. |
| `dword_69B614` | `g_midiPendingBufferCount` | Counts returned/submitted stream buffers during callback/reset. |
| `pmh` / `g_midiHeadersRaw` | `g_midiHeaders` | Two 84-byte `MIDIHDR`-sized records with buffer pointers and recorded-byte counts. |
| `dword_69B828` / `DAT_0069B828` | `g_midiDocumentState` | Passed to MIDI document parse/read/release helpers. |
| `Destination` | `g_midiCurrentPath` | Copied by `StartSelectedMidiFile` and opened by `MidiStreamOpenAndPrimeBuffers`; reject generated `g_midiSelectedPath` as a lower-quality alias because the same storage carries the current path consumed by stream setup. |

## State Families

| Family | Globals | Evidence |
| --- | --- | --- |
| WinMM stream and reset control | `hms`, `hObject`, `dword_69B508`, `dword_69B50C`, `dword_69B518`, `g_midiCallbackStreamOpen` | Stream setup opens the `HMIDISTRM`, reset/close stops and waits on the event, raw callback-only open sets the callback-open flag, and the callback gates refill/restart behavior through the same state words. |
| Two-buffer stream headers | `pmh`, `dword_69B520`, `dword_69B610`, `dword_69B614` | The helper pages document two `MIDIHDR` slots, prepared-header lifetime, active-slot rotation, and pending-buffer accounting across callback and reset. |
| Document and SMF parser state | `dword_69B514`, `dword_69B828`, `dword_69B870`, `dword_69B874`, `dword_69B878`, `dword_69B87C`, `xmmword_69B880` | Reader/parser helpers load and release the document state; the stream-fill helper uses the scratch range to pick the next track event, track parse flags, and replay pending output. |
| Volume and channel output | `dword_69B524`, channel-volume table at `0x0069b5d0` | The callback and volume helpers scale channel volume before sending `midiOutShortMsg` control changes through the WinMM stream. |
| Current file path | `g_midiCurrentPath` / `Destination` | Track-start and stream-open paths copy/open the current MIDI path as part of the same playback setup boundary. |

## 2026-06-17 SMF Parser Declaration Plan

B001's MIDI source-quality pass accepts descriptive declarations for the SMF parser/stream state used by exact helper pages. These are not proven original symbol names, but they are now preferred over raw `dword` names in draft C++:

```cpp
struct MidiDocument;
struct MidiTrackState;
struct MidiEvent;
struct MidiStreamWriteContext;

static MidiTrackState* g_midiTrackScanCursor;
static MidiTrackState* g_midiSelectedTrack;
static DWORD g_midiFillState;
static DWORD g_midiSelectedTick;
static MidiEvent g_midiPendingEvent;
```

`MidiDocument` is the static document/source context around `0x0069b828`; `MidiTrackState` is the 40-byte per-track record; `MidiEvent` is the 16-byte parsed-event scratch and handoff record; and `MidiStreamWriteContext` describes the caller-provided WinMM stream output buffer. Dedicated by-type pages for `MidiDocument`, `MidiTrackState`, `MidiEvent`, and `MidiStreamWriteContext` would improve the future score ceiling. Their absence no longer blocks function-body C++, and [UID:0002B2][0x0069b870-0x0069b890.MidiSMFParserScratchGlobals](by-memory/0x0069b870-0x0069b890.MidiSMFParserScratchGlobals.md) now supplies the concrete scratch-global storage declarations. Full `MidiDocument`, `MidiTrackState`, and `MidiStreamWriteContext` structure definitions should still be promoted into by-type pages or a shared `MidiPlayer.cpp` declaration block so generated helper code has complete type definitions before use.

Accepted parser result names are `MIDI_FILL_PARSE_FAILED = -101`, `MIDI_FILL_PREVIOUS_PARSE_FAILED = -102`, `MIDI_FILL_END_OF_STREAM = -103`, `MIDI_FILL_OUTPUT_FULL = -104`, and `MIDI_FILL_UNSUPPORTED_EVENT = -105`.

B003's 2026-06-18 scratch-global pass resolves [UID:0002B2][0x0069b870-0x0069b890.MidiSMFParserScratchGlobals](by-memory/0x0069b870-0x0069b890.MidiSMFParserScratchGlobals.md) as the private declaration block for the five stream-fill scratch globals above. B009's 2026-07-05 repair corrects its active static-initializer wording: current MCP session `supervisor_recovery_20260705` reads zero static storage at the sampled UID0002B2 dwords, while runtime `MidiFillStreamBuffer` writes `g_midiSelectedTick = 0xffffffff` during scans and clears other scratch state on first-fill/reset paths. The target still emits `struct MidiEvent`, `MidiFillResult`, fill-state bit constants, and private `static` storage at generation position `0` under this global-state owner so helper bodies can reference source-facing names instead of raw `dword_69B870`/`xmmword_69B880` placeholders.

## Behavior Evidence

| Range | Contribution |
| --- | --- |
| `0x00525920-0x00525b0d` | Opens the WinMM stream, creates the callback/event boundary, and primes the two-buffer playback state. |
| `0x00525be0-0x00525dbb` | Callback consumes returned headers, updates pending counts/state flags, refills stream buffers, applies volume state, and signals reset waits. |
| `0x00525ba0-0x00525bdf` | Raw no-route helper [UID:00041I][0x00525ba0-0x00525bdf.MidiApplySingleChannelVolumeRaw](by-memory/0x00525ba0-0x00525bdf.MidiApplySingleChannelVolumeRaw.md) sends a single channel-volume controller message from `g_midiChannelVolume` and `g_midiStreamRunning`. |
| `0x00525f40-0x0052609a` | [UID:00041K][0x00525f40-0x0052609a.MidiPlayerRawVolumeAndStreamLocalHelpers](by-memory/0x00525f40-0x0052609a.MidiPlayerRawVolumeAndStreamLocalHelpers.md) creates the buffer event, opens the callback stream, closes stream resources, applies global volume, and implements raw volume up/down methods. |
| `0x00526350-0x00526452` | [UID:00041N][0x00526350-0x00526452.MidiPlayerRawStreamControlHelpers](by-memory/0x00526350-0x00526452.MidiPlayerRawStreamControlHelpers.md) copies paths, opens/primes without restart, toggles pause, and restarts selected MIDI stream state. |
| `0x00526460-0x00526569` | Reset helper stops and resets the stream, waits for pending buffer return, unprepares headers, and conditionally reopens/restarts playback. |
| `0x005270e0-0x005271a3` | Releases document/parser state guarded by the loaded-document flag. |
| `0x005271b0-0x005273a0` | Stream-fill helper consumes the parser scratch globals to emit packed MIDI stream events into WinMM buffers. |
| `0x005273a0-0x005277bb` | SMF load helpers populate document/track state used by the callback refill path. |
| `0x0060c26a-0x0060c320` | Static lifetime wrapper constructs and tears down the document-state object attached to the same global-state family. |

## 2026-07-14 B004 UID00023C Declaration And Ownership Synchronization

- [UID:0002B1][0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals](by-memory/0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals.md) is the position-0 declaration owner for the private 0x48-byte `MidiDocument`, its exact 0x28-byte `MidiTrackState` records, the exact 0x54-byte `MidiStreamWriteContext`, `MidiLoadResult`, and the document constructor/load/failure/release/fill method declarations. These are `MidiPlayer.cpp` module support, not fields or methods of the 12-byte `MidiPlayer` instance.
- [UID:0002B2][0x0069b870-0x0069b890.MidiSMFParserScratchGlobals](by-memory/0x0069b870-0x0069b890.MidiSMFParserScratchGlobals.md) remains separate position-0 private fill scratch. Its five exact ranges are consumed only by [UID:0002C6][0x005271b0-0x005273a0.MidiStreamBufferFillHelper](by-memory/0x005271b0-0x005273a0.MidiStreamBufferFillHelper.md); reset does not write `g_midiSelectedTick`, while scan-time selection writes the runtime `0xffffffff` sentinel.
- [UID:0002C7][0x005273a0-0x005277bb.MidiSMFDocumentLoadHelper](by-memory/0x005273a0-0x005277bb.MidiSMFDocumentLoadHelper.md) returns `MidiLoadResult::Failure` as binary value `1`. [UID:0002C5][0x005270c0-0x005270d5.MidiDocumentLoadFailureWrapper](by-memory/0x005270c0-0x005270d5.MidiDocumentLoadFailureWrapper.md) therefore emits `MidiDocument::LoadFailed` and returns true on failure; historical parse-success naming is rejected-stale.
- The exact track/event/write layouts, two-buffer WinMM state, source-adapter/Win32 split, source-file route, child-owned declaration blocks, by-global aggregate marker, and `87/89` score are retained. Original spellings remain confidence caps; they do not justify merging this storage into the class or creating a separate source owner.

## Reconstruction Caveats

- This is a documentation grouping, not evidence of a single original global struct.
- Final names should be checked against the C++ rewrite and any recovered symbol names before treating them as recovered original names. UID0002B1 now supplies accepted descriptive declarations for the shared WinMM/static MIDI state; UID0002B2 supplies the SMF scratch globals and negative fill results. Remaining declaration uncertainty is limited to unrecovered original symbol spelling, dedicated by-type pages for the private MIDI structs, the stream-state constants `100`, `200`, and `300`, and the class-vs-file/private-helper split.
- 2026-07-05 B009 UID0002B1 repair: current MCP session `supervisor_recovery_20260705` resolves the old zero-byte/`0xffffffff` conflict by treating UID0002B1 and sampled UID0002B2 static storage as zero-initialized, with runtime constructor/fill writes carrying the `-1`, `500`, `100`, event-handle, and selected-tick sentinel behavior. [UID:0002B1][0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals](by-memory/0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals.md) now emits position-0 declarations for `g_hMidiStream`, device id storage, two `MIDIHDR` slots, prepared-header/running/restart flags, `g_midiAllowEndReplay`, `g_midiCurrentPath`, channel/default volume state, event handle, `MidiDocument`, and the end marker.
- 2026-07-02 B003 UID0001CE recheck remains the behavior proof for [UID:0001CE][0x00525920-0x00525b0d.MidiStreamOpenAndPrimeBuffers](by-memory/0x00525920-0x00525b0d.MidiStreamOpenAndPrimeBuffers.md), but its UID0002B1/shared-declaration blocker is now resolved at the data-declaration level. This support update does not add a UID0001CE function body; it only records that the previous no-code reason has been superseded by the B009 declaration repair.
- 2026-06-30 B013 recheck is retained as historical evidence for the zero-byte contradiction that forced the repair. The aggregate still emits only the `[[CHILDREN]]` route marker because exact storage declarations are child-owned by UID0002B1 and UID0002B2, not duplicated on this grouping page.
- B006's 2026-06-21 track-selection pass resolves the immediate [UID:0001CH][0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers](by-memory/0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers.md) naming dependencies for draft C++: `Destination` should be surfaced as `g_midiCurrentPath`, `0x0069b514` as `g_midiDocumentLoaded`, `0x0069b518` as `g_midiStreamRunning`, `0x0069b50c` as `g_midiRestartPending`, `0x0069b524` as `g_midiVolumeScale`, and `0x0069b510` as `g_midiAllowEndReplay` / `g_midiFillReplayMode`. The exact original spelling for `0x0069b510` remains a score cap, not a blocker for [UID:0001CH][0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers](by-memory/0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers.md)'s first-draft code.
- B011's 2026-06-25 [UID:0001CF][0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers](by-memory/0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers.md) split resolves the additional `0x0069b51c` state word as inferred `g_midiCallbackStreamOpen`, resolves the raw helper xrefs around `0x00525ba0`, `0x00525f40-0x0052609a`, and `0x00526350-0x00526452`, and confirms `ApplyMidiVolume` intentionally uses the old global `g_midiVolumeScale` while storing the new argument only after all channel sends succeed.
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
- [UID:00041H][0x00525b10-0x00525b98.MidiReleaseStreamBuffers](by-memory/0x00525b10-0x00525b98.MidiReleaseStreamBuffers.md)
- [UID:00041I][0x00525ba0-0x00525bdf.MidiApplySingleChannelVolumeRaw](by-memory/0x00525ba0-0x00525bdf.MidiApplySingleChannelVolumeRaw.md)
- [UID:00041J][0x00525dc0-0x00525f3d.MidiPlayerLifecycleMethods](by-memory/0x00525dc0-0x00525f3d.MidiPlayerLifecycleMethods.md)
- [UID:00041K][0x00525f40-0x0052609a.MidiPlayerRawVolumeAndStreamLocalHelpers](by-memory/0x00525f40-0x0052609a.MidiPlayerRawVolumeAndStreamLocalHelpers.md)
- [UID:00041N][0x00526350-0x00526452.MidiPlayerRawStreamControlHelpers](by-memory/0x00526350-0x00526452.MidiPlayerRawStreamControlHelpers.md)
- [UID:00041O][0x00526460-0x00526569.MidiPlayerResetStream](by-memory/0x00526460-0x00526569.MidiPlayerResetStream.md)
- [UID:0001CG][0x00525be0-0x00525dbb.MidiStreamCallback](by-memory/0x00525be0-0x00525dbb.MidiStreamCallback.md)
- [UID:0001CH][0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers](by-memory/0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers.md)
- [UID:00023B][0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers](by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md)
- [UID:00023C][0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers](by-memory/0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers.md)
- [UID:00024G][0x0060c26a-0x0060c320.StaticDestructorWrappersBeforePoolAllocators](by-memory/0x0060c26a-0x0060c320.StaticDestructorWrappersBeforePoolAllocators.md)
- [UID:0002B2][0x0069b870-0x0069b890.MidiSMFParserScratchGlobals](by-memory/0x0069b870-0x0069b890.MidiSMFParserScratchGlobals.md)

## Changes

- 2026-07-14 B004 UID00023C callback:
  - Score and aggregate formal disposition unchanged at `87/89`.
  - Summary/evidence: synchronized the exact 0x48-byte document, 0x28-byte track, 0x54-byte write-context, load-result, method-declaration, and separate fill-scratch contracts with UID0002B1/UID0002B2; recorded the corrected `LoadFailed` true-means-failure polarity and preserved private `MidiPlayer.cpp` ownership without converting storage into `MidiPlayer` fields or duplicating child declarations.
- 2026-07-05 B009 UID0002B1 implementation callback:
  - Score unchanged at `87/89`.
  - Summary/evidence: synchronized the global-state grouping with current MCP session `supervisor_recovery_20260705`; UID0002B1 now emits position-0 zero-initialized static state declarations, UID0002B2 static `0xffffffff` initializer wording is corrected to runtime sentinel behavior, the UID0001CE declaration blocker is marked superseded, and the by-global formal block remains a `[[CHILDREN]]` route rather than duplicate storage.
- 2026-07-02 B003 UID0001CE implementation callback:
  - Score unchanged at `87/89`.
  - Summary/evidence: added the UID0001CE-specific zero-byte/declaration blocker and repair plan from current MCP session `1f24c222`, tying the stream-open/prime helper to stream, document, header, current-path, channel/default-volume, active-index, and pending-buffer globals while preserving the aggregate no-code disposition until UID0002B1/shared declarations are repaired.
- 2026-06-30 B013 bounded empty-emitter implementation:
  - Score unchanged at `87/89`.
  - Summary/evidence: populated the formal block with the accepted no-code marker plus `[[CHILDREN]]` for this global-state aggregate. Exact state declarations remain child-owned, and [UID:0002B1][0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals](by-memory/0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals.md)/[UID:0002B2][0x0069b870-0x0069b890.MidiSMFParserScratchGlobals](by-memory/0x0069b870-0x0069b890.MidiSMFParserScratchGlobals.md) declaration consistency is explicitly follow-up because current MCP zero-byte evidence conflicts with stale `0xffffffff` initializer assumptions.
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
- 2026-06-17 B001 MIDI source-quality execution:
  - Score unchanged at `86/88`.
  - Summary/evidence: incorporated B001's accepted SMF parser declaration plan, including `MidiDocument`, `MidiTrackState`, `MidiEvent`, `MidiStreamWriteContext`, parser scratch names, and named fill results. Raw storage names remain preserved for evidence/searchability.
- 2026-06-18 B003 scratch-global declaration pass:
  - Changed from `86/88` to `87/89`.
  - Summary/evidence: [UID:0002B2][0x0069b870-0x0069b890.MidiSMFParserScratchGlobals](by-memory/0x0069b870-0x0069b890.MidiSMFParserScratchGlobals.md) now carries the first-draft private storage declarations, fill-state bit constants, `MidiFillResult`, `MidiEvent`, generation-position requirement, raw absolute-address scan confinement to `MidiFillStreamBuffer`, and the raw-file virtual-tail caveat for initialized bytes. This raises the global-state page because the scratch declarations are no longer an open code-entry blocker for the populated MIDI helper C++.
- 2026-06-21 B006 track-selection support sync:
  - Score unchanged.
  - Summary/evidence: added `g_midiAllowEndReplay` / `g_midiFillReplayMode` as the preferred descriptive name for `0x0069b510`, rejected generated `g_midiUseLooseFile`, rejected generated `g_midiStreamOpen` for `0x0069b514`, and clarified `g_midiCurrentPath` as the selected path storage copied by `StartSelectedMidiFile`.
- 2026-06-25 B011 [UID:0001CF][0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers](by-memory/0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers.md) support sync:
  - Score unchanged.
  - Summary/evidence: added inferred `g_midiCallbackStreamOpen` at `0x0069b51c`, raw helper xrefs from [UID:00041I][0x00525ba0-0x00525bdf.MidiApplySingleChannelVolumeRaw](by-memory/0x00525ba0-0x00525bdf.MidiApplySingleChannelVolumeRaw.md), [UID:00041K][0x00525f40-0x0052609a.MidiPlayerRawVolumeAndStreamLocalHelpers](by-memory/0x00525f40-0x0052609a.MidiPlayerRawVolumeAndStreamLocalHelpers.md), and [UID:00041N][0x00526350-0x00526452.MidiPlayerRawStreamControlHelpers](by-memory/0x00526350-0x00526452.MidiPlayerRawStreamControlHelpers.md), and synchronized the volume/header/reset state names with the new exact child pages.
