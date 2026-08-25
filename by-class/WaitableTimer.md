*** UID:0000FY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000P7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000P7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# WaitableTimer

## Summary

`WaitableTimer` is a Win32 multimedia timer/event wrapper class in the `NexusTK/util/WaitableTimer.cpp` source-root module. It owns a persistent completion event, an embedded critical section, a running flag, a multimedia timer id, and a short-lived callback gate event used to synchronize `timeSetEvent` registration with the callback.

This class is the direct semantic owner for the WaitableTimer executable island [UID:0001NX][0x005c0ff0-0x005c129a.WaitableTimer](by-memory/0x005c0ff0-0x005c129a.WaitableTimer.md), reviewed non-emitting split inventory [UID:0001NY][0x005c1120-0x005c11b5.WaitableTimerRawStartStop](by-memory/0x005c1120-0x005c11b5.WaitableTimerRawStartStop.md), and exact source-bearing helper methods [UID:0002L8][0x005c1120-0x005c116a.WaitableTimerStartMultimediaTimer](by-memory/0x005c1120-0x005c116a.WaitableTimerStartMultimediaTimer.md) / [UID:0002L9][0x005c1170-0x005c11b5.WaitableTimerCancelMultimediaTimer](by-memory/0x005c1170-0x005c11b5.WaitableTimerCancelMultimediaTimer.md). UID0001NY is not a third source definition: its children exhaust the two method bodies and the only remaining in-range bytes are the six-byte alignment fence.

## Source Placement

- Source file root: [UID:0000P7][WaitableTimer](by-file/WaitableTimer.md).
- Proposed path: `NexusTK/util/WaitableTimer.cpp` and likely `NexusTK/util/WaitableTimer.h`.
- Ownership rule: the class is the narrow owner for class layout, vtable, methods, callback, and raw helper bodies; the file page remains the generated source-root route.
- Rejected direct owners: [UID:0000OT][TimerMgr](by-file/TimerMgr.md), PlatformApi / WideApiDispatchTable, UI/Application pages, and no-owner/non-emitting. TimerMgr remains a related timing subsystem, but no direct caller/lifetime evidence proves a merge.

## Layout

See [UID:0001WI][WaitableTimerLayout](by-type/by-struct/WaitableTimerLayout.md). Current field names are source-facing inferences from behavior:

| Offset | Proposed field | Evidence summary |
| --- | --- | --- |
| `+0x00` | `vftable` | Constructor, cleanup body, and scalar deleting destructor store `0x00631188`. |
| `+0x04` | `m_completionEvent` / historical `m_hCompletionEvent` | Created by `g_pfnCreateEventW`; reset by cancel/destructor paths; set by callback; closed by destructive cleanup. |
| `+0x08` | `m_criticalSection` | Initialized by constructor; entered/left by cancel/callback/destructor paths; deleted by destructive cleanup. |
| `+0x20` | `m_isRunning` | Cleared by constructor/cancel/callback/destructors; set by the raw start helper. |
| `+0x21` | padding | Three bytes implied before dword alignment at `+0x24`. |
| `+0x24` | `m_timerId` | Stores `timeSetEvent` result; killed with `timeKillEvent`; cleared by callback/cancel/destructor paths. |
| `+0x28` | `m_callbackGateEvent` | Created through `g_pfnCreateEventW`, signaled after successful timer registration, waited/closed by callback, closed by cancel/destructor paths. Generated `m_hWorkerThread` is rejected. |

## Method And Helper Inventory

| Range | Current source-facing role | Status |
| --- | --- | --- |
| `0x005c0ff0-0x005c109c` | `WaitableTimer::WaitableTimer()` | Constructor body. Future exact child split recommended before C++ emission. |
| `0x005c10a0-0x005c1111` | `WaitableTimer::~WaitableTimer()` / non-deleting cleanup body | Future exact child split recommended before C++ emission. Generated `WaitableTimer::Cleanup` remains a search alias, not final proof. |
| [UID:0002L8][0x005c1120-0x005c116a.WaitableTimerStartMultimediaTimer](by-memory/0x005c1120-0x005c116a.WaitableTimerStartMultimediaTimer.md) | `WaitableTimer::StartMultimediaTimer(UINT delayMilliseconds)` | Raw no-function helper; first-draft C++ now emitted from the exact child. |
| [UID:0002L9][0x005c1170-0x005c11b5.WaitableTimerCancelMultimediaTimer](by-memory/0x005c1170-0x005c11b5.WaitableTimerCancelMultimediaTimer.md) | `WaitableTimer::CancelMultimediaTimer()` | Raw no-function helper; first-draft C++ now emitted from the exact child. |
| `0x005c11c0-0x005c120e` | `WaitableTimerCallback` | `timeSetEvent` callback. Future exact child split recommended before C++ emission. |
| `0x005c1210-0x005c129a` | scalar deleting destructor | Compiler-generated from the class destructor shape; future exact child should carry no-code proof. |

