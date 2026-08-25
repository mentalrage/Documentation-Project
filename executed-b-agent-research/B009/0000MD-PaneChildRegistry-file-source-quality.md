# 0000MD PaneChildRegistry Whole-File Source Quality
** TARGET-REPORT-UID:0000MD **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **


## Finalized Report / Current Recommendation

- Current recommendation: retain [UID:0000MD] `by-file/PaneChildRegistry.md`, [UID:0000A3] `by-class/PaneChildRegistry.md`, and [UID:0000Z2] `by-memory/0x00469180-0x004691fa.PaneChildRegistry.md` only as non-emitting compatibility warning pages. `PaneChildRegistry` is not a real source file, class, type, global, vtable, RTTI family, or resource family.
- Canonical source disposition: the aliased body at `[0x00469180,0x004691fa)` is [UID:0000Z1] `BlackHole::QueuePaneForDeferredDeletion`, owned by [UID:00000W] `BlackHole` and emitted through [UID:0000HR] `NexusTK/ui/core/BlackHole.cpp`.
- Whole-file repair: preserve the six-function BlackHole family, six exact `0xcc` pads, ten-slot vtable, RTTI, singleton storage, layout, and all callers. Replace the dated generated snapshot's invalid class/child nesting with a self-contained C++03 `BlackHole.h`, correct the pane timer-handler expression, guard `List.h`, and route `BlackHole.h` to every generated consumer.
- IDA handoff count: five applying function entities, each with three ordered public mutation calls (`rename`, `set_function_comments`, `set_repeatable_comments`), for fifteen calls total. I04 and P01-P04 require no mutation.
- No PaneChildRegistry CPP or H is recommended. The target's blank reconstruction path and owner `NONE` are correct; its score should rise because the alias disposition and real-family closure are now exhaustive.
- Accepted ordinary callback result: all 65 B009-owned claims are incorporated or disposition-verified. The BlackHole/List formal source and all 16 consumer include routes were physically reconstructed through validator command `000000024777`; one empty List H child marker discovered by readback was removed and revalidated by command `000000024778` without changing any declaration.
- Confidence: very strong for alias rejection, BlackHole ownership, ranges, behavior, caller topology, layout, vtable, global, source path, and required formal source. Only original private lexical spellings for five stripped BlackHole functions remain unrecoverable.

## Supporting Research

- Assignment authority: goal SHA256 `A194BD360D6D07964E89EB1204351DA405D79809F4E850692CA0031FEA8E0847`; report-only boundaries and target UID0000MD were followed.
- Dated documentation snapshot `2026-08-16T06:34:00.8520751Z`: target UID0000MD SHA256 `49E2C3F971B1364F3D9EC505E181F90345093426C40C31AA744F1DDECDBED66C`, 4,532 bytes/57 lines; class alias UID0000A3 SHA256 `8498504F45DAB67DC5F67890E0AAE77D5174481C9453767C1760330C897F8E91`, 3,936/53; memory alias UID0000Z2 SHA256 `B4892BCE765F9D234CF0C428FDE3C245038EC659C0A227D3616A8AF00EF9A601`, 2,485/33.
- Same snapshot: BlackHole file UID0000HR SHA256 `365AA4CF561838892ECD559D09D35A1D1E25DC71F620A44BB848D23C00CDC81F`; class UID00000W `74F5537290D734A69D9C332669F47DB225A9222B632CC3458F8DD991F4C8F485`; aggregate UID0000Z0 `08310D3380970B7A6192B7B47683487FADAE1F81B04EB31431FDF0A9DE4951EE`.
- Exact method snapshot hashes: UID0002M0 `D7ED55EFCAA8C85018EA08AB68197D81F2F7FE29A9BCB08745167629FEA2F76A`; UID0002M1 `40FB2EB279ECA79EE6822A44F6C756F5B0AD07ECBCF87C31A0B37BE90DAA6439`; UID0002M3 `A08E059E3F4A546E71FF77EF468314747DCC016A601560CC6F6A7B5B071E160B`; UID0000Z1 `C0BC8F6E19C31611696461D986FCC776B3228E399487B78D872DB5904C8D3099`; UID0002M4 `BA99CB4022610F3A38EE4B068B538A355B4D71BB03BE2F685CCAB2ECD0E02EFA`; UID0002M2 `8657374D11C537A33E98FDEF4AAA712C4A2E2992E16236A0B536FEF10CBCA112`.
- Data/type snapshot hashes: UID0000Q8 `60DB6A5EF4148D13916E0B5FC66D07F74857F5B35F8DCA5922131114F83C1966`; UID00028K `378D0CE78382EDE17F3B5A3B95C8271B14D4FF66532195578FB572B1801C3B77`; UID0001TT `7B300E134FB483D9C28C25266FF6E47A37208DF5D1E8D4F4C32E4A66B71E35DE`; UID0001X2 `50B2A8D0ECCC8B8D36D04708A2320B32D2DC5B8041048CBF52D3917023F1E93E`; List class UID000079 `9C69E4F370A64A0F15217DB58D2A8BC74D62691DC088E6811EB6888421FD2011`.
- Matching executed reports were rechecked as leads: B011 BlackHole report SHA256 `9ABC04B54A8FB4BB398CB2C49933374653350B814F11054128992022CA0A7B45`; B002 BlackHole aggregate report SHA256 `6D1B64FE7002DEBE41DEC913B9D8E77912111C32AF1E409E2A2C62F3B4D1C66B`. Their ownership conclusion survives; their generated-output completeness conclusion does not.
- Dated generated snapshot command `000000024682`, refreshed `2026-08-16T01:45:46-04:00`: `BlackHole.cpp` SHA256 `6CA8711E5650840504B9905AAA7528B0E1A77022D99BD53F6B522529F08ED6D6`, 3,416 bytes/90 lines; `BlackHole.h` absent; `PaneChildRegistry.cpp/.h` absent. These identities are dated observations, not permanent current authority.
- Historical report-only phase fact: before the explicit implementation callback, B009 performed no validator, generated refresh, IDA mutation, IDA save, report execution, lifecycle command, or ordinary-document edit.
- Accepted callback snapshot: 33 ordinary destinations were edited under individual short leases and scoped-validated by commands `000000024738` through `000000024770`; List was narrowly corrected/revalidated by `000000024778`. Owning-route waited refresh `000000024777` and the subsequent List incremental refresh produced the physically reread artifacts recorded in Section 31.

## Target

- Primary target: [UID:0000MD] `by-file/PaneChildRegistry.md`.
- Additional target UIDs: none. All other UIDs are deeply researched support destinations and do not receive additional-target coverage credit from this report.
- Original assignment queue snapshot: `86/88`, path `NONE`, owner `NONE`, blank reconstructability tracker field, direct/additional reports `0/0`.
- Hypothesis tested: PaneChildRegistry might be a real source family hidden behind stale docs. Result: rejected by complete negative symbol/type/data/source/output evidence and positive BlackHole evidence.
- Real code family examined: `[0x004690b0,0x00469290)` with source functions through `0x00469288`, exact padding through `0x00469290`, BlackHole vtable `[0x00613118,0x00613140)`, RTTI records, singleton storage `0x0067a74c`, and every direct caller of the aliased method.

## Current Target State

- UID0000MD is `94/97` with path `NONE` and owner `NONE`; its body is a non-emitting compatibility warning with complete negative proof and the full real-family redirect. UID0000A3 and UID0000Z2 remain `-1/-1`, owner `NONE`, non-reconstructable, emitter blank, and formal CPP/H blank.
- UID0000HR/UID00000W now own the complete `NexusTK/ui/core/BlackHole.cpp`/`.h` route. Formal CPP uses top-level children; formal H is guarded and self-contained; UID0000Z1 uses `static_cast<TimerHandler *>(pane)`; UID000079 List H is guarded and has no empty H child marker.
- The six BlackHole children, six pads, singleton global/storage, layout, and vtable pages carry the accepted scores, exact caller/xref inventories, ownership, compiler dispositions, and formal source without losing prior research.
- All 16 consumer owner fragments include the exact relative BlackHole header once before first use. FrameChrome uses `g_pApplicationCleanupQueue`; consumer scores and unrelated formal source are unchanged.
- Dated physical snapshot `2026-08-16T04:54:31-04:00`, command `000000024777`: BlackHole CPP/H and all 16 consumers carry the accepted source/include routes. Dated List snapshot `2026-08-16T04:56:36-04:00`, command `000000024778`: one guard pair, all declarations preserved, and zero unresolved child tokens.
- PaneChildRegistry CPP/H remain absent. Manual coverage and supervisor-owned IDA rows remain outside B009's callback scope.
- Current lifecycle state is intentionally not asserted in ordinary prose. The report artifact path and supervisor-owned validator metadata govern review/execution/archive state.

## Executive Recommendation

- Retain the three PaneChildRegistry pages as searchable warnings; do not delete paths that preserve old links.
- Route all source ownership to UID0000HR/UID00000W and all exact function ownership to UID0002M0, UID0002M1, UID0002M3, UID0000Z1, UID0002M4, and compiler-covered UID0002M2.
- Preserve the implemented UID00000W CPP preamble/top-level children and complete guarded H/global extern.
- Preserve UID0000Z1's `static_cast<TimerHandler *>(pane)` call to `TimerMgr::RemovePendingTimersForOwner`.
- Preserve UID000079's C++03 include guard and all existing List declarations; the empty H child marker is deliberately absent because validator readback proved it emitted invalid placeholder text.
- Preserve exact BlackHole header visibility at the earliest formal CPP owner for all 16 non-BlackHole generated consumers and the corrected FrameChrome global spelling.
- Preserve IDA bytes, ranges, frames, current raw ABI types, vtable, RTTI, xrefs, globals, and unrelated successor identities. Supervisor-owned IDA scope is five applying entities and fifteen ordered calls: five pure renames, five regular function-comment writes, and five repeatable function-comment writes. I04 is already exact.

## Supervisor Active Recheck

