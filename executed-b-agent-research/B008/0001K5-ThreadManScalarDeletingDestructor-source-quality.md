** TARGET-REPORT-UID:0001K5 **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001K5 ThreadManScalarDeletingDestructor Source-Quality Research

Status: FINISHED  
Agent: B008  
Assignment id: `B008-goal2-threadman-scalar-deleting-destructor-source-quality-0001K5-20260619`  
Target: [UID:0001K5] `source-3/project-documentation/by-memory/0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md`  
Report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B008/research/0001K5-ThreadManScalarDeletingDestructor-source-quality.md`  
Report-only rule: no by-* docs, generated files, IDA DB, generated source, project-level reports, or `by-memory/-coverage-report.md` were edited.

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0001K5] reconstructable, but classify it as the MSVC scalar deleting destructor wrapper generated from the source-level `ThreadMan::~ThreadMan()` destructor. The source destructor body is ordinary `ThreadMan` teardown; this exact `0x005974f0-0x0059756e` range is compiler wrapper glue and should not receive handwritten formal C++.
- Final disposition: class-owned generated-binary destructor wrapper. The direct semantic owner/emitter should change from [UID:0000OR] `Thread.cpp` to [UID:0000EW] `ThreadMan`; `Thread.cpp` remains the source-file route through the class page.
- Required action: update the target from `84/88` to `86/91`, change `CANONICAL_OWNER:0000EW`, change `EMITTER_UIDS:0000EW`, keep `RECONSTRUCTABLE:TRUE`, keep the target's formal `RECONSTRUCTION_CPP CODE` block blank, and replace stale "95+ gate" language with target-specific wrapper/no-code proof.
- Confidence: high for exact range, padding, bytes, vtable-only reachability, cleanup order, `g_pThreadMan` clear, worker-handle/list fields, `LObject` base cleanup, delete-flag behavior, and class/source placement. Confidence is capped below final-audit because live IDA MCP was unavailable in this pass and exact original member spelling remains inferred/descriptive.

## Target

- Target UID: `0001K5`
- Target path: `source-3/project-documentation/by-memory/0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md`
- Current metadata: `COMPLETION:84`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000OR`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OR`, blank formal C++.
- Recommended metadata: `COMPLETION:86`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000EW`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000EW`, blank formal C++.
- Current coverage row location: under the `0x00596250-0x0059756e` Thread/ThreadMan cluster, after [UID:0001K4] `ClearThreadManSingleton` and before the ignored `0x0059756e-0x00597570` padding row.

## Supervisor Active Recheck

- Supervisor asked for B-agent source-quality/inference work on scalar deleting destructor boundaries, vtable reachability, `g_pThreadMan` writes, worker handle cleanup, watch-list destruction, `LObject` base cleanup, delete-flag/guard paths, relation to [UID:0001K1] raw non-deleting destructor cleanup, final C++ policy, field names/types, source ownership, constructor/worker-loop/singleton interactions, support-doc updates, coverage text, validation commands, and IDA recommendations.
- No split is required for [UID:0001K5]. Fresh PE bytes confirm the exact target is one 126-byte function with five `0xcc` bytes before it and two `0xcc` bytes after it. The successor `0x00597570` is the TimerHandler vtable-installing constructor and is not a ThreadMan tail.
- This report rechecked prior [Agent-B009 `0001K5`](../../Agent-B009/research/0001K5-ThreadManScalarDeletingDestructor-source-quality.md) and [Agent-B003 `0000EW`](../../Agent-B003/research/0000EW-ThreadMan-class-source-quality.md) reports as leads. B008 independently confirmed their core wrapper/source-shape conclusion with local PE/Capstone scans.

## Inference Research Guidance Check

- `by-structure.md` says ownership must be the narrowest semantic owner, not merely the final `.cpp` route. A method/destructor wrapper for `ThreadMan` should therefore route through [UID:0000EW] once that class clears the gate, with [UID:0000OR] still acting as the source-file root.
- `by-structure.md` also says code may be entered after the active combined-score/emitter gate, but the code must be the source represented by that page's own range. This target's own range is scalar deleting destructor wrapper glue, so the active gate does not require a fake `ThreadMan::scalar_deleting_destructor` body.
- `inference_research.md` supports confidence-rated source-file and field-name inference when stripped binaries lack original symbol names. Here the binary proves roles and offsets; exact original spelling is inferred, not source-proven.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Best-supported conclusion | Rejected alternatives / effect |
| --- | --- | --- | --- |
| `sub_5974F0` generated/raw name | Target body uses `this` in `ecx`, reads deleting flags from `[ebp+8]`, tests `flags & 1`, tests `flags & 4`, optionally calls the global delete wrapper, and is referenced only by `.rdata:0x0062e2c4`. | Source-facing binary role is `ThreadMan` scalar deleting destructor wrapper. IDA rename candidate: `ThreadMan__scalar_deleting_destructor` or MSVC-style ``ThreadMan::`scalar deleting destructor'``. | Reject treating `sub_5974F0` as an original handwritten method name or standalone source helper. |
| Exact range and boundary | Local PE bytes at `0x005974f0-0x0059756e` are one coherent function; `0x005974eb-0x005974f0` is five `cc`; `0x0059756e-0x00597570` is two `cc`; `0x00597570` begins `mov dword ptr [ecx], 0x62e338; ret`. | Keep target range unchanged. Preserve ignored padding row after the target. | Reject merging `0x00597570` into ThreadMan; it is TimerHandler/TimerMgr successor code. Reject splitting [UID:0001K5] internally. |
| Vtable reachability | Pointer scan found target VA `0x005974f0` exactly once at `.rdata:0x0062e2c4`; no target RVA/raw-offset hits; no `.text` rel32 direct calls/jumps to target. Existing docs also record vtable xref/no direct callers. | Target is not dead and not directly source-called. It is vtable slot wrapper glue for `ThreadMan`. | Reject no-owner/non-emitting "dead code" handling. The class declaration/destructor must regenerate this slot even though the formal code block stays blank. |
| Direct owner/emitter | Target restores `ThreadMan` vtable, tears down `ThreadMan` fields, clears `g_pThreadMan`, and vtable slot belongs to `ThreadMan`; current class page is `86/85` and emits through [UID:0000OR]. | Change direct `CANONICAL_OWNER` and `EMITTER_UIDS` to [UID:0000EW] `ThreadMan`; [UID:0000OR] `Thread.cpp` remains indirect source root. | Reject keeping direct owner/emitter as file [UID:0000OR] after class gate is satisfied. File-level ownership was a staging shortcut, not the narrow semantic owner. |
| Ordinary destructor source shape | Raw non-deleting destructor body at `0x00596d20-0x00596d6a` repeats the worker-handle cleanup, watch-list delete, singleton clear, and base-cleanup tail jump without deleting flags or storage release. Target repeats the same cleanup then handles delete flags. | Source body is ordinary `ThreadMan::~ThreadMan()` cleanup: terminate/close `m_workerThreadHandle`, delete/null `m_watchList`, clear `g_pThreadMan`, then implicit `LObject` base destruction. | Reject an empty destructor; reject writing vtable stores, explicit base destructor call, delete flags, `OperatorDeleteWrapper`, or guard path in source destructor C++. |
| `this+0x08` member | Constructor stores `CreateThread` handle at `+0x08`; target/raw destructor call `TerminateThread` and `CloseHandle` on it and clear it. Import parser confirmed IAT `0x0060d220 = TerminateThread` and `0x0060d110 = CloseHandle`. | Field type/name: `HANDLE m_workerThreadHandle` at `+0x08` (descriptive/source-facing; original prefix not proven). | Reject generic `thread`, `worker`, or `HANDLE*`; code uses a Win32 handle value, not a pointer to a custom object. |
| `this+0x0c` related member | Constructor passes `this+0x0c` as the `CreateThread` thread-id out pointer; raw message wrappers post to this id through `PostThreadMessageW`. | Field type/name: `DWORD m_workerThreadId` at `+0x0c`. Not directly read by [UID:0001K5], but needed in `ThreadManLayout` and class docs. | Reject leaving `+0x0c` as anonymous when destructor support docs discuss `ThreadMan` layout. |
| `this+0x10` member | Constructor allocates a `List(20,16)` object and stores pointer at `+0x10`; worker loop scans/mutates records through it; target/raw destructor reads pointer and calls first virtual slot with deleting flag `1`, then clears `+0x10`. | Field type/name: `List *m_watchList` at `+0x10`, element semantics `ThreadManWatchRecord` size `0x14`. | Reject inline array, `std::list`, or ordinary current capacity field. The destructor deletes a heap object through a vtable. |
| `ThreadManWatchRecord` relationship | Existing docs and B003 class pass identify `List(20,16)` elements as records with `thread`, `context`, watched thread id, pending byte, and deadline tick. Worker helpers and loop use the same offsets. | Target should cross-reference the record/list ownership but does not need to emit record C++. Support docs should prefer `watchedThreadId` for record `+0x08` to avoid confusion with `ThreadMan::m_workerThreadId`. | Reject treating watch-list destructor as `delete[]` or raw buffer free. It is a `List` object scalar deletion. |
| `g_pThreadMan` | Pointer scan found immediate `0x0069be08` at constructor writes `0x00596c34/0x00596c3c`, raw cleanup `0x00596d61`, EH clear helper `0x005974e2`, and target clear `0x00597534`. Storage/global docs isolate exact global. | Source declaration remains `static ThreadMan *g_pThreadMan;` in `util/Thread.cpp` unless later linkage evidence changes `static`. Ordinary destructor clears it. | Reject a source method named `ClearThreadManSingleton`; [UID:0001K4] is compiler EH cleanup only. |
| `LObject` base cleanup | Target calls `0x004f4a90`; raw destructor tail-jumps there. `LObjectRuntimeShell` exact child identifies `0x004f4a90` as `LObjectDestructorBody`. | Source destructor must not explicitly call `LObject::~LObject()`; C++ emits base destruction after derived destructor body. Target doc should identify this call as compiler-emitted base cleanup after derived body. | Reject decompiler-shaped source with `sub_4F4A90(this)` or manual `LObjectDestructorBody()` call. |
| Delete wrapper path | Target calls `0x004f4ac0` only after `flags & 1` is set and `flags & 4` is clear. `OperatorDeleteWrapper` routes through `GetMemoryMan` and `FreeBufferMemory`. | This is MSVC scalar deleting destructor storage release, not source-authored `ThreadMan` logic. | Reject modeling `operator delete(this)` inside `ThreadMan::~ThreadMan()`. |
| Flag-4 guard/no-op path | Target pushes `0x14` and `this`, calls `0x0041b6a0`, adjusts stack, returns `this`, and does not call `0x004f4ac0`. `0x14` matches observed object size. | Document as compiler/runtime deleting-destructor flag-4 path with size argument, not handwritten code. | Reject interpreting it as a normal MemoryMan free path or source-level sized delete in this project source. |
| Constructor/static route | Fresh pointer scan found no target VA/RVA pointer hits and no direct rel32 calls to constructor `0x00596bf0`; support docs already keep singleton construction route open. Worker entry VA `0x00597100` is pushed by constructor at `0x00596cb1`, and worker entry calls worker loop at `0x00597140`. | Constructor reachability remains a broader singleton/static-initializer question, but it does not block [UID:0001K5] wrapper owner or no-code policy. | Reject using missing constructor caller as reason to leave scalar wrapper file-owned or non-emitting. |
| Raw helper liveness | Fresh scan found no pointer/rel32 hits for raw destructor/message-wrapper starts or watch helper starts, matching existing docs. | Raw ordinary destructor at `0x00596d20` is still valuable source-shape evidence. No-route helper uncertainty should stay in [UID:0001K1]/[UID:0003V7], not block [UID:0001K5]. | Reject requiring raw helper split before documenting scalar wrapper. Optional future split of `0x00596d20-0x00596d6f` would improve ordinary destructor C++ placement. |
| Final target C++ | Page clears score/emitter gate after recommendation, but target range is generated wrapper glue, not handwritten source. | Keep target formal C++ blank and add explicit no-code proof. Put source destructor draft only in support docs or future raw destructor child. | Reject old "below 95/95" no-code blocker. Also reject pseudo-C++ `ThreadMan::scalar_deleting_destructor(unsigned int flags)`. |

