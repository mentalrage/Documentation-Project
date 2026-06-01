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
- [UID:0000P7][WaitableTimer](by-file/WaitableTimer.md) owns a provisional multimedia timer/event wrapper.
- [UID:0000OS][ThreadSafeNodeList](by-file/ThreadSafeNodeList.md) owns or documents a lock-protected intrusive list helper.
- [UID:0000OT][TimerMgr](by-file/TimerMgr.md) remains the higher-level timer scheduler and should not be merged with `WaitableTimer` without caller evidence; see [UID:0001QU][client_timing](by-meta/client_timing.md).

## Observed Behavior

- `Thread` workers are created suspended through `_beginthreadex`, then resumed by a start helper. They wait on a primary semaphore plus optional secondary wait handles.
- Thread messages are 24-byte queue elements. Messages with an event handle are synchronous: the worker stores the result in a handler entry and signals the event.
- [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md) is a concrete `Thread` consumer that queues browse-directory, HTTP-get, and NCA-update work through message ids documented in [UID:0001SP][MiscWorkThreadMessageId](by-type/by-enum/MiscWorkThreadMessageId.md).
- `RingBuffer` blocks producers when full and consumers when empty through `MonitorCondition` semaphores.
- `ThreadMan` starts a separate worker thread, posts and consumes Win32 messages `0x0464-0x0468`, and maintains a watchdog list of 20-byte thread records. It checks `IsDebuggerPresent` during construction and suppresses fatal dead-thread checks under a debugger.
- 2026-05-26 IDA MCP recheck reconfirmed the worker-loop/function-boundary model: the raw message-posting wrappers still need function recovery, while the worker loop, worker entry, singleton clear, and deleting destructor remain modeled under ThreadMan.
- `CriticalSectionLock` is used in application message-loop paths as an RAII wrapper for caller-owned critical sections.
- `WaitableTimer` uses a Win32 event, critical section, multimedia timer id, and worker-thread handle. Current `simroot_v2` emits the constructor, cleanup body, multimedia timer callback, and scalar deleting destructor, but the live construction path remains unknown.

## Open Questions

- Live construction path for `ThreadMan`; direct constructor xrefs were not found.
- Live callers for the raw ThreadMan message-posting wrappers at `0x00596d70-0x00596e0b`; IDA currently shows the starts as raw code with no direct xrefs.
- Confirm whether the current no-xref status for raw ThreadMan wrappers is dead retained utility code or an IDA function-boundary/caller-recovery gap.
- Live construction path for `WaitableTimer`; direct constructor xrefs were not found.
- Final names/signatures for the Thread synchronous-send helpers at `0x00596620`, `0x00596760`, and `0x00596a00`.
- Final symbolic names for [UID:0001SR][ThreadManMessageId](by-type/by-enum/ThreadManMessageId.md) values `0x0464-0x0468`.
- Whether generated `RingBufferIterator` is a real class or a projected view over helper code.
- Whether the `0x005967d0` secondary-wait helper belongs to base `Thread` or remains a Socket-owned wrapper.
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
