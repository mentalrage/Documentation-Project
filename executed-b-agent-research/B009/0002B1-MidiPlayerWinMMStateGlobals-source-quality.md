** TARGET-REPORT-UID:0002B1 **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# UID0002B1 MidiPlayerWinMMStateGlobals Source-Quality Report


## Finalized Report / Current Recommendation

UID0002B1 should stay owned by [UID:0000T9][MidiPlayerWinMMState](../../../../../by-global/MidiPlayerWinMMState.md), emitted through that owner into [UID:0000LD][MidiPlayer](../../../../../by-file/MidiPlayer.md), and changed from a blank data page to the source-declaration owner for the concrete `0x0069b500-0x0069b870` WinMM MIDI state.

The current initializer conclusion is not mixed at file/static-storage time: live MCP session `supervisor_recovery_20260705` reads zero bytes across the sampled target range and at the adjacent UID0002B2 scratch range. The older `0xffffffff`/`0xff` target wording is stale as static-initializer evidence. Runtime code still writes sentinel/default values after static initialization: `MidiPlayer::MidiPlayer` writes device id `-1`, replay flag `1`, volume scale `500`, and creates the buffer-return event; `MidiFillStreamBuffer` writes `0xffffffff` to the selected-tick scratch during scans. The implementation should therefore document zero-initialized storage plus runtime defaults, not static `0xffffffff` declarations.

Recommended target metadata after implementation: `COMPLETION:89`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000T9`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000T9`, and `EMITTER_POSITION_OPTIONAL:0`. The position change is needed because generated `MidiPlayer.cpp` currently references these globals before UID0002B1 contributes declarations.

## Supporting Research

Scope reviewed for this report-only pass:

- Target: [UID:0002B1][0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals](../../../../../by-memory/0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals.md).
- Global/file/class support: [UID:0000T9][MidiPlayerWinMMState](../../../../../by-global/MidiPlayerWinMMState.md), [UID:0000LD][MidiPlayer](../../../../../by-file/MidiPlayer.md), and [UID:00008A][MidiPlayer](../../../../../by-class/MidiPlayer.md).
- MIDI helper pages around `0x00525920-0x0052664b`, reset/callback/open/track-control pages, static destructor wrapper `0x0060c300`, and adjacent [UID:0002B2][MidiSMFParserScratchGlobals](../../../../../by-memory/0x0069b870-0x0069b890.MidiSMFParserScratchGlobals.md).
- Generated `auto-generated/NexusTK/audio/MidiPlayer.cpp` read-only state at validator command `000000007322`, refreshed `2026-07-05T18:54:51-04:00`.
- Tracker/coverage generated rows read-only: UID0002B1 remains `85/90`, reconstructable true, memory coverage says it emits through `MidiPlayer.cpp`, but generated output contains only an empty UID0002B1 marker.
- Live MCP: JSON-RPC endpoint `http://127.0.0.1:13337/mcp`, database/session `supervisor_recovery_20260705`, `server_health` status `ok`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.

Report-only phase note: no by-* implementation edits, validators, lifecycle commands, generated edits, coverage edits, or manual tracker edits were performed before Gate 1.

Implementation callback note: after Gate 1 passed, B009 edited the accepted target/support by-* docs under leases, ran scoped file validators only, and inspected validator-owned generated output read-only. No `execute_report`, lifecycle/archive command, manual generated edit, manual coverage edit, manual tracker edit, or supervisor-ledger edit was performed.

## Target

- UID: `0002B1`
- Path: `by-memory/0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals.md`
- Pre-implementation state: `COMPLETION:85`, `CONFIDENCE:90`, owner/emitter `0000T9`, reconstructable true, blank formal C++.
- Post-implementation state: `COMPLETION:89`, `CONFIDENCE:92`, owner/emitter `0000T9`, reconstructable true, `EMITTER_POSITION_OPTIONAL:0`, formal declaration block populated and validator-applied by command `000000007357`.
- Range: half-open `0x0069b500-0x0069b870`.
- Pre-implementation generated symptom: `auto-generated/NexusTK/audio/MidiPlayer.cpp` referenced `g_hMidiStream`, `g_midiHeaders`, `g_midiCurrentPath`, `g_midiDocumentState`, and related names, but UID0002B1 emitted only an empty marker near the end of the file.
- Post-implementation generated state: `auto-generated/NexusTK/audio/MidiPlayer.cpp` now contains UID0002B1 declarations near the top of the file before UID0002B2 and before helper bodies. The inspected header records validator command `000000007356`, refreshed `2026-07-05T19:31:55-04:00`; final target validator command `000000007357` exited `0` and reported `generated_refresh: completed`.

## Current Target State

The page already has the right high-level owner and range, but its evidence is internally contradictory. The active `## Evidence` section still says a 2026-06-07 pass confirmed `0xff` initialized bytes and `0xffffffff` static-state initialization. Later target and support notes from 2026-07-02 and 2026-06-30 correctly warn that newer MCP reads returned zero bytes at `0x0069b500`, `0x0069b828`, and `0x0069b870`.

The current MCP pass resolves that conflict:

