*** UID:0000OR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Thread

## Status

- Proposed module: `util/Thread.cpp`
- Proposed header: `util/Thread.h`
- Confidence: very strong for utility/threading ownership, complete `Thread.h/.cpp` topology, exact central worker implementation, concrete Monitor/RingBuffer/List contracts, full Thread virtual order, and the combined Thread/ThreadMan source root; bounded only by exact historical folder/guard and private source spelling.
- Current validator-owned generated source: `NexusTK/util/Thread.cpp` with companion `Thread.h`; both Thread and ThreadMan source route through this compilation unit.
- Historical recovered companions: removed `source-3/simroot_v2/class_Thread.cpp` and `class_ThreadMan.cpp` snapshots are dated provenance only, not current generated-source authority.

## File Role

`Thread.cpp` plus companion `Thread.h` is the shared worker-thread abstraction source root. Guarded H owns the reusable complete [UID:0000EV][Thread](by-class/Thread.md) class and records used by browser, socket, downloader, [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md), and other async subsystems. CPP includes its sibling H and emits exact method/class children, including the exact [UID:0004CL][0x00596810-0x00596915.ThreadProc](by-memory/0x00596810-0x00596915.ThreadProc.md) worker and [UID:0000EW][ThreadMan](by-class/ThreadMan.md), the process-level watchdog/debug thread manager.

The module should stay under `util/` rather than `network/` or `browser/`. Derived classes consume this base, while the base itself owns generic Win32 handles, message queues, synchronous event handoff, thread startup, and cleanup.

## Likely Contents

- [UID:0000EV][Thread](by-class/Thread.md)
- [UID:0000EW][ThreadMan](by-class/ThreadMan.md)
- [UID:0000SH][g_pThreadMan](by-global/g_pThreadMan.md)
- Thread message structs and handler-entry structs
- `Thread::Thread(int messageCapacity)`, `Thread::WaitForQueueDrain`, `Thread::WaitForResult`, `Thread::AddWaitHandle`, `Thread::RemoveLastWaitHandle`, raw `Thread::SetWaitTimeout`, `Thread::StartThread`, raw `Thread::SuspendThread`, raw `Thread::ResumeThread`, `Thread::DispatchRequest`, retained raw `Thread::DispatchPriorityRequest`, and `Thread::DispatchRequestAndReturnEvent`
- Private `ThreadMessage` queue record and `ThreadResultEntry` synchronous result record
- [UID:0001WB][ThreadManWatchRecord](by-type/by-struct/ThreadManWatchRecord.md) and [UID:0001SR][ThreadManMessageId](by-type/by-enum/ThreadManMessageId.md)
- Thread entry helper at `0x00596af0`
- ThreadMan class declaration/API inventory through [UID:0000EW][ThreadMan](by-class/ThreadMan.md)
- File-static `ThreadManWorkerEntry` helper at `0x00597100`
- ThreadMan worker loop, ordinary destructor/message-posting wrappers, constructor, scalar deleting destructor wrapper, and retained watch-list helper island through the `ThreadMan` class/source family
- Guarded `Thread.h` with `<windows.h>`, `"LObject.h"`, `ThreadMessage`, `ThreadResultEntry`, forward declarations, complete `Thread` declaration, fields, and method surface
- Include/dependency route in `Thread.cpp`: `#include "Thread.h"`, then `#include "Singleton.h"`, then the exact `[[CHILDREN]]` implementation stream
- File-static `ThreadMan *g_pThreadMan = NULL;` plus explicit `Singleton<ThreadMan>` constructor/destructor specializations, emitted after the complete ThreadMan class shell and before ThreadMan method children

Thread depends on [UID:0000N8][RingBuffer](by-file/RingBuffer.md), [UID:0000LI][Monitor](by-file/Monitor.md), and [UID:0000KS][List](by-file/List.md). Those are lower-level utility modules and remain separate. The concrete field is `Monitor *m_resultMonitor`; UID0001CL emits `0x00528710` / `0x00528720` as `Monitor::Lock` / `Monitor::Unlock`. Historical `RequestSyncGate *m_resultGate` wording is retained only as a superseded compatibility assumption and must not create duplicate types or bodies.

## Evidence

