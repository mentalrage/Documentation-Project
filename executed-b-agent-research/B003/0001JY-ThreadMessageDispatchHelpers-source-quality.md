** TARGET-REPORT-UID:0001JY **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B003 Source-Quality Report: [UID:0001JY] ThreadMessageDispatchHelpers

Status: FINISHED report-only. No by-* documentation files and no `by-memory/-coverage-report.md` edits were made.

## Target

- Primary target: `source-3/project-documentation/by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md`
- Required report: `source-3/project-documentation/tools/leaser/Agents/Agent-B003/research/0001JY-ThreadMessageDispatchHelpers-source-quality.md`
- Current target metadata: `COMPLETION:85`, `CONFIDENCE:86`, `CANONICAL_OWNER:0000OR`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OR`
- Recommended target metadata: `COMPLETION:88`, `CONFIDENCE:89`; keep `CANONICAL_OWNER:0000OR`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000OR`
- Filename note: keep the current filename for stable UID/path compatibility, but all visible title/prose/coverage wording should call the item `ThreadMessageDispatchHelpers`; `CashShopRequestWaitDispatch` is stale generated-owner residue only.

## Executive Recommendation

[UID:0001JY] is generic base `Thread` queue, wait, result, and virtual-dispatch infrastructure in `NexusTK/util/Thread.cpp`. The stale CashShop owner should be rejected completely for this range. CashShop, Socket, downloader, and MiscWorkThread code are consumers or derived-thread call sites; they do not own these base queue primitives.

The aggregate itself should keep a blank formal C++ block with an explicit no-code proof: it spans multiple independent source methods plus alignment padding and already overlaps exact child [UID:0001JZ]. Method-body C++ should be emitted from exact child pages or from future exact splits, while the class page [UID:0000EV] should carry the `Thread` declaration and API inventory.

Best current source-facing names:

| Address/range | Recommended source-facing name/signature | Confidence |
| --- | --- | --- |
| `0x00596620-0x0059675e` | `void Thread::WaitForQueueDrain()`; alternate original spelling could be `FlushMessageQueue()` | High for behavior/signature, medium for exact original spelling |
| `0x00596760-0x005967c7` | `int Thread::WaitForResult(HANDLE resultEvent)` | High |
| `0x005967d0-0x005967e5` | `HANDLE Thread::AddWaitHandle(HANDLE handle)` | High |
| `0x005967f0-0x00596805` | `void Thread::RemoveLastWaitHandle()` | High for behavior, medium-high for original spelling |
| `0x00596810-0x00596915` | `virtual int Thread::ThreadProc()` | High |
| `0x00596920-0x00596931` | `virtual void Thread::OnMessage(int messageId, int arg1, int arg2)` | High |
| `0x00596940-0x0059695e` | `virtual int Thread::OnMessageEx(int messageId, int syncArg1, int syncArg2, int arg1, int arg2)` | High for signature, medium-high for spelling |
| `0x00596960-0x005969b0` | `BOOL Thread::DispatchRequest(int messageId, int arg1, int arg2)` | High |
| `0x005969b0-0x00596a00` | `BOOL Thread::DispatchPriorityRequest(int messageId, int arg1, int arg2)` | Medium; raw complete sibling with no direct refs |
| `0x00596a00-0x00596ae8` | `HANDLE Thread::DispatchRequestAndReturnEvent(int messageId, int syncArg1, int syncArg2, int arg1, int arg2)` | High for behavior/signature order, medium for exact name |

`0x00596620` is best modeled as a queue-drain/barrier helper, not as a CashShop or Socket request. It posts synchronous message id `2` with no payload. The Socket async command dispatcher at `0x00575e60` switches only on ids `3` through `14`, so id `2` falls to the base handler. The Socket sync handler at `0x00576200` handles only id `0x0c` specially and otherwise tail-jumps to base `Thread::OnMessageEx`, which returns `0`. That means message id `2` is a no-op synchronous work item used to wait until earlier queued work has run.

## Evidence Checked

