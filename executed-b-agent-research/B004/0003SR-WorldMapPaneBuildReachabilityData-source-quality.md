** TARGET-REPORT-UID:0003SR **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

# UID0003SR WorldMapPaneBuildReachabilityData Source-Quality Report

## Finalized Report / Current Recommendation

- This is the complete research and implementation-callback artifact for [UID:0003SR] `by-memory/0x005c4bd0-0x005c5075.WorldMapPaneBuildReachabilityData.md`.
- The exact target path, half-open range `[0x005c4bd0,0x005c5075)`, name `WorldMapPaneBuildReachabilityData`, canonical owner `0000G9`, emitter `0000PB`, `RECONSTRUCTABLE:TRUE`, blank emitter position, and `Nested:0` were retained.
- The target is now `92/94` and emits one private out-of-line `void WorldMapPane::BuildReachabilityData()` definition in `NexusTK/map/WorldMapPane.cpp`.
- The body is a breadth-first traversal of a directed row-major adjacency matrix. It resets persistent reachability and predecessor arrays, starts at signed `m_currentNodeIndex`, visits every newly reachable node once, and records the first predecessor discovered.
- The descriptive `WorldMapReachabilityBitSet` and `WorldMapNodeEntryVector` class/helper pages are now non-emitting documentation facades over old MSVC/Dinkumware `std::vector<bool>` and `std::vector<WorldMapNode>` specializations. Their machine bodies remain documented as compiler/library expansion, not separately handwritten NexusTK classes.
- The exact eleven-byte `0xcc` alignment interval `[0x005c5075,0x005c5080)` is now recorded in `by-memory/-ignored.md` without changing either neighboring range.
- Implementation, scoped validators, lease release, and final generated verification are complete. B004 did not manually edit manual coverage/generated/tracker/audit/supervisor/validator/lifecycle/IDA files and performed no report execute/move/archive command; external lifecycle state remains supervisor/validator-owned.

## Supporting Research

### Mandatory live IDA MCP

- The first pre-restart worker was unavailable: database `ee0266d3` returned worker/session-unreachable results and a subsequent `idb_list` returned no usable IDB. That is historical outage evidence only; no fallback report was created from that state.
- After the supervisor restart at `2026-07-14T07:48:20-04:00`, a fresh `idb_list` returned database `1feab207` with worker PID `20008`.
- `server_health` on `1feab207` returned `status=ok` with auto-analysis, Hex-Rays, and string cache ready for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` / input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`.
- A bounded `lookup_funcs(0x005c4bd0)` returned `sub_5C4BD0`, size `0x4a5`. A bounded `get_bytes(0x005c4bd0,16)` returned the real prologue `55 8b ec 6a ff 68 e4 bf 60 00 64 a1 00 00 00 00`.
- A final evidence-time recheck returned the same healthy status, function identity, and real bytes. These statements are time-scoped evidence observations, not an assertion that an MCP worker remains indefinitely available.

### Report-search matrix

The exact search terms were `UID0003SR`, `0003SR`, `0x005c4bd0`, `0x005c4bd0-0x005c5075`, `WorldMapPaneBuildReachabilityData`, `BuildReachabilityData`, `WorldMapReachabilityBitSet`, `WorldMapNodeEntryVector`, `UID000149`, `0x004a88e0`, `UID0001B2`, `0x00514a10`, `UID0000G9`, `UID0000PB`, `vector<bool>`, `std::deque<int>`, and `WorldMapPane`.

- `tools/leaser/Agents/Agent-B001/research` through `Agent-B005/research`: no direct current UID0003SR report matched when searched.
- `source-3/project-documentation/executed-b-agent-research/B001/0001O4-worldmap-source-split-audit.md`: direct historical split report. It established the target boundary and route but left only a shallow temporary-vector/list description and blank source body. It is a lead, not current source proof.
- `source-3/project-documentation/executed-b-agent-research/B003/000149-DequePushBack-empty-emitter-source-quality.md`: relevant executed support. It identifies target queue operations as `std::deque<int>`, including the initial out-of-line append and inlined neighbor append. It intentionally did not resolve UID0003SR fields/body.
- `source-3/project-documentation/executed-b-agent-research/B006/0001B2-UInt32VectorConstructor-empty-emitter-source-quality.md`: relevant executed support. It identifies the local word-vector construction at `0x005c4df3` as the backing storage generated for `std::vector<bool>`, not a project-owned bitset class.
- `source-3/project-documentation/executed-b-agent-research/B001/000271-WorldMapReadOnlyData.md`: relevant owner/source support only; it confirms WorldMapPane vtable/resource/numeric ownership but contains no UID0003SR body claim.
- `source-3/project-documentation/executed-b-agent-research/B001/0001AW-mappane-packet-source-split-audit.md` and `source-3/project-documentation/executed-b-agent-research/B001/0001AW-mappane-packet-source-split-continuation-batch8.md`: relevant construction/input support. They establish that `MapPane` packet parsing supplies WorldMapPane's node table and packed `N*N` graph, but do not reconstruct UID0003SR.
- `source-3/project-documentation/executed-b-agent-research/B010/00041E-VectorGrowAcc2Drw-source-quality.md`: incidental missing-reference mention only; no direct target claim.
- Other executed matches for `WorldMapPane`, owner, or source-family terms were opened/classified as shared string, file-route, vtable, singleton, or sibling-method evidence; none supplied the target body.
- `tools/leaser/Agents/Older-Research/**`: no direct or relevant matching report for the search matrix.
- `tools/leaser/Agents/SpecialReports/**`: no direct or relevant matching report for the search matrix.
- `archived/**`: no direct UID0003SR report matched.
- `source/WorldMapPane.cpp`: matching stale Wave/decompiler-shaped artifact with `meth_0x5c4bd0`, raw offsets, SEH scaffolding, and helper shims. It corroborates historical address mapping only and is rejected as original/human source evidence.
- `source-2`: no original or reconstructed `WorldMapPane.cpp` target body was found.

### Documentation and generated-state comparison

- Historical pre-callback snapshot: target UID0003SR was `86/90` and blank; WorldMapPane class/file were `88/90` and `90/89`; both custom-container facades were `86/89`, reconstructable, and emitting; generated command `000000010993` had no target definition and eight Empty Emitter Markers.
- Current implemented state: target `92/94`; class `90/93`; file `91/92`; broad index remains false/non-emitting `88/91`; bitset facade `91/94` false; node-vector facade `90/94` false; all ten exact specialization helpers are false/non-emitting at the accepted scores.
- Final generated command `000000011041` at `2026-07-14T08:28:57-04:00` emits the target definition once, has no target Empty Emitter Marker, emits neither custom facade nor any of their ten helper bodies, and contains no duplicate sibling `WorldMapPane::` definition.

## Target

- UID: `0003SR`
- Historical B004 research/implementation-callback artifact path before supervisor lifecycle: `tools/leaser/Agents/Agent-B004/research/0003SR-WorldMapPaneBuildReachabilityData-source-quality.md`
- Destination: `by-memory/0x005c4bd0-0x005c5075.WorldMapPaneBuildReachabilityData.md`
- Exact range: `[0x005c4bd0,0x005c5075)` (`0x4a5`, 1189 bytes)
- Applied human identity: private nonvirtual `void WorldMapPane::BuildReachabilityData()`
- Applied source: `NexusTK/map/WorldMapPane.cpp`, declaration in `WorldMapPane.h`
- Canonical owner/emitter: `0000G9` / `0000PB`
- Applied score: `92/94`

