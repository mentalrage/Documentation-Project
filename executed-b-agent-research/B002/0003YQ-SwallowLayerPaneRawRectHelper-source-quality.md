** TARGET-REPORT-UID:0003YQ **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003YQ **
# 0003YQ SwallowLayerPaneRawRectHelper MCP-Backed Source-Quality Research

## Finalized Report / Current Recommendation
- Implemented recommendation: keep [UID:0003YQ] as a `SwallowLayerPane` raw current-rectangle helper, correct the stale page range from `0x005c29a0-0x005c29ea` to `0x005c29a0-0x005c29ec`, and raise the target to `86/89` after target/support docs incorporated the MCP-backed evidence below.
- Final disposition: direct owner/emitter remain [UID:0000E9] `SwallowLayerPane`; `RECONSTRUCTABLE:TRUE` remains correct; formal C++ must remain blank because no live caller/pointer/table/vtable/source route is proven.
- Implementation status: supervisor accepted this MCP-backed report, and the B002 implementation callback has been completed. Remaining supervisor-owned actions are verification, applying the coverage text if accepted, coverage validation, and moving this report to executed.
- Confidence: high for exact boundary, field roles, Swallow ownership, and negative route checks because accepted IDA MCP session `0b5e057e` confirmed the key facts and current resumed session `b880584f` reconfirmed the boundary/no-route subset after the supervisor restart; medium for exact original source-facing helper name/type and live-method status.

## Supporting Research

This is the MCP-backed redo for assignment `B002-redo-swallow-raw-rect-helper-source-quality-0003YQ-mcp-20260623`. The prior report's raw PE/Ghidra fallback was treated as a lead only. Current supervisor instruction required IDA MCP evidence before report acceptance.

Required context read for this redo:

- `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B002\goal.md`
- `E:\NTK\GhidraBridge\.codex\skills\ntk-b-agent-workflow\SKILL.md`
- `E:\NTK\GhidraBridge\.codex\skills\ntk-b-agent-workflow\references\b-agent-research-and-implementation-workflow.md`
- `E:\NTK\GhidraBridge\source-3\project-documentation\by-structure.md` and folder guidance already used by this target family

MCP redo provenance:

- Endpoint: `http://127.0.0.1:13337/mcp`
- Active IDB session used: `0b5e057e`
- Discarded stale sessions: `15216dde` and `0f0b38fb`
- `server_health`: `status:"ok"`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`
- `idb_list`: one active adopted worker session `0b5e057e` for `NexusTK.exe.i64`
- Post-restart/resume confirmation session: supervisor restarted MCP for logging/debug hardening and assigned active session `b880584f`; B002 did not start, stop, restart, or kill MCP/IDA. Lightweight read-only JSON-RPC confirmation at `2026-06-23T10:12:21Z`/`2026-06-23T10:12:41Z` used `initialize`, `tools/list`, `server_health`, `idb_list`, `lookup_funcs`, `get_bytes`, `disasm`, `xrefs_to`, and `find_bytes`. Current session `b880584f` reported `server_health status:"ok"`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, one active worker session `b880584f`, `lookup_funcs` no function at `0x005c299f`, `0x005c29a0`, or `0x005c29ea`, successor `sub_5C29EC` at `0x005c29ec` size `0xb`, `get_bytes 0x005c29e8 size 8` as `5d c2 04 00 81 e9 a0 00`, `disasm 0x005c29a0` as `<no function>` through `0x005c29e9: retn 4` followed by `sub_5C29EC` at `0x005c29ec`, `xrefs_to 0x005c29a0` with zero xrefs, `xrefs_to 0x005c29ec` with one data xref from `0x00631304`, no `A0 29 5C 00` or `A0 29 1C 00` raw-start pointer hit, and one `EC 29 5C 00` successor-pointer hit at `0x00631304`.
- MCP schema note for the resume pass: an initial local PowerShell parser attempt failed before producing an MCP result because this host's `ConvertFrom-Json` lacks `-Depth`; after removing that parameter, MCP requests succeeded. Two first-form tool calls used stale argument shapes (`get_bytes` with `regions.start`, `disasm` with `addrs`) and returned schema/tool-argument errors; after following the current `tools/list` schema (`regions.addr` and `addr`), both calls succeeded. These were request-shape corrections, not MCP unavailability, timeout, refused connection, or stale session.

No by-* docs, generated/project-level files, IDA DB, tool state, support docs, or coverage reports were edited during the MCP report redo. During the later accepted implementation callback, B002 edited only the accepted target/support by-* docs and this report; no `-coverage-report.md`, IDA DB, by-project-structure, or unrelated docs were manually edited.
Path-state reconciliation: the corrected target path `by-memory/0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper.md` exists and the old `by-memory/0x005c29a0-0x005c29ea.SwallowLayerPaneRawRectHelper.md` path remains absent. The implementation reconciled the stale pre-MCP target text into current MCP-backed evidence instead of recreating the old file.

## Target
- Target UID: `0003YQ`
- Original stale target path from the redo assignment: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x005c29a0-0x005c29ea.SwallowLayerPaneRawRectHelper.md`
- Recommended corrected target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper.md`
- Source queue/report row: `B002-redo-swallow-raw-rect-helper-source-quality-0003YQ-mcp-20260623`
- Current supervisor classification: MCP-backed source-quality redo for raw `SwallowLayerPane` current-rectangle helper, starting from `85/87`
- Starting scores and parent state: target `85/87`, direct owner/emitter [UID:0000E9] `SwallowLayerPane`, reconstructable true, blank formal C++; related parent/migration docs are [UID:0001O2] `SwallowLayerPaneCore`, [UID:0001O3] `SwallowLayerPaneRawFlightHelpers`, and [UID:0001O1] `SnowingAndSwallowLayerPanes`. Implemented target state is `86/89` with owner/emitter/reconstructable unchanged and formal C++ still blank.

## Current Target State
- Starting metadata changed during implementation: `COMPLETION:85`, `CONFIDENCE:87`, stale `MEMORY_RANGE:0x005c29a0-0x005c29ea`.
- Metadata kept during implementation: `CANONICAL_OWNER:0000E9`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000E9`, blank `EMITTER_POSITION_OPTIONAL`, blank `RECONSTRUCTION_CPP`.
- Existing open questions/blockers: no modeled IDA function at `0x005c29a0`; no proven incoming route; exact output rectangle source type is unresolved; final `SwallowLayerPane.cpp` versus broader `WeatherLayerPane.cpp` source placement remains a weather-family migration question.
- Existing stale assumption now contradicted by MCP: current docs say `0x005c29ea-0x005c29ec` is alignment. IDA MCP `get_bytes` and `disasm` show those bytes are part of the `retn 4` instruction at `0x005c29e9`, and the Snowing thunk starts at `0x005c29ec`.

