** TARGET-REPORT-UID:00026P **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00026P ThreadReadOnlyData Source-Quality Report

Assignment: `B003-goal2-thread-readonly-data-source-quality-00026P-20260618`

Target: [UID:00026P] `by-memory/0x0062e268-0x0062e338.ThreadReadOnlyData.md`

Recommended target after boundary repair: `by-memory/0x0062e268-0x0062e334.ThreadReadOnlyData.md`

## Evidence Checked

- Read the supervisor and agent instructions:
  - `tools/leaser/Agents/Supervisor.md`
  - `tools/leaser/Agents/Agent-B003/goal.md`
  - `tools/leaser/Agents/Agent-B003/notes.md`
  - `by-structure.md`
  - `inference_research.md`
  - `by-project-structure/proposed-source-tree.md`
- Read the primary target:
  - [UID:00026P] `by-memory/0x0062e268-0x0062e338.ThreadReadOnlyData.md`
- Rechecked source-placement/support pages:
  - [UID:0000OR] `by-file/Thread.md`
  - [UID:0000EV] `by-class/Thread.md`
  - [UID:0000EW] `by-class/ThreadMan.md`
  - [UID:0001JX] `by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md`
  - [UID:0001K0] `by-memory/0x00596bf0-0x00596d13.ThreadManConstructor.md`
  - [UID:0001K1] `by-memory/0x00596d20-0x00596e0b.ThreadManRawMessageWrappers.md`
  - [UID:0001K2] `by-memory/0x00596e10-0x005970df.ThreadManWorkerLoop.md`
  - [UID:0001K3] `by-memory/0x00597100-0x005971ad.ThreadManWorkerEntry.md`
  - [UID:0001K5] `by-memory/0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md`
  - [UID:0003V7] `by-memory/0x005971b0-0x005974da.ThreadManWatchListRawHelpers.md`
  - [UID:0000SH] `by-global/g_pThreadMan.md`
  - [UID:0001WA] `by-type/by-struct/ThreadManLayout.md`
  - [UID:0001WB] `by-type/by-struct/ThreadManWatchRecord.md`
  - [UID:0001SR] `by-type/by-enum/ThreadManMessageId.md`
- Rechecked adjacent `.rdata` pages:
  - [UID:00026O] `by-memory/0x0062df94-0x0062e268.TextEditReadOnlyData.md`
  - [UID:00026Q] `by-memory/0x0062e338-0x0062e480.TimerTotemReadOnlyData.md`
  - [UID:0003E0] `by-memory/0x0062e338-0x0062e344.TimerHandlerVtableData.md`
  - [UID:0001Z7] `by-memory/0x0060d670-0x0066d000.ReadOnlyDataSection.md`
- Rechecked prior B001 executed report for the ThreadMan watch-list split:
  - `tools/leaser/Agents/Agent-B001/research/executed/older/005971ad-threadman-watch-list-raw-cluster.md`