- IDA MCP confirms a dense thread/thread-manager island at `0x00596250-0x0059756e`.
- `Thread::Thread` constructs two `RingBuffer(24, messageSize)` instances, a `Monitor`, a `List(8, 16)`, a Win32 semaphore, and a suspended `_beginthreadex` worker.
- B006 2026-07-07 MCP session `507affd6` confirms constructor callers push explicit queue/message-capacity values (`5`, `0x64`, and `0x800` observed) before `0x00596250`; the current source-facing declaration is `Thread(int messageCapacity)` or equivalent, not a no-argument constructor.
- `Thread::ThreadProc` sleeps at each iteration, waits on the primary semaphore and additional handles, invokes `OnDispatchBegin`, selects priority before default with `RingBuffer::IsEmpty`, dequeues exactly one record, dispatches asynchronous/synchronous handlers, publishes into caller-created result entries under `Monitor`, signals the caller event, routes secondary wait indices, tests stop, then calls `OnIdle`.
- `Thread` constructor callers at `0x0041a69b`, `0x0045393b`, `0x004700dd`, `0x005281db`, and `0x00574812` indicate broad derived-thread reuse.
- 2026-06-08 IDA MCP parent-gate audit tightened the base `Thread` class evidence: `Thread::ThreadProc` at `0x00596810` dispatches secondary wait-handle notifications through vtable offset `+0x34`; the base `Thread` vtable at `0x0062e26c` stores [UID:0000WL][0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual](by-memory/0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual.md) at that slot; and the `FileDownloader`, `MiniMapDownloader`, `BrowserThread`, and `MiscWorkThread` vtables retain the same inherited default slot.
- `ThreadMan::ThreadMan` writes `g_pThreadMan` at `0x0069be08`, checks `IsDebuggerPresent`, creates a task list, and starts a manager worker thread.
- `ThreadMan` constructs `List(20, 16)` for watchdog records and its worker loop consumes Win32 messages `0x0464-0x0468`.
- The raw ThreadMan helper gap at [UID:0001K1][0x00596d20-0x00596e0b.ThreadManRawMessageWrappers](by-memory/0x00596d20-0x00596e0b.ThreadManRawMessageWrappers.md) posts those same Win32 message ids with `PostThreadMessageW`; current validator-generated `auto-generated/NexusTK/util/Thread.cpp` emits the accepted ordinary destructor/message-wrapper bodies while preserving the raw/no-direct-xref caveat.
- B001 2026-06-16 split the later raw watch-list helper island as [UID:0003V7][0x005971b0-0x005974da.ThreadManWatchListRawHelpers](by-memory/0x005971b0-0x005974da.ThreadManWatchListRawHelpers.md), with outer padding recorded in [UID:0000VN][-ignored](by-memory/-ignored.md). The island has no function objects, no xrefs to starts, and no VA/RVA pointer constants, but its bytes implement ThreadMan watch-list helper logic over the `ThreadManWatchRecord` layout.
- No direct constructor xrefs to `ThreadMan::ThreadMan` were found in this pass. It may be constructed through static/Singleton glue not modeled as a direct call.
- 2026-05-26 IDA MCP recheck reconfirmed the same ThreadMan boundaries: constructor `0x00596bf0`, worker loop `0x00596e10`, worker entry `0x00597100`, singleton clear `0x005974e0`, and scalar deleting destructor `0x005974f0` are modeled; raw wrapper starts `0x00596d20`, `0x00596d70`, `0x00596d90`, `0x00596db0`, `0x00596dd0`, and `0x00596df0` still report `Not a function` with empty xrefs.
- B003 2026-06-20 source-placement review keeps `ThreadMan` in `NexusTK/util/Thread.cpp` and rejects a separate `ThreadMan.cpp` split absent source/PDB/project evidence. The same review routes true member children through [UID:0000EW][ThreadMan](by-class/ThreadMan.md), while `ThreadManWorkerEntry`, [UID:0000SH][g_pThreadMan](by-global/g_pThreadMan.md), and compiler cleanup storage/glue remain file/global or no-code generated artifacts as appropriate.
- B003 2026-06-20 source-quality research resolved [UID:0001JY][0x00596620-0x005969b0.CashShopRequestWaitDispatch](by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md) as generic base `Thread` queue/result/wait-handle/worker-dispatch/post-helper infrastructure. Its historical `queue-drain` family label applies to `WaitForQueueDrain`, not to ThreadProc's per-wake dequeue. The old CashShop names are stale filename/generated-owner residue only; caller diversity, vtable/data refs, field/record layout, and Socket command fallback all point to `util/Thread.cpp`.
- B013 2026-06-21 source-quality review keeps this file as `NexusTK/util/Thread.cpp` / `Thread.h`, rejects Socket/CashShop/FileDownloader/Browser/MiscWorkThread as owners of the base helpers, and treats `ThreadMan.cpp` as unproven. The review confirms `Thread : public LObject`, `ThreadMessage`, `ThreadResultEntry`, `OnWaitObject(int)`, `WaitForQueueDrain`, `WaitForResult`, Add/Remove wait-handle pairing, `DispatchRequest`, raw `DispatchPriorityRequest`, event-backed `DispatchRequestAndReturnEvent`, and `ThreadEntry` as the current source-facing model.
- B011 2026-07-07 MCP session `ef57d27f` reconfirmed [UID:0004CP][0x005969b0-0x00596a00.ThreadDispatchPriorityRequestRaw](by-memory/0x005969b0-0x00596a00.ThreadDispatchPriorityRequestRaw.md) as existing exact child coverage and source emission under this file route. The current repair is return-value/source-quality correction: [UID:0004CP][0x005969b0-0x00596a00.ThreadDispatchPriorityRequestRaw](by-memory/0x005969b0-0x00596a00.ThreadDispatchPriorityRequestRaw.md) pushes to `m_priorityQueue` and returns `ReleaseSemaphore(m_waitHandles[0], 1, NULL)`, while [UID:0004CO][0x00596960-0x005969b0.ThreadDispatchRequest](by-memory/0x00596960-0x005969b0.ThreadDispatchRequest.md) pushes to `m_messageQueue` and returns the same semaphore result. B011 also found zero xrefs and zero VA/RVA/file-offset pointer-byte hits for `0x005969b0`; this remains a raw-helper caveat, not a reason to remove the source body or move it to consumer modules.
- B006 2026-06-20 Socket source-quality research reconfirms the Socket boundary from the Socket side: `0x00596960` remains Thread queue infrastructure used by Socket command wrappers, and direct calls to `Thread::AddWaitHandle` at `0x005764cc` and raw `0x0057773f` are Socket setup/serial-open consumers only.
- B008 2026-06-19 scalar-wrapper recheck keeps [UID:0001K5][0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor](by-memory/0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md) as a direct [UID:0000EW][ThreadMan](by-class/ThreadMan.md) child routed through this source file. The local PE scan found no direct constructor caller and no direct target callers for the scalar wrapper, but the wrapper's sole target-VA pointer hit is the `ThreadMan` vtable slot at `.rdata:0x0062e2c4`, so missing direct calls do not justify file-direct ownership, no-owner handling, or a fake source method.
- B009 2026-06-19 older Rule 26 report reaches the same source-routing decision for [UID:0001K5][0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor](by-memory/0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md): this file remains the `util/Thread.cpp` source root, [UID:0000EW][ThreadMan](by-class/ThreadMan.md) is the narrow direct owner/emitter, and the blank formal C++ block is intentional generated-wrapper policy rather than a stale `95+` gate blocker. The ordinary destructor source body is represented by [UID:0001K1][0x00596d20-0x00596e0b.ThreadManRawMessageWrappers](by-memory/0x00596d20-0x00596e0b.ThreadManRawMessageWrappers.md)'s raw `0x00596d20` cleanup sequence, not by hand-porting the scalar wrapper.
- B012 source-quality reanalysis independently reaches the same route: keep [UID:0000OR][Thread](by-file/Thread.md) as the `NexusTK/util/Thread.cpp` source-file root, but route the scalar deleting destructor wrapper directly through [UID:0000EW][ThreadMan](by-class/ThreadMan.md). The missing direct constructor call remains a broader singleton/static-initializer question, not a reason to create `ThreadMan.cpp`, demote [UID:0001K5][0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor](by-memory/0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md) to no-owner, or move wrapper code into handwritten source.
- B009 2026-07-04 UID0001CL callback established that old `RequestSyncGate` helper labels at `0x00528710` / `0x00528720` are source-emitted by [UID:0001CL][0x005285e0-0x00528929.MonitorAndConditions](by-memory/0x005285e0-0x00528929.MonitorAndConditions.md) as `Monitor::Lock` / `Monitor::Unlock`. B008's exact worker pass closes the remaining field question as `Monitor *m_resultMonitor`; the earlier alias remains historical only.
- B008 2026-08-01 live worker-loop reanalysis reconfirmed [UID:0004CL][0x00596810-0x00596915.ThreadProc](by-memory/0x00596810-0x00596915.ThreadProc.md) as `[0x00596810,0x00596915)`, 261 bytes, with five inherited vtable refs and no direct code caller. One `RingBuffer_Dequeue`, no `List::Add`, inline `List::GetCount`, virtual `List::GetElementAt`, Monitor lock/unlock, and stop-before-idle control flow independently establish the exact source body.
- The formal split is now self-contained: [UID:0000EV][Thread](by-class/Thread.md) emits complete guarded `Thread.h` after explicit Win32/LObject dependencies, while its CPP channel contains only `#include "Thread.h"` and the child stream. This closes downstream complete-base legality for `MiscWorkThread` without moving or duplicating any Thread body.
- 2026-07-31/2026-08-01 B007 live reanalysis resolves the ThreadMan singleton source topology. RTTI gives `ThreadMan` three hierarchy entries with direct empty `Singleton<ThreadMan>` at PMD `{4,-1,0}`; constructor order publishes `g_pThreadMan` through the adjusted base before the derived body, and ordinary/EH/scalar teardown clears it at the reverse-base stage. The source root therefore requires `"Singleton.h"`, a dual-base ThreadMan declaration, and class-specific Singleton specializations rather than explicit derived constructor/destructor assignments.
- [UID:0000SH][g_pThreadMan](by-global/g_pThreadMan.md) remains canonically owned by this Thread.cpp file but emits through ThreadMan UID0000EW at position `1`. This is an output-order attachment, not class-static ownership: it places the file-static definition/specializations after the complete class declaration and before method bodies. The exact by-memory storage child remains covered-by and does not duplicate the definition.