## Executive Recommendation
- Best direct owner: [UID:0000E9] `SwallowLayerPane`.
- Range action: rename/update [UID:0003YQ] to `0x005c29a0-0x005c29ec`. This is a boundary repair of the existing child concept, not a new child split.
- Split/padding action: do not create a `0x005c29ea-0x005c29ec` padding child. MCP proves those bytes are not padding.
- Score action: raise to `86/89` after accepted incorporation. The score moves above `85/87` because the exact range and negative routes are now MCP-backed, but remains capped because the helper has no live route and no source-quality C++.
- C++ action: keep formal C++ blank. A readable source shape exists, but by-structure code quality is not met because liveness and original source shape remain unproven.
- Condition before C++ can be emitted: a live caller, function pointer/table entry, vtable route, source/debug symbol, or equivalent direct route to `0x005c29a0` must be found, and the project-local rectangle type/name must be resolved strongly enough to avoid decompiler-shaped private-helper code.

## Supervisor Active Recheck
- Redo-time supervisor instruction: redo/update the report with IDA MCP evidence; if MCP failed during that MCP-dependent evidence pass, stop with `PAUSED_MCP_UNAVAILABLE`.
- MCP result: MCP responded for session `0b5e057e`; required evidence was collected from `server_health`, `idb_list`, `lookup_funcs`, `get_bytes`, `disasm`, `decompile`, `xrefs_to`, `xref_query`, `callees`, `find_bytes`, and `get_int`.
- Split repair requirement: yes, but as a narrow corrected half-open range. No additional source-bearing child is needed.
- Implementation status: completed after supervisor acceptance. Target/support by-* docs were updated at report-level detail under B002 leases, and scoped validators passed.

## Inference Research Guidance Check
- Existing docs and the prior raw-only report were treated as leads. IDA MCP session `0b5e057e` is now the authoritative current evidence for acceptance.
- Important assumptions rechecked: current end address, claimed padding, function-object status, xrefs/callers, byte pattern pointer hits, vtable/table route, outgoing callee, source owner, no-code proof, and coverage/support text.
- Direct IDA facts are separated from inferred source-facing names. `GetCurrentSwallowRect` remains descriptive/inferred, not original-name proof.
- Wave2/Wave3 material remains ignored unless current docs use it as a source-placement lead. WeatherLayerPane's old provenance note about split files remains only a migration/source-family clue.

## Heuristic / Inference Reanalysis And Validation
- Range and padding: MCP `lookup_funcs` reports `0x005c29a0`, `0x005c29ea`, and `0x005c299f` are not functions, while `0x005c29ec` is function `sub_5C29EC` size `0xb`. MCP `disasm 0x005c29a0` shows `<no function>` code from `0x005c29a0` through `retn 4` at `0x005c29e9`, followed immediately by `sub_5C29EC` at `0x005c29ec`. This confirms corrected range `0x005c29a0-0x005c29ec`.
- Raw helper role: direct disassembly shows the body selects frame-rect offset `0x12c` when `[esi+0x118] == 1`, otherwise offset `0x154`, copies four dwords to the caller output pointer in `ecx`, pushes `[esi+0x114]` and `[esi+0x110]`, and calls `sub_4B78F0`. This is original-proof for "copy selected current Swallow frame rect and offset it"; it is inference for "private current-rect helper".
- Field roles: direct target disassembly proves `+0x118` direction selector, `+0x110/+0x114` current X/Y, and `+0x12c/+0x154` selected rect subfields. MCP decompile of modeled `sub_5C2930` confirms the same dword-index layout: `this[70]` (`+0x118`) selects dword offsets 75 and 85 (`+0x12c` and `+0x154`), `this[68]/this[69]` (`+0x110/+0x114`) feed `sub_4B78F0`, then the virtual slot `+0x20` invalidates the rect.
- Relationship to live Swallow timer method: MCP decompile of `sub_5C2500` confirms the modeled timer handler uses timer ids 256/257, the timer-subobject receiver adjustment (`this - 164`), active state, direction, position, frame rectangles, `sub_4B78F0`, `sub_4B8E00`, `_rand`, `sub_5975E0`, and modeled call `sub_5C2930` at `0x005c25e2`. This ties the raw helper's field family to live `SwallowLayerPane` behavior.
- Liveness: MCP `xrefs_to 0x005c29a0` returns zero incoming xrefs. MCP `callees 0x005c29a0` returns `No function found`. MCP `decompile 0x005c29a0` fails because IDA has no function there. MCP `find_bytes` finds no VA or RVA encodings for `0x005c29a0`.
- Pointer/table/vtable route: MCP `find_bytes` finds the absolute VA bytes for successor `0x005c29ec` exactly once at `0x00631304`; it finds no VA/RVA bytes for `0x005c29a0`, no VA/RVA bytes for stale `0x005c29ea`, and no VA/RVA bytes for `0x005c2930`. MCP `get_int` on nearby vtable slots shows Snowing data at `0x00631304 -> 0x005c29ec` and `0x00631334 -> 0x005c29f7`, while Swallow slots point to `0x005c2a60`, `0x005c26b0`, `0x005c2360`, `0x005c2430`, `0x005c2a02`, `0x005c2a0d`, and `0x005c2500` (decimal values converted with `tools/int_convert.py`). No slot points to `0x005c29a0`.
- Unique body: MCP `find_bytes` for the target body prefix `55 8B EC 56 8B F1 B8 54 01 00 00 8B 4D 08 BA 2C 01 00 00` returns one hit at `0x005c29a0`.
- Name/type: best descriptive name remains `GetCurrentSwallowRect`. Use `RectBounds *outRect` or the project-local rect type if future code is authorized; preserve `RECT *outRect` only as a historical/provisional alias. No source symbol or caller name proves the exact spelling or type.
- Rejected alternatives: BackPane ownership is rejected because this body uses Swallow fields and BackPane only supplies helper dependencies/confusing generated labels. Snowing ownership is rejected because Snowing starts at successor thunk `0x005c29ec`, and the `0x00631304` pointer targets that thunk. Base WeatherLayerPane direct ownership is rejected because this body is concrete Swallow field logic. Pure padding/ignored treatment is rejected because MCP disassembly shows coherent code.

