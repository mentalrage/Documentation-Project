*** UID:0000EW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ThreadMan

## Summary

`ThreadMan` is a process-level thread manager/watchdog singleton. It records whether a debugger is present, owns a task list, starts a manager worker thread, and clears [UID:0000SH][g_pThreadMan](by-global/g_pThreadMan.md) on teardown.

## Likely Original Placement

- Source: [UID:0000OR][Thread](by-file/Thread.md)
- Proposed path: `util/Thread.cpp`
- Confidence: medium

## Method Families

| Range | Role |
| --- | --- |
| `0x00596bf0-0x00596d13` | [UID:0001K0][0x00596bf0-0x00596d13.ThreadManConstructor](by-memory/0x00596bf0-0x00596d13.ThreadManConstructor.md): sets singleton, checks `IsDebuggerPresent`, creates task list, starts worker thread. |
| `0x00596d20-0x00596e0b` | [UID:0001K1][0x00596d20-0x00596e0b.ThreadManRawMessageWrappers](by-memory/0x00596d20-0x00596e0b.ThreadManRawMessageWrappers.md): non-deleting cleanup and `PostThreadMessageW` wrappers for worker messages `0x0464-0x0468`. |
| `0x00596e10-0x005970df` | [UID:0001K2][0x00596e10-0x005970df.ThreadManWorkerLoop](by-memory/0x00596e10-0x005970df.ThreadManWorkerLoop.md): message-pump/watchdog behavior with task-list checks. |
| `0x00597100-0x005971ad` | [UID:0001K3][0x00597100-0x005971ad.ThreadManWorkerEntry](by-memory/0x00597100-0x005971ad.ThreadManWorkerEntry.md). |
| `0x005974e0-0x005974eb` | [UID:0001K4][0x005974e0-0x005974eb.ClearThreadManSingleton](by-memory/0x005974e0-0x005974eb.ClearThreadManSingleton.md). |
| `0x005974f0-0x0059756e` | [UID:0001K5][0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor](by-memory/0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md): terminates worker thread, releases task list, clears singleton. |

## Evidence

- Generated source and IDA agree that `ThreadMan::ThreadMan` writes `0x0069be08`.
- Xrefs to `0x0069be08` are in the constructor, singleton-clear helper, destructor, and an unmodeled adjacent region around `0x00596d5f`.
- Constructor resolves `kernel32.dll` and optionally calls `IsDebuggerPresent`.
- Worker loop strings include a fatal-app-exit dead-thread message pattern.
- The worker list is `List(20, 16)` and stores [UID:0001WB][ThreadManWatchRecord](by-type/by-struct/ThreadManWatchRecord.md) records.
- IDA raw disassembly on 2026-05-25 shows the unmodeled `0x00596d20-0x00596e0b` helper gap posts exactly the message ids consumed by the worker loop.
- 2026-05-26 IDA MCP recheck reconfirmed the modeled function set and sizes: constructor `0x00596bf0` size `0x123`, worker loop `0x00596e10` size `0x2cf`, worker entry `0x00597100` size `0xad`, singleton clear `0x005974e0` size `0x0b`, and scalar deleting destructor `0x005974f0` size `0x7e`.
- The same recheck still reports the raw destructor/post-message starts `0x00596d20`, `0x00596d70`, `0x00596d90`, `0x00596db0`, `0x00596dd0`, and `0x00596df0` as `Not a function` with empty `xrefs_to`.
- No direct constructor caller was found in this pass; construction may be through static singleton glue or a function not currently modeled as a direct call.

## Generated Data Caveats

Current `source-3/simroot_v2/class_ThreadMan.cpp` emits the constructor, worker loop, scalar deleting destructor, worker entry, and singleton-clear helper. The constructor/destructor are useful leads, but the worker loop still has a very low score and replaces concrete Win32 message handling with fake helper names. The active output also omits the raw destructor/message-wrapper family at `0x00596d20-0x00596e0b`.

`class_ThreadMan.cpp.disabled` contains bad/stale rows:

- `0x0045004b`: missing code and not part of the ThreadMan island.
- `0x004e0052`: NewHumanImageLib data-loading code, not a ThreadMan method.

The next function at `0x00597570` is [UID:0000F0][TimerHandler](by-class/TimerHandler.md) construction, not an unresolved ThreadMan tail.

2026-05-26 IDA MCP recheck still resolves `0x0045004b` inside `sub_450030` at `0x00450030`, `0x004e0052` inside `NewHumanImageLib::NewHumanImageLib` at `0x004dfd10`, and `0x00597570` as the `TimerHandler` vtable constructor. None of those rows should be restored as ThreadMan methods.

## Cross-References

- File: [UID:0000OR][Thread](by-file/Thread.md)
- Memory: [UID:0001JX][0x00596250-0x0059756e.ThreadAndThreadMan](by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md)
- Raw wrappers: [UID:0001K1][0x00596d20-0x00596e0b.ThreadManRawMessageWrappers](by-memory/0x00596d20-0x00596e0b.ThreadManRawMessageWrappers.md)
- Worker loop: [UID:0001K2][0x00596e10-0x005970df.ThreadManWorkerLoop](by-memory/0x00596e10-0x005970df.ThreadManWorkerLoop.md)
- Worker entry: [UID:0001K3][0x00597100-0x005971ad.ThreadManWorkerEntry](by-memory/0x00597100-0x005971ad.ThreadManWorkerEntry.md)
- Global: [UID:0000SH][g_pThreadMan](by-global/g_pThreadMan.md)
- Layout/types: [UID:0001WA][ThreadManLayout](by-type/by-struct/ThreadManLayout.md), [UID:0001WB][ThreadManWatchRecord](by-type/by-struct/ThreadManWatchRecord.md), [UID:0001SR][ThreadManMessageId](by-type/by-enum/ThreadManMessageId.md)
- Related: [UID:0000EV][Thread](by-class/Thread.md), [UID:000079][List](by-class/List.md), [UID:0000F0][TimerHandler](by-class/TimerHandler.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:78`.
  - Summary/evidence: scored from the detailed singleton constructor, worker-loop, raw-wrapper, worker-entry, destructor, layout/type, and bad-generated-row documentation, with confidence capped by unresolved constructor reachability and raw wrapper function-boundary caveats.
- 2026-05-31: Reconstructable metadata was blank.
  - Before: `RECONSTRUCTABLE:`.
  - After: `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA MCP rechecked the source-owned `ThreadMan` constructor, worker loop, worker entry, singleton clear helper, and scalar deleting destructor boundaries. The page remains unattached and has no C++ reconstruction because raw wrapper boundaries and final source shape are not yet at the near-final threshold.
