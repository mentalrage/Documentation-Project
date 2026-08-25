*** UID:0000SI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
TimerMgr* g_pTimerMgr = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pTimerMgr

## Status

- Symbol kind: singleton pointer/global data.
- Address: `0x0067ab80` in IDA as `dword_67AB80`.
- Current generated names: `g_pTimerMgr`, `dword_67AB80`
- Likely owner: [UID:0000OT][TimerMgr](by-file/TimerMgr.md)
- Confidence: strong for storage, lifecycle ownership, and scheduler consumers; medium-high for final declaration spelling/linkage.

## Role

`g_pTimerMgr` points to the process-wide [UID:0000F1][TimerMgr](by-class/TimerMgr.md) instance. Timer owners use it to schedule, cancel, query, and unregister callbacks through [UID:0000F0][TimerHandler](by-class/TimerHandler.md) wrappers and direct scheduler helpers. The `TimerMgr` constructor writes this pointer, and destructor/static clear helpers reset it to null.

## Evidence

- Active `class_TimerMgr.cpp` declares `TimerMgr* g_pTimerMgr` and writes it during `TimerMgr::TimerMgr`.
- Active `class_TimerHandler.cpp` uses `g_pTimerMgr->UnregisterHandler(this)` in the scalar deleting destructor.
- IDA shows more than 30 xrefs in the first sampled set, including timer wrapper calls at `0x005975e0`, `0x00597600`, `0x00597610`, and `0x00597630`, plus broad UI/object/app timer users. The `0x00597580` destructor also unregisters through this singleton.
- IDA decompilation of the static `TimerMgr` destructor writes `dword_67AB80 = 0`.
- 2026-05-31 IDA MCP recheck reported storage name `dword_67AB80`, `0xffffffff` initial data in that older IDB view, and 125 xrefs. B009 restored-session MCP evidence supersedes the initializer part for the current IDB: `0x0067ab80` now reads `00 00 00 00`, value `0x0`. The 125-xref ownership evidence remains useful; the source declaration should be `TimerMgr* g_pTimerMgr = 0;`.
- [UID:0002VW][0x0067ab80-0x0067ab84.g_pTimerMgr](by-memory/0x0067ab80-0x0067ab84.g_pTimerMgr.md) records the exact `0x0067ab80-0x0067ab84` slot with `125` xrefs and split-owner guidance that keeps this slot with `TimerMgr.cpp`.
- The exact storage page records constructor publish/fallback writes at `0x00597702` and `0x00597709`, clear paths at `0x0059779c`, `0x00597fd0`, and `0x005980af`, and representative consumers at `0x0046919d`, `0x00494610`, `0x004947a0`, `0x004a6c40`, `0x005a5bd0`, `0x005ab090`, and `0x005ab410`.
- [UID:0000F0][TimerHandler](by-class/TimerHandler.md) records exact wrapper/caller evidence: the schedule wrapper at `0x005975e0` has 163 direct callers, unregister at `0x00597600` has 45, targeted cancel at `0x00597610` has 47, and alternate cancel at `0x00597630` has one; every wrapper loads this singleton before forwarding to `TimerMgr`.
- [UID:0001K6][0x00597570-0x005986da.TimerMgrAndTimerQueue](by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md) and [UID:0001KA][0x00597dc0-0x005986da.TimerMgrQueueHelpers](by-memory/0x00597dc0-0x005986da.TimerMgrQueueHelpers.md) split the executable owner into constructor, destructor, dispatch, schedule, removal, query, tick, queue, and singleton-clear children; this keeps `g_pTimerMgr` tied to the scheduler family rather than feature-local timer users.
- B015 `0001KA` raw PE reanalysis reconfirmed the split-owner model from the global side: the `0x0067ab80` dword pattern appears broadly in timer consumers and lifecycle paths, `0x00597fd0` is a constructor-unwind singleton-clear thunk with no normal source caller, and `0x00598090` clears the singleton through the `TimerMgr` scalar deleting destructor wrapper.
- [UID:000046][EarthquakeEffecter](by-class/EarthquakeEffecter.md) reads this singleton for `TimerMgr + 0x18` current tick state. The constructor stores `currentTick - 0x3c` into `m_lastShakeTick`, and `ApplyEffect` accepts new random shake offsets only when the tick delta exceeds `0x50`. Use `g_pTimerMgr`, not generated `g_pTimer`, for this path.

## 2026-06-30 B009 Initializer Reconciliation

