** TARGET-REPORT-UID:0001GZ **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# 0001GZ ScrollInventoryPane Source-Quality Research


## Finalized Report / Current Recommendation
- Current implemented disposition: [UID:0001GZ][0x00563260-0x0056470c.ScrollInventoryPane](../../../by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md) is the `ScrollInventoryPane` executable aggregate owned and emitted through [UID:0000CK][ScrollInventoryPane](../../../by-class/ScrollInventoryPane.md), with file route [UID:0000KB][InventoryScrollPane](../../../by-file/InventoryScrollPane.md).
- Final disposition: source-bearing aggregate/index over exact child methods, not a standalone method body. It now emits only a formal no-standalone-body marker, and generated `InventoryScrollPane.cpp` no longer reports an Empty Emitter Marker for UID0001GZ.
- Callback action applied: target metadata is `COMPLETION:86`, `CONFIDENCE:90`; `CANONICAL_OWNER:0000CK`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CK`, and blank optional position are retained; the exact formal marker block in `## First-Draft C++ Recommendation` is inserted in the target page.
- Confidence: high for owner/emitter, range boundary, child inventory, caller/callee/vtable evidence, generated-output reason, and no-standalone-aggregate-body policy; capped below final audit by unresolved exact source split and the fact that UID0001GZ is still a broad aggregate over several modeled/raw helper islands rather than one final source body. UID0001H0's earlier source-ready gap was resolved later by B008 and is no longer current generated-output evidence against UID0001GZ.

## Supporting Research
- Assignment history: `Agent-B007/goal.md` originally assigned UID0001GZ as a report-only Medium B-agent pass requiring MCP-backed evidence. Supervisor later accepted the report and authorized this implementation callback; the report now records both the research evidence and the callback incorporation results.
- MCP provenance: supervisor restarted MCP; B007 rechecked read-only availability and used active session `aa3930bd` only. `idb_list` reported one active NexusTK session for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `13724`, `is_active:true`. `server_health` reported `status:ok`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- Historical pause state: earlier paused MCP evidence from stale/no-session state is not used as final evidence. The evidence in this report is from the restored `aa3930bd` session plus current local docs/generated files.
- Local docs reviewed: target by-memory page, `by-class/ScrollInventoryPane.md`, `by-file/InventoryScrollPane.md`, `by-file/NewInventoryPane.md`, UID0001H0, UID0001H1, layout, vtable, vtable-data, tracker/coverage generated reports, generated `InventoryScrollPane.cpp`, and executed B003 UID0001H1 report.
- Historical generated state before callback: `auto-generated/NexusTK/ui/inventory/InventoryScrollPane.cpp` header recorded validator command `000000005987`, refreshed `2026-07-04T00:52:33-04:00`; it emitted UID0001H1 `ResetScrollState()` and still showed an Empty Emitter Marker for UID0001GZ.
- Historical B007 generated state after B007 scoped validators: `InventoryScrollPane.cpp` header recorded validator command `000000006077`, refreshed `2026-07-04T04:27:22-04:00`, and contained UID0001GZ marker-only output while UID0001H0 still appeared as an Empty Emitter Marker outside B007 scope.
- Current generated state after later B008 UID0001H0 work: `InventoryScrollPane.cpp` header records validator command `000000006093`, refreshed `2026-07-04T04:34:48-04:00`; UID0001GZ remains marker-only at lines 7-8, and UID0001H0 now emits `void ScrollInventoryPane::UpdateFromDrag(int localX, int localY)` beginning at lines 10-11. UID0000CK, UID0001W0, and UID0001YQ remain Empty Emitter Markers, outside this UID0001GZ report's scope.
- Coordination note: B008 owns the UID0001H0 source/C++ work. This B007 implementation did not alter UID0001H0 source/C++; the current generated UID0001H0 body is later B008 output.

## Target
- Target UID: `0001GZ`
- Target path: `by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md`
- Historical source queue/report row before callback: `auto-generated/-ag-research-tracker.md` reported `85/89`, combined `87.0`, reconstructable `true`, reports `0`.
- Supervisor classification for the accepted work: reconstructable by-memory source-quality callback, marker-only aggregate/status repair.
- Current implemented scores and parent state: target metadata is `86/90`, `CANONICAL_OWNER:0000CK`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CK`; class parent UID0000CK is `85/86` and routes to by-file UID0000KB at `86/88`.

## Current Target State
- Current metadata: `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000CK`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CK`, blank `EMITTER_POSITION_OPTIONAL`.
- Current C++/emitter state: the target formal multiline `RECONSTRUCTION_CPP CODE` block contains the accepted marker-only no-standalone-body comment. The inline `RECONSTRUCTION_CPP CODE:[[[]]]` value remains blank as required.
- Historical pre-callback stale assumptions: the target `Item Summary` said "Unassigned under corrected 85/85 gate" and cited old parent blockers (`InventoryScrollPane 84/80`, `ScrollInventoryPane 82/82`, `NewInventoryPane 82/82`). The implemented target summary now historicalizes those blockers as superseded by the current UID0000CK/UID0000KB route and `86/90` marker-only policy.
- Related target/support docs checked: UID0001H0 was blank/source-blocked during the B007 callback and was intentionally left to B008; current generated output now shows B008's UID0001H0 `ScrollInventoryPane::UpdateFromDrag` C++ body. UID0001H1 carries formal `ScrollInventoryPane::ResetScrollState()` C++; layout/vtable pages carry the accepted tail-field/vtable evidence. B007 edited only the UID0001GZ target, class/file support notes, and the stale UID0001H1 support summary; UID0001H0 source/C++ was not altered by B007.
- Lifecycle history: initial B007 report-only work made no by-* edits. The supervisor-authorized implementation callback applied the by-* edits and scoped validators recorded below. Report execution/lifecycle state is supervisor-owned and was not modified by B007.

