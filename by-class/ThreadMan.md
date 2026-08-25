*** UID:0000EW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Thread;
class List;
struct ThreadManWatchRecord;

class ThreadMan : public LObject, public Singleton<ThreadMan>
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

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ThreadMan

## Summary

`ThreadMan` is a process-level thread manager/watchdog singleton implemented with the generic `Thread` utility code. It derives directly from `LObject` and empty `Singleton<ThreadMan>`, records whether a debugger is present, owns a worker thread handle/id pair, maintains a `List` of `ThreadManWatchRecord` entries, and posts/consumes private worker messages `WM_USER+0x64` through `WM_USER+0x68`. Explicit `Singleton<ThreadMan>` constructor/destructor specializations publish and clear [UID:0000SH][g_pThreadMan](by-global/g_pThreadMan.md); those lifetime writes are generated around the derived constructor/destructor rather than handwritten assignments in them.

## Likely Original Placement

- Source: [UID:0000OR][Thread](by-file/Thread.md)
- Proposed path: `util/Thread.cpp`
- Confidence: strong for the shared utility/threading source family and `util/Thread.cpp` placement, medium-high for exact private helper spelling and static/singleton construction syntax.

Keep `ThreadMan` in `NexusTK/util/Thread.cpp` with [UID:0000OR][Thread](by-file/Thread.md). A separate `ThreadMan.cpp` is source-plausible by class name only; current evidence favors the shared `Thread.cpp` file because the executable island, generated route, `g_pThreadMan` storage, and `Thread`/`ThreadMan` read-only data are all contiguous/shared, and no file-path or source-tree evidence supports a split.

## Class-Level C++ Scope

This class page now emits the source-facing class declaration and API inventory with direct public bases `LObject, Singleton<ThreadMan>` and `[[CHILDREN]]` after the closed class shell. Method bodies belong in the exact child by-memory pages, and compiler-generated cleanup/deleting wrapper ranges should not be emitted as named handwritten methods. The class declaration intentionally includes only `virtual ~ThreadMan();`; it does not include scalar-deleting-destructor pseudo-code or a `ClearSingleton` helper. Its H channel remains blank because current source topology keeps the complete class private to `Thread.cpp`.

## Destructor And Wrapper Policy

The source-level destructor is ordinary `ThreadMan::~ThreadMan()` behavior: terminate/close `m_workerThreadHandle` when present, clear the handle slot, and delete/null `m_watchList`. Reverse base destruction then invokes `Singleton<ThreadMan>::~Singleton()` to clear [UID:0000SH][g_pThreadMan](by-global/g_pThreadMan.md) before implicit `LObject` teardown. The raw non-deleting destructor body in [UID:0001K1][0x00596d20-0x00596e0b.ThreadManRawMessageWrappers](by-memory/0x00596d20-0x00596e0b.ThreadManRawMessageWrappers.md) is the best current body-shape evidence for that sequence.

[UID:0001K5][0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor](by-memory/0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md) is class-owned MSVC scalar deleting destructor wrapper glue reached only through `ThreadMan` vtable slot `0x0062e2c4`. B008's 2026-06-19 local PE/Capstone recheck found the target VA pointer only in that vtable slot, zero target RVA/raw-offset hits, and zero `.text` rel32 direct callers. Keep it reconstructable through this class declaration, but do not add a source-visible scalar-deleting-destructor method or explicit `operator delete`, guard-helper, or base-destructor calls.

B009's older Rule 26 report correctly identifies the wrapper as blank-C++ generated ABI support and the `0x00596d20` sequence as the ordinary source destructor. Its explicit global clear in the draft below is preserved as a historical pre-PMD assumption, not the current source recommendation:

```cpp
ThreadMan::~ThreadMan()
{
    if (m_workerThreadHandle != NULL) {
        TerminateThread(m_workerThreadHandle, 0);
        CloseHandle(m_workerThreadHandle);
        m_workerThreadHandle = NULL;
    }

    if (m_watchList != NULL) {
        delete m_watchList;
        m_watchList = NULL;
    }

    g_pThreadMan = NULL;
}
```