- `get_bytes` returned all zero bytes for sampled regions `0x0069b500+0x80`, `0x0069b580+0x80`, `0x0069b600+0x60`, `0x0069b820+0x70`, and `0x0069b870+0x20`.
- `get_int` returned `0` for dwords at `0x0069b500`, `0x0069b504`, `0x0069b508`, `0x0069b50c`, `0x0069b510`, `0x0069b514`, `0x0069b518`, `0x0069b51c`, `0x0069b520`, `0x0069b524`, `0x0069b5d0`, `0x0069b610`, `0x0069b614`, `0x0069b618`, `0x0069b828`, `0x0069b840`, `0x0069b86c`, and all sampled UID0002B2 dwords through `0x0069b88c`.
- `entity_query names` inside `0x0069b500-0x0069b890` returned only `hms`, `puDeviceID`, `pmh`, `Destination`, and `hObject`; final source names remain descriptive/inferred rather than recovered symbol names.

The target is not a no-code page anymore. Its remaining blocker is incorporation of the declaration block and support synchronization for stale initializer text, not ownership or live evidence.

## Heuristic / Inference Reanalysis And Validation

The old heuristic failure was treating historical sampled `0xff` bytes as a current static initializer. Current live MCP contradicts that directly, and decompilation explains why the binary still contains runtime sentinels:

- `sub_525DC0` / `MidiPlayer::MidiPlayer` writes runtime defaults: `g_midiDeviceId = -1`, `g_midiRestartPending = 0`, `g_midiAllowEndReplay = 1`, `g_midiDocumentLoaded = 0`, `g_midiStreamRunning = 0`, `g_midiHeadersPrepared = 0`, `g_midiCallbackStreamOpen = 0`, `g_midiVolumeScale = 500`, and `g_hMidiBufferEvent = CreateEventW(...)`.
- `sub_525920` opens the stream, allocates two `0x400` buffers, loads the document from `g_midiCurrentPath`, copies the read-only four-dword default volume vector `100,100,100,100` four times into `g_midiChannelVolume[16]`, clears active/pending buffer counters, fills two `MIDIHDR` overlays, and marks headers prepared.
- `sub_525BE0` callback updates `g_midiStreamState`, `g_midiPendingBufferCount`, `g_midiChannelVolume[channel]`, `g_midiEndOfStreamReached`, and the active header index; it consumes `g_midiDocumentState` and `g_midiAllowEndReplay`.
- `sub_527080` constructs the 68-byte document object at `0x0069b828`: it constructs the embedded DATFile-like object at `+0x18`, sets `datFileSource = 0`, `fileHandle = -1`, `allocatedPayloadCount = 0`, and tempo scale `100`.
- `sub_5271B0` owns UID0002B2 runtime scratch mutations: reset/first-fill clears track cursor/selected/fill-state/pending-event scratch to zero, while each scan sets selected tick to `0xffffffff`. This supports zero static declarations plus runtime sentinel writes for UID0002B2.

The source-shape blocker is therefore resolved as follows: UID0002B1 should emit zero-initialized file-scope static storage and private MIDI layout declarations at the top of `MidiPlayer.cpp`; child helper bodies keep writing runtime defaults. Support docs should preserve the historical `0xffffffff` notes only as rejected stale static-initializer evidence.

## Ranked Ownership Analysis

| Rank | Candidate | Disposition | Evidence |
| ---: | --- | --- | --- |
| 1 | [UID:0000T9][MidiPlayerWinMMState](../../../../../by-global/MidiPlayerWinMMState.md) with emitter route to [UID:0000LD][MidiPlayer](../../../../../by-file/MidiPlayer.md) | Accepted | Current target metadata already uses this route; all observed xrefs are WinMM MIDI stream/callback/document helpers; by-global formal marker delegates exact declarations to UID0002B1/UID0002B2 children. |
| 2 | Direct [UID:0000LD][MidiPlayer](../../../by-file/MidiPlayer.md) owner/emitter on UID0002B1 | Rejected for canonical owner, accepted as source file route | The source file is `NexusTK/audio/MidiPlayer.cpp`, but the project uses `MidiPlayerWinMMState` as the scored global-state owner grouping for the exact data pages. |
| 3 | [UID:00008A][MidiPlayer](../../../by-class/MidiPlayer.md) object/class fields | Rejected | `MidiPlayer` object is 12 bytes; target storage is process-wide `.data`, referenced by free helpers/callbacks and not addressed via `this`. |
| 4 | UID0002B2 scratch block merge | Rejected | UID0002B1 ends at the last callback-era end-state dword `0x0069b86c`; UID0002B2 starts at `0x0069b870` and direct refs are confined to `sub_5271B0` stream-fill scratch use. |
| 5 | SoundManager/audio-driver owner | Rejected | Code uses WinMM MIDI APIs and MidiPlayer support docs; no RAD/Miles SoundManager owner evidence appears in current xrefs. |
| 6 | New `MidiSMFDocument.cpp` / parser-only file | Rejected for this target | No recovered filename, by-file page, proposed source-tree route, or stronger routing evidence. Parser/document helpers remain private support inside `MidiPlayer.cpp`. |

## Source Placement

Source placement is `NexusTK/audio/MidiPlayer.cpp`. UID0002B1 should remain a child data page under `MidiPlayerWinMMState`, but its formal declaration block should be generated early enough for all MIDI helper bodies. Recommended `EMITTER_POSITION_OPTIONAL:0` matches this role.

The declarations are file-scope/private static state, not public class members. They include WinMM stream state, two `MIDIHDR` overlay slots, channel volume table, path buffer, event handle, and the static SMF document object. The DATFile/archive implementation remains an external dependency; this page only stores the embedded `DATFile` subobject as part of `MidiDocument` layout.

