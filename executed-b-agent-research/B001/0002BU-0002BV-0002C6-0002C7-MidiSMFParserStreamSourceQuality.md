** TARGET-REPORT-UID:0002BU **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002BU-0002BV-0002C6-0002C7 MIDI SMF Parser / Stream Source-Quality Research

## Finalized Report / Current Recommendation

Current recommendation: keep all four primary targets as reconstructable private `MidiPlayer.cpp` helpers, keep `CANONICAL_OWNER:0000LD`, keep `EMITTER_UIDS:0000LD`, and populate formal reconstruction C++ after adding the shared descriptive type/constant names below to the `MidiPlayer` source-family documentation. The original source names are not proven; the recommended names are descriptive/inferred but are strong enough for source-quality draft code under the current `(COMPLETION + CONFIDENCE) / 2 > 85` C++ gate.

| UID | Target | Current score | Recommended score | Owner | Emitter | Reconstructable | C++ policy |
| --- | --- | ---: | ---: | --- | --- | --- | --- |
| 0002BU | `0x00526790-0x005269ea.MidiEventReader` | 82/90 | 88/91 | `0000LD` | `0000LD` | TRUE | Populate with `MidiReadEvent` draft; use inferred `MidiDocument`, `MidiTrackState`, `MidiEvent`, and SMF status constants. |
| 0002BV | `0x005269f0-0x00526ba8.MidiStreamEventEncoder` | 82/90 | 87/91 | `0000LD` | `0000LD` | TRUE | Populate with `MidiWriteStreamEvent` draft; use inferred `MidiStreamWriteContext`, WinMM `MIDIEVENT` packing, and named fill result constants. |
| 0002C6 | `0x005271b0-0x005273a0.MidiStreamBufferFillHelper` | 82/90 | 86/90 | `0000LD` | `0000LD` | TRUE | Populate with `MidiFillStreamBuffer` draft, but keep score slightly lower because the exact end/replay return branches and scratch global source spelling remain inferred. |
| 0002C7 | `0x005273a0-0x005277bb.MidiSMFDocumentLoadHelper` | 82/90 | 88/91 | `0000LD` | `0000LD` | TRUE | Populate with `MidiLoadDocument` draft; use inferred SMF header/track structs and explicit `GlobalAlloc`/`GlobalLock` ownership. |

Final disposition: no split or ownership repair is needed for the four primary ranges. The correct source grouping is a private Standard MIDI File reader/stream helper block inside `NexusTK/audio/MidiPlayer.cpp`, possibly originally a small private MIDI document helper compiled adjacent to `MidiPlayer.cpp`, but the existing `MidiPlayer` file page is the best current canonical owner and emitter.

Confidence: high for behavior, owner/emitter routing, field-offset roles, status constants, and source placement. Medium for original source spellings and exact class-method versus file-static helper declarations.

## Target

- Target UIDs: 0002BU, 0002BV, 0002C6, 0002C7.
- Target paths:
  - `source-3/project-documentation/by-memory/0x00526790-0x005269ea.MidiEventReader.md`
  - `source-3/project-documentation/by-memory/0x005269f0-0x00526ba8.MidiStreamEventEncoder.md`
  - `source-3/project-documentation/by-memory/0x005271b0-0x005273a0.MidiStreamBufferFillHelper.md`
  - `source-3/project-documentation/by-memory/0x005273a0-0x005277bb.MidiSMFDocumentLoadHelper.md`
- Source queue/report row: assigned by user as Agent-B001 MIDI SMF parser/stream source-quality pass.
- Current generated route: all four are listed in `auto-generated/-ag-memory-coverage.md` as emitting through `0000LD` to `auto-generated/NexusTK/audio/MidiPlayer.cpp`.
- Generated output status: `auto-generated/NexusTK/audio/MidiPlayer.cpp` is present but zero bytes, so the route exists but no formal reconstruction code has been emitted yet.

## Supervisor Active Recheck

The assignment explicitly required source-quality inference instead of repeating existing blockers. The four target pages already have owner/emitter metadata and clear the current code-entry gate, but still contain stale wording that final C++ must stay blank because helper/type/global names are provisional. That older position is no longer the best recommendation. The original names remain unproven, but descriptive source-quality names are defensible and should be used with clear "inferred/descriptive" labeling.

No split repair is recommended. The target functions are exact modeled ranges with established padding and callers in the existing docs. The broader parents [UID:00023B] and [UID:00023C] should remain helper-island aggregates, not competing owners.

## Evidence Standards Used

Current live IDA MCP was attempted and unavailable. This report therefore uses existing by-* pages that record prior live IDA MCP sessions as documentation evidence, plus local generated files, generated coverage rows, support docs, and cross-document consistency checks. I do not claim new live IDA facts in this session.

Evidence reviewed:

- Target docs for 0002BU, 0002BV, 0002C6, and 0002C7.
- Support docs [UID:00023B], [UID:00023C], [UID:0001CE], [UID:0001CG], [UID:0001CI], sibling reader/source helpers, scratch globals [UID:0002B2], WinMM state [UID:0000T9], by-file [UID:0000LD], and by-class [UID:00008A].
- `by-memory/-coverage-report.md` target rows at current lines 2271, 2272, 2287, and 2288.
- `auto-generated/-ag-memory-coverage.md` rows 1500, 1501, 1513, and 1515 proving emitter routing to `auto-generated/NexusTK/audio/MidiPlayer.cpp`.
- `source-3/simroot_v2/audio/MidiPlayer.cpp` as a generated lead only, not authority.

## Function / Child Inventory

