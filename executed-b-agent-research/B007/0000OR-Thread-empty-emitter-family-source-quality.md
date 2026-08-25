** TARGET-REPORT-UID:0000OR **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000OR Thread Empty-Emitter Family Source-Quality Report

**ASSIGNMENT:** B007-implement-0000OR-Thread-empty-emitter-family-20260701  
**MODE:** Accepted implementation callback applied to scoped target/support by-* docs.

## Scope

Primary target:

- [UID:0000OR] `by-file/Thread.md`
- Generated output: `auto-generated/NexusTK/util/Thread.cpp`

Scoped empty emitters visible in the current generated file:

- [UID:0000WL] `by-memory/0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual.md`
- [UID:0001K0] `by-memory/0x00596bf0-0x00596d13.ThreadManConstructor.md`
- [UID:0001K1] `by-memory/0x00596d20-0x00596e0b.ThreadManRawMessageWrappers.md`
- [UID:0001K2] `by-memory/0x00596e10-0x005970df.ThreadManWorkerLoop.md`
- [UID:0001K5] `by-memory/0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md`
- [UID:0001WA] `by-type/by-struct/ThreadManLayout.md`
- [UID:0000SH] `by-global/g_pThreadMan.md`
- [UID:000305] `by-memory/0x0069be08-0x0069be0c.g_pThreadMan.md`
- [UID:0001JX] `by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md`
- [UID:0001JY] `by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md`
- [UID:0001K3] `by-memory/0x00597100-0x005971ad.ThreadManWorkerEntry.md`
- [UID:00026P] `by-memory/0x0062e268-0x0062e334.ThreadReadOnlyData.md`

Out-of-scope support lead noted but not part of this empty-marker list:

- [UID:0003V7] `by-memory/0x005971b0-0x005974da.ThreadManWatchListRawHelpers.md`

## Implementation Callback Guardrail

This callback applied only the accepted scoped by-* target/support edits and this report ledger/checklist update. Generated files, coverage reports, validator/tool state, queue files, archives, supervisor ledgers, by-project-structure docs, and IDA database files were not edited by hand. [UID:0001JX] was not reclassified as non-emitting in this pass.

## Live MCP Evidence

IDA MCP was available and responsive. The active database is `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` for module `NexusTK.exe`; auto-analysis, Hex-Rays, and the string cache were reported ready.

Evidence requests used:

- MCP `initialize` / `tools/list`: server `ida-pro-mcp` version `1.0.0`.
- MCP `idb_list` request 3: active `supervisor_resume_20260629`, input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, not analyzing.
- MCP `server_health` request 4: status `ok`, imagebase `0x400000`, strings cache ready with 2067 strings.
- MCP `lookup_funcs` request 5:
  - `0x0041b6b0` is `nullsub_17`, size `0x3`.
  - `0x00596bf0` is `sub_596BF0`, size `0x123`.
  - raw starts `0x00596d20`, `0x00596d70`, `0x00596d90`, `0x00596db0`, `0x00596dd0`, `0x00596df0` have no function records.
  - `0x00596e10` is `sub_596E10`, size `0x2cf`.
  - `0x00597100` is `sub_597100`, size `0xad`.
  - `0x005974e0` is `sub_5974E0`, size `0xb`.
  - `0x005974f0` is `sub_5974F0`, size `0x7e`.
  - `0x005969b0`, `0x0062e268`, and `0x0069be08` are not function starts.
- MCP `analyze_function` request 6, constructor `0x00596bf0`: size 291 bytes; writes the singleton, installs the ThreadMan vtable, probes `KERNEL32.DLL` / `IsDebuggerPresent`, allocates a `List(20, 16)`, starts a worker thread with `ThreadManWorkerEntry`, and throws `Win32Error` on `CreateThread` failure.
- MCP `analyze_function` request 7, worker loop `0x00596e10`: size 719 bytes; uses `MsgWaitForMultipleObjects` with timeout `500` and wake mask `0x4ff`, drains `PeekMessageW` through `unk_69BE8C`, handles message ids `0x0464` through `0x0468`, mutates the watch list, uses `timeGetTime`, and reports `Possibly dead thread 0x%p`.
- MCP `analyze_function` request 8, worker entry `0x00597100`: size 173 bytes; called by the constructor through data xref `0x596cb0`; wraps the worker loop in SEH/C++ exception handling, formats exception text through a virtual method at vtable offset `0x0c`, calls `MessageBoxW`, requests application exit through `sub_464E40`, deletes the exception object, and returns with `ret 4`.
- MCP `analyze_function` request 9, scalar deleting destructor `0x005974f0`: size 126 bytes; compiler wrapper restores the ThreadMan vtable, terminates/closes the worker handle, deletes the watch list, clears `g_pThreadMan`, runs the base destructor, and conditionally frees storage.
- MCP `xrefs_to` request 23:
  - `0x0041b6b0` has seven data xrefs from vtables, including Thread-related and STL-folded references.
  - `0x0069be08` is referenced by constructor, raw destructor, cleanup thunk, and scalar deleting destructor.
  - `0x0062e2c4` is referenced by constructor, raw destructor, and scalar deleting destructor.
  - `0x00597100` has a data xref from constructor thread creation.
  - `0x00596e10` has a code xref from worker entry.
  - `0x005974f0` has a vtable data xref.
- MCP `get_bytes` request 24:
  - `0x00596d20-0x00596e0f` contains the raw ordinary destructor and five raw message wrappers.
  - `0x0062e268-0x0062e333` contains Thread/ThreadMan RTTI, vtables, `KERNEL32.DLL`, `IsDebuggerPresent`, and `Possibly dead thread 0x%p`.
  - `0x0069be08` currently contains `00 00 00 00`.
- MCP `insn_query` request 25:
  - `0x00596d20` raw destructor terminates and closes the worker handle, deletes the watch list, clears `g_pThreadMan`, and tail-jumps to the base destructor.
  - `0x00596d70` posts `0x0464`.
  - `0x00596d90` posts `0x0465`.
  - `0x00596db0` posts `0x0466`.
  - `0x00596dd0` posts `0x0467` with `GetCurrentThreadId`.
  - `0x00596df0` posts `0x0468` with `GetCurrentThreadId`.
- MCP `get_string` request 26:
  - `0x0062e2ec`: `IsDebuggerPresent`
  - `0x0062e300`: `Possibly dead thread 0x%p`
  - `0x00612598`: `Error`
  - `0x0062e2d0` is typed narrowly by IDA but bytes from request 24 decode the UTF-16 `KERNEL32.DLL` literal.
- MCP `xref_query` request 27: no xrefs to raw starts `0x00596d20`, `0x00596d70`, `0x00596d90`, `0x00596db0`, `0x00596dd0`, `0x00596df0`, or `0x005969b0`.

## Existing Report Leads Reviewed

Relevant executed B-agent reports were reviewed as support leads, not used as a substitute for this by-file family report:

