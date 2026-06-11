*** UID:0000EV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
| [UID:0000WL][0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual](by-memory/0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual.md) | Empty inherited external-wait callback at vtable offset `+0x34`; now attached to this class after Batch100 proved the `Thread::ThreadProc` call site and base/derived vtable slot layout. |
| `0x00596250-0x005963f2` | Constructor: creates semaphore, queues, monitor, handler list, and suspended worker thread. |
| `0x00596400-0x00596534` | Destructor: closes thread/wait handles, deletes queues, closes pending sync events, deletes monitor/list. |
| `0x00596540-0x005965bf` | Graceful stop helper that posts stop message then terminates if still active. |
| `0x005965c0-0x005965cc` | Force terminate wrapper. |
| `0x005965e0-0x005967c7` | Start/resume and synchronous message helper family, omitted from active generated source. |
| `0x005967d0-0x005967e5` | Secondary wait-handle registration wrapper, now reclassified from stale Socket ownership to base `Thread` ownership after IDA body/caller review. |
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
- 2026-06-08 IDA MCP decompilation of `Thread::ThreadProc` at `0x00596810-0x00596915` confirms the base dispatch loop waits on `this + 0x0c` with count byte `this[8]`, routes primary queue work through vtable offsets `+0x24`, `+0x28`, `+0x2c`, and `+0x30`, and routes non-primary wait-handle signals through offset `+0x34`.
- 2026-06-08 vtable slot audit confirms `Thread` vtable `0x0062e26c` stores [UID:0000WL][0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual](by-memory/0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual.md) at slot index `13` / offset `+0x34`, and the `FileDownloader`, `MiniMapDownloader`, `BrowserThread`, and `MiscWorkThread` vtables retain that same inherited slot value.

## Open Questions

- Final names/signatures for the sync-send and post-message helpers.
- Final source-level spelling for the empty external-wait virtual body at `0x0041b6b0`. Ownership is now class-attached to `Thread`, but the exact original method name remains provisional and the body is still folded with unrelated STL vtable entries.
- Final source-level names for the `0x005967d0` wait-handle registration wrapper and its wait-count/handle-array fields.

## Cross-References

- File: [UID:0000OR][Thread](by-file/Thread.md)
- Memory: [UID:0001JX][0x00596250-0x0059756e.ThreadAndThreadMan](by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md)
- Memory: [UID:0000WL][0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual](by-memory/0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual.md)
- Related classes: [UID:0000EW][ThreadMan](by-class/ThreadMan.md), [UID:0000C1][RingBuffer](by-class/RingBuffer.md), [UID:00008L][Monitor](by-class/Monitor.md), [UID:000079][List](by-class/List.md), [UID:00001A][BrowserThread](by-class/BrowserThread.md), [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md)
- Item: [UID:0001JZ][0x005967d0-0x005967e5.SocketThreadEvent](by-memory/0x005967d0-0x005967e5.SocketThreadEvent.md)

## Changes

- 2026-06-08 A001 Batch100 parent-gate audit:
  - Before: `COMPLETION:84`, `CONFIDENCE:80`.
  - After: `COMPLETION:86`, `CONFIDENCE:85`.
  - Evidence: live IDA MCP decompiled `Thread::ThreadProc`, confirmed the `WaitForMultipleObjects` non-primary-handle dispatch through vtable offset `+0x34`, and verified that the base `Thread` vtable plus `FileDownloader`, `MiniMapDownloader`, `BrowserThread`, and `MiscWorkThread` derived vtables all keep [UID:0000WL][0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual](by-memory/0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual.md) in that inherited slot. The class now clears the strict parent gate for the no-op body; confidence remains below final-audit range because the original external-wait virtual name and some helper/field names are still provisional.
- 2026-06-07 A001 supervisor correction audit:
  - What changed: corrected the [UID:0000WL][0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual](by-memory/0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual.md) method-family and open-question text after removing that page's parent attachment under the corrected 85/85 target assignment rule.
  - Evidence: the by-memory page still records the base `Thread` vtable slot plus derived worker-thread/download-thread slots, but keeps the STL fold-sharing caveat and sub-85 completion score as assignment blockers.
- 2026-06-07 A001 no-op virtual note:
  - What changed: updated the [UID:0000WL][0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual](by-memory/0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual.md) method-family and open-question text after attaching that by-memory page to this class.
  - Evidence: the by-memory page records the base `Thread` vtable slot plus derived worker-thread/download-thread slots and keeps the STL fold-sharing caveat as the reason final source spelling remains open.
- Before: reconstruction autogen metadata was unclassified.
- Changed to: marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000OR][Thread](by-file/Thread.md).
- Evidence: 2026-06-05 IDA MCP on `NexusTK.exe` (`md5 4247e04e20b65d6414c7238aa8ff5515`) confirmed representative base-thread method starts across the no-op virtual, constructor/destructor, stop/terminate/start, wait registration, dispatch, post helpers, thread entry, and scalar deleting destructor at `0x0041b6b0`, `0x00596250`, `0x00596400`, `0x00596540`, `0x005965c0`, `0x005965e0`, `0x005967d0`, `0x00596810`, `0x00596960`, `0x00596a00`, `0x00596af0`, and `0x00596bb0`; this page and parent [UID:0000OR][Thread](by-file/Thread.md) both meet the 80/80 parent gate. No C++ was emitted because the page is below the 95/95 reconstruction-code bar.
- 2026-06-02 wait-handle wrapper ownership update:
  - What existed before: the `0x005967d0` method-family row and open question treated the helper as a Socket-owned review item.
  - Changed to: documented as a base `Thread` wait-handle registration wrapper with Socket only as the observed caller.
  - Summary/evidence: [UID:0001JZ][0x005967d0-0x005967e5.SocketThreadEvent](by-memory/0x005967d0-0x005967e5.SocketThreadEvent.md) records IDA MCP body/caller/callee/raw-byte evidence showing only inherited `Thread` wait-count and wait-handle array writes.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:80`.
  - Summary/evidence: scored from the constructor/destructor/dispatch/post/thread-entry method map, broad derived-class caller evidence, queue/monitor/list ownership notes, and remaining ownership questions for the no-op virtual and wait-handle wrapper.