| Range / Item | UID | Role | Reconstructable | Direct owner | Current score | Recommended score |
| --- | --- | --- | --- | --- | ---: | ---: |
| `0x00526790-0x005269ea` | 0002BU | Decode one SMF track event into a 16-byte parsed event record. | TRUE | `0000LD` | 82/90 | 88/91 |
| `0x005269f0-0x00526ba8` | 0002BV | Encode one parsed event into a WinMM stream event. | TRUE | `0000LD` | 82/90 | 87/91 |
| `0x005271b0-0x005273a0` | 0002C6 | Fill one MIDI stream buffer from the loaded multi-track SMF document. | TRUE | `0000LD` | 82/90 | 86/90 |
| `0x005273a0-0x005277bb` | 0002C7 | Load an SMF document, allocate track records and buffers, seed first deltas. | TRUE | `0000LD` | 82/90 | 88/91 |

## Heuristic / Inference Reanalysis And Validation

### Source grouping and ownership

Best inference: `audio/MidiPlayer.cpp` owns the assigned functions as private helper routines. Evidence: [UID:0000LD] maps `MidiPlayer.cpp` to the WinMM MIDI stream controller; [UID:00023B] and [UID:00023C] tie the parser/fill helpers to `MidiStreamOpenAndPrimeBuffers`, `MidiStreamCallback`, and `MidiDocumentRelease`; generated `-ag-memory-coverage.md` routes all four to `0000LD`; no support page shows a stronger standalone by-file owner.

Rejected alternative: create a new canonical `MidiSMFDocument.cpp` owner now. This would be plausible as a future source-layout refinement, but there is no recovered source filename, no by-file page, and the static document state, callback, reset, and track-selection family are already centered on `MidiPlayer.cpp`. A new file would be a structural guess with weaker direct evidence than the existing scored file owner.

Rejected alternative: attach to [UID:00008A] `MidiPlayer` class. The parser helpers operate on static document/global state and are called from free callback/open helpers; they are better modeled as file-static/private helpers than class methods until an original class member declaration is proven.

Impact: keep `CANONICAL_OWNER:0000LD` and `EMITTER_UIDS:0000LD` for all four targets. No owner/emitter change is recommended.

### Helper names

Original names cannot be proven. Source-quality descriptive names are still defensible:

| Current page | Recommended descriptive function name | Why |
| --- | --- | --- |
| `MidiEventReader` | `MidiReadEvent` | It reads one event from a track, handling running status, SysEx/meta payloads, and next-delta seeding. |
| `MidiStreamEventEncoder` | `MidiWriteStreamEvent` | It writes one parsed event into a WinMM `MIDIEVENT` stream buffer. "Encode" is acceptable in docs, but "Write" better matches buffer mutation. |
| `MidiStreamBufferFillHelper` | `MidiFillStreamBuffer` | It is the shared producer called by stream-open and callback refill paths. |
| `MidiSMFDocumentLoadHelper` | `MidiLoadDocument` | It validates `MThd`/`MTrk`, allocates track state, and prepares playback. |

Rejected names: `ReadMidiStreamChunk` from Wave3 is too broad for 0002C6 because the helper fills a WinMM buffer and manages parser scratch state, not only chunk reading. `OpenMidiDocument` fits the tiny parse-success wrapper [UID:0002C5] better than the loader body at 0002C7. `MidiDocumentEvent` should be rejected for the 40-byte track table because the record is per-track parser state, not one MIDI event.

Impact: these names should unblock first-draft C++ while being marked inferred/descriptive.

### Type and field model

Best descriptive type names:

- `MidiDocument`: static document/source context at `0x0069b828`, constructed by [UID:0002C4], consumed by stream-open/callback/reset/release/load/fill helpers.
- `MidiTrackState`: one 40-byte (`0x28`) track record. Fields are role-proven across the byte reader, VLQ reader, prime/reset, loader, and stream-fill helper.
- `MidiEvent`: one 16-byte parsed event record. Fields are role-proven by 0002BU, 0002BV, and scratch global [UID:0002B2].
- `MidiStreamWriteContext`: stream-output context whose base buffer and offsets are written by 0002BV and reset/consumed by 0002C6.

Recommended field names, all descriptive/inferred:

```cpp
struct MidiTrackState {
    DWORD flags;              // +0x00, bit 0 marks done/error/end
    DWORD trackLength;        // +0x04, MTrk payload length
    DWORD bufferedBytes;      // +0x08
    BYTE* buffer;             // +0x0c, 0x400-byte GlobalAlloc/GlobalLock pointer
    BYTE* cursor;             // +0x10
    DWORD pendingTick;        // +0x14, absolute tick selected by stream fill
    DWORD runningStatus;      // +0x18, low byte used
    DWORD trackStartOffset;   // +0x1c
    DWORD sourceOffset;       // +0x20
    DWORD bytesRemaining;     // +0x24
};

struct MidiEvent {
    DWORD tick;               // +0x00
    BYTE status;              // +0x04
    BYTE data1;               // +0x05, channel data1 or meta type
    BYTE data2;               // +0x06
    BYTE reserved;            // +0x07
    DWORD payloadLength;      // +0x08
    BYTE* payload;            // +0x0c
};
```

Rejected alternatives:

- Treat the 40-byte record as `MidiDocumentEvent`: rejected because it holds per-track buffering, source offsets, running status, and pending absolute time.
- Treat `this+0x18` as an unknown adapter only: partially stale. Support docs now identify it as an embedded `DATFile` member for DAT/archive-backed sources, while the final enclosing `MidiDocument` name remains inferred.
- Treat `dword_69B870` and `dword_69B874` as permanent globals with independent ownership: rejected. [UID:0002B2] shows all direct refs confined to stream-fill, so they are scratch locals hoisted into file/static storage, probably due to original static state or compiler layout.

