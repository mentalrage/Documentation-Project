** TARGET-REPORT-UID:0001NX **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001NX WaitableTimer Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: replace stale Wave2/Wave3/prewave wording in the WaitableTimer target/support docs with current IDA MCP session `ff68e691` evidence, keep [UID:0001NX] as the documented class-island aggregate, and raise it from `86/86` to `88/90`.
- Final disposition: [UID:0001NX] remains reconstructable NexusTK source evidence for the WaitableTimer class island, but the aggregate should not receive a monolithic C++ body. The source-ready code belongs on exact child method/helper pages.
- Required action if accepted: update [UID:0001NX], WaitableTimer class/file/layout/vtable support pages, [UID:0001NY], [UID:0002L8], [UID:0002L9], and the threading/timing meta notes at report-level detail; do not edit `-coverage-report.md` directly.
- Confidence: strong for range boundaries, raw-helper no-function status, behavior, field roles, vtable identity, Win32 dependency identities, source-file placement, and no-route negative evidence; medium for original public/private method spelling and live construction/caller route.

## Supporting Research

## Target

- Target UID: `0001NX`
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x005c0ff0-0x005c129a.WaitableTimer.md`
- Source queue/report row: `project-level/-auto-completion-stats.md`, `by-memory_Reconstructable` low-score row, current `86/86`.
- Current supervisor classification: B005 report-only source-quality research. No by-* edits, no coverage-report edits, no report move to `executed`.
- Current scores and parent state: target `86/86`, `CANONICAL_OWNER:0000P7`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000P7`, blank emitter position, blank C++.

## Current Target State

- Existing metadata: `COMPLETION:86`, `CONFIDENCE:86`, owner/emitter [UID:0000P7][WaitableTimer](by-file/WaitableTimer.md), reconstructable true, no C++.
- Existing owner/emitter/reconstructable state: the target currently routes directly to the file page. Under current `by-structure.md`, this is too broad for a class-owned method island: the correct direct semantic owner is [UID:0000FY][WaitableTimer](by-class/WaitableTimer.md), with the class then routing to [UID:0000P7].
- Existing C++/emitter state: blank aggregate C++. This is correct for the assigned range because `0x005c0ff0-0x005c129a` contains multiple source bodies, raw helper starts, padding, a callback, and a compiler scalar deleting destructor.
- Existing open questions and stale assumptions:
  - Target still cites Wave2, prewave exports, old live-MCP timeout caveats, `class_WaitableTimer.cpp`, and an obsolete "below 95/95" code-entry policy.
  - It records the raw helpers and field roles accurately in broad terms but does not use current session `ff68e691` as the evidence basis.
  - It keeps file-level ownership even though the island is class-owned.
  - It leaves exact source child C++ unresolved even though [UID:0002L8] and [UID:0002L9] now clear the active combined-score/emitter evidence threshold if rerouted to the class or an aggregate with a `[[CHILDREN]]` route.
- Related target/support docs checked:
  - [UID:0000FY][WaitableTimer](by-class/WaitableTimer.md)
  - [UID:0000P7][WaitableTimer](by-file/WaitableTimer.md)
  - [UID:0001NY][0x005c1120-0x005c11b5.WaitableTimerRawStartStop](by-memory/0x005c1120-0x005c11b5.WaitableTimerRawStartStop.md)
  - [UID:0002L8][0x005c1120-0x005c116a.WaitableTimerStartMultimediaTimer](by-memory/0x005c1120-0x005c116a.WaitableTimerStartMultimediaTimer.md)
  - [UID:0002L9][0x005c1170-0x005c11b5.WaitableTimerCancelMultimediaTimer](by-memory/0x005c1170-0x005c11b5.WaitableTimerCancelMultimediaTimer.md)
  - [UID:0001WI][WaitableTimerLayout](by-type/by-struct/WaitableTimerLayout.md)
  - [UID:0001Z2][WaitableTimerVtable](by-type/by-vtable/WaitableTimerVtable.md)
  - [UID:0002P2][0x00631184-0x0063118c.WaitableTimerVtableData](by-memory/0x00631184-0x0063118c.WaitableTimerVtableData.md)
  - [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md)
  - [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md)
  - [UID:0001QT][client_threading](by-meta/client_threading.md)
  - [UID:0001QU][client_timing](by-meta/client_timing.md)
  - `auto-generated/NexusTK/util/WaitableTimer.cpp`
  - `auto-generated/-ag-memory-coverage.md`
  - `by-memory/-coverage-report.md`
  - `by-project-structure/proposed-source-tree.md`

## Executive Recommendation

- Best direct owner: [UID:0000FY][WaitableTimer](by-class/WaitableTimer.md). The executable island is a class method/helper island anchored by a WaitableTimer vtable, constructor/destructor vtable stores, and a layout used consistently across constructor, raw helpers, callback, and destructors. [UID:0000P7][WaitableTimer](by-file/WaitableTimer.md) remains the source file root.
- Target status: keep [UID:0001NX] as a reconstructable source-bearing aggregate for the WaitableTimer class island, but keep its C++ blank and document exact no-code proof. Update metadata to `88/90`, `CANONICAL_OWNER:0000FY`, `EMITTER_UIDS:0000FY`, `RECONSTRUCTABLE:TRUE`, blank emitter position.
- Raw helper aggregate: keep [UID:0001NY] as the exact raw start/cancel aggregate and no-code container. It should be rerouted to the WaitableTimer class for ownership if support docs are updated, but it should not receive a combined C++ body.
- Exact raw children: [UID:0002L8] and [UID:0002L9] are ready for first-draft C++ if the accepted implementation also repairs their emitter route to the class or to a parent aggregate with a `[[CHILDREN]]` route. Their source-facing names `StartMultimediaTimer` and `CancelMultimediaTimer` are descriptive, not original-proven.
- Missing exact child pages: split/child creation is recommended for `0x005c0ff0-0x005c109c`, `0x005c10a0-0x005c1111`, `0x005c11c0-0x005c120e`, and `0x005c1210-0x005c129a` in a future accepted split/implementation pass. The scalar deleting destructor child should remain no-code/compiler-generated; constructor/destructor/callback children are plausible source-code candidates once exact pages exist.

## Supervisor Active Recheck

- Supervisor instruction: produce a report-only B-agent source-quality report for [UID:0001NX] using current IDA MCP session `ff68e691`, with no by-* edits, no coverage-report edits, no subagents, and no fallback-only finalization.
- MCP requirement satisfied: started with lightweight JSON-RPC `initialize`, `tools/list`, `server_health(database='ff68e691')`, and `idb_list`. `server_health` returned status `ok`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, auto-analysis ready, Hex-Rays ready, strings ready. `idb_list` showed active session `ff68e691`.
- Split repair: not authorized in this report-only assignment. This report identifies split candidates and exact child responsibilities for supervisor approval.
- Every source-bearing child in scope: existing raw exact children [UID:0002L8] and [UID:0002L9] are evaluated for C++ readiness; missing modeled-function child pages are listed as recommended future splits; aggregate no-code proof is documented.

## Inference Research Guidance Check

