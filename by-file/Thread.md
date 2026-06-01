*** UID:0000OR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# Thread

## Status

- Proposed module: `util/Thread.cpp`
- Proposed header: `util/Thread.h`
- Confidence: strong for utility/threading ownership, medium for exact original folder.
- Current recovered source: `source-3/simroot_v2/class_Thread.cpp`
- Related recovered source: `source-3/simroot_v2/class_ThreadMan.cpp`

## File Role

`Thread.cpp` is the likely shared worker-thread abstraction module. It owns the base [UID:0000EV][Thread](by-class/Thread.md) class used by browser, socket, downloader, [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md), and other async subsystems, and likely also owns [UID:0000EW][ThreadMan](by-class/ThreadMan.md), the process-level watchdog/debug thread manager.

The module should stay under `util/` rather than `network/` or `browser/`. Derived classes consume this base, while the base itself owns generic Win32 handles, message queues, synchronous event handoff, thread startup, and cleanup.

## Likely Contents

- [UID:0000EV][Thread](by-class/Thread.md)
- [UID:0000EW][ThreadMan](by-class/ThreadMan.md)
- [UID:0000SH][g_pThreadMan](by-global/g_pThreadMan.md)
- Thread message structs and handler-entry structs
- [UID:0001WB][ThreadManWatchRecord](by-type/by-struct/ThreadManWatchRecord.md) and [UID:0001SR][ThreadManMessageId](by-type/by-enum/ThreadManMessageId.md)
- Thread entry helper at `0x00596af0`
- ThreadMan worker entry and worker loop at `0x00597100` and `0x00596e10`
- ThreadMan raw destructor/message-posting wrappers at `0x00596d20-0x00596e0b`

Thread depends on [UID:0000N8][RingBuffer](by-file/RingBuffer.md), [UID:0000LI][Monitor](by-file/Monitor.md), and [UID:0000KS][List](by-file/List.md). Those are lower-level utility modules and should remain separate unless later source-file evidence proves a single larger synchronization source.

## Evidence

- IDA MCP confirms a dense thread/thread-manager island at `0x00596250-0x0059756e`.
- `Thread::Thread` constructs two `RingBuffer(24, messageSize)` instances, a `Monitor`, a `List(8, 16)`, a Win32 semaphore, and a suspended `_beginthreadex` worker.
- `Thread::ThreadProc` waits on the primary semaphore and additional handles, dispatches asynchronous and synchronous messages through virtual handlers, stores sync-message results, and signals caller events.
- `Thread` constructor callers at `0x0041a69b`, `0x0045393b`, `0x004700dd`, `0x005281db`, and `0x00574812` indicate broad derived-thread reuse.
- `ThreadMan::ThreadMan` writes `g_pThreadMan` at `0x0069be08`, checks `IsDebuggerPresent`, creates a task list, and starts a manager worker thread.
- `ThreadMan` constructs `List(20, 16)` for watchdog records and its worker loop consumes Win32 messages `0x0464-0x0468`.
- The raw ThreadMan helper gap at [UID:0001K1][0x00596d20-0x00596e0b.ThreadManRawMessageWrappers](by-memory/0x00596d20-0x00596e0b.ThreadManRawMessageWrappers.md) posts those same Win32 message ids with `PostThreadMessageW`; active generated output currently omits the gap.
- No direct constructor xrefs to `ThreadMan::ThreadMan` were found in this pass. It may be constructed through static/Singleton glue not modeled as a direct call.
- 2026-05-26 IDA MCP recheck reconfirmed the same ThreadMan boundaries: constructor `0x00596bf0`, worker loop `0x00596e10`, worker entry `0x00597100`, singleton clear `0x005974e0`, and scalar deleting destructor `0x005974f0` are modeled; raw wrapper starts `0x00596d20`, `0x00596d70`, `0x00596d90`, `0x00596db0`, `0x00596dd0`, and `0x00596df0` still report `Not a function` with empty xrefs.

## Generated Output Caveats

Current `source-3/simroot_v2/class_Thread.cpp` now emits most of the main `Thread` helper island through `0x00596bb0` plus the global `ThreadEntry` helper. It also emits the generic queue post helper `Thread::DispatchRequest` at `0x00596960` and the event-returning synchronous post helper at `0x00596a00`. It still needs ownership cleanup before migration:

- `0x00596620` and `0x00596760` are still documented/generated with `CashShopRequest::*` owner names even though the bodies operate on generic `Thread` queues, monitors, and result-event lists.
- `0x00596960` is the queue post primitive used by [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md) and by cash-shop/download request helpers. Current simroot output correctly hints at generic `Thread` ownership here, but older docs and generated callers may still call it as a `CashShopRequest` method.
- `0x00596bb0` is emitted with the artifact type name `Thread_00596bb0`.
- The generated `ThreadEntry` helper is useful but still low-fidelity in exception typing and surrounding declarations.

Current `source-3/simroot_v2/class_ThreadMan.cpp` emits the worker loop and entry helpers, but `RunMessagePump` has very low fidelity and introduces fake helper functions for Win32 message dispatch. It also omits the raw ThreadMan destructor/message wrappers in `0x00596d20-0x00596e0b`. Disabled `ThreadMan` rows at `0x0045004b` and `0x004e0052` are not valid ThreadMan methods; `0x004e0052` is an interior instruction in `NewHumanImageLib::NewHumanImageLib`, and `0x00597570` belongs to [UID:0000F0][TimerHandler](by-class/TimerHandler.md), not ThreadMan.

2026-05-26 IDA MCP recheck still resolves disabled row `0x0045004b` inside `sub_450030` at `0x00450030`, a small lower-bound/binary-search helper called from the LodePNG island, and resolves `0x004e0052` inside `NewHumanImageLib::NewHumanImageLib` at `0x004dfd10`. It also reconfirmed `0x00597570` as the `TimerHandler` vtable-installing constructor with non-ThreadMan callers.

## Source-Structure Decision

Use `util/Thread.cpp` for both `Thread` and `ThreadMan` until contrary evidence appears. Keeping them together matches the memory island, singleton/watchdog relationship, and shared thread-message abstractions. Keep [UID:00001A][BrowserThread](by-class/BrowserThread.md) with [UID:0000HV][Browser](by-file/Browser.md) and [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md) with [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md); both are derived worker implementations, not part of this generic base file.

## Cross-References

- [UID:0000EV][Thread](by-class/Thread.md)
- [UID:0000EW][ThreadMan](by-class/ThreadMan.md)
- [UID:0001JX][0x00596250-0x0059756e.ThreadAndThreadMan](by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md)
- [UID:0001K1][0x00596d20-0x00596e0b.ThreadManRawMessageWrappers](by-memory/0x00596d20-0x00596e0b.ThreadManRawMessageWrappers.md)
- [UID:0001K2][0x00596e10-0x005970df.ThreadManWorkerLoop](by-memory/0x00596e10-0x005970df.ThreadManWorkerLoop.md)
- [UID:0000SH][g_pThreadMan](by-global/g_pThreadMan.md)
- [UID:0001WB][ThreadManWatchRecord](by-type/by-struct/ThreadManWatchRecord.md)
- [UID:0001SR][ThreadManMessageId](by-type/by-enum/ThreadManMessageId.md)
- [UID:0000N8][RingBuffer](by-file/RingBuffer.md)
- [UID:0000LI][Monitor](by-file/Monitor.md)
- [UID:0001JZ][0x005967d0-0x005967e5.SocketThreadEvent](by-memory/0x005967d0-0x005967e5.SocketThreadEvent.md)
- [UID:0001QT][client_threading](by-meta/client_threading.md)
- [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md)

## Changes

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `88` and confidence to `80`.
  - Evidence: document covers Thread/ThreadMan module role, likely contents, dependencies, IDA island evidence, caller fan-in, singleton/watchdog behavior, raw wrapper gaps, generated-output caveats, source-structure decision, and cross-references; confidence remains capped by exact original folder and ThreadMan split.
- 2026-05-31: Assigned projected reconstruction path.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank.
  - After: set path to `NexusTK/util/`.
  - Evidence: the page already documents `util/Thread.cpp` as the working module, and the 2026-05-31 IDA MCP recheck reconfirmed ThreadMan singleton storage/cleanup around `0x0069be08`, the `ThreadMan` constructor at `0x00596bf0`, the clear helper at `0x005974e0`, and the scalar deleting destructor at `0x005974f0`.
