** TARGET-REPORT-UID:0001K5 **
** AUTHOR-AGENT-ID:B012 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001K5 ThreadManScalarDeletingDestructor Source-Quality Research

Status: FINISHED

Agent: B012

Target: [UID:0001K5] `source-3/project-documentation/by-memory/0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md`

Report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B012/research/0001K5-ThreadManScalarDeletingDestructor-source-quality.md`

Report-only compliance: no `by-*` documentation file was edited, and `source-3/project-documentation/by-memory/-coverage-report.md` was not edited.

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0001K5] reconstructable, but classify `0x005974f0-0x0059756e` as the MSVC scalar deleting destructor wrapper generated from the source-level ordinary destructor `ThreadMan::~ThreadMan()`. The exact target range should not receive formal handwritten C++.
- Final disposition: class-owned generated-binary destructor wrapper. The direct semantic owner/emitter should be [UID:0000EW] `ThreadMan`; [UID:0000OR] `Thread` / `NexusTK/util/Thread.cpp` remains the source-file root reached through the class page.
- Required action for later implementation: update target metadata from `84/88` to `86/91`, change `CANONICAL_OWNER:0000EW`, change `EMITTER_UIDS:0000EW`, keep `RECONSTRUCTABLE:TRUE`, keep the formal `RECONSTRUCTION_CPP CODE` block blank, and replace stale "95+" / "wait for final source gate" wording with a target-specific no-code proof.
- Confidence: high for exact bytes, range, padding, vtable-only reachability, no ordinary direct callers, worker handle/list cleanup, singleton clear, base cleanup, delete-flag path, guard path, and `Thread.cpp` source placement. Confidence remains below final-audit because exact original member prefixes and singleton construction route remain inferred or broader class-level questions.

## Target

- Target UID: `0001K5`
- Target path: `source-3/project-documentation/by-memory/0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md`
- Current target metadata checked from the target doc: `COMPLETION:84`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000OR`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OR`, blank formal C++.
- Recommended target metadata: `COMPLETION:86`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000EW`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000EW`, blank formal C++.
- Current coverage row checked in `by-memory/-coverage-report.md`: [UID:0001K5] is listed at `84%`, kind `scalar deleting destructor`, attached to `Thread.cpp`, with exact `0x7e` range, vtable-slot xref, no direct callers, worker-handle/list cleanup, `g_pThreadMan` clear, `LObject` cleanup, MemoryMan delete-wrapper flag path, and guard/no-op flag-4 branch.
- Required coverage action: supervisor-owned replacement row only. B012 did not edit coverage.

## Supervisor Active Recheck

- This is the B012 report-only pass requested for [UID:0001K5] `ThreadManScalarDeletingDestructor`.
- The current assignment required source-level destructor-shape review, field/global/helper/type naming, vtable reachability, no-direct-caller recheck, callee list, boundary padding, adjacent TimerMgr separation, `Thread.cpp` ownership, support-doc checklist, no-code or first-draft C++ decision, exact coverage row text, and validator baseline.
- Split decision: no split is needed for [UID:0001K5]. The target is one exact function-like wrapper body from `0x005974f0` through `0x0059756d`, half-open end `0x0059756e`.
- Boundary decision: keep `0x005974eb-0x005974f0` as five bytes of `0xcc` padding after [UID:0001K4] `ClearThreadManSingleton`; keep `0x0059756e-0x00597570` as two bytes of `0xcc` padding before the TimerHandler/TimerMgr successor at `0x00597570`. Do not merge the successor into ThreadMan.

## Inference Research Guidance Check

- `by-structure.md` current rule: direct `CANONICAL_OWNER` should be the narrowest true semantic owner, not merely the final `.cpp` route. Because [UID:0001K5] is a `ThreadMan` destructor wrapper and [UID:0000EW] `ThreadMan` clears the `85/85` gate, class ownership is preferred.
- `by-structure.md` C++ rule: formal C++ may be entered only when the item is reconstructable, has a nonblank emitter route to generated source, and the average score exceeds `85`, but that is a minimum eligibility gate. The code must represent the source for the page's exact range. This target's exact range is generated destructor-wrapper glue, not a handwritten source method.
- `inference_research.md` guidance applied: hard facts are raw bytes, xrefs, imports, disassembly, pointer hits, current docs, and validator output. Inferences are explicitly marked for original member naming, source file/header spelling, and raw helper liveness.
- Existing docs and prior B reports were treated as leads, not authority. B012 independently rechecked the target bytes, disassembly, pointer hits, rel32 call/jump hits, import names, raw ordinary destructor parity, and nearby boundary bytes from the PE.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Best-supported conclusion | Rejected alternatives / remaining effect |
| --- | --- | --- | --- |
| Generated name / function role for `sub_5974F0` | Target body uses `this` in `ecx`, saves it in `esi`, reads deleting flags from `[ebp+8]`, tests `flags & 1`, tests `flags & 4`, conditionally calls [UID:000197] `OperatorDeleteWrapper`, and is pointed to by `.rdata:0x0062e2c4`. Local PE scan found no `.text` rel32 direct callers. | Source-facing binary role: `ThreadMan` MSVC scalar deleting destructor wrapper. IDA/comment name can be `ThreadMan__scalar_deleting_destructor` or MSVC-style ``ThreadMan::`scalar deleting destructor'``. | Reject treating it as an original source method such as `ThreadMan::ScalarDeletingDestructor(unsigned int)`. The deleting-flags parameter and optional storage-release branch are ABI/compiler glue. |
| Source-authored destructor shape | Raw ordinary destructor bytes at `0x00596d20-0x00596d6f` perform the same worker-handle cleanup, watch-list delete, singleton clear, and tail jump to `LObject` cleanup, without deleting flags or storage release. Target duplicates that body then applies scalar deleting destructor policy. | Source destructor is ordinary `ThreadMan::~ThreadMan()`: terminate/close `m_workerThreadHandle`, delete/null `m_watchList`, clear `g_pThreadMan`, then implicit base destructor cleanup. | Reject empty destructor. Reject explicit source vtable writes, explicit `LObjectDestructorBody(this)`, explicit scalar flags handling, and source-level `OperatorDeleteWrapper` call in `ThreadMan::~ThreadMan()`. |
| First-draft C++ eligibility | Recommended target would have `86/91` and nonblank emitter via class, but the exact range is a wrapper. Current `by-structure.md` limits a by-memory C++ block to source represented by that exact range. | Formal C++ for [UID:0001K5] should stay blank with target-specific no-code proof. Source destructor draft should be carried in [UID:0000EW] `ThreadMan.md` support notes or a future split raw ordinary destructor page, not in [UID:0001K5]. | Reject adding pseudo-C++ for a wrapper with `flags`. Reject using old `95+` wording as the reason; the reason is source-shape mismatch, not score gate. |
| `this+0x08` field | Constructor [UID:0001K0] stores the `CreateThread` handle at `+0x08`; target and raw destructor load `+0x08`, pass it to `TerminateThread(handle, 0)`, pass it again to `CloseHandle`, and clear `+0x08`. B012 import parse confirms `0x0060d220 = KERNEL32.dll!TerminateThread` and `0x0060d110 = KERNEL32.dll!CloseHandle`. | Best source-facing name/type: `HANDLE m_workerThreadHandle` at `ThreadMan +0x08`. Existing unprefixed `workerThreadHandle` in [UID:0001WA] remains acceptable as layout table wording. | Reject generic `thread`, `worker`, or pointer-to-Thread type. This is a Win32 `HANDLE` value. Exact original `m_` prefix is inferred, not proven. |
| `this+0x0c` related field | Constructor passes `this+0x0c` as the `CreateThread` thread-id output pointer; message wrappers use it as the target thread id for `PostThreadMessageW`. Target does not read it directly. | Best source-facing name/type: `DWORD m_workerThreadId` at `ThreadMan +0x0c`. Include in support docs to avoid confusing it with per-record watched thread ids. | Not a direct target field, but leaving it anonymous keeps class/layout docs weaker. Exact original name remains inferred. |
| `this+0x10` field | Constructor allocates/stores a `List(20, 16)` at `+0x10`; worker loop/watch helpers use the list; target and raw destructor read pointer at `+0x10`, call the first virtual slot with deleting flag `1`, and clear the pointer. | Best source-facing name/type: `List *m_watchList` at `ThreadMan +0x10`, containing 20-byte `ThreadManWatchRecord` entries. | Reject inline array, raw buffer, or `std::list` ownership. The destructor deletes a heap object through a vtable pointer, not records individually. |
| `ThreadManWatchRecord` relationship | [UID:0001WB] documents a 0x14-byte record. [UID:0001K0] creates `List(20,16)`. Worker docs show record `+0x08` comes from `Thread +0x60`; B003 class pass argues for `watchedThreadId`. [UID:0001K5] only deletes the list object, not records directly. | Support docs should cross-link [UID:0001K5] as deleting the watch list object that owns `ThreadManWatchRecord` slots. Prefer `watchedThreadId` for record `+0x08`, `probePending`/`watchdogPending` for `+0x0c`, and `deadlineTick` for `+0x10`. | Reject claiming [UID:0001K5] performs record-level cleanup. It invokes the list object's deleting destructor. |
| `g_pThreadMan` | Local PE immediate scan found `0x0069be08` at constructor writes `0x00596c34/0x00596c3c`, raw destructor clear `0x00596d61`, singleton clear helper `0x005974e2`, and target clear `0x00597534`. Existing global/storage docs identify [UID:0000SH]/[UID:000305]. | Best source-facing declaration remains `static ThreadMan *g_pThreadMan;` in `util/Thread.cpp`; ordinary destructor clears it. `static` is high-probability but still an inferred linkage spelling. | Reject a source helper named `ClearThreadManSingleton()` for normal lifetime. [UID:0001K4] is constructor-unwind cleanup glue; normal destructor clears are [UID:0001K1] and [UID:0001K5]. |
| ThreadMan vtable data | Local PE reads `0x0062e2c0 -> 0x00651650` RTTI/COL pointer, `0x0062e2c4 -> 0x005974f0`, `0x0062e2c8 -> 0x004f4b10`, `0x0062e2cc -> 0x0041b6c0`; `0x0062e2d0` begins UTF-16 `KERNEL32.DLL` bytes. Immediate scan for `0x0062e2c4` finds constructor store `0x00596c4f`, raw destructor restore `0x00596d28`, and target restore `0x005974fb`. | `0x0062e2c4` is the ThreadMan vtable first slot and only target pointer hit. `0x0062e2d0` is the adjacent `KERNEL32.DLL` literal, not a vtable slot. | Reject treating `.rdata:0x0062e2d0` and `0x0062e2d4` as functions `0x0045004b`/`0x004e0052`; they are UTF-16 literal dwords. |
| `LObject` base cleanup | Target calls `0x004f4a90`; raw ordinary destructor tail-jumps there. [UID:000370] documents `0x004f4a90-0x004f4a97` as non-deleting `LObject` base destructor body. | Source-level `ThreadMan::~ThreadMan()` relies on implicit base destructor invocation. Target doc should identify the call as compiler-emitted base cleanup after derived cleanup. | Reject decompiler-shaped source `LObjectDestructorBody(this);` in the destructor body. |
| `OperatorDeleteWrapper` | Target calls `0x004f4ac0` only after `flags & 1` is true and `flags & 4` is false. [UID:000197] documents it as MemoryMan-backed global delete wrapper via `GetMemoryMan` and `FreeBufferMemory`. | `0x004f4ac0` is scalar deleting destructor storage release, not `ThreadMan` source logic. | Reject adding `operator delete(this)` to `ThreadMan::~ThreadMan()`. Storage release belongs to compiler-generated deleting wrapper. |
| Guard flag path / `0x0041b6a0` | Target branch at `0x0059755c-0x00597564` pushes `0x14` and `this`, calls `0x0041b6a0`, adds `esp,8`, returns `this`. B012 disassembly of `0x0041b6a0` shows a one-byte `ret` followed by `0xcc`; `by-memory/-ignored.md` records it as `@_guard_check_icall_nop@4`, ignored MSVC CFG/runtime helper. | Document as compiler/runtime guard/no-op path for deleting-destructor flag bit `4`, with object size `0x14` / 20. It is not NexusTK product logic. | Reject source-level sized delete or MemoryMan free on this branch. This branch specifically avoids `OperatorDeleteWrapper`. |
| Reachability / callers | Local scan found target VA `0x005974f0` exactly once at `.rdata:0x0062e2c4`; zero target RVA hits; zero target raw-offset hits; zero `.text` rel32 calls/jumps to target. Existing target doc also says no ordinary direct callers. | Target is vtable-reachable generated destructor glue, not dead code and not a source-called helper. | Reject `CANONICAL_OWNER:NONE` or ignored/dead classification. The class declaration and destructor must regenerate this wrapper. |
| Constructor/static route | Local scan found zero VA pointer hits and zero rel32 hits to constructor `0x00596bf0`. Worker entry `0x00597100` has a VA/immediate hit at constructor `0x00596cb1`; worker loop `0x00596e10` has one direct call at `0x00597140` from worker entry. | Missing constructor direct caller remains a broader singleton/static-lifetime question, not a blocker for [UID:0001K5]. The wrapper's vtable route is independently proven. | Reject using missing constructor caller to keep [UID:0001K5] file-owned or non-emitting. |
| Raw helper liveness | Local scan found zero VA pointer hits and zero `.text` rel32 hits for `0x00596d20`, message wrapper starts `0x00596d70/90/b0/d0/f0`, and representative watch helper starts `0x005971b0/1f0/230/2f0/360/3a0/3e0/430/490`. | Raw ordinary destructor remains source-shape evidence despite no modeled caller. Message/watch helpers are a separate [UID:0001K1]/[UID:0003V7] liveness question. | Reject requiring raw helper proof before target classification. Optional future split of `0x00596d20-0x00596d6f` can improve ordinary destructor C++ placement but is not required for [UID:0001K5]. |
| Owner/source placement | Target restores ThreadMan vtable, tears down ThreadMan fields, clears ThreadMan singleton, and sits in ThreadMan vtable slot. [UID:0000EW] class clears `86/85` and emits through [UID:0000OR] `Thread`. [UID:0000OR] is source root `NexusTK/util/Thread.cpp`. | Set direct `CANONICAL_OWNER:0000EW` and `EMITTER_UIDS:0000EW`; keep [UID:0000OR] as indirect source root. No evidence supports a new `ThreadMan.cpp` split. | Reject keeping [UID:0000OR] as direct owner merely because it is the final `.cpp` file. Reject a separate source file absent stronger source/project evidence. |
| Range/split/merge | Local bytes show five-byte prepad, one 126-byte wrapper, two-byte postpad, and successor `0x00597570` disassembles as `mov [ecx], 0x0062e338; mov eax, ecx; ret`. Timer docs assign successor to TimerHandler/TimerMgr. | Keep exact range unchanged. Do not split internally. Do not merge with TimerMgr or with [UID:0001K4]. | Reject TimerHandler merge and reject treating padding bytes as target body. |

