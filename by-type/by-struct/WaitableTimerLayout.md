*** UID:0001WI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000FY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000FY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# WaitableTimer Layout

## Status

- Entity kind: class/object layout.
- Owner class: [UID:0000FY][WaitableTimer](by-class/WaitableTimer.md).
- Owner module: [UID:0000P7][WaitableTimer](by-file/WaitableTimer.md).
- Rebuild handling: source-declared class layout; exact binary vtable/RTTI bytes are compiler-emitted.
- Size evidence: `0x2c` / 44 bytes (Verified with int_convert.py), matching the scalar deleting destructor object-size path.
- Confidence: strong for offsets, lifecycle transitions, and class ownership; medium-high for exact original field spellings.

## Current MCP Evidence

- The accepted 2026-08-04 B005 report used sole healthy read-only session `b002-uid0004hs-persist-reopen`, PID `20412`, and canonical IDB disk snapshot SHA-256 `CE0222E87E1A569A73EB43DD72BF53412B103DD9281A535EEC2BCC01DE0932FA` (`143196420` bytes). This is dated layout evidence, not a permanent current-session assertion.
- B005 2026-06-23 accepted report uses IDA MCP session `ff68e691`, PE SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- `lookup_funcs` confirms modeled WaitableTimer bodies at `0x005c0ff0`, `0x005c10a0`, `0x005c11c0`, and `0x005c1210`; raw helper starts `0x005c1120` and `0x005c1170` remain not functions.
- Constructor decompilation stores the vtable, calls `g_pfnCreateEventW` / `dword_69BE3C`, writes `+0x04`, initializes `+0x08`, clears `+0x20/+0x24/+0x28`, and throws on failed event creation.
- Raw start disassembly sets `+0x20`, creates `+0x28`, registers callback `0x005c11c0`, stores `+0x24`, loops until nonzero id, and signals `+0x28`.
- Raw cancel disassembly enters `+0x08`, clears `+0x20`, kills `+0x24`, closes `+0x28`, resets `+0x04`, clears `+0x24/+0x28`, and leaves the critical section.
- Callback decompilation waits on `+0x28` with `0xffffffff`, closes/clears it, clears `+0x24`, signals `+0x04`, and leaves `+0x08`.
- Scalar deleting destructor decompilation repeats destructive cleanup and optionally frees the object.
- `xrefs_to 0x00631188` confirms vtable stores at `0x005c1020`, `0x005c10a8`, and `0x005c121b`.
- The fresh report-time inventory counted 31 raw start, 20 raw cancel, and 24 callback instructions; both raw starts had zero inbound xrefs and zero VA/RVA/raw-offset pointer patterns. Those negatives affect liveness, not the exact field map.

## Layout

| Offset | Size | Proposed field | Evidence |
| --- | ---: | --- | --- |
| `+0x00` | `4` | `vftable` | Constructor, cleanup body, and scalar deleting destructor store `0x00631188`. |
| `+0x04` | `4` | `m_completionEvent` / historical `m_hCompletionEvent` | Constructor creates it through `g_pfnCreateEventW`; cleanup/cancel/destructor call `ResetEvent`; callback calls `SetEvent`; destructive cleanup closes it. |
| `+0x08` | `0x18` | `m_criticalSection` | Constructor initializes it; cancel/callback/destructor paths enter/leave it; destructive cleanup deletes it. |
| `+0x20` | `1` | `m_isRunning` | Constructor clears it; raw start helper sets it; cleanup/cancel/callback/destructor paths clear it. |
| `+0x21` | `3` | padding | Implied alignment before dword field `+0x24`. |
| `+0x24` | `4` | `m_timerId` | Raw start stores the `timeSetEvent` result; cleanup/cancel/destructor call `timeKillEvent`; callback and reset paths clear it. |
| `+0x28` | `4` | `m_callbackGateEvent` | Raw start creates it through `g_pfnCreateEventW`, stores it, and signals it after timer registration; callback waits/closes it; cancel/destructor close it. |

## Lifecycle Matrix

| Path | Layout effects |
| --- | --- |
| Constructor `0x005c0ff0` | Stores vtable at `+0x00`, creates completion event into `+0x04`, initializes `+0x08`, clears `+0x20/+0x24/+0x28`, and throws a `Win32Error`-style object on event-creation failure. |
| Cleanup body `0x005c10a0` | Re-stores vtable, enters `+0x08`, clears `+0x20`, kills `+0x24`, closes/clears `+0x28`, resets `+0x04`, leaves/deletes `+0x08`, closes `+0x04`, and closes residual gate if present. |
| Raw start helper `0x005c1120-0x005c116a` | Sets `+0x20`, creates `+0x28`, registers callback `0x005c11c0` through `timeSetEvent(delay, 5, callback, this, 0)`, stores nonzero id at `+0x24`, then signals `+0x28`. |
| Raw cancel helper `0x005c1170-0x005c11b5` | Enters `+0x08`, clears `+0x20`, kills `+0x24`, closes `+0x28`, resets `+0x04`, clears `+0x24/+0x28`, and leaves `+0x08` without deleting reusable object state. |
| Callback `0x005c11c0` | Treats callback argument three as `this`, clears `+0x20`, enters `+0x08`, waits forever on `+0x28`, closes/clears `+0x28`, clears `+0x24`, signals `+0x04`, and leaves `+0x08`. |
| Scalar deleting destructor `0x005c1210` | Mirrors destructive cleanup for `+0x20/+0x24/+0x28/+0x04/+0x08`, then optionally frees the object. |