Instruction and policy files:

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B003/goal.md`
- `.codex/AGENTS.md`
- `source-3/project-documentation/by-project-structure/by-structure.md`
- `source-3/project-documentation/tools/leaser/inference_research.md`

Primary/support docs:

- [UID:0001JY] `by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md`
- [UID:0000OR] `by-file/Thread.md`
- [UID:0000EV] `by-class/Thread.md`
- [UID:0001JX] `by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md`
- [UID:0001JZ] `by-memory/0x005967d0-0x005967e5.ThreadAddWaitHandleHelper.md`
- [UID:0000WL] `by-memory/0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual.md`
- [UID:00026P] `by-memory/0x0062e268-0x0062e334.ThreadReadOnlyData.md`
- [UID:0003GY] `by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md`
- [UID:0001HU] `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`
- [UID:0001HT] `by-memory/0x00574b90-0x00575377.CashShopRequestSendQueue.md`
- [UID:0001I1] `by-memory/0x00575d90-0x005797ae.SocketTransportCore.md`
- [UID:0003A7] `by-memory/0x00577610-0x0057779e.SocketOpenSerialTransportRaw.md`
- [UID:0000DD] `by-class/Socket.md`
- [UID:0000NS] `by-file/Socket.md`
- [UID:00001H] `by-class/CashShopRequest.md`
- [UID:0000I0] `by-file/CashShopRequest.md`
- [UID:0000BX] `by-class/RequestSyncGate.md`
- [UID:0000N8] `by-file/RingBuffer.md`
- [UID:0000KS] `by-file/List.md`
- [UID:0001QT] `by-meta/client_threading.md`
- `source-3/project-documentation/by-memory/-coverage-report.md`

Prior source-quality reports checked:

- `source-3/project-documentation/tools/leaser/Agents/Agent-B013/research/0000EV-Thread-class-source-quality.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B002/research/executed/0003GY-thread-dispatch-wrapper-source-quality.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/executed/0001CJ-MiscWorkThreadAndNotifications-source-quality.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B003/research/0000EW-ThreadMan-class-source-quality.md`

Binary evidence checked locally:

- Original executable: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Image base: `0x00400000`
- MD5/SHA256 per existing docs: `4247e04e20b65d6414c7238aa8ff5515` / `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`
- PE section mapping for `.text`, `.rdata`, and `.data`
- Capstone disassembly for `0x00596620-0x00596a00`
- Rel32 call/jump scans into starts `0x00596620`, `0x00596760`, `0x005967d0`, `0x005967f0`, `0x00596810`, `0x00596920`, `0x00596940`, `0x00596960`, `0x005969b0`, `0x00596a00`, and `0x00596af0`
- VA/RVA dword pointer scans for the same starts
- Socket dispatcher disassembly at `0x00575e60-0x005761a4`
- Socket sync handler disassembly at `0x00576200-0x00576245`
- Socket cleanup tail around `0x00577ad1-0x00577af6`

## Body And Padding Map

Recommended target inventory:

| Range | Classification | Source-facing role |
| --- | --- | --- |
| `0x00596620-0x0059675e` | modeled function | `Thread::WaitForQueueDrain()`; posts fixed synchronous no-op/barrier message id `2`, waits for the event, removes result entry, closes event. |
| `0x0059675e-0x00596760` | padding | Two `0xcc` bytes. |
| `0x00596760-0x005967c7` | modeled function | `Thread::WaitForResult(HANDLE resultEvent)`; waits on caller-provided event, scans result list, closes event, removes entry, returns stored result. |
| `0x005967c7-0x005967d0` | padding | Nine `0xcc` bytes before exact child [UID:0001JZ]. |
| `0x005967d0-0x005967e5` | modeled function and exact child | `Thread::AddWaitHandle(HANDLE handle)`. |
| `0x005967e5-0x005967f0` | padding | Eleven `0xcc` bytes. |
| `0x005967f0-0x00596805` | modeled function with stale alias pollution | `Thread::RemoveLastWaitHandle()`. Create an exact child page or split during implementation. |
| `0x00596805-0x00596810` | padding | Eleven `0xcc` bytes. |
| `0x00596810-0x00596915` | modeled virtual method | `Thread::ThreadProc()`. |
| `0x00596915-0x00596920` | padding | Eleven `0xcc` bytes. |
| `0x00596920-0x00596931` | modeled virtual method | `Thread::OnMessage(int messageId, int arg1, int arg2)`. |
| `0x00596931-0x00596940` | padding | Fifteen `0xcc` bytes. |
| `0x00596940-0x0059695e` | modeled virtual method | `Thread::OnMessageEx(int messageId, int syncArg1, int syncArg2, int arg1, int arg2)`. |
| `0x0059695e-0x00596960` | padding | Two `0xcc` bytes. |
| `0x00596960-0x005969b0` | modeled function | `Thread::DispatchRequest(int messageId, int arg1, int arg2)`. |
| `0x005969b0-0x00596a00` | raw sibling outside target | `Thread::DispatchPriorityRequest(int messageId, int arg1, int arg2)`; create a separate raw child rather than extending [UID:0001JY]. |
| `0x00596a00-0x00596ae8` | modeled sibling outside target | `Thread::DispatchRequestAndReturnEvent(...)`; belongs with the same helper family but outside the current target. |

Boundary conclusion: keep [UID:0001JY] at `0x00596620-0x005969b0`. Do not fold `0x005969b0-0x00596a00` into this target. Instead add a sibling raw child for that exact range or document it as a child of the `0x00596a00` sync-post family.

## Field And Record Layout

Recommended `Thread` fields for this range:

| Offset | Recommended name/type | Evidence and role |
| --- | --- | --- |
| `+0x04` | `DWORD m_waitTimeout` | Passed as the timeout to `WaitForMultipleObjects` in `ThreadProc`; constructor initializes it to `INFINITE` in existing docs. |
| `+0x08` | `signed char m_waitHandleCount` | Sign-extended by add/remove helpers and `ThreadProc`; count includes the primary semaphore handle at `+0x0c`. |
| `+0x0c` | `HANDLE m_waitHandles[16]` | Passed as the wait-object array to `WaitForMultipleObjects`; index `0` is the thread wake semaphore signaled by queue-post helpers. |
| `+0x4c` | `RingBuffer *m_messageQueue` | Default request queue used by `DispatchRequest`, `WaitForQueueDrain`, and `DispatchRequestAndReturnEvent`. |
| `+0x50` | `RingBuffer *m_priorityQueue` | Checked first by `ThreadProc`; raw `0x005969b0` writes here. `m_priorityQueue` is a high-probability name, exact original spelling unproven. |
| `+0x54` | `RequestSyncGate *m_resultGate` / `m_resultLock` | Lock/unlock helper calls at `0x00528710` and `0x00528720` guard result-list access. |
| `+0x58` | `List *m_resultList` | Contains 8-byte result records `{HANDLE event; int result}`; created as `List(8, 16)` by the constructor in existing Thread docs. |
| `+0x5c` | `HANDLE m_threadHandle` | Documented by Thread constructor/destructor/stop helpers. |
| `+0x60` | `unsigned int m_threadId` | Used by ThreadMan watch records and existing ThreadMan report evidence. |
| `+0x64` | `unsigned char m_stopRequested` / `bool m_stopRequested` | Set by base message id `1` handlers; checked by `ThreadProc` loop. |

Recommended private record layouts:

```cpp
struct ThreadMessage
{
    int messageId;       // +0x00
    int arg1;            // +0x04
    int arg2;            // +0x08
    HANDLE resultEvent;  // +0x0c, zero for async messages
    int syncArg1;        // +0x10
    int syncArg2;        // +0x14
};

