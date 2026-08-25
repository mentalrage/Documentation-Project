** TARGET-REPORT-UID:0001KA **
** AUTHOR-AGENT-ID:B015 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001KA TimerMgrQueueHelpers Source-Quality Reanalysis

Agent: Agent-B015  
Assignment: `B015-goal2-timermgr-queue-helpers-source-quality-0001KA-20260619`  
Target: [UID:0001KA][0x00597dc0-0x005986da.TimerMgrQueueHelpers](../../../by-memory/0x00597dc0-0x005986da.TimerMgrQueueHelpers.md)  
Report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B015\research\0001KA-TimerMgrQueueHelpers-source-quality.md`  
Mode: report-only. No by-* documentation and no `by-memory/-coverage-report.md` were edited by this pass.

## Finalized Report / Current Recommendation

- Current recommendation: reclassify [UID:0001KA] as a reviewed non-emitting mixed helper/context page after the child metadata is normalized. The exact source-bearing work belongs to child function pages, not to the aggregate.
- Final disposition: `0001KA` should remain nested under [UID:0001K6][TimerMgrAndTimerQueue] for memory/context, but it should not be an output route or a C++ body owner. Recommended target metadata is `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0001K6`, `RECONSTRUCTABLE:FALSE`, `EMITTER_UIDS:` blank.
- Required action: incorporate the raw-range evidence, child owner/source-placement decisions, helper/type names, rejected alternatives, open-question closure, and child first-draft C++ routing plan into the target/support docs. Do not place monolithic C++ into `0001KA`.
- Confidence: high for range, child coverage, reachability, owner split, queue record layout, source module, and no-code aggregate disposition; medium-high for original source spellings because stripped binary evidence cannot prove exact names.

## Target

- Target UID: `0001KA`
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00597dc0-0x005986da.TimerMgrQueueHelpers.md`
- Current metadata: `COMPLETION:85`, `CONFIDENCE:87`, `CANONICAL_OWNER:0001K6`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0001K6`, blank C++.
- Current generated output: `auto-generated/NexusTK/util/TimerMgr.cpp` contains only an empty emitter marker for `0001KA` and empty markers for every exact child in this tail range.
- Current coverage row: stale at `82%`, still says final-name/C++ blockers and uses older parent-gate wording.
- Source root supported by current docs and proposed source tree: [UID:0000OT][TimerMgr](../../../by-file/TimerMgr.md), `NexusTK/util/TimerMgr.cpp`.
- Direct semantic sub-owners:
  - [UID:0000F1][TimerMgr](../../../by-class/TimerMgr.md) for `FindQueuedTimerDueTick`, `BeginTimerPeriod`, `RefreshCurrentTick`, and the `TimerMgr` deleting-destructor wrapper.
  - [UID:0000F2][TimerMgrTimerQueue](../../../by-class/TimerMgrTimerQueue.md) for the queue iterator/template helpers, destructor, grow, erase/splice, and insert operations.
  - [UID:0000OT][TimerMgr](../../../by-file/TimerMgr.md) for the constructor-unwind singleton-clear thunk, but that thunk is compiler-generated cleanup rather than handwritten source.

## Evidence Checked

Read directly for this report:

- Governing rules: `Supervisor.md`, `.codex/AGENTS.md`, Agent-B015 `goal.md`, Agent-B015 `notes.md`, `by-structure.md`, `inference_research.md`, and `by-project-structure/proposed-source-tree.md`.
- Target and parent docs: [UID:0001KA], [UID:0001K6][0x00597570-0x005986da.TimerMgrAndTimerQueue](../../../by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md), [UID:0000OT][TimerMgr](../../../by-file/TimerMgr.md), [UID:0000F0][TimerHandler](../../../by-class/TimerHandler.md), [UID:0000F1][TimerMgr](../../../by-class/TimerMgr.md), and [UID:0000F2][TimerMgrTimerQueue](../../../by-class/TimerMgrTimerQueue.md).
- Exact executable children: [UID:0002KX] through [UID:0002L7].
- Data/type/global support: [UID:0001WD][TimerMgrLayout](../../../by-type/by-struct/TimerMgrLayout.md), [UID:0001VX][ScheduledTimerEvent](../../../by-type/by-struct/ScheduledTimerEvent.md), [UID:0000SI][g_pTimerMgr](../../../by-global/g_pTimerMgr.md), [UID:0002VW][0x0067ab80-0x0067ab84.g_pTimerMgr](../../../by-memory/0x0067ab80-0x0067ab84.g_pTimerMgr.md), [UID:00029S][0x0069b3ac-0x0069b3d0.TimerMgrStaticObjectStorage](../../../by-memory/0x0069b3ac-0x0069b3d0.TimerMgrStaticObjectStorage.md), [UID:000306][0x0069be0c-0x0069be10.TimerMgrTickBaselineMirror](../../../by-memory/0x0069be0c-0x0069be10.TimerMgrTickBaselineMirror.md), [UID:000307][0x0069be10-0x0069be14.TimerMgrCurrentTickMirror](../../../by-memory/0x0069be10-0x0069be14.TimerMgrCurrentTickMirror.md), and [UID:0003E1][0x0062e344-0x0062e354.TimerMgrVtableData](../../../by-memory/0x0062e344-0x0062e354.TimerMgrVtableData.md).
- Prior B-agent context: Agent-B014 `0001K6-TimerMgrAndTimerQueue-source-quality.md`, plus older TimerMgr tick/global reports surfaced by search. Existing reports were treated as leads and rechecked against current docs and raw bytes where possible.
- Generated reports/output: `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-class-coverage.md`, `auto-generated/-ag-file-coverage.md`, `auto-generated/NexusTK/util/TimerMgr.cpp`, `project-level/-auto-completion-stats.md`, and current `by-memory/-coverage-report.md`.
- Raw binary: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, size `2679296`, SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`. The same-sized read-only copy exists at `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.

IDA MCP was not available as a direct tool in this session. The direct binary recheck used PE section parsing and Capstone disassembly locally. Existing by-* docs include IDA-backed caller/callee/decompiler evidence; this report distinguishes those existing IDA facts from the fresh raw-PE facts below.

## Exact Range, Padding, And Raw PE Recheck

The target range is exactly the half-open executable coverage range `0x00597dc0-0x005986da`.

Raw PE facts from `NexusTK.exe`:

- Target raw offset: `0x1971c0`.
- Target raw end: `0x197ada`.
- Target length: `0x91a`.
- Target bytes SHA-256: `2e73c513c14f8328a811838ba8cb1a0754dada5697dd6311a2c5c6e808f3d0fa`.
- Predecessor padding `0x00597db9-0x00597dc0`: seven bytes, all `cc`.
- Successor padding `0x005986da-0x005986e0`: six bytes, all `cc`.
- Successor [UID:0001KB][TimerPane] starts at `0x005986e0`; `TimerPane` is a map/UI timer overlay and not part of the scheduler implementation.

Child boundary table:

| UID | Display range | Exact body / padding result | Raw facts |
| --- | --- | --- | --- |
| `0002KX` | `0x00597dc0-0x00597e3f` | exact half-open body `0x00597dc0-0x00597e3f`; padding `0x00597e3f-0x00597e40` one `cc` | length `0x7f`, 61 instructions, no callees, `ret 8` paths at `0x00597e31` and `0x00597e3c` |
| `0002KY` | `0x00597e40-0x00597e8a` | exact half-open body; padding `0x00597e8a-0x00597e90` six `cc` | length `0x4a`, imports `timeGetDevCaps`, `timeBeginPeriod`, `timeGetTime`, writes `0x0069be10` and `0x0069be0c` |
| `0002KZ` | `0x00597e90-0x00597ea3` | exact half-open body; padding `0x00597ea3-0x00597eb0` thirteen `cc` | length `0x13`, imports `timeGetTime`, writes `TimerMgr+0x18` and `0x0069be10` |
| `0002L0` | `0x00597eb0-0x00597f17` | exact half-open body; padding `0x00597f17-0x00597f20` nine `cc` | length `0x67`, 47 instructions, no callees, four stack-argument iterator/helper ABI |
| `0002L1` | `0x00597f20-0x00597fc9` | exact half-open body; padding `0x00597fc9-0x00597fd0` seven `cc` | length `0xa9`, 74 instructions, three direct calls to `0002L0`, hidden-output iterator-like return |
| `0002L2` | `0x00597fd0-0x00597fdb` | exact half-open body; padding `0x00597fdb-0x00597fe0` five `cc` | bytes `c7 05 80 ab 67 00 00 00 00 00 c3`; writes `g_pTimerMgr = 0`; one rel32 call from constructor-unwind support |
| `0002L3` | `0x00597fe0-0x00598083` | exact half-open body; padding `0x00598083-0x00598090` thirteen `cc` | length `0xa3`, 57 instructions, calls free/invalid-parameter helpers, cleans queue fields |
| `0002L4` | `0x00598090-0x005980eb` | exact half-open body; padding `0x005980eb-0x005980f0` five `cc` | length `0x5b`, vtable slot dword reference from `0x0062e344`, calls `timeEndPeriod`, `0002L3`, base cleanup, delete helper, guard support |
| `0002L5` | filename/title `0x005980f0-0x00598281` | executable body includes final byte `0x00598281`; true half-open body is `0x005980f0-0x00598282`; padding is `0x00598282-0x00598290` fourteen `cc` | the `0x00598281` byte is the final `00` immediate byte of `call 0x005cd607`, so implementation text should call this a final-byte display convention |
| `0002L6` | filename/title `0x00598290-0x00598471` | executable body includes final byte `0x00598471`; true half-open body is `0x00598290-0x00598472`; padding is `0x00598472-0x00598480` fourteen `cc` | the `0x00598471` byte is the final `00` immediate byte of `ret 0x1c`; current child row display should be clarified |
| `0002L7` | filename/title `0x00598480-0x005986d9` | true half-open body is `0x00598480-0x005986da`; successor padding starts at `0x005986da` | length `0x25a`, 223 decoded instructions in raw pass, `ret 0x14` at `0x005986d7` |

The target doc should explicitly record the final-byte-display convention for [UID:0002L5], [UID:0002L6], and [UID:0002L7]. The aggregate should still use the half-open end `0x005986da`.

## Direct Xref / Caller / Callee Inventory

Fresh raw rel32 scan of `.text` confirms the current reachability model:

| Target | Direct rel32 sites found | Meaning |
| --- | --- | --- |
| `0x00597dc0` [UID:0002KX] | `0x0050ebf1` | one direct query caller in a higher-level timer/audio-style owner path; existing doc states this caller checks event id `2` and adjusts scheduling policy |
| `0x00597e40` [UID:0002KY] | `0x004a6c5e` | application-loop/timer startup calls multimedia timer-period setup |
| `0x00597e90` [UID:0002KZ] | `0x004a6c86`, `0x004f63c0` | application/tick refresh callers update current timer tick |
| `0x00597eb0` [UID:0002L0] | `0x00597f75`, `0x00597f82`, `0x00597f8e` | only called by rotate helper |
| `0x00597f20` [UID:0002L1] | `0x00598693` | only called by queue insert helper |
| `0x00597fd0` [UID:0002L2] | `0x00609b5e` | only constructor-unwind/EH cleanup call found; no normal source caller |
| `0x00597fe0` [UID:0002L3] | `0x00597795`, `0x005980a8` | static/non-deleting TimerMgr destructor path and scalar deleting destructor wrapper destroy embedded queue |
| `0x00598090` [UID:0002L4] | no direct rel32 call sites | reached through TimerMgr vtable data; dword pattern `0x00598090` appears once at `0x0062e344` |
| `0x005980f0` [UID:0002L5] | `0x005984ac`, `0x005985a6` | only queue insert grows storage, both times for one additional queued event |
| `0x00598290` [UID:0002L6] | `0x0059789f`, `0x00597b05`, `0x00597c7f`, `0x00597d9f` | dispatch/removal helpers erase contiguous logical ranges |
| `0x00598480` [UID:0002L7] | `0x005979c5` | `TimerMgr::ScheduleTimer` inserts a sorted scheduled event |

Global/data xref facts from raw dword-pattern scan:

- `0x0067ab80` (`g_pTimerMgr`) appears as a dword pattern 125 times. Sampled `.text` references include `0x004a6c5a`, `0x004a6c65`, `0x004a6c82`, `0x004a6c8c`, `0x004f63bc`, wrapper calls, broad timer consumers, constructor publication, and destructor/clear paths. This confirms central scheduler singleton ownership rather than caller-local ownership.
- `0x0069be0c` appears at `0x004abad8`/`0x004abada` and `0x00597e80`/`0x00597e81`, matching the TimerMgr tick baseline mirror page.
- `0x0069be10` appears at `0x004abad3`/`0x004abad4`, `0x005977c4`/`0x005977c5`, `0x00597e7b`/`0x00597e7c`, and `0x00597e9c`/`0x00597e9d`, matching current tick mirror evidence.
- `0x00598090` appears exactly once as data at `0x0062e344`, the first slot in `TimerMgr` vtable data [UID:0003E1].

## Function / Child Inventory And Recommendations

| UID | Current route | Best source-facing role | Recommended route/disposition |
| --- | --- | --- | --- |
| `0002KX` `TimerMgrFindQueuedTimerDueTick` | current owner/emitter `0001KA` | private `TimerMgr` query method: `DWORD TimerMgr::FindQueuedTimerDueTick(TimerHandler *owner, int timerId) const` | change direct owner/emitter to [UID:0000F1][TimerMgr]; keep reconstructable; first-draft C++ eligible on child |
| `0002KY` `TimerMgrBeginTimerPeriod` | current owner/emitter `0001KA` | private `TimerMgr` multimedia timer-period setup method: `void TimerMgr::BeginTimerPeriod()` or `StartTimerPeriod()` | change direct owner/emitter to [UID:0000F1]; keep reconstructable; first-draft C++ eligible on child |
| `0002KZ` `TimerMgrRefreshCurrentTick` | current owner/emitter `0001KA` | private `TimerMgr` tick refresh method: `void TimerMgr::RefreshCurrentTick()` | change direct owner/emitter to [UID:0000F1]; keep reconstructable; first-draft C++ eligible on child |
| `0002L0` `TimerQueueReverseRange` | current owner/emitter `0000F2` | queue-iterator algorithm helper equivalent to reverse over `TimerMgrTimerQueue::Iterator` | keep [UID:0000F2]; document as static/template-style queue-local algorithm support, not an ordinary public method |
| `0002L1` `TimerQueueRotateRange` | current owner/emitter `0000F2` | queue-iterator rotate helper equivalent to three-reverse `std::rotate`-style algorithm | keep [UID:0000F2]; document as static/template-style queue-local algorithm support |
| `0002L2` `ClearGlobalTimerMgr` | current owner/emitter `0000OT`, reconstructable true | compiler-generated TimerMgr constructor-unwind singleton-clear thunk; source effect is constructor publication cleanup | recommend `RECONSTRUCTABLE:FALSE`, owner [UID:0000OT] for context, `EMITTER_UIDS:` blank; no formal C++ |
| `0002L3` `TimerMgrTimerQueueDestructor` | current owner/emitter `0000F2` | `TimerMgrTimerQueue::~TimerMgrTimerQueue()` | keep [UID:0000F2]; first-draft C++ eligible on child |
| `0002L4` `TimerMgrScalarDeletingDestructor` | current owner/emitter `0001KA` | compiler-generated scalar deleting destructor wrapper over `TimerMgr::~TimerMgr()` source semantics | change direct owner to [UID:0000F1]; document generated-wrapper nature; do not model as a handwritten helper. If kept as emitter, emit only destructor-source semantics or a marker, not a flag-wrapper body |
| `0002L5` `TimerMgrTimerQueueEnsureCapacity` | current owner/emitter `0001KA` | private queue grow/reserve method: `void TimerMgrTimerQueue::EnsureCapacityForInsert(unsigned int additionalCount)` | change direct owner/emitter to [UID:0000F2]; clarify true half-open end `0x00598282`; first-draft C++ eligible on child |
| `0002L6` `TimerMgrTimerQueueSpliceTimerRange` | current owner/emitter `0001KA` | private queue erase method returning iterator: `Iterator TimerMgrTimerQueue::EraseRange(Iterator first, Iterator last)` | change direct owner/emitter to [UID:0000F2]; prefer source-facing name `EraseRange` over `SpliceTimerRange`; clarify true half-open end `0x00598472`; first-draft C++ eligible on child |
| `0002L7` `TimerMgrTimerQueueInsertTimer` | current owner/emitter `0001KA` | private queue insert method returning iterator: `Iterator TimerMgrTimerQueue::InsertTimer(Iterator where, const ScheduledTimerEvent &event)` | change direct owner/emitter to [UID:0000F2]; first-draft C++ eligible on child |

## Best Source-Facing Names, Types, Fields, And Globals

### Source module and classes

- Source file: keep `NexusTK/util/TimerMgr.cpp` ([UID:0000OT]).
- `TimerMgr`: process-wide scheduler class ([UID:0000F1]).
- `TimerMgrTimerQueue`: embedded scheduled-event queue ([UID:0000F2]), not a generic reusable container. Its only proven use is the scheduler.
- `TimerHandler`: callback owner base ([UID:0000F0]); relevant because queued records store `TimerHandler *owner` and callback signature evidence is inherited from the broader TimerMgr family.
- `TimerPane`: separate map/UI timer overlay in `NexusTK/map/TimerPane.cpp`, not scheduler source.
- `WaitableTimer`: separate lower-level utility in `NexusTK/util/WaitableTimer.cpp`, not part of this exact queue helper tail.

### `TimerMgr` layout names

Use the [UID:0001WD][TimerMgrLayout] offsets, with source-facing names:

| Offset | Recommended name | Evidence |
| --- | --- | --- |
| `+0x00` | `LObject` / vtable base | constructor/destructor/vtable docs |
| `+0x04` | `m_timerQueue.m_root` or `m_queue.root` | static storage layout and queue destructor clear path |
| `+0x08` | `m_timerQueue.m_slots` / `ScheduledTimerEvent **slotEntries` | reverse/insert/grow use as pointer array |
| `+0x0c` | `m_timerQueue.m_capacity` / `slotCapacity` | capacity masks and grow logic |
| `+0x10` | `m_timerQueue.m_startIndex` | ring logical-start adjustment in insert/erase |
| `+0x14` | `m_timerQueue.m_count` | queue count in query/insert/erase/destructor |
| `+0x18` | `m_currentTick` | written by begin-period and refresh, mirrored to `0x0069be10` |
| `+0x1c` | `m_timerPeriod` or `m_timerResolution` | passed to `timeEndPeriod`, initialized by `timeBeginPeriod`; prefer `m_timerPeriod` for WinMM terminology |
| `+0x20` | `m_nextDueTick` | cached next due tick or empty sentinel `0xffffffff` from constructor/dispatch docs |

### `ScheduledTimerEvent` record names

Use the [UID:0001VX][ScheduledTimerEvent] 20-byte layout:

| Offset | Recommended name | Evidence |
| --- | --- | --- |
| `+0x00` | `owner` (`TimerHandler *`) | query compares owner; dispatch virtual-calls owner callback |
| `+0x04` | `timerId` in callback-facing text, `eventId` in low-level queue text if needed | schedule/cancel/query compare this field; wrapper docs call it event id |
| `+0x08` | `dueTick` | query returns this value; scheduler sorted insert compares due times |
| `+0x0c` | `arg0` | copied to callback payload; no caller-family semantic name is globally proven |
| `+0x10` | `arg1` | copied to callback payload; no caller-family semantic name is globally proven |

The best-supported callback signature remains:

```cpp
virtual bool OnTimer(int timerId, int arg0, int arg1);
```

That signature is supported by `ScheduledTimerEvent`, `TimerHandler` wrapper/callback docs, and derived callback pages. Do not use more specific names for `arg0`/`arg1` in the generic queue/type pages until a specific caller family proves them.

### Globals and generated labels

| Generated/current label | Best source-facing name | Disposition |
| --- | --- | --- |
| `dword_67AB80`, [UID:0000SI] | `g_pTimerMgr` | source-declared global pointer in `TimerMgr.cpp`; exact storage child `0002VW` |
| `dword_69BE0C`, [UID:000306] | `g_timerTickBaselineMirror` or `g_timerBaselineTick` | descriptive static/global tick mirror; exact original name unproven |
| `dword_69BE10`, [UID:000307] | `g_timerCurrentTickMirror` or `g_currentTimerTick` | descriptive static/global current tick mirror; exact original name unproven |
| `dword_69B3AC`, [UID:00029S] | static `TimerMgr` object storage | source-declared/generated-binary storage in `TimerMgr.cpp` |
| `??_7TimerMgr@@6B@`, [UID:0003E1] | `TimerMgr` vtable | source-declared/generated-binary, first slot points to `0002L4` |
| `sub_597FD0` style raw function | `TimerMgrConstructorUnwindClearSingleton` | compiler/EH cleanup thunk, not a handwritten helper |
| `sub_598090` style deleting destructor | `TimerMgrScalarDeletingDestructor` | compiler-generated wrapper around source destructor semantics |

## Heuristic / Inference Reanalysis And Validation

### 1. Aggregate disposition

Best inference: [UID:0001KA] is a mixed helper/context range and should not remain an emitting source item.

Evidence:

- The range contains at least three semantic categories: `TimerMgr` methods, `TimerMgrTimerQueue` helpers/methods, and compiler-generated cleanup/destructor wrapper artifacts.
- Exact child pages already exist for every executable function in the range.
- Several children have direct owners that are not `0001KA` (`0002L0`, `0002L1`, `0002L3`, `0002L2`) and several more should be normalized away from the aggregate (`0002KX`, `0002KY`, `0002KZ`, `0002L4`, `0002L5`, `0002L6`, `0002L7`).
- The aggregate itself has no source-level declaration, class, table, or source object that would be emitted as one C++ construct.
- `by-structure.md` says reviewed mixed-owner convenience pages whose exact children carry real source ownership should be `RECONSTRUCTABLE:FALSE` and should not have emitters.

Rejected alternative: keep `0001KA` as `RECONSTRUCTABLE:TRUE` with `EMITTER_UIDS:0001K6`. That route only produces an empty marker today and forces children through a memory-context page that is not a semantic source owner. The broader [UID:0001K6] can remain a source-family aggregate for the whole `TimerMgr.cpp` island, but this narrower tail page is not the source-family root.

### 2. `TimerMgr` query/tick helper names

Best inference:

- `0x00597dc0`: `TimerMgr::FindQueuedTimerDueTick(TimerHandler *owner, int timerId) const`.
- `0x00597e40`: `TimerMgr::BeginTimerPeriod()`; acceptable alternate `StartTimerPeriod()` if the class uses "start" terminology elsewhere.
- `0x00597e90`: `TimerMgr::RefreshCurrentTick()`.

Evidence:

- `0002KX` uses `this` as a `TimerMgr *`, reads embedded queue `count/start/capacity/slots`, compares `owner` and `timerId`, and returns a due tick or zero.
- `0002KY` calls WinMM `timeGetDevCaps`, `timeBeginPeriod`, and `timeGetTime`, stores the timer period at `this+0x1c`, stores current tick at `this+0x18`, and initializes both tick mirror globals.
- `0002KZ` only samples `timeGetTime`, writes `this+0x18`, and mirrors it to `0x0069be10`.
- Callers are scheduler/application loop paths, not queue class paths.

Rejected alternatives:

- Do not route these as queue methods. They use the outer `TimerMgr` object and scheduler globals.
- Do not call `0002KY` `InitializeCurrentTick` only; the `timeBeginPeriod` side effect is the key source responsibility.
- Do not call `0002KZ` `GetCurrentTick`; it mutates object/global tick state.

### 3. Queue reverse/rotate helper classification

Best inference: `0002L0` and `0002L1` are queue-local static/template-style iterator algorithm helpers, probably generated from source equivalent to reverse/rotate over a `TimerMgrTimerQueue::Iterator`, not ordinary public/private methods with `this` in `ecx`.

Evidence:

- `0002L0` does not use `ecx`; it takes four stack arguments corresponding to two iterator/control-plus-index pairs. It swaps 20-byte `ScheduledTimerEvent` records by dereferencing queue slot arrays.
- `0002L1` takes hidden output and iterator-like inputs, calls `0002L0` three times, and returns an iterator-like triple. This is exactly the standard three-reverse implementation shape used for rotate.
- Only `0002L1` calls `0002L0`, and only queue insertion calls `0002L1`. There is no public API caller surface.
- The helpers are queue-layout-specific because their inlined iterator operations dereference `slotEntries`, `slotCapacity`, and record slots.

Rejected alternatives:

- Reject generic reusable `VectorHelpers` or Dinkumware ownership. Although the algorithm shape resembles standard algorithms, the instantiated code is specialized to `TimerMgrTimerQueue` iterator state and copies `ScheduledTimerEvent`.
- Reject public `TimerMgrTimerQueue::ReverseRange`/`RotateRange` API names. No evidence shows external API use; they are implementation helpers for insert.
- Reject pure padding/runtime classification. They are live code with direct internal callers and source-rebuild relevance.

Recommended source-facing names:

- `ReverseTimerQueueRange(TimerQueueIterator first, TimerQueueIterator last)` or `TimerMgrTimerQueueReverseRange`.
- `RotateTimerQueueRange(TimerQueueIterator first, TimerQueueIterator middle, TimerQueueIterator last)` or `TimerMgrTimerQueueRotateRange`.

Keep the current child filenames if renaming is out of scope, but target/support docs should explain that the source-facing abstraction is an iterator range, not raw integer offsets.

### 4. `ClearGlobalTimerMgr` classification

Best inference: [UID:0002L2] is a compiler-generated constructor-unwind cleanup thunk for singleton publication, equivalent to `g_pTimerMgr = 0` if the static `TimerMgr` constructor fails after publishing the singleton. It should not be emitted as a handwritten function.

Evidence:

- Raw bytes are exactly `mov dword ptr [0x0067ab80], 0; ret`.
- Fresh rel32 scan found one call site at `0x00609b5e`, an EH/static cleanup area, and no normal direct source caller.
- The analogous ThreadMan cleanup child [UID:0001K4] is already modeled as a compiler cleanup thunk and ignored/non-reconstructable.
- Constructor/static storage docs show `TimerMgr` publishes `g_pTimerMgr` during construction, which gives the compiler a reason to emit an unwind cleanup.

Rejected alternatives:

- Reject source-authored file-local helper. There is no normal source caller surface and no evidence it was named or called by handwritten code.
- Reject attaching it to caller modules. It only writes the TimerMgr singleton.

### 5. `TimerMgrScalarDeletingDestructor` classification

Best inference: [UID:0002L4] is the compiler-generated scalar deleting destructor wrapper for `TimerMgr`, but it contains the visible source destructor semantics. It should be documented under [UID:0000F1][TimerMgr], not under the queue-helper aggregate.

Evidence:

- No direct rel32 callers were found; raw dword scan found one vtable slot reference at `0x0062e344`.
- The body writes/uses `TimerMgr` vtable state, calls `timeEndPeriod(this->m_timerPeriod)`, destroys the embedded queue via `0002L3`, clears `g_pTimerMgr`, runs base cleanup, and conditionally deletes the object based on the deleting-destructor flag.
- The same cleanup responsibilities appear in static destructor evidence for the static `TimerMgr` object.

Rejected alternatives:

- Reject source-facing name `TimerMgr::ScalarDeletingDestructor` as a handwritten method. That is a compiler ABI artifact.
- Reject queue ownership. Queue destructor is only one callee; the wrapper is a `TimerMgr` vtable slot and manipulates the outer object/global.

Implementation decision:

- Change direct owner to [UID:0000F1].
- Do not put a decompiler-shaped flag-wrapper body into formal C++. If the page remains an emitting reconstructable binary artifact by local convention, the source-like code should be destructor semantics only, or a marker explaining compiler-generated wrapper regeneration. A future exact `TimerMgr::~TimerMgr` source child would be the better place for ordinary destructor C++.

### 6. Queue destructor/grow/erase/insert method names

Best inference:

- `0002L3`: `TimerMgrTimerQueue::~TimerMgrTimerQueue()`.
- `0002L5`: `TimerMgrTimerQueue::EnsureCapacityForInsert(unsigned int additionalCount)`; current `EnsureCapacity` is acceptable if parameter text says "additional queued events".
- `0002L6`: `TimerMgrTimerQueue::EraseRange(Iterator first, Iterator last)`; current `SpliceTimerRange` is descriptive but less source-like.
- `0002L7`: `TimerMgrTimerQueue::InsertTimer(Iterator where, const ScheduledTimerEvent &event)` or `InsertEvent`.

Evidence:

- `0002L3` frees queued record slots, slot array, and root/sentinel storage; callers are TimerMgr destructor paths.
- `0002L5` is only called by insert, both times with one additional slot needed; it doubles/minimum-grows capacity, preserves wrapped ring contents with `memmove`/`memset`, updates slot array/capacity, and validates/free old large allocations.
- `0002L6` removes a contiguous logical range, chooses head-vs-tail shift by lower move cost, decrements count, updates start index, and returns an iterator-like triple. This is source-like `erase(first,last)`.
- `0002L7` inserts one 20-byte `ScheduledTimerEvent`, grows capacity if needed, chooses cheaper head/tail shift, lazily allocates a 0x14-byte record slot, copies the event, adjusts start/count, calls rotate helper for one branch, and returns an iterator-like triple.

Rejected alternatives:

- Reject generic `Queue.cpp`/`Deque.cpp` ownership. This queue stores `ScheduledTimerEvent` records and is only called by TimerMgr schedule/dispatch/cancel paths.
- Reject naming the record pointers as raw `void *` slots. Allocation size, copy size, and type docs support `ScheduledTimerEvent`.
- Reject leaving offset fields unnamed. `slotEntries`, `slotCapacity`, `startIndex`, and `count` are strongly supported by every queue method.

### 7. Source placement

Best inference: all target children belong under `NexusTK/util/TimerMgr.cpp` through semantic class/file owners, not caller modules.

Evidence:

- Proposed source tree lists `TimerMgr.cpp` under `util/`, with `TimerPane.cpp` separately under `map/` and `WaitableTimer.cpp` separately under `util/`.
- `TimerMgr` file/class/global/type docs link singleton, static object storage, tick mirrors, vtable data, TimerHandler wrappers, and queue methods to one scheduler module.
- The target range is contiguous with the larger TimerMgr island and bounded by non-TimerMgr `cc` padding before `TimerPane`.
- Caller fan-in includes application loop, timer owners, dispatch/removal paths, and UI/audio/map consumers; consumers do not own the scheduler queue.

Rejected alternatives:

- Reject `Application.cpp` ownership for `0002KY/KZ`. Application calls timer setup/refresh, but the fields/globals and owner object are TimerMgr.
- Reject `SoundManager.cpp` ownership for `0002KX`. The caller may be an audio/timer policy user, but the helper scans the central TimerMgr queue.
- Reject `TimerPane.cpp` ownership for any child in this target. `TimerPane` begins after confirmed padding at `0x005986e0`.
- Reject `WaitableTimer.cpp` ownership. It is a separate lower-level timer/event primitive and is not referenced as owner by the queue helpers.

## Ranked Ownership Analysis

### 1. [UID:0000F1] TimerMgr

Evidence for:

- `0002KX`, `0002KY`, `0002KZ`, and `0002L4` use or mutate outer `TimerMgr` state.
- Tick globals, singleton, static object storage, and vtable data all point to TimerMgr ownership.
- Current class/file docs already describe these responsibilities.

Evidence against:

- Queue record movement/grow/erase/insert internals are owned by the embedded queue, not the outer class, even though the queue is part of the `TimerMgr` object layout.

Decision:

- Use `0000F1` for `0002KX`, `0002KY`, `0002KZ`, and `0002L4`.
- Do not use `0000F1` as the direct owner for `0002L0`, `0002L1`, `0002L3`, `0002L5`, `0002L6`, or `0002L7`; those are queue-owned.

### 2. [UID:0000F2] TimerMgrTimerQueue

Evidence for:

- Queue helpers access the queue control block, slot array, capacity, start index, count, and `ScheduledTimerEvent` slots.
- Insert/remove/dispatch/schedule paths all centralize queue mutation here.
- Existing class doc is already `86/88` and source-routed through TimerMgr.

Evidence against:

- The queue is embedded and scheduler-specific, so its source file is still `TimerMgr.cpp`; this is not evidence for a standalone generic `Queue.cpp`.
- `0002L0/L1` are template/static iterator-style helpers rather than ordinary methods, but their instantiated iterator semantics are queue-specific.

Decision:

- Use `0000F2` for `0002L0`, `0002L1`, `0002L3`, `0002L5`, `0002L6`, and `0002L7`.
- In child docs, distinguish ordinary private queue methods (`destructor`, `EnsureCapacity`, `EraseRange`, `InsertTimer`) from algorithm/template support (`ReverseRange`, `RotateRange`).

### 3. [UID:0000OT] TimerMgr file

Evidence for:

- Source module is the file root for TimerMgr/TimerHandler/TimerMgrTimerQueue and the singleton/static/tick declarations.
- [UID:0002L2] is an EH cleanup thunk for TimerMgr singleton state and has no class method `this`.

Evidence against:

- The file page is not the best direct owner for class methods when class pages clear the gate. Current reconstruction metadata separates semantic owner from source output route.

Decision:

- Keep [UID:0000OT] as source file route for all children through class/global owners.
- Use [UID:0000OT] only as contextual owner for [UID:0002L2] if that ignored/generated thunk keeps a canonical owner.

### 4. [UID:0001KA] TimerMgrQueueHelpers aggregate

Evidence for:

- It is a useful memory-context page for the exact tail range and nested child map.
- Current pages use it as an emitter route for several children.

Evidence against:

- It is not a semantic source owner.
- It crosses TimerMgr, TimerMgrTimerQueue, and compiler-generated cleanup/wrapper artifacts.
- Exact child pages already carry real source ownership.
- Keeping it as an emitter produces only an empty marker and obscures direct ownership.

Decision:

- Keep as non-emitting context/index nested under `0001K6`.
- Reclassify to `RECONSTRUCTABLE:FALSE` after child emitters are normalized.

## First-Draft C++ Recommendation

### Target [UID:0001KA]

Do not emit first-draft C++ for [UID:0001KA].

Exact no-code proof:

1. `0001KA` is a mixed memory aggregate over exact children, not one source function, method, declaration, class, table, or source module.
2. The range contains `TimerMgr` methods, `TimerMgrTimerQueue` methods/helpers, a constructor-unwind singleton-clear thunk, and a scalar deleting destructor wrapper.
3. Exact child pages already own the source-bearing bodies. Monolithic aggregate C++ would duplicate child bodies and violate the by-memory rule that a page's C++ is limited to its own source object.
4. The current emitter route through `0001K6` produces only an empty marker, which confirms routing but not source shape.
5. The correct implementation direction is to normalize child owners/emitters and place source-like code on child pages only where the child represents source-authored behavior.

If the supervisor chooses not to reclassify immediately and keeps `0001KA` as `RECONSTRUCTABLE:TRUE`, then formal C++ should still not contain method bodies. At most it should contain a marker comment documenting that the page is an aggregate and children emit code. The stronger recommendation is `RECONSTRUCTABLE:FALSE` with blank `EMITTER_UIDS`.

### Child C++ eligibility and emitter metadata

Recommended child code/source handling:

| UID | Emitter metadata | C++ recommendation |
| --- | --- | --- |
| `0002KX` | `CANONICAL_OWNER:0000F1`, `EMITTER_UIDS:0000F1` | yes, source-like `TimerMgr::FindQueuedTimerDueTick` |
| `0002KY` | `CANONICAL_OWNER:0000F1`, `EMITTER_UIDS:0000F1` | yes, source-like `TimerMgr::BeginTimerPeriod` |
| `0002KZ` | `CANONICAL_OWNER:0000F1`, `EMITTER_UIDS:0000F1` | yes, source-like `TimerMgr::RefreshCurrentTick` |
| `0002L0` | keep `0000F2` | do not make public API; either emit static helper/template-support source shape or let `InsertTimer` source use a rotate/reverse abstraction |
| `0002L1` | keep `0000F2` | same as `0002L0`; source shape is rotate over queue iterators |
| `0002L2` | recommended `RECONSTRUCTABLE:FALSE`, blank emitter | no C++; compiler/EH cleanup thunk |
| `0002L3` | keep `0000F2` | yes, source-like `TimerMgrTimerQueue::~TimerMgrTimerQueue` |
| `0002L4` | `CANONICAL_OWNER:0000F1`; emitter policy depends on wrapper convention | no decompiler-style scalar flag wrapper; source destructor semantics belong to TimerMgr destructor handling |
| `0002L5` | `CANONICAL_OWNER:0000F2`, `EMITTER_UIDS:0000F2` | yes, source-like queue capacity/grow helper |
| `0002L6` | `CANONICAL_OWNER:0000F2`, `EMITTER_UIDS:0000F2` | yes, source-like queue `EraseRange` |
| `0002L7` | `CANONICAL_OWNER:0000F2`, `EMITTER_UIDS:0000F2` | yes, source-like queue `InsertTimer` |

Source-like child draft shapes for later implementation:

```cpp
DWORD TimerMgr::FindQueuedTimerDueTick(TimerHandler *owner, int timerId) const
{
    for (int i = m_queue.m_count - 1; i >= 0; --i) {
        const int logicalIndex = m_queue.m_startIndex + i;
        ScheduledTimerEvent *event = m_queue.SlotAt(logicalIndex);
        if (event != 0 && event->owner == owner && event->timerId == timerId) {
            return event->dueTick;
        }
    }
    return 0;
}