## Evidence Standards Used

- Existing docs read or checked as direct support:
  - Target [UID:0001K5] `by-memory/0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md`
  - [UID:0000EW] `by-class/ThreadMan.md`
  - [UID:0000OR] `by-file/Thread.md`
  - [UID:0001JX] `by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md`
  - [UID:0001K0] `by-memory/0x00596bf0-0x00596d13.ThreadManConstructor.md`
  - [UID:0001K1] `by-memory/0x00596d20-0x00596e0b.ThreadManRawMessageWrappers.md`
  - [UID:0001K4] `by-memory/0x005974e0-0x005974eb.ClearThreadManSingleton.md`
  - [UID:0001K6] `by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md`
  - [UID:00026P] `by-memory/0x0062e268-0x0062e334.ThreadReadOnlyData.md`
  - [UID:0001WA] `by-type/by-struct/ThreadManLayout.md`
  - [UID:0001WB] `by-type/by-struct/ThreadManWatchRecord.md`
  - [UID:0000SH] `by-global/g_pThreadMan.md`
  - [UID:000370] `by-memory/0x004f4a90-0x004f4a97.LObjectDestructorBody.md`
  - [UID:000197] `by-memory/0x004f4ac0-0x004f4b00.OperatorDeleteWrapper.md`
  - `by-memory/-ignored.md` entry for `0x0041b6a0-0x0041b6a1` `@_guard_check_icall_nop@4`