- Historical original-research attestation `2026-08-16T06:27:39.138544Z`/worker `2026-08-16T06:27:39.256758Z`: `ok:true`, session `supervisor_uid0000li_i37rollback2_20260816`, canonical `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, listener PID `14320`, redirector PID `13544`, worker PID `15484`.
- Fresh repair-cycle attestation `2026-08-16T07:59:41.471831Z`/worker `2026-08-16T07:59:41.593893Z`: `ok:true`, session `supervisor_uid0000kb_i15rollback4_20260816`, same canonical path, listener PID `14320`, redirector PID `13896`, worker PID `21808`. Fresh `server_health` returned `status:ok`, imagebase `0x400000`, Hex-Rays ready, strings cache ready/2068, and `auto_analysis_ready:false`; all bounded reads succeeded.
- Read-only endpoints used: `idb_list`, `runtime_attestation`, `server_health`, `lookup_funcs`, `inspect_items`, `get_comments`, `stack_frame`, `xref_query`, `analyze_batch`, `type_inspect`, `entity_query`, and `get_bytes`.
- Fresh live recheck covered all six functions, all six pads, successor `0x469290`, all 83 aliased-method calls, every vtable/boundary head, both singleton items, the TimerMgr projection, local types, bytes/hashes, comments, frames, and complete directional xrefs. All five desired function names returned `Not found`, proving no current collision.
- Installed public schemas were independently rechecked: `set_function_comments` writes FR only, while FP requires the separate `set_repeatable_comments` endpoint. The five applying entities therefore require fifteen ordered calls, not ten.
- No mutation endpoint, process-control endpoint, or save endpoint was used.

## Inference Research Guidance Check

- Evidence order: exact boundaries/bytes/xrefs and RTTI; function behavior and call topology; data/type/vtable relationships; current docs/generated output; then descriptive source naming.
- The stale alias was not accepted from prose. It was retested against names, globals, types, RTTI, vtables, callers, callees, neighboring code/data, output paths, and source-tree routes.
- Broad call fan-in is consumer evidence, not owner evidence. Ownership is established by BlackHole constructor/destructor/global/vtable/RTTI/list behavior and the fact that the helper operates on the BlackHole receiver.
- Source-facing names for stripped functions remain descriptive inferences. Exact ranges, ABI prestates, bytes, and behavior are original-proof facts.
- No Wave2/Wave3 assumptions were used.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence | Resolution |
| --- | --- | --- |
| Real PaneChildRegistry family? | Zero PaneChildRegistry function/global/name/type/RTTI/vtable/resource/output hits; exact body receiver is `BlackHole *`; all nearby class identities are BlackHole. | No real family. Retain compatibility warnings only. |
| BlackHole or Pane owner? | Method scans `this+0xc`, invokes List slots `+0x10/+0x18`, and shares global/vtable/lifecycle with the five sibling BlackHole functions. Pane is only the argument. | BlackHole owns the method; Pane is a consumed type. |
| Application owner? | Application constructs and destroys the object, but Motion and 83 pane/dialog paths consume it; RTTI names BlackHole. | Application is lifecycle consumer, not source owner. |
| Separate PaneChildRegistry.cpp? | No extra code/data/type and no generated output; proposed source tree already routes BlackHole under `ui/core`. | Reject separate CPP/H. |
| Headerless BlackHole? | Seventeen TUs use methods/global, no TU includes a declaration, and current BlackHole CPP needs its own class/global declarations before child definitions. | A guarded `BlackHole.h` is mandatory. |
| Dated class-emission snapshot | Child definitions occurred inside class braces. | Class CPP becomes includes plus top-level children; class declaration moves to H. |
| Timer-handler spelling | IDA passes `pane+0xa4`; `Pane` publicly derives `TimerHandler`; generated Pane has no `m_timerHandler` member. | Use `static_cast<TimerHandler *>(pane)`. |
| List header safety | BlackHole H includes List H; generated List H has no guard. | Guard List H while preserving declarations. |
| Singleton/global shape | RTTI proves `Singleton<BlackHole>`; storage is a separately emitted pointer used by many TUs. | Keep inheritance plus one `extern` in H and one definition in CPP. |
| Compiler artifacts | Scalar deleting destructor and RTTI/vtable arise from declarations. | No handwritten scalar/RTTI/vtable source body. |
| Current raw IDA types | Five stripped functions have mechanically valid but source-poor ABI projections. Type application can alter frame state and is unnecessary for source fidelity. | Final IDA disposition is pure rename plus distinct FR/FP comment endpoints only; formal H/CPP owns source types. |
| Original spellings | No symbols/debug data remain for five stripped names. | Use behavior-derived names and cap confidence below symbol certainty. |

No unresolved blocker affects ownership, source placement, reconstructability, formal CPP/H, generated routing, or scores.

## Evidence Standards Used

- Original-proof: exact IDA ranges, bytes/hashes, vtable/RTTI records, global storage, direct xrefs, caller/callee sets, frame maps, and absence queries.
- Very-strong: cross-function class lifecycle, source order, List semantics, Pane inheritance adjustment, and generated consumer audit.
- Strong: descriptive source-facing names and final public global/header spelling.
- Negative proof required complete searches by UID, stale/correct name, address, source path, generated output, type catalog, entity catalog, and archived reports.
- Dated generated/tracker/coverage observations are evidence snapshots only. Supervisor gates reread then-current generated/manual artifacts.

## Evidence Checked

- Target/class/memory alias pages; BlackHole file/class/aggregate/six exact children/global/storage/layout/vtable; List, Pane, TimerHandler, TimerMgr, Singleton, source tree, manual coverage, tracker, generated CPP/H, and matching executed reports.
- Full BlackHole code span `[0x4690b0,0x469290)`, six function objects, six pad spans, successor function, all entry comments/types/frames, function body dependencies, and exact bytes.
- Complete I04 xref set of 83 calls; 49 modeled callers and three no-function code sites were reconciled independently.
- Ten vtable dwords, four vtable-address stores, scalar-dtor slot, RTTI records at `0x64254c..0x64260c` and `0x674810..0x67483c`, singleton storage at `0x67a74c`, and source boundary at `0x613140`.
- Every use of `g_pApplicationCleanupQueue`, `QueuePaneForDeferredDeletion`, `EnqueueIfMissing`, `ReleaseQueuedOwnedObjects`, and stale `g_pBlackHole` in the dated generated snapshot.
- Whole-file completeness result: one real six-function source family, one compiler wrapper, six pads, one vtable, one RTTI family, one singleton storage/global route, one layout, zero resources/statics/strings unique to PaneChildRegistry, and zero PaneChildRegistry outputs.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C0000MD-001 | 0000MD | Classify PaneChildRegistry as a stale alias with no source family. | original-proof | Zero symbols/types/RTTI/vtable/global/output; BlackHole receiver. | UID0000MD Status/Decision | incorporate | applied |
| C0000MD-002 | 0000MD | Retain UID0000MD as a non-emitting compatibility warning with path/owner `NONE`. | very-strong | Existing links and exact corrected owner route. | UID0000MD metadata/body | incorporate | applied |
| C0000MD-003 | 0000A3 | Retain class alias at `-1/-1`, owner NONE, non-reconstructable, blank emitter/formals. | original-proof | No PaneChildRegistry class/type/RTTI. | UID0000A3 metadata/body | already-present | already-present |
| C0000MD-004 | 0000Z2 | Retain exact-address alias at `-1/-1`, owner NONE, non-reconstructable, blank emitter/formals. | original-proof | Same bytes are UID0000Z1 BlackHole method. | UID0000Z2 metadata/body | already-present | already-present |
| C0000MD-005 | 0000HR | Retain `NexusTK/ui/core/BlackHole.cpp` as the canonical real source file. | original-proof | RTTI, vtable, lifecycle, full family. | UID0000HR status/role | incorporate | applied |
| C0000MD-006 | 00000W | Retain BlackHole as direct class emitter and `List`/`Singleton<BlackHole>` class. | original-proof | RTTI and constructor/vtable/layout. | UID00000W class/formals | incorporate | applied |
| C0000MD-007 | 0000Z0 | Keep the aggregate non-emitting and index the complete six-function/pad family. | very-strong | Mixed source/compiler/padding span. | UID0000Z0 inventory | incorporate | applied |
| C0000MD-008 | 0002M0 | Preserve constructor `[4690b0,4690f6)` and its source body. | original-proof | Application caller, List(4,1024), vtable/global writes. | UID0002M0 | incorporate | applied |
| C0000MD-009 | 0002M1 | Preserve ordinary destructor `[469100,469115)` and its source body. | original-proof | vtable/global clear and List dtor tail. | UID0002M1 | incorporate | applied |
| C0000MD-010 | 0002M3 | Preserve EnqueueIfMissing `[469120,469171)` and its source body. | original-proof | Motion caller, null/dedup/append behavior. | UID0002M3 | incorporate | applied |
| C0000MD-011 | 0000Z1 | Preserve QueuePaneForDeferredDeletion `[469180,4691fa)` as BlackHole source. | original-proof | 83 calls, Pane/timer cleanup, List dedup. | UID0000Z1 | incorporate | applied |
| C0000MD-012 | 0002M4 | Preserve ReleaseQueuedOwnedObjects `[469200,469233)` and its source body. | original-proof | cleanup/idle callers, virtual deletes, RemoveAll. | UID0002M4 | incorporate | applied |
| C0000MD-013 | 0002M2 | Keep scalar deleting destructor `[469240,469288)` compiler-covered with no handwritten body. | original-proof | vtable slot, delete flag, operator delete. | UID0002M2 | already-present | already-present |
| C0000MD-014 | 0000Z0 | Preserve all six literal `0xcc` pad spans and successor `0x469290`. | original-proof | Exact bytes and function boundaries. | UID0000Z0 range table | incorporate | applied |
| C0000MD-015 | 0000Q8 | Retain `g_pApplicationCleanupQueue` as BlackHole-owned global. | original-proof | 72 xrefs and constructor/destructor writes. | UID0000Q8 | incorporate | applied |
| C0000MD-016 | 00028K | Retain exact zero-initialized storage `[67a74c,67a750)`. | original-proof | Physical item/type/comment/xrefs. | UID00028K | incorporate | applied |
| C0000MD-017 | 0001TT | Retain exact BlackHole size `0x14` and List-base layout. | original-proof | constructor allocation semantics and scalar delete size. | UID0001TT | incorporate | applied |
| C0000MD-018 | 0001X2 | Retain exact ten-slot vtable `[613118,613140)`. | original-proof | Integer reads, RTTI, constructor stores. | UID0001X2 | incorporate | applied |
| C0000MD-019 | 00000W | Preserve complete BlackHole/Singleton RTTI as compiler metadata. | original-proof | 12 named RTTI/string entities. | UID00000W/UID0001X2 evidence | incorporate | applied |
| C0000MD-020 | 0000MD | Record zero PaneChildRegistry-owned resources, strings, statics, globals, or by-item entities. | original-proof | Repository and IDA negative searches. | UID0000MD inventory | incorporate | applied |
| C0000MD-021 | 0000HR | Keep source placement under `NexusTK/ui/core/`. | very-strong | Pane/EventDispatcher adjacency and broad UI consumers. | UID0000HR path | already-present | already-present |
| C0000MD-022 | 00000W | Replace invalid class-nested child emission with includes plus top-level `[[CHILDREN]]`. | original-proof | Physical generated BlackHole.cpp ordering. | UID00000W formal CPP | incorporate | applied |
| C0000MD-023 | 00000W | Emit a complete guarded C++03 `BlackHole.h`. | very-strong | Seventeen consumers and missing sibling H. | UID00000W formal H | incorporate | applied |
| C0000MD-024 | 000079 | Add one include guard around the complete existing List formal H. | very-strong | BlackHole H dependency; generated List.h unguarded. | UID000079 formal H | incorporate | applied |
| C0000MD-025 | 0000Z1 | Replace nonexistent `pane->m_timerHandler` with `static_cast<TimerHandler *>(pane)`. | original-proof | Public Pane inheritance and exact `pane+0xa4` call argument. | UID0000Z1 formal CPP/body | reject-stale | applied |
| C0000MD-026 | 0000Q8 | Declare the global once as `extern` in BlackHole H and define it once in CPP. | very-strong | Multi-TU use and current single definition. | UID00000W H / UID0000Q8 CPP | incorporate | applied |
| C0000MD-027 | 0000MD | Keep PaneChildRegistry CPP/H absent after refresh. | original-proof | No real source/type and current absence. | UID0000MD output disposition | not-applicable | excluded-with-reason |
| C0000MD-028 | 0000MD | Historicalize alias-page claims about current sidecars/generated source. | very-strong | Dated command-24682 contradicts active wording. | UID0000MD/0000A3/0000Z2 prose | incorporate | applied |
| C0000MD-029 | 0000HR | Update BlackHole docs from expected-complete output to the exact dated blocker/resolution. | original-proof | Dated generated CPP was invalid and H was absent. | UID0000HR/00000W/0000Z0 status | incorporate | applied |
| C0000MD-030 | 0000HR | Preserve proposed-source-tree BlackHole route and absence of PaneChildRegistry source. | very-strong | Existing tree already matches binary ownership. | source-tree read-only evidence | already-present | already-present |
| C0000MD-031 | 0000HR | Record the dated snapshot of all 17 generated BlackHole-consuming TUs and absence of any BlackHole include. | original-proof | Dated physical generated repository search. | UID0000HR generated audit | incorporate | applied |
| C0000MD-032 | 00000D | Add `../ui/core/BlackHole.h` before Application children. | very-strong | Application.cpp cleanup use. | by-class/Application.md formal CPP | incorporate | applied |
| C0000MD-033 | 000050 | Add `../ui/core/BlackHole.h` to FittingRoom formal CPP. | very-strong | FittingRoom.cpp pane queue use. | by-class/FittingRoomDialog.md | incorporate | applied |
| C0000MD-034 | 0000FN | Add `../ui/core/BlackHole.h` to UserListDialogPane formal CPP. | very-strong | Two UserListDialogPane.cpp uses. | by-class/UserListDialogPane.md | incorporate | applied |
| C0000MD-035 | 000099 | Add `../ui/core/BlackHole.h` to NewSayToUserMessageInputPane formal CPP. | very-strong | SayInputPanes.cpp use. | by-class/NewSayToUserMessageInputPane.md | incorporate | applied |
| C0000MD-036 | 00007O | Add `../ui/core/BlackHole.h` to MainMenuPane formal CPP. | very-strong | Two MainMenuPane.cpp uses. | by-class/MainMenuPane.md | incorporate | applied |
| C0000MD-037 | 0002QH | Add `../ui/core/BlackHole.h` before first MapPane consuming child. | very-strong | MapPane.cpp uses precede later class fragments. | UID0002QH formal CPP | incorporate | applied |
| C0000MD-038 | 0003UN | Add `../core/BlackHole.h` before first UserPane consuming child. | very-strong | Two UserPane.cpp uses. | UID0003UN formal CPP | incorporate | applied |
| C0000MD-039 | 00008R | Add `../ui/core/BlackHole.h` to Motion formal CPP. | very-strong | Motion.cpp EnqueueIfMissing use. | by-class/Motion.md | incorporate | applied |
| C0000MD-040 | 00015O | Add `BlackHole.h` and replace stale `g_pBlackHole` with `g_pApplicationCleanupQueue`. | original-proof | FrameChrome.cpp only stale global spelling. | UID00015O formal CPP | reject-stale | applied |
| C0000MD-041 | 0000A5 | Add `../core/BlackHole.h` to ParcelIconPane formal CPP. | very-strong | ParcelPane.cpp use. | by-class/ParcelIconPane.md | incorporate | applied |
| C0000MD-042 | 00004M | Add `BlackHole.h` to EventDispatcher formal CPP. | very-strong | EventDispatcher.cpp drain use. | by-class/EventDispatcher.md | incorporate | applied |
| C0000MD-043 | 00001P | Add `../core/BlackHole.h` to CharInputPane formal CPP. | very-strong | InputPanes.cpp uses. | by-class/CharInputPane.md | incorporate | applied |
| C0000MD-044 | 0000BP | Add `../core/BlackHole.h` to RankingRewardInfoDialog formal CPP. | very-strong | RankingDialog.cpp use. | by-class/RankingRewardInfoDialog.md | incorporate | applied |
| C0000MD-045 | 0000EE | Add `../core/BlackHole.h` to TargetOptionDialog formal CPP. | very-strong | TargetOptionDialog.cpp use. | by-class/TargetOptionDialog.md | incorporate | applied |
| C0000MD-046 | 00006X | Add `../core/BlackHole.h` before TargetSelectionInputPanes consumers. | very-strong | Sixteen generated calls in one TU. | by-class/ItemWhoInputPane.md | incorporate | applied |
| C0000MD-047 | 0000G2 | Add `../core/BlackHole.h` to WebBoardDialog formal CPP. | very-strong | Two WebBoardDialog.cpp uses. | by-class/WebBoardDialog.md | incorporate | applied |
| C0000MD-048 | 0000Z1 | Preserve all 83 exact direct call xrefs to `0x469180`. | original-proof | Complete analyze_batch/xref_query set. | UID0000Z1 caller inventory | incorporate | applied |
| C0000MD-049 | 0000Z1 | Preserve three no-function callers at `46e28d`,`53dd9f`,`545dd7`. | original-proof | Raw-site bounded inspection. | UID0000Z1 caller inventory | incorporate | applied |
| C0000MD-050 | 0002M0 | Preserve sole constructor caller `464549` in Application Startup. | original-proof | Directional xref. | UID0002M0 evidence | incorporate | applied |
| C0000MD-051 | 0002M3 | Preserve sole enqueue caller `53a0bc` in Motion OnTimer. | original-proof | Directional xref. | UID0002M3 evidence | incorporate | applied |
| C0000MD-052 | 0002M4 | Preserve drain callers `464c19` and `4a6c4a`. | original-proof | Directional xrefs. | UID0002M4 evidence | incorporate | applied |
| C0000MD-053 | 0001X2 | Preserve vtable routes to scalar destructor and inherited List slots. | original-proof | Exact ten dwords and stores. | UID0001X2 evidence | incorporate | applied |
| C0000MD-054 | 0000Z1 | Resolve Pane slots `+0x38/+0x40` to RemoveFromLayer/UnregisterEventHandler. | original-proof | Vtable dwords `621a20/621a28`. | UID0000Z1 behavior | incorporate | applied |
| C0000MD-055 | 0000Z1 | Resolve timer cleanup to `TimerMgr_RemovePendingTimersForOwner` with adjusted TimerHandler base. | original-proof | Call `4691aa`, global `67ab80`, argument `pane+0xa4`. | UID0000Z1 behavior/formal CPP | incorporate | applied |
| C0000MD-056 | 00000W | Preserve List count/get/append/remove-all semantics and owned virtual deletion. | original-proof | Bodies and vtable slots. | UID00000W role | incorporate | applied |
| C0000MD-057 | 0000Q8 | Preserve exact 72-xref singleton lifecycle and consumers. | original-proof | Complete bounded xref count and writers. | UID0000Q8 evidence | incorporate | applied |
| C0000MD-058 | 0000SI | Do not duplicate the prior cataloged g_pTimerMgr rename/type action from this target. | very-strong | Catalog 0141 versus current blank physical label/type projection. | IDA handoff P04 | reject-stale | excluded-with-reason |
| C0000MD-059 | 0000MD | Record exact absence of PaneChildRegistry local type, name, function, and global. | original-proof | type_inspect/entity_query. | UID0000MD negative evidence | incorporate | applied |
| C0000MD-060 | 00000W | Record the one BlackHole-named function and 13 BlackHole/global entities returned by live query. | original-proof | Entity query and RTTI. | UID00000W evidence | incorporate | applied |
| C0000MD-061 | 0002M0 | I01: apply three ordered public calls: pure rename, FR write, then FP write. | very-strong | Fresh literal prestate, collision-free desired name, and deterministic three-stage readbacks. | IDA supervisor handoff I01 | incorporate | proposed |
| C0000MD-062 | 0002M1 | I02: apply three ordered public calls: pure rename, FR write, then FP write. | very-strong | Fresh literal prestate, collision-free desired name, and deterministic three-stage readbacks. | IDA supervisor handoff I02 | incorporate | proposed |
| C0000MD-063 | 0002M3 | I03: apply three ordered public calls: pure rename, FR write, then FP write. | very-strong | Fresh literal prestate, collision-free desired name, and deterministic three-stage readbacks. | IDA supervisor handoff I03 | incorporate | proposed |
| C0000MD-064 | 0000Z1 | I04: retain already exact name/type/comments with no endpoint. | original-proof | Live exact readback. | IDA supervisor handoff I04 | already-present | proposed |
| C0000MD-065 | 0002M4 | I05: apply three ordered public calls: pure rename, FR write, then FP write. | very-strong | Fresh literal prestate, collision-free desired name, and deterministic three-stage readbacks. | IDA supervisor handoff I05 | incorporate | proposed |
| C0000MD-066 | 0002M2 | I06: apply three ordered public calls: pure rename, FR write, then FP write. | very-strong | Fresh literal prestate, collision-free desired name, and deterministic three-stage readbacks. | IDA supervisor handoff I06 | incorporate | proposed |
| C0000MD-067 | 0000Z0 | P01: protect all function ranges, frames, bytes, xrefs, and six pad spans. | original-proof | Complete endpoint/hash audit. | IDA supervisor handoff P01 | already-present | proposed |
| C0000MD-068 | 0001X2 | P02: protect every vtable head/value/xref and physical successor bytes. | original-proof | Full dword/physical-head readback. | IDA supervisor handoff P02 | already-present | proposed |
| C0000MD-069 | 00028K | P03: protect singleton storage/comment/type/xrefs and successor boundary. | original-proof | Exact item/comment/bytes/xref count. | IDA supervisor handoff P03 | already-present | proposed |
| C0000MD-070 | 0000MD | P04: do not create a PaneChildRegistry UDT or mutate BlackHole/List/Pane types. | original-proof | Negative type query and source ownership. | IDA supervisor handoff P04 | reject-invalid | proposed |
| C0000MD-071 | 00000W | Use the exact formal BlackHole CPP/H and preserve all six child dispositions. | very-strong | Complete source/dependency audit. | First-Draft C++ Recommendation | incorporate | applied |
| C0000MD-072 | 0000MD | Keep all PaneChildRegistry formal CPP/H channels blank. | original-proof | No source family or declarations. | UID0000MD/0000A3/0000Z2 formals | not-applicable | excluded-with-reason |
| C0000MD-073 | 0000MD | Raise target score from `86/88` to `94/97`. | very-strong | Exhaustive disposition and no unresolved blocker. | UID0000MD metadata | incorporate | applied |
| C0000MD-074 | 0000HR | Apply the exact canonical-family score table without changing alias `-1/-1` rows. | very-strong | Resolved source/header/output blockers. | Named family metadata | incorporate | applied |
| C0000MD-075 | 0000MD | Preserve consumer-document scores while adding only dependency includes. | very-strong | Include-only support changes. | Sixteen consumer docs | already-present | already-present |
| C0000MD-076 | 0000MD | Supply literal supervisor-owned manual coverage replacement rows. | very-strong | Current coverage rows versus resolved state. | Section 28/manual coverage | incorporate | proposed |
| C0000MD-077 | 0000MD | Treat tracker/generated identities as dated read-only evidence only. | very-strong | Mutable generated state. | Report evidence prose | incorporate | proposed |
| C0000MD-078 | 0000MD | Keep ordinary report prose lifecycle-neutral. | very-strong | Report-only workflow contract. | Whole report | already-present | proposed |
| C0000MD-079 | 0000MD | Run no validators or generated refresh during report-only research. | original-proof | Assignment boundary. | Validator Results | not-applicable | proposed |
| C0000MD-080 | 0000MD | Change only this report; declare no additional target UID and emit no terminal marker. | original-proof | Assignment scope and artifact audit. | Changed Files/checklist | already-present | proposed |

Ledger allocation after the accepted callback: `65` disposition-verified B009-owned rows and `15` supervisor/process-owned proposed rows. The proposed set is exactly C0000MD-061..070 and C0000MD-076..080.

## Positive Evidence Summary

- BlackHole identity is binary-authenticated by vtable `??_7BlackHole@@6B@`, complete-object locator/class hierarchy/base descriptors, type descriptors for `BlackHole` and `Singleton<BlackHole>`, constructor vtable/global writes, and scalar-destructor vtable routing.
- The exact alias body receives `BlackHole *this`, operates on inherited List count/data through virtual slots, and shares the same dedup/append sequence as UID0002M3.
- Pane cleanup order is exact: null guard; Pane vslot `+0x38` RemoveFromLayer; Pane vslot `+0x40` UnregisterEventHandler; TimerMgr remove-pending with the `TimerHandler` subobject at `+0xa4`; deduplicate; append.
- Constructor/destructor/drain/global evidence gives a closed lifetime: Application startup constructs; idle work drains; Application shutdown drains/deletes; destructors clear the singleton pointer.
- Source completeness is bounded: six exact functions, six exact pads, one ten-slot vtable, one RTTI family, one global/storage route, one `0x14` layout, and no unique resource or string payload.
- Repository source routing already places BlackHole in `ui/core`; the only substantive unresolved state is formal/source assembly, not ownership.

## IDA MCP Facts

- The fresh authoritative canonical session is `supervisor_uid0000kb_i15rollback4_20260816`; the earlier session is retained only as dated history under Supervisor Active Recheck. Every I01-I06/P01-P04 fact below was reconfirmed through read-only calls in the fresh session.
- Function objects and fresh raw ABI types:

| ID | Range | Current name | Current type | Frame |
| --- | --- | --- | --- | --- |
| I01 | `[4690b0,4690f6)` | `sub_4690B0` | `int __thiscall(BlackHole *this)` | `{var_4@+4:4 _DWORD,__saved_registers@+8:4 _DWORD,__return_address@+c:4 _UNKNOWN *}` |
| I02 | `[469100,469115)` | `sub_469100` | `void __thiscall(LObject *this)` | `{__return_address@+0:4 _UNKNOWN *}` |
| I03 | `[469120,469171)` | `sub_469120` | `void __thiscall(_DWORD *this, int)` | `{__saved_registers@+4:4 _DWORD,__return_address@+8:4 _UNKNOWN *,arg_0@+c:4 _DWORD}` |
| I04 | `[469180,4691fa)` | `BlackHole__QueuePaneForDeferredDeletion` | `void __thiscall(BlackHole *this, Pane *pane)` | `{__saved_registers@+8:4 _DWORD,__return_address@+c:4 _UNKNOWN *,pane@+10:4 Pane *}` |
| I05 | `[469200,469233)` | `sub_469200` | `int __thiscall(_DWORD *this)` | `{__return_address@+8:4 _UNKNOWN *}` |
| I06 | `[469240,469288)` | `sub_469240` | `LObject *__thiscall(LObject *Block, char)` | `{__saved_registers@+4:4 _DWORD,__return_address@+8:4 _UNKNOWN *,arg_0@+c:4 _DWORD}` |

- Exact body SHA256 values: I01 `17DC6F3070411D128A2597121944854710C27CC003362FF8E6D182F630967D73`; I02 `15C2D7F904D4B1171DE37E3181D4B2BEB8E931BD03A7E7651E3670CE66628D73`; I03 `F9FD134B313EE8FF1DF748F698699BF0B58100E12F66C0C37A41BB5868AD8B14`; I04 `DD7DE7E529C369AB5366BDB505209D096069D5473564C753542C816E31772A8C`; I05 `92BBACE2492A6E46041697D3835AF7AF6A129593090C3748074E7879304C3251`; I06 `FD98AE8758674D2EF50652EAAAA1F2F18014D2F4EDE77E4A0413C9B49CE56C7E`.
- Exact pad map: `[4690f6,469100)` 10 `cc`, SHA `22E52BBA61DA8AD6732BE550205A10B89A1BB3B0EA491BE07DE9294F0EB6F045`; `[469115,469120)` 11 `cc`, `3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943`; `[469171,469180)` 15 `cc`, `54CC9DD9593316E80CCAF5D10856E6502A0D75F20473A92FA01D63228EF1624C`; `[4691fa,469200)` 6 `cc`, `33CC4A00A0F04735602819132DA3E3FAC4CDEB8EC7AEE92551DC79BA8488E722`; `[469233,469240)` 13 `cc`, `0D0BB866505BC0E2D4276FCDEE1AFDC8887662D04CCE9E4BBB4C10FBA6D0F1CE`; `[469288,469290)` 8 `cc`, `3D2F424783DF5853C8D7121B1371650C04241F318E1B0CD46BEDBC805B9164C3`.
- Aggregate `[4690b0,469290)` SHA256 `5A0942E7B0F515E2AF9E973363A2C1CB33F5A4FA1923C424068804A375411BF5`; successor is function `sub_469290 [469290,469426)` and is outside BlackHole.
- I04 is the only already source-named function. AR absent; AP absent; FR exact `Detaches a pane, unregisters input and timers, and queues it once for deferred deletion.`; FP exact `void BlackHole::QueuePaneForDeferredDeletion(Pane *pane);`.
- BlackHole vtable `[613118,613140)` SHA256 `BCD22996329BA9958D432056C43417FB5978D8B6450737E4BEB44D7AB972950A`, values by head: `613118->469240`, `61311c->4f4b10`, `613120->41b6c0`, `613124->4f32a0`, `613128->4f32b0`, `61312c->4f32e0`, `613130->4f33c0`, `613134->4f33e0`, `613138->4f34a0`, `61313c->4f34b0`.
- Vtable-address incoming stores are `4690d7`, `4690eb`, `469100`, `469246`; prefix outgoing data edge is `613118->469240`. The physical successor span `[613140,613144)` is four one-byte undefined heads, bytes `84 b2 96 b1`, freshly recomputed SHA `1A6A8AE3EB37C6FD7CC05EF3E402BDFA6F2F8E4CFED85613E88422AA3E6508A0`; head `613140` is named `unk_613140`, remaining names blank, all types/comments absent, with incoming data refs `4708ed` and `47099d` and no outgoing xref.
- Singleton storage `[67a74c,67a750)` is a four-byte data item named `g_pApplicationCleanupQueue`, type `BlackHole *`, bytes `00 00 00 00`, SHA `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`, AR exact `BlackHole deferred-deletion queue singleton pointer (source-facing g_pApplicationCleanupQueue).`, AP absent, 72 incoming xrefs, no outgoing xref.
- Successor `[67a750,67a754)` is `g_pLanguageMan`, type `LanguageMan *`, bytes `00 00 00 00`, SHA `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`, AR exact `Sole externally linked LanguageMan singleton pointer. Canonical source identity is g_pLanguageMan; historical dword_67A750, DAT_0067a750, and g_pStringTable aliases are rejected.`, AP absent, 192 incoming xrefs, and no outgoing xref; no proposed endpoint touches either data item.
- Pane vtable cell `621a20` points to `544ce0 Pane_RemoveFromLayer`; cell `621a28` points to `544d70 Pane_UnregisterEventHandler`.
- Timer callee `597a10` is `TimerMgr_RemovePendingTimersForOwner`, type `void __thiscall(TimerMgr *this, TimerHandler *owner)`, with target call at `4691aa`. Global address `67ab80` is a one-byte undefined physical head with blank physical name, a four-byte semantic `TimerMgr *` projection, bytes `00 00 00 00`, AR absent, AP absent, 125 incoming data xrefs, and no outgoing xref; `46919d` is this body's reference.
- `type_inspect`: `PaneChildRegistry` absent; `BlackHole` and `List` exist only as non-UDT forward identities; `Pane` is a size-248 UDT projection; `TimerHandler` is a size-4 UDT. No type mutation is recommended.
- Entity query returns one BlackHole-named function and 13 BlackHole/global entities; none contains PaneChildRegistry.

## Function / Child Inventory

| Item | Physical range | Source/compiler disposition | Owner/emitter |
| --- | --- | --- | --- |
| Constructor | `[4690b0,4690f6)` | Source `BlackHole::BlackHole()` | UID0002M0 -> UID00000W |
| Pad 1 | `[4690f6,469100)` | Alignment, no source | UID0000Z0 index |
| Ordinary destructor | `[469100,469115)` | Source `BlackHole::~BlackHole()` | UID0002M1 -> UID00000W |
| Pad 2 | `[469115,469120)` | Alignment, no source | UID0000Z0 index |
| Enqueue helper | `[469120,469171)` | Source `EnqueueIfMissing` | UID0002M3 -> UID00000W |
| Pad 3 | `[469171,469180)` | Alignment, no source | UID0000Z0 index |
| Pane adapter | `[469180,4691fa)` | Source `QueuePaneForDeferredDeletion` | UID0000Z1 -> UID00000W |
| Pad 4 | `[4691fa,469200)` | Alignment, no source | UID0000Z0 index |
| Drain helper | `[469200,469233)` | Source `ReleaseQueuedOwnedObjects` | UID0002M4 -> UID00000W |
| Pad 5 | `[469233,469240)` | Alignment, no source | UID0000Z0 index |
| Scalar deleting destructor | `[469240,469288)` | Compiler-generated from virtual destructor; no body | UID0002M2 -> UID00000W |
| Pad 6 | `[469288,469290)` | Alignment, no source | UID0000Z0 index |
| Vtable | `[613118,613140)` | Compiler-generated ten-slot table | UID0001X2 -> UID00000W |
| RTTI | `64254c..64260c`, `674810..67483c` | Compiler-generated BlackHole/Singleton records | UID00000W |
| Singleton global/storage | `[67a74c,67a750)` | One source definition and one H extern | UID0000Q8/UID00028K -> UID0000HR |
| Layout | size `0x14` | List primary base; Singleton empty-base relationship | UID0001TT -> UID00000W |
| PaneChildRegistry aliases | UID0000MD/0000A3/0000Z2 | Warning/index only; no source/formal/output | owner/emitter NONE |

Resources/imports: no BlackHole-unique resource, string, import wrapper, file static, or constant table was found. `1024`, pointer element size `4`, delete flag `1`, vtable addresses, and `Pane+0xa4` are code constants, not separate source objects.

## Direct Xref / Caller Inventory

- I01 incoming `{464549 code}` from `Application__Startup`; I02 incoming absent; I03 incoming `{53a0bc code}` from `Motion_OnTimer`; I05 incoming `{464c19,4a6c4a code}`; I06 incoming `{613118 data}`.
- I04 exact 83-call set:

`41c58c,45215e,458a5a,45ddb8,46ad71,46d39b,46e28d,46e921,49dad7,4a0670,4a0ee1,4a1012,4a1575,4b73c6,4f1c81,4f2060,4f2076,4f2614,4f2657,4f26e1,4f271b,4f2747,4f2982,4f2d31,4f2e27,4f2e3d,4f2ef7,4f2f0d,4f7c7e,4f8a9a,4f9212,504862,5048d0,5048e1,5048f2,504917,504931,504942,504953,50496d,50497e,50498f,5049a0,5049b1,5049d0,504a13,504a24,504a3e,504a4f,504a60,504a8b,504b86,53dd9f,53dfcb,53e94d,53ed5d,53f14d,53f90b,53fe71,542098,542519,5446a7,545241,545dd7,5460bb,546f92,59dadc,59e6ec,5aad16,5aae89,5ae843,5ae959,5ae9e2,5af146,5af23c,5af7a6,5af7f2,5afc3c,5afecc,5b0095,5b04bc,5b0758,5b1cb2`.

- These resolve to 49 modeled caller functions: `41c310,451c90,458a10,45dda0,46ad40,46d360,46e8f0,49dad0,4a0580,4a0e70,4a0fc0,4a1500,4b73b0,4f1c00,4f2010,4f25a0,4f2920,4f2cd0,4f2dd0,4f2ea0,4f7a10,4f7d10,4f91c0,5047f0,504b70,53ddb0,53e8f0,53ecf0,53f0a0,53f830,53fdc0,541fa0,5424b0,544690,545220,546070,546f40,59da90,59e3d0,5aac80,5ae730,5af050,5af710,5afa10,5afe70,5b0010,5b0290,5b06f0,5b1c40`.
- Three callsites are outside function objects: `46e28d` in raw WebBoardDialogOld teardown `[46e260,46e294)`, `53dd9f` in raw tail code around `[53dd80,53dda5)`, and `545dd7` in raw tiny thunk `[545dd0,545ddc)`.
- Direct target callee: `597a10`; virtual calls resolve through Pane `+0x38/+0x40` and List `+0x10/+0x18`. I01 calls List ctor `4f3060`; I02 tail-calls List dtor `4f30e0`; I05 uses virtual GetElementAt/delete/RemoveAll; I06 calls `4f30e0`, `4f4ac0`, and guard `41b6a0`.
- The breadth proves shared deferred-deletion service use. It does not create 83 ownership claims or a PaneChildRegistry owner.

## Documentation Evidence And IDA Status

- UID0000MD, UID0000A3, and UID0000Z2 preserve the stale name, point at BlackHole, use lifecycle-neutral dated generated wording, and carry the complete no-source/real-family closure.
- UID0000HR/UID00000W/UID0000Z0 and all six exact children preserve prior behavioral research and now carry the accepted guarded H/top-level CPP assembly, corrected timer-base expression, exact score table, and compiler dispositions.
- UID0000Q8/UID00028K, UID0001TT, and UID0001X2 preserve global/layout/vtable ownership and incorporate the fresh physical readback, exact 72-xref inventory, declaration placement, and boundary protection.
- UID000079 preserves every List declaration under one guard. Physical command-24777 readback exposed a literal empty-child placeholder from the accepted H marker; B009 removed only that marker, revalidated command `000000024778`, and reread a token-free guarded List H.
- Sixteen consumer owner fragments preserve all unrelated source/scores and supply one exact BlackHole include before first use; physical readback found no stale `g_pBlackHole` and no consumer-local `class BlackHole` definition.
- At B009's dated manual-coverage snapshot, UID0000MD was misclassified as reconstructable and the BlackHole family was understated; exact supervisor-owned replacement text is in Section 28.
- Dated tracker rows show UID0000MD uncovered at `86/88`, while BlackHole has prior report coverage. Tracker state is generated and not edited here.
- IDA current state is partially source-labeled only at I04/global/vtable/RTTI. Five applying entities are safe through fifteen ordered calls: pure rename, FR write, then FP write for each; source types remain formal-source concerns.

## Ranked Ownership Analysis

| Rank | Candidate | Evidence for | Evidence against | Disposition |
| --- | --- | --- | --- | --- |
| 1 | BlackHole | Receiver, List state, six-function family, vtable, RTTI, singleton global, lifecycle, exact docs. | Five stripped lexical names only. | Canonical owner/source. |
| 2 | Pane | Pane argument and two virtual cleanup calls. | Receiver is not Pane; queue state/global/RTTI are BlackHole. | Consumed type only. |
| 3 | Application | Constructs/destroys queue. | Broad independent consumers and named BlackHole RTTI. | Lifecycle consumer only. |
| 4 | EventDispatcher/TimerMgr | Cleanup dependencies. | Neither owns queue/list/global/vtable. | Dependencies only. |
| 5 | PaneChildRegistry | Historical generated owner-context name. | No binary/source/type/output identity; exact body is BlackHole. | Rejected stale alias. |

Best forced candidate if BlackHole were disallowed would be Pane because the adapter takes a Pane and performs Pane cleanup. That forced choice still fails receiver/state/RTTI/global evidence. No evidence would justify a PaneChildRegistry source unless a distinct symbol/type/vtable/global or non-overlapping function family is discovered; none exists in the canonical IDB or repository.

## Source Placement

- Canonical CPP: `NexusTK/ui/core/BlackHole.cpp` through UID0000HR.
- Required sibling H: `NexusTK/ui/core/BlackHole.h` through UID00000W formal H.
- Placement rationale: the service is shared UI-core lifecycle infrastructure adjacent to Pane/EventDispatcher, not an Application-private or dialog-private implementation.
- `PaneChildRegistry.cpp` and `PaneChildRegistry.h` remain absent. Warning pages have documentation identity only.
- `List.h` support edit belongs to UID000079; consumer includes belong to the earliest emitting formal CPP fragment in each affected TU.

## Range / Split / Padding / Reclassification Analysis

- Source family half-open range is `[0x004690b0,0x00469288)` plus compiler-covered scalar wrapper inside that range; alignment ends at `0x00469290`.
- Exact source children are I01-I05; I06 is compiler-generated. No broad aggregate formal body should emit.
- Six pads are independent boundaries, not function tails or source stubs.
- `0x00469180-0x004691fa` has one physical function and two documentation identities. UID0000Z1 is authoritative source child; UID0000Z2 is an ignored alias. Do not split bytes or duplicate emission.
- `0x00613118-0x00613140` is exactly ten BlackHole vtable dwords. `[0x00613140,0x00613144)` belongs to the following compiler-data family and is protected as a boundary, not absorbed.
- `[0x0067a74c,0x0067a750)` is the BlackHole singleton pointer. `[0x0067a750,0x0067a754)` is `g_pLanguageMan` and is not BlackHole data.
- Reclassification: UID0000MD coverage becomes `ignored`, not `reconstructable`; UID0000A3/UID0000Z2 remain ignored/non-reconstructable.

## Negative Evidence Summary

- No function, global, IDA name, string, type, UDT, RTTI, vtable, storage, source path, generated CPP, or generated H contains PaneChildRegistry as a real program identity.
- No unique code remains after mapping the alias range to UID0000Z1 and the containing family to UID0000Z0.
- No resource, import wrapper, file static, literal pool, or constant table requires a PaneChildRegistry file.
- No caller constructs, destroys, casts to, or stores a PaneChildRegistry object.
- No generated consumer requires a PaneChildRegistry declaration; all require BlackHole.
- Adjacency to Pane logic and historical sidecar naming are weaker than receiver/vtable/RTTI/global evidence and cannot support ownership.

## IDA Rename / Type / Comment Recommendations

Public endpoint binding for each applying entity is exactly three ordered calls: public `rename` with `batch.func`, `pure:true`, `allow_overwrite:false`, `dry_run:false`, and `stop_on_error:true`; public `set_function_comments` for FR; then public `set_repeatable_comments` for FP. The `database` argument of all three calls must be the exact supervisor-attested canonical session ID in use at Gate 2B. Five entities therefore require fifteen mutating endpoint calls: five per endpoint. I04 requires no endpoint. No `define_func`, `set_type`, address comment, local/frame, data, UDT, byte, or analysis endpoint is recommended. Preserving current raw ABI prototypes is a final safety disposition: exact source types are carried by formal CPP/H without risking frame mutation.

| ID | Classification/endpoints | Literal current prestate | Exact action | Literal deterministic expected poststate |
| --- | --- | --- | --- | --- |
| I01 | apply; `rename(pure:true)` then `set_function_comments` then `set_repeatable_comments` | function `[4690b0,4690f6)`; name `sub_4690B0`; type `int __thiscall(BlackHole *this)`; AR absent; AP absent; FR absent; FP absent; frame `{var_4@+4:4 _DWORD,__saved_registers@+8:4 _DWORD,__return_address@+c:4 _UNKNOWN *}`; bytes SHA `17DC6F3070411D128A2597121944854710C27CC003362FF8E6D182F630967D73`; incoming `{464549 code}`; entry outgoing `{4690b1 code}`; predecessor outside family; successor pad `[4690f6,469100)`. | name `BlackHole__Constructor`; FR `Construct the BlackHole deferred-deletion queue with four-byte List elements and 1024-element page capacity, install its vtable, and publish the singleton pointer.`; FP `BlackHole::BlackHole();` | function `[4690b0,4690f6)`; name `BlackHole__Constructor`; type `int __thiscall(BlackHole *this)`; AR absent; AP absent; FR `Construct the BlackHole deferred-deletion queue with four-byte List elements and 1024-element page capacity, install its vtable, and publish the singleton pointer.`; FP `BlackHole::BlackHole();`; frame `{var_4@+4:4 _DWORD,__saved_registers@+8:4 _DWORD,__return_address@+c:4 _UNKNOWN *}`; bytes SHA `17DC6F3070411D128A2597121944854710C27CC003362FF8E6D182F630967D73`; incoming `{464549 code}`; entry outgoing `{4690b1 code}`; predecessor outside family; successor pad `[4690f6,469100)`. |
| I02 | apply; `rename(pure:true)` then `set_function_comments` then `set_repeatable_comments` | function `[469100,469115)`; name `sub_469100`; type `void __thiscall(LObject *this)`; AR absent; AP absent; FR absent; FP absent; frame `{__return_address@+0:4 _UNKNOWN *}`; bytes SHA `15C2D7F904D4B1171DE37E3181D4B2BEB8E931BD03A7E7651E3670CE66628D73`; incoming absent; entry outgoing `{469106 code,613118 data}`; predecessor pad `[4690f6,469100)`; successor pad `[469115,469120)`. | name `BlackHole__Destructor`; FR `Clear the BlackHole singleton pointer and tail-call the inherited List non-deleting destructor.`; FP `BlackHole::~BlackHole();` | function `[469100,469115)`; name `BlackHole__Destructor`; type `void __thiscall(LObject *this)`; AR absent; AP absent; FR `Clear the BlackHole singleton pointer and tail-call the inherited List non-deleting destructor.`; FP `BlackHole::~BlackHole();`; frame `{__return_address@+0:4 _UNKNOWN *}`; bytes SHA `15C2D7F904D4B1171DE37E3181D4B2BEB8E931BD03A7E7651E3670CE66628D73`; incoming absent; entry outgoing `{469106 code,613118 data}`; predecessor pad `[4690f6,469100)`; successor pad `[469115,469120)`. |
| I03 | apply; `rename(pure:true)` then `set_function_comments` then `set_repeatable_comments` | function `[469120,469171)`; name `sub_469120`; type `void __thiscall(_DWORD *this, int)`; AR absent; AP absent; FR absent; FP absent; frame `{__saved_registers@+4:4 _DWORD,__return_address@+8:4 _UNKNOWN *,arg_0@+c:4 _DWORD}`; bytes SHA `F9FD134B313EE8FF1DF748F698699BF0B58100E12F66C0C37A41BB5868AD8B14`; incoming `{53a0bc code}`; entry outgoing `{469121 code}`; predecessor pad `[469115,469120)`; successor pad `[469171,469180)`. | name `BlackHole__EnqueueIfMissing`; FR `Ignore null, scan inherited List pointer entries for identity, and append the owned object pointer only when absent.`; FP `void BlackHole::EnqueueIfMissing(LObject *object);` | function `[469120,469171)`; name `BlackHole__EnqueueIfMissing`; type `void __thiscall(_DWORD *this, int)`; AR absent; AP absent; FR `Ignore null, scan inherited List pointer entries for identity, and append the owned object pointer only when absent.`; FP `void BlackHole::EnqueueIfMissing(LObject *object);`; frame `{__saved_registers@+4:4 _DWORD,__return_address@+8:4 _UNKNOWN *,arg_0@+c:4 _DWORD}`; bytes SHA `F9FD134B313EE8FF1DF748F698699BF0B58100E12F66C0C37A41BB5868AD8B14`; incoming `{53a0bc code}`; entry outgoing `{469121 code}`; predecessor pad `[469115,469120)`; successor pad `[469171,469180)`. |
| I04 | already-present; no endpoint | function `[469180,4691fa)`; name `BlackHole__QueuePaneForDeferredDeletion`; type `void __thiscall(BlackHole *this, Pane *pane)`; AR absent; AP absent; FR `Detaches a pane, unregisters input and timers, and queues it once for deferred deletion.`; FP `void BlackHole::QueuePaneForDeferredDeletion(Pane *pane);`; frame `{__saved_registers@+8:4 _DWORD,__return_address@+c:4 _UNKNOWN *,pane@+10:4 Pane *}`; bytes SHA `DD7DE7E529C369AB5366BDB505209D096069D5473564C753542C816E31772A8C`; incoming exact set `{41c58c,45215e,458a5a,45ddb8,46ad71,46d39b,46e28d,46e921,49dad7,4a0670,4a0ee1,4a1012,4a1575,4b73c6,4f1c81,4f2060,4f2076,4f2614,4f2657,4f26e1,4f271b,4f2747,4f2982,4f2d31,4f2e27,4f2e3d,4f2ef7,4f2f0d,4f7c7e,4f8a9a,4f9212,504862,5048d0,5048e1,5048f2,504917,504931,504942,504953,50496d,50497e,50498f,5049a0,5049b1,5049d0,504a13,504a24,504a3e,504a4f,504a60,504a8b,504b86,53dd9f,53dfcb,53e94d,53ed5d,53f14d,53f90b,53fe71,542098,542519,5446a7,545241,545dd7,5460bb,546f92,59dadc,59e6ec,5aad16,5aae89,5ae843,5ae959,5ae9e2,5af146,5af23c,5af7a6,5af7f2,5afc3c,5afecc,5b0095,5b04bc,5b0758,5b1cb2 code}`; entry outgoing `{469181 code}`; predecessor pad `[469171,469180)`; successor pad `[4691fa,469200)`. | none | function `[469180,4691fa)`; name `BlackHole__QueuePaneForDeferredDeletion`; type `void __thiscall(BlackHole *this, Pane *pane)`; AR absent; AP absent; FR `Detaches a pane, unregisters input and timers, and queues it once for deferred deletion.`; FP `void BlackHole::QueuePaneForDeferredDeletion(Pane *pane);`; frame `{__saved_registers@+8:4 _DWORD,__return_address@+c:4 _UNKNOWN *,pane@+10:4 Pane *}`; bytes SHA `DD7DE7E529C369AB5366BDB505209D096069D5473564C753542C816E31772A8C`; incoming exact set `{41c58c,45215e,458a5a,45ddb8,46ad71,46d39b,46e28d,46e921,49dad7,4a0670,4a0ee1,4a1012,4a1575,4b73c6,4f1c81,4f2060,4f2076,4f2614,4f2657,4f26e1,4f271b,4f2747,4f2982,4f2d31,4f2e27,4f2e3d,4f2ef7,4f2f0d,4f7c7e,4f8a9a,4f9212,504862,5048d0,5048e1,5048f2,504917,504931,504942,504953,50496d,50497e,50498f,5049a0,5049b1,5049d0,504a13,504a24,504a3e,504a4f,504a60,504a8b,504b86,53dd9f,53dfcb,53e94d,53ed5d,53f14d,53f90b,53fe71,542098,542519,5446a7,545241,545dd7,5460bb,546f92,59dadc,59e6ec,5aad16,5aae89,5ae843,5ae959,5ae9e2,5af146,5af23c,5af7a6,5af7f2,5afc3c,5afecc,5b0095,5b04bc,5b0758,5b1cb2 code}`; entry outgoing `{469181 code}`; body dependencies `{Pane vslots +38/+40,67ab80 data,597a10 code,List vslots +10/+18}`; predecessor pad `[469171,469180)`; successor pad `[4691fa,469200)`. |
| I05 | apply; `rename(pure:true)` then `set_function_comments` then `set_repeatable_comments` | function `[469200,469233)`; name `sub_469200`; type `int __thiscall(_DWORD *this)`; AR absent; AP absent; FR absent; FP absent; frame `{__return_address@+8:4 _UNKNOWN *}`; bytes SHA `92BBACE2492A6E46041697D3835AF7AF6A129593090C3748074E7879304C3251`; incoming `{464c19,4a6c4a code}`; entry outgoing `{469201 code}`; predecessor pad `[4691fa,469200)`; successor pad `[469233,469240)`. | name `BlackHole__ReleaseQueuedOwnedObjects`; FR `Delete each non-null owned pointer through its virtual destructor, then clear every inherited List entry.`; FP `void BlackHole::ReleaseQueuedOwnedObjects();` | function `[469200,469233)`; name `BlackHole__ReleaseQueuedOwnedObjects`; type `int __thiscall(_DWORD *this)`; AR absent; AP absent; FR `Delete each non-null owned pointer through its virtual destructor, then clear every inherited List entry.`; FP `void BlackHole::ReleaseQueuedOwnedObjects();`; frame `{__return_address@+8:4 _UNKNOWN *}`; bytes SHA `92BBACE2492A6E46041697D3835AF7AF6A129593090C3748074E7879304C3251`; incoming `{464c19,4a6c4a code}`; entry outgoing `{469201 code}`; predecessor pad `[4691fa,469200)`; successor pad `[469233,469240)`. |
| I06 | apply; `rename(pure:true)` then `set_function_comments` then `set_repeatable_comments` | function `[469240,469288)`; name `sub_469240`; type `LObject *__thiscall(LObject *Block, char)`; AR absent; AP absent; FR absent; FP absent; frame `{__saved_registers@+4:4 _DWORD,__return_address@+8:4 _UNKNOWN *,arg_0@+c:4 _DWORD}`; bytes SHA `FD98AE8758674D2EF50652EAAAA1F2F18014D2F4EDE77E4A0413C9B49CE56C7E`; incoming `{613118 data}`; entry outgoing `{469241 code}`; predecessor pad `[469233,469240)`; successor pad `[469288,469290)`. | name `BlackHole__ScalarDeletingDestructor`; FR `Compiler-generated BlackHole scalar deleting destructor: restore vtable, clear singleton, destroy List, and optionally free the 0x14-byte object.`; FP `Compiler-generated from virtual BlackHole::~BlackHole(); no handwritten source body.` | function `[469240,469288)`; name `BlackHole__ScalarDeletingDestructor`; type `LObject *__thiscall(LObject *Block, char)`; AR absent; AP absent; FR `Compiler-generated BlackHole scalar deleting destructor: restore vtable, clear singleton, destroy List, and optionally free the 0x14-byte object.`; FP `Compiler-generated from virtual BlackHole::~BlackHole(); no handwritten source body.`; frame `{__saved_registers@+4:4 _DWORD,__return_address@+8:4 _UNKNOWN *,arg_0@+c:4 _DWORD}`; bytes SHA `FD98AE8758674D2EF50652EAAAA1F2F18014D2F4EDE77E4A0413C9B49CE56C7E`; incoming `{613118 data}`; entry outgoing `{469241 code}`; predecessor pad `[469233,469240)`; successor pad `[469288,469290)`. |

The ordered stage ledger below makes every intermediate state independently reachable. `PF-Ixx` is an exact immutable physical frame, not a shorthand for unknown state:

| Frame | Exact immutable state at every stage |
| --- | --- |
| PF-I01 | function `[4690b0,4690f6)`; type `int __thiscall(BlackHole *this)`; AR absent; AP absent; frame `{var_4@+4:4 _DWORD,__saved_registers@+8:4 _DWORD,__return_address@+c:4 _UNKNOWN *}`; bytes SHA `17DC6F3070411D128A2597121944854710C27CC003362FF8E6D182F630967D73`; incoming `{464549 code}`; entry outgoing `{4690b1 code}`; predecessor outside family; successor pad `[4690f6,469100)`. |
| PF-I02 | function `[469100,469115)`; type `void __thiscall(LObject *this)`; AR absent; AP absent; frame `{__return_address@+0:4 _UNKNOWN *}`; bytes SHA `15C2D7F904D4B1171DE37E3181D4B2BEB8E931BD03A7E7651E3670CE66628D73`; incoming absent; entry outgoing `{469106 code,613118 data}`; predecessor pad `[4690f6,469100)`; successor pad `[469115,469120)`. |
| PF-I03 | function `[469120,469171)`; type `void __thiscall(_DWORD *this, int)`; AR absent; AP absent; frame `{__saved_registers@+4:4 _DWORD,__return_address@+8:4 _UNKNOWN *,arg_0@+c:4 _DWORD}`; bytes SHA `F9FD134B313EE8FF1DF748F698699BF0B58100E12F66C0C37A41BB5868AD8B14`; incoming `{53a0bc code}`; entry outgoing `{469121 code}`; predecessor pad `[469115,469120)`; successor pad `[469171,469180)`. |
| PF-I05 | function `[469200,469233)`; type `int __thiscall(_DWORD *this)`; AR absent; AP absent; frame `{__return_address@+8:4 _UNKNOWN *}`; bytes SHA `92BBACE2492A6E46041697D3835AF7AF6A129593090C3748074E7879304C3251`; incoming `{464c19,4a6c4a code}`; entry outgoing `{469201 code}`; predecessor pad `[4691fa,469200)`; successor pad `[469233,469240)`. |
| PF-I06 | function `[469240,469288)`; type `LObject *__thiscall(LObject *Block, char)`; AR absent; AP absent; frame `{__saved_registers@+4:4 _DWORD,__return_address@+8:4 _UNKNOWN *,arg_0@+c:4 _DWORD}`; bytes SHA `FD98AE8758674D2EF50652EAAAA1F2F18014D2F4EDE77E4A0413C9B49CE56C7E`; incoming `{613118 data}`; entry outgoing `{469241 code}`; predecessor pad `[469233,469240)`; successor pad `[469288,469290)`. |

Each stage prestate/readback is the exact union of its named physical frame and its literal name/FR/FP tuple. The fresh collision query returned `Not found` for all five desired names before S01/S04/S07/S10/S13.

| Stage | Immediate exact prestate | Exact public call | Immediate deterministic readback |
| --- | --- | --- | --- |
| S01 I01 rename | PF-I01; name `sub_4690B0`; FR absent; FP absent. | `rename` with `batch={func:{addr:"0x4690b0",name:"BlackHole__Constructor"},pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}`. | PF-I01; name `BlackHole__Constructor`; FR absent; FP absent. Only the name changes. |
| S02 I01 FR | PF-I01; name `BlackHole__Constructor`; FR absent; FP absent. | `set_function_comments` with `items={addr:"0x4690b0",comment:"Construct the BlackHole deferred-deletion queue with four-byte List elements and 1024-element page capacity, install its vtable, and publish the singleton pointer."}`. | PF-I01; name `BlackHole__Constructor`; FR `Construct the BlackHole deferred-deletion queue with four-byte List elements and 1024-element page capacity, install its vtable, and publish the singleton pointer.`; FP absent. Only FR changes. |
| S03 I01 FP | PF-I01; name `BlackHole__Constructor`; FR `Construct the BlackHole deferred-deletion queue with four-byte List elements and 1024-element page capacity, install its vtable, and publish the singleton pointer.`; FP absent. | `set_repeatable_comments` with `items={addr:"0x4690b0",comment:"BlackHole::BlackHole();"}`. | PF-I01; name `BlackHole__Constructor`; FR `Construct the BlackHole deferred-deletion queue with four-byte List elements and 1024-element page capacity, install its vtable, and publish the singleton pointer.`; FP `BlackHole::BlackHole();`. Only FP changes. |
| S04 I02 rename | PF-I02; name `sub_469100`; FR absent; FP absent. | `rename` with `batch={func:{addr:"0x469100",name:"BlackHole__Destructor"},pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}`. | PF-I02; name `BlackHole__Destructor`; FR absent; FP absent. Only the name changes. |
| S05 I02 FR | PF-I02; name `BlackHole__Destructor`; FR absent; FP absent. | `set_function_comments` with `items={addr:"0x469100",comment:"Clear the BlackHole singleton pointer and tail-call the inherited List non-deleting destructor."}`. | PF-I02; name `BlackHole__Destructor`; FR `Clear the BlackHole singleton pointer and tail-call the inherited List non-deleting destructor.`; FP absent. Only FR changes. |
| S06 I02 FP | PF-I02; name `BlackHole__Destructor`; FR `Clear the BlackHole singleton pointer and tail-call the inherited List non-deleting destructor.`; FP absent. | `set_repeatable_comments` with `items={addr:"0x469100",comment:"BlackHole::~BlackHole();"}`. | PF-I02; name `BlackHole__Destructor`; FR `Clear the BlackHole singleton pointer and tail-call the inherited List non-deleting destructor.`; FP `BlackHole::~BlackHole();`. Only FP changes. |
| S07 I03 rename | PF-I03; name `sub_469120`; FR absent; FP absent. | `rename` with `batch={func:{addr:"0x469120",name:"BlackHole__EnqueueIfMissing"},pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}`. | PF-I03; name `BlackHole__EnqueueIfMissing`; FR absent; FP absent. Only the name changes. |
| S08 I03 FR | PF-I03; name `BlackHole__EnqueueIfMissing`; FR absent; FP absent. | `set_function_comments` with `items={addr:"0x469120",comment:"Ignore null, scan inherited List pointer entries for identity, and append the owned object pointer only when absent."}`. | PF-I03; name `BlackHole__EnqueueIfMissing`; FR `Ignore null, scan inherited List pointer entries for identity, and append the owned object pointer only when absent.`; FP absent. Only FR changes. |
| S09 I03 FP | PF-I03; name `BlackHole__EnqueueIfMissing`; FR `Ignore null, scan inherited List pointer entries for identity, and append the owned object pointer only when absent.`; FP absent. | `set_repeatable_comments` with `items={addr:"0x469120",comment:"void BlackHole::EnqueueIfMissing(LObject *object);"}`. | PF-I03; name `BlackHole__EnqueueIfMissing`; FR `Ignore null, scan inherited List pointer entries for identity, and append the owned object pointer only when absent.`; FP `void BlackHole::EnqueueIfMissing(LObject *object);`. Only FP changes. |
| S10 I05 rename | PF-I05; name `sub_469200`; FR absent; FP absent. | `rename` with `batch={func:{addr:"0x469200",name:"BlackHole__ReleaseQueuedOwnedObjects"},pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}`. | PF-I05; name `BlackHole__ReleaseQueuedOwnedObjects`; FR absent; FP absent. Only the name changes. |
| S11 I05 FR | PF-I05; name `BlackHole__ReleaseQueuedOwnedObjects`; FR absent; FP absent. | `set_function_comments` with `items={addr:"0x469200",comment:"Delete each non-null owned pointer through its virtual destructor, then clear every inherited List entry."}`. | PF-I05; name `BlackHole__ReleaseQueuedOwnedObjects`; FR `Delete each non-null owned pointer through its virtual destructor, then clear every inherited List entry.`; FP absent. Only FR changes. |
| S12 I05 FP | PF-I05; name `BlackHole__ReleaseQueuedOwnedObjects`; FR `Delete each non-null owned pointer through its virtual destructor, then clear every inherited List entry.`; FP absent. | `set_repeatable_comments` with `items={addr:"0x469200",comment:"void BlackHole::ReleaseQueuedOwnedObjects();"}`. | PF-I05; name `BlackHole__ReleaseQueuedOwnedObjects`; FR `Delete each non-null owned pointer through its virtual destructor, then clear every inherited List entry.`; FP `void BlackHole::ReleaseQueuedOwnedObjects();`. Only FP changes. |
| S13 I06 rename | PF-I06; name `sub_469240`; FR absent; FP absent. | `rename` with `batch={func:{addr:"0x469240",name:"BlackHole__ScalarDeletingDestructor"},pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}`. | PF-I06; name `BlackHole__ScalarDeletingDestructor`; FR absent; FP absent. Only the name changes. |
| S14 I06 FR | PF-I06; name `BlackHole__ScalarDeletingDestructor`; FR absent; FP absent. | `set_function_comments` with `items={addr:"0x469240",comment:"Compiler-generated BlackHole scalar deleting destructor: restore vtable, clear singleton, destroy List, and optionally free the 0x14-byte object."}`. | PF-I06; name `BlackHole__ScalarDeletingDestructor`; FR `Compiler-generated BlackHole scalar deleting destructor: restore vtable, clear singleton, destroy List, and optionally free the 0x14-byte object.`; FP absent. Only FR changes. |
| S15 I06 FP | PF-I06; name `BlackHole__ScalarDeletingDestructor`; FR `Compiler-generated BlackHole scalar deleting destructor: restore vtable, clear singleton, destroy List, and optionally free the 0x14-byte object.`; FP absent. | `set_repeatable_comments` with `items={addr:"0x469240",comment:"Compiler-generated from virtual BlackHole::~BlackHole(); no handwritten source body."}`. | PF-I06; name `BlackHole__ScalarDeletingDestructor`; FR `Compiler-generated BlackHole scalar deleting destructor: restore vtable, clear singleton, destroy List, and optionally free the 0x14-byte object.`; FP `Compiler-generated from virtual BlackHole::~BlackHole(); no handwritten source body.`. Only FP changes. |

Protection rows are no-endpoint contracts:

| ID | Classification | Literal protected prestate and identical expected poststate |
| --- | --- | --- |
| P01 | protect | I01 protected state: function `[4690b0,4690f6)`; type `int __thiscall(BlackHole *this)`; frame `{var_4@+4:4 _DWORD,__saved_registers@+8:4 _DWORD,__return_address@+c:4 _UNKNOWN *}`; bytes SHA `17DC6F3070411D128A2597121944854710C27CC003362FF8E6D182F630967D73`; incoming `{464549 code}`; entry outgoing `{4690b1 code}`; predecessor outside family; successor `[4690f6,469100)`. I02 protected state: function `[469100,469115)`; type `void __thiscall(LObject *this)`; frame `{__return_address@+0:4 _UNKNOWN *}`; bytes SHA `15C2D7F904D4B1171DE37E3181D4B2BEB8E931BD03A7E7651E3670CE66628D73`; incoming absent; entry outgoing `{469106 code,613118 data}`; predecessor `[4690f6,469100)`; successor `[469115,469120)`. I03 protected state: function `[469120,469171)`; type `void __thiscall(_DWORD *this, int)`; frame `{__saved_registers@+4:4 _DWORD,__return_address@+8:4 _UNKNOWN *,arg_0@+c:4 _DWORD}`; bytes SHA `F9FD134B313EE8FF1DF748F698699BF0B58100E12F66C0C37A41BB5868AD8B14`; incoming `{53a0bc code}`; entry outgoing `{469121 code}`; predecessor `[469115,469120)`; successor `[469171,469180)`. I04 protected state: function `[469180,4691fa)`; type `void __thiscall(BlackHole *this, Pane *pane)`; frame `{__saved_registers@+8:4 _DWORD,__return_address@+c:4 _UNKNOWN *,pane@+10:4 Pane *}`; bytes SHA `DD7DE7E529C369AB5366BDB505209D096069D5473564C753542C816E31772A8C`; incoming exact set `{41c58c,45215e,458a5a,45ddb8,46ad71,46d39b,46e28d,46e921,49dad7,4a0670,4a0ee1,4a1012,4a1575,4b73c6,4f1c81,4f2060,4f2076,4f2614,4f2657,4f26e1,4f271b,4f2747,4f2982,4f2d31,4f2e27,4f2e3d,4f2ef7,4f2f0d,4f7c7e,4f8a9a,4f9212,504862,5048d0,5048e1,5048f2,504917,504931,504942,504953,50496d,50497e,50498f,5049a0,5049b1,5049d0,504a13,504a24,504a3e,504a4f,504a60,504a8b,504b86,53dd9f,53dfcb,53e94d,53ed5d,53f14d,53f90b,53fe71,542098,542519,5446a7,545241,545dd7,5460bb,546f92,59dadc,59e6ec,5aad16,5aae89,5ae843,5ae959,5ae9e2,5af146,5af23c,5af7a6,5af7f2,5afc3c,5afecc,5b0095,5b04bc,5b0758,5b1cb2 code}`; entry outgoing `{469181 code}`; predecessor `[469171,469180)`; successor `[4691fa,469200)`. I05 protected state: function `[469200,469233)`; type `int __thiscall(_DWORD *this)`; frame `{__return_address@+8:4 _UNKNOWN *}`; bytes SHA `92BBACE2492A6E46041697D3835AF7AF6A129593090C3748074E7879304C3251`; incoming `{464c19,4a6c4a code}`; entry outgoing `{469201 code}`; predecessor `[4691fa,469200)`; successor `[469233,469240)`. I06 protected state: function `[469240,469288)`; type `LObject *__thiscall(LObject *Block, char)`; frame `{__saved_registers@+4:4 _DWORD,__return_address@+8:4 _UNKNOWN *,arg_0@+c:4 _DWORD}`; bytes SHA `FD98AE8758674D2EF50652EAAAA1F2F18014D2F4EDE77E4A0413C9B49CE56C7E`; incoming `{613118 data}`; entry outgoing `{469241 code}`; predecessor `[469233,469240)`; successor `[469288,469290)`. Pad `[4690f6,469100)`: 10-byte data item; name absent; type absent; AR absent; AP absent; FR not applicable; FP not applicable; SHA `22E52BBA61DA8AD6732BE550205A10B89A1BB3B0EA491BE07DE9294F0EB6F045`; incoming absent; outgoing absent. Pad `[469115,469120)`: 11-byte data item; name absent; type absent; AR absent; AP absent; FR not applicable; FP not applicable; SHA `3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943`; incoming absent; outgoing absent. Pad `[469171,469180)`: 15-byte data item; name absent; type absent; AR absent; AP absent; FR not applicable; FP not applicable; SHA `54CC9DD9593316E80CCAF5D10856E6502A0D75F20473A92FA01D63228EF1624C`; incoming absent; outgoing absent. Pad `[4691fa,469200)`: 6-byte data item; name absent; type absent; AR absent; AP absent; FR not applicable; FP not applicable; SHA `33CC4A00A0F04735602819132DA3E3FAC4CDEB8EC7AEE92551DC79BA8488E722`; incoming absent; outgoing absent. Pad `[469233,469240)`: 13-byte data item; name absent; type absent; AR absent; AP absent; FR not applicable; FP not applicable; SHA `0D0BB866505BC0E2D4276FCDEE1AFDC8887662D04CCE9E4BBB4C10FBA6D0F1CE`; incoming absent; outgoing absent. Pad `[469288,469290)`: 8-byte data item; name absent; type absent; AR absent; AP absent; FR not applicable; FP not applicable; SHA `3D2F424783DF5853C8D7121B1371650C04241F318E1B0CD46BEDBC805B9164C3`; incoming absent; outgoing absent. Successor function `[469290,469426)`: name `sub_469290`; type `int __thiscall(int this, wchar_t *Source)`; AR absent; AP absent; FR absent; FP absent; frame `{var_2C@+10:4 DialogPane *,Block@+14:4 void *,var_24@+18:4 DialogPane *,bounds@+1c:16 struct RectBounds,var_10@+2c:4 _DWORD,var_C@+30:4 _DWORD,var_4@+38:4 _DWORD,__saved_registers@+3c:4 _DWORD,__return_address@+40:4 _UNKNOWN *,Source@+44:4 wchar_t *,arg_4@+48:4 _DWORD}`; incoming absent; entry outgoing `{469291 code}`; predecessor `[469288,469290)`. |
| P02 | protect | Head `613118`: 4-byte data; value `469240`; name `??_7BlackHole@@6B@`; type absent; AR absent; AP absent; FR not applicable; FP not applicable; incoming `{4690d7,4690eb,469100,469246 data}`; outgoing `{469240 data}`. Head `61311c`: 4-byte data; value `4f4b10`; name absent; type absent; AR absent; AP absent; FR not applicable; FP not applicable; incoming absent; outgoing `{4f4b10 data}`. Head `613120`: 4-byte data; value `41b6c0`; name absent; type absent; AR absent; AP absent; FR not applicable; FP not applicable; incoming absent; outgoing `{41b6c0 data}`. Head `613124`: 4-byte data; value `4f32a0`; name absent; type absent; AR absent; AP absent; FR not applicable; FP not applicable; incoming absent; outgoing `{4f32a0 data}`. Head `613128`: 4-byte data; value `4f32b0`; name absent; type absent; AR absent; AP absent; FR not applicable; FP not applicable; incoming absent; outgoing `{4f32b0 data}`. Head `61312c`: 4-byte data; value `4f32e0`; name absent; type absent; AR absent; AP absent; FR not applicable; FP not applicable; incoming absent; outgoing `{4f32e0 data}`. Head `613130`: 4-byte data; value `4f33c0`; name absent; type absent; AR absent; AP absent; FR not applicable; FP not applicable; incoming absent; outgoing `{4f33c0 data}`. Head `613134`: 4-byte data; value `4f33e0`; name absent; type absent; AR absent; AP absent; FR not applicable; FP not applicable; incoming absent; outgoing `{4f33e0 data}`. Head `613138`: 4-byte data; value `4f34a0`; name absent; type absent; AR absent; AP absent; FR not applicable; FP not applicable; incoming absent; outgoing `{4f34a0 data}`. Head `61313c`: 4-byte data; value `4f34b0`; name absent; type absent; AR absent; AP absent; FR not applicable; FP not applicable; incoming absent; outgoing `{4f34b0 data}`. Exact `[613118,613140)` SHA `BCD22996329BA9958D432056C43417FB5978D8B6450737E4BEB44D7AB972950A`. Successor head `613140`: one-byte undefined; byte `84`; name `unk_613140`; type absent; AR absent; AP absent; FR not applicable; FP not applicable; incoming `{4708ed,47099d data}`; outgoing absent. Successor head `613141`: one-byte undefined; byte `b2`; name absent; type absent; AR absent; AP absent; FR not applicable; FP not applicable; incoming absent; outgoing absent. Successor head `613142`: one-byte undefined; byte `96`; name absent; type absent; AR absent; AP absent; FR not applicable; FP not applicable; incoming absent; outgoing absent. Successor head `613143`: one-byte undefined; byte `b1`; name absent; type absent; AR absent; AP absent; FR not applicable; FP not applicable; incoming absent; outgoing absent. Exact `[613140,613144)` SHA `1A6A8AE3EB37C6FD7CC05EF3E402BDFA6F2F8E4CFED85613E88422AA3E6508A0`. |
| P03 | protect | Data `[67a74c,67a750)`: width 4; name `g_pApplicationCleanupQueue`; type `BlackHole *`; AR `BlackHole deferred-deletion queue singleton pointer (source-facing g_pApplicationCleanupQueue).`; AP absent; FR not applicable; FP not applicable; bytes `00 00 00 00`; SHA `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`; incoming set `{41c585,452151,458a53,45ddb1,464c0f,464c1e,4690d0,4690e4,469106,46924c,46ad6a,46d394,46e286,46e91a,49dad1,4a0669,4a0eb8,4a0fdb,4a1548,4a6c43,4b73c0,4f1c7a,4f2059,4f206f,4f260d,4f264a,4f26da,4f2714,4f273a,4f297b,4f2d24,4f2e20,4f2e36,4f2ef0,4f2f06,4f7c77,4f8a93,4f920b,504824,504b80,53a0b2,53dd98,53dfc4,53e946,53ed56,53f146,53f904,53fe6a,542091,542512,5446a1,54523a,545dd1,5460b5,546f85,59dad5,59e6e6,5aad10,5aae83,5ae833,5ae94f,5ae9d8,5af136,5af232,5af798,5af7e4,5afc36,5afec5,5b0087,5b04b6,5b0751,5b1cab data}`; outgoing absent. Successor `[67a750,67a754)`: width 4; name `g_pLanguageMan`; type `LanguageMan *`; AR `Sole externally linked LanguageMan singleton pointer. Canonical source identity is g_pLanguageMan; historical dword_67A750, DAT_0067a750, and g_pStringTable aliases are rejected.`; AP absent; FR not applicable; FP not applicable; bytes `00 00 00 00`; SHA `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`; incoming set `{41ba58,41d6a0,464347,464411,464c2e,46c3cc,46f23f,46f8e2,471829,471bc3,471d93,471fb7,473eac,474114,476592,476864,47a15b,47a2c4,47c6a5,47c994,47e114,47e4c4,48ebc5,48ebe4,48ec06,48ec28,48ec4a,48ec6c,48ec8e,48ecb0,48ecd2,48ecf4,4a24a4,4a32a0,4a4c10,4af1d5,4afdb0,4b03b8,4cef92,4cf62e,4f0066,4f006d,4f02ef,4f03c0,4f0431,4f7152,4f8e11,4f9d66,4fa335,4fa7d6,4fc9a3,4fe712,503bf8,503c3b,50857a,513890,514848,51f55c,5204d2,52990f,52a393,52adde,52b371,52b433,52b6e0,52bb55,52ca42,52cf51,52d013,52d190,52d545,52e3b5,52e803,52ea00,52eee5,5301c2,53047f,530534,530c18,53e34d,540e21,54531c,547559,5478d8,54795c,54833b,548ca7,548e52,549066,553c39,553ce9,553dd4,553eb5,553f69,554019,554353,5544d7,568d9c,56bf01,56bff1,571d87,5864ad,5877aa,589d5a,58a9aa,58b4bf,58b5a6,5a163e,5a6168,5a61c2,5a647c,5a6517,5a65b2,5a664d,5a66af,5a6742,5a690e,5a69a9,5a6a44,5a6aec,5a6b87,5a6c2d,5a6c8f,5a729a,5a7b6f,5a93f1,5a9471,5a94fe,5a9573,5a9715,5a97f5,5a98d5,5a99b5,5a9a51,5a9b15,5a9bf5,5a9cd5,5a9db5,5a9ea2,5a9f85,5aa065,5aa101,5aa181,5aa321,5abacd,5adcc7,5ade07,5b26e7,5b2a1d,5b2b49,5b2b62,5b2d6e,5b2d87,5b2fd7,5b3227,5b3da0,5b4524,5b4854,5b4a9a,5b4b77,5b4d34,5b4ea8,5b4fe4,5b5180,5b51e3,5b52b7,5b5407,5b56a4,5b5904,5b5b37,5b5d14,5b5f34,5b6194,5b6344,5b65d4,5b67c7,5b68c7,5b6af5,5b6b80,5b6bc0,5b6c87,5b7107,5b8acf,5be034,5be0a0,5be110,5be199,5c0672,5c06bb,5c06e6,5c0711,5c0893 data}`; outgoing absent. No data endpoint is permitted. |
| P04 | reject-invalid | Type query `PaneChildRegistry`: absent. Type query `BlackHole`: forward identity present, not a UDT. Type query `List`: forward identity present, not a UDT. Type query `Pane`: UDT size 248, member `_paneBase` at `+0`. Type query `TimerHandler`: UDT size 4, member `vftable` at `+0`. No `declare_type`, `set_type`, member, frame, or UDT endpoint is permitted. Address `67ab80`: physical item is one-byte undefined head `[67ab80,67ab81)`; physical name absent; semantic type projection `TimerMgr *` over four bytes; AR absent; AP absent; FR not applicable; FP not applicable; bytes `[67ab80,67ab84)` `00 00 00 00`; SHA `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`; incoming exact set `{46919d,483fb4,494610,494812,4a6c58,4a6c63,4a6c80,4a6c8b,4a6cae,4a7120,4a903e,4aa200,4aa2ec,4e99ff,4e9be0,4e9e54,4ea015,4f63ba,4f7455,4f8f4a,507d27,50894e,50e0b9,50e20d,50eb40,50ebcc,50ebe8,50ebfa,50ec0f,50eeaf,50efe3,50ff2c,510260,51195d,511e12,512b05,512edc,5135b3,51420a,537fce,538038,538076,538ace,538c28,538d26,53a0d6,53a2e3,53aa86,53b250,53b33c,53b373,53b682,53b785,53b89f,53b905,53b93a,53ba74,53bf56,53cbad,53cc05,53cc2f,53ccfc,55b11a,55b17c,55b316,55b5eb,55b731,55b83b,566f57,567017,5670d7,568ed1,568f7d,570957,570a17,570ad7,571e41,571eed,578f33,5975a9,5975f0,597601,597617,597637,59767b,597702,597709,59779c,597fd0,5980af,5a2e56,5a373c,5a37ed,5a3840,5a502e,5a57b2,5a58c4,5a5dd1,5a5f22,5a63b3,5a6cc5,5a7be0,5a8255,5a84e7,5a86d7,5a8d1d,5a8f24,5a8f64,5a8fca,5ab194,5ab1f3,5ab2dd,5ab355,5ab36e,5ab3fa,5ab4f5,5ab568,5ab62a,5ab6a2,5ab6bb,5ab747,5abb77,5ac266,5add6d,5bd1d6 data}`; outgoing absent. No target-owned rename or duplicate catalog action is permitted. |

All proposed I actions are supervisor-owned. B009 did not mutate or save IDA.

## First-Draft C++ Recommendation

The PaneChildRegistry target/class/memory-alias formal CPP and H channels remain blank. The eligible source is the BlackHole family only.

Formal CPP for UID00000W, replacing its current class-shell CPP exactly:

```cpp
#include "BlackHole.h"
#include "Pane.h"
#include "../../util/TimerMgr.h"