## Evidence Standards Used

- Existing IDA-backed documentation: target page, [UID:0001K1] raw wrappers, [UID:0001K0] constructor, [UID:0001K2] worker loop, [UID:0003V7] watch helpers, [UID:0001K4] singleton clear, [UID:0001WA] layout, [UID:0001WB] watch record, [UID:0000EW] class, [UID:0000OR] file, [UID:0000SH] singleton global, [UID:00026P] read-only data, [UID:000195] `LObjectRuntimeShell`, and [UID:000197] `OperatorDeleteWrapper`.
- Prior B-agent reports used as leads: B009 `0001K5-ThreadManScalarDeletingDestructor-source-quality.md` and B003 `0000EW-ThreadMan-class-source-quality.md`. B008 did not treat them as authoritative; raw PE scans below revalidated the key claims.
- Fresh B008 local binary evidence: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA1 `c285b73dc7b54c9a0e28ff7591a9bdde2ac55f9a`, image base `0x00400000`, PE section parsing, Capstone x86 32-bit disassembly, direct rel32 scans, absolute pointer scans, import-table parsing.
- Live IDA MCP status: attempted `http://127.0.0.1:13337/mcp` `tools/list`; request timed out. This report therefore relies on existing live-IDA-backed docs plus fresh local PE checks.