Impact: a new by-type struct page for `MidiDocument` and `MidiTrackState` would be helpful, but it is not required before drafting the four function bodies. Scores should remain below 95 because original type names are not recovered.

### Scratch globals

Recommended source-quality names:

| Current global | Recommended name | Role |
| --- | --- | --- |
| `dword_69B870` | `g_midiTrackScanCursor` | Track-table scan cursor/end pointer during selection. |
| `dword_69B874` | `g_midiSelectedTrack` | Chosen active `MidiTrackState*`. |
| `dword_69B878` | `g_midiFillState` | Scratch bitfield: end, parse error, pending event replay. |
| `dword_69B87C` | `g_midiSelectedTick` | Best/smallest pending tick found during scan. |
| `xmmword_69B880` | `g_midiPendingEvent` | 16-byte parsed event retried after output-full. |

Recommended bit names:

- `MIDI_FILL_AT_END = 0x01`
- `MIDI_FILL_PARSE_ERROR = 0x02`
- `MIDI_FILL_PENDING_EVENT = 0x04`

Rejected alternative: keep `dword_69B...` names in C++ until original symbols are recovered. This would preserve searchability but fails the source-quality requirement. The report should preserve raw names in historical notes and use descriptive names in code.

Impact: update [UID:0002B2] and [UID:0000T9] to include the descriptive name map; this supports formal C++ for 0002C6.

### Status constants and WinMM event constants

Recommended constants:

```cpp
enum MidiFillResult {
    MIDI_FILL_OK = 0,
    MIDI_FILL_PARSE_FAILED = -101,
    MIDI_FILL_PREVIOUS_PARSE_FAILED = -102,
    MIDI_FILL_END_OF_STREAM = -103,
    MIDI_FILL_OUTPUT_FULL = -104,
    MIDI_FILL_UNSUPPORTED_EVENT = -105
};

enum MidiStatusConstants {
    MIDI_STATUS_CONTROL_CHANGE = 0xB0,
    MIDI_STATUS_PROGRAM_CHANGE = 0xC0,
    MIDI_STATUS_CHANNEL_PRESSURE = 0xD0,
    MIDI_STATUS_SYSEX = 0xF0,
    MIDI_STATUS_ESCAPE = 0xF7,
    MIDI_STATUS_META = 0xFF,
    MIDI_META_END_OF_TRACK = 0x2F,
    MIDI_META_TEMPO = 0x51,
    MIDI_CONTROLLER_VOLUME = 7
};
```

Evidence: target docs record `-101`, `-102`, `-103`, `-104`, and `-105`; stream open/callback docs treat `0xffffff99` as end-of-stream; encoder docs record `0x40000000` for controller-volume callback tagging and `0x01000000` for tempo stream records.

Rejected alternative: name `-104` as a hard error. The stream-fill helper uses it to preserve/retry a pending event when the caller buffer is full, so `MIDI_FILL_OUTPUT_FULL` is more accurate.

Impact: resolves the "negative status constants" blocker enough for draft C++. Confidence remains below final because exact original enum names are unavailable.

### SMF tags and endian handling

Recommended constants:

```cpp
static const DWORD MIDI_TAG_MTHD = 0x6468544D;
static const DWORD MIDI_TAG_MTRK = 0x6B72544D;
```

These match little-endian memory comparison for ASCII `MThd` and `MTrk` as recorded in 0002C7. Header length, format, track count, division, and track length should be byte-swapped from file order.

Rejected alternative: use host-order FourCC text macros without noting endianness. The documentation records numeric comparisons, so source should make the file-order conversion explicit.

Impact: improves 0002C7 C++ readiness.

### Source placement of shared declarations

Best placement: add shared helper declarations, structs, constants, and globals to [UID:0000LD] `MidiPlayer.cpp` documentation, with possible future by-type pages for `MidiDocument`, `MidiTrackState`, `MidiEvent`, and `MidiStreamWriteContext`.

Rejected placement: by-class `MidiPlayer` only. The document parser and scratch globals are file-static implementation details and not class object layout.

Impact: the target function C++ blocks can reference these shared declarations; the declarations themselves should not be pasted into every target function block as if each function owned them.

### Remaining blockers

Remaining uncertainty is not enough to keep formal C++ blank:

- Original function/type/global names are not recovered.
- Current IDA MCP was unavailable for this session, so this report relies on existing prior IDA-backed documentation and local files.
- 0002C6 has the most nuanced return behavior around end-of-stream replay and pending output-full replay. The draft captures the documented state machine, but this target should stay slightly lower at 86/90 until a future live decompile pass verifies the exact branch-to-return mapping.
- No by-type page currently defines the MIDI document or track record structure. Creating those pages would improve score ceiling and make future code cleaner.

## Ranked Ownership Analysis

### 1. [UID:0000LD] MidiPlayer by-file

Evidence for:

- File page is projected to `NexusTK/audio/`.
- It explicitly owns WinMM MIDI stream setup, callback, reset, document release, reader/parser helpers, SMF load/fill helpers, `g_pMidiPlayer`, and `MidiPlayerWinMMState`.
- `auto-generated/-ag-memory-coverage.md` routes all four targets to `0000LD` and resolves to `auto-generated/NexusTK/audio/MidiPlayer.cpp`.
- Stream-open [UID:0001CE] and callback [UID:0001CG] call 0002C6; parse wrapper [UID:0002C5] calls 0002C7; 0002BU and 0002BV are internal to the same parser/fill island.