- `by-structure.md` requires the narrowest true semantic owner. The existing direct file owner is demoted because a class page exists, is scored above the gate, and the island is class-owned.
- Existing Wave2/Wave3/prewave claims were treated as stale lead material only. They should be removed or rewritten as historical context if implementation is accepted. Current MCP session `ff68e691` is the report evidence basis.
- Direct IDA facts: function starts/ranges, raw helper not-function status, xrefs, imports, decompilation, vtable data, raw bytes, padding, and SHA-256.
- Documentation evidence: current by-* pages already document the main field roles, source placement under `util/WaitableTimer.cpp`, raw helper split, and `+0x28` callback-gate correction, but several pages use stale evidence wording and old code-gate language.
- Inference: source-facing names such as `m_completionEvent`, `m_criticalSection`, `m_isRunning`, `m_timerId`, `m_callbackGateEvent`, `StartMultimediaTimer`, `CancelMultimediaTimer`, and `WaitableTimerCallback` are inferred/descriptive from behavior, not original symbol proof.

## Heuristic / Inference Reanalysis And Validation

- Stale Wave2/Wave3 wording: target, file, and class docs still cite Wave2/prewave/generator state. Current project rule says ignore stale Wave2/Wave3 unless a current override exists. Replace with `ff68e691` MCP facts and retain generated output only as a caveat.
- Boundary shape: the island starts at `0x005c0ff0` after predecessor `sub_5C0FA0` ends at `0x005c0fe1`; `0x005c0fe1-0x005c0ff0` is fifteen `0xcc` bytes. It ends at `0x005c129a`, followed by six `0xcc` bytes before successor `sub_5C12A0` at `0x005c12a0`.
- Function body inventory: IDA has function objects at `0x005c0ff0`, `0x005c10a0`, `0x005c11c0`, and `0x005c1210`. It does not have function objects at `0x005c1120` or `0x005c1170`.
- Raw helpers: despite no IDA function object or direct xrefs, the raw helper bytes are complete code bodies with `retn 4` at `0x005c1167` and `retn` at `0x005c11b4`; their roles are validated by field writes, Win32 calls, and the callback pointer data xref.
- Callback identity: `0x005c11c0` is not a normal class method caller target. It is pushed as a callback pointer by `0x005c1149` and decompiles as `void __stdcall(int,int,int,int,int)`, matching a `timeSetEvent` callback shape with the object pointer in the third parameter.
- `+0x28` field name: generated `m_hWorkerThread` is rejected. MCP decompilation/raw helper evidence shows this field is created by `g_pfnCreateEventW`, signaled after `timeSetEvent`, waited with `WaitForSingleObject(..., 0xffffffff)`, closed as a handle, and cleared. Best source-facing name is `m_callbackGateEvent`.
- Win32 dispatch dependency: `0x0069be3c` is not an arbitrary global; [UID:0000WD] writes imported `CreateEventW` into it at `0x0041a30c`, and `xrefs_to` confirms WaitableTimer constructor/start helper call the dispatch slot. Source may use a project dispatch variable or wrapper, so docs should preserve both `g_pfnCreateEventW` and `CreateEventW`.
- Timer behavior: start uses `timeSetEvent(delay, 5, WaitableTimerCallback, this, 0)` in a retry loop until the returned timer id is nonzero, stores it at `+0x24`, then signals the gate event. Cancel/destructor use `timeKillEvent`, `CloseHandle`, and `ResetEvent`.
- Ownership: `TimerMgr` is rejected as direct owner because no caller/lifetime route to `TimerMgr` was found and the implementation is a low-level waitable/multimedia timer wrapper, not the high-level queued scheduler under [UID:0000OT].
- First-draft C++ readiness: exact raw helper children are ready if emission routing is corrected; aggregate and scalar deleting destructor are not. Constructor/destructor/callback source bodies are ready enough for proposed exact child pages, but child pages should be created before adding code because parent aggregate C++ cannot contain sibling/child bodies.

## Evidence Standards Used

- IDA MCP tools used: `initialize`, `tools/list`, `server_health`, `idb_list`, `survey_binary`, `lookup_funcs`, `func_profile`, `callees`, `xrefs_to`, `xref_query`, `get_bytes`, `find_bytes`, `insn_query`, `decompile`, and `imports`.
- Numeric conversions: `tools/int_convert.py` verified `0xac` = 172, `0x71` = 113, `0x4e` = 78, `0x8a` = 138, `0x4a` = 74, `0x45` = 69, `0x2c` = 44, `0x20` = 32, `0x24` = 36, `0x28` = 40, `0x14` = 20, and `0xffffffff` = 4294967295.
- Evidence ladder: direct MCP function/xref/byte/decompile facts are primary; current by-* docs and generated output are supporting leads; source-facing names and file placement are inference from behavior, class/type support, and proposed source-tree context.
- Tool limitations: IDA MCP cannot prove original method names, field spellings, private/public visibility, or original source-file layout without source metadata. Decompiler output was cross-checked against bytes/disassembly/xrefs for behavior-driving claims.

## Evidence Checked

- Binary identity: `survey_binary(minimal)` on `ff68e691` reports module `NexusTK.exe`, image base `0x400000`, `.text 0x00401000-0x0060d000`, SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- Function/range checks:
  - `lookup_funcs` reports `sub_5C0FF0` size `0xac` at `0x005c0ff0`, `sub_5C10A0` size `0x71` at `0x005c10a0`, `sub_5C11C0` size `0x4e` at `0x005c11c0`, `sub_5C1210` size `0x8a` at `0x005c1210`.
  - `lookup_funcs` reports no function at `0x005c1120`, `0x005c116a`, `0x005c1170`, `0x005c11b5`, `0x005c120e`, or `0x005c129a`.
  - Predecessor `sub_5C0FA0` starts `0x005c0fa0`, size `0x41`, ending at `0x005c0fe1`; successor `sub_5C12A0` starts `0x005c12a0`, size `0x101`.
- Bytes/padding:
  - `get_bytes 0x005c0fe1 size 15` returned all `0xcc`.
  - `get_bytes 0x005c109c size 4`, `0x005c1111 size 15`, `0x005c116a size 6`, `0x005c11b5 size 11`, `0x005c120e size 2`, and `0x005c129a size 6` confirm local padding/gaps.
  - `get_bytes 0x00631184 size 12` returned `a4 3f 65 00 10 12 5c 00 ec 3f 65 00`, matching WaitableTimer COL, destructor slot, then WeatherLayerPane COL.
- Xrefs/callees:
  - Zero xrefs to `0x005c0ff0`, `0x005c10a0`, `0x005c1120`, and `0x005c1170`.
  - `0x005c11c0` has one data xref from `0x005c1149`.
  - `0x005c1210` has one data xref from `0x00631188`.
  - `0x00631188` has store/data refs from `0x005c1020`, `0x005c10a8`, and `0x005c121b`.
  - `0x0069be3c` has 12 refs including initializer write `0x0041a30c`, constructor call `0x005c1026`, and raw start call `0x005c1134`.
- Targeted pointer-negative checks:
  - `find_bytes` for VA/RVA pointers to `0x005c1120` (`20 11 5c 00`, `20 11 1c 00`) found zero hits.
  - `find_bytes` for VA/RVA pointers to `0x005c1170` (`70 11 5c 00`, `70 11 1c 00`) found zero hits.
  - `find_bytes` for VA callback pointer `c0 11 5c 00` found one hit at `0x005c114a`; RVA form `c0 11 1c 00` found zero hits.
  - `find_bytes` for VA/RVA constructor pointers to `0x005c0ff0` found zero hits.