void TimerMgr::BeginTimerPeriod()
{
    TIMECAPS caps;
    timeGetDevCaps(&caps, sizeof(caps));

    m_timerPeriod = caps.wPeriodMin;
    timeBeginPeriod(m_timerPeriod);

    const DWORD now = timeGetTime();
    m_currentTick = now;
    g_timerCurrentTickMirror = now;
    g_timerTickBaselineMirror = now;
}

void TimerMgr::RefreshCurrentTick()
{
    const DWORD now = timeGetTime();
    m_currentTick = now;
    g_timerCurrentTickMirror = now;
}
```

Queue helper declarations to use as source-facing targets:

```cpp
struct TimerQueueIterator {
    TimerMgrTimerQueue *queue;
    int logicalIndex;
    ScheduledTimerEvent *event;
};

class TimerMgrTimerQueue {
private:
    ScheduledTimerEvent *SlotAt(int logicalIndex) const;
    void EnsureCapacityForInsert(unsigned int additionalCount);
    TimerQueueIterator EraseRange(TimerQueueIterator first, TimerQueueIterator last);
    TimerQueueIterator InsertTimer(TimerQueueIterator where,
                                   const ScheduledTimerEvent &event);

    static void ReverseTimerQueueRange(TimerQueueIterator first,
                                       TimerQueueIterator last);
    static TimerQueueIterator RotateTimerQueueRange(TimerQueueIterator first,
                                                    TimerQueueIterator middle,
                                                    TimerQueueIterator last);
};
```

These snippets are source-facing drafts, not final verified original names. The exact implementation callback should compare them against each child page's current decompiler/raw notes before inserting formal C++.

## Open-Question Closure

| Target open question | Closure |
| --- | --- |
| Final source names/signatures for queue-local primitives and TimerMgr helpers | Closed to best-supported descriptive names above. Exact original spellings remain unproven by stripped binary evidence, but names/signatures are strong enough for documentation and child first-draft source direction. |
| Were helpers private methods, static file helpers, or compiler/template artifacts? | Closed by category: `KX/KY/KZ` are private `TimerMgr` methods; `L5/L6/L7` and destructor are private `TimerMgrTimerQueue` methods; `L0/L1` are queue-local static/template-style iterator algorithm helpers; `L2` is compiler/EH cleanup; `L4` is compiler scalar deleting destructor wrapper over `TimerMgr` destructor semantics. |
| Field/type names for queue slot/capacity/start/count/event records | Closed: use `slotEntries`, `slotCapacity`, `startIndex`, `count`, and `ScheduledTimerEvent { owner, timerId/eventId, dueTick, arg0, arg1 }`; keep `arg0/arg1` generic. |
| Owner/emitter/source placement for aggregate and children | Closed: target non-emitting context under `0001K6`; source file `0000OT`; direct owners `0000F1`, `0000F2`, and ignored/generated `0000OT` context for `L2`. |
| Child pages needing support incorporation | Closed with checklist below. `KX/KY/KZ/L4/L5/L6/L7` need owner/emitter normalization away from `0001KA`; `L0/L1` need template/static-helper clarification; `L2` needs compiler-cleanup reclassification; `L5/L6/L7` need exact half-open/final-byte convention notes. |
| Should aggregate remain no-code and children emit first-draft C++? | Closed: aggregate should be no-code and preferably `RECONSTRUCTABLE:FALSE`; eligible children should emit source-like code where they represent source-authored behavior. |
| Raw-function/modeling status | Closed: every executable child in `0001KA` has a function body; no unmodeled raw bytes remain except confirmed `cc` padding and the final-byte display nuance for `L5/L6/L7`. |
| Caller/reachability evidence | Closed with rel32 and vtable/global evidence above. `L4` is vtable-driven rather than direct-call-driven; `L2` is EH cleanup only; all other children have direct rel32 call sites. |

## Proposed Metadata And Score Changes

Target:

```text
[UID:0001KA]
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:0001K6
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
RECONSTRUCTION_CPP CODE: keep blank
```

Rationale: completion/confidence increase because this pass resolves the aggregate role, exact range/padding, child owner split, helper classification, field/type/global names, source placement, open questions, and no-code proof. The target becomes non-emitting because exact children carry real source ownership.

Support metadata recommendations:

```text
[UID:0002KX] CANONICAL_OWNER:0000F1 EMITTER_UIDS:0000F1 COMPLETION:86 CONFIDENCE:90
[UID:0002KY] CANONICAL_OWNER:0000F1 EMITTER_UIDS:0000F1 COMPLETION:87 CONFIDENCE:92
[UID:0002KZ] CANONICAL_OWNER:0000F1 EMITTER_UIDS:0000F1 COMPLETION:89 CONFIDENCE:93
[UID:0002L0] CANONICAL_OWNER:0000F2 EMITTER_UIDS:0000F2 COMPLETION:87 CONFIDENCE:91
[UID:0002L1] CANONICAL_OWNER:0000F2 EMITTER_UIDS:0000F2 COMPLETION:87 CONFIDENCE:91
[UID:0002L2] CANONICAL_OWNER:0000OT RECONSTRUCTABLE:FALSE EMITTER_UIDS: COMPLETION:88 CONFIDENCE:92
[UID:0002L3] CANONICAL_OWNER:0000F2 EMITTER_UIDS:0000F2 COMPLETION:88 CONFIDENCE:92
[UID:0002L4] CANONICAL_OWNER:0000F1 EMITTER_UIDS:0000F1 COMPLETION:86 CONFIDENCE:91
[UID:0002L5] CANONICAL_OWNER:0000F2 EMITTER_UIDS:0000F2 COMPLETION:87 CONFIDENCE:90
[UID:0002L6] CANONICAL_OWNER:0000F2 EMITTER_UIDS:0000F2 COMPLETION:87 CONFIDENCE:90
[UID:0002L7] CANONICAL_OWNER:0000F2 EMITTER_UIDS:0000F2 COMPLETION:87 CONFIDENCE:90
```

Notes on those scores:

- `0002KX/KY/KZ` already have strong scores; the important change is owner/emitter normalization.
- `0002L0/L1` earn a modest score raise only if the static/template iterator-helper classification and signature evidence are incorporated.
- `0002L2` should become ignored/non-reconstructable cleanup support like the ThreadMan singleton-clear thunk; its score can rise because its role is now clearer.
- `0002L3/L5/L6/L7` earn modest raises if raw boundary/caller/source-name evidence is incorporated.
- `0002L4` should not receive a score raise until the implementation decides how to represent source destructor semantics versus compiler wrapper emission.

## Exact Target / Support Implementation Checklist

If accepted, the implementation callback should apply the following exact scope.

1. Target [UID:0001KA] [0x00597dc0-0x005986da.TimerMgrQueueHelpers](../../../by-memory/0x00597dc0-0x005986da.TimerMgrQueueHelpers.md)
   - Change metadata to `COMPLETION:88`, `CONFIDENCE:90`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and keep `CANONICAL_OWNER:0001K6`.
   - Replace stale "reconstructable scheduler helper subrange" wording with reviewed non-emitting mixed helper/context wording.
   - Add exact raw PE evidence: target raw offset/end/length/SHA, predecessor/successor `cc` padding, and child boundary table including true half-open ends for `0002L5` and `0002L6`.
   - Add the child owner/source-placement table from this report.
   - Add the helper classification: `KX/KY/KZ` private `TimerMgr` methods; `L0/L1` static/template queue-iterator algorithms; `L2` compiler/EH cleanup; `L3/L5/L6/L7` `TimerMgrTimerQueue` methods; `L4` compiler scalar deleting destructor wrapper over `TimerMgr` destructor semantics.
   - Add the no-code proof and remove old 95/95-gate language.
   - Add an open-question closure section rather than leaving generic future-work bullets.

2. Child [UID:0002KX] [0x00597dc0-0x00597e3f.TimerMgrFindQueuedTimerDueTick](../../../by-memory/0x00597dc0-0x00597e3f.TimerMgrFindQueuedTimerDueTick.md)
   - Change owner/emitter to [UID:0000F1].
   - Document source-facing signature `DWORD TimerMgr::FindQueuedTimerDueTick(TimerHandler *owner, int timerId) const`.
   - Add raw rel32 caller confirmation `0x0050ebf1`, no-callee fact, ret-8 ABI, and newest-to-oldest scan semantics.
   - Add first-draft C++ on the child if accepted.

3. Child [UID:0002KY] [0x00597e40-0x00597e8a.TimerMgrBeginTimerPeriod](../../../by-memory/0x00597e40-0x00597e8a.TimerMgrBeginTimerPeriod.md)
   - Change owner/emitter to [UID:0000F1].
   - Document signature `void TimerMgr::BeginTimerPeriod()`.
   - Add raw caller `0x004a6c5e`, imports, `this+0x1c`, `this+0x18`, `0x0069be10`, and `0x0069be0c`.
   - Add first-draft C++ on the child if accepted.

4. Child [UID:0002KZ] [0x00597e90-0x00597ea3.TimerMgrRefreshCurrentTick](../../../by-memory/0x00597e90-0x00597ea3.TimerMgrRefreshCurrentTick.md)
   - Change owner/emitter to [UID:0000F1].
   - Document signature `void TimerMgr::RefreshCurrentTick()`.
   - Add raw caller confirmation `0x004a6c86` and `0x004f63c0`, sole `timeGetTime` callee, and current tick mirror writes.
   - Add first-draft C++ on the child if accepted.

5. Children [UID:0002L0] and [UID:0002L1]
   - Preserve owner/emitter [UID:0000F2].
   - Raise to `87/91` only if the template/static iterator-helper classification is incorporated.
   - Document that `0002L0` uses a four-stack-argument ABI for two iterator/control-plus-index pairs and does not use `ecx`.
   - Document that `0002L1` is a three-reverse rotate helper returning an iterator-like triple and called only from insert.
   - Avoid presenting them as public queue methods.

6. Child [UID:0002L2] [0x00597fd0-0x00597fdb.ClearGlobalTimerMgr](../../../by-memory/0x00597fd0-0x00597fdb.ClearGlobalTimerMgr.md)
   - Reclassify to `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, score `88/92`.
   - Rename/source-facing role in text to `TimerMgrConstructorUnwindClearSingleton` or equivalent.
   - Add raw bytes `c7 05 80 ab 67 00 00 00 00 00 c3`, rel32 call site `0x00609b5e`, and no-normal-caller conclusion.
   - Explicitly compare to [UID:0001K4] `ClearThreadManSingleton` compiler cleanup thunk.

