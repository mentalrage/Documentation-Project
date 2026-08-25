** TARGET-REPORT-UID:0001CH **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001CH MidiPlayerTrackSelectionHelpers Source-Quality Report

Agent: Agent-B006  
Assignment: B-preferred source-quality / heuristic research for [UID:0001CH] `MidiPlayerTrackSelectionHelpers`  
Target: `source-3/project-documentation/by-memory/0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers.md`  
Required output path: `source-3/project-documentation/tools/leaser/Agents/Agent-B006/research/0001CH-MidiPlayerTrackSelectionHelpers-source-quality.md`  
Status: report-only. No target/support docs or coverage report were edited.

## Bottom Line

[UID:0001CH] should move from a blank helper-pair page to first-draft source C++ in `NexusTK/audio/MidiPlayer.cpp`.

Best-supported source shape:

| Range | Source-quality name/signature | Placement | Code status |
| --- | --- | --- | --- |
| `0x00526100-0x00526233` | `void MidiPlayer::SelectTrack(unsigned short trackId)` | `MidiPlayer` class method | Populate first-draft C++ |
| `0x00526240-0x00526332` | `static void StartSelectedMidiFile(const wchar_t *path)` | private file-scope helper in `MidiPlayer.cpp` | Populate first-draft C++ |

Recommended target metadata:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LD | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LD | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Rationale: the target already clears the active code-entry gate with `85/87` and nonblank emitter route. This pass resolves the main blockers: class-method versus file-static split, selected-track field name, config music flag, configured/fallback path names, current path global, start/reset/open/restart/volume helper names, and generated-output artifacts. Confidence should stay below final audit because exact original symbol spellings are inferred, and live IDA MCP was not available in this Codex toolset.

## Evidence Checked

- Target page `by-memory/0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers.md`.
- `by-file/MidiPlayer.md`, `by-class/MidiPlayer.md`, `by-global/MidiPlayerWinMMState.md`, `by-global/g_pMidiPlayer.md`.
- `by-memory/0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals.md` and `0x0069b870-0x0069b890.MidiSMFParserScratchGlobals.md`.
- `by-memory/0x00525920-0x00525b0d.MidiStreamOpenAndPrimeBuffers.md`, `0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers.md`, `0x00525be0-0x00525dbb.MidiStreamCallback.md`.
- `by-memory/0x0061fafc-0x0061fb74.MidiPlayerReadOnlyData.md` for `Midi\\%s` and `%d.mid` string evidence.
- `by-memory/0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers.md`, `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`, `by-class/Config.md`, and `by-file/Config.md`.
- Caller page `by-memory/0x00512f20-0x00513305.MapPaneHandleAnimationSoundPacket.md`.
- Generated outputs:
  - `project-documentation/auto-generated/NexusTK/audio/MidiPlayer.cpp`.
  - `simroot_v2/audio/MidiPlayer.cpp` as a generated lead only, not source proof.
- Prior executed MIDI research:
  - B001 `0002BU-0002BV-0002C6-0002C7-MidiSMFParserStreamSourceQuality.md`.
  - B003 `0002B2-MidiSMFParserScratchGlobals-source-quality.md`.
- `by-memory/-coverage-report.md` current row for [UID:0001CH].
- `project-level/-unresolved.md` raw-name hits for `sub_526100`, `sub_526240`, and `sub_526340`.
- Numeric conversion verified with `tools/int_convert.py`: decimal `2124` is `0x84c`; decimal `12` is `0xc`.
- IDA MCP availability check: `tool_search` for IDA/MCP/decompile tools returned no tools in this Codex session. This report relies on existing IDA-backed docs and lists live IDA checks as validator needs.

## Heuristic / Inference Reanalysis And Validation

### Owner, Emitter, And Source File

Keep owner/emitter [UID:0000LD] `MidiPlayer`, source path `NexusTK/audio/MidiPlayer.cpp`.

Evidence:

- The target methods read/write the `MidiPlayer` object at `this+0x04` and `this+0x08`, use `g_pMidiPlayer` owned by the same file/class family, and operate on WinMM MIDI globals documented under [UID:0000T9].
- `by-file/MidiPlayer.md` explicitly owns the WinMM MIDI stream controller, two-buffer MIDI header lifetime, active MIDI singleton, parser helpers, reset helper, and track selection/start helper pair.
- `by-project-structure/proposed-source-tree.md` separates `NexusTK/audio/MidiPlayer.cpp` from `NexusTK/audio/SoundManager.cpp`.
- The only external call into `0x00526100` is from the MapPane animation/sound packet handler at `0x00512fb2`; MapPane is a consumer of a music-selection route, not the owner.
- Config helper calls are storage access through `g_pConfig`; Config does not own the playback policy.

Rejected owner alternatives:

- `SoundManager`: owns Miles/Redbook/stream/sample music, not WinMM MIDI stream open/reset/parser state.
- `MapPane`: owns packet parsing and calls the music route, but does not own MIDI state.
- `Config`: owns selector string storage and the music flag, but `SelectTrack` is playback policy and stream control.
- `Application`: constructs the player and owns startup lifetime, but not this helper logic.

### Function Split And Declaration Shape

`0x00526100` should be a `MidiPlayer` method. It uses the object playback flag and selected-track field, and the generated `simroot_v2` lead independently chose `MidiPlayer::SelectTrack(unsigned short)`. The method has one known external call from MapPane packet handling, consistent with public/private class behavior through `g_pMidiPlayer`.

`0x00526240` should be a private file-scope helper, not a class method. The target page records only calls from `0x00526100` at `0x005261c8` and `0x0052621c`; its behavior copies a path into global current-path storage, resets/opens/restarts the WinMM stream, updates global running/restart flags, and reapplies volume. There is no documented `this` access. Treat it as `static void StartSelectedMidiFile(const wchar_t *path)`.

No further child split is required. The target page is already an exact helper pair with two function bodies and no code after `0x00526332`; padding `0x00526332-0x00526340` remains alignment before `MidiPlayer::StopPlayback`.

### Names And Signatures

Recommended names:

| Current/raw surface | Recommended source name | Evidence |
| --- | --- | --- |
| `sub_526100` | `MidiPlayer::SelectTrack` | Checks requested track id, object playback state, selected-track field; generated lead uses `SelectTrack`; caller is a packet path selecting MIDI music. |
| `sub_526240` | `StartSelectedMidiFile` | Copies selected path, opens/primes/restarts playback; only called by `SelectTrack`. |
| `this+0x04` | `m_playbackEnabled` | Constructor/enable/disable/select use as local playback-enabled flag. |
| `this+0x08` | `m_selectedTrackId` | Constructor/disable/stop store `-1`; select compares/stores requested track id `<= 12`; not a device id. |
| `g_pConfig + 0x84c` | `Config::m_midiEnabled` | Enable/disable/select check or update this MIDI/music gate. |
| `0x0048eaa0` | `ConfigGetStringPreference` or `Config::GetStringPreference` | Selector-based Config string lookup; MIDI passes track id as selector. |
| `0x0048eb00` | `ConfigSetStringPreference` or `Config::SetStringPreference` | Selector-based Config string setter; MIDI clears/updates the selector before fallback. |
| `Destination` | `g_midiCurrentPath` | Track-start helper copies the selected path and stream-open helper opens it. |
| `dword_69B510` | `g_midiAllowEndReplay` / `g_midiFillReplayMode` | Existing docs call it fill budget/limit; B001 fill-helper signature uses an end-replay-style boolean; generated lead writes `0` for configured `Midi\\%s` and `1` for fallback `%d.mid`. |
| `dword_69B514` | `g_midiDocumentLoaded` | Open/reset/document release guard. Prefer this over generated `g_midiStreamOpen`. |
| `dword_69B518` | `g_midiStreamRunning` | Callback/refill/restart running flag. |
| `dword_69B50C` | `g_midiRestartPending` | Restart-pending/reset coordination used by start/reset. |
| `dword_69B524` | `g_midiVolumeScale` | Volume scale applied by `0x00525ff0`. |
| `0x00525920` | `MidiStreamOpenAndPrimeBuffers` | Existing exact page title and behavior. |
| `0x00525ff0` | `ApplyMidiVolume` | Applies current MIDI volume scale across 16 channels through `midiOutShortMsg`. |
| `0x00526460` | `MidiPlayer_ResetStream` / source-private `ResetMidiStream` | Existing saved label and support docs use `MidiPlayer_ResetStream`; source cleanup can shorten to `ResetMidiStream` once all refs are updated. |