- Tried a live IDA MCP refresh at `http://127.0.0.1:13337/mcp`; it failed with `Unable to connect to the remote server`. Fresh live-IDB claims are therefore not added here. This report uses existing IDA-backed docs plus local PE byte/xref scans.
- Local PE evidence used `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA1 `c285b73dc7b54c9a0e28ff7591a9bdde2ac55f9a`, image base `0x00400000`.
- Local byte/dword scan of `0x0062e268-0x0062e338` found:

```text
0062e268: 0065163c   Thread RTTI complete-object-locator pointer
0062e26c: 00596bb0   Thread vtable first slot
0062e270: 004f4b10
0062e274: 0041b6c0
0062e278: 00596540
0062e27c: 005965c0
0062e280: 0041b6a0
0062e284: 0041b6a0
0062e288: 00596810
0062e28c: 0041b6a0
0062e290: 0041b6a0
0062e294: 0041b6a0
0062e298: 00596920
0062e29c: 00596940
0062e2a0: 0041b6b0
0062e2a4: 00000000
0062e2a8: 00000000
0062e2ac: 00000000
0062e2b0: 00000001
0062e2b4: 00000000
0062e2b8: 00000000
0062e2bc: 00000000
0062e2c0: 00651650   ThreadMan RTTI complete-object-locator pointer
0062e2c4: 005974f0   ThreadMan vtable first slot
0062e2c8: 004f4b10
0062e2cc: 0041b6c0
0062e2d0: 0045004b   UTF-16 "K","E" at start of KERNEL32.DLL
0062e2d4: 004e0052   UTF-16 "R","N"
0062e2d8: 004c0045   interior UTF-16 "E","L", not a source string start
0062e2dc: 00320033
0062e2e0: 0044002e
0062e2e4: 004c004c
0062e2e8: 00000000
0062e2ec: 65447349   ASCII "IsDe..."
0062e2f0: 67677562
0062e2f4: 72507265
0062e2f8: 6e657365
0062e2fc: 00000074
0062e300: 006f0050   UTF-16 "Possibly dead thread 0x%p"
0062e334: 006516f0   TimerHandler RTTI complete-object-locator pointer, not Thread/ThreadMan
0062e338: 00597650   TimerHandler vtable first slot
```

- Local string scan found:
  - UTF-16 `KERNEL32.DLL` starts at `0x0062e2d0`.
  - UTF-16 `EL32.DLL` appears only as the interior substring starting at `0x0062e2d8`; it is not the source literal start.
  - ASCII `IsDebuggerPresent` appears at `0x0062e2ec` and separately in the PE import-name table at `0x0066bd5a`.
  - UTF-16 `Possibly dead thread 0x%p` starts at `0x0062e300` and terminates before `0x0062e334`.
- Local dword reference scan found:
  - `0x0062e26c` referenced from `.text` immediates at `0x00596294` and `0x00596433`, matching the documented `Thread` vptr stores near `0x00596292` and `0x00596431`.
  - `0x0062e2c4` referenced from `.text` immediates at `0x00596c4f`, `0x00596d28`, and `0x005974fb`, matching documented `ThreadMan` vtable stores at `0x00596c4d`, `0x00596d26`, and `0x005974f9`.
  - `0x0062e2d0` referenced from `.text` at `0x00596c45`, matching the constructor's loader argument.
  - `0x0062e2d8` had no direct dword reference as a string start.
  - `0x0062e2ec` referenced from `.text` at `0x00596c63`, matching `GetProcAddress`.
  - `0x0062e300` referenced from `.text` at `0x005970a2`, `0x0059729a`, and `0x0059732d`, matching the worker-loop/watch-list dead-thread diagnostics.
  - `0x0062e338` referenced from `.text` at `0x00597572`, `0x005975a4`, and `0x00597677`, matching `TimerHandler` vtable use and proving the successor starts immediately after the TimerHandler RTTI locator at `0x0062e334`.
  - `0x0069be08` referenced from `.text` at `0x00596c34`, `0x00596c3c`, `0x00596d61`, `0x005974e2`, and `0x00597534`, matching `g_pThreadMan` constructor/destructor/cleanup state.
  - `0x0065163c` is referenced by the COL pointer at `0x0062e268`; `0x00651650` is referenced by the COL pointer at `0x0062e2c0`; `0x006516f0` is referenced by the COL pointer at `0x0062e334`.
- Local PE import table check found a separate KERNEL32 import-name-table occurrence of `IsDebuggerPresent` at `0x0066bd5a`. The constructor still uses the local source literal at `0x0062e2ec` for a dynamic `GetProcAddress` probe, but the docs should stop saying or implying that the binary does not import the API directly unless a full import/source-linkage explanation is added.

## Heuristic / Inference Reanalysis And Validation

The current source-facing placement is still `util/Thread.cpp`, but only after a boundary repair. The corrected `0x0062e268-0x0062e334` span contains `Thread` compiler RTTI/vtable data, `ThreadMan` compiler RTTI/vtable data, and `ThreadMan` source literals. That is all part of the shared Thread/ThreadMan utility module documented by [UID:0000OR] `Thread.md`. It should not be split to a direct `Thread`-only owner because half of the target is `ThreadMan`, and it should not be assigned only to `ThreadMan` because the first table is the generic `Thread` base vtable.

The current metadata `CANONICAL_OWNER:0000OR` / `EMITTER_UIDS:0000OR` is therefore correct for the corrected range ending at `0x0062e334`. It is not fully correct for the current physical file range ending at `0x0062e338`, because the final dword at `0x0062e334` is a `TimerHandler` RTTI complete-object-locator pointer and belongs to the successor timer/totem island. The supervisor should repair the range rather than set the broad target owner to mixed/none.

`Thread` vtable/type evidence validates the current Thread side. `0x0062e268` is a `Thread` RTTI complete-object-locator pointer to `0x0065163c`, and the `Thread` vtable starts at `0x0062e26c`. Existing support docs identify the base class vtable as `??_7Thread@@6B@`; the local dword hits confirm use in the `Thread` constructor/destructor path. Slot evidence remains consistent with [UID:0000EV] `Thread.md`: the table includes the scalar deleting destructor at `0x00596bb0`, generic stop/terminate/dispatch helpers, and the inherited external-wait default no-op slot at `0x0041b6b0`.

`ThreadMan` vtable/type evidence needs a documentation correction. `0x0062e2c0` is the `ThreadMan` RTTI complete-object-locator pointer to `0x00651650`, and `0x0062e2c4` is the `ThreadMan` vtable base. The current primary target omits the `0x0062e2c0` locator row and describes `0x0062e2c4-0x0062e2d8` as ThreadMan vtable data. That end is too late. Dwords at `0x0062e2d0` and `0x0062e2d4` are UTF-16 `KERN`, not code pointers. The defensible ThreadMan compiler-emitted table span is `0x0062e2c0-0x0062e2d0` when including the RTTI locator pointer, with the actual vtable base at `0x0062e2c4`.

The debugger support library literal is `KERNEL32.DLL`, not `EL32.DLL`. `0x0062e2d8` is only the interior `EL32.DLL` suffix of the UTF-16 literal beginning at `0x0062e2d0`. The constructor page's `off_62E2D0` evidence is therefore a strong contradiction of the current target row and any support-doc text that treats `EL32.DLL` as a source literal.

The dynamic debugger probe interpretation is valid with a narrower wording. `ThreadMan::ThreadMan` calls the loader thunk with the UTF-16 `KERNEL32.DLL` literal, calls `GetProcAddress` with the local ASCII `IsDebuggerPresent` literal at `0x0062e2ec`, optionally calls the result, and frees the module. However, the PE also contains a separate `IsDebuggerPresent` import-name-table entry at `0x0066bd5a`. The local literal is still a ThreadMan source literal for the dynamic probe, but it should not be used as proof that the executable lacks a normal import-table occurrence.

The dead-thread diagnostic is strongly placed in `ThreadMan`. The UTF-16 literal `Possibly dead thread 0x%p` starts at `0x0062e300`, terminates before `0x0062e334`, and is referenced at `0x005970a2`, `0x0059729a`, and `0x0059732d`. These hits align with [UID:0001K2] `ThreadManWorkerLoop` and [UID:0003V7] `ThreadManWatchListRawHelpers`, so the source role is a `ThreadMan` watchdog/timeout diagnostic. This validates current ownership but corrects the exact end boundary.

The `0x0062e2a4-0x0062e2c0` scalar run remains unresolved but bounded. It is a seven-dword run `0, 0, 0, 1, 0, 0, 0` between the final known `Thread` vtable slot and the `ThreadMan` RTTI locator pointer. I found no direct text references or support-doc explanation for it. Rejected alternatives: it is not part of the `ThreadMan` vtable because `0x0062e2c0` is the locator pointer and `0x0062e2c4` has the vtable refs; it is not the debugger library string because the string starts at `0x0062e2d0`; it is not the TimerHandler predecessor because TimerHandler RTTI starts at `0x0062e334`. Best current classification is compiler/linker RTTI/vtable-adjacent scalar data or an unparsed MSVC metadata tail inside the Thread/ThreadMan read-only island. It should be documented as unresolved generated data and should not be emitted as handwritten C++.

Related globals/types remain coherent with the ThreadMan placement:

- [UID:0000SH] `g_pThreadMan` should remain a `ThreadMan *` singleton storage at `0x0069be08`, owned by `Thread.cpp`.
- [UID:0001WA] `ThreadManLayout` remains the best current layout: `+0x00` vptr/`LObject` base, `+0x04` debugger-present flag, `+0x08` worker thread handle, `+0x0c` worker thread id, `+0x10` watch-list pointer.
- [UID:0001WB] `ThreadManWatchRecord` remains the best current 20-byte record layout: thread object, register/context pointer, thread identity/provisional thread key, watchdog-pending flag/state, and deadline tick.
- [UID:0001SR] `ThreadManMessageId` remains the best current enum family for `0x0464-0x0468`, with symbolic names still provisional but source role confirmed by raw wrappers and worker loop.

Support-doc recheck did not find a better source file than `util/Thread.cpp`. `Thread.md`, `ThreadMan.md`, `ThreadAndThreadMan.md`, the constructor, worker loop, raw wrappers, scalar deleting destructor, global, struct, and enum pages all converge on the same source root. The remaining source-shape debt is not ownership debt for this `.rdata` page; it affects formal C++ placement and exact helper names.

Rejected source-placement alternatives:

- `ThreadMan.cpp`: plausible by class name, but weaker than current evidence because `Thread` and `ThreadMan` are a contiguous code/data utility island and `by-file/Thread.md` already documents the shared file root at `89/85`.
- `Thread.cpp` with a direct `ThreadMan` class owner instead of file owner: too narrow for `0x0062e268-0x0062e2a4`, which is `Thread` class data.
- TextEdit predecessor ownership: rejected. The predecessor ends at `0x0062e268`; local and existing IDA-backed evidence identify `0x0062e268` as `Thread` RTTI, not TextEdit/TextPad.
- Timer successor exclusion at `0x0062e338`: partially wrong. `0x0062e338` is the TimerHandler vtable base, but `0x0062e334` is the TimerHandler COL pointer and should move with the timer successor/exact child.

Validation/contradiction of current docs:

- Validated: attach the Thread/ThreadMan data to [UID:0000OR] `Thread.md` / `util/Thread.cpp`.
- Validated: keep formal C++ blank on this read-only aggregate.
- Validated: source strings belong to the ThreadMan constructor and worker/watch-list diagnostics, not to a generated byte array.
- Contradicted: the current `EL32.DLL` row. Replace with UTF-16 `KERNEL32.DLL` at `0x0062e2d0`; mark `0x0062e2d8` as an interior substring only if mentioned.
- Contradicted: the current target end at `0x0062e338`. End at `0x0062e334`; move `0x0062e334-0x0062e338` to TimerHandler read-only data handling.
- Contradicted: the current ThreadMan vtable subrange ending at `0x0062e2d8`. The source-vtable span ends before the `KERNEL32.DLL` literal at `0x0062e2d0`.
- Incomplete: the primary target should add the `ThreadMan` RTTI locator pointer at `0x0062e2c0`.
- Stale: coverage report rows for `00026O`, `00026P`, and `00026Q` still show older ranges/scores and reconstructability labels.

Impact on score/owner/emitter/source placement/C++:

- Owner/emitter can remain [UID:0000OR] only after the `0x0062e334` boundary repair.
- The page clears the active source-quality gate after the correction because `RECONSTRUCTABLE:TRUE`, owner/emitter are nonblank, and `(87 + 91) / 2 = 89`.
- The unresolved `0x0062e2a4-0x0062e2c0` scalar run and live-MCP unavailability prevent a higher final-source score, but they do not prevent a defensible owner/emitter route or blank-code proof.
- Formal C++ should remain blank because the target is compiler-emitted RTTI/vtable data plus literals that should arise at method use sites.

## Recommended Metadata And Score Changes

Recommended after applying the boundary and string corrections:

```text
*** UID:00026P | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended file/range title:

```text
by-memory/0x0062e268-0x0062e334.ThreadReadOnlyData.md

# 0x0062e268-0x0062e334 Thread Read-Only Data
```

Score rationale: raise completion from `83` to `87` because the report resolves the source placement, corrects the library literal, adds the missing `ThreadMan` RTTI locator, identifies the TimerHandler tail as out-of-range, reconciles support docs, and supplies exact supervisor changes. Raise confidence from `88` to `91` because the corrections are byte-level and xref-supported by existing IDA docs plus local PE scans. Do not raise higher until the `0x0062e2a4-0x0062e2c0` scalar run is parsed or explicitly explained by an RTTI parser/live IDA type view, and until live IDA MCP is available again.

If the supervisor does not repair the end boundary and leaves `0x0062e334-0x0062e338` inside [UID:00026P], do not raise the target above `84/88`: the current range then remains mixed-owner and contains TimerHandler RTTI that is not owned by [UID:0000OR].

## First-Draft C++ Recommendation

Do not populate formal `RECONSTRUCTION_CPP` for [UID:00026P], even after the score/range repair.

Target-specific no-code proof:

1. `0x0062e268` and `0x0062e26c` are MSVC compiler-emitted RTTI/vtable data for `Thread`. In source, these arise from the `Thread` class declaration and virtual method definitions; hand-emitting a dword table would encode compiler output instead of source.
2. `0x0062e2c0` and `0x0062e2c4` are MSVC compiler-emitted RTTI/vtable data for `ThreadMan`. They likewise belong to declarations and virtual methods, not to an independent source object.
3. `0x0062e2d0`, `0x0062e2ec`, and `0x0062e300` are source-authored literals, but their source role is at use sites in `ThreadMan::ThreadMan`, `ThreadMan` worker-loop/watchdog code, and raw watch-list helpers. Emitting them in this `.rdata` page would duplicate or distort the eventual method/source-file reconstruction.
4. `0x0062e2a4-0x0062e2c0` is unresolved compiler/linker-adjacent scalar data and is not a safe handwritten declaration.
5. The successor dword `0x0062e334` is not part of this target after repair, so no TimerHandler declaration belongs here.