## Thread Dispatch Helper Resolution

[UID:0001JY][0x00596620-0x005969b0.CashShopRequestWaitDispatch](by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md) is resolved as generic base `Thread` queue-drain, result-wait, wait-handle, worker-dispatch, and queue-post infrastructure. The old `CashShopRequestWaitDispatch` filename and generated owner labels are search/provenance residue only.

Current source-facing helper names and split policy:

| Range | Source-facing role | Notes |
| --- | --- | --- |
| `0x00596620-0x0059675e` | [UID:0004CI][0x00596620-0x0059675e.ThreadWaitForQueueDrain](by-memory/0x00596620-0x0059675e.ThreadWaitForQueueDrain.md) | Queues synchronous no-op message id `2`, waits for the event, and drains earlier queued work. Socket async dispatch handles ids `3-14`, and Socket sync dispatch handles only id `0x0c` specially, so id `2` falls to the base handler. |
| `0x00596760-0x005967c7` | [UID:0004CJ][0x00596760-0x005967c7.ThreadWaitForResult](by-memory/0x00596760-0x005967c7.ThreadWaitForResult.md) | Waits on the event, scans/removes result entry, closes the event, and returns the stored result; preserve the binary's odd no-match event-handle fallback until source evidence proves dead code. |
| `0x005967d0-0x005967e5` | `Thread::AddWaitHandle(HANDLE)` | Exact child [UID:0001JZ][0x005967d0-0x005967e5.ThreadAddWaitHandleHelper](by-memory/0x005967d0-0x005967e5.ThreadAddWaitHandleHelper.md). |
| `0x005967f0-0x00596805` | [UID:0004CK][0x005967f0-0x00596805.ThreadRemoveLastWaitHandle](by-memory/0x005967f0-0x00596805.ThreadRemoveLastWaitHandle.md) | Live through Socket `CloseTransport` tail jump `0x00577aef`; now exact child coverage. |
| `0x00596810-0x00596915` | [UID:0004CL][0x00596810-0x00596915.ThreadProc](by-memory/0x00596810-0x00596915.ThreadProc.md) | Calls `OnDispatchBegin`, selects nonempty priority before default, dequeues exactly one `ThreadMessage` per primary wake, dispatches async/sync virtual handlers, writes caller-created result entries under `Monitor`, signals events, routes secondary wait indices, tests stop, then calls `OnIdle`. |
| `0x00596920-0x00596931` | [UID:0004CM][0x00596920-0x00596931.ThreadOnMessage](by-memory/0x00596920-0x00596931.ThreadOnMessage.md) | Base async message handler; message id `1` sets `m_stopRequested`. |
| `0x00596940-0x0059695e` | [UID:0004CN][0x00596940-0x0059695e.ThreadOnMessageEx](by-memory/0x00596940-0x0059695e.ThreadOnMessageEx.md) | Base sync message handler; message id `1` sets `m_stopRequested` and returns `0`. |
| `0x00596960-0x005969b0` | [UID:0004CO][0x00596960-0x005969b0.ThreadDispatchRequest](by-memory/0x00596960-0x005969b0.ThreadDispatchRequest.md) | Default async post helper used by downloader, MiscWorkThread, Socket, and packet-send wrappers. |
| `0x005969b0-0x00596a00` | [UID:0004CP][0x005969b0-0x00596a00.ThreadDispatchPriorityRequestRaw](by-memory/0x005969b0-0x00596a00.ThreadDispatchPriorityRequestRaw.md) | Writes to `m_priorityQueue` at `+0x50`, has no direct refs, and is now exact adjacent child coverage instead of a [UID:0001JY][0x00596620-0x005969b0.CashShopRequestWaitDispatch](by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md) subrange. |
| `0x00596a00-0x00596ae8` | `Thread::DispatchRequestAndReturnEvent(...)` | Event-backed synchronous post helper. |

