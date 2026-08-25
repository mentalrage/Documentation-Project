*** UID:0000EV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "Thread.h"
#include "Singleton.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_UTIL_THREAD_H
#define NEXUSTK_UTIL_THREAD_H

#include <windows.h>
#include "LObject.h"

struct ThreadMessage
{
    int messageId;
    int arg1;
    int arg2;
    HANDLE resultEvent;
    int syncArg1;
    int syncArg2;
};

struct ThreadResultEntry
{
    HANDLE event;
    int result;
};

class RingBuffer;
class Monitor;
class List;

class Thread : public LObject
{
public:
    Thread(int messageCapacity);
    virtual ~Thread();

    virtual void StopThread();
    virtual void ForceTerminate();

    virtual void OnStart();
    virtual void OnThreadBegin();
    virtual int ThreadProc();
    virtual void OnThreadEnd();
    virtual void OnDispatchBegin();
    virtual void OnIdle();
    virtual void OnMessage(int messageId, int arg1, int arg2);
    virtual int OnMessageEx(int messageId, int syncArg1, int syncArg2,
                            int arg1, int arg2);
    virtual void OnWaitObject(int waitIndex);

    DWORD StartThread();
    DWORD SuspendThread();
    DWORD ResumeThread();

    void WaitForQueueDrain();
    int WaitForResult(HANDLE resultEvent);
    HANDLE AddWaitHandle(HANDLE handle);
    void RemoveLastWaitHandle();

    BOOL DispatchRequest(int messageId, int arg1, int arg2);
    BOOL DispatchPriorityRequest(int messageId, int arg1, int arg2);
    HANDLE DispatchRequestAndReturnEvent(int messageId, int syncArg1, int syncArg2, int arg1, int arg2);

private:
    static unsigned __stdcall ThreadEntry(void *context);

    DWORD m_waitTimeout;
    signed char m_waitHandleCount;
    HANDLE m_waitHandles[16];
    RingBuffer *m_messageQueue;
    RingBuffer *m_priorityQueue;
    Monitor *m_resultMonitor;
    List *m_resultList;
    HANDLE m_threadHandle;
    unsigned int m_threadId;
    unsigned char m_stopRequested;
};

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Thread

## Summary

`Thread` is the shared worker-thread base class. It owns Win32 thread and wait handles, two blocking `RingBuffer` message queues, a concrete `Monitor` guarding synchronous results, and a `List` of caller-created event/result records. Its complete virtual order is recovered from the base and derived vtables: `OnStart`, `OnThreadBegin`, `ThreadProc`, `OnThreadEnd`, `OnDispatchBegin`, `OnIdle`, `OnMessage`, `OnMessageEx`, and `OnWaitObject` follow the inherited/base slots. Historical `RequestSyncGate`, `OnDispatchEnd`, and derived-only Socket names are retained only as corrected assumptions, not current declarations.

## Likely Original Placement

- Source: [UID:0000OR][Thread](by-file/Thread.md)
- Proposed source pair: `util/Thread.cpp` and `util/Thread.h`
- Confidence: strong

## Method Families