## Current Target State

- Header state is `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:0000G9`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000PB`, blank emitter position, `Nested:0`.
- The exact formal C++ block is installed and generated once. There is no UID0003SR Empty Emitter Marker.
- Target prose now carries the exact algorithm, ABI, bytes/hash, boundaries/padding, callers/callees/xrefs, fields/types, start-versus-hover distinction, standard-container disposition, error/precondition behavior, negative evidence, and ranked source inference.
- The historical custom-container labels are now explicitly false/non-emitting documentation facades; their complete binary behavior remains preserved.

## Executive Recommendation

The accepted implementation is complete: one source-authored managed definition preserves the domain BFS, member orchestration, traversal order, route-tree semantics, and unguarded start-index precondition; lower-level vector specializations are false/non-emitting compiler support; class/file/aggregate documentation and exact ignored padding are synchronized.

## Supervisor Active Recheck

- Duplicate/ownership search at evidence time found no B001-B005 direct-target report, assignment, or lease conflict for UID0003SR.
- Existing executed reports were treated as historical/support leads and independently checked against live IDA MCP.
- B004's implementation and validators are complete. Report validation, execution, counting, movement, and archive state remain external supervisor/validator-owned facts and are not asserted by this artifact.

## Inference Research Guidance Check

- Exact facts are labeled separately from source inference.
- Exact: bytes, hash, boundaries, call graph, offsets, element stride, bit-vector layout, branch order, write order, caller count, no-xref results, and compiler helper behavior.
- Inferred but high probability: source-facing field names, method access/name, and `WorldMapNode` member names beyond the fields used by this target.
- No inferred name changes control flow, layout, ABI, or score rationale.
- The selected names are the best-supported human-source model after comparing constructor, drawing, hover, route, packet-parser, and standard-library helpers; no investigable blocker is deferred.

## Heuristic / Inference Reanalysis And Validation

1. The `thiscall` receiver and exclusive WorldMapPane constructor calls reject a file-local free helper.
2. The target combines domain graph traversal with standard-container operations. That rejects a pure template/runtime classification even though large portions inline Dinkumware code.
3. `+0x1ec` is a signed 16-bit persistent current/origin node. Constructor stores the packet parameter there; StartTravel and FindPredecessor use it as the route root. The signed extension in UID0003SR is exact.
4. `+0x1e8` is a distinct mutable hover/selection index. Hover methods update it and OnDraw consumes it. Constructor initially mirrors the same parameter into both fields, which explains the old ambiguity without making them aliases.
5. `+0x258/+0x25c/+0x260` is a `std::vector<WorldMapNode>` with exact `0x94` stride. `+0x264..+0x270` and `+0x274..+0x280` are old 16-byte MSVC `std::vector<bool>` layouts. `+0x284..+0x28c` is `std::vector<int>`.
6. The condition order is exact from the CFG: unvisited first, adjacency second, self-edge rejection third. The recommended C++ preserves that short-circuit order.
7. No bounds guard exists before initial indexing. Adding an empty-graph or invalid-start guard would alter observable failure behavior and is rejected.
8. `BuildReachabilityData` is retained because it is the established documentation/source-family name and accurately covers both reachable flags and predecessor data. `BuildReachabilityTree` is semantically precise but lacks historical corroboration.
9. The practical confidence ceiling is 94 because no PDB/original source survives. Exact behavior and source shape are resolved, but private identifier spelling remains inferential.

## Evidence Standards Used

- Healthy live IDA MCP was mandatory for function, bytes, decompile, disassembly, CFG, xref, caller, callee, and field-use evidence.
- Local PE hashing was used for immutable binary identity and exact range hashing.
- Current by-* pages and generated output were read directly; generated output was not edited.
- Historical reports and stale source artifacts were leads only, never sole proof.
- Positive evidence required converging call/data/layout behavior. Negative claims used bounded xref, pointer-byte, vtable, string, and report-root searches.
- Source inference was accepted only where one candidate best explains all observed behavior without ABI/control-flow changes.

## Evidence Checked

- IDB: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, image base `0x00400000`.
- Input PE: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`.
- PE MD5: `4247E04E20B65D6414C7238AA8FF5515`.
- PE SHA256: `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`.
- Target bytes SHA256: `F81D6B47E10FA69AD9564853818B59ED501F876CD8438CEC899B95198B9DB365`.
- Target head: `55 8b ec 6a ff 68 e4 bf 60 00 64 a1 00 00 00 00 50 83 ec 4c 53 56 57 a1 24 2f 67 00 33 c5 50 8d`.
- Target tail: `00 59 5f 5e 5b 8b e5 5d c3 e8 9d c4 e5 ff e8 98 c4 e5 ff 8d 4d bc e8 40 08 00 00 e8 92 85 00 00`.
- Directly opened current destinations: target, `by-class/WorldMapPane.md`, `by-file/WorldMapPane.md`, `by-class/WorldMapReachabilityBitSet.md`, `by-class/WorldMapNodeEntryVector.md`, broad UID0001O4, all ten exact vector-specialization helper pages, UID0003T6, `by-memory/-ignored.md`, and relevant sibling pages.
- Directly opened manual rows: `by-memory/-coverage-report.md` UID0001O4 region, `by-class/-coverage-report.md` UID0000G8/G9/GA rows, and `by-file/-coverage-report.md` UID0000PB row.
- Directly opened prior reports: the exact paths classified under Supporting Research. No direct matches existed in Older-Research, SpecialReports, or archived roots.

## Claim And Incorporation Ledger

