*** UID:00008A | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LD | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LD | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "MidiPlayer.h"
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_AUDIO_MIDIPLAYER_H
#define NEXUSTK_AUDIO_MIDIPLAYER_H

#include "../util/LObject.h"

class MidiPlayer : public LObject
{
public:
    MidiPlayer();
    virtual ~MidiPlayer();

    void IncreaseMidiVolume();
    void DecreaseMidiVolume();
    int IsPlaybackEnabled() const;
    void EnableMidiPlayback();
    void DisableMidiPlayback();
    void SelectTrack(unsigned short trackId);
    void StopPlayback();

private:
    int m_playbackEnabled;
    int m_selectedTrackId;
};

typedef char MidiPlayerSizeMustBe12[
    sizeof(MidiPlayer) == 0x0c ? 1 : -1];

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MidiPlayer

## Status

- Confidence: strong for behavior, WinMM ownership, source-family placement, singleton lifecycle, complete public class declaration, field layout, and standalone header route; private helper spellings remain separately bounded.
- Likely source file: [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md)
- Main address doc: [UID:0001CF][0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers](by-memory/0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers.md)
- Autogen status: attached to [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md). CPP emits the required `#include "MidiPlayer.h"` before existing child source; H emits the complete guarded class declaration and `0x0c` size assertion. Private helper bodies and the [UID:0002B1][0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals](by-memory/0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals.md)/[UID:0002B2][0x0069b870-0x0069b890.MidiSMFParserScratchGlobals](by-memory/0x0069b870-0x0069b890.MidiSMFParserScratchGlobals.md) declarations remain exact child-owned source.

## Class Purpose

`MidiPlayer` is the process MIDI playback controller. It tracks whether MIDI playback is enabled, manages the selected MIDI track sentinel, owns the process singleton [UID:0000RM][g_pMidiPlayer](by-global/g_pMidiPlayer.md), and coordinates WinMM stream shutdown through `MidiPlayer_ResetStream`.

This class is a sibling audio subsystem to [UID:0000DG][SoundManager](by-class/SoundManager.md). `SoundManager` manages Miles/MP3/WAV/Redbook audio policy; `MidiPlayer` owns WinMM MIDI state and buffering.

[UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md) is an external UI consumer. Its key handler calls `IsPlaybackEnabled`, `EnableMidiPlayback`, and `DisableMidiPlayback`, paired with SoundManager music mute/unmute calls. This consumer requires the complete `MidiPlayer.h` declaration and [UID:0000RM][g_pMidiPlayer](by-global/g_pMidiPlayer.md) extern but does not own MIDI state.

## Layout Notes

Current evidence suggests a compact 12-byte object allocated by `Application`:

| Offset | Field | Evidence |
| --- | --- | --- |
| `0x00` | `LObject`/vtable base | Constructor calls `LObject::LObject` and installs `MidiPlayer_vtable`. |
| `0x04` | `m_playbackEnabled` | `IsPlaybackEnabled`, `EnableMidiPlayback`, and `DisableMidiPlayback` read/write this dword. |
| `0x08` | `m_selectedTrackId` | Selected MIDI track id; constructor, disable, and stop store `-1`, while `SelectTrack(unsigned short trackId)` compares against the requested id and stores valid ids `0..12`. This is not the WinMM device id; `puDeviceID` / `g_midiDeviceId` is global device storage at `0x0069b504`. |

`m_selectedTrackId` is now the preferred field name. Older generated names such as `m_selectedDeviceId` or `m_currentDeviceId` are rejected because [UID:0001CH][0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers](by-memory/0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers.md) compares the field to requested track ids, clears it to the no-track sentinel, and does not use it as the WinMM device id.

## Source Placement And Runtime Boundary

`MidiPlayer` belongs in the audio source family as the WinMM MIDI controller. It should remain separate from [UID:0000DG][SoundManager](by-class/SoundManager.md), which owns the broader Miles/MP3/WAV/Redbook policy. The MIDI pages consistently tie this class to Windows `WINMM` stream APIs, two prepared MIDI buffers, a stream callback, a document/parser state block, and a process singleton.

