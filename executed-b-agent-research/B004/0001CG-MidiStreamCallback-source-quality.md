** TARGET-REPORT-UID:0001CG **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **

# UID0001CG MidiStreamCallback Source-Quality Report

## Target

- Target: [UID:0001CG][0x00525be0-0x00525dbb.MidiStreamCallback](../../../by-memory/0x00525be0-0x00525dbb.MidiStreamCallback.md).
- Assignment: B004 report-only Medium pass for `MidiStreamCallback`.
- Report path required by `goal.md`: `tools/leaser/Agents/Agent-B004/research/0001CG-MidiStreamCallback-source-quality.md`.
- Report-only constraints observed: no by-* edits, no generated/coverage/project-level edits, no validator or report lifecycle execution, no leases needed.

## Current Target State

- Current metadata: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000LD`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000LD`.
- Current formal C++ state: blank `RECONSTRUCTION_CPP` body, with the generated output still showing an empty emitter marker for UID0001CG.
- Current target summary already captures the main behavior: WinMM stream callback installed by the stream-open helpers, exact five-argument stdcall ABI, `retn 14h`, `MOM_DONE`/`0x3c9` buffer-return path, `MOM_POSITIONCB`/`0x3ca` controller-volume path, and callees to reset/fill/release/WinMM APIs.
- Parent/support state checked: `by-file/MidiPlayer.md` is `88/89`; `by-class/MidiPlayer.md` is `87/90`; `by-global/MidiPlayerWinMMState.md` is `87/89`; `by-memory/0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers.md` is `88/90`; callback support helpers now carry accepted source-facing names and several populated formal C++ bodies.

## Evidence Checked

- Assignment/workflow: `tools/leaser/Agents/Agent-B004/goal.md`; project skill `ntk-b-agent-workflow`; `references/b-agent-research-and-implementation-workflow.md`; `references/score-blocker-audit-standard.md`.
- Target/support docs:
  - `by-memory/0x00525be0-0x00525dbb.MidiStreamCallback.md`
  - `by-file/MidiPlayer.md`
  - `by-class/MidiPlayer.md`
  - `by-global/MidiPlayerWinMMState.md`
  - `by-memory/0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals.md`
  - `by-memory/0x00525920-0x00525b0d.MidiStreamOpenAndPrimeBuffers.md`
  - `by-memory/0x00525f40-0x0052609a.MidiPlayerRawVolumeAndStreamLocalHelpers.md`
  - `by-memory/0x00526460-0x00526569.MidiPlayerResetStream.md`
  - `by-memory/0x005270e0-0x005271a3.MidiDocumentRelease.md`
  - `by-memory/0x005271b0-0x005273a0.MidiStreamBufferFillHelper.md`
  - `by-memory/0x005269f0-0x00526ba8.MidiStreamEventEncoder.md`
- Generated/tracker state read-only:
  - `auto-generated/-ag-research-tracker.md`: UID0001CG remains `85/88`, combined `86.5`, reports `0`.
  - `project-level/-auto-completion-stats.md`: same score state.
  - `auto-generated/-ag-coverage-report-by-memory.md`: UID0001CG listed as `emits_code:false`.
  - `auto-generated/NexusTK/audio/MidiPlayer.cpp`: raw helper `OpenMidiStreamCallbackOnly` already references `MidiStreamCallback`; UID0001CG itself remains an empty emitter marker.