## Executive Recommendation
- Keep direct semantic ownership on [UID:0000CK][ScrollInventoryPane](../../../by-class/ScrollInventoryPane.md). The receiver fields, vtable stores, method inventory, UID0001H1 body, and UID0001H0/update interaction all belong to that class.
- Keep current file route through [UID:0000KB][InventoryScrollPane](../../../by-file/InventoryScrollPane.md). [UID:0000LS][NewInventoryPane](../../../by-file/NewInventoryPane.md) remains a plausible final fold destination because it is the only constructor caller, but it is a consumer/fold candidate, not the direct owner.
- Do not write broad aggregate C++ for UID0001GZ. The aggregate contains multiple modeled functions, raw helper islands, child pages, padding, and vtable/layout dependencies; pasting child method bodies into the aggregate would violate by-memory source-boundary policy.
- Implemented a formal marker-only no-standalone-body comment so UID0001GZ is no longer an empty emitter while preserving exact child-method ownership. Do not use `[[CHILDREN]]` for this target unless the supervisor deliberately wants generator child insertion: generated output already emits exact child pages through class UID0000CK, and UID0001GZ has `Nested:0`.

## Supervisor Active Recheck
- Research-pass MCP recheck: the user instruction resumed Agent-B007's report-only goal after MCP restart and required using the fresh active session returned by `idb_list`; that final evidence pass used `aa3930bd`.
- The assigned item did not require split creation. Exact child pages already exist for UID0001H0 and UID0001H1; raw subranges are documented in the aggregate, and UID0001H0 source/C++ was handled by B008 outside B007 scope.
- Every source-bearing child in scope was reviewed for disposition: UID0001H1 is implemented with first-draft C++; UID0001H0 now has B008-generated `UpdateFromDrag` C++ in current generated output; the UID0001GZ aggregate itself remains an implementation-ready marker-only no-code disposition instead of a broad body.

## Inference Research Guidance Check
- `by-structure.md` requires `by-memory` C++ to be limited to the page's own memory range and says parent aggregate code should contain only parent-range source shape or a child insertion point when appropriate. That prevents adding UID0001H1 `ResetScrollState()` or B008's UID0001H0 C++ into UID0001GZ.
- Evidence is separated as: MCP facts (`aa3930bd` lookup/xref/callee/byte/decompile/find-bytes), documentation evidence (current by-* pages and executed B003 report), generated evidence (`InventoryScrollPane.cpp` and auto-generated tracker/coverage), and inference (marker-only aggregate policy and final source-file fold uncertainty).
- Stale Wave2/Wave3/generated labels were treated only as leads. Generated `class_` naming and old `AUTOGEN_PARENT_UID` language are not used as current authority.

## Heuristic / Inference Reanalysis And Validation
- Ownership: class ownership is current and defensible. Constructor vtable stores hit the `ScrollInventoryPane` vtables, the layout tail fields are class-local, UID0001H1's formal C++ uses `m_highlightPart`/`m_activePart`, and UID0001H0 calls the owner callback only after recomputing this class's scroll position.
- Source placement: [UID:0000KB] is the current source route because it has a valid `NexusTK/ui/inventory/` path and records the companion scrollbar file hypothesis. [UID:0000LS] remains a file-fold candidate because `xrefs_to 0x00563260` has exactly one caller at `0x004eb4e4` inside `NewInventoryPane::NewInventoryPane`.
- Range/split: current MCP `entity_query` over `0x00563260-0x00564710` lists 13 functions including successor `0x00564710`. The target range itself contains 12 modeled functions plus raw non-function helper starts. The raw starts at `0x00563310`, `0x00563340`, `0x00563420`, `0x00563440`, `0x00564330`, `0x005643a0`, and `0x005646b0` remain outside IDA's function table.
- Generated-output blocker resolution: UID0001GZ was not covered before callback because the formal block was blank while `EMITTER_UIDS:0000CK` was nonblank. The implemented comment-only marker resolves the generated empty marker without inventing aggregate executable code; B007 validator command `000000006077` first showed UID0001GZ marker-only output, and current generated command `000000006093` still shows the same UID0001GZ marker.
- UID0001H0 relationship: during the B007 callback, `UpdateFromDrag` had strong behavior evidence but no formal C++ and was assigned to B008, so B007 correctly excluded it. Current generated output now shows B008's `ScrollInventoryPane::UpdateFromDrag(int localX, int localY)` body; this supersedes the old generated-empty state without changing UID0001GZ's marker-only aggregate policy.
- UID0001H1 relationship: B003 resolved the reset child as source-bearing `ScrollInventoryPane::ResetScrollState()` and explicitly warned not to merge that child C++ into UID0001GZ aggregate C++. Current MCP still reports no xrefs to `0x005646b0`.
- Rejected alternatives: direct `NewInventoryPane` owner, generic `ScrollBar` owner, no-owner/non-emitting target, raw broad decompiler body, `[[CHILDREN]]` child insertion, and leaving the stale "unassigned/parent blocker" summary unchanged.
- Remaining unresolved issue: the exact original source-file split between standalone `InventoryScrollPane.cpp` and folded `NewInventoryPane.cpp` is unresolved, but it does not affect direct class owner/emitter or marker-only aggregate treatment.

## Evidence Standards Used
- Evidence types used: MCP `idb_list`, `server_health`, `lookup_funcs`, `entity_query`, `xrefs_to`, `callees`, `get_bytes`, `find_bytes`, and targeted decompile; current by-* docs; executed B003 report; generated tracker/coverage; generated C++ output.
- Strength: current MCP confirms the active IDB, exact function table, caller/callee sets, vtable xrefs, bytes/padding, raw non-function starts, and negative VA/RVA literal searches. Existing by-* docs and B003 provide accepted source-facing field/method names.
- Confidence limits: no symbol proof for original file split, no raw-start xref for UID0001H1, no safe single aggregate C++ body, and several raw helper islands still remain documented inside UID0001GZ rather than all being exact source-ready child pages.