Rejected names:

- `m_selectedDeviceId`: rejected because `puDeviceID`/device id is global stream-open storage at `0x0069b504`; `this+0x08` is compared to requested track ids and cleared on stop.
- `m_currentDeviceId`: same rejection.
- `SelectMidiTrack`: acceptable but less supported than `SelectTrack` because generated source map already uses `SelectTrack` and the class context supplies MIDI.
- `StartSelectedMidiPath`: semantically okay but less source-like than `StartSelectedMidiFile`; the helper receives a filename/path and opens a MIDI document.
- `g_midiUseLooseFile`: rejected as final name. The generated lead uses it only in `SelectTrack`, while support docs show `0x0069b510` is passed into the stream-fill helper. `g_midiAllowEndReplay` or `g_midiFillReplayMode` better matches B001's accepted fill-helper argument role.
- `g_midiStreamOpen`: rejected as final name for `0x0069b514`; support docs and reset/document release behavior support `g_midiDocumentLoaded`.
- `g_pApplication->midiEnabled`: rejected. The target page and `int_convert.py`-verified offset show the select helper checks `g_pConfig + 2124` / `0x84c`, not `g_pApplication`.

### Path And Config Semantics

Best-supported path behavior:

1. Validate `g_pConfig->m_midiEnabled`, `this->m_playbackEnabled`, `trackId <= 12`, and `trackId != m_selectedTrackId`.
2. Clear selected track to `-1`, reset current stream, then store the requested track id.
3. Read the Config selector string for the track id through the Config string preference helper.
4. If nonempty, format configured DAT/resource-style path as `Midi\\%s`, set fill replay mode false, and call `StartSelectedMidiFile`.
5. If playback still is not running, clear or update the Config selector through the setter, format fallback filename `%d.mid`, set fill replay mode true, and call `StartSelectedMidiFile` again.

The setter argument should be validated during implementation. Current best direction is that it clears the failed configured selector before fallback, matching the generated draft. The alternative that it writes the fallback string is less supported because the setter call is documented at `0x005261e7` while the `%d.mid` string xref is documented at `0x005261f0`, after the setter call.

### Start Helper Semantics

Best-supported `StartSelectedMidiFile` behavior:

1. Copy the selected path into `g_midiCurrentPath`.
2. If a MIDI document/stream payload is already loaded, call reset with skip-reopen flag `0x00010000`.
3. Call `MidiStreamOpenAndPrimeBuffers`; on success set `g_midiDocumentLoaded = 1`.
4. If `g_midiRestartPending` is set, call `midiStreamRestart`, clear restart-pending, and reapply volume.
5. If another stream is still running, reset it normally.
6. If no document is loaded, clear running state; otherwise clear stream state, restart the WinMM stream, set `g_midiStreamRunning = 1` on success, and call `ApplyMidiVolume(g_midiVolumeScale)`.

This matches the target page, `MidiStreamOpenAndPrimeBuffers`, `MidiPlayerWinMMState`, and the generated start-helper lead. The generated lead has good control-flow fidelity but poor source quality: explicit `__stdcall`, `g_midiSelectedPath`, `g_midiStreamOpen`, and `g_midiMasterVolume` should be normalized to project doc names.

### Generated Output Reconciliation

`project-documentation/auto-generated/NexusTK/audio/MidiPlayer.cpp` currently emits SMF parser scratch declarations and several helper bodies, but [UID:0001CH] is still an empty emitter marker.

`simroot_v2/audio/MidiPlayer.cpp` provides useful leads:

- It names `0x00526100` as `SelectTrack` and gives signature `void MidiPlayer::SelectTrack(unsigned short trackId)`.
- It names `0x00526240` as `StartSelectedMidiFile`.
- Its `StartSelectedMidiFile` control flow closely matches target/support docs.

Do not copy the generated draft directly:

- It uses `g_pApplication->midiEnabled`, contradicting target `g_pConfig + 0x84c`.
- It uses `m_selectedDeviceId`, contradicting selected-track behavior.
- It uses `g_midiUseLooseFile`/`g_midiStreamOpen`/`g_midiSelectedPath`, while support docs prefer `g_midiAllowEndReplay` or fill-mode state, `g_midiDocumentLoaded`, and `g_midiCurrentPath`.
- It contains explicit calling-convention and modern/source-style artifacts that prior B001 MIDI research warned against copying.