| ID | Claim | Action | Destination | Verification state | Evidence / callback proof required |
|---|---|---|---|---|---|
| C01 | Pin healthy IDB/PE identity and hashes. | incorporate | UID0003SR | applied | Target records evidence-time MCP session, PE MD5/SHA256, target SHA256, and head/tail bytes. |
| C02 | Preserve exact `[0x005c4bd0,0x005c5075)` 1189-byte target. | incorporate | UID0003SR | applied | Range/hash/boundary text applied; validators `11020` and `11041` returned exit 0/ok 1. |
| C03 | Add `[0x005c5075,0x005c5080)` eleven-byte `0xcc` padding. | incorporate | `by-memory/-ignored.md` | applied | Exact ignored entry added; validator `11037` exit 0/ok 1; neighbor ranges unchanged. |
| C04 | Classify ABI as private nonvirtual `void __thiscall WorldMapPane`. | incorporate | UID0003SR, UID0000G9 | applied | Target Status/ABI and class BuildReachabilityData contract applied. |
| C05 | Record the two constructor call sites and sole-caller fact. | incorporate | UID0003SR | applied | Target records `0x005c2f63`/`0x005c3231`; UID0003SC stayed read-only. |
| C06 | Record no direct pointer, end-pointer, data, vtable, or string refs. | incorporate | UID0003SR | applied | Bounded negative inventory applied under caller/xref and error/negative sections. |
| C07 | Derive `nodeCount` from `m_nodes.size()` with stride `0x94`. | incorporate | UID0003SR, UID0000G9 | applied | Exact typed expression in formal body and 0x94 field/record evidence in both docs. |
| C08 | Resolve `+0x258..+0x260` as `std::vector<WorldMapNode> m_nodes`. | incorporate | UID0000G9, UID0000G8 | applied | Class field contract and false node-vector facade preserve constructor/assign/stride proof. |
| C09 | Resolve `+0x264..+0x270` as flattened `std::vector<bool> m_adjacency`. | incorporate | UID0000G9, UID0000GA | applied | Class/facade record packet `N*N` row-major directed storage and source type. |
| C10 | Resolve `+0x274..+0x280` as `std::vector<bool> m_reachableNodes`. | incorporate | UID0000G9, UID0000GA | applied | Class/facade/target record resets, writes, hover/draw reads, and 16-byte layout. |
| C11 | Resolve `+0x284..+0x28c` as `std::vector<int> m_predecessors`. | incorporate | UID0000G9 | applied | Class and target record `-1` initialization, first parents, and route readers. |
| C12 | Resolve signed `short +0x1ec` as `m_currentNodeIndex`. | incorporate | UID0003SR, UID0000G9 | applied | Typed field and sign-extended target/route evidence applied. |
| C13 | Separate mutable `int +0x1e8` hover/selection from route origin. | incorporate | UID0000G9 | applied | Class and target distinguish constructor mirror from hover writers/OnDraw reader. |
| C14 | Preserve `m_reachableNodes.assign(nodeCount,false)`. | incorporate | UID0003SR | applied | Exact formal call applied; helper pages retain erase/insert expansion evidence. |
| C15 | Preserve `m_predecessors.assign(nodeCount,-1)`. | incorporate | UID0003SR | applied | Exact formal call and vector capacity/fill evidence applied. |
| C16 | Preserve local `std::vector<bool> visitedNodes(nodeCount,false)`. | incorporate | UID0003SR | applied | Exact formal declaration and underlying word-vector/mask evidence applied. |
| C17 | Preserve local `std::deque<int> pendingNodes`. | incorporate | UID0003SR | applied | Exact formal declaration plus append/grow/front/pop/destructor evidence applied. |
| C18 | Enqueue and mark the signed start node in both bitsets. | incorporate | UID0003SR | applied | Exact three-statement order is in formal body and algorithm inventory. |
| C19 | Preserve queue-nonempty BFS outer loop. | incorporate | UID0003SR | applied | Exact `while (!pendingNodes.empty())` body emitted once. |
| C20 | Scan every candidate `0..nodeCount-1` for each dequeued node. | incorporate | UID0003SR | applied | Exact for-loop bound and row-major index emitted. |
| C21 | Preserve condition order: unvisited, adjacent, then non-self. | incorporate | UID0003SR | applied | Managed block preserves the three short-circuit operands in binary order. |
| C22 | Mark, store first predecessor, and enqueue each discovery. | incorporate | UID0003SR | applied | Managed block preserves visited/reachable/predecessor/enqueue side-effect order. |
| C23 | Pop only after the entire adjacency row is scanned. | incorporate | UID0003SR | applied | `pop_front()` remains after the for-loop; generated readback confirms it. |
| C24 | Preserve absence of empty/count/start bounds guards. | incorporate | UID0003SR | applied | Formal body contains no clamp/check/early return; precondition evidence retained. |
| C25 | Historicalize compiler EH/cleanup/error tails as source-container operations. | historicalize | UID0003SR | applied | Exact error/callee evidence retained; no SEH/cookie/allocator scaffolding emitted. |
| C26 | Document directed row-major graph and first-predecessor shortest-edge tree. | incorporate | UID0003SR, UID0000G9 | applied | Target/class include directed, no-symmetry, first-discovery, no-distance/no-early-stop facts. |
| C27 | Retain `BuildReachabilityData`, private access, void/no-arg signature. | incorporate | UID0003SR, UID0000G9 | applied | Name/signature/access/source placement and ranked alternatives retained. |
| C28 | Retain owner `0000G9`, emitter `0000PB`, and WorldMapPane route. | already-present | UID0003SR | already-present | Header preserved; validator/generated source both route through UID0000PB. |
| C29 | Retain `Nested:0`, blank position, no split/merge/rename. | already-present | UID0003SR | already-present | Header/path/range unchanged; relative nesting and eleven-byte padding documented separately. |
| C30 | Insert the one exact managed C++ definition. | incorporate | UID0003SR | applied | Validator `11041` generated exactly one definition and zero target empty markers. |
| C31 | Raise target `86/90 -> 92/94`. | incorporate | UID0003SR | applied | Header, score rationale, validator `11020`, and generated metadata all show `92/94`. |
| C32 | Reclassify UID0000GA as non-emitting `std::vector<bool>` documentation facade. | reject-stale | UID0000GA | applied | `91/94`, false, blank emitter/formal; validator `11024` exit 0/ok 1. |
| C33 | Reclassify UID0003SX/T0/T1/T4/T5/T9/TA as generated STL support. | reject-stale | seven bitset helper pages | applied | Accepted scores, false/blank states, exact behavior, and source disposition validated by `11026-11032`. |
| C34 | Reclassify UID0000G8 as non-emitting `std::vector<WorldMapNode>` documentation facade. | reject-stale | UID0000G8 | applied | `90/94`, false, blank emitter/formal; validator `11025` exit 0/ok 1. |
| C35 | Reclassify UID0003SZ/T7/T8 as generated STL support. | reject-stale | three node-vector helper pages | applied | Accepted scores, false/blank states, exact behavior validated by `11033`, `11034`, `11036`. |
| C36 | Synchronize WorldMapPane class/file fields, algorithm, route, and scores. | incorporate | UID0000G9, UID0000PB | applied | Class `90/93`, file `91/92`, blank class formal and `NexusTK/map/` route validated. |
| C37 | Synchronize broad UID0001O4 split index without making it emit. | incorporate | UID0001O4 | applied | Preserved `88/91`, false/blank; target/helper/current-MCP text synchronized by `11023`. |
| C38 | Keep sibling methods, UID000149, UID0001B2, and UID0003T6 read-only. | already-present | listed support pages | already-present | No direct edits; only validator-managed reference/index effects occurred. |
| C39 | Classify all prior reports and stale Wave source as historical/support evidence. | historicalize | report and target prose | applied | Full search matrix retained; class/file/aggregate current prose rejects stale artifacts as source proof. |
| C40 | Supply exact manual coverage replacement/addition text without editing coverage. | incorporate | supervisor-owned coverage rows | applied | Exact text remains under the required heading; no manual coverage file was edited. |

## Positive Evidence Summary

- Exact body and function boundaries are live-IDB and byte/hash confirmed.
- Constructor initializes all implicated containers and calls UID0003SR twice after alternate resource branches, so both calls operate on complete graph state.
- StartTravel and FindPredecessor independently consume `m_predecessors` and signed `m_currentNodeIndex` exactly as a BFS route tree requires.
- Hover and OnDraw independently consume `m_reachableNodes`, proving that the persistent bitset is not merely a local visited set.
- Packet parsing supplies `N*N` packed adjacency bits, and target indexes `current*nodeCount+candidate`, proving row-major graph storage.
- Dinkumware helper identities converge with the observed 16-byte `vector<bool>`, 12-byte `vector<int>`, and deque layouts.
- The algorithm has one domain source body and compiler-expanded container internals; this explains every basic block and callee without inventing project containers.

## IDA MCP Facts