| Range | Role |
| --- | --- |
| [UID:0000WL][0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual](by-memory/0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual.md) | Empty inherited external-wait callback at vtable offset `+0x34`; now attached to this class after Batch100 proved the `Thread::ThreadProc` call site and base/derived vtable slot layout. |
| `0x00596250-0x005963f2` | Constructor: accepts a queue/message-capacity argument, creates semaphore, queues, monitor, handler list, and suspended worker thread. |
| `0x00596400-0x00596534` | Destructor: closes thread/wait handles, deletes queues, closes pending sync events, deletes monitor/list. |
| `0x00596540-0x005965bf` | Graceful stop helper that posts stop message then terminates if still active. |
| `0x005965c0-0x005965cc` | Force terminate wrapper. |
| `0x005965d0-0x005965db` | Raw `Thread::SetWaitTimeout` helper: stores the timeout argument to `m_waitTimeout` at `this+0x04`; no current IDA function record or incoming xrefs. |
| `0x005965e0-0x005965f3` | `Thread::StartThread`: calls the folded/default vtable hook at `+0x14`, then Win32 `ResumeThread` on `m_threadHandle`; modeled function with six code xrefs. |
| `0x00596600-0x00596609` | Raw `Thread::SuspendThread` wrapper over `m_threadHandle`; no current IDA function record or incoming xrefs. |
| `0x00596610-0x00596619` | Raw `Thread::ResumeThread` wrapper over `m_threadHandle`; no current IDA function record or incoming xrefs. |
| `0x00596620-0x005967c7` | `Thread::WaitForQueueDrain()` and `Thread::WaitForResult(HANDLE)` synchronous queue/result helper family. |
| `0x005967d0-0x005967e5` | `Thread::AddWaitHandle(HANDLE)` exact child [UID:0001JZ][0x005967d0-0x005967e5.ThreadAddWaitHandleHelper](by-memory/0x005967d0-0x005967e5.ThreadAddWaitHandleHelper.md); Socket remains caller evidence only. |
| `0x005967f0-0x00596805` | `Thread::RemoveLastWaitHandle()` raw/exact split candidate; live Socket `CloseTransport` tail jump at `0x00577aef` corrects the old no-route/alias-pollution caveat. |
| `0x00596810-0x0059695e` | Exact [UID:0004CL][0x00596810-0x00596915.ThreadProc](by-memory/0x00596810-0x00596915.ThreadProc.md), `Thread::OnMessage(int,int,int)`, and `Thread::OnMessageEx(int,int,int,int,int)`. `ThreadProc` performs one priority/default dequeue per primary wake, publishes into caller-created result entries under `Monitor`, checks stop, then calls `OnIdle`. |
| `0x00596960-0x00596ae8` | Async/sync message post helpers: `Thread::DispatchRequest`, retained raw sibling `Thread::DispatchPriorityRequest` at `0x005969b0-0x00596a00`, and `Thread::DispatchRequestAndReturnEvent`. Current `simroot_v2/class_Thread.cpp` already emits parts of this family; older docs/generated owners may still attach nearby wait helpers to `CashShopRequest`. |
| `0x00596af0-0x00596bac` | `_beginthreadex` entry function. |
| `0x00596bb0-0x00596be8` | Scalar deleting destructor. |

## Evidence

