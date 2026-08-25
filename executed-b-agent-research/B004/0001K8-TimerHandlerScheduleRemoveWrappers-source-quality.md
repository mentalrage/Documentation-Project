** TARGET-REPORT-UID:0001K8 **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001K8 TimerHandlerScheduleRemoveWrappers Source-Quality Report

Agent: B004  
Assignment: `B004-report-timerhandler-schedule-remove-wrappers-source-quality-0001K8-mcp-20260623`  
Date: 2026-06-23  
MCP session: `ff68e691`  
Target: [UID:0001K8] `by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md`

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0001K8] at `COMPLETION:86`, `CONFIDENCE:86`, `CANONICAL_OWNER:0000F0`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000F0`, blank `EMITTER_POSITION_OPTIONAL`, and keep the existing first-draft TimerHandler wrapper C++.
- Final disposition: current MCP session `ff68e691` revalidates the two exact wrapper functions, the byte/padding fences, the high direct code caller fan-in, the `g_pTimerMgr` forwarding route, and the exact manager callee targets. This is a live TimerHandler wrapper pair, not an InterfaceEfx/FittingRoom consumer, not a TimerMgr method body, and not a pointer-table/vtable-dispatched callback.
- Required action if accepted: incorporate a 2026-06-23 B004 current-session evidence section into the target and synchronize support docs that still only carry older raw-IDA/B014/B013 wording. Preserve the current score cap because MCP freshness does not prove original method spellings, the final TimerHandler source-file split, or that the original declarations were exactly `void` rather than status-returning wrappers whose return values were unused.
- Confidence: high for binary behavior, exact split, xrefs, callee routes, and owner family; medium-high for source-facing names/signatures.

## Supporting Research

## Target

- Target UID: `0001K8`.
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md`.
- Source queue/report row: `project-level/-auto-completion-stats.md` lists [UID:0001K8] as a low-score reconstructable by-memory target at `86/86`.
- Current supervisor classification: report-only MCP-backed recheck after the current [UID:0001K6] TimerMgr aggregate refresh.
- Current scores and parent state: target `86/86`, direct owner/emitter [UID:0000F0] `TimerHandler`, reconstructable true. The source-family container is [UID:0000OT] `TimerMgr.cpp`; parent aggregate [UID:0001K6] remains `85/87` with blank aggregate C++ after the accepted B004 refresh.

## Current Target State