The current source-facing body removes only that last assignment; the accepted `Singleton<ThreadMan>::~Singleton()` specialization generates the clear before `LObject::~LObject`. Keep the handle/list cleanup as destructor-body guidance for the raw ordinary destructor page. The class declaration here remains `virtual ~ThreadMan();`; exact original member prefixes are still inferred, but `m_isDebuggerPresent`, `m_workerThreadHandle`, `m_workerThreadId`, and `m_watchList` are the current best supported source-facing names and do not block the scalar-wrapper no-code policy.

B012's source-quality reanalysis independently validates the same policy and closes the remaining heuristic issues for this class page. The direct owner/emitter for [UID:0001K5][0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor](by-memory/0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md) is this class, not the file page and not `NONE`, because the wrapper is the `ThreadMan` vtable slot at `.rdata:0x0062e2c4`. The final source should keep `ThreadMan` in `NexusTK/util/Thread.cpp`, expose `virtual ~ThreadMan();`, and let MSVC regenerate the scalar wrapper, delete flags, vtable slot, `OperatorDeleteWrapper` call, and guard/no-op branch. Do not introduce a source-visible scalar deleting destructor, `ThreadMan::ClearSingleton`, explicit base-destructor call, or `ThreadMan.cpp` split without stronger source/project evidence.

## Method Families

| Range | Role |
| --- | --- |
| `0x00596bf0-0x00596d13` | [UID:0001K0][0x00596bf0-0x00596d13.ThreadManConstructor](by-memory/0x00596bf0-0x00596d13.ThreadManConstructor.md): `ThreadMan::ThreadMan()`, with compiler-inlined direct `Singleton<ThreadMan>` base publication before the derived body, then `IsDebuggerPresent` probing, `List(20,16)` watch storage, and worker-thread startup. |
| `0x00596d20-0x00596e0b` | [UID:0001K1][0x00596d20-0x00596e0b.ThreadManRawMessageWrappers](by-memory/0x00596d20-0x00596e0b.ThreadManRawMessageWrappers.md): ordinary `ThreadMan::~ThreadMan()` body plus retained `PostThreadMessageW` wrappers for worker messages `0x0464-0x0468`. |
| `0x00596e10-0x005970df` | [UID:0001K2][0x00596e10-0x005970df.ThreadManWorkerLoop](by-memory/0x00596e10-0x005970df.ThreadManWorkerLoop.md): `ThreadMan::RunMessagePump()`, the Win32 wait/message pump and watchdog scan. |
| `0x00597100-0x005971ad` | [UID:0001K3][0x00597100-0x005971ad.ThreadManWorkerEntry](by-memory/0x00597100-0x005971ad.ThreadManWorkerEntry.md): file-static `ThreadManWorkerEntry(LPVOID)` passed to `CreateThread`. |
| `0x005971b0-0x005974da` | [UID:0003V7][0x005971b0-0x005974da.ThreadManWatchListRawHelpers](by-memory/0x005971b0-0x005974da.ThreadManWatchListRawHelpers.md): retained private watch-list helper island over `ThreadManWatchRecord` fields; source-shaped but no function objects, start xrefs, or pointer constants. |
| `0x005974e0-0x005974eb` | [UID:0001K4][0x005974e0-0x005974eb.ClearThreadManSingleton](by-memory/0x005974e0-0x005974eb.ClearThreadManSingleton.md): constructor-unwind action generated from `Singleton<ThreadMan>::~Singleton()`, no source method. |
| `0x005974f0-0x0059756e` | [UID:0001K5][0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor](by-memory/0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md): compiler-generated scalar deleting destructor wrapper around the ordinary destructor, Singleton-base teardown, `LObject` teardown, and delete policy. |

## Evidence