- Constructor callers at `0x0041a69b`, `0x0045393b`, `0x004700dd`, `0x005281db`, and `0x00574812` show broad reuse by derived thread classes, including [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md).
- `RingBuffer` constructor is called twice from `Thread::Thread`, with element size `24`.
- B006 2026-07-07 MCP session `507affd6` confirms constructor callers push explicit queue/message-capacity values (`5`, `0x64`, and `0x800` observed) before calling `0x00596250`, and the constructor passes that argument to both `RingBuffer(24, messageCapacity)` allocations. The formal class declaration now uses `Thread(int messageCapacity)`; older generated `Thread();` spelling is stale declaration output, not current source evidence.
- `Monitor` and `List` are allocated inside `Thread::Thread`, confirming that thread message synchronization is generic utility infrastructure.
- IDA confirms all function starts in the main `0x00596250-0x00596be8` island.
- IDA and current `simroot_v2` confirm `0x00596960` is a generic queue post helper: it packs six dwords, enqueues through the queue pointer at `this + 76`, and signals the semaphore at `this + 12`. This is the helper reached by the packet-send wrapper at [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md).
- [UID:0003GY][0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper](by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md) also reaches `0x00596960` with `(this, messageId, payload, 0)`, but B002 2026-06-17 found no caller, vtable/data pointer, source-neighbor, or declaration route proving it is a direct `Thread` method. Treat it as dependency-only semantic evidence, not an emitted child.
- 2026-06-08 IDA MCP decompilation of `Thread::ThreadProc` at `0x00596810-0x00596915` confirms the base dispatch loop waits on `this + 0x0c` with count byte `this[8]`, routes primary queue work through vtable offsets `+0x24`, `+0x28`, `+0x2c`, and `+0x30`, and routes non-primary wait-handle signals through offset `+0x34`.
- 2026-06-08 vtable slot audit confirms `Thread` vtable `0x0062e26c` stores [UID:0000WL][0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual](by-memory/0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual.md) at slot index `13` / offset `+0x34`, and the `FileDownloader`, `MiniMapDownloader`, `BrowserThread`, and `MiscWorkThread` vtables retain that same inherited slot value.
- B003 2026-06-20 source-quality research resolves [UID:0001JY][0x00596620-0x005969b0.CashShopRequestWaitDispatch](by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md) as generic base `Thread` queue-drain/result-wait/wait-handle/worker-dispatch/post-helper infrastructure. The report proves command-id-2 queue-drain semantics, final working field/record layouts, `0x005967f0` liveness through Socket cleanup tail jump `0x00577aef`, and `0x005969b0` as the retained priority queue post sibling.
- B011 2026-07-07 MCP session `ef57d27f` reconfirmed [UID:0004CP][0x005969b0-0x00596a00.ThreadDispatchPriorityRequestRaw](by-memory/0x005969b0-0x00596a00.ThreadDispatchPriorityRequestRaw.md) as the retained raw no-xref priority-post sibling: `0x005969b0` is still not an IDA function, has zero code/data xrefs and zero VA/RVA/file-offset pointer-byte hits, writes to `m_priorityQueue` at `+0x50`, and returns `ReleaseSemaphore(m_waitHandles[0], 1, NULL)`. The same callback corrected [UID:0004CO][0x00596960-0x005969b0.ThreadDispatchRequest](by-memory/0x00596960-0x005969b0.ThreadDispatchRequest.md) to return `ReleaseSemaphore` after pushing to `m_messageQueue`, matching the modeled sibling decompile and the priority helper's raw instruction order.
- B013 2026-06-21 source-quality review independently validates the same `util/Thread.cpp` route and extends the declaration inventory: `StopThread`, `ForceTerminate`, `StartThread`, `SuspendThread`, `ResumeThread`, `ThreadEntry`, `WaitForQueueDrain`, `WaitForResult`, `AddWaitHandle`, `RemoveLastWaitHandle`, `ThreadProc`, `OnMessage`, `OnMessageEx`, `OnWaitObject`, `DispatchRequest`, `DispatchPriorityRequest`, and `DispatchRequestAndReturnEvent` are the current source-facing method/helper names. `CashShopRequest::*`, `Socket::QueueThreadEvent`, no-argument `Thread::OnSignaled()`, `Thread_00596bb0`, and queue names such as `m_pSendQueue`/`m_pRecvQueue` are retained only as generated or historical labels.
- B006 2026-07-07 raw lifecycle wrapper audit adds the missing `0x005965d0` wait-timeout setter and raw `0x00596600`/`0x00596610` suspend/resume wrappers to the class evidence. The wrappers are source-shaped but currently have no function records or xrefs, so exact child docs should carry raw/no-xref caveats. Vtable hook slots before `OnMessage` are concrete but not fully named: base vtable `0x0062e26c` has folded/default no-op entries at `+0x14`, `+0x18`, `+0x20`, `+0x24`, and `+0x28`; `StartThread` calls `+0x14`, while `ThreadEntry` calls `+0x18`, `+0x1c`, and `+0x20`.
- 2026-07-04 B009 UID0001CL callback keeps `m_resultGate` as the narrow Thread field name but historicalizes the `RequestSyncGate` type spelling: MCP session `eb7ce28b` reconfirmed that `0x00528710` / `0x00528720` live in the Monitor/MonitorCondition island and are source-emitted as `Monitor::Lock` / `Monitor::Unlock`, with no separate `RequestSyncGate` vtable or constructor evidence.
- The complete Thread declaration is a required downstream dependency for [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md) and other derived workers. Guarded `Thread.h` now includes `<windows.h>` for Win32 types and generated-complete `"LObject.h"` for the direct base; no incomplete base or implicit PCH definition is required.
- Thread.cpp now also includes `"Singleton.h"` immediately after `"Thread.h"`. The dependency is source-only: [UID:0000EW][ThreadMan](by-class/ThreadMan.md) is a direct `Singleton<ThreadMan>` consumer in the CPP stream, while the accepted `Thread.h` declaration and H channel remain unchanged.
- B008 2026-08-01 live reanalysis of [UID:0004CL][0x00596810-0x00596915.ThreadProc](by-memory/0x00596810-0x00596915.ThreadProc.md) reconfirmed `sub_596810` as a 261-byte/99-instruction virtual worker with five data-only vtable xrefs, one `RingBuffer_Dequeue`, no `List::Add`, caller-created result-entry scan/write, and stop-before-slot-`+0x28` timing. `RingBuffer::IsEmpty`/`Dequeue`, inline `List::GetCount`, virtual `List::GetElementAt`, and `Monitor::Lock`/`Unlock` are the exact source-facing dependencies.
- The base Thread vtable at `0x0062e26c` and FileDownloader, MiniMapDownloader, MiscWorkThread, and Socket vtables share `ThreadProc` at slot `+0x1c`. `StartThread` calls `+0x14`, `ThreadEntry` calls `+0x18`, `+0x1c`, and `+0x20`, `ThreadProc` calls `+0x24` before queue selection and `+0x28` after every non-stopping iteration, then uses `+0x2c`, `+0x30`, and `+0x34` for async, sync, and secondary-wait dispatch.

