** TARGET-REPORT-UID:0000EW **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B003 Research Report: [UID:0000EW] ThreadMan class source-quality pass

Status: FINISHED  
Agent: B003  
Target: `source-3/project-documentation/by-class/ThreadMan.md`  
Required output: `source-3/project-documentation/tools/leaser/Agents/Agent-B003/research/0000EW-ThreadMan-class-source-quality.md`  
Report-only rule: no by-* documentation edited; no `by-memory/-coverage-report.md` edit.

## 1. Scope and instruction sources checked

Read and applied:

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B003/goal.md`
- `.codex/AGENTS.md`
- `source-3/project-documentation/by-structure.md`
- `source-3/project-documentation/inference_research.md`

Applicable supervisor rules:

- B-agent report first; implementation callback later.
- Rule 21 active-code gate is `completion/confidence > 85/85` with a nonblank emitter route, not the older 90/95 gate.
- Rule 24 source routing should use narrow source-level owners/emitter UIDs, with generated/destructor glue treated separately.
- Rule 26 requires all useful behavior, field/type, route, ownership, and source-shape research in the future docs, not a short summary.
- Rule 27 prohibits dropping first-draft C++ for code-emitting reconstructable targets unless there is a target-specific no-code proof.

## 2. Files and evidence checked

Primary and support docs:

- `by-class/ThreadMan.md`
- `by-file/Thread.md`
- `by-class/Thread.md`
- `by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md`
- `by-memory/0x00596bf0-0x00596d13.ThreadManConstructor.md`
- `by-memory/0x00596d20-0x00596e0b.ThreadManRawMessageWrappers.md`
- `by-memory/0x00596e10-0x005970df.ThreadManWorkerLoop.md`
- `by-memory/0x00597100-0x005971ad.ThreadManWorkerEntry.md`
- `by-memory/0x005971b0-0x005974da.ThreadManWatchListRawHelpers.md`
- `by-memory/0x005974e0-0x005974eb.ClearThreadManSingleton.md`
- `by-memory/0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md`
- `by-memory/0x0062e268-0x0062e334.ThreadReadOnlyData.md`
- `by-type/by-struct/ThreadManLayout.md`
- `by-type/by-struct/ThreadManWatchRecord.md`
- `by-type/by-enum/ThreadManMessageId.md`
- `by-global/g_pThreadMan.md`
- `by-memory/0x0069be08-0x0069be0b.g_pThreadMan.md`
- `by-meta/client_threading.md`
- `auto-generated/NexusTK/util/Thread.cpp`

Binary evidence checked locally from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`:

- PE image base and section mapping.
- Disassembly for `0x00596250-0x0059756e`.
- Rel32 call/jump scans into ThreadMan starts.
- Absolute VA/RVA pointer scans for ThreadMan starts.
- Vtable and literal references around `0x0062e2c4`.

## 3. Current target state

`by-class/ThreadMan.md` is currently:

- `COMPLETION:86`
- `CONFIDENCE:85`
- `RECONSTRUCTABLE:TRUE`
- `CANONICAL_OWNER:0000OR`
- `EMITTER_UIDS:0000OR`
- formal C++ blank

The page is source-bearing and should not remain blocked by the old 95/95 C++ gate. The correct target-level C++ for this class page is the class declaration and source-facing API inventory; method bodies belong in the child by-memory method/helper pages.

## 4. High-confidence class shape

`ThreadMan` is a process-level watchdog/message-pump singleton implemented with the generic `Thread` system in `NexusTK/util/Thread.cpp`. It owns:

- a debugger-presence byte at `this+0x04`
- a worker thread handle at `this+0x08`
- a worker thread id at `this+0x0c`
- a `List` of 0x14-byte `ThreadManWatchRecord` elements at `this+0x10`

The constructor dynamically probes `KERNEL32.DLL!IsDebuggerPresent`, creates the watch-list storage as `List(20, 16)`, starts a worker thread with `CreateThread`, and stores the worker thread id at `this+0x0c`.

The worker thread receives `WM_USER + 0x64` through `WM_USER + 0x68` messages by `PostThreadMessageW`, updates the watch list, and periodically scans for dead/unresponsive threads unless the debugger probe says a debugger is present.

## 5. Source placement conclusion

Recommended source placement: keep `ThreadMan` in `NexusTK/util/Thread.cpp` under [UID:0000OR], not a new `ThreadMan.cpp`.

Evidence:

- Existing `by-file/Thread.md` already owns the generic `Thread` and `ThreadMan` island.
- `auto-generated/NexusTK/util/Thread.cpp` is the current generated route for [UID:0000EW], [UID:0001WA], [UID:0001WB], [UID:0001SR], and `g_pThreadMan`.
- `ThreadMan` lives contiguously in the `0x00596250-0x0059756e` Thread/ThreadMan code island.
- ThreadMan read-only data is adjacent to Thread read-only data at `0x0062e268-0x0062e334`.
- The global singleton `g_pThreadMan` is already file-owned by [UID:0000OR].
- No direct evidence was found for a separate original `ThreadMan.cpp`.

