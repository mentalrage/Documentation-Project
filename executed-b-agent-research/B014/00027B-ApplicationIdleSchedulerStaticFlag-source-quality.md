** TARGET-REPORT-UID:00027B **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00027B ApplicationIdleSchedulerStaticFlag Source-Quality Research

Agent: Agent-B014
Assignment: B014-report-00027B-application-idle-scheduler-static-flag-source-quality-20260626
Report status: IMPLEMENTATION CALLBACK APPLIED / READY FOR SUPERVISOR VERIFICATION
Target from goal.md: [UID:00027B] by-memory/0x0066d880-0x0066d888.ApplicationIdleSchedulerStaticFlag.md

## Executive Recommendation

Accept [UID:00027B] as a source-ready EventDispatcher-private initialized `bool` plus linker/alignment padding. The remaining blank-C++ blocker can be resolved now: current IDA MCP evidence proves the byte value, confined references, one-shot clear, scheduler behavior, and adjacent EventMan table boundary tightly enough to emit the source declaration.

Recommended final metadata:

| Field | Current target doc | Recommendation |
|---|---:|---:|
| `COMPLETION` | `85` | `90` |
| `CONFIDENCE` | `88` | `91` |
| `CANONICAL_OWNER` | `0000J7` | `0000J7` |
| `EMITTER_UIDS` | `0000J7` | `0000J7` |
| `EMITTER_POSITION_OPTIONAL` | blank | `0` |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` |

Final source-facing name:

`s_idleTimerSetupPending`

Formal `RECONSTRUCTION_CPP CODE` recommendation for the target:

```cpp
static bool s_idleTimerSetupPending = true;
```

The seven bytes at `0x0066d881-0x0066d888` are not source declarations. They should stay documented as zero padding/alignment before the separate EventMan key-translation table at `0x0066d888`.

## Current Repository State

[UID:00027B] currently has `COMPLETION:85`, `CONFIDENCE:88`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000J7`, `EMITTER_UIDS:0000J7`, blank `EMITTER_POSITION_OPTIONAL`, and blank formal C++. The page already documents the main facts, but it still calls the source names provisional and leaves C++ blank because the final variable name and `ApplicationHelper_4A6C40` versus possible `MessageLoopScheduler` source split were unresolved.

Generated state is stale relative to the current by-* target:

| Generated or supervisor-owned artifact | Observed state |
|---|---|
| `auto-generated/-ag-research-tracker.md` | UID `00027B` still listed as `78/86`, blank code |
| `auto-generated/-ag-coverage-report-by-memory.md` | UID `00027B` still listed as `78%`, `emits_code:false` |
| `auto-generated/-ag-memory-coverage.md` | Routes UID `00027B` as emitting through [UID:0000J7] to `auto-generated/NexusTK/ui/core/EventDispatcher.cpp` |
| `auto-generated/NexusTK/ui/core/EventDispatcher.cpp` | Has an empty marker for UID `00027B`, stale `Completion:78`, `Confidence:86`; marker currently appears after UID `000142` |
| `by-memory/-coverage-report.md` | Manual row still lists UID `00027B` as `78%` |

Generated/project-level/manual coverage files were read as evidence only. They were not edited.

## Evidence Sources Read

Primary target and directly related docs:

| Path | Evidence used |
|---|---|
| `by-memory/0x0066d880-0x0066d888.ApplicationIdleSchedulerStaticFlag.md` | Current metadata, byte/padding layout, provisional names, C++ blocker |
| `by-memory/0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler.md` | Companion scheduler behavior, EventDispatcher source route, field offsets `+0x2c` and `+0x30` |
| `by-memory/0x004a7120-0x004a712c.ApplicationIdleTickBaseline.md` | Baseline snapshot helper and field-name coordination |
| `by-file/EventDispatcher.md` | Source-file owner for idle scheduler helpers |
| `by-class/EventDispatcher.md` | EventDispatcher class context and rejection of standalone `ApplicationHelper_4A6C40` ownership |
| `by-class/ApplicationHelper_4A6C40.md` | Generated wrapper/grouping page; current row still names UID `00027B` provisionally |
| `by-file/Application.md` | Application owns `RunMessageLoop` call sites only |
| `by-memory/0x00464cd0-0x00464e1f.ApplicationRunMessageLoop.md` | Caller route into the idle helpers |
| `by-file/Event.md` | Event/EventMan ownership of successor key tables |
| `by-memory/0x0066d888-0x0066da88.EventManKeyTranslationTables.md` | Successor table boundary and EventMan constructor copy xref |
| `by-project-structure/proposed-source-tree.md` | Confirms `EventDispatcher.cpp` as current placement for `ApplicationHelper_4A6C40` scheduler helpers |

Executed B-agent reports used as leads and rechecked:

| Report | Relevant accepted context |
|---|---|
| `executed-b-agent-research/B001/000141-EventDispatcher-source-quality.md` | EventDispatcher aggregate route, `EventDispatcher::ProcessIdleWork()` name, generated-wrapper rejection |
| `executed-b-agent-research/B001/000143-application-idle-tick-baseline-source-quality.md` | Companion baseline helper, field names, provisional UID `00027B` names |
| `executed-b-agent-research/B012/00004M-EventDispatcher-class-source-quality.md` | EventDispatcher class/source-file ownership and no standalone ApplicationHelper class |
| `executed-b-agent-research/B015/0001KA-TimerMgrQueueHelpers-source-quality.md` | `TimerMgr::BeginTimerPeriod()` and `TimerMgr::RefreshCurrentTick()` names for the two timer callees |

## IDA MCP Availability

IDA MCP was available and used for this report.

| Field | Value |
|---|---|
| Endpoint | `http://127.0.0.1:13337/mcp` |
| Active session | `80de0a67` |
| IDB path | `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` |
| Module | `NexusTK.exe` |
| Input path | `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` |
| Imagebase | `0x400000` |
| Auto-analysis | ready |
| Hex-Rays | ready |
| Strings cache | ready, 2067 strings |

No fallback-only report was produced.

## IDA MCP Findings

### Bytes, Padding, and Boundary

MCP `get_bytes` and `get_int` reconfirm:

| Address/range | Bytes or value | Meaning |
|---|---|---|
| `0x0066d880-0x0066d888` | `01 00 00 00 00 00 00 00` | Target range: initialized byte `true` plus seven zero bytes |
| `0x0066d880` | unsigned byte `1` | Source `bool` initial value |
| `0x0066d881` | unsigned byte `0` | First padding byte |
| `0x0066d887` | unsigned byte `0` | Last padding byte before successor |
| `0x0066d888` | unsigned byte `0`; following bytes `00 1b 31 32 33 34 35 36 ...` | Start of separate EventMan key table |

`0x8` is 8 bytes, `0x7` is 7 bytes, and `0x100` is 256 bytes (Verified with `int_convert.py`). The first dword at `0x0066d880` is `0x00000001`, but all current code references use byte operands, so the correct source type is `bool`, not `int`, `DWORD`, or `BOOL`.

MCP `xrefs_to` reconfirm:

| Target | Xrefs |
|---|---|
| `0x0066d880` | exactly three data xrefs: `0x004a6c4f`, `0x004a6c77`, `0x004a6c92`, all in `sub_4A6C40` |
| `0x0066d881` | zero xrefs |
| `0x0066d887` | zero xrefs |
| `0x0066d888` | one data xref: `0x004a8cfd` in `sub_4A8B40` |

This proves a clean split:

- `0x0066d880-0x0066d881`: source byte declaration;
- `0x0066d881-0x0066d888`: padding/alignment, no source item and no xrefs;
- `0x0066d888`: start of independent EventMan key translation tables.

### Scheduler Function

