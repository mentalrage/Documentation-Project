** TARGET-REPORT-UID:00041I **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 00041I MidiApplySingleChannelVolumeRaw Source-Quality Report

Assignment: `B001-report-00041I-MidiApplySingleChannelVolumeRaw-by-memory-20260701`

Mode: implementation callback completed for the accepted report. B001 edited only the accepted target by-memory page and this report ledger; no generated files, project-level generated reports, coverage reports, validator/tool state, ledgers, queues, archives, lock files, or IDA DB were manually edited.

## Finalized Report / Current Recommendation

- Current recommendation: accepted and implemented. [UID:00041I] remains a reconstructable, emitting, file-static `MidiPlayer.cpp` helper named `SendMidiChannelVolume`; the target page now carries current-session MCP evidence, instruction-level behavior, no-route proof, generated-output freshness, and score rationale.
- Final disposition: no split, rename, owner change, emitter change, or C++ code change is recommended. The current formal C++ is still the best source-shaped representation of the raw body.
- Required action if accepted: completed. The target by-memory page was updated; support pages were confirmed already sufficient at same-or-greater detail and were not edited.
- Score recommendation: applied, `COMPLETION:85 -> 87`, `CONFIDENCE:86 -> 88`.
- Confidence: strong for behavior, boundaries, owner/emitter, globals/imports, and C++; capped by zero incoming route to the raw start.

## Target