## Vtable Contract And Worker APIs

| Offset | Source-facing virtual | Binary/use evidence |
| --- | --- | --- |
| `+0x14` | `OnStart()` | Called by `StartThread` immediately before `ResumeThread`; Socket has a unique empty override at `0x00575d90`. |
| `+0x18` | `OnThreadBegin()` | Called by `ThreadEntry` immediately before `ThreadProc`. |
| `+0x1c` | `ThreadProc()` | Base body at `0x00596810`, inherited through five Thread-family vtables. |
| `+0x20` | `OnThreadEnd()` | Called by `ThreadEntry` immediately after `ThreadProc` returns. |
| `+0x24` | `OnDispatchBegin()` | Called on a primary semaphore wake before priority/default queue selection; observed base/derived entries are folded no-ops. |
| `+0x28` | `OnIdle()` | Called after every non-stopping wait iteration, including timeout/failure and secondary-handle paths; Socket overrides it with nonblocking receive polling. Historical `OnDispatchEnd` is too narrow. |
| `+0x2c` | `OnMessage(int,int,int)` | Asynchronous message dispatch for records without `resultEvent`. |
| `+0x30` | `OnMessageEx(int,int,int,int,int)` | Synchronous dispatch ordered as message id, sync args, then ordinary args. |
| `+0x34` | `OnWaitObject(int)` | Receives the nonzero wait index directly when it is below the handle count. The folded default body remains globally shared and must not be uniquely renamed in IDA. |

Queue/result API resolution:

- `m_priorityQueue` is tested first with `RingBuffer::IsEmpty`; `m_messageQueue` is the fallback. Exactly one selected record is removed through `RingBuffer::Dequeue(void *)` per primary semaphore wake.
- `ThreadMessage` is exactly 24 bytes in producer/consumer order: `messageId`, `arg1`, `arg2`, `resultEvent`, `syncArg1`, `syncArg2`.
- `ThreadResultEntry` is exactly eight bytes: caller event then integer result. `DispatchRequestAndReturnEvent` creates/registers the entry before queueing; `ThreadProc` does not append one.
- `m_resultMonitor` is a `Monitor *` at `+0x54`. It guards an inline `List::GetCount()` read and virtual `List::GetElementAt(int)` scan over `m_resultList` at `+0x58`; the result is written before unlock and `SetEvent`.

## Field And Record Layout

Current source-facing field names for the helper family:

| Offset | Current name/type | Role |
| --- | --- | --- |
| `+0x04` | `DWORD m_waitTimeout` | Worker-loop wait timeout. |
| `+0x08` | `signed char m_waitHandleCount` | Number of handles in `m_waitHandles`, including primary semaphore. |
| `+0x0c` | `HANDLE m_waitHandles[16]` | Primary wake semaphore plus secondary wait handles passed to `WaitForMultipleObjects`. |
| `+0x4c` | `RingBuffer *m_messageQueue` | Default `ThreadMessage` queue. |
| `+0x50` | `RingBuffer *m_priorityQueue` | Priority/high-priority `ThreadMessage` queue selected before the default queue. One record, not a full drain, is dequeued per wake. |
| `+0x54` | `Monitor *m_resultMonitor` | Concrete 16-byte Monitor object pointer guarding result-list search/write. Historical `RequestSyncGate *m_resultGate` wording is superseded; no separate type/vtable/constructor exists. |
| `+0x58` | `List *m_resultList` | 8-byte `{event,result}` records for synchronous calls. |
| `+0x5c` | `HANDLE m_threadHandle` | Worker thread handle. |
| `+0x60` | `unsigned int m_threadId` | Worker thread id, also used by ThreadMan/watch support. |
| `+0x64` | `unsigned char m_stopRequested` | Base stop flag set by message id `1`. |

Private record layouts:

```cpp
struct ThreadMessage
{
    int messageId;
    int arg1;
    int arg2;
    HANDLE resultEvent;
    int syncArg1;
    int syncArg2;
};

struct ThreadResultEntry
{
    HANDLE event;
    int result;
};
```

## Draft Declaration Inventory

The validator-managed H block now emits the complete declaration-level first-draft source for `Thread`, `ThreadMessage`, and `ThreadResultEntry` under guard `NEXUSTK_UTIL_THREAD_H`, after explicit `<windows.h>` and `"LObject.h"` dependencies. CPP is exactly `#include "Thread.h"`, `#include "Singleton.h"`, then `[[CHILDREN]]`, so exact method children emit implementations after the sibling declaration without a duplicate CPP-resident class.

The virtual order is binary-exact. The source spellings `OnStart`, `OnThreadBegin`, `OnThreadEnd`, `OnDispatchBegin`, and `OnIdle` are high-probability human names inferred from call timing, derived override behavior, and project style because original symbols are absent. That remaining spelling uncertainty is not permission to omit the slots or use decompiler labels.

The declaration uses `Monitor *m_resultMonitor`. The historical `RequestSyncGate *m_resultGate` alias is preserved in prose/history only; UID0001CL emits `0x00528710` / `0x00528720` as `Monitor::Lock` / `Monitor::Unlock` and Thread does not duplicate those bodies.

The normalized header guard follows the accepted projected path/stem convention; its exact historical macro spelling remains inferred. All existing methods, fields, records, Monitor compatibility notes, child routes, and open questions are preserved. The source split changes placement, not behavior or layout.

```cpp
class Thread : public LObject
{
public:
    Thread(int messageCapacity);
    virtual ~Thread();

    virtual void StopThread();
    virtual void ForceTerminate();

    virtual void OnStart();
    virtual void OnThreadBegin();
    virtual int ThreadProc();
    virtual void OnThreadEnd();
    virtual void OnDispatchBegin();
    virtual void OnIdle();
    virtual void OnMessage(int messageId, int arg1, int arg2);
    virtual int OnMessageEx(int messageId, int syncArg1, int syncArg2,
                            int arg1, int arg2);
    virtual void OnWaitObject(int waitIndex);

    DWORD StartThread();
    DWORD SuspendThread();
    DWORD ResumeThread();

    void WaitForQueueDrain();
    int WaitForResult(HANDLE resultEvent);
    HANDLE AddWaitHandle(HANDLE handle);
    void RemoveLastWaitHandle();

    BOOL DispatchRequest(int messageId, int arg1, int arg2);
    BOOL DispatchPriorityRequest(int messageId, int arg1, int arg2);
    HANDLE DispatchRequestAndReturnEvent(int messageId, int syncArg1, int syncArg2, int arg1, int arg2);

private:
    static unsigned __stdcall ThreadEntry(void *context);

    DWORD m_waitTimeout;
    signed char m_waitHandleCount;
    HANDLE m_waitHandles[16];
    RingBuffer *m_messageQueue;
    RingBuffer *m_priorityQueue;
    Monitor *m_resultMonitor;
    List *m_resultList;
    HANDLE m_threadHandle;
    unsigned int m_threadId;
    unsigned char m_stopRequested;
};
```

