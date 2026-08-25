** TARGET-REPORT-UID:0001K5 **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001K5 ThreadManScalarDeletingDestructor Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0001K5][0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor](../../../../../by-memory/0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md) reconstructable, but document it as MSVC scalar deleting destructor wrapper glue generated from the source-level `ThreadMan::~ThreadMan()` ordinary destructor. Do not emit formal target C++ for this exact range.
- Final disposition: class-owned generated-binary destructor wrapper. The source-authored destructor semantics are the `ThreadMan` teardown sequence shared with the raw non-deleting destructor at `0x00596d20`; the deleting flags, optional `OperatorDeleteWrapper`, and flag-4 no-op/guard branch are compiler wrapper behavior.
- Required action: update the target from `84/88` to `86/91`, change direct owner/emitter from file [UID:0000OR][Thread](../../../../../by-file/Thread.md) to class [UID:0000EW][ThreadMan](../../../../../by-class/ThreadMan.md), keep `RECONSTRUCTABLE:TRUE`, keep the formal `RECONSTRUCTION_CPP CODE` block blank, and replace stale 95+ no-code wording with target-specific no-code proof.
- Confidence: high for exact bytes, range, padding, vtable-only reachability, field behavior, singleton behavior, base cleanup, and wrapper policy; capped below final-audit because live IDA MCP was unavailable during this B009 pass and exact original spelling of `ThreadMan` field names remains inferred/descriptive.

## Target

- Target UID: `0001K5`
- Target path: `source-3/project-documentation/by-memory/0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B009/research/0001K5-ThreadManScalarDeletingDestructor-source-quality.md`
- Source queue/report row: `project-level/-auto-completion-stats.md` lists `0001K5` at `84/88`; `auto-generated/-ag-memory-coverage.md` lists it as emitting through `0000OR` with no code; `by-memory/-coverage-report.md` line currently describes an `84%` scalar deleting destructor attached to `Thread.cpp`.
- Current scores and parent state: `COMPLETION:84`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000OR`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OR`, blank C++.
- Recommended scores and parent state: `COMPLETION:86`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000EW`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000EW`, blank C++.

## Executive Recommendation

[UID:0001K5] should not receive handwritten C++. It is the vtable-reachable MSVC scalar deleting destructor wrapper for `ThreadMan`. Its cleanup statements are the same class teardown already present in the raw non-deleting destructor start [UID:0001K1][0x00596d20](../../../../../by-memory/0x00596d20-0x00596e0b.ThreadManRawMessageWrappers.md), while the `flags` tests, `OperatorDeleteWrapper` call, sized flag-4 no-op/guard path, prologue/epilogue, and vtable route are compiler ABI output.

The direct semantic owner should be [UID:0000EW][ThreadMan](../../../../../by-class/ThreadMan.md), not the by-file page. The emitted-source route still reaches [UID:0000OR][Thread](../../../../../by-file/Thread.md) through the class page and `NexusTK/util/Thread.cpp`. This follows `by-structure.md`: class methods and vtable-owned compiler support should attach to the class when the class clears the gate; the by-file page remains the source root.

## Supervisor Active Recheck

- Supervisor assignment: B009 source-quality / heuristic research for [UID:0001K5] `ThreadManScalarDeletingDestructor`, report-only first.
- Scope checked: exact source shape for `ThreadMan` teardown, wrapper/no-code policy, `+0x08/+0x10` field names, `g_pThreadMan` singleton behavior, relation to raw non-deleting destructor and `ClearThreadManSingleton`, flag-4 guard policy, vtable-only reachability, support docs, owner/emitter/source placement, split adjustment, and C++ readiness.
- Split decision: no split is needed for [UID:0001K5]. It is an exact 126-byte function with five-byte prepad and two-byte postpad. A later optional split of [UID:0001K1] could isolate the raw ordinary destructor from message wrappers if the project wants a formal ordinary-destructor C++ page, but that is not required to document this target.
- Report-only compliance: no target/support by-* docs and no `by-memory/-coverage-report.md` were edited.

## Inference Research Guidance Check

