** TARGET-REPORT-UID:0001CE **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **

# UID0001CE MidiStreamOpenAndPrimeBuffers Source-Quality Report

## Target

- UID: `0001CE`
- Target path: `by-memory/0x00525920-0x00525b0d.MidiStreamOpenAndPrimeBuffers.md`
- Current name: `MidiStreamOpenAndPrimeBuffers`
- Current owner/emitter: [UID:0000LD] `by-file/MidiPlayer.md`
- Current assignment: report-only Medium source-quality pass for `MidiStreamOpenAndPrimeBuffers`; no by-* implementation edits authorized in this pass.

## Current Target State

Current target metadata is `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000LD`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000LD`, blank `EMITTER_POSITION_OPTIONAL`, and an empty formal C++ block.

The target page already records a strong behavior outline: exact `0x00525920-0x00525b0d` range, `0x1ed` byte function size, stream open through `midiStreamOpen`, callback pointer `0x00525be0`, two `0x54` byte MIDI header slots, `0x400` byte backing buffers, parse/load through `0x005270c0`, stream property setup using document time division, two-buffer fill/prepare/submit through `MidiFillStreamBuffer`, cleanup through `MidiDocumentRelease`, and returns `0`, `1`, or `-1`.

The current score blockers are narrower than the existing target text suggests. Behavior, owner, range, callers, and dependency direction are well supported. The remaining blocker is formal C++ readiness: [UID:0002B1] `MidiPlayerWinMMStateGlobals` still has an empty emitter marker and the restored MCP session confirms zero initialized bytes at `0x0069b500`, `0x0069b828`, and `0x0069b870`, while old support text and [UID:0002B2] still contain older `0xffffffff` initializer assumptions. UID0001CE cannot safely instantiate source code that constructs `MidiStreamWriteContext`, `g_midiHeaders`, document globals, and stream state until that shared declaration/initializer conflict is repaired.

Read-only generated state checked in `auto-generated/NexusTK/audio/MidiPlayer.cpp`: header `validator-command-id: 000000004725`, refreshed `2026-07-02T17:01:13-04:00`; UID0002B2 declarations are emitted, while UID0002B1 and UID0001CE remain empty emitter markers. Generated callers already reference `MidiStreamOpenAndPrimeBuffers()` from `StartSelectedMidiFile`, `OpenSelectedMidiFileNoRestart`, and `MidiPlayer_ResetStream`.

## Evidence Checked

IDA MCP evidence was re-run after supervisor restoration. Endpoint `http://127.0.0.1:13337/mcp`, database/session `1f24c222`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. `server_health` reported `status: ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`.

Schema-current MCP calls used:

- `lookup_funcs` for `0x00525920`, `0x00525b0d`, `0x00525be0`, `0x005270c0`, `0x005270e0`, `0x005271b0`, `0x00526240`, `0x00526350`, and `0x00526460`.
- `analyze_function 0x00525920 include_asm:false`.
- `disasm 0x00525920 max_instructions:160 include_total:true`.
- `xrefs_to` for `0x00525920` and `0x00525be0`.
- `decompile` for `0x005270c0`, `0x005270e0`, and `0x005271b0`.
- `get_bytes` for `0x0069b500` size 64, `0x0069b828` size 32, and `0x0069b870` size 32.
- `type_query` for `*Midi*`, `*SMF*`, and `*Track*`, and `search_structs Midi`.
- `xrefs_to` for key state addresses `0x0069b500`, `0x0069b504`, `0x0069b510`, `0x0069b520`, `0x0069b528`, `0x0069b5d0`, `0x0069b610`, `0x0069b614`, `0x0069b828`, and `0x0069b870`.
- `int_convert` for small constants including `0x1ed`, `0x54`, `0x400`, and `0x30000`.

Current docs checked:

- Target `by-memory/0x00525920-0x00525b0d.MidiStreamOpenAndPrimeBuffers.md`.
- `by-file/MidiPlayer.md`.
- `by-class/MidiPlayer.md`.
- `by-global/MidiPlayerWinMMState.md`.
- `by-memory/0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals.md`.
- `by-memory/0x0069b870-0x0069b890.MidiSMFParserScratchGlobals.md`.
- `by-memory/0x005271b0-0x005273a0.MidiStreamBufferFillHelper.md`.
- `auto-generated/NexusTK/audio/MidiPlayer.cpp` as read-only generated lead material.
- `by-structure.md` code-entry and IDA MCP output-discipline sections.

Existing report search terms included `0001CE`, `00525920`, `MidiStreamOpenAndPrimeBuffers`, `OpenAndPrimeMidiStream`, `sub_525920`, and `midiStreamOpen` across `executed-b-agent-research` and `tools/leaser/Agents`. Relevant opened matches:

