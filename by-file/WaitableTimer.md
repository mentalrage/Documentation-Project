*** UID:0000P7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# WaitableTimer

## Status

- Proposed module: `util/WaitableTimer.cpp`.
- Proposed header: `util/WaitableTimer.h`.
- Role: source root for the `WaitableTimer` class and its exact method/helper pages.
- Direct semantic class owner: [UID:0000FY][WaitableTimer](by-class/WaitableTimer.md).
- Confidence: strong for utility source placement and class island boundaries; medium for final original public/private method spelling and live construction route.

## File Role

`WaitableTimer.cpp` is a small Win32 event plus multimedia timer wrapper module. It owns the `WaitableTimer` class declaration and source bodies that manage:

- persistent completion event `m_completionEvent` at `+0x04`;
- embedded critical section `m_criticalSection` at `+0x08`;
- running flag `m_isRunning` at `+0x20`;
- multimedia timer id `m_timerId` at `+0x24`;
- callback startup gate event `m_callbackGateEvent` at `+0x28`.

The file is utility/platform-adjacent. It should remain separate from [UID:0000OT][TimerMgr](by-file/TimerMgr.md) until direct caller/lifetime evidence proves the original source merged the low-level waitable timer wrapper into the high-level timer scheduler.

## Likely Contents

- [UID:0000FY][WaitableTimer](by-class/WaitableTimer.md)
- [UID:0001NX][0x005c0ff0-0x005c129a.WaitableTimer](by-memory/0x005c0ff0-0x005c129a.WaitableTimer.md)
- [UID:0001NY][0x005c1120-0x005c11b5.WaitableTimerRawStartStop](by-memory/0x005c1120-0x005c11b5.WaitableTimerRawStartStop.md) as a reviewed non-reconstructable, non-emitting split inventory over the exact start/cancel children and internal fence.
- [UID:0001WI][WaitableTimerLayout](by-type/by-struct/WaitableTimerLayout.md)
- [UID:0001Z2][WaitableTimerVtable](by-type/by-vtable/WaitableTimerVtable.md)
- [UID:0002P2][0x00631184-0x0063118c.WaitableTimerVtableData](by-memory/0x00631184-0x0063118c.WaitableTimerVtableData.md)
- `WaitableTimer::WaitableTimer()` at `0x005c0ff0-0x005c109c` after future exact child split.
- Non-deleting destructor / cleanup body at `0x005c10a0-0x005c1111` after future exact child split.
- [UID:0002L8][0x005c1120-0x005c116a.WaitableTimerStartMultimediaTimer](by-memory/0x005c1120-0x005c116a.WaitableTimerStartMultimediaTimer.md)
- [UID:0002L9][0x005c1170-0x005c11b5.WaitableTimerCancelMultimediaTimer](by-memory/0x005c1170-0x005c11b5.WaitableTimerCancelMultimediaTimer.md)
- `WaitableTimerCallback` at `0x005c11c0-0x005c120e` after future exact child split.
- Scalar deleting destructor at `0x005c1210-0x005c129a` as compiler-generated no-code evidence after future exact child split.

## Current MCP Evidence

- The accepted 2026-08-04 B005 report used sole healthy read-only session `b002-uid0004hs-persist-reopen`, PID `20412`, and canonical IDB disk snapshot SHA-256 `CE0222E87E1A569A73EB43DD72BF53412B103DD9281A535EEC2BCC01DE0932FA` (`143196420` bytes). This is dated source-placement evidence, not a permanent current-session assertion.
- B005 2026-06-23 accepted report used IDA MCP session `ff68e691`, PE SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- `lookup_funcs` confirmed modeled functions at `0x005c0ff0`, `0x005c10a0`, `0x005c11c0`, and `0x005c1210`; raw helper starts `0x005c1120` and `0x005c1170` remain not functions.
- Raw byte and padding checks confirm `0x005c1120-0x005c116a`, `0x005c1170-0x005c11b5`, and padding before/between/after the island's bodies.
- Xref checks confirm no direct constructor/raw-start routes, callback data ref `0x005c1149 -> 0x005c11c0`, vtable slot `0x00631188 -> 0x005c1210`, and vtable stores at `0x005c1020`, `0x005c10a8`, and `0x005c121b`.
- [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md) installs imported `CreateEventW` into `0x0069be3c`; the constructor and raw start helper consume that dispatch slot as `g_pfnCreateEventW`.
- The complete report-time raw inventory found 31 start instructions, 20 cancel instructions, 24 callback instructions, zero inbound xrefs and zero VA/RVA/raw-offset pointer patterns for both raw starts, the sole callback data xref `0x005c1149 -> 0x005c11c0`, and 12 CreateEventW-slot xrefs.

## Source-Structure Decision

Use `NexusTK/util/WaitableTimer.cpp`. The module is adjacent to threading/timing utility code, but its implementation is a reusable Win32 event/critical-section/multimedia timer primitive with no direct `TimerMgr` caller proof.

Do not assign direct method ownership to this by-file page when the class page clears the gate. [UID:0000FY][WaitableTimer](by-class/WaitableTimer.md) is the correct direct semantic owner for class method/helper pages; this by-file page is the generated source root.