- Target UID: `00041I`
- Target path: `by-memory/0x00525ba0-0x00525bdf.MidiApplySingleChannelVolumeRaw.md`
- Queue row: `auto-generated/-ag-research-tracker.md` -> by-memory Not-Covered Files - Reconstructable, score `85/86`, combined `85.5`, reconstructable `true`, reports `0`.
- Current metadata:
  - `COMPLETION:85`
  - `CONFIDENCE:86`
  - `CANONICAL_OWNER:0000LD`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:0000LD`
  - blank `EMITTER_POSITION_OPTIONAL`
  - formal C++ present

## Current Target State

The target page already documents the right high-level conclusion: `0x00525ba0-0x00525bdf` is a raw, unmodeled `MidiPlayer` local helper that sends one WinMM controller-7 channel-volume message when `g_midiStreamRunning` is nonzero. It already routes through [UID:0000LD] `MidiPlayer` and emits through `auto-generated/NexusTK/audio/MidiPlayer.cpp`.

The current page is score-capped because it records no external xref/pointer route. That cap remains real after current MCP recheck, but the page can safely improve because the report revalidated:

- the current MCP session and IDB state;
- the exact raw instruction body and adjacent padding;
- the lack of modeled function promotion at `0x00525ba0`;
- zero incoming xrefs and zero VA/RVA/raw pointer-pattern hits;
- the WinMM import and MIDI state/global relationships;
- the relation to sibling `ApplyMidiVolume` and callback volume paths;
- generated output freshness and current formal C++ shape.

Related support docs checked:

- `by-file/MidiPlayer.md`
- `by-class/MidiPlayer.md`
- `by-global/MidiPlayerWinMMState.md`
- `by-memory/0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals.md`
- `by-memory/0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers.md`
- `by-memory/0x00525f40-0x0052609a.MidiPlayerRawVolumeAndStreamLocalHelpers.md`
- `by-memory/0x00525be0-0x00525dbb.MidiStreamCallback.md`
- `by-memory/0x00525920-0x00525b0d.MidiStreamOpenAndPrimeBuffers.md`
- `by-memory/0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers.md`

## Evidence Checked

IDA MCP was mandatory and available.

- Endpoint: `http://127.0.0.1:13337/mcp`
- Active database/session: `supervisor_resume_20260629`
- `idb_list`: active adopted worker session for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_analyzing:false`.
- `server_health`: `status:ok`, module `NexusTK.exe`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.

MCP calls used:

- `lookup_funcs` for `0x00525ba0`, `0x00525bdf`, `0x00525be0`, `0x00525ff0`, and `0x00525b10`.
- `insn_query` scoped to `0x00525ba0-0x00525be0`, count `80`, max scan `100`, with disassembly.
- `get_bytes` for `0x00525b98`, `0x00525ba0`, `0x00525bdf`, `0x00525be0`, `0x0061fb60`, and `0x0069b5d0`.
- `xrefs_to` for `0x00525ba0`, `0x00525bdf`, `0x00525ff0`, `0x0069b5d0`, `0x0069b518`, `0x0061fb60`, `0x0069b500`, and `0x0060d4dc`.
- `xref_query` for incoming and outgoing refs on `0x00525ba0`, and incoming refs on `0x00525ff0`.
- `find_bytes` for raw helper pointer patterns `a0 5b 52 00`, `a0 5b 12 00`, and `a0 4f 12 00`.
- `imports_query` for `midiOutShortMsg` and `midiStreamOpen`.
- `analyze_function` for `0x00525ff0` with assembly.

Documentation and generated lead material checked:

- assigned target page and support pages listed above;
- `auto-generated/-ag-research-tracker.md`;
- `auto-generated/-ag-coverage-report-by-memory.md`;
- `auto-generated/NexusTK/audio/MidiPlayer.cpp`, header `validator-command-id: 000000004115`, `validator-refreshed-at: 2026-07-01T17:52:14-04:00`;
- executed B011 report `executed-b-agent-research/B011/0001CF-MidiPlayerAndWinMMHelpers-source-quality.md`;
- executed B013 report `executed-b-agent-research/B013/0000LD-MidiPlayer-empty-emitter-family-source-quality.md`;
- executed B006 track-selection report matches for `g_midiStreamRunning` and `ApplyMidiVolume`;
- stale unrelated B003 `00041I` TextFilter report hits were identified as UID-collision history, not target evidence.

Mandated search terms used before finalizing:

- `00041I`
- `0x00525ba0`
- `0x00525bdf`
- `MidiApplySingleChannelVolumeRaw`
- `SendMidiChannelVolume`
- `MidiPlayer`
- `g_midiStreamRunning`
- `g_midiChannelVolume`
- `midiOutShortMsg`

The search also included generated output and report roots. Relevant current target matches were the target/support docs, B011, B013, and generated `MidiPlayer.cpp`; stale `00041I` matches in B003 TextFilter material were rejected as a UID collision from an unrelated historical target.

## IDA MCP Facts

Function/range facts:

- `lookup_funcs 0x00525ba0`: `Not a function`.
- `lookup_funcs 0x00525bdf`: `Not a function`.
- `lookup_funcs 0x00525be0`: modeled `sub_525BE0`, size `0x1db`, the following WinMM callback.
- `lookup_funcs 0x00525ff0`: modeled `sub_525FF0`, size `0x6a`, the sibling `ApplyMidiVolume` helper.
- `lookup_funcs 0x00525b10`: modeled `sub_525B10`, size `0x88`, the preceding release-buffer helper.

Instruction facts for `0x00525ba0-0x00525bdf`:

| Address | Instruction | Source meaning |
| --- | --- | --- |
| `0x00525ba0` | `push ebp` | raw helper prologue |
| `0x00525ba1` | `mov ebp, esp` | stack frame |
| `0x00525ba3` | `cmp dword ptr unk_69B518, 0` | test `g_midiStreamRunning` |
| `0x00525baa` | `jz short loc_525BDE` | return without sending when stream is not running |
| `0x00525bad` | `mov esi, [ebp+8]` | load `channel` argument |
| `0x00525bb0` | `mov eax, 10624DD3h` | reciprocal multiply constant used by compiler for division by 1000 |
| `0x00525bb5` | `mov ecx, dword ptr unk_69B5D0[esi*4]` | read `g_midiChannelVolume[channel]` |
| `0x00525bbc` | `imul ecx, [ebp+0Ch]` | multiply by `volumeScale` argument |
| `0x00525bc0-0x00525bc2` | `mul ecx`; `shr edx, 6` | scale product by `/ 1000` |
| `0x00525bc5` | `shl edx, 10h` | move scaled value into MIDI data-byte position |
| `0x00525bc8` | `or edx, esi` | preserve channel nibble |
| `0x00525bca` | `or edx, 7B0h` | add control-change status and controller-7 byte |
| `0x00525bd1` | `push dword ptr ds:69B500h` | pass `g_hMidiStream` as `HMIDIOUT` |
| `0x00525bd7` | `call ds:midiOutShortMsg` | send WinMM short message |
| `0x00525bdf` | `retn` | raw cdecl-like return |

Byte/boundary facts:

- `get_bytes 0x00525b98 size 8`: eight `0xcc` bytes before the helper start.
- `get_bytes 0x00525ba0 size 64`: complete 64-byte body ending in `5e 5d c3`.
- `get_bytes 0x00525bdf size 1`: `0xc3`.
- `get_bytes 0x00525be0 size 8`: next modeled callback begins with `55 8b ec ...`.
- Therefore the helper body is exactly `0x00525ba0-0x00525bdf`, followed by no padding byte before the callback start at `0x00525be0`; the preceding padding is `0x00525b98-0x00525ba0`.

Xref and route facts:

- `xrefs_to 0x00525ba0`: zero incoming cross-references.
- `xref_query 0x00525ba0 direction=to`: total `0`, no cross-references.
- `find_bytes` found zero matches for VA pointer pattern `a0 5b 52 00`, image-RVA pattern `a0 5b 12 00`, and raw-offset-style pattern `a0 4f 12 00`.
- `xrefs_to 0x00525bdf` returns only the fallthrough code xref from `0x00525bde`, not an external route.
- In contrast, `xrefs_to 0x00525ff0` returns five code refs to the modeled `ApplyMidiVolume`: raw volume-up/down sites at `0x526076` and `0x526094`, plus three refs from modeled `sub_526240` / `StartSelectedMidiFile` at `0x5262b9`, `0x52630c`, and `0x526328`.

Global/import facts:

- `imports_query midiOutShortMsg`: import at `0x60d4dc`, module `WINMM`.
- `xrefs_to 0x0060d4dc`: call/data refs at `0x525bd7` in this raw helper, `0x525c67` in `MidiStreamCallback`, and `0x526040`/`0x525ffe` in `ApplyMidiVolume`.
- `xrefs_to 0x0069b5d0`: five refs including `0x5259c8` stream-open default copy, `0x525bb5` this raw helper, `0x525c27`/`0x525c3d` callback update/forward path, and `0x526010` `ApplyMidiVolume`.
- `xrefs_to 0x0069b518`: fourteen refs including `0x525ba3` this raw helper, callback refs, constructor/track-selection/reset refs, and `0x525ff3` `ApplyMidiVolume`.
- `get_bytes 0x0061fb60 size 32`: first four DWORDs are `0x64`, `0x64`, `0x64`, `0x64`, matching documented default channel volume values copied into `0x0069b5d0`.
- `get_bytes 0x0069b5d0 size 64`: current IDB data bytes are zero at the writable channel-volume table; the runtime open helper initializes the table from the read-only defaults.

Constant verification:

- `0x3e8` is decimal `1000` (Verified with `tools/int_convert.py`).
- `0x7b0` is decimal `1968`, bytes `b0 07`, representing controller-change status `0xb0` plus controller `7 << 8` (Verified with `tools/int_convert.py`).
- `0x10` is decimal `16` (Verified with `tools/int_convert.py`).
- `0xb0` is decimal `176` with `--size 2` (Verified with `tools/int_convert.py`).
- `0x07` is decimal `7` (Verified with `tools/int_convert.py`).

## Positive Evidence Summary

- The body is source-shaped code, not padding: it has a standard prologue, stack arguments, meaningful global reads, a WinMM import call, and a normal return.
- The exact behavior is narrow and fully understood: guard on `g_midiStreamRunning`, read a channel index and scale argument, compute `g_midiChannelVolume[channel] * volumeScale / 1000`, build a controller-7 short message, and send it through `midiOutShortMsg`.
- The owner/emitter route is strong. The helper touches only the same WinMM MIDI state documented under [UID:0000T9] and sits between exact `MidiPlayer.cpp` helper siblings in [UID:0001CF].
- The helper name `SendMidiChannelVolume` is defensible source-facing reconstruction: the body sends one MIDI channel-volume controller message; sibling `ApplyMidiVolume` sends the same message shape across all sixteen channels.
- Current generated output already emits exactly this helper in `auto-generated/NexusTK/audio/MidiPlayer.cpp`, and the generated file is current relative to validator command `000000004115`.

## Negative Evidence Summary

- IDA still does not model `0x00525ba0` as a function.
- No incoming code or data xref to `0x00525ba0` exists in the current IDB.
- No VA/RVA/raw pointer byte pattern for the helper start was found.
- There is no callback table, vtable, exported symbol, direct caller, generated route, or sibling decompile route that proves source reachability.
- The raw helper should therefore not be upgraded to near-final confidence or used to infer a public API. It remains a private file-static helper with a no-route confidence cap.

## Heuristic / Inference Reanalysis And Validation

The main source-quality question is whether `SendMidiChannelVolume` is too speculative because the raw start has no route. Current evidence supports keeping the function and C++, but preserving the no-route caveat.

Validated inferences:

- `channel`: direct stack argument from `[ebp+8]`, used as `g_midiChannelVolume[channel]` and ORed into the low MIDI status nibble. This is source-shaped and should remain the first parameter.
- `volumeScale`: direct stack argument from `[ebp+0Ch]`, multiplied by per-channel volume before the `/ 1000` scale. This is source-shaped and should remain the second parameter.
- `g_midiStreamRunning`: accepted support name for `0x0069b518`; current xrefs include this helper, callback, constructor, track-selection, raw stream-control, and reset paths.
- `g_midiChannelVolume`: accepted support name for the table at `0x0069b5d0`; current xrefs show initialization by stream-open, update/forwarding by callback, this single-channel helper, and all-channel application by `ApplyMidiVolume`.
- `g_hMidiStream`: accepted support name for `0x0069b500`; current xrefs show this helper uses the same WinMM handle as stream open, callback, reset, close, and all-channel volume logic.
- `MIDI_STATUS_CONTROL_CHANGE` and `MIDI_CONTROLLER_VOLUME`: the raw immediate `0x7b0` is the packed source expression `0xb0 | (7 << 8)`, and `int_convert.py` verifies the constants.

Rejected alternatives:

- `MidiPlayer` class method: rejected. The helper has no `this` access and uses only globals and stack arguments, so file-static helper form is more plausible.
- `SoundManager` owner: rejected. The helper uses WinMM MIDI stream state, not Miles/MP3/WAV/Redbook state.
- Callback-only helper owned by `MidiStreamCallback`: rejected as direct ownership. The callback also uses the same message shape, but this helper is separately bounded before the callback and should remain a sibling private helper in `MidiPlayer.cpp`.
- New source file or `MidiSMFDocument.cpp`: rejected. The helper is not SMF parser/document logic and has no evidence outside the `MidiPlayer` WinMM helper island.
- Padding/dead code: rejected for behavior/source-family documentation because the body is meaningful, bounded, and uses live state/imports; retained as no-route raw because reachability is not proven.

No Wave2/Wave3 evidence was used as authority. Generated C++ was used only as read-only lead/freshness material and checked against current MCP.

## Ranked Ownership Analysis

### 1. [UID:0000LD] MidiPlayer / `NexusTK/audio/MidiPlayer.cpp`

- Evidence for: exact adjacency to release-buffer and callback/helper island; reads `g_midiStreamRunning`, `g_midiChannelVolume`, and `g_hMidiStream`; calls WinMM `midiOutShortMsg`; support docs already route the whole WinMM MIDI family through `MidiPlayer.cpp`; generated output currently emits the helper there.
- Evidence against: no recovered original filename or symbol for this specific raw helper, and no incoming route to the helper start.
- Decision: keep as canonical owner and emitter.

### 2. [UID:0000T9] MidiPlayerWinMMState

- Evidence for: the helper is mostly global-state manipulation and uses state documented under this global owner.
- Evidence against: this page is a state-family documentation owner, not the direct source owner of file-static helper code.
- Decision: keep as support/cross-reference only, not canonical owner.

### 3. [UID:00008A] MidiPlayer class

- Evidence for: same source family as class methods and volume controls.
- Evidence against: no `this` pointer, vtable, object field, or class-method caller evidence in this raw body.
- Decision: reject direct class ownership; file-static helper is more source-shaped.

### 4. [UID:0000NV]/[UID:0000DG] SoundManager

- Evidence for: broad audio subsystem relation only.
- Evidence against: SoundManager owns Miles/MP3/WAV/Redbook paths, while this target is WinMM MIDI stream code and uses `MidiPlayer` state.
- Decision: reject.

## Source Placement

Recommended placement remains private file-scope helper code in `NexusTK/audio/MidiPlayer.cpp`, routed by [UID:0000LD]. The current C++ form:

- avoids IDA/decompiler labels;
- uses accepted support names for global state and MIDI constants;
- keeps `SendMidiChannelVolume` file-static rather than public/class method;
- matches the nearby `ApplyMidiVolume` helper shape while preserving the target's exact one-channel behavior.

No by-file/source-tree change is recommended.

## Range / Split / Padding / Reclassification Analysis

- `0x00525b98-0x00525ba0`: eight bytes of `0xcc` padding after [UID:00041H] `ReleaseMidiStreamBuffers`.
- `0x00525ba0-0x00525bdf`: exact source-authored raw helper body.
- `0x00525bdf`: `retn` byte is the last byte of the helper.
- `0x00525be0`: next modeled function [UID:0001CG] `MidiStreamCallback` begins immediately.

No split, merge, reclassification, or new child page is recommended. The current target range is already exact.

## First-Draft C++ Recommendation

Eligible for C++: yes. The target is reconstructable, has a confirmed owner/emitter route through [UID:0000LD], and already exceeds the current combined-score/emitter gate.

Recommended code: keep the current formal `RECONSTRUCTION_CPP CODE` unchanged:

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

Reason it preserves behavior:

- The stream-running guard matches `cmp [0x0069b518],0` / `jz`.
- `channel` comes from `[ebp+8]`.
- `volumeScale` comes from `[ebp+0Ch]`.
- The compiler's reciprocal multiply sequence implements `/ 1000`; `0x3e8` is `1000` (Verified with `tools/int_convert.py`).
- The packed message expression represents `0xb0 | channel | (7 << 8) | (scaled << 16)`, matching the `or edx, esi` and `or edx, 0x7b0` instructions.
- The helper intentionally ignores the return value from `midiOutShortMsg`, unlike `ApplyMidiVolume`, and the current C++ preserves that.

Reason no code change is recommended:

- Replacing the constants with raw `0x7b0` would be less source-shaped.
- Adding return-value handling would contradict this target's raw body.
- Making it a class method would invent a `this` relationship not present in the instructions.
- Renaming it to an `Apply*` name would conflate this one-channel send with sibling `ApplyMidiVolume`, which loops over sixteen channels and updates `g_midiVolumeScale`.

## Score And Metadata Recommendation

Current metadata:

- `COMPLETION:85`
- `CONFIDENCE:86`
- `CANONICAL_OWNER:0000LD`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000LD`
- formal C++ populated