- Search terms included UID/address/name/source-family terms: `0001CG`, `0x00525be0`, `0x00525dbb`, `sub_525BE0`, `MidiStreamCallback`, `MOM_DONE`, `MOM_POSITIONCB`, `0x00525f60`, `g_midiStreamState`, `MidiFillStreamBuffer`, `MidiStreamWriteContext`.
- IDA MCP discipline: narrow, current-schema calls only. MCP initially timed out once and then refused one connection, but recovered after a short wait; the final active session was `1f24c222` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.
- Current MCP calls/results:
  - `server_health`: status ok, module `NexusTK.exe`, imagebase `0x400000`.
  - `lookup_funcs`: `0x00525be0` is `sub_525BE0`, size `0x1db`; `0x00525dbb` is not a function; `0x00525920`, `0x00525dc0`, `0x00526460`, `0x005270e0`, and `0x005271b0` are modeled surrounding/support functions.
  - `xrefs_to 0x00525be0`: exactly two data xrefs, `0x00525939` from `sub_525920` and `0x00525f67` from an unfenced raw helper site.
  - `callees 0x00525be0`: `midiOutShortMsg`, `sub_526460`, `SetEvent`, `sub_5271B0`, `midiStreamOut`, `sub_5270E0`.
  - `analyze_function 0x00525be0`: prototype `signed int __stdcall(int, int, int, _DWORD *, int)`, size 475, no normal callers, decompiled message switch and state writes.
  - `disasm 0x00525be0`: bounded disassembly confirms `sub eax, 3C9h`, `sub eax, 1` for `0x3c9/0x3ca`, `retn 14h`, `MIDIHDR` callback param access at `[ebp+arg_C]`, stream event read from `lpData + dwBytesRecorded + 8`, state constants `0x64/0xc8/0x12c`, `midiStreamOut` with `cbmh=0x40`, and active-header rotation.
  - `decompile 0x00525920`: confirms `midiStreamOpen(&hms, &puDeviceID, 1, (DWORD_PTR)sub_525BE0, 0, 0x30000)`.
  - `disasm 0x00525f50`: confirms raw helper `0x00525f60` also pushes `offset sub_525BE0`, calls `midiStreamOpen`, and sets `0x0069b51c`.

## Positive Evidence Summary

- Boundary and ABI are current-MCP confirmed: `0x00525be0-0x00525dbb`, 475 bytes, five stdcall args, `retn 14h`. `0x00525dbb` is not a function and the page's five-byte post-function padding remains consistent with the target boundary.
- Callback installation is no longer single-site-only evidence. MCP finds the expected stream-prime xref at `0x00525939` and the raw callback-only open helper at `0x00525f67`; support page UID00041K already documents the raw `OpenMidiStreamCallbackOnly` helper and generated output already emits that helper by name.
- No normal direct callers are present, which is positive rather than negative for this target because WinMM invokes the callback by pointer. The only two xrefs are callback-pointer routes into `midiStreamOpen`.
- The `MOM_POSITIONCB`/`0x3ca` branch is exact enough for source: it treats callback `dwParam1` as `MIDIHDR *`, reads `MIDIEVENT.dwEvent` at `lpData + dwBytesRecorded + 8`, filters controller-change status `0xb0` and controller `7`, updates `g_midiChannelVolume[channel]`, and when `g_midiStreamRunning` is set sends a scaled controller-7 message through `midiOutShortMsg`.
- The `MOM_DONE`/`0x3c9` branch is exact enough for source: it ignores already-idle state `200`, increments `g_midiPendingBufferCount`, handles flushing/end state `300` by setting idle, calling `MidiPlayer_ResetStream(0)`, and signaling `g_hMidiBufferEvent` when both buffers returned, handles stopping state `100` by setting idle and signaling, otherwise refills the active two-buffer slot.
- The refill path is strongly linked to accepted helpers and field maps. It casts the active `MIDIHDR` storage to the accepted `MidiStreamWriteContext` shape, clears write offset/limit/bytes/tick/full fields at offsets `+0x40/+0x44/+0x48/+0x4c/+0x50`, calls `MidiFillStreamBuffer(&g_midiDocumentState, FALSE, stream, g_midiAllowEndReplay)`, copies `stream->bytesWritten` to `header->dwBytesRecorded`, submits with `midiStreamOut(g_hMidiStream, header, 0x40)`, rotates `g_midiActiveHeaderIndex` modulo two, and decrements `g_midiPendingBufferCount`.
- Accepted support names now cover the old C++ blockers:
  - `MidiFillStreamBuffer`, `MidiStreamWriteContext`, `MidiFillResult`, `MIDI_FILL_END_OF_STREAM`, and buffer-full replay behavior are documented and emitted by UID0002C6/UID0002BV.
  - `MidiPlayer_ResetStream`, `MIDI_STREAM_STATE_IDLE`, `MIDI_STREAM_STATE_STOPPING`, and `MIDI_STREAM_STATE_FLUSHING` are documented and emitted by UID00041O.
  - `g_hMidiStream`, `g_hMidiBufferEvent`, `g_midiStreamState`, `g_midiAllowEndReplay`, `g_midiStreamRunning`, `g_midiVolumeScale`, `g_midiActiveHeaderIndex`, `g_midiPendingBufferCount`, `g_midiHeaders`, `g_midiDocumentState`, and `g_midiEndOfStreamReached`/`0x0069b86c` are mapped by UID0000T9/UID0002B1.
  - `MIDI_STATUS_CONTROL_CHANGE` and `MIDI_CONTROLLER_VOLUME` are accepted in `MidiPlayer.md` and already used in generated MIDI code.