The file-level owner [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md) is projected to `NexusTK/audio/`. Treat [UID:0000T9][MidiPlayerWinMMState](by-global/MidiPlayerWinMMState.md) as a documentation map for related globals, not proof of a single original struct.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `MidiPlayer` | `0x00525dc0-0x00525ea6` | [UID:00041J][0x00525dc0-0x00525f3d.MidiPlayerLifecycleMethods](by-memory/0x00525dc0-0x00525f3d.MidiPlayerLifecycleMethods.md) constructs `LObject`, assigns `g_pMidiPlayer`, initializes playback flags and WinMM global state, creates the buffer-return event. |
| `~MidiPlayer` | `0x00525eb0-0x00525f3d` | [UID:00041J][0x00525dc0-0x00525f3d.MidiPlayerLifecycleMethods](by-memory/0x00525dc0-0x00525f3d.MidiPlayerLifecycleMethods.md) resets stream if open, releases MIDI buffers, closes stream/event handles, clears singleton, destroys `LObject`. |
| `IsPlaybackEnabled` | `0x005260a0-0x005260a4` | [UID:00041L][0x005260a0-0x005260ff.MidiPlayerPlaybackToggleMethods](by-memory/0x005260a0-0x005260ff.MidiPlayerPlaybackToggleMethods.md) returns the playback-enabled field. |
| `EnableMidiPlayback` | `0x005260b0-0x005260ca` | [UID:00041L][0x005260a0-0x005260ff.MidiPlayerPlaybackToggleMethods](by-memory/0x005260a0-0x005260ff.MidiPlayerPlaybackToggleMethods.md) sets Config offset `+0x28de50` and object playback flag if currently disabled. |
| `DisableMidiPlayback` | `0x005260d0-0x005260ff` | [UID:00041L][0x005260a0-0x005260ff.MidiPlayerPlaybackToggleMethods](by-memory/0x005260a0-0x005260ff.MidiPlayerPlaybackToggleMethods.md) clears Config offset `+0x28de50`, clears selected-track sentinel, resets stream, and marks playback disabled. |
| `SelectTrack` | `0x00526100-0x00526233` | Class method. Selects a requested MIDI track, checks `Config::m_midiEnabled`, `m_playbackEnabled`, `trackId <= 12`, and `m_selectedTrackId`, resets current playback state, resolves configured `Midi\\%s` and fallback `%d.mid` paths through Config string preferences, and starts playback through `StartSelectedMidiFile`. |
| `StartSelectedMidiFile` | `0x00526240-0x00526332` | Private file helper, not a class method. Copies the selected path into `g_midiCurrentPath`, resets/opens/primes/restarts the WinMM stream, updates global running/restart state, and reapplies MIDI volume. |
| `IncreaseMidiVolume` | `0x00526060-0x0052607b` | [UID:00041K][0x00525f40-0x0052609a.MidiPlayerRawVolumeAndStreamLocalHelpers](by-memory/0x00525f40-0x0052609a.MidiPlayerRawVolumeAndStreamLocalHelpers.md) raw class-shaped method that checks `m_playbackEnabled`, raises `g_midiVolumeScale` by 100 when the scale is at or below 900, and calls the private `__stdcall ApplyMidiVolume` helper. |
| `DecreaseMidiVolume` | `0x00526080-0x00526099` | [UID:00041K][0x00525f40-0x0052609a.MidiPlayerRawVolumeAndStreamLocalHelpers](by-memory/0x00525f40-0x0052609a.MidiPlayerRawVolumeAndStreamLocalHelpers.md) raw class-shaped method that checks `m_playbackEnabled`, lowers `g_midiVolumeScale` by 100 when the scale is at or above 100, and calls the private `__stdcall ApplyMidiVolume` helper. |
| `StopPlayback` | `0x00526340-0x00526350` | [UID:00041M][0x00526340-0x00526350.MidiPlayerStopPlayback](by-memory/0x00526340-0x00526350.MidiPlayerStopPlayback.md) clears selected-track sentinel and calls `MidiPlayer_ResetStream(0)`. |
| `ScalarDeletingDestructor` | `0x00526580-0x0052664b` | [UID:00041P][0x00526570-0x0052664b.MidiPlayerCompilerCleanupHelpers](by-memory/0x00526570-0x0052664b.MidiPlayerCompilerCleanupHelpers.md) is MSVC scalar deleting destructor glue; source output belongs to the destructor and class declaration, not a hand-authored method body. |

## Related Free Helpers

- [UID:00041H][0x00525b10-0x00525b98.MidiReleaseStreamBuffers](by-memory/0x00525b10-0x00525b98.MidiReleaseStreamBuffers.md) `ReleaseMidiStreamBuffers` unprepares headers and frees backing buffers.
- [UID:00041I][0x00525ba0-0x00525bdf.MidiApplySingleChannelVolumeRaw](by-memory/0x00525ba0-0x00525bdf.MidiApplySingleChannelVolumeRaw.md) `SendMidiChannelVolume` is a raw no-route helper that sends one controller-7 channel-volume message.
- [UID:00041K][0x00525f40-0x0052609a.MidiPlayerRawVolumeAndStreamLocalHelpers](by-memory/0x00525f40-0x0052609a.MidiPlayerRawVolumeAndStreamLocalHelpers.md) contains source-ready raw event/open/close helpers, `__stdcall ApplyMidiVolume`, and raw volume up/down methods; exact raw helper names remain inferred confidence caps, not formal C++ blockers.
- [UID:00041N][0x00526350-0x00526452.MidiPlayerRawStreamControlHelpers](by-memory/0x00526350-0x00526452.MidiPlayerRawStreamControlHelpers.md) contains raw stream-control helpers distinct from `StartSelectedMidiFile`.
- [UID:00041O][0x00526460-0x00526569.MidiPlayerResetStream](by-memory/0x00526460-0x00526569.MidiPlayerResetStream.md) `MidiPlayer_ResetStream` stops and resets the active stream, optionally reopening playback depending on flags.
- [UID:00041P][0x00526570-0x0052664b.MidiPlayerCompilerCleanupHelpers](by-memory/0x00526570-0x0052664b.MidiPlayerCompilerCleanupHelpers.md) records the singleton clear helper and scalar deleting destructor as non-emitting compiler cleanup.
- [UID:0001CE][0x00525920-0x00525b0d.MidiStreamOpenAndPrimeBuffers](by-memory/0x00525920-0x00525b0d.MidiStreamOpenAndPrimeBuffers.md) opens the WinMM stream and primes the two MIDI buffers.
- [UID:0001CG][0x00525be0-0x00525dbb.MidiStreamCallback](by-memory/0x00525be0-0x00525dbb.MidiStreamCallback.md) is the IDA-confirmed WinMM callback passed to `midiStreamOpen`.
- [UID:00023B][0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers](by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md) owns the file/adapter-backed Standard MIDI File reader, track event decoder, and stream-event encoder helpers.
- [UID:0002BS][0x00526650-0x005266a1.MidiExactReadHelper](by-memory/0x00526650-0x005266a1.MidiExactReadHelper.md) is private file-scope `MidiReadExact` over the `MidiDocument` source context, not a `MidiPlayer` object method; its formal C++ lives on the exact child page and implements DATFile/Win32 exact-count reads with failed/short-read nonzero return semantics.
- [UID:0002BW][0x00526bb0-0x00526cd9.MidiVariableLengthQuantityReader](by-memory/0x00526bb0-0x00526cd9.MidiVariableLengthQuantityReader.md) is private file-scope `MidiReadVariableLength` over the `MidiDocument`/`MidiTrackState` parser state, not a `MidiPlayer` object method; its formal C++ lives on the exact child page and decodes SMF VLQ values with inline 0x400-byte DATFile/Win32 refill.
- [UID:0002C1][0x00526fa0-0x00526ff6.MidiSourceSeekHelper](by-memory/0x00526fa0-0x00526ff6.MidiSourceSeekHelper.md) is private file-scope `MidiSeekSource` over the `MidiDocument` source context, not a `MidiPlayer` object method; its formal C++ lives on the exact child page while the raw no-route evidence remains a confidence cap.
- [UID:0001CI][0x005270e0-0x005271a3.MidiDocumentRelease](by-memory/0x005270e0-0x005271a3.MidiDocumentRelease.md) releases MIDI document/parser resources used by reset/callback paths.
- [UID:00023C][0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers](by-memory/0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers.md) loads the SMF track table and fills WinMM stream buffers from parsed track events.
- [UID:0002B1][0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals](by-memory/0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals.md) records the shared WinMM stream/device/header/channel/path/event/document/end-marker storage emitted as position-0 private `MidiPlayer.cpp` declarations.
- [UID:0002B2][0x0069b870-0x0069b890.MidiSMFParserScratchGlobals](by-memory/0x0069b870-0x0069b890.MidiSMFParserScratchGlobals.md) records the stream-fill scratch bitfield, selected-track pointer, best pending delta, and parsed-event scratch storage consumed by `sub_5271B0`.