- Prior B-agent reports used as leads and rechecked:
  - `tools/leaser/Agents/Agent-B008/research/0001K5-ThreadManScalarDeletingDestructor-source-quality.md`
  - `tools/leaser/Agents/Agent-B009/research/0001K5-ThreadManScalarDeletingDestructor-source-quality.md`
  - `tools/leaser/Agents/Agent-B003/research/0000EW-ThreadMan-class-source-quality.md`
- Fresh local PE evidence:
  - Binary: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
  - MD5: `4247e04e20b65d6414c7238aa8ff5515`
  - SHA1: `c285b73dc7b54c9a0e28ff7591a9bdde2ac55f9a`
  - Image base: `0x00400000`
  - Capstone x86 32-bit disassembly
  - Manual PE section parsing, import parsing, pointer scans, and `.text` rel32 call/jump scans.
- Validator evidence:
  - Scoped target validation command completed with exit code `0` and `ok: 1`.

## Raw PE / Capstone Facts

PE section map from B012 local script:

| Section | VA | RVA | Raw | Raw size | Virtual size |
| --- | --- | --- | --- | --- | --- |
| `.text` | `0x00401000` | `0x001000` | `0x000400` | `0x20b600` | `0x20b4ac` |
| `.rdata` | `0x0060d000` | `0x20d000` | `0x20ba00` | `0x05f200` | `0x05f0be` |
| `.data` | `0x0066d000` | `0x26d000` | `0x26ac00` | `0x00d800` | `0x02fe24` |
| `.rsrc` | `0x0069d000` | `0x29d000` | `0x278400` | `0x015e00` | `0x015c38` |

Target and boundary facts:

- Target raw span: VA `0x005974f0-0x0059756e`, raw `0x001968f0-0x0019696e`, size `0x7e` / 126 bytes.
- Prepad: VA `0x005974eb-0x005974f0`, raw `0x001968eb-0x001968f0`, bytes `cc cc cc cc cc`.
- Postpad: VA `0x0059756e-0x00597570`, raw `0x0019696e-0x00196970`, bytes `cc cc`.
- Successor head at `0x00597570`: bytes `c7 01 38 e3 62 00 8b c1 c3 cc ...`, disassembling as `mov dword ptr [ecx], 0x62e338; mov eax, ecx; ret`, matching TimerHandler vtable installation in the TimerMgr/TimerHandler island.

