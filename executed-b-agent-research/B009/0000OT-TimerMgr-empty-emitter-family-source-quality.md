** TARGET-REPORT-UID:0000OT **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# [UID:0000OT] TimerMgr Empty-Emitter Family Source-Quality Report

Status: report-only, implementation-ready for supervisor validation.

Agent: B009

Assignment: `B009-revise-0000OT-TimerMgr-empty-emitter-family-20260630`

Primary target: [UID:0000OT] `by-file/TimerMgr.md`

Generated file inspected read-only: `auto-generated/NexusTK/util/TimerMgr.cpp`

Report output: `tools/leaser/Agents/Agent-B009/research/0000OT-TimerMgr-empty-emitter-family-source-quality.md`

Report-only constraints observed: no by-* docs edited, no leases taken, no generated files edited, no coverage/project reports edited, no validator/tool state edited, no IDA database edits, no executed archives edited, no supervisor ledgers edited, no lock files edited, and no subagents spawned.

## Executive Disposition

[UID:0000OT] `TimerMgr.md` is the correct file owner for the TimerMgr source family and should remain `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"` with `CANONICAL_OWNER:FILE`.

The current generated output is not empty because the file is poorly owned. It is empty for 16 support emitters because several support pages have source-quality evidence but blank formal `RECONSTRUCTION_CPP CODE` fields. This revision resolves the current empty-emitter family and the supervisor-returned score/source-quality blockers with a mixed implementation plan:

- add marker-only class/support blocks where a page is a routing, layout, storage, compiler-wrapper, or aggregate page rather than a standalone source declaration/body;
- add first-draft source bodies where MCP and existing documentation prove exact source-level functions, declarations, or file-local static helper algorithms;
- preserve the existing filled TimerMgr queue/helper emitters;
- repair or historicalize stale `00041*` UID/path pollution in TimerMgr and directly affected TimerHandler support prose without editing the unrelated NewHumanImageLib/VectorGrow target pages;
- reconcile the old `0xffffffff` initializer claims against current zero bytes in the active MCP session;
- raise UID0000OT target score to `COMPLETION:92`, `CONFIDENCE:90`, because this pass clears the empty-emitter family and converts the named blockers into implementation-ready edits rather than leaving them as deferrals.

Recommended target metadata:

```text
COMPLETION:92
CONFIDENCE:90
PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"
CANONICAL_OWNER:FILE
```

No UID0000OT by-file target C++ body is recommended beyond support notes, generated-output disposition, and stale-link/initializer reconciliation. The exact C++/marker insertions belong to the 16 empty child/support pages listed below.

## Current Target And Queue State

Queue row from `auto-generated/-ag-research-tracker.md`:

| UID | Target | Total emitters | Filled | Empty | Filled pct | Generated output | Target path |
|---|---|---:|---:|---:|---:|---|---|
| 0000OT | TimerMgr | 24 | 8 | 16 | 33.3% | `auto-generated/NexusTK/util/TimerMgr.cpp` | `by-file/TimerMgr.md` |

Current `by-file/TimerMgr.md` state before implementation:

```text
UID:0000OT
COMPLETION:90
CONFIDENCE:86
PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"
CANONICAL_OWNER:FILE
```

The target page already describes the TimerMgr scheduler source family, including `TimerHandler`, `TimerMgr`, `TimerMgrTimerQueue`, queue/storage/tick mirrors, and scheduler helper ownership. The page also contains older evidence from passes where MCP was unavailable and contains stale references to old UID-collision paths for unrelated NewHumanImageLib/VectorGrow pages. This report does not recommend editing those unrelated `00041*` target pages, but it does require correcting the polluted inbound TimerMgr/TimerHandler prose so the current TimerMgr family points at the existing TimerMgr schedule/remove/cancel helper paths.

## Generated Output Inventory

Read-only generated header observed in `auto-generated/NexusTK/util/TimerMgr.cpp`:

```text
validator-command-id: 000000002660
validator-refreshed-at: 2026-06-30T07:03:51-04:00
validator-refresh-source: foreground-generated-refresh
source-by-file-uid: 0000OT
source-by-file-path: by-file/TimerMgr.md
```

Currently filled emitters that must be preserved:

| UID | Name |
|---|---|
| 0001K8 | `TimerHandlerScheduleRemoveWrappers` |
| 0002KX | `FindQueuedTimerDueTick` |
| 0002KY | `BeginTimerPeriod` |
| 0002KZ | `RefreshCurrentTick` |
| 0002L3 | `TimerMgrTimerQueue` destructor |
| 0002L5 | `EnsureCapacityForInsert` |
| 0002L6 | `EraseRange` |
| 0002L7 | `InsertTimer` |

Current read-only generated `InsertTimer` evidence: the filled UID0002L7 output already calls `RotateRange(...)` in the insertion path. That generated source shape is a consistency check for recommending file-local static `RotateRange` and `ReverseRange` bodies in UID0002L1/UID0002L0 rather than marker-only comments or a separate `VectorHelpers` owner.

Current empty emitters requiring this report's implementation plan:

| UID | Current path | Current score | Disposition |
|---|---|---:|---|
| 0000F0 | `by-class/TimerHandler.md` | 87/89 | marker-only class route with `[[CHILDREN]]` |
| 0001K7 | `by-memory/0x00597580-0x005975c3.TimerHandlerDestructor.md` | 86/88 | first-draft destructor C++ |
| 0001K9 | `by-memory/0x00597610-0x00597645.TimerHandlerWrappers.md` | 86/88 | first-draft wrapper C++ |
| 0000F1 | `by-class/TimerMgr.md` | 87/86 | marker-only class route with `[[CHILDREN]]` |
| 0002L4 | `by-memory/0x00598090-0x005980eb.TimerMgrScalarDeletingDestructor.md` | 86/91 | marker-only compiler wrapper |
| 0001WD | `by-type/by-struct/TimerMgrLayout.md` | 86/88 | marker-only class layout support |
| 0000F2 | `by-class/TimerMgrTimerQueue.md` | 86/88 | marker-only class route with `[[CHILDREN]]` |
| 0002L0 | `by-memory/0x00597eb0-0x00597f17.TimerQueueReverseRange.md` | 87/91 | first-draft file-local static reverse helper |
| 0002L1 | `by-memory/0x00597f20-0x00597fc9.TimerQueueRotateRange.md` | 87/91 | first-draft file-local static rotate helper |
| 0001VX | `by-type/by-struct/ScheduledTimerEvent.md` | 85/90 | first-draft struct declaration |
| 0000SI | `by-global/g_pTimerMgr.md` | 86/90 | first-draft global pointer definition |
| 0002VW | `by-memory/0x0067ab80-0x0067ab84.g_pTimerMgr.md` | 88/91 | marker-only exact storage, no duplicate global |
| 0001K6 | `by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md` | 86/88 | marker-only aggregate/source-family page |
| 00029S | `by-memory/0x0069b3ac-0x0069b3d0.TimerMgrStaticObjectStorage.md` | 88/90 | marker-only process-lifetime object storage |
| 000306 | `by-memory/0x0069be0c-0x0069be10.TimerMgrTickBaselineMirror.md` | 86/88 | first-draft global tick mirror definition |
| 000307 | `by-memory/0x0069be10-0x0069be14.TimerMgrCurrentTickMirror.md` | 86/88 | first-draft global tick mirror definition |

Expected generated freshness after implementation and scoped validation: `auto-generated/NexusTK/util/TimerMgr.cpp` should be regenerated from by-* docs, should still identify `0000OT` as source by-file, should preserve the 8 existing filled emitters, and should no longer contain empty-emitter markers for the 16 UIDs in this table.

## Evidence Checked

Current docs read:

- `by-file/TimerMgr.md`
- `by-class/TimerHandler.md`
- `by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md`
- `by-memory/0x00597580-0x005975c3.TimerHandlerDestructor.md`
- `by-memory/0x00597610-0x00597645.TimerHandlerWrappers.md`
- `by-class/TimerMgr.md`
- `by-memory/0x00597910-0x00597a0c.TimerMgrScheduleTimer.md`
- `by-memory/0x00597a10-0x00597b73.TimerMgrRemovePendingTimersForOwner.md`
- `by-memory/0x00597b80-0x00597c99.TimerMgrCancelTimer.md`
- `by-memory/0x00597ca0-0x00597db9.TimerMgrCancelPendingTimersExceptEvent.md`
- `by-memory/0x00598090-0x005980eb.TimerMgrScalarDeletingDestructor.md`
- `by-type/by-struct/TimerMgrLayout.md`
- `by-class/TimerMgrTimerQueue.md`
- `by-memory/0x00597eb0-0x00597f17.TimerQueueReverseRange.md`
- `by-memory/0x00597f20-0x00597fc9.TimerQueueRotateRange.md`
- `by-type/by-struct/ScheduledTimerEvent.md`
- `by-global/g_pTimerMgr.md`
- `by-memory/0x0067ab80-0x0067ab84.g_pTimerMgr.md`
- `by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md`
- `by-memory/0x0069b3ac-0x0069b3d0.TimerMgrStaticObjectStorage.md`
- `by-memory/0x0069be0c-0x0069be10.TimerMgrTickBaselineMirror.md`
- `by-memory/0x0069be10-0x0069be14.TimerMgrCurrentTickMirror.md`