- Decompilation:
  - `0x005c0ff0` constructs the vtable, creates event handle through `unk_69BE3C(0,0,0,0)`, throws `Win32Error` on null, initializes critical section at `+0x08`, clears `+0x20`, `+0x24`, and `+0x28`.
  - `0x005c10a0` is a non-deleting destructor/cleanup body: vtable store, critical-section enter, optional active timer kill, close gate, reset completion event, clear timer/gate fields, leave/delete critical section, close completion event, close residual gate if present.
  - `0x005c11c0` is a `__stdcall` timer callback taking five integers; it treats the third argument as `this`, clears running, enters the critical section, waits on `+0x28` with `0xffffffff`, closes it, clears `+0x28/+0x24`, signals `+0x04`, and leaves the critical section.
  - `0x005c1210` duplicates destructor cleanup and conditionally calls `sub_5C7526(Block)` when the scalar-deleting flag has bit 1.
- Imports:
  - WINMM: `timeSetEvent` at `0x60d4e0`, `timeKillEvent` at `0x60d4e4`.
  - KERNEL32: `CloseHandle`, `InitializeCriticalSection`, `EnterCriticalSection`, `LeaveCriticalSection`, `DeleteCriticalSection`, `SetEvent`, `ResetEvent`, `WaitForSingleObject`, and `CreateEventW`.
- Docs/generated checked: target/support docs listed above, `by-project-structure/proposed-source-tree.md` WaitableTimer section, `auto-generated/NexusTK/util/WaitableTimer.cpp`, `auto-generated/-ag-memory-coverage.md`, `project-level/-resolved.md`, `project-level/-unresolved.md`, and `by-memory/-coverage-report.md`.
- Failed/unavailable checks: none. MCP remained available for the evidence pass.

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Next verification / remaining uncertainty |
| --- | --- | --- | --- | --- |
| [UID:0001NX] is a WaitableTimer class island, not a TimerMgr island | Strong | Vtable `0x00631188`, constructor/destructor stores, class/file/layout docs, field access pattern, Win32 timer wrapper behavior | No direct xrefs to TimerMgr; `client_timing` says keep separate until caller proof | Find live construction/lifetime path if indirect allocation or factory evidence appears |
| Direct semantic owner should be [UID:0000FY], not [UID:0000P7] | Strong | `by-structure.md` narrow-owner rule; all source state is class layout/method state; file remains route root | Existing docs attach directly to file, but this is old broad routing | Implementation should reroute target/support memory pages through class while preserving file source placement |
| `+0x28` is a callback gate event | Strong | Created by `g_pfnCreateEventW`; signaled after successful `timeSetEvent`; waited/closed by callback; closed by cancel/destructor | Generated `m_hWorkerThread` rejected; no thread create/wait evidence | Original field spelling unknown; use descriptive `m_callbackGateEvent` |
| [UID:0002L8] is source-ready as `StartMultimediaTimer(UINT)` | Strong behavior, medium name | Raw disassembly, not-function status, exact return, no xrefs, `timeSetEvent` loop, field writes, callback pointer | No original name, no direct caller | Confirm public/private visibility and final spelling from caller/lifetime route |
| [UID:0002L9] is source-ready as `CancelMultimediaTimer()` | Strong behavior, medium name | Raw disassembly, `EnterCriticalSection`, `timeKillEvent`, `CloseHandle`, `ResetEvent`, field clears | No original name, no direct caller | Confirm public/private visibility and final spelling from caller/lifetime route |
| `0x005c11c0` is a timer callback, not a normal method | Strong | Pushed by raw start helper as callback pointer; `__stdcall` five-argument decompile; third argument used as `this` | No direct caller; no vtable slot | Exact callback typedef spelling unknown |
| Aggregate C++ for [UID:0001NX] should remain blank | Strong | Range spans multiple functions/raw helpers/padding/scalar deleting destructor; by-memory C++ cannot contain sibling/child code | Current route could emit a marker, but no single source body exists | Create exact children for remaining bodies and route code there |
| Scalar deleting destructor should not be hand-authored as source C++ | Strong | Vtable slot body checks delete flag and calls allocator/free helper; compiler artifact generated from virtual destructor | It is still a real binary body and should be documented | Exact child can document no-code/compiler-generated proof |

## Positive Evidence Summary

- The island is bounded by hard padding and neighboring functions: predecessor ends at `0x005c0fe1`, fifteen `0xcc` bytes precede `0x005c0ff0`, and six `0xcc` bytes follow `0x005c129a` before successor `0x005c12a0`.
- Four modeled functions and two raw non-modeled helpers form one coherent WaitableTimer layout at offsets `+0x04`, `+0x08`, `+0x20`, `+0x24`, and `+0x28`.
- Constructor, cleanup/destructor, callback, scalar deleting destructor, start, and cancel all share the same object layout and Win32 timer/event semantics.
- Vtable support is direct: `0x00631188` points to `0x005c1210`; vtable store xrefs occur in constructor, non-deleting destructor/cleanup body, and scalar deleting destructor.
- `g_pfnCreateEventW` dispatch identity is supported by WideApiDispatchInit, WideApiDispatchTable, and WaitableTimer call sites.
- Raw helper no-route evidence is current and targeted: zero function objects, zero xrefs to starts, zero VA/RVA pointer hits for start/cancel, and one expected callback pointer hit from the start helper.

## IDA MCP Facts

- Function/range facts:
  - `0x005c0ff0-0x005c109c`: `sub_5C0FF0`, size `0xac` / 172 bytes (Verified with int_convert.py), constructor.
  - `0x005c10a0-0x005c1111`: `sub_5C10A0`, size `0x71` / 113 bytes (Verified with int_convert.py), non-deleting destructor/cleanup body.
  - `0x005c1120-0x005c116a`: no IDA function object, 74-byte raw start helper including body/padding to next boundary (Verified with int_convert.py); return is `retn 4` at `0x005c1167`.
  - `0x005c1170-0x005c11b5`: no IDA function object, 69-byte raw cancel helper (Verified with int_convert.py); return is `retn` at `0x005c11b4`.
  - `0x005c11c0-0x005c120e`: `sub_5C11C0`, size `0x4e` / 78 bytes (Verified with int_convert.py), timer callback.
  - `0x005c1210-0x005c129a`: `sub_5C1210`, size `0x8a` / 138 bytes (Verified with int_convert.py), scalar deleting destructor.
- Data/table/padding facts:
  - Pre-padding `0x005c0fe1-0x005c0ff0`: fifteen `0xcc` bytes.
  - Internal padding `0x005c109c-0x005c10a0`, `0x005c1111-0x005c1120`, `0x005c116a-0x005c1170`, `0x005c11b5-0x005c11c0`, `0x005c120e-0x005c1210`.
  - Post-padding `0x005c129a-0x005c12a0`: six `0xcc` bytes.
  - Vtable data `0x00631184-0x0063118c`: WaitableTimer complete object locator, destructor slot, then WeatherLayerPane COL.