## Open Questions

- Exact original private/helper and virtual spellings cannot be recovered from symbols/PDB. Current names are evidence-backed, human source-facing selections. Behavior, ABI, slot order, field types, queue/list APIs, and source placement are resolved.
- The folded base bodies at `0x0041b6a0` and `0x0041b6b0` remain shared with unrelated methods and must retain neutral IDA identities. Their source declarations are `OnDispatchBegin`/`OnIdle` as applicable to folded slots and `OnWaitObject(int)` for the `+0x34` slot; no handwritten duplicate body or unique global rename is required.
- Historical `RequestSyncGate`, queue-drain, new-result-entry, `OnDispatchEnd`, Socket `NoOpVirtualHook`, and Socket `PollAndReceive` source spellings are resolved as superseded assumptions. They remain documented as history rather than current declaration blockers.

## Cross-References

- File: [UID:0000OR][Thread](by-file/Thread.md)
- Memory: [UID:0001JX][0x00596250-0x0059756e.ThreadAndThreadMan](by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md)
- Memory: [UID:0000WL][0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual](by-memory/0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual.md)
- Related classes: [UID:0000EW][ThreadMan](by-class/ThreadMan.md), [UID:0000C1][RingBuffer](by-class/RingBuffer.md), [UID:00008L][Monitor](by-class/Monitor.md), [UID:000079][List](by-class/List.md), [UID:00001A][BrowserThread](by-class/BrowserThread.md), [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md)
- Reusable template dependency consumed by `MiscWorkThread`: [UID:0004ZL][SingletonTemplate](by-type/by-template/SingletonTemplate.md)
- Item: [UID:0001JZ][0x005967d0-0x005967e5.ThreadAddWaitHandleHelper](by-memory/0x005967d0-0x005967e5.ThreadAddWaitHandleHelper.md)

## Changes

- 2026-08-01 B008 UID0004CL implementation callback:
  - Raised `91/92` to `93/94` while preserving owner/emitter [UID:0000OR][Thread](by-file/Thread.md).
  - Completed the formal virtual order from `OnStart` through `OnWaitObject`, replaced `RequestSyncGate *m_resultGate` with `Monitor *m_resultMonitor`, and retained exact `ThreadMessage`/`ThreadResultEntry` records and the complete `0x68` field layout.
  - Added exact one-message-per-wake queue selection, `IsEmpty`/`Dequeue`, inline `GetCount`, virtual `GetElementAt`, caller-created result publication, stop-before-`OnIdle`, five-vtable, and source-name inference evidence.
  - Historicalized the prior drain-loop, new-entry, RequestSyncGate, OnDispatchEnd, and Socket-derived spelling assumptions without deleting their provenance.
- 2026-08-01 B007 UID000305 support callback:
  - Preserved `91/92`, owner/emitter UID0000OR, and the complete guarded Thread.h formal channel.
  - Replaced the Thread.cpp root formal payload with the exact `Thread.h`, `Singleton.h`, then `[[CHILDREN]]` order required by the complete `ThreadMan : public LObject, public Singleton<ThreadMan>` definition.
  - Added the dependency evidence without changing Thread behavior, fields, virtual inventory, or header surface.

- 2026-07-07 B011 UID0004CP support callback:
  - What existed before: the open-question list still said supervisor-assigned exact child UIDs for `0x005967f0-0x00596805` and `0x005969b0-0x00596a00` were pending, even though [UID:0004CK][0x005967f0-0x00596805.ThreadRemoveLastWaitHandle](by-memory/0x005967f0-0x00596805.ThreadRemoveLastWaitHandle.md) and [UID:0004CP][0x005969b0-0x00596a00.ThreadDispatchPriorityRequestRaw](by-memory/0x005969b0-0x00596a00.ThreadDispatchPriorityRequestRaw.md) now exist.
  - Changed to: removed that stale open question and added current B011 support evidence for UID0004CP as the retained raw no-xref priority-post sibling plus the corrected dispatch-helper return-value policy.
  - Summary/evidence: B011 MCP session `ef57d27f` reconfirmed UID0004CP's no-function/zero-xref/zero-pointer-hit state, `m_priorityQueue` write at `+0x50`, and `ReleaseSemaphore` return; modeled [UID:0004CO][0x00596960-0x005969b0.ThreadDispatchRequest](by-memory/0x00596960-0x005969b0.ThreadDispatchRequest.md) decompiled to the same `ReleaseSemaphore` return policy.