- Existing metadata: `COMPLETION:86`, `CONFIDENCE:86`, `CANONICAL_OWNER:0000F0`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000F0`, blank `EMITTER_POSITION_OPTIONAL`.
- Existing owner/emitter/reconstructable state: direct semantic owner and emitted class methods are [UID:0000F0] `TimerHandler`; source-family context is [UID:0000OT] `TimerMgr.cpp`.
- Existing C++/emitter state: target already has source-shaped first-draft C++ for `TimerHandler::ScheduleTimer(int timerId, unsigned int delayMs, int arg0, int arg1)` and `TimerHandler::RemovePendingTimers()`. Generated `auto-generated/NexusTK/util/TimerMgr.cpp` emits the same block for [UID:0001K8].
- Existing open questions/blockers: exact original method spellings are inferred, `TimerHandler.cpp` versus `TimerMgr.cpp` source-file split remains unresolved, and IDA/Hex-Rays report raw `int` wrappers because the manager callee return value remains in `EAX`. The current source-shaped `void` wrapper interpretation is still the best source model but is not original-proof.
- Related target/support docs checked: target page, [UID:0001K6] parent aggregate, [UID:000418] callback-shaped neighbor, [UID:0000F0] `by-class/TimerHandler.md`, [UID:0000OT] `by-file/TimerMgr.md`, [UID:0000F1] `by-class/TimerMgr.md`, [UID:00041D] `TimerMgrScheduleTimer`, [UID:00041E] `TimerMgrRemovePendingTimersForOwner`, `by-global/g_pTimerMgr.md`, generated `auto-generated/NexusTK/util/TimerMgr.cpp`, `project-level/-auto-completion-stats.md`, `by-memory/-coverage-report.md`, and executed B004 report `0001K6-TimerMgrAndTimerQueue-source-quality.md`.

## Executive Recommendation

Keep the target as a single exact child covering two TimerHandler wrapper methods. Do not split, merge, rename, or reclassify it. The range is small, exact, and intentionally groups paired owner-facing wrapper methods that forward TimerHandler calls into the TimerMgr singleton.

Keep score/metadata unchanged at `86/86`. Current MCP removes stale evidence wording but does not remove the remaining source-quality cap: original source spellings and source-file placement remain inferred, and raw decompiler `int` signatures still need to be explained rather than blindly overwritten as original proof.

Keep the current first-draft C++ block. It is source-shaped and behavior-preserving because both raw functions are pure forwarders through `g_pTimerMgr`; however, the support docs should make the raw `int`/source `void` distinction explicit.

## Supervisor Active Recheck

- Trigger: supervisor assigned a report-only MCP-backed source-quality recheck for [UID:0001K8], focusing on the two TimerHandler schedule/remove wrappers after the current [UID:0001K6] refresh.
- MCP result: endpoint `http://127.0.0.1:13337/mcp`, active IDB session `ff68e691`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- Session details from `idb_list`: one active/adopted worker-backed database session `ff68e691`, `is_analyzing:false`, `is_active:true`, filename `NexusTK.exe.i64`, worker PID `14256`.
- Executable provenance: local mirror `E:\NTK\Resources\NexusTK\NexusTK.exe` has SHA-256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`, size `2679296`, last write `2025-12-11 11:24:42`.
- Split status: no split repair is needed. MCP confirms `sub_5975E0` size `0x1f`, `sub_597600` size `0x0d`, no function at separator `0x005975ff`, and no function at end fence `0x0059760d`.
- Report-only status: no leases were taken and no by-* docs, coverage reports, generated files, tool state, or IDA DB files were edited.

## Inference Research Guidance Check

The B-agent workflow was applied by separating IDA facts, documentation evidence, and source-shape inference:

- IDA facts: function starts/sizes, bytes, disassembly, Hex-Rays output, xrefs, callees, data xref negatives, byte-pattern pointer negatives, and `g_pTimerMgr` loads.
- Documentation evidence: target/support pages, accepted [UID:0001K6] parent report, generated source output, project stats, and coverage row.
- Inference: source-facing wrapper names, `void` method signatures, TimerHandler source placement within or near `TimerMgr.cpp`, and whether the source had a standalone `TimerHandler.cpp`.

No current Wave2/Wave3 instruction applies. Stale caller-biased owner names such as `InterfaceEfx::RemoveFromUpdateScheduler` and `FittingRoomDialog::ScheduleTimer` remain rejected as consumer/call-site names, not source ownership.

## Heuristic / Inference Reanalysis And Validation

1. Function boundary: MCP confirms two real functions inside the target and padding around them. The first wrapper starts at `0x005975e0`, ends before one `cc` byte at `0x005975ff`, and has IDA size `0x1f` / 31. The second starts at `0x00597600`, ends at `0x0059760d`, and has IDA size `0x0d` / 13.
2. Wrapper semantics: the schedule wrapper pushes four explicit stack arguments plus `this`, loads `g_pTimerMgr` from `0x0067ab80` into `ecx`, and calls `0x00597910`. The remove wrapper pushes `this`, loads `g_pTimerMgr`, and calls `0x00597a10`.
3. Caller fan-in: MCP reports 163 code xrefs to `0x005975e0` and 45 code xrefs to `0x00597600`. This supports a common base TimerHandler API consumed by many panes/effects/controllers.
4. TimerHandler versus TimerMgr source split: the wrappers are TimerHandler methods semantically, but they live in the TimerMgr source family and generated output currently places them in `auto-generated/NexusTK/util/TimerMgr.cpp`. Best documentation wording is direct owner [UID:0000F0], source-family [UID:0000OT], final source-file split unresolved.
5. `void` versus raw `int`: Hex-Rays prints both functions as `int __thiscall` because each wrapper returns immediately after the manager call and leaves the callee value in `EAX`. The raw machine code does not construct a wrapper status result; it only performs the side-effecting schedule/remove operation. Existing target C++ uses `void`, which is the best source-shaped form, but the raw `int` decompiler artifact should be documented as a confidence cap.
6. Manager callee routes: `0x005975e0` has one internal callee, [UID:00041D] `0x00597910` `TimerMgrScheduleTimer`; `0x00597600` has one internal callee, [UID:00041E] `0x00597a10` `TimerMgrRemovePendingTimersForOwner`.
7. Pointer/vtable/table routes: current MCP reports zero data xrefs to either wrapper entry. Bounded byte-pattern searches for VA/RVA/raw-offset encodings of `0x005975e0` and `0x00597600` also found zero matches. The wrapper pair is reached by direct calls, not vtable or callback-table entries.
8. Generated output state: generated `TimerMgr.cpp` already emits first-draft C++ for [UID:0001K8], while parent aggregate [UID:0001K6] remains blank. This supports keeping C++ on the exact child page rather than adding aggregate C++.
9. Score impact: current MCP evidence justifies a documentation refresh and prevents any downgrade, but it does not prove final source spellings/source-file split/signature return type strongly enough to raise the cap beyond `86/86`.

## Evidence Standards Used

Evidence used:

- IDA MCP `initialize`, `tools/list`, `idb_list`, `server_health`, `lookup_funcs`, `get_bytes`, `disasm`, `decompile`, `callees`, `xrefs_to`, `xref_query`, `func_profile`, and `find_bytes`.
- Local executable hash and size for provenance.
- Existing by-* target/support documentation and generated C++ output.
- Negative evidence: no function at padding fences, no data xrefs to wrapper entries, no VA/RVA/raw-offset pointer byte-pattern hits, and stale owner names rejected by direct owner/caller analysis.

The evidence is strong for range and behavior because the wrappers are tiny and MCP function bytes directly encode the source-shaped forwarding operations. Confidence remains below final-proof quality only because stripped binary evidence cannot recover original C++ spelling/source-file organization and Hex-Rays' raw return type is ABI-derived.

## Evidence Checked

- IDA MCP/manual-disassembly/raw-byte checks performed: health/session check, function lookup for `0x005975e0`, `0x005975ff`, `0x00597600`, `0x0059760d`, `0x00597910`, and `0x00597a10`; bytes for pre-padding, wrapper bodies, separator, and post-padding; disassembly/decompilation for both wrappers; callees for both wrappers; xrefs and function profiles for wrappers and manager callees; data-xref negatives and byte-pattern pointer negatives for wrapper entries.
- by-* docs, support docs, old reports, generated reports, and trackers checked: target page, TimerHandler class, TimerMgr file/class, parent aggregate, manager callee pages, `g_pTimerMgr`, generated `TimerMgr.cpp`, project stats, current coverage row, and executed [UID:0001K6] report.
- Negative checks performed: zero data xrefs to `0x005975e0`/`0x00597600`; zero byte-pattern hits for VA/RVA/raw-offset encodings `e0 75 59 00`, `00 76 59 00`, `e0 75 19 00`, `00 76 19 00`, `e0 69 19 00`, and `00 6a 19 00`; no function at separator/end padding addresses.
- Failed, unavailable, or intentionally skipped checks and why: no MCP failures occurred. Full decompilation of all 163/45 callers was intentionally skipped as unnecessary and too broad; caller fan-in and support docs are enough to classify consumers versus owner for this target.

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Next verification / remaining uncertainty |
| --- | --- | --- | --- | --- |
| [UID:0001K8] should remain one exact child with two wrappers | High | MCP confirms adjacent functions `0x005975e0-0x005975ff` and `0x00597600-0x0059760d`, separated by one `cc` byte and fenced by padding | No mixed non-wrapper code in range; no missing function at `0x005975ff` or `0x0059760d` | None for range |
| Direct owner is [UID:0000F0] `TimerHandler` | High | Both functions are `__thiscall` wrappers that forward `this` to TimerMgr helpers; support docs and generated C++ emit TimerHandler methods | Broad feature caller fan-in is consumer evidence, not ownership; no vtable/table data route changes owner | Original source file may still place definitions in `TimerMgr.cpp` or another utility file |
| Source family remains [UID:0000OT] `TimerMgr.cpp` | Medium-high | Parent aggregate/source file docs and generated `auto-generated/NexusTK/util/TimerMgr.cpp` place wrappers in TimerMgr source family | Direct class owner is TimerHandler; a separate original TimerHandler implementation file is possible | Source/PDB evidence would settle exact file split |
| First-draft C++ should stay source-shaped and `void` | Medium-high | Raw wrappers only forward through `g_pTimerMgr`; manager child docs describe side-effecting schedule/remove operations; existing generated output already emits void wrappers | Hex-Rays prints raw `int` because EAX propagates from callee; full caller return-use audit was not performed | Caller decompilation or source evidence could prove if return was ever observed |
| Score should remain `86/86` | High | Current MCP refresh validates existing docs but does not prove names/source split/signature return type | Exact behavior and C++ are strong enough that a downgrade is not justified | Raise only with final spellings/source file or stronger return-type proof |

## Positive Evidence Summary

- MCP `lookup_funcs` confirms exact function inventory:
  - `0x005975e0`: `sub_5975E0`, size `0x1f` / 31.
  - `0x00597600`: `sub_597600`, size `0x0d` / 13.
  - `0x005975ff`: no function.
  - `0x0059760d`: no function.
  - `0x00597910`: manager schedule helper `sub_597910`, size `0xfc`.
  - `0x00597a10`: manager remove-owner helper `sub_597A10`, size `0x163`.
- MCP bytes show the exact range shape:
  - `0x005975d5-0x005975e0`: eleven `cc` bytes.
  - `0x005975e0-0x005975ff`: `55 8b ec ff 75 14 ff 75 10 ff 75 0c ff 75 08 51 8b 0d 80 ab 67 00 e8 15 03 00 00 5d c2 10 00`.
  - `0x005975ff`: one `cc` byte.
  - `0x00597600-0x0059760d`: `51 8b 0d 80 ab 67 00 e8 04 04 00 00 c3`.
  - `0x0059760d-0x00597610`: three `cc` bytes.
- MCP disassembly proves the `g_pTimerMgr` forwarding route. The schedule wrapper pushes four caller arguments, pushes `ecx` as TimerHandler owner, loads `dword ptr [0x0067ab80]` into `ecx`, calls `0x00597910`, and returns with `retn 10h`. The remove wrapper pushes `ecx`, loads the same global, calls `0x00597a10`, and returns.
- MCP xrefs prove live API fan-in: 163 code xrefs to `0x005975e0` and 45 code xrefs to `0x00597600`.
- Generated C++ corroborates the source shape and emission route for this exact child page.

## IDA MCP Facts

- Function/range facts:
  - `lookup_funcs` found `sub_5975E0` at `0x005975e0`, size `0x1f`, and `sub_597600` at `0x00597600`, size `0x0d`.
  - No function exists at `0x005975ff` or `0x0059760d`.
  - `int_convert.py` confirms `0x1f` = 31, `0x0d` = 13, and `0x2d` = 45.
- Data/table/padding facts:
  - Pre-padding: 11 bytes of `cc` before the schedule wrapper.
  - Separator: one `cc` byte at `0x005975ff`.
  - Post-padding: three `cc` bytes after the remove wrapper.
  - No data/table object is embedded in the target range.
- Xref facts:
  - `xrefs_to` / `xref_query` to `0x005975e0`: 163 code xrefs.
  - `func_profile` for `0x005975e0`: 122 unique caller functions, one callee, raw prototype `int __thiscall(void *this,int,int,int,int)`, no string refs.
  - `xrefs_to` / `xref_query` to `0x00597600`: 45 code xrefs.
  - `func_profile` for `0x00597600`: 30 unique caller functions, one callee, raw prototype `int __thiscall(void *this)`, no string refs.
  - `xrefs_to` to `0x00597910`: 48 code xrefs, including this schedule wrapper and other direct TimerMgr users.
  - `xrefs_to` to `0x00597a10`: 20 code xrefs, including this remove wrapper, TimerHandler destructor/scalar deleting destructor routes, and feature consumers.
- Vtable/global/type facts:
  - Both wrappers load `g_pTimerMgr` at `0x0067ab80` via `mov ecx, dword ptr unk_67AB80`.
  - No data xrefs to either wrapper entry were found, and no VA/RVA/raw-offset pointer byte-pattern hits were found for either entry.
- Negative IDA facts:
  - No callee other than `0x00597910` from schedule wrapper and `0x00597a10` from remove wrapper.
  - No string references in either wrapper profile.
  - No evidence of vtable dispatch, callback table membership, or pointer-based registration for the wrapper entry addresses.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00597570-0x005986da` | [UID:0001K6] `TimerMgrAndTimerQueue` | Aggregate TimerMgr source-family container | TRUE, blank aggregate C++ | [UID:0000OT] `TimerMgr.cpp` | `85/87` | Accepted current-session B004 refresh; no aggregate code |