## Recommended Target Doc Changes

### Status / Reconstruction Notes

Replace the "C++ remains blank..." note with:

```text
C++ should now be populated. The source-quality shape is `void MidiPlayer::SelectTrack(unsigned short trackId)` plus private file-scope `StartSelectedMidiFile(const wchar_t *path)` in `NexusTK/audio/MidiPlayer.cpp`. Original symbol spellings remain inferred, but the class/file split, selected-track field, Config music flag, configured/fallback path strings, current-path global, and reset/open/restart/volume helper route are sufficiently resolved for first-draft source.
```

### Covered Range Table

Recommended replacement rows:

```text
| `0x00526100-0x00526233` | `MidiPlayer::SelectTrack(unsigned short trackId)` | Validates Config MIDI enablement, object playback state, requested track id, and `m_selectedTrackId`; resets the active stream, resolves configured `Midi\\%s` and fallback `%d.mid` paths, and calls `StartSelectedMidiFile`. |
| `0x00526240-0x00526332` | `StartSelectedMidiFile(const wchar_t *path)` | Private file-scope helper that copies the selected path to `g_midiCurrentPath`, resets existing loaded stream state, opens/primes playback through `MidiStreamOpenAndPrimeBuffers`, restarts WinMM playback, updates running/restart state, and reapplies `g_midiVolumeScale`. |
```

### First-Draft C++

Recommended formal C++ for the target page:

```cpp
static const unsigned int MIDI_RESET_SKIP_REOPEN = 0x00010000;
static const unsigned int MIDI_TRACK_PATH_CHARS = 260;
static const unsigned short MIDI_TRACK_NONE = (unsigned short)-1;
static const unsigned short MIDI_TRACK_MAX = 12;

static void StartSelectedMidiFile(const wchar_t *path)
{
    wcscpy_s(g_midiCurrentPath, MIDI_TRACK_PATH_CHARS, path);

    if (g_midiDocumentLoaded != 0) {
        MidiPlayer_ResetStream(MIDI_RESET_SKIP_REOPEN);
    }

    if (MidiStreamOpenAndPrimeBuffers() == 0) {
        g_midiDocumentLoaded = 1;
    }

    if (g_midiRestartPending != 0) {
        midiStreamRestart(g_hMidiStream);
        g_midiRestartPending = 0;
        ApplyMidiVolume(g_midiVolumeScale);
        return;
    }

    if (g_midiStreamRunning != 0) {
        MidiPlayer_ResetStream(0);
    }

    if (g_midiDocumentLoaded == 0) {
        g_midiStreamRunning = 0;
    } else {
        g_midiStreamState = 0;
        if (midiStreamRestart(g_hMidiStream) == 0) {
            g_midiStreamRunning = 1;
            ApplyMidiVolume(g_midiVolumeScale);
            return;
        }
    }

    ApplyMidiVolume(g_midiVolumeScale);
}

void MidiPlayer::SelectTrack(unsigned short trackId)
{
    wchar_t configuredName[MIDI_TRACK_PATH_CHARS];
    wchar_t trackPath[MIDI_TRACK_PATH_CHARS];

    if (g_pConfig->m_midiEnabled == 0) {
        return;
    }
    if (m_playbackEnabled == 0) {
        return;
    }
    if (trackId > MIDI_TRACK_MAX) {
        return;
    }
    if (trackId == m_selectedTrackId) {
        return;
    }

    m_selectedTrackId = MIDI_TRACK_NONE;
    MidiPlayer_ResetStream(0);
    m_selectedTrackId = trackId;

    ConfigGetStringPreference(g_pConfig, (unsigned char)trackId, configuredName, MIDI_TRACK_PATH_CHARS);
    if (configuredName[0] != 0) {
        swprintf(trackPath, L"Midi\\%s", configuredName);
        g_midiAllowEndReplay = 0;
        StartSelectedMidiFile(trackPath);
    }

    if (g_midiStreamRunning == 0) {
        ConfigSetStringPreference(g_pConfig, (unsigned char)trackId, L"");
        swprintf(configuredName, L"%d.mid", trackId);
        g_midiAllowEndReplay = 1;
        StartSelectedMidiFile(configuredName);
    }
}
```

Implementation notes for this C++:

- `ConfigGetStringPreference` and `ConfigSetStringPreference` are source-facing stand-ins for `0x0048eaa0` and `0x0048eb00`; exact member/static syntax can be adjusted when Config helper docs are updated.
- `g_midiAllowEndReplay` names `0x0069b510`; if implementation validation proves the selector writes are path-mode rather than fill replay mode, rename to `g_midiFillMode` rather than reverting to raw/generated names.
- `MidiPlayer_ResetStream`, `MidiStreamOpenAndPrimeBuffers`, and `ApplyMidiVolume` need shared private declarations in `MidiPlayer.cpp` support docs so this target body can compile without embedding out-of-range function bodies.
- Keep raw names `sub_526100` and `sub_526240` only in evidence/history lines.

## Required Support-Doc Updates

### `by-class/MidiPlayer.md`

Recommended exact changes:

- Change field row `0x08` from "`m_selectedTrackId` or device/track sentinel" to:

```text
| `0x08` | `m_selectedTrackId` | Selected MIDI track id; constructor, disable, and stop store `-1`, while `SelectTrack(unsigned short trackId)` compares against the requested id and stores valid ids `0..12`. This is not the WinMM device id; `puDeviceID`/`g_midiDeviceId` is the global device storage. |
```

- Update method inventory rows:

```text
| `SelectTrack` | `0x00526100-0x00526233` | Class method. Selects a requested MIDI track, resets current playback state, resolves configured `Midi\\%s` and fallback `%d.mid` paths through Config string preferences, and starts playback through `StartSelectedMidiFile`. |
| `StartSelectedMidiFile` | `0x00526240-0x00526332` | Private file helper, not a class method. Copies the selected path into `g_midiCurrentPath`, resets/open/primes/restarts the WinMM stream, updates global running/restart state, and reapplies MIDI volume. |
```

- Change touched-state row for `g_pConfig + 2124` to `g_pConfig + 0x84c` / `Config::m_midiEnabled`, noting `int_convert.py` verified `2124 == 0x84c`.
- Remove `0x00526100` and `0x00526240` from the open class-method-versus-file-scope question. Keep that question only for unresolved helpers such as callback/open/document release if still desired.
- Add note that generated `m_selectedDeviceId` is rejected.

Recommended score after support edit: `COMPLETION:87`, `CONFIDENCE:90`.

### `by-file/MidiPlayer.md`

Recommended exact changes:

- In Proposed Contents, replace "track selection/start helpers" description with:

```text
| `MidiPlayer::SelectTrack` / `StartSelectedMidiFile` | [UID:0001CH] | `0x00526100-0x00526332` | Class method plus private helper that select configured/fallback MIDI track paths, reset active stream state, open/prime/restart WinMM MIDI playback, and reapply volume. First-draft source C++ is ready under [UID:0001CH]. |
```

- Add private helper declaration guidance:

```text
Private helper names accepted for draft source: `MidiStreamOpenAndPrimeBuffers`, `StartSelectedMidiFile`, `MidiPlayer_ResetStream` or `ResetMidiStream`, and `ApplyMidiVolume`. `SelectTrack` is a `MidiPlayer` method; `StartSelectedMidiFile` is file-static.
```

- Update generated-output caveat: `auto-generated/NexusTK/audio/MidiPlayer.cpp` is no longer empty; it currently emits parser/scratch helpers and has an empty marker for [UID:0001CH] pending implementation.

Recommended score after support edit: current `87/89` can remain, or raise to `88/89` if the first-draft code is accepted.

### `by-global/MidiPlayerWinMMState.md`

Recommended name-map additions/adjustments:

```text
| `dword_69B510` / `DAT_0069B510` | `g_midiAllowEndReplay` or `g_midiFillReplayMode` | SelectTrack sets this before configured/fallback starts, and open/callback paths pass it into the stream-fill helper. Existing docs called it a fill budget/limit; B001's fill-helper signature supports an end-replay/fill-mode role. Prefer this over generated `g_midiUseLooseFile` until live decompile confirms exact semantics. |
| `Destination` | `g_midiCurrentPath` | Copied by `StartSelectedMidiFile` and opened by `MidiStreamOpenAndPrimeBuffers`; reject generated `g_midiSelectedPath` as a lower-quality alias. |
```