- Xref facts:
  - Zero direct xrefs to constructor, non-deleting destructor/cleanup body, raw start, and raw cancel.
  - One callback data xref `0x005c1149 -> 0x005c11c0`.
  - One destructor data xref `0x00631188 -> 0x005c1210`.
  - Vtable store refs at `0x005c1020`, `0x005c10a8`, and `0x005c121b`.
- Vtable/global/type facts:
  - [UID:0001Z2] one-slot WaitableTimer vtable at `0x00631188`.
  - [UID:0001WI] layout size `0x2c` / 44 bytes (Verified with int_convert.py).
  - [UID:0000TQ] `0x0069be3c` is `g_pfnCreateEventW`; [UID:0000WD] writes imported `CreateEventW` there at `0x0041a30c`.
- Negative IDA facts:
  - No direct constructor caller found.
  - No direct raw start/cancel xrefs or pointer refs found.
  - No evidence that `+0x28` is a worker thread handle.
  - No direct evidence merging WaitableTimer into TimerMgr source.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent / Owner | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x005c0ff0-0x005c129a` | [UID:0001NX][WaitableTimer](by-memory/0x005c0ff0-0x005c129a.WaitableTimer.md) | class-island aggregate | TRUE | recommend owner/emitter [UID:0000FY] | current `86/86`, recommend `88/90` | no aggregate C++ |
| `0x005c0ff0-0x005c109c` | none yet | constructor | TRUE | recommend new exact child under [UID:0000FY] | not scored | split recommended |
| `0x005c10a0-0x005c1111` | none yet | non-deleting destructor / cleanup body | TRUE | recommend new exact child under [UID:0000FY] | not scored | split recommended |
| `0x005c1120-0x005c11b5` | [UID:0001NY][WaitableTimerRawStartStop](by-memory/0x005c1120-0x005c11b5.WaitableTimerRawStartStop.md) | raw start/cancel aggregate | TRUE aggregate, no code | recommend owner/emitter [UID:0000FY] or container route to class | current `86/91`, recommend `88/92` | no aggregate C++ |
| `0x005c1120-0x005c116a` | [UID:0002L8][WaitableTimerStartMultimediaTimer](by-memory/0x005c1120-0x005c116a.WaitableTimerStartMultimediaTimer.md) | raw start helper | TRUE | recommend owner/emitter [UID:0000FY] | current `86/91`, recommend `88/92` | first-draft C++ ready |
| `0x005c1170-0x005c11b5` | [UID:0002L9][WaitableTimerCancelMultimediaTimer](by-memory/0x005c1170-0x005c11b5.WaitableTimerCancelMultimediaTimer.md) | raw cancel helper | TRUE | recommend owner/emitter [UID:0000FY] | current `86/91`, recommend `88/92` | first-draft C++ ready |
| `0x005c11c0-0x005c120e` | none yet | `timeSetEvent` callback | TRUE | recommend new exact child under [UID:0000FY] | not scored | split recommended |
| `0x005c1210-0x005c129a` | none yet | scalar deleting destructor | compiler-generated source effect | recommend new exact child/no-code proof | not scored | split recommended, no C++ |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x005c1020` | vtable store to `0x00631188` | Constructor initializes WaitableTimer vptr. |
| `0x005c1026` | call through `0x0069be3c` | Constructor creates completion event through `g_pfnCreateEventW` / `CreateEventW`. |
| `0x005c10a8` | vtable store to `0x00631188` | Non-deleting destructor/cleanup resets vptr. |
| `0x005c1134` | call through `0x0069be3c` | Raw start helper creates callback gate event. |
| `0x005c1149` | data xref to `0x005c11c0` | Raw start helper pushes timer callback pointer. |
| `0x005c121b` | vtable store to `0x00631188` | Scalar deleting destructor resets vptr. |
| `0x00631188` | data xref to `0x005c1210` | One-slot vtable points to scalar deleting destructor. |
| `0x0041a30c` | write `CreateEventW` to `0x0069be3c` | Wide API dispatch initialization proves dispatch slot identity. |

## Documentation Evidence And IDA Status

- Existing docs supporting the conclusion:
  - [UID:0000P7] already places WaitableTimer in `NexusTK/util/WaitableTimer.cpp` and rejects TimerMgr merge absent caller proof.
  - [UID:0000FY] already documents class layout, vtable, methods, raw helpers, callback, and open caller path.
  - [UID:0001WI] already corrects `+0x28` from worker thread to callback gate event.
  - [UID:0001Z2] and [UID:0002P2] already prove one-slot vtable data and WeatherLayerPane boundary.
  - [UID:0000TQ] and [UID:0000WD] already prove `g_pfnCreateEventW` / `CreateEventW` dispatch.
- Existing docs stale or incomplete:
  - [UID:0001NX] contains Wave2/prewave details, old MCP-timeout caveats, and old `95/95` code-gate language.
  - [UID:0001NX], [UID:0001NY], [UID:0002L8], and [UID:0002L9] currently route through broad or aggregate owners rather than the WaitableTimer class.
  - [UID:0002L8] and [UID:0002L9] remain blank even though their behavior is exact enough for first-draft C++ under the current gate if routing is repaired.
  - [UID:0001QT] still says `WaitableTimer` uses a worker-thread handle; that should become callback gate event.
  - `by-memory/-coverage-report.md` row for [UID:0001NX] still reports `78%` and Wave2/prewave provenance.
- Generated/coverage state:
  - `auto-generated/NexusTK/util/WaitableTimer.cpp` only contains empty markers for class, layout, vtable, target aggregate, raw aggregate, and raw children. It emits no source bodies.
  - `auto-generated/-ag-memory-coverage.md` routes WaitableTimer items through [UID:0000P7] and marks code `no`, matching the current blank C++ state but not the recommended class-owner cleanup.

## Ranked Ownership Analysis

### 1. [UID:0000FY] WaitableTimer class

- Evidence for: vtable identity, class layout, constructor/destructor stores, shared field offsets, raw helper `thiscall` shapes, callback `this` argument, and all source state belonging to one class.
- Evidence against: no live constructor/caller route found and original public/private method names are not proven.
- Decision: best direct semantic owner. Use for [UID:0001NX], [UID:0001NY], [UID:0002L8], and [UID:0002L9] if implementation is accepted. Route class output through [UID:0000P7].

### 2. [UID:0000P7] WaitableTimer file

- Evidence for: proposed source tree places `WaitableTimer.cpp` under `NexusTK/util/`; file page already owns the module; class page routes to file; the island is a standalone utility wrapper.
- Evidence against: file is too broad as canonical owner for class methods under current owner rules.
- Decision: keep as source file root and emitted source path, not the direct owner for methods/raw helpers.

### 3. [UID:0000OT] TimerMgr file / timer subsystem

- Evidence for: both modules use WinMM timers and are near each other in the proposed `util` timing/threading family.
- Evidence against: no direct xrefs from TimerMgr to WaitableTimer were found; TimerMgr is a high-level queue/scheduler, while WaitableTimer is a low-level event/multimedia timer wrapper; meta docs already warn not to merge without caller proof.
- Decision: reject as direct owner. Mention as adjacent subsystem/dependency context only.

### 4. PlatformApi / WideApiDispatchTable

- Evidence for: constructor/start use `g_pfnCreateEventW`.
- Evidence against: PlatformApi owns the dispatch slot, not the WaitableTimer class behavior; WaitableTimer only consumes the API.
- Decision: dependency only.