## Range / Split / Padding / Reclassification Analysis

The current range remains correct and should not be split:

- `0x0069b500-0x0069b527`: stream handle, device id, state flags, volume scale, and small scalar globals.
- `0x0069b528-0x0069b5cf`: two 84-byte `MIDIHDR`/stream-write-context overlay slots.
- `0x0069b5d0-0x0069b60f`: sixteen dwords of channel-volume state; runtime open path copies four default dwords of `100` four times from `0x0061fb60`.
- `0x0069b610-0x0069b617`: active header index and pending buffer count.
- `0x0069b618-0x0069b81f`: 260-wide-character current-path buffer named `Destination` by IDA and `g_midiCurrentPath` in support docs.
- `0x0069b820-0x0069b823`: `g_hMidiBufferEvent`.
- `0x0069b824-0x0069b827`: no direct refs found; best treated as alignment padding before the document object, not a source-owned named field.
- `0x0069b828-0x0069b86b`: 68-byte `MidiDocument` state object; `0x0069b840` is the embedded DATFile-like subobject destroyed by `sub_60C300`.
- `0x0069b86c-0x0069b86f`: callback end-of-stream marker, last referenced dword before UID0002B2.
- `0x0069b870`: clean successor start for UID0002B2 stream-fill scratch.

`xrefs_to 0x0069b824` returned zero direct refs. The report recommends documenting the gap as alignment/padding and not hand-authoring a fake semantic global for it. If byte-exact layout needs a declaration cue, use alignment on `g_midiDocumentState`, not a made-up field.

## Evidence Standards Used

- Live MCP evidence is mandatory and was used for initializer, xref, function boundary, and representative decompilation decisions.
- Current docs and generated files are treated as inputs but not as authoritative when contradicted by live MCP.
- Source names are accepted as descriptive/source-facing only when supported by multiple helper pages and current xrefs; no original-symbol claim is made.
- Historical `0xffffffff` notes are preserved as rejected/superseded evidence rather than silently deleted.
- Generated files, coverage reports, tracker rows, and validator state were inspected read-only and not edited.

## Evidence Checked

Live MCP checks on `supervisor_recovery_20260705`:

- `server_health`: status `ok`; IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; Hex-Rays and strings cache ready.
- `get_bytes`: zero bytes at target windows `0x0069b500`, `0x0069b580`, `0x0069b600`, `0x0069b820`, and sibling `0x0069b870`.
- `get_int`: zero dwords at every sampled target/sibling state slot listed in Current Target State.
- `entity_query names`: labels `hms`, `puDeviceID`, `pmh`, `Destination`, and `hObject` only in `0x0069b500-0x0069b890`.
- `lookup_funcs`: modeled helpers include `sub_525920` size `0x1ed`, `sub_525BE0` size `0x1db`, `sub_525DC0` size `0xe6`, `sub_526240` size `0xf2`, `sub_526460` size `0x109`, `sub_5271B0` size `0x1f0`, `sub_41A010` size `0x16`, and `sub_60C300` size `0xa`; raw starts such as `0x00525f40` remain non-functions as documented.
- `xrefs_to`: UID0002B1 refs remain concentrated in MIDI stream open/callback/lifecycle/reset/control helpers. Counts include `0x0069b500` 29, `0x0069b504` 3, `0x0069b508` 10, `0x0069b50c` 13, `0x0069b510` 3, `0x0069b514` 14, `0x0069b518` 14, `0x0069b51c` 2, `0x0069b520` 5, `0x0069b524` 9, `0x0069b528` 10, `0x0069b5d0` 5, `0x0069b610` 10, `0x0069b614` 4, `0x0069b618` 3, `0x0069b820` 8, `0x0069b828` 7, `0x0069b840` 1, `0x0069b86c` 1, and successor `0x0069b870` 3.
- `decompile 0x00525dc0`: constructor runtime defaults and event creation.
- `decompile 0x00525920`: stream open/prime, current path parse, two `MIDIHDR` slots, channel-volume defaults, active/pending counters.
- `decompile 0x00525be0`: WinMM callback, state transitions, channel-volume forwarding, document release, end marker.
- `decompile 0x00526460`: reset/stop/wait/release/reopen behavior.
- `decompile 0x00526240`: current path copy and restart behavior.
- `decompile 0x00525b10`, `0x00525eb0`, `0x00525ff0`, `0x00526580`: release/destructor/volume/scalar-delete use of the same state.
- `decompile 0x00527080`, `0x005270e0`, `0x005273a0`: document constructor/release/load layout.
- `decompile 0x005271b0`: UID0002B2 runtime scratch writes and boundary separation.
- `get_bytes 0x0061fb60`: first four dwords are `100`, proving the runtime channel-volume default vector.

Read-only file checks:

- Target/support by-* docs listed above.
- `auto-generated/NexusTK/audio/MidiPlayer.cpp`: header command `000000007322`, UID0002B1 empty marker, UID0002B2 still explicit `0xFFFFFFFF` scratch declarations, and many helper bodies referencing UID0002B1 globals before the target marker.
- Generated coverage/tracker rows: memory coverage says UID0002B1 emits through `MidiPlayer.cpp`; research tracker still records `85/90`, reconstructable true, reports `0`.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0002B1-01 | MCP session `supervisor_recovery_20260705` is available and current for this report. | High | `server_health` status `ok`, Hex-Rays ready, IDB path matches NexusTK. | Target Evidence / Changes | incorporate | Applied to target evidence and support notes; validator `000000007357` ok. |
| C-0002B1-02 | Static/image bytes for UID0002B1 are zero in current MCP, not `0xff`. | High | `get_bytes` zero windows and `get_int` zero dwords across sampled target slots. | Target Evidence / Covered Data / Item Summary | incorporate | Applied to target summary, covered data, evidence, rebuild notes, and by-global support; validator `000000007357` ok. |
| C-0002B1-03 | Older `0xffffffff` target initializer wording is stale as static-storage evidence. | High | Current zero reads contradict target line claiming `0xff`; constructor/fill helpers explain runtime sentinels separately. | Target Evidence / Rebuild Notes | reject | Applied as rejected historical evidence in target/support; no active static `0xffffffff` claim remains in changed active sections. |
| C-0002B1-04 | Runtime defaults still include device id `-1`, allow-end-replay `1`, volume scale `500`, event creation, and selected tick `0xffffffff` during scan. | High | Decompiles of `0x00525dc0`, `0x005271b0`, and `0x00525920`. | Target Evidence / Field map | incorporate | Applied to target and UID0002B2 support; generated has runtime `0xFFFFFFFF` only in helper logic, not static declarations. |
| C-0002B1-05 | Owner remains `0000T9`; source file route remains `MidiPlayer.cpp`. | High | Current metadata, by-global child marker, helper xrefs all in MidiPlayer MIDI family. | Target Metadata / Status | incorporate | Applied; target header still owner/emitter `0000T9`; validator `000000007357` ok. |
| C-0002B1-06 | UID0002B1 should use `EMITTER_POSITION_OPTIONAL:0`. | High | Generated file references globals before the current empty UID0002B1 marker; sibling UID0002B2 already uses position 0 for declarations. | Target Metadata / Rebuild Notes | incorporate | Applied; generated `MidiPlayer.cpp` now places UID0002B1 before UID0002B2 and helper bodies. |
| C-0002B1-07 | `0x0069b528-0x0069b5cf` is two 84-byte `MIDIHDR`/stream-write overlay slots. | High | Open/callback/release decompiles, refs to `pmh`, loop stride `84`, buffer length `1024`. | Target Covered Data / C++ block | incorporate | Applied in target covered data and `MidiStreamHeaderSlot`/`g_midiHeaders[2]` declarations; validator `000000007357` ok. |
| C-0002B1-08 | `0x0069b5d0-0x0069b60f` is `g_midiChannelVolume[16]`, runtime-filled with default dword `100`. | High | `sub_525920` copies four xmmwords from `0x0061fb60`; callback/volume helpers consume 16 channels. | Target Covered Data / C++ block | incorporate | Applied in target covered data and formal C++; validator `000000007357` ok. |
| C-0002B1-09 | `0x0069b618-0x0069b81f` is a 260-wide-character `g_midiCurrentPath` buffer. | High | `wcscpy_s(&0x0069b618, 0x104, path)` in `0x00526240`; IDA name `Destination`; support docs use `g_midiCurrentPath`. | Target Covered Data / C++ block | incorporate | Applied in target covered data/formal C++; by-file/by-class support synchronized; validators `000000007353`, `000000007354`, `000000007357` ok. |
| C-0002B1-10 | `0x0069b820` is `g_hMidiBufferEvent`; `0x0069b824-0x0069b827` is unreferenced alignment before document state. | High | Event xrefs and CreateEvent/SetEvent/Wait/CloseHandle decompiles; `xrefs_to 0x0069b824` zero. | Target Range / Split / Padding | incorporate | Applied; formal block uses aligned `g_midiDocumentState` and no fake padding field. |
| C-0002B1-11 | `0x0069b828-0x0069b86b` is a 68-byte `MidiDocument` object with embedded DATFile-like subobject at `+0x18`; `0x0069b86c` is end-of-stream marker. | High | `sub_527080`, `sub_5270E0`, `sub_5273A0`, `sub_60C300`, callback write to `0x0069b86c`. | Target Covered Data / C++ block | incorporate | Applied in target covered data/formal C++; validator `000000007357` ok. |
| C-0002B1-12 | UID0002B2 has a clean successor range and should not be merged into UID0002B1. | High | UID0002B2 direct refs confined to `sub_5271B0`; `0x0069b86c` is last UID0002B1 ref; successor refs start at `0x0069b870`. | Target Range / Negative Evidence | reject merge | Applied as rejected merge in target and preserved on UID0002B2; validators `000000007352`, `000000007357` ok. |
| C-0002B1-13 | UID0002B2 static `0xFFFFFFFF` formal initializers are stale if describing current image bytes. | High | Current `get_bytes/get_int` at `0x0069b870-0x0069b88c` zero; `sub_5271B0` writes runtime scratch values. | Support UID0002B2 Boundary/Initialization / Formal C++ | incorporate correction | Applied to UID0002B2 formal block and support text; validator `000000007352` ok; generated has zero static declarations. |
| C-0002B1-14 | The target should emit first-draft C++ declarations rather than remain an empty/no-code marker. | High | Owner, source route, field shape, zero initializer, and generated declaration gap are resolved. | Target formal `RECONSTRUCTION_CPP CODE` | incorporate | Applied; generated `MidiPlayer.cpp` contains UID0002B1 declarations at top; validator `000000007357` ok. |
| C-0002B1-15 | Direct class-field ownership by `MidiPlayer` is wrong. | High | Process-wide absolute globals and free callbacks/helpers; `MidiPlayer` object is compact 12-byte controller. | Target Rejected Alternatives | reject | Applied to target and by-class support; validators `000000007354`, `000000007357` ok. |
| C-0002B1-16 | SoundManager/RAD audio ownership is wrong. | High | WinMM imports and MidiPlayer support docs; no SoundManager call route for these globals. | Target Rejected Alternatives | reject | Applied to target rejected alternatives; no support owner route changed. |
| C-0002B1-17 | A new `MidiSMFDocument.cpp`/parser file is not currently justified. | Medium-high | No recovered file route; by-file `MidiPlayer` owns the helper family; docs treat parser helpers as private `MidiPlayer.cpp` support. | Source Placement / Open Questions | reject for now | Applied/preserved in target, by-file, and UID0002B2 support; validators ok. |
| C-0002B1-18 | Hand-authored fake padding global at `0x0069b824` should not be introduced. | Medium-high | No refs/name; source-shaped alignment before `MidiDocument` is cleaner. | Target Range / C++ caveat | reject | Applied; no fake padding symbol introduced; alignment caveat preserved. |
| C-0002B1-19 | Generated `MidiPlayer.cpp` currently has UID0002B1 as an empty marker despite coverage saying it emits. | High | Read-only generated file line near UID0002B1 marker; coverage row says emits to `MidiPlayer.cpp`. | Target Generated-output note | incorporate | Pre-implementation caveat preserved; post-validation generated output now contains UID0002B1 declarations. |
| C-0002B1-20 | Manual coverage/tracker edits are not needed and must not be supplied for B-agent application. | High | Validator-owned generated reports; report-only assignment prohibits edits. | Checklist / Changed Files | exclude | Excluded manually; validator-owned generated/coverage/tracker refresh occurred only through scoped validator `000000007357`. |
| C-0002B1-21 | Third-party import is not applicable. | High | This is NexusTK-owned WinMM MIDI state, not library source. | Checklist / First-Draft C++ | exclude | Excluded; no import directive added. |