- `by-structure.md` says source-quality investigation continues past 85/85, direct `CANONICAL_OWNER` must be the narrowest semantic owner, and compiler/linker-generated artifacts should be documented but not hand-ported unless a source declaration is needed to cause them.
- `inference_research.md` says ownership and source shape should be probability-rated when stripped binaries lack source metadata. This report treats previous docs as leads, then rechecks the raw PE, Capstone disassembly, pointer hits, and related docs.
- Facts: raw bytes, offsets, disassembly, pointer scan results, field offsets, calls, and existing documented IDA evidence.
- Inference: exact original C++ field spelling and whether the original declaration used `m_` prefixes. The best descriptive field names are strong enough for docs and draft C++; they are not original-proof.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Best-supported direction | Rejected alternatives / remaining effect |
| --- | --- | --- | --- |
| Compiler-generated name `sub_5974F0` / wrapper identity | Raw target has MSVC scalar deleting-destructor signature shape: `this` in `ecx`, `[ebp+8]` flags byte, `flags & 1` delete path, `flags & 4` sized no-op path, vtable-only pointer at `.rdata:0x0062e2c4`, no `.text` rel32 direct callers. | Source-facing prose name: `ThreadMan` scalar deleting destructor wrapper. IDA rename can use `ThreadMan_scalar_deleting_destructor` or MSVC-style ``ThreadMan::`scalar deleting destructor'``. | Reject treating this as a handwritten `ThreadMan::~ThreadMan()` source method body. Source should define the ordinary destructor and let MSVC regenerate this wrapper. |
| Ordinary destructor source shape | Raw non-deleting destructor `0x00596d20-0x00596d6f` repeats vtable restore, worker-handle termination/close, watch-list virtual delete, singleton clear, then tail-jumps to `LObject` cleanup. Target repeats the same cleanup before delete-flag logic. | Ordinary source destructor should terminate/close `m_workerThreadHandle`, delete/null `m_watchList`, and clear `g_pThreadMan`; `LObject` base cleanup is implicit after the body. | Reject an empty destructor and reject explicit source vtable writes or explicit `LObject::~LObject()` call in source. |
| `+0x08` field name/type | Constructor stores `CreateThread` handle at `+0x08`; target and raw destructor call `TerminateThread`/`CloseHandle` on it and clear it. `ThreadManLayout` already names it `workerThreadHandle`. | Use source-facing `HANDLE m_workerThreadHandle` at `+0x08`. | Exact original prefix is not proven. `workerThreadHandle` without `m_` remains acceptable in layout tables; C++ drafts should prefer project-normal `m_` style if used by nearby classes. |
| `+0x0c` related field | Constructor passes `this+0x0c` as `CreateThread` thread-id out pointer; raw message wrappers pass `this+0x0c` to `PostThreadMessageW`. | Use `DWORD m_workerThreadId` at `+0x0c`. | Not directly touched by [UID:0001K5], but needed for support-doc consistency. |
| `+0x10` field name/type | Constructor allocates 20-byte-record `List(20, 16)` and stores it at `+0x10`; worker loop scans it; raw/target destructors delete it through first vtable slot with deleting flag `1`. | Use `List* m_watchList` or `List* m_watchRecords`; prefer `m_watchList` because existing docs already use `watchList`, with element type `ThreadManWatchRecord` described separately. | Reject `std::list`, raw array, or owned inline list. The destructor reads a pointer and deletes a heap object. |
| `g_pThreadMan` singleton | Constructor writes `0x0069be08` at `0x00596c33/0x00596c3a`; raw destructor clears at `0x00596d5f`; clear helper clears at `0x005974e0`; target clears at `0x00597532`; storage child and global page already isolate it. | Source declaration remains `static ThreadMan* g_pThreadMan;` in `util/Thread.cpp`; destructor should clear it. `ClearThreadManSingleton` is compiler EH cleanup, not a source helper. | Reject treating `0x005974e0` as a source-authored `ClearThreadManSingleton()` function. It has one constructor-unwind jump and no ordinary callers. |
| Base destructor call | Target calls `0x004f4a90`; raw non-deleting destructor tail-jumps to `0x004f4a90`; existing docs identify it as [UID:000195] `LObject` cleanup. | Source destructor should not explicitly call base cleanup; `ThreadMan` inherits `LObject`, and C++ emits base destruction after the derived destructor body. | Reject decompiler-shaped `LObject::~LObject(this);` in source C++. |
| Flag-4 guard branch | Target tests `al,4`; if set, pushes `0x14` and `this`, calls `0x0041b6a0`, adds `esp,8`, returns `this`. This pattern matches established MSVC deleting-destructor flag-4 no-op/guard helper handling in sibling B reports. | Document as compiler/runtime flag-4 path with 20-byte object-size argument, not source logic. | Reject modeling it as a handwritten `operator delete(this, 0x14)` call. Normal delete only occurs through `0x004f4ac0` when `(flags & 1) != 0 && (flags & 4) == 0`. |
| Reachability | Raw PE pointer scan found target VA `0x005974f0` only once, at `.rdata:0x0062e2c4`; no target RVA hits; no target raw-offset hits; no `.text` rel32 direct call/jump to target. Existing docs also record vtable data xref/no direct callers. | Vtable-owned destructor glue. Caller absence is expected and supports wrapper/no-code policy. | Reject direct source-call ownership. This is not dead code; it is vtable slot 0. |
| Owner/emitter route | Target is a class destructor wrapper. `ThreadMan` class is `86/85` and emits through [UID:0000OR] `Thread.cpp`; by-file is `89/85`; layout is class-owned. | Change target direct owner/emitter to [UID:0000EW] `ThreadMan`; source root remains `NexusTK/util/Thread.cpp`. | Reject keeping [UID:0000OR] as direct owner just because it is the output file. That bypasses the class owner now that it clears 85/85. |
| Final C++ policy | Target clears active combined score/emitter gate after recommended score, but the exact range is compiler wrapper glue. `by-structure.md` says C++ must be limited to source represented by the page and compiler-generated artifacts should not be hand-ported. | Formal target C++ stays blank. Add first-draft ordinary destructor C++ as support guidance for the class/raw destructor, not in [UID:0001K5]. | Reject adding a comment-only C++ marker unless the supervisor explicitly wants emit-tracker population for wrappers. Existing project convention for this target currently uses blank C++. |
| Split/merge | Raw PE confirms exact target boundaries and padding. Target is not mixed with `TimerHandler`; raw ordinary destructor and message wrappers are separate earlier page [UID:0001K1]. | No split/merge required for [UID:0001K5]. Future optional split: isolate `0x00596d20-0x00596d6f` as ordinary destructor if first-draft destructor C++ needs a formal memory page. | The optional [UID:0001K1] split is outside this implementation callback unless supervisor asks. |

## Evidence Standards Used

- Existing documentation evidence: target page, `ThreadMan` class, `Thread.cpp` file, constructor, raw wrappers, clear helper, layout, global singleton, read-only data, generated coverage, project stats, previous B001 raw watch-list research as support.
- Raw PE evidence: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA1 `c285b73dc7b54c9a0e28ff7591a9bdde2ac55f9a`; image base `0x00400000`; manual PE section parsing; Capstone x86 32-bit disassembly; raw pointer and rel32 scans.
- Live IDA MCP status: attempted `tools/list` against `http://127.0.0.1:13337/mcp`; failed with `MCP_ERROR=Unable to connect to the remote server`. This report relies on existing IDA-backed docs plus fresh local raw PE checks.
- Number conversion evidence: `tools/int_convert.py` confirmed `0x7e = 126`, `0x14 = 20`, raw offset `0x1968f0 = 1665264`, `0x0062e2c4 = 6480580`, and `0x0069be08 = 6929928`.