### 5. No-owner/non-emitting

- Evidence for: no direct constructor/caller route and unresolved original names.
- Evidence against: vtable/class/layout evidence and current class/file pages are strong; unresolved callers do not block ownership.
- Decision: reject no-owner. Keep aggregate C++ blank where range shape blocks code, but ownership is class-backed.

## Source Placement

- Recommended placement: `NexusTK/util/WaitableTimer.cpp` and likely `NexusTK/util/WaitableTimer.h`, through [UID:0000P7].
- Why it fits: proposed source tree groups WaitableTimer with utility threading/synchronization modules and keeps it separate from TimerMgr; behavior is a reusable Win32 event/critical-section/multimedia-timer primitive.
- Rejected placements:
  - `TimerMgr.cpp`: no direct route and different abstraction level.
  - Platform/Win32 API dispatch file: only API dependency, not behavior ownership.
  - UI/application files: no callers or UI/resource evidence.
- Remaining uncertainty: final original source may have nested WaitableTimer inside a timing module or named the start/cancel helpers differently. Current best source shape is a standalone utility class.

## Range / Split / Padding / Reclassification Analysis

- Exact island boundaries:
  - Predecessor `sub_5C0FA0` ends at `0x005c0fe1`; `0x005c0fe1-0x005c0ff0` is padding.
  - Target starts at constructor `0x005c0ff0`.
  - Target ends at scalar deleting destructor end `0x005c129a`.
  - `0x005c129a-0x005c12a0` is padding before successor `sub_5C12A0`.
- Internal child/split facts:
  - `0x005c0ff0-0x005c109c`: modeled constructor, should be an exact child if source code is to be emitted.
  - `0x005c109c-0x005c10a0`: padding.
  - `0x005c10a0-0x005c1111`: modeled non-deleting destructor/cleanup body, should be an exact child.
  - `0x005c1111-0x005c1120`: padding.
  - `0x005c1120-0x005c116a`: existing raw start child.
  - `0x005c116a-0x005c1170`: padding.
  - `0x005c1170-0x005c11b5`: existing raw cancel child.
  - `0x005c11b5-0x005c11c0`: padding.
  - `0x005c11c0-0x005c120e`: modeled callback, should be an exact child.
  - `0x005c120e-0x005c1210`: padding.
  - `0x005c1210-0x005c129a`: modeled scalar deleting destructor, should be an exact child with no-code/compiler-generated proof.
- Reclassification:
  - Do not reclassify [UID:0001NX] to `FALSE` now because it still carries unsplit source-body evidence. If all modeled source bodies are later split and routed through exact child pages, supervisor may optionally demote the parent to a non-emitting audit/container.
  - [UID:0001NY] remains a raw helper aggregate/no-code container; exact children carry source code.

## Negative Evidence Summary

- No direct constructor caller or allocation route was found through `xrefs_to`, `xref_query`, or targeted pointer searches.
- No direct xrefs to raw start/cancel helper starts were found; no VA/RVA pointer patterns for their starts were found.
- The only callback pointer found is the expected `0x005c114a` immediate in the raw start helper.
- No evidence supports `+0x28` as a worker-thread handle; no thread-create path was observed in the island.
- No evidence supports merging WaitableTimer into TimerMgr, UI, application, or PlatformApi ownership.
- Consumer dependency on `CreateEventW`, `timeSetEvent`, `timeKillEvent`, critical sections, and event waits proves behavior but not external source ownership.

## IDA Rename / Type / Comment Recommendations

- IDA DB edits are not requested in this report-only pass.
- Source-facing names/types recommended for documentation and C++:
  - Class: `WaitableTimer`.
  - Fields: `m_completionEvent` at `+0x04`, `m_criticalSection` at `+0x08`, `m_isRunning` at `+0x20`, `m_timerId` at `+0x24`, `m_callbackGateEvent` at `+0x28`.
  - Helpers/methods: `StartMultimediaTimer(UINT delayMilliseconds)`, `CancelMultimediaTimer()`, `WaitableTimerCallback`.
  - Dependency: `g_pfnCreateEventW` / `CreateEventW` dispatch slot at `0x0069be3c`.
- Items intentionally left descriptive:
  - `StartMultimediaTimer` and `CancelMultimediaTimer` are behavior-derived names; original spelling remains unresolved.
  - `WaitableTimerCallback` is a source-facing static callback name; exact original free/static/member spelling remains unresolved.
  - Constructor exception type/source shape should name the documented Win32 error object only after [UID for `sub_4A60D0`] is confirmed in a dedicated pass; current docs can say it throws a `Win32Error`-style object on null event creation.

## First-Draft C++ Recommendation

- Eligible for draft C++ now if accepted and emitter route is corrected: [UID:0002L8] and [UID:0002L9].
- Not eligible for aggregate C++: [UID:0001NX] and [UID:0001NY].
- Proposed code for [UID:0002L8]:

```cpp
void WaitableTimer::StartMultimediaTimer(UINT delayMilliseconds)
{
    m_isRunning = true;
    m_callbackGateEvent = g_pfnCreateEventW(NULL, FALSE, FALSE, NULL);

    UINT timerId = 0;
    do
    {
        timerId = timeSetEvent(delayMilliseconds, 5, WaitableTimerCallback,
                               reinterpret_cast<DWORD_PTR>(this), 0);
    }
    while (timerId == 0);

    m_timerId = timerId;
    SetEvent(m_callbackGateEvent);
}
```

- Proposed code for [UID:0002L9]:

```cpp
void WaitableTimer::CancelMultimediaTimer()
{
    EnterCriticalSection(&m_criticalSection);

    m_isRunning = false;
    timeKillEvent(m_timerId);
    CloseHandle(m_callbackGateEvent);
    ResetEvent(m_completionEvent);
    m_timerId = 0;
    m_callbackGateEvent = NULL;

    LeaveCriticalSection(&m_criticalSection);
}
```

- Reason these preserve exact behavior:
  - Start sets the running byte before event creation, creates the gate through the `CreateEventW` dispatch, retries `timeSetEvent` until nonzero, stores the timer id, and signals the gate after registration.
  - Cancel has no branch or null/timer-id guard before the cleanup calls; it clears running before `timeKillEvent`, closes the gate handle, resets the completion event, clears timer/gate fields, and leaves the critical section.
- Source-facing names are inferred/descriptive. They avoid IDA labels and reflect the behavior in a mid-2000s Windows C++ utility class.
- Aggregate no-code proof:
  - [UID:0001NX] contains multiple source bodies, raw helper code, padding, a callback, and a compiler scalar deleting destructor. A single C++ body would be invalid and would either duplicate child source or hand-port compiler artifacts.
  - [UID:0001NY] contains two separate source helper bodies and padding. It should either contain no C++ or only a `[[CHILDREN]]` insertion route if supervisor chooses to keep exact raw children nested there.
- Proposed future exact child source shapes:
  - Constructor: `WaitableTimer::WaitableTimer()` creates the completion event, throws a Win32 error object on failure, initializes the critical section, and clears running/timer/gate fields.
  - Destructor: `WaitableTimer::~WaitableTimer()` kills active timer state, closes handles, resets completion event, leaves/deletes critical section, and closes the completion event.
  - Callback: `static void CALLBACK WaitableTimerCallback(UINT, UINT, DWORD_PTR user, DWORD_PTR, DWORD_PTR)` casts `user` to `WaitableTimer*`, clears running, waits/closes gate, clears timer/gate fields, signals completion event, and leaves the critical section.
  - Scalar deleting destructor: no source C++; compiler-generated from the virtual destructor and delete flag.