Recommended metadata:

- `COMPLETION:87`
- `CONFIDENCE:88`
- keep `CANONICAL_OWNER:0000LD`
- keep `RECONSTRUCTABLE:TRUE`
- keep `EMITTER_UIDS:0000LD`
- keep blank `EMITTER_POSITION_OPTIONAL`
- keep formal C++ unchanged

Score rationale:

- Completion can rise because the target can now record current-session MCP proof for the exact raw instructions, byte boundaries, constants, imports, global xrefs, generated freshness, sibling comparison, and support-doc disposition.
- Confidence can rise because current MCP independently confirms the B011 facts in the active session and verifies no contrary route/owner/code evidence.
- Scores should not go above `87/88` because the raw start still has zero xrefs and zero pointer-pattern hits. The helper is source-shaped and appropriate to emit, but original reachability and symbol spelling remain inferred.

This is not a no-improvement exception: the target page can improve materially even though owner/emitter/C++ stay unchanged.

## Open Questions With Attempted Resolution

- Open question: where is the route to `0x00525ba0`?
  - Evidence checked: `xrefs_to`, `xref_query`, VA/RVA/raw `find_bytes`, adjacent modeled function lookup, generated output, B011/B013 reports, and support docs.
  - Resolution: no route was found. This remains the hard confidence cap.