## Correction Notes

Generated metadata currently calls `+0x28` `m_hWorkerThread`. Current MCP evidence rejects that name. The field is created by `g_pfnCreateEventW` / `CreateEventW`, signaled after successful `timeSetEvent`, waited by the callback as a startup gate, and closed as an event handle. Use `m_callbackGateEvent` in source-facing docs and code.

`WaitableTimer` is a multimedia timer wrapper with event synchronization. It is not a Win32 `CreateWaitableTimer` object, and the field at `+0x28` is not a thread handle.

The raw cancel path has no inactive-state guard. The exact field lifecycle therefore includes unconditional `timeKillEvent(m_timerId)`, `CloseHandle(m_callbackGateEvent)`, and `ResetEvent(m_completionEvent)` before transient fields are cleared. Do not encode a speculative guard in source or layout semantics.

[UID:0001NY][0x005c1120-0x005c11b5.WaitableTimerRawStartStop](by-memory/0x005c1120-0x005c11b5.WaitableTimerRawStartStop.md) is a reviewed non-reconstructable split inventory, not a third method container. Its exact start/cancel children provide the source-bearing lifecycle evidence used here.

## Parent And Score Rationale

Attach this layout to [UID:0000FY][WaitableTimer](by-class/WaitableTimer.md). The class is the narrow semantic owner of the object fields and routes to [UID:0000P7][WaitableTimer](by-file/WaitableTimer.md) as the source root.

Completion is `92` and confidence `94`: the complete `0x2c` field map, sizes, padding, constructor/start/cancel/callback/destructor lifecycle, one-slot vtable, split disposition, and corrected event semantics are MCP-backed. Exact original field spellings and access visibility remain inferred, which prevents final certainty but does not leave a source-quality blocker unresolved.

Keep reconstructed C++ blank on this layout page. Method bodies belong to exact by-memory pages, and class declaration spelling should wait for a broader class/header pass.

## Source-Name And Historical Resolution

- Accepted source fields are `m_completionEvent`, `m_criticalSection`, `m_isRunning`, `m_timerId`, and `m_callbackGateEvent`. These names are inferred from exact behavior and project style rather than original symbols.
- Historical/generated `m_hWorkerThread` is disproved by CreateEventW creation plus SetEvent/WaitForSingleObject/CloseHandle use.
- Wave2/Wave3 evidence is ignored. The current layout is grounded in direct bytes, member accesses, callback flow, and the class/vtable relationship.
- The class remains routed through `NexusTK/util/WaitableTimer.cpp`; no TimerMgr or PlatformApi layout ownership is supported.

## Cross-References

- [UID:0000FY][WaitableTimer](by-class/WaitableTimer.md)
- [UID:0000P7][WaitableTimer](by-file/WaitableTimer.md)
- [UID:0001NX][0x005c0ff0-0x005c129a.WaitableTimer](by-memory/0x005c0ff0-0x005c129a.WaitableTimer.md)
- [UID:0001NY][0x005c1120-0x005c11b5.WaitableTimerRawStartStop](by-memory/0x005c1120-0x005c11b5.WaitableTimerRawStartStop.md)
- [UID:0002L8][0x005c1120-0x005c116a.WaitableTimerStartMultimediaTimer](by-memory/0x005c1120-0x005c116a.WaitableTimerStartMultimediaTimer.md)
- [UID:0002L9][0x005c1170-0x005c11b5.WaitableTimerCancelMultimediaTimer](by-memory/0x005c1170-0x005c11b5.WaitableTimerCancelMultimediaTimer.md)
- [UID:0001Z2][WaitableTimerVtable](by-type/by-vtable/WaitableTimerVtable.md)
- [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md)

## Changes

- 2026-08-04 B005 UID0001NY Rule 26 support implementation:
  - Raised from `86/89` to `92/94` and linked the exact 0x2c lifecycle to UID0001NY's resolved split-only classification.
  - Added current report-time provenance, raw-start liveness results, no-guard cancel semantics, source-name decisions, owner/source route, historical corrections, and updated score rationale.
- 2026-06-23 B005 implementation:
  - Added current MCP session `ff68e691` evidence and explicit class-route support.
  - Preserved the `+0x28` callback-gate event correction and recorded `+0x21` padding / `0x2c` size conversions with int_convert provenance.