## Positive Evidence Summary

- Current MCP confirms live zero-filled storage across UID0002B1 and the adjacent scratch range.
- Current xrefs tightly bind the range to MidiPlayer WinMM stream open, callback, reset, lifecycle, path selection, document parse/release, and stream-fill helpers.
- Current decompilation resolves the field layout at source-quality level: stream handle, device id, state flags, two `MIDIHDR` overlay slots, channel volume table, path buffer, event handle, document object, and end marker.
- The by-global owner already has a `[[CHILDREN]]` route and explicitly delegates exact data declarations to UID0002B1/UID0002B2.
- Generated output demonstrates the practical declaration gap: many helper bodies reference these globals but UID0002B1 contributes no declarations.

## Negative Evidence Summary

- Reject stale static `0xffffffff` / `0xff` initializer claims for UID0002B1 and UID0002B2. Runtime sentinel writes remain valid evidence but are not static initializers.
- Reject direct `MidiPlayer` class-field ownership; the storage is absolute process-wide state and outlives individual helper calls.
- Reject SoundManager/Miles ownership; this is WinMM MIDI code under `MidiPlayer.cpp`.
- Reject merging UID0002B1 with UID0002B2; direct refs split cleanly at `0x0069b870`.
- Reject inventing a source-owned named padding field at `0x0069b824`; document it as alignment.
- Reject fallback-only conclusions; this report is based on live MCP.
- Reject manual edits to generated output, coverage reports, tracker rows, lifecycle state, or validator queues.

## First-Draft C++ Recommendation

Populate UID0002B1's formal block and set `EMITTER_POSITION_OPTIONAL:0`. The block below intentionally does not duplicate UID0002B2's `MidiEvent` / `MidiFillResult` declarations; UID0002B2 should be support-repaired separately to remove stale `0xFFFFFFFF` static initializers while keeping its scratch declarations.

