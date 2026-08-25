** TARGET-REPORT-UID:0001CF **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B011 Report: [UID:0001CF] MidiPlayerAndWinMMHelpers

** Assignment:** `B011-report-0001CF-midi-player-winmm-helpers-20260625`  
** Mode:** report-only research, no by-* edits, no leases, no generated/manual coverage/validator-state/IDA DB edits.

## Executive Recommendation

[UID:0001CF] `by-memory/0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers.md` is reconstructable and correctly owned/emitted through [UID:0000LD] `by-file/MidiPlayer.md`, but it is an overbroad mixed aggregate rather than a single source function. It contains exact child ranges already documented, exact modeled functions not yet split into children, MSVC compiler cleanup glue, and several raw helper bodies that IDA did not promote to functions.

Do not emit a monolithic parent C++ body. Update the parent page as an inventory/container with a formal aggregate marker in its `RECONSTRUCTION_CPP CODE` block, then create or update exact child pages for the emitting pieces. This resolves the prior blockers: raw helper-shaped blocks are mapped, helper names are source-facing inferred names rather than `sub_` labels, global/state naming is tied to existing MidiPlayer support pages, owner/emitter routes satisfy the 85/85 gate, and the only blank C++ recommendation is for compiler-generated cleanup glue.

Recommended target metadata after implementation:

- `COMPLETION:88`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000LD`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000LD`
- `Nested:0`
- `Item Summary`: keep concise, but update it to say the page is a MidiPlayer WinMM aggregate/container with exact child split plan, raw-helper inventory, callback/reset/track-select graph, WinMM state globals, singleton lifecycle, and compiler cleanup disposition.

Formal target `RECONSTRUCTION_CPP CODE` content:

```cpp
// Emitted code for this mixed MidiPlayer WinMM aggregate is covered by exact child range pages.
// This parent range is an inventory/container and must not duplicate child output.
```

## MCP And Source Evidence

MCP was available and used for this report. Live check after reading the updated goal:

- Endpoint: `http://127.0.0.1:13337/mcp`
- `initialize`: HTTP 200
- `idb_list`: HTTP 200, active session `80de0a67`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker pid `26892`, active/adopted/owned, `is_analyzing:false`
- `server_health`: HTTP 200, `status:ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`

MCP-backed evidence used:

- `lookup_funcs` and `entity_query` over `0x00525b00-0x00526660`
- `decompile` for modeled functions at `0x00525b10`, `0x00525dc0`, `0x00525eb0`, `0x00525ff0`, `0x005260a0`, `0x005260b0`, `0x005260d0`, `0x00526340`, `0x00526460`, `0x00526570`, `0x00526580`
- `disasm` and raw byte inspection for non-function bodies at `0x00525ba0`, `0x00525f40`, `0x00525f60`, `0x00525fa0`, `0x00526060`, `0x00526080`, `0x00526350`, `0x005263a0`, `0x005263e0`
- `xref_query` and `find_bytes` for raw helper starts and function callers
- `imports_query` for WinMM imports
- `get_bytes` for UTF-16 resource/string evidence at `0x0061fb08`
- read-only review of current by-* support pages and generated C++ as lead material

Existing support pages checked:

- [UID:0000LD] `by-file/MidiPlayer.md`
- [UID:00008A] `by-class/MidiPlayer.md`
- [UID:0000T9] `by-global/MidiPlayerWinMMState.md`
- [UID:0000RM] `by-global/g_pMidiPlayer.md`
- [UID:0001CE] `by-memory/0x00525920-0x00525b0d.MidiStreamOpenAndPrimeBuffers.md`
- [UID:0001CG] `by-memory/0x00525be0-0x00525dbb.MidiStreamCallback.md`
- [UID:0001CH] `by-memory/0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers.md`
- [UID:0001CI] `by-memory/0x005270e0-0x005271a3.MidiDocumentRelease.md`
- [UID:00023B] `by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md`
- [UID:0002B1] `by-memory/0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals.md`
- [UID:00028Q] `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`
- `by-file/SoundManager.md`, `by-class/SoundManager.md`, and `by-meta/client_audio.md` as negative owner evidence
- `auto-generated/NexusTK/audio/MidiPlayer.cpp` as read-only emitter state

## Current Target State

Current [UID:0001CF] metadata before this report:

- `COMPLETION:86`
- `CONFIDENCE:88`
- `CANONICAL_OWNER:0000LD`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000LD`
- blank formal C++ block
- `Nested:0`

The current function table omits raw bodies at `0x00525ba0`, `0x00525f40-0x0052609a`, and `0x00526350-0x00526451`. The current C++ caveat says parent code is blank because aggregate naming/raw block questions remain. That caveat is now stale: this report resolves those questions into exact child-page specs and a formal parent marker.

Generated C++ state is read-only lead material. `auto-generated/NexusTK/audio/MidiPlayer.cpp` already emits [UID:0001CH] track-selection code and shows empty emitter markers for [UID:0001CF], [UID:0001CE], [UID:0001CG], [UID:00023B], [UID:0002B1], and related support pages. Generated reports are stale relative to live by-* scores and must be refreshed only by validator after accepted implementation.

## Ownership And Placement

Best owner/emitter route:

- Direct file owner and emitter: [UID:0000LD] `MidiPlayer.md`, score `88/89`. The range uses WinMM MIDI stream APIs, the same global state, the same parser/reset/callback helpers, and the same emitted file as existing [UID:0001CH] track selection code.
- Class owner for methods: [UID:00008A] `MidiPlayer.md`, score `87/90`. Constructor, destructor, playback toggles, volume controls, and stop method use the class object fields `m_playbackEnabled` at `this+4` and `m_selectedTrackId` at `this+8`.
- Global support: [UID:0000T9] and [UID:0002B1] cover the static WinMM stream state and should be synchronized with the newly resolved raw helper references.
- Rejected owner: SoundManager. SoundManager owns Miles/MP3/WAV/Redbook sound output and related toggles. The reviewed SoundManager/audio support pages explicitly separate MidiPlayer and WinMM MIDI stream handling from the SoundManager/Miles stack.

All proposed emitting child pages below have a direct owner and an existing emitter above the 85/85 gate. No proposed emitting child page depends on a below-gate owner or guessed emitter UID.

## Function And Raw-Body Inventory

| Range | Current IDA shape | Recommended source-facing name | Disposition |
|---|---:|---|---|
| `0x00525b10-0x00525b98` | function `sub_525B10` | `ReleaseMidiStreamBuffers` | new exact emitting child page |
| `0x00525b98-0x00525ba0` | `cc` padding | padding | parent inventory only |
| `0x00525ba0-0x00525bdf` | raw body, no IDA function | `SendMidiChannelVolume` | new exact emitting child page, no-route raw confidence cap |
| `0x00525bdf-0x00525be0` | `cc` padding | padding | parent inventory only |
| `0x00525be0-0x00525dbb` | function [UID:0001CG] | `MidiStreamCallback` | existing exact child page, support sync only |
| `0x00525dbb-0x00525dc0` | `cc` padding | padding | parent inventory only |
| `0x00525dc0-0x00525ea6` | function `sub_525DC0` | `MidiPlayer::MidiPlayer` | new exact emitting lifecycle child page |
| `0x00525eb0-0x00525f3d` | function `sub_525EB0` | `MidiPlayer::~MidiPlayer` | same lifecycle child page |
| `0x00525f3d-0x00525f40` | `cc` padding | padding | parent inventory only |
| `0x00525f40-0x00525f56` | raw body, no IDA function | `CreateMidiBufferReturnEvent` | new exact emitting raw/local helper child page |
| `0x00525f57-0x00525f60` | `cc` padding | padding | parent inventory only |
| `0x00525f60-0x00525f94` | raw body, no IDA function | `OpenMidiStreamCallbackOnly` | same raw/local helper child page |
| `0x00525f95-0x00525fa0` | `cc` padding | padding | parent inventory only |
| `0x00525fa0-0x00525fe1` | raw body, no IDA function | `CloseMidiStreamResources` | same raw/local helper child page |
| `0x00525fe2-0x00525ff0` | `cc` padding | padding | parent inventory only |
| `0x00525ff0-0x0052605a` | function `sub_525FF0` | `ApplyMidiVolume` | same raw/local helper child page |
| `0x0052605a-0x00526060` | `cc` padding | padding | parent inventory only |
| `0x00526060-0x0052607b` | raw body, no IDA function | `MidiPlayer::IncreaseMidiVolume` | same raw/local helper child page |
| `0x0052607c-0x00526080` | `cc` padding | padding | parent inventory only |
| `0x00526080-0x00526099` | raw body, no IDA function | `MidiPlayer::DecreaseMidiVolume` | same raw/local helper child page |
| `0x0052609a-0x005260a0` | `cc` padding | padding | parent inventory only |
| `0x005260a0-0x005260a4` | function `sub_5260A0` | `MidiPlayer::IsPlaybackEnabled` | new exact emitting toggle child page |
| `0x005260b0-0x005260ca` | function `sub_5260B0` | `MidiPlayer::EnableMidiPlayback` | same toggle child page |
| `0x005260d0-0x005260ff` | function `sub_5260D0` | `MidiPlayer::DisableMidiPlayback` | same toggle child page |
| `0x00526100-0x00526332` | existing [UID:0001CH] | `StartSelectedMidiFile`, `MidiPlayer::SelectTrack` | existing exact emitting child page |
| `0x00526332-0x00526340` | `cc` padding | padding | parent inventory only |
| `0x00526340-0x00526350` | function `sub_526340` | `MidiPlayer::StopPlayback` | new exact emitting child page |
| `0x00526350-0x0052639a` | raw body, no IDA function | `OpenSelectedMidiFileNoRestart` | new exact emitting raw stream-control child page |
| `0x0052639a-0x005263a0` | `ret 4` plus padding | raw-return tail/padding | covered with raw stream-control child page |
| `0x005263a0-0x005263dc` | raw body, no IDA function | `ToggleMidiStreamPause` | same raw stream-control child page |
| `0x005263dd-0x005263e0` | `cc` padding | padding | parent inventory only |
| `0x005263e0-0x00526451` | raw body, no IDA function | `RestartSelectedMidiStream` | same raw stream-control child page |
| `0x00526452-0x00526460` | `cc` padding | padding | parent inventory only |
| `0x00526460-0x00526569` | function `sub_526460` | `MidiPlayer_ResetStream` | new exact emitting child page |
| `0x00526570-0x0052657b` | function `sub_526570` | constructor EH singleton-clear helper | new exact non-emitting compiler cleanup child page |
| `0x00526580-0x0052664b` | function `sub_526580` | `MidiPlayer` scalar deleting destructor | same non-emitting compiler cleanup child page |

## Behavior Evidence By Range

`0x00525b10` releases the two prepared stream headers when `g_midiHeadersPrepared != 0`, clears that flag, then frees any `lpData` blocks in the two 84-byte header slots. It uses `midiOutUnprepareHeader`, `GlobalHandle`, `GlobalUnlock`, and `GlobalFree`. Callers are destructor, raw close helper, reset, and scalar deleting destructor.

`0x00525ba0` is an unmodeled raw helper body. It checks `g_midiStreamRunning`, uses `channel` and `volumeScale` arguments, computes `g_midiChannelVolume[channel] * volumeScale / 1000`, sends controller 7 with status `0xB0 | channel`, and returns. `xref_query` and VA/RVA `find_bytes` found no external route to the raw start. The helper is still source-shaped, contiguous with MidiPlayer WinMM helpers, and uses the same globals/imports, so it is safe as a file-static emitting child with a no-route confidence cap.

`0x00525dc0` constructs `MidiPlayer`. It calls the base constructor (`sub_4F4A80`), assigns `g_pMidiPlayer`, installs the `MidiPlayer` vtable, copies the config flag at `g_pConfig + 0x28de50` into `m_playbackEnabled`, sets `m_selectedTrackId` to `0xffff`, initializes WinMM globals, sets `g_midiVolumeScale = 500`, and creates the named event `L"Wait For Buffer Return"`. The decompiler's defensive `this == -4` artifact is exception/unwind noise, not human source.

`0x00525eb0` is the non-deleting destructor. It restores the vtable, resets the stream with skip-reopen when a stream exists, releases headers/buffers, closes any remaining stream, closes the event handle, clears `g_pMidiPlayer`, and calls the base destructor.

`0x00525f40` creates the same named event and stores it in `g_hMidiBufferEvent`. `0x00525f60` opens a WinMM stream with callback `0x00525be0`, one device, and flag `0x30000` (`CALLBACK_FUNCTION` plus stream-related flag usage as compiled), then sets `g_midiCallbackStreamOpen` at `0x0069b51c`. `0x00525fa0` performs stream reset/release/close/event close without clearing the singleton. All three raw starts have zero xrefs and zero VA/RVA pointer matches, so they should be documented as raw/local helpers, not top-level routed APIs.

`0x00525ff0` applies MIDI channel volume. Important binary detail: the function computes each channel using the current global `g_midiVolumeScale`, not the incoming argument, then stores the argument only after all 16 `midiOutShortMsg` calls succeed. If one send fails, the new volume scale is not stored. The formal C++ must preserve this order even though it looks odd.

`0x00526060` and `0x00526080` are raw class-shaped methods for volume up/down. They check `m_playbackEnabled`, bound `g_midiVolumeScale` at `<= 900` and `>= 100`, and call `ApplyMidiVolume(g_midiVolumeScale +/- 100)`. No external route was found; they remain exact raw methods with confidence cap.

`0x005260a0`, `0x005260b0`, and `0x005260d0` are playback state access/toggle methods. `IsPlaybackEnabled` returns the byte at `this+4`. `EnableMidiPlayback` writes 1 to `g_pConfig + 0x28de50` and to `m_playbackEnabled` only when disabled. `DisableMidiPlayback` writes 0 to `g_pConfig + 0x28de50`, clears `m_selectedTrackId`, calls `MidiPlayer_ResetStream(0)`, and clears `m_playbackEnabled`.

`0x00526340` sets `m_selectedTrackId = MIDI_TRACK_NONE` and calls `MidiPlayer_ResetStream(0)`.

`0x00526350` is a raw path/open helper. It copies the path into `g_midiCurrentPath`, resets with skip-reopen when a document is already loaded, calls `MidiStreamOpenAndPrimeBuffers`, and marks `g_midiDocumentLoaded = 1` on success. It does not restart the stream; that distinguishes it from [UID:0001CH] `StartSelectedMidiFile`.

`0x005263a0` toggles pause/restart state using `g_midiRestartPending`. If pending, it calls `midiStreamRestart` and clears the flag; otherwise it calls `midiStreamPause` and sets the flag. `0x005263e0` restarts selected playback: it clears a pending pause first, otherwise resets an already-running stream, sets stream state to 0, restarts the loaded stream, and sets `g_midiStreamRunning` only on successful restart.

`0x00526460` is `MidiPlayer_ResetStream`. It clears restart/running state, transitions stream state through the existing 100/200/300 state values, calls `midiStreamStop`, `midiOutReset`, waits up to 2000 ms for `g_hMidiBufferEvent`, releases the document and stream resources when loaded, and reopens/primes unless flag `0x10000` is set.

`0x00526570` only clears `g_pMidiPlayer` and has one code xref from constructor/EH cleanup at `0x0060412e`. `0x00526580` is MSVC scalar deleting destructor glue referenced by the vtable data pointer at `0x0061fafc`; it duplicates destructor cleanup and conditionally calls the delete/free helper. These are not human-authored source functions for emitter output.

## Global And Type Naming Resolution

Use existing support names where already accepted:

- `g_hMidiStream` at `0x0069b500`
- `g_midiDeviceId` at `0x0069b504`, initialized to `MIDI_MAPPER` (`0xffffffff`)
- `g_midiStreamState` at `0x0069b508`
- `g_midiRestartPending` at `0x0069b50c`
- `g_midiAllowEndReplay` / fill-replay flag at `0x0069b510`
- `g_midiDocumentLoaded` at `0x0069b514`
- `g_midiStreamRunning` at `0x0069b518`
- `g_midiHeadersPrepared` at `0x0069b520`
- `g_midiVolumeScale` at `0x0069b524`
- `g_midiHeaders` at `0x0069b528`, two 84-byte slots, first 64 bytes source-shaped as `MIDIHDR`
- `g_midiChannelVolume` at `0x0069b5d0`, 16 DWORD channel volumes, default bytes at `0x0061fb60` start with 100 values
- `g_midiActiveHeaderIndex` at `0x0069b610`
- `g_midiPendingBufferCount` at `0x0069b614`
- `g_hMidiBufferEvent` at `0x0069b820`
- `g_midiDocumentState` at `0x0069b828`
- `g_midiCurrentPath` / `Destination`

New support name to add:

- `g_midiCallbackStreamOpen` at `0x0069b51c` (inferred). Evidence: constructor clears it, raw stream-open helper `0x00525f60` sets it after successful `midiStreamOpen`, and no other writer was found in this range. Existing [UID:0002B1] calls it `unk_69B51C`; that raw label should be replaced in support text with the inferred name and evidence caveat.

Configuration naming:

- `g_pConfig + 0x84c` remains the existing [UID:0001CH] `SelectTrack` low MIDI selector enable field, documented as `m_midiEnabled` in current MidiPlayer code.
- `g_pConfig + 0x28de50` is the constructor/enable/disable music-output flag used in this target and mirrored by option UI / SoundManager toggle paths. Use the source-facing inferred name `m_musicEnabled` for the formal C++ in this report, and update [UID:00028Q] to clarify the distinction from `m_midiEnabled`.

Constants for child formal C++:

```cpp
static const unsigned int MIDI_RESET_SKIP_REOPEN = 0x00010000;
static const unsigned int MIDI_TRACK_PATH_CHARS = 260;
static const unsigned short MIDI_TRACK_NONE = (unsigned short)-1;
static const unsigned int MIDI_STREAM_STATE_STOPPING = 100;
static const unsigned int MIDI_STREAM_STATE_IDLE = 200;
static const unsigned int MIDI_STREAM_STATE_FLUSHING = 300;
static const unsigned int MIDI_CONTROLLER_VOLUME = 7;
static const unsigned int MIDI_STATUS_CONTROL_CHANGE = 0xB0;
```

`MIDI_STREAM_STATE_*` names are inferred from current stream-control behavior and existing support text. `WAIT_TIMEOUT` is the Win32 value 258. `MIDI_RESET_SKIP_REOPEN` is the existing [UID:0001CH] constant for flag `0x10000`.

## Proposed New Child Pages

Create these pages only after supervisor acceptance. Do not guess UIDs in file contents or cross-links; let the scoped validator assign UIDs to new pages. Until UID assignment, parent/support links in edited docs should use TMP links, for example `[TMP:"by-memory/0x00525b10-0x00525b98.MidiReleaseStreamBuffers.md"]`.

### Page 1: ReleaseMidiStreamBuffers

Path: `by-memory/0x00525b10-0x00525b98.MidiReleaseStreamBuffers.md`

Metadata:

- `COMPLETION:88`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000LD`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000LD`
- `Nested:0`
- `Item Summary`: Exact MidiPlayer WinMM buffer/header release helper; unprepares two stream headers when prepared, frees two global buffer blocks, clears `g_midiHeadersPrepared`, and is called by destructor/reset/raw close/scalar destructor.

Owner/emitter gate: owner [UID:0000LD] is `88/89`, emitter [UID:0000LD] is `88/89`; page score is above 85/85.

Formal `RECONSTRUCTION_CPP CODE`:

```cpp
static void ReleaseMidiStreamBuffers()
{
    if (g_midiHeadersPrepared != 0) {
        for (int i = 0; i < 2; ++i) {
            midiOutUnprepareHeader((HMIDIOUT)g_hMidiStream,
                                   &g_midiHeaders[i].header,
                                   sizeof(MIDIHDR));
        }
        g_midiHeadersPrepared = 0;
    }

    for (int i = 0; i < 2; ++i) {
        if (g_midiHeaders[i].header.lpData != NULL) {
            HGLOBAL block = GlobalHandle(g_midiHeaders[i].header.lpData);
            GlobalUnlock(block);
            block = GlobalHandle(g_midiHeaders[i].header.lpData);
            GlobalFree(block);
            g_midiHeaders[i].header.lpData = NULL;
        }
    }
}
```

Support facts to insert:

- Two header slots at `0x0069b528` and `0x0069b57c` are treated as 84-byte per-slot records whose leading source-facing member is a `MIDIHDR`.
- The repeated `GlobalHandle` call before `GlobalUnlock` and before `GlobalFree` is intentional binary behavior.

Scoped validator after creation:

> Executable block R001 was removed from this report and preserved verbatim in [0001CF-MidiPlayerAndWinMMHelpers-source-quality-removed.md](0001CF-MidiPlayerAndWinMMHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

### Page 2: SendMidiChannelVolume

Path: `by-memory/0x00525ba0-0x00525bdf.MidiApplySingleChannelVolumeRaw.md`

Metadata:

- `COMPLETION:85`
- `CONFIDENCE:86`
- `CANONICAL_OWNER:0000LD`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000LD`
- `Nested:0`
- `Item Summary`: Raw unmodeled MidiPlayer local helper that sends one MIDI channel-volume controller message when the stream is running; no external xrefs or pointer route found.