Evidence against:

- A private SMF parser source file is plausible in human source, but no source filename or separate by-file owner exists.

Decision: best direct owner and emitter.

### 2. [UID:00008A] MidiPlayer by-class

Evidence for:

- The class is the process MIDI playback controller and owns singleton state.

Evidence against:

- The target helpers are file-static/parser-global behavior, not methods on the 12-byte `MidiPlayer` object.
- They operate on `MidiDocument` static state and WinMM callback buffers rather than `this` class fields.

Decision: useful context, not canonical owner for these helpers.

### 3. Proposed new `MidiSMFDocument.cpp`

Evidence for:

- The SMF parser is a coherent private helper family with its own document/source context, track table, and scratch state.

Evidence against:

- No recovered source filename, no proposed-source-tree entry, and no stronger owner than the existing `MidiPlayer.cpp` module.
- The parser is tightly tied to `MidiPlayer` globals, callback, reset, and WinMM stream buffers.

Decision: do not create now. Mention as possible future source-layout refinement only.

## First-Draft C++ Recommendation

The following is intended as mid-2000s C++ source shape. Names are descriptive/inferred. Shared declarations should be added once in the `MidiPlayer` source-family docs or future by-type docs; individual target pages should receive only their function body where possible.

### Shared Descriptive Declarations

```cpp
static const DWORD MIDI_TAG_MTHD = 0x6468544D;
static const DWORD MIDI_TAG_MTRK = 0x6B72544D;

static const BYTE MIDI_STATUS_CONTROL_CHANGE = 0xB0;
static const BYTE MIDI_STATUS_PROGRAM_CHANGE = 0xC0;
static const BYTE MIDI_STATUS_CHANNEL_PRESSURE = 0xD0;
static const BYTE MIDI_STATUS_SYSEX = 0xF0;
static const BYTE MIDI_STATUS_ESCAPE = 0xF7;
static const BYTE MIDI_STATUS_META = 0xFF;

static const BYTE MIDI_META_END_OF_TRACK = 0x2F;
static const BYTE MIDI_META_TEMPO = 0x51;
static const BYTE MIDI_CONTROLLER_VOLUME = 7;

static const DWORD MIDI_TRACK_DONE = 0x00000001;
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

struct MidiEvent {
    DWORD tick;
    BYTE status;
    BYTE data1;
    BYTE data2;
    BYTE reserved;
    DWORD payloadLength;
    BYTE* payload;
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

struct MidiDocument {
    DWORD sourceSize;
    DWORD timeDivision;
    DWORD format;
    DWORD trackCount;
    MidiTrackState* tracks;
    DWORD datFileSource;
    DATFile datFile;
    HANDLE fileHandle;
    DWORD reserved30;
    DWORD allocatedPayloadCount;
    DWORD tempoTickCache;
    DWORD tempoScale;
    DWORD tempoUSecPerQuarter;
};

static int MidiReadTrackByte(MidiDocument* document, MidiTrackState* track, BYTE* value);
static int MidiReadVariableLength(MidiDocument* document, MidiTrackState* track, DWORD* value);
static int MidiPrimeTracks(MidiDocument* document);
static int MidiReadRaw(MidiDocument* document, void* buffer, DWORD bytesToRead, DWORD* bytesRead);
static int MidiReadExact(MidiDocument* document, void* buffer, DWORD bytesToRead);
static DWORD MidiSeekSource(MidiDocument* document, LONG offset, DWORD origin);
static int MidiOpenSource(MidiDocument* document, const wchar_t* path);
static void MidiReleaseDocument(MidiDocument* document);
static int MidiWriteStreamEvent(MidiDocument* document, const MidiEvent* event, MidiStreamWriteContext* stream);

static MidiTrackState* g_midiTrackScanCursor;
static MidiTrackState* g_midiSelectedTrack;
static DWORD g_midiFillState;
static DWORD g_midiSelectedTick;
static MidiEvent g_midiPendingEvent;
```

### [UID:0002BU] MidiEventReader

Formal C++ should be populated.

```cpp
static int MidiReadEvent(MidiDocument* document, MidiTrackState* track, MidiEvent* event)
{
    BYTE value;
    BYTE status;
    DWORD length;
    DWORD nextDelta;

    ZeroMemory(event, sizeof(*event));
    event->tick = track->pendingTick;

    if (MidiReadTrackByte(document, track, &value) != 0) {
        return 1;
    }

    if ((value & 0x80) != 0) {
        status = value;
        event->status = status;

        if (status < MIDI_STATUS_SYSEX) {
            track->runningStatus = status;
        }
    } else {
        status = (BYTE)track->runningStatus;
        if (status == 0) {
            return 1;
        }

        event->status = status;
        event->data1 = value;
    }

    if (status < MIDI_STATUS_SYSEX) {
        if ((value & 0x80) != 0) {
            if (MidiReadTrackByte(document, track, &event->data1) != 0) {
                return 1;
            }
        }

        if ((status & 0xF0) != MIDI_STATUS_PROGRAM_CHANGE &&
            (status & 0xF0) != MIDI_STATUS_CHANNEL_PRESSURE) {
            if (MidiReadTrackByte(document, track, &event->data2) != 0) {
                return 1;
            }
        }

        if (MidiReadVariableLength(document, track, &nextDelta) != 0) {
            return 1;
        }
        track->pendingTick += nextDelta;
        return 0;
    }

    if (status == MIDI_STATUS_SYSEX || status == MIDI_STATUS_ESCAPE) {
        if (MidiReadVariableLength(document, track, &length) != 0) {
            return 1;
        }

        event->payloadLength = length;
        if (length != 0) {
            event->payload = (BYTE*)malloc(length);
            if (event->payload == NULL) {
                return 1;
            }
            ++document->allocatedPayloadCount;

            while (length-- != 0) {
                if (MidiReadTrackByte(document, track, event->payload + event->payloadLength - length - 1) != 0) {
                    return 1;
                }
            }
        }

        if (MidiReadVariableLength(document, track, &nextDelta) != 0) {
            return 1;
        }
        track->pendingTick += nextDelta;
        return 0;
    }

    if (status != MIDI_STATUS_META) {
        return 1;
    }

    if (MidiReadTrackByte(document, track, &event->data1) != 0) {
        return 1;
    }
    if (MidiReadVariableLength(document, track, &length) != 0) {
        return 1;
    }

    event->payloadLength = length;
    if (length != 0) {
        event->payload = (BYTE*)malloc(length);
        if (event->payload == NULL) {
            return 1;
        }
        ++document->allocatedPayloadCount;

        for (DWORD i = 0; i < length; ++i) {
            if (MidiReadTrackByte(document, track, event->payload + i) != 0) {
                return 1;
            }
        }
    }

    if (event->data1 == MIDI_META_END_OF_TRACK) {
        track->flags |= MIDI_TRACK_DONE;
        return 0;
    }

    if (MidiReadVariableLength(document, track, &nextDelta) != 0) {
        return 1;
    }
    track->pendingTick += nextDelta;
    return 0;
}
```