struct ThreadResult
{
    HANDLE event;        // +0x00
    int result;          // +0x04
};
```

The constructor evidence in `by-file/RingBuffer.md` says `Thread::Thread` constructs two `RingBuffer(24, messageSize)` queues; that matches the 24-byte `ThreadMessage`. The result list uses 8-byte records and is scanned by event handle.

## Helper Findings

### `0x00596620` queue-drain/barrier helper

Resolved direction: use `Thread::WaitForQueueDrain()` as the best current name, with `FlushMessageQueue()` as a plausible original-spelling alternative. Do not use `CashShopRequest::SubmitAndWait`.

Evidence:

- It creates an event through `dword_69BE3C`, which [UID:0000WD]/`WideApiDispatchTable` documents as the `CreateEventW` dispatch slot.
- It registers `{event, 0}` in the result list at `this+0x58` while holding the gate at `this+0x54`.
- It queues a message record `{2, 0, 0, event, 0, 0}` to `m_messageQueue` at `this+0x4c`.
- It releases the wake semaphore at `this+0x0c`, waits on the event, scans/removes the result entry, closes the event, and unlocks.
- Direct rel32 call scan found 9 callers: `0x004f7c63`, `0x004f91f7`, `0x00504b0e`, `0x00553f11`, `0x005541c2`, `0x0055431d`, `0x0055446a`, `0x0058b058`, and `0x0058b399`.
- Documented caller examples include `OpenTerminalPane` at `0x004f91f7` and `MainMenuPane::ActivateMenuItem` cleanup/reset at `0x004f7c63`. These are UI/terminal/session cleanup barriers, not CashShop-specific request submissions.
- Socket async handler `0x00575e60` switches on command ids `3` through `14`; id `2` falls to base async handling. Socket sync handler `0x00576200` handles only id `0x0c`; id `2` falls to base `Thread::OnMessageEx` and returns `0`. This supports queue-drain/barrier semantics.

Open uncertainty: the exact original method spelling is not proven. The behavior is stronger than the name. If later source evidence finds a project convention such as `WaitForComplete`, `WaitForIdle`, or `FlushThread`, rename the method but keep the command-id-2 barrier explanation.

### `0x00596760` wait-for-result helper

Resolved direction: `int Thread::WaitForResult(HANDLE resultEvent)`.

Evidence:

- It calls `WaitForSingleObject(resultEvent, INFINITE)`.
- It locks `m_resultGate`, scans `m_resultList`, and compares record `event` fields against the supplied handle.
- On match, it loads the result dword at record `+4`, calls `CloseHandle(resultEvent)`, removes the result-list entry through the list vtable, unlocks, and returns the result.
- If no matching entry is found, the binary returns the initialized `edi` value, which is the event handle value. Preserve this odd fallback behavior in notes; do not silently rewrite it to `0` unless later source evidence proves compiler artifact.
- Direct rel32 call scan found 6 callers: `0x004f8de6`, `0x00510040`, `0x0051015e`, `0x005542fe`, `0x00554456`, and `0x0058b529`.

### `0x005967d0` add wait handle helper

Resolved direction: keep exact child [UID:0001JZ] and update it to `Thread::AddWaitHandle(HANDLE handle)`.

Evidence:

- Body bytes: `55 8b ec 0f be 51 08 8b 45 08 89 44 91 0c fe 41 08 5d c2 04 00`.
- It sign-extends `this+0x08`, writes the supplied handle to `this+0x0c + 4*count`, increments the count byte, and returns the handle.
- It has no callees.
- Current docs identify two callers: modeled Socket setup at `0x005764cc` and raw Socket serial-open at `0x0057773f`. Both are consumers of inherited base-thread wait-handle support, not Socket ownership proof.
- No VA/RVA pointer-byte matches were found for start `0x005967d0`.

### `0x005967f0` remove last wait handle helper

Resolved direction: split/create exact child `0x005967f0-0x00596805.ThreadRemoveLastWaitHandleHelper.md` and name it `Thread::RemoveLastWaitHandle()`.

Evidence:

- Disassembly:

```text
0x005967f0: mov dl, [ecx+8]
0x005967f3: lea eax, [edx-1]
0x005967f6: mov [ecx+8], al
0x005967f9: movsx eax, dl
0x005967fc: mov dword ptr [ecx+eax*4+8], 0
0x00596804: ret
```

- The apparent clear address `[ecx + oldCount*4 + 8]` is the previous last handle slot because the handle array starts at `+0x0c`; for `oldCount`, that expression equals `+0x0c + 4*(oldCount - 1)`.
- Current target prose saying IDA reports no direct callers is stale. Local rel32 scan found a direct tail jump at `0x00577aef`.
- The tail route is from Socket `CloseTransport` after closing and clearing the serial handle at `this+0x1d53c`; it sets `ecx` back to the Socket/Thread object, pops `esi`, and jumps to `0x005967f0`. This is a real cleanup route matching the add-helper callers.
- This helper should not be left as an alias-polluted blocker.

### `0x00596810` worker loop

Resolved direction: `Thread::ThreadProc()`.

Key behavior to insert in target/support docs:

- Calls `Sleep(1)` each loop.
- Calls `WaitForMultipleObjects(m_waitHandleCount, m_waitHandles, FALSE, m_waitTimeout)`.
- Return `0` means the primary semaphore signaled; it then drains the priority queue at `+0x50` first and the default queue at `+0x4c` second.
- For messages with `resultEvent == 0`, it calls virtual slot `+0x2c` as `OnMessage(messageId, arg1, arg2)`.
- For messages with `resultEvent != 0`, it calls virtual slot `+0x30` as `OnMessageEx(messageId, syncArg1, syncArg2, arg1, arg2)`, stores the return result in the matching `ThreadResult`, and signals the event with `SetEvent`.
- For non-primary wait handles, it calls virtual slot `+0x34` as `OnWaitObject(waitIndex)`. [UID:0000WL] proves the base default body is the folded `retn 4` at `0x0041b6b0`.
- It loops until `m_stopRequested` at `+0x64` is set.
- VA pointer scan found vtable/data refs to `0x00596810` at `0x0060d7c4`, `0x006106ec`, `0x0061fb90`, `0x00624f3c`, and `0x0062e288`, covering derived and base vtable slots.

### `0x00596920` and `0x00596940` base handlers

Resolved direction:

- `void Thread::OnMessage(int messageId, int arg1, int arg2)`
- `int Thread::OnMessageEx(int messageId, int syncArg1, int syncArg2, int arg1, int arg2)`

Evidence:

- Base async handler `0x00596920` sets `m_stopRequested` when `messageId == 1` and returns `void`.
- Base sync handler `0x00596940` sets `m_stopRequested` when `messageId == 1`, returns `0`, and has `ret 0x14`.
- `0x00596920` has direct calls at `0x0041b12f`, `0x00453a0e`, `0x00528030`, and `0x00576197`.
- `0x00596940` has a direct tail route at `0x0057620e` and vtable/data refs at `0x0060d7d8`, `0x00610700`, `0x00613774`, `0x0061fba4`, and `0x0062e29c`.

### `0x00596960` async queue post helper

Resolved direction: `BOOL Thread::DispatchRequest(int messageId, int arg1, int arg2)`.

Evidence:

- It builds a 24-byte `ThreadMessage` with `resultEvent == 0`, `syncArg1 == 0`, and `syncArg2 == 0`.
- It enqueues through `m_messageQueue` at `+0x4c`, releases `m_waitHandles[0]`, and returns the `ReleaseSemaphore` result.
- Direct rel32 scan found 22 call sites: `0x0041b1e8`, `0x0041b253`, `0x0041b2aa`, `0x0041b2bf`, `0x0041b2db`, `0x00453a92`, `0x005282ed`, `0x0052838e`, `0x005283cb`, `0x00574aed`, `0x00574b0d`, `0x00574b26`, `0x00574b5d`, `0x00574b7a`, `0x00574b9b`, `0x00574c05`, `0x00574c2c`, `0x00574c94`, `0x00574cbc`, `0x00574d31`, `0x00574e2e`, and `0x005752af`.
- Those callers span FileDownloader request helpers, MiscWorkThread request wrappers, Socket command-posting helpers, and packet-send wrappers. This caller diversity is positive evidence for base `Thread`, not for CashShop ownership.

### `0x005969b0` raw priority queue sibling

Resolved direction: create a sibling exact raw child for `0x005969b0-0x00596a00`, named `ThreadDispatchPriorityRequestRaw` or `ThreadPriorityDispatchRequest`.

Evidence:

- It is function-shaped raw bytes with a normal prologue/epilogue and `ret 0x0c`.
- It mirrors `0x00596960` but writes to queue `this+0x50` rather than `this+0x4c`.
- It releases the same wake semaphore at `this+0x0c`.
- Local rel32 and VA/RVA pointer scans found no direct code or pointer route to `0x005969b0`.
- `ThreadProc` checks queue `+0x50` before queue `+0x4c`, so this helper is best understood as a retained priority/high-priority async post method.

Recommendation: do not call it dead code. Mark it retained no-xref raw source-authored helper code and give it a first-draft C++ body in its exact child page if that page is created.

## Source Ownership And Rejected Alternatives

Recommended owner/emitter: keep [UID:0000OR] `Thread` / `NexusTK/util/Thread.cpp`.

Reasons:

- The field accesses are entirely base `Thread` state: queues, wake semaphore, wait-handle array, result-list, result gate, and stop flag.
- The constructor/destructor in the same island create/delete the two `RingBuffer(24, messageSize)` instances, `RequestSyncGate`/monitor-like gate, result list, wait objects, and worker thread.
- Vtable refs route `ThreadProc`, `OnMessage`, `OnMessageEx`, and `OnWaitObject` through the base and derived Thread vtables.
- Caller diversity spans Socket, FileDownloader, MiscWorkThread, UI/terminal/session cleanup, and packet-send wrappers.
- `by-file/Thread.md`, `by-class/Thread.md`, and `by-memory/ThreadAndThreadMan.md` already route this island to `util/Thread.cpp`.

Rejected direct owners:

- `CashShopRequest`: stale generated owner only. `CashShopRequest` docs already treat [UID:0001JY] as supporting boundary evidence, and no body here accesses cash-shop fields, `g_pCashShopRequest`, catalog/download payloads, or CashShop vtables.
- `Socket`: Socket calls `AddWaitHandle`, `RemoveLastWaitHandle`, and queue-post helpers as an inherited `Thread` consumer. Socket owns command wrappers and transport handlers, not the base queue infrastructure.
- `FileDownloader` / `MiniMapDownloader`: derived thread classes and request producers only. They consume `DispatchRequest` and vtable slots.
- `MiscWorkThread`: derived consumer only. Its source-owned request wrappers call the `0x00596960` base dispatch primitive.
- A new no-owner queue helper file: not needed. Existing `Thread.cpp` already owns the constructor/destructor, queues, thread entry, vtable data, ThreadMan adjacency, and source-tree route.

## Raw Reachability Findings

Rel32 route scan:

| Start | Direct rel32 refs | Notes |
| --- | ---: | --- |
| `0x00596620` | 9 | UI/terminal/session cleanup and queue-drain call sites. |
| `0x00596760` | 6 | Synchronous result wait call sites. |
| `0x005967d0` | 2 | Socket modeled setup `0x005764cc` and raw serial-open `0x0057773f`. |
| `0x005967f0` | 1 | Socket `CloseTransport` tail jump at `0x00577aef`; target doc should be corrected. |
| `0x00596810` | 0 code refs | Reached through vtables/data refs. |
| `0x00596920` | 4 | Base handler direct calls/tail routes. |
| `0x00596940` | 1 | Socket sync default tail route at `0x0057620e`. |
| `0x00596960` | 22 | Broad request/packet/thread producer fan-in. |
| `0x005969b0` | 0 | Retained raw no-xref priority helper. |
| `0x00596a00` | 1 | Event-backed Socket helper caller at `0x00574b3e`. |

VA/RVA pointer route scan:

- `0x00596810` has VA hits at `0x0060d7c4`, `0x006106ec`, `0x0061fb90`, `0x00624f3c`, and `0x0062e288`.
- `0x00596920` has VA hits at `0x00613770` and `0x0062e298`.
- `0x00596940` has VA hits at `0x0060d7d8`, `0x00610700`, `0x00613774`, `0x0061fba4`, and `0x0062e29c`.
- No VA/RVA pointer hits were found for `0x00596620`, `0x00596760`, `0x005967d0`, `0x005967f0`, `0x00596960`, `0x005969b0`, or `0x00596a00`.

## First-Draft C++ Readiness

Aggregate target [UID:0001JY]:

- Leave `RECONSTRUCTION_CPP` blank.
- Add explicit no-code proof: the page is an inventory over many independent methods and padding spans, includes exact child [UID:0001JZ], and should not emit method bodies from an aggregate page because that would duplicate or bypass exact child pages.
- This is not a "no source exists" finding. It is a "source belongs in exact children/class declaration" finding.

Exact child readiness:

- `0x005967d0` [UID:0001JZ] is ready for first-draft C++ as `Thread::AddWaitHandle`.
- `0x005967f0` should get a new exact child and first-draft C++ as `Thread::RemoveLastWaitHandle`.
- `0x005969b0` should get a new exact raw child and first-draft C++ as `Thread::DispatchPriorityRequest`, while preserving no-direct-xref evidence.
- `0x00596620`, `0x00596760`, `0x00596810`, `0x00596920`, `0x00596940`, and `0x00596960` are also method-body ready, but they currently exist only inside this aggregate. Either split exact child pages for them or place method drafts in a future dedicated Thread method island page, not in the aggregate.

First-draft snippets for future exact children:

```cpp
void Thread::WaitForQueueDrain()
{
    HANDLE event = CreateEventW(0, FALSE, FALSE, 0);
    if (event == 0)
    {
        throw Win32Error();
    }

    ThreadResult result = { event, 0 };
    m_resultGate->Lock();
    m_resultList->Append(&result);
    m_resultGate->Unlock();

    ThreadMessage message = { 2, 0, 0, event, 0, 0 };
    m_messageQueue->Enqueue(&message);
    ReleaseSemaphore(m_waitHandles[0], 1, 0);

    WaitForSingleObject(event, INFINITE);

    m_resultGate->Lock();
    for (int i = 0; i < m_resultList->GetCount(); ++i)
    {
        ThreadResult *entry = static_cast<ThreadResult *>(m_resultList->GetElementAt(i));
        if (entry->event == event)
        {
            CloseHandle(event);
            m_resultList->RemoveRange(i, 1);
            break;
        }
    }
    m_resultGate->Unlock();
}