## Evidence Standards Used
- Primary evidence: IDA MCP session `0b5e057e` function lookup, bytes, disassembly, decompilation where available, xrefs, callee query, byte pattern search, vtable value reads, and health/session metadata.
- Supplemental evidence: current by-* docs, generated reports, archived B002 report, and raw PE checks from the prior report remain context only where they agree with MCP.
- Evidence ladder: MCP bytes/disassembly and current xrefs override stale support docs. Decompiled pseudocode is used only to corroborate field relationships in modeled neighboring functions, not to name the raw helper.
- Confidence limiter: the target remains outside IDA's function graph, so MCP cannot provide caller/callee/decompile facts as a normal function. The absence of routes is evidence, but live-method status still remains unresolved.

## Evidence Checked
- MCP session checks:
  - `initialize` and `tools/list` succeeded; server name `ida-pro-mcp`, version `1.0.0`.
  - `server_health database=0b5e057e`: IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto analysis and Hex-Rays ready.
  - `idb_list`: active worker session `0b5e057e`.
- MCP function/range checks:
  - `lookup_funcs` reports `sub_5C2500` at `0x005c2500` size `0x1a6`, `sub_5C2930` at `0x005c2930` size `0x6f`, `0x005c299f` not a function, `0x005c29a0` not a function, `0x005c29ea` not a function, `sub_5C29EC` at `0x005c29ec` size `0xb`, `sub_5C29F7` at `0x005c29f7` size `0xb`, and `sub_5C2A20` at `0x005c2a20` size `0x3b`.
- MCP byte/disassembly checks:
  - `get_bytes 0x005c29a0 size 0x4c` returns the full body ending `... e8 09 4f ef ff 5e 5d c2 04 00`.
  - `get_bytes 0x005c29e8 size 8` returns `5d c2 04 00 81 e9 a0 00`, proving `0x005c29ea-0x005c29eb` are `ret 4` operand bytes and `0x005c29ec` begins the next instruction.
  - `disasm 0x005c29a0 max_instructions=34` names the region `<no function>`, shows the exact helper instructions, then labels `sub_5C29EC` at `0x005c29ec`.
  - `decompile 0x005c29a0` returns `Decompilation failed at 0x5c29a0`, consistent with no function object.
- MCP xref/callee checks:
  - `xrefs_to 0x005c29a0`: zero xrefs.
  - `xrefs_to 0x005c29ea`: zero xrefs.
  - `xrefs_to 0x005c29ec`: one data xref from `0x00631304`.
  - `xrefs_to 0x005c2930`: code xrefs from `0x005c25e2` in `sub_5C2500` and raw code `0x005c291d` with no enclosing IDA function.
  - `xref_query both 0x005c29a0` reports only an internal from-edge to the next instruction (`0x005c29a1`), not an incoming route.
  - `callees 0x005c29a0`: `No function found`.
- MCP decompile checks for surrounding modeled functions:
  - `decompile 0x005c2930`: selects dword offsets 75/85 based on `this[70]`, uses `this[68]/this[69]`, calls `sub_4B78F0`, then calls vslot `+32`.
  - `decompile 0x005c2500`: confirms timer ids 256/257, start/step flight state, `sub_4B78F0`, `sub_4B8E00`, `_rand`, `sub_5975E0`, and modeled call to `sub_5C2930`.
- MCP pointer/table checks:
  - `find_bytes "A0 29 5C 00"` and `"A0 29 1C 00"`: zero matches for VA/RVA `0x005c29a0`.
  - `find_bytes "EA 29 5C 00"` and `"EA 29 1C 00"`: zero matches for stale endpoint `0x005c29ea`.
  - `find_bytes "EC 29 5C 00"`: one match at `0x00631304`; `"EC 29 1C 00"`: zero matches.
  - `find_bytes "30 29 5C 00"` and `"30 29 1C 00"`: zero absolute VA/RVA pointer matches for `0x005c2930`; the known uses are direct rel32 calls instead.
  - `find_bytes` for the raw helper prefix returns exactly one hit at `0x005c29a0`.
  - `get_int` on nearby vtable slots: `0x00631304 -> 0x005c29ec`, `0x00631334 -> 0x005c29f7`, `0x00631340 -> 0x005c2a60`, `0x00631350 -> 0x005c26b0`, `0x00631384 -> 0x005c2360`, `0x00631388 -> 0x005c2430`, `0x00631394 -> 0x005c2a02`, `0x006313c4 -> 0x005c2a0d`, `0x006313c8 -> 0x005c2500` (decimal outputs converted with `tools/int_convert.py`).