Rejected alternative: separate `ThreadMan.cpp`.

- It is source-plausible by class name, but there is no current file-path, grouping, generated-output, or read-only-data evidence supporting that split.
- A future file split should require source/PDB/project evidence or a broader source-tree reconstruction decision.

## 6. Owner and emitter recommendation

Target class:

- Keep `by-class/ThreadMan.md` owner/emitter as [UID:0000OR] `Thread.md`, because the class itself belongs to `util/Thread.cpp`.

ThreadMan-specific child bodies:

- Recommend changing canonical owner/emitter for class member children from file-level [UID:0000OR] to class-level [UID:0000EW] where they are true `ThreadMan` methods:
  - [UID:0001K0] `ThreadManConstructor`
  - [UID:0001K1] `ThreadManRawMessageWrappers` for the ordinary destructor and retained private message-wrapper methods
  - [UID:0001K2] `ThreadManWorkerLoop`
  - [UID:0003V7] `ThreadManWatchListRawHelpers`
  - [UID:0001K5] `ThreadManScalarDeletingDestructor` as generated wrapper owned by the class

Keep file-level/source-file ownership for non-member helpers/data:

- [UID:0001K3] `ThreadManWorkerEntry` should remain a `static DWORD WINAPI` file helper in [UID:0000OR] unless later evidence proves it was a static class member.
- [UID:0001K4] `ClearThreadManSingleton` is compiler/EH cleanup glue, not a source method.
- [UID:0000SH]/[UID:000305] `g_pThreadMan` remains file/global storage owned through [UID:0000OR].

## 7. Constructor and destructor names/signatures

Recommended source-facing declarations:

```cpp
ThreadMan::ThreadMan();
ThreadMan::~ThreadMan();
```

Constructor evidence:

- `0x00596bf0-0x00596d13` calls the base `LObject` constructor, publishes `g_pThreadMan`, installs the `ThreadMan` vtable at `0x0062e2c4`, dynamically probes `IsDebuggerPresent`, creates the watch list, and starts the worker thread.
- It stores debugger result at `this+0x04`, thread handle at `this+0x08`, worker thread id at `this+0x0c`, and watch-list pointer at `this+0x10`.
- The worker entry pointer `0x00597100` is pushed in the constructor before the `CreateThread` import call.

Destructor evidence:

- `0x00596d20-0x00596d6a` is the ordinary destructor body inside the raw wrapper range. It restores the vtable, terminates/closes the worker thread handle, deletes the watch list, clears `g_pThreadMan`, and tail-calls the base destructor.
- `0x005974f0-0x0059756e` is the scalar deleting destructor wrapper referenced from the ThreadMan vtable at `0x0062e2c4`.

Policy:

- The class declaration should declare `virtual ~ThreadMan();`.
- The scalar deleting destructor by-memory item should stay no-code/generated-wrapper, with a comment/prose proof rather than source-level C++.
- The ordinary destructor body should be represented as `ThreadMan::~ThreadMan()` in the raw-wrapper child or a future split destructor child.

## 8. Raw message wrapper names/signatures

Recommended source-facing names and signatures:

```cpp
void ThreadMan::RegisterThread(Thread *thread, void *context);
void ThreadMan::UnregisterThread(Thread *thread);
void ThreadMan::ClearThreadProbe(Thread *thread);
void ThreadMan::MarkCurrentThreadBlocked();
void ThreadMan::ClearCurrentThreadBlocked();
```

Evidence:

- `0x00596d70` posts `0x0464` to `m_workerThreadId`, passing `thread` in `wParam` and `context` in `lParam`; function returns with `ret 8`.
- `0x00596d90` posts `0x0465`, passing `thread` in `wParam` and zero `lParam`; `ret 4`.
- `0x00596db0` posts `0x0466`, passing `thread` in `wParam`; `ret 4`.
- `0x00596dd0` calls `GetCurrentThreadId` and posts `0x0467` with the current thread id in `wParam`.
- `0x00596df0` calls `GetCurrentThreadId` and posts `0x0468` with the current thread id in `wParam`.
- No IDA function objects, direct xrefs, rel32 refs, or VA/RVA pointer hits were found for these raw helper starts.

Inference:

- These are source-shaped retained private/public convenience methods, not compiler glue.
- No-route evidence means they might be unused retained methods, called only through devirtualized/inlined source paths that did not survive as direct calls, or missed by the function database. It does not support deleting or treating them as generated.

Naming uncertainty:

- `ClearThreadProbe` is behavior-faithful to current docs and message `0x0466`.
- A more source-like alternate is `NotifyThreadResponsive(Thread *)`, because the helper clears a pending watchdog probe for a thread object. There is not enough evidence to replace the current family name. Keep `ClearThreadProbe` unless a source string or caller semantics proves the alternate.

## 9. Worker loop and entry names/signatures

Recommended source-facing names:

```cpp
void ThreadMan::RunMessagePump();
static DWORD WINAPI ThreadManWorkerEntry(LPVOID parameter);
```

Worker loop evidence:

- `0x00596e10-0x005970df` is called only from `0x00597140` inside the worker entry after loading `ecx` from the entry parameter.
- It uses `MsgWaitForMultipleObjects(0, 0, FALSE, 500, 0x4ff)`, drains messages with `PeekMessageW(..., PM_REMOVE)`, switches on message ids `0x0464` through `0x0468`, and scans timeouts.
- Under debugger (`this+0x04 != 0`), timeout fatal checks are skipped.
- `0x005970df-0x00597100` is switch table/alignment data and should stay outside the function body/range.

Worker entry evidence:

- `0x00597100-0x005971ad` is passed as the `CreateThread` entry address by the constructor.
- It converts the `LPVOID` parameter to `ThreadMan *`, calls `RunMessagePump`, and has exception handling that formats an error, displays `MessageBoxW(L"Error")`, and routes to the app-exit helper.
- Direct rel32 refs to the worker entry were not found because the constructor uses the address as immediate data for `CreateThread`; the VA pointer hit at `0x00596cb1` proves the route.

Ownership inference:

- `RunMessagePump` is a `ThreadMan` member.
- `ThreadManWorkerEntry` should be documented as a file-static helper in `Thread.cpp`, with a ranked alternate of private static member. The binary cannot distinguish these two source spellings; the existing file route and generic Thread helper style favor file-static.

## 10. Worker message ids

Recommended enum names:

```cpp
enum ThreadManMessageId
{
    THREADMAN_REGISTER_THREAD             = WM_USER + 0x64, // 0x0464
    THREADMAN_UNREGISTER_THREAD           = WM_USER + 0x65, // 0x0465
    THREADMAN_CLEAR_THREAD_PROBE          = WM_USER + 0x66, // 0x0466
    THREADMAN_MARK_THREAD_ID_BLOCKED      = WM_USER + 0x67, // 0x0467
    THREADMAN_CLEAR_THREAD_ID_BLOCKED     = WM_USER + 0x68  // 0x0468
};
```

Evidence:

- Raw wrappers post exactly `0x0464` through `0x0468`.
- The worker loop switch handles the same contiguous range.
- `0x0467` and `0x0468` wrappers pass `GetCurrentThreadId()` as `wParam`, and the worker loop/helper searches watch records by record `+0x08`.
- `0x0464` registration copies `*(Thread + 0x60)` into record `+0x08`; the generic `Thread` constructor uses `this+0x60` as the worker thread-id out pointer for `_beginthreadex`/thread creation.

Recommendation:

- Keep the first three current names.
- Replace `IDENTITY` wording with `THREAD_ID` or `CURRENT_THREAD` wording. `threadIdentity` was a useful placeholder, but binary evidence now ties it to the watched `Thread` object's worker thread id.

## 11. ThreadMan layout fields

Recommended source-facing field names:

```cpp
bool   m_isDebuggerPresent;   // +0x04
HANDLE m_workerThreadHandle;  // +0x08
DWORD  m_workerThreadId;      // +0x0c
List  *m_watchList;           // +0x10
```

Evidence:

- `this+0x04` receives the optional `IsDebuggerPresent` result and gates timeout/fatal scanning.
- `this+0x08` receives the `CreateThread` handle and is later used by destructor cleanup.
- `this+0x0c` is passed as the thread-id out pointer to `CreateThread`, and all raw wrappers post to this id with `PostThreadMessageW`.
- `this+0x10` receives the `List(20,16)` allocation and is the record list used by worker-loop/watch helpers.

Rejected alternatives:

- `m_threadId` alone is too ambiguous because both the manager's worker id and watched thread ids are present.
- `m_debuggerProbe` is less precise than `m_isDebuggerPresent`; the field stores the result of the probe, not the function pointer or probe state.

## 12. ThreadManWatchRecord fields

Recommended source-facing struct:

```cpp
struct ThreadManWatchRecord
{
    Thread *thread;          // +0x00
    void   *context;         // +0x04
    DWORD   watchedThreadId; // +0x08, copied from Thread +0x60
    bool    probePending;    // +0x0c
    DWORD   deadlineTick;    // +0x10
};
```

Evidence:

- Registration stores `MSG.wParam` at record `+0x00`, `MSG.lParam` at `+0x04`, `*(Thread + 0x60)` at `+0x08`, clears `+0x0c`, and clears `+0x10`.
- Helper `0x005971b0` searches by record `+0x00`.
- Helper `0x005971f0` searches by record `+0x08`.
- Timeout helpers test `+0x0c` and compare `timeGetTime()` against `+0x10`.
- The sentinel deadline `0xffffffff` is used for the blocked state set by message `0x0467`; `0x0466` only clears if the deadline is not this sentinel.

Recommendation:

- Update `ThreadManWatchRecord.md` from `threadIdentity` to `watchedThreadId` or `threadId`. I recommend `watchedThreadId` in the struct doc because it avoids confusion with `ThreadMan::m_workerThreadId`.
- Keep `context`/`registerContext` as a low-confidence field name; behavior preserves it but current docs do not prove a source consumer.

## 13. Watch-list helper names/signatures

Recommended source-facing private helpers:

```cpp
int  ThreadMan::FindWatchRecordByThread(Thread *thread) const;
int  ThreadMan::FindWatchRecordByThreadId(DWORD threadId) const;
void ThreadMan::ScanWatchList();
void ThreadMan::CheckWatchRecordTimeout(ThreadManWatchRecord *record);
void ThreadMan::AddWatchRecord(Thread *thread, void *context);
void ThreadMan::RemoveWatchRecord(Thread *thread);
void ThreadMan::ClearWatchRecordProbe(Thread *thread);
void ThreadMan::MarkThreadIdBlocked(DWORD threadId);
void ThreadMan::ClearThreadIdBlocked(DWORD threadId);
```

Evidence by address:

- `0x005971b0-0x005971ec`: scans `m_watchList` by record `+0x00`, returns index or `-1`.
- `0x005971f0-0x0059722d`: scans by record `+0x08`, returns index or `-1`.
- `0x00597230-0x005972e9`: scans all records and performs timeout/fatal checks.
- `0x005972f0-0x0059735f`: checks one record's timeout/fatal state.
- `0x00597360-0x00597397`: appends a record from `(thread, context, thread->workerThreadId)`.
- `0x005973a0-0x005973de`: removes a record by thread object.
- `0x005973e0-0x0059742f`: clears `probePending` for a thread object when `deadlineTick != 0xffffffff`.
- `0x00597430-0x00597481`: marks a record by watched thread id as blocked with `probePending = true` and `deadlineTick = 0xffffffff`.
- `0x00597490-0x005974da`: clears `probePending` for a watched thread id.

Route evidence:

- No IDA function objects, direct xrefs, rel32 refs, or VA/RVA pointer hits were found for these raw helper starts.
- The worker loop duplicates or inlines the same operations directly, so these helpers may be retained but not referenced in the final linked binary.

Policy:

- Treat them as source-shaped retained private helpers, not generated glue.
- Keep them in the `ThreadMan` class/support docs with no-route caveats.
- Do not let no-xref status block source-facing names; the names above are behavior-backed and safe enough for documentation.

## 14. Singleton clear policy

`0x005974e0-0x005974eb.ClearThreadManSingleton` should remain non-reconstructable/no-code compiler/EH cleanup glue.

Evidence:

- It only writes `0` to `g_pThreadMan` and returns.
- Existing docs identify the caller as an exception cleanup route.
- It is not a source method and should not appear in the class declaration.

Class/source treatment:

- The ordinary destructor and constructor-failure cleanup should document that `g_pThreadMan` is cleared.
- The class declaration does not need a `ClearSingleton` method.

## 15. Scalar deleting destructor policy

`0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor` should be treated as compiler-generated C++ destructor wrapper glue owned by the class but not emitted as source code.

Evidence:

- The function is referenced by the ThreadMan vtable slot at `0x0062e2c4`.
- It performs destructor-wrapper/delete-flag behavior around the ordinary destructor path.
- It is not called by source as an ordinary named function.

Recommendation:

- In the target class declaration, keep only `virtual ~ThreadMan();`.
- In the scalar deleting destructor by-memory page, keep formal C++ blank or use only a no-code marker/prose. Do not emit a fake source method named `ThreadMan::scalar_deleting_destructor`.
- Align with the pending B009 source-quality recommendation for [UID:0001K5] if accepted by the supervisor.

## 16. Debugger probe details

Recommended source-facing behavior:

- Constructor loads `KERNEL32.DLL`.
- It resolves `IsDebuggerPresent` dynamically with `GetProcAddress`.
- If resolution succeeds, it calls the function and stores the boolean result in `m_isDebuggerPresent`.
- It frees the library handle.
- Worker timeout scans are skipped when `m_isDebuggerPresent` is true.

Evidence:

- Read-only data contains UTF-16 `KERNEL32.DLL` at `0x0062e2d0` and ASCII `IsDebuggerPresent` at `0x0062e2ec`, both referenced by the constructor.
- The worker loop checks the byte at `this+0x04` before the timeout fatal path.

Rejected interpretation:

- This is not a persistent debugger function-pointer field. No object field stores the function pointer; only the resulting boolean is retained.

## 17. Stale generated disabled rows

Current target docs already note stale generated rows. Keep and sharpen them:

- `0x0045004b` is not ThreadMan. It lies inside another helper region and should not be used as ThreadMan evidence.
- `0x004e0052` is not ThreadMan. It lies inside `NewHumanImageLib::NewHumanImageLib` and should not be used as ThreadMan evidence.
- `0x00597570` is after the ThreadMan scalar deleting destructor and belongs to the TimerHandler island, not ThreadMan.

Recommendation:

- `by-class/ThreadMan.md` should say these generated disabled rows are rejected evidence, not unresolved source candidates.

## 18. Class C++ readiness

Recommendation: add first-draft class-level C++ to `by-class/ThreadMan.md`.

This target is reconstructable and already clears the active code gate. The correct C++ unit for a class page is the declaration/API inventory, not all method bodies. Child method pages should carry bodies after their own callbacks.

Suggested first-draft C++:

```cpp
class Thread;
class List;
struct ThreadManWatchRecord;

class ThreadMan : public LObject
{
public:
    ThreadMan();
    virtual ~ThreadMan();

    void RegisterThread(Thread *thread, void *context);
    void UnregisterThread(Thread *thread);
    void ClearThreadProbe(Thread *thread);
    void MarkCurrentThreadBlocked();
    void ClearCurrentThreadBlocked();

private:
    void RunMessagePump();

    int  FindWatchRecordByThread(Thread *thread) const;
    int  FindWatchRecordByThreadId(DWORD threadId) const;
    void ScanWatchList();
    void CheckWatchRecordTimeout(ThreadManWatchRecord *record);
    void AddWatchRecord(Thread *thread, void *context);
    void RemoveWatchRecord(Thread *thread);
    void ClearWatchRecordProbe(Thread *thread);
    void MarkThreadIdBlocked(DWORD threadId);
    void ClearThreadIdBlocked(DWORD threadId);

    bool   m_isDebuggerPresent;
    HANDLE m_workerThreadHandle;
    DWORD  m_workerThreadId;
    List  *m_watchList;
};
```

Notes:

- Do not include `ThreadManWorkerEntry` in the class declaration unless the supervisor chooses the static-member alternative. Best current route is a file-static helper in `Thread.cpp`.
- Do not include scalar deleting destructor pseudo-code.
- Do not emit the method bodies in this class page.
- The declaration assumes Windows headers for `DWORD` and `HANDLE`; local style may prefer existing typedefs if the generated project has them.

## 19. Metadata recommendation

Target [UID:0000EW] recommendation:

- `COMPLETION:86 -> 88`
- `CONFIDENCE:85 -> 89`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `CANONICAL_OWNER:0000OR`
- Keep `EMITTER_UIDS:0000OR`

Reason:

- Source placement, layout, message ids, destructor policy, and first-draft declaration are now resolved enough for class-level emission.
- Remaining uncertainty is limited to exact original private helper names, no-direct-xref retained helper liveness, and whether worker entry was file-static or static-member source spelling.

I do not recommend raising above 90 yet because there is still no direct construction path for the singleton and no direct call route for the retained raw wrappers/watch helpers.

## 20. Support-doc update recommendations

### `by-file/Thread.md`

Add/update:

- `ThreadMan` remains in `NexusTK/util/Thread.cpp`.
- Rejected split: no current evidence for `ThreadMan.cpp`.
- `ThreadMan` class page now owns the source-facing API/class declaration, while file-level helper `ThreadManWorkerEntry` and global `g_pThreadMan` remain file-owned.
- The generated disabled rows at `0x0045004b` and `0x004e0052` are rejected as stale false-positive ThreadMan entries.

### `by-class/ThreadMan.md`

Apply the target changes:

- Raise metadata to `88/89`.
- Replace old C++ blocker language with active-gate readiness.
- Add the class declaration above.
- Add final names/signatures for constructor/destructor, wrappers, worker loop, watch helpers, message ids, fields, and record fields.
- Add source placement conclusion and rejected `ThreadMan.cpp` alternative.
- Add scalar deleting destructor no-code policy.
- Add no-route evidence for retained raw wrappers/watch helpers.

### `by-type/by-struct/ThreadManLayout.md`

Update field names:

- `+0x04 m_isDebuggerPresent`
- `+0x08 m_workerThreadHandle`
- `+0x0c m_workerThreadId`
- `+0x10 m_watchList`

Add C++ readiness note:

- This struct layout can now support the `ThreadMan` class declaration; it should not emit a duplicate full class if [UID:0000EW] emits it.

### `by-type/by-struct/ThreadManWatchRecord.md`

Update field names:

- `threadObject -> thread`
- `registerContext -> context` or keep `registerContext` if the project prefers provenance wording
- `threadIdentity -> watchedThreadId`
- `watchdogPending -> probePending`
- `deadlineTick` stays valid

Add evidence:

- `watchedThreadId` comes from `Thread + 0x60`, which the generic `Thread` constructor uses as its worker thread-id output field.
- `deadlineTick == 0xffffffff` is the blocked sentinel set by message `0x0467`.

### `by-type/by-enum/ThreadManMessageId.md`

Update final names:

- Keep `THREADMAN_REGISTER_THREAD`, `THREADMAN_UNREGISTER_THREAD`, `THREADMAN_CLEAR_THREAD_PROBE`.
- Rename identity wording to `THREADMAN_MARK_THREAD_ID_BLOCKED` and `THREADMAN_CLEAR_THREAD_ID_BLOCKED`, or document them as the preferred source-facing names if avoiding a hard rename.
- Add `WM_USER + 0x64` through `WM_USER + 0x68` notation.