B009 implemented the accepted TimerMgr empty-emitter report by raising this global to `88/92` and adding the formal source declaration. The current MCP session `supervisor_resume_20260629` reports `server_health` ok for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` and reads `0x0067ab80` as four zero bytes. Older `0xffffffff` prose is historical/stale byte evidence for a previous session and must not be treated as current image truth. Runtime lifecycle writes are unchanged: construction publishes the static `TimerMgr` instance or zero fallback, and destructor/unwind paths clear the pointer.

## Related Globals

- `0x0069b3ac`: static `TimerMgr` storage constructed by startup code and destroyed through the static destructor path.
- `0x0069be0c`: timer tick mirror initialized by `TimerMgr::InitializeTimerResolution`.
- `0x0069be10`: current timer tick mirror updated by dispatch/refresh.
- `0x0067ab54-0x0067ab7c`: adjacent dialog/application-loop state in the same `.data` cluster. These slots are physically adjacent only; they are not `TimerMgr.cpp` declarations.
- `0x0067ab7c`: adjacent `BackGroundPane *g_pBackGroundPane` slot. Keep it with `BackPane.cpp`, not with this timer singleton.

## Cross-References

- [UID:0000OT][TimerMgr](by-file/TimerMgr.md)
- [UID:0002VW][0x0067ab80-0x0067ab84.g_pTimerMgr](by-memory/0x0067ab80-0x0067ab84.g_pTimerMgr.md)
- [UID:0000F1][TimerMgr](by-class/TimerMgr.md)
- [UID:0000F0][TimerHandler](by-class/TimerHandler.md)
- [UID:0000F2][TimerMgrScheduledEventDequeCompilerSupport](by-class/TimerMgrScheduledEventDequeCompilerSupport.md)
- [UID:0001K6][0x00597570-0x005986da.TimerMgrAndTimerQueue](by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md)
- [UID:0001KA][0x00597dc0-0x005986da.TimerMgrQueueHelpers](by-memory/0x00597dc0-0x005986da.TimerMgrQueueHelpers.md)
- [UID:00029B][0x0067ab54-0x0067ab84.ApplicationDialogTimerAndBackgroundGlobals](by-memory/0x0067ab54-0x0067ab84.ApplicationDialogTimerAndBackgroundGlobals.md)
- [UID:0002L2][0x00597fd0-0x00597fdb.ClearGlobalTimerMgr](by-memory/0x00597fd0-0x00597fdb.ClearGlobalTimerMgr.md)
- [UID:00024G][0x0060c26a-0x0060c320.StaticDestructorWrappersBeforePoolAllocators](by-memory/0x0060c26a-0x0060c320.StaticDestructorWrappersBeforePoolAllocators.md)
- [UID:0001WD][TimerMgrLayout](by-type/by-struct/TimerMgrLayout.md)
- [UID:000046][EarthquakeEffecter](by-class/EarthquakeEffecter.md)

## Changes

- 2026-06-22 Rule 26 incorporation of B015 TimerMgrQueueHelpers report:
  - Score unchanged.
  - Summary/evidence: added the B015 singleton-side support facts for the constructor-unwind clear thunk, scalar deleting destructor clear path, and broad `0x0067ab80` dword-pattern evidence while preserving `g_pTimerMgr` as the accepted source-facing name.
- 2026-06-19 B007 EarthquakeEffecter support sync:
  - Added Earthquake as a `g_pTimerMgr->+0x18` current-tick consumer and preserved the accepted `g_pTimerMgr` source-facing name over generated `g_pTimer`.
- What existed before: completion/confidence were `0/0`, reconstructable state was blank, and no autogen parent was assigned.
- What it was changed to: completion `76`, confidence `86`, `RECONSTRUCTABLE:TRUE`, and parent UID [UID:0000OT][TimerMgr](by-file/TimerMgr.md).
- Summary/evidence: the page already documented the singleton timer-manager role, and the 2026-05-31 IDA MCP recheck reconfirmed the exact storage, broad xref count, and timer-manager ownership. No C++ declaration was emitted because the final declaration/linkage form remains below the 95+ reconstruction-code threshold.
- 2026-06-06: Raised completion/confidence to `84/88` after folding in already documented exact storage and split scheduler evidence.
  - What existed before: the page named the singleton and broad owner but did not link the exact `0x0067ab80-0x0067ab84` storage cluster, the latest TimerHandler wrapper caller counts, or the queue/helper split pages that prove the scheduler ownership boundary.
  - Changed to: added exact storage-cluster evidence, constructor and clear-site addresses, representative consumer addresses, TimerHandler wrapper fanout, queue-helper split references, adjacent non-TimerMgr slot caveats, and additional cross-references.
  - Summary/evidence: existing IDA-backed docs now show `125` direct refs to the slot, constructor publish/fallback writes at `0x00597702`/`0x00597709`, clear paths at `0x0059779c`, `0x00597fd0`, and `0x005980af`, and wrapper fanout through `0x005975e0`, `0x00597600`, `0x00597610`, and `0x00597630`. Live MCP retries timed out during this pass, so the score remains below final audit level and no C++ declaration was emitted.
- 2026-06-07 A006 storage split refresh:
  - Before: score `84/88`, with exact storage still cited through the mixed `0x0067ab54-0x0067ab84` aggregate.
  - Changed to: `86/90`, with exact storage child [UID:0002VW][0x0067ab80-0x0067ab84.g_pTimerMgr](by-memory/0x0067ab80-0x0067ab84.g_pTimerMgr.md) attached here.
  - Summary/evidence: live IDA-backed split evidence confirms `0xffffffff` initialization, 125 xrefs, constructor publish/fallback writes at `0x00597702`/`0x00597709`, clear paths at `0x0059779c`, `0x00597fd0`, and `0x005980af`, and adjacent non-TimerMgr boundaries.