- Failed/unavailable checks: none required for this redo. The first `server_health` call without `database` returned the current schema's expected `database is required` error, and an initial `get_bytes` call using old `addr`/`size` arguments returned `missing required parameters: ['regions']`; after `tools/list` schema recheck, the same evidence calls with `database=0b5e057e` and `regions` succeeded. A broad `insn_query` was intentionally not repeated after the previous MCP outage because the narrower MCP `xrefs_to`, `find_bytes`, `get_int`, and disassembly checks answer the target question without destabilizing the server. Final `server_health database=0b5e057e` after evidence collection still returned `status:"ok"`.

## Inference Claim Ledger
| Claim | Confidence | Evidence | Counter-evidence checked | Next verification / remaining uncertainty |
| --- | --- | --- | --- | --- |
| Exact helper range is `0x005c29a0-0x005c29ec` | High | MCP `get_bytes` and `disasm`: `retn 4` at `0x005c29e9`, successor `sub_5C29EC` at `0x005c29ec` | Stale docs say `0x005c29a0-0x005c29ea` and padding after; MCP bytes contradict that | Apply rename/range update if supervisor accepts |
| Direct semantic owner is `SwallowLayerPane` | High | Target field offsets match modeled Swallow timer/invalidation decompilation; successor is Snowing thunk | BackPane labels/dependencies, Snowing successor data, base Weather family considered and rejected | Source file split remains open |
| Helper copies and offsets selected current Swallow rect | High | MCP target disasm copies selected rect and calls `sub_4B78F0`; modeled `sub_5C2930` uses same pattern | None found | Future type pass should name the rect type |
| Helper is proven live original source method | Low | Function-shaped body, plausible helper role | MCP: no function object, zero xrefs to start, zero VA/RVA pointer hits, no vtable slot | Need caller/pointer/source symbol before C++ |
| Best name is `GetCurrentSwallowRect` | Medium | Behavior writes current rect; surrounding docs converge | No source symbol/caller/type proof | Use descriptive/inferred only |
| First-draft C++ is safe now | Low | Behavior is mechanically reconstructable | No liveness/source-shape proof, type unresolved, final file route unresolved | Keep formal C++ blank |
| Score can move above `85/87` | Medium-high | MCP confirms boundary, owner, behavior, and negative routes | No live route or final code | Recommend `86/89`, not higher |

## Positive Evidence Summary
- Direct facts supporting the recommendation: MCP disassembly proves a coherent raw helper at `0x005c29a0` that selects a stored rect based on direction, copies four dwords to the output pointer, calls `sub_4B78F0` with current X/Y, and returns with `retn 4`.
- Boundary support: MCP `lookup_funcs` and `disasm` prove `0x005c29ec` is the next modeled function `sub_5C29EC` and that `0x005c29ea-0x005c29eb` are not padding.
- Ownership support: MCP decompilation of `sub_5C2930` and `sub_5C2500` shows the same Swallow field family and helper dependencies.
- Negative support: MCP finds no incoming xrefs, no function object, no decompile for the raw start, no absolute VA/RVA pointer to `0x005c29a0`, and no vtable slot to the helper.

## IDA MCP Facts
- Function/range facts: `0x005c29a0` is `<no function>` and `lookup_funcs` returns `Not a function`; `0x005c29ec` is `sub_5C29EC` size `0xb`.
- Data/table/padding facts: one byte of predecessor alignment exists at `0x005c299f`; no post-helper padding exists before `0x005c29ec`.
- Xref facts: `xrefs_to 0x005c29a0` and `xrefs_to 0x005c29ea` return zero. `xrefs_to 0x005c29ec` returns data xref `0x00631304`. `xrefs_to 0x005c2930` returns two code refs.
- Vtable/global/type facts: `get_int` and `find_bytes` show the only nearby pointer route is Snowing `0x00631304 -> 0x005c29ec`. Swallow vtable slots route to modeled Swallow methods/thunks, not `0x005c29a0`.
- Negative IDA facts: no decompilation at target, no callee set at target because no function is defined, no incoming xrefs to target, no pointer bytes to target.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x005c2230-0x005c299f` | [UID:0001O2] `by-memory/0x005c2230-0x005c299f.SwallowLayerPaneCore.md` | Swallow modeled core plus aggregate evidence | TRUE | [UID:0000E9] | `88/90` | Excludes [UID:0003YQ]; support text should use corrected sibling range |
| `0x005c2760-0x005c292e` | [UID:0001O3] `by-memory/0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers.md` | Raw start/step flight helper pair | TRUE | [UID:0000E9] | `85/88` | Separate no-function/no-xref raw helpers |
| `0x005c2930-0x005c299f` | inside [UID:0001O2] | Modeled invalidation helper, likely `InvalidateSwallowRect` | TRUE as part of parent | [UID:0000E9] | inherited | MCP `lookup_funcs` size `0x6f`, xrefs from `0x005c25e2` and raw `0x005c291d` |
| `0x005c29a0-0x005c29ec` | [UID:0003YQ] current filename stale as `0x005c29a0-0x005c29ea...` | Raw current-rect helper | TRUE | [UID:0000E9] | recommend `86/89` | Rename/update target; no formal C++ |
| `0x005c29ec-0x005c29f7` | Snowing thunk support docs | Snowing adjustor thunk | not target | SnowingLayerPane | existing | MCP `lookup_funcs` `sub_5C29EC`, size `0xb`, data xref `0x00631304` |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x005c29a0` | MCP `xrefs_to`: zero | No incoming route to raw helper start |
| `0x005c29a0` | MCP `find_bytes` VA/RVA pointer bytes: zero | No absolute pointer route to helper start |
| `0x005c29a0` | MCP `callees`: `No function found`; `decompile`: failed | IDA does not model this raw body as a function |
| `0x005c29e2` | MCP disasm call `sub_4B78F0` | Helper offsets output rect by current Swallow position |
| `0x005c29ec` | MCP `xrefs_to`: data xref from `0x00631304` | Successor Snowing thunk pointer, not target liveness |
| `0x005c2930` | MCP `xrefs_to`: `0x005c25e2`, raw `0x005c291d` | Neighbor modeled invalidation helper is live/reused |