[UID:0001NY][0x005c1120-0x005c11b5.WaitableTimerRawStartStop](by-memory/0x005c1120-0x005c11b5.WaitableTimerRawStartStop.md) is not an additional source body. It is a false/non-emitting address inventory whose exact reconstructable children emit `StartMultimediaTimer` and `CancelMultimediaTimer`. This removes the aggregate empty marker without filler, covered-by source, or duplicate method definitions.

The raw methods are retained/unreferenced source-authored class code. Their lack of a static route is fully documented negative liveness evidence, not a reason to classify them as compiler glue or to move them into an anonymous helper file.

## Generated Output Caveats

- Generated `source-3/simroot_v2/class_WaitableTimer.cpp` remains useful as lead material only.
- Generated names `WaitableTimer::Cleanup` and `WaitableTimerCompletion_5C11C0` are not final original-name proof.
- Generated metadata names field `+0x28` as `m_hWorkerThread`, but IDA/MCP evidence shows it is a callback gate event created with `CreateEventW`, signaled after `timeSetEvent`, waited/closed by the callback, and closed by cancel/destructor paths.
- Active generated output previously omitted the raw start/cancel helpers. [UID:0002L8][0x005c1120-0x005c116a.WaitableTimerStartMultimediaTimer](by-memory/0x005c1120-0x005c116a.WaitableTimerStartMultimediaTimer.md) and [UID:0002L9][0x005c1170-0x005c11b5.WaitableTimerCancelMultimediaTimer](by-memory/0x005c1170-0x005c11b5.WaitableTimerCancelMultimediaTimer.md) now carry first-draft C++ for those exact raw helper bodies.
- Historical generated output also carried a UID0001NY empty marker. The resolved false/non-emitting inventory state removes that marker while preserving both exact child definitions.
- A guarded cancel variant is rejected because the binary performs `timeKillEvent`, `CloseHandle`, and `ResetEvent` without an inactive-state branch.

## Source Placement, Naming, And Remaining Limits

- `NexusTK/util/WaitableTimer.cpp` and a single `WaitableTimer.h` remain the best source shape for a compact Win32 event/critical-section/WinMM utility. TimerMgr is a higher-level scheduler and no caller, layout, or lifetime evidence supports merging the modules.
- Live construction/lifetime and raw-start callers remain absent after xref and three-form pointer searches. This is a completed negative finding.
- Original public/private spellings for `StartMultimediaTimer`, `CancelMultimediaTimer`, callback helper, and non-deleting destructor/cleanup body cannot be recovered from the stripped image. The behavior-backed names are the accepted human-source reconstruction choices.
- A future source-family pass should create exact child pages for the constructor, non-deleting destructor/cleanup body, callback, and scalar deleting destructor.
- Wave2/Wave3 and generated raw-label evidence is historical only and does not control current placement or naming.

## Score Rationale

- Completion/confidence `92/92` reflects resolved source root, exact class island and split inventory, method/callback behavior, field layout, vtable, dispatch dependency, negative liveness, child-only emission, and no-TimerMgr-merge decision.
- Remaining uncertainty is exact historical file/access spelling and the still-unsplit constructor/callback family, not an unresolved UID0001NY blocker.

## Cross-References

- [UID:0000FY][WaitableTimer](by-class/WaitableTimer.md)
- [UID:0001NX][0x005c0ff0-0x005c129a.WaitableTimer](by-memory/0x005c0ff0-0x005c129a.WaitableTimer.md)
- [UID:0001NY][0x005c1120-0x005c11b5.WaitableTimerRawStartStop](by-memory/0x005c1120-0x005c11b5.WaitableTimerRawStartStop.md)
- [UID:0002L8][0x005c1120-0x005c116a.WaitableTimerStartMultimediaTimer](by-memory/0x005c1120-0x005c116a.WaitableTimerStartMultimediaTimer.md)
- [UID:0002L9][0x005c1170-0x005c11b5.WaitableTimerCancelMultimediaTimer](by-memory/0x005c1170-0x005c11b5.WaitableTimerCancelMultimediaTimer.md)
- [UID:0001WI][WaitableTimerLayout](by-type/by-struct/WaitableTimerLayout.md)
- [UID:0001Z2][WaitableTimerVtable](by-type/by-vtable/WaitableTimerVtable.md)
- [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md)
- [UID:0000OT][TimerMgr](by-file/TimerMgr.md)
- [UID:0001QT][client_threading](by-meta/client_threading.md)
- [UID:0001QU][client_timing](by-meta/client_timing.md)

## Changes

- 2026-08-04 B005 UID0001NY Rule 26 support implementation:
  - Raised from `87/86` to `92/92`, added UID0001NY's resolved false/non-emitting inventory role, and preserved exact child-only source emission in `NexusTK/util/WaitableTimer.cpp`.
  - Incorporated current report-time range/liveness/callback/dispatch evidence, source-placement and naming rationale, generated-state correction, cancel-guard rejection, score rationale, and historical Wave/generated-name treatment.
- 2026-06-23 B005 implementation:
  - Added current MCP session `ff68e691` evidence and clarified that this page is the source root while [UID:0000FY][WaitableTimer](by-class/WaitableTimer.md) is the direct class owner.
  - Preserved the no-TimerMgr-merge caveat and replaced stale generated/Wave2-style caveats with current source-quality decisions.