| `0x005975d0-0x005975d5` | [UID:000418] `TimerHandlerReturnTrueCallbackShape` | Callback-shaped no-route neighbor | Non-emitting/no-owner | no owner | `78/88` in support context | Remains route-less with `__purecall` caveat |
| `0x005975e0-0x005975ff` | part of [UID:0001K8] | TimerHandler schedule wrapper | TRUE | [UID:0000F0] `TimerHandler` | target `86/86` | First exact function in assigned target |
| `0x00597600-0x0059760d` | part of [UID:0001K8] | TimerHandler remove-pending wrapper | TRUE | [UID:0000F0] `TimerHandler` | target `86/86` | Second exact function in assigned target |
| `0x00597910-0x00597a0c` | [UID:00041D] `TimerMgrScheduleTimer` | Manager schedule helper | TRUE, C++ blank | [UID:0000F1] `TimerMgr` | `86/88` | Schedule wrapper callee |
| `0x00597a10-0x00597b73` | [UID:00041E] `TimerMgrRemovePendingTimersForOwner` | Manager remove-owner helper | TRUE, C++ blank | [UID:0000F1] `TimerMgr` | `86/88` | Remove wrapper callee |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x005975e0` | 163 code xrefs, 122 unique caller functions | Live widely-used TimerHandler schedule API |
| `0x005975e0` | callee `0x00597910` / `sub_597910` | Forwards to TimerMgr schedule helper |
| `0x00597600` | 45 code xrefs, 30 unique caller functions | Live TimerHandler unregister/remove-pending API |
| `0x00597600` | callee `0x00597a10` / `sub_597A10` | Forwards to TimerMgr owner-removal helper |
| `0x0067ab80` | loaded by both wrappers | Process/global TimerMgr singleton pointer, documented as `g_pTimerMgr` |
| `0x00597910` | 48 code xrefs | Manager helper has direct callers beyond this wrapper; not owned by TimerHandler |
| `0x00597a10` | 20 code xrefs | Manager owner-removal helper has destructor/feature routes beyond this wrapper |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion:
  - Target page already records exact split, padding, stale owner rejection, and first-draft wrapper C++.
  - `by-class/TimerHandler.md` lists the schedule wrapper and unregister wrapper as TimerHandler methods forwarding through `g_pTimerMgr`.
  - `by-file/TimerMgr.md` includes [UID:0001K8] in the TimerMgr source family and generated-output route.
  - `by-class/TimerMgr.md` documents the manager helper methods reached by the wrappers.
  - `by-global/g_pTimerMgr.md` documents the singleton pointer used by the wrapper loads.
  - Executed [UID:0001K6] report confirms exact child C++ emits where safe and parent aggregate remains blank.
- Existing docs that are stale, incomplete, or contradicted:
  - Target/support pages rely on older raw-IDA/B014/B013 language and should gain current MCP session `ff68e691` provenance.
  - Some support wording uses "unregister" while the target C++ uses `RemovePendingTimers()`. Both describe the same behavior, but support docs should explicitly call `RemovePendingTimers()` an inferred source-facing name.
  - Stale feature-owner names remain rejected and should not be reintroduced.
- Generated/coverage report state:
  - `auto-generated/NexusTK/util/TimerMgr.cpp` emits [UID:0001K8] C++ with the same source-shaped wrapper bodies.
  - Current coverage row already states reconstructable 86% and strong evidence, but it does not cite current MCP `ff68e691`; replacement text is supplied below for supervisor-owned application.

## Ranked Ownership Analysis

### 1. [UID:0000F0] TimerHandler

- Evidence for: both functions are `__thiscall` wrappers where incoming `ecx` is the TimerHandler owner pointer; schedule wrapper passes `this` plus four explicit fields to the manager; remove wrapper passes `this` to the manager; existing target/generated C++ already emits `TimerHandler::ScheduleTimer` and `TimerHandler::RemovePendingTimers`.
- Evidence against: the source file may not be a standalone TimerHandler implementation file; the wrappers are physically clustered in the TimerMgr aggregate.
- Decision: keep direct canonical owner/emitter [UID:0000F0] and describe source-family placement through [UID:0000OT].

### 2. [UID:0000OT] TimerMgr.cpp / [UID:0000F1] TimerMgr

- Evidence for: wrappers are inside the TimerMgr aggregate range, generated source places them in `NexusTK/util/TimerMgr.cpp`, and both call TimerMgr helper methods through `g_pTimerMgr`.
- Evidence against: the wrapper methods are not manager methods; `this` is forwarded as an owner argument, while loaded `g_pTimerMgr` becomes the manager `this` for the actual helper calls.
- Decision: use [UID:0000OT] as source-family context/support synchronization, not canonical owner for [UID:0001K8].

### 3. Feature callers such as InterfaceEfx, FittingRoomDialog, UI panes, or no-owner

- Evidence for: many features call the wrappers, and historical docs mention feature-biased names.
- Evidence against: MCP proves high caller fan-in across many callers, which is consumer evidence. No single feature owns the shared wrappers. The functions are live direct-call APIs, not route-less no-owner artifacts.
- Decision: reject as owners/emitters. Preserve as consumer evidence only.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: none.
- Likely full contents: no new file recommended. If future source evidence proves a separate `TimerHandler.cpp`, its likely contents would include TimerHandler destructor/wrappers/callback declarations, but current generated/source-family evidence still routes through `TimerMgr.cpp`.
- Candidate related items that belong: [UID:0001K8] belongs with TimerHandler class docs and TimerMgr source-family docs.
- Candidate related items rejected: manager helper method bodies remain separate TimerMgr child pages; callback-shaped [UID:000418] remains separate and route-less.
- Standalone, narrow, or broad source-file inference: narrow exact child under broad TimerMgr source-family container.

## Source Placement

- Recommended source file/class/global/module placement: direct class methods on [UID:0000F0] `TimerHandler`, documented in [UID:0000OT] `TimerMgr.cpp` source family.
- Why this placement fits source-tree and subsystem context: the wrappers expose owner-facing TimerHandler API while routing implementation through the singleton TimerMgr. Generated `TimerMgr.cpp` already emits these wrappers under the TimerMgr source file.
- Rejected placements and why: `TimerMgr` class method ownership rejected because incoming `ecx` is TimerHandler until the wrapper loads `g_pTimerMgr`; InterfaceEfx/FittingRoom/FittingRoomDialog/other feature owner rejected because broad callers are consumers; no-owner rejected because both wrappers are live and heavily called.
- Remaining placement uncertainty: original source may have had a small `TimerHandler.cpp` or inline definitions included from a header. No source/PDB evidence currently proves that split.

## Range / Split / Padding / Reclassification Analysis

- Exact range/boundary facts:
  - Target range: `0x005975e0-0x0059760d`, total 45 bytes.
  - Schedule function: `0x005975e0-0x005975ff`, 31 bytes.
  - Separator: `0x005975ff`, one `cc`.
  - Remove function: `0x00597600-0x0059760d`, 13 bytes.
  - Pre-fence: `0x005975d5-0x005975e0`, eleven `cc`.
  - Post-fence: `0x0059760d-0x00597610`, three `cc`.
- Children/subranges to create, repair, merge, leave ignored, or leave no-owner: none. Keeping the paired wrappers in one exact child is defensible and already source-shaped.
- Padding/table/data/code distinctions: only code plus `int3` padding; no embedded table/data in the target.
- Parent/container impact: parent [UID:0001K6] remains aggregate/no-code; this child retains the only source C++ for these exact wrappers.

## Negative Evidence Summary

- No data xrefs to `0x005975e0` or `0x00597600`.
- No VA/RVA/raw-offset pointer byte-pattern hits for either entry address.
- No function at `0x005975ff` or `0x0059760d`.
- No string references in either wrapper.
- No evidence that manager helper bodies should be folded into this child.
- No evidence that any feature caller owns the wrappers; the caller fan-in is too broad and behavior is a shared TimerHandler API.
- No proof that raw Hex-Rays `int` return type is original source. It is an ABI/decompiler artifact unless caller-return-use/source evidence proves otherwise.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing names/types/comments:
  - Keep documentation source names `TimerHandler::ScheduleTimer(int timerId, unsigned int delayMs, int arg0, int arg1)` and `TimerHandler::RemovePendingTimers()`.
  - Keep `g_pTimerMgr` for `0x0067ab80`.
  - Keep manager helper names `TimerMgr::ScheduleTimer(...)` and `TimerMgr::RemovePendingTimersForOwner(...)` as documentation-grade inferred names.
- Evidence for each proposed name/type/comment: forwarding behavior and support docs align with scheduling/removing pending timer events owned by the TimerHandler pointer; generated C++ already uses this source shape.
- Items intentionally left unchanged and why: do not claim the exact original names are proven; do not rename IDA DB functions during this report-only task; do not force raw Hex-Rays `int` into source C++.
- Whether IDA DB edits are safe, unsafe, or not requested: not requested. This assignment is report-only, and IDA DB edits are out of scope.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes; existing C++ should remain.
- Recommended code:

```cpp
void TimerHandler::ScheduleTimer(int timerId, unsigned int delayMs, int arg0, int arg1)
{
    g_pTimerMgr->ScheduleTimer(this, timerId, delayMs, arg0, arg1);
}