int Thread::WaitForResult(HANDLE resultEvent)
{
    int result = reinterpret_cast<int>(resultEvent);
    WaitForSingleObject(resultEvent, INFINITE);

    m_resultGate->Lock();
    for (int i = 0; i < m_resultList->GetCount(); ++i)
    {
        ThreadResult *entry = static_cast<ThreadResult *>(m_resultList->GetElementAt(i));
        if (entry->event == resultEvent)
        {
            result = entry->result;
            CloseHandle(resultEvent);
            m_resultList->RemoveRange(i, 1);
            break;
        }
    }
    m_resultGate->Unlock();
    return result;
}

HANDLE Thread::AddWaitHandle(HANDLE handle)
{
    const int index = m_waitHandleCount;
    m_waitHandles[index] = handle;
    ++m_waitHandleCount;
    return handle;
}

void Thread::RemoveLastWaitHandle()
{
    const int oldCount = m_waitHandleCount;
    m_waitHandleCount = static_cast<signed char>(oldCount - 1);
    m_waitHandles[oldCount - 1] = 0;
}

void Thread::OnMessage(int messageId, int arg1, int arg2)
{
    if (messageId == 1)
    {
        m_stopRequested = true;
    }
}

int Thread::OnMessageEx(int messageId, int syncArg1, int syncArg2, int arg1, int arg2)
{
    if (messageId == 1)
    {
        m_stopRequested = true;
    }
    return 0;
}