Target body bytes:

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
0x005974ff  test eax, eax
0x00597501  je 0x0059751c
0x00597503  push 0
0x00597505  push eax
0x00597506  call dword ptr [0x0060d220]    ; TerminateThread
0x0059750c  push dword ptr [esi+0x08]
0x0059750f  call dword ptr [0x0060d110]    ; CloseHandle
0x00597515  mov [esi+0x08], 0
0x0059751c  mov ecx, [esi+0x10]
0x0059751f  test ecx, ecx
0x00597521  je 0x00597530
0x00597523  mov eax, [ecx]
0x00597525  push 1
0x00597527  call dword ptr [eax]           ; delete watch-list object
0x00597529  mov [esi+0x10], 0
0x00597530  mov ecx, esi
0x00597532  mov dword ptr [0x0069be08], 0
0x0059753c  call 0x004f4a90                ; LObject destructor body
0x00597541  mov eax, [ebp+8]               ; deleting flags
0x00597544  test al, 1
0x00597546  je 0x00597567
0x00597548  test al, 4
0x0059754a  jne 0x0059755c
0x0059754c  push esi
0x0059754d  call 0x004f4ac0                ; OperatorDeleteWrapper
0x00597552  add esp, 4
0x00597555  mov eax, esi
0x00597557  pop esi
0x00597558  pop ebp
0x00597559  ret 4
0x0059755c  push 0x14
0x0059755e  push esi
0x0059755f  call 0x0041b6a0                ; @_guard_check_icall_nop@4
0x00597564  add esp, 8
0x00597567  mov eax, esi
0x00597569  pop esi
0x0059756a  pop ebp
0x0059756b  ret 4
```

Raw ordinary destructor comparison, `0x00596d20-0x00596d70`:

```text
0x00596d20  push esi
0x00596d21  mov esi, ecx
0x00596d23  mov eax, [esi+0x08]
0x00596d26  mov [esi], 0x0062e2c4
0x00596d2c  test eax, eax
0x00596d2e  je 0x00596d49
0x00596d30  push 0
0x00596d32  push eax
0x00596d33  call dword ptr [0x0060d220]    ; TerminateThread
0x00596d39  push dword ptr [esi+0x08]
0x00596d3c  call dword ptr [0x0060d110]    ; CloseHandle
0x00596d42  mov [esi+0x08], 0
0x00596d49  mov ecx, [esi+0x10]
0x00596d4c  test ecx, ecx
0x00596d4e  je 0x00596d5d
0x00596d50  mov eax, [ecx]
0x00596d52  push 1
0x00596d54  call dword ptr [eax]
0x00596d56  mov [esi+0x10], 0
0x00596d5d  mov ecx, esi
0x00596d5f  mov dword ptr [0x0069be08], 0
0x00596d69  pop esi
0x00596d6a  jmp 0x004f4a90
0x00596d6f  int3
```

ThreadMan vtable area dwords:

| VA | Value | Meaning |
| --- | --- | --- |
| `0x0062e2c0` | `0x00651650` | RTTI complete-object-locator pointer per [UID:00026P] |
| `0x0062e2c4` | `0x005974f0` | ThreadMan scalar deleting destructor slot |
| `0x0062e2c8` | `0x004f4b10` | inherited/base virtual slot |
| `0x0062e2cc` | `0x0041b6c0` | inherited/base no-op virtual slot |
| `0x0062e2d0` | `0x0045004b` | first UTF-16 dword of `KERNEL32.DLL`, not a vtable function |
| `0x0062e2d4` | `0x004e0052` | second UTF-16 dword of `KERNEL32.DLL`, not a vtable function |

Pointer and rel32 scan facts:

| Query | Result |
| --- | --- |
| Target VA `0x005974f0` pointer hits | One hit: raw `0x0022ccc4`, VA `.rdata:0x0062e2c4` |
| Target RVA `0x001974f0` pointer hits | Zero |
| Target raw offset `0x001968f0` pointer hits | Zero |
| `.text` rel32 calls/jumps to `0x005974f0` | Zero |
| `ThreadMan` vtable immediate `0x0062e2c4` hits | `0x00596c4f`, `0x00596d28`, `0x005974fb` |
| `g_pThreadMan` immediate `0x0069be08` hits | `0x00596c34`, `0x00596c3c`, `0x00596d61`, `0x005974e2`, `0x00597534` |
| Constructor VA `0x00596bf0` pointer hits / rel32 hits | Zero / zero |
| Worker entry VA `0x00597100` pointer hits / rel32 hits | One VA/immediate hit at `0x00596cb1` / zero rel32 hits |
| Worker loop `0x00596e10` rel32 hits | One direct call at `0x00597140` |
| Clear singleton `0x005974e0` rel32 hits | One direct jump at `0x00609ace` from constructor cleanup/EH region |
| Raw destructor/message wrapper starts | Zero VA pointer hits and zero rel32 hits for `0x00596d20`, `0x00596d70`, `0x00596d90`, `0x00596db0`, `0x00596dd0`, `0x00596df0` |
| Watch helper starts | Zero VA pointer hits and zero rel32 hits for representative starts `0x005971b0`, `0x005971f0`, `0x00597230`, `0x005972f0`, `0x00597360`, `0x005973a0`, `0x005973e0`, `0x00597430`, `0x00597490` |

Import-table facts used by the target and support range:

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

| Range / Item | UID / Path | Role | Reconstructable | Direct owner recommendation | Score state / recommendation | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00596bf0-0x00596d13` | [UID:0001K0] `ThreadManConstructor` | `ThreadMan::ThreadMan()` constructor, singleton publish, vtable install, debugger probe, watch-list construction, worker thread start | TRUE | current file-owned [UID:0000OR]; semantic class-owned [UID:0000EW] if broader child routing is accepted | current `88/86` | Supports target field names and source placement |
| `0x00596d20-0x00596e0b` | [UID:0001K1] `ThreadManRawMessageWrappers` | Raw ordinary destructor plus retained message-post wrappers | TRUE | current file-owned [UID:0000OR]; semantic class-owned [UID:0000EW] for member bodies | current `88/86` | Contains the ordinary destructor source-shape evidence for target no-code proof |
| `0x00596e10-0x005970df` | [UID:0001K2] `ThreadManWorkerLoop` | Worker message pump/watchdog loop | TRUE | current file-owned [UID:0000OR]; semantic class-owned [UID:0000EW] if broader child routing is accepted | current `88/86` | Supports `m_workerThreadId`, `m_watchList`, debugger flag, and record semantics |
| `0x00597100-0x005971ad` | [UID:0001K3] `ThreadManWorkerEntry` | CreateThread entry; calls worker loop | TRUE | keep [UID:0000OR] as file-static helper unless source evidence proves static class member | current `88/87` | Constructor pointer route at `0x00596cb1` |
| `0x005971b0-0x005974da` | [UID:0003V7] `ThreadManWatchListRawHelpers` | Retained raw watch-list helper island | TRUE | current file-owned [UID:0000OR]; semantic class-owned [UID:0000EW] if broader child routing is accepted | current `86/87` | Supports record/list semantics; no direct route remains separate caveat |
| `0x005974e0-0x005974eb` | [UID:0001K4] `ClearThreadManSingleton` | Constructor-unwind singleton-clear thunk | FALSE | NONE | current `88/92` | Not a source method; one jump from EH cleanup |
| `0x005974f0-0x0059756e` | [UID:0001K5] target | MSVC scalar deleting destructor wrapper for ThreadMan | TRUE | recommend [UID:0000EW] | recommend `86/91` | Formal C++ blank by exact no-code proof |
| `0x00597570-0x005986da` | [UID:0001K6] `TimerMgrAndTimerQueue` | TimerHandler/TimerMgr successor island | TRUE | [UID:0000OT] TimerMgr source module | current `85/87` | Separate island; target must not merge into it |
| `0x0062e2c4` | inside [UID:00026P] `ThreadReadOnlyData` | ThreadMan vtable slot pointing to target | TRUE as generated-binary data implied by class declaration | source root [UID:0000OR], semantic class slot [UID:0000EW] | support doc `87/91` | Sole target VA pointer hit |
| `0x0069be08` | [UID:000305] storage / [UID:0000SH] global | ThreadMan singleton pointer | TRUE | [UID:0000OR] source root/global | global `86/88` | Cleared by raw ordinary destructor and scalar wrapper |