Generated output inspected read-only:

- `auto-generated/NexusTK/util/TimerMgr.cpp`

Old/current report search terms used as leads:

- `0000OT`
- `TimerMgr`
- `TimerMgr-empty`
- `TimerMgr.*empty`
- `TimerMgrAndTimerQueue`
- `0001K6`
- `0001K7`
- `0001K9`
- `0002L0`
- `0002L1`
- `00029S`
- `000306`
- `000307`
- `0000SI`
- `0002VW`
- `ScheduledTimerEvent`
- `TimerMgrLayout`

Relevant old/executed reports opened as leads only:

- `executed-b-agent-research/B015/0001KA-TimerMgrQueueHelpers-source-quality.md`
- `executed-b-agent-research/B014/0001K6-TimerMgrAndTimerQueue-source-quality.md`
- `executed-b-agent-research/B002/0001K6-TimerMgrAndTimerQueue-source-quality.md`
- `executed-b-agent-research/B008/0002L2-ClearGlobalTimerMgr-source-quality.md`
- `executed-b-agent-research/B006/00041A-NewHumanImageLibLoadLayerTable-source-quality.md` for the stale UID-collision note only

Old reports were not treated as authoritative where they used raw-PE fallback or older MCP sessions. Current IDA MCP evidence below is the controlling evidence for this report.

## Current IDA MCP Evidence

MCP availability: available and responding. No fallback-only report path was used.

Session evidence:

```text
MCP initialize: HTTP 200
protocol: 2025-06-18
server: ida-pro-mcp 1.0.0
session_id: supervisor_resume_20260629
idb_path: E:\NTK\Resources\NexusTK\NexusTK.exe.i64
module: NexusTK.exe
input_path: C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe
imagebase: 0x400000
is_analyzing: false
is_active: true
auto_analysis_ready: true
hexrays_ready: true
strings_cache_ready: true
worker pid: 24256
```

Revision refresh after supervisor restored the listener:

```text
idb_list: one active worker session
session_id: supervisor_resume_20260629
idb_path: E:\NTK\Resources\NexusTK\NexusTK.exe.i64
created_at: 2026-06-30T13:18:38.172059
last_accessed: 2026-06-30T13:27:47.661971
is_active: true
worker_pid: 24256
server_health: status ok, module NexusTK.exe, imagebase 0x400000, auto_analysis_ready true, hexrays_ready true, strings_cache_ready true, strings_cache_size 2067
```

Function lookup evidence:

| Address | MCP name | Size | Use in report |
|---:|---|---:|---|
| 0x00597580 | `??1exception@boost@@MAE@XZ_4` | 0x43 | TimerHandler destructor body |
| 0x00597610 | `sub_597610` | 0x16 | TimerHandler cancel wrapper |
| 0x00597630 | `sub_597630` | 0x16 | TimerHandler cancel-except wrapper |
| 0x00597eb0 | `sub_597EB0` | 0x67 | queue-local reverse helper |
| 0x00597f20 | `sub_597F20` | 0xa9 | queue-local rotate helper |
| 0x00598090 | `sub_598090` | 0x5b | TimerMgr scalar deleting destructor |
| 0x00597a10 | `sub_597A10` | 0x163 | remove TimerHandler pending timers |
| 0x00597b80 | `sub_597B80` | 0x119 | remove one TimerHandler timer |
| 0x00597ca0 | `sub_597CA0` | 0x119 | remove all except one TimerHandler timer |
| 0x00597fe0 | `sub_597FE0` | 0xa3 | TimerMgr queue cleanup |

Decompile evidence:

- `0x00597580` sets the TimerHandler vtable and calls `sub_597A10((_DWORD *)unk_67AB80, (int)this)`, proving `TimerHandler::~TimerHandler()` unregisters/removes this handler's pending timers through the global TimerMgr.
- `0x00597610` calls `sub_597B80((int *********)unk_67AB80, (int)this, a2)`, proving the single-timer removal wrapper.
- `0x00597630` calls `sub_597CA0((int *********)unk_67AB80, (int)this, a2)`, proving the cancel-all-except wrapper.
- `0x00597eb0` is a raw cdecl four-argument range reverse helper, no `ecx` receiver, swapping 0x14-byte scheduled-event records. It is support for queue insertion/rotation, not a public method. The source-facing insertion should be a file-local static `ReverseRange` helper because the existing filled `InsertTimer` emitter already calls `RotateRange` and the helper's only observed callers are from rotate.
- `0x00597f20` is a raw cdecl rotate helper with hidden output/result shape, calls `sub_597EB0` three times, and is called by queue insertion. It is support for queue insertion/rotation, not a public method. The source-facing insertion should be a file-local static `RotateRange` helper that implements the standard three-reverse rotate shape and returns `first + (last - middle)`.
- `0x00598090` is the scalar deleting destructor wrapper for TimerMgr: it sets the TimerMgr vtable, calls `timeEndPeriod(Block[7])`, calls queue cleanup `sub_597FE0(Block + 1)`, clears `unk_67AB80`, calls base cleanup, and conditionally deletes storage.

Xref evidence:

| Target | Total xrefs | First observed xref | Source-quality use |
|---:|---:|---:|---|
| 0x00597580 | 15 | 0x484006 | destructor is widely used virtual/nonvirtual support |
| 0x00597610 | 47 | 0x420dc4 | single-timer cancellation wrapper has broad source callers |
| 0x00597630 | 1 | 0x53a96d | cancel-except wrapper has one source caller |
| 0x00597eb0 | 3 | 0x597f75 | only called by rotate helper |
| 0x00597f20 | 1 | 0x598693 | only called by insertion path |
| 0x00598090 | 1 | 0x0062e344 | vtable data only, scalar deleting destructor wrapper |
| 0x0067ab80 | 125 | 0x46919d | global TimerMgr pointer is real and central |
| 0x0069b3ac | 2 | 0x419f90 | static object storage is initialization/destruction storage |
| 0x0069be0c | 2 | 0x4abad8 | tick baseline mirror global |
| 0x0069be10 | 4 | 0x4abad3 | current tick mirror global |
| 0x0062e338 | 3 | 0x597570 | TimerHandler vtable data |
| 0x0062e344 | 3 | 0x597713 | TimerMgr vtable data / deleting destructor slot |

Current byte/value evidence:

| Address | Current MCP bytes/value | Use |
|---:|---|---|
| 0x0067ab80 | `00 00 00 00`, value `0x0` | `g_pTimerMgr` initializes to null in current IDB |
| 0x0069b3ac | 0x24 zero bytes | TimerMgr static object storage is zero-initialized in current IDB |
| 0x0069be0c | value `0x0` | tick baseline mirror initializes to zero |
| 0x0069be10 | value `0x0` | current tick mirror initializes to zero |
| 0x0062e338 | value `0x597650` | TimerHandler vtable slot evidence |
| 0x0062e33c | value `0x5ca28c` | purecall slot evidence |
| 0x0062e344 | value `0x598090` | TimerMgr scalar deleting destructor vtable slot |

Negative evidence required for ownership/source placement:

- No evidence supports moving TimerMgr source ownership out of `by-file/TimerMgr.md`; generated output already routes the TimerMgr family to `auto-generated/NexusTK/util/TimerMgr.cpp`.
- No evidence supports EventDispatcher, SoundManager, BrowserPane, WaitableTimer, or Boost source ownership for this family; those are callers or stale labels, not owners.
- `0x00597eb0` and `0x00597f20` have no `this` receiver and are only internal iterator/range algorithm helpers. Emitting them as public `TimerMgrTimerQueue` methods would overstate the source API, but leaving them marker-only is now too weak because current MCP and the existing filled `InsertTimer` body support source-shaped file-local static helper bodies.
- `0x00598090` is vtable-referenced deleting destructor wrapper evidence, not a normal handwritten source method.
- `0x0067ab80`, `0x0069b3ac`, `0x0069be0c`, and `0x0069be10` currently read as zero-initialized in the active IDB. Older prose that reported `0xffffffff` initializers should be reconciled during implementation as historical/stale fallback evidence, not preserved as current byte truth.
- Current `by-file/TimerMgr.md`, `by-class/TimerHandler.md`, and `by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md` contain stale display links that point TimerMgr helper roles at NewHumanImageLib/VectorGrow paths for UID-collision rows. The current TimerMgr helper docs exist at `by-memory/0x00597910-0x00597a0c.TimerMgrScheduleTimer.md`, `by-memory/0x00597a10-0x00597b73.TimerMgrRemovePendingTimersForOwner.md`, `by-memory/0x00597b80-0x00597c99.TimerMgrCancelTimer.md`, and `by-memory/0x00597ca0-0x00597db9.TimerMgrCancelPendingTimersExceptEvent.md`; polluted inbound links should be corrected or historicalized in TimerMgr support prose instead of editing unrelated NewHumanImageLib/VectorGrow pages.
- Old reports that relied on MCP-unavailable raw-PE fallback are useful leads but are superseded by the current `supervisor_resume_20260629` MCP evidence above.