BOOL Thread::DispatchRequest(int messageId, int arg1, int arg2)
{
    ThreadMessage message = { messageId, arg1, arg2, 0, 0, 0 };
    m_messageQueue->Enqueue(&message);
    return ReleaseSemaphore(m_waitHandles[0], 1, 0);
}

BOOL Thread::DispatchPriorityRequest(int messageId, int arg1, int arg2)
{
    ThreadMessage message = { messageId, arg1, arg2, 0, 0, 0 };
    m_priorityQueue->Enqueue(&message);
    return ReleaseSemaphore(m_waitHandles[0], 1, 0);
}

HANDLE Thread::DispatchRequestAndReturnEvent(int messageId,
                                             int syncArg1,
                                             int syncArg2,
                                             int arg1,
                                             int arg2)
{
    HANDLE event = CreateEventW(0, FALSE, FALSE, 0);
    if (event == 0)
    {
        throw Win32Error();
    }

    ThreadResult result = { event, 0 };
    m_resultGate->Lock();
    m_resultList->Append(&result);
    m_resultGate->Unlock();

    ThreadMessage message = { messageId, arg1, arg2, event, syncArg1, syncArg2 };
    m_messageQueue->Enqueue(&message);
    ReleaseSemaphore(m_waitHandles[0], 1, 0);
    return event;
}
```

Notes for implementation:

- The list method names in the snippets are source-facing placeholders; map them to the existing `List` API names once the exact class declarations are applied.
- The `WaitForQueueDrain` draft intentionally preserves the binary's duplicated result-removal logic instead of calling `WaitForResult`, because the compiled binary has no call from `0x00596620` to `0x00596760`.
- The `Win32Error` construction path is simplified. The binary allocates an 8-byte exception object and calls `0x004a60d0` before throwing via `0x005ca20a` with type metadata `0x006590d4`; exact exception naming belongs in the Thread/Win32Error support docs.

## Recommended Target Changes

In `by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md`:

1. Change metadata:
   - `COMPLETION:85 -> 88`
   - `CONFIDENCE:86 -> 89`
   - Keep `CANONICAL_OWNER:0000OR`
   - Keep `RECONSTRUCTABLE:TRUE`
   - Keep `EMITTER_UIDS:0000OR`

2. Replace stale reconstruction-state text:

```text
The active code-entry gate is cleared for the underlying Thread methods, but this target remains an aggregate inventory over multiple independent method bodies and padding spans. Leave this aggregate's formal C++ block blank and emit source through the Thread class declaration plus exact method children. The aggregate should carry first-draft C++ guidance and exact split instructions only.
```

3. Update the covered-range table with source-facing names from this report:
   - `0x00596620-0x0059675e`: `Thread::WaitForQueueDrain()` / queue-drain barrier helper.
   - `0x00596760-0x005967c7`: `Thread::WaitForResult(HANDLE resultEvent)`.
   - `0x005967d0-0x005967e5`: exact child [UID:0001JZ] `Thread::AddWaitHandle(HANDLE)`.
   - `0x005967f0-0x00596805`: `Thread::RemoveLastWaitHandle()`, with direct tail-jump route from Socket cleanup at `0x00577aef`.
   - `0x00596810-0x00596915`: `Thread::ThreadProc()`.
   - `0x00596920-0x00596931`: `Thread::OnMessage`.
   - `0x00596940-0x0059695e`: `Thread::OnMessageEx`.
   - `0x00596960-0x005969b0`: `Thread::DispatchRequest`.

4. Add field/record layout section:
   - `m_waitTimeout`, `m_waitHandleCount`, `m_waitHandles`, `m_messageQueue`, `m_priorityQueue`, `m_resultGate`, `m_resultList`, `m_threadHandle`, `m_threadId`, `m_stopRequested`.
   - `ThreadMessage` 24-byte record.
   - `ThreadResult` 8-byte record.

5. Add route/liveness section with exact rel32/pointer findings from this report.

6. Add command-id-2 queue-drain proof:
   - `0x00596620` queues `{2,0,0,event,0,0}`.
   - Socket async dispatcher range handles ids `3-14`.
   - Socket sync handler handles only id `0x0c` specially and otherwise tails to base `OnMessageEx`.
   - Therefore id `2` is a no-op synchronous barrier in current consumers.

7. Add sibling split recommendation:
   - Create `by-memory/0x005967f0-0x00596805.ThreadRemoveLastWaitHandleHelper.md`.
   - Create `by-memory/0x005969b0-0x00596a00.ThreadDispatchPriorityRequestRaw.md`.
   - Do not extend [UID:0001JY] to include `0x005969b0`.

8. Replace old open questions with resolved directions:
   - Helper names: best current names as above.
   - Queue/result fields: names and layouts above.
   - `0x005967f0`: live via Socket cleanup tail jump; not dead/no-route.
   - `0x005969b0`: retained no-xref priority queue helper; split as raw sibling.
   - Source placement: `util/Thread.cpp`.

## Support-Doc Updates Needed

### `by-class/Thread.md`

Recommended metadata: apply B013's class-level recommendation if not already done:

- `COMPLETION:86 -> 88`
- `CONFIDENCE:85 -> 89`
- Keep `CANONICAL_OWNER:0000OR`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OR`