### `by-memory/0x00596bf0-0x00596d13.ThreadManConstructor.md`

Recommended future changes:

- Canonical owner/emitter should become [UID:0000EW] if the implementation callback includes child routing.
- Add source-facing signature `ThreadMan::ThreadMan()`.
- Replace old no-C++/95-gate text with child-method body readiness or state that body emission belongs to this child, not the class page.
- Add final field names and debugger probe import/source behavior.

### `by-memory/0x00596d20-0x00596e0b.ThreadManRawMessageWrappers.md`

Recommended future changes:

- Canonical owner/emitter should become [UID:0000EW] if child routing is accepted.
- Split ordinary destructor from raw wrappers if the supervisor wants cleaner per-function pages. If not splitting, document that the range contains one ordinary destructor plus five retained message-wrapper methods.
- Add source-facing signatures listed in section 8.
- Keep no-direct-xref evidence, but classify as retained source-shaped methods rather than generated glue.

### `by-memory/0x00596e10-0x005970df.ThreadManWorkerLoop.md`

Recommended future changes:

- Canonical owner/emitter should become [UID:0000EW] if child routing is accepted.
- Use source-facing signature `void ThreadMan::RunMessagePump()`.
- Add final message names and `m_isDebuggerPresent` gating.
- Preserve exact endpoint at `0x005970df`; switch table/alignment after that stays outside.

### `by-memory/0x00597100-0x005971ad.ThreadManWorkerEntry.md`

Recommended future changes:

- Keep file-owned [UID:0000OR] unless a broader callback selects the private static-member alternative.
- Use `static DWORD WINAPI ThreadManWorkerEntry(LPVOID parameter)` as the source-facing helper name/signature.
- Document CreateThread pointer route from `0x00596cb1`.

### `by-memory/0x005971b0-0x005974da.ThreadManWatchListRawHelpers.md`

Recommended future changes:

- Canonical owner/emitter should become [UID:0000EW] if child routing is accepted.
- Add the nine source-facing helper names from section 13.
- Preserve no-route evidence and classify them as retained source-shaped private helper methods.
- Note that the worker loop contains equivalent inline logic, which explains no direct helper calls without proving dead compiler artifacts.

### `by-memory/0x005974e0-0x005974eb.ClearThreadManSingleton.md`

Recommended future changes:

- Keep `RECONSTRUCTABLE:FALSE`.
- Keep no C++.
- Clarify this is EH/compiler cleanup for `g_pThreadMan`, not a class method.

### `by-memory/0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md`

Recommended future changes:

- Align with pending B009 policy: class-owned generated scalar deleting destructor wrapper.
- No formal source C++ beyond the class declaration's `virtual ~ThreadMan();`.
- Update score/metadata per accepted B009 report if supervisor accepts it.

### `by-global/g_pThreadMan.md` and `by-memory/0x0069be08-0x0069be0b.g_pThreadMan.md`

Recommended future changes:

- Keep file/global ownership through [UID:0000OR].
- Add that constructor publishes it, ordinary destructor clears it, and [UID:0001K4] is compiler cleanup.
- Do not create a `ThreadMan::ClearSingleton` source method.

### `by-memory/0x0062e268-0x0062e334.ThreadReadOnlyData.md`

Recommended future changes:

- Cross-reference `ThreadMan` vtable `0x0062e2c4`, constructor vtable install, ordinary destructor vtable restore, and scalar deleting destructor vtable slot.
- Keep `KERNEL32.DLL`, `IsDebuggerPresent`, and `Possibly dead thread 0x%p` as ThreadMan source literals.

### `by-meta/client_threading.md`

Recommended future changes:

- Close or narrow ThreadMan-specific open questions:
  - The worker entry route is proven by the CreateThread pointer.
  - Raw wrappers/watch helpers remain no-direct-xref retained source-shaped helpers, not generated glue.
  - `ThreadManWatchRecord +0x08` is watched `Thread` worker thread id, not an abstract identity token.
  - `ThreadMan` remains in `Thread.cpp` absent stronger source evidence.

## 21. Exact implementation callback checklist

If the supervisor accepts this report, the callback should instruct:

1. Edit `by-class/ThreadMan.md`.
2. Change metadata:
   - `COMPLETION:86` to `COMPLETION:88`
   - `CONFIDENCE:85` to `CONFIDENCE:89`
   - keep `RECONSTRUCTABLE:TRUE`
   - keep `CANONICAL_OWNER:0000OR`
   - keep `EMITTER_UIDS:0000OR`
3. Add the class declaration from section 18 to the formal C++ block.
4. Replace old 95/95 or "no C++ yet" language with the active-gate class-page policy:
   - class page emits declaration/API inventory
   - child pages emit method bodies
   - scalar deleting destructor and singleton clear remain no-code generated/cleanup artifacts