B001's 2026-06-17 source-quality pass accepts descriptive private helper/type names for the SMF parser family: `MidiDocument`, `MidiTrackState`, `MidiEvent`, `MidiStreamWriteContext`, `MidiReadEvent`, `MidiWriteStreamEvent`, `MidiFillStreamBuffer`, and `MidiLoadDocument`. The 2026-06-29 B007 implementation resolves `MidiReadExact` on [UID:0002BS][0x00526650-0x005266a1.MidiExactReadHelper](by-memory/0x00526650-0x005266a1.MidiExactReadHelper.md), the 2026-06-29 B008 implementation resolves `MidiReadVariableLength` on [UID:0002BW][0x00526bb0-0x00526cd9.MidiVariableLengthQuantityReader](by-memory/0x00526bb0-0x00526cd9.MidiVariableLengthQuantityReader.md), and the 2026-06-28 B001 implementation resolves `MidiSeekSource` on [UID:0002C1][0x00526fa0-0x00526ff6.MidiSourceSeekHelper](by-memory/0x00526fa0-0x00526ff6.MidiSourceSeekHelper.md). These remain private file helpers under [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md), not `MidiPlayer` object methods, because they operate on the private MIDI document/track/source state and WinMM stream buffers rather than the 12-byte class instance.

B009's 2026-07-05 UID0002B1 repair confirms the shared WinMM/static state and [UID:0002B2][0x0069b870-0x0069b890.MidiSMFParserScratchGlobals](by-memory/0x0069b870-0x0069b890.MidiSMFParserScratchGlobals.md) scratch block are private file-static implementation storage, not `MidiPlayer` object layout. Do not convert `g_hMidiStream`, `g_midiHeaders`, `g_midiCurrentPath`, `g_midiDocumentState`, `g_midiTrackScanCursor`, `g_midiSelectedTrack`, `g_midiFillState`, `g_midiSelectedTick`, or `g_midiPendingEvent` into class fields; the 12-byte instance layout remains the singleton's playback flag and selected-track/device sentinel, while the globals are emitted through [UID:0000T9][MidiPlayerWinMMState](by-global/MidiPlayerWinMMState.md) before helper bodies.

## Touched State

| State/global | Access pattern | Evidence |
| --- | --- | --- |
| [UID:0000RM][g_pMidiPlayer](by-global/g_pMidiPlayer.md) / `0x0067ab4c` | Constructor assigns the active singleton; destructor/scalar-delete cleanup clears it; application, main-menu, music-control, sound-status, and audio-control consumers read it. | [UID:0000RM][g_pMidiPlayer](by-global/g_pMidiPlayer.md) and [UID:0001CF][0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers](by-memory/0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers.md). |
| `this+0x04` | Playback-enabled flag used by enable/disable/select helpers. | Class methods and [UID:0001CH][0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers](by-memory/0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers.md). |
| `this+0x08` | Selected MIDI track sentinel; constructor, disable, stop, and select paths store or compare `m_selectedTrackId`. | Class methods and [UID:0001CH][0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers](by-memory/0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers.md). |
| [UID:0000T9][MidiPlayerWinMMState](by-global/MidiPlayerWinMMState.md) | Stream handle, callback event, prepared headers, stream state flags, volume, current path, and parser/document state. | State map plus stream open/callback/reset/parser pages. |
| [UID:0002B2][0x0069b870-0x0069b890.MidiSMFParserScratchGlobals](by-memory/0x0069b870-0x0069b890.MidiSMFParserScratchGlobals.md) | Stream-fill scratch globals used to resume parser state, retry output-full events, store selected-track scan state, and hold the parsed-event record. | Live IDA confirms all direct refs are inside `sub_5271B0`, the stream-fill helper in [UID:00023C][0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers](by-memory/0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers.md). |
| `g_pConfig + 0x84c` / `Config::m_midiEnabled` | Low MIDI selector-enable byte checked by [UID:0001CH][0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers](by-memory/0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers.md) `SelectTrack`; `int_convert.py` verified decimal `2124 == 0x84c`. | [UID:0001CH][0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers](by-memory/0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers.md). |
| `g_pConfig + 0x28de50` / inferred `Config::m_musicEnabled` | Music/MIDI output enable byte copied by [UID:00041J][0x00525dc0-0x00525f3d.MidiPlayerLifecycleMethods](by-memory/0x00525dc0-0x00525f3d.MidiPlayerLifecycleMethods.md) constructor and written by [UID:00041L][0x005260a0-0x005260ff.MidiPlayerPlaybackToggleMethods](by-memory/0x005260a0-0x005260ff.MidiPlayerPlaybackToggleMethods.md) enable/disable methods. Keep distinct from `+0x84c`. | [UID:00041J][0x00525dc0-0x00525f3d.MidiPlayerLifecycleMethods](by-memory/0x00525dc0-0x00525f3d.MidiPlayerLifecycleMethods.md), [UID:00041L][0x005260a0-0x005260ff.MidiPlayerPlaybackToggleMethods](by-memory/0x005260a0-0x005260ff.MidiPlayerPlaybackToggleMethods.md), and [UID:00028Q][0x0067a7c8-0x0067a7cc.g_pConfig](by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md). |