- `executed-b-agent-research/B006/0001CH-MidiPlayerTrackSelectionHelpers-source-quality.md`: accepted `MidiStreamOpenAndPrimeBuffers`, `g_midiCurrentPath`, `g_midiAllowEndReplay` / `g_midiFillReplayMode`, `g_midiDocumentLoaded`, and `StartSelectedMidiFile` dependency semantics.
- `executed-b-agent-research/B011/0001CF-MidiPlayerAndWinMMHelpers-source-quality.md`: resolved raw caller `OpenSelectedMidiFileNoRestart`, reset caller, and `g_midiCallbackStreamOpen`; preserved UID0001CE as the exact open/prime child.
- `executed-b-agent-research/B012/0002BY-MidiTrackBufferPrimeReset-source-quality.md`: corrected `MidiFillStreamBuffer` replay semantics and confirmed UID0001CE calls the fill helper with reset flag `1` for the first buffer and `0` for later buffers.
- `executed-b-agent-research/B013/0000LD-MidiPlayer-empty-emitter-family-source-quality.md`: identified UID0001CE as a remaining empty marker because stream-buffer/shared-state declarations were not repaired; this current report rechecked and keeps that blocker rather than treating it as vague future work.
- `executed-b-agent-research/B001/0002BU-0002BV-0002C6-0002C7-MidiSMFParserStreamSourceQuality.md`: accepted `MidiFillStreamBuffer`, `MidiStreamWriteContext`, and `MIDI_FILL_*` names.
- `executed-b-agent-research/B002/00041N-MidiPlayerRawStreamControlHelpers-by-memory-source-quality.md`: confirmed raw call at `0x0052637e`.
- `executed-b-agent-research/B007/0000LC-MetaMan-empty-emitter-family-source-quality.md`: only boundary support; confirms predecessor padding before `0x00525920`.

## Positive Evidence Summary

MCP confirms the function boundary and current IDA model: `lookup_funcs 0x00525920` returns `sub_525920`, size `0x1ed` / 493 bytes, and `0x00525b0d` is not a function. Disassembly reports 128 instructions and ends with three returns at `0x00525aec`, `0x00525b02`, and `0x00525b0c`.

MCP confirms the caller set: `xrefs_to 0x00525920` returns code refs at `0x526271` in `sub_526240`, `0x52637e` in raw/unmodeled code, and `0x52654c` in `sub_526460`. Current support names map these to `StartSelectedMidiFile`, `OpenSelectedMidiFileNoRestart`, and `MidiPlayer_ResetStream`.

MCP confirms the callback linkage: disassembly at `0x525939` pushes `offset sub_525BE0` as `dwCallback` to `midiStreamOpen`, and `xrefs_to 0x00525be0` returns the data ref at `0x525939` plus a separate raw helper ref at `0x525f67`.

MCP confirms behavior:

- If `g_hMidiStream` / `0x0069b500` is zero, the helper calls `midiStreamOpen(&0x0069b500, &0x0069b504, 1, sub_525BE0, 0, 0x30000)`, returning `1` on failure.
- It loops over `0xA8` bytes in `0x54` byte steps, covering two MIDI header records, writes `dwBufferLength = 0x400`, allocates `GlobalAlloc(0x42, 0x400)`, locks it, and stores `lpData`; null lock/allocation returns `-1`.
- It calls `sub_5270C0(&unk_69B828, 0x0069b618)`. Current decompile of `0x005270c0` shows this wrapper returns `sub_5273A0(this, path) == 1`, so this target treats nonzero as open/load failure and returns `1`.
- It copies document time division from `unk_69B82C` into the local property data at stack `var_4`, sets `cbStruct` / first property dword to `8`, copies `xmmword_61FB60` into four channel-volume/default lanes at `0x0069b5d0`, `0x0069b5e0`, `0x0069b5f0`, and `0x0069b600`, and calls `midiStreamProperty(hms, propdata, 0x80000001)`.
- It clears `0x0069b614` and `0x0069b610`, then fills up to two headers through `sub_5271B0(&unk_69B828, resetFlag, streamContext, 0x0069b510)`.
- Fill return `-103` / raw `0xffffff99` sets a local end flag and still queues the current buffer; other nonzero fill returns clean up the document and return `1`.
- It copies the stream write-context byte count into the `MIDIHDR.dwBytesRecorded` slot, prepares headers only when `0x0069b520` is zero, submits via `midiStreamOut`, sets `0x0069b520 = 1`, resets `0x0069b610 = 0`, and returns `0`.

MCP confirms direct state xrefs from the target to `g_hMidiStream`, `g_midiDeviceId`, `g_midiAllowEndReplay` / fill mode, `g_midiHeadersPrepared`, the header array at `0x0069b528`, channel defaults at `0x0069b5d0`, active header index `0x0069b610`, pending count `0x0069b614`, and document state `0x0069b828`.

Support evidence confirms the owner/emitter route. `by-file/MidiPlayer.md` owns the WinMM MIDI stream controller in `NexusTK/audio/MidiPlayer.cpp`; `by-class/MidiPlayer.md` documents the compact 12-byte class but treats UID0001CE as a related free helper; `by-global/MidiPlayerWinMMState.md` maps the process-wide state used by this helper. There is no stronger class-method receiver: UID0001CE has no `this` argument and works almost entirely through file-scope WinMM state and private MIDI document state.