- Keep `g_midiDocumentLoaded`, `g_midiStreamRunning`, `g_midiRestartPending`, `g_midiStreamState`, and `g_midiVolumeScale` as preferred names.
- Add a note that generated `g_midiStreamOpen` is a rejected alias for `g_midiDocumentLoaded`.

Recommended score after support edit: `COMPLETION:88`, `CONFIDENCE:90`.

### `by-memory/0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals.md`

Recommended touched-state update:

```text
| `0x0069b510` | `dword_69B510` | SelectTrack writes configured/fallback fill mode and open/callback pass it to `MidiFillStreamBuffer`; recommended descriptive name `g_midiAllowEndReplay` / `g_midiFillReplayMode`, pending live decompile confirmation. |
```

### `by-memory/0x00525920-0x00525b0d.MidiStreamOpenAndPrimeBuffers.md`

Recommended update:

- Rename touched-state row `0x0069b510` from "Fill budget/limit" to:

```text
| `0x0069b510` | Fill replay/mode flag passed to `MidiFillStreamBuffer`; [UID:0001CH] writes it before configured/fallback starts. Recommended descriptive name `g_midiAllowEndReplay` or `g_midiFillReplayMode`. |
```

- Add caller-name update: `0x00526271` caller is `StartSelectedMidiFile`.
- Prefer helper name `MidiStreamOpenAndPrimeBuffers` or `OpenAndPrimeMidiStream`; do not use raw `sub_525920` in new source snippets.

### `by-memory/0x00525be0-0x00525dbb.MidiStreamCallback.md`

Recommended update:

- Rename touched-state row `0x0069b510` consistently with `g_midiAllowEndReplay` / `g_midiFillReplayMode`.
- Note that `StartSelectedMidiFile` is the target that prepares the current path and triggers stream restart before callback refill paths observe the running state.

### `by-memory/0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers.md`

Recommended update:

- Replace the [UID:0001CH] inventory row with:

```text
| `0x00526100-0x00526332` | [UID:0001CH][0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers](by-memory/0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers.md) | Exact child now ready to emit `MidiPlayer::SelectTrack` and `StartSelectedMidiFile`; this aggregate should remain an inventory/parent and must not duplicate the child code. |
```

- Update raw helper caveat to say `0x00526100` and `0x00526240` are no longer omitted due to class/file-scope uncertainty.

### `by-memory/0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers.md`

Recommended updates:

- Replace raw caller references to `sub_526100` with `MidiPlayer::SelectTrack`.
- Add source-facing names:

```text
`0x0048eaa0`: `ConfigGetStringPreference` / `Config::GetStringPreference`.
`0x0048eb00`: `ConfigSetStringPreference` / `Config::SetStringPreference`.
```

- For the MIDI setter call, record current best inference: `SelectTrack` clears/updates the selector before `%d.mid` fallback; validate exact source argument with live decompile before finalizing Config helper C++.

### `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`

Recommended Known Field Cluster addition:

```text
| `+0x84c` | MIDI/music enable byte used by `MidiPlayer::EnableMidiPlayback`, `DisableMidiPlayback`, and `SelectTrack`; `int_convert.py` verifies this is decimal `2124` in older notes. Use descriptive name `m_midiEnabled` or `m_musicEnabled` until final Config field spelling is recovered. |
```

Prefer `m_midiEnabled` in `MidiPlayer` code to avoid confusion with the later `+0x291908..+0x291914` music-control/Redbook/SoundManager cluster.

### `by-memory/0x00512f20-0x00513305.MapPaneHandleAnimationSoundPacket.md`

Recommended update:

Replace:

```text
Calls audio helper routes `sub_526100` and `sub_526340`.
```

with:

```text
Calls MIDI helper routes `MidiPlayer::SelectTrack` (`0x00526100`) and `MidiPlayer::StopPlayback` (`0x00526340`) through the global MIDI player; MapPane remains a consumer of MIDI playback control.
```

This also removes `sub_526100` and `sub_526340` raw-name hits from the unresolved list after validator refresh.

### `by-memory/0x0061fafc-0x0061fb74.MidiPlayerReadOnlyData.md`

Recommended update:

- Name local literals descriptively:

```text
`L"Midi\\%s"`: configured MIDI track resource/path format used by `MidiPlayer::SelectTrack`.
`L"%d.mid"`: fallback track filename format used by `MidiPlayer::SelectTrack`.
```