## Documentation Evidence And IDA Status
- Existing docs that support the conclusion: Swallow class/file, WeatherLayerPane file, Swallow core, Swallow raw flight helpers, SnowingAndSwallow migration index, archived B002 report, and current generated output all identify `0x005c29a0` as Swallow-shaped raw rect-helper evidence with blank C++.
- Existing docs that are stale or contradicted: current target/support docs that name `0x005c29a0-0x005c29ea` and claim `0x005c29ea-0x005c29ec` alignment are contradicted by MCP bytes/disassembly.
- Generated/coverage state: `auto-generated/-ag-memory-coverage.md` contains the stale [UID:0003YQ] path/range as marker-only/no-code output. Manual `by-memory/-coverage-report.md` still needs supervisor-owned [UID:0003YQ] row insertion and stale parent sync if accepted.

## Ranked Ownership Analysis

### 1. [UID:0000E9] SwallowLayerPane
- Evidence for: target reads the same concrete direction/position/frame-rect fields that MCP decompilation confirms in modeled Swallow timer/invalidation methods; surrounding Swallow pages and vtable/resource evidence support the class; target sits between Swallow core and Snowing thunk code.
- Evidence against: no proven incoming route and no original source symbol.
- Decision: keep as direct owner/emitter.

### 2. [UID:0000P8] WeatherLayerPane Source Family / [UID:0000OD] SwallowLayerPane File
- Evidence for: source-tree and generated route keep Weather/Raining/Snowing/Swallow under the weather-layer map family; `SwallowLayerPane.cpp` remains plausible if concrete layer files are split.
- Evidence against: this is source-file placement, not direct class ownership. The body is not a base WeatherLayerPane method.
- Decision: keep direct owner [UID:0000E9] and current source-family caveat. Do not force generated route migration in this target report.

### 3. Rejected or weaker candidates
- BackPane: rejected. MCP target field accesses are Swallow-specific; BackPane helpers are dependencies or generated-label pollution.
- SnowingLayerPane: rejected. MCP proves Snowing starts at `0x005c29ec`; the only pointer hit is to that successor thunk.
- Ignored/padding: rejected. MCP disassembly shows a coherent raw helper body and `retn 4`.
- Forced live C++ method: rejected. MCP finds no incoming route to the raw helper start.

## Source Placement
- Recommended source context: direct class owner `SwallowLayerPane`; likely final source module `map/SwallowLayerPane.cpp` if concrete weather layers split; current generated family route remains under [UID:0000P8] `WeatherLayerPane`.
- Why this fits: the helper uses Swallow-only fields and resources, but current file-level docs still preserve one-file versus per-layer uncertainty.
- Rejected placements: `BackPane.cpp`, `SnowingLayerPane.cpp`, and base `WeatherLayerPane` direct method ownership.
- Remaining uncertainty: final generated file move from `WeatherLayerPane.cpp` to `SwallowLayerPane.cpp` is a broader weather-family migration decision.

## Range / Split / Padding / Reclassification Analysis
- Exact boundary facts: MCP bytes show predecessor code ending before the `0xcc` byte at `0x005c299f`; raw helper starts at `0x005c29a0`; `retn 4` at `0x005c29e9` consumes bytes through `0x005c29eb`; `sub_5C29EC` starts at `0x005c29ec`.
- Children/subranges: repair/rename existing [UID:0003YQ] to `0x005c29a0-0x005c29ec`; no new child; no padding child at `0x005c29ea-0x005c29ec`.
- Parent/container impact: [UID:0001O1] should mention corrected [UID:0003YQ] alongside [UID:0001O3]; [UID:0001O2] should keep [UID:0003YQ] as an excluded sibling, not fold it into aggregate C++.

## Negative Evidence Summary
- MCP found no incoming xrefs to `0x005c29a0`.
- MCP found no IDA function object and no decompilation for `0x005c29a0`.
- MCP found no absolute VA/RVA pointer bytes to `0x005c29a0`.
- MCP found no Swallow vtable slot pointing to `0x005c29a0`.
- MCP found the one nearby pointer route points to `0x005c29ec`, the successor Snowing thunk.
- No direct evidence proves the helper was a live retained source method, so formal C++ remains unsafe.

## IDA Rename / Type / Comment Recommendations
- Proposed source-facing name if a later IDA/source pass is authorized: `SwallowLayerPane::GetCurrentSwallowRect`.
- Parameter/type direction: `outRect`, using `RectBounds *` or the project-local rectangle type if resolved; `RECT *` remains a historical/provisional alias.
- Field comment direction: `+0x118` direction, `+0x110/+0x114` current X/Y, `+0x12c/+0x154` frame rect fields.
- IDA DB edits: not requested. This report is documentation-only and must not edit IDA DB state.

## First-Draft C++ Recommendation
- Eligible for draft C++: no.
- Recommended code: none in the formal `RECONSTRUCTION_CPP` section.
- Reason code should remain blank: MCP proves the raw body and role but also proves the current no-function/no-xref status. The source type/name and final source-file route remain unresolved.
- Exact no-code proof: `lookup_funcs 0x005c29a0` returns `Not a function`; `decompile 0x005c29a0` fails; `callees 0x005c29a0` returns `No function found`; `xrefs_to 0x005c29a0` returns zero; `find_bytes` finds no VA/RVA pointer encoding for `0x005c29a0`; nearby vtable reads show no slot to the target; the only nearby absolute pointer is `0x00631304 -> 0x005c29ec`, a Snowing thunk. Emitting C++ now would be decompiler-shaped private-helper code without proven liveness.