7. Child [UID:0002L3] [0x00597fe0-0x00598083.TimerMgrTimerQueueDestructor](../../../by-memory/0x00597fe0-0x00598083.TimerMgrTimerQueueDestructor.md)
   - Preserve owner/emitter [UID:0000F2]; raise to `88/92` if raw and source-name details are incorporated.
   - Document source signature `TimerMgrTimerQueue::~TimerMgrTimerQueue()`.
   - Add raw caller confirmation `0x00597795` and `0x005980a8`, free helper calls, field cleanup, and large-allocation validation notes.
   - Add first-draft C++ if accepted.

8. Child [UID:0002L4] [0x00598090-0x005980eb.TimerMgrScalarDeletingDestructor](../../../by-memory/0x00598090-0x005980eb.TimerMgrScalarDeletingDestructor.md)
   - Change direct owner to [UID:0000F1].
   - Document generated scalar deleting destructor wrapper classification.
   - Add vtable-only reachability: no direct rel32 caller; dword pointer at `0x0062e344`.
   - Do not hand-emit a scalar flag-wrapper body as ordinary source. If the page keeps an emitter, use source destructor semantics or a marker per supervisor policy.

9. Child [UID:0002L5] [0x005980f0-0x00598281.TimerMgrTimerQueueEnsureCapacity](../../../by-memory/0x005980f0-0x00598281.TimerMgrTimerQueueEnsureCapacity.md)
   - Change owner/emitter to [UID:0000F2]; raise to `87/90` if details are incorporated.
   - Clarify true half-open body `0x005980f0-0x00598282`; current filename/title end `0x00598281` is final executable byte.
   - Document source signature `EnsureCapacityForInsert(unsigned int additionalCount)` or `EnsureCapacity(unsigned int additionalCount)`.
   - Add raw caller sites `0x005984ac` and `0x005985a6`, both from insert.
   - Add first-draft C++ if accepted.