MCP `lookup_funcs 0x004a6c40` reports `sub_4A6C40`, size `0x9b` / 155 bytes (Verified with `int_convert.py`). MCP `analyze_function` reports 8 basic blocks, cyclomatic complexity 4, callers from `sub_464CD0`, and callees:

`sub_469200`, `sub_597E40`, `sub_5977B0`, `sub_4A7E70`, `sub_597E90`, and `sub_4B6F60`.

Relevant disassembly facts:

| Address | Instruction role |
|---|---|
| `0x004a6c4f` | compares the flag byte against zero before timer-period setup |
| `0x004a6c5e` | calls `0x00597e40` only when the flag is set |
| `0x004a6c6a` | dispatches queued TimerMgr work |
| `0x004a6c72` | rebuilds EventDispatcher traversal state through `this + 4` |
| `0x004a6c77` | compares the same flag byte again |
| `0x004a6c86` | calls `0x00597e90` on the second flag-true path |
| `0x004a6c92` | clears the flag byte to zero |
| `0x004a6c99-0x004a6c9f` | copies TimerMgr current tick into EventDispatcher `+0x2c` and clears EventDispatcher `+0x30` |
| `0x004a6cbb-0x004a6cc1` | computes elapsed tick buckets by dividing by `0x14` / 20 (Verified with `int_convert.py`) |
| `0x004a6cd0-0x004a6cd5` | dispatches changed idle/frame slice and stores the new slice at `+0x30` |

The two field offsets are `0x2c` / 44 and `0x30` / 48 (Verified with `int_convert.py`), matching current support docs as `m_idleTickBaseline` and `m_lastDispatchedIdleSlice`.

### Caller Route

MCP `xrefs_to 0x004a6c40` reports exactly two code xrefs:

| Call site | Owner context |
|---|---|
| `0x00464df7` | `Application::RunMessageLoop` calls idle work after the message queue drains |
| `0x00464e0e` | `Application::RunMessageLoop` calls idle work after wait timeout/default idle path |

MCP disassembly of `0x00464cd0` shows both call sites load `ecx` from `unk_67AB30` / `g_pEventDispatcher` immediately before calling `sub_4A6C40`. The same function calls `sub_4A7120` once at `0x00464ce1` after loading the same pointer. This makes Application the caller/scheduling site, not the owner of the state byte.

### TimerMgr Callees

MCP confirms the timer helper semantics:

| Address | Current source-facing role | Evidence |
|---|---|---|
| `0x00597e40-0x00597e8a` | `TimerMgr::BeginTimerPeriod()` | Calls `timeGetDevCaps`, clamps the period, calls `timeBeginPeriod`, reads `timeGetTime`, writes TimerMgr `+0x18` and `+0x1c`, and writes tick mirrors |
| `0x00597e90-0x00597ea3` | `TimerMgr::RefreshCurrentTick()` | Calls `timeGetTime`, writes TimerMgr `+0x18`, and updates the current-tick mirror |

The helper sizes are `0x4a` / 74 and `0x13` / 19 (Verified with `int_convert.py`). This supports a setup/pending name for UID `00027B`, not a generic EventMan, Application, or recurring dirty flag name.

### EventMan Successor Boundary

MCP `analyze_function 0x004a8b40` and disassembly show the EventMan constructor copies the table beginning at `0x0066d888`:

- `0x004a8cfd`: pushes source `0x0066d888`;
- `0x004a8d13`: calls the copy helper with size `0x100` / 256 (Verified with `int_convert.py`);
- `0x004a8d1d`: separately pushes source `0x0066d988` for the next `0x100`-byte table.

The `0x0066d888` table therefore starts immediately after UID `00027B` and is not padding belonging to the flag.

## Source-Quality Analysis

### Source Placement

Accepted placement: private/file-local storage in `NexusTK/ui/core/EventDispatcher.cpp`, owned and emitted by [UID:0000J7] `EventDispatcher`.

Reasoning:

- All three xrefs to the byte are inside the EventDispatcher idle-work helper at `0x004a6c40`.
- The only callers of that helper are Application message-loop idle sites, but they pass `g_pEventDispatcher` in `ecx`; Application does not read, write, or own the byte.
- The helper writes EventDispatcher state offsets `+0x2c` and `+0x30`, and calls EventDispatcher traversal rebuild through `this + 4`.
- The proposed source tree already places the `ApplicationHelper_4A6C40` scheduler cluster under `ui/core/EventDispatcher.cpp`.
- No evidence proves a separate `MessageLoopScheduler` class/file. That remains a possible future source-organization split, not a current owner.

Rejected placements:

| Candidate | Reason rejected |
|---|---|
| `Application.cpp` | Application has caller control flow only; no direct byte access and no ownership of EventDispatcher fields |
| `ApplicationHelper_4A6C40` class/file | Generated grouping label; no allocation, vtable, layout, or source-file evidence |
| `MessageLoopScheduler` class/file | Plausible conceptual name but unproven; no separate object or storage cluster |
| `TimerMgr.cpp` | TimerMgr functions are callees; the flag is not a TimerMgr field or global |
| `Event.cpp` / `EventMan` | Only the successor table at `0x0066d888` belongs to EventMan |
| New `by-global` page | Current by-memory page already owns the exact source declaration plus padding boundary |

### Final Name Selection

Accepted name: `s_idleTimerSetupPending`.

Reasoning:

- `s_`: the byte is private to the EventDispatcher idle scheduler in current xref evidence; no external read, write, or address-taken use was found.
- `idleTimer`: the flag is used by the message-loop idle scheduler, not by general TimerMgr queue code or EventMan input tables.
- `SetupPending`: the byte is initialized `true`, checked twice during the first idle-work pass, then cleared to zero with no static setter back to one. It gates initial timer-period setup, current-tick refresh, and baseline/slice reset. A recurring "dirty" or broad "needs refresh" name overstates the observed lifecycle.

Rejected source names:

| Candidate | Reason rejected |
|---|---|
| `byte_66D880` | IDA storage label only; unacceptable as final source name |
| `g_timerResolutionNeedsRefresh` | Existing generated/provisional name; `g_` overstates visibility, `resolution` is weaker than the project TimerMgr term `timer period`, and "needs refresh" implies a recurring setter that does not exist |
| `g_idleTimerResolutionDirty` | `dirty` implies repeated invalidation/re-dirty behavior; no setter is present |
| `s_timerPeriodSetupPending` | Close alternate, but too TimerMgr-specific and hides the EventDispatcher idle-baseline reset side effect |
| `s_messageLoopSchedulerInitialized` | Polarity is reversed and it hides the TimerMgr/baseline setup behavior |
| `ApplicationIdleSchedulerStaticFlag` | Documentation title, not a source variable name |

### C++ Readiness

Formal C++ is now safe for this target:

- The target is reconstructable, has nonblank owner/emitter route, and clears the active code-entry gate.
- The exact source declaration is one byte: MSVC `bool` matches the byte-sized compare and write instructions.
- Initial value is direct MCP data (`1`).
- All references are confined to one EventDispatcher helper.
- The seven trailing bytes have no xrefs and should not be represented as a source array.
- `EMITTER_POSITION_OPTIONAL:0` should be set so this static declaration appears before any future formal `ProcessIdleWork()` code that reads it. This follows the project precedent for source-data declaration pages that must be emitted before consuming helper bodies.

The confidence should stay below final-audit range because no original source symbol was recovered, and a future source-organization pass could still introduce a small message-loop helper within `EventDispatcher.cpp`. That does not block the current formal declaration.

## Recommended Target-Doc State After Callback

[UID:00027B] should be updated to:

- metadata `COMPLETION:90`, `CONFIDENCE:91`, `EMITTER_POSITION_OPTIONAL:0`;
- source-facing name `s_idleTimerSetupPending`;
- formal C++ block exactly as shown in the executive recommendation;
- statement that only `0x0066d880-0x0066d881` is the source byte and `0x0066d881-0x0066d888` is padding;
- current MCP evidence for bytes, xrefs, scheduler behavior, caller route, and EventMan successor boundary;
- explicit rejection of `byte_66D880`, `g_timerResolutionNeedsRefresh`, `g_idleTimerResolutionDirty`, Application ownership, `ApplicationHelper_4A6C40` source ownership, and unproven standalone `MessageLoopScheduler` ownership.

Suggested replacement `Item Summary`:

`Source-ready EventDispatcher-private one-byte idle-timer setup flag plus padding: formal declaration is static bool s_idleTimerSetupPending = true; exact MCP bytes are 01 00 00 00 00 00 00 00, three xrefs are confined to EventDispatcher::ProcessIdleWork, padding has no xrefs, and 0x0066d888 starts the separate EventMan key table.`

## Recommended Support-Doc State After Callback

| Document | Required update |
|---|---|
| `by-file/EventDispatcher.md` | Add `s_idleTimerSetupPending` to the EventDispatcher idle scheduler/file-local storage notes; state it is emitted before idle helper bodies and is not an object field |
| `by-class/EventDispatcher.md` | Add a class-context note that the flag is EventDispatcher.cpp private static storage used by `ProcessIdleWork()`, not `EventDispatcher` instance layout |
| `by-memory/0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler.md` | Replace provisional `g_timerResolutionNeedsRefresh` / `g_idleTimerResolutionDirty` language with final `s_idleTimerSetupPending`; preserve exact xref addresses and timer/baseline behavior |
| `by-memory/0x004a7120-0x004a712c.ApplicationIdleTickBaseline.md` | Update companion state vocabulary so the baseline helper references the same final flag name when discussing UID `00027B` |
| `by-class/ApplicationHelper_4A6C40.md` | Update the UID `00027B` child row from provisional names to final `s_idleTimerSetupPending`; retain generated-wrapper rejection |
| `by-file/Application.md` | Ensure Application is documented as caller/message-loop owner only, not owner of the flag |
| `by-file/Event.md` | If touched, note the predecessor `0x0066d880-0x0066d888` is EventDispatcher idle scheduler storage/padding and the EventMan table starts at `0x0066d888` |
| `by-memory/0x0066d888-0x0066da88.EventManKeyTranslationTables.md` | If current text uses only raw predecessor names, update the boundary note to reference `s_idleTimerSetupPending` as the predecessor source byte while preserving the `0x0066d888` table start |
| `by-memory/0x0066d47c-0x0066d880.ChecksumLookupTablesData.md` | Optional boundary cleanup only if callback scope includes it: replace successor raw-label wording with "successor EventDispatcher idle timer setup flag at `0x0066d880`"; no owner/range change |

No split, file rename, new by-global page, or owner/emitter change is recommended.

## Manual Coverage Row Recommendation

Do not edit `by-memory/-coverage-report.md` in this report-only phase. If the supervisor applies a manual coverage sync after implementation, replace the current UID `00027B` row with:

```markdown
    - [UID:00027B][0x0066d880-0x0066d888.ApplicationIdleSchedulerStaticFlag](by-memory/0x0066d880-0x0066d888.ApplicationIdleSchedulerStaticFlag.md) 0x0066d880-0x0066d888 | global flag plus padding | ApplicationIdleSchedulerStaticFlag : reconstructable : 90% : very-strong : B014 source-quality pass resolves this as the EventDispatcher.cpp private `static bool s_idleTimerSetupPending = true` declaration plus seven zero padding bytes before the EventMan key table; live IDA MCP session `80de0a67` confirms bytes `01 00 00 00 00 00 00 00`, exactly three scheduler xrefs at `0x004a6c4f`, `0x004a6c77`, and `0x004a6c92`, no padding-byte xrefs, Application::RunMessageLoop caller route through `g_pEventDispatcher`, timer-period/current-tick setup via TimerMgr, baseline/slice reset at EventDispatcher `+0x2c/+0x30`, and separate successor table start at `0x0066d888`.
```