## Fresh Raw PE / Capstone Facts

- PE sections:
  - `.text` VA `0x00401000`, raw `0x00000400`, raw size `0x20b600`.
  - `.rdata` VA `0x0060d000`, raw `0x0020ba00`, raw size `0x5f200`.
  - `.data` VA `0x0066d000`, raw `0x0026ac00`, raw size `0x0d800`.
  - `.rsrc` VA `0x0069d000`, raw `0x00278400`, raw size `0x15e00`.
- Target raw span: VA `0x005974f0-0x0059756e`, raw `0x001968f0-0x0019696e`, size `0x7e` / 126 bytes.
- Prepad: `0x005974eb-0x005974f0` raw `0x001968eb`, bytes `cc cc cc cc cc`.
- Postpad: `0x0059756e-0x00597570` raw `0x0019696e`, bytes `cc cc`.
- Successor bytes at `0x00597570`: `c7 01 38 e3 62 00 8b c1 c3 cc ...`, disassembling as a TimerHandler vtable store to `0x0062e338`, `mov eax, ecx`, `ret`.
- Target body bytes:

```text
55 8b ec 56 8b f1 8b 46 08 c7 06 c4 e2 62 00 85
c0 74 19 6a 00 50 ff 15 20 d2 60 00 ff 76 08 ff
15 10 d1 60 00 c7 46 08 00 00 00 00 8b 4e 10 85
c9 74 0d 8b 01 6a 01 ff 10 c7 46 10 00 00 00 00
8b ce c7 05 08 be 69 00 00 00 00 00 e8 4f d5 f5
ff 8b 45 08 a8 01 74 1f a8 04 75 10 56 e8 6e d5
f5 ff 83 c4 04 8b c6 5e 5d c2 04 00 6a 14 56 e8
3c 41 e8 ff 83 c4 08 8b c6 5e 5d c2 04 00
```

Target disassembly summary:

```text
0x005974f4  mov esi, ecx
0x005974f6  mov eax, [esi+0x08]
0x005974f9  mov [esi], 0x0062e2c4
0x00597506  call dword ptr [0x0060d220]  ; TerminateThread
0x0059750f  call dword ptr [0x0060d110]  ; CloseHandle
0x00597515  mov [esi+0x08], 0
0x0059751c  mov ecx, [esi+0x10]
0x00597525  push 1
0x00597527  call dword ptr [eax]         ; delete watch-list object
0x00597529  mov [esi+0x10], 0
0x00597532  mov dword ptr [0x0069be08], 0
0x0059753c  call 0x004f4a90              ; LObject destructor body
0x00597541  mov eax, [ebp+8]             ; deleting flags
0x00597544  test al, 1
0x00597548  test al, 4
0x0059754d  call 0x004f4ac0              ; normal delete wrapper
0x0059755c  push 0x14
0x0059755e  push esi
0x0059755f  call 0x0041b6a0              ; flag-4 guard/no-op path
0x0059756b  ret 4
```

Raw non-deleting destructor comparison, `0x00596d20-0x00596d70`:

```text
0x00596d23  mov eax, [esi+0x08]
0x00596d26  mov [esi], 0x0062e2c4
0x00596d33  call dword ptr [0x0060d220]  ; TerminateThread
0x00596d3c  call dword ptr [0x0060d110]  ; CloseHandle
0x00596d42  mov [esi+0x08], 0
0x00596d49  mov ecx, [esi+0x10]
0x00596d52  push 1
0x00596d54  call dword ptr [eax]
0x00596d56  mov [esi+0x10], 0
0x00596d5f  mov dword ptr [0x0069be08], 0
0x00596d6a  jmp 0x004f4a90
```