- Generated source and IDA agree that `ThreadMan::ThreadMan` writes `0x0069be08`.
- Xrefs to `0x0069be08` are in the constructor, singleton-clear helper, destructor, and an unmodeled adjacent region around `0x00596d5f`.
- Constructor dynamically loads UTF-16 `KERNEL32.DLL` from `0x0062e2d0`, resolves ASCII `IsDebuggerPresent` from `0x0062e2ec`, optionally calls the result, and stores the debugger-present flag at `this+0x04`. The PE also has a separate import-name-table occurrence of `IsDebuggerPresent`; the local literal remains ThreadMan constructor probe data.
- Worker loop strings include a fatal-app-exit dead-thread message pattern.
- The worker list is `List(20, 16)` and stores [UID:0001WB][ThreadManWatchRecord](by-type/by-struct/ThreadManWatchRecord.md) records.
- IDA raw disassembly on 2026-05-25 shows the unmodeled `0x00596d20-0x00596e0b` helper gap posts exactly the message ids consumed by the worker loop.
- 2026-05-26 IDA MCP recheck reconfirmed the modeled function set and sizes: constructor `0x00596bf0` size `0x123`, worker loop `0x00596e10` size `0x2cf`, worker entry `0x00597100` size `0xad`, singleton clear `0x005974e0` size `0x0b`, and scalar deleting destructor `0x005974f0` size `0x7e`.
- The same recheck still reports the raw destructor/post-message starts `0x00596d20`, `0x00596d70`, `0x00596d90`, `0x00596db0`, `0x00596dd0`, and `0x00596df0` as `Not a function` with empty `xrefs_to`.
- No direct constructor caller was found in this pass; construction may be through static singleton glue or a function not currently modeled as a direct call.
- The 2026-06-02 [UID:0001JX][0x00596250-0x0059756e.ThreadAndThreadMan](by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md) aggregate attaches the full `Thread`/`ThreadMan` island to [UID:0000OR][Thread](by-file/Thread.md) after confirming modeled starts, raw-helper non-function status, singleton xrefs, major callees, and adjacent padding.
- The exact child pages for the constructor, raw wrappers, worker loop, worker entry, singleton clear, and scalar deleting destructor are all now reconstructable and parent-attached to `Thread.cpp`, with scores at or above the 80/80 attachment gate.
- A008 attempted a live IDA MCP recheck on 2026-06-07, but `http://127.0.0.1:13337/mcp` was unavailable. No new live-IDB facts are added by that attempt; this update is based on the already written IDA-backed documentation cited above.
- 2026-06-08 Agent-A002 live IDA MCP `py_eval` rechecked the parent/source gate: `ThreadMan::ThreadMan` remains modeled at `0x00596bf0-0x00596d13`, the worker loop at `0x00596e10-0x005970df`, the worker entry at `0x00597100-0x005971ad`, and the scalar deleting destructor at `0x005974f0-0x0059756e`; raw starts `0x00596d20`, `0x00596d70`, `0x00596d90`, `0x00596db0`, `0x00596dd0`, and `0x00596df0` still have no IDA function objects. The same check found `ThreadMan` vtable refs at `0x00596c4d`, `0x00596d26`, and `0x005974f9`, plus [UID:0000SH][g_pThreadMan](by-global/g_pThreadMan.md) refs at `0x00596c33`, `0x00596c3a`, `0x00596d5f`, `0x005974e0`, and `0x00597532`.
- B001 2026-06-16 split the later raw watch-list helper island as [UID:0003V7][0x005971b0-0x005974da.ThreadManWatchListRawHelpers](by-memory/0x005971b0-0x005974da.ThreadManWatchListRawHelpers.md), with outer padding recorded in [UID:0000VN][-ignored](by-memory/-ignored.md). The island has no function objects, no xrefs to starts, and no VA/RVA pointer constants, but its bytes implement ThreadMan watch-list helper logic over [UID:0001WB][ThreadManWatchRecord](by-type/by-struct/ThreadManWatchRecord.md).
- B003 2026-06-20 source-quality review tied the final field/message names to the current binary evidence: `this+0x04` is `m_isDebuggerPresent`, `this+0x08` is `m_workerThreadHandle`, `this+0x0c` is `m_workerThreadId`, `this+0x10` is `m_watchList`, and watch-record `+0x08` is `watchedThreadId` copied from generic `Thread+0x60`.
- The raw wrapper starts and watch-list helper starts still have no direct xrefs, function records, or pointer constants, but their bodies are coherent source-shaped `ThreadMan` methods/helpers rather than compiler glue. This supports documenting them as retained private/public API candidates while preserving the no-direct-route caveat.
- B008 2026-06-19 scalar-wrapper recheck independently reconfirmed the destructor field roles from raw PE/Capstone: `+0x08` is the Win32 worker thread `HANDLE`, `+0x0c` is the manager worker thread id used by `PostThreadMessageW`, and `+0x10` is a heap `List *` deleted through its vtable. The same pass keeps constructor reachability as a separate singleton/static-initializer question rather than a blocker for scalar-wrapper class ownership.
- 2026-07-31/2026-08-01 B007 live reanalysis resolves the remaining base/lifetime question. ThreadMan RTTI has exactly three hierarchy entries and the `Singleton<ThreadMan>` base descriptor PMD `{mdisp=4,pdisp=-1,vdisp=0}`. The complete object is `0x14` bytes; MSVC empty-base optimization overlaps the empty base at `+4` with `m_isDebuggerPresent`.
- Constructor bytes call `LObject` first, form the empty Singleton subobject at `this+4`, convert it back to the complete object for `g_pThreadMan`, then install the ThreadMan vtable and run the derived body. Ordinary destruction performs derived cleanup, clears the pointer at the reverse-base position, and tail-jumps to `LObject::~LObject`. The EH action and scalar wrapper reproduce the same base clear. This convergence makes direct `Singleton<ThreadMan>` inheritance and explicit class-specialization lifetime code materially stronger than the older explicit-derived-assignment model.
- Live IDA still has only an incomplete no-member `ThreadMan` type and no `Singleton<ThreadMan>` UDT. No guessed full IDA UDT is required for the source declaration; exact class layout is documented by [UID:0001WA][ThreadManLayout](by-type/by-struct/ThreadManLayout.md).