[[CHILDREN]]
```

Formal H for UID00000W:

```cpp
#ifndef NEXUSTK_UI_CORE_BLACKHOLE_H
#define NEXUSTK_UI_CORE_BLACKHOLE_H

#include "../../util/List.h"
#include "../../util/Singleton.h"

class Pane;

class BlackHole : public List, public Singleton<BlackHole>
{
public:
    BlackHole();
    virtual ~BlackHole();

    void EnqueueIfMissing(LObject *object);
    void QueuePaneForDeferredDeletion(Pane *pane);
    void ReleaseQueuedOwnedObjects();
};

extern BlackHole *g_pApplicationCleanupQueue;

typedef char BlackHoleSizeMustBe20[
    sizeof(BlackHole) == 0x14 ? 1 : -1];

#endif
```

Formal CPP replacement for UID0000Z1; the other five child CPP dispositions remain byte-semantically unchanged:

```cpp
void BlackHole::QueuePaneForDeferredDeletion(Pane *pane)
{
    if (pane == NULL)
        return;

    pane->RemoveFromLayer();
    pane->UnregisterEventHandler();
    g_pTimerMgr->RemovePendingTimersForOwner(
        static_cast<TimerHandler *>(pane));
    EnqueueIfMissing(pane);
}
```

Formal H replacement for UID000079, preserving every existing declaration and adding one guard:

```cpp
#ifndef NEXUSTK_UTIL_LIST_H
#define NEXUSTK_UTIL_LIST_H