## Ranked Ownership And Source Placement

| Rank | Owner / placement | Disposition | Rationale |
|---:|---|---|---|
| 1 | `by-file/TimerMgr.md` -> `NexusTK/util/TimerMgr.cpp` | primary file owner | Existing target owner, generated route, queue row, and MCP evidence all align on one TimerMgr utility source family. |
| 2 | `by-class/TimerHandler.md`, `by-class/TimerMgr.md`, `by-class/TimerMgrTimerQueue.md` | class routing/support pages | These are owner support pages under the TimerMgr file. They should emit marker text plus `[[CHILDREN]]`, not partial standalone class declarations in this pass. |
| 3 | exact by-memory function pages | function/source-shape pages | Destructor and TimerHandler wrappers can emit exact first-draft C++; deleting destructor remains marker-only compiler-wrapper support; queue iterator helpers should emit file-local static `ReverseRange`/`RotateRange` bodies rather than public class methods. |
| 4 | `by-type/by-struct/ScheduledTimerEvent.md` and `by-global/g_pTimerMgr.md` | source declarations | These are safe source-level declarations with exact size/current initializer evidence. |
| 5 | storage by-memory pages | storage support markers or simple globals | Exact storage pages should avoid duplicate definitions when a by-global/source declaration owns the emitted line. Tick mirror pages can emit direct globals because no separate by-global page currently owns them. |

## Heuristic / Inference Reanalysis And Validation

The revised recommendation applies the score-blocker standard to each named uncertainty rather than leaving it as a deferral.

- File ownership: keep `by-file/TimerMgr.md` because the queue row, generated C++ header, current target metadata, and surrounding TimerHandler/TimerMgr/TimerMgrTimerQueue docs all route to `NexusTK/util/TimerMgr.cpp`. Caller systems such as EventDispatcher, SoundManager, BrowserPane, WaitableTimer, and feature panes remain consumers.
- Source split: document that the exact original disk split is unproven, but preserve the current TimerMgr.cpp route because no current evidence proves a separate `TimerHandler.cpp`. This is a bounded source-placement decision, not a reason to suppress class/child emission.
- Queue helpers: convert [UID0002L0]/[UID0002L1] from marker-only to first-draft file-local static helper bodies. The raw ABI is not suitable for public class methods, but the source algorithm is clear: reverse swaps `ScheduledTimerEvent` records and rotate performs the standard three-reverse operation used by queue insert.
- Stale UID/path pollution: treat wrong NewHumanImageLib/VectorGrow links as documentation corruption in TimerMgr/TimerHandler support pages. Correct the inbound links to current TimerMgr helper paths or raw TimerHandler ranges while leaving unrelated UID-collision target pages untouched.
- Initializers: make current MCP bytes authoritative for image initializers. Historical `0xffffffff` prose is preserved only as stale/superseded evidence; runtime constructor/member sentinel writes remain a separate behavior fact.
- Source names: prefer names already present in current TimerMgr paths and generated C++ when they match behavior, and add rationale for each name where original spelling is not directly proven. No final code should use raw `sub_`, `unk_`, or decompiler temporary names.

## Score And Metadata Before/After Disposition

Owner, reconstructable state, emitter UIDs, and reconstruction path remain unchanged unless the table says otherwise. Score increases are modest because the work clears empty emitters, resolves stale evidence, and gives source-shaped helper bodies, but does not claim original-source spellings or final header declarations are proven.

| UID | Destination doc | Before | Recommended after | Metadata/score rationale |
|---|---|---:|---:|---|
| 0000OT | `by-file/TimerMgr.md` | 90/86 | 92/90 | File owner remains correct; empty-emitter family is cleared; stale UID/path pollution and zero-initializer contradiction become required doc edits instead of score blockers. |
| 0000F0 | `by-class/TimerHandler.md` | 87/89 | 89/91 | Class route gains formal `[[CHILDREN]]` marker and stale pure-callback UID link correction; direct child pages own the methods. |
| 0001K8 | `by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md` | 86/86 | 87/89 | Already-emitting support page keeps current C++; stale callee links are corrected to current TimerMgr helper paths and name consistency is improved. |
| 0001K7 | `by-memory/0x00597580-0x005975c3.TimerHandlerDestructor.md` | 86/88 | 89/91 | Formal destructor C++ is supported by MCP decompile and destructor/removal call evidence. |
| 0001K9 | `by-memory/0x00597610-0x00597645.TimerHandlerWrappers.md` | 86/88 | 89/91 | Formal cancel/cancel-except wrappers are supported by direct MCP decompiles and call targets. |
| 0000F1 | `by-class/TimerMgr.md` | 87/86 | 89/90 | Class route gains formal marker, current helper-route prose, and stale child display correction; method/storage pages own concrete code. |
| 0002L4 | `by-memory/0x00598090-0x005980eb.TimerMgrScalarDeletingDestructor.md` | 86/91 | 88/93 | Formal no-code marker is strong because vtable-only deleting destructor wrapper is compiler-generated, not source-authored body. |
| 0001WD | `by-type/by-struct/TimerMgrLayout.md` | 86/88 | 87/90 | Layout page gains no-duplicate marker and clearer class-layout support role. |
| 0000F2 | `by-class/TimerMgrTimerQueue.md` | 86/88 | 89/91 | Queue class route gains formal marker and child/helper ownership clarity; helper bodies now land in exact by-memory helper pages. |
| 0002L0 | `by-memory/0x00597eb0-0x00597f17.TimerQueueReverseRange.md` | 87/91 | 89/92 | Formal file-local static `ReverseRange` body is now supported by no-`ecx`, 0x14 record swap, and only-rotate xrefs; public-method alternative remains rejected. |
| 0002L1 | `by-memory/0x00597f20-0x00597fc9.TimerQueueRotateRange.md` | 87/91 | 89/92 | Formal file-local static `RotateRange` body is now supported by three calls to reverse and the existing filled `InsertTimer` call to `RotateRange`. |
| 0001VX | `by-type/by-struct/ScheduledTimerEvent.md` | 85/90 | 88/92 | Five-dword event record gets formal source struct and naming rationale. |
| 0000SI | `by-global/g_pTimerMgr.md` | 86/90 | 88/92 | Global pointer definition gets current MCP zero initializer and historicalizes old `0xffffffff` prose. |
| 0002VW | `by-memory/0x0067ab80-0x0067ab84.g_pTimerMgr.md` | 88/91 | 89/93 | Exact-storage page gains no-duplicate marker and current zero bytes; by-global owns the emitted declaration. |
| 0001K6 | `by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md` | 86/88 | 88/90 | Aggregate page gains no-monolithic-body marker and stale child-path correction/source-family proof. |
| 00029S | `by-memory/0x0069b3ac-0x0069b3d0.TimerMgrStaticObjectStorage.md` | 88/90 | 89/92 | Static storage gains no-duplicate marker and current all-zero byte reconciliation. |
| 000306 | `by-memory/0x0069be0c-0x0069be10.TimerMgrTickBaselineMirror.md` | 86/88 | 88/91 | Tick baseline mirror gets formal zero-initialized global and current xref/byte proof. |
| 000307 | `by-memory/0x0069be10-0x0069be14.TimerMgrCurrentTickMirror.md` | 86/88 | 88/91 | Current tick mirror gets formal zero-initialized global and current xref/byte proof. |
| 00041D | `by-memory/0x00597910-0x00597a0c.TimerMgrScheduleTimer.md` | 86/88 | 86/88 | Read-only link destination for stale-link correction. No content edit is required in this callback because the target page itself is already the current TimerMgr helper; wrong inbound links are repaired in TimerMgr/TimerHandler docs. |
| 00041E | `by-memory/0x00597a10-0x00597b73.TimerMgrRemovePendingTimersForOwner.md` | 86/88 | 86/88 | Read-only link destination for stale-link correction. No content edit is required here; do not edit the unrelated NewHuman/Vector UID-collision path, and repair wrong inbound TimerMgr prose instead. |

## Per-UID Implementation Disposition