void TimerHandler::RemovePendingTimers()
{
    g_pTimerMgr->RemovePendingTimersForOwner(this);
}
```

- Reason it preserves exact original behavior: the schedule wrapper forwards `this`, four explicit stack arguments, and the global TimerMgr singleton to `0x00597910`; the remove wrapper forwards `this` and the singleton to `0x00597a10`.
- Reason it matches the most plausible original precompiled mid-2000s developer source shape: thin owner-facing class methods wrapping a singleton manager are a common source idiom, and the compiler output is a straightforward `thiscall` forwarder with no extra local state.
- Inferred source-facing names/types/fields used instead of IDA/decompiler labels: `TimerHandler`, `ScheduleTimer`, `RemovePendingTimers`, `g_pTimerMgr`, `TimerMgr::ScheduleTimer`, `TimerMgr::RemovePendingTimersForOwner`, `timerId`, `delayMs`, `arg0`, and `arg1`.
- Naming/coding style convention used and evidence for consistency: existing target/generated C++ and TimerMgr support docs use PascalCase class methods and `g_` singleton naming.
- Reason code should remain blank, if applicable: not applicable for this exact child.
- Exact no-code proof, if not eligible: not applicable.

## Final Recommendation

- Exact changes recommended: documentation sync only. Add current MCP `ff68e691` evidence, range bytes, xref counts, callee routes, pointer/data negative checks, source-signature rationale, rejected alternatives, and score cap rationale to target/support docs.
- Exact parent assignments recommended: keep [UID:0001K8] owner/emitter [UID:0000F0] and source-family relationship to [UID:0000OT].
- Exact items left no-owner/non-emitting and why: none in this target. Neighbor [UID:000418] remains no-owner/non-emitting in its own page, not part of this child.
- Exact future work outside this assignment scope: final source/PDB evidence or broad caller return-use audit could prove original names/source-file split/return type and permit a score policy change later.

## Recommended Target Doc Changes

- Target path: `by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md`.
- Exact report facts to incorporate:
  - Add `2026-06-23 B004 MCP-backed recheck` section with endpoint/session `ff68e691`, IDB path, health, executable hash/size, and current-session provenance.
  - Record MCP `lookup_funcs` facts for `sub_5975E0` size `0x1f` and `sub_597600` size `0x0d`; record no function at `0x005975ff` or `0x0059760d`.
  - Record exact byte sequences and padding fences listed above.
  - Record disassembly/decompile summary: schedule pushes `arg4/arg3/arg2/arg1/this`, loads `g_pTimerMgr` from `0x0067ab80`, calls `0x00597910`, returns `retn 10h`; remove pushes `this`, loads `g_pTimerMgr`, calls `0x00597a10`, returns.
  - Record xref/profile counts: 163 code xrefs / 122 unique caller functions for schedule wrapper; 45 code xrefs / 30 unique caller functions for remove wrapper; 48 code xrefs to manager schedule helper; 20 to manager remove-owner helper.
  - Record negative evidence: zero data xrefs to wrapper entries and zero VA/RVA/raw-offset pointer byte-pattern hits.
  - Preserve first-draft C++ unchanged but explain raw `int` decompiler signatures as ABI/return-propagation artifacts and source `void` as best source-shaped inference.
  - Preserve rejection of InterfaceEfx/FittingRoom/feature/no-owner alternatives.
- Metadata/score/owner/emitter/reconstructable/C++ changes: none. Keep `86/86`, owner/emitter `0000F0`, reconstructable true, blank emitter position, and existing C++.
- Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: preserve B014/B013 historical context as superseded by current MCP evidence, not contradicted; preserve stale owner rejections and source-split caveat.

## Recommended Support Doc Changes

If accepted, keep support sync focused on current-session evidence and source-quality caps. Do not rewrite already adequate queue/type pages.

| Support path | Exact report facts to incorporate | Metadata/link/score/C++ changes |
| --- | --- | --- |
| `by-class/TimerHandler.md` | Add current `ff68e691` evidence for [UID:0001K8]: exact two wrapper ranges, 163/45 caller fan-in, `g_pTimerMgr` forwarding, source `void` wrapper rationale versus raw `int`, and no pointer/data route. Preserve direct TimerHandler owner and final source-file split caveat. | None |
| `by-file/TimerMgr.md` | Add current-session support note that [UID:0001K8] is source-family TimerMgr.cpp child C++, not aggregate code; it forwards TimerHandler APIs into TimerMgr manager helpers. Preserve generated-output state and original spelling caveat. | None |
| `by-class/TimerMgr.md` | Add or confirm current evidence that [UID:0001K8] calls [UID:00041D] `0x00597910` and [UID:00041E] `0x00597a10`, while the helpers remain TimerMgr bodies with their own source-shape blockers. | None |
| `by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md` | Add/confirm child-row support for current [UID:0001K8] evidence after the [UID:0001K6] refresh: child emits safe wrapper C++; aggregate remains blank; exact child route through TimerHandler/TimerMgr source family. | None |
| `by-global/g_pTimerMgr.md` | Optional only if supervisor wants all `g_pTimerMgr` wrapper routes synchronized; current page already documents the singleton and wrapper loads. If edited, add the current [UID:0001K8] route proof and 163/45 fan-in as a supporting xref example. | None |

Expected validators after implementation for every changed by-* doc:

> Executable block R001 was removed from this report and preserved verbatim in [0001K8-TimerHandlerScheduleRemoveWrappers-source-quality-removed.md](0001K8-TimerHandlerScheduleRemoveWrappers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Run `by-global\g_pTimerMgr.md` validator only if that optional page is edited.

## Score And Metadata Recommendation

- Current score/metadata: [UID:0001K8] `COMPLETION:86`, `CONFIDENCE:86`, `CANONICAL_OWNER:0000F0`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000F0`, blank emitter position, existing first-draft C++.
- Recommended score/metadata: unchanged.
- Score rationale and reason not higher/lower:
  - Not higher: exact original method spellings and final source-file split are still inferred; raw decompiler return type is `int` and source `void` remains a source-quality inference; manager helper method C++ remains blank, so wrapper names depend on documentation-grade helper naming.
  - Not lower: current MCP proves exact bytes, boundaries, callees, broad caller fan-in, global forwarding, and no table/pointer alternate route; generated output already emits source-shaped child C++.