#include "LObject.h"

typedef int (__cdecl *ListCompareFunction)(const void *left,
                                           const void *right);

class List : public LObject
{
public:
    List(int elementSize, int pageSize);
    virtual ~List();
    virtual void *GetData();
    virtual void *GetElementAt(int index);
    virtual void InsertAt(int index, int count, void *source);
    virtual void Append(int count, void *source);
    virtual void RemoveAt(int index, int count);
    virtual void RemoveAll();
    virtual void SwapElements(int firstIndex, int secondIndex);
    void AssignFrom(List *source);
    void SetCount(int count);
    int GetCount() const { return m_count; }
    void Sort(ListCompareFunction compare);

protected:
    int m_elementSize;
    int m_pageSize;
    int m_count;
    void *m_data;

private:
    void ReserveElementCapacity(int elementCount);
    void ReservePageCapacity(int pageCount);
    int PageCountForElementCount(int elementCount);
};

typedef char ListSizeMustBe20[sizeof(List) == 0x14 ? 1 : -1];

#endif
```

The accepted draft's H-level `[[CHILDREN]]` marker was removed during implementation after command-24777 physical readback proved that List has no H children and the validator therefore emitted literal invalid `[[No Children Attached]]`. This is a generated-evidence correction, not a declaration loss: CPP child placement and every H declaration remain unchanged.

Exact consumer formal-CPP prefixes:

| Destination | Exact prefix/in-place correction |
| --- | --- |
| UID00000D Application | `#include "../ui/core/BlackHole.h"` before `[[CHILDREN]]` |
| UID000050 FittingRoomDialog | `#include "../ui/core/BlackHole.h"` before existing CPP |
| UID0000FN UserListDialogPane | `#include "../ui/core/BlackHole.h"` before existing CPP |
| UID000099 NewSayToUserMessageInputPane | `#include "../ui/core/BlackHole.h"` before `[[CHILDREN]]` |
| UID00007O MainMenuPane | `#include "../ui/core/BlackHole.h"` before `[[CHILDREN]]` |
| UID0002QH MapPaneExitToMenuTeardown | `#include "../ui/core/BlackHole.h"` before its bodies |
| UID0003UN UserPaneHandleServerEntryPacket | `#include "../core/BlackHole.h"` before its bodies |
| UID00008R Motion | `#include "../ui/core/BlackHole.h"` before existing CPP |
| UID00015O FramePartPane | `#include "BlackHole.h"` before existing CPP; use `g_pApplicationCleanupQueue` at the call |
| UID0000A5 ParcelIconPane | `#include "../core/BlackHole.h"` before existing CPP |
| UID00004M EventDispatcher | `#include "BlackHole.h"` before `[[CHILDREN]]` |
| UID00001P CharInputPane | `#include "../core/BlackHole.h"` before `[[CHILDREN]]` |
| UID0000BP RankingRewardInfoDialog | `#include "../core/BlackHole.h"` before existing CPP |
| UID0000EE TargetOptionDialog | `#include "../core/BlackHole.h"` before existing CPP |
| UID00006X ItemWhoInputPane | `#include "../core/BlackHole.h"` before its TargetSelectionInputPanes children |
| UID0000G2 WebBoardDialog | `#include "../core/BlackHole.h"` before `[[CHILDREN]]` |