- Function: `sub_5C4BD0`, `0x4a5` bytes, 398 instructions, 66 basic blocks.
- Prototype shape: `void __thiscall(_DWORD *this)`; no return value or explicit source parameter.
- Caller count: one function (`sub_5C2AC0`, WorldMapPane constructor/setup), with calls at `0x005c2f63` and `0x005c3231`.
- Callee count: 19 modeled targets including operator new, vector/deque helpers, invalid-parameter support, security cookie, and `__CxxFrameHandler3`.
- Strings: zero.
- Vtable refs: zero.
- Code xrefs to target end: zero.
- Raw VA/RVA scans found no `0x005c4bd0` or `0x005c5075` embedded pointer values.
- The target's successful return path ends before error tails at `0x005c505e`, `0x005c5063`, `0x005c506b`, and `0x005c5070`.

## Function / Child Inventory

### Target block phases

| Range | Exact role |
|---|---|
| `0x005c4bd0-0x005c4c40` | Prologue, security/SEH state, local deque initialization. |
| `0x005c4c4d-0x005c4c7e` | Compute node count from `m_nodes` begin/end divided by `0x94`. |
| `0x005c4c53-0x005c4cd5` | Reset persistent reachable `vector<bool>` to `nodeCount` false bits. |
| `0x005c4cda-0x005c4dd4` | Assign `nodeCount` copies of `-1` to predecessor `vector<int>`. |
| `0x005c4ddd-0x005c4e3d` | Construct local visited `vector<bool>`. |
| `0x005c4e4b-0x005c4e94` | Enqueue and mark signed current/origin node. |
| `0x005c4e96-0x005c500b` | Outer deque BFS and complete candidate scan. |
| `0x005c5011-0x005c5047` | Destroy local bit-vector words and deque storage. |
| `0x005c505e-0x005c5070` | Vector length/too-long/invalid-parameter error tails. |
| `0x005c5075-0x005c5080` | Eleven `0xcc` alignment bytes outside target. |

### Exact field inventory

| Offset | Type / highest-probability name | Evidence and target use |
|---|---|---|
| `+0x1e8` | `int m_hoveredNodeIndex` | Hover helpers write it; OnDraw reads it. Constructor initially mirrors packet node value. Not the BFS root field. |
| `+0x1ec` | `short m_currentNodeIndex` | Constructor word store; signed reads by UID0003SR, StartTravel, and FindPredecessor. |
| `+0x238` | `int` travel target index | Route context only; not read by UID0003SR. |
| `+0x258..+0x260` | `std::vector<WorldMapNode> m_nodes` | Exact `0x94` stride; target uses size. |
| `+0x264..+0x270` | `std::vector<bool> m_adjacency` | Flattened `N*N` row-major directed adjacency matrix. |
| `+0x274..+0x280` | `std::vector<bool> m_reachableNodes` | Target resets/sets; hover/draw paths read. |
| `+0x284..+0x28c` | `std::vector<int> m_predecessors` | Target fills `-1`/parent indexes; route paths read. |
| `+0x290` | unrelated byte state | Adjacent but unused by UID0003SR. |

`WorldMapNode` is exactly `0x94` bytes: coordinates at `+0x00/+0x04`, `wchar_t name[64]` at `+0x08`, a 16-bit travel field at `+0x88`, natural padding at `+0x8a`, and 32-bit travel payload fields at `+0x8c/+0x90`. UID0003SR depends only on record stride/count, so uncertain payload spelling does not block its source.

### Direct callee inventory and source disposition

| Callee | Disposition in target source |
|---|---|
| operator new `0x005c74f6` | Container allocation expansion; no explicit source call. |
| `0x005c5b20` | Old `vector<bool>` erase/move range inside `assign`. |
| `0x005c56a0` | Old `vector<bool>` insert false bits inside `assign`. |
| `0x00423e00`, `0x00421520`, `0x004a7c30`, `0x00514a10` | Standard vector allocation/fill/copy support. |
| `0x004a88e0` | `std::deque<int>::push_back` for initial enqueue. |
| `0x0043e0b0` | Dinkumware deque `_Growmap`, reached by inlined neighbor enqueue. |
| `0x00439e00`, cleanup thunk `0x00439f50` | Local deque destruction/cleanup. |
| `0x00423810` | Local word-vector cleanup. |
| `0x005c58b0` | Existing non-emitting `vector<bool> too long` throw helper UID0003T6. |
| invalid-parameter support | Library contract failure tail. |
| security cookie / `__CxxFrameHandler3` | Compiler ABI; no source statement. |

No helper body inside `[0x005c4bd0,0x005c5075)` warrants a child split. The compiler-expanded branches remain part of one source method.

## Direct Xref / Caller Inventory

- `sub_5C2AC0` is the only modeled caller.
- Call `0x005c2f63`: constructor/setup branch after graph/node/container initialization.
- Call `0x005c3231`: alternate graphics/resource branch after the same required state is initialized.
- No ordinary sibling method calls UID0003SR directly.
- No indirect/vtable call slot targets UID0003SR.
- No data pointer, immediate pointer, VA, RVA, or end-address pointer was found.
- Constructor-only reachability and no vtable slot support a private nonvirtual member called during initialization, not dead code.

## Documentation Evidence And IDA Status

- Current documentation correctly associates the target with WorldMapPane but freezes the research at container-shaped pseudocode and unresolved names.
- Live MCP reanalysis closes those blockers and independently confirms the useful parts of the prior split/deque/vector reports.
- The old custom-container labels are historical reverse-engineering abstractions. They remain useful navigation buckets but should not emit source.
- IDA session `1feab207` was healthy when all final evidence and bounded rechecks were collected. Future availability is not asserted.

## Ranked Ownership Analysis

### 1. Private `WorldMapPane` out-of-line method - selected

- Exact `thiscall` member access, constructor-only call sites, persistent WorldMapPane fields, and source route all converge.
- One source definition naturally expands into the observed STL-heavy body.

### 2. File-local WorldMap helper - rejected

- Would require an explicit receiver parameter absent from the ABI and does not explain established class-private naming/ownership.

### 3. Compiler/template body - rejected for the target, accepted for lower helpers

- STL operations explain most low-level branches, but the BFS graph policy and WorldMapPane member orchestration are domain-authored source.

### 4. Inlined clone - rejected

- The body has one stable out-of-line address and two calls; it is not duplicated at call sites.

### 5. Dead retained helper - rejected

- Two live constructor calls reach it after graph initialization.

## Source Placement

- Definition: `NexusTK/map/WorldMapPane.cpp` under emitter UID0000PB.
- Declaration: private section of `WorldMapPane` in `WorldMapPane.h`.
- No standalone `WorldMapReachabilityBitSet` or `WorldMapNodeEntryVector` source/header is recommended; those names remain documentation labels for standard-template specialization evidence.
- The target should not be emitted in `MapPane.cpp`: MapPane parses/owns the input protocol, while WorldMapPane owns and consumes the graph.

## Range / Split / Padding / Reclassification Analysis

- Predecessor UID0003SQ `WorldMapPaneDrawPlayerMarker` is `[0x005c48b0,0x005c4bd0)` and ends exactly at the target start.
- UID0003SR is exactly `[0x005c4bd0,0x005c5075)`. Its target SHA256 is pinned above.
- `[0x005c5075,0x005c5080)` is exactly eleven `0xcc` bytes and has no function/xref identity. It belongs in the ignored padding ledger.
- Successor UID0003SS starts exactly at `0x005c5080`, size `0x66`.
- No internal source split is justified. EH cleanup/error tails are compiler expansion of local standard containers.
- `Nested:0` is the correct relative delta from the previous address-sorted row; all surrounding exact WorldMapPane sibling methods are also level zero. It is not a child count.
- Blank emitter position remains correct because the file has one source body with no special ordering contract.