## Boundary And Helper Map

| Range | Kind | Notes |
| --- | --- | --- |
| `0x00525920-0x00525b0d` | stream open/prime helper | Opens WinMM stream and primes two buffers before playback. |
| `0x00525b0d-0x00525b10` | alignment | Boundary padding before `ReleaseMidiBuffers_525B10`. |
| `0x00525b10-0x0052664b` | main sparse class/helper island | Parent aggregate [UID:0001CF][0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers](by-memory/0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers.md) now split into exact children for release, raw helpers, lifecycle, toggles, stop, reset, and compiler cleanup. |
| `0x00526332-0x00526340` | alignment | Padding before `StopPlayback`. |
| `0x0052664b-0x00526650` | alignment | Padding before the SMF reader/parser island. |
| `0x00526650-0x005270d5` | MIDI file reader/parser helpers | Standard MIDI File reader, track event decoder, and stream-event encoder helpers. |
| `0x005270e0-0x005271a3` | MIDI document release | Releases document/parser resources used by callback/open/reset paths. |
| `0x005271b0-0x005277bb` | SMF load/fill helpers | Loads track tables and fills WinMM stream buffers from parsed events. |

## Data Caveats

- Several MIDI state globals still have provisional source-facing names, but the UID0002B1/UID0002B2 declaration pass now supplies first-draft C++ storage; remaining uncertainty is original spelling and final type polish, not an empty declaration blocker.
- The SMF parser/source exact child pages [UID:0002BS][0x00526650-0x005266a1.MidiExactReadHelper](by-memory/0x00526650-0x005266a1.MidiExactReadHelper.md), [UID:0002BU][0x00526790-0x005269ea.MidiEventReader](by-memory/0x00526790-0x005269ea.MidiEventReader.md), [UID:0002BV][0x005269f0-0x00526ba8.MidiStreamEventEncoder](by-memory/0x005269f0-0x00526ba8.MidiStreamEventEncoder.md), [UID:0002BW][0x00526bb0-0x00526cd9.MidiVariableLengthQuantityReader](by-memory/0x00526bb0-0x00526cd9.MidiVariableLengthQuantityReader.md), [UID:0002C1][0x00526fa0-0x00526ff6.MidiSourceSeekHelper](by-memory/0x00526fa0-0x00526ff6.MidiSourceSeekHelper.md), [UID:0002C6][0x005271b0-0x005273a0.MidiStreamBufferFillHelper](by-memory/0x005271b0-0x005273a0.MidiStreamBufferFillHelper.md), and [UID:0002C7][0x005273a0-0x005277bb.MidiSMFDocumentLoadHelper](by-memory/0x005273a0-0x005277bb.MidiSMFDocumentLoadHelper.md) now have draft C++ using accepted descriptive names. Remaining class-level caveats concern original symbols, sibling helper declarations, and whether a private SMF helper source file existed, not whether these helper bodies should remain blank.
- `MidiPlayer_ResetStream` and the raw helper blocks now use accepted source-facing names through [UID:00041H][0x00525b10-0x00525b98.MidiReleaseStreamBuffers](by-memory/0x00525b10-0x00525b98.MidiReleaseStreamBuffers.md) through [UID:00041P][0x00526570-0x0052664b.MidiPlayerCompilerCleanupHelpers](by-memory/0x00526570-0x0052664b.MidiPlayerCompilerCleanupHelpers.md). State-global names remain descriptive/inferred where original symbols are absent; see [UID:0000T9][MidiPlayerWinMMState](by-global/MidiPlayerWinMMState.md).
- `0x00525be0`, `0x00525920`, the broader `0x00526650-0x005270d5` helper island, and `0x005270e0` are IDA-confirmed source-family members, but their final shape as class methods versus private file-scope helpers remains open where exact child pages have not resolved it. [UID:0002BS][0x00526650-0x005266a1.MidiExactReadHelper](by-memory/0x00526650-0x005266a1.MidiExactReadHelper.md) is resolved as private file-scope `MidiReadExact`, not a class method, [UID:0002BW][0x00526bb0-0x00526cd9.MidiVariableLengthQuantityReader](by-memory/0x00526bb0-0x00526cd9.MidiVariableLengthQuantityReader.md) is resolved as private file-scope `MidiReadVariableLength`, not a class method, and [UID:0002C1][0x00526fa0-0x00526ff6.MidiSourceSeekHelper](by-memory/0x00526fa0-0x00526ff6.MidiSourceSeekHelper.md) is resolved as private file-scope `MidiSeekSource`, not a class method. The [UID:0001CF][0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers](by-memory/0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers.md) subranges are resolved: lifecycle/toggle/stop methods belong to this class, raw no-route helpers are file-local/source-family helpers, and `0x00526570-0x0052664b` is compiler cleanup glue.
- 2026-05-26 recheck: IDA MCP resolves the omitted helper starts with the same MIDI-family callers, so do not infer separate original files only from the class/private-helper split.
- 2026-05-28 recheck: the former unknown span after `0x0052664b` is MIDI reader/parser code plus alignment padding, not an unrelated subsystem or arbitrary gap.
- 2026-05-28 recheck: the former unknown span after `0x005271a3` is the matching SMF load/stream-fill helper island plus alignment padding before `MiscWorkThread`.
- 2026-05-30 recheck: [UID:00023B][0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers](by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md) is now nested into exact child pages for the file/adapter reader, event reader, stream-event encoder, track-buffer helpers, and parser wrapper. Treat those as private helper routines tied to this MIDI subsystem unless later source evidence proves a separate owner.
- 2026-05-30 recheck: [UID:00023C][0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers](by-memory/0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers.md) is now nested into exact child pages for stream-buffer fill and SMF document load. These remain private MIDI helper routines unless later source evidence proves a separate owner.
- 2026-06-01 recheck: [UID:0001CF][0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers](by-memory/0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers.md) records current IDA function sizes across the sparse class/helper island, reset fan-in from callback/destructor/disable/select/start/stop/scalar-delete paths, WinMM callees, and boundary padding at `0x00525b0d`, `0x00526332`, and `0x0052664b`.
- 2026-06-01 recheck: [UID:0001CH][0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers](by-memory/0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers.md) confirms the select helper checks config music state, object playback state, requested track id, and selected-track field before resolving configured/fallback paths and starting stream playback.
- 2026-06-06 live IDA refresh confirms the main class/method starts and sizes: constructor `0x00525dc0` size `0xe6`, destructor `0x00525eb0` size `0x8d`, `IsPlaybackEnabled` `0x005260a0` size `0x4`, `EnableMidiPlayback` `0x005260b0` size `0x1a`, `DisableMidiPlayback` `0x005260d0` size `0x2f`, select helper `0x00526100` size `0x133`, start selected path helper `0x00526240` size `0xf2`, `StopPlayback` `0x00526340` size `0x10`, reset helper `0x00526460` size `0x109`, singleton clear helper `0x00526570` size `0xb`, and scalar deleting destructor `0x00526580` size `0xcb`.
- `xrefs_to 0x0067ab4c` on 2026-06-06 reports the expected singleton lifecycle refs in constructor/destructor/clear/scalar-delete plus application, main-menu, music-control, sound-status/audio-control, and shutdown consumers. The same xref set supports keeping [UID:0000RM][g_pMidiPlayer](by-global/g_pMidiPlayer.md) with this class/file family.
- 2026-06-06 scratch-state refresh: [UID:0002B2][0x0069b870-0x0069b890.MidiSMFParserScratchGlobals](by-memory/0x0069b870-0x0069b890.MidiSMFParserScratchGlobals.md) recorded historical initialized-byte evidence, previous/next data boundaries, all direct refs confined to `sub_5271B0`, stream-fill bitfield roles, selected-track/best-delta storage, and parsed-event scratch usage. B009's 2026-07-05 support repair supersedes the static-initializer reading with current MCP zero static storage plus runtime selected-tick sentinel writes.
- 2026-06-15 C001 `.rdata` owner-gate refresh opened IDA MCP session `c001_midiplayer_rdata_20260615` on `NexusTK.exe.i64`, confirmed Hex-Rays/string-cache readiness, and reconfirmed the `MidiPlayer` read-only island: `0x0061faf8 -> ??_R4MidiPlayer@@6B@`, `0x0061fafc -> ??_7MidiPlayer@@6B@`, vtable write/data refs from constructor `0x00525dc0`, destructor `0x00525eb0`, and scalar deleting destructor `0x00526580`, track-selection format refs from `0x0052619c`/`0x005261f0`, and successor `MiscWorkThread` vtable refs at `0x0061fb74`.
- The same C001 refresh used `lookup_funcs` and `analyze_component` to reconfirm constructor/destructor/select/start/reset/scalar-deleting-destructor sizes and the internal call graph: select helper `0x00526100` calls start helper `0x00526240` and reset helper `0x00526460`; start, destructor, and scalar deleting destructor also flow through reset/cleanup. This closes the strict owner-gate blocker for the exact `MidiPlayer` RTTI locator child while leaving final helper/global names below final-C++ readiness.

