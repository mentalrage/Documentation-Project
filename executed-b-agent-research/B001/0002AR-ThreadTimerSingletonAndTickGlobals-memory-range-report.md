** TARGET-REPORT-UID:0002AR **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002AR ThreadTimerSingletonAndTickGlobals Memory Range Advanced-Scan Report

## Finalized Report / Current Recommendation

- Current recommendation: repair scanner-visible target text and the stale shared coverage row; do not change the target UID, range, split state, owner/emitter metadata, reconstructable state, or score.
- Final disposition: this is a real scanner-visible document-label gap plus stale coverage-report wording. It is not a stale filename, stale range, canonical-owner, emitter, split/merge, or IDA-name repair issue.
- Required action: add exact `ThreadTimerSingletonAndTickGlobals` document text to the target page, replace the old timed-out evidence note with current live IDA/PE evidence, and replace the `by-memory/-coverage-report.md` row that still calls the aggregate `reconstructable : 80%`.
- Routing decision: keep `CANONICAL_OWNER:NONE`, keep `RECONSTRUCTABLE:FALSE`, keep blank `EMITTER_UIDS`, keep score `86/88`, and keep final C++ blank. Exact child pages carry the source declarations.
- Confidence: high for label repair and mixed-index disposition; high for current range boundaries; high for child ownership split; medium-high for final source-level names of the two TimerMgr tick mirrors.

## Supporting Research

## Target

- Target UID: `0002AR`
- Target path: `by-memory/0x0069be08-0x0069be14.ThreadTimerSingletonAndTickGlobals.md`
- Source queue/report row: `auto-generated/by-memory-tool-report.md` Advanced-Error-Scan
- Exact scanner complaint: `0x0069be08-0x0069be14.ThreadTimerSingletonAndTickGlobals.md: missing document text for ThreadTimerSingletonAndTickGlobals`
- Current supervisor classification: `error-repair-assigned` to Agent-B001 in `tools/leaser/Agents/Supervisor_notes.md`, batch `B001-MR-0002AR`
- Current header state:

```text
UID:0002AR
COMPLETION:86
CONFIDENCE:88
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP CODE: blank
```

Current generated routing:

```markdown
| [UID:0002AR][0x0069be08-0x0069be14.ThreadTimerSingletonAndTickGlobals](by-memory/0x0069be08-0x0069be14.ThreadTimerSingletonAndTickGlobals.md) | not_reconstructable | `NONE` |  |  | no |  | `by-memory/0x0069be08-0x0069be14.ThreadTimerSingletonAndTickGlobals.md` |  |
```

Current stale shared coverage row:

```markdown
    - [UID:0002AR][0x0069be08-0x0069be14.ThreadTimerSingletonAndTickGlobals](by-memory/0x0069be08-0x0069be14.ThreadTimerSingletonAndTickGlobals.md) 0x0069be08-0x0069be14 | global-data cluster | ThreadTimerSingletonAndTickGlobals : reconstructable : 80% : strong : ThreadMan singleton pointer plus TimerMgr tick mirror globals.
```

## Executive Recommendation

The target should remain a reviewed mixed coverage index:

- Keep `CANONICAL_OWNER:NONE`.
- Keep `RECONSTRUCTABLE:FALSE`.
- Keep `EMITTER_UIDS:` blank.
- Keep score `86/88`.
- Keep `RECONSTRUCTION_CPP CODE` blank because this page is not a source-level object and because the exact children have their own reconstruction metadata.

The current split is correct:

- [UID:000305] `0x0069be08-0x0069be0c.g_pThreadMan` owns the exact `ThreadMan` singleton pointer storage and routes through [UID:0000SH] `g_pThreadMan` / [UID:0000OR] `Thread`.
- [UID:000306] `0x0069be0c-0x0069be10.TimerMgrTickBaselineMirror` owns the first TimerMgr tick mirror and routes through [UID:0000OT] `TimerMgr`.
- [UID:000307] `0x0069be10-0x0069be14.TimerMgrCurrentTickMirror` owns the second TimerMgr tick mirror and routes through [UID:0000OT] `TimerMgr`.