UID0002M0, UID0002M1, UID0002M3, UID0002M4, and UID0000Q8 existing formal CPP bodies are retained. UID0002M2 remains a compiler-role comment only. Child H channels remain blank because UID00000W owns the declaration once.

## Final Recommendation

- Accept the stale-alias decision and reject any PaneChildRegistry source/header/class emission.
- Accept BlackHole as the single real source family and the exact six-item function inventory.
- Accept the implemented guarded class H, top-level child CPP assembly, List guard without an empty H child marker, corrected TimerHandler cast, singleton extern/definition split, and 16 consumer formal-CPP includes.
- Accept five supervisor-owned applying function entities through fifteen ordered calls: five pure renames, five FR writes, and five FP writes. I04 and all protection rows require no mutation.
- Accept the implemented score table and supervisor-owned manual coverage text below. No B009-owned source-quality blocker remains; supervisor IDA/manual-coverage/lifecycle rows stay unchecked.

## Recommended Target Doc Changes

- Implemented UID0000MD disposition: retained UID/path and `PROPOSED_RECONSTRUCTION_PATH:"NONE"`/`CANONICAL_OWNER:NONE`, raised score to `94/97`, stated non-reconstructability in prose, and made the warning/redirect explicit.
- Active generated/sidecar wording is historicalized as dated command-24682 evidence; no PaneChildRegistry output is expected or present in the dated post-refresh readback.
- Complete real-family inventory, ownership chain, range/split decision, negative proof, generated closure, and authoritative support links are incorporated.
- Formal CPP/H disposition remains deliberately blank, not blocked or pending.