- Metadata fields to change or leave unchanged: leave all metadata unchanged.

## Open Questions With Attempted Resolution

| Open question | Evidence checked | Resolution / remaining impact |
| --- | --- | --- |
| Are the exact original names `ScheduleTimer` and `RemovePendingTimers`? | Target/generated C++, support docs, decompile behavior, manager helper docs | Best source-facing names remain these inferred names; not original-proof, so cap remains |
| Were the original return types `void`? | Raw disassembly, Hex-Rays output, manager helper semantics, generated C++ | Source `void` remains best shape because wrappers are side-effect forwarders; raw `int` is EAX propagation. Not proof enough for a score raise |
| Does [UID:0001K8] belong to TimerHandler or TimerMgr? | `thiscall` flow, `g_pTimerMgr` load, support docs, generated source | Direct owner/emitter TimerHandler; source family TimerMgr.cpp; final source-file split unresolved |
| Should the pair be split into two pages? | Exact bytes/padding and source C++ | No. The paired wrappers are tiny, adjacent, and already source-shaped together |
| Do data/vtable/pointer routes indicate a hidden owner? | MCP data-xref and byte-pattern searches | No. Direct code call fan-in is the route |

## Exact Supervisor-Owned Coverage Text

Applicable because the coverage row should mention current MCP provenance if the report is accepted. B004 must not apply it directly because `-coverage-report.md` files are supervisor-owned.

