** TARGET-REPORT-UID:0002B2 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002B2 MidiSMFParserScratchGlobals Source-Quality Report

Assignment: `B003-goal2-midi-smf-parser-scratch-globals-source-quality-0002B2-20260618`  
Agent: `Agent-B003`  
Date: 2026-06-18  
Target: [UID:0002B2] `by-memory/0x0069b870-0x0069b890.MidiSMFParserScratchGlobals.md`  
Required output path: `tools/leaser/Agents/Agent-B003/research/0002B2-MidiSMFParserScratchGlobals-source-quality.md`

This is report-only research. I did not edit by-* docs, generated reports/source, the IDA DB, or `by-memory/-coverage-report.md`. The only created file is this report.

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0002B2] as a reconstructable source-declared global-data page, keep `CANONICAL_OWNER:0000T9`, keep `EMITTER_UIDS:0000T9`, add a low emitter position so the declarations are emitted before the helper bodies that use them, and populate formal C++ with private `MidiPlayer.cpp` SMF scratch declarations.
- Final disposition: source-owned private MIDI parser/stream-fill scratch storage under [UID:0000T9] `MidiPlayerWinMMState`, emitted into `NexusTK/audio/MidiPlayer.cpp`.
- Required action: replace stale "blank because 95/95/final declaration grouping unresolved" wording with the concrete declaration plan below; change score from `82/90` to `86/90`; set `EMITTER_POSITION_OPTIONAL:0`; populate the target's `RECONSTRUCTION_CPP CODE` block with the draft declaration block in this report.
- Confidence: high for exact range, direct xref confinement, source route, and declaration grouping; medium-high for original symbol spelling and exact static initializer spelling because no original symbols or headers are recovered.

## Target

- Target UID: `0002B2`
- Target path: `source-3/project-documentation/by-memory/0x0069b870-0x0069b890.MidiSMFParserScratchGlobals.md`
- Current state: `COMPLETION:82`, `CONFIDENCE:90`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000T9`, `EMITTER_UIDS:0000T9`, blank formal C++.
- Current generated route: `auto-generated/-ag-memory-coverage.md` routes [UID:0002B2] through [UID:0000T9] to `auto-generated/NexusTK/audio/MidiPlayer.cpp`.
- Current generated integration problem: `auto-generated/NexusTK/audio/MidiPlayer.cpp` now contains formal helper C++ for [UID:0002BU], [UID:0002BV], [UID:0002C6], and [UID:0002C7], including references to `g_midiTrackScanCursor`, `g_midiSelectedTrack`, `g_midiFillState`, `g_midiSelectedTick`, `g_midiPendingEvent`, `MidiEvent`, `MidiTrackState`, and `MIDI_FILL_*`, but [UID:0002B2] still emits no declarations.

## Evidence Checked

Read workflow and policy:

- `tools/leaser/Agents/Supervisor.md`
- `tools/leaser/Agents/Agent-B003/goal.md`
- `tools/leaser/Agents/Agent-B003/notes.md`
- `by-structure.md`, especially the current code-entry rule: reconstructable item, nonblank emitter route that surfaces to generated source, and `(COMPLETION + CONFIDENCE) / 2 > 85`; older `90/90+` and `95/95` wording is stale.
- `inference_research.md` guidance as referenced by B003 goal instructions.
- `by-project-structure/proposed-source-tree.md` as source-tree context for `NexusTK/audio/MidiPlayer.cpp`.

Read target/support docs:

- [UID:0002B2] `by-memory/0x0069b870-0x0069b890.MidiSMFParserScratchGlobals.md`
- [UID:0000T9] `by-global/MidiPlayerWinMMState.md`
- [UID:0000LD] `by-file/MidiPlayer.md`
- [UID:00008A] `by-class/MidiPlayer.md`
- [UID:0002B1] `by-memory/0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals.md`
- [UID:00023B] `by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md`
- [UID:00023C] `by-memory/0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers.md`
- [UID:0002BU] `by-memory/0x00526790-0x005269ea.MidiEventReader.md`
- [UID:0002BV] `by-memory/0x005269f0-0x00526ba8.MidiStreamEventEncoder.md`
- [UID:0002C6] `by-memory/0x005271b0-0x005273a0.MidiStreamBufferFillHelper.md`
- [UID:0002C7] `by-memory/0x005273a0-0x005277bb.MidiSMFDocumentLoadHelper.md`
- [UID:0001CI] `by-memory/0x005270e0-0x005271a3.MidiDocumentRelease.md`
- Prior accepted B001 report: `tools/leaser/Agents/Agent-B001/research/executed/0002BU-0002BV-0002C6-0002C7-MidiSMFParserStreamSourceQuality.md`
- Current `by-memory/-coverage-report.md`
- Current `auto-generated/-ag-memory-coverage.md`
- Current `project-level/-auto-completion-stats.md`
- Current generated `auto-generated/NexusTK/audio/MidiPlayer.cpp`

Local executable checks against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`:

- Parsed PE headers directly from the file. Image base is `0x400000`.
- `.data` virtual range includes `0x0069b870`, but this address is in the virtual tail beyond the file-backed raw bytes. Therefore a raw-file-only byte read cannot independently verify the initialized `0xffffffff` bytes. The prior documented IDA `get_bytes`/item inspection remains the byte-initialization evidence.
- Scanned the raw executable for little-endian absolute VA references to the target and adjacent data addresses. This raw scan is independent positive evidence for xref confinement and previous/next item separation.
- Disassembled `0x005271b0-0x005273a0` with Capstone to list every direct operand reference to `0x0069b870-0x0069b88c`.

Raw address scan results:

| Address | Raw absolute-address hits | Meaning |
| --- | --- | --- |
| `0x0069b86c` | `0x00525d4a` | Previous item [UID:0002B1] has a separate callback-era reference before this range. |
| `0x0069b870` | `0x005271dd`, `0x00527228`, `0x00527261` | All inside `MidiFillStreamBuffer`. |
| `0x0069b874` | `0x005271d8`, `0x0052721d`, `0x0052726d` | All inside `MidiFillStreamBuffer`. |
| `0x0069b878` | `0x005271cc`, `0x005271e4`, `0x00527203`, `0x005272f2`, `0x00527341`, `0x0052736f`, `0x0052737f`, `0x00527392` | All inside `MidiFillStreamBuffer`. |
| `0x0069b87c` | `0x00527223`, `0x00527267` | All inside `MidiFillStreamBuffer`. |
| `0x0069b880` | `0x005271d3`, `0x0052727a`, `0x00527323`, `0x00527353` | All inside `MidiFillStreamBuffer`. |
| `0x0069b884` | `0x00527290`, `0x005272ec` | All inside `MidiFillStreamBuffer`; these byte reads inspect the `MidiEvent` status/type area. |
| `0x0069b888` | none | Internal dword of the 16-byte `MidiEvent`; no direct absolute operand is expected. |
| `0x0069b88c` | `0x005272b3`, `0x0052730d` | All inside `MidiFillStreamBuffer`; payload pointer cleanup. |
| `0x0069b890` | `0x0052dd88`, `0x0052dd90`, `0x0052e71c`, `0x0052f712`, `0x0052f82f` | Successor item, outside `MidiFillStreamBuffer`; confirms half-open end at `0x0069b890`. |

Capstone disassembly references inside `0x005271b0-0x005273a0`:

```text
005271cb: mov     dword ptr [0x69b878], eax
005271d0: movups  xmmword ptr [0x69b880], xmm0
005271d7: mov     dword ptr [0x69b874], eax
005271dc: mov     dword ptr [0x69b870], eax
005271e3: mov     eax, dword ptr [0x69b878]
00527201: mov     dword ptr [0x69b878], 0
0052721b: mov     dword ptr [0x69b874], esi
00527221: mov     dword ptr [0x69b87c], edx
00527227: mov     dword ptr [0x69b870], eax
00527260: mov     dword ptr [0x69b870], eax
00527265: mov     dword ptr [0x69b87c], edx
0052726b: mov     dword ptr [0x69b874], esi
00527279: push    0x69b880
0052728e: cmp     byte ptr [0x69b884], 0xff
005272b1: push    dword ptr [0x69b88c]
005272ea: cmp     byte ptr [0x69b884], 0xff
005272f1: mov     dword ptr [0x69b878], eax
0052730b: push    dword ptr [0x69b88c]
00527322: push    0x69b880
0052733f: or      dword ptr [0x69b878], 4
00527352: push    0x69b880
0052736d: or      dword ptr [0x69b878], 4
0052737d: or      dword ptr [0x69b878], 2
00527390: or      dword ptr [0x69b878], 1
```

Validation/state commands run:

> Executable block R001 was removed from this report and preserved verbatim in [0002B2-MidiSMFParserScratchGlobals-source-quality-removed.md](0002B2-MidiSMFParserScratchGlobals-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Heuristic / Inference Reanalysis And Validation

### Declaration grouping

Best inference: [UID:0002B2] should emit a private declaration block for the SMF stream-fill scratch globals in `MidiPlayer.cpp`. It should not stay blank.

Evidence:

- The target is reconstructable, has nonblank `EMITTER_UIDS:0000T9`, and `auto-generated/-ag-memory-coverage.md` shows the route surfaces to `auto-generated/NexusTK/audio/MidiPlayer.cpp`.
- `(82 + 90) / 2 = 86`, so the target already clears the current code-entry gate. With this pass's declaration grouping resolved, `86/90` is justified.
- [UID:0002C6] formal C++ now calls `g_midiTrackScanCursor`, `g_midiSelectedTrack`, `g_midiFillState`, `g_midiSelectedTick`, and `g_midiPendingEvent`; generated `MidiPlayer.cpp` uses those names but lacks declarations.
- All direct references to the target storage are confined to `MidiFillStreamBuffer`, so these are private file-static scratch globals rather than externally visible API globals.
- The previous data at `0x0069b86c` and next data at `0x0069b890` have different xref sets, supporting a clean half-open item rather than a mixed range.

Rejected alternatives:

- Leave formal C++ blank until original symbols are recovered: rejected. The current gate does not require original symbols, and the accepted descriptive names are already used by populated helper C++.
- Keep raw `dword_69B...` names in generated source: rejected. Raw names are useful in evidence sections but are not source-quality declarations.
- Fold the declarations into [UID:0002C6] `MidiFillStreamBuffer`: rejected. The storage exists at `0x0069b870-0x0069b890` and has its own by-memory item; [UID:0002C6] should only own function code.
- Emit this as a field inside a `MidiPlayer` object: rejected. The class object is only 12 bytes and the scratch state is process-wide static storage.

Impact: populate formal storage declarations on [UID:0002B2], keep the target reconstructable, and add early emitter placement.

### Global names and types

Accepted source-facing names remain valid and should be promoted from "draft names" to "formal declaration names" for this target:

| Address | Formal declaration | Evidence |
| --- | --- | --- |
| `0x0069b870` | `static MidiTrackState* g_midiTrackScanCursor` | Stores track table scan cursor/end pointer inside `MidiFillStreamBuffer`; raw hits at `0x5271dd`, `0x527228`, `0x527261`. |
| `0x0069b874` | `static MidiTrackState* g_midiSelectedTrack` | Stores selected active 40-byte track record pointer; raw hits at `0x5271d8`, `0x52721d`, `0x52726d`. |
| `0x0069b878` | `static DWORD g_midiFillState` | Bitfield set/cleared/read by stream-fill reset/replay/terminal branches; raw hits include `0x5271cc`, `0x527203`, `0x52733f`, `0x52737d`, and `0x527390`. |
| `0x0069b87c` | `static DWORD g_midiSelectedTick` | Stores best/smallest pending tick selected from active tracks; raw hits at `0x527223` and `0x527267`. |
| `0x0069b880-0x0069b890` | `static MidiEvent g_midiPendingEvent` | 16-byte parsed event scratch passed by address to event reader and stream-event writer; status/type bytes read at `0x69b884`, payload pointer read at `0x69b88c`. |

Initial values:

- Existing target docs record live IDA item inspection showing eight initialized little-endian `0xffffffff` dwords across this range.
- Local raw PE reading cannot verify the data bytes because the address is in the virtual tail of `.data` beyond raw file-backed bytes. This does not contradict IDA's loaded-image view, but it means the report's raw-file evidence supports references/boundaries rather than initial bytes.
- Formal declarations should preserve the documented all-`0xffffffff` initial state. The first-fill/reset path zeroes the scratch state before normal use, but binary parity for this data page requires explicit `0xffffffff` initializers.

Rejected alternatives:

- Initialize the globals to zero because first-fill resets them anyway: rejected for binary reconstruction. The data page documents initialized `0xffffffff` dwords, and the source declaration should reproduce that storage state.
- Model `g_midiPendingEvent` as a raw `DWORD[4]`: rejected for final source because [UID:0002BU], [UID:0002BV], and [UID:0002C6] already use the validated `MidiEvent` field model. A raw array can remain a fallback only if the supervisor refuses to place `MidiEvent` as a shared declaration.

Impact: raises completion because the final declaration grouping and formal storage syntax are no longer open.

### Type names

Best current type directions:

- `MidiEvent`: 16-byte parsed event record. This type is directly represented by this data page and can be fully declared here:
  - `+0x00 DWORD tick`
  - `+0x04 BYTE status`
  - `+0x05 BYTE data1`
  - `+0x06 BYTE data2`
  - `+0x07 BYTE reserved`
  - `+0x08 DWORD payloadLength`
  - `+0x0c BYTE* payload`
- `MidiTrackState`: 40-byte per-track record. This data page only stores pointers to it, but the field map is already supported by [UID:0002C7], [UID:0002BU], [UID:0002C6], [UID:0001CI], and [UID:00023B]. A forward declaration is enough for this page's two pointer globals, while the full definition should live in a future by-type page or a file-level shared declaration block.
- `MidiDocument`: static document/source context around `0x0069b828`; this data page does not store it but sibling helper code uses it. Keep source-facing type name and recommend a by-type page, but do not make [UID:0002B2] the canonical owner of full document layout.
- `MidiStreamWriteContext`: caller-provided output-buffer context used by [UID:0002BV] and [UID:0002C6]; not stored in this range. Keep source-facing type name and recommend a by-type page or shared declaration block.

Rejected alternatives:

- `MidiDocumentEvent` for `MidiTrackState`: rejected by B001 and by current support docs because the 40-byte record contains per-track parser state, source offsets, buffer/cursor state, running status, and pending tick, not one event.
- `MidiStreamEncoderState` for `MidiStreamWriteContext`: weaker because the structure is owned by the stream-fill writer context passed into the encoder, not by the encoder alone.

Impact: `MidiEvent` is required in the [UID:0002B2] formal block. The other type names should be referenced by forward declarations here and by support-doc shared declaration text elsewhere.

### Fill-state bits and fill results

Accepted bit names:

- `MIDI_FILL_AT_END = 0x01`: no active track remains/end-of-stream state recorded.
- `MIDI_FILL_PARSE_ERROR = 0x02`: parse failure state recorded and replayed as previous parse failure.
- `MIDI_FILL_PENDING_EVENT = 0x04`: `MidiWriteStreamEvent` returned output-full, so `g_midiPendingEvent` is retried.

Accepted result names:

- `MIDI_FILL_OK = 0`
- `MIDI_FILL_PARSE_FAILED = -101`
- `MIDI_FILL_PREVIOUS_PARSE_FAILED = -102`
- `MIDI_FILL_END_OF_STREAM = -103`
- `MIDI_FILL_OUTPUT_FULL = -104`
- `MIDI_FILL_UNSUPPORTED_EVENT = -105`

Rejected alternatives:

- Treat `-104` as terminal failure: rejected. The helper preserves and retries `g_midiPendingEvent`.
- Omit `MIDI_FILL_PARSE_FAILED = -101` from this target because the target page only mentions `-102` through `-104`: rejected. [UID:0002C6] uses `MIDI_FILL_PARSE_FAILED`, and the declaration group should be consistent with the accepted B001 source-quality plan.

Impact: define these constants before helper code. They are source declarations with no storage outside the target range except compile-time constants.

### Boundary and split/range decision

The range should remain exactly `0x0069b870-0x0069b890`.

Evidence:

- Four scalar dword items at `0x0069b870`, `0x0069b874`, `0x0069b878`, and `0x0069b87c` followed by one 16-byte event item at `0x0069b880-0x0069b890`.
- Previous item `0x0069b86c` has a distinct xref at `0x00525d4a`.
- Successor `0x0069b890` has five references outside `MidiFillStreamBuffer` and belongs to [UID:0002B3] `CreateUserDialogPaneSingletonSlot`.
- Direct refs to all target addresses except the internal `0x0069b888` dword are inside `0x005271b0-0x005273a0`.

Rejected alternatives:

- Merge into [UID:0002B1] `MidiPlayerWinMMStateGlobals`: rejected. [UID:0002B2] has a narrower stream-fill scratch role and a clean boundary.
- Merge with [UID:0002B3]: rejected. The successor belongs to login/CreateUserDialogPane singleton state with unrelated xrefs.
- Split each dword into separate pages: rejected. The five declarations are one coherent scratch group used by one function; individual split would obscure source grouping and would not improve ownership.

Impact: no split repair is needed.

### Ownership and source placement

Ranked placement:

1. [UID:0000T9] `MidiPlayerWinMMState` as canonical documentation owner, emitted through `MidiPlayer.cpp`.
   - Evidence for: target is source-declared global state; [UID:0000T9] is the scored map for the same WinMM/SMF global family and already routes to [UID:0000LD]; [UID:0002B1] uses the same direct parent; current target metadata and generated coverage already route through [UID:0000T9].
   - Evidence against: [UID:0000T9] is a documentation grouping, not a literal original C++ `struct`. This does not block ownership; it is the narrowest current owner for global storage.
   - Decision: keep `CANONICAL_OWNER:0000T9`, keep `EMITTER_UIDS:0000T9`, add early emitter position.
2. [UID:0000LD] `MidiPlayer.cpp` as direct file owner/emitter.
   - Evidence for: the actual source declarations must appear in `NexusTK/audio/MidiPlayer.cpp`; B001 accepted all sibling helpers as private file helpers under [UID:0000LD].
   - Evidence against: using [UID:0000LD] as canonical owner would bypass the narrower global-state map. Direct file emission is an acceptable fallback only if generated ordering through [UID:0000T9] cannot place declarations before consumers.
   - Decision: use as final source file route, not canonical owner. Fallback emitter-only route is acceptable if validation shows [UID:0000T9] child output still appears after helper uses.
3. New private `MidiSMFParser.cpp` or `MidiSMFDocument.cpp`.
   - Evidence for: reader/fill/load helpers form a coherent SMF subsystem.
   - Evidence against: no recovered filename, no by-file page, no proposed-source-tree entry, no separate globals outside the `MidiPlayer` state family, and no stronger route than [UID:0000LD].
   - Decision: reject as current owner. Keep as historical possibility in support docs only.
4. [UID:00008A] `MidiPlayer` class.
   - Evidence for: class controls MIDI playback and singleton lifecycle.
   - Evidence against: scratch storage is static/global, not fields of the 12-byte `MidiPlayer` object; helpers are private file/static routines, not object methods.
   - Decision: context only, not owner/emitter.
5. `SoundManager` or generic audio/file I/O owners.
   - Evidence for: broad audio module adjacency only.
   - Evidence against: WinMM MIDI path is explicitly separated from SoundManager/Miles/Redbook; direct refs are from SMF stream fill only.
   - Decision: reject.

## Recommended Metadata And Score Changes

Recommended target metadata:

```text
COMPLETION: 86
CONFIDENCE: 90
CANONICAL_OWNER: 0000T9
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 0000T9
EMITTER_POSITION_OPTIONAL: 0
```

Rationale:

- Completion `82 -> 86`: final declaration grouping is resolved, current code-entry policy is applied, formal source declarations are recommended, raw-address xref confinement was rechecked, and generated-source integration was checked. Completion remains below final audit because original symbols are not recovered, full by-type pages for `MidiDocument`/`MidiTrackState`/`MidiStreamWriteContext` are still missing, and local raw-file bytes cannot independently confirm IDA's initialized `0xffffffff` data because the address is in `.data` virtual tail.
- Confidence stays `90`: direct xref confinement and existing IDA docs are strong. I do not recommend raising confidence because the all-`0xffffffff` initialization relies on prior loaded-IDB evidence rather than local raw bytes, and original declarations remain inferred/descriptive.
- `EMITTER_POSITION_OPTIONAL:0`: needed so the generated declaration block appears before the already-emitted helper bodies in `MidiPlayer.cpp`. If validation shows [UID:0000T9] child placement still lands after [UID:0002BU]/[UID:0002BV]/[UID:0002C6]/[UID:0002C7], keep canonical owner `0000T9` but route this target directly to `EMITTER_UIDS:0000LD` with `EMITTER_POSITION_OPTIONAL:0` as an emitter-order fallback.

Support-doc score recommendations:

- [UID:0000T9] `MidiPlayerWinMMState`: recommend `86/88 -> 87/89` after adding the concrete [UID:0002B2] formal declaration plan, generated-source ordering note, and final scratch global declarations. It remains below final because the larger WinMM state map still has unresolved stream-state names.
- [UID:0000LD] `MidiPlayer`: no required score change. Add a note that [UID:0002B2] now supplies the private scratch-global declarations needed by generated helper code; keep the possible private SMF source split caveat.
- [UID:00008A] `MidiPlayer` class: no score change. Add a clarifying note that the scratch globals are file-static MIDI parser storage, not class object fields.
- [UID:00023C] and [UID:0002C6]: no required score change. Replace any remaining "standalone storage grouping unresolved" language with a cross-link to [UID:0002B2]'s declaration block.

## First-Draft C++ Recommendation

Populate [UID:0002B2]'s formal `RECONSTRUCTION_CPP CODE` block. This is not a no-code target anymore.

This declaration block is intentionally private/file-static and should be placed before the MIDI SMF helper bodies in `auto-generated/NexusTK/audio/MidiPlayer.cpp`. It includes the fill bit/result constants and the `MidiEvent` declaration needed for the 16-byte object represented by this range. It uses forward declarations for related types that this range only stores as pointers or references through sibling helper code.

```cpp
struct MidiDocument;
struct MidiTrackState;
struct MidiStreamWriteContext;

struct MidiEvent {
    DWORD tick;
    BYTE status;
    BYTE data1;
    BYTE data2;
    BYTE reserved;
    DWORD payloadLength;
    BYTE* payload;
};

static const DWORD MIDI_FILL_AT_END = 0x00000001;
static const DWORD MIDI_FILL_PARSE_ERROR = 0x00000002;
static const DWORD MIDI_FILL_PENDING_EVENT = 0x00000004;

enum MidiFillResult {
    MIDI_FILL_OK = 0,
    MIDI_FILL_PARSE_FAILED = -101,
    MIDI_FILL_PREVIOUS_PARSE_FAILED = -102,
    MIDI_FILL_END_OF_STREAM = -103,
    MIDI_FILL_OUTPUT_FULL = -104,
    MIDI_FILL_UNSUPPORTED_EVENT = -105
};

static MidiTrackState* g_midiTrackScanCursor = (MidiTrackState*)0xFFFFFFFF;
static MidiTrackState* g_midiSelectedTrack = (MidiTrackState*)0xFFFFFFFF;
static DWORD g_midiFillState = 0xFFFFFFFF;
static DWORD g_midiSelectedTick = 0xFFFFFFFF;
static MidiEvent g_midiPendingEvent = {
    0xFFFFFFFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFFFFFFFF,
    (BYTE*)0xFFFFFFFF
};
```

Important integration note:

- This block closes the storage-declaration gap for [UID:0002B2].
- It does not replace the need for future shared by-type pages or a file-level shared declaration block for the full `MidiDocument`, `MidiTrackState`, and `MidiStreamWriteContext` layouts. [UID:0002BU]/[UID:0002BV]/[UID:0002C6]/[UID:0002C7] already use those types with field accesses, so the generated source still benefits from a broader shared declaration pass. That broader pass is outside this 32-byte storage target and should not be used as a reason to keep [UID:0002B2] blank.

If the supervisor wants [UID:0002B2] to own the full shared type declarations temporarily until by-type pages exist, use this support-only extension before the storage declarations, but prefer dedicated by-type pages for final cleanup:

```cpp
struct MidiTrackState {
    DWORD flags;
    DWORD trackLength;
    DWORD bufferedBytes;
    BYTE* buffer;
    BYTE* cursor;
    DWORD pendingTick;
    DWORD runningStatus;
    DWORD trackStartOffset;
    DWORD sourceOffset;
    DWORD bytesRemaining;
};

struct MidiStreamWriteContext {
    BYTE* buffer;
    BYTE reservedHeader[0x3C];
    DWORD writeOffset;
    DWORD writeLimit;
    DWORD bytesWritten;
    DWORD lastEventTick;
    DWORD fullEventPending;
};
```

Do not put an invented full `MidiDocument` body into [UID:0002B2]'s formal code unless a dedicated type pass validates the adapter/file/source subobject fields. `MidiDocument` is not stored in this target range.

## Exact Supervisor Changes Required

### Target Metadata

In [UID:0002B2] replace:

```text
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

with:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Keep:

```text
*** CANONICAL_OWNER:0000T9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000T9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Target Status Text

Replace the stale final-C++ sentence:

```markdown
- Final C++ remains blank because these are source-declared globals but the final declaration style, original symbol names, and helper split are below the 95/95 rewrite gate.
```

with:

```markdown
- Formal C++ should now be populated with private `MidiPlayer.cpp` declarations for the scratch globals, fill-state bits, fill-result constants, and the 16-byte `MidiEvent` shape. The active code-entry policy is the current combined-score/emitter gate, not the old `95/95` wording. Original symbols remain unproven, but the descriptive names are validated by the accepted SMF helper C++ and by direct xref confinement to `MidiFillStreamBuffer`.
```

Add this paragraph under `## Reconstruction Notes`:

```markdown
The declaration grouping is now resolved for this target. Emit these globals as private file-static storage under the `MidiPlayer.cpp` source family, with [UID:0000T9][MidiPlayerWinMMState](by-global/MidiPlayerWinMMState.md) as the canonical documentation owner. Set `EMITTER_POSITION_OPTIONAL:0` so the declarations are generated before the helper bodies that use them. If generator validation still places this block after [UID:0002BU]/[UID:0002BV]/[UID:0002C6]/[UID:0002C7], keep `CANONICAL_OWNER:0000T9` but route this target directly to [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md) as emitter with position `0`.
```

Replace the score rationale table with:

```markdown
| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 86 | The page now has a concrete final declaration grouping, current code-entry policy analysis, formal storage declaration recommendation, raw executable absolute-address scan confirming all target references are confined to `MidiFillStreamBuffer`, previous/next data separation at `0x0069b86c` and `0x0069b890`, accepted source-facing names, and generated-source integration evidence showing these declarations are needed before populated helper C++. Capped below final because original symbols are not recovered, full by-type pages for `MidiDocument`/`MidiTrackState`/`MidiStreamWriteContext` are still missing, and local raw-file bytes cannot independently verify IDA's initialized `0xffffffff` values because this address is in `.data` virtual tail. |
| Confidence | 90 | Prior live IDA evidence and the current raw address scan strongly support boundaries, xref confinement, roles, owner/emitter route, and declaration names. Confidence stays at 90 because the all-`0xffffffff` initializer remains loaded-IDB evidence rather than raw-file-backed evidence in this pass, and source spellings remain descriptive/inferred. |
```

Add this change-history bullet:

```markdown
- 2026-06-18 B003 source-quality reanalysis: recommend `82/90 -> 86/90`, keep owner/emitter [UID:0000T9], set `EMITTER_POSITION_OPTIONAL:0`, and populate formal C++ with private `MidiPlayer.cpp` scratch-global declarations. Direct raw executable scans found all absolute references to `0x0069b870-0x0069b88c` inside `0x005271b0-0x005273a0` and found successor `0x0069b890` references outside the stream-fill helper, confirming the half-open data boundary. The local raw file cannot verify initialized bytes because this `.data` address is in the virtual tail beyond raw file-backed data; prior live IDA initialized-byte evidence remains the source for the eight `0xffffffff` dwords.
```

### Formal C++ Block

Insert the `First-Draft C++ Recommendation` block above into [UID:0002B2]'s `RECONSTRUCTION_CPP CODE` section.

### Support Docs

For [UID:0000T9] `by-global/MidiPlayerWinMMState.md`, add after `## 2026-06-17 SMF Parser Declaration Plan`:

```markdown
2026-06-18 B003 reanalysis resolves [UID:0002B2][0x0069b870-0x0069b890.MidiSMFParserScratchGlobals](by-memory/0x0069b870-0x0069b890.MidiSMFParserScratchGlobals.md) as the formal storage-declaration owner for the SMF fill scratch globals. The declarations should be emitted as private file-static storage in `MidiPlayer.cpp` before the helper bodies that use them. The canonical documentation owner remains this global-state map, while the final generated source route remains [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md). Use `EMITTER_POSITION_OPTIONAL:0` on [UID:0002B2] and validate generated order.
```

Replace the [UID:0000T9] caveat:

```markdown
Dedicated by-type pages for these declarations would improve the future score ceiling, but their absence no longer blocks the first-draft C++ on ...
```

with:

```markdown
Dedicated by-type pages for `MidiDocument`, `MidiTrackState`, `MidiEvent`, and `MidiStreamWriteContext` would improve the future score ceiling. Their absence no longer blocks function-body C++, and [UID:0002B2] now supplies the concrete scratch-global storage declarations. Full `MidiDocument`, `MidiTrackState`, and `MidiStreamWriteContext` structure definitions should still be promoted into by-type pages or a shared `MidiPlayer.cpp` declaration block so generated helper code has complete type definitions before use.
```

For [UID:0000LD] `by-file/MidiPlayer.md`, add under `## MIDI SMF Source-Quality Declarations`:

```markdown
B003's 2026-06-18 scratch-global pass resolves [UID:0002B2] as the source-bearing declaration block for `g_midiTrackScanCursor`, `g_midiSelectedTrack`, `g_midiFillState`, `g_midiSelectedTick`, and `g_midiPendingEvent`. These are private file-static declarations in `MidiPlayer.cpp`, not `MidiPlayer` object fields. The possible historical `MidiSMFDocument.cpp` split remains unproven and should not block emitting this storage under the current `MidiPlayer.cpp` route.
```

For [UID:00008A] `by-class/MidiPlayer.md`, add under `## Data Caveats`:

```markdown
[UID:0002B2]'s SMF parser scratch globals are static implementation storage for the private MIDI parser/fill helpers, not fields of the 12-byte `MidiPlayer` object. Their formal declarations should be generated in `MidiPlayer.cpp` before the private helper bodies, while this class page remains focused on the object singleton and public playback controls.
```

For [UID:00023C] `MidiSMFLoadAndStreamFillHelpers`, replace the open question about scratch global names with:

```markdown
Original source spellings for the scratch globals remain unrecovered, but [UID:0002B2] now owns the formal descriptive declarations `g_midiTrackScanCursor`, `g_midiSelectedTrack`, `g_midiFillState`, `g_midiSelectedTick`, and `g_midiPendingEvent` for generated `MidiPlayer.cpp`. This aggregate's remaining open questions are the possible private SMF source-file split and exact `MidiFillStreamBuffer` replay/end branch mapping, not whether the scratch globals should emit.
```

For [UID:0002C6] `MidiStreamBufferFillHelper`, add:

```markdown
The scratch globals referenced by this formal C++ are now expected to be emitted by [UID:0002B2] before this helper body. If generated order validation shows the declarations after this helper, fix emitter placement rather than reverting the helper or scratch declarations to blank C++.
```

## Coverage Report Replacement Text

Placement context: replace the existing [UID:0002B2] row under the `.data` global-data section after [UID:0002B1] and before [UID:0002B3].

```markdown
    - [UID:0002B2][0x0069b870-0x0069b890.MidiSMFParserScratchGlobals](by-memory/0x0069b870-0x0069b890.MidiSMFParserScratchGlobals.md) 0x0069b870-0x0069b890 | global-data scratch | MidiSMFParserScratchGlobals : reconstructable : 86% : strong : B003 2026-06-18 source-quality pass resolves this as the private `MidiPlayer.cpp` storage declaration block for `g_midiTrackScanCursor`, `g_midiSelectedTrack`, `g_midiFillState`, `g_midiSelectedTick`, and 16-byte `g_midiPendingEvent`; keeps [UID:0000T9][MidiPlayerWinMMState](by-global/MidiPlayerWinMMState.md) owner/emitter with early emitter position; validates accepted `MidiEvent`, fill-state bits, and `MidiFillResult` names; raw executable absolute-address scan confirms all target refs are confined to `0x005271b0-0x005273a0` while previous `0x0069b86c` and successor `0x0069b890` have separate xref sets; formal C++ should be populated, with score capped because original symbols and full shared by-type declarations remain unrecovered and local raw-file bytes cannot independently verify IDA's initialized `0xffffffff` values for this virtual `.data` tail.
```

No `auto-generated/-ag-memory-coverage.md` manual edit is recommended; it is generated. After supervisor edits, regenerate/validate so it changes from "emits/no code" to a coded/declaration-bearing state as appropriate.

## Follow-Up Actions

Supervisor actions:

- Apply the [UID:0002B2] metadata and formal C++ changes above.
- Apply support-doc text to [UID:0000T9], [UID:0000LD], [UID:00008A], [UID:00023C], and [UID:0002C6].
- Apply the `by-memory/-coverage-report.md` row replacement.
- Regenerate/validate and inspect `auto-generated/NexusTK/audio/MidiPlayer.cpp` to ensure [UID:0002B2]'s declarations appear before [UID:0002BU]/[UID:0002BV]/[UID:0002C6]/[UID:0002C7] helper code.
- If generated order is wrong despite `EMITTER_POSITION_OPTIONAL:0`, change [UID:0002B2]'s emitter route to direct [UID:0000LD] with position `0` while keeping canonical owner [UID:0000T9].

Recommended validation commands:

> Executable block R002 was removed from this report and preserved verbatim in [0002B2-MidiSMFParserScratchGlobals-source-quality-removed.md](0002B2-MidiSMFParserScratchGlobals-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

The generated source inspection should show the [UID:0002B2] declaration block before the first helper body that references `MidiEvent`, `MidiTrackState`, `MIDI_FILL_*`, or the `g_midi*` globals.

## Remaining Blockers

- Original source names remain unrecovered. The accepted names are descriptive/inferred but now strong enough for formal declarations under the current code-entry policy.
- The local raw executable cannot verify the eight initialized `0xffffffff` dwords because `0x0069b870` maps to the virtual tail of `.data` beyond the raw file-backed bytes. Prior live IDA loaded-image evidence remains the initialization source. A future IDA `get_bytes(0x0069b870, 0x20)` recheck would improve final-audit confidence but is not required before emitting the declarations.
- Full shared type pages for `MidiDocument`, `MidiTrackState`, and `MidiStreamWriteContext` still do not exist. This does not block [UID:0002B2]'s storage declarations, but generated helper code will remain structurally incomplete until those type definitions are supplied in by-type pages or a shared `MidiPlayer.cpp` declaration block.
- The possible historical private SMF parser/document source file remains unproven. Current evidence keeps declarations in `MidiPlayer.cpp`; no owner/emitter change to a new file is justified.
- Generated order must be validated after applying `EMITTER_POSITION_OPTIONAL:0`. If declarations appear after helper bodies, fix emitter placement rather than leaving [UID:0002B2] blank.

## Changed Files

Created:

- `source-3/project-documentation/tools/leaser/Agents/Agent-B003/research/0002B2-MidiSMFParserScratchGlobals-source-quality.md`

Modified:

- None outside this research report.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0002B2-MidiSMFParserScratchGlobals-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:27","uid":"0002B2"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002B2-MidiSMFParserScratchGlobals-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0002B2-MidiSMFParserScratchGlobals-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002B2"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