- Source placement is consistent: all evidence routes remain inside `NexusTK/audio/MidiPlayer.cpp`; no SoundManager/Miles/MP3/WAV/Redbook route is supported.

## Negative Evidence Summary

- No class-method receiver is present. The first, third, and fifth callback arguments are materially unused, and the callback is passed to WinMM as a free/static callback pointer. Routing UID0001CG to `by-class/MidiPlayer.md` as a method is rejected; the class page is only a support aggregate.
- No separate source file is supported. The callback shares globals, helpers, and the stream-open sites with the accepted `MidiPlayer.cpp` WinMM family. SoundManager is rejected because it owns the Miles/MP3/WAV/Redbook side, not this WinMM MIDI stream path.
- No child-page split is needed for this report. The branch bodies are inside one exact modeled function and do not represent separate callable starts; the only additional callback-pointer route belongs to already-split UID00041K at `0x00525f60`.
- The second data xref at `0x00525f67` is not a normal caller and does not undermine callback ownership. It is the raw `OpenMidiStreamCallbackOnly` helper already owned by the same file family.
- The decompiler's `signed int` return is not source-owner evidence against `void CALLBACK`. WinMM `MidiOutProc` style callbacks are invoked through `CALLBACK_FUNCTION`; the binary returns incidental `eax` values, but the call contract consumes no return value. A `void CALLBACK` source signature is the best source-facing reconstruction.
- The `controller != 0x27 && controller == MIDI_CONTROLLER_VOLUME` pair in disassembly is redundant for the accepted controller-volume path. It should be preserved if exact branch parity is desired, but it is not a naming/layout blocker.
- The remaining uncertainty is original symbol spelling and complete shared declaration placement, not behavior. That should cap below final but should not block first-draft C++ or score movement.

## Ranked Ownership Analysis

1. `by-file/MidiPlayer.md` / UID0000LD: accepted owner and emitter. Current MCP confirms both callback-pointer xrefs are `midiStreamOpen` routes in the MidiPlayer WinMM family: `0x00525939` in stream open/prime and `0x00525f67` in raw `OpenMidiStreamCallbackOnly`. All internal callees are accepted MidiPlayer helpers (`MidiPlayer_ResetStream`, `MidiFillStreamBuffer`, `MidiDocumentRelease`) and all touched globals are owned under the MidiPlayer WinMM state family.
2. `by-class/MidiPlayer.md` / UID00008A: support only, not owner. The class page should continue linking the callback as a private/static WinMM helper, but the callback has no `this` receiver and no class-method ABI.
3. `by-global/MidiPlayerWinMMState.md` / UID0000T9 and child data pages: support only, not owner. They own the static state declarations and naming evidence that the callback consumes.
4. `by-file/SoundManager.md` or other audio files: rejected. No MCP xref, import, or support-doc route connects UID0001CG to Miles/MP3/WAV/Redbook SoundManager behavior.
5. New child pages: rejected for this pass. MCP shows one modeled callback function; message branches and refill logic are internal control flow, not separate callable starts.

## Source Placement

