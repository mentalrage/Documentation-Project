** TARGET-REPORT-UID:0000LD **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000LD MidiPlayer Empty-Emitter Family Source-Quality Report

TARGET-REPORT-UID:0000LD  
AUTHOR-AGENT-ID:B013  

Assignment: `B013-report-0000LD-MidiPlayer-empty-emitter-family-20260630`  
Agent: `Agent-B013`  
Date: 2026-06-30  
Target: [UID:0000LD] `by-file/MidiPlayer.md`  
Report path: `tools/leaser/Agents/Agent-B013/research/0000LD-MidiPlayer-empty-emitter-family-source-quality.md`

Implementation callback status: accepted bounded first batch implemented on 2026-06-30. I edited only the accepted target/support by-* docs and this report, used short leases for by-* edits, ran the scoped validators, inspected generated `auto-generated/NexusTK/audio/MidiPlayer.cpp` read-only, and did not spawn subagents or manually edit generated files, manual coverage reports, validator/tool state, the IDA DB, executed archives, supervisor ledgers, or lock files.

## Finalized Report / Current Recommendation

- Current recommendation: the supervisor accepted the bounded first implementation batch for the pre-callback `auto-generated/NexusTK/audio/MidiPlayer.cpp` empty markers, and the accepted batch has been implemented. The batch applied formal no-code markers on aggregate/data pages, a formal singleton declaration, formal C++ for the source raw-read/release/size/close/refill/wrapper helpers listed below, and support fixes to the already-populated `MidiReadRaw` callers whose return-polarity is contradicted by current MCP.
- Final disposition: [UID:0000LD] remains the source root for `NexusTK/audio/MidiPlayer.cpp`. The family is not complete after this bounded batch; five current empty markers remain second-batch follow-up because current MCP exposes a shared declaration and generated-output consistency blocker.
- Implementation result: only the accepted candidate-batch docs were edited, scoped validators ran for every changed by-* doc, the generated file was inspected read-only after the queue drained, and no accepted candidate-batch row remains unapplied.
- Confidence: high for the empty-marker inventory, owner/source route, no-code dispositions, and raw-read polarity finding; medium-high for the first-batch helper C++ names because `MidiDocument`/`MidiTrackState` remain inferred descriptive types.

## Target

- Target UID: `0000LD`
- Target path: `by-file/MidiPlayer.md`
- Source queue row: `auto-generated/-ag-research-tracker.md` line 79 reports 38 total emitters, 20 filled, 18 empty, 52.6 percent complete, generated file `auto-generated/NexusTK/audio/MidiPlayer.cpp`.
- Current file metadata: `COMPLETION:88`, `CONFIDENCE:89`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/audio/"`, `CANONICAL_OWNER:FILE`.
- Pre-callback generated file checked: `auto-generated/NexusTK/audio/MidiPlayer.cpp`, header `validator-command-id: 000000001773`, `validator-refreshed-at: 2026-06-30T00:05:54-04:00`, source by-file UID `0000LD`.

## Current Target State

[UID:0000LD] is a valid by-file generated source root for `NexusTK/audio/MidiPlayer.cpp`. Current docs strongly place the WinMM MIDI stream controller, `MidiPlayer` class, singleton pointer, WinMM state globals, MIDI SMF parser helpers, callback, reset, and document helpers in this source family and keep the family separate from [UID:0000NV] `SoundManager`.

The generated file is not empty. It already contains formal draft code for 20 routed emitters, including the scratch-global declaration block [UID:0002B2], release buffers [UID:00041H], single-channel volume [UID:00041I], lifecycle methods [UID:00041J], raw local helpers [UID:00041K], playback toggles [UID:00041L], track selection [UID:0001CH], stop [UID:00041M], raw stream-control helpers [UID:00041N], reset [UID:00041O], exact read [UID:0002BS], track byte read [UID:0002BT], event reader [UID:0002BU], stream-event encoder [UID:0002BV], VLQ reader [UID:0002BW], track prime [UID:0002BY], source seek [UID:0002C1], stream fill [UID:0002C6], and SMF document load [UID:0002C7].

The pre-callback generated file had 18 empty markers, listed in the inventory below. This report deliberately does not claim the family is complete. It recommended a bounded first batch because current MCP found two material consistency blockers that should not be papered over by adding more guessed code:

- current bytes for `0x0069b500`, `0x0069b828`, and `0x0069b870` are zero in the active IDB, while older docs and the currently emitted [UID:0002B2] scratch declarations still say or emit `0xffffffff` initializers;
- current MCP proves `sub_527000` / [UID:0002C2] returns nonzero on successful DATFile/Win32 reads, while already-populated [UID:0002BY] and [UID:0002C7] call it as if nonzero were failure.

Those are current evidence issues, not speculation. The bounded batch fixes the proven raw-read polarity surface and avoids adding stream-open/callback/shared-state C++ that would depend on the stale declaration block.

## Supervisor Active Recheck

The initial assignment was report-first research for [UID:0000LD] `by-file/MidiPlayer.md` from the Files With Empty Emitters front queue. The assignment allowed a bounded first implementation batch if the report included a complete empty-marker inventory, clearly marked candidate-batch rows, and listed remaining rows as follow-up. The supervisor accepted that bounded batch and converted this report to an implementation callback.

No split execution was performed. No by-* docs were edited during the report-only phase; the accepted callback edits are recorded in the implementation results below.

## MCP Evidence

MCP was mandatory and was used live.

- Endpoint: `http://127.0.0.1:13337/mcp`
- `initialize`: HTTP 200.
- `tools/list`: HTTP 200.
- `idb_list`: active session `supervisor_resume_20260629`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker pid `17592`, backend `worker`, active/adopted/owned, `is_analyzing:false`.
- `server_health(database='supervisor_resume_20260629')`: `status:ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`.

Current MCP function state for empty-code helper rows:

| Address | MCP result | Meaning |
| --- | --- | --- |
| `0x00525920` | `sub_525920`, size `0x1ed` | Modeled stream-open/two-buffer prime function. |
| `0x00525be0` | `sub_525BE0`, size `0x1db` | Modeled WinMM callback. |
| `0x00526ce0` | `Not a function`; disassembly shows normal prologue/body/`retn 4` | Raw track-buffer refill helper. |
| `0x00526f10` | `Not a function`; disassembly shows normal prologue/body/`retn 4` | Raw source-open helper. |
| `0x00526f60` | `Not a function`; disassembly shows close body and `retn` | Raw source-close helper. |
| `0x00527000` | `sub_527000`, size `0x39` | Modeled raw source read helper. |
| `0x00527040` | `Not a function`; disassembly shows size/ready body and `retn` | Raw source-size/ready helper. |
| `0x00527080` | `sub_527080`, size `0x35` | Modeled document/source initializer. |
| `0x005270c0` | `sub_5270C0`, size `0x15` | Modeled parse-success wrapper. |
| `0x005270e0` | `sub_5270E0`, size `0xc3` | Modeled document release helper. |

Current MCP xref/callee facts:

- `xrefs_to 0x00525920`: three code refs at `0x526271`, `0x52637e`, and `0x52654c`.
- `xrefs_to 0x00525be0`: callback pointer data ref at `0x525939` in `sub_525920`, plus raw helper data ref at `0x525f67`.
- `xrefs_to 0x00526ce0`, `0x00526f10`, `0x00526f60`, and `0x00527040`: zero entry xrefs.
- `xrefs_to 0x00527000`: one SMF-loader caller at `0x52763b`.
- `xrefs_to 0x00527080`: one static-initializer caller at `0x41a015`.
- `xrefs_to 0x005270c0`: one stream-open caller at `0x52599d`.
- `xrefs_to 0x005270e0`: three callers at `0x525af2`, `0x525d91`, and `0x526514`.
- `callees 0x00525920`: `midiStreamOpen`, `GlobalAlloc`, `sub_5270C0`, `midiStreamProperty`, `sub_5271B0`, `sub_5270E0`.
- `callees 0x00525be0`: `midiOutShortMsg`, `sub_526460`, `SetEvent`, `sub_5271B0`, `midiStreamOut`, `sub_5270E0`.
- `callees 0x00527000`: `ReadFile`.
- `callees 0x00527080`: `sub_49C130` / DATFile constructor support.
- `callees 0x005270c0`: `sub_5273A0`.
- `callees 0x005270e0`: `sub_49C540`, `CloseHandle`, `GlobalUnlock`, `GlobalFree`.