## Final Recommendation

- Update [UID:0001NX] to `88/90`, owner/emitter [UID:0000FY], reconstructable true, blank C++.
- Replace stale evidence basis with MCP session `ff68e691`, PE SHA-256, exact function/raw-helper/padding facts, xref facts, decompilation facts, and negative route checks.
- Preserve unresolved caveats: no direct constructor/caller route, original method spelling unknown, public/private status unknown, exact callback helper spelling unknown, constructor exception helper details not fully resolved, and final TimerMgr relationship blocked absent caller proof.
- Update support docs to route ownership through WaitableTimer class, keep source file as `NexusTK/util/WaitableTimer.cpp`, correct worker-thread wording, document raw helper no-route evidence, and identify raw children as first-draft C++ ready.
- Do not edit coverage directly. Supply exact replacement row text below for supervisor-owned application.

## Recommended Target Doc Changes

- Target path: `by-memory/0x005c0ff0-0x005c129a.WaitableTimer.md`
- Metadata:
  - `COMPLETION:88`
  - `CONFIDENCE:90`
  - `CANONICAL_OWNER:0000FY`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:0000FY`
  - blank `EMITTER_POSITION_OPTIONAL`
  - blank `RECONSTRUCTION_CPP`
- Exact facts to incorporate:
  - Current MCP session `ff68e691`, endpoint `http://127.0.0.1:13337/mcp`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
  - PE SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
  - Modeled function starts/sizes, raw not-function starts, exact byte/padding facts, vtable bytes, xrefs, callees/imports, decompilation behavior, and no-route checks.
  - Replace `Wave2`, `prewave`, stale MCP timeout, and old `95/95` C++ blocker language.
  - Ownership reroute: class direct owner, file source root.
  - No aggregate C++ proof and exact children/source split recommendation.

## Recommended Support Doc Changes

- `by-class/WaitableTimer.md`
  - Add current MCP session `ff68e691` proof.
  - Update ownership/source-placement to make class the direct owner for target and raw helpers, with file [UID:0000P7] as source route.
  - Replace `+0x28` worker-thread wording with callback-gate event wherever stale.
  - Add/retain field names and method/helper list, with caveat that source spellings are inferred.
  - Add first-draft method readiness notes for [UID:0002L8]/[UID:0002L9] and split-needed notes for constructor/destructor/callback/scalar deleting destructor.
- `by-file/WaitableTimer.md`
  - Replace stale evidence with `ff68e691`.
  - Keep source placement `NexusTK/util/WaitableTimer.cpp`.
  - Clarify file owns the module/source root while the class is the direct semantic owner for method/range pages.
  - Preserve TimerMgr rejection and no direct caller/lifetime caveat.
- `by-memory/0x005c1120-0x005c11b5.WaitableTimerRawStartStop.md`
  - Update to current MCP evidence.
  - Keep as no-code aggregate; optionally reroute owner/emitter to [UID:0000FY] or add only a child insertion route if supervisor wants nested child emission.
  - Preserve not-function/no-xref/no-pointer-ref evidence and exact padding.
- `by-memory/0x005c1120-0x005c116a.WaitableTimerStartMultimediaTimer.md`
  - Update to `88/92`, owner/emitter [UID:0000FY] if accepted.
  - Add first-draft C++ above.
  - Preserve no-function/no-xref/no-pointer-ref evidence, callback xref, exact API call order, retry loop, and field writes.
- `by-memory/0x005c1170-0x005c11b5.WaitableTimerCancelMultimediaTimer.md`
  - Update to `88/92`, owner/emitter [UID:0000FY] if accepted.
  - Add first-draft C++ above.
  - Preserve no-function/no-xref/no-pointer-ref evidence and exact critical-section/timer/handle/reset field behavior.
- `by-type/by-struct/WaitableTimerLayout.md`
  - Add current MCP confirmation if not already present; keep `+0x28` callback-gate event correction.
  - Note `+0x21` is padding after the running byte and class size is `0x2c` / 44 bytes (Verified with int_convert.py).
- `by-type/by-vtable/WaitableTimerVtable.md` and `by-memory/0x00631184-0x0063118c.WaitableTimerVtableData.md`
  - Add current `ff68e691` confirmation if not already present; preserve one-slot table and WeatherLayerPane boundary.
- `by-global/WideApiDispatchTable.md` and `by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md`
  - No required metadata change. Optional note only if stale: WaitableTimer constructor/start helper are current `g_pfnCreateEventW` consumers.
- `by-meta/client_threading.md`
  - Replace "worker-thread handle" wording with callback-gate event.
  - Keep live construction path open.
- `by-meta/client_timing.md`
  - Keep WaitableTimer separate from TimerMgr absent caller proof; add current MCP confirmation if stale.

## Score And Metadata Recommendation

- Current target score/metadata: `86/86`, owner/emitter [UID:0000P7], reconstructable true, blank C++.
- Recommended target score/metadata: `88/90`, owner/emitter [UID:0000FY], reconstructable true, blank C++.
- Score rationale:
  - Completion rises because current report resolves stale evidence wording, exact boundaries, raw helper status, vtable/layout/type support, field names, dependency identities, route checks, source placement, and first-draft child C++ disposition.
  - Confidence rises because MCP session `ff68e691` directly confirms function boundaries, xrefs, bytes, decompilation, imports, vtable bytes, and negative pointer checks.
  - Not higher than `88/90` because the target aggregate still lacks exact child pages for constructor/destructor/callback/scalar deleting destructor, no direct live construction/caller route was found, original method spellings/visibility remain inferred, and aggregate C++ must stay blank.
- Metadata changes:
  - Change [UID:0001NX] direct owner/emitter from file [UID:0000P7] to class [UID:0000FY].
  - Keep source file root [UID:0000P7] unchanged via class.
  - Keep reconstructable true until missing source bodies are split and routed.

## Open Questions With Attempted Resolution

- Live construction/caller route:
  - Checked `xrefs_to`, `xref_query`, and pointer patterns for constructor/raw helpers.
  - Result: no direct route found. This remains unresolved and caps score/C++ confidence for public API naming.
- Original start/cancel/helper names:
  - Checked current docs, generated output, xrefs, and behavior.
  - Result: no original-proof names. Use descriptive `StartMultimediaTimer`, `CancelMultimediaTimer`, and `WaitableTimerCallback`.
- Constructor exception source:
  - Decompiler shows allocation/constructor path and `_CxxThrowException` for a Win32Error-style object.
  - Result: enough to document throw behavior, but not enough to finalize exact constructor code without a child page and supporting exception-helper review.
- TimerMgr relationship:
  - Checked by-meta timing/threading docs and direct route evidence.
  - Result: keep separate; merge only if future caller/lifetime evidence proves original source grouping.
- Aggregate reconstructable classification:
  - [UID:0001NX] remains true because it still carries source-body evidence for unsplit parts of the island.
  - If exact children are later created for all bodies, supervisor can re-evaluate whether the parent becomes a non-emitting audit/container.