The current advanced-scan warning is caused by the target page title/body lacking exact `ThreadTimerSingletonAndTickGlobals`. The target filename and generated reports contain that compact label, but the document text does not.

## Supervisor Active Recheck

The supervisor assignment asked whether the memory-ranges advanced-scan warning is only a scanner-visible label/title mismatch or a real documentation/range/name/canonical-owner/emitter/range/split issue.

Result:

- Scanner label issue: yes, real. The target page lacks exact `ThreadTimerSingletonAndTickGlobals` text.
- Documentation evidence issue: yes, minor. The target still says the 2026-06-07 live IDA refresh timed out; current B001 live IDA MCP now supplies the missing xref/byte evidence.
- Shared coverage issue: yes, real. `by-memory/-coverage-report.md` still marks this reviewed mixed aggregate as `reconstructable : 80%`, contradicting the target header and generated `-ag-memory-coverage`.
- Range issue: no. `0x0069be08-0x0069be14` remains the correct historical mixed aggregate over three exact four-byte children.
- Filename issue: no. The current filename is correct.
- Canonical-owner issue: no. The aggregate correctly remains `CANONICAL_OWNER:NONE` because it crosses `ThreadMan` and `TimerMgr` ownership.
- Emitter issue: no. The aggregate correctly has blank `EMITTER_UIDS`; exact reconstructable children emit through their owners.
- Split/merge issue: no. The exact children already exist and are still supported by live IDA evidence.
- IDA-safe name repair: no. IDA currently renders the slots as offsets from the broad `dword_69BC18` area, not as proven final source identifiers for this aggregate.

No by-* files or coverage report files were edited in this assignment, per user instruction.

## Inference Research Guidance Check

`by-structure.md` and `inference_research.md` drive the conclusion:

- A reviewed mixed container should be `RECONSTRUCTABLE:FALSE` when it is only an audit/index page and exact children carry real source ownership.
- `CANONICAL_OWNER` must be the direct semantic owner. There is no single direct owner for a physical range that contains both a `ThreadMan` singleton pointer and two `TimerMgr` tick mirrors.
- `EMITTER_UIDS` is output routing. This aggregate should not emit source because doing so would duplicate or misroute the children; exact children already route to their appropriate owner/emitter chains.
- Address adjacency is weak evidence. Here, adjacency is outweighed by split xref sets and writer behavior: ThreadMan construction/teardown writes `0x0069be08`, while TimerMgr timer-period/refresh/dispatch paths reference `0x0069be0c` and `0x0069be10`.
- Current docs are useful leads but not authority. The old timeout note was rechecked with live IDA MCP, and the shared coverage row was found stale.

Documentation assumptions treated as uncertain:

- The exact final source-level names for `TimerMgrTickBaselineMirror` and `TimerMgrCurrentTickMirror` remain provisional.
- The exact declaration spelling and static linkage for `g_pThreadMan` remains below final C++ quality.
- The aggregate compact label `ThreadTimerSingletonAndTickGlobals` is a filename/report label, not a source identifier.

## Evidence Standards Used

Evidence checked:

- Current B001 `goal.md`
- `by-structure.md`
- `inference_research.md`
- `by-project-structure/proposed-source-tree.md`
- Target page, exact child pages, neighboring range pages, Thread/ThreadMan docs, TimerMgr docs, and relevant global/file/class pages
- Current `auto-generated/by-memory-tool-report.md`
- Current `auto-generated/-ag-memory-coverage.md`
- Current `by-memory/-coverage-report.md`
- Live IDA MCP `server_health`, `lookup_funcs`, `xrefs_to`, `get_bytes`, `get_global_value`, `insn_query`, and `entity_query`
- Read-only raw PE section mapping for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Lease state checks

The evidence is strong enough to recommend text repair, current live evidence refresh, and shared coverage-row replacement. It does not justify entering C++ or collapsing the exact children into one owner.

## IDA MCP Facts

Session:

- IDA MCP session: `b001_0003gy`
- Input binary: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- IDB: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`
- Image base: `0x00400000`
- Auto-analysis ready: `true`
- Hex-Rays ready: `true`

Function/range facts:

| Address | Function |
| --- | --- |
| `0x00596bf0` | `sub_596BF0`, size `0x123` |
| `0x00596c33`, `0x00596c3a` | inside `sub_596BF0` |
| `0x00596d5f` | raw/non-modeled cleanup body, no containing function |
| `0x005974e0` | `sub_5974E0`, size `0x0b` |
| `0x00597532` | inside `sub_5974F0`, size `0x7e` |
| `0x004ab870` | `sub_4AB870`, size `0x4a0` |
| `0x005977b0` | `sub_5977B0`, size `0x15a` |
| `0x00597e40` | `sub_597E40`, size `0x4a` |
| `0x00597e90` | `sub_597E90`, size `0x13` |

Xref facts:

| Address | Direct xref count | Meaning |
| --- | ---: | --- |
| `0x0069be04` | 8 | Predecessor TextEdit mouse-selection scratch word; separate owner, all refs in `sub_590DE0`. |
| `0x0069be08` | 5 | Exact `ThreadMan` singleton pointer slot. |
| `0x0069be0c` | 2 | TimerMgr baseline/current tick mirror. |
| `0x0069be10` | 4 | TimerMgr current tick mirror. |
| `0x0069be14` | 30 shown, more available | Successor WideApi dispatch pointer table; unrelated PlatformApi table. |

Current direct xrefs:

```text
0x0069be08:
  0x00596c33  sub_596BF0
  0x00596c3a  sub_596BF0
  0x00596d5f  raw cleanup body
  0x005974e0  sub_5974E0
  0x00597532  sub_5974F0

0x0069be0c:
  0x004abad8  sub_4AB870
  0x00597e80  sub_597E40

0x0069be10:
  0x004abad3  sub_4AB870
  0x005977c4  sub_5977B0
  0x00597e7b  sub_597E40
  0x00597e9c  sub_597E90
```

Representative instruction facts:

```text
0x00596c33  mov dword_69BC18+1F0h, eax
0x00596c3a  mov dword_69BC18+1F0h, 0
0x00596d5f  mov dword_69BC18+1F0h, 0
0x005974e0  mov dword_69BC18+1F0h, 0
0x00597532  mov dword_69BC18+1F0h, 0

0x00597e72  call ds:timeGetTime
0x00597e78  mov [esi+18h], eax
0x00597e7b  mov dword_69BC18+1F8h, eax
0x00597e80  mov dword_69BC18+1F4h, eax

0x00597e93  call ds:timeGetTime
0x00597e99  mov [esi+18h], eax
0x00597e9c  mov dword_69BC18+1F8h, eax
```

Interpretation:

- `dword_69BC18+1F0h` is `0x0069be08`; ThreadMan constructor and cleanup/destructor paths publish or clear the singleton pointer.
- `dword_69BC18+1F4h` is `0x0069be0c`; TimerMgr timer-period setup writes the baseline mirror.
- `dword_69BC18+1F8h` is `0x0069be10`; TimerMgr setup and refresh write the current tick mirror, and TimerMgr dispatch/application timing paths read it.
- The predecessor and successor addresses have independent xref clusters, so the target range is not missing bytes on either side.

Data/name facts:

- `get_bytes` returned all zero bytes for `0x0069be00-0x0069be20`, including the full `0x0069be08-0x0069be14` cluster.
- `get_global_value` returned zero for `0x0069be0c`, `0x0069be10`, and `0x0069be14`; reads at `0x0069be04`/`0x0069be08` returned zero-filled bytes because IDA models broad data around `0x0069bc18`.
- `entity_query` over `0x0069be00-0x0069be20` returned no named IDA globals or names.

## PE / Raw Evidence

Read-only PE mapping of `NexusTK.exe`:

```text
ImageBase: 0x00400000
0x0069be08: section .data, VA 0x0066d000-0x0069ce24, VirtualSize 0x2fe24, RawSize 0xd800, raw-backed end 0x0067a800
  virtual zero-fill tail, not initialized raw bytes