## Evidence Checked
- IDA MCP checks performed on `aa3930bd`: `idb_list`; `server_health`; `lookup_funcs` on all key target starts/interiors/successor; `entity_query` bounded to `0x00563260-0x00564710`; `xrefs_to` constructor, UID0001H0, raw reset, vtable bases, and successor vtable; `callees` for constructor/mouse/timer/paint/region/part-rect/dispatcher/update; `get_bytes` at constructor boundary, raw setter/predicate/helper/reset boundaries, and vtable data; `find_bytes` for VA/RVA dwords for `0x00563260`, `0x00564520`, and `0x005646b0`; targeted decompile for `0x004eb420`, `0x00563260`, `0x00564460`, and `0x00564520`.
- by-* docs checked: target UID0001GZ; UID0000CK class; UID0000KB file; UID0000LS file; UID0001H0; UID0001H1; UID0001W0 layout; UID0001YQ vtables; UID0003CO exact vtable data.
- Old reports searched: `rg` terms `0001GZ`, `0x00563260`, `ScrollInventoryPane`, and `InventoryScrollPane` under `tools/leaser/Agents` and `executed-b-agent-research`; opened executed B003 UID0001H1 report as the directly relevant accepted report and used B014 only as a sibling pattern lead from search results.
- Generated checked: `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `auto-generated/NexusTK/ui/inventory/InventoryScrollPane.cpp`.
- Negative checks: no xrefs to raw reset start `0x005646b0`; zero VA/RVA dword hits for `0x00563260`, `0x00564520`, and `0x005646b0`; no current evidence that [UID:0000LS] should be direct semantic owner; no evidence that UID0001GZ should contain child C++.
- Failed/unavailable checks: none in the final MCP pass. The earlier stale/no-session MCP condition was superseded by supervisor restore and is not used as evidence.

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0001GZ-01 | Final MCP evidence uses active session `aa3930bd`; stale/no-session evidence is not final provenance. | High | `idb_list` active session, `server_health status:ok`, Hex-Rays ready. | Target `2026-07-04 B007 MCP Source-Quality Recheck`; class/file support evidence notes. | incorporate | applied |
| C-0001GZ-02 | UID0001GZ remains a multi-body aggregate with 12 modeled target functions, raw helper islands, and successor `0x00564710`. | High | `lookup_funcs`, `entity_query`, `get_bytes` boundary reads. | Target `Covered Ranges`, `Score Rationale`, and `2026-07-04 B007 MCP Source-Quality Recheck`. | incorporate | applied |
| C-0001GZ-03 | Direct owner/emitter should remain `ScrollInventoryPane` UID0000CK and file route UID0000KB. | High | Constructor vtable refs, class docs, file docs, UID0001H1 owner, UID0001H0 receiver/callback. | Target metadata/status; `by-class/ScrollInventoryPane.md`; `by-file/InventoryScrollPane.md`. | incorporate | applied |
| C-0001GZ-04 | `NewInventoryPane` is a caller/fold candidate, not direct owner. | High | `xrefs_to 0x00563260` one caller `0x004eb4e4`; `decompile 0x004eb420` allocates 272, calls `sub_563260(v2,0)`, stores child. | Target B007 recheck block; class/file support evidence and fold caveat. | incorporate | applied |
| C-0001GZ-05 | Target's stale "unassigned/parent blockers" summary is false in current docs and generated coverage. | High | Target metadata has owner/emitter `0000CK`; class/file support scores are `85/86` and `86/88`; generated coverage repeated stale summary before callback. | Target `Item Summary`; support notes; generated refresh through validators. | incorporate | applied |
| C-0001GZ-06 | UID0001GZ should not receive a broad source body or copied child method C++. | High | `by-structure.md` by-memory block rule; B003 explicitly says do not merge UID0001H1 C++ into UID0001GZ. | Target formal C++ block, source-policy note, class/file support notes. | incorporate | applied |
| C-0001GZ-07 | UID0001GZ should receive a formal marker-only no-standalone-body comment to clear its Empty Emitter Marker. | High | Pre-callback generated `InventoryScrollPane.cpp` had UID0001GZ Empty Emitter Marker; B007 post-validator generated header `000000006077` showed marker-only UID0001GZ output; current generated header `000000006093` still shows UID0001GZ marker-only output at lines 7-8. | Target `RECONSTRUCTION_CPP CODE` block and generated freshness observation. | incorporate | applied |
| C-0001GZ-08 | UID0001H1 is already source-ready and emitted; its stale summary can be support-synced but child code is already present. | High | UID0001H1 target has formal `ResetScrollState()` C++; generated output includes the body; B003 executed report. | UID0001H1 Item Summary support sync only; target/class/file relationship notes. | already-present / incorporate | applied |
| C-0001GZ-09 | UID0001H0 remains related but should not be edited by B007 because B008 owns that source/C++ work; later B008 output supersedes the old UID0001H0 Empty Emitter Marker. | High | `rg` over B-agent goals showed Agent-B008 assigned UID0001H0; supervisor callback explicitly forbade B007 UID0001H0 source/C++ changes; current generated header `000000006093` now emits `ScrollInventoryPane::UpdateFromDrag`. | Report checklist/support recommendations; class/file support notes preserve B008 boundary; current generated-output note records B008 output. | already-present | already-present |
| C-0001GZ-10 | Recommended target score is `86/90`, not higher. | Medium-high | Fresh MCP evidence resolves stale provenance/output blocker; final source split and broad aggregate/raw-island policy remain unresolved. | Target metadata and score rationale; validator command `000000006069` confirmed completion/confidence updates. | incorporate | applied |

## Positive Evidence Summary
- Direct facts supporting recommendation: active MCP `aa3930bd` confirms target function/raw inventory, constructor caller, vtable store xrefs, UID0001H0 dispatcher/update relationship, raw reset no-xref state, byte padding, and zero VA/RVA literal hits for target/update/reset starts.
- Corroborating documentation/generated evidence: by-class/by-file/layout/vtable pages route the class through UID0000CK/UID0000KB; executed B003 report and UID0001H1 page provide accepted child C++; pre-callback generated output proved UID0001GZ's problem was an empty-emitter marker, not missing owner/emitter routing; B007 post-callback output contained the UID0001GZ marker-only line, and current B008-refreshed output keeps that marker while adding UID0001H0 `UpdateFromDrag` C++.
- Strongest inference chain: a multi-method aggregate with exact child pages should not emit a synthetic broad method; a formal comment-only no-standalone-body marker records that source policy and removes empty generated output for the target.

## IDA MCP Facts
- Function/range facts: `lookup_funcs` reports constructor `sub_563260` size `0xa1`; modeled helpers at `0x00563370` (`0x5b`), `0x005633d0` (`0x27`), `0x00563400` (`0x1a`), `0x00563460` (`0x1e1`), `0x00563650` (`0x5`), `0x00563660` (`0x33`), `0x005636a0` (`0x6e0`), `0x00563d80` (`0x31d`), `0x005640a0` (`0x287`), `0x00564460` (`0xc0`), `0x00564520` (`0x18d`); successor `0x00564710` is `sub_564710`, size `0xa1`.
- Raw starts/non-functions: `0x00563310`, `0x00563340`, `0x00563420`, `0x00563440`, `0x00564330`, `0x005643a0`, `0x005646ad`, `0x005646b0`, and `0x0056470c` are not function starts in current IDA.
- Xref facts: constructor has one code xref at `0x004eb4e4` inside `sub_4EB420`; UID0001H0 has two xrefs at `0x005644bb` and `0x005644e4` inside `sub_564460`; raw reset start `0x005646b0` has zero xrefs.
- Vtable facts: constructor stores vtable bases `0x0062402c`, `0x00624078`, and `0x006240a8` at `0x005632b1`, `0x005632b7`, and `0x005632c1`; successor `0x006240b4` is stored by `sub_564710` at `0x00564761`.
- Decompile facts: `NewInventoryPane` constructor allocates `272`, calls `sub_563260(v2, 0)`, stores the pointer at `this+0x114`, then calls `sub_563400`; `ScrollInventoryPane` constructor writes orientation at `+0xfc`, zeroes `+0xfe/+0x100`, writes `0x00010000` at `+0xf8`, writes `-255` at `+0x102`, clears `+0x104`, and initializes point `+0x108`.
- Dispatcher/update facts: `sub_564460` checks active part `+0x104` for thumb part `2`, calls `sub_564520`, otherwise classifies through `sub_563D80`, invalidates stale `+0x103` through `sub_5640A0` and Pane vslot `+0x20`; `sub_564520` reads current `+0xfe`, orientation `+0xfc`, range `+0x100`, drag anchors `+0x108/+0x10c`, and calls owner callback `0x004eba00` only on position change.
- Byte facts: target starts after `0xcc` padding with `55 8b ec`; raw setter/predicate/helper spans have method-shaped prologues; `0x005646ad-0x005646af` is `cc cc cc`, `0x005646b0` begins `55 8b ec`, and the next modeled function begins at `0x00564710`.
- Negative IDA facts: `find_bytes` reports zero matches for VA/RVA dword patterns for `0x00563260`, `0x00564520`, and `0x005646b0`.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00563260-0x0056470c` | UID0001GZ target | ScrollInventoryPane aggregate | `TRUE` | UID0000CK | current `86/90` | Marker-only aggregate applied. |
| `0x00564520-0x005646ad` | UID0001H0 | `UpdateFromDrag` method | `TRUE` | UID0000CK | current generated output shows `88/91` | Emits `ScrollInventoryPane::UpdateFromDrag(int localX, int localY)` through B008 work; B007 did not edit this child. |
| `0x005646b0-0x0056470c` | UID0001H1 | `ResetScrollState` raw helper | `TRUE` | UID0000CK | `86/89` | Already emits formal child C++. |
| Layout offsets `+0xf8`-`+0x10f` | UID0001W0 | class layout support | `TRUE` | UID0000CK | `85/88` | Support metadata; no standalone method C++. |
| Vtable family `0x00624028-0x006240b0` | UID0001YQ / UID0003CO | source-declared/generated-binary vtables | `TRUE` | UID0000CK | `86/90` | Support metadata; no standalone method C++. |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00563260` | code xref `0x004eb4e4` in `sub_4EB420` | `NewInventoryPane` constructs the private scrollbar. |
| `0x00564520` | code xrefs `0x005644bb`, `0x005644e4` in `sub_564460` | `UpdateFromDrag` is reached only through the local active-state dispatcher. |
| `0x005646b0` | zero xrefs | Raw reset remains caller-unproven but accepted as UID0001H1 child. |
| `0x0062402c`, `0x00624078`, `0x006240a8` | data xrefs from `0x005632b1`, `0x005632b7`, `0x005632c1` | Constructor-installed ScrollInventoryPane vtable views. |
| `0x006240b4` | data xref `0x00564761` in `sub_564710` | Successor `ScrollVolumePane` boundary. |

## Documentation Evidence And IDA Status
- Existing docs that support the conclusion: UID0000CK, UID0000KB, UID0000LS, UID0001W0, UID0001YQ, UID0003CO, and executed B003 report all support class ownership, inventory source route, one-caller/fold caveat, field/vtable roles, and UID0001H1 child emission.
- Historical stale docs repaired by this callback: UID0001GZ Item Summary and generated coverage row said unassigned and old parent blockers before implementation; UID0001H1 Item Summary said "attached to InventoryScrollPane file parent" and "final C++ remains blocked" despite current class owner/emitter and formal C++. These UID0001GZ/support phrases were updated in the target, class/file support, and UID0001H1 support summary.
- Historical B007 callback exclusion: UID0001H0 had related stale/source-blocked wording during the B007 callback, but it was B008-owned active work and the callback explicitly excluded B007 source/C++ edits there.
- Current generated/coverage state: generated C++ header `000000006093` has UID0001GZ marker-only output and no UID0001GZ Empty Emitter Marker; it also has UID0001H0 `UpdateFromDrag` C++ from B008. Project-level/generated coverage refreshes were validator side effects only; B007 did not edit generated files manually.

## Ranked Ownership Analysis

### 1. UID0000CK ScrollInventoryPane
- Evidence for: constructor installs `ScrollInventoryPane` vtables; helper/update/reset fields are class-local; UID0001H1 formal source body is a class method; class page routes to valid file root; current target already has owner/emitter UID0000CK.
- Evidence against: final source-file split remains open and UID0001GZ is still a broad marker-only aggregate rather than one standalone body; those are source-placement/C++ completeness caps, not ownership blockers. UID0001H0's historical missing-body cap was superseded by later B008 output.
- Decision: retain as canonical owner and emitter.

### 2. UID0000KB InventoryScrollPane
- Evidence for: current source file route, valid projected path `NexusTK/ui/inventory/`, by-file page documents companion scrollbar file, generated output currently stages `InventoryScrollPane.cpp`.
- Evidence against: by-structure prefers the direct class owner for class methods/aggregates when known. Direct file ownership would lose receiver/layout/vtable semantics.
- Decision: retain as file route only.

### 3. UID0000LS NewInventoryPane
- Evidence for: sole constructor caller at `0x004eb4e4`; caller allocates `272` bytes and stores the child pointer; final migration may fold the companion source into `NewInventoryPane.cpp`.
- Evidence against: the target receiver is the scrollbar object, not `NewInventoryPane`; vtables/layout are `ScrollInventoryPane`; no evidence NewInventoryPane owns the child method bodies directly.
- Decision: reject direct owner/emitter; preserve as fold candidate.

### 4. Generic ScrollBar / Shared Scroll Helper / No Owner
- Evidence for: repeated scroll-control patterns and shared TimerHandler/Pane dependencies.
- Evidence against: class-specific vtables, one item-inventory constructor caller, inventory-specific part-rect helper, and accepted UID0001H1 class method body.
- Decision: reject. No-owner/non-emitting treatment is too weak because owner/emitter evidence is already current and above gate.

### Proposed new file/grouping, if applicable
- Proposed owner/name/path: no new file. Keep [UID:0000KB] `InventoryScrollPane.md` and generated path `NexusTK/ui/inventory/InventoryScrollPane.cpp`, with possible future fold into `NewInventoryPane.cpp`.
- Likely full contents: constructor, range/position/enable helpers, mouse/timer handlers, paint, region/part-rect/highlight helpers, dispatcher, UID0001H0 update, UID0001H1 reset, layout/vtable declarations.
- Candidate related items rejected from the B007 callback: UID0001H0 formal C++ because it was B008-owned work, now present in current generated output; layout/vtable marker cleanup because those pages are support metadata not required to resolve UID0001GZ.
- Standalone/narrow/broad source-file inference: current dedicated companion file is defensible; final physical fold remains unresolved but nonblocking.

## Source Placement
- Recommended source file/class/module placement: direct class `ScrollInventoryPane`, generated through `NexusTK/ui/inventory/InventoryScrollPane.cpp`.
- Why this fits: UI inventory path matches [UID:0000KB]/[UID:0000LS]; constructor is private to `NewInventoryPane`; scrollbar behavior is feature-specific rather than generic.
- Rejected placements: direct `NewInventoryPane` method ownership, generic `ScrollBar`, no-owner/non-emitting aggregate, and raw `sub_563260`/aggregate decompiler file.
- Remaining placement uncertainty: whether the final original source had a standalone `InventoryScrollPane.cpp` or a private section of `NewInventoryPane.cpp`.

## Range / Split / Padding / Reclassification Analysis
- Exact range/boundary facts: target starts at modeled constructor `0x00563260`, contains modeled and raw helper islands through raw reset ending before `0x0056470c`, then four `0xcc` bytes before successor `0x00564710`.
- Children/subranges: UID0001H0 and UID0001H1 exact child pages exist. UID0001H1 is source-ready, and UID0001H0 now emits B008 `UpdateFromDrag` C++ in current generated output. Raw setter/highlight/drag islands remain documented in the aggregate and can become future exact children if source-quality callbacks require them.
- Padding/table/data/code distinctions: `cc` padding separates modeled functions/raw bodies; vtable data lives separately under UID0003CO/UID0001YQ and should not be folded into this executable aggregate's C++.
- Parent/container impact: UID0001GZ is a source-bearing aggregate marker/index, not a broad body. Keep `RECONSTRUCTABLE:TRUE` but make emitted content marker-only.

## Negative Evidence Summary
- No direct owner evidence for NewInventoryPane beyond constructor consumption.
- No generic ScrollBar/shared helper ownership evidence; shared helpers are callees/dependencies.
- No `0x005646b0` xrefs and no VA/RVA dword route to target/update/reset starts in current MCP `find_bytes`.
- No safe broad C++ body: the range contains multiple methods, raw helper islands, padding, and child pages; child C++ belongs on exact children.
- No current basis for B007 to modify UID0001H0 formal C++ because B008 owns that target and current generated output already includes B008's source body.

## IDA Rename / Type / Comment Recommendations
- Proposed source-facing names/types/comments: keep existing accepted names `ScrollInventoryPane`, `UpdateFromDrag` as a candidate/descriptive method name for UID0001H0, `ResetScrollState` for UID0001H1, `m_highlightPart`, `m_activePart`, `TimerHandler` view, and `GetPartRect`.
- Evidence: decompile and support docs show `+0xfc` orientation, `+0xfe` position, `+0x100` range, `+0x103` highlight, `+0x104` active part, `+0x108/+0x10c` drag anchor, and `0x004eba00` owner callback.
- Items intentionally left unchanged: no IDA DB renames or function creation; no suggested IDA function at raw `0x005646b0`; no exact source name for unresolved `+0xfa`.
- IDA DB edit safety: not requested and outside this B-agent callback scope.

## First-Draft C++ Recommendation
- Eligible for draft C++: not eligible for a standalone executable C++ body. Eligible for a formal marker-only no-code block because UID0001GZ is an emitting aggregate with no safe broad source body.
- Recommended code: exact formal `RECONSTRUCTION_CPP CODE` header/block insertion text for the target:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// This aggregate has no standalone source body; exact ScrollInventoryPane method bodies are emitted by exact child pages routed through [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md).
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Reason it preserves exact original behavior: it emits no executable statements, no ABI glue, and no duplicated child method bodies.
- Reason it matches plausible original source shape: the original source would have class methods, not one monolithic function spanning constructor, paint, mouse/timer, region helpers, dispatcher, update, and reset. The marker records that the aggregate is documentation/output routing only.
- Inferred source-facing names/types/fields used: `ScrollInventoryPane`, UID0000CK, exact child method pages; no new source variable names are introduced by the marker.
- Naming/coding style convention: comment-only marker follows existing project covered/no-standalone marker practice and avoids decompiler labels.
- Reason code should remain blank except the marker: UID0001GZ's own memory range is an aggregate over children; by-memory policy forbids pasting child source into the aggregate.
- Exact no-code proof: current MCP and docs prove the range contains multiple functions/raw helpers and exact child pages; B003 already emits UID0001H1 and explicitly rejects merging child C++ into UID0001GZ.

## Final Recommendation
- Exact changes applied: set UID0001GZ to `COMPLETION:86`, `CONFIDENCE:90`; kept owner/reconstructable/emitter fields; replaced stale unassigned summary; added `aa3930bd` evidence block; inserted the formal marker-only no-standalone-body comment.
- Exact parent assignments implemented: direct owner/emitter remains UID0000CK; file route remains UID0000KB; NewInventoryPane remains fold candidate only.
- Exact items left no-owner/non-emitting and why: none for UID0001GZ. It should remain emitting, but marker-only. No support page should be made no-owner/non-emitting as part of this target.
- Exact future work outside this assignment scope: any UID0001H0 follow-up should remain with B008 or a coordinated supervisor callback; current generated output already includes B008's UID0001H0 `UpdateFromDrag` body. Raw setter/highlight/drag helper exact child splits can be future work if needed; final file fold into NewInventoryPane remains a later source-tree decision.

## Recommended Target Doc Changes
- Target path: `by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md`
- Exact report facts incorporated: MCP session `aa3930bd` health/provenance, function inventory, raw starts, constructor one-caller evidence, `272` allocation/caller context, vtable refs, UID0001H0 xrefs, UID0001H1 no-xref state, bytes/padding, pre-callback generated Empty Emitter Marker state, B007-generated marker-only state after validation, current B008-generated UID0001H0 output state, and B003 non-merge warning.
- Metadata/score/owner/emitter/reconstructable/C++ changes applied: `COMPLETION:86`, `CONFIDENCE:90`, kept `CANONICAL_OWNER:0000CK`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CK`, blank optional position, inserted formal marker-only block from `## First-Draft C++ Recommendation`.
- Historical/stale assumptions, rejected alternatives, and negative evidence preserved: historical parent-blocker text was rewritten as stale/superseded rather than current truth; final source-file fold caveat, B007's no-edit boundary for B008-owned UID0001H0, UID0001H1 no-route caveat, and rejected NewInventoryPane/generic ScrollBar/no-owner/broad-body alternatives remain.