## Current MCP Evidence

- The accepted 2026-08-04 B005 report used sole healthy read-only session `b002-uid0004hs-persist-reopen`, PID `20412`, and canonical IDB disk snapshot SHA-256 `CE0222E87E1A569A73EB43DD72BF53412B103DD9281A535EEC2BCC01DE0932FA` (`143196420` bytes). The identity is dated evidence; the supervisor-owned IDA gate must reread current authority.
- B005 accepted report evidence uses IDA MCP session `ff68e691`, PE SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- `lookup_funcs` reports modeled functions at `0x005c0ff0` (`0xac` / 172 bytes), `0x005c10a0` (`0x71` / 113 bytes), `0x005c11c0` (`0x4e` / 78 bytes), and `0x005c1210` (`0x8a` / 138 bytes), with raw not-function starts at `0x005c1120` and `0x005c1170`.
- Raw helper byte checks confirm `0x005c1120-0x005c116a` and `0x005c1170-0x005c11b5`, with `0xcc` padding at `0x005c116a-0x005c1170` and `0x005c11b5-0x005c11c0`.
- Xref checks find no direct xrefs to constructor or raw helper starts, one callback data xref `0x005c1149 -> 0x005c11c0`, one scalar deleting destructor data xref from `0x00631188`, and vtable stores at `0x005c1020`, `0x005c10a8`, and `0x005c121b`.
- Targeted VA/RVA pointer searches found no raw-helper start pointers for `0x005c1120` or `0x005c1170`. The only callback pointer hit was the expected immediate at `0x005c114a`.
- `0x0069be3c` / `g_pfnCreateEventW` is initialized by [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md) at `0x0041a30c`; it is consumed by the constructor and raw start helper.
- The report-time inventory counted 31 start instructions, 20 cancel instructions, 24 callback instructions, zero inbound xrefs and zero VA/RVA/raw-offset pointer patterns for both raw starts, and 12 xrefs to the CreateEventW dispatch slot.

## Vtable

IDA confirms a one-slot table `??_7WaitableTimer@@6B@` at `0x00631188`, with complete-object-locator pointer at `0x00631184` and scalar deleting destructor slot `0x005c1210`. The dword at `0x0063118c` is the `WeatherLayerPane` complete-object-locator pointer, not a second `WaitableTimer` slot.

See [UID:0001Z2][WaitableTimerVtable](by-type/by-vtable/WaitableTimerVtable.md) and [UID:0002P2][0x00631184-0x0063118c.WaitableTimerVtableData](by-memory/0x00631184-0x0063118c.WaitableTimerVtableData.md).

## C++ And Emission Notes

- The class page remains blank; method bodies belong on exact by-memory ranges.
- [UID:0001NX][0x005c0ff0-0x005c129a.WaitableTimer](by-memory/0x005c0ff0-0x005c129a.WaitableTimer.md) remains a no-code aggregate because it spans multiple functions/helpers/padding and a compiler scalar deleting destructor.
- [UID:0001NY][0x005c1120-0x005c11b5.WaitableTimerRawStartStop](by-memory/0x005c1120-0x005c11b5.WaitableTimerRawStartStop.md) is a reviewed `RECONSTRUCTABLE:FALSE`, emitter-blank split inventory. It receives no filler or covered-by source because it has no independent source-level definition.
- [UID:0002L8][0x005c1120-0x005c116a.WaitableTimerStartMultimediaTimer](by-memory/0x005c1120-0x005c116a.WaitableTimerStartMultimediaTimer.md) and [UID:0002L9][0x005c1170-0x005c11b5.WaitableTimerCancelMultimediaTimer](by-memory/0x005c1170-0x005c11b5.WaitableTimerCancelMultimediaTimer.md) now contain first-draft C++ using inferred source-facing names. [UID:0002L9][0x005c1170-0x005c11b5.WaitableTimerCancelMultimediaTimer](by-memory/0x005c1170-0x005c11b5.WaitableTimerCancelMultimediaTimer.md) intentionally has no `if (m_timerId != 0)` guard because the raw body has no branch before `timeKillEvent`, `CloseHandle`, and `ResetEvent`.