0x0069be0c: section .data, VA 0x0066d000-0x0069ce24, VirtualSize 0x2fe24, RawSize 0xd800, raw-backed end 0x0067a800
  virtual zero-fill tail, not initialized raw bytes
0x0069be10: section .data, VA 0x0066d000-0x0069ce24, VirtualSize 0x2fe24, RawSize 0xd800, raw-backed end 0x0067a800
  virtual zero-fill tail, not initialized raw bytes
0x0069be14: section .data, VA 0x0066d000-0x0069ce24, VirtualSize 0x2fe24, RawSize 0xd800, raw-backed end 0x0067a800
  virtual zero-fill tail, not initialized raw bytes
```

Conclusion: the cluster starts zero-initialized in the loader image. Runtime/source semantics come from the later ThreadMan and TimerMgr writes, not from initialized raw data. The zero-fill fact supports source-declared writable globals and does not imply one source owner for the physical cluster.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0069be08-0x0069be14` | [UID:0002AR] `ThreadTimerSingletonAndTickGlobals` | Mixed coverage index over ThreadMan/TimerMgr writable globals | `FALSE` | `NONE` | `86/88` | Keep; repair scanner label and stale evidence/coverage wording. |
| `0x0069be08-0x0069be0c` | [UID:000305] `g_pThreadMan` | Exact ThreadMan singleton pointer storage | `TRUE` | [UID:0000SH] `g_pThreadMan` | `86/88` | Keep assigned/emitting through Thread. |
| `0x0069be0c-0x0069be10` | [UID:000306] `TimerMgrTickBaselineMirror` | Exact TimerMgr baseline tick mirror | `TRUE` | [UID:0000OT] `TimerMgr` | `86/88` | Keep assigned/emitting through TimerMgr. |
| `0x0069be10-0x0069be14` | [UID:000307] `TimerMgrCurrentTickMirror` | Exact TimerMgr current tick mirror | `TRUE` | [UID:0000OT] `TimerMgr` | `86/88` | Keep assigned/emitting through TimerMgr. |
| `0x0069bdf8-0x0069be08` | [UID:0002AQ] `TerminalAndTextEditGlobals` | Predecessor mixed index | `FALSE` | `NONE` | `87/90` | Boundary support only; separate scope. |
| `0x0069be14-0x0069bec4` | [UID:0002AS] `WideApiDispatchPointerTable` | Successor PlatformApi dispatch table | `TRUE` | [UID:0000TQ] `WideApiDispatchTable` | `87/87` | Boundary support only; separate owner. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00596c33` | writes `0x0069be08` inside ThreadMan constructor | Publishes singleton pointer when object construction succeeds. |
| `0x00596c3a` | writes zero to `0x0069be08` inside ThreadMan constructor path | Fallback/null path. |
| `0x00596d5f` | writes zero to `0x0069be08` in raw cleanup body | Clears singleton during raw cleanup/destructor-adjacent path. |
| `0x005974e0` | writes zero to `0x0069be08` | Singleton-clear helper. |
| `0x00597532` | writes zero to `0x0069be08` inside scalar deleting destructor | Destructor clears singleton. |
| `0x00597e80` | writes `timeGetTime()` value to `0x0069be0c` | TimerMgr begin-period helper initializes baseline tick mirror. |
| `0x00597e7b` | writes `timeGetTime()` value to `0x0069be10` | TimerMgr begin-period helper initializes current tick mirror. |
| `0x00597e9c` | writes `timeGetTime()` value to `0x0069be10` | TimerMgr refresh helper updates current tick mirror. |
| `0x005977c4` | xref to `0x0069be10` in TimerMgr dispatch | Dispatch path uses current tick mirror. |
| `0x004abad3`, `0x004abad8` | xrefs to `0x0069be10`/`0x0069be0c` in `sub_4AB870` | Application/timing consumer path reads both tick mirrors. |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- [UID:0002AR] already states this is a mixed global-data cluster / coverage index, `RECONSTRUCTABLE:FALSE`, blank assignment, split into exact children.
- [UID:000305] exact child documents `0x0069be08` as `g_pThreadMan`, owner [UID:0000SH], emitter [UID:0000SH], with ThreadMan constructor/cleanup/destructor evidence.
- [UID:0000SH] `g_pThreadMan`, [UID:0000EW] `ThreadMan`, and [UID:0000OR] `Thread` tie `0x0069be08` to `util/Thread.cpp`.
- [UID:000306] and [UID:000307] exact children document the two tick mirror slots as TimerMgr-owned source-declared globals.
- [UID:0000F1] `TimerMgr` and [UID:0000OT] `TimerMgr` document tick mirrors, multimedia timer setup, refresh, dispatch, and source-file ownership.
- [UID:0002KY] `TimerMgrBeginTimerPeriod` and [UID:0002KZ] `TimerMgrRefreshCurrentTick` contain direct IDA-backed writes to `0x0069be0c`/`0x0069be10`.
- [UID:0002AQ] predecessor and [UID:0002AS] successor pages document the exact adjacent range boundaries.

Existing docs that are stale, incomplete, or contradicted:

- Target title `# Thread And Timer Singleton/Tick Globals` lacks the compact `ThreadTimerSingletonAndTickGlobals` label.
- Target evidence still records that the 2026-06-07 live IDA MCP refresh timed out. Current live IDA MCP evidence now confirms the split and should be added.
- `by-memory/-coverage-report.md` row for [UID:0002AR] is stale: it says `reconstructable : 80% : strong` despite the target header and generated report now saying non-reconstructable/no-owner/non-emitting.