Pointer and call scan facts:

| Query | Result |
| --- | --- |
| Target VA `0x005974f0` pointer hits | One hit: raw `0x0022ccc4`, VA `.rdata:0x0062e2c4`. |
| Target RVA `0x001974f0` pointer hits | Zero. |
| Target raw offset `0x001968f0` pointer hits | Zero. |
| `.text` rel32 calls/jumps to `0x005974f0` | Zero. |
| `ThreadMan` vtable immediate `0x0062e2c4` hits | `0x00596c4f` constructor, `0x00596d28` raw destructor, `0x005974fb` scalar wrapper. |
| `g_pThreadMan` immediate `0x0069be08` hits | `0x00596c34`, `0x00596c3c`, `0x00596d61`, `0x005974e2`, `0x00597534`. |
| Constructor `0x00596bf0` VA pointer/rel32 hits | Zero pointer hits, zero rel32 hits. |
| Worker entry `0x00597100` VA pointer/rel32 hits | One pointer/immediate hit at `0x00596cb1`, zero rel32 hits. |
| Worker loop `0x00596e10` rel32 hits | One direct call at `0x00597140` from worker entry. |
| Clear singleton `0x005974e0` rel32 hits | One direct jump at `0x00609ace` from constructor cleanup/EH region. |
| Raw destructor/message-wrapper starts | Zero VA pointer hits and zero rel32 hits for `0x00596d20`, `0x00596d70`, `0x00596d90`, `0x00596db0`, `0x00596dd0`, and `0x00596df0`. |
| Watch helper starts | Zero VA pointer hits and zero rel32 hits for representative starts `0x005971b0`, `0x005971f0`, `0x00597230`, `0x00597360`, and `0x00597490`. |

Import-table facts:

| IAT | Import |
| --- | --- |
| `0x0060d110` | `KERNEL32.dll!CloseHandle` |
| `0x0060d13c` | `KERNEL32.dll!GetCurrentThreadId` |
| `0x0060d220` | `KERNEL32.dll!TerminateThread` |
| `0x0060d234` | `KERNEL32.dll!CreateThread` |
| `0x0060d238` | `KERNEL32.dll!FatalAppExitW` |
| `0x0060d254` | `KERNEL32.dll!LoadLibraryW` |
| `0x0060d298` | `KERNEL32.dll!IsDebuggerPresent` |
| `0x0060d378` | `USER32.dll!PostThreadMessageW` |
| `0x0060d380` | `USER32.dll!PeekMessageW` |
| `0x0060d468` | `USER32.dll!MsgWaitForMultipleObjects` |
| `0x0060d50c` | `WINMM.dll!timeGetTime` |

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct owner state | Score state | B008 status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00596bf0-0x00596d13` | [UID:0001K0] `ThreadManConstructor` | `ThreadMan::ThreadMan()` constructor; publishes singleton, vtable, debugger probe, watch list, worker thread. | TRUE | currently [UID:0000OR], semantic [UID:0000EW] | `88/86` | Supports field names and source route; no direct ctor caller remains broader singleton question. |
| `0x00596d20-0x00596e0b` | [UID:0001K1] `ThreadManRawMessageWrappers` | Raw ordinary destructor plus five retained message-posting wrappers. | TRUE | currently [UID:0000OR], semantic [UID:0000EW] | `88/86` | Contains ordinary destructor source-shape evidence at `0x00596d20-0x00596d6f`; optional future split could isolate destructor C++. |
| `0x00596e10-0x005970df` | [UID:0001K2] `ThreadManWorkerLoop` | Worker message pump/watchdog loop. | TRUE | currently [UID:0000OR], semantic [UID:0000EW] | `88/86` | Supports `m_workerThreadId`, `m_watchList`, and record semantics. |
| `0x00597100-0x005971ad` | [UID:0001K3] `ThreadManWorkerEntry` | `CreateThread` entry; calls worker loop. | TRUE | [UID:0000OR] is still plausible direct file owner | `88/87` | Constructor pointer at `0x00596cb1`; file-static entry remains best source spelling. |
| `0x005971b0-0x005974da` | [UID:0003V7] `ThreadManWatchListRawHelpers` | Raw watch-list helper island. | TRUE | currently [UID:0000OR], semantic [UID:0000EW] | `86/87` | No direct route; supports list/record field semantics but does not block [UID:0001K5]. |
| `0x005974e0-0x005974eb` | [UID:0001K4] `ClearThreadManSingleton` | Compiler/EH singleton clear thunk. | FALSE | NONE | `88/92` | Do not model as source helper; destructor source should clear singleton. |
| `0x005974f0-0x0059756e` | [UID:0001K5] target | Scalar deleting destructor wrapper. | TRUE | recommend [UID:0000EW] | recommend `86/91` | Exact target; formal C++ should remain blank. |
| `0x0062e2c4` | inside [UID:00026P] `ThreadReadOnlyData` | `ThreadMan` vtable first slot points to target. | source-declared/generated-binary | [UID:0000OR] aggregate with [UID:0000EW] sub-owner | `87/91` | Pointer scan found target only here. |
| `0x0069be08` | [UID:0000SH] / [UID:000305] `g_pThreadMan` | Global ThreadMan singleton pointer. | TRUE | [UID:0000OR] | global `86/88` | Cleared by raw destructor and scalar wrapper; constructor publishes it. |

## Ranked Ownership Analysis

### 1. [UID:0000EW] `ThreadMan` Class

- Evidence for: target is vtable-reachable through `ThreadMan` vtable slot `0x0062e2c4`; constructor/raw destructor/target all install or restore this vtable; target tears down fields that belong to `ThreadMan`; target clears the `ThreadMan` singleton; class page is already `86/85` and routes to `Thread.cpp`.
- Evidence against: existing target and many sibling method pages are still directly file-owned by [UID:0000OR]. That is legacy/staging ownership and not a direct semantic owner under current `by-structure.md`.
- Decision: accept as direct owner/emitter. Set `CANONICAL_OWNER:0000EW` and `EMITTER_UIDS:0000EW`.

### 2. [UID:0000OR] `Thread` File

- Evidence for: `Thread.cpp` is still the correct source root; proposed source tree places `Thread.cpp` under `NexusTK/util/`; by-file doc owns the Thread/ThreadMan source island; generated output path is `auto-generated/NexusTK/util/Thread.cpp`.
- Evidence against: the target is not a free function or file-level helper. Direct ownership by the file bypasses a valid class owner.
- Decision: keep as indirect source route only. Do not keep as direct owner/emitter for [UID:0001K5] after support update.

### 3. `CANONICAL_OWNER:NONE` / Non-Emitting / Ignored

- Evidence for: exact wrapper bytes are compiler-generated and should not be written as source code.
- Evidence against: vtable slot and source class declaration must regenerate the wrapper. It is not padding, not runtime-library code, and not dead. The cleanup semantics come from the source `ThreadMan` destructor.
- Decision: reject. Keep `RECONSTRUCTABLE:TRUE` with class route and blank formal C++.

### 4. Separate `ThreadMan.cpp`

- Evidence for: a one-class file is plausible in a different codebase.
- Evidence against: current by-file docs, proposed source tree, memory locality, read-only data, `g_pThreadMan`, and generated route all support `NexusTK/util/Thread.cpp`; no independent source-file evidence supports a separate `ThreadMan.cpp`.
- Decision: reject for this implementation. Mention only as a rejected alternative in support docs if source-placement caveats are updated.

## First-Draft C++ / No-Code Recommendation

Do not populate [UID:0001K5]'s formal `RECONSTRUCTION_CPP CODE` block. The target's exact range is compiler-generated scalar deleting destructor wrapper glue, and source C++ should not contain a source-visible method with a deleting-flags parameter.

Target-specific no-code proof to add:

```text
This page documents the MSVC scalar deleting destructor wrapper generated for `ThreadMan::~ThreadMan()`. The source project should define the ordinary `ThreadMan` destructor and class declaration; the compiler will regenerate this vtable slot, the deleting-flag tests, the optional storage-release call, and the flag-4 guard/no-op path. Do not hand-author C++ for this exact range.
```

Source-level destructor draft that should be carried into [UID:0000EW] `ThreadMan` support docs and into a future [UID:0001K1] destructor split if the supervisor chooses to emit ordinary destructor C++:

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

Draft constraints:

- Do not include vtable writes.
- Do not explicitly call `LObject::~LObject()`; base destruction is implicit.
- Do not include scalar deleting `flags`, `OperatorDeleteWrapper`, or `0x0041b6a0`.
- Keep `TerminateThread`/`CloseHandle` despite modern style concerns; that is the exact binary behavior.
- Use `List *m_watchList` unless a future header audit proves a stronger concrete list typedef.

## Exact Recommended Target Changes

Target path: `source-3/project-documentation/by-memory/0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md`

Recommended metadata:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000EW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000EW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended target content updates:

- Replace the status text that says C++ is blank because of a `95+` final-source gate. Use target-specific no-code proof: exact range is scalar deleting destructor wrapper glue; ordinary destructor source belongs to `ThreadMan::~ThreadMan()` source shape, not to this wrapper page.
- Add "source-declared/generated-binary" wording: the page is reconstructable because the class declaration/destructor source must cause the wrapper to exist, but no handwritten function body should be emitted for this range.
- Add exact raw PE facts from this report: PE hash, raw offset `0x001968f0`, size `0x7e`, prepad/postpad bytes, target bytes or summarized byte table, disassembly highlights, import identities, pointer scan, no direct caller scan, and successor TimerHandler boundary.
- Replace anonymous field names with best source-facing names:
  - `this+0x08` = `HANDLE m_workerThreadHandle`.
  - `this+0x10` = `List *m_watchList`, holding 20-byte `ThreadManWatchRecord` records.
  - `g_pThreadMan` = `static ThreadMan *g_pThreadMan` in `util/Thread.cpp` (static linkage still inferred).
- Add relationship to [UID:0001K1]: raw non-deleting destructor `0x00596d20-0x00596d6f` is the best source-shape evidence for `ThreadMan::~ThreadMan()` and duplicates the target cleanup without deleting flags.
- Add explicit rejected alternatives: file direct owner, no-owner/non-emitting/dead code, handwritten scalar deleting destructor source, explicit base destructor source call, source `ClearThreadManSingleton()` helper, TimerHandler merge, and source-sized delete for the flag-4 path.
- Add `2026-06-19 B008 source-quality pass` change entry with before/after score `84/88 -> 86/91`, owner/emitter `0000OR -> 0000EW`, exact boundary/bytes/xrefs/field/source-shape evidence, and target-specific blank-C++ policy.

## Exact Recommended Support Doc Changes

### [UID:0000EW] `by-class/ThreadMan.md`

- Add a destructor policy section saying [UID:0001K5] is class-owned MSVC scalar deleting destructor wrapper glue reached through vtable `0x0062e2c4`, and the class declaration should surface only `virtual ~ThreadMan();`.
- Carry source destructor draft or prose:
  - terminate/close `m_workerThreadHandle`;
  - delete/null `m_watchList`;
  - clear `g_pThreadMan`;
  - rely on implicit `LObject` base cleanup.
- Add field names with confidence:
  - `bool m_isDebuggerPresent` at `+0x04`;
  - `HANDLE m_workerThreadHandle` at `+0x08`;
  - `DWORD m_workerThreadId` at `+0x0c`;
  - `List *m_watchList` at `+0x10`.
- Replace old "95/95" C++ blocker wording with active-gate policy: class page should eventually emit class declaration/API inventory, while [UID:0001K5] remains no-code because it is generated wrapper glue.
- If supervisor also accepts the B003 class report, raise class metadata to `88/89` and add the B003 class declaration. If this callback is limited to [UID:0001K5], do not force the class score change, but do add the destructor/wrapper policy needed by this target.

### [UID:0000OR] `by-file/Thread.md`

- Add that [UID:0001K5] is now best treated as class-owned `ThreadMan` wrapper routed through [UID:0000EW], while `Thread.cpp` remains the source root.
- Preserve `NexusTK/util/Thread.cpp` placement and rejected `ThreadMan.cpp` split. Mention no separate file evidence was found.
- Note that blank C++ for [UID:0001K5] is target-specific wrapper policy, not stale old-gate wording.

### [UID:0001WA] `by-type/by-struct/ThreadManLayout.md`

- Update field names to source-facing `m_isDebuggerPresent`, `m_workerThreadHandle`, `m_workerThreadId`, and `m_watchList`, or add them beside existing unprefixed names as the current best descriptive spelling.
- Add B008 destructor-facing evidence:
  - scalar wrapper and raw destructor both use `+0x08` as Win32 handle and `+0x10` as heap `List *`;
  - object size `0x14` appears in scalar deleting flag-4 path;
  - `m_` prefix is inferred/descriptive, not original-proof.
- Remove/replace any old wording that final field names are an unresolved blocker for [UID:0001K5]'s no-code policy. They remain a class/header final-audit caveat only.

### [UID:0001WB] `by-type/by-struct/ThreadManWatchRecord.md`

- Add a cross-note that [UID:0001K5] deletes the heap `List` containing these 20-byte records via the list object's vtable, not via record-level cleanup.
- Prefer or at least document `watchedThreadId` for record `+0x08` because ThreadMan itself has `m_workerThreadId` at object `+0x0c`. This reduces ambiguity when source names are entered later.

### [UID:0001K1] `by-memory/0x00596d20-0x00596e0b.ThreadManRawMessageWrappers.md`

- Add that B008 local PE disassembly reconfirmed the raw non-deleting destructor body at `0x00596d20-0x00596d6f`: vtable restore, worker handle terminate/close/clear, watch-list delete/null, `g_pThreadMan = NULL`, and tail jump to `LObject` destructor body.
- State this raw body is the best evidence for ordinary `ThreadMan::~ThreadMan()` source shape.
- Add optional future split recommendation: split `0x00596d20-0x00596d6f` into a dedicated ordinary-destructor page if the project wants formal destructor-body C++ in by-memory output. This split is not required for [UID:0001K5].
- If support child routing is accepted, change direct owner/emitter from [UID:0000OR] to [UID:0000EW] for the class method parts, while keeping source root through `Thread.cpp`.

### [UID:0001K0] `by-memory/0x00596bf0-0x00596d13.ThreadManConstructor.md`

- Add cross-note that B008 pointer scan again found no direct constructor caller, so constructor/static singleton route remains broader open work, but this does not block scalar destructor wrapper ownership.
- Add cross-note that constructor publishes `g_pThreadMan`, installs `ThreadMan` vtable, stores `m_workerThreadHandle`, passes `&m_workerThreadId`, and stores `m_watchList`; those names should be synchronized with `ThreadManLayout`.
- If support child routing is accepted, change direct owner/emitter from [UID:0000OR] to [UID:0000EW] for this class method.

### [UID:0001K2] `by-memory/0x00596e10-0x005970df.ThreadManWorkerLoop.md`

- Add support note that B008 confirmed worker loop direct call from worker entry at `0x00597140`; this preserves constructor/entry/loop route.
- Synchronize field names: `m_isDebuggerPresent`, `m_workerThreadId`, `m_watchList`, and `ThreadManWatchRecord::watchedThreadId`.
- If support child routing is accepted, change direct owner/emitter from [UID:0000OR] to [UID:0000EW].

### [UID:0003V7] `by-memory/0x005971b0-0x005974da.ThreadManWatchListRawHelpers.md`

- Add support note that B008 found zero pointer and rel32 hits for representative raw helper starts, matching B001's no-route evidence.
- State this does not block [UID:0001K5] because scalar destructor uses only the `m_watchList` object pointer and not these helper entry points.
- If support child routing is accepted, change semantic direct owner/emitter to [UID:0000EW] while preserving no-direct-route caveat and source root through `Thread.cpp`.

### [UID:0001K4] `by-memory/0x005974e0-0x005974eb.ClearThreadManSingleton.md`

- Add a cross-note that B008 rel32 scan found one jump to `0x005974e0` from `0x00609ace`, consistent with constructor cleanup/EH, while normal destructor clears happen in [UID:0001K1] and [UID:0001K5].
- Preserve `RECONSTRUCTABLE:FALSE`, blank owner/emitter, and no C++.

### [UID:0000SH] `by-global/g_pThreadMan.md`

- Add that ordinary `ThreadMan::~ThreadMan()` source should clear `g_pThreadMan = NULL`; [UID:0001K4] is constructor-unwind cleanup glue; [UID:0001K1] and [UID:0001K5] are destructor clear sites.
- Keep `static ThreadMan *g_pThreadMan;` as likely declaration; mark `static` as inferred pending final linkage audit.

### [UID:00026P] `by-memory/0x0062e268-0x0062e334.ThreadReadOnlyData.md`

- Add B008 pointer-scan fact: target VA `0x005974f0` appears only at `.rdata:0x0062e2c4`, with zero target RVA/raw-offset pointer hits and zero `.text` rel32 callers.
- Interpret `0x0062e2c4` as the ThreadMan vtable slot for the scalar deleting destructor wrapper generated from the class declaration/destructor.

### [UID:0001JX] `by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md`

- Update [UID:0001K5] child-status wording to "class-owned generated scalar deleting destructor wrapper around ordinary destructor/delete policy; formal C++ blank by target-specific no-code proof."
- Replace old "90/90+" or stale "final C++ gate" wording as needed with active gate plus target-specific no-code reasoning.
- If child routing support is accepted, document that class member children should move to [UID:0000EW] while this aggregate remains file-owned `Thread.cpp`.

### Read-only/vtable/global support docs

- [UID:000305] `by-memory/0x0069be08-0x0069be0c.g_pThreadMan.md`: add that scalar wrapper clear is one of the five immediate uses, but source declaration remains global/file-owned.
- [UID:000195] / exact [UID:000370] `LObjectDestructorBody`: no required score change; cross-reference target as one of many derived destructor base-cleanup callers if support docs are already being touched.
- [UID:000197] `OperatorDeleteWrapper`: no required score change; cross-reference target as a representative scalar deleting destructor caller with normal `(flags & 1) && !(flags & 4)` path if implementation scope allows.
- Timer neighbor docs: no score change; if target boundary text is updated, preserve that `0x00597570` is TimerHandler/TimerMgr successor, not ThreadMan.

## Score / Metadata Recommendation

- Target before: `84/88`, direct owner/emitter [UID:0000OR], blank C++.
- Target after: `86/91`, direct owner/emitter [UID:0000EW], blank C++.
- Completion rationale: raise to `86` because B008 rechecked exact bytes, raw offset, padding, import names, disassembly, field cleanup sequence, flag paths, vtable-only reachability, raw ordinary-destructor parity, singleton/base cleanup relation, owner/emitter route, and target-specific no-code proof. Keep below higher final levels because this page should not emit source C++, live MCP was unavailable, and exact original member spelling is inferred.
- Confidence rationale: raise to `91` because fresh local PE facts and existing IDA-backed docs strongly agree. Cap below `95+` because final original field spelling, singleton construction route, and optional raw destructor split remain outside this exact target.
- Reconstructability: keep `TRUE`. This is source-declared/generated-binary wrapper support that must be regenerated by class source, not ignored padding/runtime code.

## Exact Pending Coverage Text

Do not edit `source-3/project-documentation/by-memory/-coverage-report.md` as B008. Supervisor-owned replacement for the existing [UID:0001K5] row, placed between the [UID:0001K4] `ClearThreadManSingleton` row and the ignored `0x0059756e-0x00597570` padding row:

```markdown
    - [UID:0001K5][0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor](by-memory/0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md) 0x005974f0-0x0059756e | compiler-generated destructor wrapper | ThreadManScalarDeletingDestructor : reconstructable : 86% : very strong : B008 2026-06-19 source-quality recheck classifies this as the MSVC scalar deleting destructor wrapper generated from source-level `ThreadMan::~ThreadMan`; local PE/Capstone evidence confirms exact `0x7e` / 126-byte body at raw `0x001968f0`, five-byte prepad `0x005974eb-0x005974f0`, two-byte postpad `0x0059756e-0x00597570`, successor `0x00597570` TimerHandler boundary, ThreadMan vtable restore at `0x005974f9`, `m_workerThreadHandle` termination/close/clear at `+0x08`, `m_watchList` delete/null at `+0x10`, `g_pThreadMan` clear at `0x00597532`, `LObject` base cleanup call at `0x0059753c`, `OperatorDeleteWrapper` only for `(flags & 1) != 0 && (flags & 4) == 0`, flag-4 guard/no-op path through `0x0041b6a0` after pushing `this` and `0x14` / 20-byte object size, target VA pointer hit only in the ThreadMan vtable slot `.rdata:0x0062e2c4`, zero target RVA/raw-offset hits, zero `.text` rel32 direct callers, direct class owner/emitter route through [UID:0000EW][ThreadMan](by-class/ThreadMan.md) into [UID:0000OR][Thread](by-file/Thread.md), raw ordinary-destructor parity at `0x00596d20-0x00596d6f`, and formal target C++ should remain blank because source should express ordinary `ThreadMan` destructor semantics and let MSVC regenerate the wrapper.