### [UID:0002BV] MidiStreamEventEncoder

Formal C++ should be populated.

```cpp
static DWORD MidiEventDelta(MidiStreamWriteContext* stream, const MidiEvent* event)
{
    DWORD delta = event->tick - stream->lastEventTick;
    stream->lastEventTick = event->tick;
    return delta;
}

static int MidiWriteShortStreamEvent(MidiStreamWriteContext* stream, DWORD tick, DWORD event)
{
    MIDIEVENT* outEvent;

    if (stream->writeOffset + sizeof(MIDIEVENT) > stream->writeLimit) {
        stream->fullEventPending = 1;
        return MIDI_FILL_OUTPUT_FULL;
    }

    outEvent = (MIDIEVENT*)(stream->buffer + stream->writeOffset);
    outEvent->dwDeltaTime = tick;
    outEvent->dwStreamID = 0;
    outEvent->dwEvent = event;

    stream->writeOffset += sizeof(MIDIEVENT);
    stream->bytesWritten += sizeof(MIDIEVENT);
    stream->fullEventPending = 0;
    return MIDI_FILL_OK;
}

static void MidiFreeEventPayload(MidiDocument* document, const MidiEvent* event)
{
    if (event->payload != NULL && document->allocatedPayloadCount != 0) {
        free(event->payload);
        --document->allocatedPayloadCount;
    }
}

static int MidiWriteStreamEvent(MidiDocument* document, const MidiEvent* event, MidiStreamWriteContext* stream)
{
    DWORD packed;
    DWORD tempo;
    int result;

    if (event->status < MIDI_STATUS_SYSEX) {
        packed = event->status | ((DWORD)event->data1 << 8) | ((DWORD)event->data2 << 16);

        if ((event->status & 0xF0) == MIDI_STATUS_CONTROL_CHANGE &&
            event->data1 == MIDI_CONTROLLER_VOLUME) {
            packed |= 0x40000000;
        }

        return MidiWriteShortStreamEvent(stream, MidiEventDelta(stream, event), packed);
    }

    if (event->status == MIDI_STATUS_SYSEX || event->status == MIDI_STATUS_ESCAPE) {
        MidiFreeEventPayload(document, event);
        return MIDI_FILL_OK;
    }

    if (event->status == MIDI_STATUS_META && event->data1 == MIDI_META_TEMPO) {
        if (event->payloadLength < 3 || event->payload == NULL) {
            MidiFreeEventPayload(document, event);
            return MIDI_FILL_UNSUPPORTED_EVENT;
        }

        tempo = ((DWORD)event->payload[0] << 16) |
                ((DWORD)event->payload[1] << 8) |
                (DWORD)event->payload[2];

        document->tempoUSecPerQuarter = tempo;
        document->tempoTickCache = event->tick;

        result = MidiWriteShortStreamEvent(
            stream,
            MidiEventDelta(stream, event),
            0x01000000 | (tempo & 0x00FFFFFF));

        MidiFreeEventPayload(document, event);
        return result;
    }

    MidiFreeEventPayload(document, event);
    return MIDI_FILL_UNSUPPORTED_EVENT;
}
```

### [UID:0002C6] MidiStreamBufferFillHelper

Formal C++ should be populated, but keep the page score below the other three until the exact replay/end branch values are live-IDA rechecked.