## Recommended Support Doc Changes
- `by-class/ScrollInventoryPane.md`: B007 updated UID0001GZ score/status to `86/90` marker-only aggregate, clarified that UID0001GZ has no standalone class body while exact child pages emit through the class, and preserved UID0001H1 source-ready state plus B008 ownership boundary for UID0001H0. Current generated output now supersedes the historical UID0001H0 empty-marker state with B008 `UpdateFromDrag` C++.
- `by-file/InventoryScrollPane.md`: updated generated/source-output notes so UID0001GZ is marker-only through UID0000CK/UID0000KB and no longer blank solely because of old parent blockers. Standalone-vs-folded caveat remains.
- `by-memory/0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw.md`: support-sync only; rewrote the stale Item Summary phrase to reflect direct class owner/emitter UID0000CK, formal C++ already present, and raw no-route caveat retained. No metadata or C++ change was made by B007 in this callback.
- `by-memory/0x00564520-0x005646ad.ScrollInventoryPaneUpdateFromDrag.md`: already-present/currently superseded by B008. B008 owns UID0001H0 work, current generated output emits `ScrollInventoryPane::UpdateFromDrag`, and this B007 repair does not change UID0001H0 source/C++.
- `by-type/by-struct/ScrollInventoryPaneLayout.md`, `by-type/by-vtable/ScrollInventoryPaneVtables.md`, and `by-memory/0x00624028-0x006240b0.ScrollInventoryPaneVtableData.md`: already present at same-or-greater detail for UID0001GZ field/vtable facts; no edit needed.
- Generated reports and generated C++: not edited manually. B007 scoped validators refreshed generated `auto-generated/NexusTK/ui/inventory/InventoryScrollPane.cpp` to validator command `000000006077`; current generated output after later B008 work is command `000000006093`.