10. Child [UID:0002L6] [0x00598290-0x00598471.TimerMgrTimerQueueSpliceTimerRange](../../../by-memory/0x00598290-0x00598471.TimerMgrTimerQueueSpliceTimerRange.md)
    - Change owner/emitter to [UID:0000F2]; raise to `87/90` if details are incorporated.
    - Prefer source-facing name `EraseRange`; keep filename if renaming is not in scope.
    - Clarify true half-open body `0x00598290-0x00598472`; current filename/title end `0x00598471` is final executable byte.
    - Add raw caller sites `0x0059789f`, `0x00597b05`, `0x00597c7f`, and `0x00597d9f`.
    - Add first-draft C++ if accepted.

11. Child [UID:0002L7] [0x00598480-0x005986d9.TimerMgrTimerQueueInsertTimer](../../../by-memory/0x00598480-0x005986d9.TimerMgrTimerQueueInsertTimer.md)
    - Change owner/emitter to [UID:0000F2]; raise to `87/90` if details are incorporated.
    - Clarify true half-open body `0x00598480-0x005986da`; current filename/title end `0x005986d9` is final executable byte.
    - Document source signature `TimerMgrTimerQueue::InsertTimer(Iterator where, const ScheduledTimerEvent &event)`.
    - Add raw caller site `0x005979c5`, ensure-capacity calls, lazy 0x14 allocation, 20-byte event copy, rotate helper dependency, and iterator-like return.
    - Add first-draft C++ if accepted.