- Place UID0001CG in `NexusTK/audio/MidiPlayer.cpp` through owner/emitter UID0000LD.
- Treat `MidiStreamCallback` as a private file-scope WinMM callback with a `CALLBACK`/stdcall ABI, not as a `MidiPlayer` instance method.
- Keep source order near the existing WinMM stream helpers. Generated output already has raw helper `OpenMidiStreamCallbackOnly` calling `MidiStreamCallback`, so the callback body must be available before or by declaration for that helper.
- Keep `by-global/MidiPlayerWinMMState.md` and its child data pages as declaration/support owners for globals such as `g_hMidiStream`, `g_midiHeaders`, `g_midiStreamState`, `g_midiActiveHeaderIndex`, and `g_midiPendingBufferCount`; do not duplicate global storage declarations in UID0001CG.
- No support evidence requires moving the callback into SoundManager, a parser-only file, or a separate callback source file.

## Heuristic / Inference Reanalysis And Validation

- Owner/emitter route: validated as `CANONICAL_OWNER:0000LD` and `EMITTER_UIDS:0000LD`. The target is source-authored private WinMM callback code in `MidiPlayer.cpp`; it is not compiler glue and not generated solely by data declarations.
- Callback name: `MidiStreamCallback` is the best current source-facing name. It is already used by generated raw helper UID00041K and by support prose, and directly describes both `midiStreamOpen` callback-pointer xrefs.
- Message mapping: `0x3c9` maps to `MOM_DONE`; `0x3ca` maps to `MOM_POSITIONCB`. The disassembly implements this as subtract `0x3c9`, test zero, subtract one, then test zero, so a two-case `switch`/`if` is source-equivalent.
- State mapping: values `100`, `200`, and `300` match existing accepted names from reset/control support: `MIDI_STREAM_STATE_STOPPING`, `MIDI_STREAM_STATE_IDLE`, and `MIDI_STREAM_STATE_FLUSHING`. The callback's `300` path is the end/flushing path that calls reset after both buffers return; the `100` path is the stop path that only signals.
- Stream buffer layout: the report validates the previously open layout blocker. `MidiStreamWriteContext` is intentionally passed at the same address as the active `MIDIHDR`: `lpData` at offset `+0x00` is the writer buffer pointer, and writer fields begin at `+0x40`. This matches UID0002BV's field map and the callback/open helper writes.
- Helper roles: `MidiFillStreamBuffer` owns SMF event selection/replay/output-full handling; `MidiDocumentRelease` owns document cleanup on callback fill/submit failure; `MidiPlayer_ResetStream` owns stop/reset/reopen handling after end-state buffer returns; `SetEvent` releases the waiting reset/open path after both buffers return.
- Generated marker state: UID0001CG currently emits only `// UID:0001CG ... Empty Emitter Marker`, while generated `OpenMidiStreamCallbackOnly` already references `MidiStreamCallback`. This is a concrete integration blocker that the recommended formal body resolves.
- Rejected alternatives:
  - Keep metadata unchanged: rejected. Current MCP plus accepted support pages resolve the old blocker list enough for implementation-ready first-draft C++.
  - Move owner to `by-class/MidiPlayer.md`: rejected, callback has no `this` receiver and is passed as a static/free callback.
  - Split `MOM_DONE` and `MOM_POSITIONCB` into child pages: rejected, no separate entries/callable starts.
  - Emit only marker/no-code proof: rejected. The behavior, helper names, field layout, and owner/emitter route are now source-ready below final confidence.

## Score And Metadata Recommendation