The exact child H channels remain blank because their member declarations belong once in the eventual complete class header. The class page also stays blank until that complete constructor/destructor/callback declaration surface can be emitted coherently; child method CPP remains valid independently.

## Source Quality And Score Rationale

- Completion/confidence `92/92` reflects the exact 0x2c state layout, one-slot vtable, complete class-island inventory, raw start/cancel split, callback synchronization, owner/source route, negative liveness, corrected field names, and precise child-only emission decision.
- `StartMultimediaTimer`, `CancelMultimediaTimer`, `WaitableTimerCallback`, `m_completionEvent`, `m_callbackGateEvent`, and `g_pfnCreateEventW` are accepted behavior-backed human source names. Exact historical spelling/access is unavailable, which caps the score but does not justify raw IDA labels.
- The two raw methods are retained/unreferenced project source, not compiler glue. The scalar deleting destructor is compiler-generated and remains separately identified.
- `NexusTK/util/WaitableTimer.cpp` remains the best file route. No direct caller/lifetime/layout evidence supports merging this class into TimerMgr or PlatformApi.

## Resolved Questions And Remaining Limits

- No live construction/caller route for `WaitableTimer` was found after xref and pointer-pattern checks. This is a completed negative result, not deferred investigation.
- Original public/private visibility and exact method/callback spellings are irrecoverable from the stripped image. Current names are the accepted highest-probability source-facing inferences.
- Constructor exception helper details need a future exact constructor pass before constructor C++ is entered.
- The UID0001NY aggregate question is resolved: it is already a non-emitting split inventory. Exact constructor, cleanup, callback, and scalar-destructor child creation remains outside this report's declared target and does not reopen UID0001NY.
- Historical Wave2/Wave3 evidence and generated `m_hWorkerThread`/raw `sub_` names are rejected for current source reconstruction.

## Cross-References

- File: [UID:0000P7][WaitableTimer](by-file/WaitableTimer.md)
- Aggregate: [UID:0001NX][0x005c0ff0-0x005c129a.WaitableTimer](by-memory/0x005c0ff0-0x005c129a.WaitableTimer.md)
- Raw helper aggregate: [UID:0001NY][0x005c1120-0x005c11b5.WaitableTimerRawStartStop](by-memory/0x005c1120-0x005c11b5.WaitableTimerRawStartStop.md)
- Start helper: [UID:0002L8][0x005c1120-0x005c116a.WaitableTimerStartMultimediaTimer](by-memory/0x005c1120-0x005c116a.WaitableTimerStartMultimediaTimer.md)
- Cancel helper: [UID:0002L9][0x005c1170-0x005c11b5.WaitableTimerCancelMultimediaTimer](by-memory/0x005c1170-0x005c11b5.WaitableTimerCancelMultimediaTimer.md)
- Layout: [UID:0001WI][WaitableTimerLayout](by-type/by-struct/WaitableTimerLayout.md)
- Vtable: [UID:0001Z2][WaitableTimerVtable](by-type/by-vtable/WaitableTimerVtable.md)
- Timing context: [UID:0001QU][client_timing](by-meta/client_timing.md)

## Changes

- 2026-08-04 B005 UID0001NY Rule 26 support implementation:
  - Raised from `87/87` to `92/92` and synchronized the class with UID0001NY's resolved false/non-emitting split disposition and exact child-only emission.
  - Added current report-time MCP provenance, full negative liveness and dispatch counts, retained-source classification, blank-header rationale, naming/source-placement decisions, score rationale, and historical corrections.
- 2026-06-23 B005 implementation:
  - Added current MCP session `ff68e691` evidence, class-direct-owner/source-root routing, source-facing field/helper names, child C++ readiness, exact no-code aggregate rationale, and no-TimerMgr-merge caveat.
  - Replaced old `95/95` and generated-name caveats with current by-structure gate language and explicit generated-name rejections.