12. Support [UID:0000F1][TimerMgr](../../../by-class/TimerMgr.md)
    - Add the normalized helper list and private method names.
    - Add `m_timerPeriod`, `m_currentTick`, `m_nextDueTick`, and embedded queue layout names if not already present at the same detail.
    - Add generated-wrapper caveat for `TimerMgrScalarDeletingDestructor`.

13. Support [UID:0000F2][TimerMgrTimerQueue](../../../by-class/TimerMgrTimerQueue.md)
    - Add queue-local algorithm classification for reverse/rotate.
    - Add `Iterator`/iterator-like triple terminology and explain output triple fields.
    - Add final source-facing method names `EnsureCapacityForInsert`, `EraseRange`, and `InsertTimer`.
    - Preserve "not a generic container" negative evidence.

14. Support [UID:0001WD][TimerMgrLayout](../../../by-type/by-struct/TimerMgrLayout.md), [UID:0001VX][ScheduledTimerEvent](../../../by-type/by-struct/ScheduledTimerEvent.md), [UID:0000OT][TimerMgr](../../../by-file/TimerMgr.md), and [UID:0000SI][g_pTimerMgr](../../../by-global/g_pTimerMgr.md)
    - Incorporate any missing field/global names and exact references from this report, or explicitly note when already present.
    - Keep tick mirror original names marked descriptive/inferred.
    - Do not move TimerPane or WaitableTimer into this source module.