## Negative Evidence Summary

- No symbols/PDB/original source reveal exact private identifier spelling.
- No string literals occur in the target.
- No vtable slot or RTTI path references the target.
- No pointer/immediate/data references to target start or end were found.
- No third ordinary caller, callback registration, or retained dead-code path was found.
- No graph symmetry assertion exists; directed behavior must be preserved.
- No empty-node, negative-start, upper-bound, or self-start guard exists before initial indexing.
- No distance vector, destination argument, early goal stop, weighted edge, or recursive traversal exists.
- No evidence supports handwritten custom bitset/node-vector source classes.
- No direct prior report or original source artifact supplies a competing source body.

## IDA Rename / Type / Comment Recommendations

- Rename `sub_5C4BD0` to `WorldMapPane__BuildReachabilityData` only in a separately authorized IDA-edit workflow; this report did not mutate IDA.
- Apply prototype `void __thiscall WorldMapPane::BuildReachabilityData(WorldMapPane *this)` in IDA notation.
- Type fields as listed in the exact field inventory, including signed 16-bit `m_currentNodeIndex`.
- Comment `+0x1e8` as hover/selection state, not the BFS origin.
- Comment adjacency indexing as `m_adjacency[currentNode * nodeCount + nodeIndex]` and the predecessor vector as first-discovery BFS parents.
- Comment `[0x005c5075,0x005c5080)` as alignment padding outside the function.

## First-Draft C++ Recommendation

Destination: [UID:0003SR] `by-memory/0x005c4bd0-0x005c5075.WorldMapPaneBuildReachabilityData.md`.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include <deque>
#include <vector>