File/placement: replace the existing [UID:0001K8] row in `by-memory/-coverage-report.md`.

Exact replacement text:

```text
    - [UID:0001K8][0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md) 0x005975e0-0x0059760d | timer-handler wrappers | TimerHandlerScheduleRemoveWrappers : reconstructable : 86% : strong : B004 MCP-backed source-quality recheck using active IDA session `ff68e691` keeps [UID:0000F0] TimerHandler owner/emitter and the 86/86 cap; current MCP health points at `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `lookup_funcs` confirms `sub_5975E0` size `0x1f` and `sub_597600` size `0x0d` with no functions at `0x005975ff`/`0x0059760d`, `get_bytes` confirms the 31-byte schedule wrapper, one-byte `cc` separator, 13-byte remove wrapper, and surrounding padding, disassembly/decompile prove `g_pTimerMgr` loads from `0x0067ab80` and calls to `0x00597910`/`0x00597a10`, xrefs show 163 schedule callers and 45 remove callers, data-xref and VA/RVA/raw-offset pointer-pattern checks find no alternate table/vtable route, generated `TimerMgr.cpp` already emits source-shaped TimerHandler wrapper C++, and the cap remains due to inferred original method spellings/source split and raw `int` versus source `void` signature uncertainty.
```

Reason B agent must not apply it directly: active assignment is report-only and explicitly forbids editing `-coverage-report.md` files.

## Follow-Up Actions

- Supervisor actions: review/accept the report, then send an implementation callback if the current-session evidence should be incorporated into by-* docs and coverage.
- A-agent actions: none.
- B004 future research actions: only if assigned, audit broad caller return-use or search for source/PDB naming evidence that could raise this target above `86/86`.

## Confidence

- Recommendation confidence: high.
- Score confidence: high for unchanged `86/86`.
- Remaining uncertainty: exact original method spellings, original return types, final TimerHandler source-file split, and final manager helper source declarations.

## Validator Results

- Commands run from `E:\NTK\GhidraBridge\source-3\project-documentation` during the accepted implementation callback:

| File | Command | Exit code | ok | Side effects / notes |
| --- | --- | --- | --- | --- |
| `by-memory\0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md` | `python .\tools\validator.py --mode file --file by-memory\0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md --apply --queue-timeout 240` | `0` | `1` | `stats_row_update:3`, `projected_stats_update:1`, `autogen_registry_rebuild:1`, `autogen_registry_stale:2`, `autogen_cpp_noop:270`, `autogen_cpp_conflict:5`, `autogen_report_noop:7`, `errors:0`. |
| `by-class\TimerHandler.md` | `python .\tools\validator.py --mode file --file by-class\TimerHandler.md --apply --queue-timeout 240` | `0` | `1` | `stats_row_update:4`, `projected_stats_update:1`, `autogen_registry_rebuild:1`, `autogen_registry_stale:2`, `autogen_cpp_noop:270`, `autogen_cpp_conflict:5`, `autogen_report_noop:7`, `errors:0`. |
| `by-file\TimerMgr.md` | `python .\tools\validator.py --mode file --file by-file\TimerMgr.md --apply --queue-timeout 240` | `0` | `1` | `stats_row_update:0`, `projected_stats_update:1`, `autogen_registry_rebuild:1`, `autogen_registry_stale:2`, `autogen_cpp_noop:270`, `autogen_cpp_conflict:5`, `autogen_report_noop:7`, `errors:0`. |
| `by-class\TimerMgr.md` | `python .\tools\validator.py --mode file --file by-class\TimerMgr.md --apply --queue-timeout 240` | `0` | `1` | `stats_row_update:1`, `projected_stats_update:1`, `autogen_registry_rebuild:1`, `autogen_registry_stale:2`, `autogen_cpp_noop:270`, `autogen_cpp_conflict:5`, `autogen_report_noop:7`, `errors:0`. |
| `by-memory\0x00597570-0x005986da.TimerMgrAndTimerQueue.md` | `python .\tools\validator.py --mode file --file by-memory\0x00597570-0x005986da.TimerMgrAndTimerQueue.md --apply --queue-timeout 240` | `0` | `1` | `stats_row_update:4`, `projected_stats_update:1`, `autogen_registry_rebuild:1`, `autogen_registry_stale:2`, `autogen_cpp_noop:270`, `autogen_cpp_conflict:5`, `autogen_report_noop:7`, `errors:0`. |

The validator repeatedly reported existing project-wide generated-state side effects, not target-specific failures: stale registry entries for missing `0003E6` / `00026U`, five existing `autogen_cpp_conflict` files whose nonempty generated files lack the autogen sentinel, and seven `auto-generated/-ag-*` coverage report no-ops. It also refreshed `project-level/-auto-completion-stats.md`, `validator.ini`, and autogen registry state through the normal validator-owned path. No `-coverage-report.md` file was edited by B004.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B004/research/0001K8-TimerHandlerScheduleRemoveWrappers-source-quality.md` during the report-only pass.
- Modified during implementation callback:
  - `by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md`
  - `by-class/TimerHandler.md`
  - `by-file/TimerMgr.md`
  - `by-class/TimerMgr.md`
  - `by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md`
  - `tools/leaser/Agents/Agent-B004/research/0001K8-TimerHandlerScheduleRemoveWrappers-source-quality.md`