## Exact Supervisor-Owned Coverage Text

- File/placement: `by-memory/-coverage-report.md`, replace the existing [UID:0001NX] row. Do not apply directly in B005 report-only work.

```text
    - [UID:0001NX][0x005c0ff0-0x005c129a.WaitableTimer](by-memory/0x005c0ff0-0x005c129a.WaitableTimer.md) 0x005c0ff0-0x005c129a | class aggregate | WaitableTimer : reconstructable : 88% : strong : B005 2026-06-23 MCP session ff68e691 confirms exact island boundaries, PE SHA-256 9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632, modeled functions at 0x005c0ff0/0x005c10a0/0x005c11c0/0x005c1210, raw start/cancel helpers at 0x005c1120/0x005c1170 with no IDA function objects or direct xrefs, callback data ref from 0x005c1149, vtable slot 0x00631188, CreateEventW dispatch 0x0069be3c, and 0xcc padding before/inside/after the island; route direct ownership through WaitableTimer class, keep util/WaitableTimer.cpp as the source file root, leave aggregate C++ blank, and put first-draft source only on exact child bodies.
```

- Optional child-row replacements if supervisor accepts raw-child C++/score reroute in the same implementation callback:

```text
        - [UID:0001NY][0x005c1120-0x005c11b5.WaitableTimerRawStartStop](by-memory/0x005c1120-0x005c11b5.WaitableTimerRawStartStop.md) 0x005c1120-0x005c11b5 | aggregate | WaitableTimer raw start/cancel helpers : reconstructable : 88% : very-strong : B005 2026-06-23 MCP session ff68e691 reconfirms the two raw non-IDA-modeled helper bodies, no direct xrefs or VA/RVA pointer refs to either start, callback pointer xref 0x005c1149 -> 0x005c11c0, 0xcc padding between/after helpers, and source routing through the WaitableTimer class; keep aggregate C++ blank and emit source through exact children.
            - [UID:0002L8][0x005c1120-0x005c116a.WaitableTimerStartMultimediaTimer](by-memory/0x005c1120-0x005c116a.WaitableTimerStartMultimediaTimer.md) 0x005c1120-0x005c116a | method | WaitableTimer::StartMultimediaTimer : reconstructable : 88% : very-strong : MCP-backed raw helper sets running, creates the callback-gate event through g_pfnCreateEventW/CreateEventW, loops timeSetEvent(delay,5,0x005c11c0,this,0) until a nonzero timer id, stores +0x24, signals +0x28, has no function object or direct route, and is ready for first-draft C++ with inferred source spelling.
            - [UID:0002L9][0x005c1170-0x005c11b5.WaitableTimerCancelMultimediaTimer](by-memory/0x005c1170-0x005c11b5.WaitableTimerCancelMultimediaTimer.md) 0x005c1170-0x005c11b5 | method | WaitableTimer::CancelMultimediaTimer : reconstructable : 88% : very-strong : MCP-backed raw helper enters +0x08 critical section, clears +0x20 without a guard, kills +0x24 with timeKillEvent, closes +0x28, resets +0x04, clears +0x24/+0x28, leaves the critical section, has no function object or direct route, and is ready for first-draft C++ with inferred source spelling.
```

## Follow-Up Actions

- Supervisor actions:
  - Decide whether the implementation callback should include only [UID:0001NX] and support-doc evidence, or also the raw child C++/reroute.
  - Apply coverage text after verifying implementation; B005 must not edit coverage directly.
  - Consider a future split callback for constructor/destructor/callback/scalar deleting destructor exact pages.
- A-agent actions:
  - If accepted, update by-* docs at report-level detail and run scoped validators for every changed by-* doc.
- B005 future research:
  - Search for indirect construction/lifetime route if assigned a deeper WaitableTimer/TimerMgr pass.
  - Review Win32Error helper around `sub_4A60D0` if constructor C++ is accepted later.

## Confidence

- Recommendation confidence: strong for class/file placement, range facts, and no aggregate C++; medium for final helper names and exact source visibility.
- Score confidence: strong for `88/90`. Higher scores need exact child splits and live construction/caller evidence or stronger source-name proof.
- Remaining uncertainty: original method spellings, public/private visibility, constructor exception helper source shape, and any indirect/factory construction route.

## Validator Results

- Implementation validators run from `E:\NTK\GhidraBridge\source-3\project-documentation` after the by-* edits. Every scoped command exited `0`, scanned one markdown file, and reported `ok: 1`.

| File | Command | Exit | Result |
| --- | --- | --- | --- |
| `by-memory/0x005c0ff0-0x005c129a.WaitableTimer.md` | `python .\tools\validator.py --mode file --file by-memory\0x005c0ff0-0x005c129a.WaitableTimer.md --apply --queue-timeout 240` | 0 | `ok: 1`; metadata/owner updates applied in the first run and projected stats refreshed. |
| `by-class/WaitableTimer.md` | `python .\tools\validator.py --mode file --file by-class\WaitableTimer.md --apply --queue-timeout 240` | 0 | `ok: 1`; reference index/projected stats refreshed. |
| `by-file/WaitableTimer.md` | `python .\tools\validator.py --mode file --file by-file\WaitableTimer.md --apply --queue-timeout 240` | 0 | `ok: 1`; reference index/projected stats refreshed. |
| `by-memory/0x005c1120-0x005c11b5.WaitableTimerRawStartStop.md` | `python .\tools\validator.py --mode file --file by-memory\0x005c1120-0x005c11b5.WaitableTimerRawStartStop.md --apply --queue-timeout 240` | 0 | `ok: 1`; metadata/owner route and projected stats refreshed. |
| `by-memory/0x005c1120-0x005c116a.WaitableTimerStartMultimediaTimer.md` | `python .\tools\validator.py --mode file --file by-memory\0x005c1120-0x005c116a.WaitableTimerStartMultimediaTimer.md --apply --queue-timeout 240` | 0 | `ok: 1`; score/owner/C++ emitter route projected and generated output refreshed. |
| `by-memory/0x005c1170-0x005c11b5.WaitableTimerCancelMultimediaTimer.md` | `python .\tools\validator.py --mode file --file by-memory\0x005c1170-0x005c11b5.WaitableTimerCancelMultimediaTimer.md --apply --queue-timeout 240` | 0 | `ok: 1`; score/owner/C++ emitter route projected and generated output refreshed. |
| `by-type/by-struct/WaitableTimerLayout.md` | `python .\tools\validator.py --mode file --file by-type\by-struct\WaitableTimerLayout.md --apply --queue-timeout 240` | 0 | `ok: 1`; reference index/projected stats refreshed. |
| `by-type/by-vtable/WaitableTimerVtable.md` | `python .\tools\validator.py --mode file --file by-type\by-vtable\WaitableTimerVtable.md --apply --queue-timeout 240` | 0 | `ok: 1`; reference index/projected stats refreshed. |
| `by-memory/0x00631184-0x0063118c.WaitableTimerVtableData.md` | `python .\tools\validator.py --mode file --file by-memory\0x00631184-0x0063118c.WaitableTimerVtableData.md --apply --queue-timeout 240` | 0 | `ok: 1`; reference index/projected stats refreshed. |
| `by-meta/client_threading.md` | `python .\tools\validator.py --mode file --file by-meta\client_threading.md --apply --queue-timeout 240` | 0 | `ok: 1`; reference index/projected stats refreshed. |
| `by-meta/client_timing.md` | `python .\tools\validator.py --mode file --file by-meta\client_timing.md --apply --queue-timeout 240` | 0 | `ok: 1`; reference index/projected stats refreshed. |