- 2026-07-07 B006 UID0001JX implementation callback:
  - Changed formal declaration/support prose from no-argument `Thread()` to `Thread(int messageCapacity)` based on current MCP caller evidence and `RingBuffer(24, messageCapacity)` use.
  - Summary/evidence: added raw `SetWaitTimeout`, raw `SuspendThread`, raw `ResumeThread`, `StartThread` vtable-hook caveats, current generated-declaration mismatch warning, and no-overclaim guidance for folded/default vtable hook names before `OnMessage`.
- 2026-07-04 B009 UID0001CL support sync:
  - Historicalized the `RequestSyncGate *m_resultGate` wording as a compatibility alias for a Monitor-style Thread result gate, while preserving the field name/type in the current Thread declaration to avoid a broad Thread refactor.
  - Evidence: UID0001CL MCP session `eb7ce28b` reconfirmed `0x00528710` / `0x00528720` belong to the Monitor/MonitorCondition island and are emitted as `Monitor::Lock` / `Monitor::Unlock`; no separate `RequestSyncGate` vtable/constructor/source route exists for duplicate emission.
- 2026-06-21 B013 source-quality incorporation:
  - Kept: `COMPLETION:88`, `CONFIDENCE:89`, `CANONICAL_OWNER:0000OR`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000OR`.
  - Changed to: explicit B013 provenance, declaration inventory covering lifecycle wrappers, suspend/resume/start helpers, the `_beginthreadex` entry helper, and `ThreadResultEntry` naming; stale no-code language from the historical below-95 gate is superseded by the active declaration-only draft with `[[CHILDREN]]`.
  - Summary/evidence: B013 local PE review of `NexusTK.exe` (MD5 `4247E04E20B65D6414C7238AA8FF5515`) confirms constructor field writes, object size `0x68`, wait-handle count/array at `+0x08/+0x0c`, default/priority 24-byte queues at `+0x4c/+0x50`, result gate/list at `+0x54/+0x58`, thread handle/id at `+0x5c/+0x60`, stop flag at `+0x64`, `ThreadMessage`/`ThreadResultEntry` layouts, external wait callback `OnWaitObject(int)`, `RemoveLastWaitHandle` liveness through Socket cleanup, and stale CashShop/Socket/generated-owner rejections.
- 2026-06-20 B003 Rule 26 source-quality incorporation:
  - Before: `COMPLETION:86`, `CONFIDENCE:85`, with sync-send/post-message names, wait-handle fields, and `0x005967d0` helper spelling still listed as open.
  - Changed to: `COMPLETION:88`, `CONFIDENCE:89`, accepted current source-facing field names, `ThreadMessage`/`ThreadResultEntry` layouts, helper names/signatures, `RemoveLastWaitHandle` live tail-jump evidence, priority-post sibling policy, and declaration-level first-draft C++ with `[[CHILDREN]]`.
  - Summary/evidence: B003's report over [UID:0001JY][0x00596620-0x005969b0.CashShopRequestWaitDispatch](by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md) checked local disassembly, rel32 and pointer refs, Socket command fallback, `ThreadProc` queue priority, result-list synchronization, and support docs. The stale CashShop names are now treated only as filename/provenance residue.
- 2026-06-08 A001 Batch100 parent-gate audit:
  - Before: `COMPLETION:84`, `CONFIDENCE:80`.
  - After: `COMPLETION:86`, `CONFIDENCE:85`.
  - Evidence: live IDA MCP decompiled `Thread::ThreadProc`, confirmed the `WaitForMultipleObjects` non-primary-handle dispatch through vtable offset `+0x34`, and verified that the base `Thread` vtable plus `FileDownloader`, `MiniMapDownloader`, `BrowserThread`, and `MiscWorkThread` derived vtables all keep [UID:0000WL][0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual](by-memory/0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual.md) in that inherited slot. The class now clears the strict parent gate for the no-op body; confidence remains below final-audit range because the original external-wait virtual name and some helper/field names are still provisional.
- 2026-06-17 B002 dependency-only wrapper note:
  - Summary/evidence: added [UID:0003GY][0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper](by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md) as semantic evidence for the `0x00596960` queue primitive only. No Thread owner/emitter route is assigned for that wrapper without a caller/declaration path.
- 2026-06-07 A001 supervisor correction audit:
  - What changed: corrected the [UID:0000WL][0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual](by-memory/0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual.md) method-family and open-question text after removing that page's parent attachment under the corrected 85/85 target assignment rule.
  - Evidence: the by-memory page still records the base `Thread` vtable slot plus derived worker-thread/download-thread slots, but keeps the STL fold-sharing caveat and sub-85 completion score as assignment blockers.
- 2026-06-07 A001 no-op virtual note:
  - What changed: updated the [UID:0000WL][0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual](by-memory/0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual.md) method-family and open-question text after attaching that by-memory page to this class.
  - Evidence: the by-memory page records the base `Thread` vtable slot plus derived worker-thread/download-thread slots and keeps the STL fold-sharing caveat as the reason final source spelling remains open.
- Before: reconstruction autogen metadata was unclassified.
- Changed to: marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000OR][Thread](by-file/Thread.md).
- Evidence: 2026-06-05 IDA MCP on `NexusTK.exe` (`md5 4247e04e20b65d6414c7238aa8ff5515`) confirmed representative base-thread method starts across the no-op virtual, constructor/destructor, stop/terminate/start, wait registration, dispatch, post helpers, thread entry, and scalar deleting destructor at `0x0041b6b0`, `0x00596250`, `0x00596400`, `0x00596540`, `0x005965c0`, `0x005965e0`, `0x005967d0`, `0x00596810`, `0x00596960`, `0x00596a00`, `0x00596af0`, and `0x00596bb0`; this page and parent [UID:0000OR][Thread](by-file/Thread.md) both met the historical 80/80 parent gate. The old "no C++ below 95/95" conclusion is superseded by the active Rule 26/current-gate declaration-only draft C++ above; exact method bodies still belong to exact by-memory children.
- 2026-06-02 wait-handle wrapper ownership update:
  - What existed before: the `0x005967d0` method-family row and open question treated the helper as a Socket-owned review item.
  - Changed to: documented as a base `Thread` wait-handle registration wrapper with Socket only as the observed caller.
  - Summary/evidence: [UID:0001JZ][0x005967d0-0x005967e5.ThreadAddWaitHandleHelper](by-memory/0x005967d0-0x005967e5.ThreadAddWaitHandleHelper.md) records IDA MCP body/caller/callee/raw-byte evidence showing only inherited `Thread` wait-count and wait-handle array writes.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:80`.
  - Summary/evidence: scored from the constructor/destructor/dispatch/post/thread-entry method map, broad derived-class caller evidence, queue/monitor/list ownership notes, and remaining ownership questions for the no-op virtual and wait-handle wrapper.
- 2026-07-31 B004 UID0004HM implementation:
  - Changed score from `88/89` to `91/92`; owner/emitter remain [UID:0000OR][Thread](by-file/Thread.md).
  - Moved the complete existing Thread/record declaration without loss from CPP into guarded formal H after explicit `<windows.h>` and `"LObject.h"` dependencies.
  - Replaced CPP with exact sibling-header include plus child stream, making `Thread` a legal reusable complete base for [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md) without duplicate declarations or PCH assumptions.
  - Preserved every method, field, record, vtable/secondary-wait fact, Monitor compatibility caveat, child route, inferred-name limitation, and historical change.