Generated/coverage report state:

- `auto-generated/by-memory-tool-report.md` reports the scanner warning exactly as assigned.
- `auto-generated/-ag-memory-coverage.md` already reports [UID:0002AR] as `not_reconstructable`, `CANONICAL_OWNER:NONE`, blank emitters, and no generated path.
- `by-memory/-coverage-report.md` needs supervisor-owned row replacement.

## Ranked Ownership Analysis

### 1. Keep as mixed no-owner/non-emitting coverage index

Evidence for:

- Target range physically contains three exact source-bearing children with two different owner chains.
- Live IDA xrefs split by behavior: ThreadMan constructor/cleanup/destructor references only `0x0069be08`; TimerMgr timer-period/refresh/dispatch/timing consumers reference `0x0069be0c` and `0x0069be10`.
- Current exact children already carry reconstructable source ownership and emitter routes.
- `by-structure.md` says reviewed mixed containers should be `RECONSTRUCTABLE:FALSE` when exact children carry real source ownership.

Evidence against:

- The physical range is contiguous and all three items are zero-initialized writable `.data`, which can make it tempting to model as one data cluster.

Decision: accepted. Physical adjacency is weaker than xref/ownership evidence, and this aggregate should not emit source.

### 2. Assign aggregate to `Thread` / `ThreadMan`

Evidence for:

- The first four bytes are the `ThreadMan` singleton pointer, and the target title starts with "Thread".
- `Thread.cpp` and `g_pThreadMan` are strong, gate-cleared owners for `0x0069be08`.

Evidence against:

- ThreadMan has no semantic ownership over `0x0069be0c` or `0x0069be10`.
- TimerMgr helper writes and reads prove the following two dwords are timer tick mirrors.

Decision: rejected for the aggregate; accepted only for child [UID:000305].

### 3. Assign aggregate to `TimerMgr`

Evidence for:

- Two of the three dwords are TimerMgr tick mirrors.
- `TimerMgr.cpp` is a strong owner for timer tick globals and clears the parent gate.

Evidence against:

- TimerMgr has no semantic ownership over the `ThreadMan` singleton pointer at `0x0069be08`.
- ThreadMan constructor/destructor evidence is exclusive and strong for the first dword.

Decision: rejected for the aggregate; accepted only for children [UID:000306] and [UID:000307].

### 4. Assign aggregate to a new shared `ThreadTimer` file/grouping

Evidence for:

- The current compact label combines Thread and Timer wording.
- Both systems are utility/runtime-adjacent.

Evidence against:

- Proposed source tree already keeps `util/Thread.cpp` and `util/TimerMgr.cpp` as separate utility modules.
- Live IDA shows no common initializer, common owner object, common table, or shared lifecycle function for the three dwords.
- Creating a new grouping would obscure the already-supported direct source owners.

Decision: rejected. No new owner/file/grouping is warranted.

## Negative Evidence Summary

- Address adjacency alone does not prove common source ownership.
- No IDA evidence ties `0x0069be08` to TimerMgr; its refs are ThreadMan constructor/cleanup/destructor paths.
- No IDA evidence ties `0x0069be0c` or `0x0069be10` to ThreadMan; their refs are TimerMgr/application timing paths.
- The successor `0x0069be14` has many unrelated xrefs and is documented as a PlatformApi wide dispatch table; it must not be merged into the Thread/Timer aggregate.
- The predecessor `0x0069be04` has a separate TextEditPane xref cluster; it must not be merged into this target.
- The aggregate compact label is not an IDA/source name. It should be present for scanner/report consistency only.

## Exact Required Edits

Do not edit `by-memory/-coverage-report.md` directly from this B-agent assignment. The following is the exact supervisor-applicable repair text.

### Target Page: `by-memory/0x0069be08-0x0069be14.ThreadTimerSingletonAndTickGlobals.md`

Replace the title:

```markdown
# Thread And Timer Singleton/Tick Globals
```

with:

```markdown
# ThreadTimerSingletonAndTickGlobals - Thread And Timer Singleton/Tick Globals
```

Insert this summary bullet after the address range bullet:

```markdown
- Document label: `ThreadTimerSingletonAndTickGlobals` is the current generated filename/report label for this reviewed mixed coverage index; it is not a recovered original source variable name.
```

Replace this evidence bullet:

```markdown
- 2026-06-07 A004 Batch 056 attempted a fresh IDA MCP refresh for this cluster, but `py_eval`, `xrefs_to`, and `idb_meta` timed out. The split and score update therefore rely on already written IDA-backed global, file, and exact TimerMgr helper evidence rather than new live facts.
```

with:

```markdown
- 2026-06-14 B001 live IDA MCP recheck now confirms the split after the earlier timeout: `0x0069be08` has five refs in ThreadMan constructor/raw cleanup/clear/destructor paths (`0x00596c33`, `0x00596c3a`, `0x00596d5f`, `0x005974e0`, `0x00597532`); `0x0069be0c` has two refs (`0x004abad8`, `0x00597e80`), and `0x0069be10` has four refs (`0x004abad3`, `0x005977c4`, `0x00597e7b`, `0x00597e9c`) in TimerMgr/application timing paths. `0x0069be04` remains the predecessor TextEdit scratch word with eight unrelated refs, while `0x0069be14` begins the following WideApi dispatch pointer table with many unrelated refs. Current IDA bytes/global values are zeroed because the cluster lies in the `.data` virtual zero-fill tail.
```

Append this new change-log entry:

```markdown
- 2026-06-14 B001 memory-range advanced-scan audit recommendation:
  - Keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, score `86/88`, and blank C++.
  - Repair the scanner-visible compact label by adding exact `ThreadTimerSingletonAndTickGlobals` document text.
  - Replace the prior timed-out evidence note with current live IDA MCP xref/byte facts and PE zero-fill evidence.
  - Refresh the stale `by-memory/-coverage-report.md` row from `reconstructable : 80%` to reviewed non-reconstructable mixed-index wording.
```

### Shared Coverage Report: `by-memory/-coverage-report.md`

Replace the current [UID:0002AR] row:

```markdown
    - [UID:0002AR][0x0069be08-0x0069be14.ThreadTimerSingletonAndTickGlobals](by-memory/0x0069be08-0x0069be14.ThreadTimerSingletonAndTickGlobals.md) 0x0069be08-0x0069be14 | global-data cluster | ThreadTimerSingletonAndTickGlobals : reconstructable : 80% : strong : ThreadMan singleton pointer plus TimerMgr tick mirror globals.
```

with:

```markdown
    - [UID:0002AR][0x0069be08-0x0069be14.ThreadTimerSingletonAndTickGlobals](by-memory/0x0069be08-0x0069be14.ThreadTimerSingletonAndTickGlobals.md) 0x0069be08-0x0069be14 | mixed global-data coverage index | ThreadTimerSingletonAndTickGlobals : not_reconstructable : 86% : strong : Reviewed non-emitting mixed coverage index over exact child source declarations; [UID:000305][0x0069be08-0x0069be0c.g_pThreadMan](by-memory/0x0069be08-0x0069be0c.g_pThreadMan.md) carries the ThreadMan singleton pointer through `g_pThreadMan`/`Thread`, while [UID:000306][0x0069be0c-0x0069be10.TimerMgrTickBaselineMirror](by-memory/0x0069be0c-0x0069be10.TimerMgrTickBaselineMirror.md) and [UID:000307][0x0069be10-0x0069be14.TimerMgrCurrentTickMirror](by-memory/0x0069be10-0x0069be14.TimerMgrCurrentTickMirror.md) carry TimerMgr tick mirrors; live IDA confirms split xref sets and clean predecessor/successor boundaries.
```

### Generated Coverage Report

No replacement is needed for `auto-generated/-ag-memory-coverage.md`; the current generated row already has the correct non-reconstructable/no-owner/non-emitting state:

```markdown
| [UID:0002AR][0x0069be08-0x0069be14.ThreadTimerSingletonAndTickGlobals](by-memory/0x0069be08-0x0069be14.ThreadTimerSingletonAndTickGlobals.md) | not_reconstructable | `NONE` |  |  | no |  | `by-memory/0x0069be08-0x0069be14.ThreadTimerSingletonAndTickGlobals.md` |  |
```

## Follow-Up Actions

Supervisor actions:

- Apply the exact target-page text repair if accepted.
- Apply the exact `by-memory/-coverage-report.md` row replacement if accepted.
- Validate the target page and shared coverage report after applying edits.
- Regenerate `auto-generated/by-memory-tool-report.md` and confirm the `ThreadTimerSingletonAndTickGlobals` warning clears.

A-agent actions:

- None required before supervisor repair. Exact child pages are already present and assigned.

B001 future research actions:

- None for this target after supervisor repair unless later evidence changes the TimerMgr tick mirror names or source-file split.

## Validation / Lease State

- Files edited by Agent-B001 in this assignment: this research report only.
- No by-* files were edited, per assignment instruction.
- `by-memory/-coverage-report.md` was not edited directly.
- Normal validator was not run because no in-scope by-* documentation file was changed by this agent; supervisor should run normal file validation after applying the recommended target/shared-report edits.
- Report-only checks: ASCII check passed; trailing whitespace check passed; report file exists at the required Agent-B001 research-root path.
- Lease state before report creation: `tools/leaser/Agents/current_leases.md` showed no active leases.
- Closeout lease check: `tools/leaser/Agents/current_leases.md` shows no active leases; targeted search found no Agent-B001, target-page, or `by-memory/-coverage-report.md` lease.
- Lease acquired: none, because only the B001 research report was created.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B001/research/0002AR-ThreadTimerSingletonAndTickGlobals-memory-range-report.md`
- Modified: none outside this report.
- Renamed: none.
- Moved to executed: none.

## Confidence

- Label/text repair: `95/95`. The scanner complaint is exact, and the target page lacks the compact token.
- Range boundary: `92/92`. Live IDA xrefs isolate `0x0069be08-0x0069be14` between unrelated TextEdit and WideApi table neighbors.
- Mixed-index disposition: `91/90`. The target is split into exact children with distinct source owners; by-structure rules support `RECONSTRUCTABLE:FALSE` for the aggregate.
- Child ownership split: `90/88`. ThreadMan and TimerMgr child routes are directly supported by writer/xref evidence and current owner docs.
- Final source names/declarations: `78/82`. `g_pThreadMan` is strong as a role name, but exact static linkage remains provisional; TimerMgr tick mirror names remain descriptive documentation labels rather than recovered source identifiers.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0002AR-ThreadTimerSingletonAndTickGlobals-memory-range-report.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:21","uid":"0002AR"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