## Negative Evidence Summary

No recovered local type proves original source spellings for `MidiDocument`, `MidiTrackState`, `MidiStreamWriteContext`, `MidiStreamBuffer`, or the WinMM state globals. Current MCP `type_query *Midi*` finds only SDK `midihdr_tag`; `*SMF*` returns no hits; `*Track*` only finds unrelated `tagTRACKMOUSEEVENT`. `search_structs Midi` also finds only `midihdr_tag`.

No evidence supports moving UID0001CE to the 12-byte `MidiPlayer` class as a member method. The target has no receiver, is reached by file-local start/reset/raw helpers, and manipulates module-level WinMM state and parser state.

No evidence supports moving UID0001CE to `SoundManager` or Miles audio code. All direct APIs are WinMM MIDI or Win32 global-memory calls, and the surrounding docs separate WinMM MIDI from SoundManager/Miles/MP3/WAV/Redbook policy.

No evidence supports a separate `MidiSMFDocument.cpp` owner as the current route. A private SMF helper source split remains historically plausible, but there is no recovered filename, by-file page, proposed source-tree route, or stronger owner than existing [UID:0000LD] `MidiPlayer.cpp`.

No evidence supports treating `0xffffff99` as a generic failure. Current [UID:0002C6] formal C++ and MCP decompile show this is `MIDI_FILL_END_OF_STREAM = -103`, produced only when a prior end state is replayed without allowed replay. UID0001CE handles it as a stop-after-current-buffer condition.

Current MCP `get_bytes` returns all zero bytes for `0x0069b500`, `0x0069b828`, and `0x0069b870`. That does not invalidate the code-flow evidence, but it blocks immediate shared-state declaration C++ because [UID:0002B1] old text and [UID:0002B2] emitted initializers still carry older `0xffffffff` assumptions. A UID0001CE body would have to rely on those globals and structures.

Generated output proves the dependency gap is real: UID0002B2 emits `MidiEvent` and fill-result declarations, but UID0002B1 still emits only an empty marker, while existing generated bodies reference undeclared `g_hMidiStream`, `g_midiHeaders`, `g_midiDocumentState`, `g_midiCurrentPath`, and related state. UID0001CE should not add another body on top of unrepaired shared declarations.

## Heuristic / Inference Reanalysis And Validation

Ownership/source placement: keep `CANONICAL_OWNER:0000LD` and `EMITTER_UIDS:0000LD`. The best source-facing shape is a private file-scope `static int MidiStreamOpenAndPrimeBuffers()` in `NexusTK/audio/MidiPlayer.cpp`. This function is not a `MidiPlayer` instance method and not a generic parser helper: it bridges selected path/document state, WinMM stream setup, two-buffer header allocation, and initial stream-buffer output.

Function naming: keep `MidiStreamOpenAndPrimeBuffers` as the preferred descriptive name. `OpenAndPrimeMidiStream` is a tolerable alias, but current by-* pages and generated callers already use `MidiStreamOpenAndPrimeBuffers`; changing it would create churn without stronger original-symbol evidence. Raw `sub_525920` should remain only in evidence/searchability text.

Caller liveness: all three current xrefs are live and meaningful. The modeled start helper `0x00526240` and reset helper `0x00526460` are direct named support routes. The raw `0x0052637e` call remains preserved through [UID:00041N] `OpenSelectedMidiFileNoRestart`, with no restart/volume behavior after open. This target therefore remains a shared private helper, not a dead function or one-off child of only one caller.

Split/range: the `0x00525920-0x00525b0d` page is the correct exact target. Neighboring evidence keeps `0x00525914-0x00525920` as preceding `0xcc` alignment and `0x00525b0d-0x00525b10` as following alignment before [UID:0001CF]. No split inside UID0001CE is supported: the function is one coherent open/prime routine with one stack frame, one prologue, shared error paths, and shared success state.

Raw/helper role recovery: `sub_5270C0` is the parse success wrapper for `MidiLoadDocument`; `sub_5270E0` releases MIDI document resources; `sub_5271B0` is `MidiFillStreamBuffer`. Current decompile confirms UID0001CE passes reset flag `1` for the first buffer and then `0`, and passes `0x0069b510` as the allow-end-replay/fill-mode flag. This aligns B006/B012/B013 evidence and resolves the stale "fill budget" phrasing.

Score blockers: the old broad blockers "global names, helper return constants, and source split" are partly resolved. Fill constants and helper names are now accepted; source placement is sufficiently resolved to `MidiPlayer.cpp`; caller names are known. The remaining real blocker is exact shared declaration support, especially [UID:0002B1] plus full definitions or shared declarations for `MidiDocument`, `MidiTrackState`, `MidiStreamWriteContext`, a two-header wrapper such as `MidiStreamBuffer`, and stream/header/global initializers. This report converts that blocker into an implementation-ready repair, not an open-ended future investigation.

Implementation-ready support repair:

- Repair [UID:0002B1] first or in the same accepted callback batch before inserting UID0001CE C++.
- [UID:0002B1] should provide the static storage declarations needed by existing and future helper bodies: `g_hMidiStream`, `g_midiDeviceId`, stream state/restart/document/running/header/volume globals, `g_midiHeaders` as two 84-byte `MIDIHDR`-backed records or a source-quality wrapper, current path buffer, `g_midiDocumentState`, channel-volume/default lanes, and state constants.
- Reconcile current zero-byte MCP evidence with [UID:0002B2] and old `0xffffffff` initializer wording before emitting initializers. The current session supports zero-initialized storage for `0x0069b500`, `0x0069b828`, and `0x0069b870`; any nonzero sentinels must be justified by explicit static constructor/runtime initialization, not stale byte text.
- Provide or route full declarations for `MidiStreamWriteContext` fields used by [UID:0002C6] and UID0001CE. UID0001CE writes context fields that decompile as offsets `+0x40`, `+0x44`, `+0x48`, and `+0x50` inside/around each `0x54` header-shaped record; generated code currently only forward-declares `MidiStreamWriteContext`, which is insufficient for source code that constructs it.

Rejected alternatives:

- Populate UID0001CE body immediately from decompilation: rejected for this report because it would depend on unrepaired UID0002B1 declarations and incomplete `MidiStreamWriteContext`/header wrapper definitions.
- Mark UID0001CE no-code permanently or covered by the parent aggregate: rejected. The function is source-authored code with a valid owner/emitter route; the no-code disposition is only a current-pass formal-code blocker proof.
- Move the body into [UID:0001CG] callback or [UID:0002C6] fill helper: rejected. UID0001CE calls both callback and fill helper but owns distinct stream-open/property/header-priming behavior.
- Rename `g_midiCurrentPath` back to generated `g_midiSelectedPath`, `g_midiDocumentLoaded` to generated `g_midiStreamOpen`, or `g_midiAllowEndReplay` to generated `g_midiUseLooseFile`: rejected by B006/B011 support and current data flow.

## Ranked Ownership Analysis

1. [UID:0000LD] `by-file/MidiPlayer.md` / `NexusTK/audio/MidiPlayer.cpp`: recommended direct owner and emitter. Positive evidence: UID0001CE is no-argument private helper code that opens the WinMM MIDI stream, installs the MIDI callback, allocates the two stream buffers, uses `g_midiCurrentPath` / static MIDI document state, and is called only by MidiPlayer start/reset/raw stream-control helpers. The file page already owns the WinMM MIDI stream controller, buffer lifetime, callback, reset, parser/fill helpers, and process-wide MIDI globals. Negative evidence against this route is only unrecovered original symbol spelling and the possible historical SMF helper source split, not a stronger current owner.
2. [UID:00008A] `by-class/MidiPlayer.md`: rejected as canonical owner. The class page owns the 12-byte object layout and instance methods such as `SelectTrack`, playback toggles, stop, and lifecycle methods. UID0001CE has no `this` receiver and does not read object fields directly; it operates through module-level WinMM state and document/parser state. The class page remains useful support text only.
3. [UID:0000T9] `by-global/MidiPlayerWinMMState.md`: rejected as canonical owner, accepted as support owner for state declarations. UID0001CE heavily touches the WinMM state cluster, but the function is code in the MidiPlayer source module; the global page and [UID:0002B1] should document/emit storage declarations, not own this text function body.
4. New `MidiSMFDocument.cpp` / private MIDI parser by-file: rejected for this target. The parser/source split remains historically plausible for helper types, but no recovered filename, by-file page, source-tree route, or stronger ownership evidence exists. UID0001CE is specifically the WinMM stream-open/priming bridge, not only the SMF parser.
5. [UID:0000NV]/[UID:0000DG] SoundManager/Miles audio family: rejected. UID0001CE uses WinMM `midiStreamOpen`, `midiStreamProperty`, `midiOutPrepareHeader`, `midiStreamOut`, `GlobalAlloc`, and `GlobalLock`; no RAD Miles, MP3/WAV, Redbook, or DAT audio-resource ownership route is present.
6. Covered-by aggregate/no-owner/non-emitting: rejected. UID0001CE is exact source-authored code with a live caller set and a valid emitter route. The current no-code disposition is only a formal C++ readiness blocker caused by shared declarations, not evidence that the function should be permanently non-emitting.

## Source Placement

Place UID0001CE as a private file-scope helper in [UID:0000LD] `MidiPlayer.cpp` under `NexusTK/audio/`, using the current descriptive name `MidiStreamOpenAndPrimeBuffers`.

Source-shape rationale: the helper is a bridge between `StartSelectedMidiFile` / raw open / reset control and the lower SMF document/fill helpers. It should sit near the WinMM MIDI stream helpers and before the callback/fill code in final source. It should not become a `MidiPlayer` instance method because no object receiver is used, and it should not move into a parser-only source because it performs WinMM stream open, property, header allocation, prepare, and submit work.