5. Add final field names, record field names, wrapper names, worker loop/entry names, message ids, and source placement conclusions from this report.
6. Update `by-file/Thread.md`, `ThreadManLayout.md`, `ThreadManWatchRecord.md`, `ThreadManMessageId.md`, `g_pThreadMan.md`, `ThreadReadOnlyData.md`, and `client_threading.md` with the support-doc details listed above.
7. If child-routing support edits are included, change ThreadMan member method by-memory owners/emitters to [UID:0000EW] for [UID:0001K0], [UID:0001K1], [UID:0001K2], [UID:0003V7], and [UID:0001K5]. Keep [UID:0001K3] file-owned unless the callback explicitly chooses static-member routing.
8. Do not edit `by-memory/-coverage-report.md`; use the pending row text below if the supervisor owns coverage updates.
9. Run validators listed in section 25.

## 22. Exact coverage text

Recommended `by-class/-coverage-report.md` replacement row:

```markdown
- [UID:0000EW][ThreadMan](by-class/ThreadMan.md) : reconstructable : 88% : very strong : Process-level thread manager/watchdog singleton in `NexusTK/util/Thread.cpp`; publishes `g_pThreadMan`, probes `IsDebuggerPresent`, owns worker thread handle/id and watch-list records, posts `WM_USER+0x64..0x68` worker messages, and now has source-facing class declaration/field/helper names. Remaining uncertainty is exact private helper source spelling, no-direct-xref retained helper liveness, and singleton construction route.
```

Pending `by-memory/-coverage-report.md` row text if the supervisor includes support coverage cleanup. Do not apply directly during this B-agent report phase:

```markdown
- [UID:0001JX][ThreadAndThreadMan](by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md) : reconstructable : 86% : strong : Aggregates the generic `Thread` and `ThreadMan` island in `NexusTK/util/Thread.cpp`; exact children cover Thread construction/start/teardown, ThreadMan constructor/destructor/wrapper/worker/watch-list methods, scalar deleting destructor glue, and transition to TimerHandler after `0x0059756e`. No aggregate C++ should emit while class/method children own source bodies.
- [UID:0001K0][ThreadManConstructor](by-memory/0x00596bf0-0x00596d13.ThreadManConstructor.md) : reconstructable : 88% : strong : `ThreadMan::ThreadMan()` publishes `g_pThreadMan`, installs the ThreadMan vtable, dynamically probes `IsDebuggerPresent`, allocates `List(20,16)` watch storage, starts the worker thread with entry `0x00597100`, stores handle/id fields, and has constructor-failure cleanup paths.
- [UID:0001K1][ThreadManRawMessageWrappers](by-memory/0x00596d20-0x00596e0b.ThreadManRawMessageWrappers.md) : reconstructable : 88% : strong : Contains the ordinary `ThreadMan::~ThreadMan()` body plus retained source-shaped message wrappers for register/unregister/clear-probe/mark-current-thread-blocked/clear-current-thread-blocked; wrappers post `WM_USER+0x64..0x68` to `m_workerThreadId` and have no direct xrefs or pointer hits.
- [UID:0001K2][ThreadManWorkerLoop](by-memory/0x00596e10-0x005970df.ThreadManWorkerLoop.md) : reconstructable : 88% : strong : `ThreadMan::RunMessagePump()` drains worker messages, updates watch records, scans watchdog deadlines unless a debugger is present, and routes dead-thread failures through the fatal app-exit path; only direct caller is ThreadMan worker entry.
- [UID:0001K3][ThreadManWorkerEntry](by-memory/0x00597100-0x005971ad.ThreadManWorkerEntry.md) : reconstructable : 88% : very strong : File-static `ThreadManWorkerEntry(LPVOID)` passed to `CreateThread` by the constructor; calls the member worker loop and handles top-level exceptions with message formatting, `MessageBoxW("Error")`, and app-exit routing.
- [UID:0003V7][ThreadManWatchListRawHelpers](by-memory/0x005971b0-0x005974da.ThreadManWatchListRawHelpers.md) : reconstructable : 86% : strong : Retained no-direct-xref ThreadMan private helper island for finding watch records by thread object/id, scanning/checking watchdog deadlines, adding/removing records, clearing probe state, and marking/clearing blocked thread-id records; source-shaped but not proven live by direct call/pointer routes.
- [UID:0001K4][ClearThreadManSingleton](by-memory/0x005974e0-0x005974eb.ClearThreadManSingleton.md) : not reconstructable : 88% : very strong : Compiler/EH cleanup thunk that clears `g_pThreadMan`; not a source method and should stay no-code.
- [UID:0001K5][ThreadManScalarDeletingDestructor](by-memory/0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md) : reconstructable : 86% : very strong : Compiler-generated scalar deleting destructor wrapper reached through ThreadMan vtable `0x0062e2c4`; class-owned wrapper around ordinary destructor/delete policy, no standalone source C++ beyond `virtual ~ThreadMan()`.
```