## Direct Caller / Callee / Reachability Inventory

| Address / Item | Evidence | Meaning |
| --- | --- | --- |
| `.rdata:0x0062e2c4` | dword value `0x005974f0` | Sole absolute target pointer hit; ThreadMan vtable slot |
| `0x00596c4f` | immediate `0x0062e2c4` in constructor | Constructor installs ThreadMan vtable |
| `0x00596d28` | immediate `0x0062e2c4` in raw ordinary destructor | Ordinary destructor restores ThreadMan vtable |
| `0x005974fb` | immediate `0x0062e2c4` in target | Wrapper restores ThreadMan vtable |
| `0x00597506` | indirect import call through `0x0060d220` | `TerminateThread(m_workerThreadHandle, 0)` |
| `0x0059750f` | indirect import call through `0x0060d110` | `CloseHandle(m_workerThreadHandle)` |
| `0x00597527` | `call dword ptr [eax]` after loading `[m_watchList]` vtable and pushing `1` | Deletes watch-list object using virtual deleting destructor |
| `0x00597532` | immediate store to `0x0069be08` | Clears `g_pThreadMan` |
| `0x0059753c` | direct call `0x004f4a90` | `LObject` base destructor body |
| `0x0059754d` | direct call `0x004f4ac0` | `OperatorDeleteWrapper` normal scalar-delete path only when `(flags & 1) != 0 && (flags & 4) == 0` |
| `0x0059755f` | direct call `0x0041b6a0` | MSVC CFG guard/no-op helper path when `flags & 4` is set; object size `0x14` is pushed first |
| `.text` rel32 to target | zero | No ordinary direct callers; expected for vtable wrapper |
| VA/RVA/raw pointer hits to target | one VA hit, zero RVA/raw hits | Vtable-only route is exact in the local PE scan |

## Source-Level Destructor Shape

The accepted source shape should distinguish two layers:

1. Source-authored ordinary destructor:

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

This draft is source-shape guidance for [UID:0000EW] `ThreadMan` or a future split of the raw ordinary destructor at `0x00596d20-0x00596d6f`. It should not be pasted into [UID:0001K5]'s formal C++ block.

2. Compiler-generated scalar deleting destructor wrapper:

- Restores the ThreadMan vtable.
- Runs the ordinary cleanup sequence.
- Invokes `LObject` base cleanup.
- Tests deleting flags from the hidden wrapper parameter.
- Calls `OperatorDeleteWrapper(this)` only for `(flags & 1) != 0 && (flags & 4) == 0`.
- Takes the `@_guard_check_icall_nop@4` branch only when `flags & 4` is set, after pushing `0x14` and `this`.
- Returns `this` and uses `ret 4`.

Only the ordinary destructor is source-authored. The exact target range [UID:0001K5] is the second layer and should remain formal no-code.

## Formal C++ No-Code Proof

Do not populate [UID:0001K5]'s `RECONSTRUCTION_CPP CODE` block.

Proof:

- The target's exact ABI shape is a scalar deleting destructor wrapper: `this` arrives in `ecx`, the hidden deleting-destructor flags are read from `[ebp+8]`, and the body returns with `ret 4`.
- The target is vtable-reachable through `.rdata:0x0062e2c4`, and B012's scan found no ordinary `.text` rel32 direct callers. This matches compiler-generated destructor wrapper use.
- The source-authored cleanup sequence is independently visible in the raw ordinary destructor at `0x00596d20-0x00596d6f`, which performs the same field/global cleanup and tail-jumps to `LObject` cleanup without the deleting flags or storage-release wrapper.
- The target's extra behavior after cleanup is compiler policy: `flags & 1`, `flags & 4`, [UID:000197] `OperatorDeleteWrapper`, and ignored `@_guard_check_icall_nop@4` helper.
- The class declaration and ordinary destructor source should regenerate the target wrapper. A handwritten method with a `flags` parameter would be decompiler-shaped and not plausible mid-2000s source.
- If formal destructor C++ is desired later, split or update the raw ordinary destructor part of [UID:0001K1], not [UID:0001K5].

## Ranked Ownership Analysis

### 1. [UID:0000EW] `ThreadMan` class

- Evidence for:
  - Target restores the `ThreadMan` vtable at `0x0062e2c4`.
  - Target is the first vtable slot of the ThreadMan table and tears down ThreadMan object fields.
  - Target clears `g_pThreadMan`, calls the base destructor body, and implements the class deleting-destructor wrapper policy.
  - [UID:0000EW] is already reconstructable, scored `86/85`, and emits through [UID:0000OR] `Thread`.
  - Current `by-structure.md` explicitly prefers the narrow semantic class owner over the final file route when a method/vtable item belongs to a class.