Insert/update:

- Add final/provisional class declaration inventory for `Thread`, with `[[CHILDREN]]` body insertion.
- Add field layout names listed in this report.
- Add `ThreadMessage` and `ThreadResult` private layout notes.
- Replace old no-C++ gate text with active-gate text: class page should emit declaration/API inventory; exact method bodies emit from method children.
- Add final helper names and signatures from this report.
- Update `0x005967f0` from unresolved alias-polluted helper to `Thread::RemoveLastWaitHandle()` with Socket cleanup tail-jump evidence.
- Add `0x005969b0` as retained raw priority dispatch helper.

### `by-file/Thread.md`

Recommended metadata: no mandatory score change, but confidence can defensibly rise from `85` to `87` or `88` if the implementation incorporates these findings.

Insert/update:

- Replace stale caveat saying `0x00596620` and `0x00596760` are still generated with CashShop owners with a resolved statement:

```text
[UID:0001JY] is now resolved as generic base `Thread` queue-drain, result-wait, wait-handle, worker-dispatch, and queue-post infrastructure. The old CashShop names are stale generated labels only.
```

- Add `Thread::WaitForQueueDrain`, `Thread::WaitForResult`, `Thread::AddWaitHandle`, `Thread::RemoveLastWaitHandle`, `Thread::DispatchRequest`, retained `Thread::DispatchPriorityRequest`, and `Thread::DispatchRequestAndReturnEvent` to likely contents.
- Clarify that `0x005969b0` is the priority queue sibling using field `+0x50`, currently no direct refs.
- Keep `ThreadMan` in this same file; this pass does not move it.

### `by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md`

Insert/update:

- Update child map names:
  - `0x00596620-0x0059675e`: `Thread::WaitForQueueDrain`.
  - `0x00596760-0x005967c7`: `Thread::WaitForResult`.
  - `0x005967f0-0x00596805`: `Thread::RemoveLastWaitHandle`; tail-jump route from Socket `CloseTransport`.
  - `0x00596960-0x005969b0`: `Thread::DispatchRequest`.
  - `0x005969b0-0x00596a00`: retained raw `Thread::DispatchPriorityRequest`, recommended separate child.
  - `0x00596a00-0x00596ae8`: `Thread::DispatchRequestAndReturnEvent`.
- Add queue/result record layouts or link to the Thread class page section after it is updated.
- Update score rationale to remove `queue/result record field names` and `0x005969b0 sibling raw helper` as passive blockers; they now have best-supported directions, though the aggregate can still stay blank C++ due split policy.

### `by-memory/0x005967d0-0x005967e5.ThreadAddWaitHandleHelper.md`

Recommended metadata after implementation:

- Consider `COMPLETION:88 -> 89`, `CONFIDENCE:88 -> 90` if first-draft C++ and final field names are added.
- Keep `CANONICAL_OWNER:0000OR` or move to class owner `0000EV` only if the supervisor prefers class-owned exact method children. Emitter should remain `0000OR` either way.

Insert/update:

- Name/signature: `HANDLE Thread::AddWaitHandle(HANDLE handle)`.
- Add first-draft C++ from this report.
- Use field names `m_waitHandleCount` and `m_waitHandles`.
- Preserve the two direct Socket consumer refs and the no-VA/RVA pointer evidence.