## Score And Metadata Recommendation
- Historical pre-callback score/metadata: `85/89`, owner/emitter UID0000CK, reconstructable true, blank formal C++.
- Current implemented score/metadata: `86/90`, same owner/reconstructable/emitter/blank optional position, formal marker-only block.
- Score rationale and reason not higher/lower: completion was raised because current MCP evidence and marker-only policy resolved the stale unassigned/current-output blocker; confidence was raised because `aa3930bd` confirmed the same owner/boundary/caller/vtable facts. Do not raise above `86/90` because this is still an aggregate with unresolved exact source split, raw helper islands are not all exact child pages, and UID0001H1 has raw no-route caveat. UID0001H0's earlier formal-source gap was later cleared by B008 and is not a current score cap in this repaired report.
- Score-improvement attempt: parent blockers were rechecked and are stale; owner/emitter already valid; generated empty state was checked; child-source blocker was narrowed to B008-owned UID0001H0 during the B007 callback and then superseded by B008 generated output; no broad body is safe under by-memory policy.
- Metadata fields changed or left unchanged: changed only completion/confidence and formal C++ marker; left owner/reconstructable/emitter/position unchanged.

## Open Questions With Attempted Resolution
- Open question: standalone `InventoryScrollPane.cpp` versus folded `NewInventoryPane.cpp`.
- Evidence checked: one constructor caller, NewInventoryPane allocation/store, by-file routes, proposed source tree, generated output.
- Best supported resolution: keep current standalone companion route UID0000KB; preserve fold caveat only.
- Historical unresolved question now superseded: UID0001H0 final C++ and exact method name were outside B007 callback scope because B008 owned that target.
- Evidence checked: B007 MCP callers/callees/decompile, B008 active goal at the time of callback, UID0001H0 page, and current generated `InventoryScrollPane.cpp` command `000000006093`.
- Best supported resolution: treat UID0001H0 as related but outside B007 authorship; current generated output now uses `ScrollInventoryPane::UpdateFromDrag(int localX, int localY)` from B008, so it is no longer a current generated-output/source-ready blocker for UID0001GZ.
- Remaining unresolved question: exact original names for `+0xfa` and some geometry locals.
- Evidence checked: constructor/update/layout docs and decompile.
- Best supported resolution: do not invent names in UID0001GZ marker; preserve current descriptive layout caveats.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text
- Not applicable for this report. The stale by-memory auto coverage/tracker state was validator-owned generated output, and scoped validators handled the registry/stats/generated refresh side effects. B007 did not manually edit `auto-generated/-ag-coverage-report-by-memory.md`, tracker files, or coverage reports.