```cpp
static void MidiResetFillScratch(void)
{
    g_midiTrackScanCursor = NULL;
    g_midiSelectedTrack = NULL;
    g_midiFillState = 0;
    g_midiSelectedTick = 0xFFFFFFFF;
    ZeroMemory(&g_midiPendingEvent, sizeof(g_midiPendingEvent));
}

static MidiTrackState* MidiSelectNextTrack(MidiDocument* document)
{
    MidiTrackState* track;
    MidiTrackState* best;
    DWORD bestTick;

    best = NULL;
    bestTick = 0xFFFFFFFF;
    track = document->tracks;

    for (DWORD i = 0; i < document->trackCount; ++i, ++track) {
        if ((track->flags & MIDI_TRACK_DONE) != 0) {
            continue;
        }

        if (best == NULL || track->pendingTick < bestTick) {
            best = track;
            bestTick = track->pendingTick;
        }
    }

    g_midiSelectedTrack = best;
    g_midiSelectedTick = bestTick;
    return best;
}

static int MidiFillStreamBuffer(MidiDocument* document, BOOL resetState, MidiStreamWriteContext* stream, BOOL allowEndReplay)
{
    MidiTrackState* track;
    int result;

    stream->bytesWritten = 0;

    if (resetState) {
        MidiResetFillScratch();
        if (MidiPrimeTracks(document) != 0) {
            g_midiFillState |= MIDI_FILL_PARSE_ERROR;
            return MIDI_FILL_PARSE_FAILED;
        }
    } else {
        if ((g_midiFillState & MIDI_FILL_AT_END) != 0 && !allowEndReplay) {
            return MIDI_FILL_END_OF_STREAM;
        }
        if ((g_midiFillState & MIDI_FILL_PARSE_ERROR) != 0) {
            return MIDI_FILL_PREVIOUS_PARSE_FAILED;
        }
    }

    if ((g_midiFillState & MIDI_FILL_PENDING_EVENT) != 0) {
        g_midiFillState &= ~MIDI_FILL_PENDING_EVENT;
        result = MidiWriteStreamEvent(document, &g_midiPendingEvent, stream);
        if (result == MIDI_FILL_OUTPUT_FULL) {
            g_midiFillState |= MIDI_FILL_PENDING_EVENT;
            return MIDI_FILL_OK;
        }
        if (result != MIDI_FILL_OK) {
            g_midiFillState |= MIDI_FILL_PARSE_ERROR;
            return result;
        }
    }

    for (;;) {
        track = MidiSelectNextTrack(document);
        if (track == NULL) {
            g_midiFillState |= MIDI_FILL_AT_END;
            return MIDI_FILL_END_OF_STREAM;
        }

        ZeroMemory(&g_midiPendingEvent, sizeof(g_midiPendingEvent));
        if (MidiReadEvent(document, track, &g_midiPendingEvent) != 0) {
            g_midiFillState |= MIDI_FILL_PARSE_ERROR;
            return MIDI_FILL_PARSE_FAILED;
        }

        if (g_midiPendingEvent.status == MIDI_STATUS_META &&
            g_midiPendingEvent.data1 == MIDI_META_END_OF_TRACK) {
            if (g_midiPendingEvent.payload != NULL && document->allocatedPayloadCount != 0) {
                free(g_midiPendingEvent.payload);
                --document->allocatedPayloadCount;
            }
            continue;
        }

        result = MidiWriteStreamEvent(document, &g_midiPendingEvent, stream);
        if (result == MIDI_FILL_OUTPUT_FULL) {
            g_midiFillState |= MIDI_FILL_PENDING_EVENT;
            return MIDI_FILL_OK;
        }
        if (result != MIDI_FILL_OK) {
            g_midiFillState |= MIDI_FILL_PARSE_ERROR;
            return result;
        }
    }
}
```

### [UID:0002C7] MidiSMFDocumentLoadHelper

Formal C++ should be populated.

```cpp
static WORD MidiSwapWord(WORD value)
{
    return (WORD)((value << 8) | (value >> 8));
}

static DWORD MidiSwapDword(DWORD value)
{
    return ((value & 0x000000FF) << 24) |
           ((value & 0x0000FF00) << 8) |
           ((value & 0x00FF0000) >> 8) |
           ((value & 0xFF000000) >> 24);
}

static int MidiLoadDocument(MidiDocument* document, const wchar_t* path)
{
    DWORD tag;
    DWORD headerLength;
    WORD format;
    WORD trackCount;
    WORD division;
    HGLOBAL tableHandle;

    document->sourceSize = 0;
    document->timeDivision = 0;
    document->format = 0;
    document->trackCount = 0;
    document->tracks = NULL;
    document->allocatedPayloadCount = 0;

    if (MidiOpenSource(document, path) != 0) {
        return 0;
    }

    if (MidiReadExact(document, &tag, sizeof(tag)) != 0 || tag != MIDI_TAG_MTHD) {
        MidiReleaseDocument(document);
        return 0;
    }

    if (MidiReadExact(document, &headerLength, sizeof(headerLength)) != 0 ||
        MidiReadExact(document, &format, sizeof(format)) != 0 ||
        MidiReadExact(document, &trackCount, sizeof(trackCount)) != 0 ||
        MidiReadExact(document, &division, sizeof(division)) != 0) {
        MidiReleaseDocument(document);
        return 0;
    }

    headerLength = MidiSwapDword(headerLength);
    format = MidiSwapWord(format);
    trackCount = MidiSwapWord(trackCount);
    division = MidiSwapWord(division);

    if (headerLength < 6 || trackCount == 0) {
        MidiReleaseDocument(document);
        return 0;
    }

    if (headerLength > 6) {
        MidiSeekSource(document, (LONG)(headerLength - 6), FILE_CURRENT);
    }

    document->format = format;
    document->trackCount = trackCount;
    document->timeDivision = division;

    tableHandle = GlobalAlloc(0x40, sizeof(MidiTrackState) * trackCount);
    document->tracks = (MidiTrackState*)GlobalLock(tableHandle);
    if (document->tracks == NULL) {
        MidiReleaseDocument(document);
        return 0;
    }

    for (DWORD i = 0; i < trackCount; ++i) {
        MidiTrackState* track = document->tracks + i;
        DWORD length;
        DWORD bytesRead;
        DWORD firstRead;
        HGLOBAL bufferHandle;

        if (MidiReadExact(document, &tag, sizeof(tag)) != 0 || tag != MIDI_TAG_MTRK) {
            MidiReleaseDocument(document);
            return 0;
        }

        if (MidiReadExact(document, &length, sizeof(length)) != 0) {
            MidiReleaseDocument(document);
            return 0;
        }

        length = MidiSwapDword(length);
        ZeroMemory(track, sizeof(*track));
        track->trackLength = length;
        track->trackStartOffset = MidiSeekSource(document, 0, FILE_CURRENT);
        track->sourceOffset = track->trackStartOffset;
        track->bytesRemaining = length;

        bufferHandle = GlobalAlloc(0x40, 0x400);
        track->buffer = (BYTE*)GlobalLock(bufferHandle);
        if (track->buffer == NULL) {
            MidiReleaseDocument(document);
            return 0;
        }

        firstRead = (length < 0x400) ? length : 0x400;
        if (firstRead != 0) {
            if (MidiReadRaw(document, track->buffer, firstRead, &bytesRead) != 0 ||
                bytesRead != firstRead) {
                MidiReleaseDocument(document);
                return 0;
            }

            track->bufferedBytes = bytesRead;
            track->cursor = track->buffer;
            track->sourceOffset += bytesRead;
            track->bytesRemaining -= bytesRead;

            if (MidiReadVariableLength(document, track, &track->pendingTick) != 0) {
                MidiReleaseDocument(document);
                return 0;
            }
        } else {
            track->flags |= MIDI_TRACK_DONE;
        }

        MidiSeekSource(document, (LONG)(track->trackStartOffset + track->trackLength), FILE_BEGIN);
    }

    return 1;
}
```