## Recommended Support Doc Changes

- UID0000A3 and UID0000Z2 preserve metadata/formal blanks, historicalize generated-source wording, and point only to UID0000HR/00000W/0000Z1.
- UID0000HR/UID00000W/UID0000Z0 incorporate the complete inventory and exact assembly/header resolution.
- UID0002M0/0002M1/0002M3/0000Z1/0002M4/0002M2 preserve bodies/ranges/evidence and incorporate fresh prestates, callers, scores, and the corrected UID0000Z1 timer expression.
- UID0000Q8/UID00028K/UID0001TT/UID0001X2 preserve global/layout/vtable facts and incorporate exact readback/source placement.
- UID000079 has one exact guard, every declaration, and no empty H marker.
- Sixteen consumer destinations contain only the exact prefixes/correction from Section 22; unrelated formal source and scores are preserved.
- Do not edit `by-project-structure/proposed-source-tree.md`; it is already correct and is read-only support evidence.

## Score And Metadata Recommendation

| UID | Pre-callback | Implemented | Rationale |
| --- | --- | --- | --- |
| 0000MD | `86/88`, NONE/NONE | `94/97`, NONE/NONE | Exhaustive alias disposition and real-family closure. |
| 0000A3 | `-1/-1` | unchanged | Ignored compatibility class page. |
| 0000Z2 | `-1/-1` | unchanged | Ignored exact-address alias. |
| 0000HR | `89/93` | `95/97` | Complete source/header/generated route. |
| 00000W | `90/93` | `96/97` | Complete class CPP/H and exact binary identity. |
| 0000Z0 | `88/92` | `94/96` | Complete non-emitting family index. |
| 0002M0 | `88/93` | `94/96` | Exact constructor/source/IDA disposition. |
| 0002M1 | `88/93` | `94/96` | Exact destructor/source/IDA disposition. |
| 0002M3 | `89/93` | `95/96` | Exact dedup helper/source/IDA disposition. |
| 0000Z1 | `88/93` | `96/97` | Exact 83-call adapter and corrected formal dependency. |
| 0002M4 | `88/93` | `95/96` | Exact drain/source/IDA disposition. |
| 0002M2 | `88/93` | `94/96` | Exact compiler-role disposition. |
| 0000Q8 | `90/92` | `94/96` | Exact global declaration/definition route. |
| 00028K | `89/92` | `93/96` | Exact physical storage protection. |
| 0001TT | `88/93` | `94/97` | Exact layout and guarded H assertion. |
| 0001X2 | `89/93` | `94/97` | Exact table/RTTI/boundary protection. |
| 000079 | `92/91` | `93/94` | Self-contained guarded List H. |

Consumer-document scores remain unchanged because their edits are dependency visibility only.

## Open Questions With Attempted Resolution

| Question | Attempts | Resolution |
| --- | --- | --- |
| Could PaneChildRegistry be a stripped original class? | Searched all IDA names/functions/globals/types/RTTI/strings, repository docs/output, and archived reports. | No; exact body and all surrounding identities are BlackHole. |
| Could it be a file-local helper family? | Inventoried entire containing range, callers/callees, adjacent data, and source tree. | No unique helper/data remains; warning page only. |
| Should aliases be deleted? | Checked cross-document references and historical links. | Retain as non-emitting warnings to avoid broken archival links. |
| Is `g_pApplicationCleanupQueue` original spelling? | Compared current IDA, docs, singleton use, and stale `g_pBlackHole`. | Best source-facing spelling; not claimed as debug-symbol proof. |
| Is `LObject *` exact queue element type? | Constructor element size, virtual delete, Motion and Pane consumers, List docs. | Strongest common polymorphic type; behavior/layout do not depend on private typedef spelling. |
| Can `pane->m_timerHandler` be preserved? | Read Pane H/layout/type and exact `lea pane+0xa4`. | No; use public-base `static_cast<TimerHandler *>(pane)`. |
| Is a BlackHole H really required? | Audited all consumers and missing declarations in the dated generated snapshot. | Yes; 17 TUs and the owning CPP require it. |
| Can List H retain an empty child marker? | Command-24777 physical readback showed validator output `[[No Children Attached]]` in the now-included header. | No; remove only the H marker, preserve all declarations/CPP children, revalidate 24778. |
| Should current raw IDA types be replaced? | Compared source shape and known parser/frame risks. | No type endpoint; deterministic pure rename plus distinct FR/FP comment endpoints only. Formal source resolves types. |
| Any remaining score cap? | Audited ownership, split, source, header, output, callers, compiler artifacts, names. | Only unavailable original lexical spelling; confidence remains below 100. |

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Supervisor-owned manual coverage replacement payload; B009 does not edit these files:

`by-file/-coverage-report.md`

- `[UID:0000HR][BlackHole](by-file/BlackHole.md) : reconstructable : 95% : very-strong : Canonical NexusTK/ui/core/BlackHole.cpp deferred-deletion queue with complete six-function family, six exact pads, List/Singleton class shape, 0x14 layout, ten-slot vtable/RTTI, singleton global/storage, exact pane/event/timer cleanup adapter with 83 direct calls, guarded BlackHole/List headers, corrected TimerHandler base cast, complete consumer includes, and formal/generated source closure.`
- `[UID:0000MD][PaneChildRegistry](by-file/PaneChildRegistry.md) : ignored : 94% : very-strong : Non-emitting compatibility warning for a stale generated alias; live canonical IDA and complete repository research find no PaneChildRegistry source/class/type/global/vtable/RTTI/resource/output, and map the exact aliased body to BlackHole::QueuePaneForDeferredDeletion in UID0000HR.`

`by-class/-coverage-report.md`

- `[UID:00000W][BlackHole](by-class/BlackHole.md) : reconstructable : 96% : very-strong : Complete C++03 BlackHole class/header and top-level child CPP route with List and Singleton<BlackHole>, exact six-function/compiler inventory, 0x14 layout, vtable/RTTI, singleton extern/definition, corrected Pane TimerHandler adjustment, and all generated consumer declarations.`
- `[UID:0000A3][PaneChildRegistry](by-class/PaneChildRegistry.md) : ignored : 96% : very-strong : Historical compatibility alias only; no standalone class/type/RTTI/vtable/source/header exists, and authoritative behavior is BlackHole::QueuePaneForDeferredDeletion.`

`by-memory/-coverage-report.md`

- `[UID:0000Z0][0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue](by-memory/0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue.md) 0x004690b0-0x00469288 | class aggregate | BlackHoleDeferredDeletionQueue : reconstructable : 94% : very-strong : Non-emitting complete index over six exact BlackHole functions, six literal alignment pads through 0x00469290, List/Singleton ownership, vtable/RTTI, singleton storage, callers, formal source order, and compiler-artifact disposition.`
- `[UID:0002M0][0x004690b0-0x004690f6.BlackHoleConstructor](by-memory/0x004690b0-0x004690f6.BlackHoleConstructor.md) 0x004690b0-0x004690f6 | constructor | BlackHoleConstructor : reconstructable : 94% : very-strong : Exact Application startup caller, List(4,1024) construction, BlackHole vtable and singleton writes, bytes/frame/padding, formal C++, and deterministic three-stage rename/FR/FP handoff.`
- `[UID:0002M1][0x00469100-0x00469115.BlackHoleDestructor](by-memory/0x00469100-0x00469115.BlackHoleDestructor.md) 0x00469100-0x00469115 | destructor | BlackHoleDestructor : reconstructable : 94% : very-strong : Exact ordinary destructor, singleton clear, List destructor tail, bytes/frame/padding, formal C++, and deterministic three-stage rename/FR/FP handoff.`
- `[UID:0002M3][0x00469120-0x00469171.BlackHoleEnqueueIfMissing](by-memory/0x00469120-0x00469171.BlackHoleEnqueueIfMissing.md) 0x00469120-0x00469171 | class method | BlackHoleEnqueueIfMissing : reconstructable : 95% : very-strong : Exact Motion caller, null guard, List count/GetElementAt identity scan, duplicate suppression, append, bytes/frame/padding, formal C++, and deterministic three-stage rename/FR/FP handoff.`
- `[UID:0000Z1][0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion](by-memory/0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion.md) 0x00469180-0x004691fa | class method | BlackHoleQueuePaneForDeferredDeletion : reconstructable : 96% : very-strong : Exact 83-call pane adapter, three raw caller sites, Pane layer/event virtual cleanup, TimerMgr owner cleanup through the adjusted TimerHandler base, List dedup/append, exact IDA state, corrected formal C++, and stale PaneChildRegistry alias rejection.`
- `[UID:0002M4][0x00469200-0x00469233.BlackHoleReleaseQueuedOwnedObjects](by-memory/0x00469200-0x00469233.BlackHoleReleaseQueuedOwnedObjects.md) 0x00469200-0x00469233 | class method | BlackHoleReleaseQueuedOwnedObjects : reconstructable : 95% : very-strong : Exact Application shutdown/idle callers, inherited List traversal, non-null virtual deletion, RemoveAll tail, bytes/frame/padding, formal C++, and deterministic three-stage rename/FR/FP handoff.`
- `[UID:0002M2][0x00469240-0x00469288.BlackHoleScalarDeletingDestructor](by-memory/0x00469240-0x00469288.BlackHoleScalarDeletingDestructor.md) 0x00469240-0x00469288 | deleting destructor wrapper | BlackHoleScalarDeletingDestructor : reconstructable : 94% : very-strong : Exact vtable-routed MSVC scalar deleting destructor, List teardown, singleton clear, optional operator delete, 0x14 size, bytes/frame/padding, compiler-covered no-body disposition, and deterministic three-stage rename/FR/FP handoff.`
- `[UID:0000Z2][0x00469180-0x004691fa.PaneChildRegistry](by-memory/0x00469180-0x004691fa.PaneChildRegistry.md) 0x00469180-0x004691fa | stale alias | PaneChildRegistry : ignored : -1 : very-strong : Historical exact-address alias retained for links; no separate bytes/source/type exist and authoritative source child is UID0000Z1 BlackHoleQueuePaneForDeferredDeletion.`
- `[UID:00028K][0x0067a74c-0x0067a750.g_pApplicationCleanupQueue](by-memory/0x0067a74c-0x0067a750.g_pApplicationCleanupQueue.md) 0x0067a74c-0x0067a750 | global pointer | g_pApplicationCleanupQueue : reconstructable : 93% : very-strong : Exact zero-initialized BlackHole singleton pointer with BlackHole* type, source-facing comment, 72 xrefs, constructor/destructor writes, broad consumers, one CPP definition, one H extern, and protected g_pLanguageMan boundary.`

`by-global/-coverage-report.md`

- `[UID:0000Q8][g_pApplicationCleanupQueue](by-global/g_pApplicationCleanupQueue.md) : reconstructable : 94% : very-strong : BlackHole-owned singleton/global route with exact zero storage child, 72 xrefs, lifecycle writers/readers, one guarded BlackHole H extern, one CPP definition, and complete consumer header visibility.`

`by-type/by-struct/-coverage-report.md`

- `[UID:0001TT][BlackHoleLayout](by-type/by-struct/BlackHoleLayout.md) : reconstructable : 94% : very-strong : Exact 0x14-byte BlackHole layout using the List primary base and Singleton<BlackHole> relationship, pointer-size List elements, List(4,1024) construction, scalar-delete size, guarded class H, and compile-time size assertion.`

`by-type/by-vtable/-coverage-report.md`

- `[UID:0001X2][BlackHoleVtable](by-type/by-vtable/BlackHoleVtable.md) : reconstructable : 94% : very-strong : Exact ten-dword BlackHole vtable at 0x00613118 with scalar deleting destructor plus inherited List surface, four vtable-address stores, complete BlackHole/Singleton RTTI, exact bytes/hash, and protected following compiler-data boundary at 0x00613140.`

No tracker text is hand-authored because `-ag-research-tracker.md` is generated. Supervisor refresh should derive target ignored/reconstructability state from accepted ordinary metadata and coverage.

## Follow-Up Actions

1. B009 callback history: C0000MD-001..060 and C0000MD-071..075 were disposition-verified under short ordinary-file leases; scoped commands 24738-24770 plus List correction 24778 passed, owning-route waited refresh 24777 completed, and all target-specific generated conditions were physically reread.
2. Supervisor performs a fresh exact-artifact Gate 1/Gate 2A audit of this report and ordinary implementation.
3. Supervisor independently handles C0000MD-061..070 at Gate 2B: five applying entity rows require the literal fifteen-call sequence in Section 21, while I04 and P01-P04 require no mutation.
4. Supervisor owns manual coverage reconciliation from Section 28, tracker/generated then-current reread, and report lifecycle actions.
5. No follow-up research question or B009-owned ordinary implementation remains open.

## Confidence

- Alias rejection: `97%`, original-proof/very-strong.
- BlackHole ownership and source placement: `97%`, original-proof.
- Function/range/padding/vtable/global/layout inventory: `97%`, original-proof.
- Formal C++03 source/header route and dependency closure: `96%`, very-strong.
- Descriptive names for five stripped functions: `90%`, strong; exact behavior is higher confidence than spelling.
- Remaining uncertainty: unavailable original private lexical spellings and whether original source exposed the singleton through this exact global name. Neither affects faithful behavior, layout, ABI, or build routing.

## Validator Results

- Exact callback cwd for every command: `E:\NTK\GhidraBridge\source-3\project-documentation`.
- Each scoped row's exact command is `python .\tools\validator.py --mode file --file "<path>" --apply --queue-timeout 240`, with `<path>` replaced verbatim by the Path column. Every row exited `0`, reported `ok:1`, reported no error, and initially reported `generated_refresh: deferred`.