## Follow-Up Actions
- Supervisor actions: lifecycle/audit/execution handling is external to this report and remains supervisor-owned.
- A-agent actions: none required.
- B007 boundary after callback: stop before `execute_report`; do not modify UID0001H0 unless the supervisor sends a separate coordinated callback.

## Confidence
- Recommendation confidence: high for marker-only target disposition and current owner/emitter route.
- Score confidence: medium-high; `86/90` is conservative for a broad aggregate.
- Remaining uncertainty: source-file fold and broader raw helper child coverage remain open, but neither blocks the UID0001GZ marker-only fix. UID0001H0's final source body is now present in current generated output through B008.

## Validator Results
- Scoped validator commands run from `source-3/project-documentation`:
  - `python .\tools\validator.py --mode file --file by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md --apply --queue-timeout 240` -> command_id `000000006069`, command_timestamp `2026-07-04T04:21:22-04:00`, exit code `0`, `ok: 1`; reported `autogen_registry_update: 2`, `completion_update: 1`, `confidence_update: 1`, `stats_row_remove: 1`, `projected_stats_update: 1`, `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-class/ScrollInventoryPane.md --apply --queue-timeout 240` -> command_id `000000006072`, command_timestamp `2026-07-04T04:21:37-04:00`, exit code `0`, `ok: 1`; reported `stats_row_update: 4`, `projected_stats_update: 1`, `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-file/InventoryScrollPane.md --apply --queue-timeout 240` -> command_id `000000006074`, command_timestamp `2026-07-04T04:21:48-04:00`, exit code `0`, `ok: 1`; reported `stats_incremental_noop: 1`, `projected_stats_update: 1`, `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-memory/0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw.md --apply --queue-timeout 240` -> command_id `000000006075`, command_timestamp `2026-07-04T04:21:58-04:00`, exit code `0`, `ok: 1`; reported `stats_incremental_noop: 1`, `projected_stats_update: 1`, `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md --apply --queue-timeout 240` -> command_id `000000006077`, command_timestamp `2026-07-04T04:27:22-04:00`, exit code `0`, `ok: 1`; reran after a target-doc historical wording repair and reported `stats_incremental_noop: 1`, `projected_stats_update: 1`, `generated_refresh: deferred`.