## Exact Supervisor-Owned Replacement Rows For `by-memory/-coverage-report.md`

Placement context: replace the existing rows under the `0x00526650-0x005270d5` and `0x005271b0-0x005277bb` MIDI helper sections. Do not edit this file directly from B001.

```text
        - [UID:0002BU][0x00526790-0x005269ea.MidiEventReader](by-memory/0x00526790-0x005269ea.MidiEventReader.md) 0x00526790-0x005269ea | function | MidiEventReader : reconstructable : 88% : strong : Attached to `MidiPlayer.cpp`; source-quality pass validates descriptive names `MidiReadEvent`, `MidiDocument`, `MidiTrackState`, and `MidiEvent`, confirms running-status/channel/SysEx/meta/end-of-track behavior from prior IDA-backed docs, and recommends formal C++ population under the current emitter gate.
        - [UID:0002BV][0x005269f0-0x00526ba8.MidiStreamEventEncoder](by-memory/0x005269f0-0x00526ba8.MidiStreamEventEncoder.md) 0x005269f0-0x00526ba8 | function | MidiStreamEventEncoder : reconstructable : 87% : strong : Attached to `MidiPlayer.cpp`; source-quality pass validates descriptive name `MidiWriteStreamEvent`, `MidiStreamWriteContext`, WinMM `MIDIEVENT` 12-byte writes, tempo `0xff/0x51`, controller-volume callback tagging, payload cleanup, and named `MIDI_FILL_OUTPUT_FULL`/`MIDI_FILL_UNSUPPORTED_EVENT` returns; formal C++ should be populated.
        - [UID:0002C6][0x005271b0-0x005273a0.MidiStreamBufferFillHelper](by-memory/0x005271b0-0x005273a0.MidiStreamBufferFillHelper.md) 0x005271b0-0x005273a0 | function | MidiStreamBufferFillHelper : reconstructable : 86% : strong : Attached to `MidiPlayer.cpp`; source-quality pass validates descriptive name `MidiFillStreamBuffer`, scratch names `g_midiTrackScanCursor`/`g_midiSelectedTrack`/`g_midiFillState`/`g_midiSelectedTick`/`g_midiPendingEvent`, fill-state bits, and named negative results; formal C++ should be populated but branch-return confidence remains below final audit.
        - [UID:0002C7][0x005273a0-0x005277bb.MidiSMFDocumentLoadHelper](by-memory/0x005273a0-0x005277bb.MidiSMFDocumentLoadHelper.md) 0x005273a0-0x005277bb | function | MidiSMFDocumentLoadHelper : reconstructable : 88% : strong : Attached to `MidiPlayer.cpp`; source-quality pass validates descriptive name `MidiLoadDocument`, SMF tag constants `MThd`/`MTrk`, byte-swapped header fields, `MidiTrackState` allocation, 0x400-byte track buffers, initial VLQ seeding, and cleanup ownership; formal C++ should be populated.
```

## Support Docs The Supervisor Should Update

Rule 26 incorporation should not prune existing historical uncertainty. Add the new findings as source-quality conclusions and keep older unproven-name caveats as historical assumptions.

Target pages:

- [UID:0002BU] `0x00526790-0x005269ea.MidiEventReader.md`: add recommended descriptive function name `MidiReadEvent`; add `MidiEvent` and `MidiTrackState` field map; replace "C++ remains blank" with "formal C++ should be populated with inferred names"; add constants for channel status, SysEx, meta, EOT, and payload ownership.
- [UID:0002BV] `0x005269f0-0x00526ba8.MidiStreamEventEncoder.md`: add `MidiWriteStreamEvent`, `MidiStreamWriteContext`, `MidiFillResult`, `MEVT_F_CALLBACK`/tempo event reasoning, and formal C++ recommendation.
- [UID:0002C6] `0x005271b0-0x005273a0.MidiStreamBufferFillHelper.md`: add scratch global descriptive names, state bits, `MidiFillStreamBuffer` name, formal C++ recommendation, and note that exact end/replay branch mapping remains the score cap rather than a code-entry blocker.
- [UID:0002C7] `0x005273a0-0x005277bb.MidiSMFDocumentLoadHelper.md`: add `MidiLoadDocument`, `MidiDocument`, `MidiTrackState`, SMF endian/tag constants, allocation ownership, and formal C++ recommendation.