- `executed-b-agent-research/B003/0000EW-ThreadMan-class-source-quality.md`
- `executed-b-agent-research/B013/0000EV-Thread-class-source-quality.md`
- `executed-b-agent-research/B003/0001JY-ThreadMessageDispatchHelpers-source-quality.md`
- `executed-b-agent-research/B003/00026P-ThreadReadOnlyData-source-quality.md`
- `executed-b-agent-research/B008/0001K5-ThreadManScalarDeletingDestructor-source-quality.md`

These reports correctly established the Thread/ThreadMan ownership route, but the current by-file family still has generated empty markers requiring target-level dispositions.

## Current Generated-Output Audit

Current generated file:

- `auto-generated/NexusTK/util/Thread.cpp`
- Header proof: `validator-command-id: 000000003465`
- Header timestamp: `validator-refreshed-at: 2026-07-01T05:44:04-04:00`
- Source by-file UID: `0000OR`

Current generated tracker context:

- Total emitters: 17
- Filled emitters: 5
- Empty emitters: 12
- Fill rate: 29.4%

Current populated generated outputs:

- [UID:0000EV] `Thread` class declaration.
- [UID:0000EW] `ThreadMan` class declaration.
- [UID:0001SR] `ThreadManMessageId` enum.
- [UID:0001WB] `ThreadManWatchRecord` struct.
- [UID:0001JZ] `Thread::AddWaitHandle` body.

Current empty markers:

- [UID:0000WL] no-op Thread virtual body.
- [UID:0001K0] ThreadMan constructor.
- [UID:0001K1] ordinary destructor and raw message wrappers.
- [UID:0001K2] ThreadMan worker loop.
- [UID:0001K5] scalar deleting destructor wrapper.
- [UID:0001WA] ThreadMan layout evidence page.
- [UID:0000SH] `g_pThreadMan` source-facing global.
- [UID:000305] exact `g_pThreadMan` storage page.
- [UID:0001JX] broad Thread/ThreadMan aggregate range.
- [UID:0001JY] broad dispatch-helper aggregate range.
- [UID:0001K3] ThreadMan worker entry.
- [UID:00026P] Thread/ThreadMan read-only compiler data.

The accepted route should remain file root [UID:0000OR], class [UID:0000EV], class [UID:0000EW], generated path `NexusTK/util/Thread.cpp`. Broad aggregate pages should not emit duplicate source bodies when exact class, method, global, enum, and struct pages carry the source output.

## Target Findings And Recommendations

### [UID:0000OR] `by-file/Thread.md`

Recommended metadata:

- Keep `COMPLETION:89`
- Keep `CONFIDENCE:88`
- Keep `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"`
- Keep `CANONICAL_OWNER:FILE`

Recommended implementation-callback edit:

- Add a durable 2026-07-01 generated-output audit section with the header proof, tracker context, five populated outputs, twelve empty-marker dispositions, route rationale, and the explanation that exact child pages carry source output while aggregate/container and generated-binary pages should not duplicate it.

No formal C++ block change is required in the file root beyond preserving its existing include/order notes and child ownership map.

### [UID:0000WL] `ThreadDefaultNoOpVirtual`

Recommended metadata:

- `COMPLETION:88`
- `CONFIDENCE:90`
- Keep `CANONICAL_OWNER:0000EV`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:0000EV`

Recommended formal `RECONSTRUCTION_CPP CODE` insertion:

```cpp
void Thread::OnWaitObject(int)
{
}
```

Evidence and caveats to preserve:

- MCP request 5 identifies `0x0041b6b0` as a 3-byte `nullsub_17`.
- MCP request 23 shows only data xrefs, including Thread vtable use and STL-folded vtable use.
- The empty `ret 4` body is source-shaped and should not stay blank solely because the final original virtual name is inferred.
- `Thread::OnWaitObject(int)` remains a best source-facing name, not a symbol-proven original spelling.

### [UID:0001K0] `ThreadManConstructor`

Recommended metadata:

- `COMPLETION:89`
- `CONFIDENCE:89`
- Keep `CANONICAL_OWNER:0000EW`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:0000EW`

Recommended formal `RECONSTRUCTION_CPP CODE` insertion:

```cpp
ThreadMan::ThreadMan()
    : m_isDebuggerPresent(false),
      m_workerThreadHandle(NULL),
      m_workerThreadId(0),
      m_watchList(NULL)
{
    g_pThreadMan = this;

    HMODULE kernel32 = LoadLibraryW(L"KERNEL32.DLL");
    if (kernel32 != NULL)
    {
        typedef BOOL (WINAPI *IsDebuggerPresentProc)();
        IsDebuggerPresentProc isDebuggerPresent =
            reinterpret_cast<IsDebuggerPresentProc>(GetProcAddress(kernel32, "IsDebuggerPresent"));
        if (isDebuggerPresent != NULL)
            m_isDebuggerPresent = (isDebuggerPresent() != FALSE);
        FreeLibrary(kernel32);
    }

    m_watchList = new List(sizeof(ThreadManWatchRecord), 16);
    m_workerThreadHandle = CreateThread(NULL, 0, ThreadManWorkerEntry, this, 0, &m_workerThreadId);
    if (m_workerThreadHandle == NULL)
        throw Win32Error();
}
```

Evidence and caveats to preserve:

- MCP request 6 proves constructor size 291 bytes.
- It publishes `g_pThreadMan`, stores the ThreadMan vtable, probes `KERNEL32.DLL` / `IsDebuggerPresent`, allocates a 20-byte element / 16-growth watch list, starts `ThreadManWorkerEntry`, and throws `Win32Error` on failure.
- The exact project loader helper name remains local-source inferred; the formal draft uses `LoadLibraryW` because the target literal and `GetProcAddress`/`FreeLibrary` sequence are proved.
- The thrown `Win32Error` source spelling follows current project error naming and constructor evidence.

### [UID:0001K1] `ThreadManRawMessageWrappers`

Recommended metadata:

- `COMPLETION:89`
- `CONFIDENCE:89`
- Keep `CANONICAL_OWNER:0000EW`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:0000EW`

Recommended formal `RECONSTRUCTION_CPP CODE` insertion:

```cpp
ThreadMan::~ThreadMan()
{
    if (m_workerThreadHandle != NULL)
    {
        TerminateThread(m_workerThreadHandle, 0);
        CloseHandle(m_workerThreadHandle);
        m_workerThreadHandle = NULL;
    }

    if (m_watchList != NULL)
    {
        delete m_watchList;
        m_watchList = NULL;
    }

    g_pThreadMan = NULL;
}

void ThreadMan::RegisterThread(Thread *thread, void *context)
{
    PostThreadMessageW(m_workerThreadId, THREADMAN_REGISTER_THREAD,
                       reinterpret_cast<WPARAM>(thread),
                       reinterpret_cast<LPARAM>(context));
}

void ThreadMan::UnregisterThread(Thread *thread)
{
    PostThreadMessageW(m_workerThreadId, THREADMAN_UNREGISTER_THREAD,
                       reinterpret_cast<WPARAM>(thread), 0);
}

void ThreadMan::ClearThreadProbe(Thread *thread)
{
    PostThreadMessageW(m_workerThreadId, THREADMAN_CLEAR_THREAD_PROBE,
                       reinterpret_cast<WPARAM>(thread), 0);
}