Owner/emitter gate: owner [UID:0000LD] is `88/89`, emitter [UID:0000LD] is `88/89`; page score is above 85/85. The no-route raw start caps confidence but does not prevent first-draft C++ because behavior, ownership, globals, and source family are exact.

Formal `RECONSTRUCTION_CPP CODE`:

```cpp
static void SendMidiChannelVolume(unsigned int channel, unsigned int volumeScale)
{
    if (g_midiStreamRunning == 0) {
        return;
    }

    DWORD scaled = (g_midiChannelVolume[channel] * volumeScale) / 1000;
    DWORD message = MIDI_STATUS_CONTROL_CHANGE |
                    channel |
                    (MIDI_CONTROLLER_VOLUME << 8) |
                    (scaled << 16);
    midiOutShortMsg((HMIDIOUT)g_hMidiStream, message);
}
```

Support facts to insert:

- Raw start `0x00525ba0` is not an IDA function in current IDB.
- `xref_query` and VA/RVA immediate scans found no route to this helper start.
- It reads `g_midiStreamRunning`, `g_midiChannelVolume`, and `g_hMidiStream`, and emits controller 7 volume for one channel.

Scoped validator after creation:

> Executable block R002 was removed from this report and preserved verbatim in [0001CF-MidiPlayerAndWinMMHelpers-source-quality-removed.md](0001CF-MidiPlayerAndWinMMHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

### Page 3: MidiPlayerLifecycleMethods

Path: `by-memory/0x00525dc0-0x00525f3d.MidiPlayerLifecycleMethods.md`

Metadata:

- `COMPLETION:88`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:00008A`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000LD`
- `Nested:0`
- `Item Summary`: Exact MidiPlayer constructor/destructor range; initializes singleton, playback state, selected track, WinMM stream globals, volume default, named buffer-return event, and destructor stream/event/singleton cleanup.

Owner/emitter gate: owner [UID:00008A] is `87/90`, emitter [UID:0000LD] is `88/89`; page score is above 85/85.

Formal `RECONSTRUCTION_CPP CODE`:

```cpp
MidiPlayer::MidiPlayer()
    : LObject(),
      m_playbackEnabled(g_pConfig->m_musicEnabled != 0),
      m_selectedTrackId(MIDI_TRACK_NONE)
{
    g_pMidiPlayer = this;
    g_midiDeviceId = MIDI_MAPPER;
    g_midiRestartPending = 0;
    g_midiAllowEndReplay = 1;
    g_midiDocumentLoaded = 0;
    g_midiStreamRunning = 0;
    g_midiHeadersPrepared = 0;
    g_midiCallbackStreamOpen = 0;
    g_midiVolumeScale = 500;
    g_hMidiBufferEvent = CreateEventW(NULL, FALSE, FALSE, L"Wait For Buffer Return");
}

MidiPlayer::~MidiPlayer()
{
    if (g_hMidiStream != NULL) {
        MidiPlayer_ResetStream(MIDI_RESET_SKIP_REOPEN);
    }

    ReleaseMidiStreamBuffers();

    if (g_hMidiStream != NULL) {
        midiStreamClose(g_hMidiStream);
        g_hMidiStream = NULL;
    }

    CloseHandle(g_hMidiBufferEvent);
    g_pMidiPlayer = NULL;
}
```

Support facts to insert:

- Constructor copies `g_pConfig + 0x28de50` into `m_playbackEnabled`; this is represented as inferred `g_pConfig->m_musicEnabled`.
- Constructor event name comes from UTF-16 string at `0x0061fb08`: `L"Wait For Buffer Return"`.
- Destructor calls reset only when `g_hMidiStream != NULL`, always releases buffers, closes any remaining stream, closes the event, and clears `g_pMidiPlayer`.
- Do not carry the decompiler `this == -4` artifact into source; it is EH/constructor cleanup shape.

Scoped validator after creation:

> Executable block R003 was removed from this report and preserved verbatim in [0001CF-MidiPlayerAndWinMMHelpers-source-quality-removed.md](0001CF-MidiPlayerAndWinMMHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

### Page 4: RawVolumeAndStreamLocalHelpers

Path: `by-memory/0x00525f40-0x0052609a.MidiPlayerRawVolumeAndStreamLocalHelpers.md`

Metadata:

- `COMPLETION:86`
- `CONFIDENCE:88`
- `CANONICAL_OWNER:0000LD`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000LD`
- `Nested:0`
- `Item Summary`: Exact mixed raw/local MidiPlayer helper range covering named event creation, callback-only stream open, stream resource close, apply-volume function, and raw volume up/down methods.

Owner/emitter gate: owner [UID:0000LD] is `88/89`, emitter [UID:0000LD] is `88/89`; page score is above 85/85. Class-shaped volume methods are included in the file-local helper range because IDA did not model them as standalone functions and no external route was found; note [UID:00008A] as semantic class support in body text.

Formal `RECONSTRUCTION_CPP CODE`:

```cpp
static HANDLE CreateMidiBufferReturnEvent()
{
    g_hMidiBufferEvent = CreateEventW(NULL, FALSE, FALSE, L"Wait For Buffer Return");
    return g_hMidiBufferEvent;
}

static bool OpenMidiStreamCallbackOnly()
{
    MMRESULT result = midiStreamOpen(&g_hMidiStream,
                                     &g_midiDeviceId,
                                     1,
                                     (DWORD_PTR)MidiStreamCallback,
                                     0,
                                     CALLBACK_FUNCTION);
    if (result != MMSYSERR_NOERROR) {
        return false;
    }

    g_midiCallbackStreamOpen = 1;
    return true;
}

static void CloseMidiStreamResources()
{
    if (g_hMidiStream != NULL) {
        MidiPlayer_ResetStream(MIDI_RESET_SKIP_REOPEN);
    }

    ReleaseMidiStreamBuffers();

    if (g_hMidiStream != NULL) {
        midiStreamClose(g_hMidiStream);
        g_hMidiStream = NULL;
    }

    CloseHandle(g_hMidiBufferEvent);
}

static void ApplyMidiVolume(unsigned int volumeScale)
{
    if (g_midiStreamRunning == 0) {
        return;
    }

    for (unsigned int channel = 0; channel < 16; ++channel) {
        DWORD scaled = (g_midiChannelVolume[channel] * g_midiVolumeScale) / 1000;
        DWORD message = MIDI_STATUS_CONTROL_CHANGE |
                        channel |
                        (MIDI_CONTROLLER_VOLUME << 8) |
                        (scaled << 16);
        if (midiOutShortMsg((HMIDIOUT)g_hMidiStream, message) != MMSYSERR_NOERROR) {
            return;
        }
    }

    g_midiVolumeScale = volumeScale;
}

void MidiPlayer::IncreaseMidiVolume()
{
    if (m_playbackEnabled != 0 && g_midiVolumeScale <= 900) {
        ApplyMidiVolume(g_midiVolumeScale + 100);
    }
}

void MidiPlayer::DecreaseMidiVolume()
{
    if (m_playbackEnabled != 0 && g_midiVolumeScale >= 100) {
        ApplyMidiVolume(g_midiVolumeScale - 100);
    }
}
```

Support facts to insert:

- Raw helper starts: `0x00525f40`, `0x00525f60`, `0x00525fa0`, `0x00526060`, `0x00526080`.
- Modeled function inside range: `0x00525ff0` `ApplyMidiVolume`.
- No xrefs or pointer immediates were found for the raw starts.
- `ApplyMidiVolume` intentionally sends controller messages using the old global `g_midiVolumeScale`, then stores the new argument only after all sends succeed.

Scoped validator after creation:

> Executable block R004 was removed from this report and preserved verbatim in [0001CF-MidiPlayerAndWinMMHelpers-source-quality-removed.md](0001CF-MidiPlayerAndWinMMHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

### Page 5: PlaybackToggleMethods

Path: `by-memory/0x005260a0-0x005260ff.MidiPlayerPlaybackToggleMethods.md`

Metadata:

- `COMPLETION:88`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:00008A`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000LD`
- `Nested:0`
- `Item Summary`: Exact MidiPlayer playback-enabled accessor and enable/disable methods; uses `m_playbackEnabled`, selected-track reset, config flag `g_pConfig + 0x28de50`, and `MidiPlayer_ResetStream(0)`.

Owner/emitter gate: owner [UID:00008A] is `87/90`, emitter [UID:0000LD] is `88/89`; page score is above 85/85.

Formal `RECONSTRUCTION_CPP CODE`:

```cpp
int MidiPlayer::IsPlaybackEnabled() const
{
    return m_playbackEnabled;
}

void MidiPlayer::EnableMidiPlayback()
{
    if (m_playbackEnabled == 0) {
        g_pConfig->m_musicEnabled = 1;
        m_playbackEnabled = 1;
    }
}

void MidiPlayer::DisableMidiPlayback()
{
    if (m_playbackEnabled == 1) {
        g_pConfig->m_musicEnabled = 0;
        m_selectedTrackId = MIDI_TRACK_NONE;
        MidiPlayer_ResetStream(0);
        m_playbackEnabled = 0;
    }
}
```

Support facts to insert:

- `IsPlaybackEnabled` has an external caller at `0x0057c124`.
- Enable/disable have callers at `0x0053de1b`, `0x00540c4f`, raw `0x00541150`, `0x0057a409`, `0x0057a493`, `0x0057c141` for enable, and `0x0053de3d`, `0x00540c6a`, raw `0x0054117d`, `0x0057a3e9`, `0x0057a463`, `0x0057c12f` for disable.
- The config field here is `+0x28de50`, not [UID:0001CH] `SelectTrack`'s `+0x84c`.

Scoped validator after creation:

> Executable block R005 was removed from this report and preserved verbatim in [0001CF-MidiPlayerAndWinMMHelpers-source-quality-removed.md](0001CF-MidiPlayerAndWinMMHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

### Page 6: StopPlayback

Path: `by-memory/0x00526340-0x00526350.MidiPlayerStopPlayback.md`

Metadata:

- `COMPLETION:87`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:00008A`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000LD`
- `Nested:0`
- `Item Summary`: Exact MidiPlayer stop method; clears selected track and resets the MIDI stream without skip-reopen.

Owner/emitter gate: owner [UID:00008A] is `87/90`, emitter [UID:0000LD] is `88/89`; page score is above 85/85.

Formal `RECONSTRUCTION_CPP CODE`:

```cpp
void MidiPlayer::StopPlayback()
{
    m_selectedTrackId = MIDI_TRACK_NONE;
    MidiPlayer_ResetStream(0);
}
```

Support facts to insert:

- Callers: `0x004f6955`, `0x0050289c`, `0x00504a6f`, `0x00512fa7`.
- This method is separate from [UID:0001CH] `SelectTrack` and should be added to [UID:00008A] method inventory.

Scoped validator after creation:

> Executable block R006 was removed from this report and preserved verbatim in [0001CF-MidiPlayerAndWinMMHelpers-source-quality-removed.md](0001CF-MidiPlayerAndWinMMHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

### Page 7: RawStreamControlHelpers

Path: `by-memory/0x00526350-0x00526452.MidiPlayerRawStreamControlHelpers.md`

Metadata:

- `COMPLETION:85`
- `CONFIDENCE:86`
- `CANONICAL_OWNER:0000LD`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000LD`
- `Nested:0`
- `Item Summary`: Raw unmodeled MidiPlayer stream-control helper range covering path/open without restart, pause/restart toggle, and selected-stream restart; no external xrefs or pointer route found.

Owner/emitter gate: owner [UID:0000LD] is `88/89`, emitter [UID:0000LD] is `88/89`; page score is above 85/85. The no-route raw starts cap confidence but source family and behavior are strong.

Formal `RECONSTRUCTION_CPP CODE`:

```cpp
static void OpenSelectedMidiFileNoRestart(const wchar_t *path)
{
    wcscpy_s(g_midiCurrentPath, MIDI_TRACK_PATH_CHARS, path);

    if (g_midiDocumentLoaded != 0) {
        MidiPlayer_ResetStream(MIDI_RESET_SKIP_REOPEN);
    }

    if (MidiStreamOpenAndPrimeBuffers() == MMSYSERR_NOERROR) {
        g_midiDocumentLoaded = 1;
    }
}

static void ToggleMidiStreamPause()
{
    if (g_midiRestartPending != 0) {
        midiStreamRestart(g_hMidiStream);
        g_midiRestartPending = 0;
        return;
    }

    midiStreamPause(g_hMidiStream);
    g_midiRestartPending = 1;
}

static void RestartSelectedMidiStream()
{
    if (g_midiRestartPending != 0) {
        midiStreamRestart(g_hMidiStream);
        g_midiRestartPending = 0;
        return;
    }

    if (g_midiStreamRunning != 0) {
        MidiPlayer_ResetStream(0);
    }

    if (g_midiDocumentLoaded != 0) {
        g_midiStreamState = 0;
        if (midiStreamRestart(g_hMidiStream) == MMSYSERR_NOERROR) {
            g_midiStreamRunning = 1;
        }
        return;
    }

    g_midiStreamRunning = 0;
}
```

Support facts to insert:

- Raw helper starts: `0x00526350`, `0x005263a0`, `0x005263e0`.
- No xrefs or VA/RVA pointer routes were found for these starts.
- `OpenSelectedMidiFileNoRestart` returns with `ret 4` at `0x0052639a`.
- This page should distinguish `OpenSelectedMidiFileNoRestart` from [UID:0001CH] `StartSelectedMidiFile`, which also performs stream restart/volume behavior.

Scoped validator after creation:

> Executable block R007 was removed from this report and preserved verbatim in [0001CF-MidiPlayerAndWinMMHelpers-source-quality-removed.md](0001CF-MidiPlayerAndWinMMHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

### Page 8: MidiPlayerResetStream

Path: `by-memory/0x00526460-0x00526569.MidiPlayerResetStream.md`

Metadata:

- `COMPLETION:88`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000LD`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000LD`
- `Nested:0`
- `Item Summary`: Exact MidiPlayer stream reset helper; stops/resets WinMM stream, waits for buffer-return event, releases document/buffers/stream, and optionally reopens/primes.

Owner/emitter gate: owner [UID:0000LD] is `88/89`, emitter [UID:0000LD] is `88/89`; page score is above 85/85.

Formal `RECONSTRUCTION_CPP CODE`:

```cpp
static MMRESULT MidiPlayer_ResetStream(unsigned int flags)
{
    int documentLoaded = g_midiDocumentLoaded;
    int streamState = g_midiStreamState;

    if (g_midiDocumentLoaded == 0 &&
        g_midiStreamRunning == 0 &&
        g_midiStreamState == MIDI_STREAM_STATE_IDLE) {
        goto release_document;
    }

    g_midiRestartPending = 0;
    g_midiStreamRunning = 0;

    if (g_midiStreamState != MIDI_STREAM_STATE_IDLE) {
        if (g_midiStreamState != MIDI_STREAM_STATE_FLUSHING) {
            streamState = MIDI_STREAM_STATE_STOPPING;
        }
        g_midiStreamState = streamState;
    }

    MMRESULT result = midiStreamStop(g_hMidiStream);
    if (result != MMSYSERR_NOERROR) {
        return result;
    }

    result = midiOutReset((HMIDIOUT)g_hMidiStream);
    if (result != MMSYSERR_NOERROR) {
        return result;
    }

    result = WaitForSingleObject(g_hMidiBufferEvent, 2000);
    if (result != WAIT_TIMEOUT && g_midiStreamState != MIDI_STREAM_STATE_IDLE) {
        return result;
    }

    documentLoaded = g_midiDocumentLoaded;

release_document:
    g_midiStreamState = 0;

    if (documentLoaded != 0) {
        MidiDocumentRelease(&g_midiDocumentState);
        ReleaseMidiStreamBuffers();

        if (g_hMidiStream != NULL) {
            midiStreamClose(g_hMidiStream);
            g_hMidiStream = NULL;
        }

        g_midiDocumentLoaded = 0;
    }

    if ((flags & MIDI_RESET_SKIP_REOPEN) == 0) {
        result = MidiStreamOpenAndPrimeBuffers();
        if (result == MMSYSERR_NOERROR) {
            g_midiDocumentLoaded = 1;
        }
    } else {
        result = (MMRESULT)(flags >> 16);
    }

    return result;
}
```

Support facts to insert:

- `0x10000` skip-reopen flag is existing `MIDI_RESET_SKIP_REOPEN`.
- Wait timeout comparison uses Win32 `WAIT_TIMEOUT` (`258`).
- State values are current support names/inferred: stopping `100`, idle `200`, flushing `300`.
- Callers: callback, destructor, raw close, disable, select/start, stop, raw stream control, scalar deleting destructor.

Scoped validator after creation:

> Executable block R008 was removed from this report and preserved verbatim in [0001CF-MidiPlayerAndWinMMHelpers-source-quality-removed.md](0001CF-MidiPlayerAndWinMMHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

### Page 9: CompilerCleanupHelpers

Path: `by-memory/0x00526570-0x0052664b.MidiPlayerCompilerCleanupHelpers.md`

Metadata:

- `COMPLETION:86`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:00008A`
- `RECONSTRUCTABLE:FALSE`
- `EMITTER_UIDS:`
- `Nested:0`
- `Item Summary`: Exact compiler cleanup range for MidiPlayer constructor EH singleton-clear helper and MSVC scalar deleting destructor glue; not source-emitting because constructor/destructor/class declaration provide source-level code.

Owner gate: owner [UID:00008A] is `87/90`; page score is above 85/85. No emitter is proposed because this is non-reconstructable compiler glue.

Formal C++ remains blank for this child. No-code proof:

`0x00526570` has only one code xref from constructor/EH cleanup at `0x0060412e` and only clears `g_pMidiPlayer`. `0x00526580` is the MSVC scalar deleting destructor reached by the `MidiPlayer` vtable pointer at `0x0061fafc`; it duplicates destructor cleanup and conditionally calls the delete/free helper. Emitting hand-written C++ for this child would duplicate compiler-generated cleanup and produce non-source-shaped output. The source-level code belongs in `MidiPlayer::MidiPlayer`, `MidiPlayer::~MidiPlayer`, and the class declaration.

Scoped validator after creation:

> Executable block R009 was removed from this report and preserved verbatim in [0001CF-MidiPlayerAndWinMMHelpers-source-quality-removed.md](0001CF-MidiPlayerAndWinMMHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Existing Child Page Disposition

[UID:0001CE] `MidiStreamOpenAndPrimeBuffers` remains the exact open/prime child before the parent range. Do not duplicate its body. Add references only where needed to note it is called by `OpenSelectedMidiFileNoRestart`, `MidiPlayer_ResetStream`, and existing [UID:0001CH] `StartSelectedMidiFile`.

[UID:0001CG] `MidiStreamCallback` remains the exact callback child. Its current name, owner/emitter, and range are supported by the callback pointer xref at `0x00525939` and by WinMM message handling. Implementation should add cross-reference synchronization after new UIDs exist: the callback's helper dependencies now resolve to the new release/reset/raw volume-support children. Do not merge callback output into the parent.

[UID:0001CH] `MidiPlayerTrackSelectionHelpers` already emits formal code for `StartSelectedMidiFile` and `MidiPlayer::SelectTrack`. Keep it as the exact child. Implementation should update dependency text after new UIDs exist so `MidiPlayer_ResetStream`, `ApplyMidiVolume`, and `ReleaseMidiStreamBuffers` point at the new child pages.

[UID:0001CI] `MidiDocumentRelease` and [UID:00023B] `MidiFileReaderAndSMFParserHelpers` remain downstream document/parser support. No edits are required for this report's accepted scope because they already identify the reset/release/parser relationship at sufficient detail for the new child split.

## Support-Doc Synchronization Required After Acceptance

Target page [UID:0001CF]:

- Replace blank parent `RECONSTRUCTION_CPP CODE` block with the two-line aggregate marker above.
- Update score to `88/90`.
- Update the inventory table to include every raw range and the proposed/new child pages.
- Replace the stale "raw/helper names unresolved" caveat with the resolved raw-helper table and child disposition.
- Add a child split plan using TMP links for new pages before validator assigns UIDs.
- Keep `CANONICAL_OWNER:0000LD`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000LD`.

[UID:0000LD] `by-file/MidiPlayer.md`:

- Add the new child pages to the MidiPlayer.cpp implementation inventory using TMP links until validation assigns UIDs.
- Add source-facing helper names: `ReleaseMidiStreamBuffers`, `SendMidiChannelVolume`, `CreateMidiBufferReturnEvent`, `OpenMidiStreamCallbackOnly`, `CloseMidiStreamResources`, `ApplyMidiVolume`, `MidiPlayer::IncreaseMidiVolume`, `MidiPlayer::DecreaseMidiVolume`, `MidiPlayer::IsPlaybackEnabled`, `MidiPlayer::EnableMidiPlayback`, `MidiPlayer::DisableMidiPlayback`, `MidiPlayer::StopPlayback`, `OpenSelectedMidiFileNoRestart`, `ToggleMidiStreamPause`, `RestartSelectedMidiStream`, `MidiPlayer_ResetStream`.
- Note that raw no-route helpers are file-local/source-family inferred and have no external xrefs/pointer routes.
- Preserve separation from SoundManager/Miles.

[UID:00008A] `by-class/MidiPlayer.md`:

- Add constructor/destructor/toggle/volume/stop method evidence and exact child page references.
- Keep object layout: vtable at `+0`, `m_playbackEnabled` at `+4`, `m_selectedTrackId` at `+8`.
- Note that `0x00526580` is scalar deleting destructor glue and should not emit source C++.

[UID:0000T9] `by-global/MidiPlayerWinMMState.md`:

- Add `g_midiCallbackStreamOpen` at `0x0069b51c` as an inferred name, with evidence from constructor clear and raw open helper set.
- Add raw helper xrefs for `g_midiChannelVolume`, `g_midiVolumeScale`, `g_hMidiBufferEvent`, and `g_midiHeadersPrepared`.
- Preserve existing state names and constants; do not revert to `unk_69B51C`.

[UID:0002B1] `by-memory/0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals.md`:

- Replace/augment `unk_69B51C` with `g_midiCallbackStreamOpen` and the evidence caveat.
- Add xrefs from new child ranges, especially `0x00525ba0`, `0x00525f60`, `0x00525ff0`, `0x00526060`, `0x00526080`, `0x00526350`, `0x005263a0`, `0x005263e0`, and `0x00526460`.

[UID:00028Q] `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`:

- Clarify that this parent target's constructor/enable/disable read/write `g_pConfig + 0x28de50`, represented in first-draft MidiPlayer code as inferred `m_musicEnabled`.
- Preserve existing [UID:0001CH] use of `g_pConfig + 0x84c` as `m_midiEnabled`; do not conflate the two config offsets.

[UID:0000RM] `by-global/g_pMidiPlayer.md`:

- Add child references for constructor/destructor and compiler cleanup helpers: constructor assigns, destructor/scalar delete clear, EH helper at `0x00526570` clears from constructor cleanup.

Existing child pages [UID:0001CG] and [UID:0001CH]:

- Add cross-reference/dependency sync after new UIDs exist. [UID:0001CG] should point its helper dependencies at the new release/reset/raw volume-support children. [UID:0001CH] should point `MidiPlayer_ResetStream`, `ApplyMidiVolume`, and `ReleaseMidiStreamBuffers` dependencies at the new child pages. Their formal C++ does not need replacement in this report.

No generated files, manual coverage reports, validator state/cache, lease files, or IDA DB should be edited by hand.

## Scoped Validators Required After Acceptance

Run after each new/edited by-* file. For new child pages, run file-mode validator once after creation so UIDs are assigned. If TMP links remain unresolved after UID assignment, re-run the target/support files that contain TMP links.

Exact scoped commands:

> Executable block R010 was removed from this report and preserved verbatim in [0001CF-MidiPlayerAndWinMMHelpers-source-quality-removed.md](0001CF-MidiPlayerAndWinMMHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Generated-refresh check after scoped validators:

- Inspect validator output for `command_id` and `command_timestamp`.
- Check refreshed headers in `auto-generated/NexusTK/audio/MidiPlayer.cpp` and generated reports only as read-only output. If the generated output is older than the validator command metadata and matters for supervisor verification, rerun the relevant scoped validator with `--wait-generated`.
- Do not manually edit `auto-generated/` or any manual `-coverage-report.md`.

## Score Rationale

Why [UID:0001CF] can move from `86/88` to `88/90`:

- MCP confirms all modeled function starts/sizes and raw helper bodies across the full range.
- Previously named blockers are now resolved: raw helper-shaped blocks are mapped, singleton lifecycle is exact, reset/callback/track-select graph is connected, WinMM state names are synchronized, config-offset distinction is documented, and compiler cleanup is isolated.
- The parent remains an aggregate, so it should not receive monolithic function C++; however, Rule 26 allows a formal aggregate marker when child pages carry the actual emitted code.
- Existing owner/emitter route is strong and above gate: [UID:0000LD] owns/emits MidiPlayer.cpp, [UID:00008A] owns class methods, and support globals are documented.

Why the parent score should not go higher than `88/90` now:

- Several raw starts have no external route or pointer/immediate reference. Behavior and ownership are strong, but original source visibility and exact symbol names remain inferred.
- Some helper spellings are source-facing inferred names selected from behavior and subsystem context, not original debug symbols.
- The exact final organization of raw no-route helpers in the original source file cannot be proven beyond file-local/class-method shape.

This is not a no-improvement exception. The report provides first-draft formal C++ for every safely emitting child and a precise no-code proof only for compiler-generated cleanup glue.

## Implementation Tracking Checklist

Leave unchecked during report-only pass. Check items only during an accepted implementation callback.

- [x] Create `by-memory/0x00525b10-0x00525b98.MidiReleaseStreamBuffers.md` as [UID:00041H] with metadata `88/90`, owner/emitter [UID:0000LD], formal C++ above, and behavior/xref/padding evidence. Proof: scoped validator `python .\tools\validator.py --mode file --file by-memory/0x00525b10-0x00525b98.MidiReleaseStreamBuffers.md --apply --queue-timeout 240` returned command_id `000000001472`, command_timestamp `2026-06-25T13:44:20-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`.
- [x] Create `by-memory/0x00525ba0-0x00525bdf.MidiApplySingleChannelVolumeRaw.md` as [UID:00041I] with metadata `85/86`, owner/emitter [UID:0000LD], formal C++ above, and raw no-route proof. Proof: scoped validator `python .\tools\validator.py --mode file --file by-memory/0x00525ba0-0x00525bdf.MidiApplySingleChannelVolumeRaw.md --apply --queue-timeout 240` returned command_id `000000001473`, command_timestamp `2026-06-25T13:44:21-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`.
- [x] Create `by-memory/0x00525dc0-0x00525f3d.MidiPlayerLifecycleMethods.md` as [UID:00041J] with metadata `88/90`, owner [UID:00008A], emitter [UID:0000LD], formal C++ above, and constructor/destructor evidence. Proof: scoped validator `python .\tools\validator.py --mode file --file by-memory/0x00525dc0-0x00525f3d.MidiPlayerLifecycleMethods.md --apply --queue-timeout 240` returned command_id `000000001475`, command_timestamp `2026-06-25T13:44:23-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`.
- [x] Create `by-memory/0x00525f40-0x0052609a.MidiPlayerRawVolumeAndStreamLocalHelpers.md` as [UID:00041K] with metadata `86/88`, owner/emitter [UID:0000LD], formal C++ above, and raw/modeled helper evidence. Proof: scoped validator `python .\tools\validator.py --mode file --file by-memory/0x00525f40-0x0052609a.MidiPlayerRawVolumeAndStreamLocalHelpers.md --apply --queue-timeout 240` returned command_id `000000001476`, command_timestamp `2026-06-25T13:44:34-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`.
- [x] Create `by-memory/0x005260a0-0x005260ff.MidiPlayerPlaybackToggleMethods.md` as [UID:00041L] with metadata `88/90`, owner [UID:00008A], emitter [UID:0000LD], formal C++ above, and config-offset evidence. Proof: scoped validator `python .\tools\validator.py --mode file --file by-memory/0x005260a0-0x005260ff.MidiPlayerPlaybackToggleMethods.md --apply --queue-timeout 240` returned command_id `000000001478`, command_timestamp `2026-06-25T13:44:44-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`.
- [x] Create `by-memory/0x00526340-0x00526350.MidiPlayerStopPlayback.md` as [UID:00041M] with metadata `87/90`, owner [UID:00008A], emitter [UID:0000LD], formal C++ above, and caller evidence. Proof: scoped validator `python .\tools\validator.py --mode file --file by-memory/0x00526340-0x00526350.MidiPlayerStopPlayback.md --apply --queue-timeout 240` returned command_id `000000001479`, command_timestamp `2026-06-25T13:44:54-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`.
- [x] Create `by-memory/0x00526350-0x00526452.MidiPlayerRawStreamControlHelpers.md` as [UID:00041N] with metadata `85/86`, owner/emitter [UID:0000LD], formal C++ above, and raw no-route proof. Proof: scoped validator `python .\tools\validator.py --mode file --file by-memory/0x00526350-0x00526452.MidiPlayerRawStreamControlHelpers.md --apply --queue-timeout 240` returned command_id `000000001480`, command_timestamp `2026-06-25T13:45:04-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`.
- [x] Create `by-memory/0x00526460-0x00526569.MidiPlayerResetStream.md` as [UID:00041O] with metadata `88/90`, owner/emitter [UID:0000LD], formal C++ above, and state/wait/reopen evidence. Proof: scoped validator `python .\tools\validator.py --mode file --file by-memory/0x00526460-0x00526569.MidiPlayerResetStream.md --apply --queue-timeout 240` returned command_id `000000001482`, command_timestamp `2026-06-25T13:45:14-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`.
- [x] Create `by-memory/0x00526570-0x0052664b.MidiPlayerCompilerCleanupHelpers.md` as [UID:00041P] with metadata `86/90`, owner [UID:00008A], `RECONSTRUCTABLE:FALSE`, blank emitter/formal C++, and compiler-generated no-code proof. Proof: scoped validator `python .\tools\validator.py --mode file --file by-memory/0x00526570-0x0052664b.MidiPlayerCompilerCleanupHelpers.md --apply --queue-timeout 240` returned command_id `000000001484`, command_timestamp `2026-06-25T13:45:26-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`.
- [x] Update [UID:0001CF] `by-memory/0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers.md`: metadata is `88/90`, formal aggregate marker is present, inventory table is resolved to child UIDs, raw-helper disposition and owner/emitter rationale are documented, and no `[TMP:` references remain. Proof: scoped validator `python .\tools\validator.py --mode file --file by-memory/0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers.md --apply --queue-timeout 240` returned command_id `000000001486`, command_timestamp `2026-06-25T13:45:36-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`.
- [x] Update [UID:0000LD] `by-file/MidiPlayer.md`: added new child inventory, source-facing helper names, raw no-route caveats, and SoundManager separation. Proof: scoped validator `python .\tools\validator.py --mode file --file by-file/MidiPlayer.md --apply --queue-timeout 240` returned command_id `000000001456`, command_timestamp `2026-06-25T13:41:44-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`.
- [x] Update [UID:00008A] `by-class/MidiPlayer.md`: added constructor/destructor/toggle/volume/stop method evidence, compiler cleanup disposition, and child links. Proof: scoped validator `python .\tools\validator.py --mode file --file by-class/MidiPlayer.md --apply --queue-timeout 240` returned command_id `000000001457`, command_timestamp `2026-06-25T13:41:46-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`; validator also reported existing `missing_ref_uid 0003PF` from the 2026-06-15 RTTI-locator changelog row, not from the new 0001CF implementation links.
- [x] Update [UID:0000T9] `by-global/MidiPlayerWinMMState.md`: added inferred `g_midiCallbackStreamOpen`, raw helper xrefs, and state/global synchronization. Proof: scoped validator `python .\tools\validator.py --mode file --file by-global/MidiPlayerWinMMState.md --apply --queue-timeout 240` returned command_id `000000001458`, command_timestamp `2026-06-25T13:41:48-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`.
- [x] Update [UID:0002B1] `by-memory/0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals.md`: documented inferred `g_midiCallbackStreamOpen` at `0x0069b51c` alongside the superseded `unk_69B51C` wording and added xrefs from the new child ranges. Proof: scoped validator `python .\tools\validator.py --mode file --file by-memory/0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals.md --apply --queue-timeout 240` returned command_id `000000001459`, command_timestamp `2026-06-25T13:41:49-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`.
- [x] Update [UID:00028Q] `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`: clarified `+0x28de50` inferred `m_musicEnabled` versus `+0x84c` `m_midiEnabled`. Proof: scoped validator `python .\tools\validator.py --mode file --file by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md --apply --queue-timeout 240` returned command_id `000000001460`, command_timestamp `2026-06-25T13:41:51-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`; validator also reported existing missing refs `0003UX`, `0003UY`, `0003UA`, and `0003UJ` from older LivingObjectPane support rows, not from the new MidiPlayer config-offset correction.
- [x] Update [UID:0000RM] `by-global/g_pMidiPlayer.md`: added constructor/destructor/EH cleanup/scalar destructor singleton facts. Proof: scoped validator `python .\tools\validator.py --mode file --file by-global/g_pMidiPlayer.md --apply --queue-timeout 240` returned command_id `000000001461`, command_timestamp `2026-06-25T13:41:52-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`.
- [x] Update [UID:0001CG] and [UID:0001CH] dependency/caller references after new UIDs exist; their formal code blocks were not replaced. Proof: [UID:0001CG] `by-memory/0x00525be0-0x00525dbb.MidiStreamCallback.md` validator returned command_id `000000001462`, command_timestamp `2026-06-25T13:41:54-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`; [UID:0001CH] `by-memory/0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers.md` validator returned command_id `000000001463`, command_timestamp `2026-06-25T13:41:55-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`.
- [x] After all scoped validators, verified generated refresh headers/read-only output for `auto-generated/NexusTK/audio/MidiPlayer.cpp` and generated reports. Proof: final queue-status poll reported zero queued/processing generated-refresh jobs at command_id `000000001521`, command_timestamp `2026-06-25T13:50:06-04:00`; `auto-generated/NexusTK/audio/MidiPlayer.cpp` and `auto-generated/-ag-memory-coverage.md` headers show `validator-command-id: 000000001486`, equal to the last parent/child validator; `auto-generated/-ag-file-coverage.md`, `auto-generated/-ag-class-coverage.md`, and `auto-generated/-ag-global-coverage.md` show `validator-command-id: 000000001488`, newer than that validator; `auto-generated/-ag-research-tracker.md` shows `validator-command-id: 000000001513`, also newer. No `--wait-generated` rerun was needed.
- [x] Confirm no generated files, project-level generated files, manual `-coverage-report.md`, validator state/cache, lease files, or IDA DB were manually edited. Proof: generated outputs were only read for headers and refreshed by validator-owned jobs; no generated/project-level/coverage/validator-state/lease/IDA files were hand-edited; `Select-String` over all touched by-* docs found no `[TMP:` references; support leases were released with eight `Success` rows, parent/child leases were released with ten `Success` rows, and `tools/leaser/Agents/current_leases.md` after release had no B011 entries.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B011","command_id":"000000004165","destination_path":"executed-b-agent-research/B011/0001CF-MidiPlayerAndWinMMHelpers-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B011/research/0001CF-MidiPlayerAndWinMMHelpers-source-quality.md","timestamp":"2026-06-25T13:56:19","uid":"0001CF"} -->
<!-- {"agent":"B011","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001CF-MidiPlayerAndWinMMHelpers-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B011/0001CF-MidiPlayerAndWinMMHelpers-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001CF"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