## 2026-07-14 B004 UID00023C Private Document Boundary

- `MidiDocument` is private `MidiPlayer.cpp` module support, not a subobject of the 12-byte `MidiPlayer` controller and not a `MidiPlayer` method family. The class instance remains exactly the `LObject` base/vptr, playback-enabled field, and selected-track sentinel documented above.
- [UID:0002B1][0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals](by-memory/0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals.md) emits the private 0x48-byte document declaration and the 0x28-byte track and 0x54-byte stream-write-context layouts at file position 0. [UID:0002B2][0x0069b870-0x0069b890.MidiSMFParserScratchGlobals](by-memory/0x0069b870-0x0069b890.MidiSMFParserScratchGlobals.md) remains separate file-static fill scratch.
- [UID:0002C4][0x00527080-0x005270b5.MidiReaderConstructorInit](by-memory/0x00527080-0x005270b5.MidiReaderConstructorInit.md), [UID:0002C7][0x005273a0-0x005277bb.MidiSMFDocumentLoadHelper](by-memory/0x005273a0-0x005277bb.MidiSMFDocumentLoadHelper.md), [UID:0002C5][0x005270c0-0x005270d5.MidiDocumentLoadFailureWrapper](by-memory/0x005270c0-0x005270d5.MidiDocumentLoadFailureWrapper.md), [UID:0001CI][0x005270e0-0x005271a3.MidiDocumentRelease](by-memory/0x005270e0-0x005271a3.MidiDocumentRelease.md), and [UID:0002C6][0x005271b0-0x005273a0.MidiStreamBufferFillHelper](by-memory/0x005271b0-0x005273a0.MidiStreamBufferFillHelper.md) are the private document constructor/load/failure/release/fill source family. `LoadFailed` returns true when `Load` returns the binary failure value `1`; it is not a parse-success predicate.
- The controller lifecycle/vtable/public playback surface and every unrelated helper conclusion remain unchanged. The former aggregate marker is superseded by the complete CPP include and H declaration above. Historical `MidiFillStreamBuffer`, `MidiLoadDocument`, parse-success-wrapper, and separate helper-file names remain provenance only where explicitly dated; they are not the current source contract.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 89 | The existing compact object, method, helper, WinMM, parser, and global-state inventory now has a complete guarded H declaration, exact `LObject` include, public surface, two-field `0x0c` assertion, CPP header include, semantic-global declaration route, and SoundStatusPane consumer. Remaining gaps are private helper/static-state names outside this class contract. |
| Confidence | 92 | IDA-backed method sizes, singleton xrefs, allocation/layout, vtable, field access, WinMM imports, child formals, and the generated producer/consumer requirement converge on the emitted class/header route. Uncertainty remains limited to unrelated private helper/global spellings. |

