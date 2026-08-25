** TARGET-REPORT-UID:0000EV **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B013 Source-Quality Report: 0000EV Thread

Status: FINISHED

Assignment: B013 report-only Rule 26 source-quality pass for [UID:0000EV] `Thread`

Target: `E:\NTK\GhidraBridge\source-3\project-documentation\by-class\Thread.md`

Report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B013\research\0000EV-Thread-class-source-quality.md`

No by-* documentation, generated output, IDA database state, or `by-memory/-coverage-report.md` was edited for this pass.

## Recommendation Summary

Raise [UID:0000EV] `Thread` from `86/85` to `88/89`, keep `CANONICAL_OWNER:0000OR`, keep `RECONSTRUCTABLE:TRUE`, keep `EMITTER_UIDS:0000OR`, and populate a declaration-only class-level C++ block with `[[CHILDREN]]`. The target now satisfies the current code-entry gate: it is reconstructable, has a confirmed emitter route to [UID:0000OR] `Thread.cpp`, and `(88 + 89) / 2 > 85`.

Do not put full method bodies into the class page. The class page should emit the `Thread` declaration, resolved field layout, method prototypes, and child insertion point. Exact method bodies should remain on exact by-memory children. The existing old note saying no C++ was emitted because the page was below a `95/95` bar is stale under Supervisor Rule 20 and should be superseded.

Best current source route:

```text
NexusTK/util/Thread.h
NexusTK/util/Thread.cpp
```

Best current class relationship:

```text
Thread : public LObject
```

Best current high-probability helper names:

| Address | Recommended source-facing name/signature | Confidence |
| --- | --- | --- |
| `0x0041b6b0` | `virtual void OnWaitObject(int waitIndex);` empty default body | High for signature/role, medium-high for exact original spelling |
| `0x005965e0` | `DWORD StartThread();` | High |
| `0x00596600` | `DWORD SuspendThread();` | Medium-high; no direct callers found |
| `0x00596610` | `DWORD ResumeThread();` | Medium-high; no direct callers found |
| `0x00596620` | `void WaitForQueueDrain();` / `void FlushMessageQueue();` | High for behavior/signature, medium for original name |
| `0x00596760` | `int WaitForResult(HANDLE resultEvent);` | High |
| `0x005967d0` | `HANDLE AddWaitHandle(HANDLE handle);` | High |
| `0x005967f0` | `void RemoveLastWaitHandle();` | High for behavior, medium-high for original name |
| `0x00596810` | `virtual int ThreadProc();` | High |
| `0x00596920` | `virtual void OnMessage(int messageId, int arg1, int arg2);` | High |
| `0x00596940` | `virtual int OnMessageEx(int messageId, int syncArg1, int syncArg2, int arg1, int arg2);` | High for signature, medium-high for `OnMessageEx` spelling |
| `0x00596960` | `BOOL DispatchRequest(int messageId, int arg1, int arg2);` | High |
| `0x005969b0` | `BOOL DispatchPriorityRequest(int messageId, int arg1, int arg2);` | Medium; raw modeled-by-bytes sibling has no direct callers |
| `0x00596a00` | `HANDLE DispatchRequestAndReturnEvent(int messageId, int syncArg1, int syncArg2, int arg1, int arg2);` | High for behavior/signature order, medium for exact name |
| `0x00596af0` | `static unsigned __stdcall ThreadEntry(void *context);` | High |

The generated names `CashShopRequest::*`, `Socket::QueueThreadEvent`, `Thread::OnSignaled()` with no argument, `m_pSendQueue` / `m_pRecvQueue` as final names, `Thread_00596bb0`, and stale old-gate comments should be treated as generated or historical labels, not final source.

## Evidence Checked

Rules and policy:

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B013/goal.md`, including the Implementation Callback Detail Contract
- `.codex/AGENTS.md`
- `source-3/project-documentation/by-structure.md`
- `source-3/project-documentation/inference_research.md`
- `source-3/project-documentation/by-project-structure/proposed-source-tree.md`
- `source-3/project-documentation/by-class/-guidance.md`

Primary/support docs:

- [UID:0000EV] `by-class/Thread.md`
- [UID:0000OR] `by-file/Thread.md`
- [UID:0000EW] `by-class/ThreadMan.md`
- [UID:0001JX] `by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md`
- [UID:0001JY] `by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md`
- [UID:0001JZ] `by-memory/0x005967d0-0x005967e5.ThreadAddWaitHandleHelper.md`
- [UID:0000WL] `by-memory/0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual.md`
- [UID:0003GY] `by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md`
- [UID:0001HU] `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`
- [UID:0001HT] `by-memory/0x00574b90-0x00575377.CashShopRequestSendQueue.md`
- [UID:0000Q5] `by-global/g_packetSender.md`
- [UID:0001P0] `by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md`
- [UID:00008I] `by-class/MiscWorkThread.md`
- [UID:00001A] `by-class/BrowserThread.md`
- [UID:00004W] `by-class/FileDownloader.md`
- [UID:00008D] `by-class/MiniMapDownloader.md`
- [UID:00026P] `by-memory/0x0062e268-0x0062e334.ThreadReadOnlyData.md`
- [UID:0001WA] `by-type/by-struct/ThreadManLayout.md`
- [UID:0001WB] `by-type/by-struct/ThreadManWatchRecord.md`
- [UID:0001SR] `by-type/by-enum/ThreadManMessageId.md`

Prior B reports:

- `tools/leaser/Agents/Agent-B001/research/executed/0003GY-UnreferencedThreadDispatchWrapper-current-source-routing.md`
- `tools/leaser/Agents/Agent-B002/research/executed/0003GY-thread-dispatch-wrapper-source-quality.md`
- `tools/leaser/Agents/Agent-B003/research/executed/00026P-ThreadReadOnlyData-source-quality.md`