Recommended support snippet only, not formal target C++:

```cpp
// Candidate file-local names if the supervisor later chooses source constants
// instead of in-place literals inside ThreadMan methods.
static const wchar_t kThreadManKernel32DllName[] = L"KERNEL32.DLL";
static const char kThreadManIsDebuggerPresentName[] = "IsDebuggerPresent";
static const wchar_t kThreadManDeadThreadFormat[] = L"Possibly dead thread 0x%p";
```

Preferred source placement if C++ is later emitted in parent/support docs:

- `kThreadManKernel32DllName` and `kThreadManIsDebuggerPresentName`, or direct literals, belong with `ThreadMan::ThreadMan`.
- `kThreadManDeadThreadFormat`, or a direct literal, belongs with the `ThreadMan` worker-loop/watch-list timeout diagnostic path.
- Vtables/RTTI/COL pointers should not be manually emitted.

## Exact Supervisor Changes Required

Apply these changes only in supervisor-owned by-* docs or coverage files. This agent did not edit them.

1. Rename/move the primary target file:

```text
from: by-memory/0x0062e268-0x0062e338.ThreadReadOnlyData.md
to:   by-memory/0x0062e268-0x0062e334.ThreadReadOnlyData.md
```

2. In [UID:00026P], replace the metadata score lines with:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