15. Validation expected after implementation
    - Run:
      `python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00597dc0-0x005986da.TimerMgrQueueHelpers.md`
    - Also run scoped validator commands for every child/support file whose metadata or C++ is changed.
    - Report exit code, scanned markdown count, `ok` count, and any autogen side effects.
    - Do not edit `by-memory/-coverage-report.md`; supervisor applies rows.

## Supervisor-Owned Coverage Row Text

Current target row is stale:

```text
    - [UID:0001KA][0x00597dc0-0x005986da.TimerMgrQueueHelpers](by-memory/0x00597dc0-0x005986da.TimerMgrQueueHelpers.md) 0x00597dc0-0x005986da | aggregate | TimerMgrQueueHelpers : reconstructable : 82% : strong : TimerMgr queue-helper subrange nested under TimerMgrAndTimerQueue, with scheduler query/tick/clear/destructor helpers, queue reverse/rotate/destroy/grow/splice/insert functions, TimerMgr/TimerMgrTimerQueue family split, shared layout/event/singleton dependencies, TimerPane/WaitableTimer boundaries, and final-name/C++ blockers documented.
```

Proposed exact replacement target row:

```text
    - [UID:0001KA][0x00597dc0-0x005986da.TimerMgrQueueHelpers](by-memory/0x00597dc0-0x005986da.TimerMgrQueueHelpers.md) 0x00597dc0-0x005986da | mixed helper context | TimerMgrQueueHelpers : ignored : 88% : strong : B015 source-quality reanalysis reclassifies this exact TimerMgr tail as a non-emitting mixed context over source-bearing child pages; raw PE confirms target `0x00597dc0-0x005986da`, predecessor/successor `0xcc` padding, child direct-call/vtable reachability, and final-byte conventions for [UID:0002L5], [UID:0002L6], and [UID:0002L7]; direct source ownership is split among TimerMgr methods, TimerMgrTimerQueue methods/template-style iterator helpers, a compiler EH singleton-clear thunk, and a compiler scalar deleting destructor wrapper, with source output through `NexusTK/util/TimerMgr.cpp` only on eligible children.
```