## Final Recommendation
- Exact changes recommended: target range/path/title to `0x005c29a0-0x005c29ec`; score `86/89`; owner/emitter/reconstructable unchanged; formal C++ blank.
- Exact parent assignments recommended: direct owner/emitter [UID:0000E9] `SwallowLayerPane`; source-family caveat through [UID:0000P8] `WeatherLayerPane`.
- Exact items left non-coded: [UID:0003YQ] remains reconstructable/empty-emitter evidence with target-specific no-code proof.
- Future work outside this assignment: final weather-family file split and any IDA/source-symbol pass that might prove liveness/name/type.

## Recommended Target Doc Changes
- Target path: rename/update to `by-memory/0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper.md`.
- Exact facts to incorporate: MCP session `0b5e057e`; health/session details; `lookup_funcs` no function at target and `sub_5C29EC` at successor; `get_bytes`/`disasm` exact range; `decompile` failure at target; modeled `sub_5C2930`/`sub_5C2500` decompile field corroboration; xrefs and pointer negatives; `0x00631304 -> 0x005c29ec` Snowing thunk data; unique body prefix; field roles; rejected owners; descriptive `GetCurrentSwallowRect`; `RectBounds`/`RECT` uncertainty; no-code proof.
- Metadata/score/owner/emitter/reconstructable/C++ changes: `COMPLETION:86`, `CONFIDENCE:89`, corrected range/path/title; keep [UID:0000E9], `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000E9`, blank emitter position, blank C++.
- Historical assumptions to preserve: old `0x005c29ea` endpoint and `0x005c29ea-0x005c29ec` padding claim are superseded by MCP bytes/disassembly.

## Recommended Support Doc Changes
- `by-class/SwallowLayerPane.md`: update [UID:0003YQ] range/link to `0x005c29a0-0x005c29ec`; add MCP-backed endpoint correction, field roles, and no-code caveat.
- `by-file/SwallowLayerPane.md`: update function/proposed-content rows and support prose; preserve source-family caveat, rejected BackPane/Snowing/base Weather ownership, and unresolved `RectBounds`/`RECT` type.
- `by-file/WeatherLayerPane.md`: update [UID:0003YQ] range/link and clarify WeatherLayerPane is the source-family/generated route, not direct method owner.
- `by-memory/0x005c2230-0x005c299f.SwallowLayerPaneCore.md`: update excluded adjacent raw helper to corrected range; preserve that it is not folded into aggregate C++.
- `by-memory/0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers.md`: update sibling range/link and shared no-xref raw-helper policy.
- `by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md`: update covered range/IDA map/padding notes to `0x005c29a0-0x005c29ec`; replace stale post-helper padding claim with MCP-backed "Snowing thunk starts at `0x005c29ec`".
- `by-project-structure/proposed-source-tree.md`: optional only; current goal says do not edit by-project-structure unless a future callback explicitly requires it.
- Generated/project-level files: do not edit manually. Let validator/project tooling update them after accepted by-* implementation.

## Score And Metadata Recommendation
- Current score/metadata: `85/87`, owner/emitter [UID:0000E9], reconstructable true, blank C++.
- Recommended score/metadata: `86/89`, owner/emitter/reconstructable unchanged, blank C++.
- Reason not higher: no live route, no function object, no source symbol, unresolved exact type, unresolved final file split, and no formal C++.
- Reason not lower: MCP now proves exact bytes, boundary, behavior, field roles, owner direction, pointer/table negatives, and successor thunk boundary.

## Open Questions With Attempted Resolution
- Is the helper live? MCP checked function status, xrefs, callee/decompile availability, byte pointer hits, and vtable values. No live route found. Remains unresolved and blocks C++.
- What is the exact source-facing type? MCP proves a 16-byte rect copy and `sub_4B78F0` offset call; it does not prove `RECT`, `RectBounds`, or another project-local type. Remains unresolved and blocks C++.
- Which source file should ultimately emit it? Swallow is the direct class owner; WeatherLayerPane remains the source-family route. Final file split remains unresolved and does not block range/owner correction.
- Can score move above `85/87`? Yes, to `86/89` after MCP-backed correction; not higher without liveness/source-shape proof.

## Exact Supervisor-Owned Coverage Text
- File/placement: `by-memory/-coverage-report.md`, in the `0x005c1bd0-0x005c2ab5` weather-layer neighborhood after the [UID:0001O3] row and before `0x005c2ab5-0x005c2ac0` padding.
- Exact insert text:

```markdown
    - [UID:0003YQ][0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper](by-memory/0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper.md) 0x005c29a0-0x005c29ec | raw helper | SwallowLayerPaneRawRectHelper : reconstructable : 86% : strong : B002 MCP-backed source-quality recheck using IDA session `0b5e057e` corrects the stale `0x005c29ea` endpoint: MCP `get_bytes`/`disasm` shows the helper's `retn 4` at `0x005c29e9` consumes bytes through `0x005c29eb` and ends exclusive at `0x005c29ec`, where modeled Snowing thunk `sub_5C29EC` starts; the body is unique, has no IDA function object, target decompilation fails, `xrefs_to 0x005c29a0` returns zero, MCP byte searches find no raw-start VA/RVA pointer hit and no stale-endpoint pointer hit, and nearby vtable data points to Snowing thunk `0x005c29ec` plus modeled Swallow methods/thunks rather than the raw helper; direct instruction evidence copies the selected Swallow frame rect at `+0x12c`/`+0x154` based on direction `+0x118`, offsets it by X/Y `+0x110/+0x114` through `0x004b78f0`, keeps direct owner/emitter [UID:0000E9][SwallowLayerPane](by-class/SwallowLayerPane.md), and keeps formal C++ blank until a live caller/pointer/source-shape route is proven.
```