- Warnings/errors: none reported by the scoped file validators. Git later warned that changed markdown files may be normalized from LF to CRLF the next time Git touches them; that was not a validator warning.
- B007 generated freshness history: after B007's final scoped target rerun, `auto-generated/NexusTK/ui/inventory/InventoryScrollPane.cpp` header recorded `validator-command-id: 000000006077`, `validator-refreshed-at: 2026-07-04T04:27:22-04:00`, `validator-refresh-source: deferred-generated-refresh`; UID0001GZ appeared as marker-only output and was not an Empty Emitter Marker.
- Current generated artifact state after later B008 work: `InventoryScrollPane.cpp` header records `validator-command-id: 000000006093`, `validator-refreshed-at: 2026-07-04T04:34:48-04:00`; UID0001GZ remains marker-only at lines 7-8, and UID0001H0 now emits `ScrollInventoryPane::UpdateFromDrag(int localX, int localY)` beginning at lines 10-11.
- Generated/tracker side effects observed from B007 scoped validators: `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-coverage-report-by-memory.md`, `auto-generated/-ag-research-tracker.md`, `project-level/-auto-completion-stats.md`, and `tools/validator.ini` changed through validator-owned refresh/state updates. Generated tracker listed UID0001GZ as `86/90`, generated memory coverage listed it as `coded`, and by-memory generated coverage listed `emits_code:true` with the new marker-summary text. Current generated C++ was later refreshed by B008 command `000000006093`; this repair reads that state but does not edit generated files.
- Validator state/lifecycle: B007 did not edit validator state and did not run `execute_report`, lifecycle, archive, registry, dry-run, or probing commands. A read-only `--queue-status` check was used only to observe deferred generated-refresh queue state while waiting for the generated file header to catch up.