| UID | Destination doc | Required edit class | Score action | Proof |
|---|---|---|---|---|
| 0000OT | `by-file/TimerMgr.md` | add empty-emitter family source disposition, MCP provenance, generated inventory, rejected alternatives, target score rationale, stale `00041*` inbound-link reconciliation, and zero-initializer reconciliation | raise 90/86 -> 92/90 | current generated output has 16 blank children; restored MCP resolves helper and initializer blockers |
| 0000F0 | `by-class/TimerHandler.md` | formal marker-only C++ block with `[[CHILDREN]]`; replace wrong NewHuman pure-callback link with raw `0x005975d0-0x005975d5` TimerHandler body wording until registry-owned UID/path repair exists | raise 87/89 -> 89/91 | class route page; child method pages own concrete bodies; stale link is local prose pollution |
| 0001K8 | `by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md` | preserve existing C++; replace stale callee links to NewHuman/Vector paths with current TimerMgr schedule/remove helper paths; update caveat from unresolved naming to accepted descriptive consistency | raise 86/86 -> 87/89 | C++ already present; current wrapper call targets are `0x00597910` and `0x00597a10`, not NewHuman/Vector code |
| 0001K7 | `by-memory/0x00597580-0x005975c3.TimerHandlerDestructor.md` | formal destructor C++ body | raise 86/88 -> 89/91 | MCP decompile shows vtable store and global TimerMgr removal call |
| 0001K9 | `by-memory/0x00597610-0x00597645.TimerHandlerWrappers.md` | formal two-wrapper C++ body | raise 86/88 -> 89/91 | MCP decompile shows wrappers around `sub_597B80` and `sub_597CA0` |
| 0000F1 | `by-class/TimerMgr.md` | formal marker-only C++ block with `[[CHILDREN]]`; align child/helper prose with current TimerMgr paths | raise 87/86 -> 89/90 | class route page; method/storage pages own concrete source |
| 0002L4 | `by-memory/0x00598090-0x005980eb.TimerMgrScalarDeletingDestructor.md` | formal marker-only compiler-wrapper block | raise 86/91 -> 88/93 | vtable-only deleting destructor wrapper, no direct source caller |
| 0001WD | `by-type/by-struct/TimerMgrLayout.md` | formal marker-only layout-support block | raise 86/88 -> 87/90 | documents class layout offsets, not standalone struct |
| 0000F2 | `by-class/TimerMgrTimerQueue.md` | formal marker-only C++ block with `[[CHILDREN]]` plus helper/source-route note | raise 86/88 -> 89/91 | class route page; queue method/helper pages own concrete source |
| 0002L0 | `by-memory/0x00597eb0-0x00597f17.TimerQueueReverseRange.md` | formal file-local static `ReverseRange` C++ body and no-public-method proof | raise 87/91 -> 89/92 | raw cdecl helper called only by rotate; current decompile swaps 0x14-byte event records |
| 0002L1 | `by-memory/0x00597f20-0x00597fc9.TimerQueueRotateRange.md` | formal file-local static `RotateRange` C++ body and no-public-method proof | raise 87/91 -> 89/92 | raw cdecl helper called only by insert; current decompile calls reverse three times |
| 0001VX | `by-type/by-struct/ScheduledTimerEvent.md` | formal struct declaration and field-name rationale | raise 85/90 -> 88/92 | exact 0x14 five-dword event record |
| 0000SI | `by-global/g_pTimerMgr.md` | formal global definition; historicalize old `0xffffffff` initializer as stale against current zero bytes | raise 86/90 -> 88/92 | current MCP data bytes and 125 xrefs prove null-initialized TimerMgr pointer |
| 0002VW | `by-memory/0x0067ab80-0x0067ab84.g_pTimerMgr.md` | formal marker-only exact-storage block; current bytes zero reconciliation | raise 88/91 -> 89/93 | by-global owns emitted declaration; storage page must not duplicate |
| 0001K6 | `by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md` | formal marker-only aggregate block; align child path prose with current TimerMgr paths where present | raise 86/88 -> 88/90 | source-family aggregate, not one source body |
| 00029S | `by-memory/0x0069b3ac-0x0069b3d0.TimerMgrStaticObjectStorage.md` | formal marker-only static-storage block; current zero bytes reconciliation | raise 88/90 -> 89/92 | process-lifetime storage generated from file-level static instance; no standalone duplicate definition |
| 000306 | `by-memory/0x0069be0c-0x0069be10.TimerMgrTickBaselineMirror.md` | formal global definition and current zero-byte/xref proof | raise 86/88 -> 88/91 | current MCP value zero and two xrefs |
| 000307 | `by-memory/0x0069be10-0x0069be14.TimerMgrCurrentTickMirror.md` | formal global definition and current zero-byte/xref proof | raise 86/88 -> 88/91 | current MCP value zero and four xrefs |
| 00041D/00041E TimerMgr helper paths | `0x00597910...ScheduleTimer`, `0x00597a10...RemovePendingTimersForOwner` | no content edit; use as correct link destinations for stale inbound docs | keep 86/88 each | target pages themselves are already current TimerMgr helper docs; UID-collision registry/path repair is outside by-* editing and validator-owned |

## Formal Reconstruction Insertions

These are exact proposed `RECONSTRUCTION_CPP CODE` insertion blocks for implementation callback use. Each block is destination-specific and should replace the currently blank formal code field in that destination doc only after re-reading current content and acquiring a short lease.