- Exact replacement text for [UID:0001O1] parent coverage if supervisor syncs parent text:

```markdown
    - [UID:0001O1][0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes](by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md) 0x005c1bd0-0x005c2ab5 | migration index | SnowingAndSwallowLayerPanes : not_reconstructable : 86% : strong : B001 2026-06-16 reclassified the interleaved Snowing/Swallow weather-layer island as a non-emitting source-family migration index under [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md); exact Snowing children, Swallow core [UID:0001O2][0x005c2230-0x005c299f.SwallowLayerPaneCore](by-memory/0x005c2230-0x005c299f.SwallowLayerPaneCore.md), raw Swallow helpers [UID:0001O3][0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers](by-memory/0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers.md) and [UID:0003YQ][0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper](by-memory/0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper.md), compiler thunks, and padding rows carry the actual source/ignore state, so no aggregate final C++ should emit from this range.
```

- Exact replacement text for stale [UID:0001O2] coverage row if supervisor syncs the already-executed parent score:

```markdown
    - [UID:0001O2][0x005c2230-0x005c299f.SwallowLayerPaneCore](by-memory/0x005c2230-0x005c299f.SwallowLayerPaneCore.md) 0x005c2230-0x005c299f | source-family aggregate | SwallowLayerPaneCore : reconstructable : 88% : strong : B002 2026-06-17 source-quality reanalysis corrected the half-open end to `0x005c299f`, kept owner/emitter [UID:0000E9][SwallowLayerPane](by-class/SwallowLayerPane.md), preserved blank aggregate C++, documented modeled Swallow constructor/paint/move/timer/draw/invalidation methods, raw helper evidence, constructor caller/resource/timer/vtable facts, and leaves adjacent raw current-rect helper [UID:0003YQ][0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper](by-memory/0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper.md) as a separate no-xref child.
```

- Reason B002 must not apply it directly: all `-coverage-report.md` files remain supervisor-owned.

## Follow-Up Actions
- Supervisor actions: verify this report/checklist against the changed target/support docs; apply the supervisor-owned `by-memory/-coverage-report.md` text if accepted; validate coverage; move this report to executed; reassign B002 as needed.
- A-agent actions: none.
- B002 future actions: none for this report unless supervisor requests additional follow-up.

## Confidence
- Recommendation confidence: high for range/owner/no-code disposition after MCP confirmation.
- Score confidence: medium-high for `86/89`.
- Remaining uncertainty: live reachability, exact original helper name/type, final source file split.

## Validator Results
- Initial target validator side effects from the first implementation validation: `path_update` for [UID:0003YQ] from `by-memory/0x005c29a0-0x005c29ea.SwallowLayerPaneRawRectHelper.md` to `by-memory/0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper.md`; six `reference_source_path_update` entries for target references; `completion_update 86`; `confidence_update 89`; `uid_link_insert` entries in related docs; `reference_index_add 0002ZA`; generated/project tool side effects included `validator.ini` registry rebuild, projected stats update, `auto-generated/-ag-memory-coverage.md` update, one generated C++ update, and known unrelated stale registry notices for missing `0003E6` and `00026U`.
- Final scoped validator rerun summary:
  - `python .\tools\validator.py --mode file --file by-memory\0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-class\SwallowLayerPane.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-file\SwallowLayerPane.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-file\WeatherLayerPane.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x005c2230-0x005c299f.SwallowLayerPaneCore.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
- Final validator side effects on rerun: each command reported `autogen_registry_rebuild: 1`, `projected_stats_update: 1`, `autogen_report_noop: 7`, `autogen_cpp_noop: 270`, `stats_incremental_noop: 1`, and known unrelated stale registry notices for missing `0003E6` and `00026U`.
- Post-resume scoped validator pass after supervisor MCP session update and B002 lease reacquisition at `2026-06-23T10:16:53Z`:
  - `python .\tools\validator.py --mode file --file by-memory\0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-class\SwallowLayerPane.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-file\SwallowLayerPane.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-file\WeatherLayerPane.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x005c2230-0x005c299f.SwallowLayerPaneCore.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
- Post-resume validator side effects: each command reported `autogen_registry_rebuild: 1`, `autogen_registry_stale: 2`, `autogen_report_noop: 7`, `autogen_cpp_noop: 270`, `autogen_cpp_conflict: 5`, `projected_stats_update: 1`, `stats_incremental_noop: 1`, and no target metadata/path/link updates (`completion_update`, `confidence_update`, `path_update`, `reference_source_path_update`, `uid_link_insert`, and `reference_index_add` all `0`). The unrelated stale registry rows remain `0003E6` missing `by-memory/0x0062e960-0x0062e998.UserListDialogPaneVtableLeadInData.md` and `00026U` missing `by-memory/0x0062e960-0x0062eccc.UserListReadOnlyData.md`; unrelated generated-C++ sentinel conflicts remain `0000JH`, `0000JQ`, `0000JW`, `0000JX`, and `0000K5`.
- Unresolved validator warnings/errors: none target-specific. The stale registry notices for `0003E6` and `00026U` are unrelated existing validator registry state.

## Changed Files
- Created: none.
- Modified by B002 implementation callback:
  - `by-memory/0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper.md`
  - `by-class/SwallowLayerPane.md`
  - `by-file/SwallowLayerPane.md`
  - `by-file/WeatherLayerPane.md`
  - `by-memory/0x005c2230-0x005c299f.SwallowLayerPaneCore.md`
  - `by-memory/0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers.md`
  - `by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md`
  - `tools/leaser/Agents/Agent-B002/research/0003YQ-SwallowLayerPaneRawRectHelper-source-quality.md`