Generated tracker/coverage reports should be refreshed by validator/executed-report workflow, not manually edited.

## Recommended Validation After Callback

Run scoped validators from `source-3/project-documentation` for each edited by-* file, for example:

> Executable block R001 was removed from this report and preserved verbatim in [00027B-ApplicationIdleSchedulerStaticFlag-source-quality-removed.md](00027B-ApplicationIdleSchedulerStaticFlag-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Only run validators for files actually edited. If the callback includes manual `by-memory/-coverage-report.md` authority, validate that file separately under the supervisor's explicit coverage-report scope.

After validation/generation, inspect `auto-generated/NexusTK/ui/core/EventDispatcher.cpp` to confirm UID `00027B` emits `s_idleTimerSetupPending` before any future UID `000142` helper body that references it. If generated order is still wrong despite `EMITTER_POSITION_OPTIONAL:0`, fix emitter placement rather than reverting the target to blank C++.

## Files Changed In This Pass

Implementation callback edited these by-* documentation files:

- `by-memory/0x0066d880-0x0066d888.ApplicationIdleSchedulerStaticFlag.md`
- `by-file/EventDispatcher.md`
- `by-class/EventDispatcher.md`
- `by-memory/0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler.md`
- `by-memory/0x004a7120-0x004a712c.ApplicationIdleTickBaseline.md`
- `by-class/ApplicationHelper_4A6C40.md`
- `by-memory/0x0066d888-0x0066da88.EventManKeyTranslationTables.md`
- `by-memory/0x0066d47c-0x0066d880.ChecksumLookupTablesData.md`

This report was also updated with implementation proof. No manual `-coverage-report.md`, IDA DB, or generated file edits were made. Validator command `000000003081` performed the required generated refresh and updated validator-managed generated/project-level state.

Reviewed but not edited:

- `by-file/Application.md`: current text already keeps Application as the `RunMessageLoop` caller and routes the idle helpers through EventDispatcher.
- `by-file/Event.md`: current Event/EventMan ownership remains correct; the predecessor-boundary sync was applied to the exact EventMan key-table by-memory page instead.

## Implementation Proof

Leases:

- Acquired short leases for the eight edited by-* files with `python .\tools\leaser\leaser.py B014 lease ...`; every path returned `Success`.
- Release step was run after the validator batch for the same eight paths. The leaser returned `Rejected[No active lease]` for each path because no B014 lease remained active by then; `tools/leaser/Agents/current_leases.md` showed no B014 entries afterward.

Validator results from `source-3/project-documentation`:

| Command ID | Timestamp | File | Exit | Generated refresh |
|---|---|---|---:|---|
| `000000003073` | `2026-06-26T17:28:09-04:00` | `by-file/EventDispatcher.md` | 0 | deferred |
| `000000003074` | `2026-06-26T17:28:18-04:00` | `by-class/EventDispatcher.md` | 0 | deferred |
| `000000003076` | `2026-06-26T17:28:24-04:00` | `by-memory/0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler.md` | 0 | deferred |
| `000000003077` | `2026-06-26T17:28:41-04:00` | `by-memory/0x004a7120-0x004a712c.ApplicationIdleTickBaseline.md` | 0 | deferred |
| `000000003078` | `2026-06-26T17:28:52-04:00` | `by-class/ApplicationHelper_4A6C40.md` | 0 | deferred |
| `000000003079` | `2026-06-26T17:29:06-04:00` | `by-memory/0x0066d888-0x0066da88.EventManKeyTranslationTables.md` | 0 | deferred |
| `000000003080` | `2026-06-26T17:29:12-04:00` | `by-memory/0x0066d47c-0x0066d880.ChecksumLookupTablesData.md` | 0 | deferred |
| `000000003081` | `2026-06-26T17:29:22-04:00` | `by-memory/0x0066d880-0x0066d888.ApplicationIdleSchedulerStaticFlag.md` | 0 | completed with `--wait-generated` |

Known validator noise: existing missing/stale registry targets were reported for unrelated historical Event/EventMan paths and generated registry entries. All scoped file validators returned `ok: 1`.

Generated output proof:

- `auto-generated/NexusTK/ui/core/EventDispatcher.cpp` was refreshed by validator command `000000003081`.
- Lines 7-8 now contain UID `00027B` followed by `static bool s_idleTimerSetupPending = true;`.
- The declaration appears before later EventDispatcher helper emissions, satisfying `EMITTER_POSITION_OPTIONAL:0`.

## Implementation Tracking Checklist

- [x] Supervisor validates this report and authorizes implementation.
- [x] Acquire short leases only for callback-authorized by-* files that will be edited immediately.
- [x] Update [UID:00027B] metadata to `COMPLETION:90`, `CONFIDENCE:91`, `EMITTER_POSITION_OPTIONAL:0`, keeping owner/emitter [UID:0000J7].
- [x] Update [UID:00027B] source-facing name to `s_idleTimerSetupPending` and demote `byte_66D880`, `g_timerResolutionNeedsRefresh`, and `g_idleTimerResolutionDirty` to rejected/provisional aliases.
- [x] Populate [UID:00027B] formal C++ exactly as `static bool s_idleTimerSetupPending = true;`.
- [x] Update [UID:00027B] evidence for bytes, byte type, padding, xrefs, Application caller route, scheduler behavior, TimerMgr helper names, EventDispatcher field resets, and EventMan successor table boundary.
- [x] Update `by-file/EventDispatcher.md` with the private EventDispatcher.cpp static storage and early-emitter-order note.
- [x] Update `by-class/EventDispatcher.md` to state this flag is not an instance field but is used by the EventDispatcher idle scheduler.
- [x] Update [UID:000142] `ApplicationIdleWorkScheduler` with the final flag name and preserve the exact xref/scheduler behavior.
- [x] Update [UID:000143] `ApplicationIdleTickBaseline` companion wording to use the final flag name where it discusses UID `00027B`.
- [x] Update `by-class/ApplicationHelper_4A6C40.md` child matrix/prose to remove provisional-name wording for UID `00027B` and retain wrapper rejection.
- [x] Update `by-file/Application.md` only for caller-only clarification if current text leaves ambiguity. No edit needed; current text was already caller-only.
- [x] Update EventMan/key-table support docs if current wording needs predecessor-boundary sync; do not move ownership from EventMan for UID `00027C`.
- [x] Optionally update the predecessor checksum-table boundary doc if callback scope explicitly includes raw-label cleanup.
- [x] Do not manually edit generated reports, project-level generated files, manual `-coverage-report.md` files, validator/tool state, or IDA DB. Validator-managed generated refresh occurred under command `000000003081`.
- [x] Run scoped validators for each edited by-* file from `source-3/project-documentation`.
- [x] Record validator command IDs, timestamps, exit codes, and generated-refresh state in the implementation result.
- [x] Confirm generated EventDispatcher output has the UID `00027B` declaration in a valid order.
- [x] Release leases immediately after the edit/validator batch; explicit unlease found no active B014 leases remaining.
- [ ] Supervisor executes the accepted report through the documented validator `execute_report` workflow after verification.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B014","command_id":"000000004165","destination_path":"executed-b-agent-research/B014/00027B-ApplicationIdleSchedulerStaticFlag-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B014/research/00027B-ApplicationIdleSchedulerStaticFlag-source-quality.md","timestamp":"2026-06-26T17:32:59","uid":"00027B"} -->
<!-- {"agent":"B014","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00027B-ApplicationIdleSchedulerStaticFlag-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B014/00027B-ApplicationIdleSchedulerStaticFlag-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00027B"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