void ThreadMan::MarkCurrentThreadBlocked()
{
    PostThreadMessageW(m_workerThreadId, THREADMAN_MARK_THREAD_ID_BLOCKED,
                       GetCurrentThreadId(), 0);
}

void ThreadMan::ClearCurrentThreadBlocked()
{
    PostThreadMessageW(m_workerThreadId, THREADMAN_CLEAR_THREAD_ID_BLOCKED,
                       GetCurrentThreadId(), 0);
}
```

Evidence and caveats to preserve:

- MCP requests 24 and 25 prove the raw ordinary destructor at `0x00596d20` and wrappers at `0x00596d70`, `0x00596d90`, `0x00596db0`, `0x00596dd0`, and `0x00596df0`.
- MCP request 27 confirms no direct xrefs to the raw starts. That explains raw-helper caution but is not enough to leave source-shaped wrappers blank.
- Message ids are the already-emitted [UID:0001SR] enum values `0x0464` through `0x0468`.
- `RegisterThread`, `UnregisterThread`, `ClearThreadProbe`, `MarkCurrentThreadBlocked`, and `ClearCurrentThreadBlocked` are best source-facing names, not symbol-proven spellings.

### [UID:0001K2] `ThreadManWorkerLoop`

Recommended metadata:

- `COMPLETION:89`
- `CONFIDENCE:88`
- Keep `CANONICAL_OWNER:0000EW`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:0000EW`

Recommended formal `RECONSTRUCTION_CPP CODE` insertion:

```cpp
void ThreadMan::RunMessagePump()
{
    MSG msg;

    for (;;)
    {
        DWORD result = MsgWaitForMultipleObjects(0, NULL, FALSE, 500, QS_ALLINPUT);
        if (result == WAIT_OBJECT_0)
        {
            while (PeekMessageW(&msg, NULL, 0, 0, PM_REMOVE))
            {
                switch (msg.message)
                {
                case THREADMAN_REGISTER_THREAD:
                    AddWatchRecord(reinterpret_cast<Thread *>(msg.wParam),
                                   reinterpret_cast<void *>(msg.lParam));
                    break;

                case THREADMAN_UNREGISTER_THREAD:
                    RemoveWatchRecord(reinterpret_cast<Thread *>(msg.wParam));
                    break;

                case THREADMAN_CLEAR_THREAD_PROBE:
                    ClearWatchRecordProbe(reinterpret_cast<Thread *>(msg.wParam));
                    break;

                case THREADMAN_MARK_THREAD_ID_BLOCKED:
                    MarkThreadIdBlocked(static_cast<DWORD>(msg.wParam));
                    break;

                case THREADMAN_CLEAR_THREAD_ID_BLOCKED:
                    ClearThreadIdBlocked(static_cast<DWORD>(msg.wParam));
                    break;
                }
            }
        }
        else if (result == WAIT_TIMEOUT && !m_isDebuggerPresent)
        {
            ScanWatchList();
        }
    }
}
```

Recommended support note:

- The existing [UID:0000EW] class declaration already carries private helper names for the message-pump operations. The worker loop body should use those names as first-draft source structure, while preserving the caveat that the optimized binary inlines or duplicates list mutation behavior and retains raw helper bodies with no direct call xrefs.

Evidence and caveats to preserve:

- MCP request 7 proves exact size 719 bytes, `MsgWaitForMultipleObjects`, timeout `500`, wake mask `0x4ff`, `PeekMessageW`, message ids `0x0464` through `0x0468`, `timeGetTime`, list mutation, and the `Possibly dead thread 0x%p` watchdog.
- Helper names are inference-backed project source names. Unresolved helper spelling is not a sufficient no-code reason for this exact source-authored virtual/body.
- The formal body is intentionally first-draft source structure. It does not claim final optimizer equivalence for each list mutation instruction.

### [UID:0001K5] `ThreadManScalarDeletingDestructor`

Recommended metadata:

- Keep `COMPLETION:86`
- Keep `CONFIDENCE:91`
- Keep `CANONICAL_OWNER:0000EW`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:0000EW`

Recommended formal `RECONSTRUCTION_CPP CODE` insertion:

```cpp
// Compiler-emitted scalar deleting destructor for ThreadMan; generated from
// virtual ~ThreadMan() and the ordinary destructor source, so no standalone
// handwritten source body is emitted for this exact range.
```

Evidence and caveats to preserve:

- MCP request 9 proves a scalar deleting destructor wrapper with flag-controlled storage free.
- This is a genuine compiler-generated wrapper. The source-owned destructor should be emitted from [UID:0001K1], not duplicated here.

### [UID:0001WA] `ThreadManLayout`

Recommended metadata:

- Keep `COMPLETION:86`
- Keep `CONFIDENCE:90`
- Keep `CANONICAL_OWNER:0000EW`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:0000EW`

Recommended formal `RECONSTRUCTION_CPP CODE` insertion:

```cpp
// ThreadMan object layout is emitted by [UID:0000EW] ThreadMan class declaration;
// this page supplies offset evidence only and should not emit a duplicate type.
```

Evidence and caveats to preserve:

- The current [UID:0000EW] class declaration already emits the actual fields.
- This page is still useful as layout proof for offsets and should be retained, but duplicate struct/class emission would create conflicting source.

### [UID:0000SH] `g_pThreadMan`

Recommended metadata:

- `COMPLETION:88`
- `CONFIDENCE:89`
- Keep `CANONICAL_OWNER:0000OR`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:0000OR`

Recommended formal `RECONSTRUCTION_CPP CODE` insertion:

```cpp
static ThreadMan *g_pThreadMan = NULL;
```

Evidence and caveats to preserve:

- MCP requests 6, 23, 24, and 25 prove constructor publication, raw destructor clear, cleanup thunk clear, scalar deleting destructor clear, and zero-initialized storage at `0x0069be08`.
- The project already uses `g_pThreadMan` as the source-facing singleton name.
- `static` remains an inferred source linkage qualifier because the binary proves file-local use shape but not the exact original spelling.

### [UID:000305] `g_pThreadMan` Exact Storage

Recommended metadata:

- `COMPLETION:87`
- `CONFIDENCE:89`
- Keep `CANONICAL_OWNER:0000SH`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:0000SH`

Recommended formal `RECONSTRUCTION_CPP CODE` insertion:

```cpp
// Exact storage for g_pThreadMan is emitted by [UID:0000SH] as
// static ThreadMan *g_pThreadMan = NULL; no duplicate source declaration is
// emitted for this address-only storage page.
```

Evidence and caveats to preserve:

- MCP request 24 proves the storage bytes are currently zero.
- The source declaration belongs on [UID:0000SH]; this exact-address page should not duplicate it.

### [UID:0001JX] `ThreadAndThreadMan`

Revision recheck:

- The earlier standalone recommendation to reclassify [UID:0001JX] as non-emitting is not safe by itself. [UID:0001JX] is a broader Thread/ThreadMan aggregate that still covers real Thread source bodies that do not yet have exact child pages, including `Thread::Thread`, `Thread::~Thread`, `Thread::StopThread`, `Thread::ForceTerminate`, the start/suspend/resume helper family, `Thread::DispatchRequestAndReturnEvent`, `ThreadEntry`, and the Thread scalar deleting destructor wrapper.
- ThreadMan-side bodies in the aggregate are already represented by exact child pages or explicit child targets in this report: [UID:0001K0], [UID:0001K1], [UID:0001K2], [UID:0001K3], [UID:0001K4], [UID:0001K5], and [UID:0003V7].
- Thread dispatch subrange [UID:0001JY] is now handled below with an implementation-ready exact child-page plan. That fixes only the `0x00596620-0x005969b0` portion and does not cover all remaining Thread bodies inside [UID:0001JX].

Revised recommendation:

- Reject the previous standalone [UID:0001JX] historicalization as stale/incomplete for this report revision.
- Do not clear [UID:0001JX]'s empty marker in an implementation callback unless the callback is explicitly expanded to create/update exact child pages for the remaining Thread-side source bodies listed above.
- Keep the current [UID:0001JX] metadata during the scoped [UID:0001JY] repair:
  - `COMPLETION:87`
  - `CONFIDENCE:88`
  - `CANONICAL_OWNER:0000OR`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:0000OR`

Full child plan required before any future non-emitting [UID:0001JX] reclassification:

| Proposed child path | Range | Source role | UID handling expectation | Metadata route | C++ disposition |
| --- | --- | --- | --- | --- | --- |
| `by-memory/0x00596250-0x005963f2.ThreadConstructor.md` | `0x00596250-0x005963f2` | `Thread::Thread()` constructor | New UID assigned by validator after file creation; use TMP refs from parent until assigned. | `CANONICAL_OWNER:0000OR`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OR`, initial score about `88/88`. | First-draft constructor C++ required before clearing [UID:0001JX]. |
| `by-memory/0x00596400-0x00596534.ThreadDestructor.md` | `0x00596400-0x00596534` | `Thread::~Thread()` | New UID assigned by validator. | `CANONICAL_OWNER:0000OR`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OR`, initial score about `88/88`. | First-draft destructor C++ required. |
| `by-memory/0x00596540-0x005965bf.ThreadStopThread.md` | `0x00596540-0x005965bf` | `Thread::StopThread()` | New UID assigned by validator. | `CANONICAL_OWNER:0000OR`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OR`. | First-draft method C++ required. |
| `by-memory/0x005965c0-0x005965cc.ThreadForceTerminate.md` | `0x005965c0-0x005965cc` | `Thread::ForceTerminate()` | New UID assigned by validator. | `CANONICAL_OWNER:0000OR`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OR`. | First-draft wrapper C++ required. |
| `by-memory/0x005965e0-0x0059661f.ThreadStartSuspendResumeHelpers.md` | `0x005965e0-0x0059661f` | `StartThread` / `SuspendThread` / `ResumeThread` helper area and padding | New UID assigned by validator, after confirming exact sub-boundaries. | `CANONICAL_OWNER:0000OR`, `RECONSTRUCTABLE:TRUE` for source bodies; padding subspans ignored or parent-documented. | Split into exact bodies first if multiple starts are confirmed; do not emit aggregate helper C++. |
| `by-memory/0x00596a00-0x00596ae8.ThreadDispatchRequestAndReturnEvent.md` | `0x00596a00-0x00596ae8` | `Thread::DispatchRequestAndReturnEvent(...)` | New UID assigned by validator. | `CANONICAL_OWNER:0000OR`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OR`. | First-draft method C++ required. |
| `by-memory/0x00596af0-0x00596bac.ThreadEntry.md` | `0x00596af0-0x00596bac` | static `_beginthreadex` entry helper | New UID assigned by validator. | `CANONICAL_OWNER:0000OR`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OR`. | First-draft static helper C++ required, with exception/start/proc/end caveats. |
| `by-memory/0x00596bb0-0x00596be8.ThreadScalarDeletingDestructor.md` | `0x00596bb0-0x00596be8` | compiler scalar deleting destructor wrapper for `Thread` | New UID assigned by validator. | `CANONICAL_OWNER:0000EV` or `0000OR` after class-owner check, `RECONSTRUCTABLE:TRUE`, emitter through [UID:0000EV] or [UID:0000OR]. | Formal comment-only compiler-wrapper no-code disposition, not handwritten C++. |

Validators for a future [UID:0001JX] split callback must include the created child files and then [UID:0001JX] itself with `--wait-generated`. This report revision does not apply that broad split; it only prevents the earlier [UID:0001JX] aggregate-clearing claim from losing source work.

Evidence and caveats to preserve:

- [UID:0001JX] is a broad audit/container page over Thread and ThreadMan code, not itself a single source-level function, object, global, or type.
- It cannot be safely marked `RECONSTRUCTABLE:FALSE` until exact child pages cover all source-authored bodies inside its range or a broader split callback explicitly scopes the uncovered Thread bodies.
- The current [UID:0001JY] revision supplies the implementation-ready child plan for the dispatch-helper subrange only.

### [UID:0001JY] `CashShopRequestWaitDispatch`

Recommended metadata:

- Keep `COMPLETION:88`
- Keep `CONFIDENCE:89`
- Keep `CANONICAL_OWNER:0000OR`
- Change `RECONSTRUCTABLE:FALSE` only after the exact child-page plan below is applied.
- Clear `EMITTER_UIDS` only after the exact child-page plan below is applied.

Recommended formal C++:

- Keep [UID:0001JY]'s own formal block blank after exact source children exist. The aggregate should not emit duplicate partial C++.

Exact subrange/body inventory and child-page plan:

| Range | Current body/subrange | Implementation-ready disposition |
| --- | --- | --- |
| `0x00596620-0x0059675e` | `Thread::WaitForQueueDrain()` queue-drain barrier | Create `by-memory/0x00596620-0x0059675e.ThreadWaitForQueueDrain.md`; validator assigns new UID; `CANONICAL_OWNER:0000OR`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OR`, suggested score `88/89`; insert first-draft C++ below. |
| `0x0059675e-0x00596760` | two `0xcc` alignment bytes | No source child; retain as padding evidence in [UID:0001JY] and, if required by coverage tooling, the by-memory ignored ledger under supervisor/validator rules. |
| `0x00596760-0x005967c7` | `int Thread::WaitForResult(HANDLE resultEvent)` | Create `by-memory/0x00596760-0x005967c7.ThreadWaitForResult.md`; validator assigns new UID; `CANONICAL_OWNER:0000OR`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OR`, suggested score `88/89`; insert first-draft C++ below. |
| `0x005967c7-0x005967d0` | nine `0xcc` alignment bytes | No source child; retain as padding evidence in [UID:0001JY]. |
| `0x005967d0-0x005967e5` | `HANDLE Thread::AddWaitHandle(HANDLE handle)` | Existing exact child [UID:0001JZ] already emits formal C++; keep as already-present child coverage. |
| `0x005967e5-0x005967f0` | eleven `0xcc` alignment bytes | No source child; retain as padding evidence in [UID:0001JY]. |
| `0x005967f0-0x00596805` | `void Thread::RemoveLastWaitHandle()` | Create `by-memory/0x005967f0-0x00596805.ThreadRemoveLastWaitHandle.md`; validator assigns new UID; `CANONICAL_OWNER:0000OR`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OR`, suggested score `89/90`; insert first-draft C++ below. |
| `0x00596805-0x00596810` | eleven `0xcc` alignment bytes | No source child; retain as padding evidence in [UID:0001JY]. |
| `0x00596810-0x00596915` | `virtual int Thread::ThreadProc()` worker dispatch loop | Create `by-memory/0x00596810-0x00596915.ThreadProc.md`; validator assigns new UID; `CANONICAL_OWNER:0000OR`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OR`, suggested score `88/88`; insert first-draft C++ below and preserve vtable-offset caveats. |
| `0x00596915-0x00596920` | eleven `0xcc` alignment bytes | No source child; retain as padding evidence in [UID:0001JY]. |
| `0x00596920-0x00596931` | `virtual void Thread::OnMessage(int messageId, int arg1, int arg2)` | Create `by-memory/0x00596920-0x00596931.ThreadOnMessage.md`; validator assigns new UID; `CANONICAL_OWNER:0000OR`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OR`, suggested score `90/91`; insert first-draft C++ below. |
| `0x00596931-0x00596940` | fifteen `0xcc` alignment bytes | No source child; retain as padding evidence in [UID:0001JY]. |
| `0x00596940-0x0059695e` | `virtual int Thread::OnMessageEx(int messageId, int syncArg1, int syncArg2, int arg1, int arg2)` | Create `by-memory/0x00596940-0x0059695e.ThreadOnMessageEx.md`; validator assigns new UID; `CANONICAL_OWNER:0000OR`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OR`, suggested score `90/91`; insert first-draft C++ below. |
| `0x0059695e-0x00596960` | two `0xcc` alignment bytes | No source child; retain as padding evidence in [UID:0001JY]. |
| `0x00596960-0x005969b0` | `BOOL Thread::DispatchRequest(int messageId, int arg1, int arg2)` | Create `by-memory/0x00596960-0x005969b0.ThreadDispatchRequest.md`; validator assigns new UID; `CANONICAL_OWNER:0000OR`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OR`, suggested score `89/90`; insert first-draft C++ below. |