void WorldMapPane::BuildReachabilityData()
{
    const int nodeCount = static_cast<int>(m_nodes.size());

    m_reachableNodes.assign(nodeCount, false);
    m_predecessors.assign(nodeCount, -1);

    std::vector<bool> visitedNodes(nodeCount, false);
    std::deque<int> pendingNodes;

    pendingNodes.push_back(m_currentNodeIndex);
    visitedNodes[m_currentNodeIndex] = true;
    m_reachableNodes[m_currentNodeIndex] = true;

    while (!pendingNodes.empty())
    {
        const int currentNode = pendingNodes.front();

        for (int nodeIndex = 0; nodeIndex < nodeCount; ++nodeIndex)
        {
            if (!visitedNodes[nodeIndex] &&
                m_adjacency[currentNode * nodeCount + nodeIndex] &&
                currentNode != nodeIndex)
            {
                visitedNodes[nodeIndex] = true;
                m_reachableNodes[nodeIndex] = true;
                m_predecessors[nodeIndex] = currentNode;
                pendingNodes.push_back(nodeIndex);
            }
        }

        pendingNodes.pop_front();
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

This is the only new emitting formal block. It intentionally has no guard, explicit EH, raw offsets, allocator calls, deque map manipulation, or bit-word arithmetic. Existing managed blocks on the reclassified STL documentation pages remain blank.

## Final Recommendation

C01-C40 are applied as one bounded callback. UID0003SR is the sole emitted source definition for this behavior. Standard-container facade/helper pages are false/non-emitting while retaining exact binary documentation. WorldMapPane class/file/aggregate pages carry the resolved field and algorithm contract without unrelated C++ inflation, and the ignored ledger carries exact alignment coverage. No implementation item remains.

## Recommended Target Doc Changes

1. Applied `COMPLETION:86 -> 92` and `CONFIDENCE:90 -> 94`.
2. Preserved UID, path, range, owner `0000G9`, emitter `0000PB`, reconstructable true, blank position, and `Nested:0`.
3. Applied the accepted Item Summary exactly.
4. Inserted the exact managed definition above; generated command `11041` emits it once.
5. Added exact hashes, ABI, phase/block inventory, callers/callees, field layout, BFS ordering, no-guard behavior, cleanup/error disposition, negative evidence, ranked names, and source placement without compression.

## Recommended Support Doc Changes

- Applied UID0000G9 `88/90 -> 90/93`, retaining owner/emitter/reconstructable state and blank formal class block while adding the complete typed reachability contract.
- Applied UID0000PB `90/89 -> 91/92`, retaining `NexusTK/map/` and replacing custom-helper source claims with standard-container specialization disposition.
- Synchronized UID0001O4 at unchanged `88/91`, false/non-emitting with blank formal state and current split/helper evidence.
- Applied UID0000GA `86/89 -> 91/94`, false, blank emitter/formal, owner `0000PB`, as a `std::vector<bool>` documentation facade.
- Applied UID0003SX `90/94`, T0 `90/94`, T1 `90/94`, T4 `91/94`, T5 `90/94`, T9 `90/94`, TA `91/94`; each is false/blank, `Nested:0`, exact-range/evidence preserving, owner UID0000GA.
- Applied UID0000G8 `86/89 -> 90/94`, false, blank emitter/formal, owner `0000PB`, as a `std::vector<WorldMapNode>` documentation facade.
- Applied UID0003SZ `90/94`, T7 `91/94`, T8 `90/94`; each is false/blank, `Nested:0`, exact-range/evidence preserving, owner UID0000G8.
- Added exact `[0x005c5075,0x005c5080)` WorldMapPane reachability-to-hover alignment to `by-memory/-ignored.md`.
- Verified UID0003T6, UID000149, UID0001B2, UID0003SC, siblings, read-only-data/vtable/global pages, and unrelated scores/formal blocks remained outside direct edit scope.

## Score And Metadata Recommendation

| Destination | Pre-callback | Applied | Metadata disposition |
|---|---:|---:|---|
| UID0003SR target | 86/90 | 92/94 | true; owner 0000G9; emitter 0000PB; blank position; Nested 0 |
| UID0000G9 WorldMapPane | 88/90 | 90/93 | true; emitter 0000PB; formal class block unchanged blank |
| UID0000PB WorldMapPane file | 90/89 | 91/92 | true source route; unrelated content preserved |
| UID0001O4 broad executable index | 88/91 | 88/91 | false/non-emitting; prose/index sync only |
| UID0000GA bitset facade | 86/89 | 91/94 | false; blank emitter/formal; owner 0000PB |
| UID0000G8 node-vector facade | 86/89 | 90/94 | false; blank emitter/formal; owner 0000PB |
| UID0003SX/T0/T1/T5/T9 | 85-86/89-90 | 90/94 | false; blank emitter/formal; exact owner retained |
| UID0003T4/TA | 86/90 | 91/94 | false; blank emitter/formal; exact owner retained |
| UID0003SZ/T8 | 85-86/90 | 90/94 | false; blank emitter/formal; exact owner retained |
| UID0003T7 | 86/90 | 91/94 | false; blank emitter/formal; exact owner retained |

The applied improvement is justified by exact body/hash/boundary, full CFG/side-effect closure, caller and container typing, source shape, formal source, and negative evidence. Confidence stops at 94 because private names cannot be proven from original symbols/source.

## Open Questions With Attempted Resolution

- **Original method spelling:** no PDB/source symbol exists. `BuildReachabilityData` wins over `BuildReachabilityTree`, `CalculateReachableNodes`, and `BuildRouteTable` because it is historically established and covers both persistent outputs. Resolved by ranked inference.
- **Start field:** constructor initially duplicates one value at `+0x1e8/+0x1ec`; cross-function writes/reads prove distinct hover and signed current/origin roles. Resolved.
- **Container identity:** old documents called two private custom classes. Layout and standard helper calls prove `std::vector<bool>` and `std::vector<WorldMapNode>`. Resolved.
- **Graph directionality:** no symmetry enforcement exists; retain directed semantics. Resolved conservatively from exact behavior.
- **Empty graph handling:** no guard exists. Constructor/input invariants are the source precondition; adding a guard is rejected. Resolved.
- **Node payload names:** fields beyond stride are not used by this target. Their exact source spelling remains outside target scope and does not block this implementation.
- **Internal split:** all internal helper-shaped code is inlined/library expansion and one source method accounts for it. No child split. Resolved.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

B004 inspected each affected manual coverage row and did not edit any coverage file. The following is exact proposed supervisor-owned text.

### `by-memory/-coverage-report.md`

Replace the current UID0001O4 row with:

```text
    - [UID:0001O4][0x005c2ac0-0x005c5c87.WorldMapPane](by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md) 0x005c2ac0-0x005c5c87 | class aggregate | WorldMapPane : ignored : 88% : very strong : Non-emitting WorldMapPane executable split index over exact source-bearing methods and compiler/runtime children; live IDA resolves UID0003SR as the out-of-line breadth-first reachability-tree builder and resolves the former node-vector/bitset helper labels as generated old-MSVC std::vector<WorldMapNode>/std::vector<bool> specialization support owned semantically by WorldMapPane.cpp.
```

Add these address-sorted child/padding rows under UID0001O4:

```text
        - [UID:0003SR][0x005c4bd0-0x005c5075.WorldMapPaneBuildReachabilityData](by-memory/0x005c4bd0-0x005c5075.WorldMapPaneBuildReachabilityData.md) 0x005c4bd0-0x005c5075 | private class method | WorldMapPane::BuildReachabilityData : reconstructable : 92% : very strong : Exact out-of-line BFS over a directed row-major std::vector<bool> adjacency matrix; resets persistent reachable/predecessor vectors, starts at signed current-node state, records first-discovery parents, preserves unguarded constructor preconditions, and emits through WorldMapPane.cpp.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005c5075-0x005c5080 | padding | WorldMapPane reachability-to-hover alignment : ignored : 100% : very strong : Eleven exact 0xcc bytes between UID0003SR and the 0x005c5080 hover-update successor.
        - [UID:0003SX][0x005c53d0-0x005c54f3.WorldMapReachabilityBitSetReserveBits](by-memory/0x005c53d0-0x005c54f3.WorldMapReachabilityBitSetReserveBits.md) 0x005c53d0-0x005c54f3 | compiler/STL support | std::vector<bool> reserve/grow specialization : ignored : 90% : very strong : Old MSVC/Dinkumware std::vector<bool> specialization body; preserve exact binary documentation and regenerate from standard-container source/toolchain rather than handwritten NexusTK C++.
        - [UID:0003SZ][0x005c5510-0x005c557a.WorldMapNodeEntryVectorDestructor](by-memory/0x005c5510-0x005c557a.WorldMapNodeEntryVectorDestructor.md) 0x005c5510-0x005c557a | compiler/STL support | std::vector<WorldMapNode> destructor specialization : ignored : 90% : very strong : Old MSVC/Dinkumware vector specialization cleanup; non-emitting compiler/library support with exact 0x94-byte element evidence retained.
        - [UID:0003T0][0x005c5580-0x005c55d7.WorldMapReachabilityBitSetPositionHelper](by-memory/0x005c5580-0x005c55d7.WorldMapReachabilityBitSetPositionHelper.md) 0x005c5580-0x005c55d7 | compiler/STL support | std::vector<bool> iterator-position helper : ignored : 90% : very strong : Old MSVC/Dinkumware std::vector<bool> specialization body, regenerated by the standard container/toolchain.
        - [UID:0003T1][0x005c55e0-0x005c563c.WorldMapReachabilityBitSetResolveIterator](by-memory/0x005c55e0-0x005c563c.WorldMapReachabilityBitSetResolveIterator.md) 0x005c55e0-0x005c563c | compiler/STL support | std::vector<bool> iterator resolver : ignored : 90% : very strong : Old MSVC/Dinkumware std::vector<bool> specialization body, regenerated by the standard container/toolchain.
        - [UID:0003T4][0x005c56a0-0x005c584b.WorldMapReachabilityBitSetInsertBits](by-memory/0x005c56a0-0x005c584b.WorldMapReachabilityBitSetInsertBits.md) 0x005c56a0-0x005c584b | compiler/STL support | std::vector<bool> insert specialization : ignored : 91% : very strong : Exact generated insert/growth/shift specialization reached by source-level vector<bool>::assign; no standalone NexusTK body.
        - [UID:0003T5][0x005c5850-0x005c58a9.WorldMapReachabilityBitSetShrinkToBitCount](by-memory/0x005c5850-0x005c58a9.WorldMapReachabilityBitSetShrinkToBitCount.md) 0x005c5850-0x005c58a9 | compiler/STL support | std::vector<bool> shrink specialization : ignored : 90% : very strong : Old MSVC/Dinkumware std::vector<bool> specialization body, regenerated by standard-container source/toolchain.
        - [UID:0003T6][0x005c58b0-0x005c58ba.VectorBoolTooLongThrowHelper_5C58B0](by-memory/0x005c58b0-0x005c58ba.VectorBoolTooLongThrowHelper_5C58B0.md) 0x005c58b0-0x005c58ba | compiler/STL support | vector<bool> too-long throw helper : ignored : 86% : strong : Existing non-emitting MSVC STL diagnostic helper; verify-only and unchanged by UID0003SR.
        - [UID:0003T7][0x005c58c0-0x005c5a8f.WorldMapNodeEntryVectorAssign](by-memory/0x005c58c0-0x005c5a8f.WorldMapNodeEntryVectorAssign.md) 0x005c58c0-0x005c5a8f | compiler/STL support | std::vector<WorldMapNode> assign specialization : ignored : 91% : very strong : Old MSVC/Dinkumware vector assign/grow body for 0x94-byte records; non-emitting compiler/library support.
        - [UID:0003T8][0x005c5a90-0x005c5aca.WorldMapNodeEntryVectorFreeAllocation](by-memory/0x005c5a90-0x005c5aca.WorldMapNodeEntryVectorFreeAllocation.md) 0x005c5a90-0x005c5aca | compiler/STL support | std::vector<WorldMapNode> allocation free helper : ignored : 90% : very strong : Old MSVC/Dinkumware vector allocation cleanup; no standalone NexusTK source body.
        - [UID:0003T9][0x005c5ad0-0x005c5b18.WorldMapReachabilityBitSetEndIterator](by-memory/0x005c5ad0-0x005c5b18.WorldMapReachabilityBitSetEndIterator.md) 0x005c5ad0-0x005c5b18 | compiler/STL support | std::vector<bool> end iterator helper : ignored : 90% : very strong : Old MSVC/Dinkumware std::vector<bool> specialization body, regenerated by the standard container/toolchain.
        - [UID:0003TA][0x005c5b20-0x005c5c87.WorldMapReachabilityBitSetMoveBitRange](by-memory/0x005c5b20-0x005c5c87.WorldMapReachabilityBitSetMoveBitRange.md) 0x005c5b20-0x005c5c87 | compiler/STL support | std::vector<bool> erase/move specialization : ignored : 91% : very strong : Exact generated range-move/erase specialization reached by source-level vector<bool>::assign; no standalone NexusTK body.
```

### `by-class/-coverage-report.md`

Replace the three current rows with:

```text
- [UID:0000G8][WorldMapNodeEntryVector](by-class/WorldMapNodeEntryVector.md) : ignored : 90% : very strong : Non-emitting documentation facade for the old MSVC/Dinkumware std::vector<WorldMapNode> specialization used by WorldMapPane; exact 0x94-byte records and helper behavior remain documented, while ordinary source uses std::vector and the toolchain regenerates helper bodies.
- [UID:0000G9][WorldMapPane](by-class/WorldMapPane.md) : reconstructable : 90% : very strong : WorldMapPane class contract with exact lifecycle/render/input/travel children plus a behavior-complete UID0003SR private BFS body, typed nodes/adjacency/reachable/predecessor containers, signed current-node versus hover-state separation, source route, and compiler-STL helper disposition.
- [UID:0000GA][WorldMapReachabilityBitSet](by-class/WorldMapReachabilityBitSet.md) : ignored : 91% : very strong : Non-emitting documentation facade for old MSVC/Dinkumware std::vector<bool> specialization behavior used by WorldMapPane adjacency/reachability/local-visited storage; exact helper ranges remain documented and regenerate from standard-container source/toolchain.
```

### `by-file/-coverage-report.md`

Replace the UID0000PB row with:

```text
- [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md) : reconstructable : 91% : very strong : NexusTK/map/WorldMapPane.cpp source module with one behavior-complete UID0003SR breadth-first reachability-tree definition, typed WorldMapPane graph/route fields, exact owner/emitter links, and old-MSVC vector/deque specialization bodies correctly classified as non-emitting compiler/library support.
```

No tracker edit is proposed; validator-generated tracker state is external and should follow validated ordinary-page state.

## Follow-Up Actions

- No implementation follow-up remains: C01-C40, all bounded ordinary destinations, scoped validators, lease releases, and waited generated readback are complete.
- Generated command `000000011041` proves exactly one UID0003SR `BuildReachabilityData` definition, no UID0003SR Empty Emitter Marker, no emitted UID0000G8/UID0000GA/helper body, and no duplicate sibling C++.
- Manual coverage replacement/addition text remains available above for external supervisor ownership; B004 did not edit those files.
- B004 performed no report execution, probe, move, or archive action. Report validation, execution, count, path movement, and archive state are external supervisor/validator-owned and neither asserted nor directed by this artifact.

## Confidence

- Binary identity, range, ABI, algorithm, branches, side effects, callers/callees, fields, standard-container disposition, and no-split decision: very strong.
- Source file/class/access/signature: very strong.
- Exact private method and field spelling: strong/high-probability inference, bounded by absent symbols/original source.
- Overall applied target confidence: `94`.

## Validator Results

All commands ran from `source-3/project-documentation` as `python .\tools\validator.py --mode file --file <path> --apply --queue-timeout 240`; final command `11041` also used `--wait-generated`. Every command exited `0` with `ok:1`.

| Command | Timestamp | Path | Result | Warnings / validator-managed side effects |
|---|---|---|---|---|
| `000000011020` | `2026-07-14T08:19:19-04:00` | UID0003SR | exit 0; ok 1 | 6 `missing_ref_uid`; target score/body registry updated; generated deferred. |
| `000000011021` | `2026-07-14T08:19:58-04:00` | UID0000G9 | exit 0; ok 1 | 10 `missing_ref_uid`; score/projected stats updated; generated deferred. |
| `000000011022` | `2026-07-14T08:20:47-04:00` | UID0000PB | exit 0; ok 1 | 23 `missing_ref_uid`; score/projected stats updated; generated deferred. |
| `000000011023` | `2026-07-14T08:21:41-04:00` | UID0001O4 | exit 0; ok 1 | 20 `missing_ref_uid`; projected stats updated; generated deferred. |
| `000000011024` | `2026-07-14T08:22:16-04:00` | UID0000GA | exit 0; ok 1 | 14 `missing_ref_uid`; score and true/emitter -> false/blank registry update; generated deferred. |
| `000000011025` | `2026-07-14T08:22:43-04:00` | UID0000G8 | exit 0; ok 1 | 12 `missing_ref_uid`; score and true/emitter -> false/blank registry update; generated deferred. |
| `000000011026` | `2026-07-14T08:23:28-04:00` | UID0003SX | exit 0; ok 1 | 2 `missing_ref_uid`; UID path registration, false/blank/score registry update; generated deferred. |
| `000000011027` | `2026-07-14T08:23:55-04:00` | UID0003T0 | exit 0; ok 1 | 2 `missing_ref_uid`; UID path registration, false/blank/score registry update; generated deferred. |
| `000000011028` | `2026-07-14T08:24:22-04:00` | UID0003T1 | exit 0; ok 1 | 2 `missing_ref_uid`; UID path registration, false/blank/score registry update; generated deferred. |
| `000000011029` | `2026-07-14T08:24:47-04:00` | UID0003T4 | exit 0; ok 1 | 1 `missing_ref_uid`; UID path registration, false/blank/score registry update; generated deferred. |
| `000000011030` | `2026-07-14T08:25:10-04:00` | UID0003T5 | exit 0; ok 1 | 4 `missing_ref_uid`; UID path registration, false/blank/score registry update; generated deferred. |
| `000000011031` | `2026-07-14T08:25:37-04:00` | UID0003T9 | exit 0; ok 1 | No file warning; UID path registration and false/blank/score registry update; generated deferred. |
| `000000011032` | `2026-07-14T08:26:02-04:00` | UID0003TA | exit 0; ok 1 | No file warning; UID path registration and false/blank/score registry update; generated deferred. |
| `000000011033` | `2026-07-14T08:26:32-04:00` | UID0003SZ | exit 0; ok 1 | 2 `missing_ref_uid`; UID path registration, false/blank/score registry update; generated deferred. |
| `000000011034` | `2026-07-14T08:26:59-04:00` | UID0003T7 | exit 0; ok 1 | 4 `missing_ref_uid`; UID path registration, false/blank/score registry update; generated deferred. |
| `000000011036` | `2026-07-14T08:27:27-04:00` | UID0003T8 | exit 0; ok 1 | No file warning; UID path registration and false/blank/score registry update; generated deferred. |
| `000000011037` | `2026-07-14T08:27:52-04:00` | `by-memory/-ignored.md` | exit 0; ok 1 | 314 pre-existing ledger-wide `missing_ref_uid`; padding references indexed; generated deferred. |
| `000000011040` | `2026-07-14T08:28:38-04:00` | UID0000G9 precision refresh | exit 0; ok 1 | 10 `missing_ref_uid`; historicalized stale recovered-file wording; generated deferred. |
| `000000011041` | `2026-07-14T08:28:57-04:00` | UID0003SR final waited refresh | exit 0; ok 1 | 4 unresolved sibling/runtime UIDs; registry rebuilt; 280 generated metadata refreshes; unrelated project-wide warnings: 15 children fallback inserts, 84 missing preferred children markers, 196 emitters with no own code. Generated refresh completed. |

The `missing_ref_uid` warnings are pre-existing unregistered exact-child/sibling links, not broken target paths; scoped helper validators registered the ten edited helper UIDs normally. B004 did not edit validator state to suppress them. Validator-managed side effects included `validator.ini` metadata/reference registry updates, projected stats updates, generated coverage metadata, and generated C++ refresh; none was edited manually.

### Generated readback

- File: `auto-generated/NexusTK/map/WorldMapPane.cpp`, 54 lines.
- Header: `validator-command-id: 000000011041`; `validator-refreshed-at: 2026-07-14T08:28:57-04:00`, equal to the waited command metadata.
- Generated `UID:0003SR` separator count `1`; `void WorldMapPane::BuildReachabilityData()` definition count `1`; target Empty Emitter Marker count `0`.
- UID0000G8 marker count `0`; UID0000GA marker count `0`; combined UID0003SX/T0/T1/T4/T5/T9/TA/SZ/T7/T8 marker/body count `0`; old custom helper-name count `0`.
- The only emitted `WorldMapPane::` definition is UID0003SR. No duplicate sibling C++ appears.
- Five unrelated/unchanged Empty Emitter Markers remain for UID0000G9, UID00035H, UID00035I, UID00035J, and UID00029E; none is a callback target helper or target method.
- Source readback contains the exact accepted includes/body and contains no raw offsets, SEH/cookie scaffolding, explicit allocator/deque-map/bit-word code, or invented bounds guard.

## Changed Files

- Modified target: `by-memory/0x005c4bd0-0x005c5075.WorldMapPaneBuildReachabilityData.md`.
- Modified ownership/route/index: `by-class/WorldMapPane.md`, `by-file/WorldMapPane.md`, `by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md`.
- Modified container facades: `by-class/WorldMapReachabilityBitSet.md`, `by-class/WorldMapNodeEntryVector.md`.
- Modified bitset specialization pages: `by-memory/0x005c53d0-0x005c54f3.WorldMapReachabilityBitSetReserveBits.md`, `0x005c5580-0x005c55d7.WorldMapReachabilityBitSetPositionHelper.md`, `0x005c55e0-0x005c563c.WorldMapReachabilityBitSetResolveIterator.md`, `0x005c56a0-0x005c584b.WorldMapReachabilityBitSetInsertBits.md`, `0x005c5850-0x005c58a9.WorldMapReachabilityBitSetShrinkToBitCount.md`, `0x005c5ad0-0x005c5b18.WorldMapReachabilityBitSetEndIterator.md`, and `0x005c5b20-0x005c5c87.WorldMapReachabilityBitSetMoveBitRange.md`.
- Modified node-vector specialization pages: `by-memory/0x005c5510-0x005c557a.WorldMapNodeEntryVectorDestructor.md`, `0x005c58c0-0x005c5a8f.WorldMapNodeEntryVectorAssign.md`, and `0x005c5a90-0x005c5aca.WorldMapNodeEntryVectorFreeAllocation.md`.
- Modified padding ledger: `by-memory/-ignored.md`.
- Modified this report: `tools/leaser/Agents/Agent-B004/research/0003SR-WorldMapPaneBuildReachabilityData-source-quality.md`.
- No path rename/new ordinary child was required. UID0003T6, UID000149, UID0001B2, siblings, read-only/vtable/global support were not directly edited.
- Manual `-coverage-report.md`, tracker, audit, supervisor, lifecycle, archive, and IDA files were not edited. Generated/registry/stat files changed only through authorized validator commands.

### Lease closure

- B004 acquired each ordinary destination only for its immediate edit/validator window and received `Success` on every explicit unlease.
- UID0003SR and UID0000G9 had one additional short lease for final waited validation and a precision wording refresh respectively; both were explicitly released.
- The shared `current_leases.md` readback captured immediately after callback validation contained no B004 lease and no lease on any UID0003SR callback destination. It listed unrelated B003 (`by-class/SelfLookPane2.md`) and B005 (`by-memory/0x004cee60-0x004cf1ef.HourPane.md`) leases at that evidence time; both were left untouched.

## Implementation Tracking Checklist

### Report-only research phase

- [x] Historical pre-callback exact artifact SHA `E5F51F2FE4FF2D327F1C2D66ECAB7DCBAE6AFA40F5EDF5D5D66DDAEBD366A6E0` passed supervisor Gate 1 before this callback.
- [x] Research evidence, rejected alternatives, formal block, exact coverage text, and unchecked callback plan were preserved in this same report.
- [x] No by-* implementation or validator ran before the explicit callback.

### Authorized callback phase

- [x] Re-read every destination immediately before editing and preserved concurrent/unrelated content.
- [x] Leased, edited, scoped-validated, and immediately released UID0003SR; commands `11020` and final waited `11041` prove the target.
- [x] Applied C01-C31 and the exact managed target definition without behavioral compression.
- [x] Preserved target UID/path/range/owner/emitter/position/Nested metadata and set `92/94`.
- [x] Added exact ignored `[0x005c5075,0x005c5080)` padding under a short lease; validator `11037`.
- [x] Synchronized UID0000G9 and UID0000PB at `90/93` and `91/92` without unrelated formal changes.
- [x] Synchronized UID0001O4 as false/non-emitting at unchanged `88/91`.
- [x] Reclassified UID0000GA and UID0000G8 false/non-emitting with blank formal blocks and complete retained evidence.
- [x] Reclassified UID0003SX/T0/T1/T4/T5/T9/TA false/non-emitting and preserved exact binary/source-disposition evidence.
- [x] Reclassified UID0003SZ/T7/T8 false/non-emitting and preserved exact binary/source-disposition evidence.
- [x] Kept UID0003T6, UID000149, UID0001B2, siblings, read-only-data, vtable, and global support outside direct edit scope.
- [x] Ran scoped validation for every changed ordinary page and recorded all command IDs/timestamps/exits/ok/warnings/side effects above.
- [x] Released every B004 lease; final shared lease readback contains no B004 or callback-destination lease.
- [x] Ran one authorized waited generated refresh, command `000000011041`, after ordinary-page validators.
- [x] Verified exactly one target definition and zero UID0003SR Empty Emitter Markers.
- [x] Verified zero emitted custom bitset/node-vector/helper bodies and no duplicate sibling C++.
- [x] Verified target source contains no raw offsets, EH scaffolding, explicit allocator/deque-map/bit-word code, or invented bounds guard.
- [x] Updated C01-C40 to legal applied/already-present states with claim-by-claim destination proof.
- [x] Added exact validator inventory, changed-file inventory, generated assertions, lease closure, and remaining naming limitation to this same report.
- [x] Did not manually edit coverage/generated/tracker/audit/supervisor/validator-state/lifecycle/archive/IDA files.
- [x] Did not run `execute_report`, report probes/counts, move, archive, or lifecycle commands.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000011079","destination_path":"executed-b-agent-research/B004/0003SR-WorldMapPaneBuildReachabilityData-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0003SR-WorldMapPaneBuildReachabilityData-source-quality.md","timestamp":"2026-07-14T08:40:34-04:00","uid":"0003SR"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