## Source-Facing Names

- Constructor/destructor: `ThreadMan::ThreadMan()` and `virtual ThreadMan::~ThreadMan()`.
- Raw message wrappers: `RegisterThread(Thread *thread, void *context)`, `UnregisterThread(Thread *thread)`, `ClearThreadProbe(Thread *thread)`, `MarkCurrentThreadBlocked()`, and `ClearCurrentThreadBlocked()`.
- Worker loop and entry: `ThreadMan::RunMessagePump()` and file-static `DWORD WINAPI ThreadManWorkerEntry(LPVOID parameter)`.
- Watch-list helpers: `FindWatchRecordByThread`, `FindWatchRecordByThreadId`, `ScanWatchList`, `CheckWatchRecordTimeout`, `AddWatchRecord`, `RemoveWatchRecord`, `ClearWatchRecordProbe`, `MarkThreadIdBlocked`, and `ClearThreadIdBlocked`.
- Worker message ids: `THREADMAN_REGISTER_THREAD`, `THREADMAN_UNREGISTER_THREAD`, `THREADMAN_CLEAR_THREAD_PROBE`, `THREADMAN_MARK_THREAD_ID_BLOCKED`, and `THREADMAN_CLEAR_THREAD_ID_BLOCKED`.

## Ownership And Emission Decision

Attach the class declaration to [UID:0000OR][Thread](by-file/Thread.md), because the class belongs in `NexusTK/util/Thread.cpp`. True `ThreadMan` member children should route through this class UID for source-level ownership/emission, while [UID:0001K3][0x00597100-0x005971ad.ThreadManWorkerEntry](by-memory/0x00597100-0x005971ad.ThreadManWorkerEntry.md) stays file-owned as a `Thread.cpp` helper unless stronger evidence proves a private static class member.

[UID:0000SH][g_pThreadMan](by-global/g_pThreadMan.md) remains canonically owned by Thread.cpp, but its generated emitter is this class at position `1`. That attachment is ordering, not class-static ownership: it emits the file-static cell and explicit Singleton specializations after the complete class shell and before unpositioned method children.

[UID:0001K4][0x005974e0-0x005974eb.ClearThreadManSingleton](by-memory/0x005974e0-0x005974eb.ClearThreadManSingleton.md) remains `RECONSTRUCTABLE:FALSE` no-code EH/compiler cleanup. [UID:0001K5][0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor](by-memory/0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md) remains compiler-generated deleting-destructor wrapper evidence; the source-level declaration is only `virtual ~ThreadMan();`.

## Generated Data Caveats

Report-time validator-generated `auto-generated/NexusTK/util/Thread.cpp` command `000000007832`, refreshed `2026-07-07T03:37:36-04:00`, already emitted the accepted `ThreadMan` declaration, constructor, ordinary destructor/message-wrapper bodies from [UID:0001K1][0x00596d20-0x00596e0b.ThreadManRawMessageWrappers](by-memory/0x00596d20-0x00596e0b.ThreadManRawMessageWrappers.md), worker loop, worker entry, and scalar-wrapper/comment policy. Later scoped validators may refresh the generated header again; use the callback report validator log for the current command/timestamp. Older `source-3/simroot_v2/class_ThreadMan.cpp` remains a low-fidelity lead: it is useful for constructor/destructor shape, but the worker loop still has a very low score and replaces concrete Win32 message handling with fake helper names. The raw watch-list helper island at [UID:0003V7][0x005971b0-0x005974da.ThreadManWatchListRawHelpers](by-memory/0x005971b0-0x005974da.ThreadManWatchListRawHelpers.md) remains blank-C++ raw helper evidence with no function records, start xrefs, or pointer constants.