- Evidence against:
  - Current target metadata is file-owned [UID:0000OR], consistent with older combined owner/emitter routing and sibling ThreadMan child pages.
  - Some broader child routing changes for [UID:0001K0], [UID:0001K1], [UID:0001K2], and [UID:0003V7] are not yet implemented.
- Decision: accept for [UID:0001K5]. Recommend `CANONICAL_OWNER:0000EW`, `EMITTER_UIDS:0000EW`.

### 2. [UID:0000OR] `Thread` / `NexusTK/util/Thread.cpp`

- Evidence for:
  - `Thread.cpp` is the correct source root. Existing file page owns the Thread and ThreadMan island.
  - Proposed source tree places `Thread.cpp` under `NexusTK/util/`.
  - `ThreadMan`, `g_pThreadMan`, ThreadMan read-only data, constructor, worker loop, worker entry, raw helpers, and scalar wrapper all cluster in the Thread/ThreadMan source family.
  - No source-tree evidence supports creating a separate `ThreadMan.cpp`.
- Evidence against:
  - `by-structure.md` says direct ownership should not bypass a class owner just to reach a final `.cpp` root.
  - Target is not a file-level free helper; it is a class vtable destructor wrapper.
- Decision: reject as direct owner/emitter for [UID:0001K5], retain as indirect source root through [UID:0000EW].

### 3. `CANONICAL_OWNER:NONE` / ignored / non-reconstructable

- Evidence for:
  - The exact wrapper body is compiler-generated and should not be hand-authored.
- Evidence against:
  - The wrapper is not padding, CRT-only code, or dead code. It is required by the `ThreadMan` vtable and must be regenerated from class/destructor source.
  - The source route is clear enough through `ThreadMan` and `Thread.cpp`.
- Decision: reject. Keep `RECONSTRUCTABLE:TRUE` with blank formal C++.

### 4. New `ThreadMan.cpp`

- Evidence for:
  - It is source-plausible by class name in isolation.
- Evidence against:
  - Existing source tree, file docs, aggregate docs, read-only data locality, and generated route all point to `util/Thread.cpp`.
  - No direct source/PDB/project evidence supports a separate file.
- Decision: reject for this target. Keep `ThreadMan` in `NexusTK/util/Thread.cpp`.

## Open Questions And Closure

- Exact original destructor spelling:
  - Best answer: `ThreadMan::~ThreadMan()`.
  - Evidence: raw ordinary destructor and scalar wrapper parity.
  - Status: closed for target purposes. Exact header formatting/access level remains a class-page detail, not a blocker.
- Exact member prefixes:
  - Best answer: use source-facing `m_isDebuggerPresent`, `m_workerThreadHandle`, `m_workerThreadId`, and `m_watchList`; retain unprefixed names as acceptable layout/table labels if the project style requires it.
  - Evidence: constructor/destructor/worker loop offsets and existing layout doc.
  - Status: closed with inferred/descriptive naming. This caps final-source confidence but should not block target score/ownership.
- `ThreadManWatchRecord +0x08` vocabulary:
  - Best answer: `watchedThreadId`, not abstract `threadIdentity`, because it is copied from `Thread +0x60`, and generic Thread construction uses that offset as a thread-id output field.
  - Status: support-doc recommendation; not a target blocker.
- Constructor reachability:
  - Evidence checked: local pointer and rel32 scans found no direct route to constructor start `0x00596bf0`; worker entry pointer from constructor is confirmed.
  - Best conclusion: unresolved broader singleton/static initialization question; not a blocker for [UID:0001K5] because the target is vtable-reachable.
- Raw wrapper/watch helper liveness:
  - Evidence checked: zero pointer and rel32 hits for raw starts.
  - Best conclusion: retained source-shaped methods/helpers with no direct route. This remains a [UID:0001K1]/[UID:0003V7] caveat and does not block [UID:0001K5].
- `0x0041b6a0` role:
  - Best answer: ignored MSVC CFG `@_guard_check_icall_nop@4`, one-byte `ret`, used as guard/no-op branch target.
  - Status: closed.
- Source C++ placement:
  - Best answer: no formal C++ in target; ordinary destructor draft belongs to class/raw destructor support.
  - Status: closed by no-code proof.

## Rejected Alternatives And Negative Evidence

- Handwritten `ThreadMan::scalar_deleting_destructor(unsigned int flags)`: rejected because flags/delete/guard structure is ABI wrapper logic, not source.
- Direct file owner [UID:0000OR]: rejected as direct owner under current narrow-owner rule; retained as source root.
- `CANONICAL_OWNER:NONE`, ignored, or dead-code treatment: rejected because the target is the ThreadMan vtable destructor slot.
- TimerHandler/TimerMgr merge: rejected by two-byte postpad and successor vtable store to `0x0062e338`.
- Source `ClearThreadManSingleton()`: rejected because [UID:0001K4] is constructor-unwind cleanup glue; normal destructor clear sites already exist.
- Explicit source `LObjectDestructorBody(this)`: rejected because base cleanup is implicit C++ destructor sequencing.
- Source `OperatorDeleteWrapper(this)`: rejected because storage release belongs to scalar deleting destructor wrapper only.
- Treating `m_watchList` as inline storage: rejected because the destructor deletes a heap object through a vtable.
- Treating missing constructor caller as a target blocker: rejected because target route is the vtable slot and direct class/source root is clear.
- Treating `.rdata` dwords `0x0045004b` / `0x004e0052` as ThreadMan functions: rejected because they are UTF-16 `KERNEL32.DLL` literal bytes immediately after the vtable.

## Exact Target Implementation Checklist

For a later implementation callback:

1. Lease edited files as B012 if the callback is assigned to B012; do not edit `by-memory/-coverage-report.md`.
2. Update [UID:0001K5] metadata:
   - `COMPLETION:86`
   - `CONFIDENCE:91`
   - `CANONICAL_OWNER:0000EW`
   - `RECONSTRUCTABLE:TRUE`
   - `EMITTER_UIDS:0000EW`
   - keep `EMITTER_POSITION_OPTIONAL` blank
   - keep formal `RECONSTRUCTION_CPP CODE` blank