The source route is ready, but formal body emission is not. The current body would require complete shared declarations from [UID:0002B1] and related type/layout support. Until those are repaired, `MidiPlayer.cpp` can keep generated calls to `MidiStreamOpenAndPrimeBuffers()` as declarations/leads, while this exact target page remains the source-quality owner for the body and no-code proof.

## Recommended Target Doc Changes

For `by-memory/0x00525920-0x00525b0d.MidiStreamOpenAndPrimeBuffers.md`:

- Set score to `COMPLETION:87`, `CONFIDENCE:90`.
- Keep `CANONICAL_OWNER:0000LD`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000LD`, and blank `EMITTER_POSITION_OPTIONAL`.
- Keep the formal `RECONSTRUCTION_CPP CODE` block empty and add the target-specific no-code proof from this report. Do not insert body C++ during this report-only phase.
- Add current MCP session `1f24c222` evidence: server health, exact function size `0x1ed` / 493 bytes, 128 instructions, three xrefs `0x526271`, `0x52637e`, `0x52654c`, callback data ref at `0x525939`, target decompile/disassembly behavior, support helper decompiles for `0x005270c0`, `0x005270e0`, and `0x005271b0`, and touched-state xrefs.
- Update behavior notes to preserve that the first fill call passes reset flag `1`, later fill passes `0`, and `0x0069b510` is the accepted allow-end-replay/fill-mode state passed to `MidiFillStreamBuffer`.
- Preserve `MIDI_FILL_END_OF_STREAM = -103` as the `0xffffff99` case that stops after queueing the current buffer; reject treating it as generic failure or as `MIDI_FILL_OUTPUT_FULL`.
- Add the current declaration blocker: [UID:0002B1] still emits an empty marker, current generated `MidiPlayer.cpp` still has UID0001CE as an empty marker, and current MCP reads zero bytes at `0x0069b500`, `0x0069b828`, and `0x0069b870`.
- Add negative evidence/rejected alternatives: not a class method, not SoundManager/Miles, not a new proven SMF source file, not covered by callback/fill/helper aggregate, and not ready for immediate body C++ until shared declarations are repaired.

## Recommended Support Doc Changes

For `by-file/MidiPlayer.md`:

- Record UID0001CE as the exact private file-scope stream-open/two-buffer priming helper whose behavior is body-understood but formal C++ remains blocked by UID0002B1/shared declaration repair.
- Keep the existing `NexusTK/audio/` route, WinMM/SoundManager separation, and expected remaining empty marker context.
- Replace any vague "follow-up" wording for UID0001CE with the concrete blocker: `MidiStreamWriteContext`, `g_midiHeaders`, `g_midiDocumentState`, current path, stream state/header globals, and initializer reconciliation.

For `by-global/MidiPlayerWinMMState.md`:

- Add a UID0001CE-specific support note that the target depends on this state family for `g_hMidiStream`, `g_midiDeviceId`, `g_midiHeadersPrepared`, `g_midiHeaders`, channel defaults, active/pending header counters, document state, current path, and fill-mode/end-replay state.
- Preserve the current aggregate no-code/children route; do not move UID0001CE code or concrete storage definitions into the aggregate page.
- Record that current MCP zero-byte reads reproduce the shared declaration/initializer blocker and must be reconciled before UID0001CE body C++ is inserted.

For `by-memory/0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals.md`:

- Add a declaration-repair note for UID0001CE: this page is the expected support page for `g_hMidiStream`, `g_midiDeviceId`, two `MIDIHDR`/stream-buffer records, document state, current path, channel defaults, and stream/header state globals used by the open/prime body.
- Preserve current zero-byte evidence from session `1f24c222` and explicitly avoid reusing stale `0xffffffff` initializer assumptions without reconciliation.
- Keep owner/emitter through [UID:0000T9] unless a supervisor-accepted support repair changes declaration routing.

For `by-class/MidiPlayer.md`:

- No required edit if the current text is considered sufficient. Optional consistency edit: add one sentence that UID0001CE is resolved for current routing as a private file-scope helper, not a `MidiPlayer` method. This is optional because the class page already states similar class/private-helper separation.

## Score And Metadata Recommendation

Recommended target metadata after report incorporation:

- `COMPLETION:87`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000LD` unchanged.
- `RECONSTRUCTABLE:TRUE` unchanged.
- `EMITTER_UIDS:0000LD` unchanged.
- `EMITTER_POSITION_OPTIONAL:` unchanged / blank.
- `RECONSTRUCTION_CPP CODE` remains blank in this pass, with the no-code proof below.

Rationale: completion should rise from `85` to `87` because current MCP revalidates exact range, instruction count, three callers, callback pointer, all major WinMM/document/fill behaviors, zero-byte shared-state blocker state, type-search negatives, and generated-output dependency state. Confidence should rise from `88` to `90` because the current restored MCP session directly confirms the behavior and the remaining blocker is precisely scoped. Completion should not reach `88+` yet because no formal body is recommended until [UID:0002B1] and shared declarations are repaired; confidence should stay below final-audit range because original source spellings and declaration layouts remain inferred.