## Open Questions

- Final names for the WinMM state globals and whether some belong as file-scope globals versus a recovered private state object.
- Whether `0x00525be0`, `0x00525920`, and `0x005270e0` should be final class methods or private file-scope helpers. `0x00526100` / `0x00526240` are resolved as `MidiPlayer::SelectTrack` plus file-static `StartSelectedMidiFile`.
- [UID:00041K][0x00525f40-0x0052609a.MidiPlayerRawVolumeAndStreamLocalHelpers](by-memory/0x00525f40-0x0052609a.MidiPlayerRawVolumeAndStreamLocalHelpers.md) is now source-ready: current MCP session `60724697` resolves the range, padding, no-route raw starts, `g_pfnCreateEventW` dispatch-slot event creation, and `__stdcall ApplyMidiVolume` ABI. Exact raw helper spellings remain confidence caps only, not naming/splitting blockers. [UID:0002BS][0x00526650-0x005266a1.MidiExactReadHelper](by-memory/0x00526650-0x005266a1.MidiExactReadHelper.md), [UID:0002BW][0x00526bb0-0x00526cd9.MidiVariableLengthQuantityReader](by-memory/0x00526bb0-0x00526cd9.MidiVariableLengthQuantityReader.md), and [UID:0002C1][0x00526fa0-0x00526ff6.MidiSourceSeekHelper](by-memory/0x00526fa0-0x00526ff6.MidiSourceSeekHelper.md) remain outside that historical blank-helper caveat.

## Cross-References

- [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md)
- [UID:0001CF][0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers](by-memory/0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers.md)
- [UID:00041H][0x00525b10-0x00525b98.MidiReleaseStreamBuffers](by-memory/0x00525b10-0x00525b98.MidiReleaseStreamBuffers.md)
- [UID:00041I][0x00525ba0-0x00525bdf.MidiApplySingleChannelVolumeRaw](by-memory/0x00525ba0-0x00525bdf.MidiApplySingleChannelVolumeRaw.md)
- [UID:00041J][0x00525dc0-0x00525f3d.MidiPlayerLifecycleMethods](by-memory/0x00525dc0-0x00525f3d.MidiPlayerLifecycleMethods.md)
- [UID:00041K][0x00525f40-0x0052609a.MidiPlayerRawVolumeAndStreamLocalHelpers](by-memory/0x00525f40-0x0052609a.MidiPlayerRawVolumeAndStreamLocalHelpers.md)
- [UID:00041L][0x005260a0-0x005260ff.MidiPlayerPlaybackToggleMethods](by-memory/0x005260a0-0x005260ff.MidiPlayerPlaybackToggleMethods.md)
- [UID:00041M][0x00526340-0x00526350.MidiPlayerStopPlayback](by-memory/0x00526340-0x00526350.MidiPlayerStopPlayback.md)
- [UID:00041N][0x00526350-0x00526452.MidiPlayerRawStreamControlHelpers](by-memory/0x00526350-0x00526452.MidiPlayerRawStreamControlHelpers.md)
- [UID:00041O][0x00526460-0x00526569.MidiPlayerResetStream](by-memory/0x00526460-0x00526569.MidiPlayerResetStream.md)
- [UID:00041P][0x00526570-0x0052664b.MidiPlayerCompilerCleanupHelpers](by-memory/0x00526570-0x0052664b.MidiPlayerCompilerCleanupHelpers.md)
- [UID:0001CE][0x00525920-0x00525b0d.MidiStreamOpenAndPrimeBuffers](by-memory/0x00525920-0x00525b0d.MidiStreamOpenAndPrimeBuffers.md)
- [UID:0001CG][0x00525be0-0x00525dbb.MidiStreamCallback](by-memory/0x00525be0-0x00525dbb.MidiStreamCallback.md)
- [UID:0001CH][0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers](by-memory/0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers.md)
- [UID:00023B][0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers](by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md)
- [UID:0001CI][0x005270e0-0x005271a3.MidiDocumentRelease](by-memory/0x005270e0-0x005271a3.MidiDocumentRelease.md)
- [UID:00023C][0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers](by-memory/0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers.md)
- [UID:0002B1][0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals](by-memory/0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals.md)
- [UID:0002B2][0x0069b870-0x0069b890.MidiSMFParserScratchGlobals](by-memory/0x0069b870-0x0069b890.MidiSMFParserScratchGlobals.md)
- [UID:0000T9][MidiPlayerWinMMState](by-global/MidiPlayerWinMMState.md)
- [UID:0000RM][g_pMidiPlayer](by-global/g_pMidiPlayer.md)
- [UID:0000DG][SoundManager](by-class/SoundManager.md)
- [UID:0000DJ][SoundStatusPane](by-class/SoundStatusPane.md)
- [UID:0001Q8][client_audio](by-meta/client_audio.md)

## Changes