- Open question: could `SendMidiChannelVolume` be a callback-only inline or artifact?
  - Evidence checked: byte boundaries, callback start at `0x00525be0`, callback volume path docs, import/global xrefs.
  - Resolution: it is a separate bounded helper before the callback; no evidence supports merging it into callback output.
- Open question: should target C++ change?
  - Evidence checked: raw instructions, `ApplyMidiVolume` decompile/assembly, constants, generated output.
  - Resolution: no. The current formal C++ is source-shaped and behavior-preserving.

## Recommended Target Doc Changes

Target path: `by-memory/0x00525ba0-0x00525bdf.MidiApplySingleChannelVolumeRaw.md`

Recommended target edits if accepted:

- Update metadata to `COMPLETION:87`, `CONFIDENCE:88`.
- Keep `CANONICAL_OWNER:0000LD`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000LD`, blank emitter position, and the current C++ block unchanged.
- Expand `Item Summary`/status to mention current MCP session `supervisor_resume_20260629`, exact raw no-function state, one-channel controller-7 send behavior, same state/import family as callback and `ApplyMidiVolume`, and no-route cap.
- Add instruction-level behavior table from `0x00525ba0` through `0x00525bdf`.
- Add boundary/padding facts: eight `0xcc` bytes before the helper and next callback start at `0x00525be0`.
- Add no-route proof: zero xrefs to `0x00525ba0`, zero VA/RVA/raw pointer pattern matches, and only fallthrough xref to `0x00525bdf`.
- Add source-placement reasoning: file-static helper in `MidiPlayer.cpp`, not a class method, not SoundManager, not SMF document/parser code.
- Add first-draft C++ disposition: current formal code stays unchanged.
- Add score rationale and reason not higher.
- Add stale report-search note: B003 TextFilter `00041I` hits are stale UID-collision material and not evidence for this target.

## Recommended Support Doc Changes

No support by-* doc edit is required for this pass.

Already-present support facts:

- `by-file/MidiPlayer.md` already lists [UID:00041I] as `SendMidiChannelVolume`, a raw no-route local helper under `MidiPlayer.cpp`.
- `by-class/MidiPlayer.md` already lists [UID:00041I] under related free helpers and does not make it a class method.
- `by-global/MidiPlayerWinMMState.md` already records this helper under volume/channel-output behavior.
- `by-memory/0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals.md` already includes [UID:00041I], `0x0069b518`, `0x0069b5d0`, and the helper-family boundary.
- `by-memory/0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers.md` already records this exact child range, padding, raw no-route disposition, owner/emitter route, and source-facing name.
- `by-memory/0x00525f40-0x0052609a.MidiPlayerRawVolumeAndStreamLocalHelpers.md` already records sibling `ApplyMidiVolume` behavior and its intentional distinction from this one-channel helper.
- `by-memory/0x00525be0-0x00525dbb.MidiStreamCallback.md` already links to [UID:00041I] and documents the callback's separate controller-volume path.

If the supervisor wants support sync despite already-present coverage, the only safe optional support edit would be a short current-session note in `by-memory/0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers.md` saying B001 revalidated [UID:00041I]'s no-route proof in MCP session `supervisor_resume_20260629`. It is not required for Rule 26 preservation because the support doc already contains same-or-better facts.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | `0x00525ba0-0x00525bdf` is an exact raw helper body, not an IDA-modeled function. | High | MCP `lookup_funcs`, `insn_query`, `get_bytes`. | target Status / Evidence | incorporate | applied: target `Status`, `Behavior`, and `Evidence` now record current MCP session, no-function lookup, exact instruction table, bytes, and range. |
| C02 | The helper tests `g_midiStreamRunning` and returns without sending when zero. | High | `cmp unk_69B518,0`; xrefs to `0x0069b518`. | target Behavior | incorporate | applied: target instruction table and behavior prose record `0x00525ba3`/`0x00525baa` stream-running guard. |
| C03 | The first argument is `channel` and indexes `g_midiChannelVolume[channel]`. | High | `mov esi,[ebp+8]`; `unk_69B5D0[esi*4]`; xrefs to `0x0069b5d0`. | target Behavior / C++ disposition | incorporate | applied: target instruction table and unchanged formal C++ disposition document `channel` from `[ebp+8]` and table read at `0x00525bb5`. |
| C04 | The second argument is `volumeScale`; the helper computes per-channel volume times scale divided by 1000. | High | `imul ecx,[ebp+0Ch]`; reciprocal multiply; `0x3e8` conversion. | target Behavior / C++ disposition | incorporate | applied: target instruction table and constant-verification paragraph record `[ebp+0Ch]`, reciprocal multiply, and `/ 1000`. |
| C05 | The helper builds a controller-7 control-change MIDI short message and calls `midiOutShortMsg`. | High | `or edx,esi`; `or edx,7B0h`; import xrefs; constant conversions. | target Behavior | incorporate | applied: target behavior/evidence record `0x7b0`, `midiOutShortMsg`, WinMM import xrefs, and verified constants. |
| C06 | There is no current route to `0x00525ba0`. | High | `xrefs_to` zero, `xref_query` zero, `find_bytes` zero for VA/RVA/raw pointer forms. | target No-Route Proof / Score Rationale | incorporate | applied: target `No-Route Proof` and `Score Rationale` record zero xrefs, zero pointer-pattern hits, and retained confidence cap. |
| C07 | The correct owner/emitter remains [UID:0000LD] `MidiPlayer`. | High | support docs, WinMM imports, state family, adjacency, generated output. | target Source Placement / metadata | incorporate | applied: target metadata unchanged for owner/emitter; `Source Placement And Naming` preserves [UID:0000LD] and rejects alternatives. |
| C08 | `SendMidiChannelVolume` should remain a private file-static helper, not a `MidiPlayer` method. | High | no `this` access; stack args and globals only. | target Source Placement / C++ disposition | incorporate | applied: target `Source Placement And Naming` rejects class-method placement and preserves file-static helper wording. |
| C09 | The current formal C++ is behavior-preserving and should not change. | High | instruction mapping and sibling comparison to `ApplyMidiVolume`. | target C++ block / First-Draft C++ section | already-present | already-present: formal C++ block was intentionally left unchanged; target now adds rationale that it preserves one-channel behavior and ignores return value as in raw body. |
| C10 | Completion/confidence should rise modestly to `87/88`, but not higher due no-route cap. | Medium-high | current MCP revalidation plus negative route proof. | target metadata / Score Rationale | incorporate | applied: target metadata is `COMPLETION:87`, `CONFIDENCE:88`, and score rationale records reason not higher. Validator command `000000004119` confirmed completion/confidence updates. |
| C11 | Support docs already contain the required owner/global/aggregate facts. | High | by-file/by-class/by-global/by-memory support review. | support docs | already-present | already-present: support docs were reviewed before implementation and not edited; target cross-references still point at the already-sufficient support docs. |
| C12 | B003 TextFilter `00041I` report hits are stale UID-collision history and must not be used as evidence. | High | report search paths and unrelated target/range. | target Historical / Evidence Checked | incorporate | applied: target `Historical / Stale Search Note` records stale B003 TextFilter UID-collision rejection. |

## Validator Results

Implementation callback validator, run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [00041I-MidiApplySingleChannelVolumeRaw-by-memory-source-quality-removed.md](00041I-MidiApplySingleChannelVolumeRaw-by-memory-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Result: exit `0`, `ok: 1`.
- `command_id: 000000004119`
- `command_timestamp: 2026-07-01T18:04:01-04:00`
- Metadata updates: `completion_update 00041I ... 87`, `confidence_update 00041I ... 88`.
- Other validator-reported side effects: `projected_stats_update: 1`, `reference_index_add: 1` for `00041K`, `stats_rescore_recommended: 1`, and four projected stats row removals for [UID:00041I].
- Generated refresh: validator reported `generated_refresh: deferred`, `generated_refresh_command_id: 000000004119`, `generated_refresh_timestamp: 2026-07-01T18:04:01-04:00`.

Generated freshness inspection:

- Read-only inspection of `auto-generated/NexusTK/audio/MidiPlayer.cpp` after validation first showed header `validator-command-id: 000000004119`, `validator-refreshed-at: 2026-07-01T18:04:01-04:00`, `validator-refresh-source: deferred-generated-refresh`.
- Final sanity inspection showed the generated header advanced to `validator-command-id: 000000004126`, `validator-refreshed-at: 2026-07-01T18:06:01-04:00`, which is newer than the target validator command and therefore current for this implementation.
- The generated UID00041I comment is updated to `Completion:87 | Confidence:88`.
- The generated `SendMidiChannelVolume` body remains unchanged.
- `python .\tools\validator.py --queue-status` returned command `000000004128`, timestamp `2026-07-01T18:06:40-04:00`; queued jobs `0`, processing jobs `0`, queued generated refresh jobs `0`, processing generated refresh jobs `0`.
- No manual coverage-report or auto-generated file edit was performed.

## Changed Files

Created:

- `tools/leaser/Agents/Agent-B001/research/00041I-MidiApplySingleChannelVolumeRaw-by-memory-source-quality.md`

Modified:

- `by-memory/0x00525ba0-0x00525bdf.MidiApplySingleChannelVolumeRaw.md`
- `tools/leaser/Agents/Agent-B001/research/00041I-MidiApplySingleChannelVolumeRaw-by-memory-source-quality.md`

Report execution:

- leave for supervisor. The supervisor runs `tools/validator.py execute_report ... --apply` only after verification.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: supervisor accepted the report and added an implementation callback to `goal.md`.
- [x] Target doc to update: `by-memory/0x00525ba0-0x00525bdf.MidiApplySingleChannelVolumeRaw.md`. Proof: target page updated during callback.
- [x] Support docs to update: none required; same-or-greater support facts are already present in `by-file/MidiPlayer.md`, `by-class/MidiPlayer.md`, `by-global/MidiPlayerWinMMState.md`, `by-memory/0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals.md`, `by-memory/0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers.md`, `by-memory/0x00525f40-0x0052609a.MidiPlayerRawVolumeAndStreamLocalHelpers.md`, and `by-memory/0x00525be0-0x00525dbb.MidiStreamCallback.md`; no support edits were made.
- [x] Current target state and actual evidence checked recorded, including MCP session `supervisor_resume_20260629`. Proof: target page now records the current MCP basis and report retains evidence list.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim. Proof: C01-C12 now show `applied` or `already-present`.
- [x] Metadata/score change applied: `COMPLETION:85 -> 87`, `CONFIDENCE:86 -> 88`. Proof: target metadata changed and validator `000000004119` confirmed updates.
- [x] Owner/emitter/reconstructable changes to apply: none; kept `CANONICAL_OWNER:0000LD`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000LD`. Proof: target metadata unchanged for those fields.
- [x] Split/rename/new-child changes to apply: none. Proof: no files created/renamed except this existing report from report phase.
- [x] Source-placement/range/padding facts applied: exact raw helper `0x00525ba0-0x00525bdf`, preceding `0xcc` padding at `0x00525b98-0x00525ba0`, next callback starts `0x00525be0`, file-static `MidiPlayer.cpp` helper. Proof: target `Evidence`, `No-Route Proof`, and `Source Placement And Naming`.
- [x] First-draft C++ disposition applied: kept current `SendMidiChannelVolume` formal C++ unchanged. Proof: target C++ block unchanged and generated file body unchanged.
- [x] Third-party import directive to apply: not applicable. Proof: target is NexusTK-owned source helper, not third-party static embed.
- [x] Exact target facts incorporated at report-level detail: instruction behavior table, no-route proof, global/import xrefs, constant verification, owner/source-placement analysis, support-doc already-present disposition, stale UID-collision rejection. Proof: target sections updated.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: no route, no pointer pattern, not class method, not SoundManager, not callback merge, not SMF document/parser, B003 stale `00041I` UID collision. Proof: target `No-Route Proof`, `Source Placement And Naming`, and `Historical / Stale Search Note`.
- [x] Open questions documented as evidence-backed unresolved: no current route to raw start; this caps confidence and prevents near-final score. Proof: target `No-Route Proof` and `Score Rationale`.
- [x] Validator run after accepted implementation: scoped file validator for target only. Proof: command `000000004119`, exit `0`, `ok: 1`.
- [x] Generated report refresh expected: validator-owned generated by-memory coverage and generated `MidiPlayer.cpp` metadata refresh; no manual generated/coverage edit. Proof: generated `MidiPlayer.cpp` header is newer than target validator command `000000004119` at final command `000000004126`, and UID00041I body remains unchanged.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: callback block in `goal.md`.
- [x] All accepted target doc details incorporated at report-level detail. Proof: target page now includes accepted MCP evidence, behavior table, range/no-route proof, score rationale, stale collision note, and rejected alternatives.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim. Proof: C01-C12 updated above.
- [x] Metadata/score changes applied or explicitly not applied with reason. Proof: scores applied; owner/emitter/reconstructable/C++ intentionally unchanged.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: target page sections updated.
- [x] Open questions documented with evidence-backed unresolved rationale. Proof: no-route cap documented.
- [x] Scoped validator run and result recorded. Proof: validator `000000004119`, timestamp `2026-07-01T18:04:01-04:00`, exit `0`, `ok: 1`.
- [x] Generated refresh completed by validator or freshness state recorded. Proof: generated `MidiPlayer.cpp` header shows newer command `000000004126` and updated UID00041I metadata.
- [x] Remaining unapplied accepted items listed with exact blocker. Proof: none remain; all accepted items are applied, already present, or not applicable.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00041I-MidiApplySingleChannelVolumeRaw-by-memory-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/00041I-MidiApplySingleChannelVolumeRaw-by-memory-source-quality.md","timestamp":"2026-07-01T18:09:00","uid":"00041I"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00041I-MidiApplySingleChannelVolumeRaw-by-memory-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/00041I-MidiApplySingleChannelVolumeRaw-by-memory-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00041I"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