If the supervisor refreshes the nested child rows in the same pass, use this replacement child block under the target row:

```text
        - [UID:0002KX][0x00597dc0-0x00597e3f.TimerMgrFindQueuedTimerDueTick](by-memory/0x00597dc0-0x00597e3f.TimerMgrFindQueuedTimerDueTick.md) 0x00597dc0-0x00597e3f | TimerMgr method | TimerMgrFindQueuedTimerDueTick : reconstructable : 86% : strong : TimerMgr private queue-query method routed through TimerMgr; B015 raw PE confirms exact 0x7f body, one direct caller at 0x0050ebf1, no callees, `ret 8`, newest-to-oldest scan over embedded queue slots, owner/timerId comparison, dueTick return, and zero-on-miss path; first-draft child C++ should use `FindQueuedTimerDueTick(TimerHandler *, int)`.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00597e3f-0x00597e40 | padding | TimerMgr queue helper alignment : ignored : 100% : strong : Confirmed one `0xcc` alignment byte.
        - [UID:0002KY][0x00597e40-0x00597e8a.TimerMgrBeginTimerPeriod](by-memory/0x00597e40-0x00597e8a.TimerMgrBeginTimerPeriod.md) 0x00597e40-0x00597e8a | TimerMgr method | TimerMgrBeginTimerPeriod : reconstructable : 87% : strong : TimerMgr multimedia timer-period setup routed through TimerMgr; B015 raw PE confirms one caller at 0x004a6c5e, `timeGetDevCaps`/`timeBeginPeriod`/`timeGetTime` imports, timer period write at `this+0x1c`, current tick write at `this+0x18`, and tick mirror writes to `0x0069be10` and `0x0069be0c`; first-draft child C++ should use `BeginTimerPeriod()`.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00597e8a-0x00597e90 | padding | TimerMgr queue helper alignment : ignored : 100% : strong : Confirmed six `0xcc` alignment bytes.
        - [UID:0002KZ][0x00597e90-0x00597ea3.TimerMgrRefreshCurrentTick](by-memory/0x00597e90-0x00597ea3.TimerMgrRefreshCurrentTick.md) 0x00597e90-0x00597ea3 | TimerMgr method | TimerMgrRefreshCurrentTick : reconstructable : 89% : strong : TimerMgr current-tick refresh routed through TimerMgr; B015 raw PE confirms callers at 0x004a6c86 and 0x004f63c0, sole `timeGetTime` import, `this+0x18` current tick update, `0x0069be10` mirror write, and padding before queue iterator helpers; first-draft child C++ should use `RefreshCurrentTick()`.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00597ea3-0x00597eb0 | padding | TimerMgr queue helper alignment : ignored : 100% : strong : Confirmed thirteen `0xcc` alignment bytes.
        - [UID:0002L0][0x00597eb0-0x00597f17.TimerQueueReverseRange](by-memory/0x00597eb0-0x00597f17.TimerQueueReverseRange.md) 0x00597eb0-0x00597f17 | queue iterator algorithm helper | TimerQueueReverseRange : reconstructable : 87% : strong : TimerMgrTimerQueue-local static/template-style reverse helper, not a public queue method; B015 raw PE confirms exact 0x67 body, no callees, callers only from rotate at 0x00597f75/0x00597f82/0x00597f8e, four-stack-argument iterator/control-plus-index ABI, 20-byte ScheduledTimerEvent swaps, and queue slot/capacity dereferences.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00597f17-0x00597f20 | padding | TimerMgr queue helper alignment : ignored : 100% : strong : Confirmed nine `0xcc` alignment bytes.
        - [UID:0002L1][0x00597f20-0x00597fc9.TimerQueueRotateRange](by-memory/0x00597f20-0x00597fc9.TimerQueueRotateRange.md) 0x00597f20-0x00597fc9 | queue iterator algorithm helper | TimerQueueRotateRange : reconstructable : 87% : strong : TimerMgrTimerQueue-local static/template-style three-reverse rotate helper; B015 raw PE confirms exact 0xa9 body, one caller from insert at 0x00598693, three internal reverse calls, iterator-like hidden-output return, and no public API caller surface.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00597fc9-0x00597fd0 | padding | TimerMgr queue helper alignment : ignored : 100% : strong : Confirmed seven `0xcc` alignment bytes.
        - [UID:0002L2][0x00597fd0-0x00597fdb.ClearGlobalTimerMgr](by-memory/0x00597fd0-0x00597fdb.ClearGlobalTimerMgr.md) 0x00597fd0-0x00597fdb | compiler cleanup thunk | ClearGlobalTimerMgr : ignored : 88% : strong : Compiler-generated TimerMgr constructor-unwind singleton-clear thunk, not handwritten source; B015 raw PE confirms exact bytes `c7 05 80 ab 67 00 00 00 00 00 c3`, write to `g_pTimerMgr`, one EH cleanup rel32 caller at 0x00609b5e, no normal source caller, and analogy to the ignored ThreadMan singleton-clear thunk.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00597fdb-0x00597fe0 | padding | TimerMgr queue helper alignment : ignored : 100% : strong : Confirmed five `0xcc` alignment bytes.
        - [UID:0002L3][0x00597fe0-0x00598083.TimerMgrTimerQueueDestructor](by-memory/0x00597fe0-0x00598083.TimerMgrTimerQueueDestructor.md) 0x00597fe0-0x00598083 | TimerMgrTimerQueue destructor | TimerMgrTimerQueueDestructor : reconstructable : 88% : strong : Embedded scheduler queue destructor routed through TimerMgrTimerQueue; B015 raw PE confirms exact 0xa3 body, callers at 0x00597795 and 0x005980a8, queued record/slot/root frees, aligned large-allocation guard, field cleanup at queue control offsets, and source signature `TimerMgrTimerQueue::~TimerMgrTimerQueue()`.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00598083-0x00598090 | padding | TimerMgr queue helper alignment : ignored : 100% : strong : Confirmed thirteen `0xcc` alignment bytes.
        - [UID:0002L4][0x00598090-0x005980eb.TimerMgrScalarDeletingDestructor](by-memory/0x00598090-0x005980eb.TimerMgrScalarDeletingDestructor.md) 0x00598090-0x005980eb | scalar deleting destructor wrapper | TimerMgrScalarDeletingDestructor : reconstructable : 86% : strong : Compiler-generated TimerMgr scalar deleting destructor wrapper attached to TimerMgr, not the queue aggregate; B015 raw PE confirms no direct rel32 caller, vtable dword reference at `0x0062e344`, `timeEndPeriod`, embedded queue destructor, base cleanup/delete helpers, `g_pTimerMgr` clear, and generated-wrapper/no-handwritten-helper policy.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005980eb-0x005980f0 | padding | TimerMgr queue helper alignment : ignored : 100% : strong : Confirmed five `0xcc` alignment bytes.
        - [UID:0002L5][0x005980f0-0x00598281.TimerMgrTimerQueueEnsureCapacity](by-memory/0x005980f0-0x00598281.TimerMgrTimerQueueEnsureCapacity.md) 0x005980f0-0x00598281 | TimerMgrTimerQueue method | TimerMgrTimerQueueEnsureCapacity : reconstructable : 87% : strong : TimerMgrTimerQueue grow helper routed through TimerMgrTimerQueue; B015 raw PE confirms callers from insert at 0x005984ac and 0x005985a6, additional-count insert use, capacity doubling/minimum-eight behavior, wrapped-ring preservation, old-storage validation/free, and true half-open body `0x005980f0-0x00598282` with filename end `0x00598281` as final executable byte.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00598282-0x00598290 | padding | TimerMgr queue helper alignment : ignored : 100% : strong : Confirmed fourteen `0xcc` alignment bytes after final byte `0x00598281`.
        - [UID:0002L6][0x00598290-0x00598471.TimerMgrTimerQueueSpliceTimerRange](by-memory/0x00598290-0x00598471.TimerMgrTimerQueueSpliceTimerRange.md) 0x00598290-0x00598471 | TimerMgrTimerQueue method | TimerMgrTimerQueueSpliceTimerRange : reconstructable : 87% : strong : TimerMgrTimerQueue erase-range helper routed through TimerMgrTimerQueue; B015 raw PE confirms dispatch/removal callers at 0x0059789f/0x00597b05/0x00597c7f/0x00597d9f, no callees, head-vs-tail shift decision, start/count updates, iterator-like return, source-facing `EraseRange(first,last)` name, and true half-open body `0x00598290-0x00598472` with filename end `0x00598471` as final executable byte.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00598472-0x00598480 | padding | TimerMgr queue helper alignment : ignored : 100% : strong : Confirmed fourteen `0xcc` alignment bytes after final byte `0x00598471`.
        - [UID:0002L7][0x00598480-0x005986d9.TimerMgrTimerQueueInsertTimer](by-memory/0x00598480-0x005986d9.TimerMgrTimerQueueInsertTimer.md) 0x00598480-0x005986d9 | TimerMgrTimerQueue method | TimerMgrTimerQueueInsertTimer : reconstructable : 87% : strong : TimerMgrTimerQueue sorted insert helper routed through TimerMgrTimerQueue; B015 raw PE confirms one caller at 0x005979c5, ensure-capacity dependencies, cheaper head/tail insertion, lazy 0x14 ScheduledTimerEvent allocation, 20-byte event copy, rotate-helper call at 0x00598693, iterator-like return, and true half-open body `0x00598480-0x005986da`.
```