3. In [UID:00026P], replace the title and Range address line with:

```text
# 0x0062e268-0x0062e334 Thread Read-Only Data

- Address range: `0x0062e268-0x0062e334`
```

4. In [UID:00026P], replace `## Summary` with:

```markdown
## Summary

This `.rdata` span contains the `Thread` RTTI locator pointer, `Thread` vtable, an unresolved generated scalar run between the two class tables, the `ThreadMan` RTTI locator pointer, the `ThreadMan` vtable, the dynamic debugger-probe literals used by `ThreadMan::ThreadMan`, and the dead-thread watchdog diagnostic literal used by ThreadMan worker/watch-list code.

Parent handling: attach this page to [UID:0000OR][Thread](by-file/Thread.md). The corrected range belongs to the shared `util/Thread.cpp` module documented by the file page: the first compiler-emitted table is for the generic `Thread` class, and the later table/literals are for `ThreadMan`. Do not attach this page directly to only [UID:0000EV][Thread](by-class/Thread.md) or only [UID:0000EW][ThreadMan](by-class/ThreadMan.md).
```

5. In [UID:00026P], replace `## Observed Contents` with:

```markdown
## Observed Contents

| Address | Item | Notes |
|---|---|---|
| `0x0062e268` | `Thread` RTTI locator pointer | `dd offset ??_R4Thread@@6B@`; points to COL/type metadata at `0x0065163c`; actual `Thread` vtable begins at `0x0062e26c`. |
| `0x0062e26c` | `Thread` vtable | `??_7Thread@@6B@`; local dword refs at `0x00596294` and `0x00596433` match `Thread` constructor/destructor vptr stores. |
| `0x0062e2a4-0x0062e2c0` | unresolved generated scalar run | Seven dwords `0, 0, 0, 1, 0, 0, 0` between the `Thread` vtable and `ThreadMan` RTTI locator; no source declaration should be emitted until RTTI/type parsing identifies it. |
| `0x0062e2c0` | `ThreadMan` RTTI locator pointer | `dd offset ??_R4ThreadMan@@6B@`; points to COL/type metadata at `0x00651650`; actual `ThreadMan` vtable begins at `0x0062e2c4`. |
| `0x0062e2c4` | `ThreadMan` vtable | `??_7ThreadMan@@6B@`; local dword refs at `0x00596c4f`, `0x00596d28`, and `0x005974fb` match constructor/raw-wrapper/destructor vptr stores. |
| `0x0062e2d0` | `KERNEL32.DLL` | UTF-16 dynamic debugger-probe support library name used by `ThreadMan::ThreadMan`; `0x0062e2d8` is only the interior `EL32.DLL` substring. |
| `0x0062e2ec` | `IsDebuggerPresent` | ASCII API name used by the constructor's `GetProcAddress` probe. The PE also has a separate import-name-table occurrence at `0x0066bd5a`; this local copy remains the ThreadMan dynamic-probe literal. |
| `0x0062e300` | dead-thread diagnostic format | UTF-16 `Possibly dead thread 0x%p`; referenced by worker-loop/watch-list timeout diagnostics at `0x005970a2`, `0x0059729a`, and `0x0059732d`. |
| `0x0062e334` | next range begins | `TimerHandler` RTTI complete-object-locator pointer; move to the timer/totem successor handling. |
```

6. In [UID:00026P], replace `## Ownership Map` with:

```markdown
## Ownership Map

| Subrange / item | Source owner | Reconstruction handling |
|---|---|---|
| `0x0062e268-0x0062e2a4` | [UID:0000EV][Thread](by-class/Thread.md) through [UID:0000OR][Thread](by-file/Thread.md) | Compiler-emitted RTTI locator pointer plus `Thread` vtable for the generic worker-thread base. Rebuild through the `Thread` declaration and virtual methods. |
| `0x0062e2a4-0x0062e2c0` | generated Thread/ThreadMan-adjacent `.rdata`, routed through [UID:0000OR][Thread](by-file/Thread.md) until parsed further | Unresolved scalar metadata run. Do not emit handwritten C++; preserve as generated data unless a later RTTI/type parser identifies a source-level construct. |
| `0x0062e2c0-0x0062e2d0` | [UID:0000EW][ThreadMan](by-class/ThreadMan.md) through [UID:0000OR][Thread](by-file/Thread.md) | Compiler-emitted RTTI locator pointer plus `ThreadMan` vtable for the process-level thread manager/watchdog singleton. |
| `0x0062e2d0-0x0062e300` | `ThreadMan::ThreadMan` through [UID:0000OR][Thread](by-file/Thread.md) | Source-authored dynamic debugger-probe literals: `KERNEL32.DLL` and `IsDebuggerPresent`. Keep with the constructor's `LoadLibraryW`/`GetProcAddress` path. |
| `0x0062e300-0x0062e334` | ThreadMan worker/watch-list diagnostics through [UID:0000OR][Thread](by-file/Thread.md) | Source-authored UTF-16 watchdog diagnostic `Possibly dead thread 0x%p`; rebuild through the worker-loop/watch-list timeout code, not as raw `.rdata`. |
```

7. In [UID:00026P], replace `## Boundary Evidence` with:

```markdown
## Boundary Evidence

| Boundary | Evidence |
|---|---|
| Predecessor | [UID:00026O][0x0062df94-0x0062e268.TextEditReadOnlyData](by-memory/0x0062df94-0x0062e268.TextEditReadOnlyData.md) ends before the `Thread` RTTI locator pointer. The old coverage-row end at `0x0062e26c` is stale. |
| Start | Existing IDA-backed docs identify `0x0062e268` as `dd offset ??_R4Thread@@6B@`; local bytes show pointer `0x0065163c` and the actual `Thread` vtable at `0x0062e26c`. |
| Internal transition | `Thread` RTTI/vtable data is followed by an unresolved generated scalar run, then `ThreadMan` RTTI/vtable data at `0x0062e2c0-0x0062e2d0`, then ThreadMan debugger/watchdog source literals. |
| End | The UTF-16 dead-thread format terminates before `0x0062e334`. Local bytes at `0x0062e334` are pointer `0x006516f0`, the `TimerHandler` RTTI complete-object-locator pointer; `0x0062e338` is the `TimerHandler` vtable first slot. |
| Successor | [UID:00026Q][TimerTotemReadOnlyData](by-memory/0x0062e338-0x0062e480.TimerTotemReadOnlyData.md) should be boundary-repaired to start at `0x0062e334` or should add an exact TimerHandler RTTI child covering the four-byte predecessor gap. |
| Enclosing section | [UID:0001Z7][0x0060d670-0x0066d000.ReadOnlyDataSection](by-memory/0x0060d670-0x0066d000.ReadOnlyDataSection.md) owns the wider `.rdata` map. |
```

8. In [UID:00026P], replace the two current reconstruction-note bullets about `EL32.DLL` and direct imports with:

```markdown
- Treat `KERNEL32.DLL` at `0x0062e2d0`, `IsDebuggerPresent` at `0x0062e2ec`, and `Possibly dead thread 0x%p` at `0x0062e300` as source literals used by ThreadMan code, not as independent byte-array declarations.
- `0x0062e2d8` is only the interior UTF-16 `EL32.DLL` substring of `KERNEL32.DLL`; do not document it as the source literal start.
- The constructor performs a dynamic `LoadLibraryW(KERNEL32.DLL)` / `GetProcAddress("IsDebuggerPresent")` probe using these local literals. The PE also has a separate import-name-table occurrence of `IsDebuggerPresent` at `0x0066bd5a`, so this local literal is dynamic-probe evidence, not proof that the binary lacks an import-table reference.
- Reconstruct the class declarations and diagnostics in `util/Thread.cpp`; do not hand-port this `.rdata` span as bytes. The vtables and RTTI are compiler-emitted, while the strings should arise from the ThreadMan constructor/worker-loop/watch-list source.
- Keep final C++ blank for this aggregate.
```

9. In [UID:0001K0] `ThreadManConstructor.md`, in the `Debugger probe` row of `## Constructor Phases`, replace the current IDA evidence/source-level meaning cells with:

```markdown
| Debugger probe | `0x00596c56` calls loader thunk `dword_69BE30` with UTF-16 `KERNEL32.DLL` at `0x0062e2d0`, `0x00596c68` calls `GetProcAddress` with ASCII `IsDebuggerPresent` at `0x0062e2ec`, and `0x00596c7c` calls `FreeLibrary` | Dynamically probes debugger presence; if the resolved function exists and returns nonzero, stores nonzero at `this+0x04`. |
```

10. In [UID:0001K0] `ThreadManConstructor.md`, in `## Touched State`, replace:

```text
| `off_62E2D0` / `"IsDebuggerPresent"` | Dynamic `kernel32`/debugger-probe literals used to avoid hard-linking the debugger API path. |
```

with:

```markdown
| `0x0062e2d0` / `0x0062e2ec` | UTF-16 `KERNEL32.DLL` and ASCII `IsDebuggerPresent` literals used by the constructor's dynamic debugger probe. The local `IsDebuggerPresent` literal is separate from the PE import-name-table occurrence at `0x0066bd5a`. |
```

11. In [UID:0000EW] `ThreadMan.md`, replace the evidence bullet:

```text
- Constructor resolves `kernel32.dll` and optionally calls `IsDebuggerPresent`.
```

with:

```markdown
- Constructor dynamically loads UTF-16 `KERNEL32.DLL` from `0x0062e2d0`, resolves ASCII `IsDebuggerPresent` from `0x0062e2ec`, optionally calls the result, and stores the debugger-present flag at `this+0x04`. The PE also has a separate import-name-table occurrence of `IsDebuggerPresent`; the local literal remains ThreadMan constructor probe data.
```

12. In [UID:00026Q] `TimerTotemReadOnlyData.md`, boundary repair is required because the TimerHandler RTTI locator is at `0x0062e334`. Recommended move:

```text
from: by-memory/0x0062e338-0x0062e480.TimerTotemReadOnlyData.md
to:   by-memory/0x0062e334-0x0062e480.TimerTotemReadOnlyData.md
```

Then replace its title/range start and first exact child references to include the locator:

```markdown
# 0x0062e334-0x0062e480 Timer/Totem Read-Only Data

- Address range: `0x0062e334-0x0062e480`
```

Recommended first observed-content row:

```markdown
| `0x0062e334` | `TimerHandler` RTTI locator pointer | `dd offset ??_R4TimerHandler@@6B@`; local bytes show pointer `0x006516f0`; the actual `TimerHandler` vtable starts at `0x0062e338`. |
| `0x0062e338` | `TimerHandler` vtable | Timer callback/handler table; [UID:0000F0][TimerHandler](by-class/TimerHandler.md) records live vtable stores/xrefs and generic timer-wrapper ownership. |
```

13. In [UID:0003E0] `TimerHandlerVtableData.md`, boundary repair is also required. Recommended move:

```text
from: by-memory/0x0062e338-0x0062e344.TimerHandlerVtableData.md
to:   by-memory/0x0062e334-0x0062e340.TimerHandlerVtableData.md
```

Recommended title/range/evidence replacement:

```markdown
# 0x0062e334-0x0062e340 TimerHandler Vtable Data

## Range

- Address range: `0x0062e334-0x0062e340`
- Kind: vtable-data
- Rebuild handling: source-declared/generated-binary

## Summary

Exact `TimerHandler` RTTI locator pointer plus vtable child at the start of the timer/totem `.rdata` island.

## Evidence

- Local bytes show `0x0062e334` as pointer `0x006516f0`, the `TimerHandler` RTTI complete-object-locator pointer.
- Existing IDA-backed docs identify `??_7TimerHandler@@6B@` at `0x0062e338`.
- The first vtable slot points to `0x00597650`; xrefs include `0x00597570`, `0x005975a2`, and `0x00597675`.
- The child starts immediately after [UID:00026P][0x0062e268-0x0062e334.ThreadReadOnlyData](by-memory/0x0062e268-0x0062e334.ThreadReadOnlyData.md) and ends before the `TimerMgr` RTTI locator/table boundary that must be audited separately.
```

Note: the existing child range `0x0062e338-0x0062e344` also appears to include the next `TimerMgr` locator/table boundary at its tail. That broader timer/totem exact-child boundary audit is adjacent to this assignment; at minimum the supervisor should not leave `0x0062e334` orphaned in [UID:00026P].

14. Update cross-links in [UID:00026O], [UID:00026P], [UID:00026Q], and [UID:0003E0] to use the new filenames/ranges if the supervisor applies the moves.

15. Suggested validation commands for the supervisor:

> Executable block R001 was removed from this report and preserved verbatim in [00026P-ThreadReadOnlyData-source-quality-removed.md](00026P-ThreadReadOnlyData-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Coverage Report Replacement Text

Replace the current coverage rows for `00026O`, `00026P`, and `00026Q` with this block after applying the boundary repairs:

```markdown
    - [UID:00026O][0x0062df94-0x0062e268.TextEditReadOnlyData](by-memory/0x0062df94-0x0062e268.TextEditReadOnlyData.md) 0x0062df94-0x0062e268 | vtable/string-data | TextEditReadOnlyData : ignored : 87% : strong : Reviewed non-emitting text-edit `.rdata` index ending before the `Thread` RTTI locator at `0x0062e268`; exact child coverage carries source ownership for text-edit vtables/strings, and the old coverage end at `0x0062e26c` was stale.
        - [UID:0002OZ][0x0062e184-0x0062e18c.TextFilterVtableData](by-memory/0x0062e184-0x0062e18c.TextFilterVtableData.md) 0x0062e184-0x0062e18c | vtable-data | TextFilterVtableData : reconstructable : 84% : strong : Exact one-slot `TextFilter` RTTI-adjacent vtable-data range bounded by `MBOLS.EPD` string data and `TextPad` metadata.
    - [UID:00026P][0x0062e268-0x0062e334.ThreadReadOnlyData](by-memory/0x0062e268-0x0062e334.ThreadReadOnlyData.md) 0x0062e268-0x0062e334 | vtable/string-data | ThreadReadOnlyData : reconstructable : 87% : strong : Attached to `Thread.cpp` after rechecking Thread/ThreadMan file, class, executable, constructor, worker, raw-wrapper, global, layout, and enum docs; corrected the debugger literal from interior `EL32.DLL` to UTF-16 `KERNEL32.DLL` at `0x0062e2d0`, added the `ThreadMan` RTTI locator at `0x0062e2c0`, documented `IsDebuggerPresent` and `Possibly dead thread 0x%p` as ThreadMan source literals, kept formal C++ blank because vtables/RTTI are compiler-emitted and literals should arise at method use sites, and moved the `TimerHandler` RTTI locator at `0x0062e334` to the timer successor.
    - [UID:00026Q][0x0062e334-0x0062e480.TimerTotemReadOnlyData](by-memory/0x0062e334-0x0062e480.TimerTotemReadOnlyData.md) 0x0062e334-0x0062e480 | vtable/string-data | TimerTotemReadOnlyData : ignored : 87% : strong : Reviewed non-emitting mixed timer/totem `.rdata` index now starting at the `TimerHandler` RTTI locator pointer `0x0062e334`, with exact children carrying reconstructable ownership for TimerHandler/TimerMgr/TimerPane/TotemFrame vtables and `TOTFRAME.EPD`; broad parent remains blank because the range crosses timer scheduler, timer overlay, and totem/status-frame owners.
```

If the supervisor does not apply the adjacent TimerTotem boundary repair in the same pass, use this temporary `00026P` row instead and leave `00026Q` unchanged until that pass:

```markdown
    - [UID:00026P][0x0062e268-0x0062e334.ThreadReadOnlyData](by-memory/0x0062e268-0x0062e334.ThreadReadOnlyData.md) 0x0062e268-0x0062e334 | vtable/string-data | ThreadReadOnlyData : reconstructable : 87% : strong : Attached to `Thread.cpp`; boundary repaired to exclude the `TimerHandler` RTTI locator at `0x0062e334`, corrected debugger literal from interior `EL32.DLL` to UTF-16 `KERNEL32.DLL` at `0x0062e2d0`, added the `ThreadMan` RTTI locator at `0x0062e2c0`, and kept formal C++ blank because vtables/RTTI are compiler-emitted and literals should arise at ThreadMan method use sites.
```

## Remaining Blockers

- Live IDA MCP was unavailable in this pass. Supervisor should rerun live IDA xrefs/decompilation if available before treating the fresh local PE scan as a live-IDB substitute.
- `0x0062e2a4-0x0062e2c0` remains unresolved generated scalar data. Additional evidence required for closure: live IDA type view, RTTI parser output around `0x0065163c`/`0x00651650`, or a validated MSVC metadata layout explanation for the seven dwords `0,0,0,1,0,0,0`. Until then, document it but do not emit C++ for it.
- Adjacent Timer/Totem exact-child boundaries need a follow-up audit because `0x0062e334` is the `TimerHandler` RTTI locator and the current `0x0062e338-0x0062e344.TimerHandlerVtableData` child may also overlap the next `TimerMgr` RTTI locator/table boundary. This does not block fixing [UID:00026P], but it affects the successor docs.
- `ThreadMan` final source C++ remains blocked by the same broader issues already documented in support pages: no modeled direct constructor caller, raw wrapper/watch-list helper starts with no function objects or start xrefs, provisional helper/field names, and final destructor/source-shape decisions. These blockers affect parent/source C++ emission, not the [UID:00026P] owner/emitter recommendation after range repair.
- If the supervisor cannot rename/move by-memory pages in this pass, [UID:00026P] should not be raised above `84/88`, because the current physical `0x0062e268-0x0062e338` file still contains TimerHandler data at `0x0062e334`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/00026P-ThreadReadOnlyData-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:27","uid":"00026P"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00026P-ThreadReadOnlyData-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/00026P-ThreadReadOnlyData-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00026P"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