## Raw PE / Capstone Facts

- PE sections: `.text` VA `0x00401000`, raw `0x00000400`; `.rdata` VA `0x0060d000`, raw `0x0020ba00`; `.data` VA `0x0066d000`, raw `0x0026ac00`; `.rsrc` VA `0x0069d000`, raw `0x00278400`.
- Target: `0x005974f0-0x0059756e`, size `0x7e` / 126 bytes, raw `0x001968f0-0x0019696e`, section `.text`.
- Prepad: `0x005974eb-0x005974f0`, five bytes `cc cc cc cc cc`, immediately after [UID:0001K4] `ClearThreadManSingleton`.
- Postpad: `0x0059756e-0x00597570`, two bytes `cc cc`, before the next `TimerHandler` helper at `0x00597570`.
- Target pointer hits: target VA `0x005974f0` appears exactly once at raw `0x0022ccc4`, VA `.rdata:0x0062e2c4`; target RVA `0x001974f0` has zero hits; target raw offset `0x001968f0` has zero hits.
- Direct `.text` rel32 callers/jumpers to target: zero.
- ThreadMan vtable immediate `0x0062e2c4` hits: `.text:0x00596c4f` constructor, `.text:0x00596d28` raw non-deleting destructor, `.text:0x005974fb` target wrapper.
- Singleton immediate `0x0069be08` hits: `.text:0x00596c34`, `0x00596c3c`, `0x00596d61`, `0x005974e2`, `0x00597534`.

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

Capstone disassembly highlights:

```text
0x005974f0: push ebp
0x005974f1: mov ebp, esp
0x005974f3: push esi
0x005974f4: mov esi, ecx
0x005974f6: mov eax, dword ptr [esi + 8]
0x005974f9: mov dword ptr [esi], 0x62e2c4
0x00597503: push 0
0x00597505: push eax
0x00597506: call dword ptr [0x60d220]      ; TerminateThread
0x0059750c: push dword ptr [esi + 8]
0x0059750f: call dword ptr [0x60d110]      ; CloseHandle
0x00597515: mov dword ptr [esi + 8], 0
0x0059751c: mov ecx, dword ptr [esi + 0x10]
0x00597525: push 1
0x00597527: call dword ptr [eax]           ; delete watch list via vtable slot
0x00597529: mov dword ptr [esi + 0x10], 0
0x00597532: mov dword ptr [0x69be08], 0
0x0059753c: call 0x4f4a90                  ; LObject destructor body
0x00597541: mov eax, dword ptr [ebp + 8]   ; deleting flags
0x00597544: test al, 1
0x00597548: test al, 4
0x0059754d: call 0x4f4ac0                  ; OperatorDeleteWrapper
0x0059755c: push 0x14
0x0059755e: push esi
0x0059755f: call 0x41b6a0                  ; guard/no-op flag-4 helper
0x00597567: mov eax, esi
0x0059756b: ret 4
```

Raw non-deleting destructor comparison:

```text
0x00596d20: push esi
0x00596d21: mov esi, ecx
0x00596d23: mov eax, dword ptr [esi + 8]
0x00596d26: mov dword ptr [esi], 0x62e2c4
0x00596d30: push 0
0x00596d32: push eax
0x00596d33: call dword ptr [0x60d220]      ; TerminateThread
0x00596d39: push dword ptr [esi + 8]
0x00596d3c: call dword ptr [0x60d110]      ; CloseHandle
0x00596d42: mov dword ptr [esi + 8], 0
0x00596d49: mov ecx, dword ptr [esi + 0x10]
0x00596d52: push 1
0x00596d54: call dword ptr [eax]           ; delete watch list
0x00596d56: mov dword ptr [esi + 0x10], 0
0x00596d5f: mov dword ptr [0x69be08], 0
0x00596d69: pop esi
0x00596d6a: jmp 0x4f4a90                  ; LObject destructor body
0x00596d6f: int3
```

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00596bf0-0x00596d13` | [UID:0001K0](../../../../../by-memory/0x00596bf0-0x00596d13.ThreadManConstructor.md) | `ThreadMan` constructor | TRUE | currently file `0000OR`; source owner class `0000EW` | `88/86` | Confirms fields, singleton publish, `List(20,16)`, worker thread start |
| `0x00596d20-0x00596e0b` | [UID:0001K1](../../../../../by-memory/0x00596d20-0x00596e0b.ThreadManRawMessageWrappers.md) | raw ordinary destructor plus message posting wrappers | TRUE | currently file `0000OR`; class semantics `0000EW` | `88/86` | Ordinary destructor source-shape evidence; no function objects/xrefs for raw starts |
| `0x005974e0-0x005974eb` | [UID:0001K4](../../../../../by-memory/0x005974e0-0x005974eb.ClearThreadManSingleton.md) | compiler EH singleton-clear thunk | FALSE | NONE | `88/92` | No source helper; constructor cleanup artifact |
| `0x005974f0-0x0059756e` | [UID:0001K5](../../../../../by-memory/0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md) | scalar deleting destructor wrapper | TRUE | recommend class `0000EW` | recommend `86/91` | Exact target; no formal C++ |
| `0x0062e2c4` | inside [UID:00026P](../../../../../by-memory/0x0062e268-0x0062e334.ThreadReadOnlyData.md) | `ThreadMan` vtable slot pointing to target | TRUE as source-declared/generated-binary data | `0000OR` aggregate; class sub-owner `0000EW` | `87/91` | Vtable-only target route |
| `0x0069be08` | [UID:000305](../../../../../by-memory/0x0069be08-0x0069be0c.g_pThreadMan.md) / [UID:0000SH](../../../../../by-global/g_pThreadMan.md) | singleton pointer storage/global | TRUE | `0000OR` | global `86/88` | Cleared by ordinary destructor and wrapper |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `.rdata:0x0062e2c4` | pointer value `0x005974f0` | Only target VA hit; `ThreadMan` vtable slot. |
| `.text:0x00596c4f` | immediate `0x0062e2c4` | Constructor installs `ThreadMan` vtable. |
| `.text:0x00596d28` | immediate `0x0062e2c4` | Raw non-deleting destructor restores `ThreadMan` vtable. |
| `.text:0x005974fb` | immediate `0x0062e2c4` | Target wrapper restores `ThreadMan` vtable. |
| `.text:0x00596c34`, `0x00596c3c` | immediate `0x0069be08` | Constructor singleton publish/fallback. |
| `.text:0x00596d61` | immediate `0x0069be08` | Raw destructor singleton clear. |
| `.text:0x005974e2` | immediate `0x0069be08` | Compiler EH cleanup thunk singleton clear. |
| `.text:0x00597534` | immediate `0x0069be08` | Target wrapper singleton clear. |
| `0x00597506` | IAT call `TerminateThread` | Stops worker handle at `+0x08`. |
| `0x0059750f` | IAT call `CloseHandle` | Releases worker handle at `+0x08`. |
| `0x00597527` | virtual call through `m_watchList` first vtable slot with flag `1` | Deletes owned list at `+0x10`. |
| `0x0059753c` | direct call `0x004f4a90` | `LObject` base destructor body. |
| `0x0059754d` | direct call `0x004f4ac0` | normal scalar delete path only when `(flags & 1) != 0 && (flags & 4) == 0`. |
| `0x0059755f` | direct call `0x0041b6a0` | flag-4 no-op/guard path with object size `0x14`. |

## Documentation Evidence And Current Status

- Target doc already records the main behavior and older live IDA facts, but it still says no C++ is emitted because final field/source shape is below a `95+` final-source gate. That is stale under the current 85/85 policy and imprecise now that wrapper no-code proof is target-specific.
- [UID:0000EW][ThreadMan](../../../../../by-class/ThreadMan.md) is `86/85` and already attaches to [UID:0000OR][Thread](../../../../../by-file/Thread.md). It still carries old final-source-blocker wording: no direct constructor caller, raw wrapper starts, final field names, and destructor/source-shape split. This report resolves the destructor/source-shape part and provides best field names for `+0x08/+0x10`, but constructor reachability and raw message-wrapper names remain class-level caveats.
- [UID:0001K1][ThreadManRawMessageWrappers](../../../../../by-memory/0x00596d20-0x00596e0b.ThreadManRawMessageWrappers.md) already documents the raw non-deleting destructor. Raw PE recheck confirms the tail `jmp 0x004f4a90` at `0x00596d6a`.
- [UID:0001WA][ThreadManLayout](../../../../../by-type/by-struct/ThreadManLayout.md) already gives the correct offsets. This report recommends source-facing final names: `m_isDebuggerPresent`, `m_workerThreadHandle`, `m_workerThreadId`, and `m_watchList`.
- [UID:0000SH][g_pThreadMan](../../../../../by-global/g_pThreadMan.md) already records the likely declaration and all relevant clear paths. This report strengthens the destructor policy: source destructor clears it; [UID:0001K4] is only EH cleanup glue.
- [UID:00026P][ThreadReadOnlyData](../../../../../by-memory/0x0062e268-0x0062e334.ThreadReadOnlyData.md) already records the `ThreadMan` vtable at `0x0062e2c4`; it should add the specific pointer-route fact that `0x0062e2c4` is the only target VA pointer hit for [UID:0001K5].

## Ranked Ownership Analysis

### 1. [UID:0000EW] ThreadMan class

- Evidence for: this is the destructor wrapper for a `ThreadMan` object; it restores the `ThreadMan` vtable, cleans `ThreadMan` fields, clears the `ThreadMan` singleton, and is reached through the `ThreadMan` vtable slot. The class page clears `86/85` and emits through `Thread.cpp`.
- Evidence against: historical target metadata used direct file owner [UID:0000OR], and some sibling ThreadMan method pages still use file ownership. That is legacy combined-owner routing, not the current narrowest-owner rule.
- Decision: accept. Recommended `CANONICAL_OWNER:0000EW`, `EMITTER_UIDS:0000EW`.

### 2. [UID:0000OR] Thread file

- Evidence for: `Thread.cpp` is the correct source root and already owns the module; generated output currently reaches `auto-generated/NexusTK/util/Thread.cpp`.
- Evidence against: `by-structure.md` says direct ownership should be the narrowest semantic owner and not merely the final file root. This is a class destructor/vtable wrapper, not a file-level free helper.
- Decision: keep as indirect source root through [UID:0000EW], but reject as direct owner/emitter for this target after the support update.

### 3. NONE / no-owner / non-emitting

- Evidence for: exact wrapper source bytes should not be hand-authored.
- Evidence against: lack of formal C++ does not mean no owner or non-emitting. The class declaration/destructor source must cause this wrapper/vtable slot to be regenerated, and the source route is clear.
- Decision: reject. Keep reconstructable/source-declared generated-binary wrapper with class owner/emitter and blank formal code.

## First-Draft C++ Recommendation

Do not populate [UID:0001K5]'s formal `RECONSTRUCTION_CPP CODE` block. The exact target range is compiler wrapper glue.

The source-level ordinary destructor draft below is ready as guidance for [UID:0000EW] / [UID:0001K1] support docs, not for [UID:0001K5]:

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
- Do not include the scalar deleting `flags` parameter, `OperatorDeleteWrapper`, or the `0x0041b6a0` flag-4 branch.
- Keep `TerminateThread` despite source-style discomfort; it is exact binary behavior and likely original source.
- Use `List* m_watchList` with `ThreadManWatchRecord` element semantics documented separately unless a later header audit proves a stronger type alias.

## Exact Recommended Doc Changes

### Target [UID:0001K5]

- Metadata:
  - `COMPLETION:86`
  - `CONFIDENCE:91`
  - `CANONICAL_OWNER:0000EW`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:0000EW`
  - keep formal C++ blank.