`class_ThreadMan.cpp.disabled` contains bad/stale rows:

- `0x0045004b`: missing code and not part of the ThreadMan island.
- `0x004e0052`: NewHumanImageLib data-loading code, not a ThreadMan method.

The next function at `0x00597570` is [UID:0000F0][TimerHandler](by-class/TimerHandler.md) construction, not an unresolved ThreadMan tail.

2026-05-26 IDA MCP recheck still resolves `0x0045004b` inside `sub_450030` at `0x00450030`, `0x004e0052` inside `NewHumanImageLib::NewHumanImageLib` at `0x004dfd10`, and `0x00597570` as the `TimerHandler` vtable constructor. None of those rows should be restored as ThreadMan methods.

## Cross-References

- File: [UID:0000OR][Thread](by-file/Thread.md)
- Memory: [UID:0001JX][0x00596250-0x0059756e.ThreadAndThreadMan](by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md)
- Raw wrappers: [UID:0001K1][0x00596d20-0x00596e0b.ThreadManRawMessageWrappers](by-memory/0x00596d20-0x00596e0b.ThreadManRawMessageWrappers.md)
- Worker loop: [UID:0001K2][0x00596e10-0x005970df.ThreadManWorkerLoop](by-memory/0x00596e10-0x005970df.ThreadManWorkerLoop.md)
- Worker entry: [UID:0001K3][0x00597100-0x005971ad.ThreadManWorkerEntry](by-memory/0x00597100-0x005971ad.ThreadManWorkerEntry.md)
- Raw watch-list helpers: [UID:0003V7][0x005971b0-0x005974da.ThreadManWatchListRawHelpers](by-memory/0x005971b0-0x005974da.ThreadManWatchListRawHelpers.md)
- Global: [UID:0000SH][g_pThreadMan](by-global/g_pThreadMan.md)
- Layout/types: [UID:0001WA][ThreadManLayout](by-type/by-struct/ThreadManLayout.md), [UID:0001WB][ThreadManWatchRecord](by-type/by-struct/ThreadManWatchRecord.md), [UID:0001SR][ThreadManMessageId](by-type/by-enum/ThreadManMessageId.md)
- Related: [UID:0000EV][Thread](by-class/Thread.md), [UID:000079][List](by-class/List.md), [UID:0000F0][TimerHandler](by-class/TimerHandler.md)

## Changes

- 2026-08-01 B007 UID000305 accepted-report ordinary callback:
  - Raised `88/89` to `92/94` while preserving Thread.cpp owner/emitter routing and blank H.
  - Added direct public `Singleton<ThreadMan>` inheritance to the exact formal class block without changing accepted methods, fields, or child stream.
  - Incorporated exact three-base RTTI/PMD/EBO, constructor/base order, normal/EH/scalar teardown convergence, specialization emission ordering, and the historical correction that removes explicit derived publication/clear assignments.

- 2026-07-07 B006 UID0001JX implementation callback:
  - Summary/evidence: refreshed the generated-data caveat to distinguish report-time validator-generated `auto-generated/NexusTK/util/Thread.cpp` command `000000007832` / `2026-07-07T03:37:36-04:00` from older `simroot_v2/class_ThreadMan.cpp`, preserving the accepted UID0001K1 destructor/message-wrapper emission and UID0003V7 raw watch-list no-code policy; later scoped validators may refresh the generated header again.
- 2026-06-20 B003 Rule 26 implementation:
  - Before: `COMPLETION:86`, `CONFIDENCE:85`, blank class C++, and old final-source-gate language that deferred class code because constructor reachability, raw helper liveness, and field names were unresolved.
  - After: `COMPLETION:88`, `CONFIDENCE:89`, first-draft class declaration/API inventory with `[[CHILDREN]]` after the closed class shell, settled field/message/watch-record names, `util/Thread.cpp` placement with rejected `ThreadMan.cpp` split, class/member child routing policy, and explicit no-code policy for singleton cleanup and scalar deleting destructor glue.
  - Summary/evidence: B003 local PE/disassembly/xref review confirmed the constructor/worker/destructor/read-only-data/global evidence, `CreateThread` worker-entry pointer, `WM_USER+0x64..0x68` message family, watched `Thread+0x60` thread-id field, no-direct-xref retained helper status, and stale disabled rows outside the ThreadMan island.