| Path | Command ID / timestamp | Relevant diagnostics and side effects |
| --- | --- | --- |
| `by-file\PaneChildRegistry.md` | `000000024738` / `2026-08-16T04:46:38-04:00` | score registry `94/97`; one UID-link label normalized; projected stats updated. |
| `by-class\PaneChildRegistry.md` | `000000024739` / `2026-08-16T04:46:40-04:00` | one UID-link label normalized; projected stats updated. |
| `by-memory\0x00469180-0x004691fa.PaneChildRegistry.md` | `000000024740` / `2026-08-16T04:46:43-04:00` | one UID-link label normalized; projected stats updated. |
| `by-file\BlackHole.md` | `000000024741` / `2026-08-16T04:46:53-04:00` | score registry `95/97`; projected stats updated. |
| `by-class\BlackHole.md` | `000000024742` / `2026-08-16T04:47:04-04:00` | score registry `96/97`; autogen registry updated. |
| `by-memory\0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue.md` | `000000024743` / `2026-08-16T04:47:06-04:00` | score registry `94/96`. |
| `by-memory\0x004690b0-0x004690f6.BlackHoleConstructor.md` | `000000024744` / `2026-08-16T04:47:08-04:00` | score registry `94/96`. |
| `by-memory\0x00469100-0x00469115.BlackHoleDestructor.md` | `000000024745` / `2026-08-16T04:47:11-04:00` | score registry `94/96`. |
| `by-memory\0x00469120-0x00469171.BlackHoleEnqueueIfMissing.md` | `000000024746` / `2026-08-16T04:47:13-04:00` | score registry `95/96`. |
| `by-memory\0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion.md` | `000000024747` / `2026-08-16T04:47:15-04:00` | score registry `96/97`; autogen registry updated. |
| `by-memory\0x00469200-0x00469233.BlackHoleReleaseQueuedOwnedObjects.md` | `000000024748` / `2026-08-16T04:47:18-04:00` | score registry `95/96`. |
| `by-memory\0x00469240-0x00469288.BlackHoleScalarDeletingDestructor.md` | `000000024749` / `2026-08-16T04:47:20-04:00` | score registry `94/96`. |
| `by-global\g_pApplicationCleanupQueue.md` | `000000024750` / `2026-08-16T04:47:22-04:00` | score registry `94/96`; generated stats row removed as threshold crossed; rescore recommendation only. |
| `by-memory\0x0067a74c-0x0067a750.g_pApplicationCleanupQueue.md` | `000000024751` / `2026-08-16T04:47:25-04:00` | score registry `93/96`. |
| `by-type\by-struct\BlackHoleLayout.md` | `000000024752` / `2026-08-16T04:47:27-04:00` | score registry `94/97`; generated stats row removed as threshold crossed; rescore recommendation only. |
| `by-type\by-vtable\BlackHoleVtable.md` | `000000024753` / `2026-08-16T04:47:29-04:00` | score registry `94/97`. |
| `by-class\List.md` | `000000024754` / `2026-08-16T04:47:32-04:00` | score registry `93/94`; guarded draft registered. |
| `by-class\Application.md` | `000000024755` / `2026-08-16T04:47:34-04:00` | autogen registry updated; no warning. |
| `by-class\FittingRoomDialog.md` | `000000024756` / `2026-08-16T04:47:36-04:00` | autogen registry updated; no warning. |
| `by-class\UserListDialogPane.md` | `000000024757` / `2026-08-16T04:47:38-04:00` | autogen registry updated; no warning. |
| `by-class\NewSayToUserMessageInputPane.md` | `000000024758` / `2026-08-16T04:47:40-04:00` | autogen registry updated; pre-existing `missing_ref_uid 0003JQ` warning only. |
| `by-class\MainMenuPane.md` | `000000024759` / `2026-08-16T04:47:43-04:00` | autogen registry updated; no warning. |
| `by-memory\0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md` | `000000024760` / `2026-08-16T04:47:45-04:00` | autogen registry updated; no warning. |
| `by-memory\0x005aac80-0x005aafe3.UserPaneHandleServerEntryPacket.md` | `000000024761` / `2026-08-16T04:47:47-04:00` | autogen registry updated; no warning. |
| `by-class\Motion.md` | `000000024762` / `2026-08-16T04:47:49-04:00` | autogen registry updated; no warning. |
| `by-memory\0x004b73b0-0x004b7661.FramePartPane.md` | `000000024763` / `2026-08-16T04:47:52-04:00` | autogen registry updated; stale global correction registered. |
| `by-class\ParcelIconPane.md` | `000000024764` / `2026-08-16T04:47:54-04:00` | autogen registry updated; no warning. |
| `by-class\EventDispatcher.md` | `000000024765` / `2026-08-16T04:47:56-04:00` | autogen registry updated; no warning. |
| `by-class\CharInputPane.md` | `000000024766` / `2026-08-16T04:47:58-04:00` | autogen registry updated; pre-existing `missing_ref_uid` warnings `000363` and `00036F` only. |
| `by-class\RankingRewardInfoDialog.md` | `000000024767` / `2026-08-16T04:48:01-04:00` | autogen registry updated; no warning. |
| `by-class\TargetOptionDialog.md` | `000000024768` / `2026-08-16T04:48:03-04:00` | autogen registry updated; no warning. |
| `by-class\ItemWhoInputPane.md` | `000000024769` / `2026-08-16T04:48:05-04:00` | autogen registry updated; no warning. |
| `by-class\WebBoardDialog.md` | `000000024770` / `2026-08-16T04:48:08-04:00` | autogen registry updated; 12 pre-existing missing-ref occurrences, four each for `0003V2`, `0003V3`, and `0003V4`; no error. |
| `by-class\List.md` correction | `000000024778` / `2026-08-16T04:56:36-04:00` | exact same command/path after empty H marker removal; autogen registry updated; no warning/error; deferred refresh later completed. |

- Approved owning-route waited command: `python .\tools\validator.py --mode file --file "by-file\BlackHole.md" --apply --wait-generated --queue-timeout 240`; command `000000024777`; timestamp `2026-08-16T04:54:31-04:00`; exit `0`; `ok:1`; `generated_refresh: completed`; `autogen_registry_rebuild:1`; `generated_metadata_refresh:277`; `autogen_header_metadata_refresh:141`. Project-wide informational diagnostics were `autogen_children_fallback_insert:7`, `autogen_children_marker_missing:72`, `autogen_emitter_has_no_code:63`, and `autogen_header_children_marker_missing:1`; none names this target family as an error.
- Command-24777 physical readback exposed one target-specific issue: generated `List.h` contained literal `[[No Children Attached]]` because the accepted List H marker had no H children. B009 removed only that marker, ran scoped command `000000024778`, allowed its validator-owned incremental refresh to complete, and reread a guarded token-free List H. No second waited refresh command was run.

Physical generated readback identities and findings:

| Artifact | SHA256 | Bytes / lines | Completion finding |
| --- | --- | ---: | --- |
| `auto-generated\NexusTK\ui\core\BlackHole.cpp` | `149D403F8FF73D820B91CA31C66B8FC227B2058146D2126C24B3E4F61C550168` | `3258 / 84` | command 24777; includes H/Pane/TimerMgr; five source bodies plus compiler/layout/vtable comments and one global definition in exact child order; zero child tokens. |
| `auto-generated\NexusTK\ui\core\BlackHole.h` | `A64F09D18E98DDB87854DA5367A38E7E8F9724902841C18833F1EF183E340CCC` | `910 / 32` | command 24777; one guard pair, List/Singleton includes, complete declaration/extern/size assertion, zero child tokens. |
| `auto-generated\NexusTK\util\List.h` | `043E78BD51837BF743B17BAD6863578A3E754311048C745E54C9DCB5CFC0F092` | `1474 / 47` | command 24778; one guard pair, every prior declaration, zero child tokens. |
| `auto-generated\NexusTK\app\Application.cpp` | `C6C8C13C3969D6E4BDAEA5C182562C6065F95C77C9FC3D47C95567A62B801E0F` | `34878 / 912` | include line 24; first BlackHole use line 161. |
| `auto-generated\NexusTK\cashshop\FittingRoom.cpp` | `74D5DBF599369422AB9CCC31A1C39C2F47A3D0349A7D1AD27261459F6201FD87` | `99545 / 2819` | include line 512; first use line 643. |
| `auto-generated\NexusTK\social\UserListDialogPane.cpp` | `20D123EF2EE83C8C31C05F183E40B449667BF6EDE4669D2BC716C9EB6AA53E22` | `41754 / 1201` | include line 24; first use line 762. |
| `auto-generated\NexusTK\social\SayInputPanes.cpp` | `310D57C830A0015F1AE11962F3F9A06AB6C289B1653AB5155CC75BB724A33463` | `16372 / 495` | include line 8; first use line 77. |
| `auto-generated\NexusTK\login\MainMenuPane.cpp` | `6B937E6CC412FD39610DCFA699C7AC17745FEA5F093E976D37745B53068BBCCB` | `31396 / 856` | include line 8; first use line 216. |
| `auto-generated\NexusTK\map\MapPane.cpp` | `56624E27A14F9142B745DD57BC9BBA95A6404619E4ABDF0A8E472342271B22B2` | `160099 / 4794` | include line 274; first use line 287. |
| `auto-generated\NexusTK\ui\panels\UserPane.cpp` | `57465E2E8C56846572C20670F1942EC2E10DE94A6105DCD5E976DD7C33938761` | `87925 / 2674` | include line 1798; first use line 1817. |
| `auto-generated\NexusTK\render\Motion.cpp` | `E2B5ABB2ECEB6C4D5F05E89FE32154A3EA55480E6024B292AD9A40346490D36D` | `7466 / 301` | include line 8; first use line 287. |
| `auto-generated\NexusTK\ui\core\FrameChrome.cpp` | `0FF6869DF567952CF165B577DC695C2CA9C4A7921EE374CA968B2C503D6E3198` | `6181 / 178` | include line 22; first use line 45; `g_pBlackHole` absent. |
| `auto-generated\NexusTK\ui\panels\ParcelPane.cpp` | `16B7F5B56D07F3561DA0C61FFC46B7C4E3195186A2D67EA6CCF40522828658AB` | `17747 / 562` | include line 324; first use line 367. |
| `auto-generated\NexusTK\ui\core\EventDispatcher.cpp` | `6E9D297DB9FF65FD85DAE853E65D51A1D9D9617D50856C42353DD09377A9AF2F` | `16757 / 487` | include line 11; first use line 60. |
| `auto-generated\NexusTK\ui\dialogs\InputPanes.cpp` | `608A1C9DD519BAE6A201786AE8393B9D381271C4069D83F745EF6CEA354FBA98` | `8357 / 249` | include line 20; first use line 41. |
| `auto-generated\NexusTK\ui\dialogs\RankingDialog.cpp` | `40CE53A935B285FE692FA1B8A0C8E14DE0062D35E2903450C0D6B0D45422A535` | `64927 / 1803` | include line 1225; first use line 1407. |
| `auto-generated\NexusTK\ui\dialogs\TargetOptionDialog.cpp` | `84A1E641BFC240A9198CC5EB6C04D1D4E4A33F2550347EEA295596B65C53681A` | `4434 / 137` | include line 39; first use line 113. |
| `auto-generated\NexusTK\ui\dialogs\TargetSelectionInputPanes.cpp` | `C9987FFFCD62442D0BF308E0EE6A21DD9A61676F3B5FA32C5DB75A7F6CF000B0` | `46113 / 1276` | include line 47; first use line 194. |
| `auto-generated\NexusTK\ui\dialogs\WebBoardDialog.cpp` | `5014E31F6D7C8F1C8A5CB78CF90F3CA031A7BFFCE355E118751230100199DC40` | `24941 / 706` | include line 70; first use line 147. |

- All 16 consumer includes occur exactly once and before first use; all carry command-24777 metadata. No consumer TU contains a local `class BlackHole`; generated NexusTK CPP/H contains zero `g_pBlackHole`; BlackHole CPP uses exactly one `static_cast<TimerHandler *>(pane)` and zero `m_timerHandler` references.
- Pre-existing unrelated literal no-child placeholders remain in six broad consumer TUs: UserListDialogPane 3, SayInputPanes 1, MapPane 1, EventDispatcher 6, InputPanes 4, and RankingDialog 1. None comes from the BlackHole include fragments or affects the target-specific source order; they are preserved outside this accepted scope. BlackHole CPP/H and List H have zero such tokens.
- PaneChildRegistry CPP/H are absent after refresh. The four manual coverage files remained byte-identical: by-file `5A5831DDB9719031C461CD4CA0C2397C6F9E86BC791698ADC5BA235070BE024E`; by-class `3715B24B0AB799B4840D08506F3469CEA714A9E3FF2AC97E42560B6CF18DE034`; by-memory `70FE5CDC8654815211568C22A5E1CC7A9C859A810CB7CADF8433B443285BB03B`; by-struct `CC89CD5B9689D8530F8511CDC4825CDF3CE0AEF96C917D65460E93AC5C05E7A3`.
- No executable script or command package is included in this report.

## Changed Files

- B009 directly edited this existing report and the following 33 ordinary destinations. Generated artifacts in Section 31 were written only by the approved validator path, never directly.

| Ordinary path | SHA256 | Bytes / lines |
| --- | --- | ---: |
| `by-file\PaneChildRegistry.md` | `B181CB832E82A276152A596390866B52620F2EBD08F488D3A1F0268A104AD4F3` | `6778 / 70` |
| `by-class\PaneChildRegistry.md` | `A7E010CF6CCFD03F8D3C6E302089696D7DE1B6A7540C63272D7F00268039F209` | `5000 / 57` |
| `by-memory\0x00469180-0x004691fa.PaneChildRegistry.md` | `9CDCD978C0EE4E6D71E397F59C8D6B26FB0C49BB6CE24B489A7D47B37C5144AB` | `3413 / 37` |
| `by-file\BlackHole.md` | `CF2AA3F995A4A70561C7E85FEDBA48E7AD851EF9ACE57FE8EE248C4602D50D3C` | `13936 / 119` |
| `by-class\BlackHole.md` | `58D5BFFEB94B40CD93663A70FB65E3FA67E66FE7DEA7C1044EE7F05A541DEB42` | `14117 / 169` |
| `by-memory\0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue.md` | `F2738DCD532A2B07D1A1ACE120806EDE5B75E994844139BACDDAE20B1F67F4DC` | `12373 / 117` |
| `by-memory\0x004690b0-0x004690f6.BlackHoleConstructor.md` | `B1491D4B0640194AC96E3EAD61D2674C22D77B5F15CABC2D616C8D9B45769259` | `7301 / 83` |
| `by-memory\0x00469100-0x00469115.BlackHoleDestructor.md` | `124E857C375A15D4E9A4B9C1AB15A0B5F385B2C4B3609115D24920CE5710E061` | `6967 / 78` |
| `by-memory\0x00469120-0x00469171.BlackHoleEnqueueIfMissing.md` | `1AC23DB2D9FE0824D8B6BBB586117286944BC0855BA1D02278D5B79D419C1F1F` | `8166 / 95` |
| `by-memory\0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion.md` | `847C1123A307D6103AFCFD492D970CE32894DEC72FDABD6B31092A82DC233847` | `11984 / 107` |
| `by-memory\0x00469200-0x00469233.BlackHoleReleaseQueuedOwnedObjects.md` | `1B9F4BEED0A12E4BB667C6CB7AD2DC4B51640FFB7DE9D40A93F6EB91A21745B0` | `7167 / 90` |
| `by-memory\0x00469240-0x00469288.BlackHoleScalarDeletingDestructor.md` | `EC3E2BE6A3831974AE082E01053D195617452A3AA687F391CD6A9C7702A2A522` | `6996 / 78` |
| `by-global\g_pApplicationCleanupQueue.md` | `9BFCEF201526EFE0F74373459FACF8669649FAFF6F71C2F481D5C6BD3557EA0A` | `11434 / 98` |
| `by-memory\0x0067a74c-0x0067a750.g_pApplicationCleanupQueue.md` | `59482067B20908F633776C275C501D5173A89118FA1E99F164DB0916EBB8E070` | `9576 / 88` |
| `by-type\by-struct\BlackHoleLayout.md` | `BD5873B69789203DE257A63295C7D2F67E9E36A2FAB278EFCDC75505C64D78D4` | `6182 / 80` |
| `by-type\by-vtable\BlackHoleVtable.md` | `89D8FCFCB32B1D342CB850CAE113234E860C4C7C7A869BA06201871C0027C912` | `8665 / 93` |
| `by-class\List.md` | `83A3CAFBF4CA2B90611EC647C7F66E454BE36957A51D160E59F47F0AA78F4962` | `38441 / 280` |
| `by-class\Application.md` | `B5D81DA39ACED02547D6D68B94BF271C90E41AA0A947F5BFA70C30B92CF55E22` | `127220 / 620` |
| `by-class\FittingRoomDialog.md` | `FDC7FF32969CF729B78A0BC2FDF531FD861A0134E10BC8D42615C4D25E7DCF5E` | `31829 / 206` |
| `by-class\UserListDialogPane.md` | `BAF20855D622474559ACD36CE4B5EA9E48BFBB9FE728888E2FAA3D9447B88F20` | `41860 / 313` |
| `by-class\NewSayToUserMessageInputPane.md` | `3A26848DA7E16FC752F28A3B03F2ED4256CE935834464327850360CB7474CF8D` | `15672 / 123` |
| `by-class\MainMenuPane.md` | `AA4F808B546FB7A5077B724352F832D1292A0F3DAD5DB6111F959B36E0E483CE` | `36035 / 227` |
| `by-memory\0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md` | `CC1E930B0D4F19902F9E2484AD499BB2EEDAA90230E2DFB93B2BC7BFCA671F53` | `29735 / 252` |
| `by-memory\0x005aac80-0x005aafe3.UserPaneHandleServerEntryPacket.md` | `8987361440989ED4C68C7E33871D240E5E908A283FC779D609C50FDDFA223681` | `16321 / 228` |
| `by-class\Motion.md` | `AADD14F9BEB83674A8848FCE500530FE8676EAA651D1A7AB5B0D224AC48959E1` | `31981 / 232` |
| `by-memory\0x004b73b0-0x004b7661.FramePartPane.md` | `294E71A8F3A0F67346562514113BBE715C14008473E59491D73A6DE76C8F0F63` | `21691 / 204` |
| `by-class\ParcelIconPane.md` | `6236515D8AEAEB9AB07F2448B9265A88560714D983F3663A9CB727D5ED32A9CF` | `25305 / 167` |
| `by-class\EventDispatcher.md` | `FD463B9A992D4B7D63BD6E0FBA874D507857DCA972F071E573E2F65F4B407762` | `36496 / 323` |
| `by-class\CharInputPane.md` | `542C744123F7077FDB77C089F25B693A65CF9022F74138ED693E52C592D9A180` | `13145 / 126` |
| `by-class\RankingRewardInfoDialog.md` | `07F624E253C011B59938D13E957BAE4227B05F4B3E13EAE92A13EC98435A72A2` | `39896 / 268` |
| `by-class\TargetOptionDialog.md` | `58A4E794AACA11619440CD911FB983F472817741027D00DAEC5B79CF47DE2392` | `10142 / 104` |
| `by-class\ItemWhoInputPane.md` | `42534DEDB9A1268F69245C5EE81EA78AAC888B3AB88CEB734D2C154957E613AA` | `20330 / 124` |
| `by-class\WebBoardDialog.md` | `BB42B1C685334C62F0395D5E73A8A85D662D3CB7EAF0F0A885847F6D7C95B5A3` | `30916 / 208` |

- No manual coverage, audit, catalog, goal, notes, IDA, MCP, or lifecycle file was directly edited. Validator registry/tracker/generated artifacts changed only through the approved scoped/waited commands.
- Every ordinary-file lease was acquired immediately before its edit and released immediately afterward. The report lease is released after final stable reconciliation; post-write lease-report reread supplies the proof.

## Implementation Tracking Checklist

