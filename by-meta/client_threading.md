*** UID:0001QT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Client Threading

## Scope

This page tracks client-level threading and synchronization behavior. File ownership decisions live in `by-file`; exact function boundaries live in `by-memory`.

## Core Primitives

- [UID:0000OR][Thread](by-file/Thread.md) owns the generic worker-thread base and [UID:0000EW][ThreadMan](by-class/ThreadMan.md) singleton/watchdog.
- [UID:0000N8][RingBuffer](by-file/RingBuffer.md) owns the blocking fixed-element queue used by Thread message passing.
- [UID:0000LI][Monitor](by-file/Monitor.md) owns mutex/semaphore monitor primitives, condition objects, request gates, and the small `CriticalSectionLock` helper.
- [UID:0000P7][WaitableTimer](by-file/WaitableTimer.md) is the source file root for the [UID:0000FY][WaitableTimer](by-class/WaitableTimer.md) multimedia timer/event wrapper class.
- [UID:0000OS][ThreadSafeNodeList](by-file/ThreadSafeNodeList.md) owns or documents a lock-protected intrusive list helper.
- [UID:0000OT][TimerMgr](by-file/TimerMgr.md) remains the higher-level timer scheduler and should not be merged with `WaitableTimer` without caller evidence; see [UID:0001QU][client_timing](by-meta/client_timing.md).

## Observed Behavior

- `Thread` workers are created suspended through `_beginthreadex`, then resumed by a start helper. They wait on a primary semaphore plus optional secondary wait handles.
- Thread messages are 24-byte queue elements modeled as `ThreadMessage { messageId, arg1, arg2, resultEvent, syncArg1, syncArg2 }`. Messages with an event handle are synchronous: the worker stores the result in an 8-byte `ThreadResult { event, result }` entry and signals the event.
- [UID:0001JY][0x00596620-0x005969b0.CashShopRequestWaitDispatch](by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md) is resolved as base `Thread` dispatch infrastructure despite its stale filename. Current names are `Thread::WaitForQueueDrain()`, `Thread::WaitForResult(HANDLE)`, `Thread::AddWaitHandle(HANDLE)`, `Thread::RemoveLastWaitHandle()`, `Thread::ThreadProc()`, `Thread::OnMessage`, `Thread::OnMessageEx`, `Thread::DispatchRequest`, retained raw sibling `Thread::DispatchPriorityRequest`, and `Thread::DispatchRequestAndReturnEvent(...)`.
- `Thread::WaitForQueueDrain()` queues synchronous no-op message id `2`. Socket async dispatch handles ids `3-14`, and Socket sync dispatch handles only id `0x0c` specially, so id `2` falls to the base handler and acts as a queue-drain barrier.
- [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md) is a concrete `Thread` consumer that queues browse-directory, HTTP-get, and NCA-update work through message ids documented in [UID:0001SP][MiscWorkThreadMessageId](by-type/by-enum/MiscWorkThreadMessageId.md).
- `RingBuffer` blocks producers when full and consumers when empty through `MonitorCondition` semaphores.
- `ThreadMan` starts a separate worker thread, posts and consumes Win32 messages `0x0464-0x0468`, and maintains a watchdog list of 20-byte thread records. It checks `IsDebuggerPresent` during construction and suppresses fatal dead-thread checks under a debugger.
- 2026-05-26 IDA MCP recheck reconfirmed the worker-loop/function-boundary model: the raw message-posting wrappers still need function recovery, while the worker loop, worker entry, singleton clear, and deleting destructor remain modeled under ThreadMan.
- 2026-06-20 B003 ThreadMan source-quality review closed several ThreadMan naming/routing questions: the worker entry route is proven by the `CreateThread` pointer in the constructor; `ThreadManWatchRecord +0x08` is `watchedThreadId` copied from generic `Thread+0x60`; worker messages use `THREADMAN_*THREAD_ID*` names for the blocked/current-thread cases; and `ThreadMan` remains in `NexusTK/util/Thread.cpp` absent stronger source-file evidence.
- `CriticalSectionLock` is used in application message-loop paths as an RAII wrapper for caller-owned critical sections.
- B005 2026-06-23 MCP session `ff68e691` reanalysis resolves `WaitableTimer` as a multimedia timer/event wrapper with a completion event, critical section, running flag, multimedia timer id, and callback-gate event. The `+0x28` field is not a worker-thread handle: it is created through `g_pfnCreateEventW` / `CreateEventW`, signaled after `timeSetEvent` registration, waited/closed by the callback, and closed by cancel/destructor paths. The raw helper children [UID:0002L8][0x005c1120-0x005c116a.WaitableTimerStartMultimediaTimer](by-memory/0x005c1120-0x005c116a.WaitableTimerStartMultimediaTimer.md) and [UID:0002L9][0x005c1170-0x005c11b5.WaitableTimerCancelMultimediaTimer](by-memory/0x005c1170-0x005c11b5.WaitableTimerCancelMultimediaTimer.md) now carry first-draft C++.