3. Replace stale final-C++ blocker wording with target-specific no-code proof:
   - it is a MSVC scalar deleting destructor wrapper generated from `ThreadMan::~ThreadMan()`;
   - source should define `virtual ~ThreadMan()` / ordinary destructor body;
   - MSVC regenerates vtable slot, deleting flags, storage release, and guard branch.
4. Add B012 raw PE facts at report-level detail:
   - exact size `0x7e` / 126 bytes;
   - raw span `0x001968f0-0x0019696e`;
   - five-byte prepad and two-byte postpad;
   - successor `0x00597570` TimerHandler vtable install;
   - full cleanup/deleting-flag disassembly summary;
   - pointer scan: target VA only at `.rdata:0x0062e2c4`, no target RVA/raw hits, no `.text` rel32 direct callers.
5. Add exact behavior:
   - vtable restore to `0x0062e2c4`;
   - `m_workerThreadHandle` at `+0x08` is terminated/closed/cleared only when non-null;
   - `m_watchList` at `+0x10` is deleted through its virtual deleting destructor with flag `1` and then nulled;
   - `g_pThreadMan` at `0x0069be08` is cleared;
   - `LObjectDestructorBody` is called;
   - `OperatorDeleteWrapper` only runs for `(flags & 1) != 0 && (flags & 4) == 0`;
   - `flags & 4` branch pushes `0x14` and `this`, calls `@_guard_check_icall_nop@4`, and avoids the normal delete wrapper.
6. Add relation to [UID:0001K1]:
   - raw ordinary destructor `0x00596d20-0x00596d6f` has the same cleanup sequence and is the source-shape evidence for `ThreadMan::~ThreadMan()`;
   - [UID:0001K5] duplicates that sequence inside wrapper glue and should not emit a second destructor body.
7. Add score rationale:
   - raise from `84/88` to `86/91` because exact raw PE, boundary, vtable-only route, field/global/helper names, raw ordinary-destructor parity, guard/delete policy, source/wrapper split, and class owner route are now documented;
   - keep below final-audit because exact original member spellings and broader constructor/static route remain unresolved outside the target.
8. Preserve or add rejected alternatives:
   - no direct source caller does not mean dead code;
   - no `ThreadMan.cpp` evidence;
   - no source `ClearThreadManSingleton`;
   - no source scalar wrapper function;
   - no TimerMgr merge;
   - no explicit source base cleanup/delete wrapper.

## Exact Support-Doc Implementation Checklist

### `by-class/ThreadMan.md`

- Add a destructor policy section:
  - [UID:0001K5] is class-owned MSVC scalar deleting destructor wrapper glue reached from vtable slot `0x0062e2c4`;
  - the class declaration should expose `virtual ~ThreadMan();`, not a source-visible scalar deleting destructor;
  - ordinary destructor semantics are terminate/close `m_workerThreadHandle`, delete/null `m_watchList`, clear `g_pThreadMan`, then implicit `LObject` base cleanup.
- Add or synchronize field names:
  - `bool m_isDebuggerPresent` at `+0x04`;
  - `HANDLE m_workerThreadHandle` at `+0x08`;
  - `DWORD m_workerThreadId` at `+0x0c`;
  - `List *m_watchList` at `+0x10`.
- Replace old `95/95` or generic "no final C++ yet" language for [UID:0001K5] with target-specific wrapper no-code policy.
- Preserve `Thread.cpp` source root and reject `ThreadMan.cpp` absent stronger source evidence.

### `by-file/Thread.md`

- Add that [UID:0001K5] is now best treated as class-owned generated destructor wrapper through [UID:0000EW], while `NexusTK/util/Thread.cpp` remains the source root.
- Preserve the `Thread` and `ThreadMan` source-family grouping.
- Note that blank target C++ is intentional wrapper policy, not stale score-gate wording.

### `by-type/by-struct/ThreadManLayout.md`

- Synchronize names/types with target evidence:
  - `+0x04` debugger-present flag;
  - `+0x08` `HANDLE m_workerThreadHandle`;
  - `+0x0c` `DWORD m_workerThreadId`;
  - `+0x10` `List *m_watchList`.
- Add B012 destructor-facing evidence:
  - target and raw destructor both terminate/close/clear `+0x08`;
  - target and raw destructor both virtual-delete/null `+0x10`;
  - scalar wrapper guard branch pushes object size `0x14`, matching the current observed object extent.
- Mark `m_` prefixes as descriptive/source-facing rather than original-proof.

### `by-type/by-struct/ThreadManWatchRecord.md`

- Add a cross-note that [UID:0001K5] deletes the heap `List` containing these records via the list object's vtable; it does not iterate or destroy records directly.
- Prefer `watchedThreadId` for record `+0x08` to avoid ambiguity with `ThreadMan::m_workerThreadId`.
- Keep `context`/`registerContext`, `probePending`/`watchdogPending`, and `deadlineTick` with current confidence labels.

### `by-memory/0x00596d20-0x00596e0b.ThreadManRawMessageWrappers.md`

- Add B012 raw ordinary-destructor comparison:
  - `0x00596d20-0x00596d6f` restores ThreadMan vtable, terminates/closes/clears worker handle, deletes/nulls watch list, clears `g_pThreadMan`, and tail-jumps to [UID:000370] `LObjectDestructorBody`.
- State this body is the best current source-shape evidence for `ThreadMan::~ThreadMan()`.
- Add optional future split recommendation:
  - split `0x00596d20-0x00596d6f` into a dedicated ordinary destructor page if the project wants formal destructor-body C++ in a by-memory method page.
  - This split is not required for [UID:0001K5].

### `by-memory/0x00596bf0-0x00596d13.ThreadManConstructor.md`

- Add cross-note that B012 scan still found no direct constructor caller; constructor/static singleton route remains a broader class/file issue.
- Synchronize constructor field names with target evidence:
  - publish `g_pThreadMan`;
  - install vtable `0x0062e2c4`;
  - store `m_workerThreadHandle`;
  - pass `&m_workerThreadId`;
  - store `m_watchList`.

### `by-memory/0x00596e10-0x005970df.ThreadManWorkerLoop.md`

- Synchronize field names and record vocabulary where relevant: `m_isDebuggerPresent`, `m_workerThreadId`, `m_watchList`, and `ThreadManWatchRecord::watchedThreadId`.
- Note B012 rel32 scan confirms the worker loop direct call at `0x00597140` from worker entry.

### `by-memory/0x005971b0-0x005974da.ThreadManWatchListRawHelpers.md`