Current MCP data facts:

- `get_bytes 0x0067ab4c size 4`: `00 00 00 00`, so `g_pMidiPlayer` is zero-initialized.
- `get_bytes 0x0069b500 size 64`: all zero bytes in the active IDB.
- `get_bytes 0x0069b828 size 72`: all zero bytes in the active IDB.
- `get_bytes 0x0069b870 size 32`: all zero bytes in the active IDB.
- `get_bytes 0x0061fafc size 120`: starts with vtable pointer bytes `80 65 52 00`, then UTF-16 `Wait For Buffer Return`, `Midi\\%s`, `%d.mid`, zero padding, four `0x0064` words, and successor pointer bytes.

Current MCP decompilation facts that affect this report:

- `sub_527000` decompiles as `ReadFile(...)` on the Win32 path and as embedded DATFile vtable slot `+0x20` on the DATFile path after setting `*bytesRead = bytesToRead`. It returns the underlying read result, so nonzero is success.
- `sub_526DA0` and `sub_5273A0` both check raw-read success as `if (!v8 || NumberOfBytesRead != requested)`, proving current generated [UID:0002BY]/[UID:0002C7] `MidiReadRaw(...) != 0` failure tests are inverted.
- `sub_5273A0` inlines source-open/size logic instead of calling raw [UID:0002BZ] or [UID:0002C3]. Current generated [UID:0002C7] `if (MidiOpenSource(document, path) != 0)` is therefore a source-abstraction draft, not a faithful direct call to `0x00526f10`.

## Evidence Checked

Read workflow and policy:

- `tools/leaser/Agents/Agent-B013/goal.md`
- `ntk-b-agent-workflow` skill `SKILL.md`
- `ntk-b-agent-workflow/references/b-agent-research-and-implementation-workflow.md`
- `ntk-b-agent-workflow/references/score-blocker-audit-standard.md`
- `ntk-b-agent-workflow/references/b-agent-report-template.md`
- `by-structure.md`
- `by-file/-guidance.md`
- `by-memory/-guidance.md`
- `by-global/-guidance.md`
- `by-class/-guidance.md`

Read target/generated files:

- [UID:0000LD] `by-file/MidiPlayer.md`
- `auto-generated/NexusTK/audio/MidiPlayer.cpp`
- `auto-generated/-ag-research-tracker.md`
- `auto-generated/-ag-file-coverage.md`
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/-ag-global-coverage.md`
- `auto-generated/-ag-class-coverage.md`

Read empty-marker target/support docs:

- [UID:00008A] `by-class/MidiPlayer.md`
- [UID:0000T9] `by-global/MidiPlayerWinMMState.md`
- [UID:0002B1] `by-memory/0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals.md`
- [UID:0000RM] `by-global/g_pMidiPlayer.md`
- [UID:00029A] `by-memory/0x0067ab4c-0x0067ab50.g_pMidiPlayer.md`
- [UID:0001CE] `by-memory/0x00525920-0x00525b0d.MidiStreamOpenAndPrimeBuffers.md`
- [UID:0001CG] `by-memory/0x00525be0-0x00525dbb.MidiStreamCallback.md`
- [UID:00023B] `by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md`
- [UID:0002BX] `by-memory/0x00526ce0-0x00526d9a.MidiTrackBufferRefill.md`
- [UID:0002BZ] `by-memory/0x00526f10-0x00526f57.MidiSourceOpenHelper.md`
- [UID:0002C0] `by-memory/0x00526f60-0x00526f97.MidiSourceCloseHelper.md`
- [UID:0002C2] `by-memory/0x00527000-0x00527039.MidiSourceRawReadHelper.md`
- [UID:0002C3] `by-memory/0x00527040-0x00527078.MidiSourceSizeReadyHelper.md`
- [UID:0002C4] `by-memory/0x00527080-0x005270b5.MidiReaderConstructorInit.md`
- [UID:0002C5] `by-memory/0x005270c0-0x005270d5.MidiParseSuccessWrapper.md`
- [UID:0001CI] `by-memory/0x005270e0-0x005271a3.MidiDocumentRelease.md`
- [UID:00023C] `by-memory/0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers.md`
- [UID:00025W] `by-memory/0x0061fafc-0x0061fb74.MidiPlayerReadOnlyData.md`

Executed and historical reports searched/opened as leads:

- Searched central executed reports, agent research, and archived/executed paths for `0000LD`, `MidiPlayer`, `MidiPlayer.cpp`, `MidiPlayerWinMMState`, `g_pMidiPlayer`, `MidiStreamOpenAndPrimeBuffers`, `MidiStreamCallback`, `MidiFileReaderAndSMFParserHelpers`, `MidiTrackBufferRefill`, `MidiSourceOpenHelper`, `MidiSourceCloseHelper`, `MidiSourceRawReadHelper`, `MidiSourceSizeReadyHelper`, `MidiReaderConstructorInit`, `MidiParseSuccessWrapper`, `MidiDocumentRelease`, `MidiSMFLoadAndStreamFillHelpers`, and `MidiPlayerReadOnlyData`.
- Opened relevant central executed reports: `B011/0001CF-MidiPlayerAndWinMMHelpers-source-quality.md`, `B001/0002BU-0002BV-0002C6-0002C7-MidiSMFParserStreamSourceQuality.md`, `B003/0002B2-MidiSMFParserScratchGlobals-source-quality.md`, `B001/0002C1-MidiSourceSeekHelper-empty-emitter-source-quality.md`, plus matching rows from `B006`, `B007`, `B008`, and `B012` reports as generated/support evidence.
- Historical A-agent notes for `0002BX`, `0002BZ`, `0002C0`, and `0002C2-0002C5` were treated as leads only and reconciled against current MCP.

Negative checks:

- MCP confirms zero entry xrefs for raw helper starts `0x00526ce0`, `0x00526f10`, `0x00526f60`, and `0x00527040`.
- Current generated output was searched for `MidiReadRaw(`, `bytesRead != firstRead`, and `MidiOpenSource(` to find stale caller tests.
- Current MCP `get_bytes` contradicts prior `0xffffffff` initialization wording for `0x0069b500`, `0x0069b828`, and `0x0069b870`.

Skipped checks during report-only research:

- Validators were intentionally deferred until supervisor acceptance. The implementation callback validator results are recorded below.
- No broad MCP scans were run. The assignment needed exact-address evidence, so calls were bounded to target rows and support addresses.

## Current Empty-Marker Inventory And Disposition

| UID | Path | Current marker | First-batch disposition |
| --- | --- | --- | --- |
| `00008A` | `by-class/MidiPlayer.md` | Empty class aggregate marker | Candidate: formal no-code marker; class aggregate should not duplicate method/helper bodies. |
| `0000T9` | `by-global/MidiPlayerWinMMState.md` | Empty global aggregate marker | Candidate: formal no-code marker; actual state declarations belong on exact data children. |
| `0002B1` | `by-memory/0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals.md` | Empty data declaration marker | Follow-up: shared declaration block needed, but current zero-byte evidence and stale [UID:0002B2] initializers must be reconciled first. |
| `0000RM` | `by-global/g_pMidiPlayer.md` | Empty global aggregate marker | Candidate: formal no-code marker; exact storage declaration belongs on [UID:00029A]. |
| `00029A` | `by-memory/0x0067ab4c-0x0067ab50.g_pMidiPlayer.md` | Empty exact singleton storage marker | Candidate: formal global pointer definition. |
| `0001CE` | `by-memory/0x00525920-0x00525b0d.MidiStreamOpenAndPrimeBuffers.md` | Empty stream-open function marker | Follow-up: formal C++ is likely, but depends on [UID:0002B1] stream-buffer declarations and state constants. |
| `0001CG` | `by-memory/0x00525be0-0x00525dbb.MidiStreamCallback.md` | Empty callback function marker | Follow-up: formal C++ is likely, but depends on [UID:0002B1] state enum/stream-buffer declarations. |
| `00023B` | `by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md` | Empty aggregate marker | Candidate: formal no-code marker; exact children own bodies. |
| `0002BX` | `by-memory/0x00526ce0-0x00526d9a.MidiTrackBufferRefill.md` | Empty raw helper marker | Candidate: formal C++ as retained raw private helper. |
| `0002BZ` | `by-memory/0x00526f10-0x00526f57.MidiSourceOpenHelper.md` | Empty raw helper marker | Follow-up: current generated [UID:0002C7] abstracts source-open incorrectly; repair open/size strategy before adding this body. |
| `0002C0` | `by-memory/0x00526f60-0x00526f97.MidiSourceCloseHelper.md` | Empty raw helper marker | Candidate: formal C++ as retained raw private helper. |
| `0002C2` | `by-memory/0x00527000-0x00527039.MidiSourceRawReadHelper.md` | Empty modeled helper marker | Candidate: formal C++ plus support fixes to raw-read caller polarity. |
| `0002C3` | `by-memory/0x00527040-0x00527078.MidiSourceSizeReadyHelper.md` | Empty raw helper marker | Candidate: formal C++ as retained raw private helper. |
| `0002C4` | `by-memory/0x00527080-0x005270b5.MidiReaderConstructorInit.md` | Empty initializer marker | Follow-up: should be represented with the shared `MidiDocument` declaration/constructor route after [UID:0002B1] is repaired. |
| `0002C5` | `by-memory/0x005270c0-0x005270d5.MidiParseSuccessWrapper.md` | Empty tiny wrapper marker | Candidate: formal C++ wrapper around `MidiLoadDocument`. |
| `0001CI` | `by-memory/0x005270e0-0x005271a3.MidiDocumentRelease.md` | Empty document-release marker | Candidate: formal C++ cleanup helper. |
| `00023C` | `by-memory/0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers.md` | Empty aggregate marker | Candidate: formal no-code marker; exact children own bodies. |
| `00025W` | `by-memory/0x0061fafc-0x0061fb74.MidiPlayerReadOnlyData.md` | Empty read-only data marker | Candidate: formal no-code marker; vtable/literals rebuild through class declaration and function bodies. |

## Candidate Batch: Exact Formal C++ / No-Code Text

### [UID:00008A] by-class/MidiPlayer.md

Recommended formal no-code marker:

```cpp
// MidiPlayer class-level source is documented on this aggregate page, but this
// page does not own a standalone emitted body in MidiPlayer.cpp. Exact method
// bodies and private helpers emit from the by-memory child pages, while vtable
// bytes rebuild from the class declaration/header route when that route is
// modeled.
```

Proof: current generated output already emits constructor/destructor/toggle/stop method bodies from exact by-memory children [UID:00041J], [UID:00041L], and [UID:00041M]. The class page documents the 12-byte object and source route; duplicating method bodies here would double-emit.

### [UID:0000T9] by-global/MidiPlayerWinMMState.md

Recommended formal no-code marker:

```cpp
// MidiPlayerWinMMState is the documentation owner for the WinMM/static MIDI
// state family. It intentionally does not duplicate storage definitions here;
// exact data declarations belong to the child data pages that cover the concrete
// addresses, currently [UID:0002B1] and [UID:0002B2].
```

Proof: [UID:0000T9] is a global-state map and route aggregate. Current generated output already emits [UID:0002B2] through it, and [UID:0002B1] is the correct exact page for the `0x0069b500-0x0069b870` declarations after the zero-initialization conflict is fixed.

### [UID:0000RM] by-global/g_pMidiPlayer.md

Recommended formal no-code marker:

```cpp
// g_pMidiPlayer is documented here as the process-wide MidiPlayer singleton.
// The concrete storage definition is emitted by the exact backing data page
// [UID:00029A], so this symbol-level page must not duplicate it.
```

Proof: current MCP shows the exact storage at `0x0067ab4c` is a zero-initialized four-byte slot; [UID:00029A] is the backing data page and emits through this global page.

### [UID:00029A] by-memory/0x0067ab4c-0x0067ab50.g_pMidiPlayer.md

Recommended metadata: `COMPLETION:87 -> 88`, `CONFIDENCE:90 -> 91`, keep `CANONICAL_OWNER:0000RM`, keep `RECONSTRUCTABLE:TRUE`, keep `EMITTER_UIDS:0000RM`.

Recommended formal C++:

```cpp
MidiPlayer* g_pMidiPlayer = NULL;
```

Proof: current MCP `get_bytes 0x0067ab4c size 4` returns zero bytes, and `xrefs_to 0x0067ab4c` includes constructor publish/clear refs at `0x00525dff`/`0x00525e06`, destructor clear at `0x00525f1e`, compiler cleanup refs, and representative application/UI consumers. This is source-declared singleton storage, not a vtable or compiler-only artifact.

### [UID:00023B] by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md

Recommended formal no-code marker:

```cpp
// This MIDI reader/parser range is an inventory aggregate. Exact child pages
// emit the source bodies for the helpers inside this island; the aggregate must
// not duplicate child output.
```

Proof: current aggregate [UID:00023B] nests exact children for every modeled or raw helper in `0x00526650-0x005270d5`. Several children already emit formal C++; this first batch adds more child output and caller-polarity fixes.

### [UID:0002BX] by-memory/0x00526ce0-0x00526d9a.MidiTrackBufferRefill.md

Recommended metadata: `COMPLETION:85 -> 87`, `CONFIDENCE:90` unchanged. Keep owner/emitter route `0000LD`.

Recommended formal C++:

```cpp
static int MidiRefillTrackBuffer(MidiDocument* document, MidiTrackState* track)
{
    DWORD sourcePosition;
    DWORD bytesToRead;
    DWORD bytesRead;
    int readOk;

    if (track->bytesRemaining == 0) {
        return 1;
    }

    track->cursor = track->buffer;

    if (document->datFileSource != 0) {
        document->datFile.Seek(track->sourceOffset, FILE_BEGIN);
        sourcePosition = document->datFile.Tell();
    } else {
        sourcePosition = SetFilePointer(document->fileHandle,
                                        track->sourceOffset,
                                        NULL,
                                        FILE_BEGIN);
    }

    if (sourcePosition == INVALID_SET_FILE_POINTER) {
        return 1;
    }

    bytesToRead = track->bytesRemaining;
    if (bytesToRead > 0x400) {
        bytesToRead = 0x400;
    }

    track->bufferedBytes = bytesToRead;

    if (document->datFileSource != 0) {
        bytesRead = bytesToRead;
        readOk = document->datFile.Read(track->buffer, bytesToRead);
    } else {
        bytesRead = bytesToRead;
        readOk = ReadFile(document->fileHandle,
                          track->buffer,
                          bytesToRead,
                          &bytesRead,
                          NULL);
    }

    track->bytesRemaining -= bytesRead;
    track->bufferedBytes = bytesRead;
    track->sourceOffset = sourcePosition + bytesRead;

    if (readOk == 0 || bytesRead == 0) {
        return 1;
    }

    return 0;
}
```

Proof: current MCP disassembly for `0x00526ce0` shows a raw function-shaped body with no IDA function object and no xrefs, but complete source logic: reset cursor from `track+0x0c`, seek to `track+0x20`, clamp remaining bytes at `0x400`, read through DATFile slot `+0x20` or Win32 `ReadFile`, update `+0x08`, `+0x20`, and `+0x24`, return `0` on successful nonzero read and `1` otherwise.

### [UID:0002C0] by-memory/0x00526f60-0x00526f97.MidiSourceCloseHelper.md

Recommended metadata: `COMPLETION:85 -> 87`, `CONFIDENCE:90` unchanged. Keep owner/emitter route `0000LD`.

Recommended formal C++:

```cpp
static void MidiCloseSource(MidiDocument* document)
{
    if (document->datFileSource != 0) {
        if (document->datFile.IsOpen()) {
            document->datFile.Close();
        }
        return;
    }

    if (document->fileHandle != INVALID_HANDLE_VALUE) {
        CloseHandle(document->fileHandle);
        document->fileHandle = INVALID_HANDLE_VALUE;
    }
}
```

Proof: current MCP disassembly for `0x00526f60` shows a raw close body with no IDA function object and no xrefs. It checks `this+0x14`, validates the embedded DATFile/source at `this+0x18` through `sub_49C540`, tail-jumps through vtable slot `+0x10` when active, otherwise closes `this+0x2c` with `CloseHandle` and stores `0xffffffff`.

### [UID:0002C2] by-memory/0x00527000-0x00527039.MidiSourceRawReadHelper.md

Recommended metadata: `COMPLETION:86 -> 88`, `CONFIDENCE:89 -> 91`. Keep owner/emitter route `0000LD`.

Recommended formal C++:

```cpp
static int MidiReadRaw(MidiDocument* document, void* buffer, DWORD bytesToRead, DWORD* bytesRead)
{
    if (document->datFileSource != 0) {
        *bytesRead = bytesToRead;
        return document->datFile.Read(buffer, bytesToRead);
    }

    return ReadFile(document->fileHandle, buffer, bytesToRead, bytesRead, NULL);
}
```

Proof: current MCP decompiles `sub_527000` exactly as a read primitive. The key correction is polarity: it returns the underlying DATFile/`ReadFile` result. Current MCP decompilation of callers [UID:0002BY] and [UID:0002C7] checks `!v8 || bytesRead != requested`, so generated callers must test `MidiReadRaw(...) == 0` for failure, not `!= 0`.

Required support C++ fixes:

- In [UID:0002BY] `by-memory/0x00526da0-0x00526f09.MidiTrackBufferPrimeReset.md`, replace:

```cpp
if (MidiReadRaw(document, track->buffer, firstRead, &bytesRead) != 0 ||
    bytesRead != firstRead) {
    return;
}
```

with:

```cpp
if (MidiReadRaw(document, track->buffer, firstRead, &bytesRead) == 0 ||
    bytesRead != firstRead) {
    return;
}
```

- In [UID:0002C7] `by-memory/0x005273a0-0x005277bb.MidiSMFDocumentLoadHelper.md`, replace the same `MidiReadRaw(...) != 0` failure check with `MidiReadRaw(...) == 0`.

### [UID:0002C3] by-memory/0x00527040-0x00527078.MidiSourceSizeReadyHelper.md

Recommended metadata: `COMPLETION:86 -> 88`, `CONFIDENCE:89 -> 90`. Keep owner/emitter route `0000LD`.

Recommended formal C++:

```cpp
static int MidiSourceIsReady(MidiDocument* document)
{
    if (document->datFileSource != 0) {
        return document->datFile.IsOpen() != 0;
    }

    if (document->fileHandle == INVALID_HANDLE_VALUE) {
        return 0;
    }

    document->sourceSize = GetFileSize(document->fileHandle, NULL);
    return document->sourceSize != INVALID_FILE_SIZE;
}
```

Proof: current MCP disassembly for `0x00527040` shows raw non-function source-ready logic: DATFile path calls `sub_49C540` on `this+0x18` and returns `1` if active; Win32 path rejects handle `-1`, calls `GetFileSize`, writes `this+0x00`, rejects `0xffffffff`, and returns `1` otherwise.

### [UID:0002C5] by-memory/0x005270c0-0x005270d5.MidiParseSuccessWrapper.md

Recommended metadata: `COMPLETION:86 -> 88`, `CONFIDENCE:89 -> 90`. Keep owner/emitter route `0000LD`.

Recommended formal C++:

```cpp
static BOOL MidiLoadDocumentSucceeded(MidiDocument* document, const wchar_t* path)
{
    return MidiLoadDocument(document, path) == 1;
}
```

Proof: current MCP decompiles `sub_5270C0` as `return sub_5273A0(this, a2) == 1;`, with one stream-open caller at `0x52599d`. This is source-authored wrapper logic, not an aggregate or compiler glue. The descriptive wrapper name keeps the accepted `MidiLoadDocument` child name without pretending the original wrapper spelling is recovered.

### [UID:0001CI] by-memory/0x005270e0-0x005271a3.MidiDocumentRelease.md

Recommended metadata: `COMPLETION:85 -> 88`, `CONFIDENCE:90` unchanged. Keep owner/emitter route `0000LD`.

Recommended formal C++:

```cpp
static void MidiReleaseDocument(MidiDocument* document)
{
    if (document->datFileSource != 0) {
        if (document->datFile.IsOpen()) {
            document->datFile.Close();
        }
    } else if (document->fileHandle != INVALID_HANDLE_VALUE) {
        CloseHandle(document->fileHandle);
        document->fileHandle = INVALID_HANDLE_VALUE;
    }

    if (document->tracks != NULL) {
        for (DWORD i = 0; i < document->trackCount; ++i) {
            MidiTrackState* track = document->tracks + i;
            if (track->buffer != NULL) {
                HGLOBAL block = GlobalHandle(track->buffer);
                GlobalUnlock(block);
                block = GlobalHandle(track->buffer);
                GlobalFree(block);
            }
        }

        HGLOBAL table = GlobalHandle(document->tracks);
        GlobalUnlock(table);
        table = GlobalHandle(document->tracks);
        GlobalFree(table);
        document->tracks = NULL;
    }
}
```

Proof: current MCP decompiles `sub_5270E0` with three direct callers and exact cleanup behavior: close active DATFile/source or Win32 handle, walk `trackCount` 40-byte entries, free per-track buffers at entry `+0x0c`, free the track table, and clear the table pointer.

### [UID:00023C] by-memory/0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers.md

Recommended formal no-code marker:

```cpp
// This SMF load/fill range is an inventory aggregate. Exact children
// [UID:0002C6] and [UID:0002C7] emit the source bodies for the modeled
// stream-fill and document-load helpers; the aggregate must not duplicate them.
```

Proof: [UID:00023C] is a two-child aggregate. Current generated output already emits [UID:0002C6] and [UID:0002C7].

### [UID:00025W] by-memory/0x0061fafc-0x0061fb74.MidiPlayerReadOnlyData.md

Recommended formal no-code marker:

```cpp
// MidiPlayer read-only data is source-declared/generated-binary output. The
// vtable rebuilds from the MidiPlayer class declaration, and the tracked string
// literals are emitted at their use sites in the MidiPlayer helper bodies. This
// page must not hand-port the raw vtable or pooled literal bytes.
```

Proof: current MCP bytes show vtable pointer bytes and UTF-16 string fragments. The `Midi\\%s` and `%d.mid` literals are already represented in [UID:0001CH] track-selection C++; vtable bytes are compiler output from class declarations.

## Remaining Rows: Follow-Up Batch Plan

These rows are not recommended for implementation in the first bounded batch. They are not no-improvement exceptions; they are exact second-batch work items with current blockers and next actions.

| UID | Reason excluded from first batch | Exact next repair |
| --- | --- | --- |
| `0002B1` | Current MCP shows zero bytes for `0x0069b500`, `0x0069b828`, and `0x0069b870`, contradicting older `0xffffffff` initializer text and current [UID:0002B2] emitted initializers. This page must provide shared declarations, but doing so before reconciling zero-init would bake conflicting state into `MidiPlayer.cpp`. | Recheck/repair [UID:0002B1] and [UID:0002B2] together. Move or normalize shared declarations so `MidiDocument`, `MidiTrackState`, `MidiStreamWriteContext`, `MidiStreamBuffer`, state constants, and zero-initialized storage emit before helper bodies. |
| `0001CE` | Current MCP supplies a modeled body, but the formal source depends on `MidiStreamBuffer`, `MidiStreamWriteContext`, `MIDI_STREAM_STATE_*`, and [UID:0002B1] state declarations. | After [UID:0002B1] declaration repair, populate `MidiStreamOpenAndPrimeBuffers` using current decompile: open stream, allocate two 0x400 buffers, parse document, set time division, initialize channel volumes, fill/prepare/submit up to two buffers, return `0`, `1`, or `-1`. |
| `0001CG` | Current MCP supplies a modeled callback body, but the formal source depends on the same state declarations and message/state constants. | After [UID:0002B1] declaration repair, populate `MidiStreamCallback` with `MOM_DONE`/`MOM_POSITIONCB` handling, two-buffer return/refill state, controller-7 volume table update, and `MidiFillStreamBuffer`/`MidiReleaseDocument` paths. |
| `0002BZ` | Current raw body returns the adapter open result or Win32 handle, while current generated [UID:0002C7] abstracts source-open with `if (MidiOpenSource(...) != 0) return 0;`. Adding `MidiOpenSource` now would either contradict raw return semantics or preserve the generated abstraction bug. | Repair [UID:0002C7] source-open abstraction first: either inline open/size exactly as `sub_5273A0` decompiles or name the raw helper with handle/open-result semantics distinct from the loader's boolean failure check. |
| `0002C4` | This is the `MidiDocument`/reader initializer and should be represented with the shared `MidiDocument` declaration/constructor route. It depends on the [UID:0002B1] shared declaration repair and the zero-init reconciliation. | After [UID:0002B1] is repaired, implement either `MidiDocument::MidiDocument()` or a retained initializer helper with exact `DATFile` construction, `datFileSource = 0`, `fileHandle = INVALID_HANDLE_VALUE`, `tempoTickCache/current timing = 0`, and default `100` field. |

## Heuristic / Inference Reanalysis And Validation

### Ownership and source placement

Best source route remains [UID:0000LD] `MidiPlayer.md` / `NexusTK/audio/MidiPlayer.cpp`.

Evidence for:

- The by-file page is already a valid generated root with `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/audio/"`.
- The empty markers all route directly or through [UID:0000T9]/[UID:0000RM] to [UID:0000LD].
- Current MCP xrefs keep stream-open, callback, reset, document release, reader/source helpers, and SMF load/fill inside the WinMM MIDI family.
- Existing docs and executed reports consistently reject `SoundManager` for this WinMM MIDI path.

Evidence against:

- A private `MidiSMFDocument.cpp` helper source remains historically plausible for the reader/SMF helpers.
- No recovered filename, by-file page, source-tree entry, or stronger owner exists for that split.

Decision: keep [UID:0000LD] as direct owner/emitter for this batch. Preserve possible private SMF source split only as a source-history caveat.

### Formal C++ versus no-code

Rows that are aggregates or source-declared/generated-binary data receive formal marker text, not blank C++:

- [UID:00008A] class aggregate;
- [UID:0000T9] WinMM state map;
- [UID:0000RM] singleton symbol map;
- [UID:00023B] reader/parser aggregate;
- [UID:00023C] load/fill aggregate;
- [UID:00025W] vtable/literal read-only data.

Rows that have exact source-authored bodies and do not depend on the unresolved stream-buffer declaration block receive formal C++ in the first batch:

- [UID:00029A], [UID:0002BX], [UID:0002C0], [UID:0002C2], [UID:0002C3], [UID:0002C5], [UID:0001CI].

Rows that would require the unresolved [UID:0002B1] shared declaration repair or source-open abstraction repair are explicitly bounded follow-up:

- [UID:0002B1], [UID:0001CE], [UID:0001CG], [UID:0002BZ], [UID:0002C4].

### Rejected alternatives

- Mark all 18 empty markers as no-code: rejected. Several exact child pages are source-authored functions/data and have valid owner/emitter routes.
- Fill [UID:0001CE] and [UID:0001CG] immediately from decompilation: rejected for this bounded batch because current shared state declarations are contradicted by current MCP zero-byte evidence and the callback/open bodies depend on those declarations.
- Emit [UID:0002B1] with the current generated [UID:0002B2] `0xffffffff` initializer convention: rejected because current MCP reads zero bytes at the relevant state/scratch addresses.
- Leave [UID:0002C2] blank due to inferred `MidiDocument` names: rejected. Current MCP proves exact body, direct caller, return polarity, and source-family route. The existing generated code already depends on `MidiReadRaw`; the blocker is caller polarity, not absence of a safe helper body.
- Move reader/source helpers to `DATFile`: rejected. They choose between embedded DATFile and Win32 handle paths inside a MIDI document/source abstraction.
- Move helper rows to [UID:00008A] `MidiPlayer` class: rejected. The receiver is `MidiDocument`/file-static state, not the 12-byte `MidiPlayer` object.

## Positive Evidence Summary

- The generated file contains current 18 empty markers, all in the `MidiPlayer.cpp` route.
- [UID:0000LD] and the relevant class/global/memory pages already clear the active owner/emitter gate.
- Current MCP confirms exact modeled functions for stream-open, callback, raw read, initializer, wrapper, release, and load/fill helpers.
- Current MCP confirms raw helper bodies and no-entry-xref caveats for refill/open/close/size helpers.
- Current MCP confirms [UID:00029A] zero-initialized singleton storage and [UID:00025W] vtable/string data.
- Current MCP exposes the raw-read return polarity, allowing a concrete support repair instead of leaving that row as an unresolved blocker.

## Negative Evidence Summary

- No direct entry xrefs for raw helper starts `0x00526ce0`, `0x00526f10`, `0x00526f60`, or `0x00527040`.
- No current evidence for a recovered `MidiSMFDocument.cpp` source file.
- No current by-type page or recovered IDA type for `MidiDocument`, `MidiTrackState`, `MidiStreamWriteContext`, or the source adapter.
- Current generated source for [UID:0002C7] abstracts source-open in a way not directly present in `sub_5273A0`.
- Current MCP byte evidence contradicts older `0xffffffff` scratch/state initializer assumptions.

## Recommended Target Doc Changes

Target path: `by-file/MidiPlayer.md`

Recommended after acceptance:

- Add a 2026-06-30 B013 bounded empty-emitter batch note.
- Record that the current generated file had 18 empty markers at command id `000000001773`, refreshed `2026-06-30T00:05:54-04:00`.
- Record first-batch candidate rows and remaining follow-up rows exactly as in the inventory.
- Preserve source route [UID:0000LD] / `NexusTK/audio/MidiPlayer.cpp`, no score change.
- Add current MCP caveat: `MidiReadRaw` returns nonzero success and [UID:0002BY]/[UID:0002C7] draft tests must use `== 0` for failure.
- Add current MCP caveat: `0x0069b500`, `0x0069b828`, and `0x0069b870` are zero in `supervisor_resume_20260629`; [UID:0002B1]/[UID:0002B2] declarations need a follow-up consistency repair.

## Recommended Support Doc Changes

Candidate-batch support docs:

- `by-class/MidiPlayer.md`: add formal no-code marker and note that class aggregate remains a declaration/ownership page; no score change.
- `by-global/MidiPlayerWinMMState.md`: add formal no-code marker and current zero-byte caveat for state declaration follow-up; no score change.
- `by-global/g_pMidiPlayer.md`: add formal no-code marker pointing to [UID:00029A]; no score change.
- `by-memory/0x0067ab4c-0x0067ab50.g_pMidiPlayer.md`: add singleton definition, raise to `88/91`.
- `by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md`: add aggregate no-code marker, batch/follow-up inventory, and raw-read polarity note; no score change.
- `by-memory/0x00526ce0-0x00526d9a.MidiTrackBufferRefill.md`: add formal C++ and score `87/90`.
- `by-memory/0x00526f60-0x00526f97.MidiSourceCloseHelper.md`: add formal C++ and score `87/90`.
- `by-memory/0x00527000-0x00527039.MidiSourceRawReadHelper.md`: add formal C++, score `88/91`, and explicit nonzero-success note.
- `by-memory/0x00527040-0x00527078.MidiSourceSizeReadyHelper.md`: add formal C++ and score `88/90`.
- `by-memory/0x005270c0-0x005270d5.MidiParseSuccessWrapper.md`: add formal C++ and score `88/90`.
- `by-memory/0x005270e0-0x005271a3.MidiDocumentRelease.md`: add formal C++ and score `88/90`.
- `by-memory/0x00526da0-0x00526f09.MidiTrackBufferPrimeReset.md`: support C++ fix only, changing `MidiReadRaw(...) != 0` to `MidiReadRaw(...) == 0`; no score change required.
- `by-memory/0x005273a0-0x005277bb.MidiSMFDocumentLoadHelper.md`: same support C++ fix for raw-read failure test and note that source-open abstraction remains second-batch follow-up; no score change required.
- `by-memory/0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers.md`: add aggregate no-code marker; no score change.
- `by-memory/0x0061fafc-0x0061fb74.MidiPlayerReadOnlyData.md`: add formal no-code marker; no score change.

Excluded from first-batch edits:

- `by-memory/0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals.md`
- `by-memory/0x00525920-0x00525b0d.MidiStreamOpenAndPrimeBuffers.md`
- `by-memory/0x00525be0-0x00525dbb.MidiStreamCallback.md`
- `by-memory/0x00526f10-0x00526f57.MidiSourceOpenHelper.md`
- `by-memory/0x00527080-0x005270b5.MidiReaderConstructorInit.md`

## Score And Metadata Recommendation

No by-file score change is recommended for [UID:0000LD]; the batch improves generated-output readiness but leaves five active follow-up rows.

Recommended score changes for candidate docs:

| UID | Current | Recommended | Reason |
| --- | ---: | ---: | --- |
| `00029A` | `87/90` | `88/91` | Exact singleton declaration and current zero-byte proof. |
| `0002BX` | `85/90` | `87/90` | Formal retained raw refill C++ with current raw disassembly proof. |
| `0002C0` | `85/90` | `87/90` | Formal retained raw close C++ with current raw disassembly proof. |
| `0002C2` | `86/89` | `88/91` | Formal raw-read C++ plus caller-polarity proof. |
| `0002C3` | `86/89` | `88/90` | Formal raw size/ready C++ with current raw disassembly proof. |
| `0002C5` | `86/89` | `88/90` | Formal wrapper C++ with current decompilation proof. |
| `0001CI` | `85/90` | `88/90` | Formal release C++ with current cleanup/deallocation proof. |

No metadata changes are recommended for owner/emitter fields in the first batch. No new child pages, splits, renames, or by-project-structure edits are recommended.

## Open Questions With Attempted Resolution

- Shared state declaration and initializers: current MCP zero-byte checks make older `0xffffffff` initializer wording unsafe. Resolution: exclude [UID:0002B1] and [UID:0002B2] declaration repair from this first batch, but record exact second-batch repair.
- Stream-open/callback C++: current MCP provides decompilation, but safe formal code needs repaired state declarations and constants. Resolution: second-batch formal C++ after [UID:0002B1] repair.
- Source-open helper: current raw helper return semantics conflict with generated [UID:0002C7] abstraction. Resolution: second-batch repair must decide inline-open versus retained helper with handle/open-result semantics.
- `MidiDocument`/`MidiTrackState` original names: no original names recovered; accepted descriptive names remain valid for candidate helper code, with confidence caps.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | Current generated `MidiPlayer.cpp` has 18 empty markers at command id `000000001773`. | High | Generated file header and marker lines 1091-1125. | `by-file/MidiPlayer.md` status/change note | incorporate | applied: `by-file/MidiPlayer.md` section `2026-06-30 B013 Bounded Empty-Emitter Batch` records the pre-batch header and 18-row inventory; validator `000000001907`, `2026-06-30T00:59:46-04:00`, exit 0, ok 1. |
| C02 | [UID:0000LD] remains the correct source root and owner/emitter route. | High | by-file metadata, generated coverage, MCP xrefs/callees. | `by-file/MidiPlayer.md` | already-present | already-present: `by-file/MidiPlayer.md` metadata remains `CANONICAL_OWNER:FILE`, source path `NexusTK/audio/`, no score change; validator `000000001907`, exit 0, ok 1. |
| C03 | [UID:00008A] should receive a formal aggregate no-code marker, not method body duplication. | High | Existing method bodies emit from exact children. | `by-class/MidiPlayer.md` C++ block/status | incorporate | applied: `by-class/MidiPlayer.md` formal block now contains the aggregate no-code marker and status text; validator `000000001908`, `2026-06-30T00:59:48-04:00`, exit 0, ok 1; final generated file emits marker text as comments at UID `00008A`. |
| C04 | [UID:0000T9] should receive a formal aggregate no-code marker. | High | Global map routes children [UID:0002B1]/[UID:0002B2]. | `by-global/MidiPlayerWinMMState.md` C++ block/status | incorporate | applied: `by-global/MidiPlayerWinMMState.md` formal block has the no-code marker plus `[[CHILDREN]]` routing so [UID:0002B2] remains emitted; final validator `000000001941`, `2026-06-30T01:04:46-04:00`, exit 0, ok 1, generated refresh completed. |
| C05 | Current MCP zero-byte evidence blocks first-batch [UID:0002B1] declaration repair. | High | `get_bytes` zero at `0x0069b500`, `0x0069b828`, `0x0069b870`. | `by-global/MidiPlayerWinMMState.md`, `by-file/MidiPlayer.md`, follow-up section | incorporate | applied: `by-file/MidiPlayer.md` batch caveats and `by-global/MidiPlayerWinMMState.md` reconstruction caveats record the zero-byte evidence and [UID:0002B1]/[UID:0002B2] follow-up; final validators `000000001907` and `000000001941`, exit 0, ok 1. |
| C06 | [UID:0000RM] should receive a formal symbol-map no-code marker. | High | Exact storage owned by [UID:00029A]. | `by-global/g_pMidiPlayer.md` C++ block/status | incorporate | applied: `by-global/g_pMidiPlayer.md` formal block points to [UID:00029A] and includes `[[CHILDREN]]` so exact storage emits; final validator `000000001942`, `2026-06-30T01:04:56-04:00`, exit 0, ok 1, generated refresh completed. |
| C07 | [UID:00029A] should emit `MidiPlayer* g_pMidiPlayer = NULL;`. | High | MCP zero bytes and singleton xrefs. | `by-memory/0x0067ab4c-0x0067ab50.g_pMidiPlayer.md` C++ block | incorporate | applied: [UID:00029A] metadata is `88/91`, formal code is `MidiPlayer* g_pMidiPlayer = NULL;`, owner/emitter unchanged; validator `000000001911`, `2026-06-30T00:59:53-04:00`, exit 0, ok 1; final generated file emits it at lines 66-67. |
| C08 | [UID:0001CE] remains follow-up because stream-buffer declarations are not repaired. | Medium-high | MCP modeled body plus [UID:0002B1] declaration blocker. | `by-file/MidiPlayer.md`, `by-memory/0x00525920-0x00525b0d...md` | incorporate | applied/excluded-with-reason: `by-file/MidiPlayer.md` lists [UID:0001CE] as follow-up; direct [UID:0001CE] edit was excluded by accepted bounded first-batch scope; validator `000000001907`, exit 0, ok 1. |
| C09 | [UID:0001CG] remains follow-up because callback constants/state declarations are not repaired. | Medium-high | MCP modeled body plus [UID:0002B1] declaration blocker. | `by-file/MidiPlayer.md`, `by-memory/0x00525be0-0x00525dbb...md` | incorporate | applied/excluded-with-reason: `by-file/MidiPlayer.md` lists [UID:0001CG] as follow-up; direct [UID:0001CG] edit was excluded by accepted bounded first-batch scope; validator `000000001907`, exit 0, ok 1. |
| C10 | [UID:00023B] should receive a formal aggregate no-code marker. | High | Exact child pages cover bodies. | `by-memory/0x00526650-0x005270d5...md` | incorporate | applied: [UID:00023B] formal block is an inventory aggregate no-code marker and the batch section records child/follow-up rows plus raw-read polarity; validator `000000001912`, `2026-06-30T00:59:55-04:00`, exit 0, ok 1. |
| C11 | [UID:0002BX] should emit retained raw `MidiRefillTrackBuffer` C++. | Medium-high | MCP raw disassembly and no-entry-xref caveat. | `by-memory/0x00526ce0-0x00526d9a...md` | incorporate | applied: [UID:0002BX] metadata is `87/90` and formal C++ emits `MidiRefillTrackBuffer`; validator `000000001913`, `2026-06-30T00:59:57-04:00`, exit 0, ok 1; final generated file contains the helper body and no empty marker for UID `0002BX`. |
| C12 | [UID:0002BZ] remains follow-up because raw return semantics conflict with generated loader abstraction. | High | MCP raw disassembly and `sub_5273A0` decompilation. | `by-file/MidiPlayer.md`, `by-memory/0x00526f10-0x00526f57...md` | incorporate | applied/excluded-with-reason: `by-file/MidiPlayer.md` follow-up list and [UID:0002C7] Open Questions record the source-open abstraction blocker; direct [UID:0002BZ] edit was excluded by accepted bounded first-batch scope; validators `000000001907` and `000000001920`, exit 0, ok 1. |
| C13 | [UID:0002C0] should emit retained raw `MidiCloseSource` C++. | Medium-high | MCP raw disassembly. | `by-memory/0x00526f60-0x00526f97...md` | incorporate | applied: [UID:0002C0] metadata is `87/90` and formal C++ emits `MidiCloseSource`; validator `000000001914`, `2026-06-30T00:59:59-04:00`, exit 0, ok 1. |
| C14 | [UID:0002C2] should emit `MidiReadRaw` with nonzero-success return. | High | MCP decompile `sub_527000`; caller decompilations use `!v8`. | `by-memory/0x00527000-0x00527039...md` | incorporate | applied: [UID:0002C2] metadata is `88/91`, formal C++ emits `MidiReadRaw`, and notes record nonzero-success semantics; validator `000000001915`, `2026-06-30T01:00:00-04:00`, exit 0, ok 1. |
| C15 | [UID:0002BY] and [UID:0002C7] must flip `MidiReadRaw` failure checks to `== 0`. | High | MCP decompile `sub_526DA0` and `sub_5273A0`. | `by-memory/0x00526da0-0x00526f09...md`, `by-memory/0x005273a0-0x005277bb...md` | incorporate | applied: [UID:0002BY] and [UID:0002C7] formal C++ now tests `MidiReadRaw(...) == 0` for failure; validators `000000001919`, `2026-06-30T01:00:07-04:00`, and `000000001920`, `2026-06-30T01:00:09-04:00`, exit 0, ok 1; final generated file contains the corrected tests. |
| C16 | [UID:0002C3] should emit retained raw size/ready C++. | Medium-high | MCP raw disassembly. | `by-memory/0x00527040-0x00527078...md` | incorporate | applied: [UID:0002C3] metadata is `88/90` and formal C++ emits `MidiSourceIsReady`; validator `000000001916`, `2026-06-30T01:00:02-04:00`, exit 0, ok 1. |
| C17 | [UID:0002C4] remains follow-up under shared `MidiDocument` declaration repair. | Medium-high | MCP static initializer and constructor decompile; [UID:0002B1] blocker. | `by-file/MidiPlayer.md`, `by-memory/0x00527080-0x005270b5...md` | incorporate | applied/excluded-with-reason: `by-file/MidiPlayer.md` lists [UID:0002C4] as follow-up under shared declaration/constructor routing; direct [UID:0002C4] edit was excluded by accepted bounded first-batch scope; validator `000000001907`, exit 0, ok 1. |
| C18 | [UID:0002C5] should emit a wrapper around `MidiLoadDocument`. | High | MCP decompile `sub_5270C0`. | `by-memory/0x005270c0-0x005270d5...md` | incorporate | applied: [UID:0002C5] metadata is `88/90` and formal C++ emits `MidiLoadDocumentSucceeded`; validator `000000001917`, `2026-06-30T01:00:04-04:00`, exit 0, ok 1. |
| C19 | [UID:0001CI] should emit `MidiReleaseDocument` cleanup C++. | High | MCP decompile and caller/callee evidence. | `by-memory/0x005270e0-0x005271a3...md` | incorporate | applied: [UID:0001CI] metadata is `88/90` and formal C++ emits `MidiReleaseDocument`; validator `000000001918`, `2026-06-30T01:00:05-04:00`, exit 0, ok 1. |
| C20 | [UID:00023C] should receive a formal aggregate no-code marker. | High | Exact child pages [UID:0002C6]/[UID:0002C7] emit bodies. | `by-memory/0x005271b0-0x005277bb...md` | incorporate | applied: [UID:00023C] formal block is an aggregate no-code marker naming child emitters [UID:0002C6]/[UID:0002C7]; validator `000000001921`, `2026-06-30T01:00:11-04:00`, exit 0, ok 1. |
| C21 | [UID:00025W] should receive formal no-code marker for vtable/literal data. | High | MCP bytes and existing string/vtable xrefs. | `by-memory/0x0061fafc-0x0061fb74...md` | incorporate | applied: [UID:00025W] formal block is a no-code marker for vtable/literal read-only data and notes explain class/use-site emission; validator `000000001922`, `2026-06-30T01:00:12-04:00`, exit 0, ok 1. |

## Validators Expected After Acceptance

Run from `E:\NTK\GhidraBridge\source-3\project-documentation` after edits:

> Executable block R001 was removed from this report and preserved verbatim in [0000LD-MidiPlayer-empty-emitter-family-source-quality-removed.md](0000LD-MidiPlayer-empty-emitter-family-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

After validators, inspect `auto-generated/NexusTK/audio/MidiPlayer.cpp` read-only:

- header command id/timestamp equal to or newer than the latest validator command;
- [UID:00029A], [UID:0002BX], [UID:0002C0], [UID:0002C2], [UID:0002C3], [UID:0002C5], and [UID:0001CI] no longer show empty markers;
- no-code aggregate/data markers appear as comments, not as `Empty Emitter Marker`;
- expected remaining empty markers are only [UID:0002B1], [UID:0001CE], [UID:0001CG], [UID:0002BZ], and [UID:0002C4] unless the supervisor expands the callback.

## Implementation Callback Results

Leases:

- Initial edit-batch lease command: `python .\tools\leaser\leaser.py B013 lease by-file/MidiPlayer.md by-class/MidiPlayer.md by-global/MidiPlayerWinMMState.md by-global/g_pMidiPlayer.md by-memory/0x0067ab4c-0x0067ab50.g_pMidiPlayer.md by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md by-memory/0x00526ce0-0x00526d9a.MidiTrackBufferRefill.md by-memory/0x00526f60-0x00526f97.MidiSourceCloseHelper.md by-memory/0x00527000-0x00527039.MidiSourceRawReadHelper.md by-memory/0x00527040-0x00527078.MidiSourceSizeReadyHelper.md by-memory/0x005270c0-0x005270d5.MidiParseSuccessWrapper.md by-memory/0x005270e0-0x005271a3.MidiDocumentRelease.md by-memory/0x00526da0-0x00526f09.MidiTrackBufferPrimeReset.md by-memory/0x005273a0-0x005277bb.MidiSMFDocumentLoadHelper.md by-memory/0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers.md by-memory/0x0061fafc-0x0061fb74.MidiPlayerReadOnlyData.md`; all 16 returned `Success`.
- Initial all-file unlease after the first validator batch returned `Rejected[No active lease]` for all 16 paths; `tools/leaser/Agents/current_leases.md` then showed no active B013 leases. This means the initial B013 leases were already absent/expired by cleanup time, not held by another agent.
- Corrective route-page leases: `python .\tools\leaser\leaser.py B013 lease by-global/MidiPlayerWinMMState.md by-global/g_pMidiPlayer.md`; both returned `Success`.
- Corrective route-page unlease: `python .\tools\leaser\leaser.py B013 unlease by-global/MidiPlayerWinMMState.md by-global/g_pMidiPlayer.md`; both returned `Success`.
- Final lease check: `tools/leaser/Agents/current_leases.md` reports no active B013 leases; any active leases listed belong to other agents on unrelated files.

Validator results, run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

| Path | Command id | Command timestamp | Exit | ok | Generated refresh state |
| --- | --- | --- | ---: | ---: | --- |
| `by-file/MidiPlayer.md` | `000000001907` | `2026-06-30T00:59:46-04:00` | 0 | 1 | deferred |
| `by-class/MidiPlayer.md` | `000000001908` | `2026-06-30T00:59:48-04:00` | 0 | 1 | deferred; pre-existing warning `missing_ref_uid 0003PF` |
| `by-global/MidiPlayerWinMMState.md` | `000000001909` | `2026-06-30T00:59:49-04:00` | 0 | 1 | deferred; superseded by rerun `000000001941` |
| `by-global/g_pMidiPlayer.md` | `000000001910` | `2026-06-30T00:59:51-04:00` | 0 | 1 | deferred; superseded by rerun `000000001942` |
| `by-memory/0x0067ab4c-0x0067ab50.g_pMidiPlayer.md` | `000000001911` | `2026-06-30T00:59:53-04:00` | 0 | 1 | deferred |
| `by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md` | `000000001912` | `2026-06-30T00:59:55-04:00` | 0 | 1 | deferred |
| `by-memory/0x00526ce0-0x00526d9a.MidiTrackBufferRefill.md` | `000000001913` | `2026-06-30T00:59:57-04:00` | 0 | 1 | deferred |
| `by-memory/0x00526f60-0x00526f97.MidiSourceCloseHelper.md` | `000000001914` | `2026-06-30T00:59:59-04:00` | 0 | 1 | deferred |
| `by-memory/0x00527000-0x00527039.MidiSourceRawReadHelper.md` | `000000001915` | `2026-06-30T01:00:00-04:00` | 0 | 1 | deferred; pre-existing warnings `missing_ref_uid 0003H3` |
| `by-memory/0x00527040-0x00527078.MidiSourceSizeReadyHelper.md` | `000000001916` | `2026-06-30T01:00:02-04:00` | 0 | 1 | deferred; pre-existing warnings `missing_ref_uid 0003H3` |
| `by-memory/0x005270c0-0x005270d5.MidiParseSuccessWrapper.md` | `000000001917` | `2026-06-30T01:00:04-04:00` | 0 | 1 | deferred |
| `by-memory/0x005270e0-0x005271a3.MidiDocumentRelease.md` | `000000001918` | `2026-06-30T01:00:05-04:00` | 0 | 1 | deferred |
| `by-memory/0x00526da0-0x00526f09.MidiTrackBufferPrimeReset.md` | `000000001919` | `2026-06-30T01:00:07-04:00` | 0 | 1 | deferred |
| `by-memory/0x005273a0-0x005277bb.MidiSMFDocumentLoadHelper.md` | `000000001920` | `2026-06-30T01:00:09-04:00` | 0 | 1 | deferred |
| `by-memory/0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers.md` | `000000001921` | `2026-06-30T01:00:11-04:00` | 0 | 1 | deferred |
| `by-memory/0x0061fafc-0x0061fb74.MidiPlayerReadOnlyData.md` | `000000001922` | `2026-06-30T01:00:12-04:00` | 0 | 1 | deferred |
| `by-global/MidiPlayerWinMMState.md --wait-generated` | `000000001941` | `2026-06-30T01:04:46-04:00` | 0 | 1 | completed |
| `by-global/g_pMidiPlayer.md --wait-generated` | `000000001942` | `2026-06-30T01:04:56-04:00` | 0 | 1 | completed |

Generated freshness inspection:

- Queue drain check: `python .\tools\validator.py --queue-status`, command id `000000001945`, `2026-06-30T01:12:26-04:00`, worker running, queued jobs `0`, processing jobs `0`, queued generated refresh jobs `0`, processing generated refresh jobs `0`.
- Final generated file header: `auto-generated/NexusTK/audio/MidiPlayer.cpp`, `validator-command-id: 000000001942`, `validator-refreshed-at: 2026-06-30T01:04:56-04:00`, `validator-refresh-source: foreground-generated-refresh`, source by-file UID `0000LD`.
- Final generated output includes [UID:00029A] `MidiPlayer* g_pMidiPlayer = NULL;`, emitted helper bodies for [UID:0002BX], [UID:0002C0], [UID:0002C2], [UID:0002C3], [UID:0002C5], and [UID:0001CI], corrected `MidiReadRaw(...) == 0` failure tests in [UID:0002BY]/[UID:0002C7], and aggregate no-code comments for [UID:00008A], [UID:0000T9], [UID:0000RM], [UID:00023B], [UID:00023C], and [UID:00025W].
- Remaining final empty markers are exactly [UID:0002B1] `by-memory\0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals.md`, [UID:0001CE] `by-memory\0x00525920-0x00525b0d.MidiStreamOpenAndPrimeBuffers.md`, [UID:0001CG] `by-memory\0x00525be0-0x00525dbb.MidiStreamCallback.md`, [UID:0002BZ] `by-memory\0x00526f10-0x00526f57.MidiSourceOpenHelper.md`, and [UID:0002C4] `by-memory\0x00527080-0x005270b5.MidiReaderConstructorInit.md`.

## Changed Files

Manual edits in this callback:

- `tools/leaser/Agents/Agent-B013/research/0000LD-MidiPlayer-empty-emitter-family-source-quality.md`
- `by-file/MidiPlayer.md`
- `by-class/MidiPlayer.md`
- `by-global/MidiPlayerWinMMState.md`
- `by-global/g_pMidiPlayer.md`
- `by-memory/0x0067ab4c-0x0067ab50.g_pMidiPlayer.md`
- `by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md`
- `by-memory/0x00526ce0-0x00526d9a.MidiTrackBufferRefill.md`
- `by-memory/0x00526f60-0x00526f97.MidiSourceCloseHelper.md`
- `by-memory/0x00527000-0x00527039.MidiSourceRawReadHelper.md`
- `by-memory/0x00527040-0x00527078.MidiSourceSizeReadyHelper.md`
- `by-memory/0x005270c0-0x005270d5.MidiParseSuccessWrapper.md`
- `by-memory/0x005270e0-0x005271a3.MidiDocumentRelease.md`
- `by-memory/0x00526da0-0x00526f09.MidiTrackBufferPrimeReset.md`
- `by-memory/0x005273a0-0x005277bb.MidiSMFDocumentLoadHelper.md`
- `by-memory/0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers.md`
- `by-memory/0x0061fafc-0x0061fb74.MidiPlayerReadOnlyData.md`

Validator-owned/generated side effects were not manually edited. `auto-generated/NexusTK/audio/MidiPlayer.cpp` was refreshed by validator command `000000001942` and inspected read-only.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation; supervisor accepted the bounded first batch and converted the goal to implementation callback.
- [x] Candidate target/support docs to update were enumerated: `by-file/MidiPlayer.md`, `by-class/MidiPlayer.md`, `by-global/MidiPlayerWinMMState.md`, `by-global/g_pMidiPlayer.md`, [UID:00029A], [UID:00023B], [UID:0002BX], [UID:0002C0], [UID:0002C2], [UID:0002C3], [UID:0002C5], [UID:0001CI], [UID:0002BY], [UID:0002C7], [UID:00023C], and [UID:00025W].
- [x] Current target state and actual evidence checked recorded: MCP session `supervisor_resume_20260629`, generated file header, tracker row, by-* docs, executed reports, lookup/xref/callee/decompile/disasm/get_bytes facts.
- [x] Complete empty-marker inventory recorded: 18 pre-batch rows, 13 candidate rows and 5 follow-up rows.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every candidate and follow-up claim; see ledger C01-C21.
- [x] Metadata/score changes applied: [UID:00029A] `88/91`, [UID:0002BX] `87/90`, [UID:0002C0] `87/90`, [UID:0002C2] `88/91`, [UID:0002C3] `88/90`, [UID:0002C5] `88/90`, [UID:0001CI] `88/90`; no [UID:0000LD] score change.
- [x] Owner/emitter/reconstructable changes applied: none. Aggregate `[[CHILDREN]]` routing was added only where needed for [UID:0000T9]/[UID:0000RM] child emission, without metadata owner/emitter changes.
- [x] Split/rename/new-child changes applied: none.
- [x] Formal no-code markers applied: [UID:00008A], [UID:0000T9], [UID:0000RM], [UID:00023B], [UID:00023C], [UID:00025W].
- [x] Formal C++ applied: [UID:00029A], [UID:0002BX], [UID:0002C0], [UID:0002C2], [UID:0002C3], [UID:0002C5], [UID:0001CI].
- [x] Support C++ corrections applied: [UID:0002BY] and [UID:0002C7] `MidiReadRaw(...) != 0` failure checks became `MidiReadRaw(...) == 0`.
- [x] Remaining follow-up rows explicitly excluded from first batch with reason: [UID:0002B1], [UID:0001CE], [UID:0001CG], [UID:0002BZ], [UID:0002C4].
- [x] Historical/stale assumptions handled: stale `0xffffffff` initializer assumption for current [UID:0002B1]/[UID:0002B2] state is rejected until reconciled; possible private `MidiSMFDocument.cpp` split remains a caveat only.
- [x] Validators run: all scoped validators listed in `Validators Expected After Acceptance` ran; results are recorded in `Implementation Callback Results`.
- [x] Generated refresh complete: validator command `000000001942` refreshed `auto-generated/NexusTK/audio/MidiPlayer.cpp`, queue status command `000000001945` showed no queued/processing jobs, and remaining marker list was inspected read-only.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation.
- [x] Short leases acquired only immediately before editing and released or confirmed absent after the edit/validator batch; final lease check showed no active B013 leases.
- [x] All accepted target/support doc details incorporated at report-level detail.
- [x] Claim And Incorporation Ledger verification state updated for every accepted claim.
- [x] Metadata/score/C++/no-code/support fixes applied or explicitly excluded with reason.
- [x] Scoped validators run and command ids/timestamps/exit/ok counts recorded.
- [x] Generated `MidiPlayer.cpp` freshness and remaining empty markers recorded.
- [x] Accepted but unapplied items: none. The five remaining empty markers are accepted follow-up exclusions, not unapplied first-batch rows.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B013","command_id":"000000004165","destination_path":"executed-b-agent-research/B013/0000LD-MidiPlayer-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B013/research/0000LD-MidiPlayer-empty-emitter-family-source-quality.md","timestamp":"2026-06-30T01:16:35","uid":"0000LD"} -->
<!-- {"agent":"B013","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000LD-MidiPlayer-empty-emitter-family-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B013/0000LD-MidiPlayer-empty-emitter-family-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000LD"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