```cpp
static const unsigned int MIDI_RESET_SKIP_REOPEN = 0x00010000;
static const unsigned int MIDI_TRACK_PATH_CHARS = 260;
static const unsigned short MIDI_TRACK_NONE = (unsigned short)-1;
static const unsigned int MIDI_STREAM_BUFFER_BYTES = 0x400;

static const DWORD MIDI_STREAM_STATE_STOPPING = 100;
static const DWORD MIDI_STREAM_STATE_IDLE = 200;
static const DWORD MIDI_STREAM_STATE_FLUSHING = 300;

static const DWORD MIDI_TRACK_DONE = 0x00000001;
static const DWORD MIDI_TAG_MTHD = 0x6468544D;
static const DWORD MIDI_TAG_MTRK = 0x6B72544D;

static const BYTE MIDI_STATUS_CONTROL_CHANGE = 0xB0;
static const BYTE MIDI_STATUS_PROGRAM_CHANGE = 0xC0;
static const BYTE MIDI_STATUS_CHANNEL_PRESSURE = 0xD0;
static const BYTE MIDI_STATUS_SYSEX = 0xF0;
static const BYTE MIDI_STATUS_ESCAPE = 0xF7;
static const BYTE MIDI_STATUS_META = 0xFF;
static const BYTE MIDI_CONTROLLER_VOLUME = 7;
static const BYTE MIDI_META_END_OF_TRACK = 0x2F;
static const BYTE MIDI_META_TEMPO = 0x51;

struct MidiTrackState {
    DWORD flags;
    DWORD trackLength;
    DWORD bufferedBytes;
    BYTE* buffer;
    BYTE* cursor;
    DWORD pendingTick;
    BYTE runningStatus;
    BYTE reservedStatus[3];
    DWORD trackStartOffset;
    DWORD sourceOffset;
    DWORD bytesRemaining;
};

struct MidiStreamWriteContext {
    LPSTR buffer;
    DWORD bufferLength;
    DWORD bytesRecorded;
    DWORD_PTR user;
    DWORD flags;
    MIDIHDR* next;
    DWORD_PTR reserved;
    DWORD offset;
    DWORD reservedWords[8];
    DWORD writeOffset;
    DWORD writeLimit;
    DWORD bytesWritten;
    DWORD lastEventTick;
    DWORD fullEventPending;
};

struct MidiStreamHeaderSlot {
    MIDIHDR header;
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
    DWORD currentTick;
    DWORD allocatedPayloadCount;
    DWORD tempoTickCache;
    DWORD tempoScalePercent;
    DWORD tempoUSecPerQuarter;
};

static HMIDISTRM g_hMidiStream;
static UINT g_midiDeviceId;
static DWORD g_midiStreamState;
static DWORD g_midiRestartPending;
static BOOL g_midiAllowEndReplay;
static BOOL g_midiDocumentLoaded;
static BOOL g_midiStreamRunning;
static BOOL g_midiCallbackStreamOpen;
static BOOL g_midiHeadersPrepared;
static DWORD g_midiVolumeScale;
static MidiStreamHeaderSlot g_midiHeaders[2];
static DWORD g_midiChannelVolume[16];
static DWORD g_midiActiveHeaderIndex;
static DWORD g_midiPendingBufferCount;
static wchar_t g_midiCurrentPath[MIDI_TRACK_PATH_CHARS];
static HANDLE g_hMidiBufferEvent;
__declspec(align(8)) static MidiDocument g_midiDocumentState;
static DWORD g_midiEndOfStreamReached;
```

Implementation caveats:

- The `DATFile` member is a dependency on the archive source family; this page should not define DATFile methods.
- If support implementation moves the constants into another earlier shared declaration block, do not duplicate them in UID0002B1. The current generated order needs these constants before helper bodies.
- `tempoScalePercent` is source-facing/descriptive. Current decompile proves constructor value `100` at document offset `+0x3c`; final original name remains open.
- The `__declspec(align(8))` marker is a source-shaped way to account for the unreferenced `0x0069b824-0x0069b827` gap. If the project has a preferred alignment idiom, use that instead of a fake padding global.

## Final Recommendation

Accept this report for an implementation callback. Apply target updates first; include the support initializer repairs only if the supervisor callback allows support-doc edits. A target-only callback can improve UID0002B1, but generated `MidiPlayer.cpp` will remain partially inconsistent if UID0002B2 continues to emit stale `0xFFFFFFFF` static initializers or if late helper pages duplicate constants now moved to the UID0002B1 declaration block.

## Recommended Target Doc Changes

For `by-memory/0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals.md`:

- Change `COMPLETION:85` to `COMPLETION:89`.
- Change `CONFIDENCE:90` to `CONFIDENCE:92`.
- Keep `CANONICAL_OWNER:0000T9`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000T9`.
- Change blank `EMITTER_POSITION_OPTIONAL:` to `EMITTER_POSITION_OPTIONAL:0`.
- Populate the formal `RECONSTRUCTION_CPP CODE` block with the first-draft declaration block above, or with the same declarations minus constants if a support shared-declaration page supplies the constants earlier.
- Replace the stale active evidence line claiming `0xff` initialized bytes with current MCP session `supervisor_recovery_20260705` zero-byte evidence.
- Add field/range table details for the two `MIDIHDR` slots, channel-volume table, current path buffer, event handle, `0x0069b824` alignment gap, `MidiDocument` object, and end marker.
- Preserve old `0xffffffff` notes as rejected historical evidence, explicitly separating static image bytes from runtime constructor/fill sentinel writes.
- Add generated-output caveat: current generated `MidiPlayer.cpp` command `000000007322` contains only an empty UID0002B1 marker although later helper code references the declarations.

## Recommended Support Doc Changes

Support docs are triggered because current evidence contradicts existing support initializer text and because the target first-draft block affects generated ordering.

- `by-global/MidiPlayerWinMMState.md`: update reconstruction caveats to cite current session `supervisor_recovery_20260705`; replace active `0xffffffff` initializer assumptions with zero-initialized static storage plus runtime sentinel/default writes; keep child-declaration routing through UID0002B1/UID0002B2.
- `by-memory/0x0069b870-0x0069b890.MidiSMFParserScratchGlobals.md`: revise Item Summary, Boundary/Initialization, Score Rationale, and formal C++ initializers. Current static bytes are zero. Runtime `sub_5271B0` clears most scratch to zero and writes `g_midiSelectedTick = 0xFFFFFFFF` during scans. The formal declarations should therefore be zero-initialized declarations, not explicit `0xFFFFFFFF` static initializers. Keep the same owner/emitter unless supervisor directs otherwise.
- `by-memory/0x00525920-0x00525b0d.MidiStreamOpenAndPrimeBuffers.md`: after UID0002B1 declarations are applied, update the no-code blocker text from unresolved shared declarations to dependency now supplied; do not invent a body unless separately callbacked.
- `by-memory/0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers.md` and related helper pages: if UID0002B1 supplies shared constants at position 0, remove or avoid duplicate late definitions such as `MIDI_RESET_SKIP_REOPEN`, `MIDI_TRACK_PATH_CHARS`, and `MIDI_TRACK_NONE` from helper-local formal blocks.
- `by-file/MidiPlayer.md` and `by-class/MidiPlayer.md`: no required owner/source-placement change; optional stale-open-question cleanup can say the UID0002B1 declaration shape is resolved but original symbol spellings remain descriptive.

Do not edit generated `auto-generated/NexusTK/audio/MidiPlayer.cpp`; let scoped validation refresh it after by-* implementation.

## Score And Metadata Recommendation

| Field | Current | Recommended | Rationale |
| --- | ---: | ---: | --- |
| Completion | 85 | 89 | Current MCP resolves the initializer conflict, field shape, range/padding, source placement, declaration route, generated empty-marker cause, and implementation-ready formal declaration block. Cap remains because original symbol spellings and some shared type final names are descriptive. |
| Confidence | 90 | 92 | Live MCP zero-byte/xref/decompile evidence is strong and internally consistent. Cap remains for original names, final `MidiDocument` field names such as `tempoScalePercent`, and generated-order support synchronization. |
| Canonical owner | `0000T9` | `0000T9` | Best owner remains `MidiPlayerWinMMState`; direct file owner is source route, not canonical data-group owner. |
| Reconstructable | `TRUE` | `TRUE` | Source-declared global/static state required by emitted helper bodies. |
| Emitter UIDs | `0000T9` | `0000T9` | By-global owner routes children into `MidiPlayer.cpp`. |
| Emitter position | blank | `0` | Declarations must appear before helper bodies; current generated output proves the blank position leaves an empty late marker. |

## Open Questions With Attempted Resolution

| Question | Resolution | Score/C++ impact |
| --- | --- | --- |
| Are static initializers zero, `0xffffffff`, or mixed? | Resolved for current image bytes: zero for UID0002B1 and sampled UID0002B2. Runtime writes create `-1`, `500`, `100`, and selected-tick sentinels later. | Removes the main declaration blocker. |
| Is `0x0069b824-0x0069b827` a missing field? | Current `xrefs_to` found no direct refs and no name. Treat as alignment before `MidiDocument`, not a fake field. | Keep confidence cap; use alignment if formal block needs layout cue. |
| Does UID0002B1 own UID0002B2 scratch? | No. UID0002B2 starts at `0x0069b870`; direct refs are stream-fill scratch only. | No merge; support correction only. |
| Are final source names recovered? | No. Names are descriptive but consistent with accepted helper pages and generated source. | Confidence cap below final audit. |
| Is a separate SMF document/parser file justified? | Not currently. No recovered filename or stronger source route than `MidiPlayer.cpp`. | Keep source placement in `MidiPlayer.cpp`; record as future source-split question only. |
| Can helper bodies now receive C++? | UID0002B1 declaration blocker is resolved, but this report should not implement helper bodies. Existing helper pages may need support updates and validators after the declaration repair. | Target C++ yes; helper body updates require separate callback scope. |
| Is generated output currently fresh and correct? | Post-validation generated `auto-generated/NexusTK/audio/MidiPlayer.cpp` contains UID0002B1 declarations and UID0002B2 zero static declarations. File header records command `000000007356`, refreshed `2026-07-05T19:31:55-04:00`; final target validator `000000007357` reported `generated_refresh: completed` at `2026-07-05T19:32:05-04:00`. | Resolved for UID0002B1/UID0002B2 content; remaining generated header-vs-final-command detail is recorded as freshness metadata, not a blocker. |

## Validator Results

Report-only phase: not run.

Implementation callback validators from `source-3/project-documentation`:

| File | Command ID | Timestamp | Exit | ok count | Generated state |
| --- | --- | --- | ---: | ---: | --- |
| `by-global/MidiPlayerWinMMState.md` | `000000007351` | `2026-07-05T19:31:40-04:00` | 0 | 1 | deferred |
| `by-memory/0x0069b870-0x0069b890.MidiSMFParserScratchGlobals.md` | `000000007352` | `2026-07-05T19:31:42-04:00` | 0 | 1 | deferred |
| `by-file/MidiPlayer.md` | `000000007353` | `2026-07-05T19:31:44-04:00` | 0 | 1 | deferred |
| `by-class/MidiPlayer.md` | `000000007354` | `2026-07-05T19:31:46-04:00` | 0 | 1 | deferred; generated header later observed older than final command |
| `by-memory/0x00525920-0x00525b0d.MidiStreamOpenAndPrimeBuffers.md` | `000000007355` | `2026-07-05T19:31:53-04:00` | 0 | 1 | deferred |
| `by-memory/0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers.md` | `000000007356` | `2026-07-05T19:31:55-04:00` | 0 | 1 | deferred; inspected `MidiPlayer.cpp` header records this command |
| `by-memory/0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals.md` | `000000007357` | `2026-07-05T19:32:05-04:00` | 0 | 1 | `--wait-generated`; reported `generated_refresh: completed` |

Non-blocking validator notes: command `000000007354` reported `missing_ref_uid 0003PF by-class/MidiPlayer.md UID reference is not present in validator.ini`; the command still exited `0` with `ok: 1`. Command `000000007357` reported broad existing generated `autogen_children_*` and `autogen_emitter_has_no_code` notices while exiting `0` with `ok: 1`.

Generated freshness inspection:

- `auto-generated/NexusTK/audio/MidiPlayer.cpp` now contains UID0002B1 at the top with `Completion:89 | Confidence:92` and the formal declarations.
- UID0002B2 immediately follows with zero static declarations: `g_midiTrackScanCursor`, `g_midiSelectedTrack`, `g_midiFillState`, `g_midiSelectedTick`, and `g_midiPendingEvent` have no explicit `0xFFFFFFFF` static initializers.
- Remaining `0xFFFFFFFF` occurrences in `MidiPlayer.cpp` are runtime/source logic, including source-position sentinel and `g_midiSelectedTick` scan initialization, not static storage initializers.
- Workspace and validator canonical-root generated files have matching SHA256 `7AEB5B281919649CF2CAACE5660533C22060D1BF509B65CACEE3085FFFBD7900`.

## Changed Files

Report-only phase created this report file:

- `tools/leaser/Agents/Agent-B009/research/0002B1-MidiPlayerWinMMStateGlobals-source-quality.md`

Implementation callback edited these by-* docs:

- `by-memory/0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals.md`
- `by-global/MidiPlayerWinMMState.md`
- `by-memory/0x0069b870-0x0069b890.MidiSMFParserScratchGlobals.md`
- `by-file/MidiPlayer.md`
- `by-class/MidiPlayer.md`
- `by-memory/0x00525920-0x00525b0d.MidiStreamOpenAndPrimeBuffers.md`
- `by-memory/0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers.md`

Validator-owned generated output/report refresh occurred through scoped validator commands only, including `auto-generated/NexusTK/audio/MidiPlayer.cpp` and validator-owned coverage/tracker metadata. No generated file, coverage report, validator state, lifecycle/archive file, supervisor ledger, or report registry file was manually edited.

## Implementation Tracking Checklist

| Item | Required implementation state | Current report-only state | Verification plan |
| --- | --- | --- | --- |
| Supervisor validation before implementation | Gate 1 must pass before by-* edits. | Applied: Gate 1 passed at SHA `BE600933C6024AEDF787BE5D262E99E394585B6BFAD54E81BC533962670F073F`. | Supervisor Gate 1 accepted before edits. |
| Target doc to update | UID0002B1 target is required for the core repair. | Applied to target. | Validator `000000007357` exit `0`, ok `1`. |
| Support docs to update | by-global initializer caveat, UID0002B2 stale static initializer, helper constant duplication, and MidiPlayer support cleanup are triggered. | Applied to by-global, UID0002B2, by-file, by-class, UID0001CE, and UID0001CH. | Validators `000000007351` through `000000007356` exit `0`. |
| Claim-ledger updates | Every accepted/rejected material claim must be applied, already present, excluded, or blocked. | Applied in this report update. | Ledger states updated above. |
| Metadata/score | Target to `89/92`; owner/emitter unchanged; position `0`. | Applied. | Target header verified; validator `000000007357` recorded completion/confidence updates. |
| Owner/emitter/reconstructable fields | Keep `CANONICAL_OWNER:0000T9`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000T9`; set position `0`. | Applied. | Generated `MidiPlayer.cpp` contains UID0002B1 under by-global route before helper bodies. |
| Split/range/source-placement/IDA decisions | Preserve `0x0069b500-0x0069b870`; no merge with UID0002B2; source route `MidiPlayer.cpp`; `0x0069b824` alignment. | Applied. | Target/support wording preserved; generated route inspected. |
| First-draft C++ marker/no-code proof | Target should receive formal C++ declarations; no-code marker rejected for target. | Applied. | UID0002B1 generated declarations present; UID0001CE remains blank by scope, not by shared-declaration blocker. |
| Third-party import | Not applicable. | Excluded. | No import directive added. |
| Historical/rejected evidence preservation | Preserve old `0xffffffff` as stale historical evidence, not current truth. | Applied. | Target/UID0002B2/by-global/by-file/by-class preserve stale-history wording and current zero-storage correction. |
| Open questions | Static initializer resolved; remaining questions are original spellings, possible future parser-file split, and generated freshness metadata. | Applied as evidence-backed caps. | Generated content fresh for UID0002B1/UID0002B2; header/final-command detail recorded. |
| Validators | Run scoped file validators after by-* edits. | Applied. | Commands `000000007351`-`000000007357`, all exit `0`, ok `1`; target used `--wait-generated`. |
| Generated-output check | Inspect generated `auto-generated/NexusTK/audio/MidiPlayer.cpp` for UID0002B1 declarations and UID0002B2 initializer consistency. | Applied. | UID0002B1 present; UID0002B2 zero static declarations; remaining `0xFFFFFFFF` hits are runtime logic. |
| No manual coverage/tracker text | Do not hand-edit generated coverage/tracker. | Compliant. | Validator-owned refresh only; no manual edits. |
| Leases | Lease only files to edit during callback and release after validation. | Applied. | Seven by-* leases granted/refreshed and released; report lease granted and released for this update. |

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000007364","destination_path":"executed-b-agent-research/B009/0002B1-MidiPlayerWinMMStateGlobals-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/0002B1-MidiPlayerWinMMStateGlobals-source-quality.md","timestamp":"2026-07-05T19:44:10-04:00","uid":"0002B1"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