Generated output checked only as a pollution/source-name lead:

- `source-3/simroot_v2/class_Thread.cpp`
- `source-3/simroot_v2/class_ThreadMan.cpp`
- `source-3/simroot_v2/class_Socket.cpp`
- `source-3/simroot_v2/class_CashShopRequest.cpp`
- broader `rg` scan for `DispatchRequest`, `596960`, `596a00`, `5967d0`, `CashShopRequest`, and `Socket`

Local executable evidence:

```text
Path: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
Image base: 0x00400000
MD5: 4247E04E20B65D6414C7238AA8FF5515
SHA256: 9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632
```

Sections parsed:

```text
.text  0x00401000-0x0060c600  raw 0x00000400+0x20b600
.rdata 0x0060d000-0x0066c200  raw 0x0020ba00+0x05f200
.data  0x0066d000-0x0069ce24  raw 0x0026ac00+0x00d800
.rsrc  0x0069d000-0x006b2e00  raw 0x00278400+0x015e00
```

Validation dry run:

> Executable block R001 was removed from this report and preserved verbatim in [0000EV-Thread-class-source-quality-removed.md](0000EV-Thread-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result: `ok: 1`; dry run only, no edits.

## Binary Findings

### Constructor And Layout

Local Capstone disassembly of `0x00596250-0x005963f2` confirms the layout and dependencies:

- Calls `LObject` construction at `0x004f4a80`.
- Installs the `Thread` vtable at `0x0062e26c`.
- Writes `0xffffffff` at `this+0x04`; this is the timeout passed to `WaitForMultipleObjects`.
- Clears byte `this+0x08`, then creates a Win32 semaphore and stores it as wait handle index 0 at `this+0x0c`.
- Allocates two `RingBuffer` objects with element size `0x18` / 24 and caller-provided `messageSize`; stores them at `this+0x4c` and `this+0x50`.
- Allocates a `Monitor` at `this+0x54`.
- Allocates a `List(8, 16)` at `this+0x58`; entries are 8-byte `{HANDLE event; int result;}` records.
- Starts `_beginthreadex` suspended with entry `0x00596af0`, `this` as context, create flag `4`, and thread-id out slot `this+0x60`; stores the thread handle at `this+0x5c`.
- Clears stop flag byte `this+0x64`.

Best current field layout:

```text
0x00  LObject/vptr base
0x04  inherited/base wait timeout used by WaitForMultipleObjects
0x08  signed char m_waitHandleCount
0x09  padding
0x0c  HANDLE m_waitHandles[16]; index 0 is the semaphore
0x4c  RingBuffer *m_messageQueue; default request queue
0x50  RingBuffer *m_priorityQueue; checked before +0x4c, only raw 0x005969b0 poster currently known
0x54  Monitor *m_resultMonitor
0x58  List *m_resultList; element size 8
0x5c  HANDLE m_threadHandle
0x60  unsigned int m_threadId
0x64  unsigned char m_stopRequested
0x65  padding
0x68  observed object size
```

The generated names `m_pSendQueue` and `m_pRecvQueue` are not safe as final field names. The binary only proves the dispatch order: `+0x50` is checked first and `+0x4c` second, while all observed public request producers call the `+0x4c` poster at `0x00596960`.

### Message Record Layout

Both `RingBuffer` instances use 24-byte elements. `Thread::ThreadProc` dequeues a 24-byte stack record and dispatches it as:

```text
offset +0x00: messageId
offset +0x04: arg1
offset +0x08: arg2
offset +0x0c: resultEvent
offset +0x10: syncArg1
offset +0x14: syncArg2
```

If `resultEvent == 0`, `ThreadProc` calls vtable offset `+0x2c`:

```cpp
OnMessage(messageId, arg1, arg2);
```

If `resultEvent != 0`, `ThreadProc` calls vtable offset `+0x30`:

```cpp
result = OnMessageEx(messageId, syncArg1, syncArg2, arg1, arg2);
```

The two hidden fields after `resultEvent` are not generic padding. `0x00596a00` writes caller arguments into `syncArg1` and `syncArg2`, and `ThreadProc` passes them ahead of `arg1` and `arg2` to the synchronous virtual. Current docs should stop describing the final two dwords only as `reserved` without noting the synchronous handler path.

### Wait And Result Record Layout

The list at `this+0x58` is constructed as `List(8, 16)` and stores:

```cpp
struct ThreadResultEntry {
    HANDLE event;
    int result;
};
```

Evidence:

- `0x00596620` inserts a one-element stack record whose first dword is the event handle before posting a barrier message.
- `0x00596760` waits on a supplied event, scans `this+0x58` for a matching first dword, returns the second dword when found, closes the event, removes the entry, and unlocks.
- `ThreadProc` stores the synchronous virtual return value at entry offset `+4`, then calls `SetEvent` on the queued record's event handle.
- The destructor scans the same list backward and closes any nonzero event handle at entry offset `+0`.

### Vtable And External Wait Callback

The local vtable scan confirms:

```text
Thread vtable base 0x0062e26c
slot 00 +0x00 0x00596bb0 scalar deleting destructor
slot 03 +0x0c 0x00596540 StopThread
slot 04 +0x10 0x005965c0 ForceTerminate
slot 07 +0x1c 0x00596810 ThreadProc
slot 11 +0x2c 0x00596920 OnMessage
slot 12 +0x30 0x00596940 OnMessageEx
slot 13 +0x34 0x0041b6b0 external wait callback default body
```

`0x0041b6b0` is exactly `ret 4`, so it consumes one stack argument. `ThreadProc` passes the non-primary `WaitForMultipleObjects` result index to vtable offset `+0x34`. The generated `Thread::OnSignaled()` with no parameter is therefore wrong. Best current source-facing declaration:

```cpp
virtual void OnWaitObject(int waitIndex);
```

Alternative name `OnWaitHandleSignaled` is semantically accurate but less likely to be a short original mid-2000s name. `OnWaitObject` should be documented as the current working name, not final PDB proof.

The body is compiler-folded with unrelated STL vtable entries, but that does not change the direct `Thread` source declaration. Fold-sharing is a codegen caveat, not an ownership blocker.

### Helper Reachability

Corrected direct PE scan results:

```text
0x00596250 constructor: direct calls at 0x0041a69b, 0x0045393b, 0x004700dd, 0x005281db, 0x00574812.
0x00596540 StopThread: six direct calls and six vtable slots in derived/base tables.
0x005965c0 ForceTerminate: no direct calls, six vtable slots.
0x005965e0 StartThread: six direct calls from FileDownloader, MiniMapDownloader, BrowserThread, Application startup, and MiscWorkThread construction paths.
0x00596600 SuspendThread wrapper: no direct calls or data slots found.
0x00596610 ResumeThread wrapper: no direct calls or data slots found.
0x00596620 queue-drain barrier: nine direct calls.
0x00596760 WaitForResult: six direct calls.
0x005967d0 AddWaitHandle: direct calls at 0x005764cc and 0x0057773f in Socket serial/transport setup.
0x005967f0 RemoveLastWaitHandle: direct jump at 0x00577aef in Socket transport cleanup after closing field +0x1d55c.
0x00596810 ThreadProc: vtable/data refs at FileDownloader, MiniMapDownloader, MiscWorkThread, Socket, and Thread tables.
0x00596920 OnMessage: direct calls from MiscWorkThread/Socket fallback paths plus vtable slots in BrowserThread and Thread.
0x00596940 OnMessageEx: Socket fallback jmp plus vtable slots in FileDownloader/MiniMapDownloader/BrowserThread/MiscWorkThread/Thread.
0x00596960 DispatchRequest: 22 direct calls across downloader, MiscWorkThread, Socket command wrappers, packet-send wrappers, and the orphan 0003GY wrapper.
0x005969b0 priority-queue poster: no direct calls or data slots found.
0x00596a00 event-returning dispatch: one direct caller at 0x00574b3e in the Socket event wrapper family.
0x00596af0 ThreadEntry: address stored in the constructor at 0x0059636c.
0x00596bb0 scalar deleting destructor: vtable slot at 0x0062e26c.
0x0041b6b0 OnWaitObject default: seven data refs, including base/derived Thread slots and unrelated STL fold-sharing refs.
```

Important correction for support docs: `0x005967f0` is not completely unreferenced. It has a direct tail-jump from Socket cleanup at `0x00577aef`. The jump occurs after the Socket path closes `this+0x1d55c`, clears it, restores `ecx` to the Socket/Thread-derived object, and then jumps into `Thread::RemoveLastWaitHandle`.

## Source-Quality Resolutions

### Owner And Source File

Keep [UID:0000EV] owned/emitted through [UID:0000OR] `Thread`, proposed path `NexusTK/util/Thread.cpp` / `Thread.h`.

Reasons:

- The constructor/destructor/dispatch/thread-entry island is contiguous at `0x00596250-0x00596be8`.
- The source-file page already owns the shared Thread/ThreadMan root at `89/85`.
- Derived classes consume the base constructor, start helper, vtable slots, queue dispatch, and fallback handlers; they do not own the base implementation.
- Socket is only the observed direct consumer of `AddWaitHandle` / `RemoveLastWaitHandle`; both bodies mutate the inherited base wait-count/handle-array fields.
- CashShopRequest is stale generated naming around packet-send wrappers and FileDownloader request helpers. It is not the owner of the base queue primitives.

Rejected placements:

- `Socket.cpp`: rejected for `0x005967d0` and `0x005967f0`. Socket calls the helpers for serial/transport event registration and cleanup, but the helpers only touch base `Thread` fields and are called with `ecx` as the derived object.
- `CashShopRequest.cpp`: rejected for `0x00596620`, `0x00596760`, `0x00596960`, and Socket send wrappers. Current `g_packetSender` evidence is Socket-owned; FileDownloader has separate `g_pCashShopRequest`/`g_pFileDownloader` storage; the base helpers are generic `Thread`.
- `FileDownloader.cpp`: rejected for base `StartThread` and `DispatchRequest`; FileDownloader uses them but does not own them.
- `Browser.cpp`, `MiniMap.cpp`, `MiscWorkThread.cpp`: rejected for the same reason. These classes derive from or use `Thread` but keep their feature-specific overrides and request wrappers in feature modules.
- `ThreadMan.cpp` as a separate source file: possible exact original split remains unproven, but current source tree and memory/data island evidence favor the existing `util/Thread.cpp` route for both `Thread` and `ThreadMan`.

### Relationship To ThreadMan

`ThreadMan` is a companion watchdog/message singleton in the same file, not the owner of `Thread` methods.

Relevant crossing evidence:

- `ThreadManWatchRecord +0x08` caches `*(threadObject + 0x60)`, matching `Thread::m_threadId`.
- `ThreadManMessageId` values `0x0464-0x0468` are Win32 worker-thread messages, separate from the 24-byte `ThreadMessage` queue records.
- `ThreadMan` raw wrappers and raw watch-list helpers should remain `ThreadMan` semantic children under the same [UID:0000OR] file root.

### Sync Send / Post Helpers

`0x00596620` is best described as a queue-drain or sync barrier. It has no explicit parameters, creates an event, registers the event in `m_resultList`, posts message id `2` with only the `resultEvent` field set, releases the semaphore, waits indefinitely, removes the result-list entry, and closes/unlocks. This is not a CashShop helper and not a general `SendMessage` overload because no caller-supplied message id or payload is passed. The generated name `SubmitAndWait` is a useful behavior lead but too vague. Recommended docs should use:

```text
Thread::WaitForQueueDrain()
```

with `Thread::FlushMessageQueue()` noted as an acceptable alternative if later caller naming points that way.

`0x00596760` should be documented as:

```text
int Thread::WaitForResult(HANDLE resultEvent)
```

It returns the stored result value when a matching `ThreadResultEntry` is found. The generated return type `HANDLE` is not semantically correct; the return is a result integer/payload dword, not another event handle.

`0x00596960` should stay:

```text
BOOL Thread::DispatchRequest(int messageId, int arg1, int arg2)
```

This is the default request poster to `m_messageQueue` at `+0x4c`.

`0x005969b0-0x00596a00` should be documented as a sibling priority-queue poster over `this+0x50`, not hidden padding. It has the same body shape as `0x00596960` except the queue pointer is `+0x50`. No direct call/pointer route was found, so it should either become an exact child page named `ThreadDispatchPriorityRequestRaw` / `ThreadPostPriorityMessageRaw` or be incorporated into a future exact post-helper child with blank formal C++ until reachability/name evidence improves.

`0x00596a00` is the event-returning synchronous poster. Exact explicit argument order is:

```cpp
HANDLE Thread::DispatchRequestAndReturnEvent(
    int messageId,  // [ebp+0x08], record +0x00
    int syncArg1,   // [ebp+0x0c], record +0x10
    int syncArg2,   // [ebp+0x10], record +0x14
    int arg1,       // [ebp+0x14], record +0x04
    int arg2);      // [ebp+0x18], record +0x08
```

It allocates a manual-reset=false, initial-state=false event with `CreateEventW(NULL, FALSE, FALSE, NULL)`, registers `{event, 0}` in `m_resultList`, enqueues the 24-byte record to `m_messageQueue`, releases the semaphore, and returns the event handle. The only direct caller at `0x00574b3e` passes `(0x0c, statusByteOut, 1, 0, 0)`, which `ThreadProc` later delivers to `OnMessageEx(0x0c, statusByteOut, 1, 0, 0)`.

### Wait-Handle Helpers

`0x005967d0` should stay assigned to [UID:0000OR] as `Thread::AddWaitHandle(HANDLE handle)`. It appends the handle at:

```text
this + 0x0c + 4 * (signed char)this[0x08]
```

then increments `this[0x08]` and returns the same handle.

`0x005967f0` should be promoted in docs from "raw/unreferenced alias" to a real remove-last wait-handle helper:

```cpp
void Thread::RemoveLastWaitHandle();
```

It decrements `m_waitHandleCount` and clears the former last handle slot. The direct jump from Socket cleanup at `0x00577aef` means this is live cleanup support for the same serial/overlapped event added by `0x005967d0`.

Best future split: create an exact child for `0x005967f0-0x00596805.ThreadRemoveLastWaitHandleHelper.md`. It is currently trapped inside [UID:0001JY] and deserves the same exact-child treatment as [UID:0001JZ].

### Default Virtuals And Compiler Glue

The following are source declarations but not feature methods:

- `0x0041b6b0`: empty `Thread::OnWaitObject(int waitIndex)` default body, folded with STL vtable users.
- `0x00596bb0`: scalar deleting destructor. Source should be `virtual ~Thread()`, not a handwritten `Thread_00596bb0` class.
- `0x00596af0`: `_beginthreadex` entry. Source should be a `static unsigned __stdcall ThreadEntry(void *)` helper or local file function, not a class artifact.

The class page can declare virtual methods and put `[[CHILDREN]]`. The exact compiler-generated deleting destructor body should not be represented as a source method body.

## First-Draft C++ Recommendation

Populate [UID:0000EV] `Thread.md` with this declaration-only class shell. This is source-style C++ for the class page; exact method bodies remain on by-memory children.

```cpp
class RingBuffer;
class Monitor;
class List;

struct ThreadResultEntry
{
    HANDLE event;
    int result;
};

struct ThreadMessage
{
    int messageId;
    int arg1;
    int arg2;
    HANDLE resultEvent;
    int syncArg1;
    int syncArg2;
};

class Thread : public LObject
{
public:
    explicit Thread(int messageSize);
    virtual ~Thread();

    virtual BOOL StopThread();
    virtual BOOL ForceTerminate();

    virtual void OnStart();
    virtual void OnThreadBegin();
    virtual int ThreadProc();
    virtual void OnThreadEnd();
    virtual void OnDispatchBegin();
    virtual void OnDispatchEnd();
    virtual void OnMessage(int messageId, int arg1, int arg2);
    virtual int OnMessageEx(int messageId, int syncArg1, int syncArg2, int arg1, int arg2);
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

protected:
    signed char m_waitHandleCount;       // +0x08
    char m_waitHandlePadding[3];         // +0x09..+0x0b
    HANDLE m_waitHandles[16];            // +0x0c; index 0 is the worker semaphore.
    RingBuffer *m_messageQueue;          // +0x4c; default request queue.
    RingBuffer *m_priorityQueue;         // +0x50; checked before m_messageQueue.
    Monitor *m_resultMonitor;            // +0x54
    List *m_resultList;                  // +0x58; ThreadResultEntry records.
    HANDLE m_threadHandle;               // +0x5c
    unsigned int m_threadId;             // +0x60
    unsigned char m_stopRequested;        // +0x64
    char m_threadPadding[3];             // +0x65..+0x67

    [[CHILDREN]]
};
```

Notes for implementation callback:

- If the supervisor is uncomfortable with the inferred hook names `OnStart`, `OnThreadBegin`, `OnThreadEnd`, `OnDispatchBegin`, and `OnDispatchEnd`, keep them as documented provisional names in the class page. Do not omit the slots entirely; derived vtables and `ThreadEntry`/`ThreadProc` call them.
- Do not declare `this+0x04` as a `Thread` private member in the class shell unless `LObject` is later proven not to own it. The constructor writes it after base construction and `ThreadProc` reads it as the wait timeout, but it sits in the apparent `LObject` base tail.
- The exact body for `OnWaitObject(int)` can be emitted by [UID:0000WL] after support update:

```cpp
void Thread::OnWaitObject(int)
{
}
```

- Exact bodies for `AddWaitHandle`, `RemoveLastWaitHandle`, `WaitForResult`, `WaitForQueueDrain`, and the dispatch helpers should be emitted by exact by-memory child pages. Do not paste them into the class page.

## Exact Target Doc Changes Recommended

Apply these to `by-class/Thread.md` only after supervisor callback.

1. Replace metadata:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

2. Populate `RECONSTRUCTION_CPP CODE:BEGIN/END` with the declaration-only C++ block from the previous section.

3. Replace the summary with wording that includes the field layout and queues:

```markdown
`Thread` is the shared `LObject`-derived worker-thread base. It owns a wait-handle array headed by a worker semaphore, two 24-byte-record `RingBuffer` queues, a `Monitor` and result-list used for event-backed synchronous messages, a suspended `_beginthreadex` worker, and virtual hooks for queue dispatch and external wait-handle signals.
```

4. Add a `## Field Layout` section with the `+0x08` through `+0x64` layout listed above, plus a note that `+0x04` is the inherited/base wait timeout.

5. Add a `## Message Records` section with `ThreadMessage` and `ThreadResultEntry` layouts and the `OnMessage` / `OnMessageEx` dispatch order.

6. Replace `## Method Families` with a more exact table:

```markdown
| Range | Role |
| --- | --- |
| [UID:0000WL][0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual](by-memory/0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual.md) | Empty `Thread::OnWaitObject(int waitIndex)` default virtual at vtable `+0x34`; exact source spelling still inferred, but the `ret 4` body and `ThreadProc` call prove one argument. |
| `0x00596250-0x005963f2` | `Thread::Thread(int messageSize)`: constructs base, semaphore, two `RingBuffer(24, messageSize)` queues, monitor, result list, and suspended worker. |
| `0x00596400-0x00596534` | `Thread::~Thread()`: closes thread/wait handles, deletes queues, closes pending result events, deletes result list/monitor, and destroys `LObject`. |
| `0x00596540-0x005965bf` | `StopThread`: posts stop message id `1`, releases the semaphore, waits briefly, then terminates if still active. |
| `0x005965c0-0x005965cc` | `ForceTerminate`: direct `TerminateThread` wrapper. |
| `0x005965e0-0x005965f3` | `StartThread`: calls the pre-start virtual at `+0x14`, then resumes the worker. |
| `0x00596600-0x00596609` | `SuspendThread` wrapper over `m_threadHandle`; no direct callers found in the scanned PE. |
| `0x00596610-0x00596619` | `ResumeThread` wrapper over `m_threadHandle`; no direct callers found in the scanned PE. |
| `0x00596620-0x0059675e` | `WaitForQueueDrain` / queue-drain sync barrier: posts message id `2` with a result event and waits for worker acknowledgement. |
| `0x00596760-0x005967c7` | `WaitForResult(HANDLE)`: waits on a returned event, retrieves the result-list payload, closes/removes the entry, and unlocks. |
| `0x005967d0-0x005967e5` | `AddWaitHandle(HANDLE)`: appends a secondary wait handle to `m_waitHandles`. |
| `0x005967f0-0x00596805` | `RemoveLastWaitHandle()`: decrements `m_waitHandleCount` and clears the former last slot; Socket cleanup tail-jumps here at `0x00577aef`. |
| `0x00596810-0x00596915` | `ThreadProc`: sleeps, waits on semaphore/registered handles, drains priority/default queues, calls virtual handlers, stores sync results, and exits on stop flag. |
| `0x00596920-0x00596931` | Base `OnMessage`: stop-message id `1` sets `m_stopRequested`. |
| `0x00596940-0x0059695e` | Base `OnMessageEx`: stop-message id `1` sets `m_stopRequested` and returns `0`. |
| `0x00596960-0x005969b0` | `DispatchRequest`: enqueues `{messageId,arg1,arg2,0,0,0}` to `m_messageQueue` and releases the semaphore. |
| `0x005969b0-0x00596a00` | Priority/sibling request poster to `m_priorityQueue`; raw body has no direct callers and needs exact child/source-name treatment before formal body C++. |
| `0x00596a00-0x00596ae8` | `DispatchRequestAndReturnEvent`: creates/registers a result event and enqueues an event-backed request record. |
| `0x00596af0-0x00596bac` | `_beginthreadex` entry helper; calls thread begin/proc/end virtual slots and handles exception reporting. |
| `0x00596bb0-0x00596be8` | Scalar deleting destructor wrapper; compiler-generated source representation is `virtual ~Thread()`. |
```

7. Replace the open questions with closed/current caveats:

```markdown
- Helper behavior and signatures are now resolved enough for declaration-level C++; exact original spellings for `WaitForQueueDrain`, `DispatchPriorityRequest`, and `OnWaitObject` remain inferred rather than PDB-proven.
- `0x005969b0-0x00596a00` should be split or documented as a raw priority-queue post helper before method-body C++ is emitted.
- `0x005967f0-0x00596805` should receive an exact child page because Socket cleanup directly tail-jumps to it.
- `0x0041b6b0` remains a folded empty body shared with unrelated STL vtable slots, but direct Thread vtable/ThreadProc evidence proves the Thread declaration.
```

8. Add a change-log entry:

```markdown
- 2026-06-19 B013 source-quality pass:
  - Recommended `86/85 -> 88/89`, declaration-only class C++ with `[[CHILDREN]]`, and current-gate replacement for the stale below-95 no-code note.
  - Local PE/Capstone scan of `NexusTK.exe` (MD5 `4247E04E20B65D6414C7238AA8FF5515`) confirmed constructor field writes, object size `0x68`, wait-handle array at `+0x0c`, queues at `+0x4c/+0x50`, result monitor/list at `+0x54/+0x58`, thread handle/id at `+0x5c/+0x60`, stop flag at `+0x64`, `ThreadMessage`/`ThreadResultEntry` layouts, external wait callback signature, helper xrefs, and stale CashShop/Socket ownership rejections.
```

## Support-Doc Updates Recommended

### by-file/Thread.md

Add B013 details to `Generated Output Caveats` and `Evidence`:

- `0x00596620` is a base `Thread` queue-drain barrier, not a CashShopRequest method.
- `0x00596760` is a base `Thread::WaitForResult(HANDLE)` helper returning a result dword, not a HANDLE source value.
- `0x005967d0` and `0x005967f0` are paired base wait-handle add/remove helpers. Socket setup/cleanup are consumers only.
- `0x005969b0-0x00596a00` is real source-shaped priority/sibling queue-post bytes to queue `+0x50`; it needs exact child treatment or explicit raw-helper caveat.
- Class-level C++ for `Thread` should be declaration-only with `[[CHILDREN]]`; method bodies belong to exact children.

### by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md

Recommended title change inside the file, without necessarily renaming the path:

```markdown
# 0x00596620-0x005969b0 Thread Message Dispatch Helpers
```

Recommended score:

```text
COMPLETION:87
CONFIDENCE:88
```

Required factual updates:

- Replace old "active `90/90+` final-source gate" wording with current combined-score/emitter gate and a target-specific no-code reason: this page is an aggregate over multiple helper bodies and padding; method-body C++ needs exact children.
- Document `0x00596620` as `WaitForQueueDrain` / queue-drain barrier.
- Document `0x00596760` as `int WaitForResult(HANDLE resultEvent)`.
- Update `0x005967f0` from no-direct-caller caveat to live Socket cleanup tail-jump evidence at `0x00577aef`.
- Document `0x005969b0-0x00596a00` as real priority/sibling queue post helper outside the current page's exclusive end and recommend exact child or sibling documentation.
- Replace `reserved` wording for message slots `+0x10/+0x14` with synchronous handler argument wording.

### by-memory/0x005967d0-0x005967e5.ThreadAddWaitHandleHelper.md

Recommended score:

```text
COMPLETION:89
CONFIDENCE:90
```

Recommended C++ if supervisor elects support-child C++:

```cpp
HANDLE Thread::AddWaitHandle(HANDLE handle)
{
    m_waitHandles[m_waitHandleCount] = handle;
    ++m_waitHandleCount;
    return handle;
}
```

Required notes:

- Best source-facing field names: `m_waitHandleCount` and `m_waitHandles`.
- Pair with future exact child `0x005967f0-0x00596805.ThreadRemoveLastWaitHandleHelper.md`.
- Socket callers at `0x005764cc` and `0x0057773f` are consumer evidence only.

### by-memory/0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual.md

Recommended update:

- Current working name: `Thread::OnWaitObject(int waitIndex)`.
- The no-code reason should not cite the old `95/95` gate. Either emit the empty body after class C++ adoption, or keep blank only if the supervisor wants to wait for exact original spelling. The safety issue is name spelling/fold-sharing, not code behavior.
- Correct generated `OnSignaled()` with no argument to one-argument signature.

Recommended C++ if accepted:

```cpp
void Thread::OnWaitObject(int)
{
}
```

### by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md

Recommended score:

```text
COMPLETION:87
CONFIDENCE:88
```

Required updates:

- Replace stale coverage/score text and old final-source gate wording.
- Record B013 field layout and message/result record findings as aggregate support for `Thread`.
- Record `0x005967f0` live Socket cleanup tail-jump.
- Keep aggregate C++ blank: it spans Thread and ThreadMan methods, raw wrappers, child pages, and padding. Source bodies should emit through exact children and class/file pages.

### by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md

No metadata change. Keep `86/86`, `CANONICAL_OWNER:NONE`, blank emitters, and blank formal C++. It remains dependency-only evidence for `0x00596960`, not a `Thread` child.

### by-class/ThreadMan.md and ThreadMan support docs

No score change required for this target. Add only a cross-note if desired:

- `ThreadManWatchRecord.threadIdentity` / cached identity reads `Thread +0x60`, now named `Thread::m_threadId`.
- This supports the same-file `Thread.cpp` relationship but does not make `ThreadMan` own `Thread` methods.

## Exact Coverage Text

Do not edit coverage in this B-report pass. The following is exact replacement text for supervisor-owned coverage files if the recommended target/support changes are accepted.

### by-class/-coverage-report.md

Replace the [UID:0000EV] row with:

```markdown
- [UID:0000EV][Thread](by-class/Thread.md) : reconstructable : 88% : strong : B013 2026-06-19 source-quality pass resolves the shared worker-thread base under [UID:0000OR][Thread](by-file/Thread.md): declaration-only class C++ with `[[CHILDREN]]`, `LObject` base, wait-handle count/array at `+0x08/+0x0c`, default and priority 24-byte `RingBuffer` queues at `+0x4c/+0x50`, result monitor/list at `+0x54/+0x58`, thread handle/id at `+0x5c/+0x60`, stop flag at `+0x64`, `ThreadMessage` and `ThreadResultEntry` layouts, external wait callback `OnWaitObject(int)` at vtable `+0x34`, sync barrier/result helpers, Add/Remove wait-handle pairing with Socket as consumer only, stale CashShop/Socket generated-owner rejection, ThreadMan relationship through `Thread+0x60`, and active combined-score/emitter gate replacing the old below-95 no-code note.
```

### by-memory/-coverage-report.md

Replace the current [UID:0001JX] row with:

```markdown
    - [UID:0001JX][0x00596250-0x0059756e.ThreadAndThreadMan](by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md) 0x00596250-0x0059756e | aggregate | ThreadAndThreadMan : reconstructable : 87% : strong : Thread/ThreadMan utility-threading island attached to `Thread.cpp`; current B013 source-quality pass resolves the Thread object layout, wait-handle array, two 24-byte RingBuffer queues, result-event list, sync barrier/result helpers, `DispatchRequest`/event-backed request record order, `OnWaitObject(int)` vtable callback, live `RemoveLastWaitHandle` Socket cleanup tail-jump, and stale CashShop/Socket owner rejections, while ThreadMan raw wrappers/watch-list helpers remain exact children with blank C++ pending original helper names/reachability.
```

Replace the current [UID:0001JY] row with:

```markdown
    - [UID:0001JY][0x00596620-0x005969b0.CashShopRequestWaitDispatch](by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md) 0x00596620-0x005969b0 | aggregate | ThreadMessageDispatchHelpers : reconstructable : 87% : strong : Reclassified stale CashShopRequest wait/dispatch row as base Thread queue, wait-handle, result-list, virtual-dispatch, and stop-message helper subrange; B013 2026-06-19 resolves `0x00596620` as a queue-drain sync barrier, `0x00596760` as `WaitForResult(HANDLE)`, `0x005967d0` as `AddWaitHandle`, `0x005967f0` as live `RemoveLastWaitHandle` reached by Socket cleanup at `0x00577aef`, `ThreadMessage` slots including synchronous args, vtable `OnMessage`/`OnMessageEx` order, and `0x00596960` default request posting to queue `+0x4c`; aggregate C++ remains blank pending exact child splits for individual method bodies and the raw `0x005969b0` priority-queue sibling.
```

Replace the current [UID:0001JZ] row with:

```markdown
    - [UID:0001JZ][0x005967d0-0x005967e5.ThreadAddWaitHandleHelper](by-memory/0x005967d0-0x005967e5.ThreadAddWaitHandleHelper.md) 0x005967d0-0x005967e5 | method | ThreadAddWaitHandleHelper : reconstructable : 89% : strong : Base Thread `AddWaitHandle(HANDLE)` helper; exact body appends the supplied handle to `m_waitHandles[m_waitHandleCount]`, increments signed byte `m_waitHandleCount` at `+0x08`, returns the handle, has no callees, and is consumed by Socket setup calls at `0x005764cc` and `0x0057773f`. B013 2026-06-19 pairs it with live `RemoveLastWaitHandle` at `0x005967f0`, rejects stale Socket ownership, and recommends first-draft method C++ under [UID:0000OR][Thread](by-file/Thread.md).
```

Optional replacement for [UID:0000WL] if the supervisor updates the no-op virtual's current-gate wording:

```markdown
    - [UID:0000WL][0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual](by-memory/0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual.md) 0x0041b6b0-0x0041b6b3 | helper | ThreadDefaultNoOpVirtual : reconstructable : 86% : very-strong : Assigned to [UID:0000EV][Thread](by-class/Thread.md); B013 2026-06-19 resolves the source-facing signature as empty `Thread::OnWaitObject(int waitIndex)` because `ThreadProc` passes the non-primary `WaitForMultipleObjects` index through vtable offset `+0x34` and the body is `ret 4`. Base and four derived thread/downloader vtables inherit the slot; unrelated STL refs remain fold-sharing caveats, not ownership blockers.
```

If an exact child is created later for `0x005967f0-0x00596805`, insert this row immediately after [UID:0001JZ]:

```markdown
    - [UID:NEW][0x005967f0-0x00596805.ThreadRemoveLastWaitHandleHelper](by-memory/0x005967f0-0x00596805.ThreadRemoveLastWaitHandleHelper.md) 0x005967f0-0x00596805 | method | ThreadRemoveLastWaitHandleHelper : reconstructable : 87% : strong : Base Thread helper that decrements signed byte `m_waitHandleCount` at `+0x08`, clears the former last slot in `m_waitHandles`, and is reached by Socket transport cleanup tail-jump `0x00577aef` after closing the serial/overlapped event stored in the Socket-derived object; source owner/emitter should route through [UID:0000OR][Thread](by-file/Thread.md), with Socket retained as consumer evidence only.
```

## Implementation Callback Checklist

If the supervisor accepts this report, send B013 an implementation callback with this concrete scope:

1. Edit only the accepted target/support docs and do not edit `by-memory/-coverage-report.md`.
2. Update [UID:0000EV] `by-class/Thread.md` to `88/89`, add the declaration-only C++ block, field layout, message/result record sections, exact method-family table, active gate wording, and B013 change-log entry.
3. Update [UID:0000OR] `by-file/Thread.md` with B013 field/helper/source-shape details and generated-output caveats.
4. Update [UID:0001JX] and [UID:0001JY] with current gate wording, field/helper names, `0x005967f0` live tail-jump evidence, and aggregate no-code proof.
5. Update [UID:0001JZ] with best field names, paired remove-helper note, optional first-draft `AddWaitHandle` C++ if accepted, and revised score if accepted.
6. Update [UID:0000WL] with `OnWaitObject(int)` signature and current gate wording; add empty method C++ only if the supervisor accepts the inferred name as sufficient.
7. Do not assign or emit [UID:0003GY]; keep it dependency-only.
8. If creating a new exact child for `0x005967f0-0x00596805`, use a separate supervisor-approved split step because this assignment was report-only for the class page.
9. Run the validation commands listed below and record results.
10. Return the exact coverage rows above for supervisor-owned application.

## Validation Commands Needed After Implementation

Run from:

> Executable block R002 was removed from this report and preserved verbatim in [0000EV-Thread-class-source-quality-removed.md](0000EV-Thread-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Target/support validation:

> Executable block R003 was removed from this report and preserved verbatim in [0000EV-Thread-class-source-quality-removed.md](0000EV-Thread-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Coverage/generated refresh after supervisor applies coverage rows:

> Executable block R004 was removed from this report and preserved verbatim in [0000EV-Thread-class-source-quality-removed.md](0000EV-Thread-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Search checks:

> Executable block R005 was removed from this report and preserved verbatim in [0000EV-Thread-class-source-quality-removed.md](0000EV-Thread-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected: no stale target old-gate wording remains; any `CashShopRequestWaitDispatch` hit should be path/title compatibility only and not semantic ownership; `OnSignaled()` with no parameter should be removed or documented as generated-name pollution.

## IDA Rename / Type / Comment Recommendations

High confidence:

- Rename `sub_596250` to `Thread::Thread`.
- Rename `sub_596400` to `Thread::~Thread`.
- Rename `sub_596540` to `Thread::StopThread`.
- Rename `sub_5965C0` to `Thread::ForceTerminate`.
- Rename `sub_5965E0` to `Thread::StartThread`.
- Rename `sub_596600` to `Thread::SuspendThread`.
- Rename `sub_596610` to `Thread::ResumeThread`.
- Rename `sub_596760` to `Thread::WaitForResult`.
- Rename `sub_5967D0` to `Thread::AddWaitHandle`.
- Rename `sub_5967F0` to `Thread::RemoveLastWaitHandle`.
- Rename `sub_596810` to `Thread::ThreadProc`.
- Rename `sub_596920` to `Thread::OnMessage`.
- Rename `sub_596940` to `Thread::OnMessageEx`.
- Rename `sub_596960` to `Thread::DispatchRequest`.
- Rename `sub_596AF0` to `ThreadEntry`.

Medium-high confidence:

- Rename `nullsub_17` / `0x0041b6b0` to `Thread::OnWaitObject` and type it as `void __thiscall(Thread *, int)`.
- Rename `sub_596620` to `Thread::WaitForQueueDrain` or `Thread::FlushMessageQueue`; choose `WaitForQueueDrain` in docs until caller names prove original spelling.
- Rename raw `0x005969b0` to `Thread::DispatchPriorityRequestRaw` or `Thread::DispatchPriorityRequest`; keep raw suffix if no IDA function/start evidence exists in the active IDB.
- Rename `sub_596A00` to `Thread::DispatchRequestAndReturnEvent`; exact original may be shorter.

Types:

```cpp
struct ThreadMessage {
    int messageId;
    int arg1;
    int arg2;
    HANDLE resultEvent;
    int syncArg1;
    int syncArg2;
};

struct ThreadResultEntry {
    HANDLE event;
    int result;
};
```

Useful comments:

- At `Thread +0x08`: `signed wait-handle count; includes m_waitHandles[0] semaphore`.
- At `Thread +0x0c`: `WaitForMultipleObjects handle array; index 0 is semaphore`.
- At `Thread +0x4c`: `default 24-byte ThreadMessage queue used by DispatchRequest`.
- At `Thread +0x50`: `priority/sibling 24-byte ThreadMessage queue checked before +0x4c`.
- At `0x005967f0`: `removes last registered secondary wait handle; Socket cleanup tail-jumps here after closing serial event`.
- At `0x0041b6b0`: `empty default external wait callback for non-primary WaitForMultipleObjects result`.

## Remaining Open Questions

These are not blockers for the recommended class declaration, but should remain documented:

- Exact original spelling for `WaitForQueueDrain` versus `FlushMessageQueue` is not recovered.
- Exact original spelling for `OnWaitObject` versus `OnWaitHandleSignaled` is inferred from behavior and vtable role.
- Exact original names for the `+0x4c` and `+0x50` queues are not recovered; `m_messageQueue` and `m_priorityQueue` are behavior-based names.
- `0x005969b0-0x00596a00` needs exact-child/range policy before method-body C++.
- The five no-op virtual hooks around start/thread-entry/dispatch begin/end use folded `0x0041b6a0`; their source names are still inferred. They should be kept as provisional declarations in the class shell and revisited when derived vtable overrides are audited.

No blocker remains for class-level declaration C++, owner/emitter routing, or replacing stale below-95 no-code reasoning on [UID:0000EV].

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B013","command_id":"000000004165","destination_path":"executed-b-agent-research/B013/0000EV-Thread-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:35","uid":"0000EV"} -->
<!-- {"agent":"B013","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000EV-Thread-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B013/0000EV-Thread-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000EV"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