- Recommended metadata change: raise UID0001CG from `85/88` to `88/90`.
- Keep `CANONICAL_OWNER:0000LD`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:0000LD`.
- Rationale: current MCP confirms the exact boundary, pointer-only callback xrefs, no normal callers, full callback branch behavior, WinMM callees, reset/fill/release helper routes, and the raw callback-only open site. Support pages now resolve the former callback blockers for state constants, stream write-context layout, helper names, and source placement. Confidence remains capped at 90 because original symbol spellings and the final shared type/global declaration placement are still inferred rather than recovered.

## Recommended Target Doc Changes

- In `by-memory/0x00525be0-0x00525dbb.MidiStreamCallback.md`, update metadata to `COMPLETION:88` and `CONFIDENCE:90`; keep `CANONICAL_OWNER:0000LD`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000LD`.
- Replace the empty `RECONSTRUCTION_CPP` marker with the exact formal block provided in `## First-Draft C++ Recommendation`.
- Add or refine target evidence notes for current MCP session `1f24c222`: exact `0x1db` boundary, no normal callers, data xrefs at `0x00525939` and `0x00525f67`, callees, message branch mapping, active-header refill behavior, and stream write-context layout at the active `MIDIHDR` base.
- Add target rationale that `0x00525f67` is the raw `OpenMidiStreamCallbackOnly` route, not a competing owner/caller.
- Add target negative-evidence text rejecting class-method ownership, SoundManager placement, child split, and marker-only/no-code disposition.

## Recommended Support Doc Changes

- `by-file/MidiPlayer.md`: proposed support sync only if not already present. Add a brief source-quality note that UID0001CG is now source-ready as private `MidiStreamCallback`, installed by both `MidiStreamOpenAndPrimeBuffers` and raw `OpenMidiStreamCallbackOnly`, and remains owned/emitted by UID0000LD.
- `by-class/MidiPlayer.md`: proposed support sync only if not already present. Keep the callback listed as a file-static/helper relationship, not a method, and note the class page is support-only for this callback.
- `by-global/MidiPlayerWinMMState.md` and `by-memory/0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals.md`: proposed support sync only if needed. Ensure the callback-consumed names remain consistent: `g_hMidiStream`, `g_hMidiBufferEvent`, `g_midiStreamState`, `g_midiAllowEndReplay`, `g_midiStreamRunning`, `g_midiVolumeScale`, `g_midiActiveHeaderIndex`, `g_midiPendingBufferCount`, `g_midiHeaders`, `g_midiDocumentState`, and the preferred name for `0x0069b86c`.
- `by-memory/0x00525f40-0x0052609a.MidiPlayerRawVolumeAndStreamLocalHelpers.md`: already contains the raw `OpenMidiStreamCallbackOnly` evidence; no mandatory support edit is required unless supervisor wants reciprocal xref wording after target incorporation.
- No support-doc child pages are recommended. If implementation finds a support doc inconsistent with this report, update only that accepted support doc under lease during callback; otherwise leave support docs unchanged as already-present.

## First-Draft C++ Recommendation