Adjacent source body named by [UID:0001JY] but outside its end-exclusive range:

| Range | Current body/subrange | Implementation-ready disposition |
| --- | --- | --- |
| `0x005969b0-0x00596a00` | retained raw `BOOL Thread::DispatchPriorityRequest(int messageId, int arg1, int arg2)` sibling | Create `by-memory/0x005969b0-0x00596a00.ThreadDispatchPriorityRequestRaw.md` in the same callback if [UID:0001JY] or [UID:0000OR] text continues to name it as a split blocker; validator assigns new UID; `CANONICAL_OWNER:0000OR`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OR`, suggested score `87/88`; insert first-draft C++ below and preserve no-direct-xref/raw-helper caveat. |

UID handling and references:

- Do not guess UIDs for the new child files. Create the target Markdown files during an implementation callback and run the validator in file mode so each receives a stable UID.
- If [UID:0001JY], [UID:0001JX], [UID:0000OR], or [UID:0000EV] must reference a child before its UID exists, use the `[TMP:"by-memory/<new-child>.md"]` workflow and let the validator replace the TMP reference.
- Only after the child files exist, carry formal C++, and validate cleanly should [UID:0001JY] become a non-emitting audit/container with `RECONSTRUCTABLE:FALSE` and blank `EMITTER_UIDS`.

Recommended formal C++ for new [UID:0001JY] children:

`by-memory/0x00596620-0x0059675e.ThreadWaitForQueueDrain.md`

```cpp
void Thread::WaitForQueueDrain()
{
    HANDLE event = CreateEventW(NULL, TRUE, FALSE, NULL);

    ThreadResultEntry entry;
    entry.event = event;
    entry.result = 0;

    m_resultGate->Lock();
    m_resultList->Add(&entry);
    m_resultGate->Unlock();

    ThreadMessage message;
    message.messageId = 2;
    message.arg1 = 0;
    message.arg2 = 0;
    message.resultEvent = event;
    message.syncArg1 = 0;
    message.syncArg2 = 0;

    m_messageQueue->Push(&message);
    ReleaseSemaphore(m_waitHandles[0], 1, NULL);

    WaitForSingleObject(event, INFINITE);

    m_resultGate->Lock();
    for (int i = 0; i < m_resultList->GetCount(); ++i)
    {
        ThreadResultEntry *current =
            static_cast<ThreadResultEntry *>(m_resultList->GetAt(i));
        if (current->event == event)
        {
            m_resultList->RemoveAt(i);
            break;
        }
    }
    m_resultGate->Unlock();

    CloseHandle(event);
}
```

`by-memory/0x00596760-0x005967c7.ThreadWaitForResult.md`

```cpp
int Thread::WaitForResult(HANDLE resultEvent)
{
    int result = reinterpret_cast<int>(resultEvent);

    WaitForSingleObject(resultEvent, INFINITE);

    m_resultGate->Lock();
    for (int i = 0; i < m_resultList->GetCount(); ++i)
    {
        ThreadResultEntry *entry =
            static_cast<ThreadResultEntry *>(m_resultList->GetAt(i));
        if (entry->event == resultEvent)
        {
            result = entry->result;
            m_resultList->RemoveAt(i);
            break;
        }
    }
    m_resultGate->Unlock();

    CloseHandle(resultEvent);
    return result;
}
```

`by-memory/0x005967f0-0x00596805.ThreadRemoveLastWaitHandle.md`

```cpp
void Thread::RemoveLastWaitHandle()
{
    --m_waitHandleCount;
    m_waitHandles[static_cast<signed char>(m_waitHandleCount)] = NULL;
}
```

`by-memory/0x00596810-0x00596915.ThreadProc.md`

```cpp
int Thread::ThreadProc()
{
    Sleep(1);

    while (!m_stopRequested)
    {
        DWORD waitResult = WaitForMultipleObjects(
            static_cast<signed char>(m_waitHandleCount),
            m_waitHandles,
            FALSE,
            m_waitTimeout);

        if (waitResult == WAIT_OBJECT_0)
        {
            ThreadMessage message;
            while (m_priorityQueue->Pop(&message) || m_messageQueue->Pop(&message))
            {
                if (message.resultEvent != NULL)
                {
                    int result = OnMessageEx(message.messageId,
                                             message.syncArg1,
                                             message.syncArg2,
                                             message.arg1,
                                             message.arg2);

                    ThreadResultEntry entry;
                    entry.event = message.resultEvent;
                    entry.result = result;

                    m_resultGate->Lock();
                    m_resultList->Add(&entry);
                    m_resultGate->Unlock();

                    SetEvent(message.resultEvent);
                }
                else
                {
                    OnMessage(message.messageId, message.arg1, message.arg2);
                }
            }
        }
        else if (waitResult > WAIT_OBJECT_0 &&
                 waitResult < WAIT_OBJECT_0 + static_cast<DWORD>(m_waitHandleCount))
        {
            OnWaitObject(static_cast<int>(waitResult - WAIT_OBJECT_0));
        }
    }

    return 0;
}
```

`by-memory/0x00596920-0x00596931.ThreadOnMessage.md`

```cpp
void Thread::OnMessage(int messageId, int, int)
{
    if (messageId == 1)
        m_stopRequested = TRUE;
}
```

`by-memory/0x00596940-0x0059695e.ThreadOnMessageEx.md`

```cpp
int Thread::OnMessageEx(int messageId, int, int, int, int)
{
    if (messageId == 1)
        m_stopRequested = TRUE;

    return 0;
}
```

`by-memory/0x00596960-0x005969b0.ThreadDispatchRequest.md`

```cpp
BOOL Thread::DispatchRequest(int messageId, int arg1, int arg2)
{
    ThreadMessage message;
    message.messageId = messageId;
    message.arg1 = arg1;
    message.arg2 = arg2;
    message.resultEvent = NULL;
    message.syncArg1 = 0;
    message.syncArg2 = 0;

    BOOL queued = m_messageQueue->Push(&message);
    ReleaseSemaphore(m_waitHandles[0], 1, NULL);
    return queued;
}
```

`by-memory/0x005969b0-0x00596a00.ThreadDispatchPriorityRequestRaw.md`

```cpp
BOOL Thread::DispatchPriorityRequest(int messageId, int arg1, int arg2)
{
    ThreadMessage message;
    message.messageId = messageId;
    message.arg1 = arg1;
    message.arg2 = arg2;
    message.resultEvent = NULL;
    message.syncArg1 = 0;
    message.syncArg2 = 0;

    BOOL queued = m_priorityQueue->Push(&message);
    ReleaseSemaphore(m_waitHandles[0], 1, NULL);
    return queued;
}
```

Evidence and caveats to preserve:

- [UID:0001JY] already records exact modeled starts and sizes: `0x00596620` size `0x13e`, `0x00596760` size `0x67`, `0x005967d0` size `0x15`, `0x005967f0` size `0x76` under stale IDA alias pollution, `0x00596810` size `0x105`, `0x00596920` size `0x11`, `0x00596940` size `0x1e`, and `0x00596960` size `0x50`.
- [UID:0001JY] records direct caller diversity for `0x00596620`, `0x00596760`, and `0x00596960`, vtable/data refs for `0x00596810` and `0x00596940`, and Socket cleanup tail-jump liveness for `0x005967f0`.
- [UID:0001JZ] already emits `Thread::AddWaitHandle`; keep it as already-present exact child coverage.
- The first-draft C++ uses inferred `RequestSyncGate`, `List`, and `RingBuffer` method spellings. These names are source-quality best guesses; the report must preserve that API-spelling caveat while no longer using it as a no-code excuse.
- Empty-marker disposition for [UID:0001JY] is incorporated only when exact source child pages are created or updated first. Reclassifying the aggregate before child repair would lose source-owned bodies and is rejected.

### [UID:0001K3] `ThreadManWorkerEntry`

Recommended metadata:

- `COMPLETION:89`
- `CONFIDENCE:88`
- Keep `CANONICAL_OWNER:0000OR`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:0000OR`