Support recommendations if accepted:

- Update `by-memory/0x00525920-0x00525b0d.MidiStreamOpenAndPrimeBuffers.md` with current session `1f24c222`, current zero-byte blocker evidence, caller/callee refresh, refined score rationale, rejected alternatives, and the current formal no-code proof.
- Update `by-file/MidiPlayer.md` to replace "formal C++ likely after UID0002B1" with a current, implementation-ready dependency statement for UID0001CE: behavior is now body-ready, but C++ insertion is blocked until UID0002B1/shared declaration repair supplies state/header/context declarations.
- Update `by-global/MidiPlayerWinMMState.md` and `by-memory/0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals.md` only to add the current UID0001CE-specific support blocker evidence and exact repair plan; do not try to solve UID0002B1 in a UID0001CE callback unless the supervisor explicitly accepts that support scope.
- `by-class/MidiPlayer.md` is already sufficient unless the supervisor wants a short optional note that UID0001CE is resolved as a private file-scope helper, not a class method.

No manual generated report, generated C++, coverage report, validator state, queue, archive, or supervisor-ledger update is recommended for the B agent. Generated/tracker refresh should happen only through scoped validators during a later accepted implementation callback and supervisor-owned report execution.

## First-Draft C++ Recommendation

Do not insert a UID0001CE formal C++ body in the current pass.

Target-specific no-code proof:

- The body behavior is sufficiently understood, but source code would require concrete declarations for `g_hMidiStream`, `g_midiDeviceId`, `g_midiHeaders`, `g_midiHeadersPrepared`, `g_midiActiveHeaderIndex`, `g_midiPendingBufferCount`, `g_midiDocumentState`, `g_midiCurrentPath`, `g_midiAllowEndReplay` / fill-mode state, channel-volume/default storage, and the `MidiStreamWriteContext` layout.
- Current generated output proves those declarations are not available yet: UID0002B1 remains an empty emitter marker while existing helper C++ already references the state names.
- Current MCP `get_bytes` returns zero bytes at `0x0069b500`, `0x0069b828`, and `0x0069b870`, matching B013's blocker and conflicting with older `0xffffffff` initializer assumptions. Emitting a UID0001CE body before reconciling that state would bake uncertain initializers and incomplete declarations into `MidiPlayer.cpp`.
- Therefore the correct formal block for UID0001CE remains empty until the UID0002B1/shared declaration callback is accepted.

Exact formal target block disposition for UID0001CE after this report, preserving the current empty block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