- Validator-owned side effects observed: `tools/validator.ini`, `project-level/-auto-completion-stats.md`, `auto-generated/-ag-memory-coverage.md`, and `auto-generated/NexusTK/map/WeatherLayerPane.cpp` received validator-managed updates during the first scoped validation; final rerun reported those generated/autogen outputs as no-op or projected-stats refresh.
- Renamed: target path already existed at corrected name when this callback resumed; validator registered [UID:0003YQ] path update from old `0x005c29ea` filename to `0x005c29ec`.
- Moved to executed: none.

## Implementation Tracking Checklist

Initial report-only MCP redo:
- [x] Supervisor validation required before implementation: prior acceptance was revoked; this revised MCP-backed report is ready for supervisor validation only.
- [x] Target/support docs to update: target [UID:0003YQ], `by-class/SwallowLayerPane.md`, `by-file/SwallowLayerPane.md`, `by-file/WeatherLayerPane.md`, [UID:0001O2], [UID:0001O3], [UID:0001O1], plus supervisor-owned coverage rows are listed.
- [x] Current target state and actual evidence checked recorded: current metadata, stale range, MCP session `0b5e057e`, health/session data, function lookup, bytes, disassembly, decompile status, xrefs, byte searches, vtable reads, modeled neighbor decompiles, and read-only old/new target path existence check are recorded.
- [x] Metadata/score changes to apply: recommend `85/87` to `86/89` after correcting the range.
- [x] Owner/emitter/reconstructable changes to apply: keep [UID:0000E9], `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000E9`, blank emitter position.
- [x] Split/rename/new-child changes to apply: rename/update existing [UID:0003YQ] to `0x005c29a0-0x005c29ec`; no new child; no `0x005c29ea-0x005c29ec` padding child.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable: preserve WeatherLayerPane source-family caveat; do not edit IDA DB; keep `GetCurrentSwallowRect` descriptive only and type unresolved.
- [x] First-draft C++ or no-code proof to apply: formal C++ stays blank; MCP-backed no-code proof supplied.
- [x] Exact target/support doc facts to incorporate at report-level detail: MCP bytes/disassembly, field roles, modeled neighbor field corroboration, xref/pointer/vtable negatives, source placement, rejected alternatives, score rationale, and coverage text supplied.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: stale `0x005c29ea` endpoint and padding claim superseded; BackPane/Snowing/base Weather/padding/live-C++ alternatives rejected.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable: old Wave2 source-placement provenance remains only a source-family lead.
- [x] Open questions to close or document as evidence-backed unresolved: liveness, exact type/name, and final file split documented with score/C++ impact.
- [x] Validators to run: listed during report-only redo and completed during the implementation callback; see `Validator Results`.
- [x] Supervisor-owned coverage-report/tracker text to apply: exact insert/replacement text supplied; not applied by B002.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation: supervisor acceptance/callback received for [UID:0003YQ] corrected target path `by-memory/0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper.md`.
- [x] Leases checked and taken: waited until after expired B003 lease on `by-file/WeatherLayerPane.md`; re-read `tools/leaser/Agents/current_leases.md`; no active required-doc conflict remained; B002 leases succeeded for target, `by-class/SwallowLayerPane.md`, `by-file/SwallowLayerPane.md`, `by-file/WeatherLayerPane.md`, [UID:0001O2], [UID:0001O3], and [UID:0001O1]. Cleanup note: B002 leases had expired before cleanup; `unlease` returned `Rejected[No active lease]` for each file, and a final `current_leases.md` scan found no active B002 rows.
- [x] Post-restart MCP confirmation completed under current session `b880584f`: after the supervisor restart/override, B002 used only read-only MCP requests against `http://127.0.0.1:13337/mcp`; `server_health`/`idb_list` showed active session `b880584f`, `lookup_funcs`/`get_bytes`/`disasm`/`xrefs_to`/`find_bytes` reconfirmed the accepted boundary and no-route facts, and no MCP timeout/refused/stale-session blocker occurred.
- [x] All accepted target/support doc details incorporated at report-level detail: target page replaced stale pre-MCP/fallback wording with MCP session `0b5e057e` evidence; support pages synchronized with corrected range, field roles, source-family caveat, rejected alternatives, and no-code policy.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason: target now `COMPLETION:86`, `CONFIDENCE:89`, corrected title/range/path `0x005c29a0-0x005c29ec`; `CANONICAL_OWNER:0000E9`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000E9`, blank emitter position, and blank formal C++ preserved; old `0x005c29ea` file remains absent; no padding child created.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: target/support docs preserve stale endpoint/padding assumption as superseded; reject BackPane, Snowing, base Weather direct method ownership, padding/ignored treatment, and forced live C++; preserve no-function, target decompile failure, zero xref, no raw-start pointer, no stale-endpoint pointer, no Swallow vtable slot, `0x00631304 -> 0x005c29ec` Snowing thunk data, and unique body evidence.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale: liveness, exact original helper name/type, `RectBounds` versus `RECT`, and final `WeatherLayerPane.cpp` versus `SwallowLayerPane.cpp` split remain unresolved with score/C++ impact documented.
- [x] Validators run and results recorded: all seven required scoped validators run from `source-3/project-documentation`; original final rerun and post-resume compact validator pass each returned exit `0` and `ok: 1` for every required by-* file; target first validation side effects, post-resume no-op/side-effect counts, unrelated stale registry notices, and unrelated generated-C++ sentinel conflicts are recorded above.
- [x] Supervisor-owned coverage-report/tracker text supplied or confirmed unchanged: exact `by-memory/-coverage-report.md` insert/replacement text remains in this report; B002 did not edit any `-coverage-report.md`.
- [x] Remaining unapplied accepted items listed with exact blocker: none. Only supervisor-owned coverage application/execution remains.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003YQ","source_path":"executed-b-agent-research/B002/0003YQ-SwallowLayerPaneRawRectHelper-source-quality.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