Field names now used across Thread docs are `m_waitTimeout`, `m_waitHandleCount`, `m_waitHandles`, `m_messageQueue`, `m_priorityQueue`, `m_resultMonitor`, `m_resultList`, `m_threadHandle`, `m_threadId`, and `m_stopRequested`; the 24-byte `ThreadMessage` and 8-byte `ThreadResultEntry` records are exact current layouts. `Monitor *m_resultMonitor` replaces the historical `RequestSyncGate *m_resultGate` alias.

## Exact ThreadProc Source Correction

- Each loop iteration begins with `Sleep(1)` and `WaitForMultipleObjects(m_waitHandleCount, m_waitHandles, FALSE, m_waitTimeout)`.
- Primary wake index zero invokes `OnDispatchBegin` before queue selection. `m_priorityQueue` is preferred only when nonempty; `m_messageQueue` is the fallback. Exactly one selected record is removed through `RingBuffer::Dequeue`.
- Null-event messages call `OnMessage(messageId,arg1,arg2)`. Event-backed messages call `OnMessageEx(messageId,syncArg1,syncArg2,arg1,arg2)` and publish the return value into an existing matching `ThreadResultEntry` while `m_resultMonitor` is locked.
- The worker reads inline `List::GetCount`, calls virtual `List::GetElementAt(int)`, writes only `entry->result`, unlocks, and calls `SetEvent` even if no matching entry was found. The caller creates/registers the entry; ThreadProc never appends one.
- A nonzero wait result below the handle count is passed directly to `OnWaitObject(int)`. Every path then checks `m_stopRequested`; a set flag returns `0`, otherwise `OnIdle` runs before the next iteration.
- The full virtual sequence is `OnStart`, `OnThreadBegin`, `ThreadProc`, `OnThreadEnd`, `OnDispatchBegin`, `OnIdle`, `OnMessage`, `OnMessageEx`, and `OnWaitObject`. These source-facing names are high-probability inferences grounded in exact call timing and derived vtables; the order and behavior are binary-exact.
- Historical generated command `000000020493` emitted the stale drain loop, `Pop`, stack-created result entry, `List::Add`, `RequestSyncGate`, and omitted virtual hooks. That output is retained as documentation-state history and must be regenerated from the corrected ordinary pages; it is not binary authority.

## B011 2026-07-07 Dispatch Return Repair Generated-Output Note

Pre-callback generated file inspected read-only during the accepted UID0004CP callback:

- `auto-generated/NexusTK/util/Thread.cpp`
- Pre-callback generated header proof: `validator-command-id: 000000007870`
- Pre-callback generated timestamp: `validator-refreshed-at: 2026-07-07T14:22:33-04:00`
- Refresh source: `deferred-generated-refresh`
- Pre-callback state: UID0004CO and UID0004CP both still emitted stale `return queued` bodies. This callback repairs the by-memory source so a scoped validator refresh can regenerate both helpers as `return ReleaseSemaphore(m_waitHandles[0], 1, NULL)`.

UID0004CP now exists as exact child coverage and emits through this `NexusTK/util/Thread.cpp` route. Its raw no-function/no-direct-xref state remains documented on the target page, but the accepted source-quality repair is return-value correction rather than split creation or ownership transfer.

## B006 2026-07-07 Report-Time Generated-Output And UID0001JX Split Note

Report-time generated file inspected during the accepted UID0001JX callback:

- `auto-generated/NexusTK/util/Thread.cpp`
- Report-time generated header proof: `validator-command-id: 000000007832`
- Report-time generated timestamp: `validator-refreshed-at: 2026-07-07T03:37:36-04:00`
- UID0001JX remains an empty aggregate marker because the missing Thread constructor/destructor/lifecycle/event-backed/entry/scalar-wrapper children do not yet exist.

The no-loss split plan keeps [UID:0001JX][0x00596250-0x0059756e.ThreadAndThreadMan](by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md) reconstructable and attached to this `Thread.cpp` source route until exact children are created for `ThreadConstructor`, `ThreadDestructor`, `ThreadStopThread`, `ThreadForceTerminate`, `ThreadSetWaitTimeoutRaw`, `ThreadStartThread`, `ThreadSuspendThreadRaw`, `ThreadResumeThreadRaw`, `ThreadDispatchRequestAndReturnEvent`, `ThreadEntry`, and `ThreadScalarDeletingDestructor`. Do not convert UID0001JX to non-emitting and do not paste those child bodies into the aggregate formal C++ block before those pages carry accepted source/no-code dispositions.

The current Thread-side raw additions are `0x005965d0-0x005965db` as `m_waitTimeout` setter, `0x00596600-0x00596609` as raw `SuspendThread`, and `0x00596610-0x00596619` as raw `ResumeThread`; all three have no current IDA function records and zero incoming xrefs. Modeled `0x005965e0-0x005965f3` is `Thread::StartThread`, with six code xrefs, a folded/default vtable hook call at `+0x14`, and a Win32 `ResumeThread` call.

## B007 2026-07-01 Historical Generated-Output Audit

Historical generated file inspected for the accepted B007 callback:

- `auto-generated/NexusTK/util/Thread.cpp`
- Generated header proof before implementation: `validator-command-id: 000000003465`
- Generated timestamp before implementation: `validator-refreshed-at: 2026-07-01T05:44:04-04:00`
- Tracker context before implementation: 17 total emitters, 5 filled, 12 empty, 29.4%.

The five populated outputs before this callback were:

- [UID:0000EV][Thread](by-class/Thread.md) `Thread` class declaration.
- [UID:0000EW][ThreadMan](by-class/ThreadMan.md) `ThreadMan` class declaration.
- [UID:0001SR][ThreadManMessageId](by-type/by-enum/ThreadManMessageId.md) `ThreadManMessageId` enum.
- [UID:0001WB][ThreadManWatchRecord](by-type/by-struct/ThreadManWatchRecord.md) `ThreadManWatchRecord` struct.
- [UID:0001JZ][0x005967d0-0x005967e5.ThreadAddWaitHandleHelper](by-memory/0x005967d0-0x005967e5.ThreadAddWaitHandleHelper.md) `Thread::AddWaitHandle` body.

Accepted empty-marker dispositions:

- [UID:0000WL][0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual](by-memory/0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual.md): emit empty `Thread::OnWaitObject(int)` body; preserve folded-vtable/STL caveat.
- [UID:0001K0][0x00596bf0-0x00596d13.ThreadManConstructor](by-memory/0x00596bf0-0x00596d13.ThreadManConstructor.md): emit first-draft `ThreadMan::ThreadMan()` with debugger probe, `List(20,16)`, `CreateThread`, and `Win32Error` throw evidence.
- [UID:0001K1][0x00596d20-0x00596e0b.ThreadManRawMessageWrappers](by-memory/0x00596d20-0x00596e0b.ThreadManRawMessageWrappers.md): emit ordinary `ThreadMan::~ThreadMan()` and retained message wrappers for ids `0x0464-0x0468`; preserve raw/no-direct-xref caveat.
- [UID:0001K2][0x00596e10-0x005970df.ThreadManWorkerLoop](by-memory/0x00596e10-0x005970df.ThreadManWorkerLoop.md): emit first-draft `ThreadMan::RunMessagePump()`; preserve timeout `500`, wake mask `0x4ff`, message drain, watchdog, and helper-name caveats.
- [UID:0001K5][0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor](by-memory/0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md): formal comment-only compiler-wrapper disposition; ordinary destructor source lives in [UID:0001K1][0x00596d20-0x00596e0b.ThreadManRawMessageWrappers](by-memory/0x00596d20-0x00596e0b.ThreadManRawMessageWrappers.md).
- [UID:0001WA][ThreadManLayout](by-type/by-struct/ThreadManLayout.md): formal comment-only no-duplicate layout disposition; [UID:0000EW][ThreadMan](by-class/ThreadMan.md) emits the `ThreadMan` fields.
- [UID:0000SH][g_pThreadMan](by-global/g_pThreadMan.md): emit `static ThreadMan *g_pThreadMan = NULL;`.
- [UID:000305][0x0069be08-0x0069be0c.g_pThreadMan](by-memory/0x0069be08-0x0069be0c.g_pThreadMan.md): formal comment-only exact-storage/no-duplicate disposition for `g_pThreadMan`.
- [UID:0001JX][0x00596250-0x0059756e.ThreadAndThreadMan](by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md): not cleared in this bounded callback; broader exact child split remains required for remaining Thread bodies before later non-emitting historicalization.
- [UID:0001JY][0x00596620-0x005969b0.CashShopRequestWaitDispatch](by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md): converted to non-emitting split index only after exact children [UID:0004CI][0x00596620-0x0059675e.ThreadWaitForQueueDrain](by-memory/0x00596620-0x0059675e.ThreadWaitForQueueDrain.md), [UID:0004CJ][0x00596760-0x005967c7.ThreadWaitForResult](by-memory/0x00596760-0x005967c7.ThreadWaitForResult.md), [UID:0001JZ][0x005967d0-0x005967e5.ThreadAddWaitHandleHelper](by-memory/0x005967d0-0x005967e5.ThreadAddWaitHandleHelper.md), [UID:0004CK][0x005967f0-0x00596805.ThreadRemoveLastWaitHandle](by-memory/0x005967f0-0x00596805.ThreadRemoveLastWaitHandle.md), [UID:0004CL][0x00596810-0x00596915.ThreadProc](by-memory/0x00596810-0x00596915.ThreadProc.md), [UID:0004CM][0x00596920-0x00596931.ThreadOnMessage](by-memory/0x00596920-0x00596931.ThreadOnMessage.md), [UID:0004CN][0x00596940-0x0059695e.ThreadOnMessageEx](by-memory/0x00596940-0x0059695e.ThreadOnMessageEx.md), and [UID:0004CO][0x00596960-0x005969b0.ThreadDispatchRequest](by-memory/0x00596960-0x005969b0.ThreadDispatchRequest.md) carry the source bodies; adjacent priority sibling [UID:0004CP][0x005969b0-0x00596a00.ThreadDispatchPriorityRequestRaw](by-memory/0x005969b0-0x00596a00.ThreadDispatchPriorityRequestRaw.md) carries `0x005969b0-0x00596a00`.
- [UID:0001K3][0x00597100-0x005971ad.ThreadManWorkerEntry](by-memory/0x00597100-0x005971ad.ThreadManWorkerEntry.md): emit first-draft `ThreadManWorkerEntry`; preserve exception API and application-exit naming caveats.
- [UID:00026P][0x0062e268-0x0062e334.ThreadReadOnlyData](by-memory/0x0062e268-0x0062e334.ThreadReadOnlyData.md): formal comment-only vtable/RTTI/literal no-standalone-source disposition.

Route rationale: keep [UID:0000OR] as the file root for `NexusTK/util/Thread.cpp`, [UID:0000EV][Thread](by-class/Thread.md) for the base `Thread` declaration, and [UID:0000EW][ThreadMan](by-class/ThreadMan.md) for the `ThreadMan` declaration. Exact child pages carry source bodies; aggregate/index pages such as [UID:0001JY][0x00596620-0x005969b0.CashShopRequestWaitDispatch](by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md) and the broader [UID:0001JX][0x00596250-0x0059756e.ThreadAndThreadMan](by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md) must not duplicate child source in their own formal C++ blocks.

## Generated Output Caveats

The removed `source-3/simroot_v2/class_Thread.cpp` companion historically emitted most of the main `Thread` helper island through `0x00596bb0`, the global `ThreadEntry` helper, `Thread::DispatchRequest` at `0x00596960`, and the event-returning synchronous post helper at `0x00596a00`. That snapshot and its caveats are retained below as dated provenance; current generated-source authority is validator-owned `NexusTK/util/Thread.cpp/.h`:

- `0x00596620` and `0x00596760` remain documented/generated in some historical places with `CashShopRequest::*` owner names even though the bodies operate on generic `Thread` queues, `Monitor *m_resultMonitor`, and result-event lists. Treat those names and `RequestSyncGate` as stale aliases. UID0001CL owns the lock/unlock bodies as `Monitor::Lock` / `Monitor::Unlock`.
- Validator command `000000020493` generated a stale UID0004CL drain/new-entry body and incomplete Thread header. The corrected by-memory/class pages now require one-message-per-wake CPP and a header containing all virtual hooks plus `Monitor`; generated output must catch up through supervisor workflow and must not be edited manually.
- `0x00596960` is the queue post primitive used by [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md) and by cash-shop/download request helpers. The removed simroot snapshot hinted at generic `Thread` ownership; current documentation and validator-owned output accept `Thread::DispatchRequest`, while older `CashShopRequest` spellings remain historical aliases.
- `0x005969b0-0x00596a00` is currently raw/no-direct-ref but should not be discarded. It is the priority-post sibling, now exists as exact child [UID:0004CP][0x005969b0-0x00596a00.ThreadDispatchPriorityRequestRaw](by-memory/0x005969b0-0x00596a00.ThreadDispatchPriorityRequestRaw.md), and emits through this `Thread.cpp` source route; the current source-quality repair is that UID0004CP and [UID:0004CO][0x00596960-0x005969b0.ThreadDispatchRequest](by-memory/0x00596960-0x005969b0.ThreadDispatchRequest.md) return `ReleaseSemaphore` rather than the queue push result.
- [UID:0003GY][0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper](by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md) is a dependency-only semantic wrapper around `0x00596960`: B002 2026-06-17 reconfirmed it forwards `(this, messageId, payload, 0)` to the generic queue post helper but has no caller, pointer, vtable, source-neighbor, or declaration evidence proving it belongs in `Thread.cpp` output.
- `0x00596bb0` is emitted with the artifact type name `Thread_00596bb0`.
- The generated `ThreadEntry` helper is useful but still low-fidelity in exception typing and surrounding declarations.

The removed `source-3/simroot_v2/class_ThreadMan.cpp` companion historically emitted the worker loop and entry helpers, but its `RunMessagePump` had very low fidelity and introduced fake helpers for Win32 message dispatch. It also omitted the raw ThreadMan destructor/message wrappers in `0x00596d20-0x00596e0b` and the raw watch-list helper island at [UID:0003V7][0x005971b0-0x005974da.ThreadManWatchListRawHelpers](by-memory/0x005971b0-0x005974da.ThreadManWatchListRawHelpers.md). These are provenance caveats, not current authority. Disabled `ThreadMan` rows at `0x0045004b` and `0x004e0052` are not valid ThreadMan methods; `0x004e0052` is an interior instruction in `NewHumanImageLib::NewHumanImageLib`, and `0x00597570` belongs to [UID:0000F0][TimerHandler](by-class/TimerHandler.md), not ThreadMan.

2026-05-26 IDA MCP recheck still resolves disabled row `0x0045004b` inside `sub_450030` at `0x00450030`, a small lower-bound/binary-search helper called from the LodePNG island, and resolves `0x004e0052` inside `NewHumanImageLib::NewHumanImageLib` at `0x004dfd10`. It also reconfirmed `0x00597570` as the `TimerHandler` vtable-installing constructor with non-ThreadMan callers.

## Source-Structure Decision

Use `util/Thread.cpp` plus companion guarded `util/Thread.h` for `Thread` and `ThreadMan` until contrary evidence appears. `Thread.h` owns the complete reusable `Thread`/record declaration after explicit `<windows.h>` and `"LObject.h"` dependencies. `Thread.cpp` includes that sibling header, includes `"Singleton.h"` for the CPP-resident ThreadMan direct base/specializations, and carries the exact child implementation stream; it must not retain a duplicate Thread declaration.

Keeping `Thread` and `ThreadMan` together matches the memory island, singleton/watchdog relationship, and shared thread-message abstractions. Keep [UID:00001A][BrowserThread](by-class/BrowserThread.md) with [UID:0000HV][Browser](by-file/Browser.md) and [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md) with [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md); both are derived worker implementations, not part of this generic base file. Their headers consume the complete Thread declaration instead of an incomplete base or implicit PCH definition.

[UID:0000EW][ThreadMan](by-class/ThreadMan.md) owns the source-facing dual-base class declaration and member API inventory. The exact child by-memory pages carry method-body/range evidence. `ThreadManWorkerEntry` remains a file-static helper in this file unless later evidence proves a private static member spelling. [UID:0000SH][g_pThreadMan](by-global/g_pThreadMan.md) remains file-static storage with explicit class-specific Singleton lifetime specializations; neither a `ThreadMan::ClearSingleton` source method nor explicit derived publication/clear statements should be emitted.

[UID:0001K5][0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor](by-memory/0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md) is reconstructable generated-binary support for `ThreadMan::~ThreadMan()`, not a standalone handwritten method in `Thread.cpp`. Keep the source route through this file, but let the class declaration/destructor regenerate the wrapper.

The normalized `NEXUSTK_UTIL_THREAD_H` guard is deterministic reconstruction topology; exact historical macro spelling remains inferred. This source split preserves all ThreadMan/helper/raw-wrapper history and changes only declaration placement. It rejects a CPP-resident duplicate class, absent-header dependency, incomplete direct base, or PCH-only source route.

## Cross-References