## ThreadMan Closure Status

- `ThreadMan` source placement is currently closed as `NexusTK/util/Thread.cpp`; a separate `ThreadMan.cpp` requires future source/PDB/project evidence.
- `ThreadManWorkerEntry` is best documented as a file-static `DWORD WINAPI ThreadManWorkerEntry(LPVOID)` helper. A private static class-member spelling remains a lower-ranked alternate, not the current route.
- Raw `ThreadMan` wrappers and watch-list helpers still have no function records, direct xrefs, or pointer constants, but they are retained source-shaped helper/method bodies rather than compiler glue. Their behavior and current names should stay documented even if body C++ waits for a method-focused rewrite.
- `ThreadManWatchRecord +0x08` is now `watchedThreadId`, copied from generic `Thread+0x60`; it is not an abstract identity token.
- Class-level C++ should no longer stay blank: [UID:0000EW][ThreadMan](by-class/ThreadMan.md) now emits the declaration/API inventory. Method bodies remain on exact child pages, while scalar deleting destructor and singleton-clear thunk ranges stay no-code generated/cleanup artifacts.

## Open Questions

- Live construction path for `ThreadMan`; direct constructor xrefs were not found.
- For retained raw ThreadMan wrappers/watch-list helpers, determine whether they are live retained methods, dead retained utility methods, or reached by source constructs that did not survive as direct references.
- Live construction path for `WaitableTimer`; direct constructor xrefs were not found in the B005 `ff68e691` pass.
- Exact original spelling for `WaitableTimer::StartMultimediaTimer`, `WaitableTimer::CancelMultimediaTimer`, and `WaitableTimerCallback`; current names are behavior-backed source-facing inferences.
- Exact original spelling for `Thread::WaitForQueueDrain`, `Thread::DispatchPriorityRequest`, `Thread::DispatchRequestAndReturnEvent`, and private `List` API names; the current names/signatures are the best-supported source-facing draft.
- Exact original macro spelling for [UID:0001SR][ThreadManMessageId](by-type/by-enum/ThreadManMessageId.md) values `0x0464-0x0468`; current behavior-backed names are documented and sufficient for draft source.
- Whether generated `RingBufferIterator` is a real class or a projected view over helper code.
- Supervisor-assigned child/split execution for `0x005967f0-0x00596805.ThreadRemoveLastWaitHandleHelper` and `0x005969b0-0x00596a00.ThreadDispatchPriorityRequestRaw`.
- Whether any `TimerMgr` callbacks are dispatched from worker-thread paths beyond the application helper/message-loop path.

## Cross-References

- [UID:0001JX][0x00596250-0x0059756e.ThreadAndThreadMan](by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md)
- [UID:0001K1][0x00596d20-0x00596e0b.ThreadManRawMessageWrappers](by-memory/0x00596d20-0x00596e0b.ThreadManRawMessageWrappers.md)
- [UID:0001K2][0x00596e10-0x005970df.ThreadManWorkerLoop](by-memory/0x00596e10-0x005970df.ThreadManWorkerLoop.md)
- [UID:0001WB][ThreadManWatchRecord](by-type/by-struct/ThreadManWatchRecord.md)
- [UID:0001G4][0x005563d0-0x005568c8.RingBuffer](by-memory/0x005563d0-0x005568c8.RingBuffer.md)
- [UID:0001CL][0x005285e0-0x00528929.MonitorAndConditions](by-memory/0x005285e0-0x00528929.MonitorAndConditions.md)
- [UID:00012A][0x0049bcf0-0x0049bd19.CriticalSectionLock](by-memory/0x0049bcf0-0x0049bd19.CriticalSectionLock.md)
- [UID:0001NX][0x005c0ff0-0x005c129a.WaitableTimer](by-memory/0x005c0ff0-0x005c129a.WaitableTimer.md)
- [UID:000153][0x004b14c0-0x004b14ef.ThreadSafeNodeListPushFront](by-memory/0x004b14c0-0x004b14ef.ThreadSafeNodeListPushFront.md)
- [UID:0001K6][0x00597570-0x005986da.TimerMgrAndTimerQueue](by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md)
- [UID:00001A][BrowserThread](by-class/BrowserThread.md)
- [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md)

## Changes

- 2026-06-23 B005 implementation:
  - Replaced stale WaitableTimer worker-thread wording with callback-gate event wording.
  - Added current WaitableTimer class/source-route and raw child C++ readiness notes.