### UID0000F0 `by-class/TimerHandler.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// UID0000F0 TimerHandler class-level source is covered by TimerMgr.cpp and exact TimerHandler method/support pages; no standalone partial class declaration is emitted until the final TimerHandler.cpp versus TimerMgr.cpp split and callback declaration are source-final.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID0001K7 `by-memory/0x00597580-0x005975c3.TimerHandlerDestructor.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
TimerHandler::~TimerHandler()
{
    g_pTimerMgr->RemovePendingTimersForOwner(this);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID0001K9 `by-memory/0x00597610-0x00597645.TimerHandlerWrappers.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void TimerHandler::CancelTimer(int timerId)
{
    g_pTimerMgr->CancelTimer(this, timerId);
}

void TimerHandler::CancelPendingTimersExceptEvent(int timerId)
{
    g_pTimerMgr->CancelPendingTimersExceptEvent(this, timerId);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID0000F1 `by-class/TimerMgr.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// UID0000F1 TimerMgr class-level source is owned by NexusTK/util/TimerMgr.cpp; exact constructor, destructor, timer-period, queue, and storage behavior is emitted by the dedicated child/support pages, so no partial class declaration is emitted here.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID0002L4 `by-memory/0x00598090-0x005980eb.TimerMgrScalarDeletingDestructor.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Compiler-generated scalar deleting destructor wrapper for TimerMgr; source destructor semantics are represented by the TimerMgr destructor and queue/global cleanup docs, not by a standalone handwritten helper body.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID0001WD `by-type/by-struct/TimerMgrLayout.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// TimerMgr layout support is covered by the TimerMgr class declaration; this page emits no standalone struct because it documents offsets for the class-owned scheduler object.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID0000F2 `by-class/TimerMgrTimerQueue.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// UID0000F2 TimerMgrTimerQueue class-level source is owned by TimerMgr.cpp; exact queue storage and method behavior is emitted by the dedicated queue child/support pages, so no partial class declaration is emitted here.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID0002L0 `by-memory/0x00597eb0-0x00597f17.TimerQueueReverseRange.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void ReverseRange(TimerMgrTimerQueue::Iterator first, TimerMgrTimerQueue::Iterator last)
{
    while (first != last) {
        --last;
        if (first == last) {
            break;
        }

        ScheduledTimerEvent temp = *first;
        *first = *last;
        *last = temp;
        ++first;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID0002L1 `by-memory/0x00597f20-0x00597fc9.TimerQueueRotateRange.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static TimerMgrTimerQueue::Iterator RotateRange(TimerMgrTimerQueue::Iterator first,
                                                TimerMgrTimerQueue::Iterator middle,
                                                TimerMgrTimerQueue::Iterator last)
{
    if (first == middle) {
        return last;
    }

    if (middle == last) {
        return first;
    }

    ReverseRange(first, middle);
    ReverseRange(middle, last);
    ReverseRange(first, last);
    return first + (last - middle);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID0001VX `by-type/by-struct/ScheduledTimerEvent.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct ScheduledTimerEvent
{
    TimerHandler* owner;
    int timerId;
    DWORD dueTick;
    int arg0;
    int arg1;
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID0000SI `by-global/g_pTimerMgr.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
TimerMgr* g_pTimerMgr = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID0002VW `by-memory/0x0067ab80-0x0067ab84.g_pTimerMgr.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Exact storage for g_pTimerMgr is emitted by [UID:0000SI]; this range page emits no duplicate global definition.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID0001K6 `by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// TimerMgrAndTimerQueue is a source-family aggregate; exact child pages emit TimerHandler, TimerMgr, TimerMgrTimerQueue, global, and queue support source.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID00029S `by-memory/0x0069b3ac-0x0069b3d0.TimerMgrStaticObjectStorage.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Process-lifetime TimerMgr static object storage is generated from the TimerMgr.cpp static instance declaration; this storage page emits no standalone duplicate definition.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID000306 `by-memory/0x0069be0c-0x0069be10.TimerMgrTickBaselineMirror.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
DWORD g_timerTickBaselineMirror = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID000307 `by-memory/0x0069be10-0x0069be14.TimerMgrCurrentTickMirror.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
DWORD g_timerCurrentTickMirror = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

## Source-Facing Naming Rationale And Consistency Checks

- `TimerHandler::ScheduleTimer` and `TimerHandler::RemovePendingTimers`: existing UID0001K8 C++ already uses these names and the wrappers are source-shaped forwarding methods on the `TimerHandler` owner. Keep them; only correct stale callee link destinations.
- `TimerHandler::CancelTimer`: selected because `0x00597610` forwards `this` and one timer id to `0x00597b80`, the current `TimerMgrCancelTimer` helper path. `CancelTimer` is more source-facing than raw `RemoveTimer` because this is the TimerHandler wrapper paired with `CancelPendingTimersExceptEvent`.
- `TimerHandler::CancelPendingTimersExceptEvent`: selected because `0x00597630` forwards `this` and one timer id to `0x00597ca0`, the current helper that removes pending entries except the supplied event/timer id. This name is long but precise and matches the existing by-memory path.
- `TimerMgr::ScheduleTimer` and `TimerMgr::RemovePendingTimersForOwner`: keep the current helper-page names because `0x00597910` constructs a `ScheduledTimerEvent` and inserts it into the queue, while `0x00597a10` walks backward and removes entries whose owner matches the supplied `TimerHandler`. `RemovePendingTimersForOwner` is preferred over `RemoveTimer` for `0x00597a10` because the predicate is owner-only, not a single timer id.
- `ScheduledTimerEvent::owner`, `timerId`, `dueTick`, `arg0`, and `arg1`: `owner` is proven by the `TimerHandler*` forwarding path; `timerId` is preferred over `eventId` for wrapper consistency; `dueTick` reflects the sorted queue and next-due cache; `arg0`/`arg1` remain generic because caller-specific payload semantics vary and no single source-facing meaning is proven.
- `g_pTimerMgr`: keep the established global name because the by-global page, many current docs, and 125 MCP xrefs already use it. The current declaration should use `= 0` rather than `= 0xffffffff`; the latter is historical/stale byte evidence for this IDB state.
- `g_timerTickBaselineMirror` and `g_timerCurrentTickMirror`: these descriptive names are accepted for the two by-memory tick globals because there are no separate by-global pages and current docs already distinguish baseline/current tick mirror roles. Both initialize to zero in current MCP bytes.
- `ReverseRange` and `RotateRange`: use file-local `static` helpers, not public `TimerMgrTimerQueue` methods. The restored MCP decompiles show no `ecx` receiver; xrefs show reverse only called by rotate and rotate only by insert; the existing filled `TimerMgrTimerQueue::InsertTimer` generated C++ already calls `RotateRange`. This makes `ReverseRange`/`RotateRange` the least decompiler-shaped and most consistent source-facing names for this pass.
- `TimerHandler`/`TimerMgr.cpp` source split: keep the file route through `NexusTK/util/TimerMgr.cpp` for this callback because current docs and generated output already route the family there and no PDB/source-path string proves a separate `TimerHandler.cpp`. This is a source-placement decision, not a blocker; implementation prose should say the final disk split remains unproven but does not prevent the current file-owned emitter plan.

## Support-Doc Plan With Destinations

Required target/support destinations for implementation callback:

- `by-file/TimerMgr.md`: add a source-quality note summarizing the current generated-empty family, restored MCP session provenance, generated inventory, target score rationale, rejected alternatives, current data-initializer reconciliation, and the fact that the source route remains `NexusTK/util/TimerMgr.cpp`. Replace or historicalize stale NewHumanImageLib/VectorGrow display links in the TimerHandler/TimerMgr proposed-content rows, evidence notes, and change history. Correct TimerMgr middle-helper references to current TimerMgr paths: `by-memory/0x00597910-0x00597a0c.TimerMgrScheduleTimer.md`, `by-memory/0x00597a10-0x00597b73.TimerMgrRemovePendingTimersForOwner.md`, `by-memory/0x00597b80-0x00597c99.TimerMgrCancelTimer.md`, and `by-memory/0x00597ca0-0x00597db9.TimerMgrCancelPendingTimersExceptEvent.md`. For the pure callback body, use raw range `0x005975d0-0x005975d5` or historicalized text rather than linking to the current NewHumanImageLib UID-collision path until validator-owned UID/path registry repair exists. No formal C++ block change is required on the file page.
- `by-class/TimerHandler.md`: replace blank formal code with the marker plus `[[CHILDREN]]`; preserve existing lifecycle/callback evidence. Replace stale [UID:000418] NewHumanImageLib links for the pure virtual out-of-line body with raw range `0x005975d0-0x005975d5` TimerHandler callback-body wording or a historicalized note explaining the UID/path collision.
- `by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md`: preserve the existing first-draft wrapper C++; replace stale callee links to NewHumanImageLib/VectorGrow UID-collision pages with current TimerMgr helper paths `by-memory/0x00597910-0x00597a0c.TimerMgrScheduleTimer.md` and `by-memory/0x00597a10-0x00597b73.TimerMgrRemovePendingTimersForOwner.md`; keep the score cap lifted to 87/89 because naming and call destinations are now coherent.
- `by-memory/0x00597580-0x005975c3.TimerHandlerDestructor.md`: insert the destructor body and update prose to current MCP session proof.
- `by-memory/0x00597610-0x00597645.TimerHandlerWrappers.md`: insert both wrapper bodies and update prose to current MCP session proof.
- `by-class/TimerMgr.md`: replace blank formal code with marker plus `[[CHILDREN]]`; preserve existing method-family evidence and align helper names with `ScheduleTimer`, `RemovePendingTimersForOwner`, `CancelTimer`, and `CancelPendingTimersExceptEvent`.
- `by-memory/0x00598090-0x005980eb.TimerMgrScalarDeletingDestructor.md`: insert compiler-wrapper marker; preserve vtable-only proof.
- `by-type/by-struct/TimerMgrLayout.md`: insert layout-support marker; preserve offset facts.
- `by-class/TimerMgrTimerQueue.md`: replace blank formal code with marker plus `[[CHILDREN]]`; preserve queue class evidence and note that range helpers are file-local static algorithms, not public queue API.
- `by-memory/0x00597eb0-0x00597f17.TimerQueueReverseRange.md`: insert the formal file-local static `ReverseRange` body and preserve no-`this`/only-rotate proof.
- `by-memory/0x00597f20-0x00597fc9.TimerQueueRotateRange.md`: insert the formal file-local static `RotateRange` body and preserve three-reverse/only-insert proof.
- `by-type/by-struct/ScheduledTimerEvent.md`: insert the exact five-field struct declaration.
- `by-global/g_pTimerMgr.md`: insert the null-initialized global pointer definition and reconcile old `0xffffffff` initializer prose against current MCP zero bytes; document older `0xffffffff` text as superseded/historical and separate it from runtime constructor writes.
- `by-memory/0x0067ab80-0x0067ab84.g_pTimerMgr.md`: insert exact-storage/no-duplicate marker and reconcile current bytes zero; current data row should show `00 00 00 00`, not `ff ff ff ff`.
- `by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md`: insert aggregate/source-family marker and keep child ownership.
- `by-memory/0x0069b3ac-0x0069b3d0.TimerMgrStaticObjectStorage.md`: insert storage/no-duplicate marker and reconcile current 36 zero bytes against older stale `0xffffffff`/all-`ff` prose. Preserve that the TimerMgr constructor/runtime fields may later hold `0xffffffff` sentinel values; do not describe the image bytes as `0xffffffff`.
- `by-memory/0x0069be0c-0x0069be10.TimerMgrTickBaselineMirror.md`: insert tick baseline global definition with zero initializer and current MCP xref/byte proof.
- `by-memory/0x0069be10-0x0069be14.TimerMgrCurrentTickMirror.md`: insert current tick global definition with zero initializer and current MCP xref/byte proof.
- `by-memory/0x00598480-0x005986d9.TimerMgrTimerQueueInsertTimer.md`: no content edit is required because current content already calls and documents `RotateRange` at same-or-greater detail; re-read during callback as consistency proof and mark already-present. This is a read-only support proof because the current generated output already shows `InsertTimer` filled and using `RotateRange`.

Explicitly excluded or read-only support destinations:

- `by-memory/0x00597910-0x00597a0c.TimerMgrScheduleTimer.md` and `by-memory/0x00597a10-0x00597b73.TimerMgrRemovePendingTimersForOwner.md`: use as correct link destinations. Do not edit them in this callback unless current re-read shows missing or contradictory TimerMgr identity; the stale pollution is in inbound TimerMgr/TimerHandler docs, not these target pages.
- NewHumanImageLib pages, VectorGrow pages, `by-memory/0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable.md`, and `by-memory/0x004e4f10-0x004e50a0.VectorGrowAcc2Drw.md`: do not edit. The TimerMgr callback should not overwrite unrelated UID-collision targets; it should remove or historicalize incorrect inbound TimerMgr references to those paths.
- `by-file/VectorHelpers.md`: no edit. Current MCP proves `0x00597eb0`/`0x00597f20` are TimerMgr queue-local helpers, and existing TimerMgr generated output calls `RotateRange`, so VectorHelpers ownership is rejected.
- Additional by-global pages for tick mirror names are not required. The current generated-empty markers are the exact by-memory pages, and those pages can safely emit the global definitions in the current file route.

## Rejected Alternatives

- Rejected moving TimerMgr source ownership to EventDispatcher, SoundManager, BrowserPane, WaitableTimer, or Boost. MCP xrefs show those systems as callers or stale labels, not source owners.
- Rejected emitting a monolithic `TimerMgrAndTimerQueue` body from [UID:0001K6]. The range is a source-family aggregate and would duplicate exact child pages.
- Rejected public `TimerMgrTimerQueue::ReverseRange` and `TimerMgrTimerQueue::RotateRange` method bodies for [UID:0002L0] and [UID:0002L1]. MCP shows cdecl internal helper shapes and narrow callers, so the recommended source shape is file-local `static ReverseRange`/`static RotateRange`.
- Rejected leaving [UID:0002L0] and [UID:0002L1] marker-only. Current MCP decompiles, current xrefs, B015 queue-helper evidence, and the already-filled `InsertTimer` call to `RotateRange` make first-draft static helper bodies safe enough for this pass.
- Rejected emitting a standalone source body for [UID:0002L4]. MCP shows a compiler-generated scalar deleting destructor wrapper referenced through vtable data.
- Rejected duplicate global definitions from storage range pages [UID:0002VW] and [UID:00029S] where an owning global/source declaration should represent the source.
- Rejected preserving older `0xffffffff` initializer claims as current byte facts. Current MCP reads zero bytes/values for the TimerMgr globals and static storage.
- Rejected keeping stale `00041*` NewHumanImageLib/VectorGrow links in TimerMgr prose as harmless. Those links directly confuse TimerMgr helper ownership, so the implementation callback must correct or historicalize the inbound links while leaving the unrelated target pages untouched.

## Callback Implementation Proof

Callback status: implementation-applied for accepted [UID:0000OT] TimerMgr empty-emitter family. This report is not executed/archived by B009.

Changed by-* files:

- `by-file/TimerMgr.md`
- `by-class/TimerHandler.md`
- `by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md`
- `by-memory/0x00597580-0x005975c3.TimerHandlerDestructor.md`
- `by-memory/0x00597610-0x00597645.TimerHandlerWrappers.md`
- `by-class/TimerMgr.md`
- `by-memory/0x00598090-0x005980eb.TimerMgrScalarDeletingDestructor.md`
- `by-type/by-struct/TimerMgrLayout.md`
- `by-class/TimerMgrTimerQueue.md`
- `by-memory/0x00597eb0-0x00597f17.TimerQueueReverseRange.md`
- `by-memory/0x00597f20-0x00597fc9.TimerQueueRotateRange.md`
- `by-type/by-struct/ScheduledTimerEvent.md`
- `by-global/g_pTimerMgr.md`
- `by-memory/0x0067ab80-0x0067ab84.g_pTimerMgr.md`
- `by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md`
- `by-memory/0x0069b3ac-0x0069b3d0.TimerMgrStaticObjectStorage.md`
- `by-memory/0x0069be0c-0x0069be10.TimerMgrTickBaselineMirror.md`
- `by-memory/0x0069be10-0x0069be14.TimerMgrCurrentTickMirror.md`

Read-only support proof:

- `by-memory/0x00598480-0x005986d9.TimerMgrTimerQueueInsertTimer.md` already calls `RotateRange`; generated `TimerMgr.cpp` line proof shows `InsertTimer` still calls `RotateRange` after refresh.
- `by-memory/0x00597910-0x00597a0c.TimerMgrScheduleTimer.md` and `by-memory/0x00597a10-0x00597b73.TimerMgrRemovePendingTimersForOwner.md` were used only as current TimerMgr link destinations; no edit was required.
- Unrelated NewHumanImageLib pages, VectorGrow pages, and `by-file/VectorHelpers.md` were not edited.

Lease proof:

- B009 acquired short leases on all 18 changed by-* files before the edit/validator batch; each initial lease command returned `Success`.
- The long validator batches exceeded the short lease TTL. A later lease attempt returned `Rejected[Already has lease]` while the lease state still existed; final unlease after validation returned `Rejected[No active lease]` for all 18 paths because the leases had already expired/purged.
- `tools/leaser/Agents/Agent-B009/current_leases.md` and the global current lease report showed no active B009 leases after the final release attempt.

Validator proof, run from `E:\NTK\GhidraBridge\source-3\project-documentation` with `python .\tools\validator.py --mode file --file <file> --apply --queue-timeout 240 --wait-generated`:

| File | command_id | command_timestamp | exit | ok |
|---|---:|---|---:|---:|
| `by-file/TimerMgr.md` | `000000002768` | `2026-06-30T14:11:22-04:00` | 0 | 1 |
| `by-class/TimerHandler.md` | `000000002770` | `2026-06-30T14:11:40-04:00` | 0 | 1 |
| `by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md` | `000000002772` | `2026-06-30T14:11:55-04:00` | 0 | 1 |
| `by-memory/0x00597580-0x005975c3.TimerHandlerDestructor.md` | `000000002775` | `2026-06-30T14:12:06-04:00` | 0 | 1 |
| `by-memory/0x00597610-0x00597645.TimerHandlerWrappers.md` | `000000002779` | `2026-06-30T14:12:19-04:00` | 0 | 1 |
| `by-class/TimerMgr.md` | `000000002782` | `2026-06-30T14:12:32-04:00` | 0 | 1 |
| `by-memory/0x00598090-0x005980eb.TimerMgrScalarDeletingDestructor.md` | `000000002785` | `2026-06-30T14:12:46-04:00` | 0 | 1 |
| `by-type/by-struct/TimerMgrLayout.md` | `000000002788` | `2026-06-30T14:12:58-04:00` | 0 | 1 |
| `by-class/TimerMgrTimerQueue.md` | `000000002791` | `2026-06-30T14:13:12-04:00` | 0 | 1 |
| `by-memory/0x00597eb0-0x00597f17.TimerQueueReverseRange.md` | `000000002794` | `2026-06-30T14:13:26-04:00` | 0 | 1 |
| `by-memory/0x00597f20-0x00597fc9.TimerQueueRotateRange.md` | `000000002797` | `2026-06-30T14:13:39-04:00` | 0 | 1 |
| `by-type/by-struct/ScheduledTimerEvent.md` | `000000002800` | `2026-06-30T14:13:52-04:00` | 0 | 1 |
| `by-global/g_pTimerMgr.md` | `000000002803` | `2026-06-30T14:14:05-04:00` | 0 | 1 |
| `by-memory/0x0067ab80-0x0067ab84.g_pTimerMgr.md` | `000000002806` | `2026-06-30T14:14:18-04:00` | 0 | 1 |
| `by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md` | `000000002809` | `2026-06-30T14:14:30-04:00` | 0 | 1 |
| `by-memory/0x0069b3ac-0x0069b3d0.TimerMgrStaticObjectStorage.md` | `000000002812` | `2026-06-30T14:14:44-04:00` | 0 | 1 |
| `by-memory/0x0069be0c-0x0069be10.TimerMgrTickBaselineMirror.md` | `000000002815` | `2026-06-30T14:14:59-04:00` | 0 | 1 |
| `by-memory/0x0069be10-0x0069be14.TimerMgrCurrentTickMirror.md` | `000000002818` | `2026-06-30T14:15:11-04:00` | 0 | 1 |

Validator-owned side effects observed in the scoped run: generated metadata/projected stats/research tracker and `validator.ini` registry refreshes were performed by validator/autogen. B009 did not manually edit generated files, generated reports, coverage reports, validator/tool state, IDA DB, executed archives, supervisor ledgers, lock files, unrelated NewHumanImageLib pages, unrelated VectorGrow pages, or `by-file/VectorHelpers.md`.

Generated freshness proof:

- `auto-generated/NexusTK/util/TimerMgr.cpp` header after validation: `validator-command-id: 000000002880`, `validator-refreshed-at: 2026-06-30T14:17:47-04:00`, `validator-refresh-source: foreground-generated-refresh`.
- Generated source route remained `Source by-file UID: 0000OT` and `Source by-file doc: by-file/TimerMgr.md`.
- The refreshed file preserves existing filled emitters including UID0001K8, UID0002KX, UID0002KY, UID0002KZ, UID0002L3, UID0002L5, UID0002L6, and UID0002L7.
- The refreshed file includes the accepted UID0001K7 destructor, UID0001K9 wrappers, class/source-family markers, UID0002L0 `ReverseRange`, UID0002L1 `RotateRange`, UID0001VX struct, UID0000SI global, and UID000306/UID000307 tick globals.
- `TimerMgrTimerQueue::InsertTimer` still calls `RotateRange`; `rg` found no empty-emitter markers for UID0000F0, UID0001K7, UID0001K9, UID0000F1, UID0002L4, UID0001WD, UID0000F2, UID0002L0, UID0002L1, UID0001VX, UID0000SI, UID0002VW, UID0001K6, UID00029S, UID000306, or UID000307.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Callback verification state/proof |
|---|---|---:|---|---|---|---|
| C-0000OT-001 | `by-file/TimerMgr.md` remains canonical file owner for `NexusTK/util/TimerMgr.cpp`. | High | queue row, generated header, current target metadata | `by-file/TimerMgr.md` owner/score/source-quality note | incorporate | applied: metadata/source route preserved; generated header remains `Source by-file UID: 0000OT`. |
| C-0000OT-002 | Pre-callback generated TimerMgr output had 24 emitters, 8 filled, 16 empty. | High | generated file read-only header and empty marker inventory | `by-file/TimerMgr.md` generated-output inventory | applied: target page records the empty-emitter family; refreshed generated file has no markers for the 16 accepted UIDs. |
| C-0000OT-003 | UID0000OT target score should rise from 90/86 to 92/90 after this pass. | Medium-high | 16 blank emitters get C++/markers; queue helper and initializer blockers now have implementation-ready edits | `by-file/TimerMgr.md` metadata/score rationale | applied: `by-file/TimerMgr.md` metadata is `COMPLETION:92`, `CONFIDENCE:90`; validator `000000002768` ok. |
| C-0000OT-004 | Stale `00041*` NewHumanImageLib/VectorGrow links in TimerMgr prose are current-doc pollution and must be corrected or historicalized in inbound TimerMgr/TimerHandler docs. | High | current docs pointed TimerMgr helper roles at wrong paths; current TimerMgr helper paths exist | `by-file/TimerMgr.md`, `by-class/TimerHandler.md`, UID0001K8 stale-link sections | applied: active route text now uses current TimerMgr/TimerHandler paths and marks older UID display text as stale UID-collision history. |
| C-0000OT-005 | The final TimerHandler-vs-TimerMgr disk source split remains unproven but no longer blocks the current file route. | Medium-high | generated route and current docs use `NexusTK/util/TimerMgr.cpp`; no PDB/source-path string proves separate `TimerHandler.cpp` | `by-file/TimerMgr.md`, `by-class/TimerHandler.md` source-placement rationale | applied: both docs retain the split caveat while emitting through UID0000OT; generated header confirms TimerMgr.cpp route. |
| C-0000F0-001 | TimerHandler class page should emit marker plus `[[CHILDREN]]`, not a partial class declaration. | High | class support role, child method ownership, generated child preservation requirement | `by-class/TimerHandler.md` formal C++ block | applied: marker plus `[[CHILDREN]]` inserted; validator `000000002770` ok; generated file shows marker comment. |
| C-0000F0-002 | The pure callback body should be described as raw TimerHandler range `0x005975d0-0x005975d5`, not linked to the current NewHumanImageLib UID-collision page. | High | current stale link; range evidence preserved | `by-class/TimerHandler.md` child table/evidence/change history | applied: active callback contract/cross-reference text uses `by-memory/0x005975d0-0x005975d5.TimerHandlerOnTimerPureVirtualBody.md` and historicalizes older [UID:000418] display text. |
| C-0001K8-001 | UID0001K8 C++ is already present and should be preserved. | High | wrapper page emits `ScheduleTimer` and `RemovePendingTimers` C++ | UID0001K8 formal C++ block | already-present: formal wrapper C++ preserved; validator `000000002772` ok; generated file keeps both methods. |
| C-0001K8-002 | UID0001K8 stale callee links should point to current TimerMgr helper paths `0x00597910` and `0x00597a10`, not NewHumanImageLib/VectorGrow pages. | High | wrapper prose had wrong links; current helper docs exist | UID0001K8 evidence/prose sections | applied: evidence now names `TimerMgrScheduleTimer.md` and `TimerMgrRemovePendingTimersForOwner.md`; old UID display names historicalized. |
| C-0001K7-001 | `TimerHandler::~TimerHandler()` removes pending timers for this handler through `g_pTimerMgr`. | High | MCP decompile `0x00597580`, xrefs, support doc | `by-memory/0x00597580-0x005975c3.TimerHandlerDestructor.md` formal C++/evidence | applied: destructor C++ inserted; validator `000000002775` ok; generated file includes `g_pTimerMgr->RemovePendingTimersForOwner(this);`. |
| C-0001K9-001 | `0x00597610` is a TimerHandler cancel wrapper around TimerMgr single-timer removal. | High | MCP decompile `0x00597610`, 47 xrefs | `by-memory/0x00597610-0x00597645.TimerHandlerWrappers.md` formal C++/evidence | applied: `CancelTimer` wrapper inserted; validator `000000002779` ok; generated file includes the call. |
| C-0001K9-002 | `0x00597630` is a TimerHandler cancel-all-except wrapper around TimerMgr removal helper. | High | MCP decompile `0x00597630`, 1 xref | `by-memory/0x00597610-0x00597645.TimerHandlerWrappers.md` formal C++/evidence | applied: `CancelPendingTimersExceptEvent` wrapper inserted; validator `000000002779` ok. |
| C-0000F1-001 | TimerMgr class page should emit marker plus `[[CHILDREN]]`, not a partial class declaration. | High | file-owned class route and exact method/support pages | `by-class/TimerMgr.md` formal C++ block | applied: marker plus `[[CHILDREN]]` inserted; validator `000000002782` ok; generated file shows marker comment. |
| C-0000F1-002 | `ScheduleTimer`, `RemovePendingTimersForOwner`, `CancelTimer`, and `CancelPendingTimersExceptEvent` are the best current source-facing TimerMgr helper names. | Medium-high | helper filenames, wrapper routes, predicates | `by-class/TimerMgr.md`, UID0001K8/UID0001K9 evidence sections | applied: active helper names and current paths are present in class/wrapper pages. |
| C-0002L4-001 | TimerMgr scalar deleting destructor is compiler-generated wrapper, not standalone handwritten source. | High | MCP decompile `0x00598090`; vtable-only xref `0x0062e344` | `by-memory/0x00598090-0x005980eb.TimerMgrScalarDeletingDestructor.md` marker/evidence | applied: compiler-wrapper marker inserted; validator `000000002785` ok; generated file shows marker comment only. |
| C-0001WD-001 | TimerMgrLayout documents class offsets and should not emit a duplicate standalone struct. | High | layout support doc, TimerMgr class ownership | `by-type/by-struct/TimerMgrLayout.md` formal marker | applied: layout marker inserted; validator `000000002788` ok; generated file shows marker comment only. |
| C-0000F2-001 | TimerMgrTimerQueue class page should emit marker plus `[[CHILDREN]]`, not a partial class declaration. | High | class support role, queue children own methods | `by-class/TimerMgrTimerQueue.md` formal C++ block | applied: marker plus `[[CHILDREN]]` inserted; validator `000000002791` ok; generated file shows marker comment. |
| C-0002L0-001 | TimerQueue reverse range should emit file-local static `ReverseRange`, not a public method and not marker-only. | High | MCP decompile `0x00597eb0`; no `ecx`; rotate-only xrefs | `by-memory/0x00597eb0-0x00597f17.TimerQueueReverseRange.md` formal C++/evidence | applied: static `ReverseRange` body inserted; validator `000000002794` ok; generated file includes the body. |
| C-0002L1-001 | TimerQueue rotate range should emit file-local static `RotateRange`, not a public method and not marker-only. | High | MCP decompile `0x00597f20`; reverse calls; existing `InsertTimer` calls `RotateRange` | `by-memory/0x00597f20-0x00597fc9.TimerQueueRotateRange.md` formal C++/evidence | applied: static `RotateRange` body inserted; validator `000000002797` ok; generated `InsertTimer` still calls it. |
| C-0001VX-001 | `ScheduledTimerEvent` is a five-dword, 0x14-byte source record with owner/timer/due/arg fields. | High | queue helper decompiles, struct doc, 0x14 record copies | `by-type/by-struct/ScheduledTimerEvent.md` formal struct declaration/naming rationale | applied: five-field struct inserted; validator `000000002800` ok; generated file includes struct. |
| C-0000SI-001 | `g_pTimerMgr` is a real TimerMgr pointer global and currently initializes to zero. | High | MCP bytes `0x0067ab80 == 00 00 00 00`, 125 xrefs | `by-global/g_pTimerMgr.md` formal global/evidence | applied: `TimerMgr* g_pTimerMgr = 0;` inserted; validator `000000002803` ok; generated file includes definition. |
| C-0000SI-002 | Older `0xffffffff` initializer prose is stale for current IDB image bytes and must be historicalized. | High | current MCP bytes zero; affected docs reported stale values | `by-global/g_pTimerMgr.md`, UID0002VW, UID00029S, UID000306, UID000307 evidence sections | applied: zero-byte reconciliation added to global/storage/tick docs; runtime sentinel wording preserved separately. |
| C-0002VW-001 | `0x0067ab80-0x0067ab84` should not duplicate the `g_pTimerMgr` definition. | High | by-global owner plus exact storage range evidence | `by-memory/0x0067ab80-0x0067ab84.g_pTimerMgr.md` marker/evidence | applied: no-duplicate marker inserted and data row updated to zero; validator `000000002806` ok. |
| C-0001K6-001 | TimerMgrAndTimerQueue range is a source-family aggregate and should not emit a monolithic body. | High | B002/B014/B015 leads plus current MCP/generator inventory | `by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md` marker/evidence | applied: aggregate marker inserted and active stale child-path prose corrected; validator `000000002809` ok. |
| C-00029S-001 | TimerMgr static object storage is process-lifetime storage generated by the file's static instance declaration and currently 36 zero bytes. | Medium-high | MCP bytes at `0x0069b3ac`, storage xrefs, support doc | `by-memory/0x0069b3ac-0x0069b3d0.TimerMgrStaticObjectStorage.md` marker/evidence/initializer reconciliation | applied: storage marker inserted and 36 zero bytes documented; validator `000000002812` ok. |
| C-000306-001 | `0x0069be0c` is a zero-initialized tick baseline mirror global. | High | MCP value zero, timer setup refs | `by-memory/0x0069be0c-0x0069be10.TimerMgrTickBaselineMirror.md` formal global/evidence | applied: zero-initialized global inserted; validator `000000002815` ok; generated file includes definition. |
| C-000307-001 | `0x0069be10` is a zero-initialized current tick mirror global. | High | MCP value zero, timer refresh refs | `by-memory/0x0069be10-0x0069be14.TimerMgrCurrentTickMirror.md` formal global/evidence | applied: zero-initialized global inserted; validator `000000002818` ok; generated file includes definition. |
| C-0000OT-006 | Existing filled emitters must be preserved when class marker pages add `[[CHILDREN]]`. | High | generated output included 8 filled emitters | class pages and generated-output verification | applied: refreshed generated file preserves existing filled UIDs including UID0001K8 and UID0002KX/KY/KZ/L3/L5/L6/L7. |
| C-0000OT-007 | `by-memory/0x00598480-0x005986d9.TimerMgrTimerQueueInsertTimer.md` already uses `RotateRange`; no content edit is required if re-read confirms current same-or-greater detail. | High | support page formal C++ and generated output call `RotateRange` | InsertTimer support page or callback proof | already-present: read-only proof confirmed; refreshed generated file still calls `RotateRange`. |
| C-0000OT-008 | NewHumanImageLib/VectorGrow target pages and `by-file/VectorHelpers.md` should not be edited for this TimerMgr callback. | High | correction is inbound TimerMgr prose; MCP proves queue-local helper ownership | callback scope/exclusions and support-doc plan | excluded-with-reason: intentionally not edited because they are unrelated targets or rejected ownership destinations. |
| C-0000OT-009 | No manual generated/coverage/tool-state edit is allowed or needed. | High | assignment constraints and workflow | implementation callback checkpoint | already-present: no manual generated/coverage/tool-state edits; validator performed its own refreshes. |

## Score-Blocker Audit

No `PAUSED_MCP_*` blocker exists. The report used current MCP evidence before acceptance, and implementation did not require fallback-only evidence.

All in-scope callback blockers were resolved:

- Final `TimerHandler.cpp` versus `TimerMgr.cpp` disk split is documented as an unproven source-placement caveat, not a blocker to current UID0000OT emission.
- UID0002L0/UID0002L1 now have formal file-local static C++ bodies, not marker-only pages and not public queue methods.
- Stale UID/path pollution is corrected or historicalized in inbound TimerMgr/TimerHandler docs; unrelated NewHumanImageLib/VectorGrow pages remain untouched.
- Current zero-byte initializer evidence is incorporated into `g_pTimerMgr`, exact storage, static storage, and tick mirror pages; runtime `0xffffffff` sentinel behavior remains separate.
- Source-facing names were applied consistently for `RemovePendingTimersForOwner`, `CancelTimer`, `CancelPendingTimersExceptEvent`, `ScheduledTimerEvent` fields, tick mirror globals, and queue range helpers.

## Implementation Tracking Checklist

Callback status: checked items are complete with proof from the applied docs, validator table, generated refresh, and ledger above.

- [x] Re-read and updated `by-file/TimerMgr.md`: metadata is `92/90`, owner/path preserved, source-quality note added, stale NewHumanImageLib/VectorGrow inbound text historicalized, current zero-initializer reconciliation added; validator `000000002768` ok.
- [x] Re-read and updated `by-class/TimerHandler.md`: score is `89/91`, marker plus `[[CHILDREN]]` inserted, current TimerHandler callback range/path used, stale UID display text historicalized; validator `000000002770` ok.
- [x] Re-read and updated `by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md`: score is `87/89`, existing C++ preserved, stale callees corrected to current TimerMgr helper paths; validator `000000002772` ok.
- [x] Re-read and updated `by-memory/0x00597580-0x005975c3.TimerHandlerDestructor.md`: score is `89/91`, destructor C++ inserted; validator `000000002775` ok.
- [x] Re-read and updated `by-memory/0x00597610-0x00597645.TimerHandlerWrappers.md`: score is `89/91`, `CancelTimer` and `CancelPendingTimersExceptEvent` C++ inserted; validator `000000002779` ok.
- [x] Re-read and updated `by-class/TimerMgr.md`: score is `89/90`, marker plus `[[CHILDREN]]` inserted, helper names/paths normalized; validator `000000002782` ok.
- [x] Re-read and updated `by-memory/0x00598090-0x005980eb.TimerMgrScalarDeletingDestructor.md`: score is `88/93`, compiler-wrapper marker inserted; validator `000000002785` ok.
- [x] Re-read and updated `by-type/by-struct/TimerMgrLayout.md`: score is `87/90`, layout-support marker inserted; validator `000000002788` ok.
- [x] Re-read and updated `by-class/TimerMgrTimerQueue.md`: score is `89/91`, marker plus `[[CHILDREN]]` inserted, file-local range-helper route documented; validator `000000002791` ok.
- [x] Re-read and updated `by-memory/0x00597eb0-0x00597f17.TimerQueueReverseRange.md`: score is `89/92`, static `ReverseRange` C++ inserted; validator `000000002794` ok.
- [x] Re-read and updated `by-memory/0x00597f20-0x00597fc9.TimerQueueRotateRange.md`: score is `89/92`, static `RotateRange` C++ inserted; validator `000000002797` ok.
- [x] Re-read and updated `by-type/by-struct/ScheduledTimerEvent.md`: score is `88/92`, five-field struct inserted; validator `000000002800` ok.
- [x] Re-read and updated `by-global/g_pTimerMgr.md`: score is `88/92`, `TimerMgr* g_pTimerMgr = 0;` inserted, stale `0xffffffff` initializer historicalized; validator `000000002803` ok.
- [x] Re-read and updated `by-memory/0x0067ab80-0x0067ab84.g_pTimerMgr.md`: score is `89/93`, no-duplicate marker inserted, data bytes reconciled to `00 00 00 00`; validator `000000002806` ok.
- [x] Re-read and updated `by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md`: score is `88/90`, aggregate/source-family marker inserted, stale active child-path prose corrected; validator `000000002809` ok.
- [x] Re-read and updated `by-memory/0x0069b3ac-0x0069b3d0.TimerMgrStaticObjectStorage.md`: score is `89/92`, storage marker inserted, 36 zero bytes reconciled against old all-`ff` prose; validator `000000002812` ok.
- [x] Re-read and updated `by-memory/0x0069be0c-0x0069be10.TimerMgrTickBaselineMirror.md`: score is `88/91`, zero-initialized tick baseline global inserted; validator `000000002815` ok.
- [x] Re-read and updated `by-memory/0x0069be10-0x0069be14.TimerMgrCurrentTickMirror.md`: score is `88/91`, zero-initialized current tick global inserted; validator `000000002818` ok.
- [x] Re-read `by-memory/0x00598480-0x005986d9.TimerMgrTimerQueueInsertTimer.md` as support evidence: no edit required; generated file still calls `RotateRange`.
- [x] Re-read `by-memory/0x00597910-0x00597a0c.TimerMgrScheduleTimer.md` and `by-memory/0x00597a10-0x00597b73.TimerMgrRemovePendingTimersForOwner.md` as current link destinations; no edits required.
- [x] Excluded NewHumanImageLib pages, VectorGrow pages, `by-file/VectorHelpers.md`, generated files, coverage reports, validator/tool state manual edits, IDA DB, executed archives, supervisor ledgers, and lock files.
- [x] Ran scoped validators for every changed by-* file with `--wait-generated`; command ids/timestamps/exits/ok counts are recorded in the callback proof table.
- [x] Inspected refreshed `auto-generated/NexusTK/util/TimerMgr.cpp`: generated header is command `000000002880`, refreshed `2026-06-30T14:17:47-04:00`, source UID remains `0000OT`, `InsertTimer` still calls `RotateRange`, existing filled emitters remain, and the 16 accepted empty markers are gone.
- [x] Updated this report's Claim And Incorporation Ledger to `applied`, `already-present`, and `excluded-with-reason` states with proof.
- [x] Updated this checklist with checked states and validator/generator proof.

## Callback Validation State

Scoped validators for all changed by-* files passed with exit `0` and `ok: 1`.

Generated TimerMgr.cpp is current and refreshed after the final scoped validator command.

No accepted item is blocked. No implementation item is intentionally deferred except excluded unrelated target pages and `by-file/VectorHelpers.md`, with reasons recorded above.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/0000OT-TimerMgr-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/0000OT-TimerMgr-empty-emitter-family-source-quality.md","timestamp":"2026-06-30T14:25:32","uid":"0000OT"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