Recommended formal `RECONSTRUCTION_CPP CODE` insertion:

```cpp
static DWORD WINAPI ThreadManWorkerEntry(LPVOID parameter)
{
    try
    {
        static_cast<ThreadMan *>(parameter)->RunMessagePump();
    }
    catch (Error *error)
    {
        wchar_t text[0x800];
        error->CopyMessage(text, 0x800);
        MessageBoxW(NULL, text, L"Error", MB_OK);
        if (g_pApplication != NULL)
            g_pApplication->RequestExit();
        delete error;
    }

    return 0;
}
```

Evidence and caveats to preserve:

- MCP request 8 proves exact size 173 bytes, direct CreateThread data xref, call to `ThreadMan::RunMessagePump`, exception formatting through virtual offset `0x0c`, `MessageBoxW`, application-exit request through `sub_464E40`, exception cleanup, and `ret 4`.
- `Error`, `CopyMessage`, `g_pApplication`, and `RequestExit` are best project source-facing names inferred from existing error/application documentation and observed calls.
- Exception API spelling remains a source-quality caveat, but it is not enough to leave this exact source-authored thread entry blank.

### [UID:00026P] `ThreadReadOnlyData`

Recommended metadata:

- Keep `COMPLETION:87`
- Keep `CONFIDENCE:91`
- Keep `CANONICAL_OWNER:0000OR`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:0000OR`

Recommended formal `RECONSTRUCTION_CPP CODE` insertion:

```cpp
// Thread/ThreadMan RTTI, vtables, and local literals are regenerated from class
// declarations and method use sites; no standalone .rdata source declaration is
// emitted for this exact range.
```

Evidence and caveats to preserve:

- MCP request 24 proves the read-only bytes contain Thread/ThreadMan RTTI, vtables, and string literals.
- `KERNEL32.DLL`, `IsDebuggerPresent`, and `Possibly dead thread 0x%p` should appear at their constructor/worker-loop use sites, not as raw declarations.
- Raw vtable/RTTI emission is a genuine generated-binary artifact and qualifies for comment-only no-code disposition.

## Rejected Alternatives

- Reject leaving all twelve markers blank as "needs investigation." MCP evidence was available and resolved the source route for each marker.
- Reject report-level reliance on previous class reports alone. The current generated by-file still has twelve empty emitters and requires per-marker dispositions.
- Reject duplicate broad aggregate C++ for [UID:0001JX] and [UID:0001JY]. Those pages span multiple source bodies and padding; exact child pages must carry method bodies.
- Reject standalone non-emitting reclassification for [UID:0001JX] in this scoped callback. The recheck found remaining unsplit Thread source bodies inside that aggregate.
- Reject non-emitting reclassification for [UID:0001JY] unless the exact child-page plan in this revision is implemented first.
- Reject raw `.rdata` declarations for [UID:00026P]. Vtables, RTTI, and use-site literals regenerate from class/method source.
- Reject omitting the source declaration for [UID:0000SH]. Lifecycle/storage evidence is strong enough for a first-draft `g_pThreadMan` declaration.

## Proposed Validator Scope For Implementation Callback

Run validators from `E:\NTK\GhidraBridge\source-3\project-documentation` after applying the accepted edits:

> Executable block R001 was removed from this report and preserved verbatim in [0000OR-Thread-empty-emitter-family-source-quality-removed.md](0000OR-Thread-empty-emitter-family-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

After validation, inspect `auto-generated/NexusTK/util/Thread.cpp` and confirm:

- Header `validator-refreshed-at` is at or after the validator command metadata.
- [UID:0000WL], [UID:0001K0], [UID:0001K1], [UID:0001K2], [UID:0001K3], [UID:0000SH], and the newly created [UID:0001JY] exact children appear as populated source or source declarations.
- [UID:0001K5], [UID:0001WA], [UID:000305], and [UID:00026P] no longer appear as actionable empty markers because they have explicit formal no-code comments or are otherwise accepted no-duplicate pages.
- [UID:0001JY] no longer appears as an empty marker only after the exact child-page/source-body repair plan is applied and [UID:0001JY] is reclassified as non-emitting.
- [UID:0001JX] may still appear as an empty marker unless a broader [UID:0001JX] exact-child split is explicitly accepted and implemented; do not clear it as a standalone aggregate in the scoped [UID:0001JY] repair.

## Implementation Callback Validation Proof

Scoped validators were rerun with `--apply --queue-timeout 240 --wait-generated` after the accepted callback edits:

| File | Command ID | Timestamp | Exit | ok |
|---|---:|---|---:|---:|
| `by-file/Thread.md` | `000000003619` | `2026-07-01T06:33:18-04:00` | 0 | 1 |
| `by-memory/0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual.md` | `000000003620` | `2026-07-01T06:33:28-04:00` | 0 | 1 |
| `by-memory/0x00596bf0-0x00596d13.ThreadManConstructor.md` | `000000003621` | `2026-07-01T06:33:39-04:00` | 0 | 1 |
| `by-memory/0x00596d20-0x00596e0b.ThreadManRawMessageWrappers.md` | `000000003622` | `2026-07-01T06:33:49-04:00` | 0 | 1 |
| `by-memory/0x00596e10-0x005970df.ThreadManWorkerLoop.md` | `000000003623` | `2026-07-01T06:33:59-04:00` | 0 | 1 |
| `by-memory/0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md` | `000000003624` | `2026-07-01T06:34:10-04:00` | 0 | 1 |
| `by-type/by-struct/ThreadManLayout.md` | `000000003625` | `2026-07-01T06:34:20-04:00` | 0 | 1 |
| `by-global/g_pThreadMan.md` | `000000003626` | `2026-07-01T06:34:30-04:00` | 0 | 1 |
| `by-memory/0x0069be08-0x0069be0c.g_pThreadMan.md` | `000000003627` | `2026-07-01T06:34:40-04:00` | 0 | 1 |
| `by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md` | `000000003628` | `2026-07-01T06:34:50-04:00` | 0 | 1 |
| `by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md` | `000000003629` | `2026-07-01T06:35:00-04:00` | 0 | 1 |
| `by-memory/0x00596620-0x0059675e.ThreadWaitForQueueDrain.md` | `000000003630` | `2026-07-01T06:35:10-04:00` | 0 | 1 |
| `by-memory/0x00596760-0x005967c7.ThreadWaitForResult.md` | `000000003631` | `2026-07-01T06:35:20-04:00` | 0 | 1 |
| `by-memory/0x005967f0-0x00596805.ThreadRemoveLastWaitHandle.md` | `000000003632` | `2026-07-01T06:35:30-04:00` | 0 | 1 |
| `by-memory/0x00596810-0x00596915.ThreadProc.md` | `000000003633` | `2026-07-01T06:35:41-04:00` | 0 | 1 |
| `by-memory/0x00596920-0x00596931.ThreadOnMessage.md` | `000000003634` | `2026-07-01T06:35:51-04:00` | 0 | 1 |
| `by-memory/0x00596940-0x0059695e.ThreadOnMessageEx.md` | `000000003635` | `2026-07-01T06:36:01-04:00` | 0 | 1 |
| `by-memory/0x00596960-0x005969b0.ThreadDispatchRequest.md` | `000000003636` | `2026-07-01T06:36:12-04:00` | 0 | 1 |
| `by-memory/0x005969b0-0x00596a00.ThreadDispatchPriorityRequestRaw.md` | `000000003637` | `2026-07-01T06:36:22-04:00` | 0 | 1 |
| `by-memory/0x00597100-0x005971ad.ThreadManWorkerEntry.md` | `000000003638` | `2026-07-01T06:36:32-04:00` | 0 | 1 |
| `by-memory/0x0062e268-0x0062e334.ThreadReadOnlyData.md` | `000000003639` | `2026-07-01T06:36:43-04:00` | 0 | 1 |

Generated `auto-generated/NexusTK/util/Thread.cpp` refreshed from foreground generation with `validator-command-id: 000000003639` and `validator-refreshed-at: 2026-07-01T06:36:43-04:00`, matching the final scoped validator command. The generated file contains populated [UID:0004CI], [UID:0004CJ], [UID:0004CK], [UID:0004CL], [UID:0004CM], [UID:0004CN], [UID:0004CO], and [UID:0004CP] output. [UID:0001JY] no longer appears as an empty marker. [UID:0001JX] still appears as an empty marker by explicit callback scope.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Action | Verification State | Callback Handling | Proof |
|---|---:|---|---|---|---|
| C-0000OR-AUDIT | 0000OR | incorporate | applied | Added generated-output audit to `by-file/Thread.md`; kept file metadata `89/88`. | Validator `000000003619`; generated header refreshed by `000000003639`. |
| C-0000WL-BODY | 0000WL | incorporate | applied | Inserted formal empty `Thread::OnWaitObject(int)` body; metadata `88/90`. | Validator `000000003620`; generated output contains the method body. |
| C-0001K0-CTOR | 0001K0 | incorporate | applied | Inserted first-draft `ThreadMan::ThreadMan()` body; metadata `89/89`. | Validator `000000003621`; body carries singleton/debugger/list/thread evidence. |
| C-0001K1-DTOR-WRAPPERS | 0001K1 | incorporate | applied | Inserted ordinary destructor plus five message wrappers; metadata `89/89`. | Validator `000000003622`; formal block includes message IDs `0x0464-0x0468`. |
| C-0001K2-WORKER-LOOP | 0001K2 | incorporate | applied | Inserted `ThreadMan::RunMessagePump()` first draft; metadata `89/88`. | Validator `000000003623`; formal block preserves helper-name caveats. |
| C-0001K5-SCALAR-DTOR | 0001K5 | incorporate | applied | Inserted formal compiler-wrapper comment-only disposition; metadata kept `86/91`. | Validator `000000003624`; no standalone source body emitted. |
| C-0001WA-LAYOUT | 0001WA | incorporate | applied | Inserted formal no-duplicate layout disposition; metadata kept `86/90`. | Validator `000000003625`; layout remains offset evidence for [UID:0000EW]. |
| C-0000SH-GLOBAL | 0000SH | incorporate | applied | Inserted `static ThreadMan *g_pThreadMan = NULL;`; metadata `88/89`. | Validator `000000003626`; lifecycle/storage caveat preserved. |
| C-000305-STORAGE | 000305 | incorporate | applied | Inserted exact-storage/no-duplicate formal comment; metadata `87/89`. | Validator `000000003627`; storage ownership points to [UID:0000SH]. |
| C-0001JX-OLD-AGGREGATE | 0001JX | reject-stale | excluded-with-reason | Did not reclassify [UID:0001JX] as non-emitting. Added bounded callback note preserving the stale-claim rejection. | Validator `000000003628`; generated [UID:0001JX] empty marker remains by scope. |
| C-0001JX-FUTURE-SPLIT | 0001JX | incorporate | applied | Preserved future full-child split plan without clearing [UID:0001JX]. | `by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md` notes the later split requirement. |
| C-0001JY-AGGREGATE | 0001JY | historicalize | applied | Reclassified broad dispatch aggregate as non-emitting split/index coverage; kept metadata `88/89`, `RECONSTRUCTABLE:FALSE`, cleared emitters. | Validator `000000003629`; [UID:0001JY] no longer appears as an empty marker in generated `Thread.cpp`. |
| C-0001JY-WAIT-DRAIN | 0004CI | incorporate | applied | Created exact child `ThreadWaitForQueueDrain`; owner/emitter `0000OR`; formal C++ inserted. | Validator `000000003630`; generated [UID:0004CI] populated. |
| C-0001JY-WAIT-RESULT | 0004CJ | incorporate | applied | Created exact child `ThreadWaitForResult`; owner/emitter `0000OR`; formal C++ inserted. | Validator `000000003631`; generated [UID:0004CJ] populated. |
| C-0001JY-ADD-WAIT | 0001JZ | already-present | already-present | Existing exact child `Thread::AddWaitHandle(HANDLE)` left in place; no duplicate added to [UID:0001JY]. | Existing [UID:0001JZ] remained the exact `0x005967d0-0x005967e5` coverage. |
| C-0001JY-REMOVE-WAIT | 0004CK | incorporate | applied | Created exact child `ThreadRemoveLastWaitHandle`; owner/emitter `0000OR`; formal C++ inserted. | Validator `000000003632`; generated [UID:0004CK] populated. |
| C-0001JY-THREADPROC | 0004CL | incorporate | applied | Created exact child `ThreadProc`; owner/emitter `0000OR`; formal C++ inserted with helper caveats. | Validator `000000003633`; generated [UID:0004CL] populated. |
| C-0001JY-ONMESSAGE | 0004CM | incorporate | applied | Created exact child `ThreadOnMessage`; owner/emitter `0000OR`; formal C++ inserted. | Validator `000000003634`; generated [UID:0004CM] populated. |
| C-0001JY-ONMESSAGEEX | 0004CN | incorporate | applied | Created exact child `ThreadOnMessageEx`; owner/emitter `0000OR`; formal C++ inserted. | Validator `000000003635`; generated [UID:0004CN] populated. |
| C-0001JY-DISPATCH | 0004CO | incorporate | applied | Created exact child `ThreadDispatchRequest`; owner/emitter `0000OR`; formal C++ inserted. | Validator `000000003636`; generated [UID:0004CO] populated. |
| C-0001JY-PRIORITY-SIBLING | 0004CP | incorporate | applied | Created adjacent priority sibling `ThreadDispatchPriorityRequestRaw`; owner/emitter `0000OR`; formal C++ inserted. | Validator `000000003637`; generated [UID:0004CP] populated. |
| C-0001K3-ENTRY | 0001K3 | incorporate | applied | Inserted first-draft `ThreadManWorkerEntry` body; metadata `89/88`. | Validator `000000003638`; exception/application-exit caveats preserved. |
| C-00026P-RODATA | 00026P | incorporate | applied | Inserted formal vtable/RTTI/literal no-standalone-source disposition; metadata kept `87/91`. | Validator `000000003639`; no standalone `.rdata` source emitted. |
| C-0003V7-RAW-HELPERS | 0003V7 | not-applicable | excluded-with-reason | Not edited; callback scope did not include this support lead. | Not listed in the accepted target set for this implementation callback. |

## Implementation Tracking Checklist

- [x] `by-file/Thread.md`: added 2026-07-01 generated-output audit with header proof, tracker context, populated outputs, empty-marker dispositions, and route rationale.
- [x] [UID:0000WL]: metadata `88/90`; formal empty `Thread::OnWaitObject(int)` body inserted.
- [x] [UID:0001K0]: metadata `89/89`; formal `ThreadMan::ThreadMan()` first draft inserted.
- [x] [UID:0001K1]: metadata `89/89`; formal ordinary destructor plus five raw message wrappers inserted.
- [x] [UID:0001K2]: metadata `89/88`; formal `ThreadMan::RunMessagePump()` first draft inserted.
- [x] [UID:0001K5]: formal compiler-wrapper comment-only disposition inserted; metadata kept `86/91`.
- [x] [UID:0001WA]: formal no-duplicate layout comment-only disposition inserted; metadata kept `86/90`.
- [x] [UID:0000SH]: metadata `88/89`; `static ThreadMan *g_pThreadMan = NULL;` inserted.
- [x] [UID:000305]: metadata `87/89`; formal exact-storage/no-duplicate comment-only disposition inserted.
- [x] [UID:0001JX]: not reclassified as non-emitting; callback note preserves the stale-claim rejection and future split plan.
- [x] Future [UID:0001JX] split-only plan preserved for a later callback; not implemented in this bounded pass by supervisor instruction.
- [x] [UID:0001JY] child [UID:0004CI] created for `Thread::WaitForQueueDrain()`.
- [x] [UID:0001JY] child [UID:0004CJ] created for `Thread::WaitForResult(HANDLE)`.
- [x] [UID:0001JY] existing child [UID:0001JZ] confirmed as already-present `HANDLE Thread::AddWaitHandle(HANDLE)` coverage.
- [x] [UID:0001JY] child [UID:0004CK] created for `Thread::RemoveLastWaitHandle()`.
- [x] [UID:0001JY] child [UID:0004CL] created for `Thread::ThreadProc()`.
- [x] [UID:0001JY] child [UID:0004CM] created for `Thread::OnMessage(...)`.
- [x] [UID:0001JY] child [UID:0004CN] created for `Thread::OnMessageEx(...)`.
- [x] [UID:0001JY] child [UID:0004CO] created for `Thread::DispatchRequest(...)`.
- [x] [UID:0001JY] adjacent sibling [UID:0004CP] created for `Thread::DispatchPriorityRequest(...)`.
- [x] [UID:0001JY] aggregate reclassified as non-emitting split/index coverage after exact child creation.
- [x] [UID:0001K3]: metadata `89/88`; formal `ThreadManWorkerEntry` first draft inserted.
- [x] [UID:00026P]: formal vtable/RTTI/literal no-standalone-source comment-only disposition inserted; metadata kept `87/91`.
- [x] Scoped validators ran with `--wait-generated`; command IDs `000000003619` through `000000003639`, all exit 0 and ok:1.
- [x] Generated `auto-generated/NexusTK/util/Thread.cpp` inspected; refreshed at `2026-07-01T06:36:43-04:00`, [UID:0001JY] removed as an empty marker, [UID:0001JX] retained by scope.
- [x] This report ledger/checklist updated with applied/already-present/excluded states and validator proof.

## Blockers

None for this bounded implementation callback. Remaining caveats are source-quality caveats rather than blockers: helper names in [UID:0001K2], exception API names in [UID:0001K3], and original linkage spelling for [UID:0000SH] remain first-draft inferred names pending future source-equivalence refinement. [UID:0001JX] remains an empty marker by explicit supervisor scope because its broader exact-child split was not part of this callback.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/0000OR-Thread-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0000OR-Thread-empty-emitter-family-source-quality.md","timestamp":"2026-07-01T06:42:02","uid":"0000OR"} -->
<!-- {"agent":"B007","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000OR-Thread-empty-emitter-family-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B007/0000OR-Thread-empty-emitter-family-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000OR"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