### New exact child: `by-memory/0x005967f0-0x00596805.ThreadRemoveLastWaitHandleHelper.md`

Create as:

- Title: `0x005967f0-0x00596805 Thread Remove Last Wait Handle Helper`
- Suggested UID: supervisor-assigned.
- `COMPLETION:86`, `CONFIDENCE:88` initially; can be `88/89` once validator and child links are complete.
- `CANONICAL_OWNER:0000OR` or class `0000EV` by supervisor policy; `EMITTER_UIDS:0000OR`.
- `RECONSTRUCTABLE:TRUE`.
- First-draft C++: `void Thread::RemoveLastWaitHandle()`.
- Include exact disassembly and Socket cleanup tail-jump at `0x00577aef`.

### New exact child: `by-memory/0x005969b0-0x00596a00.ThreadDispatchPriorityRequestRaw.md`

Create as:

- Title: `0x005969b0-0x00596a00 Thread Dispatch Priority Request Raw`
- Suggested UID: supervisor-assigned.
- `COMPLETION:85`, `CONFIDENCE:87` initially.
- `CANONICAL_OWNER:0000OR` or class `0000EV` by supervisor policy; `EMITTER_UIDS:0000OR`.
- `RECONSTRUCTABLE:TRUE`.
- First-draft C++: `BOOL Thread::DispatchPriorityRequest(int messageId, int arg1, int arg2)`.
- Include exact no-direct-ref/no-VA/RVA evidence and `ThreadProc` priority-queue consumption proof.

### `by-memory/0x0062e268-0x0062e334.ThreadReadOnlyData.md`

Insert/update:

- Add that the `Thread` vtable maps:
  - worker dispatch slot to `Thread::ThreadProc` at `0x00596810`
  - base async handler slot to `Thread::OnMessage` at `0x00596920`
  - base sync handler slot to `Thread::OnMessageEx` at `0x00596940`
  - external wait callback slot `+0x34` to folded empty body `0x0041b6b0`
- Keep vtables compiler-emitted and no formal C++ for the data page.

### `by-memory/0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual.md`

Insert/update:

- If the class page adopts `OnWaitObject(int waitIndex)`, mirror that name as the high-probability source-facing name for the folded empty virtual at vtable slot `+0x34`.
- Keep the STL fold-sharing caveat.

### `by-meta/client_threading.md`

Replace open questions:

- Remove or rewrite "final names/signatures for the Thread synchronous-send helpers at `0x00596620`, `0x00596760`, and `0x00596a00`".
- Add resolved current names:
  - `Thread::WaitForQueueDrain()`
  - `Thread::WaitForResult(HANDLE)`
  - `Thread::DispatchRequestAndReturnEvent(...)`
- Keep an exact-original-spelling caveat only.
- Add `ThreadMessage` and `ThreadResult` record layouts.
- Add `0x005969b0` as retained no-xref priority-post helper.

### Socket/CashShop support docs

Update `by-class/Socket.md`, `by-file/Socket.md`, and `by-memory/0x00575d90-0x005797ae.SocketTransportCore.md`:

- Mention `Thread::RemoveLastWaitHandle()` tail-jump from `Socket::CloseTransport` at `0x00577aef`.
- Keep [UID:0001JZ] as inherited base `Thread` infrastructure, not Socket-owned source.
- Do not add [UID:0001JY] as Socket-owned.

Update `by-class/CashShopRequest.md` and `by-file/CashShopRequest.md`:

- Remove [UID:0001JY] from "current relevant ranges" if the list is meant to contain CashShop-owned ranges, or keep it only under a clearly labeled stale/search-provenance section.
- Replace "whether wait/result list helpers were originally in this class source" with a resolved statement: current evidence routes them to base `Thread`.
- Keep CashShop as a caller/consumer only where older docs need search linkage.

## Score Rationale

Target score recommendation:

- Completion `88`: the report resolves source route, helper names, field names, record layouts, caller routes, `0x005967f0` liveness, `0x005969b0` raw sibling policy, command-id-2 barrier semantics, aggregate no-code proof, and support-doc implementation plan.
- Confidence `89`: ownership and behavior are very strong from xrefs, vtables, disassembly, support docs, and consumer diversity. Confidence stays below 90 because exact original spelling for `WaitForQueueDrain`/`DispatchPriorityRequest`, original List API names, and child split UIDs remain pending implementation.

Do not lower reconstructability. The code is source-authored and must be represented in reconstruction; only the aggregate's formal C++ block stays blank.

## IDA Rename, Type, And Comment Recommendations

High confidence:

- Rename `sub_596760` to `Thread__WaitForResult`.
- Rename `sub_5967D0` to `Thread__AddWaitHandle`.
- Rename `sub_596810` to `Thread__ThreadProc`.
- Rename `sub_596920` to `Thread__OnMessage`.
- Rename `sub_596940` to `Thread__OnMessageEx`.
- Rename `sub_596960` to `Thread__DispatchRequest`.
- Type `ThreadMessage` as a 24-byte stack/queue record.
- Type `ThreadResult` as an 8-byte list record.
- Name `this+0x08` `m_waitHandleCount`.
- Name `this+0x0c` `m_waitHandles`.
- Name `this+0x4c` `m_messageQueue`.
- Name `this+0x54` `m_resultGate` or `m_resultLock`.
- Name `this+0x58` `m_resultList`.
- Name `this+0x64` `m_stopRequested`.

Medium-high confidence:

- Rename `sub_596620` to `Thread__WaitForQueueDrain`. Add repeatable comment: "Queues synchronous no-op message id 2 as a barrier and waits for its event; stale CashShop SubmitAndWait name rejected."
- Rename `sub_5967F0` to `Thread__RemoveLastWaitHandle`; fix stale alias/decompiler pollution and add comment about Socket `CloseTransport` tail jump at `0x00577aef`.
- Name vtable slot `+0x34` `OnWaitObject(int waitIndex)`.
- Name `this+0x50` `m_priorityQueue`.