- 2026-08-24 B009 UID0000NX callback: Raised `87/90` to `89/92`. Replaced no-code commentary with `#include "MidiPlayer.h"`, added the complete guarded 12-byte class declaration, recorded the UID0000RM extern route, and documented SoundStatusPane as an external playback-toggle consumer.
- 2026-07-14 B004 UID00023C callback:
  - Score and formal aggregate disposition unchanged at `87/90`.
  - Summary/evidence: recorded that the private 0x48-byte `MidiDocument`, its constructor/load/failure/release/fill operations, its 0x28-byte tracks, its 0x54-byte write context, and its separate scratch block are `MidiPlayer.cpp` module support rather than fields or methods of the 12-byte `MidiPlayer` object. Preserved the complete controller layout, lifecycle, vtable, public playback surface, and unrelated helper history.
- 2026-07-05 B009 UID0002B1 implementation callback:
  - Score unchanged at `87/90`.
  - Summary/evidence: synchronized the class aggregate with UID0002B1's position-0 shared state declarations and UID0002B2's corrected zero static storage wording. The class page remains a no-code aggregate; shared WinMM/static state and stream-fill scratch globals stay private file-static implementation storage, not `MidiPlayer` object fields.
- 2026-06-30 B013 bounded empty-emitter implementation:
  - Score unchanged at `87/90`.
  - Summary/evidence: populated the formal block with the accepted no-code marker. The class page remains the `MidiPlayer` object/declaration aggregate and must not duplicate constructor/destructor/toggle/stop/helper bodies already emitted by exact child pages. Vtable bytes rebuild from the class declaration/header route when that route is modeled.
- 2026-06-29 B007 [UID:0002BS][0x00526650-0x005266a1.MidiExactReadHelper](by-memory/0x00526650-0x005266a1.MidiExactReadHelper.md) implementation:
  - Score unchanged at `87/90`.
  - Summary/evidence: added [UID:0002BS][0x00526650-0x005266a1.MidiExactReadHelper](by-memory/0x00526650-0x005266a1.MidiExactReadHelper.md) as private file-scope `MidiReadExact` over `MidiDocument`, not a `MidiPlayer` object method. Preserved the class/file split language: the exact child emits helper C++, while the class aggregate remains blank because it documents the 12-byte controller object.
- 2026-06-29 B008 [UID:0002BW][0x00526bb0-0x00526cd9.MidiVariableLengthQuantityReader](by-memory/0x00526bb0-0x00526cd9.MidiVariableLengthQuantityReader.md) implementation:
  - Score unchanged at `87/90`.
  - Summary/evidence: added [UID:0002BW][0x00526bb0-0x00526cd9.MidiVariableLengthQuantityReader](by-memory/0x00526bb0-0x00526cd9.MidiVariableLengthQuantityReader.md) as private file-scope `MidiReadVariableLength` over `MidiDocument`/`MidiTrackState`, not a `MidiPlayer` object method. Preserved the class/file split language: the exact child emits helper C++, while the class aggregate remains blank because it documents the 12-byte controller object.
- 2026-06-28 B001 [UID:0002C1][0x00526fa0-0x00526ff6.MidiSourceSeekHelper](by-memory/0x00526fa0-0x00526ff6.MidiSourceSeekHelper.md) empty-emitter implementation:
  - Score unchanged at `87/90`.
  - Summary/evidence: added [UID:0002C1][0x00526fa0-0x00526ff6.MidiSourceSeekHelper](by-memory/0x00526fa0-0x00526ff6.MidiSourceSeekHelper.md) as private file-scope `MidiSeekSource` over `MidiDocument`, not a `MidiPlayer` object method. Preserved the class/file split language: the exact child emits helper C++, while the class aggregate remains blank because it documents the 12-byte controller object.
- 2026-06-15 C001 `.rdata` owner-gate refresh:
  - Before: score `82/88`; the exact [UID:0003PF][0x0061faf8-0x0061fafc.MidiPlayerRttiLocatorPointer](by-memory/0x0061faf8-0x0061fafc.MidiPlayerRttiLocatorPointer.md) child could not route to this class because the class was below the strict completion gate.
  - Changed to: score `85/89`; owner/emitter route remains [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md), and final C++ remains blank.
  - Summary/evidence: live IDA MCP session `c001_midiplayer_rdata_20260615` reconfirmed the `MidiPlayer` RTTI/vtable island, constructor/destructor/scalar-deleting-destructor vtable refs, track-selection string-cluster refs, successor `MiscWorkThread` boundary, and method/helper call graph. Remaining final-C++ blockers are source-facing helper/global/field names and class-versus-file-scope helper placement.
- 2026-06-17 B001 MIDI source-quality execution:
  - Score unchanged at `85/89`.
  - Summary/evidence: incorporated the accepted SMF parser helper/type names from B001's report and clarified that `MidiReadEvent`, `MidiWriteStreamEvent`, `MidiFillStreamBuffer`, and `MidiLoadDocument` are private file helpers, not `MidiPlayer` class methods. Their exact pages now carry first-draft C++; class-level C++ remains blank because this page describes the object/class aggregate, not the private helper bodies.
- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed the MIDI controller methods and helpers at `0x00525dc0`, `0x00525eb0`, `0x005260a0`, `0x005260b0`, `0x005260d0`, `0x00526100`, `0x00526240`, `0x00526340`, `0x00526580`, plus WinMM/file/parser helpers including `0x00525920`, `0x00525b10`, `0x00525be0`, `0x00525ff0`, `0x00526460`, `0x00526570`, `0x00526650`, `0x005270e0`, and `0x005271b0`. The later attachment pass set [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md) as the source-module parent after the class crossed the 80 completion gate.
- 2026-05-30: Previously this class page linked only to aggregate MIDI reader/parser and stream-fill helper spans. It now records that both aggregates have exact child by-memory pages while keeping the helpers associated with the `MidiPlayer` subsystem. Evidence: IDA MCP function-boundary and call/import checks for the split child ranges.
- 2026-06-02: Raised the class page from `66/78` to `74/84`.
  - Before: the class page summarized behavior and helper links but did not carry over the current file-owner score, WinMM boundary notes, touched-state table, helper map, reset fan-in, or track-selection evidence.
  - After: the page records `NexusTK/audio/` placement, separate `SoundManager` boundary, singleton/config/object-field/global-state accesses, helper/padding ranges, and remaining reconstruction blockers.
  - Evidence: existing IDA-backed [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md), [UID:0001CF][0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers](by-memory/0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers.md), [UID:0001CH][0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers](by-memory/0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers.md), [UID:0000RM][g_pMidiPlayer](by-global/g_pMidiPlayer.md), and [UID:0000T9][MidiPlayerWinMMState](by-global/MidiPlayerWinMMState.md).
- 2026-06-06 A006 attachment pass:
  - Before: scored `74/84`, reconstructable but unattached because the class was below the 80 completion parent gate.
  - Changed to: `82/86` and `AUTOGEN_PARENT_UID:0000LD`; final C++ was kept blank under the old 95/95 wording, which is superseded for exact helper/declaration children by later source-quality passes.
  - Evidence: live IDA reconfirmed the main class method starts/sizes, reset/select/start helper boundaries, singleton clear/scalar-delete bodies, and `g_pMidiPlayer` lifecycle/consumer xrefs. Remaining blockers are final helper/global names and exact class-versus-file-scope placement for some private MIDI helpers.
- 2026-06-06 A006 source-sync pass:
  - Changed to: confidence `88`, removed stale source-output wording, added [UID:0002B2][0x0069b870-0x0069b890.MidiSMFParserScratchGlobals](by-memory/0x0069b870-0x0069b890.MidiSMFParserScratchGlobals.md) to related helpers/touched state/cross-references, and added score rationale.
  - Evidence: the scratch-global page recorded then-current initialization evidence, half-open boundary, xref confinement to `sub_5271B0`, stream-fill bitfield semantics, selected-track/best-delta fields, and parsed-event scratch storage. The static-initializer wording is superseded by B009's 2026-07-05 zero-storage repair, and the old final-C++ blocker for [UID:0002B2][0x0069b870-0x0069b890.MidiSMFParserScratchGlobals](by-memory/0x0069b870-0x0069b890.MidiSMFParserScratchGlobals.md) is superseded by the 2026-06-18 B003 declaration pass.
- 2026-06-18 B003 scratch-global declaration pass:
  - Score unchanged at `85/89`.
  - Summary/evidence: recorded that [UID:0002B2][0x0069b870-0x0069b890.MidiSMFParserScratchGlobals](by-memory/0x0069b870-0x0069b890.MidiSMFParserScratchGlobals.md) is emitted as private static implementation storage under [UID:0000T9][MidiPlayerWinMMState](by-global/MidiPlayerWinMMState.md), not as `MidiPlayer` fields. B009's 2026-07-05 support repair clarifies that the storage is zero-initialized statically and receives runtime sentinels in the fill helper. This preserves the 12-byte class instance boundary while supporting the generated helper C++ declarations.
- 2026-06-21 B006 track-selection Rule 26 incorporation:
  - Changed to: score `87/90`.
  - Summary/evidence: resolved `this+0x08` as `m_selectedTrackId`, rejected generated `m_selectedDeviceId`, accepted `0x00526100` as `MidiPlayer::SelectTrack(unsigned short)`, accepted `0x00526240` as private file-static `StartSelectedMidiFile(const wchar_t *)`, and normalized the Config MIDI flag to `g_pConfig + 0x84c` / `Config::m_midiEnabled`.
- 2026-06-25 B011 [UID:0001CF][0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers](by-memory/0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers.md) implementation:
  - Score unchanged at `87/90`.
  - Summary/evidence: added exact child links for lifecycle [UID:00041J][0x00525dc0-0x00525f3d.MidiPlayerLifecycleMethods](by-memory/0x00525dc0-0x00525f3d.MidiPlayerLifecycleMethods.md), playback toggles [UID:00041L][0x005260a0-0x005260ff.MidiPlayerPlaybackToggleMethods](by-memory/0x005260a0-0x005260ff.MidiPlayerPlaybackToggleMethods.md), raw volume controls [UID:00041K][0x00525f40-0x0052609a.MidiPlayerRawVolumeAndStreamLocalHelpers](by-memory/0x00525f40-0x0052609a.MidiPlayerRawVolumeAndStreamLocalHelpers.md), stop method [UID:00041M][0x00526340-0x00526350.MidiPlayerStopPlayback](by-memory/0x00526340-0x00526350.MidiPlayerStopPlayback.md), reset helper [UID:00041O][0x00526460-0x00526569.MidiPlayerResetStream](by-memory/0x00526460-0x00526569.MidiPlayerResetStream.md), compiler cleanup [UID:00041P][0x00526570-0x0052664b.MidiPlayerCompilerCleanupHelpers](by-memory/0x00526570-0x0052664b.MidiPlayerCompilerCleanupHelpers.md), plus file-local raw helper children [UID:00041H][0x00525b10-0x00525b98.MidiReleaseStreamBuffers](by-memory/0x00525b10-0x00525b98.MidiReleaseStreamBuffers.md), [UID:00041I][0x00525ba0-0x00525bdf.MidiApplySingleChannelVolumeRaw](by-memory/0x00525ba0-0x00525bdf.MidiApplySingleChannelVolumeRaw.md), and [UID:00041N][0x00526350-0x00526452.MidiPlayerRawStreamControlHelpers](by-memory/0x00526350-0x00526452.MidiPlayerRawStreamControlHelpers.md). Clarified that `+0x28de50` is the constructor/enable/disable config flag while `+0x84c` remains `SelectTrack`'s selector-enable byte.