- [UID:0000EV][Thread](by-class/Thread.md)
- [UID:0000EW][ThreadMan](by-class/ThreadMan.md)
- [UID:0001JX][0x00596250-0x0059756e.ThreadAndThreadMan](by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md)
- [UID:0001K1][0x00596d20-0x00596e0b.ThreadManRawMessageWrappers](by-memory/0x00596d20-0x00596e0b.ThreadManRawMessageWrappers.md)
- [UID:0001K2][0x00596e10-0x005970df.ThreadManWorkerLoop](by-memory/0x00596e10-0x005970df.ThreadManWorkerLoop.md)
- [UID:0003V7][0x005971b0-0x005974da.ThreadManWatchListRawHelpers](by-memory/0x005971b0-0x005974da.ThreadManWatchListRawHelpers.md)
- [UID:0000SH][g_pThreadMan](by-global/g_pThreadMan.md)
- [UID:0001WB][ThreadManWatchRecord](by-type/by-struct/ThreadManWatchRecord.md)
- [UID:0001SR][ThreadManMessageId](by-type/by-enum/ThreadManMessageId.md)
- [UID:0000N8][RingBuffer](by-file/RingBuffer.md)
- [UID:0000LI][Monitor](by-file/Monitor.md)
- [UID:0001JZ][0x005967d0-0x005967e5.ThreadAddWaitHandleHelper](by-memory/0x005967d0-0x005967e5.ThreadAddWaitHandleHelper.md)
- [UID:0001QT][client_threading](by-meta/client_threading.md)
- [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md)
- [UID:0004ZK][Singleton](by-file/Singleton.md)

## UID0000LI Dependency Closure - 2026-08-15

`Monitor *m_resultMonitor` and exact Monitor Lock/Unlock ownership are reconfirmed. Historical `RequestSyncGate *m_resultGate` text remains explicitly superseded and cannot create a source type or duplicate methods. Thread remains a consumer; the Monitor split changes no Thread method behavior, owner, or emitter route.

## Changes

- 2026-08-01 B008 UID0004CL implementation callback:
  - Raised `91/91` to `92/93` while preserving `NexusTK/util/Thread.cpp` / `Thread.h` and FILE ownership.
  - Added the exact one-message-per-wake ThreadProc flow, complete virtual sequence, concrete Monitor field, RingBuffer/List API contracts, caller-created result protocol, five-vtable route, stop/OnIdle timing, and generated command20493 correction.
  - Historicalized the prior drain-loop, Pop, new-entry/List::Add, RequestSyncGate, OnDispatchEnd, and derived Socket source-spelling assumptions without pruning their provenance.
- 2026-08-01 B007 UID000305 support callback:
  - Preserved `91/91`, `NexusTK/util/Thread.cpp` / `Thread.h`, and the existing Thread/ThreadMan ownership split.
  - Added the exact `Singleton.h` dependency, dual-base ThreadMan source model, file-static singleton definition/specializations, UID0000SH-to-UID0000EW position-1 ordering, and no-duplicate storage rule.
  - Historicalized explicit derived constructor/destructor global assignments in favor of specialization-generated normal/EH/scalar lifetime behavior; no unrelated Thread method, record, or generated-output caveat was pruned.

- 2026-07-07 B011 UID0004CP support callback:
  - What existed before: generated-output caveat text still said `0x005969b0-0x00596a00` should emit once split/UID assignment is available, and the current generated `Thread.cpp` still contained stale `return queued` bodies for UID0004CO/UID0004CP.
  - Changed to: documented that UID0004CP now exists and emits through this `NexusTK/util/Thread.cpp` route, added the B011 dispatch return repair note, and updated the caveat to say the current repair is return-value/source-quality correction rather than split creation.
  - Summary/evidence: pre-callback generated `auto-generated/NexusTK/util/Thread.cpp` was read-only inspected at command `000000007870`, refreshed `2026-07-07T14:22:33-04:00`, and still emitted stale `return queued` bodies; B011 MCP session `ef57d27f` proved UID0004CP is a raw no-function/no-xref priority-post sibling and that UID0004CO/UID0004CP return `ReleaseSemaphore`.
- 2026-07-07 B006 UID0001JX implementation callback:
  - Summary/evidence: added current generated `Thread.cpp` header command `000000007832` / `2026-07-07T03:37:36-04:00`, documented the UID0001JX no-loss split plan, added the `Thread(int messageCapacity)` constructor evidence, and synchronized raw `SetWaitTimeout`/`SuspendThread`/`ResumeThread` plus `StartThread` wrapper caveats while preserving the `NexusTK/util/Thread.cpp` source route.
- 2026-07-04 B009 UID0001CL support sync:
  - Added a narrow caveat that Thread's `RequestSyncGate *m_resultGate` wording is compatibility/result-gate support only; [UID:0001CL][0x005285e0-0x00528929.MonitorAndConditions](by-memory/0x005285e0-0x00528929.MonitorAndConditions.md) emits `0x00528710` / `0x00528720` as `Monitor::Lock` / `Monitor::Unlock`.
  - No Thread metadata or declaration rewrite: changing the result-gate type broadly is outside this callback and would touch Thread source-shape beyond the accepted Monitor support repair.
- 2026-06-21 B013 Thread class source-quality incorporation:
  - Summary/evidence: recorded B013's independent confirmation of the `NexusTK/util/Thread.cpp` route, `Thread : public LObject`, the `ThreadMessage`/`ThreadResultEntry` layouts, the resolved helper names, the Add/Remove wait-handle pairing with Socket as consumer only, stale CashShop/Socket/generated-owner rejection, and declaration-only class C++ policy. No score change was needed because this file was already above the accepted source-root gate.
- 2026-07-01 B007 bounded implementation callback:
  - Summary/evidence: added generated-output audit for command `000000003465`, recorded the 17/5/12/29.4% tracker context, documented all twelve accepted empty-marker dispositions, added exact [UID:0001JY][0x00596620-0x005969b0.CashShopRequestWaitDispatch](by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md) child links [UID:0004CI][0x00596620-0x0059675e.ThreadWaitForQueueDrain](by-memory/0x00596620-0x0059675e.ThreadWaitForQueueDrain.md)-[UID:0004CO][0x00596960-0x005969b0.ThreadDispatchRequest](by-memory/0x00596960-0x005969b0.ThreadDispatchRequest.md) plus adjacent [UID:0004CP][0x005969b0-0x00596a00.ThreadDispatchPriorityRequestRaw](by-memory/0x005969b0-0x00596a00.ThreadDispatchPriorityRequestRaw.md), and preserved that [UID:0001JX][0x00596250-0x0059756e.ThreadAndThreadMan](by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md) remains emitting until a broader exact-child split is accepted.