Do not let B015 apply these rows directly while the shared `by-memory/-coverage-report.md` ban is active.

## Scoped Validator Baseline

Command run:

> Executable block R001 was removed from this report and preserved verbatim in [0001KA-TimerMgrQueueHelpers-source-quality-removed.md](0001KA-TimerMgrQueueHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:

```text
Exit code: 0
scanned markdown files: 1
ok: 1
ok 0001KA by-memory/0x00597dc0-0x005986da.TimerMgrQueueHelpers.md UID header exists
dry run only; pass --apply to write changes
```

The validator dry run also reported the expected generated-output no-op/empty-emitter state for `auto-generated/NexusTK/util/TimerMgr.cpp`; no files were changed.

## Changed Files

Created:

```text
E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B015\research\0001KA-TimerMgrQueueHelpers-source-quality.md
```

Not edited:

```text
E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00597dc0-0x005986da.TimerMgrQueueHelpers.md
E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\-coverage-report.md
any other by-* documentation file
```

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B015","command_id":"000000004165","destination_path":"executed-b-agent-research/B015/0001KA-TimerMgrQueueHelpers-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:37","uid":"0001KA"} -->
<!-- {"agent":"B015","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001KA-TimerMgrQueueHelpers-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B015/0001KA-TimerMgrQueueHelpers-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001KA"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