- Replace stale no-code wording with:

```text
Rebuild handling: source-declared/generated-binary MSVC scalar deleting destructor wrapper for `ThreadMan::~ThreadMan()`. Do not hand-author C++ for this exact range. The source project should define the ordinary `ThreadMan` destructor; MSVC will regenerate this vtable wrapper, the deleting-flag paths, and the optional storage release call.
```

- Add behavior detail:

```text
The wrapper restores the `ThreadMan` vtable, terminates and closes `m_workerThreadHandle` at `this+0x08` when non-null, deletes and clears `m_watchList` at `this+0x10`, clears `g_pThreadMan`, calls the `LObject` base destructor body, then applies MSVC scalar deleting flags. It calls `OperatorDeleteWrapper` only when `(flags & 1) != 0 && (flags & 4) == 0`. When `flags & 4` is set it pushes `0x14` / 20 and `this`, calls the one-byte guard/no-op helper at `0x0041b6a0`, returns `this`, and does not call the normal delete wrapper.
```

- Add raw PE recheck section with the raw offset, size, prepad/postpad, body bytes, Capstone call/branch breakdown, pointer hit at `.rdata:0x0062e2c4`, no target RVA/raw hits, and no `.text` rel32 direct callers.
- Add relation to [UID:0001K1]:

```text
The ordinary source destructor shape is visible in the raw non-deleting destructor at `0x00596d20-0x00596d6f`: the same worker-handle, watch-list, singleton-clear, and `LObject` base cleanup sequence appears without deleting flags or storage-release wrapper. That ordinary destructor source shape belongs in `ThreadMan`/`Thread.cpp`; [UID:0001K5] remains no-code wrapper support.
```

- Score rationale:

```text
Raise `84/88 -> 86/91` because B009 2026-06-19 raw PE and source-quality recheck now confirms exact bytes, raw offset, padding, disassembly, flag order, callee identities, vtable-only route, object-size/layout proof, singleton/base cleanup relation, raw ordinary-destructor parity, class owner/emitter route, and explicit no-formal-C++ proof. Confidence remains capped below final-audit because live IDA MCP was unavailable during this pass and exact original source spelling of fields remains inferred.
```

### Support [UID:0000EW] `ThreadMan.md`

Add a destructor source-policy section:

```text
## Destructor Source Policy

[UID:0001K5] is the MSVC scalar deleting destructor wrapper reachable from the `ThreadMan` vtable slot at `0x0062e2c4`; it should stay no-code. The ordinary source destructor is represented by the cleanup sequence shared with [UID:0001K1] raw non-deleting destructor start `0x00596d20`: terminate/close `m_workerThreadHandle`, delete `m_watchList`, clear `g_pThreadMan`, then let the implicit `LObject` base destructor run.

Source-facing field names for the current rewrite should be `m_isDebuggerPresent` at `+0x04`, `m_workerThreadHandle` at `+0x08`, `m_workerThreadId` at `+0x0c`, and `m_watchList` at `+0x10` (`List(20,16)` of `ThreadManWatchRecord` records). Exact original spelling remains inferred, but these names are now the best supported descriptive names and should not block [UID:0001K5]'s no-code wrapper policy.
```

Also replace the class-level old `95/95` gate text with the active 85/85 gate plus target-specific note: [UID:0001K5] is blank because it is generated wrapper glue, not because `95+` is required.

### Support [UID:0001WA] `ThreadManLayout.md`