Medium confidence:

- Create/name raw function at `0x005969b0` as `Thread__DispatchPriorityRequest` if IDA function creation is allowed.
- Name `0x00596a00` `Thread__DispatchRequestAndReturnEvent`.
- Name `this+0x04` `m_waitTimeout`.

Import/IAT comments:

- `dword_69BE3C` = `g_pfnCreateEventW` / `CreateEventW`.
- Direct import/IAT use in this family includes `WaitForSingleObject`, `ReleaseSemaphore`, `CloseHandle`, `WaitForMultipleObjects`, `SetEvent`, and `Sleep`.

## Exact Pending Coverage Row Text

Do not edit `by-memory/-coverage-report.md` directly. Recommended replacement row for [UID:0001JY]:

```text
    - [UID:0001JY][0x00596620-0x005969b0.CashShopRequestWaitDispatch](by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md) 0x00596620-0x005969b0 | aggregate | ThreadMessageDispatchHelpers : reconstructable : 88% : very strong : Generic base `Thread` queue-drain/result-wait/wait-handle/worker-dispatch/post-helper inventory routed to `NexusTK/util/Thread.cpp`; stale CashShop filename/owner rejected, source-facing names inferred for `WaitForQueueDrain`, `WaitForResult`, `AddWaitHandle`, `RemoveLastWaitHandle`, `ThreadProc`, `OnMessage`, `OnMessageEx`, and `DispatchRequest`, queue/result record layouts and fields documented, command-id-2 barrier semantics proven against Socket dispatch fallback, `0x005967f0` liveness corrected via Socket `CloseTransport` tail jump at `0x00577aef`, raw no-xref `0x005969b0` priority-post sibling split recommended, aggregate C++ intentionally blank with exact child emission plan and first-draft method C++ ready.
```

Recommended replacement row for [UID:0001JZ] if that exact child is updated in the same implementation:

```text
    - [UID:0001JZ][0x005967d0-0x005967e5.ThreadAddWaitHandleHelper](by-memory/0x005967d0-0x005967e5.ThreadAddWaitHandleHelper.md) 0x005967d0-0x005967e5 | method | ThreadAddWaitHandleHelper : reconstructable : 89% : very strong : Base `Thread::AddWaitHandle(HANDLE)` helper with exact 0x15-byte body, final `m_waitHandleCount`/`m_waitHandles` field names, two Socket serial-transport consumer refs at `0x005764cc` and `0x0057773f`, no callees, no VA/RVA pointer hits, adjacent padding documented, first-draft C++ ready, and Socket ownership rejected as caller-only inherited Thread infrastructure.
```

If new child pages are created, supervisor should add coverage rows for:

```text
    - [UID:TBD][0x005967f0-0x00596805.ThreadRemoveLastWaitHandleHelper](by-memory/0x005967f0-0x00596805.ThreadRemoveLastWaitHandleHelper.md) 0x005967f0-0x00596805 | method | ThreadRemoveLastWaitHandleHelper : reconstructable : 86% : strong : Base `Thread::RemoveLastWaitHandle()` helper that decrements `m_waitHandleCount`, clears the former last `m_waitHandles` slot, corrects stale alias/decompiler pollution, and has a real Socket `CloseTransport` tail-jump route at `0x00577aef`; first-draft C++ ready.
    - [UID:TBD][0x005969b0-0x00596a00.ThreadDispatchPriorityRequestRaw](by-memory/0x005969b0-0x00596a00.ThreadDispatchPriorityRequestRaw.md) 0x005969b0-0x00596a00 | raw helper | ThreadDispatchPriorityRequestRaw : reconstructable : 85% : strong : Retained no-xref raw `Thread::DispatchPriorityRequest(int,int,int)` sibling that mirrors `DispatchRequest` but enqueues to `m_priorityQueue` at `this+0x50`, releases the base wake semaphore, has no direct rel32/VA/RVA start route, and should split from [UID:0001JY] rather than extending that aggregate.
```

## Validation Commands For Implementation Callback

Run from `source-3/project-documentation` after applying accepted doc edits:

> Executable block R001 was removed from this report and preserved verbatim in [0001JY-ThreadMessageDispatchHelpers-source-quality-removed.md](0001JY-ThreadMessageDispatchHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If new child pages are created, also validate:

> Executable block R002 was removed from this report and preserved verbatim in [0001JY-ThreadMessageDispatchHelpers-source-quality-removed.md](0001JY-ThreadMessageDispatchHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Report-only pass: validators were not run because no by-* docs were edited.

## Implementation Checklist For Later Callback

1. Update [UID:0001JY] metadata to `88/89`, keep owner/emitter.
2. Keep the target formal C++ blank and add aggregate no-code proof.
3. Replace range table roles with source-facing names.
4. Add field/record layout section.
5. Add route/liveness section with exact rel32 and pointer evidence.
6. Add command-id-2 barrier proof from Socket async/sync dispatchers.
7. Correct `0x005967f0` from "no direct callers" to live Socket cleanup tail-jump at `0x00577aef`.
8. Recommend/split exact child for `0x005967f0-0x00596805`.
9. Recommend/split exact child for `0x005969b0-0x00596a00`; keep [UID:0001JY] endpoint unchanged.
10. Update [UID:0000EV] `Thread` class with declaration, field names, record layouts, and helper signatures.
11. Update [UID:0000OR] `Thread` file and [UID:0001JX] aggregate with resolved names and raw sibling policy.
12. Update [UID:0001JZ] with final method name/signature and first-draft C++.
13. Update Thread `.rdata` / no-op virtual docs with slot names if class page adopts them.
14. Update Socket docs for `RemoveLastWaitHandle` tail route.
15. Update CashShop docs to remove [UID:0001JY] as a live ownership question and leave only stale provenance/search references.
16. Provide pending coverage rows to supervisor; do not edit `by-memory/-coverage-report.md`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0001JY-ThreadMessageDispatchHelpers-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:27","uid":"0001JY"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001JY-ThreadMessageDispatchHelpers-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0001JY-ThreadMessageDispatchHelpers-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001JY"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