## Changed Files
- Modified by this callback:
  - `by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md`
  - `by-class/ScrollInventoryPane.md`
  - `by-file/InventoryScrollPane.md`
  - `by-memory/0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw.md`
  - `tools/leaser/Agents/Agent-B007/research/0001GZ-ScrollInventoryPane-source-quality.md`
- Generated/project-level/tool-owned side effects by validator only: B007 scoped validators reported projected stats/autogen registry updates and refreshed `auto-generated/NexusTK/ui/inventory/InventoryScrollPane.cpp`, `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-coverage-report-by-memory.md`, `auto-generated/-ag-research-tracker.md`, `project-level/-auto-completion-stats.md`, and `tools/validator.ini`; B007 did not edit generated/project-level/tool-state files manually. Current generated `InventoryScrollPane.cpp` command `000000006093` is a later B008 refresh and is recorded here as current state, not as a B007 validator result.
- Renamed: none.
- Report execution: not run. B007 did not run `execute_report`, lifecycle/archive/registry commands, generated edits, coverage edits, supervisor-ledger edits, or manual report moves.
- Lease cleanup: B007 leased the four edited by-* files before editing. The later unlease command returned `Rejected[No active lease]` for each path, and the shared lease report showed no active B007 entries, so no active B007 lease remained after validation. Any later leases by other agents are outside this B007 callback.
- Report-text repair after Gate 1 failure: this report was edited in place to historicalize B007 generated header `000000006077` and record current generated header `000000006093` plus B008 UID0001H0 output. No by-* docs, generated files, project-level files, coverage reports, validator state, lifecycle/archive files, or supervisor ledgers were edited during this repair, and no validators or lifecycle commands were run during this repair.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation: completed before callback per audit `2026-07-04T04:41:00-04:00 - B007 UID0001GZ Callback Gate 1`.
- [x] Target/support docs updated during B007 callback: target `by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md`; support `by-class/ScrollInventoryPane.md`; support `by-file/InventoryScrollPane.md`; optional/stale sync `by-memory/0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw.md`. UID0001H0 source/C++ was excluded from B007 scope because B008 owns it; current generated output now shows B008's UID0001H0 body.
- [x] Current target state and actual evidence checked recorded: historical pre-callback `85/89`, owner/emitter UID0000CK, blank formal block, generated Empty Emitter Marker, and MCP `aa3930bd` function/xref/callee/byte/decompile/find-bytes evidence preserved.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: rows C-0001GZ-01 through C-0001GZ-10 now end as `applied` or `already-present`.
- [x] Metadata/score changes applied: UID0001GZ `85/89` -> `86/90`; owner/reconstructable/emitter/position retained.
- [x] Score-limiting blockers researched: stale parent gate resolved; generated Empty Emitter Marker resolved by marker implementation; UID0001H0 C++ left to B008 during B007 callback and now present in current generated output; final source split retained as confidence cap.
- [x] Owner/emitter/reconstructable handling applied: kept `CANONICAL_OWNER:0000CK`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CK`, blank `EMITTER_POSITION_OPTIONAL`.
- [x] Split/rename/new-child changes: none. Exact child pages already exist; no new split was created.
- [x] Source-placement/range/padding/reclassification facts incorporated: target and support pages record current `aa3930bd` range/padding/raw-start/vtable/caller evidence and keep aggregate as marker-only source-bearing range.
- [x] First-draft C++ or no-code proof applied: inserted exact formal no-standalone-body marker from `## First-Draft C++ Recommendation`; no child C++ was pasted and no broad aggregate body was introduced.
- [x] Third-party import directive: not applicable.
- [x] Exact target/support doc facts incorporated at report-level detail: MCP session/provenance, function inventory, raw starts, xrefs/callees, bytes/padding, B007 historical generated output, current B008-generated UID0001H0 output, stale summary replacement, rejected alternatives, and B008 coordination for UID0001H0.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: old below-gate parent blockers historicalized; NewInventoryPane direct owner, generic ScrollBar, no-owner/non-emitting, broad body, and uncoordinated UID0001H0 edits remain rejected.
- [x] Wave2/Wave3 mentions/artifacts encountered: generated/simroot labels treated only as non-authoritative leads.
- [x] Open questions documented: final file fold and exact `+0xfa` name remain; UID0001H0 first-draft C++ is now superseded by current B008 generated output.
- [x] Validators run after callback: scoped file validators `000000006069`, `000000006072`, `000000006074`, `000000006075`, and final target rerun `000000006077` completed with exit code `0` and `ok: 1`.
- [x] Generated report refresh expected: B007 validator-owned refresh removed the UID0001GZ Empty Emitter Marker from generated `InventoryScrollPane.cpp`; current generated header is now command `000000006093` after later B008 work and still contains the UID0001GZ marker.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support doc details incorporated at report-level detail.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale.
- [x] Validators run and results recorded.
- [x] Generated report refresh completed by validator or generated freshness explicitly checked.
- [x] Remaining unapplied accepted items: none. UID0001H0 is not an unapplied UID0001GZ accepted item; it was excluded from B007 authorship because B008 owns that child, and current generated output now shows B008's UID0001H0 source body.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000006114","destination_path":"executed-b-agent-research/B007/0001GZ-ScrollInventoryPane-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0001GZ-ScrollInventoryPane-source-quality.md","timestamp":"2026-07-04T04:57:06-04:00","uid":"0001GZ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