Add or revise notes to say:

```text
B009 2026-06-19 source-quality pass resolves the destructor-facing names/types for the teardown fields: `+0x08` is a Win32 `HANDLE m_workerThreadHandle`, `+0x0c` is `DWORD m_workerThreadId`, and `+0x10` is heap-owned `List* m_watchList` holding 20-byte `ThreadManWatchRecord` entries. The `m_` prefix is descriptive/source-facing, not proven original spelling.
```

No score change is required unless the implementer chooses to raise layout confidence by one point for field-name closure.

### Support [UID:0001K1] `ThreadManRawMessageWrappers.md`

Add the exact ordinary-destructor relationship:

```text
B009 2026-06-19 raw PE recheck disassembled the raw destructor tail through `0x00596d6a`, confirming the non-deleting destructor ends by tail-jumping to `0x004f4a90` after popping `esi`. This raw body is the best source-shape evidence for `ThreadMan::~ThreadMan()`. [UID:0001K5] duplicates this cleanup inside the scalar deleting wrapper and should not emit a second destructor body.
```

Optional future split recommendation:

```text
If formal destructor C++ is later entered, split `0x00596d20-0x00596d6f` into a dedicated ordinary destructor page and leave the message posting helpers as a separate raw wrapper island. This is not required for [UID:0001K5].
```

### Support [UID:0000SH] `g_pThreadMan.md`

Add:

```text
`ThreadMan::~ThreadMan()` source should clear `g_pThreadMan = NULL`; [UID:0001K4] is only constructor-unwind cleanup glue, while [UID:0001K1] and [UID:0001K5] show the normal destructor clear sites. This supports `static ThreadMan* g_pThreadMan;` in `util/Thread.cpp` but does not prove the original linkage spelling beyond strong static-singleton inference.
```

### Support [UID:00026P] `ThreadReadOnlyData.md`

Add:

```text
B009 2026-06-19 local PE pointer scan found target VA `0x005974f0` only at `.rdata:0x0062e2c4`, with no target RVA/raw-offset hits and no `.text` rel32 direct callers. Interpret `0x0062e2c4` as the `ThreadMan` vtable slot for the scalar deleting destructor wrapper; the source should regenerate it from the `ThreadMan` class declaration and ordinary destructor.
```

### Support [UID:0000OR] `Thread.md`

If edited, add only a short caveat:

```text
[UID:0001K5] is now best treated as a class-owned `ThreadMan` scalar deleting destructor wrapper routed through [UID:0000EW], while `Thread.cpp` remains the source root. Its blank C++ block is intentional wrapper no-code policy, not a stale 95+ gate blocker.
```

## Score / Metadata Recommendation

- Target before: `84/88`, direct owner/emitter `0000OR`, blank C++.
- Target after: `86/91`, direct owner/emitter `0000EW`, blank C++.
- Rationale for `86` completion: exact target bytes/range/padding, field behavior, delete-flag behavior, raw ordinary-destructor parity, singleton/base behavior, and owner route are now documented; remaining unresolved issues are mostly original spelling and broader constructor/static reachability outside this target.
- Rationale for `91` confidence: strong binary and documentation convergence, fresh raw PE validation, and no conflicting evidence; capped because live IDA MCP was unavailable and exact source spellings remain inferred.
- Support docs: no mandatory score changes. Optional minor support-score raises are defensible only if the implementation fully incorporates the field-name/destructor-policy updates.

## Exact Pending Coverage Text

Do not edit `source-3/project-documentation/by-memory/-coverage-report.md` as B009. Supervisor-owned replacement row for the existing [UID:0001K5] row:

```text
    - [UID:0001K5][0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor](by-memory/0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md) 0x005974f0-0x0059756e | compiler-generated destructor wrapper | ThreadManScalarDeletingDestructor : reconstructable : 86% : very-strong : B009 2026-06-19 raw PE/source-quality recheck classifies this as the MSVC scalar deleting destructor wrapper generated from source-level `ThreadMan::~ThreadMan`; raw PE/Capstone confirms exact `0x7e` / 126-byte body at raw `0x001968f0`, five-byte prepad, two-byte postpad, `ThreadMan` vtable restore at `0x005974f9`, `m_workerThreadHandle` termination/close/clear at `+0x08`, `m_watchList` delete/null at `+0x10`, `g_pThreadMan` clear at `0x00597532`, `LObject` base cleanup call at `0x0059753c`, `OperatorDeleteWrapper` only for `(flags & 1) != 0 && (flags & 4) == 0`, flag-4 path through `0x0041b6a0` after pushing `this` and `0x14` / 20-byte object size, target VA pointer hit only in the `ThreadMan` vtable slot `.rdata:0x0062e2c4`, no target RVA/raw-offset hits, no `.text` rel32 direct callers, direct class owner/emitter route through [UID:0000EW][ThreadMan](by-class/ThreadMan.md) into [UID:0000OR][Thread](by-file/Thread.md), raw ordinary-destructor parity at `0x00596d20-0x00596d6f`, and formal target C++ should remain blank because source should express ordinary `ThreadMan` destructor semantics and let MSVC regenerate the wrapper.
```