- Keep final C++ blank for vtable/string-data page; literals should emit through [UID:0001CH] or the surrounding `MidiPlayer.cpp` implementation, not as standalone data.

### `project-level/-unresolved.md`

No manual edit recommended. After support docs are updated and validator refreshes unresolved references, `sub_526100` and `sub_526240` should remain only in historical Evidence lines if at all.

## Exact Pending Coverage Text

Do not edit `by-memory/-coverage-report.md` in the B-agent pass. Supervisor can replace the current [UID:0001CH] row with this exact row:

```text
    - [UID:0001CH][0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers](by-memory/0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers.md) 0x00526100-0x00526332 | helper pair | MidiPlayerTrackSelectionHelpers : reconstructable : 88% : strong : Source-quality pass resolves the pair as `MidiPlayer::SelectTrack(unsigned short)` plus private `StartSelectedMidiFile(const wchar_t *)` in `NexusTK/audio/MidiPlayer.cpp`; exact IDA-backed ranges and caller set remain `0x00526100-0x00526233` from MapPane packet handler `0x00512fb2`, internal start calls at `0x005261c8`/`0x0052621c`, and `0x00526240-0x00526332` with only select-helper callers. Behavior covers config MIDI flag `g_pConfig+0x84c`, `m_playbackEnabled`, `m_selectedTrackId`, max track id `12`, Config selector string lookup/setter, `Midi\\%s` configured path and `%d.mid` fallback, selected path copy to `g_midiCurrentPath`, stream reset/open/restart, running/restart flags, `g_midiAllowEndReplay`/fill-mode state, volume reapply, and trailing `0xcc` padding; first-draft C++ should now be populated while original symbol spellings remain inferred.
```

## Validator / Implementation Needs

Before implementation callback, run or obtain live IDA checks if the IDA MCP connector is available:

```text
lookup_funcs 0x00526100 0x00526240 0x00526340 0x00525920 0x00525ff0 0x00526460
callers 0x00526100
callers 0x00526240
decompile 0x00526100
decompile 0x00526240
xrefs_to 0x0069b510
xrefs_to 0x0069b514
xrefs_to 0x0069b518
xrefs_to 0x0061fb38
xrefs_to 0x0061fb48
get_bytes 0x00526332 size 14
```

Specific validation questions:

- Confirm `0x00526240` has no `this` access and is stack-argument/file-static helper.
- Confirm `0x00526100` parameter width and compare/store width for `m_selectedTrackId`; current best is `unsigned short`.
- Confirm the `0x0048eb00` setter argument in the fallback path; current best is clearing the failed configured selector before `%d.mid` fallback.
- Confirm `0x0069b510` role and final name. Current best is `g_midiAllowEndReplay` / `g_midiFillReplayMode`, not generated `g_midiUseLooseFile`.
- Confirm exact string formatting API (`swprintf`, `wsprintfW`, or secure CRT variant) before final code grading.

After implementation callback, recommended validator commands from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0001CH-MidiPlayerTrackSelectionHelpers-source-quality-removed.md](0001CH-MidiPlayerTrackSelectionHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Also regenerate/check `auto-generated/NexusTK/audio/MidiPlayer.cpp` and verify [UID:0001CH] is no longer an empty emitter marker.

## Open Questions That Remain Score Caps, Not Blockers

- Exact original spellings for Config selector helpers and `Config::m_midiEnabled`.
- Exact original spelling for `0x0069b510`. Recommended descriptive name is `g_midiAllowEndReplay` or `g_midiFillReplayMode`; this should be validated, but it does not block first-draft target C++.
- Whether `MidiPlayer_ResetStream` should be source-cleaned to `ResetMidiStream`. The existing saved label is safe for first draft; source cleanup can be done across all MidiPlayer helper docs together.
- Exact CRT format call. The first draft uses `swprintf` to express behavior; implementation should match the decompiled call/import form.

No passive blocker remains for [UID:0001CH]. The target has enough evidence to populate source-style C++ with inferred descriptive names and to update support docs away from compiler/generated names.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/0001CH-MidiPlayerTrackSelectionHelpers-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:31","uid":"0001CH"} -->
<!-- {"agent":"B006","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001CH-MidiPlayerTrackSelectionHelpers-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B006/0001CH-MidiPlayerTrackSelectionHelpers-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001CH"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