Support pages:

- [UID:00023B] `MidiFileReaderAndSMFParserHelpers`: incorporate the shared type/constant/name conclusions for reader, event, encoder, source helper, and track record; state that original names are unproven but descriptive names are now preferred.
- [UID:00023C] `MidiSMFLoadAndStreamFillHelpers`: incorporate `MidiFillStreamBuffer`, `MidiLoadDocument`, scratch names, status constants, and C++ readiness change for the two exact children.
- [UID:0001CE] `MidiStreamOpenAndPrimeBuffers`: replace raw `0xffffff99` references with `MIDI_FILL_END_OF_STREAM` while retaining the numeric value; mention that fill helper C++ now exists and output-full is internally replayed as `MIDI_FILL_OUTPUT_FULL`.
- [UID:0001CG] `MidiStreamCallback`: same named return/status update; connect callback volume handling to 0002BV's `0x40000000` callback tagging.
- [UID:0001CI] `MidiDocumentRelease`: update terminology from "event table" to "track table" where it refers to the 40-byte track records; preserve any historical `eventTable` naming as stale/generated.
- [UID:0002B2] `MidiSMFParserScratchGlobals`: add the recommended scratch global names and bit constants.
- [UID:0000T9] `MidiPlayerWinMMState`: add the scratch names and `MidiDocument`/`MidiTrackState` declaration plan; keep raw names for searchability.
- [UID:0000LD] `MidiPlayer` by-file: update open questions to say the original private SMF helper split is unproven, but current source-quality descriptive names are accepted for draft C++; mention the generated `auto-generated/NexusTK/audio/MidiPlayer.cpp` file is currently empty until reconstruction blocks are populated.
- [UID:00008A] `MidiPlayer` by-class: update helper map and caveats to reference the new descriptive names, while making clear these remain private file helpers rather than class object methods.
- Consider new by-type pages for `MidiDocument`, `MidiTrackState`, `MidiEvent`, `MidiStreamWriteContext`, and `MidiFillResult`. This is not mandatory before code entry but would improve future score ceiling.

## Negative Evidence Summary

- No by-type page currently defines a project `MidiDocument`, `MidiTrackState`, `SMF`, or MIDI source-adapter type.
- IDA MCP was unavailable in this session, so no new decompile/xref command could prove original names.
- Wave3 `simroot_v2/audio/MidiPlayer.cpp` is useful for leads but contains modern `std::uint*`, `constexpr`, `nullptr`, overlay casts, and generic decompiler symbols. It should not be copied as final source.
- The auto-generated final `NexusTK/audio/MidiPlayer.cpp` file is empty, showing the current emitter route has not yet received reconstruction code.
- Consumer xrefs alone do not prove ownership, but here the consumer set is not isolated: stream open, callback, reset, document release, scratch globals, file page, class page, and generated coverage all point to the same `MidiPlayer` source family.

## Final Recommendation

Exact changes recommended:

- Keep all four targets assigned to [UID:0000LD] and emitted through [UID:0000LD].
- Raise target scores as listed at the top after the target pages incorporate this source-quality reanalysis and C++ draft.
- Populate formal reconstruction C++ blocks for all four targets. Do not leave them blank solely because original names are unavailable; use inferred/descriptive names and mark them as such.
- Update `by-memory/-coverage-report.md` using the exact replacement rows above.
- Update the support docs listed above so the source-quality findings are incorporated at report-level detail.

Exact items left unresolved:

- Original source names for helper functions and internal structs.
- Whether the original project had a separate private SMF document `.cpp`; current best owner remains `MidiPlayer.cpp`.
- Exact 0002C6 branch return mapping for all replay/end states, which caps score but does not block a first-draft source implementation.

## Validator Results

Commands run:

> Executable block R001 was removed from this report and preserved verbatim in [0002BU-0002BV-0002C6-0002C7-MidiSMFParserStreamSourceQuality-removed.md](0002BU-0002BV-0002C6-0002C7-MidiSMFParserStreamSourceQuality-removed.md). The archived block is non-authoritative and must not be executed.

Results:

- IDA MCP check failed with `IDA_MCP_ERROR: Unable to connect to the remote server`.
- `auto-generated/NexusTK/audio/MidiPlayer.cpp` exists and has `Length: 0`.
- Existing B001/B002/B003 executed research search found no prior report for these exact target UIDs.
- Post-write readback found exactly one matching report filename under the B001 research directory.
- ASCII safety check returned `ASCII_OK`.
- `Test-Path` returned `True`; line count was `716`.
- `git status` was attempted only for readback context and failed with `fatal: not a git repository (or any of the parent directories): .git`.
- No validator run was needed because this assignment created only this B001 research report and did not edit by-* docs or generated metadata.

## Changed Files

Created:

- `source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/0002BU-0002BV-0002C6-0002C7-MidiSMFParserStreamSourceQuality.md`

Modified:

- None outside this research report.

Renamed:

- None.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0002BU-0002BV-0002C6-0002C7-MidiSMFParserStreamSourceQuality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:21","uid":"0002BU"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002BU-0002BV-0002C6-0002C7-MidiSMFParserStreamSourceQuality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0002BU-0002BV-0002C6-0002C7-MidiSMFParserStreamSourceQuality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002BU"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