- 2026-06-21 B008 scalar deleting destructor support sync:
  - Summary/evidence: incorporated B008's target-specific wrapper policy for [UID:0001K5][0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor](by-memory/0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md), including vtable-only reachability, ordinary destructor body-shape evidence from [UID:0001K1][0x00596d20-0x00596e0b.ThreadManRawMessageWrappers](by-memory/0x00596d20-0x00596e0b.ThreadManRawMessageWrappers.md), explicit no source-visible scalar-deleting-destructor method, and the field/type interpretation used by the destructor cleanup sequence. Metadata remains `88/89`; the class declaration already emits the correct `virtual ~ThreadMan();` surface.
- 2026-06-21 B009 Rule 26 older-report reconciliation:
  - Summary/evidence: added B009's source-level destructor draft and explicit instruction that [UID:0001K5][0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor](by-memory/0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md) is blank because it is generated wrapper glue, not because the class is below a stale final-C++ gate. Metadata and emitted declaration remain unchanged.
- 2026-06-22 B012 source-quality implementation:
  - Summary/evidence: added B012's class-owner/source-placement closure for the scalar wrapper, explicitly preserving `virtual ~ThreadMan();`, current field names, `util/Thread.cpp` placement, and generated-wrapper no-code policy. Metadata and emitted declaration remain unchanged.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:78`.
  - Summary/evidence: scored from the detailed singleton constructor, worker-loop, raw-wrapper, worker-entry, destructor, layout/type, and bad-generated-row documentation, with confidence capped by unresolved constructor reachability and raw wrapper function-boundary caveats.
- 2026-05-31: Reconstructable metadata was blank.
  - Before: `RECONSTRUCTABLE:`.
  - After: `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA MCP rechecked the source-owned `ThreadMan` constructor, worker loop, worker entry, singleton clear helper, and scalar deleting destructor boundaries. The page remains unattached and has no C++ reconstruction because raw wrapper boundaries and final source shape are not yet at the near-final threshold.
- 2026-06-07 A008 parent-chain refresh:
  - What existed before: `COMPLETION:84`, `CONFIDENCE:78`, and no autogen parent, even though the exact child memory pages had already been attached to [UID:0000OR][Thread](by-file/Thread.md).
  - Changed to: `COMPLETION:86`, `CONFIDENCE:82`, and `AUTOGEN_PARENT_UID:0000OR`.
  - Summary/evidence: existing IDA-backed child pages now cover the constructor, raw destructor/message wrappers, worker loop, worker entry, singleton clear helper, scalar deleting destructor, `g_pThreadMan`, layout/type records, stale generated-row exclusions, and the aggregate `ThreadAndThreadMan` source-root chain. C++ remains blank because live constructor reachability, raw wrapper function records, final field names, and exact destructor/source spelling are still not final-audit quality. A live MCP retry in this session failed because the endpoint was unavailable, so no new live-IDB claims were added.
- 2026-06-08 Agent-A002 Batch 134 parent-gate refresh:
  - Before: `COMPLETION:86`, `CONFIDENCE:82`.
  - After: `COMPLETION:86`, `CONFIDENCE:85`.
  - Summary/evidence: live IDA MCP reconfirmed the constructor, worker loop, worker entry, scalar deleting destructor, still-raw message-wrapper starts, `ThreadMan` vtable refs, and `g_pThreadMan` refs. This raises the class parent enough to own [UID:0001WB][ThreadManWatchRecord](by-type/by-struct/ThreadManWatchRecord.md) under the strict `85/85` gate, while final source remains blocked by raw wrapper/source-shape caveats.
- 2026-06-16 B001 raw watch-list split:
  - Summary/evidence: added exact child [UID:0003V7][0x005971b0-0x005974da.ThreadManWatchListRawHelpers](by-memory/0x005971b0-0x005974da.ThreadManWatchListRawHelpers.md) to the method families, evidence, generated-output caveats, and cross-references. No score change; final source remains blocked by raw-helper names and reachability/source-emission policy.