- Already sufficient / not edited:
  - `by-global/g_pTimerMgr.md`: current page already documents `g_pTimerMgr`, wrapper loads at `0x005975e0`/`0x00597600`/`0x00597610`/`0x00597630`, 125 xrefs, [UID:0001K8]-relevant 163/45 wrapper fan-in through [UID:0000F0], exact storage page [UID:0002VW], constructor/clear paths, and split-owner guidance. The accepted report marked this support page optional only if stale or missing, so no edit or validator was required.
- Renamed: none.
- Moved to executed: none.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation. Proof: supervisor accepted this report and sent implementation callback `B004-implement-timerhandler-schedule-remove-wrappers-source-quality-0001K8-mcp-20260623`.
- [x] Target/support docs to update: target `by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md`; support `by-class/TimerHandler.md`, `by-file/TimerMgr.md`, `by-class/TimerMgr.md`, and `by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md`; optional `by-global/g_pTimerMgr.md` only if supervisor wants current [UID:0001K8] route proof there. Proof: all five required by-* docs were edited; `by-global/g_pTimerMgr.md` was reread and left unchanged because it already contains the singleton route and fan-in at same-or-greater detail for this optional route.
- [x] Current target state and actual evidence checked recorded: incorporated MCP session `ff68e691`, IDB path/health/provenance, executable hash/size, exact bytes, function sizes, disassembly/decompile summaries, xref counts, manager callees, data/pointer negative checks, generated output state, and support-doc evidence. Proof: target gained `2026-06-23 B004 MCP-Backed Recheck`; support docs gained current [UID:0001K8] evidence sections/entries.
- [x] Metadata/score changes to apply: none; keep `COMPLETION:86`, `CONFIDENCE:86`, `CANONICAL_OWNER:0000F0`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000F0`, blank emitter position. Proof: target metadata lines remain unchanged.
- [x] Owner/emitter/reconstructable changes to apply: none; keep direct owner/emitter [UID:0000F0] and document source-family route through [UID:0000OT]. Proof: target status and support docs now explicitly preserve TimerHandler direct owner/emitter and TimerMgr.cpp source-family route.
- [x] Split/rename/new-child changes to apply: none; keep exact range `0x005975e0-0x0059760d` and two-wrapper child grouping. Proof: no file rename, split, child creation, or metadata range change was applied.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable: add current source-placement and padding evidence to docs; no IDA DB changes requested. Proof: target and aggregate record source-placement and padding evidence; no IDA DB change was made.
- [x] First-draft C++ or no-code proof to apply: keep existing first-draft C++ unchanged and document why source `void` is preferred over raw Hex-Rays `int` while remaining an inference cap. Proof: target C++ block is unchanged; target and TimerHandler support now document raw `int`/source `void` rationale.
- [x] Exact target/support doc facts to incorporate at report-level detail: range bytes/padding, `g_pTimerMgr` load, calls to `0x00597910`/`0x00597a10`, caller counts 163/45, manager helper xrefs 48/20, zero data xrefs, zero pointer-pattern hits, generated C++ route, rejected owners, and score cap rationale. Proof: target contains full current-session facts; TimerHandler, TimerMgr file/class, and aggregate support docs contain synchronized summaries with the same route/negative evidence.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: preserve B014/B013 historical context as superseded by current `ff68e691`; preserve InterfaceEfx/FittingRoom/feature-owner/no-owner rejection; preserve exact source-spelling/source-split caveats. Proof: target and support docs retain older evidence sections and add current B004 evidence without removing the rejected-owner/caveat text.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable. Proof: no active Wave2/Wave3 instruction was used; stale caller-biased owner artifacts remain rejected in target/support docs.
- [x] Open questions to close or document as evidence-backed unresolved: original names, original return type, final source-file split, and manager helper declarations remain unresolved caps. Proof: target and support docs document these as score/source-shape caveats.
- [x] Validators to run after accepted implementation:
  - `python .\tools\validator.py --mode file --file by-memory\0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md --apply --queue-timeout 240`
  - `python .\tools\validator.py --mode file --file by-class\TimerHandler.md --apply --queue-timeout 240`
  - `python .\tools\validator.py --mode file --file by-file\TimerMgr.md --apply --queue-timeout 240`
  - `python .\tools\validator.py --mode file --file by-class\TimerMgr.md --apply --queue-timeout 240`
  - `python .\tools\validator.py --mode file --file by-memory\0x00597570-0x005986da.TimerMgrAndTimerQueue.md --apply --queue-timeout 240`
  - Run `by-global\g_pTimerMgr.md` validator only if that optional support page is edited.
  Proof: all five commands ran from `source-3/project-documentation` during the final leased validator pass; all returned exit code `0` and `ok: 1`. `by-global\g_pTimerMgr.md` was not edited, so no validator was run for it.
- [x] Supervisor-owned coverage-report/tracker text to apply: exact [UID:0001K8] replacement row supplied above for `by-memory/-coverage-report.md`; B004 did not edit coverage during report-only pass. Proof: row remains above for supervisor-owned application, and B004 did not edit any `-coverage-report.md` file during implementation.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation: accepted callback named this report and target, with assignment ID `B004-implement-timerhandler-schedule-remove-wrappers-source-quality-0001K8-mcp-20260623`.
- [x] All accepted target/support doc details incorporated at report-level detail: target gained full `2026-06-23 B004 MCP-Backed Recheck`; support docs gained current-session [UID:0001K8] evidence, route/callee summaries, generated-output/source-family notes, and score/source-shape caveats.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason: no metadata, score, owner, emitter, split, rename, or C++ changes were applied; target remains `86/86`, owner/emitter `0000F0`, reconstructable true, blank emitter position, and existing C++ unchanged by accepted disposition.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: target/support docs retain InterfaceEfx/FittingRoom/feature/no-owner rejection, no vtable/table route, zero data xrefs, zero VA/RVA/raw-offset pointer hits, no functions at padding fences, and unresolved original-name/return/source-file split caveats.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale: original method spelling, raw `int` versus source `void` proof, final source-file split, and manager helper declarations remain documented unresolved caps.
- [x] Validators run and results recorded: table above records all five validator commands, final leased-pass exit code `0`, `ok: 1`, and side-effect counts.
- [x] Supervisor-owned coverage-report/tracker text supplied or confirmed unchanged: exact [UID:0001K8] coverage replacement row remains in this report; B004 made no coverage edit.
- [x] Remaining unapplied accepted items listed with exact blocker: no accepted non-coverage item remains unapplied. Coverage row remains supervisor-owned by rule; optional `by-global/g_pTimerMgr.md` edit was excluded as already sufficient at same-or-greater detail.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/0001K8-TimerHandlerScheduleRemoveWrappers-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:17","uid":"0001K8"} -->
<!-- {"agent":"B004","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001K8-TimerHandlerScheduleRemoveWrappers-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/0001K8-TimerHandlerScheduleRemoveWrappers-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001K8"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