When UID0002B1/shared declarations are repaired, UID0001CE should receive a formal body equivalent to: open the stream if needed, allocate/lock two `0x400` buffers, load `g_midiDocumentState` from `g_midiCurrentPath`, set `MIDIPROP_TIMEDIV`, initialize channel defaults, call `MidiFillStreamBuffer` for one or two buffers, treat `MIDI_FILL_END_OF_STREAM` as stop-after-current-buffer, prepare unprepared headers, submit with `midiStreamOut`, set prepared state, reset active index, and return `0`, `1`, or `-1`. This is an implementation-ready behavioral recipe, not formal C++ insertion text for the current callback.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID0001CE exact range remains `0x00525920-0x00525b0d`, IDA `sub_525920`, size `0x1ed` / 493 bytes, 128 instructions. | High | MCP `lookup_funcs`, `analyze_function`, `disasm` session `1f24c222`. | Target `2026-07-02 B003 Source-Quality Callback` and `Score Rationale` now state `sub_525920`, size `0x1ed` / 493 bytes, and 128 bounded-disassembly instructions; existing `Address Range` already carried the exact range. | incorporate | applied |
| C02 | UID0001CE has exactly three current entry xrefs: `0x526271`, `0x52637e`, `0x52654c`. | High | MCP `xrefs_to 0x00525920`. | Target `Caller Evidence` already carried the three entries; target callback section restates current three-code-ref surface; `by-file/MidiPlayer.md` adds current `1f24c222` support note. | incorporate | applied |
| C03 | Callback pointer `0x00525be0` is passed at `0x525939`; callback is separate from the open/prime body. | High | MCP disasm and `xrefs_to 0x00525be0`. | Target `Behavior`, `Caller Evidence`, and callback section preserve `0x00525939`; `Reconstruction Notes` keeps callback separation; `by-file/MidiPlayer.md` support note preserves callback pointer context. | incorporate | applied |
| C04 | Core behavior is open-if-null, allocate two `0x54` header records and `0x400` buffers, load MIDI document, set stream property, fill/prepare/submit up to two buffers. | High | MCP target decompile/disasm. | Target `Behavior` already contained the behavior table; callback section adds current disassembly/decompile details and support-helper decompile links. | incorporate | applied |
| C05 | `MIDI_FILL_END_OF_STREAM = -103` is stop-after-current-buffer handling, not generic failure; other nonzero fill results clean up and return `1`. | High | MCP target decompile; [UID:0002C6] support; B012 report. | Target `Behavior`, `Reconstruction Notes`, and callback section preserve `0xffffff99` / `-103` stop-after-current-buffer semantics; no [UID:0002C6] edit was required because this callback did not change that support page. | incorporate | applied |
| C06 | Owner/emitter stay [UID:0000LD] `MidiPlayer.cpp`; UID0001CE is private file-scope helper, not a `MidiPlayer` method, not SoundManager, not a new SMF source file. | High | Current docs, caller/callee family, no receiver, no stronger source route; Ranked Ownership Analysis. | Target metadata unchanged and callback section records ranked owner/source placement and rejected alternatives; `by-file/MidiPlayer.md` states private `NexusTK/audio/MidiPlayer.cpp` helper and rejects SoundManager/class/new-SMF owner. | incorporate | applied |
| C07 | Current MCP zero-byte reads for `0x0069b500`, `0x0069b828`, and `0x0069b870` keep [UID:0002B1] declaration repair as the real C++ blocker. | High | MCP `get_bytes`; B013 prior blocker; generated UID0002B1 empty marker. | Target callback section and `Reconstruction Notes` add zero-byte blocker; `by-global/MidiPlayerWinMMState.md` and `by-memory/0x0069b500-0x0069b870...md` add UID0001CE-specific zero-byte/declaration repair notes. | incorporate | applied |
| C08 | No original local types prove `MidiDocument`, `MidiTrackState`, `MidiStreamWriteContext`, or source spellings; only SDK `midihdr_tag` and unrelated `tagTRACKMOUSEEVENT` appear. | High | MCP `type_query` and `search_structs`. | Target callback section records type-search negatives and no-code impact; support docs preserve declaration caveat through the UID0002B1/shared-declaration blocker. | incorporate | applied |
| C09 | Recommended metadata after incorporation is `87/90`, owner/emitter/reconstructable unchanged, formal C++ blank. | Medium-high | Score audit, current MCP evidence, and no-code proof. | Target metadata header changed to `COMPLETION:87`, `CONFIDENCE:90`; `CANONICAL_OWNER:0000LD`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000LD`, blank position, and blank formal C++ preserved; validator `000000004767` applied completion/confidence updates. | incorporate | applied |
| C10 | Immediate formal C++ insertion is rejected with a target-specific no-code proof, but a later body is body-ready after UID0002B1/shared declaration repair. | High | MCP body plus declaration/generated blockers. | Target formal block remains empty; `Reconstruction Notes`, callback section, and `by-file/MidiPlayer.md` state body-ready but formal-C++-blocked-by-UID0002B1/shared-declarations disposition. | incorporate | applied |
| C11 | Generated output state should be recorded as read-only evidence: command `000000004725`, refreshed `2026-07-02T17:01:13-04:00`, UID0001CE and UID0002B1 still empty markers. | High | Read-only `auto-generated/NexusTK/audio/MidiPlayer.cpp`. | Target callback section records accepted generated empty-marker state; after scoped validators, generated `auto-generated/NexusTK/audio/MidiPlayer.cpp` header is now current for command `000000004771`, refreshed `2026-07-02T18:08:39-04:00`, and remains read-only. | incorporate | applied |
| C12 | [UID:0002B1] is an implementation-ready support repair dependency for UID0001CE, not a vague future-work excuse. | High | Current MCP zero bytes, generated empty marker, UID0001CE decompile dependency on state/header/context declarations. | `by-file/MidiPlayer.md`, `by-global/MidiPlayerWinMMState.md`, and `by-memory/0x0069b500-0x0069b870...md` now state the concrete UID0001CE declaration repair dependency and zero-byte blocker. | incorporate | applied |
| C13 | Optional `by-class/MidiPlayer.md` edit is not required if current class/private helper separation is already present. | Medium-high | Current class doc already lists UID0001CE as related free helper and open question/source-family member, not an object method. | `by-class/MidiPlayer.md` was not edited; current class/private-helper separation was already present at sufficient detail, and `by-file/MidiPlayer.md` now carries the consistency note. | not-applicable | excluded-with-reason |

## Implementation Tracking Checklist

- [x] Apply Recommended Target Doc Changes to `by-memory/0x00525920-0x00525b0d.MidiStreamOpenAndPrimeBuffers.md`: set `COMPLETION:87`, `CONFIDENCE:90`, keep `CANONICAL_OWNER:0000LD`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000LD`, blank position, and empty formal C++ block. Proof: target metadata changed to `87/90`; owner/emitter/reconstructable/formal block preserved; target now has `2026-07-02 B003 Source-Quality Callback`, updated `Reconstruction Notes`, updated `Score Rationale`, and a 2026-07-02 change entry.
- [x] Apply Recommended Support Doc Changes to `by-file/MidiPlayer.md`: record UID0001CE as a private file-scope `MidiPlayer.cpp` helper that is behavior-ready but formal-C++ blocked by UID0002B1/shared state declarations; preserve `NexusTK/audio/` route, SoundManager rejection, and expected-empty-marker context. Proof: `MIDI SMF Source-Quality Declarations` now contains the 2026-07-02 B003 UID0001CE paragraph and `Open Questions` no longer treats `0x00525920` as class-vs-file unresolved.
- [x] Apply Recommended Support Doc Changes to `by-global/MidiPlayerWinMMState.md`: add the UID0001CE-specific current zero-byte/declaration blocker and exact repair plan; do not convert the aggregate into concrete storage declarations. Proof: `Reconstruction Caveats` and `Changes` now carry the UID0001CE zero-byte/declaration blocker and repair plan.
- [x] Apply Recommended Support Doc Changes to `by-memory/0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals.md`: record that UID0001CE depends on this page for `g_hMidiStream`, `g_midiDeviceId`, `g_midiHeaders`, document state, current path, channel defaults, and stream/header globals; preserve current MCP zero-byte evidence as a declaration repair blocker. Proof: `Rebuild Notes` and `Changes` now carry the UID0001CE dependency set and zero-byte blocker.
- [x] Treat `by-class/MidiPlayer.md` as optional/not-applicable unless supervisor wants the consistency sentence from Recommended Support Doc Changes. Proof: no class edit made; C13 marked `excluded-with-reason` because the class/private-helper separation was already sufficient and the new support consistency note lives in `by-file/MidiPlayer.md`.
- [x] Preserve Ranked Ownership Analysis negative evidence in the target/support docs: no original MIDI/SMF local type names, no stronger `MidiSMFDocument.cpp` source route, no SoundManager/Miles ownership, no covered-by parent/callback/fill-helper disposition, and no raw `sub_525920` use in source snippets. Proof: target callback section records ranked owner/source placement, rejected alternatives, and type-search negatives; by-file support note rejects SoundManager/class/new-SMF ownership.
- [x] Preserve the `First-Draft C++ Recommendation` no-code disposition for UID0001CE until UID0002B1/shared declaration repair is accepted. Proof: target formal C++ block remains empty and target/support docs state the UID0002B1/shared-declaration blocker.
- [x] During callback, update the Claim And Incorporation Ledger rows C01-C13 with `applied`, `already-present`, or `excluded-with-reason` proof against the exact destination sections named in the ledger. Proof: ledger rows above now show C01-C12 `applied` and C13 `excluded-with-reason`.
- [x] Run scoped validators from `source-3/project-documentation` after accepted by-* edits:
  - `python .\tools\validator.py --mode file --file by-memory/0x00525920-0x00525b0d.MidiStreamOpenAndPrimeBuffers.md --apply --queue-timeout 240`: exit code 0; `command_id: 000000004767`; `command_timestamp: 2026-07-02T18:08:10-04:00`; `ok: 1`; no warnings; `completion_update: 1`, `confidence_update: 1`, `stats_row_remove: 1`, `projected_stats_update: 1`; `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-file/MidiPlayer.md --apply --queue-timeout 240`: exit code 0; `command_id: 000000004768`; `command_timestamp: 2026-07-02T18:08:16-04:00`; `ok: 1`; no warnings; `stats_incremental_noop: 1`, `projected_stats_update: 1`; `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-global/MidiPlayerWinMMState.md --apply --queue-timeout 240`: exit code 0; `command_id: 000000004770`; `command_timestamp: 2026-07-02T18:08:27-04:00`; `ok: 1`; no warnings; `reference_index_add: 1`, `stats_row_update: 1`, `projected_stats_update: 1`; `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-memory/0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals.md --apply --queue-timeout 240`: exit code 0; `command_id: 000000004771`; `command_timestamp: 2026-07-02T18:08:39-04:00`; `ok: 1`; no warnings; `reference_index_add: 1`, `stats_incremental_noop: 1`, `projected_stats_update: 1`; `generated_refresh: deferred`.
  - Optional `by-class/MidiPlayer.md` validator not run because the class file was not edited.
- [x] After validators, inspect generated `auto-generated/NexusTK/audio/MidiPlayer.cpp` read-only. Proof: generated header now shows `validator-command-id: 000000004771`, `validator-refreshed-at: 2026-07-02T18:08:39-04:00`, `validator-refresh-source: deferred-generated-refresh`, equal to the latest scoped validator metadata.
- [x] Do not edit generated reports, generated C++, manual coverage reports, project-level generated reports, validator state, queues, archives, supervisor ledgers, or IDA DB. Proof: no manual edits were made to those files; validator-reported side effects were validator-owned updates to projected stats/generated output.
- [x] Do not run `execute_report`, any dry-run/status/probing lifecycle variant, registry lifecycle command, archive command, or manual report move. Proof: only scoped file validators and leaser lease/unlease commands were run; report remains in `tools/leaser/Agents/Agent-B003/research/`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004791","destination_path":"executed-b-agent-research/B003/0001CE-MidiStreamOpenAndPrimeBuffers-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0001CE-MidiStreamOpenAndPrimeBuffers-source-quality.md","timestamp":"2026-07-02T18:16:57-04:00","uid":"0001CE"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