- Add B012 no-route recheck for representative raw helper starts.
- State that this does not block [UID:0001K5] because scalar destructor only deletes the `m_watchList` object pointer; helper liveness belongs to the watch-helper page.

### `by-memory/0x005974e0-0x005974eb.ClearThreadManSingleton.md`

- Preserve `RECONSTRUCTABLE:FALSE`, blank owner/emitter, and no C++.
- Add/retain that B012 rel32 scan found the one jump to `0x005974e0` from `0x00609ace`, consistent with constructor cleanup/EH.
- Clarify normal destructor clears happen in [UID:0001K1] and [UID:0001K5].

### `by-global/g_pThreadMan.md`

- Add that ordinary `ThreadMan::~ThreadMan()` source should clear `g_pThreadMan = NULL`.
- Clarify [UID:0001K4] is constructor-unwind cleanup glue, while [UID:0001K1] and [UID:0001K5] are destructor clear sites.
- Keep likely declaration `static ThreadMan *g_pThreadMan;` in `util/Thread.cpp`, with `static` still an inferred linkage detail.

### `by-memory/0x0062e268-0x0062e334.ThreadReadOnlyData.md`

- Add B012 pointer-scan fact:
  - target VA `0x005974f0` appears only at `.rdata:0x0062e2c4`;
  - zero target RVA/raw-offset hits;
  - zero `.text` rel32 direct callers.
- Interpret `0x0062e2c4` as the ThreadMan scalar deleting destructor slot generated by class/destructor declaration.
- Preserve that `0x0062e2d0` begins the `KERNEL32.DLL` literal, so dwords `0x0045004b` and `0x004e0052` are not vtable function entries.

### `by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md`

- Update [UID:0001K5] child row/status to "class-owned compiler-generated scalar deleting destructor wrapper around ordinary ThreadMan destructor/delete policy; formal C++ blank by target-specific no-code proof."
- Preserve aggregate source root as `Thread.cpp`.
- Preserve boundary with TimerMgr/TimerHandler after `0x0059756e`.

### Optional / no mandatory edit

- [UID:000370] `LObjectDestructorBody`: no target-required edit. Optional representative caller cross-reference is acceptable if the support edit scope includes it.
- [UID:000197] `OperatorDeleteWrapper`: no target-required edit. Optional representative scalar deleting destructor caller note is acceptable.
- [UID:0001K6] `TimerMgrAndTimerQueue`: no target-required edit unless the implementation chooses to add a boundary cross-note. Existing page already records `0x00597570` as TimerHandler vtable install.
- `by-memory/0x0069be08-0x0069be0c.g_pThreadMan.md`: optional exact-storage cross-note if the implementation edits singleton support; global page is the primary support doc.

## Validator Commands For Later Implementation

Run scoped validators from `E:\NTK\GhidraBridge\source-3\project-documentation` for every edited file. Expected implementation commands if all recommended support docs are edited:

> Executable block R001 was removed from this report and preserved verbatim in [0001K5-ThreadManScalarDeletingDestructor-source-quality-removed.md](0001K5-ThreadManScalarDeletingDestructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If exact storage or optional runtime/helper support docs are edited, also validate those files.

Do not validate or edit `by-memory/-coverage-report.md` as B012 unless a future supervisor instruction explicitly lifts the current ban.

## Scoped Validator Baseline Result

Baseline command run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R002 was removed from this report and preserved verbatim in [0001K5-ThreadManScalarDeletingDestructor-source-quality-removed.md](0001K5-ThreadManScalarDeletingDestructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:

- Exit code: `0`
- `apply`: `False`
- Scanned markdown files: `1`
- `ok`: `1`
- Key target line: `ok 0001K5 by-memory/0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md UID header exists`
- The command was dry-run baseline validation only. No by-* file or coverage report was edited.

## Exact Supervisor-Owned Coverage Row Text

Do not edit `source-3/project-documentation/by-memory/-coverage-report.md` as B012. Supervisor-owned replacement row for the existing [UID:0001K5] row, to remain between [UID:0001K4] `ClearThreadManSingleton` and the ignored `0x0059756e-0x00597570` padding row:

```markdown
    - [UID:0001K5][0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor](by-memory/0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md) 0x005974f0-0x0059756e | compiler-generated destructor wrapper | ThreadManScalarDeletingDestructor : reconstructable : 86% : very-strong : B012 2026-06-19 source-quality reanalysis classifies this as the MSVC scalar deleting destructor wrapper generated from source-level `ThreadMan::~ThreadMan`; local PE/Capstone evidence confirms exact `0x7e` / 126-byte body at raw `0x001968f0`, five-byte prepad `0x005974eb-0x005974f0`, two-byte postpad `0x0059756e-0x00597570`, successor `0x00597570` TimerHandler boundary, ThreadMan vtable restore at `0x005974f9`, `m_workerThreadHandle` termination/close/clear at `+0x08`, `m_watchList` delete/null at `+0x10`, `g_pThreadMan` clear at `0x00597532`, [UID:000370] `LObjectDestructorBody` call at `0x0059753c`, [UID:000197] `OperatorDeleteWrapper` only for `(flags & 1) != 0 && (flags & 4) == 0`, flag-4 guard/no-op path through ignored MSVC `@_guard_check_icall_nop@4` at `0x0041b6a0` after pushing `this` and `0x14` / 20-byte object size, target VA pointer hit only in the ThreadMan vtable slot `.rdata:0x0062e2c4`, zero target RVA/raw-offset hits, zero `.text` rel32 direct callers, direct class owner/emitter route through [UID:0000EW][ThreadMan](by-class/ThreadMan.md) into source root [UID:0000OR][Thread](by-file/Thread.md), raw ordinary-destructor parity at `0x00596d20-0x00596d6f`, and formal target C++ should remain blank because source should express ordinary `ThreadMan` destructor semantics and let MSVC regenerate the wrapper.
```

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B012/research/0001K5-ThreadManScalarDeletingDestructor-source-quality.md`
- Modified: none outside B012 research.
- `by-memory/-coverage-report.md`: not edited.

FINISHED

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B012","command_id":"000000004165","destination_path":"executed-b-agent-research/B012/0001K5-ThreadManScalarDeletingDestructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:35","uid":"0001K5"} -->
<!-- {"agent":"B012","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001K5-ThreadManScalarDeletingDestructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B012/0001K5-ThreadManScalarDeletingDestructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001K5"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
