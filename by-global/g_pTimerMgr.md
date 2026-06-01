*** UID:0000SI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pTimerMgr

## Status

- Symbol kind: singleton pointer/global data.
- Address: `0x0067ab80` in IDA as `dword_67AB80`.
- Current generated names: `g_pTimerMgr`, `dword_67AB80`
- Likely owner: [UID:0000OT][TimerMgr](by-file/TimerMgr.md)
- Confidence: strong.

## Role

`g_pTimerMgr` points to the process-wide [UID:0000F1][TimerMgr](by-class/TimerMgr.md) instance. Timer owners use it to schedule, cancel, and unregister callbacks. The `TimerMgr` constructor writes this pointer, and destructor/static clear helpers reset it to null.

## Evidence

- Active `class_TimerMgr.cpp` declares `TimerMgr* g_pTimerMgr` and writes it during `TimerMgr::TimerMgr`.
- Active `class_TimerHandler.cpp` uses `g_pTimerMgr->UnregisterHandler(this)` in the scalar deleting destructor.
- IDA shows more than 30 xrefs in the first sampled set, including timer wrapper calls at `0x005975e0`, `0x00597600`, `0x00597610`, and `0x00597630`, plus broad UI/object/app timer users. The `0x00597580` destructor also unregisters through this singleton.
- IDA decompilation of the static `TimerMgr` destructor writes `dword_67AB80 = 0`.
- 2026-05-31 IDA MCP recheck confirms storage name `dword_67AB80`, `0xffffffff` initial data in the current IDB view, and 125 xrefs. Sampled xrefs include application timer dispatch at `0x004a6c40`, timer wrapper/handler users, UI/object/app callers, and the `TimerMgr` constructor at `0x005976c0-0x00597780`.

## Related Globals

- `0x0069b3ac`: static `TimerMgr` storage constructed by startup code and destroyed through the static destructor path.
- `0x0069be0c`: timer tick mirror initialized by `TimerMgr::InitializeTimerResolution`.
- `0x0069be10`: current timer tick mirror updated by dispatch/refresh.

## Cross-References

- [UID:0000OT][TimerMgr](by-file/TimerMgr.md)
- [UID:0000F1][TimerMgr](by-class/TimerMgr.md)
- [UID:0000F0][TimerHandler](by-class/TimerHandler.md)
- [UID:0001K6][0x00597570-0x005986da.TimerMgrAndTimerQueue](by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md)
- [UID:00024G][0x0060c26a-0x0060c320.StaticDestructorWrappersBeforePoolAllocators](by-memory/0x0060c26a-0x0060c320.StaticDestructorWrappersBeforePoolAllocators.md)

## Changes

- What existed before: completion/confidence were `0/0`, reconstructable state was blank, and no autogen parent was assigned.
- What it was changed to: completion `76`, confidence `86`, `RECONSTRUCTABLE:TRUE`, and parent UID [UID:0000OT][TimerMgr](by-file/TimerMgr.md).
- Summary/evidence: the page already documented the singleton timer-manager role, and the 2026-05-31 IDA MCP recheck reconfirmed the exact storage, broad xref count, and timer-manager ownership. No C++ declaration was emitted because the final declaration/linkage form remains below the 95+ reconstruction-code threshold.