## Validator Needs

When the supervisor sends an implementation callback, lease all edited target/support docs first, then run scoped validation from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0001K5-ThreadManScalarDeletingDestructor-source-quality-removed.md](0001K5-ThreadManScalarDeletingDestructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If `Thread.md` is edited, also validate:

> Executable block R002 was removed from this report and preserved verbatim in [0001K5-ThreadManScalarDeletingDestructor-source-quality-removed.md](0001K5-ThreadManScalarDeletingDestructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## IDA Rename / Type / Comment Recommendations

- `sub_5974F0`: rename/comment as `ThreadMan_scalar_deleting_destructor` or ``ThreadMan::`scalar deleting destructor'``; confidence high.
- Raw `0x00596d20`: add function/comment candidate `ThreadMan_non_deleting_destructor` / `ThreadMan::~ThreadMan` raw body if IDA function creation is acceptable; confidence high for role, medium for exact IDA function creation policy because current IDA has no function object there.
- `dword_69BE08`: rename/type as `ThreadMan *g_pThreadMan`; confidence high for type, medium-high for `static` linkage.
- `ThreadMan` struct/class fields:
  - `+0x04`: `bool m_isDebuggerPresent`; confidence high for role.
  - `+0x08`: `HANDLE m_workerThreadHandle`; confidence high.
  - `+0x0c`: `DWORD m_workerThreadId`; confidence high.
  - `+0x10`: `List *m_watchList`; confidence high for pointer/list role, medium-high for exact original member spelling.
- `0x004f4a90`: keep/comment as `LObjectDestructorBody` / non-deleting `LObject` cleanup; confidence high from existing docs.
- `0x004f4ac0`: keep/comment as `OperatorDeleteWrapper`; confidence high from existing docs and scalar deleting destructor patterns.
- `0x0041b6a0`: comment as one-byte MSVC guard/no-op helper used by flag-4 deleting destructor paths; confidence high for wrapper role, not NexusTK source.

## Open Questions With Attempted Resolution

- Exact original destructor spelling: likely `ThreadMan::~ThreadMan()`. This is high-confidence from raw destructor and vtable wrapper, but original header formatting and access specifier are not proven. Does not block target no-code policy.
- Exact member prefixes: `m_workerThreadHandle` and `m_watchList` are descriptive best guesses. Existing docs use `workerThreadHandle`/`watchList`; either is acceptable if the project chooses one convention. This caps confidence but should no longer block wrapper documentation.
- Constructor reachability/static singleton creation: no direct constructor caller is modeled in existing docs. This remains a broader `ThreadMan`/startup question, not a blocker for target wrapper ownership or no-code policy.
- Raw message wrapper names: `RegisterThread`, `UnregisterThread`, and probe-clear/mark names remain provisional in [UID:0001K1]. Not a blocker for [UID:0001K5], but still a reason not to over-raise the class page.
- Optional raw destructor split: if the project wants final C++ for `ThreadMan::~ThreadMan()` in a by-memory page, split `0x00596d20-0x00596d6f`. For this report, exact target remains unsplit and blank C++.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B009/research/0001K5-ThreadManScalarDeletingDestructor-source-quality.md`
- Modified: none.
- Moved to executed: none.

## Validation Results

- Report-only task; no by-* docs edited and no validator run was required.
- Raw PE commands run:
  - Manual PE/Capstone script over `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` for target/range/padding/disassembly/pointer scans.
  - `tools/int_convert.py` for `0x7e`, `0x14`, `0x1968f0`, `0x62e2c4`, and `0x69be08`.
- Live IDA MCP: unavailable (`Unable to connect to the remote server`).

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/0001K5-ThreadManScalarDeletingDestructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:33","uid":"0001K5"} -->
<!-- {"agent":"B009","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001K5-ThreadManScalarDeletingDestructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B009/0001K5-ThreadManScalarDeletingDestructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001K5"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