```

## Validation Commands Needed After Implementation

Report-only pass: no validators were run because no by-* docs were edited.

When a supervisor implementation callback is accepted, lease edited target/support docs first. Then run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0001K5-ThreadManScalarDeletingDestructor-source-quality-removed.md](0001K5-ThreadManScalarDeletingDestructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If support changes include exact storage or aggregate pages, also validate:

> Executable block R002 was removed from this report and preserved verbatim in [0001K5-ThreadManScalarDeletingDestructor-source-quality-removed.md](0001K5-ThreadManScalarDeletingDestructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## IDA Rename / Type / Comment Recommendations

- `0x005974f0`: rename/comment as `ThreadMan__scalar_deleting_destructor`; type as `void *__thiscall ThreadMan_scalar_deleting_destructor(ThreadMan *this, unsigned int flags)` only as a binary ABI wrapper type, not as source C++. Confidence high for role.
- `0x00596d20`: add comment or raw function candidate `ThreadMan__dtor` / `ThreadMan_non_deleting_destructor` if IDA function creation policy allows raw starts. Confidence high for role, medium for function-object policy because IDA currently has no function object there.
- `0x0062e2c4`: label as `ThreadMan_vftable` / scalar deleting destructor slot. Confidence high.
- `0x0069be08`: label/type as `ThreadMan *g_pThreadMan`; confidence high for type, medium-high for `static` linkage.
- `ThreadMan` class/struct fields:
  - `+0x04`: `bool m_isDebuggerPresent`; confidence high.
  - `+0x08`: `HANDLE m_workerThreadHandle`; confidence high.
  - `+0x0c`: `DWORD m_workerThreadId`; confidence high.
  - `+0x10`: `List *m_watchList`; confidence high for role, medium-high for exact original spelling.
- `ThreadManWatchRecord +0x08`: prefer `watchedThreadId`; confidence high for thread-id role through `Thread + 0x60`, medium-high for exact original spelling.
- `0x004f4a90`: keep/comment as `LObjectDestructorBody` / non-deleting base cleanup; confidence high from support docs.
- `0x004f4ac0`: keep/comment as `OperatorDeleteWrapper` / MemoryMan-backed global delete wrapper; confidence high.
- `0x0041b6a0`: comment as MSVC guard/no-op helper used by flag-4 deleting destructor paths; confidence high for wrapper role, not NexusTK source.
- Do not create source-visible IDA names for [UID:0001K4] as `ThreadMan::ClearSingleton`; use cleanup/EH comment only.

## Rejected Alternatives And Negative Evidence

- Handwritten `ThreadMan::scalar_deleting_destructor(unsigned int flags)`: rejected because flags/delete/guard structure is MSVC wrapper ABI, vtable-only reachable, and not source-called.
- Direct file owner [UID:0000OR]: rejected as direct owner because current rules prefer the narrow class owner; retained as indirect source root.
- `CANONICAL_OWNER:NONE` or ignored/non-reconstructable: rejected because vtable slot and source destructor declaration must regenerate this wrapper.
- TimerHandler merge: rejected by two-byte postpad and successor vtable store at `0x00597570` to `0x0062e338`.
- Source `ClearThreadManSingleton()` helper: rejected because `0x005974e0` has only constructor-cleanup jump route and normal destructor clear sites already exist.
- Explicit source `LObject::~LObject()` call: rejected because base cleanup is compiler-emitted after derived destructor.
- Source `operator delete` in `ThreadMan::~ThreadMan()`: rejected because storage release is scalar deleting wrapper behavior only under deleting flags.
- Treating `m_watchList` as an inline container or array: rejected because destructor deletes a heap object through its vtable at `this+0x10`.
- Treating missing constructor direct calls as a blocker for [UID:0001K5]: rejected because target is vtable-reachable and class/source route is clear; constructor route remains separate singleton startup research.

## Open Questions With Attempted Resolution

- Exact original destructor spelling: best answer is `ThreadMan::~ThreadMan()`. Evidence is vtable wrapper and raw non-deleting destructor parity. Original header formatting/access specifier is not proven, but not needed for target wrapper no-code policy.
- Exact member prefixes: `m_workerThreadHandle`, `m_workerThreadId`, and `m_watchList` are descriptive best-supported names. Existing docs use unprefixed names. This should not block target score/ownership; it only caps final-source confidence.
- Constructor/static singleton construction path: still no direct constructor caller or constructor pointer hit was found in the PE scan. This remains a class/file startup question, not a target blocker.
- Raw ordinary destructor formal C++ placement: safest future path is to split `0x00596d20-0x00596d6f` from [UID:0001K1] if the project wants a by-memory formal destructor body. Until then, target [UID:0001K5] should remain blank C++ and class docs can carry the ordinary destructor draft.
- Live IDA MCP availability: unavailable/timed out during B008. Existing docs contain multiple prior live IDA checks, and fresh PE/Capstone checks confirmed the target-specific claims. This caps confidence below final-audit but does not change the recommendation.

## Implementation Checklist For Supervisor Callback

1. Lease target and support docs before editing. Do not edit `by-memory/-coverage-report.md`; use the exact pending row from this report.
2. Update [UID:0001K5] target metadata to `86/91`, `CANONICAL_OWNER:0000EW`, `EMITTER_UIDS:0000EW`, keep `RECONSTRUCTABLE:TRUE`, keep formal C++ blank.
3. Replace stale `95+` no-code language with target-specific wrapper/no-code proof.
4. Add B008 raw PE evidence, disassembly, pointer-scan facts, field names, relation to raw non-deleting destructor, flag-path explanation, and rejected alternatives to the target doc at report-level detail.
5. Update support docs listed above, especially `ThreadMan.md`, `ThreadManLayout.md`, `ThreadManRawMessageWrappers.md`, `g_pThreadMan.md`, and `ThreadReadOnlyData.md`.
6. If supervisor accepts broader ThreadMan class routing, change class-method child owners/emitters to [UID:0000EW] for [UID:0001K0], [UID:0001K1], [UID:0001K2], [UID:0003V7], and [UID:0001K5]. Keep [UID:0001K3] file-owned unless a separate callback chooses static-member routing.
7. Run scoped validators for every edited file using the commands above.
8. Record exact validation results, changed files, before/after scores, and pending supervisor-owned coverage row in B008 notes or implementation response.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B008/research/0001K5-ThreadManScalarDeletingDestructor-source-quality.md`
- Modified: none outside B008 research.
- Moved to executed: none.

## Validation Results

- Report-only pass; no by-* docs edited, so no validator command was run.
- Live IDA MCP attempt: `URLError: <urlopen error timed out>` for `http://127.0.0.1:13337/mcp`.
- Local PE/Capstone scripts run read-only against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` for target bytes, padding, disassembly, pointer hits, rel32 hits, import names, and raw destructor comparison.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/0001K5-ThreadManScalarDeletingDestructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:33","uid":"0001K5"} -->
<!-- {"agent":"B008","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001K5-ThreadManScalarDeletingDestructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B008/0001K5-ThreadManScalarDeletingDestructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001K5"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