- Validator-owned side effects observed: `tools/validator.ini`, `project-level/-auto-completion-stats.md`, and `auto-generated/NexusTK/util/WaitableTimer.cpp` refreshed from the scoped validator runs. `auto-generated/NexusTK/util/WaitableTimer.cpp` now contains [UID:0002L8] and [UID:0002L9] generated first-draft C++ and empty emitter markers for aggregate/container pages.
- Lease closeout: the post-validator `leaser.py B005 unlease ...` command returned `Rejected[No active lease]` for each edited path because the short-lived leases had already expired. A subsequent read of `tools/leaser/Agents/current_leases.md` showed no B005 leases and only unrelated B001 Application leases.

## Changed Files

- Updated by B005 implementation:
  - `by-memory/0x005c0ff0-0x005c129a.WaitableTimer.md`
  - `by-class/WaitableTimer.md`
  - `by-file/WaitableTimer.md`
  - `by-memory/0x005c1120-0x005c11b5.WaitableTimerRawStartStop.md`
  - `by-memory/0x005c1120-0x005c116a.WaitableTimerStartMultimediaTimer.md`
  - `by-memory/0x005c1170-0x005c11b5.WaitableTimerCancelMultimediaTimer.md`
  - `by-type/by-struct/WaitableTimerLayout.md`
  - `by-type/by-vtable/WaitableTimerVtable.md`
  - `by-memory/0x00631184-0x0063118c.WaitableTimerVtableData.md`
  - `by-meta/client_threading.md`
  - `by-meta/client_timing.md`
  - `tools/leaser/Agents/Agent-B005/research/0001NX-WaitableTimer-source-quality.md`
- Validator-owned/generated refreshes from `--apply`: `tools/validator.ini`, `project-level/-auto-completion-stats.md`, and `auto-generated/NexusTK/util/WaitableTimer.cpp`.
- Not edited by B005: any `-coverage-report.md` file, IDA DB, tool state outside validator/leaser normal operation, and unrelated docs.
- Moved to executed: none.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation. Proof: supervisor accepted this report and issued `B005-implement-waitable-timer-source-quality-0001NX-mcp-20260623`.
- [x] Target doc to update: `by-memory/0x005c0ff0-0x005c129a.WaitableTimer.md` now contains current MCP session `ff68e691`, PE SHA-256, function/range/body state, padding, decompilation, xrefs, vtable/layout evidence, negative route checks, source-placement analysis, score rationale, and aggregate no-code proof.
- [x] Metadata/score changes to apply to [UID:0001NX]: applied `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000FY`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000FY`, blank emitter position, blank C++.
- [x] Owner/source-placement changes to apply: target/raw helpers now route directly to [UID:0000FY], with [UID:0000P7] / `NexusTK/util/WaitableTimer.cpp` preserved as source file root; TimerMgr/PlatformApi/UI/Application routes are rejected in target/support docs.
- [x] Support docs to update if accepted: updated all required support docs listed in the callback. `by-memory/0x00631184-0x0063118c.WaitableTimerVtableData.md` uses actual UID [UID:0002P2].
- [x] Split/rename/new-child changes to apply or defer: no constructor/destructor/callback/scalar-deleting exact child pages were created in this callback; target/class/file docs preserve them as future split recommendations.
- [x] Source-facing names to apply: docs and child C++ now use `m_completionEvent`, `m_criticalSection`, `m_isRunning`, `m_timerId`, `m_callbackGateEvent`, `StartMultimediaTimer`, `CancelMultimediaTimer`, `WaitableTimerCallback`, and `g_pfnCreateEventW` / `CreateEventW`, with original-spelling caveats.
- [x] First-draft C++ to apply only if supervisor accepts raw child implementation: added first-draft C++ to [UID:0002L8] and [UID:0002L9] after owner/emitter reroute. The [UID:0002L9] body intentionally has no `if (m_timerId != 0)` guard because raw evidence shows no branch before `timeKillEvent`, `CloseHandle`, and `ResetEvent`; this corrects the earlier draft without changing the accepted behavior requirement of exact raw preservation.
- [x] No-code proof to apply: [UID:0001NX] and [UID:0001NY] remain blank aggregate/multi-body C++ slots; scalar deleting destructor remains a future no-code/compiler-generated split recommendation.
- [x] Historical/stale assumptions to remove or mark superseded: Wave2/prewave, old MCP-timeout, old `95/95` code-gate, generated `m_hWorkerThread`, generated `WaitableTimer::Cleanup`, and generated `WaitableTimerCompletion_5C11C0` are removed as authority or explicitly superseded/search aliases.
- [x] Negative evidence to preserve: target/support docs preserve zero xrefs to constructor/raw helper starts, zero VA/RVA pointer hits for raw helper starts, no TimerMgr merge proof, no live construction path, and no original method spelling proof.
- [x] Open questions to keep evidence-backed unresolved: docs keep live construction/caller route, source names/visibility, constructor exception helper details, and TimerMgr relationship unresolved with evidence-backed caps.
- [x] Validators to run in implementation: all eleven scoped validators ran with exit code `0` and `ok: 1`; see Validator Results.
- [x] Supervisor-owned coverage-report text to apply: exact [UID:0001NX]/[UID:0001NY]/[UID:0002L8]/[UID:0002L9] coverage text remains supplied in this report; no `-coverage-report.md` file was edited.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation. Proof: callback named this report and assignment ID.
- [x] All accepted target/support doc details incorporated at report-level detail. Proof: required target, class/file, raw aggregate/children, layout/vtable/vtable-data, threading, and timing pages updated.
- [x] Metadata/score/owner/emitter/C++ changes applied or explicitly not applied with reason. Proof: [UID:0001NX] `88/90`, [UID:0001NY] `88/92`, [UID:0002L8]/[UID:0002L9] `88/92`, owner/emitter [UID:0000FY]; aggregate C++ blank; exact child C++ emitted.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: docs supersede stale Wave/prewave/MCP-timeout/generated-name language and retain TimerMgr/no-route/original-name caveats.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale. Proof: live construction route, original names/visibility, constructor exception helper details, and TimerMgr relationship remain documented as unresolved.
- [x] Validators run and results recorded. Proof: Validator Results table records command, exit code `0`, and `ok: 1` for every changed by-* doc.
- [x] Supervisor-owned coverage-report/tracker text supplied or confirmed unchanged. Proof: exact row text remains in this report; B005 did not edit `by-memory/-coverage-report.md` or other `-coverage-report.md` files.
- [x] Remaining unapplied accepted items listed with exact blocker. Proof: no accepted non-coverage item remains blocked. Future child-page creation was explicitly out of callback scope; WideApi dispatch docs were checked and already contained the required `g_pfnCreateEventW` / `CreateEventW` consumer notes at sufficient detail, so they were not changed.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/0001NX-WaitableTimer-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:17","uid":"0001NX"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