- 2026-06-20 B003 Thread dispatch helper Rule 26 incorporation:
  - Before: `CONFIDENCE:85`; the file page still said `0x00596620`/`0x00596760` needed ownership cleanup and did not carry the current field/record/helper-name resolution.
  - Changed to: `CONFIDENCE:88`, added `Thread::WaitForQueueDrain`, `Thread::WaitForResult`, `Thread::AddWaitHandle`, `Thread::RemoveLastWaitHandle`, `Thread::DispatchRequest`, retained `Thread::DispatchPriorityRequest`, `Thread::DispatchRequestAndReturnEvent`, `ThreadMessage`, and `ThreadResultEntry` to likely contents, and added a dispatch-helper resolution section.
  - Summary/evidence: B003 [UID:0001JY][0x00596620-0x005969b0.CashShopRequestWaitDispatch](by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md) research proves base `Thread` ownership through queue/result fields, `RequestSyncGate` use, broad rel32 caller fan-in, vtable/data refs, Socket command-id fallback, live `0x005967f0` Socket cleanup tail jump, and the priority-queue sibling at `0x005969b0`.
- 2026-06-20 B006 Socket support sync:
  - Added Socket-side confirmation that `Thread::DispatchRequest` and `Thread::AddWaitHandle` are inherited Thread infrastructure consumed by Socket, not Socket-owned source.
- 2026-06-20 B003 ThreadMan Rule 26 incorporation:
  - Summary/evidence: recorded the accepted `NexusTK/util/Thread.cpp` source-placement decision for `ThreadMan`, rejected a separate `ThreadMan.cpp` split absent source evidence, clarified that the class page owns the declaration/API while child pages own method bodies, and documented that true `ThreadMan` member children route through [UID:0000EW][ThreadMan](by-class/ThreadMan.md) while the worker entry and singleton global remain file/global artifacts.
- 2026-06-21 B008 ThreadMan scalar-wrapper support sync:
  - Summary/evidence: added the target-specific [UID:0001K5][0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor](by-memory/0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md) route policy from B008: direct owner/emitter is [UID:0000EW][ThreadMan](by-class/ThreadMan.md), [UID:0000OR] remains only the source-file route, and missing direct caller/constructor xrefs do not block class ownership because the wrapper is vtable-reachable generated destructor support.
- 2026-06-21 B009 Rule 26 older-report reconciliation:
  - Summary/evidence: recorded B009's route policy and no-code reason for [UID:0001K5][0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor](by-memory/0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md), preserving `Thread.cpp` as the source root while keeping direct ownership on [UID:0000EW][ThreadMan](by-class/ThreadMan.md).
- 2026-06-22 B012 source-quality implementation:
  - Summary/evidence: added B012's confirmation that this file remains the `util/Thread.cpp` source root while the scalar wrapper's direct owner/emitter is [UID:0000EW][ThreadMan](by-class/ThreadMan.md); missing constructor reachability remains a broader startup/static route issue, not a blocker for wrapper routing.
- 2026-06-08 A001 Batch100 parent/source refresh:
  - Before: `COMPLETION:88`, `CONFIDENCE:80`.
  - After: `COMPLETION:89`, `CONFIDENCE:85`.
  - Evidence: live IDA MCP refreshed the base `Thread` vtable/dispatch relationship by tying `Thread::ThreadProc` non-primary wait-handle dispatch at offset `+0x34` to the inherited [UID:0000WL][0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual](by-memory/0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual.md) slot across the base and derived thread/downloader vtables. This strengthens the file-level source-root confidence while preserving the exact-folder and final helper-name caveats.
- 2026-06-16 B001 ThreadMan raw watch-list split:
  - Summary/evidence: added exact child [UID:0003V7][0x005971b0-0x005974da.ThreadManWatchListRawHelpers](by-memory/0x005971b0-0x005974da.ThreadManWatchListRawHelpers.md) to the likely contents/caveats/cross-references. No score change; the file already owned the ThreadMan source root, and the new child remains blank-C++ pending original helper names and reachability/source-emission policy.
- 2026-06-17 B002 dependency-only wrapper note:
  - Summary/evidence: added [UID:0003GY][0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper](by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md) as a semantic dependency caveat only. Its body is a Thread queue wrapper, but B002 found no source-placement route to `Thread.cpp`, so it remains no-owner/non-emitting.
- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `88` and confidence to `80`.
  - Evidence: document covers Thread/ThreadMan module role, likely contents, dependencies, IDA island evidence, caller fan-in, singleton/watchdog behavior, raw wrapper gaps, generated-output caveats, source-structure decision, and cross-references; confidence remains capped by exact original folder and ThreadMan split.
- 2026-05-31: Assigned projected reconstruction path.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank.
  - After: set path to `NexusTK/util/`.
  - Evidence: the page already documents `util/Thread.cpp` as the working module, and the 2026-05-31 IDA MCP recheck reconfirmed ThreadMan singleton storage/cleanup around `0x0069be08`, the `ThreadMan` constructor at `0x00596bf0`, the clear helper at `0x005974e0`, and the scalar deleting destructor at `0x005974f0`.
- 2026-07-31 B004 UID0004HM implementation:
  - Changed score from `89/88` to `91/91`; path and canonical file ownership remain unchanged.
  - Made the documented `Thread.cpp`/`Thread.h` pair physical in formal source: guarded complete class/record declaration in H after explicit Win32/LObject dependencies, and sibling-header include plus child stream in CPP.
  - Preserved all Thread/ThreadMan methods, fields, records, dispatch/wait helpers, singleton/watchdog evidence, raw-wrapper caveats, exact child routes, Monitor compatibility, source-placement history, and generated caveats.
  - Documented legal downstream complete-base use by `MiscWorkThread` and rejected CPP-resident duplicate declarations, incomplete bases, absent-header routes, and implicit PCH dependency.