## 23. IDA rename/type/comment recommendations

High confidence:

- `0x00596bf0`: `ThreadMan__ThreadMan`
- `0x00596d20`: `ThreadMan__dtor`
- `0x00596d70`: `ThreadMan__RegisterThread`
- `0x00596d90`: `ThreadMan__UnregisterThread`
- `0x00596db0`: `ThreadMan__ClearThreadProbe`
- `0x00596dd0`: `ThreadMan__MarkCurrentThreadBlocked`
- `0x00596df0`: `ThreadMan__ClearCurrentThreadBlocked`
- `0x00596e10`: `ThreadMan__RunMessagePump`
- `0x00597100`: `ThreadManWorkerEntry`
- `0x005974e0`: `ThreadMan_ClearSingleton_EhCleanup`
- `0x005974f0`: `ThreadMan__scalar_deleting_destructor`
- `0x0069be08`: `g_pThreadMan`
- `0x0062e2c4`: `ThreadMan_vftable`

Medium/high confidence watch-helper names:

- `0x005971b0`: `ThreadMan__FindWatchRecordByThread`
- `0x005971f0`: `ThreadMan__FindWatchRecordByThreadId`
- `0x00597230`: `ThreadMan__ScanWatchList`
- `0x005972f0`: `ThreadMan__CheckWatchRecordTimeout`
- `0x00597360`: `ThreadMan__AddWatchRecord`
- `0x005973a0`: `ThreadMan__RemoveWatchRecord`
- `0x005973e0`: `ThreadMan__ClearWatchRecordProbe`
- `0x00597430`: `ThreadMan__MarkThreadIdBlocked`
- `0x00597490`: `ThreadMan__ClearThreadIdBlocked`

Suggested types:

```cpp
struct ThreadManWatchRecord {
    Thread *thread;
    void *context;
    DWORD watchedThreadId;
    bool probePending;
    DWORD deadlineTick;
};

ThreadMan *__cdecl get_global_name_only_for_g_pThreadMan; // do not create this fake symbol; keep data symbol only
```

Do not create source-visible symbols for:

- scalar deleting destructor
- EH singleton clear thunk
- stale generated disabled rows at `0x0045004b` and `0x004e0052`

## 24. Open questions and closure status

Open: What is the exact original class source file?

- Best answer: `NexusTK/util/Thread.cpp`.
- Evidence: existing file owner, generated route, contiguous Thread/ThreadMan island, shared threading data/literals, no contrary file evidence.
- Status: closed for implementation unless new source evidence appears.

Open: Is `ThreadManWorkerEntry` file-static or static class member?

- Best answer: file-static `ThreadManWorkerEntry(LPVOID)`.
- Evidence: binary only proves a `CreateThread` entry pointer; existing source route and generic Thread helper pattern favor file-static.
- Status: rank as file-static with static-member alternate documented.

Open: Are raw wrappers/watch-list helpers live?

- Best answer: no direct liveness proved, but they are retained source-shaped methods/helpers.
- Evidence checked: no IDA functions, no direct xrefs, no rel32 refs, no VA/RVA pointer hits for starts; bodies are coherent thiscall-style wrappers/helpers, not compiler glue.
- Status: closed as retained no-direct-route source-shaped helpers; not a blocker for names.

Open: What does `ThreadManWatchRecord +0x08` mean?

- Best answer: watched `Thread` worker thread id.
- Evidence: registration copies `*(Thread + 0x60)`; generic `Thread` constructor passes `this+0x60` as thread-id output for thread creation.
- Status: closed.

Open: Should class C++ remain blank?

- Best answer: no. The class page should emit the declaration/API inventory because it clears active gate and has no target-specific no-code proof.
- Status: closed.

Open: Should scalar deleting destructor get source C++?

- Best answer: no. It is compiler-generated wrapper glue; source declaration is only `virtual ~ThreadMan();`.
- Status: closed.

## 25. Validation commands for implementation callback

Run from `E:\NTK\GhidraBridge\source-3\project-documentation` after accepted implementation edits:

> Executable block R001 was removed from this report and preserved verbatim in [0000EW-ThreadMan-class-source-quality-removed.md](0000EW-ThreadMan-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If child by-memory owner/routing edits are included:

> Executable block R002 was removed from this report and preserved verbatim in [0000EW-ThreadMan-class-source-quality-removed.md](0000EW-ThreadMan-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## 26. Final recommendation summary

`ThreadMan` is ready for class-level source C++ as a declaration in `by-class/ThreadMan.md`. Keep the class under `NexusTK/util/Thread.cpp` through [UID:0000OR]. The class-specific child method bodies should route to [UID:0000EW] when those support pages are updated, while the worker entry remains a file-static `Thread.cpp` helper and scalar deleting/singleton-clear functions remain no-code generated/cleanup artifacts.

Recommended target score: `88/89`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0000EW-ThreadMan-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:26","uid":"0000EW"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000EW-ThreadMan-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0000EW-ThreadMan-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000EW"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