Checklist allocation: `65` checked / `15` unchecked. The unchecked set is exactly C0000MD-061..070 and C0000MD-076..080; B009 did not check any supervisor-owned IDA, manual-coverage, or lifecycle/process row.

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | C0000MD-001 | 0000MD | Classify PaneChildRegistry as a stale alias with no source family. | original-proof | Zero symbols/types/RTTI/vtable/global/output; BlackHole receiver. | UID0000MD Status/Decision | incorporate | applied |
| [x] | C0000MD-002 | 0000MD | Retain UID0000MD as a non-emitting compatibility warning with path/owner `NONE`. | very-strong | Existing links and exact corrected owner route. | UID0000MD metadata/body | incorporate | applied |
| [x] | C0000MD-003 | 0000A3 | Retain class alias at `-1/-1`, owner NONE, non-reconstructable, blank emitter/formals. | original-proof | No PaneChildRegistry class/type/RTTI. | UID0000A3 metadata/body | already-present | already-present |
| [x] | C0000MD-004 | 0000Z2 | Retain exact-address alias at `-1/-1`, owner NONE, non-reconstructable, blank emitter/formals. | original-proof | Same bytes are UID0000Z1 BlackHole method. | UID0000Z2 metadata/body | already-present | already-present |
| [x] | C0000MD-005 | 0000HR | Retain `NexusTK/ui/core/BlackHole.cpp` as the canonical real source file. | original-proof | RTTI, vtable, lifecycle, full family. | UID0000HR status/role | incorporate | applied |
| [x] | C0000MD-006 | 00000W | Retain BlackHole as direct class emitter and `List`/`Singleton<BlackHole>` class. | original-proof | RTTI and constructor/vtable/layout. | UID00000W class/formals | incorporate | applied |
| [x] | C0000MD-007 | 0000Z0 | Keep the aggregate non-emitting and index the complete six-function/pad family. | very-strong | Mixed source/compiler/padding span. | UID0000Z0 inventory | incorporate | applied |
| [x] | C0000MD-008 | 0002M0 | Preserve constructor `[4690b0,4690f6)` and its source body. | original-proof | Application caller, List(4,1024), vtable/global writes. | UID0002M0 | incorporate | applied |
| [x] | C0000MD-009 | 0002M1 | Preserve ordinary destructor `[469100,469115)` and its source body. | original-proof | vtable/global clear and List dtor tail. | UID0002M1 | incorporate | applied |
| [x] | C0000MD-010 | 0002M3 | Preserve EnqueueIfMissing `[469120,469171)` and its source body. | original-proof | Motion caller, null/dedup/append behavior. | UID0002M3 | incorporate | applied |
| [x] | C0000MD-011 | 0000Z1 | Preserve QueuePaneForDeferredDeletion `[469180,4691fa)` as BlackHole source. | original-proof | 83 calls, Pane/timer cleanup, List dedup. | UID0000Z1 | incorporate | applied |
| [x] | C0000MD-012 | 0002M4 | Preserve ReleaseQueuedOwnedObjects `[469200,469233)` and its source body. | original-proof | cleanup/idle callers, virtual deletes, RemoveAll. | UID0002M4 | incorporate | applied |
| [x] | C0000MD-013 | 0002M2 | Keep scalar deleting destructor `[469240,469288)` compiler-covered with no handwritten body. | original-proof | vtable slot, delete flag, operator delete. | UID0002M2 | already-present | already-present |
| [x] | C0000MD-014 | 0000Z0 | Preserve all six literal `0xcc` pad spans and successor `0x469290`. | original-proof | Exact bytes and function boundaries. | UID0000Z0 range table | incorporate | applied |
| [x] | C0000MD-015 | 0000Q8 | Retain `g_pApplicationCleanupQueue` as BlackHole-owned global. | original-proof | 72 xrefs and constructor/destructor writes. | UID0000Q8 | incorporate | applied |
| [x] | C0000MD-016 | 00028K | Retain exact zero-initialized storage `[67a74c,67a750)`. | original-proof | Physical item/type/comment/xrefs. | UID00028K | incorporate | applied |
| [x] | C0000MD-017 | 0001TT | Retain exact BlackHole size `0x14` and List-base layout. | original-proof | constructor allocation semantics and scalar delete size. | UID0001TT | incorporate | applied |
| [x] | C0000MD-018 | 0001X2 | Retain exact ten-slot vtable `[613118,613140)`. | original-proof | Integer reads, RTTI, constructor stores. | UID0001X2 | incorporate | applied |
| [x] | C0000MD-019 | 00000W | Preserve complete BlackHole/Singleton RTTI as compiler metadata. | original-proof | 12 named RTTI/string entities. | UID00000W/UID0001X2 evidence | incorporate | applied |
| [x] | C0000MD-020 | 0000MD | Record zero PaneChildRegistry-owned resources, strings, statics, globals, or by-item entities. | original-proof | Repository and IDA negative searches. | UID0000MD inventory | incorporate | applied |
| [x] | C0000MD-021 | 0000HR | Keep source placement under `NexusTK/ui/core/`. | very-strong | Pane/EventDispatcher adjacency and broad UI consumers. | UID0000HR path | already-present | already-present |
| [x] | C0000MD-022 | 00000W | Replace invalid class-nested child emission with includes plus top-level `[[CHILDREN]]`. | original-proof | Physical generated BlackHole.cpp ordering. | UID00000W formal CPP | incorporate | applied |
| [x] | C0000MD-023 | 00000W | Emit a complete guarded C++03 `BlackHole.h`. | very-strong | Seventeen consumers and missing sibling H. | UID00000W formal H | incorporate | applied |
| [x] | C0000MD-024 | 000079 | Add one include guard around the complete existing List formal H. | very-strong | BlackHole H dependency; generated List.h unguarded. | UID000079 formal H | incorporate | applied |
| [x] | C0000MD-025 | 0000Z1 | Replace nonexistent `pane->m_timerHandler` with `static_cast<TimerHandler *>(pane)`. | original-proof | Public Pane inheritance and exact `pane+0xa4` call argument. | UID0000Z1 formal CPP/body | reject-stale | applied |
| [x] | C0000MD-026 | 0000Q8 | Declare the global once as `extern` in BlackHole H and define it once in CPP. | very-strong | Multi-TU use and current single definition. | UID00000W H / UID0000Q8 CPP | incorporate | applied |
| [x] | C0000MD-027 | 0000MD | Keep PaneChildRegistry CPP/H absent after refresh. | original-proof | No real source/type and current absence. | UID0000MD output disposition | not-applicable | excluded-with-reason |
| [x] | C0000MD-028 | 0000MD | Historicalize alias-page claims about current sidecars/generated source. | very-strong | Dated command-24682 contradicts active wording. | UID0000MD/0000A3/0000Z2 prose | incorporate | applied |
| [x] | C0000MD-029 | 0000HR | Update BlackHole docs from expected-complete output to the exact dated blocker/resolution. | original-proof | Dated generated CPP was invalid and H was absent. | UID0000HR/00000W/0000Z0 status | incorporate | applied |
| [x] | C0000MD-030 | 0000HR | Preserve proposed-source-tree BlackHole route and absence of PaneChildRegistry source. | very-strong | Existing tree already matches binary ownership. | source-tree read-only evidence | already-present | already-present |
| [x] | C0000MD-031 | 0000HR | Record the dated snapshot of all 17 generated BlackHole-consuming TUs and absence of any BlackHole include. | original-proof | Dated physical generated repository search. | UID0000HR generated audit | incorporate | applied |
| [x] | C0000MD-032 | 00000D | Add `../ui/core/BlackHole.h` before Application children. | very-strong | Application.cpp cleanup use. | by-class/Application.md formal CPP | incorporate | applied |
| [x] | C0000MD-033 | 000050 | Add `../ui/core/BlackHole.h` to FittingRoom formal CPP. | very-strong | FittingRoom.cpp pane queue use. | by-class/FittingRoomDialog.md | incorporate | applied |
| [x] | C0000MD-034 | 0000FN | Add `../ui/core/BlackHole.h` to UserListDialogPane formal CPP. | very-strong | Two UserListDialogPane.cpp uses. | by-class/UserListDialogPane.md | incorporate | applied |
| [x] | C0000MD-035 | 000099 | Add `../ui/core/BlackHole.h` to NewSayToUserMessageInputPane formal CPP. | very-strong | SayInputPanes.cpp use. | by-class/NewSayToUserMessageInputPane.md | incorporate | applied |
| [x] | C0000MD-036 | 00007O | Add `../ui/core/BlackHole.h` to MainMenuPane formal CPP. | very-strong | Two MainMenuPane.cpp uses. | by-class/MainMenuPane.md | incorporate | applied |
| [x] | C0000MD-037 | 0002QH | Add `../ui/core/BlackHole.h` before first MapPane consuming child. | very-strong | MapPane.cpp uses precede later class fragments. | UID0002QH formal CPP | incorporate | applied |
| [x] | C0000MD-038 | 0003UN | Add `../core/BlackHole.h` before first UserPane consuming child. | very-strong | Two UserPane.cpp uses. | UID0003UN formal CPP | incorporate | applied |
| [x] | C0000MD-039 | 00008R | Add `../ui/core/BlackHole.h` to Motion formal CPP. | very-strong | Motion.cpp EnqueueIfMissing use. | by-class/Motion.md | incorporate | applied |
| [x] | C0000MD-040 | 00015O | Add `BlackHole.h` and replace stale `g_pBlackHole` with `g_pApplicationCleanupQueue`. | original-proof | FrameChrome.cpp only stale global spelling. | UID00015O formal CPP | reject-stale | applied |
| [x] | C0000MD-041 | 0000A5 | Add `../core/BlackHole.h` to ParcelIconPane formal CPP. | very-strong | ParcelPane.cpp use. | by-class/ParcelIconPane.md | incorporate | applied |
| [x] | C0000MD-042 | 00004M | Add `BlackHole.h` to EventDispatcher formal CPP. | very-strong | EventDispatcher.cpp drain use. | by-class/EventDispatcher.md | incorporate | applied |
| [x] | C0000MD-043 | 00001P | Add `../core/BlackHole.h` to CharInputPane formal CPP. | very-strong | InputPanes.cpp uses. | by-class/CharInputPane.md | incorporate | applied |
| [x] | C0000MD-044 | 0000BP | Add `../core/BlackHole.h` to RankingRewardInfoDialog formal CPP. | very-strong | RankingDialog.cpp use. | by-class/RankingRewardInfoDialog.md | incorporate | applied |
| [x] | C0000MD-045 | 0000EE | Add `../core/BlackHole.h` to TargetOptionDialog formal CPP. | very-strong | TargetOptionDialog.cpp use. | by-class/TargetOptionDialog.md | incorporate | applied |
| [x] | C0000MD-046 | 00006X | Add `../core/BlackHole.h` before TargetSelectionInputPanes consumers. | very-strong | Sixteen generated calls in one TU. | by-class/ItemWhoInputPane.md | incorporate | applied |
| [x] | C0000MD-047 | 0000G2 | Add `../core/BlackHole.h` to WebBoardDialog formal CPP. | very-strong | Two WebBoardDialog.cpp uses. | by-class/WebBoardDialog.md | incorporate | applied |
| [x] | C0000MD-048 | 0000Z1 | Preserve all 83 exact direct call xrefs to `0x469180`. | original-proof | Complete analyze_batch/xref_query set. | UID0000Z1 caller inventory | incorporate | applied |
| [x] | C0000MD-049 | 0000Z1 | Preserve three no-function callers at `46e28d`,`53dd9f`,`545dd7`. | original-proof | Raw-site bounded inspection. | UID0000Z1 caller inventory | incorporate | applied |
| [x] | C0000MD-050 | 0002M0 | Preserve sole constructor caller `464549` in Application Startup. | original-proof | Directional xref. | UID0002M0 evidence | incorporate | applied |
| [x] | C0000MD-051 | 0002M3 | Preserve sole enqueue caller `53a0bc` in Motion OnTimer. | original-proof | Directional xref. | UID0002M3 evidence | incorporate | applied |
| [x] | C0000MD-052 | 0002M4 | Preserve drain callers `464c19` and `4a6c4a`. | original-proof | Directional xrefs. | UID0002M4 evidence | incorporate | applied |
| [x] | C0000MD-053 | 0001X2 | Preserve vtable routes to scalar destructor and inherited List slots. | original-proof | Exact ten dwords and stores. | UID0001X2 evidence | incorporate | applied |
| [x] | C0000MD-054 | 0000Z1 | Resolve Pane slots `+0x38/+0x40` to RemoveFromLayer/UnregisterEventHandler. | original-proof | Vtable dwords `621a20/621a28`. | UID0000Z1 behavior | incorporate | applied |
| [x] | C0000MD-055 | 0000Z1 | Resolve timer cleanup to `TimerMgr_RemovePendingTimersForOwner` with adjusted TimerHandler base. | original-proof | Call `4691aa`, global `67ab80`, argument `pane+0xa4`. | UID0000Z1 behavior/formal CPP | incorporate | applied |
| [x] | C0000MD-056 | 00000W | Preserve List count/get/append/remove-all semantics and owned virtual deletion. | original-proof | Bodies and vtable slots. | UID00000W role | incorporate | applied |
| [x] | C0000MD-057 | 0000Q8 | Preserve exact 72-xref singleton lifecycle and consumers. | original-proof | Complete bounded xref count and writers. | UID0000Q8 evidence | incorporate | applied |
| [x] | C0000MD-058 | 0000SI | Do not duplicate the prior cataloged g_pTimerMgr rename/type action from this target. | very-strong | Catalog 0141 versus current blank physical label/type projection. | IDA handoff P04 | reject-stale | excluded-with-reason |
| [x] | C0000MD-059 | 0000MD | Record exact absence of PaneChildRegistry local type, name, function, and global. | original-proof | type_inspect/entity_query. | UID0000MD negative evidence | incorporate | applied |
| [x] | C0000MD-060 | 00000W | Record the one BlackHole-named function and 13 BlackHole/global entities returned by live query. | original-proof | Entity query and RTTI. | UID00000W evidence | incorporate | applied |
| [ ] | C0000MD-061 | 0002M0 | I01: apply three ordered public calls: pure rename, FR write, then FP write. | very-strong | Fresh literal prestate, collision-free desired name, and deterministic three-stage readbacks. | IDA supervisor handoff I01 | incorporate | proposed |
| [ ] | C0000MD-062 | 0002M1 | I02: apply three ordered public calls: pure rename, FR write, then FP write. | very-strong | Fresh literal prestate, collision-free desired name, and deterministic three-stage readbacks. | IDA supervisor handoff I02 | incorporate | proposed |
| [ ] | C0000MD-063 | 0002M3 | I03: apply three ordered public calls: pure rename, FR write, then FP write. | very-strong | Fresh literal prestate, collision-free desired name, and deterministic three-stage readbacks. | IDA supervisor handoff I03 | incorporate | proposed |
| [ ] | C0000MD-064 | 0000Z1 | I04: retain already exact name/type/comments with no endpoint. | original-proof | Live exact readback. | IDA supervisor handoff I04 | already-present | proposed |
| [ ] | C0000MD-065 | 0002M4 | I05: apply three ordered public calls: pure rename, FR write, then FP write. | very-strong | Fresh literal prestate, collision-free desired name, and deterministic three-stage readbacks. | IDA supervisor handoff I05 | incorporate | proposed |
| [ ] | C0000MD-066 | 0002M2 | I06: apply three ordered public calls: pure rename, FR write, then FP write. | very-strong | Fresh literal prestate, collision-free desired name, and deterministic three-stage readbacks. | IDA supervisor handoff I06 | incorporate | proposed |
| [ ] | C0000MD-067 | 0000Z0 | P01: protect all function ranges, frames, bytes, xrefs, and six pad spans. | original-proof | Complete endpoint/hash audit. | IDA supervisor handoff P01 | already-present | proposed |
| [ ] | C0000MD-068 | 0001X2 | P02: protect every vtable head/value/xref and physical successor bytes. | original-proof | Full dword/physical-head readback. | IDA supervisor handoff P02 | already-present | proposed |
| [ ] | C0000MD-069 | 00028K | P03: protect singleton storage/comment/type/xrefs and successor boundary. | original-proof | Exact item/comment/bytes/xref count. | IDA supervisor handoff P03 | already-present | proposed |
| [ ] | C0000MD-070 | 0000MD | P04: do not create a PaneChildRegistry UDT or mutate BlackHole/List/Pane types. | original-proof | Negative type query and source ownership. | IDA supervisor handoff P04 | reject-invalid | proposed |
| [x] | C0000MD-071 | 00000W | Use the exact formal BlackHole CPP/H and preserve all six child dispositions. | very-strong | Complete source/dependency audit. | First-Draft C++ Recommendation | incorporate | applied |
| [x] | C0000MD-072 | 0000MD | Keep all PaneChildRegistry formal CPP/H channels blank. | original-proof | No source family or declarations. | UID0000MD/0000A3/0000Z2 formals | not-applicable | excluded-with-reason |
| [x] | C0000MD-073 | 0000MD | Raise target score from `86/88` to `94/97`. | very-strong | Exhaustive disposition and no unresolved blocker. | UID0000MD metadata | incorporate | applied |
| [x] | C0000MD-074 | 0000HR | Apply the exact canonical-family score table without changing alias `-1/-1` rows. | very-strong | Resolved source/header/output blockers. | Named family metadata | incorporate | applied |
| [x] | C0000MD-075 | 0000MD | Preserve consumer-document scores while adding only dependency includes. | very-strong | Include-only support changes. | Sixteen consumer docs | already-present | already-present |
| [ ] | C0000MD-076 | 0000MD | Supply literal supervisor-owned manual coverage replacement rows. | very-strong | Current coverage rows versus resolved state. | Section 28/manual coverage | incorporate | proposed |
| [ ] | C0000MD-077 | 0000MD | Treat tracker/generated identities as dated read-only evidence only. | very-strong | Mutable generated state. | Report evidence prose | incorporate | proposed |
| [ ] | C0000MD-078 | 0000MD | Keep ordinary report prose lifecycle-neutral. | very-strong | Report-only workflow contract. | Whole report | already-present | proposed |
| [ ] | C0000MD-079 | 0000MD | Run no validators or generated refresh during report-only research. | original-proof | Assignment boundary. | Validator Results | not-applicable | proposed |
| [ ] | C0000MD-080 | 0000MD | Change only this report; declare no additional target UID and emit no terminal marker. | original-proof | Assignment scope and artifact audit. | Changed Files/checklist | already-present | proposed |

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000024856","destination_path":"executed-b-agent-research/B009/0000MD-PaneChildRegistry-file-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/0000MD-PaneChildRegistry-file-source-quality.md","timestamp":"2026-08-16T05:42:10-04:00","uid":"0000MD"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