Recommended UID0001CG exact formal `RECONSTRUCTION_CPP CODE` insertion text:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void CALLBACK MidiStreamCallback(HMIDIOUT hMidiOut,
                                        UINT message,
                                        DWORD_PTR instance,
                                        DWORD_PTR param1,
                                        DWORD_PTR param2)
{
    (void)hMidiOut;
    (void)instance;
    (void)param2;

    if (message == MOM_POSITIONCB) {
        MIDIHDR* header = (MIDIHDR*)param1;
        BYTE* eventBase = (BYTE*)header->lpData + header->dwBytesRecorded;
        DWORD event = *(DWORD*)(eventBase + 8);
        BYTE controller = (BYTE)((event >> 8) & 0xff);

        if ((event & 0xf0) == MIDI_STATUS_CONTROL_CHANGE &&
            controller != 0x27 &&
            controller == MIDI_CONTROLLER_VOLUME) {
            unsigned int channel = event & 0x0f;
            unsigned int volume = (event >> 16) & 0x7f;

            g_midiChannelVolume[channel] = volume;
            if (g_midiStreamRunning != 0) {
                DWORD scaled = (g_midiVolumeScale * g_midiChannelVolume[channel]) / 1000;
                DWORD outgoing = MIDI_STATUS_CONTROL_CHANGE |
                                 channel |
                                 (MIDI_CONTROLLER_VOLUME << 8) |
                                 (scaled << 16);
                midiOutShortMsg((HMIDIOUT)g_hMidiStream, outgoing);
            }
        }
        return;
    }

    if (message != MOM_DONE) {
        return;
    }

    if (g_midiStreamState == MIDI_STREAM_STATE_IDLE) {
        return;
    }

    ++g_midiPendingBufferCount;

    if (g_midiStreamState == MIDI_STREAM_STATE_FLUSHING) {
        if (g_midiPendingBufferCount >= 2) {
            g_midiStreamState = MIDI_STREAM_STATE_IDLE;
            MidiPlayer_ResetStream(0);
            SetEvent(g_hMidiBufferEvent);
        }
        return;
    }

    if (g_midiStreamState == MIDI_STREAM_STATE_STOPPING) {
        if (g_midiPendingBufferCount >= 2) {
            g_midiStreamState = MIDI_STREAM_STATE_IDLE;
            SetEvent(g_hMidiBufferEvent);
        }
        return;
    }

    if (g_midiStreamRunning == 0 || g_midiPendingBufferCount == 0) {
        return;
    }

    MIDIHDR* header = &g_midiHeaders[g_midiActiveHeaderIndex].header;
    MidiStreamWriteContext* stream = (MidiStreamWriteContext*)header;
    stream->writeOffset = 0;
    stream->writeLimit = MIDI_STREAM_BUFFER_BYTES;
    stream->bytesWritten = 0;
    stream->lastEventTick = 0;
    stream->fullEventPending = 0;

    int fillResult = MidiFillStreamBuffer(&g_midiDocumentState,
                                          FALSE,
                                          stream,
                                          g_midiAllowEndReplay);
    if (fillResult != MIDI_FILL_OK) {
        if (fillResult == MIDI_FILL_END_OF_STREAM) {
            g_midiEndOfStreamReached = 1;
            g_midiStreamState = MIDI_STREAM_STATE_FLUSHING;
            return;
        }

        MidiDocumentRelease(&g_midiDocumentState);
        return;
    }

    header->dwBytesRecorded = stream->bytesWritten;
    if (midiStreamOut(g_hMidiStream, header, sizeof(MIDIHDR)) != MMSYSERR_NOERROR) {
        MidiDocumentRelease(&g_midiDocumentState);
        return;
    }

    g_midiActiveHeaderIndex = (g_midiActiveHeaderIndex + 1) % 2;
    --g_midiPendingBufferCount;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Notes for implementation callback:
- If the active shared declarations do not already define `MIDI_STREAM_BUFFER_BYTES`, use the existing constant value `1024` / `0x400` or add the private file-local constant in the owner page, not in this child body.
- If `g_midiEndOfStreamReached` is not the accepted final symbol for `0x0069b86c`, use the owner/global page's current preferred source-facing name and keep the address evidence in prose.
- The formal block should replace the current empty marker for UID0001CG; no aggregate body or child page is required.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| 0001CG-C01 | Raise UID0001CG from `85/88` to `88/90`. | Strong | Current MCP confirms exact boundary, pointer-only callback xrefs, no normal callers, complete branch behavior, callees, and support pages resolving former blockers. | `by-memory/0x00525be0-0x00525dbb.MidiStreamCallback.md` metadata and score rationale | incorporate | applied: target header now has `COMPLETION:88` and `CONFIDENCE:90`; `## Score Rationale` records the 2026-07-02 B004 raise. Scoped validator `000000004757` returned exit code 0 / `ok: 1` with completion/confidence updates. |
| 0001CG-C02 | Keep `CANONICAL_OWNER:0000LD`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000LD`. | Strong | Both callback-pointer xrefs enter `midiStreamOpen` in the MidiPlayer WinMM family; all internal callees/state are owned by MidiPlayer support pages. | Target metadata; `by-file/MidiPlayer.md` support note if needed | incorporate | applied: target header still has `CANONICAL_OWNER:0000LD`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000LD`; `## Status` now states owner/emitter UID0000LD. Support file `by-file/MidiPlayer.md` already lists UID0001CG in related helpers and contents. |
| 0001CG-C03 | Insert first-draft `MidiStreamCallback` formal C++ block. | Strong | Generated output previously had UID0001CG empty marker, while raw helper already references `MidiStreamCallback`; MCP proves message branches, state writes, fill/release/reset calls, and stream submit path. | Target `RECONSTRUCTION_CPP` block | incorporate | applied: target `RECONSTRUCTION_CPP` block now contains the accepted `static void CALLBACK MidiStreamCallback(...)` body. Scoped validator `000000004757` recorded `autogen_registry_update ... blank -> block`. |
| 0001CG-C04 | Record current MCP evidence for the second callback-pointer route at `0x00525f67`. | Strong | MCP `disasm 0x00525f50` shows raw helper pushing `offset sub_525BE0`, calling `midiStreamOpen`, and setting `0x0069b51c`. | Target evidence notes; optional reciprocal support in UID00041K if needed | incorporate | applied/already-present: target `## Evidence` now records current session `1f24c222`, `xrefs_to` refs at `0x00525939` and `0x00525f67`, and raw helper behavior. UID00041K already documents `OpenMidiStreamCallbackOnly` passing UID0001CG to `midiStreamOpen`, so no support edit was needed. |
| 0001CG-C05 | Record stream write-context layout at the active `MIDIHDR` base with writer fields at `+0x40`. | Strong | MCP callback/open writes clear fields at `+0x40/+0x44/+0x48/+0x4c/+0x50`; UID0002BV documents the accepted `MidiStreamWriteContext` field map. | Target behavior/reconstruction notes; optional support note in UID0002BV only if inconsistent | incorporate | applied/already-present: target `## Behavior` and `## Reconstruction Notes` now state `MidiStreamWriteContext` overlays the active `MIDIHDR`; C++ block uses `MidiStreamWriteContext* stream = (MidiStreamWriteContext*)header`. UID0002BV already documents the context field map, so no support edit was needed. |
| 0001CG-C06 | Reject class-method ownership, SoundManager placement, child-page split, and marker-only disposition. | Strong | No `this` receiver, no SoundManager route, no branch entry starts, and enough formal C++ evidence exists. | Target negative evidence / ranked ownership / source placement sections | incorporate | applied: target `## Reconstruction Notes` now records ranked ownership outcome, class page support-only role, WinMM state support-only role, SoundManager rejection, child split rejection, and formal C++ acceptance. |
| 0001CG-C07 | Support docs need only consistency sync, not mandatory semantic rewrites. | Medium-high | `MidiPlayer.md`, `MidiPlayer` class, WinMM state, UID00041K, UID0002C6, and UID0002BV already carry the accepted names/routes used by this report. | `by-file/MidiPlayer.md`, `by-class/MidiPlayer.md`, `by-global/MidiPlayerWinMMState.md`, UID00041K, UID0002B1/UID0002BV only if callback edit reveals inconsistency | already-present | already-present/excluded-with-reason: support docs were verified read-only. `MidiPlayer.md` already separates MidiPlayer from SoundManager, lists UID0001CG and accepted helper/type/constants; `by-class/MidiPlayer.md` is aggregate/support-only; `MidiPlayerWinMMState.md`/UID0002B1 already map consumed globals; UID00041K already documents `OpenMidiStreamCallbackOnly`; UID0002C6/UID0002BV already document `MidiFillStreamBuffer`, `MidiStreamWriteContext`, fill results, and controller-volume constants. No stale/lower-detail support inconsistency was found, so no support files were edited or validated. |

## Implementation Tracking Checklist

- [x] Research file `tools/leaser/Agents/Agent-B004/research/0001CG-MidiStreamCallback-source-quality.md`: created and repaired in place with required sections, exact formal C++ insertion shape, required ledger schema, and file-specific implementation checklist.
- [x] Target file `by-memory/0x00525be0-0x00525dbb.MidiStreamCallback.md`: implementation applied under B004 lease. Metadata changed to `88/90`, owner/emitter/reconstructable retained, formal C++ block populated, current MCP/session evidence added, source placement and rejected alternatives preserved, and score rationale updated.
- [x] Support file `by-file/MidiPlayer.md`: verified read-only during callback. Already present proof: separates MidiPlayer from SoundManager, lists UID0001CG as the exact callback page, lists accepted `MidiStreamWriteContext`, fill results, status constants, and `OpenMidiStreamCallbackOnly`; no stale/lower-detail inconsistency found.
- [x] Support file `by-class/MidiPlayer.md`: verified read-only during callback. Already present proof: class page is aggregate/support with exact helper bodies emitted by by-memory children; no method-owner rewrite needed.
- [x] Support file `by-global/MidiPlayerWinMMState.md`: verified read-only during callback. Already present proof: owns WinMM/static MIDI state family and maps callback-consumed globals; no duplicate target body needed.
- [x] Support file `by-memory/0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals.md`: verified read-only during callback. Already present proof: maps `g_hMidiStream`, `g_midiStreamState`, `g_midiAllowEndReplay`, `g_midiStreamRunning`, `g_midiVolumeScale`, `g_midiActiveHeaderIndex`, `g_midiPendingBufferCount`, `g_midiDocumentState`, and `0x0069b86c`.
- [x] Support file `by-memory/0x00525f40-0x0052609a.MidiPlayerRawVolumeAndStreamLocalHelpers.md`: verified read-only during callback. Already present proof: contains `OpenMidiStreamCallbackOnly`, passes `(DWORD_PTR)MidiStreamCallback`, and documents raw `0x00525f60-0x00525f94` route.
- [x] Support file `by-memory/0x005271b0-0x005273a0.MidiStreamBufferFillHelper.md` and encoder support UID0002BV: verified read-only during callback. Already present proof: existing pages document `MidiFillStreamBuffer`, `MidiStreamWriteContext`, `MIDI_FILL_END_OF_STREAM`, `MIDI_FILL_OUTPUT_FULL`, `MIDI_STATUS_CONTROL_CHANGE`, and `MIDI_CONTROLLER_VOLUME`.
- [x] Implementation callback only: leased `by-memory/0x00525be0-0x00525dbb.MidiStreamCallback.md` with `python .\leaser.py B004 lease ...` before editing; applied claims `0001CG-C01` through `0001CG-C06`; released with `python .\leaser.py B004 unlease ...` after validator batch, both commands returned `Success`.
- [x] Implementation callback only: inspected recommended support docs and edited none because claim `0001CG-C07` is already-present/excluded-with-reason as recorded in the ledger.
- [x] Implementation callback only: ran scoped validator from `source-3/project-documentation`: `python .\tools\validator.py --mode file --file 'by-memory/0x00525be0-0x00525dbb.MidiStreamCallback.md' --apply --queue-timeout 240`; `command_id: 000000004757`; `command_timestamp: 2026-07-02T18:05:38-04:00`; exit code `0`; `ok: 1`; warnings: none reported; updates included completion/confidence, registry hash, blank-to-block, reference index, projected stats.
- [x] Implementation callback only: reported generated-refresh state after scoped validation without manual generated edits. Validator returned `generated_refresh: deferred`, `generated_refresh_command_id: 000000004757`; generated `auto-generated/NexusTK/audio/MidiPlayer.cpp` and `auto-generated/-ag-coverage-report-by-memory.md` headers now show `validator-command-id: 000000004757` and refreshed `2026-07-02T18:05:38-04:00`. Queue status `000000004762` still showed one generated refresh queued and one processing after the relevant headers had refreshed.
- [x] Implementation callback only: updated this report's ledger/checklist with applied/already-present/excluded states and proof after edits and validation.
- [x] Implementation callback only: confirmed target lease released; no support leases were taken; stopped at supervisor execute handoff. No `execute_report`, dry-run/status/probing variant, registry lifecycle command, manual report move, or archive command was run.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004774","destination_path":"executed-b-agent-research/B004/0001CG-MidiStreamCallback-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0001CG-MidiStreamCallback-source-quality.md","timestamp":"2026-07-02T18:10:02-04:00","uid":"0001CG"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
