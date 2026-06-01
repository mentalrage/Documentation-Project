*** UID:0000EV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Thread

## Summary

`Thread` is the shared worker-thread base class. It owns Win32 thread and wait handles, two blocking `RingBuffer` message queues, a `Monitor`, and a handler list for synchronous message events/results.

## Likely Original Placement

- Source: [UID:0000OR][Thread](by-file/Thread.md)
- Proposed path: `util/Thread.cpp`
- Confidence: strong

## Method Families

| Range | Role |
| --- | --- |
| [UID:0000WL][0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual](by-memory/0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual.md) | Empty `OnSignaled`-style virtual stub. Current generated source places it on `Thread`, but locality is non-contiguous and should be reviewed with derived vtables. |
| `0x00596250-0x005963f2` | Constructor: creates semaphore, queues, monitor, handler list, and suspended worker thread. |
| `0x00596400-0x00596534` | Destructor: closes thread/wait handles, deletes queues, closes pending sync events, deletes monitor/list. |
| `0x00596540-0x005965bf` | Graceful stop helper that posts stop message then terminates if still active. |
| `0x005965c0-0x005965cc` | Force terminate wrapper. |
| `0x005965e0-0x005967c7` | Start/resume and synchronous message helper family, omitted from active generated source. |
| `0x005967d0-0x005967e5` | Secondary wait-handle registration wrapper, currently documented as a Socket-owned review item. |
| `0x00596810-0x0059695e` | Worker dispatch loop and base message handlers. |
| `0x00596960-0x00596ae8` | Async/sync message post helpers. Current `simroot_v2/class_Thread.cpp` emits `Thread::DispatchRequest` at `0x00596960` and an event-returning helper at `0x00596a00`; older docs/generated owners may still attach nearby wait helpers to `CashShopRequest`. |
| `0x00596af0-0x00596bac` | `_beginthreadex` entry function. |
| `0x00596bb0-0x00596be8` | Scalar deleting destructor. |

## Evidence

- Constructor callers at `0x0041a69b`, `0x0045393b`, `0x004700dd`, `0x005281db`, and `0x00574812` show broad reuse by derived thread classes, including [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md).
- `RingBuffer` constructor is called twice from `Thread::Thread`, with element size `24`.
- `Monitor` and `List` are allocated inside `Thread::Thread`, confirming that thread message synchronization is generic utility infrastructure.
- IDA confirms all function starts in the main `0x00596250-0x00596be8` island.
- IDA and current `simroot_v2` confirm `0x00596960` is a generic queue post helper: it packs six dwords, enqueues through the queue pointer at `this + 76`, and signals the semaphore at `this + 12`. This is the helper reached by the packet-send wrapper at [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md).

## Open Questions

- Final names/signatures for the sync-send and post-message helpers.
- Whether `0x0041b6b0` is truly the base `Thread::OnSignaled` implementation or a derived-class virtual slot with polluted owner metadata.
- Whether the `0x005967d0` wrapper should stay with [UID:0000DD][Socket](by-class/Socket.md) or move back to base `Thread`.

## Cross-References

- File: [UID:0000OR][Thread](by-file/Thread.md)
- Memory: [UID:0001JX][0x00596250-0x0059756e.ThreadAndThreadMan](by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md)
- Memory: [UID:0000WL][0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual](by-memory/0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual.md)
- Related classes: [UID:0000EW][ThreadMan](by-class/ThreadMan.md), [UID:0000C1][RingBuffer](by-class/RingBuffer.md), [UID:00008L][Monitor](by-class/Monitor.md), [UID:000079][List](by-class/List.md), [UID:00001A][BrowserThread](by-class/BrowserThread.md), [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md)
- Item: [UID:0001JZ][0x005967d0-0x005967e5.SocketThreadEvent](by-memory/0x005967d0-0x005967e5.SocketThreadEvent.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:80`.
  - Summary/evidence: scored from the constructor/destructor/dispatch/post/thread-entry method map, broad derived-class caller evidence, queue/monitor/list ownership notes, and remaining ownership questions for the no-op virtual and wait-handle wrapper.
