** TARGET-REPORT-UID:00037X **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID00037X MapPaneInteractionMapChangeCore Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: replace UID00037X's convenience aggregate with a non-emitting split index and seven exact address-ordered source-method children. Five are IDA-modeled methods; the two formerly described as route-negative raw helpers are retained standalone MapPane methods with independent compiler function shapes and complete formal C++.
- Final disposition: UID00037X becomes `90/92`, owner `NONE`, reconstructable `FALSE`, blank emitter/position/formal body, and `Nested:0`. Its seven children are nested under it, while the existing successor UID00037Y keeps `Nested:-4` and closes the child depth.
- Completed callback: after supervisor Gate 1 accepted exact report SHA `91A778A81D2C048F02C7825A7EFA6602CD4D7F4898E3A83B8C8DA4D9D9AD16B3`, B005 serially registered real child UIDs `0004Q8` through `0004QE`, applied Destinations 1-15 and every accepted support synchronization, scoped-validated each changed ordinary page under a short lease, released every lease, and completed waited generated refresh `000000012202`.
- Confidence: very strong for boundaries, behavior, owner, source file, ABI direction, packet layout, field offsets, caller/callee routes, standalone source disposition, compiler artifacts, and split shape; strong rather than final for stripped private method/field spellings and the two unreferenced standalone-method entry routes.
- Lifecycle/status: B005's accepted implementation callback is complete and independently reviewable from this durable artifact. Supervisor Gate 2, manual coverage application, report execution, and archival remain external supervisor-owned state; this report does not assert that those lifecycle actions have occurred.

## Supporting Research

### Mandatory MCP availability and initial evidence-time session

- During the initial report pass, streamable-MCP initialization and `idb_list` discovered database session `4836cd9f` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `18612`, active/adopted, `is_analyzing:false`.
- That initial evidence-time `server_health` returned `status:ok`; auto-analysis, Hex-Rays, and the `2067`-entry string cache were ready. This is historical collection provenance, not a claim that the expired session remains alive after review.
- Initial bounded `lookup_funcs`, `get_bytes`, `decompile`, `insn_query`, callers, callees, xrefs, function-profile/basic-block, and local data/table checks completed against the target and named support functions. The broadest instruction query took about 43 seconds but returned successfully; the current conclusions rely on the fresh `fa658e1e` repair pass below rather than the expired worker, and no fallback-only conclusion is used.
- IDA was read-only. No rename, type mutation, comment mutation, function creation, process management, or database save was requested.

### Gate 1 raw-source-disposition repair evidence

- Historical failure state: supervisor Gate 1 rejected exact SHA `D05ABB27AE83E9C18AFE9A18941471D951BA8D80F97E033E0459D7B95B33590F` because absence of an entry xref had been used as the sole reason to leave two source-shaped child formals blank. That no-code inference is superseded; every underlying byte, boundary, behavior, caller/callee, history, and negative-route fact remains preserved.
- A fresh post-recovery `idb_list` discovered active session `fa658e1e` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `17316`, active/adopted, `is_analyzing:false`. Evidence-time `server_health` returned `status:ok` with auto-analysis, Hex-Rays, and the `2067`-entry string cache ready.
- Bounded `lookup_funcs` reconfirmed that neither `0x0050b140` nor `0x0050b190` has an IDA function object, while adjacent starts `0x0050b080` and `0x0050b1b0` remain independent modeled functions of sizes `0xb9` and `0xff`.
- Bounded instruction walks prove complete independent compiler function shapes. `[0x0050b140,0x0050b18c)` begins `push ebp; mov ebp,esp`, captures `this` from `ecx`, consumes one dword stack argument, preserves `esi/edi`, and ends `retn 4`; `[0x0050b190,0x0050b1a7)` begins `push esi; mov esi,ecx`, consumes no stack argument, and ends `pop esi; retn`. Exact `cc` spans isolate both from their neighbors.
- Exact wildcarded body searches found one occurrence of each body, at its own start. Neither interval is a byte-identical duplicate, adjacent tail/interior, thunk, forwarding stub, EH fragment, jump-table body, or compiler cleanup. Both contain nontrivial NexusTK policy and therefore require retained source.
- The first body has a source-parallel inlined sequence at `0x00511d61-0x00511da3` inside UID0003TO: descriptor `134` stores draw color `143` at MapPane `+0x4c8`, invalidates, presents, sleeps 100 ms, clears the dword, invalidates, and presents again. Map render `0x005094e0` reads the same dword and passes a nonzero value to `GrafPort::SetDrawColor(int)`, resolving the field as `m_mapFlashColor` and the retained method as `MapPane::FlashMapColor(int drawColor)`.
- The second body has a source-parallel inlined completion sequence in UID0001B1's MapRefreshDimmer callback at `0x005149c3-0x005149db`: call `ObjectList::RemoveMarkedVisibleObjects()` and clear MapPane `+0x4cd`. The producer-shaped raw method at `0x0050f460` sends opcode `0x38`, sets `+0x4cd/+0x4ce` to `1/1`, marks visible objects, and prunes marked row objects; UID0003TK also tests/clears `+0x4cd` across map identity/dimension changes. This lifecycle resolves `+0x4cd` as `m_visibleObjectRefreshPending` and the retained no-argument method as `MapPane::FinishVisibleObjectRefresh()`.
- The missing inbound routes remain useful liveness evidence: current `xref_query` returns only each start's local fall-through-to-next-instruction edge, and prior VA/RVA/vtable/table checks remain negative. They now cap exact original spelling and prove no currently identified call site; they do not suppress source or emission.
- Current/archived searches were repeated for both addresses and the new semantic names. Relevant opened matches were UID0003TO, UID0001B1/MapRefreshDimmer, UID0003TK, UID00037V, UID0001AW, UID00023F/ObjectListExtendedTypeLookupHelpers, UID0001D3/ObjectListAccessorsAndSweeps, SurfaceRenderPresentation, `g_pScreenPane`, MapPane class/file/layout, and the current B005 report. No prior direct report supplied a stronger original symbol or a valid compiler/no-source disposition.
- No IDA mutation was performed. The transient pre-recovery `4836cd9f` failure remains incident history only and is not used as evidence.

### Complete-class formal rebase

- Read-only comparison against the latest ordinary managed blocks found Destination 10 UserPane equal to the current 231-line formal plus only the accepted MapPane friendship and exact `+0x13eb3e` bool split; Destination 11 ObjectList equal to the current formal plus only the two accepted declarations; and Destination 13 LivingObjectPane equal to the current formal plus only MapPane friendship.
- During the report-only rebase, Destination 12 ObjectPane was expanded to preserve the current inline `GetObjectId() const` declaration/body in addition to the accepted MapPane forward declaration/friendship. During the authorized callback, Destinations 10-13 were applied to their shared class pages after reread; no concurrent declaration or field was dropped.

### Prior-report search provenance

- Exact terms searched were `00037X`, `UID:00037X`, `0x0050b080`, `0x0050b140`, `0x0050b190`, `MapPaneInteractionMapChangeCore`, `MapPaneFlashRuntimeStateRaw`, `MapPaneRemoveMarkedVisibleObjectsRaw`, `FlashMapColor`, `FinishVisibleObjectRefresh`, `sub_50B080`, `sub_50B1B0`, `sub_50B2B0`, `sub_50B990`, `sub_50BBB0`, `GetObjectScreenPoint`, `GetObjectScreenPosition`, `InteractWithObject`, `SendMovementPacket`, `BuildLocalMovementPath`, `CompactMovementPath`, `ChangeMap`, `MapPane`, `ObjectList`, `UserPane`, and `NexusTK/map/MapPane.cpp`.
- Roots actually searched were central `executed-b-agent-research`, all active `tools/leaser/Agents/Agent-B001/research` through `Agent-B015/research`, `tools/leaser/Agents/Older-Research`, and central invalidated/legacy executed roots. Active roots had one relevant unexecuted B001 UID0002QY lead; legacy/invalidated roots had no direct UID00037X report.
- Every relevant report match was opened and classified:
  - `executed-b-agent-research/B001/B001-MEMTOOL-00506970-MapPaneInputPacketRenderCore.md`: direct parent split/range support, not a direct UID00037X source-quality report; useful for the broad physical parent and first-level child boundary.
  - `executed-b-agent-research/B005/0001AV-SaveUserSettings-empty-emitter-source-quality.md`: incidental executed predecessor/boundary support for exact end `0x0050b078` and following eight-byte alignment.
  - `executed-b-agent-research/B005/0001LL-TargetObjectWithKeyboardPaneMouseEvent-source-quality.md` and `executed-b-agent-research/B005/0001LD-0001LE-SelectObjectWithKeyboardPaneInputHandlers-source-quality.md`: incidental executed caller support for `InteractWithObject`; neither audits the helper body.
  - `executed-b-agent-research/B010/00023F-ObjectListExtendedTypeLookupHelpers-source-quality.md`: incidental executed support for `ObjectList::RemoveMarkedVisibleObjects` and raw prune semantics.
  - `executed-b-agent-research/B001/0001DE-LivingObjectPaneCore-source-quality.md`, `executed-b-agent-research/B001/00007B-LivingObjectPane-class-source-quality.md`, `executed-b-agent-research/B001/0002CF-g_movementSubstepScale.md`, and `executed-b-agent-research/B001/0002R2-LivingObjectPaneRenderFrameMethods-report.md`: incidental executed coordinate/interpolation/type/caller support for the first child.
  - `executed-b-agent-research/B015/0003H4-LivingObjectPaneSendDirectionPacketRawHelper-source-quality.md`, `executed-b-agent-research/B008/0003UY-LivingObjectPaneRawFacingPacketHelper-source-quality.md`, and `executed-b-agent-research/B003/0003UX-LivingObjectPaneRawWaypointPacketHelper-source-quality.md`: incidental executed movement-packet/field-order support; no direct UID00037X coverage.
  - `executed-b-agent-research/B007/0002JS-ObjectListConstructor-source-quality.md`, `executed-b-agent-research/B005/0001D1-ObjectListLifecycle-source-quality.md`, and `executed-b-agent-research/B006/0001D3-ObjectListAccessorsAndSweeps-source-quality.md`: incidental executed constructor, detach, prune, and lifecycle support for `ChangeMap`.
  - `executed-b-agent-research/B012/0001D2-MapPaneSpatialIndex-source-quality.md` and `executed-b-agent-research/B009/0002CD-ObjectListFindByObjectId-source-quality.md`: incidental executed front-row/accessor and id-lookup support for collect/sort behavior.
  - `executed-b-agent-research/B005/0002QJ-MapPaneLoadCompressedMapFile-empty-emitter-source-quality.md` and `executed-b-agent-research/B005/0002QK-MapPaneSaveCompressedMapFile-source-quality.md`: incidental executed paired load/save support for `ChangeMap`; both deliberately leave this direct map-change body to its own audit.
  - `executed-b-agent-research/B003/0003UG-LivingObjectPaneClearLinkedRecordByIndex-source-quality.md`: incidental movement-history support only; it does not describe this opcode-`0x13` target collection.
  - Active `tools/leaser/Agents/Agent-B001/research/0002QY-MotionAnimationTimerTick-empty-emitter-source-quality.md`: unexecuted concurrent lead, not authority. Its then-current `BuildLocalMovementPath`/`CompactMovementPath` wording and some destination-first PacketBuffer examples conflict with this target's direct semantics and current value-first helper contract; this report does not edit the B001 artifact.
- The Gate 1 repair repeated the address/old-name/new-name query over the same central executed, all active `Agent-B*/research`, `Older-Research`, and existing legacy executed/archived roots. The only direct match was this current B005 artifact; no additional report path required opening. Current by-* matches opened for bounded support were UID0003TO `MapPaneHandleObjectMoveEffectPacket`, UID00037V `MapPaneRenderViewCore`, UID0001B1 `MapRefreshDimmerMethods`, UID0003TK `MapPaneHandleEffectMapStatePacket`, UID0001AW `MapPanePacketHandlers`, ObjectList refresh helpers, Surface presentation, `g_pScreenPane`, and MapPane class/file/layout.
- Evidence-based prior-report conclusion: no prior direct UID00037X report resolves the complete seven-method family, including the two starts historically labeled raw, their formal C++, exact split/nesting, target score, or synchronized caller/class/global surface. All opened reports are bounded support or parent/boundary evidence.

### Current documentation and generated baseline

- UID00037X is `85/89`, owner/emitter UID00007Q, reconstructable `TRUE`, blank position, blank Item Summary, blank formal body, and `Nested:8`. Its prose preserves all five modeled starts and raw internals as one convenience aggregate and explicitly leaves names/body blockers open.
- Generated `auto-generated/NexusTK/map/MapPane.cpp` from validator command `000000012015` contains a UID00037X Empty Emitter Marker. This is the expected consequence of a live reconstructable aggregate with a blank body, not evidence that any of the seven independently bounded source methods lacks source.
- UID0001AT is already a non-emitting broad physical parent. UID0001AV ends at `0x0050b078`; `0x0050b078-0x0050b080` is already ignored alignment. UID00037Y begins at `0x0050bce0`, has `Nested:-4`, and `0x0050bcd8-0x0050bce0` is already ignored alignment.

## Target

- Target UID: `00037X`.
- Target path: `by-memory/0x0050b080-0x0050bcd8.MapPaneInteractionMapChangeCore.md`.
- Assignment-time source queue/report row: `auto-generated/-ag-research-tracker.md`, `## by-memory` -> `### Not-Covered Files - Reconstructable`, direct row `85/89`, reports `0`. Tracker/lifecycle state after the callback is validator/supervisor-owned and is not frozen by this report.
- Current supervisor classification: accepted split-first source-quality implementation callback completed by B005; post-callback review and later lifecycle actions remain supervisor-owned.
- Required report path: `tools/leaser/Agents/Agent-B005/research/00037X-MapPaneInteractionMapChangeCore-source-quality.md`.

## Current Target State

- Historical assignment baseline: `85/89`, canonical owner/emitter UID00007Q MapPane, reconstructable true, blank emitter position, blank Item Summary, `Nested:8`, and an empty managed block that generated a UID00037X Empty Emitter Marker despite five modeled functions and two additional independent compiler-shaped source functions.
- Callback-current target: `90/92`, owner `NONE`, reconstructable false, blank emitter/position/formal, exact split-index Item Summary and `Nested:0`; authoritative generated output has no UID00037X body/marker and contains all seven child definitions once.
- Historical blockers at assignment time were provisional helper names, unresolved raw starts, no function/table split, no exact packet/body types, generic MapPane runtime fields, stale movement-path names in UID0003UI, incomplete UserPane/ObjectList declarations, file-static selected-target linkage incompatible with the newly proven MapPane consumer, stale Wave2 `GetObjectScreenPosition`, and no exact score-improvement rationale. This repaired report resolves both formerly raw starts as retained standalone source methods; no source/no-code blocker remains.
- Existing useful evidence preserved: MapPane owner/file route, predecessor/successor boundaries, five modeled starts, the map-id-change SaveCompressedMapFile call, existing select/target caller roles, `m_tileOriginX/Y`, tile-dimension globals, `m_objectList`, and current map load/save dependencies.
- Current callback state: the accepted ordinary by-* pages listed under Changed Files are implemented and scoped-validated. B005 did not manually edit manual coverage, generated output, tracker, audit, supervisor, validator-state, goal, queue, lock, IDA, or lifecycle files; validator-owned registry/coverage/generated refresh side effects are recorded below.

## Executive Recommendation

Accepted and applied recommendation: UID00037X is a non-emitting split index with seven exact address-ordered children. All seven are source-bearing MapPane methods named `MapPane::GetObjectScreenPoint`, `MapPane::FlashMapColor`, `MapPane::FinishVisibleObjectRefresh`, `MapPane::InteractWithObject`, `MapPane::CollectMovementTargetObjectIds`, `MapPane::SortMovementTargetObjectIdsByDistance`, and `MapPane::ChangeMap`. The two unmodeled starts emit complete standalone source because independent prologue/return/padding shapes and nontrivial policy prove source functions; exhaustive entry-route negatives remain liveness and lexical-confidence evidence only.

The source route remains UID0000L3 `NexusTK/map/MapPane.cpp`. UID0003UI in `NexusTK/ui/panels/UserPane.cpp` now uses collect/sort rather than false path-building/compaction names and preserves the packet count-versus-nine-id cap. UserPane, ObjectList, ObjectPane, and LivingObjectPane class blocks received only the exact declaration/access changes needed by these definitions. The selected-object global at `0x0069bf28` remains defined under TargetSelectionInputPanes but now has external linkage because MapPane directly consumes it; the established `s_selectObjectTargetId` spelling remains a lexical-confidence cap rather than triggering a speculative broad rename.

## Supervisor Active Recheck

- Historical recheck basis: the assignment selected UID00037X as the then-current lowest unassigned direct reconstructable tracker row and required report-only, mandatory-MCP, split-first source-quality work before implementation authorization.
- The accepted split repair established before implementation that the broad target is not one source function and must not emit a monolithic body; the callback applied that disposition.
- Every source-bearing subrange has a complete applied destination block. The Gate 1 repair and callback superseded the two invalid blank/no-entry dispositions with complete retained standalone method bodies and exact field/helper contracts.
- The required serial registration procedure completed in address order: `0004Q8`, `0004Q9`, `0004QA`, `0004QB`, `0004QC`, `0004QD`, and `0004QE`. Each real UID was issued before its references were introduced; no brace token remains.

## Inference Research Guidance Check

- IDA facts, current documentation evidence, and source-facing inference are separated throughout this report. Addresses, bytes, hashes, instructions, xrefs, block counts, field offsets, packet widths, and direct call orders are binary facts. Names such as `m_objectInteractionTimerActive`, `m_includeAdjacentMovementTargets`, and `m_mapTransitionState` are best descriptive source inferences.
- Split-first rules control the parent/child disposition. Modeled functions, raw source-shaped bodies, compiler alignment, and the attached switch table are not flattened into one body.
- Current by-* docs were treated as hypotheses where contradicted. In particular, UID0003UI's `BuildLocalMovementPath` and `CompactMovementPath` names are rejected because the helpers collect object IDs and sort by squared distance; they do not build or compact a path.
- The old `by-memory/-report.old.md` Wave2 name `GetObjectScreenPosition` was found and ignored as stale authority. Current source-facing `GetObjectScreenPoint` is supported by the direct body and the accepted LivingObjectPane render caller. No Wave2/Wave3 workflow or stored source was used as evidence.
- Original stripped spellings are not claimed. The lexical caps remain explicit without carrying unresolved body/type blockers forward.

## Heuristic / Inference Reanalysis And Validation

| Issue | Reanalysis and evidence | Resolution |
| --- | --- | --- |
| Broad aggregate | Five modeled starts, two unmodeled but independently compiled source-method starts, six alignment/table distinctions, and independent ABI/caller surfaces exist inside one page. | Split into seven source-method child pages; parent becomes non-emitting index. |
| First helper name | Body converts an ObjectPane map point to screen pixels and applies LivingObjectPane movement interpolation. Existing accepted caller uses `GetObjectScreenPoint`. | `GetObjectScreenPoint`; reject stale `GetObjectScreenPosition` only as historical alias. |
| Unmodeled `0x0050b140` | Independent one-argument `__thiscall` prologue/epilogue and surrounding `cc`; exact body stores/clears dword `+0x4c8`, invalidates/presents twice, and sleeps 100 ms. Render consumes the dword as a GrafPort draw color; UID0003TO inlines the same policy with color 143. Unique full-body search rejects a duplicate/interior/compiler fragment. | Retained standalone `void MapPane::FlashMapColor(int drawColor)`, owner/emitter UID00007Q, source `MapPane.cpp`, blank optional position, `90/92`, complete Destination 3. Missing inbound route caps spelling/liveness only. |
| Unmodeled `0x0050b190` | Independent no-argument `__thiscall` prologue/epilogue and surrounding `cc`; exact body calls ObjectList prune and clears byte `+0x4cd`. UID0001B1 inlines the same completion, while `0x0050f460` sets the byte when beginning visible-object refresh. Unique full-body search rejects a duplicate/interior/compiler fragment. | Retained standalone `void MapPane::FinishVisibleObjectRefresh()`, owner/emitter UID00007Q, source `MapPane.cpp`, blank optional position, `90/92`, complete Destination 4. Missing inbound route caps spelling/liveness only. |
| Interaction helper | Builds fixed six-byte opcode `0x43`, subtype `0x01`, big-endian object-id packet. Human targets are gated by byte `+0x3f1` and timer id 5/4000 ms; other kinds send immediately. | `InteractWithObject`; `m_objectInteractionTimerActive`; preserve no-send human gate and ungated nonhuman branch. |
| Packet helper ABI | Current UID0003YJ and UID0001HU establish value-first scalar writers and Socket member send. | Use value-first `PacketBufferWriteUInt8/UInt32BE` and `g_packetSender->QueueAndSendPacket`. Reject destination-first stale examples. |
| `0x0050b2b0` role | Produces a `vector<unsigned int>` of object IDs from directional visible-row scans or selected-target/adjacent scans. No movement steps are constructed. | `CollectMovementTargetObjectIds`; reject `BuildLocalMovementPath`. |
| Attached data | Code ends at `0x0050b97d`; three-byte NOP alignment precedes four target dwords at `0x0050b980-0x0050b990`, referenced by dispatch at `0x0050b338`. | Keep table/alignment attached to the collection child so the compiler regenerates the switch table. |
| UserPane trailing byte | MapPane directly tests `UserPane+0x13eb3e` exactly against 1 to widen directional lanes and include eight neighbors. | `bool m_includeAdjacentMovementTargets`; split the surrounding reserved tail without size change. |
| Selected target linkage | Collection fallback directly reads `0x0069bf28`. Current formal declares all five globals static in TargetSelectionInputPanes.cpp, which cannot satisfy a MapPane.cpp consumer. | Preserve definition owner but remove `static` only from `s_selectObjectTargetId`; emit an external declaration with the MapPane collector. |
| Null behavior | Selected ID lookup is conditionally appended, but the adjacent-expansion branch dereferences the target without a null guard. | Preserve the stale-id null-dereference edge; do not invent defensive behavior. |
| `0x0050b990` role | Performs ascending selection-sort-like swaps by squared row/column distance to the UserPane. It does not remove or deduplicate IDs. | `SortMovementTargetObjectIdsByDistance`; reject `CompactMovementPath`. |
| Sort preconditions | Every ID is resolved through `ObjectList::FindByObjectId`; dereferences are unchecked. Equal distances do not swap. | Preserve valid-ID precondition and stable equal-distance behavior. |
| Map-change signature | Six source arguments are proved by stack reads and use: map id, width, height, weather mode, transition byte, and load option. Return is unused/void. | `ChangeMap(unsigned short, short, short, unsigned char, unsigned char, int)`. |
| Map-change order | Save/optional music stop occurs only when map ID changes; ObjectList detaches/deletes/recreates; fields store; state updates; changed maps load; all paths draw/invalidate. | Exact Destination 8 body. No null/global guard, rollback, or reordered load/save is added. |
| `+0x414` meaning | Current class prose calls it deferred cleanup; SetMapState owns/recreates it and exit teardown queues it for deferred deletion. | Prefer `m_weatherLayerPane`; historical generic deferred-cleanup wording is superseded, not erased. |
| ObjectList class surface | `ChangeMap` uses `DetachAll`; `FinishVisibleObjectRefresh` uses `RemoveMarkedVisibleObjects`; both roles are already documented but absent from the complete class declaration. | Add both declarations, preserve all current class content and score. |
| Access control | MapPane directly reads ObjectPane/LivingObjectPane fields and UserPane state in binary-shaped source. Current class blocks make those fields protected/private. | Add `friend class MapPane` to the three complete class blocks rather than inventing out-of-line getters absent from the call graph. |
| UID0003UI packet shape | Opcode `0x13`; subtype 4 when direction nonzero or no IDs, otherwise subtype 2/3; elapsed tick quantum 125 capped 40; count is full vector size; only first 9 IDs serialized; local terminator not sent. | Replace full formal body; remove compiler range-check call and false path names. |
| Compiler artifacts | Security cookie, EH chunks, vector destructor/free, range-check failure, jump table, and scalar allocator lowering are generated. | Do not handwrite them. Keep source scopes/standard container/switch semantics. |

Rejected alternatives are: monolithic UID00037X source; ProfileStorage ownership due adjacency; ObjectList ownership of MapPane orchestration; UserPane ownership of receiver-bearing MapPane helpers; target-selection ownership of the collector solely because it reads the selected-id global; compiler/runtime ownership of `ChangeMap`; static file-local `s_selectObjectTargetId`; added null guards; count clamping to nine; ID deduplication; stable-path/compact-path semantics; blanking or classifying either unique source-shaped method as compiler/no-source solely because no inbound route survives; substituting an inline analog for either canonical out-of-line body; and handwritten jump-table/EH/cookie/vector cleanup.

## Evidence Standards Used

- Direct evidence: MCP function bounds, exact raw bytes and SHA-256, instruction/basic-block profiles, Hex-Rays decompilation, code/data xrefs, caller/callee inventories, local table xrefs, global references, adjacent ranges, and modeled/no-function status.
- Corroborating evidence: current by-memory/class/file/type/global pages, current generated MapPane/UserPane output, current manual coverage rows, executed reports opened by exact UID/address/name/source-family search, and active unexecuted report leads treated as non-authoritative.
- Negative evidence: no modeled function, inbound xref, static VA/RVA pointer, vtable/table slot, immediate start reference, or generated call route for the two unmodeled source-method starts; no inbound ordinary caller for `ChangeMap`; no direct prior report; no third-party import source. These route negatives cap liveness and spelling but do not establish no-source.
- Evidence ladder: binary behavior/boundaries control; current accepted support docs establish stable types/names where consistent; repeated sibling/caller vocabulary supports descriptive inference; stale generated/Wave2 names are rejected when behavior disagrees.
- Confidence remains below final-symbol certainty because the executable is stripped and inbound liveness cannot be recovered for two starts. Exact-body uniqueness rejects duplicate output; the remaining limits cap naming/route confidence but do not block exact behavior or first-draft source.

## Evidence Checked

- IDA MCP: fresh `idb_list`/`server_health`; exact bytes over `[0x0050b080,0x0050bcd8)`; modeled starts at `0x0050b080`, `0x0050b1b0`, `0x0050b2b0`, `0x0050b990`, and `0x0050bbb0`; unmodeled independent starts at `0x0050b140` and `0x0050b190`; bounded decompilation/disassembly; exact-body uniqueness searches; function profiles; callers/callees/xrefs; attached table; predecessor/successor padding; referenced ObjectList, MapPane, UserPane, PacketBuffer, Socket, timer, sound, load/save, draw, state, render-consumer, producer, and inline-analog helpers.
- Current docs: UID00037X, UID0001AT, UID0001AV, UID00037Y, UID0003UI, UID0003ZS, UID0003TO, UID00037V, UID0001B1, UID0003TK, UID0001AW, UID00007Q/0000L3 MapPane, UID0000FQ/0000P1 UserPane, UID00009Q/0000M4 ObjectList, UID00009R/0000M5 ObjectPane, UID00007B/0000KU LivingObjectPane, UID00042K MapPaneLayout, UID0002AB selected-target globals, UID00009S ObjectStatusBlob, UID0003YJ PacketBuffer writers, UID0001HU Socket send, Surface presentation, `g_pScreenPane`, Pane invalidation, and relevant load/save/render/timer pages.
- Generated/read-only: `auto-generated/NexusTK/map/MapPane.cpp`, `auto-generated/NexusTK/ui/panels/UserPane.cpp`, and current auto-generated tracker. Manual coverage rows were read in `by-memory`, `by-class`, `by-file`, and `by-type/by-struct` coverage files; none was edited.
- Old reports: exact search terms/roots/matches are recorded under Supporting Research. No prior direct report exists.
- Negative checks: both unmodeled starts were checked for function records, code/data xrefs, immediate/static pointers, vtable/table routes, ordinary generated references, exact byte duplicates, adjacent-function containment, thunk/EH/table/compiler-fragment shape, and canonical inline-only substitution; `ChangeMap` was checked for direct callers/xrefs; selected-target linkage was checked against its current static formal; source ownership alternatives and table/padding splits were tested.
- Historical report-only phase: no implementation validator, lease, report lifecycle command, execute/probe/move/archive command, or IDA mutation was run before Gate 1. The authorized callback later used only the scoped validators and leases recorded below; the one slow bounded instruction query completed and is not an unresolved failure.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID00037X is a non-emitting split index, not one source function. | Very strong | Five modeled/two unmodeled independent source starts, padding/table inventory | UID00037X metadata/status/formal | incorporate | applied |
| C02 | Parent range/hash/boundaries and exact internal inventory are fixed. | Very strong | MCP bytes/hash/functions; UID1AV/37Y boundaries | UID00037X Range Evidence | incorporate | applied |
| C03 | First child is MapPane GetObjectScreenPoint at `[b080,b139)`. | Strong | two caller functions, body, existing accepted caller name | `0004Q8` Destination 2 | incorporate | applied |
| C04 | Screen conversion and movement interpolation use exact axis/global/field semantics. | Very strong behavior; strong names | body, DirectionToTileOffset, globals, LivingObjectPane fields | first child/class/file/layout | incorporate | applied |
| C05 | `[b140,b18c)` is a retained standalone `MapPane::FlashMapColor(int)` method, not a no-code raw child, adjacent interior, inline-only copy, or compiler fragment. | Very strong source shape; strong spelling | independent prologue/retn4/cc, unique bytes, UID3TO inline analog, render consumer | `0004Q9` Destination 3 | incorporate | applied |
| C06 | FlashMapColor stores/clears dword `m_mapFlashColor`, calls `InvalidateRect(NULL)` and `g_pScreenPane->RenderPresentation()` twice around `Sleep(100)`, and preserves the absent-entry liveness caveat. | Very strong behavior/ABI | complete disassembly, Pane slot contract, Surface presentation route, field-use inventory | flash child/MapPane/UID3TO/UID37V support | incorporate | applied |
| C07 | `[b190,b1a7)` is a retained standalone `MapPane::FinishVisibleObjectRefresh()` method, not a no-code raw child, adjacent interior, inline-only copy, or compiler fragment. | Very strong source shape; strong spelling | independent thiscall/retn/cc, unique bytes, UID1B1 inline analog, producer lifecycle | `0004QA` Destination 4 | incorporate | applied |
| C08 | FinishVisibleObjectRefresh calls `ObjectList::RemoveMarkedVisibleObjects()` and clears `m_visibleObjectRefreshPending`; absent entry refs cap liveness only. | Very strong behavior | direct call/store, f460 producer, UID1B1/UID3TK consumers, ObjectList support | finish child/ObjectList/MapPane/UID1B1/UID3TK support | incorporate | applied |
| C09 | Interaction child is exact `[b1b0,b2af)` and emits Destination 5. | Very strong | function/body/callers/packet writers | `0004QB` | incorporate | applied |
| C10 | Human interaction uses timer gate id 5/4000; nonhuman sends immediately; packet is exact six bytes. | Very strong | full CFG, status kind, timer handler, packet ABI | interaction child/UID3ZS/layout | incorporate | applied |
| C11 | Collection child is exact `[b2b0,b990)` with attached align/table and emits Destination 6. | Very strong | function end, table xref/targets, caller | `0004QC` | incorporate | applied |
| C12 | Action mode 2 performs exact directional lane scans over visible front-row buckets. | Very strong | switch/table/body/object list calls | collection child/MapPane support | incorporate | applied |
| C13 | Non-action mode appends selected target then optional eight neighboring-tile objects, preserving null-deref edge. | Very strong | CFG/global xref/body | collection child/UID2AB/UserPane | incorporate | applied |
| C14 | Sort child is exact `[b990,bbb0)` and emits Destination 7. | Very strong | modeled body/caller/callees | `0004QD` | incorporate | applied |
| C15 | Sort is ascending squared distance, stable on ties, no dedup/compaction/null checks. | Very strong | nested loop comparisons and swaps | sort child/UID3UI | incorporate | applied |
| C16 | ChangeMap child is exact `[bbb0,bcd8)` and emits Destination 8. | Very strong | full decompile/EH/function profile | `0004QE` | incorporate | applied |
| C17 | ChangeMap preserves conditional save/music stop and ObjectList detach/delete/recreate order. | Very strong | CFG/callee order/field stores | change child/ObjectList/MapPane | incorporate | applied |
| C18 | ChangeMap stores dimensions/state/id, updates weather, conditionally loads, then draws/invalidates. | Very strong | CFG/callees/field offsets | change child/layout/class/file | incorporate | applied |
| C19 | UID0003UI must use collect/sort names and corrected formal body at `90/92`. | Very strong | sole caller decompile and packet body | UID0003UI Destination 9 | incorporate | applied |
| C20 | UID0003UI count is full vector size while serialization is capped at nine; terminator is local-only. | Very strong | packet stores/loop/send length | UID0003UI/UserPane support | incorporate | applied |
| C21 | UserPane class adds MapPane friendship and exact `+0x13eb3e` bool split without size change. | Strong | direct field reads and exact class layout | UID0000FQ Destination 10 | incorporate | applied |
| C22 | ObjectList class declares DetachAll and RemoveMarkedVisibleObjects. | Strong | direct MapPane calls and current helper docs | UID00009Q Destination 11 | incorporate | applied |
| C23 | ObjectPane class adds MapPane friendship for binary-proven direct type/id access. | Strong | direct field loads; existing ObjectList friendship precedent | UID00009R Destination 12 | incorporate | applied |
| C24 | LivingObjectPane class adds MapPane friendship for binary-proven movement fields. | Strong | direct moving/facing/frame loads | UID00007B Destination 13 | incorporate | applied |
| C25 | `s_selectObjectTargetId` changes from static to external linkage; other four globals stay static. | Very strong linkage; strong spelling | direct MapPane global read and current formal | UID0002AB Destination 14/file support | incorporate | applied |
| C26 | UID0003ZS uses `m_objectInteractionTimerActive` for timer case 5. | Very strong role; strong name | set/schedule/clear chain | UID0003ZS Destination 15 | incorporate | applied |
| C27 | MapPane class records all seven child methods, `FlashMapColor`/`FinishVisibleObjectRefresh` declarations, fields, source evidence, and liveness caps but remains `89/89` with blank broad class block. | Very strong | current class breadth, complete child formals, class rebase | UID00007Q prose | incorporate | applied |
| C28 | MapPane file records exact source order, seven emitted definitions, dependencies, tables, no-code compiler exclusions, and remains `89/85`. | Very strong | address order and source ownership | UID0000L3 prose | incorporate | applied |
| C29 | MapPaneLayout adds `+0x3f1/+0x40c/+0x40d/+0x410/+0x414/+0x4c8/+0x4cd` rows, with `+0x4c8` as `m_mapFlashColor` and `+0x4cd` as `m_visibleObjectRefreshPending`; score/formal unchanged. | Strong | direct reads/writes and producer/consumer/inline lifecycle | UID00042K prose | incorporate | applied |
| C30 | UserPane file records corrected movement-packet route and field/linkage contract, score unchanged `91/92`. | Very strong | caller/body/current class/file | UID0000P1 prose | incorporate | applied |
| C31 | ObjectList file records new declaration surface and target consumers, score unchanged `90/92`. | Very strong | direct calls/current object-list family | UID0000M4 prose | incorporate | applied |
| C32 | Nesting is parent 0, first child +4, later children 0, UID37Y -4; four internal padding rows are ignored. | Very strong | address-sort cumulative nesting and exact CC bytes | UID37X/children/UID37Y/-ignored | incorporate | applied |
| C33 | Stable dependency pages remain verify-only unless reread exposes an exact contradiction, including Pane invalidation, Surface presentation, and `g_pScreenPane`. | Strong | current ObjectStatus/PacketBuffer/Socket/timer/sound/config/render/global docs | named support pages | already-present | already-present |
| C34 | Historical names, missing-entry-route uncertainty, superseded raw/no-code assumptions, no-caller facts, null/count quirks, and compiler exclusions must be preserved. | Very strong | current docs plus direct negative evidence | all changed target/support docs | historicalize | applied |
| C35 | Exact manual coverage text, validator plan/results, generated assertions, and the reconciled callback checklist are supplied. | Very strong | read-only coverage/template/workflow check plus callback command/readback evidence | report sections below | incorporate | applied |

### Callback Verification Notes

| Claim IDs | Destination-specific implementation proof |
| --- | --- |
| C01-C02 | UID00037X now has `90/92`, owner `NONE`, reconstructable `FALSE`, blank emitter/position/formal, exact split inventory and `Nested:0`; scoped validator `000000012152` passed and final refresh `000000012202` generated no UID00037X marker/body. |
| C03-C04 | Validator-issued UID0004Q8 contains Destination 2 byte-for-byte, exact `91/93` metadata, `Nested:4`, screen conversion/interpolation evidence, class/file/layout links, and passed registration `000000012132` plus final scoped validation `000000012196`; generated definition count is one. |
| C05-C06 | UID0004Q9 contains Destination 3 byte-for-byte and the full standalone-source, flash-field, invalidate/present/sleep, inline-analog, render-consumer, absent-entry, and rejected-no-code evidence; registration `000000012135` and corrected scoped validation `000000012137` passed; generated definition count is one. |
| C07-C08 | UID0004QA contains Destination 4 byte-for-byte and the full standalone-source, ObjectList prune, refresh-field, producer/consumer/inline-analog, absent-entry, and rejected-no-code evidence; validator `000000012139` passed, and support validators `000000012183`, `000000012185`, and `000000012186` preserve the lifecycle; generated definition count is one. |
| C09-C10 | UID0004QB contains Destination 5 byte-for-byte, exact `92/94` metadata, packet/status/timer/caller evidence, and passed registration `000000012141` plus final scoped validation `000000012190`; UID0003ZS Destination 15 passed `000000012161`; generated interaction definition and timer field are present once/in the accepted route. |
| C11-C13 | UID0004QC contains Destination 6 byte-for-byte, exact `91/93` metadata, switch-table/directional/selected/adjacent/null-edge evidence, and passed registration `000000012143` plus final scoped validation `000000012191`; UID0002AB and UserPane support passed `000000012160`/`000000012156`; generated definition count is one. |
| C14-C15 | UID0004QD contains Destination 7 byte-for-byte, exact `91/93` metadata and stable ascending squared-distance/no-normalization evidence; registration `000000012146` and final scoped validation `000000012193` passed; UID0003UI caller passed `000000012155`; generated definition count is one. |
| C16-C18 | UID0004QE contains Destination 8 byte-for-byte, exact `91/93` metadata and complete save/music/ObjectList/state/weather/load/draw/EH/order evidence; registration `000000012147` and final scoped validation `000000012194` passed; MapPane/ObjectList support validators passed; generated definition count is one. |
| C19-C20 | UID0003UI now has `90/92`, Destination 9 byte-for-byte and exact collect/sort, subtype, elapsed, full-count/nine-ID cap, local terminator, value-first ABI, and compiler-exclusion evidence; validator `000000012155` passed and UserPane generated output contains exactly one definition. |
| C21 | UID0000FQ contains Destination 10 byte-for-byte with preserved complete class union, MapPane friendship, exact `+0x13eb3e` bool and size guard; validator `000000012156` passed and generated UserPane contains one friendship and one adjacent-target bool declaration. |
| C22 | UID00009Q contains Destination 11 byte-for-byte with preserved class union plus `DetachAll`/`RemoveMarkedVisibleObjects`; validator `000000012157` passed and ObjectList generated output reflects the declarations. |
| C23 | UID00009R contains Destination 12 byte-for-byte with the accepted declaration/friend order and preserved inline `GetObjectId`; final scoped validator `000000012201` passed and ObjectPane generated output refreshed under `000000012202`. |
| C24 | UID00007B contains Destination 13 byte-for-byte with preserved complete class union and MapPane friendship; validator `000000012159` passed and LivingObjectPane generated output refreshed. |
| C25 | UID0002AB contains Destination 14 byte-for-byte at `89/91`; only `s_selectObjectTargetId` lost `static`, the other four definitions remain static, and UID0000OH records the cross-file consumer; validators `000000012160` and `000000012171` passed; generated output has one external selected-id definition and no static selected-id definition. |
| C26 | UID0003ZS contains Destination 15 byte-for-byte and preserves timer case 5 plus the complete set/schedule/clear chain under `m_objectInteractionTimerActive`; validator `000000012161` passed and generated MapPane uses the accepted field. |
| C27-C31 | MapPane class/file/layout, UserPane file, and ObjectList file contain all accepted seven-method, field, source-order, packet, declaration, liveness, compiler-exclusion, and history detail at unchanged support scores; validators `000000012162`, `000000012164`, `000000012165`, `000000012166`, and `000000012167` passed. |
| C32 | Parent/children/successor now use cumulative `0,4,0,0,0,0,0,0,-4`; UID00037Y passed `000000012175`; four internal `cc` spans were added without duplicating predecessor/successor padding and `by-memory/-ignored.md` passed `000000012188`. |
| C33 | The named stable ObjectStatusBlob, PacketBuffer, Socket, TimerHandler, Pane/Surface/screen-pane, sound/config/global, load/save, ObjectList-method, and render dependencies were reread and remained verify-only; no contradiction required an edit. |
| C34 | Every changed target/support page retains the report's bytes, hashes, CFG/caller/callee/xref evidence, route negatives, inline analogs, producer/consumer lifecycles, null/count quirks, historical names, superseded raw/no-code assumptions, rejected alternatives, compiler exclusions, and lexical caps. |
| C35 | The exact supervisor-owned coverage text remains below and was not manually applied; all 31 changed ordinary pages passed scoped validation, all 15 formal blocks compare byte-for-byte, waited refresh `000000012202` passed, generated assertions/hashes and validator-owned side effects are recorded, and every B005 lease was released. |

## Positive Evidence Summary

- Exact target bytes form five IDA-modeled functions, two coherent independently compiled but unmodeled functions, ordinary `0xcc` boundaries, and one compiler switch table attached to the large collection method.
- Receiver offsets and direct MapPane sibling calls prove MapPane ownership for all seven children. UID0000L3 already owns the surrounding coordinate, object-list, render, weather, load, save, and packet integration methods.
- The first body matches accepted LivingObjectPane render use, tile-origin fields, tile pixel globals, and movement-substep scaling.
- The interaction packet has an unambiguous six-byte layout, exact human/nonhuman branch split, timer set/clear chain, and five direct caller sites from select/target input handlers.
- The collect/sort pair has one shared caller that immediately serializes returned object IDs. Directional comparisons, selected-id fallback, adjacent scan, squared-distance ordering, and the nine-ID serialization cap close the false path/compaction names.
- ChangeMap's save/load/state/object-list/draw sequence agrees with executed direct SaveCompressedMapFile, LoadCompressedMapFile, ObjectList lifecycle, SoundManager, and MapPane render support.
- The selected-id direct data reference proves the current file-static linkage is not source-complete across the accepted file split.

## IDA MCP Facts

- Whole parent: `[0x0050b080,0x0050bcd8)`, `3160` bytes, SHA-256 `57486B5C3B189C205C2C5B06C4D60095379D4B3972229A650889C08313B0541F`.
- `0x0050b080-0x0050b139`: 59 instructions, 4 blocks, 2 caller functions/3 call sites, 3 callee records, SHA-256 `9A142FCEC488D085F1CA915C425131C5705E9F5183549EA25C1DFF579D610A78`.
- `0x0050b140-0x0050b18c`: unmodeled independent 76-byte function body, SHA-256 `16C7485D6D080A267BD05D9AD9FC0E8FA35932673D505E64C0E79E23960EEAED`, no recovered inbound route, unique exact body.
- `0x0050b190-0x0050b1a7`: unmodeled independent 23-byte function body, SHA-256 `E8C9F63A32E7C379B7C488002D5EC64FA5EC32E5DDCB14A5C2554CA6925E597B`, no recovered inbound route, unique exact body.
- First unmodeled body: independent `push ebp` frame, one stack argument, MapPane dword `+0x4c8` store/clear, two vtable-`+0x20` null-rect invalidations, two `sub_557140` presentation calls through `dword_67A7CC`, `Sleep(100)`, and `retn 4`; seven leading and four trailing `cc` bytes isolate it.
- Second unmodeled body: independent no-argument `thiscall`, ObjectList pointer load from MapPane `+0x424`, direct `sub_5359E0` prune call, MapPane byte `+0x4cd` clear, and plain `retn`; four leading and nine trailing `cc` bytes isolate it.
- Exact wildcard body searches returned only `0x0050b140` and `0x0050b190` respectively. Neither is contained in the adjacent modeled functions or represented by a byte-identical canonical duplicate.
- `0x0050b1b0-0x0050b2af`: 82 instructions, 5 blocks, 3 caller functions/5 call sites, 7 callees, SHA-256 `9754E713CE8C42CA18B3565D2D095F0734468EDFBECBD5BBBDB6228D644FD423`.
- `0x0050b2b0-0x0050b990`: 532 instructions, 82 blocks, one caller function, 6 callees, SHA-256 `268DD2349753DF0A781DB635366C82DDE06FB4CA3703832B7EFA1F1E1735D64B`; code returns by `0x0050b97d`, alignment/table occupies the tail.
- `0x0050b990-0x0050bbb0`: 183 instructions, 10 blocks, one caller function, 3 callees, SHA-256 `615C7B7B2D6AD6F3E21D4697F4D9C606300A2B180CEA758BA7D29DEBA5DE9E8C`.
- `0x0050bbb0-0x0050bcd8`: 99 instructions, 15 blocks including EH chunks `0x00602707/0x00602712`, no ordinary start caller/xref, 12 callees, SHA-256 `72E14E2A46F72A76A49EBA66828F16D8D5F712A421929191826EC4231B490517`.
- Padding/data facts: seven `cc` bytes `[b139,b140)`, four `[b18c,b190)`, nine `[b1a7,b1b0)`, one `[b2af,b2b0)`, three-byte `0F 1F 00` alignment `[b97d,b980)`, table dwords `[b980,b990)` to `b33f/b44f/b574/b6a5`, and eight `cc` bytes `[bcd8,bce0)`.
- Xref facts: first helper callers are `0x0053a700` and `0x0053bdc0`; interaction callers are `0x005af710`, `0x005afa10`, and `0x005b0290`; collect/sort caller is `0x005a8cf0`; ChangeMap has no ordinary start caller. Absence of a direct `ChangeMap` caller is compatible with vtable/indirect dispatch and does not negate its complete member-source shape.
- Global/type facts: `0x0069bf28` is the SelectObject saved target ID; UserPane `+0x13eb3e` is a one-byte exact-1 expansion gate; ObjectStatusBlob is exactly 68 bytes; PacketBuffer scalar writers are value-first; Socket send is a member taking packet plus short length.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `[0x0050b080,0x0050bcd8)` | UID00037X | non-emitting split index | FALSE | UID0001AT | `90/92` | applied/validated |
| `[0x0050b080,0x0050b139)` | `0004Q8` | MapPane GetObjectScreenPoint | TRUE | UID00037X | `91/93` | registered/applied, Destination 2 |
| `[0x0050b139,0x0050b140)` | by-memory/-ignored | alignment | FALSE | n/a | n/a | exact ignored row applied |
| `[0x0050b140,0x0050b18c)` | `0004Q9` | MapPane FlashMapColor | TRUE | UID00037X | `90/92` | registered/applied, Destination 3 |
| `[0x0050b18c,0x0050b190)` | by-memory/-ignored | alignment | FALSE | n/a | n/a | exact ignored row applied |
| `[0x0050b190,0x0050b1a7)` | `0004QA` | MapPane FinishVisibleObjectRefresh | TRUE | UID00037X | `90/92` | registered/applied, Destination 4 |
| `[0x0050b1a7,0x0050b1b0)` | by-memory/-ignored | alignment | FALSE | n/a | n/a | exact ignored row applied |
| `[0x0050b1b0,0x0050b2af)` | `0004QB` | MapPane InteractWithObject | TRUE | UID00037X | `92/94` | registered/applied, Destination 5 |
| `[0x0050b2af,0x0050b2b0)` | by-memory/-ignored | alignment | FALSE | n/a | n/a | exact ignored row applied |
| `[0x0050b2b0,0x0050b990)` | `0004QC` | collect movement target object IDs plus switch table | TRUE | UID00037X | `91/93` | registered/applied, Destination 6 |
| `[0x0050b990,0x0050bbb0)` | `0004QD` | sort movement target IDs by distance | TRUE | UID00037X | `91/93` | registered/applied, Destination 7 |
| `[0x0050bbb0,0x0050bcd8)` | `0004QE` | MapPane ChangeMap | TRUE | UID00037X | `91/93` | registered/applied, Destination 8 |
| `[0x0050bcd8,0x0050bce0)` | existing by-memory/-ignored | alignment | FALSE | n/a | n/a | verify-only |
| `[0x0050bce0,0x0050e320)` | UID00037Y | successor tile/object-grid aggregate | TRUE | UID0001AT | `87/89` | closure note synchronized; `Nested:-4` preserved |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0053a79a`, `0x0053a849`, `0x0053bde2` | calls `0x0050b080` | LivingObjectPane render/bounds consumers of exact screen point helper. |
| `0x0050b080` | calls ObjectPane GetMapPosition and DirectionToTileOffset | map-to-screen conversion plus moving-living interpolation. |
| `0x0050b140` | no start xref; calls Pane invalidation, Surface presentation, and Sleep | retained standalone FlashMapColor source body; missing route caps liveness only. |
| `0x0050b190` | no start xref; calls `0x005359e0` | retained standalone FinishVisibleObjectRefresh source body; missing route caps liveness only. |
| `0x005094e0` | reads MapPane `+0x4c8`, passes nonzero value to `GrafPort::SetDrawColor(int)` | proves the dword is a map-flash draw color, not generic runtime state. |
| `0x00511d61-0x00511da3` | UID0003TO stores color 143, invalidates/presents, sleeps, clears, invalidates/presents | source-parallel inline FlashMapColor policy; corroborates semantics but does not replace the unique out-of-line body. |
| `0x0050f49c` | stores word `0x0101` to MapPane `+0x4cd/+0x4ce` before visible-object mark/prune work | producer proves `+0x4cd` is pending visible-object refresh state. |
| `0x005149c3-0x005149db` | UID0001B1 calls RemoveMarkedVisibleObjects and clears `+0x4cd` | source-parallel inline FinishVisibleObjectRefresh completion; not a canonical replacement. |
| UID0003TK packet path | tests and clears MapPane `+0x4cd` across map identity/dimension changes | independent lifecycle consumer/clear corroboration. |
| `0x005af710`, `0x005afa10`, `0x005b0290` | five call sites to `0x0050b1b0` | select/target keyboard/mouse confirmation invokes object interaction. |
| `0x0050b1b0` | GetSpriteConfig, PacketBuffer writes, Socket send, timer schedule | exact interaction packet and human cooldown. |
| `0x005a8cf0` | calls `0x0050b2b0` then `0x0050b990` | UserPane movement sender collects then sorts object IDs. |
| `0x0050b2b0` | GetClampedVisibleTileBounds, GetFrontRowBucket, GetMapPosition, vector append, FindByObjectId | directional or selected-target collection. |
| `0x0050b338` | data xref to `0x0050b980` table | attached direction-switch table with four targets. |
| `0x0050b990` | FindByObjectId and GetMapPosition | distance comparator/sort with unchecked valid-ID assumption. |
| `0x0050bbb0` | no ordinary start caller/xref | likely indirect/member route; behavior and receiver remain fully source-shaped. |
| `0x0050bbe7` | calls UID0002QK only if map id differs | save-before-change behavior. |
| `0x0050bc1a`, `0x0050bc55` | ObjectList DetachAll and constructor | old index teardown and replacement. |
| `0x0050bc8x-0x0050bcb4` | SetMapState, conditional load, DrawVisibleTiles | state/load/render tail; exact order preserved in Destination 8. |

## Documentation Evidence And IDA Status

- Current supporting docs correctly establish MapPane ownership/source file, canonical dimensions/origin/object-list fields, exact load/save bodies, ObjectStatusBlob size/status kind, ObjectList constructor/find/accessor/prune families, value-first PacketBuffer writers, Socket member send, and UserPane movement ticks/action mode.
- UID00037X is stale/incomplete because it treats independent source functions and raw helpers as one emitting aggregate, leaves the formal and Item Summary blank, and carries `Nested:8` rather than a cumulative one-level child plan.
- UID0003UI is stale because its formal names object-ID collection as path construction and distance ordering as compaction, omits the local terminator, and handwrites a compiler range-check failure.
- UID0002AB is source-incomplete only for linkage: `s_selectObjectTargetId` has a direct cross-file MapPane consumer and cannot remain `static`. The other four definitions remain file-local.
- MapPane class/file/layout pages have the right broad owner but need bounded target evidence and field corrections, especially `+0x414` weather-layer identity. Their broad scores and blank MapPane class formal remain appropriate.
- Historical generated baseline contained a UID00037X Empty Emitter Marker from the old aggregate. Waited callback refresh `000000012202` superseded that baseline with seven ordinary child definitions and no UID00037X body or marker; the split-index parent remains non-emitting by metadata.

## Ranked Ownership Analysis

### 1. UID00007Q MapPane / UID0000L3 MapPane.cpp

- Evidence for: every body uses a MapPane receiver/fields; helper neighborhood is MapPane; callers are MapPane consumers; the file already owns coordinate, object list, packet, timer, weather, load/save, and draw families; ChangeMap orchestrates MapPane-owned state.
- Evidence against: two unmodeled starts have no recovered inbound entry route, and stripped symbols prevent exact private spelling. These limit lexical/liveness confidence, not source retention, ownership, or emission.
- Result: direct owner and emitter for all seven child methods.

### 2. UID0000FQ UserPane / UID0000P1 UserPane.cpp

- Evidence for: sole collect/sort caller is UserPane movement packet sender; collector reads UserPane action/facing/expansion state.
- Evidence against: all candidate target helpers use MapPane receiver fields and ObjectList ownership through MapPane. UserPane is a caller/consumer.
- Result: support owner for UID0003UI and its fields, rejected as target child owner.

### 3. UID00009Q ObjectList / UID0000M4 ObjectList.cpp

- Evidence for: collector/sorter/prune/change methods call ObjectList APIs and own required declaration surface.
- Evidence against: ObjectList is reached through MapPane `m_objectList`; it does not own packet, weather, active-map, tile-origin, or render state.
- Result: dependency/support declarations only.

### 4. TargetSelectionInputPanes / ProfileStorage / generic runtime

- TargetSelectionInputPanes owns the selected-id definition and selection UI, but one global read does not transfer a MapPane method.
- ProfileStorage is only the predecessor source island; exact padding and receiver behavior reject adjacency ownership.
- CRT/STL/EH/timer/socket/sound/render libraries are callees or compiler lowering, not owners of the MapPane policy.
- Result: rejected direct owners.

## Source Placement

- Place all seven child definitions in `NexusTK/map/MapPane.cpp` in exact address order. `FlashMapColor` and `FinishVisibleObjectRefresh` retain their no-inbound-route facts in documentation while emitting their unique, independently compiled source bodies.
- Place the corrected UID0003UI definition in `NexusTK/ui/panels/UserPane.cpp` and the class field/friendship update in the UserPane header block.
- Keep ObjectList, ObjectPane, and LivingObjectPane class declarations under their current `NexusTK/map` routes; add only the accepted declarations/friendship needed by this source.
- Keep the selected-target global definition under `NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp`, but give `s_selectObjectTargetId` external linkage and declare it in the MapPane collector block. This is the minimum source-complete response to the direct cross-translation-unit read.
- Reject a new interaction/path/map-change source file: the target functions are interleaved inside the existing MapPane method family and share its private state.
- Reject moving the selected-id definition to MapPane: selection panes remain its producers/primary owner, and external linkage is sufficient.

## Range / Split / Padding / Reclassification Analysis

- Exact parent bounds remain `[0x0050b080,0x0050bcd8)`. Predecessor `[0x0050b078,0x0050b080)` and successor `[0x0050bcd8,0x0050bce0)` are already documented `cc` alignment and are not absorbed.
- Seven child ranges are exact and non-overlapping. The first child has validator syntax `Nested:4`; all six later children have `Nested:0`. UID00037X is `Nested:0`; UID00037Y remains `Nested:-4`. In address-sort order this opens one level at the first child and closes it at the following sibling without treating child count as nesting.
- Add internal ignored rows for `[b139,b140)`, `[b18c,b190)`, `[b1a7,b1b0)`, and `[b2af,b2b0)` only. They are exact compiler/linker `cc` alignment.
- Keep `[b97d,b980)` and `[b980,b990)` inside the collection child: the three-byte NOP and four-dword table are compiler-generated support for that method's direction switch, with a direct data xref from its dispatch.
- Parent reclassification to reconstructable false prevents a duplicate aggregate emitter. All seven children are reconstructable/emitting; the two unmodeled starts remain explicitly route-negative but source-bearing because independent prologue/return/padding shapes, unique bytes, policy semantics, and parallel inline lifecycles disprove the former no-source inference.
- Child registration completed serially in address order as `0004Q8`, `0004Q9`, `0004QA`, `0004QB`, `0004QC`, `0004QD`, and `0004QE`. Each page was registered before its first cross-reference; no unresolved brace token or pre-reference remains.

## Negative Evidence Summary

- No function record, inbound code/data xref, immediate/static VA or RVA pointer, vtable slot, table entry, or generated call reaches starts `0x0050b140` or `0x0050b190`. This proves no currently identified entry route, not absence of original source. Their independent compiler shapes, unique body matches, and nontrivial policy require retained standalone definitions; inline analogs validate semantics without being substituted as canonical bodies.
- No ordinary caller/xref reaches `0x0050bbb0`. This does not justify blank C++ because the complete EH-backed member body, MapPane receiver, state sequence, and likely indirect dispatch are source-shaped; it only caps route confidence.
- No body constructs movement steps, removes duplicate IDs, compacts invalid entries, clamps serialized count to nine, or checks each sort lookup for null. Those attractive normalizations are rejected.
- No null guard protects the selected target before the optional adjacent scan. Adding one would change a real stale-id failure edge.
- No evidence supports ProfileStorage, ObjectList, UserPane, TargetSelectionInputPanes, Socket, TimerMgr, SoundManager, zlib, CRT, or STL as direct owners of the target MapPane bodies.
- No symbol proves exact private spellings. Names are behaviorally specific and source-quality, but lexical confidence remains below final.
- No third-party import applies. All source-bearing behavior is NexusTK integration code.

## IDA Rename / Type / Comment Recommendations

- If a later supervisor-authorized IDA mutation pass is performed, preferred function names are the seven child names used by Destinations 2-8, including `FlashMapColor` and `FinishVisibleObjectRefresh`. This report does not mutate IDA or create function objects.
- Preferred comments for `0x0050b140` and `0x0050b190` identify retained standalone MapPane methods and preserve the missing-entry-route caveat; they must not restate the superseded blank/no-source conclusion.
- Preferred field names are `m_objectInteractionTimerActive` at `+0x3f1`, `m_mapTransitionState` at `+0x40c`, `m_weatherMode` at `+0x40d`, `m_weatherType` at `+0x410`, `m_weatherLayerPane` at `+0x414`, `m_mapFlashColor` at `+0x4c8`, `m_visibleObjectRefreshPending` at `+0x4cd`, and `m_includeAdjacentMovementTargets` at UserPane `+0x13eb3e`.
- Keep `s_selectObjectTargetId` spelling for current source synchronization but change its linkage; a broad `g_` rename is not justified without updating all producer/consumer source together and without original symbols.
- Leave compiler EH chunks, security-cookie support, vector helper lowering, jump-table entries, and alignment unnamed as standalone source methods.

## First-Draft C++ Recommendation

- Eligible source bodies: all seven MapPane children and UID0003UI. Only the non-reconstructable UID00037X split-index parent remains blank; missing inbound routes at two children are liveness evidence, not no-code proof.
- Exactly 15 destination-specific managed blocks follow. They are the only accepted and applied C++/declaration/formal changes in this callback, and all fifteen compare byte-for-byte with their current destination blocks. No C++ draft or declaration change exists only in prose.
- Third-party import: not applicable; no vetted external static source corresponds to this product-code family.
- The blocks use established project types, value-first packet writers, Socket member send, standard vector source, direct binary-shaped friend access, and ordinary C++ scopes. They omit compiler lowering and preserve every observed edge.

### Destination 1 - UID00037X parent

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 10 - UID0000FQ `by-class/UserPane.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class MapPane;
struct PaneKeyEvent;
struct ServerMessageEvent;

static bool __stdcall HandleUIPanelSwitchPacket(
    const unsigned char *packet);
static void SendDirectionPacket(unsigned char direction);

struct LinkedPlayerRecord
{
    unsigned int objectId;                // +0x000
    wchar_t name[128];                    // +0x004
    bool active;                          // +0x104
    unsigned char reserved105;
    unsigned short field106;
    unsigned char state108[7];
    unsigned char reserved10f;
    unsigned short field110;
    unsigned char field112;
    unsigned char reserved113;
    unsigned short field114;
    unsigned char field116;
    unsigned char reserved117;
    unsigned short field118;
    unsigned char field11a;
    unsigned char reserved11b;
    unsigned int value11c;
    unsigned int value120;
    unsigned int value124;
    unsigned int value128;
};

struct LocalInventorySlotRecord
{
    unsigned char active;                 // +0x000
    unsigned char reserved001;
    unsigned short itemId;                // +0x002
    unsigned char iconStyle;              // +0x004
    unsigned char reserved005;
    wchar_t displayName[80];              // +0x006
    wchar_t secondaryText[80];            // +0x0a6
    wchar_t tertiaryText[80];             // +0x146
    unsigned char reserved1e6[2];
    unsigned int quantityOrCount;         // +0x1e8
    unsigned char quantityPromptFlag;     // +0x1ec
    unsigned char reserved1ed[3];
    unsigned int value1f0;                // +0x1f0
    unsigned int value1f4;                // +0x1f4
    unsigned char targetMode;             // +0x1f8
    unsigned char reserved1f9[3];
};

struct MovementWaypointSegment
{
    int startX;
    int startY;
    int endX;
    int endY;
};

struct SpellCommandSlotRecord
{
    unsigned char active;                 // +0x000
    unsigned char reserved001[3];
    int inputKind;                        // +0x004
    unsigned char reserved008[0xa0];
    wchar_t prompt[80];                   // +0x0a8
};

struct LocalMovementHistoryRecord
{
    unsigned char active;
    unsigned char reserved01[3];
    int tileY;
    int tileX;
    unsigned char direction;
    unsigned char reserved0d[3];
};

class UserPane : public LivingObjectPane
{
public:
    enum UserTimerMessage
    {
        kUserPaneMovementStep = 20
    };

    UserPane();
    virtual ~UserPane();

    virtual void OnBoundsChanged(const RectBounds *bounds);
    virtual void OnClipBounds(RectBounds *clip, RectBounds *out);
    virtual void ShowNameLabel();
    virtual void HideNameLabel();
    virtual bool OnKeyEvent(const PaneKeyEvent *event);
    virtual bool OnServerMessage(const ServerMessageEvent *event);
    virtual bool OnAnimationStep(int message, int frameOrDirection, int aux);
    virtual MapPane *GetMapPane();

    void SendGiveItemPacket(signed char slot, bool allItems);
    void SendDropItemPacket(signed char slot, bool allItems);
    CollectionPlayerDataView &GetCollectionData();
    const CollectionPlayerDataView &GetCollectionData() const;

    MapPoint *GetViewportPosition(MapPoint *outPosition) const;
    void ProcessMovement(unsigned char direction);
    void InitializeWalkAnimation(unsigned char direction);
    void StartDirectionalAnimation(unsigned char direction);
    LocalInventorySlotRecord *GetInventorySlotAddress(char inventorySlot);
    void DispatchConfiguredShortcutHotkey(short hotkeyNumber, int unused);
    void ExecuteHotkeyAction(short hotkey);
    void UseInventorySlot(unsigned char slot);
    void UseCommandSlot(unsigned char slot);
    void TryPerformAction();
    bool WarpToPosition(int x, int y, int viewportColumn, int viewportRow);
    LocalMovementHistoryRecord *GetActiveMovementHistoryRecordByIndex(
        unsigned char recordIndex);
    void ClearAllMovementHistoryRecords();
    void ClearMovementHistoryRecordByIndex(int recordIndex);
    void UpdateScreenPosition();
    void SendMovementPacket(unsigned char direction);
    void TryDispatchFunctionKeyShortcut(
        unsigned short functionKeyOrdinal, unsigned int currentTick);
    void CopyDeferredUserListPacket(
        const unsigned char *packetData, size_t packetSize);
    bool ParsePlayerSettingsPacket(const unsigned char *packet);
    bool ParseInventorySlotUpdatePacket(const unsigned char *packet);
    bool HandleServerEntryPacket(const unsigned char *packet);
    bool HandleWarpPacket(const unsigned char *packet);
    bool HandleMovementReplyPacket(const unsigned char *packet);
    bool HandleExtendedMovementReplyPacket(const unsigned char *packet);
    bool HandleChatMessagePacket(const unsigned char *packet);
    bool HandleUserListPacket(const ServerMessageEvent *event);
    bool HandlePositionSyncPacket(const unsigned char *packet);
    bool ParseLinkedObjectsPacket(const unsigned char *packet);
    void SendMovementWaypointPacket(
        unsigned char direction, unsigned short token,
        const MovementWaypointSegment *segment);
    void SendFaceDirectionPacket(unsigned char direction);
    void SendAutoFaceDirectionPacket();
    void SendActionPacketWithAutoFace();
    void SendAttackTargetPacket(unsigned char action);

private:
    friend class MapPane;

    SpellCommandSlotRecord *GetSpellCommandSlotRecord(unsigned char slot)
    {
        return &m_spellCommandSlots[slot - 1];
    }

    void ClearMovementHistoryToken()
    {
        m_movementState[2] = 0;
        m_movementState[3] = 0;
    }

    void SetMovementReplyState()
    {
        m_movementState[1] = 1;
        m_movementState[2] = 1;
    }

    bool IsDirectionDelayActive() const
    {
        return m_movementState[4] != 0;
    }

    void SetDirectionDelayActive(bool active)
    {
        m_movementState[4] = active ? 1 : 0;
    }

    unsigned char m_userPaneBaseTail[0x0c];       // 0x20c
    LinkedPlayerRecord m_linkedPlayers[50];       // 0x218
    signed char m_linkedPlayerCount;              // 0x3cb0
    unsigned char m_preCollectionState[0x213];    // 0x3cb1
    int m_localPlayerHitRadius;                   // 0x3ec4
    CollectionPlayerDataView m_collectionData;   // 0x3ec8
    int m_screenX;                                // 0x1340cc
    int m_screenY;                                // 0x1340d0
    unsigned int m_screenState;                   // 0x1340d4
    RectBounds m_screenHitBounds;                 // 0x1340d8
    RectBounds m_screenLowerHitBounds;            // 0x1340e8
    MapPane *m_mapPane;                           // 0x1340f8
    unsigned char m_playerSettingsState[8];       // 0x1340fc
    LocalInventorySlotRecord m_inventorySlots[52];// 0x134104
    SpellCommandSlotRecord m_spellCommandSlots[52];// 0x13a834
    bool m_spellCommandSlotsReady;                // 0x13ead4
    unsigned char m_preViewportState[3];          // 0x13ead5
    int m_viewportColumn;                         // 0x13ead8
    int m_viewportRow;                            // 0x13eadc
    int m_movementLimitTop;                       // 0x13eae0
    int m_movementLimitLeft;                      // 0x13eae4
    int m_movementLimitBottom;                    // 0x13eae8
    int m_movementLimitRight;                     // 0x13eaec
    unsigned char m_movementState[5];             // 0x13eaf0
    unsigned char m_preActionTickState[3];        // 0x13eaf5
    unsigned int m_lastActionTick;                // 0x13eaf8
    unsigned char m_preWhisperHistory[8];         // 0x13eafc
    List *m_whisperHistoryOther;                  // 0x13eb04
    List *m_outgoingWhisperRecipientHistory;      // 0x13eb08
    List *m_incomingWhisperSenderHistory;         // 0x13eb0c
    unsigned char m_whisperHistorySource;         // 0x13eb10
    unsigned char m_preMovementHistory[3];        // 0x13eb11
    LocalMovementHistoryRecord *m_movementHistoryRecords; // 0x13eb14
    int m_movementHistoryCapacity;                // 0x13eb18
    unsigned char m_movementHistoryWriteIndex;    // 0x13eb1c
    unsigned char m_movementHistoryState[3];      // 0x13eb1d
    unsigned char *m_deferredUserListPacket;      // 0x13eb20
    size_t m_deferredUserListPacketSize;          // 0x13eb24
    int m_deferredUserListCount;                  // 0x13eb28
    unsigned int m_deferredUserListDeadline;      // 0x13eb2c
    bool m_deferredUserListActive;                // 0x13eb30
    unsigned char m_preMovementTicks[3];          // 0x13eb31
    unsigned int m_lastMovementSendTick;          // 0x13eb34
    unsigned int m_lastMovementInputTick;         // 0x13eb38
    unsigned char m_actionMode;                   // 0x13eb3c
    unsigned char m_userPaneTrailingState0;       // 0x13eb3d
    bool m_includeAdjacentMovementTargets;        // 0x13eb3e
    unsigned char m_userPaneTrailingState2[0x45]; // 0x13eb3f
};

typedef char LinkedPlayerRecordSizeMustBe300[
    sizeof(LinkedPlayerRecord) == 0x12c ? 1 : -1];
typedef char LocalInventorySlotRecordSizeMustBe508[
    sizeof(LocalInventorySlotRecord) == 0x1fc ? 1 : -1];
typedef char SpellCommandSlotRecordSizeMustBe328[
    sizeof(SpellCommandSlotRecord) == 0x148 ? 1 : -1];
typedef char LocalMovementHistoryRecordSizeMustBe16[
    sizeof(LocalMovementHistoryRecord) == 0x10 ? 1 : -1];
typedef char UserPaneSizeMustBe1305476[
    sizeof(UserPane) == 0x13eb84 ? 1 : -1];

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 11 - UID00009Q `by-class/ObjectList.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
typedef unsigned int ObjectListKey;

class List;
class ObjectPane;

class ObjectList : public LObject
{
public:
    ObjectList(int gridWidth, int gridHeight);
    virtual ~ObjectList();

    bool HasValidGridOrigin();
    void AddObjectPane(ObjectPane *object);
    void RemoveObjectPane(ObjectPane *object);
    ObjectPane *ResolveObjectListKey(ObjectListKey key);
    ObjectListKey GetTypedObjectKey(ObjectPane *object);
    ObjectPane *FindByObjectId(int objectId);
    bool ContainsTypedObject(ObjectPane *object);
    void DetachAll(ObjectPane *preserveObject);
    void RemoveMarkedVisibleObjects();

    List *GetPrimaryCellList();
    List *GetSecondaryCellList();
    List *GetPrimaryRowBucket(int row);
    List *GetSecondaryRowBucket(int row);
    List *GetVisibleObjectList();
    List *GetSecondaryGlobalList();
    List *GetAlternateGlobalList();
    List *GetTertiaryGlobalList();
    List *GetQuaternaryGlobalList();
    List *GetQuinaryGlobalList();
    List *GetFrontRowBucket(int row);
    List *GetBackRowBucket(int row);

private:
    static const ObjectListKey kObjectListKeyNotFound = 0xffffffffu;

    ObjectListKey FindStaticObjectKey(ObjectPane *object);
    ObjectListKey FindLivingObjectKey(ObjectPane *object);
    ObjectListKey FindItemObjectKey(ObjectPane *object);
    ObjectListKey FindFlyingObjectKey(ObjectPane *object);
    ObjectListKey FindPrimaryEffectObjectKey(ObjectPane *object);
    ObjectListKey FindSecondaryEffectObjectKey(ObjectPane *object);
    ObjectListKey FindBalloonObjectKey(ObjectPane *object);
    ObjectListKey FindHitBarObjectKey(ObjectPane *object);
    ObjectListKey FindDamageNumberObjectKey(ObjectPane *object);

    int m_minX;
    int m_minY;
    int m_gridWidth;
    int m_gridHeight;
    List *m_itemObjects;
    List *m_flyingObjects;
    List **m_primaryEffectRows;
    List **m_secondaryEffectRows;
    List **m_livingObjectRows;
    List **m_staticObjectRows;
    List *m_balloonObjects;
    List *m_hitBarObjects;
    List *m_damageNumberObjects;
    List *m_objectInfoObjects;
    List *m_lightingObjects;
    List *m_soundObjects;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 12 - UID00009R `by-class/ObjectPane.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
enum ObjectPaneType
{
    kObjectPaneTypeItem = 0,
    kObjectPaneTypeFlying = 1,
    kObjectPaneTypePrimaryEffect = 2,
    kObjectPaneTypeLiving = 3,
    kObjectPaneTypeSecondaryEffect = 4,
    kObjectPaneTypeStatic = 5,
    kObjectPaneTypeBalloon = 6,
    kObjectPaneTypeHitBar = 7,
    kObjectPaneTypeDamageNumber = 8,
    kObjectPaneTypeObjectInfo = 9,
    kObjectPaneTypeLighting = 10,
    kObjectPaneTypeSound = 11
};

class MapPane;
class ObjectList;
class SoundObjectPane;
class GrafPort;
struct MapPoint;

class ObjectPane : public Pane
{
    friend class MapPane;
    friend class ObjectList;

public:
    ObjectPane(unsigned char objectType,
               int objectId,
               int mapX,
               int mapY);
    virtual ~ObjectPane() = 0;

    MapPoint *GetMapPosition(MapPoint *outPosition) const;
    int GetObjectId() const
    {
        return m_objectId;
    }
    ObjectPane *GetAttachedObject() const;
    void SetSoundObjectPane(SoundObjectPane *soundObjectPane);
    void ClearSoundObjectPane();

    virtual void UpdateRenderRegion(const RectBounds *bounds);
    virtual void InvalidateRect(const RectBounds *bounds);
    virtual void SetBounds(const RectBounds *bounds,
                           const RectBounds *clipBounds);
    virtual void AttachObject(ObjectPane *attachedObject);
    virtual void DetachObject();
    virtual void ClearOutputRects(RectBounds *firstBounds,
                                  RectBounds *secondBounds);
    virtual void SetObjectData(const RectBounds *objectData);
    virtual RectBounds *GetObjectData(RectBounds *outObjectData) const;
    virtual void RenderFrame(GrafPort *target,
                             const RectBounds *bounds)
    {
    }
    virtual RectBounds *GetEmptyRect(RectBounds *outBounds) const;
    virtual void DrawSpriteFrame(GrafPort *target,
                                 const RectBounds *bounds)
    {
    }
    virtual void SetMapPosition(int mapX, int mapY);

protected:
    unsigned char m_objectType;
    int m_objectId;
    int m_mapX;
    int m_mapY;
    RectBounds m_objectDataRect;
    ObjectPane *m_attachedObject;
    float m_attachmentHeightOffset;
    SoundObjectPane *m_soundObjectPane;
    unsigned char m_transientObjectFlag;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 13 - UID00007B `by-class/LivingObjectPane.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Motion;
class List;
class AttachedObjectPane;
class GrafPort;
struct NxRect;

class LivingObjectPane : public ObjectPane
{
public:
    enum TimerMessage
    {
        kLivingTimerForwardStep = 0x41645746,
        kLivingTimerBoxStep = 0x41534246,
        kLivingTimerDirectionDelay = 0x43684469,
        kLivingTimerFrameAnimation = 0x446e4146,
        kLivingTimerRefresh = 0x52654461
    };

    class BoxRotator : public FrameHandler
    {
    public:
        explicit BoxRotator(LivingObjectPane *owner) : m_owner(owner) {}
        virtual ~BoxRotator() {}

        virtual void Advance(int frame);
        void Start();
        void Stop();

    private:
        friend class LivingObjectPane;
        LivingObjectPane *m_owner;
    };

    LivingObjectPane(
        int objectId,
        int mapX,
        int mapY,
        const ObjectStatusBlob &objectStatus,
        unsigned char facing);
    LivingObjectPane(int objectId, int mapX, int mapY, unsigned char facing);
    virtual ~LivingObjectPane();

    void GetSpriteConfig(ObjectStatusBlob *out) const;
    bool SetSpriteConfig(const ObjectStatusBlob *objectStatus, unsigned char facing);
    void InitializeSpriteConfig(const ObjectStatusBlob *objectStatus, unsigned char facing);
    bool HasGMNameSuffix() const;

    void SetMovingState(bool moving);
    void SetLinkedGroundObject(ObjectPane *pane);
    void InsertType2AttachedObject(AttachedObjectPane *pane);
    void InsertType4AttachedObject(AttachedObjectPane *pane);
    void SetLinkedShadowObject(ObjectPane *pane);
    void SetLinkedEpfObject(ObjectPane *pane);
    void ReplaceLinkedNameplateObject(ObjectPane *pane);
    void DestroyLinkedObjects();
    void ClearAttachedObjects();

    void AddMotion(Motion *effect);
    void RemoveMotion(Motion *effect);
    void ClearAllEffects();
    void SetCurrentMotion(Motion *effect);
    void SetHighlightState(bool highlighted);
    void ShowDamageEffect(int value, short soundId);
    bool BeginMoveTo(int x, int y, unsigned char facing, short stepDelay);
    void SetFacing(unsigned char facing);
    void PlayAnimation(unsigned int animationGroup);
    void PlayFacingAnimation();
    void PlayDeathAnimation();
    void RequestNameplateEffect();
    void RemoveSpecialEffect();
    void ScheduleBoxRotationStep();
    void CancelBoxRotationStep();
    void ApplyLinkedObjectMode(int mode);
    void SyncPositionToLinkedObjects();
    void RefreshAllLinkedObjects();

    virtual void GetRenderBounds(NxRect *imageRect, NxRect *screenRect) const;
    virtual void RenderFrame(GrafPort *target, const RectBounds *bounds);
    virtual RectBounds *ComputeRenderBounds(RectBounds *outBounds);
    virtual void DrawSpriteFrame(GrafPort *target, const RectBounds *bounds);
    virtual void SetMapPosition(int x, int y);
    virtual void SetSpriteAttribute(unsigned char value);
    virtual void PlayActionAnimationOrEffect(unsigned action, int value, unsigned char facing);
    virtual void ShowName();
    virtual void HideName();
    virtual void PropagateLinkedObjectMode(int mode);
    virtual bool OnTimer(int timerId, int arg0, int arg1);

private:
    friend class MapPane;
    friend class Motion;

    bool TryStepForward();

    unsigned char m_nameState;                  // 0x128
    wchar_t m_nameBuffer[33];                   // 0x12a
    unsigned int m_nameStateToken;              // 0x16c
    List *m_type2AttachedObjects;                // 0x170
    List *m_type4AttachedObjects;                // 0x174
    ObjectStatusBlob m_objectStatus;             // 0x178
    List *m_activeEffects;                       // 0x1bc, Motion * values
    Motion *m_currentEffect;                     // 0x1c0
    bool m_isMoving;                             // 0x1c4
    unsigned char m_facing;                     // 0x1c5
    signed char m_moveFrame;                     // 0x1c6
    unsigned int m_animationFrame;               // 0x1c8
    unsigned int m_animationGroup;               // 0x1cc
    bool m_terminalAnimation;                    // 0x1d0
    bool m_nameVisible;                          // 0x1d1
    unsigned int m_boxRotationStep;              // 0x1d4
    ObjectPane *m_linkedGroundObject;             // 0x1d8
    ObjectPane *m_linkedShadowObject;             // 0x1dc
    ObjectPane *m_linkedEpfObject;                // 0x1e0
    ObjectPane *m_linkedNameplateObject;          // 0x1e4
    bool m_highlighted;                          // 0x1e8
    unsigned int m_boxRotationPhase;             // 0x1ec
    BoxRotator m_boxRotator;                     // 0x1f0
    unsigned int m_renderEffectState;            // 0x1f8
    RectBounds m_bounds;                         // 0x1fc
};

typedef char LivingObjectPaneSizeMustBe524[
    sizeof(LivingObjectPane) == 0x20c ? 1 : -1];

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 14 - UID0002AB `by-memory/0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static unsigned int s_spellWhoTargetId = 0;
static unsigned int s_itemWhoTargetId = 0;
unsigned int s_selectObjectTargetId = 0;
static unsigned int s_targetObjectTargetId = 0;
static unsigned int s_targetObjectPreviousTargetId = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 15 - UID0003ZS `by-memory/0x00509030-0x00509439.MapPaneMovementTimerHandler.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool MapPane::OnTimerEvent(int timerId, int, int)
{
    switch (timerId)
    {
    case 5:
        m_objectInteractionTimerActive = false;
        return true;

    case 7:
        if (m_pendingActionPoll)
        {
            if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) != 0)
            {
                if (g_pUserPane != NULL)
                    g_pUserPane->TryPerformAction();
                m_timerHandler.ScheduleTimer(7, 500, 0, 0);
            }
            else
            {
                ClearPendingActionPoll();
            }
            return true;
        }

        /* fall through to the movement/path timer */
    case 6:
        if (!m_queuedMapStateRefresh)
            return true;

        if (g_pInputBlockerPane != NULL)
        {
            ClearQueuedMapStateRefresh();
            return true;
        }

        if (m_activeObjectPane != NULL)
        {
            int direction = SelectMovementPathStep();
            if (direction >= 0 && direction < 4)
                m_activeObjectPane->ProcessMovement(direction);
        }

        if (ShouldClearMovementTimerState())
            ClearQueuedMapStateRefresh();
        else
            m_timerHandler.ScheduleTimer(6, 44, 0, 0);
        return true;

    case 8:
        if (!m_queuedMapStateRefresh)
            return true;

        if (g_pInputBlockerPane != NULL)
        {
            ClearQueuedMapStateRefresh();
            return true;
        }

        if (m_activeObjectPane != NULL)
        {
            MapPoint currentPosition;
            m_activeObjectPane->GetMapPosition(&currentPosition);

            ObjectPane *target = m_objectList != NULL
                ? m_objectList->FindByObjectId(m_pendingActionTargetObjectId)
                : NULL;

            int direction = BuildPathToPendingActionTarget(target, currentPosition);
            if (direction >= 0 && direction < 4)
                m_activeObjectPane->ProcessMovement(direction);
            else
                ResolvePendingActionTarget(target, currentPosition);
        }

        if (ShouldClearMovementTimerState())
            ClearQueuedMapStateRefresh();
        else
            m_timerHandler.ScheduleTimer(8, 44, 0, 0);
        return true;

    default:
        return false;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

The seven MapPane source bodies preserve exact runtime ordering. Destinations 10-13 preserve every current declaration/field/size guard, including ObjectPane's current inline `GetObjectId()`, and add only the stated friend/field/declaration changes. Destination 14 changes only one linkage specifier. Destination 15 preserves the complete current timer body and changes only the case-5 field name.

### Final Recommendation - Source Matrix

- The accepted exact seven-child split and 15 managed destinations were applied with serial validator-issued UIDs and no monolithic parent output.
- UID00037X was raised from `85/89` to `90/92`, UID0003UI from `86/88` to `90/92`, and UID0002AB from `88/90` to `89/91`. Child scores match the inventory; all other support scores/routes remain unchanged.
- Retain `FlashMapColor` and `FinishVisibleObjectRefresh` as reconstructable, emitting MapPane methods. Their missing inbound routes remain explicit liveness/lexical caps; independent compiler shapes, unique bytes, policy semantics, and inline lifecycle analogs make blank/no-source treatment unsafe.
- Keep MapPane class formal blank and class score `89/89`; this target does not justify replacing a deliberately blank 124-method class surface with a partial declaration.
- Keep unresolved items only as lexical/liveness caps: original private spellings, whether `s_` originally meant static/state, and the missing inbound routes for the two unmodeled starts. None blocks the split or any first-draft source body.

### Recommended Target Doc Changes - Source Matrix

- Applied/verified target path: `by-memory/0x0050b080-0x0050bcd8.MapPaneInteractionMapChangeCore.md`.
- Current metadata is completion `90`, confidence `92`, owner `NONE`, reconstructable `FALSE`, blank emitter and position, Destination 1 blank formal, and `Nested:0`.
- Item Summary: `Non-emitting MapPane interaction/map-change split index over seven exact source methods, attached switch-table data, and explicit internal alignment; exact children carry source and cumulative nesting decisions, including two independently compiled methods whose inbound routes remain unrecovered.`
- Aggregate-as-function wording was replaced with the full range/hash/child/padding/table/caller/owner/source/negative/history evidence in this report. Real children were linked only after serial registration.
- Preserve the prior SaveCompressedMapFile support fact and select/target caller evidence as historical/current bounded evidence, while superseding the unresolved-helper and monolithic-emitter conclusions.

### Recommended Support Doc Changes - Source Matrix

- Applied/verified status: all accepted support changes in this source matrix are complete. The seven exact child pages were created/registered in the inventory, and each page contains exact metadata, Item Summary, range/hash, instruction/CFG, caller/callee/xref, behavior/type/field/global, source-placement, negative evidence, history, score rationale, and its corresponding Destination 2-8 block.
- First child Item Summary: `MapPane object-to-screen point helper with exact tile-origin conversion, tile-pixel globals, LivingObjectPane movement interpolation, caller evidence, and source-ready formal body.`
- FlashMapColor Item Summary: `Source-ready standalone MapPane map-flash-color method with an independent thiscall prologue/epilogue; stores and clears m_mapFlashColor around two whole-pane invalidation and Surface presentation passes with a 100 ms sleep; unique out-of-line body and opcode-0x29 inline analog preserve the absent-entry liveness caveat.`
- FinishVisibleObjectRefresh Item Summary: `Source-ready standalone MapPane visible-object refresh completion method with an independent thiscall prologue/epilogue; calls ObjectList::RemoveMarkedVisibleObjects and clears m_visibleObjectRefreshPending; unique out-of-line body, MapRefreshDimmer inline analog, and producer lifecycle preserve the absent-entry liveness caveat.`
- Interaction Item Summary: `MapPane object-interaction sender; exact six-byte 0x43/0x01/object-id packet, ObjectStatusBlob human gate, timer-id-5 cooldown, nonhuman immediate send, source ABI, callers, and formal body.`
- Collection Item Summary: `MapPane movement-target object-id collector; exact directional lane scan, selected-target fallback, optional eight-neighbor expansion, attached switch table, stale-id null edge, and source-ready formal body.`
- Sort Item Summary: `MapPane movement-target object-id distance sorter; ascending squared-distance selection order, stable ties, unchecked valid-id precondition, no dedup/compaction, and source-ready formal body.`
- ChangeMap Item Summary: `MapPane map-change method; conditional save/music stop, ObjectList detach/delete/recreate, map/weather/transition stores, conditional load, draw/invalidate tail, exact EH/negative evidence, and source-ready formal body.`
- UID0003UI: set `90/92`, retain owner/emitter UID0000FQ, reconstructable true, position blank and `Nested:8`; apply Destination 9; rewrite behavior/packet/open questions/history at report-level detail and reject path/compact/rangecheck claims.
- UID0000FQ UserPane: preserve `92/93`, owner/emitter/position/size and all current formal content; apply Destination 10; document friend access and exact `+0x13eb3e` field split. UID0000P1 UserPane file stays `91/92` and records corrected caller/source/header/global contract.
- UID00009Q ObjectList: preserve `90/92`, owner/emitter and all current formal content; apply Destination 11. UID0000M4 file stays `90/92` and records the two declarations plus target callsites.
- UID00009R ObjectPane and UID00007B LivingObjectPane: preserve `92/94` and `92/93`; apply Destinations 12/13 with only MapPane friendship added. Their by-file pages stay `91/92` and `90/92` and record the access rationale without moving source.
- UID0002AB: set `89/91`, preserve owner/emitter/position/range/nesting and four static definitions; apply Destination 14; document the direct MapPane consumer and external-linkage correction. UID0000OH stays `90/88` and records the externally visible select-object ID while preserving the target-selection source owner.
- UID0003ZS: preserve `88/89`, owner/emitter/metadata; apply Destination 15 and synchronize only the timer-id-5 role/field name plus its set/clear chain.
- UID00007Q MapPane: keep `89/89` and blank broad formal. Add seven-source-method inventory and declarations/prose for `FlashMapColor`/`FinishVisibleObjectRefresh`, exact field rows, route-negative liveness caps, caller/callee/table/negative evidence, and rejected historical names.
- UID0000L3 MapPane: keep `89/85` and path. Add exact source order, seven emitted definitions, selected-id external declaration, support includes/types, compiler-only exclusions, and generated expectations.
- UID00042K MapPaneLayout: keep `84/87`, owner/emitter and comment-only formal. Add exact field rows for `+0x3f1`, `+0x40c`, `+0x40d`, `+0x410`, `+0x414`, `+0x4c8`, and `+0x4cd`, with source-name confidence and producer/consumer chains.
- UID0003TO and UID00037V: preserve scores, metadata, routes, and formals; add the exact opcode-`0x29` inline FlashMapColor analog and the render-time `m_mapFlashColor` consumer, explicitly distinguishing those live uses from the retained standalone body.
- UID0001B1, UID0003TK, and UID0001AW `MapPanePacketHandlers`: preserve scores, metadata, routes, and formals; add the exact inline FinishVisibleObjectRefresh analog, map-state test/clear lifecycle, and `0x0050f460` producer that sets `m_visibleObjectRefreshPending` before visible-object mark/prune work.
- `by-memory/-ignored.md`: add the four exact internal `cc` spans with reasons/evidence/owner links; verify the existing predecessor/successor padding rows without duplication.
- UID0001AT and UID00037Y: bounded split/nesting link synchronization only; preserve scores, owner/emitter/reconstructable/formal and UID00037Y `Nested:-4`.
- Verify-only unless an exact contradiction appears on callback reread: UID0001AV, UID0002QJ, UID0002QK, UID00009S/0000M6 ObjectStatusBlob, UID0003YJ PacketBuffer, UID0001HU Socket, UID0001K8 TimerHandler wrappers, Pane invalidation, Surface presentation, `g_pScreenPane`, SoundManager/config/global tile-dimension/movement-scale pages, ObjectList exact method pages, and current load/draw/state children.

### Score And Metadata Recommendation - Source Matrix

- Historical baseline was UID00037X `85/89`, owner/emitter UID00007Q, reconstructable true, blank Item Summary/formal, `Nested:8`; callback-current state is `90/92`, owner none, reconstructable false, blank emitter/position/formal, exact Item Summary, `Nested:0`.
- Child scores: screen point `91/93`; FlashMapColor `90/92`; FinishVisibleObjectRefresh `90/92`; interaction `92/94`; collection `91/93`; sort `91/93`; ChangeMap `91/93`. All seven children use owner/emitter UID00007Q and blank optional source position.
- UID0003UI is `90/92` because the sole caller route, exact packet shape, helper semantics, value-first writer ABI, count/cap edge, local terminator, and complete body are resolved.
- UID0002AB is `89/91` because the direct MapPane read closes linkage and consumer coverage; confidence remains below final because original global spelling and fifth-slot role remain stripped.
- Other support scores remain unchanged. Friendship/declaration/field prose synchronizations solve target compile/source-shape issues but do not complete the broad classes/files.
- Score blockers removed: child-formal gaps; monolithic aggregate; unmodeled-function boundaries/source disposition; table ownership; packet ABI; ObjectStatus kind; timer gate; collection versus path semantics; sort versus compaction; selected global linkage; UserPane field; ObjectList methods; map-change args/order/state; caller packet edge; compiler exclusions.
- Remaining caps: no original symbols, no inbound route to two unmodeled starts, no ordinary start caller for ChangeMap, and broader MapPane header incompleteness. These justify staying below `95` but do not justify retaining the old parent score or suppressing source-ready child bodies.

### Open Questions With Attempted Resolution - Source Matrix

- Exact original names: stripped symbols prevent certainty. Caller vocabulary, field roles, current accepted names, and direct semantics support the selected names. Impact: confidence cap only; no C++ blocker.
- Unmodeled-method liveness: function lookup, xrefs, immediate/static VA/RVA, vtable/table, and generated routes were exhausted with no inbound hit. Resolution: retain both unique, independently compiled out-of-line methods with complete source; their inline analogs validate policy/fields but are not substituted as canonical copies. Missing routes cap original spelling and current liveness only.
- ChangeMap reachability: no ordinary start caller was found. The complete member receiver, EH, source-shaped calls, and state policy justify source C++; likely virtual/indirect dispatch remains a route-confidence cap.
- Selected ID linkage/name: direct MapPane read disproves static linkage. The established `s_selectObjectTargetId` spelling is retained to avoid a speculative broad rename; only linkage changes. A future symbol-bearing header would be required to prove original prefix.
- UserPane expansion byte: exact one-byte compare-to-1, both directional/adjacent behaviors, and stable class size support a bool. Exact original phrase is unknown; selected name is descriptive and no longer blocks source.
- `+0x4cd` spelling: the `0x0050f460` producer sets the byte before visible-object marking/pruning, while UID0001B1 and UID0003TK consume/clear it. `m_visibleObjectRefreshPending` is the best descriptive field name; stripped symbols cap lexical confidence only.
- `+0x414` role: SetMapState lifecycle and exit teardown prove a weather layer that is later deferred for deletion. Resolution supersedes generic `m_deferredCleanupPane` as current identity while retaining it as historical behavior wording.
- Count-versus-nine mismatch and target null edge were tested as potential decompiler errors; instruction stores/loop bounds/branches confirm them. They are intentional exact quirks, not open normalization work.
- No unresolved question prevents or remains unapplied in the completed split, scores, metadata, or formal source.

### Exact Manual Supervisor-Owned Coverage Or Tracker Text - Source Matrix

The following manual rows were read without editing. At callback completion, `by-memory/-coverage-report.md` contains UID00037X but no UID0003UI or new-child rows; the real child UIDs are now `0004Q8` through `0004QE` and the exact pending supervisor-owned insertions below use those values. `by-class/-coverage-report.md` rows for MapPane/ObjectList/ObjectPane are current-score but need description synchronization; UserPane/LivingObjectPane rows are stale. `by-file/-coverage-report.md` MapPane/ObjectList/ObjectPane rows need description synchronization; UserPane/LivingObjectPane/TargetSelection rows are stale against current metadata. `by-type/by-struct/-coverage-report.md` UID00042K needs field synchronization. UID0002AB's by-memory manual row is stale at `86`. UID0003TO, UID00037V, UID0001B1, UID0003TK, and UID0001AW retain path/title/score/reconstructable classification, so their current manual rows are verify-only despite completed ordinary-page evidence synchronization.

Supervisor-owned exact replacement/insertion text, now carrying the serially issued real UIDs:

- Replace UID00037X row in `by-memory/-coverage-report.md`:
        - [UID:00037X][0x0050b080-0x0050bcd8.MapPaneInteractionMapChangeCore](by-memory/0x0050b080-0x0050bcd8.MapPaneInteractionMapChangeCore.md) 0x0050b080-0x0050bcd8 | split index | MapPaneInteractionMapChangeCore : not reconstructable : 90% : very strong : Non-emitting MapPane interaction/map-change split index over seven exact source methods, attached direction-switch data, and explicit internal alignment; exact children carry source and cumulative nesting decisions, including two independently compiled methods whose inbound routes remain unrecovered.
- Insert beneath it, in address order:
            - [UID:0004Q8][0x0050b080-0x0050b139.MapPaneGetObjectScreenPoint](by-memory/0x0050b080-0x0050b139.MapPaneGetObjectScreenPoint.md) 0x0050b080-0x0050b139 | method | MapPaneGetObjectScreenPoint : reconstructable : 91% : very strong : Source-ready MapPane object-to-screen point helper with exact tile-origin conversion, tile-pixel globals, LivingObjectPane movement interpolation, callers, access contract, and formal body.
            - [UID:0004Q9][0x0050b140-0x0050b18c.MapPaneFlashMapColor](by-memory/0x0050b140-0x0050b18c.MapPaneFlashMapColor.md) 0x0050b140-0x0050b18c | method | MapPaneFlashMapColor : reconstructable : 90% : very strong : Source-ready standalone MapPane map-flash-color method with an independent thiscall prologue/epilogue; stores and clears m_mapFlashColor around two whole-pane invalidation and Surface presentation passes with a 100 ms sleep; unique out-of-line body and opcode-0x29 inline analog preserve the absent-entry liveness caveat.
            - [UID:0004QA][0x0050b190-0x0050b1a7.MapPaneFinishVisibleObjectRefresh](by-memory/0x0050b190-0x0050b1a7.MapPaneFinishVisibleObjectRefresh.md) 0x0050b190-0x0050b1a7 | method | MapPaneFinishVisibleObjectRefresh : reconstructable : 90% : very strong : Source-ready standalone MapPane visible-object refresh completion method with an independent thiscall prologue/epilogue; calls ObjectList::RemoveMarkedVisibleObjects and clears m_visibleObjectRefreshPending; unique out-of-line body, MapRefreshDimmer inline analog, and producer lifecycle preserve the absent-entry liveness caveat.
            - [UID:0004QB][0x0050b1b0-0x0050b2af.MapPaneInteractWithObject](by-memory/0x0050b1b0-0x0050b2af.MapPaneInteractWithObject.md) 0x0050b1b0-0x0050b2af | method | MapPaneInteractWithObject : reconstructable : 92% : very strong : Source-ready MapPane interaction sender with exact six-byte 0x43/0x01/object-id packet, ObjectStatusBlob human gate, timer-id-5 cooldown, nonhuman immediate send, five call sites, and value-first packet ABI.
            - [UID:0004QC][0x0050b2b0-0x0050b990.MapPaneCollectMovementTargetObjectIds](by-memory/0x0050b2b0-0x0050b990.MapPaneCollectMovementTargetObjectIds.md) 0x0050b2b0-0x0050b990 | method plus switch table | MapPaneCollectMovementTargetObjectIds : reconstructable : 91% : very strong : Source-ready movement-target ID collector with directional visible-row lanes, selected-id fallback, optional eight-neighbor expansion, attached jump table, external selected-id linkage, and preserved stale-id null edge.
            - [UID:0004QD][0x0050b990-0x0050bbb0.MapPaneSortMovementTargetObjectIdsByDistance](by-memory/0x0050b990-0x0050bbb0.MapPaneSortMovementTargetObjectIdsByDistance.md) 0x0050b990-0x0050bbb0 | method | MapPaneSortMovementTargetObjectIdsByDistance : reconstructable : 91% : very strong : Source-ready ascending squared-distance selection sorter with stable ties, unchecked valid-id precondition, no deduplication/compaction, and exact UserPane caller pairing.
            - [UID:0004QE][0x0050bbb0-0x0050bcd8.MapPaneChangeMap](by-memory/0x0050bbb0-0x0050bcd8.MapPaneChangeMap.md) 0x0050bbb0-0x0050bcd8 | method | MapPaneChangeMap : reconstructable : 91% : very strong : Source-ready MapPane change method with conditional cache save/music stop, ObjectList detach/delete/recreate, exact map/weather/transition stores, conditional load, draw/invalidate tail, EH exclusions, and preserved failure/order semantics.
- Insert UID0003UI in `by-memory/-coverage-report.md` at address order near other `0x005a8...` UserPane rows:
        - [UID:0003UI][0x005a8cf0-0x005a8e67.UserPaneSendMovementPacket](by-memory/0x005a8cf0-0x005a8e67.UserPaneSendMovementPacket.md) 0x005a8cf0-0x005a8e67 | method | UserPaneSendMovementPacket : reconstructable : 90% : very strong : Source-ready UserPane opcode-0x13 movement-target sender using MapPane collect/sort helpers, subtype 4 or action-mode subtype 2/3, elapsed/125 capped at 40, full vector count with only nine serialized IDs, local-only terminator, value-first writes, and no handwritten range-check lowering.
- Replace UID0002AB row in `by-memory/-coverage-report.md`:
    - [UID:0002AB][0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals](by-memory/0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals.md) 0x0069bf20-0x0069bf34 | global-data cluster | TargetSelectionSavedTargetGlobals : reconstructable : 89% : very strong : Five contiguous target-selection IDs remain defined under TargetSelectionInputPanes; direct MapPane movement-target collection proves s_selectObjectTargetId requires external linkage, while the other four definitions stay file-local and the unresolved fifth-slot spelling remains a confidence cap.
- Replace class rows in `by-class/-coverage-report.md`:
  - [UID:00007Q][MapPane](by-class/MapPane.md) : reconstructable : 89% : very-strong : Live game-world pane class with blank broad class formal and child-only source emission; UID00037X is now a non-emitting seven-child interaction/map-change split with seven source-ready methods, exact packet/object-list/target/global/weather/flash/refresh fields, switch-table/padding evidence, missing-route liveness caps, and load/save/draw ordering.
  - [UID:00009Q][ObjectList](by-class/ObjectList.md) : reconstructable : 90% : very-strong : Complete LObject-derived 0x44 ObjectList declaration routed to NexusTK/map/ObjectList.cpp with ObjectListKey, exact lifecycle/dispatch/find/predicate/accessor/private lookup declarations, newly synchronized DetachAll and RemoveMarkedVisibleObjects declarations for MapPane change/prune consumers, semantic storage, child-only emission, and compiler exclusions.
  - [UID:0000FQ][UserPane](by-class/UserPane.md) : reconstructable : 92% : very-strong : Complete local-player UserPane declaration at exact size 0x13eb84 with movement/packet/server method inventory, corrected opcode-0x13 movement-target sender, MapPane friendship, action mode, exact +0x13eb3e adjacent-target bool split, and preserved full field/record/size-guard surface.
  - [UID:00009R][ObjectPane](by-class/ObjectPane.md) : reconstructable : 92% : very-strong : Complete abstract 0x128 ObjectPane declaration over Pane with exact ObjectPaneType constants 0..11, byte type ABI, ObjectList and MapPane friendship for binary-proven direct type/id access, preserved inline GetObjectId accessor, exact id/map/bounds/attachment/sound/transient layout, methods/default virtuals, implicit padding, and compiler vtable coverage.
  - [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md) : reconstructable : 92% : very-strong : Complete 0x20c LivingObjectPane declaration with ObjectStatusBlob, linked objects/effects/movement/render/timer surface, nested BoxRotator, exact moving/facing/frame fields, MapPane friendship for binary-proven screen interpolation, size guard, child-only method emission, and compiler exclusions.
- Replace file rows in `by-file/-coverage-report.md`:
  - [UID:0000L3][MapPane](by-file/MapPane.md) : reconstructable : 89% : very-strong : Major NexusTK/map/MapPane.cpp source root with source-ready compressed-map load/save and UID00037X interaction/map-change child family: seven exact definitions including route-negative FlashMapColor and FinishVisibleObjectRefresh, selected-target external declaration, ObjectList lifecycle, packet/timer/global/weather/render dependencies, attached switch table, exact source order, and compiler-artifact exclusions.
  - [UID:0000P1][UserPane](by-file/UserPane.md) : reconstructable : 91% : very-strong : NexusTK/ui/panels/UserPane.cpp source root with complete UserPane class/method families and corrected opcode-0x13 movement-target sender using MapPane collect/sort, exact count-versus-nine cap/local terminator behavior, action/adjacent-target fields, packet ABI, and preserved movement-history/server/caller evidence.
  - [UID:0000M4][ObjectList](by-file/ObjectList.md) : reconstructable : 90% : very-strong : NexusTK/map/ObjectList.cpp source root with complete ObjectList header/class route, semantic storage taxonomy, exact lifecycle/dispatch/accessor/private key methods, DetachAll and RemoveMarkedVisibleObjects declarations/MapPane consumers, child-only emission, and compiler table/cookie/vtable/scalar-wrapper exclusions.
  - [UID:0000M5][ObjectPane](by-file/ObjectPane.md) : reconstructable : 91% : very-strong : NexusTK/map/ObjectPane.cpp and reconstructed ObjectPane.h route for the complete 0x128 declaration, ObjectPaneType enum, ObjectList/MapPane friendship, exact child methods/layout/default virtuals, SoundObjectPane ownership, and compiler-only vtables without by-file reconstruction metadata.
  - [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md) : reconstructable : 90% : very-strong : NexusTK/map/LivingObjectPane.cpp source root with complete class/BoxRotator declaration, linked/effect/movement/render/timer/packet families, MapPane friendship for exact moving-screen interpolation, static pool/global evidence, source-order boundaries, and compiler-artifact exclusions.
  - [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md) : reconstructable : 90% : strong : Target-selection source root with spell/item/object panes, packet helpers, five saved-target definitions, and externally linked s_selectObjectTargetId required by direct MapPane collection while the other four globals stay file-local; exact producer/consumer ownership, raw-helper/thunk policy, and historical static-linkage assumption are preserved.
- Replace UID00042K row in `by-type/by-struct/-coverage-report.md`:
  - [UID:00042K][MapPaneLayout](by-type/by-struct/MapPaneLayout.md) : reconstructable : 84% : strong : Focused MapPane layout support with canonical dimensions/tile/origin/object-list fields plus exact interaction timer +0x3f1, transition/weather +0x40c/+0x40d/+0x410/+0x414, map-flash color +0x4c8, and visible-object-refresh-pending +0x4cd roles; broader field ledger and no standalone class emission remain preserved.

These are manual supervisor-owned rows. B005 must not apply them directly. The auto-generated tracker row is validator-owned and should follow source-page metadata/Item Summary plus the supervisor lifecycle; no exact hand edit is proposed for `auto-generated/-ag-research-tracker.md`.

### Follow-Up Actions - Source Matrix

- Supervisor Gate 1 accepted the source matrix and B005 completed its bounded responsibility: serial child registration, ordinary target/support edits, scoped validation, generated readback, report reconciliation, and immediate lease release.
- Manual coverage application, Gate 2, report execution, and archival remain supervisor-owned external state; they are not pending B005 report work and this artifact issues no lifecycle directive.
- No additional B-agent research target is required for UID00037X. Remaining original-symbol uncertainty is a documented confidence cap, not deferred body work.
- Future unrelated work may split ObjectList's own raw accessor aggregate or complete the broad MapPane class header, but neither is required to implement these exact definitions.

### Confidence - Source Matrix

- Recommendation confidence: very strong for split, behavior, ownership, source route, metadata direction, body order, packet/data edges, and retained-source dispositions.
- Score confidence: strong. `90/92` parent reflects complete split/source-quality documentation but correctly remains below final original-source certainty; child scores preserve lexical/liveness caps for unreferenced starts without treating them as no-source.
- Remaining uncertainty: exact private lexical spellings, original linkage prefix, two missing inbound routes, and indirect ChangeMap dispatch. Each has explicit score impact and none blocks or was omitted from the implemented formal source.

### Validator Results - Source Matrix

- Historical report-only fact: no implementation validator, child registration, or lease ran before Gate 1. Callback-current fact: every changed ordinary page passed its scoped validator, all seven UIDs were issued serially, and waited refresh `000000012202` completed with `exit 0`, `ok:1`.
- Generated assertions passed: `NexusTK/map/MapPane.cpp` contains exactly one definition for each of the seven target children, including `FlashMapColor` and `FinishVisibleObjectRefresh`, no UID00037X parent marker/body, corrected timer/global/declarations, and no handwritten compiler lowering; `NexusTK/ui/panels/UserPane.cpp` contains one corrected UID0003UI body with count/nine-cap/terminator behavior.
- Full command/timestamp/result matrix, warnings, validator-owned side effects, generated hashes, and destination hashes are recorded in the required top-level Validator Results section.

### Changed Files - Source Matrix

- This report was created during report-only research and updated in place after the accepted callback. The exact 31 ordinary changed pages and verify-only dependencies are recorded in the required top-level Changed Files section.
- No file was renamed or moved. B005 did not manually edit restricted/generated/manual coverage/tracker/audit/supervisor/validator/lifecycle files; validator-owned refresh side effects are recorded separately.
- No execute/probe/count/move/archive/report-lifecycle command was run.

### Implementation Tracking Checklist - Source Matrix

Initial report-only pass:
- [x] Supervisor Gate 1 accepted the exact repaired artifact before implementation.
- [x] UID00037X converted to the exact `90/92`, owner-none, reconstructable-false, blank-formal split index with `Nested:0` and complete Item Summary/evidence.
- [x] Seven children registered serially as `0004Q8`-`0004QE`; first child uses `Nested:4`, later children `Nested:0`, and no token remains.
- [x] Destinations 2-8 and all exact child metadata, Item Summaries, evidence, formals, missing-route liveness caps, and score rationales applied.
- [x] UID0003UI and Destinations 9-15 applied exactly with report-level packet, class union, linkage, timer, history, and negative evidence.
- [x] UID00007Q/UID0000L3/UID00042K and every accepted caller/consumer/file/parent/successor/ignored support page synchronized at same-or-greater detail and preserved support scores/formals.
- [x] Exact hashes, CFG/caller/callee/xref facts, packet/state quirks, route negatives, historical assumptions, rejected alternatives, compiler exclusions, inline analogs, producer/consumer lifecycles, and lexical caps preserved.
- [x] C33 dependencies reread and retained verify-only because no exact contradiction appeared.
- [x] All accepted C++/declarations remain exclusively in the 15 exact formal managed destination blocks; no third-party import applies.
- [x] Exact manual coverage text preserved as supervisor-owned; no manual coverage or generated/tracker output was manually edited.
- [x] One scoped validator per changed ordinary page, serial UID issuance, immediate lease release, final waited refresh, generated readback, and report reconciliation completed.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support doc details incorporated at report-level detail.
- [x] All seven real validator-issued UIDs recorded and every brace token replaced before cross-linking.
- [x] All 15 accepted managed blocks applied byte-for-byte to their named pages; hashes recorded below.
- [x] C01-C35 use legal terminal states with claim-specific destination/validator/generated proof.
- [x] Metadata/score/owner/emitter/split/nesting/linkage/C++ changes applied or explicitly verify-only.
- [x] Historical/stale assumptions, rejected alternatives, negative evidence, missing-entry-route liveness limits, superseded raw/no-code wording, inline analogs, null/count quirks, and lexical caps preserved.
- [x] Open questions resolved or retained only with evidence-backed score/C++ impact.
- [x] Scoped validators and final waited generated refresh recorded with command IDs/timestamps/results/side effects.
- [x] Exact changed/verify-only files, generated hashes/counts/order/markers, and all lease releases recorded.
- [x] No accepted item remains blocked and the generated lease report has zero B005 rows.
- [x] No execute_report/probe/lifecycle/move/archive, manual coverage/tracker/generated/audit/supervisor/validator-state edit, or IDA mutation performed.

### Destination 2 - `0004Q8` `by-memory/0x0050b080-0x0050b139.MapPaneGetObjectScreenPoint.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
MapPoint *MapPane::GetObjectScreenPoint(
    ObjectPane *object,
    MapPoint *outPoint) const
{
    object->GetMapPosition(outPoint);
    outPoint->y =
        (outPoint->y - m_tileOriginY + 1) * g_mapTilePixelHeight;
    outPoint->x =
        (outPoint->x - m_tileOriginX + 1) * g_mapTilePixelWidth;

    if (object->m_objectType == kObjectPaneTypeLiving)
    {
        LivingObjectPane *living = static_cast<LivingObjectPane *>(object);
        if (living->m_isMoving)
        {
            MapPoint step;
            DirectionToTileOffset(&step, living->m_facing);
            const int divisor = 4 * g_movementSubstepScale;
            outPoint->y +=
                living->m_moveFrame * step.y * g_mapTilePixelHeight / divisor;
            outPoint->x +=
                living->m_moveFrame * step.x * g_mapTilePixelWidth / divisor;
        }
    }

    return outPoint;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 3 - `0004Q9` `by-memory/0x0050b140-0x0050b18c.MapPaneFlashMapColor.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void MapPane::FlashMapColor(int drawColor)
{
    m_mapFlashColor = drawColor;
    InvalidateRect(NULL);
    g_pScreenPane->RenderPresentation();
    Sleep(100);
    m_mapFlashColor = 0;
    InvalidateRect(NULL);
    g_pScreenPane->RenderPresentation();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 4 - `0004QA` `by-memory/0x0050b190-0x0050b1a7.MapPaneFinishVisibleObjectRefresh.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void MapPane::FinishVisibleObjectRefresh()
{
    m_objectList->RemoveMarkedVisibleObjects();
    m_visibleObjectRefreshPending = false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 5 - `0004QB` `by-memory/0x0050b1b0-0x0050b2af.MapPaneInteractWithObject.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void MapPane::InteractWithObject(LivingObjectPane *target)
{
    ObjectStatusBlob status;
    target->GetSpriteConfig(&status);

    unsigned char packet[80];
    PacketBufferWriteUInt8(0x43, packet);
    PacketBufferWriteUInt8(0x01, packet + 1);
    PacketBufferWriteUInt32BE(target->m_objectId, packet + 2);

    if (status.m_statusKind == ObjectStatusBlob::HumanObject)
    {
        if (m_objectInteractionTimerActive)
            return;

        m_objectInteractionTimerActive = true;
        g_packetSender->QueueAndSendPacket(packet, 6);
        m_timerHandler.ScheduleTimer(5, 4000, 0, 0);
        return;
    }

    g_packetSender->QueueAndSendPacket(packet, 6);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 6 - `0004QC` `by-memory/0x0050b2b0-0x0050b990.MapPaneCollectMovementTargetObjectIds.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
extern unsigned int s_selectObjectTargetId;

void MapPane::CollectMovementTargetObjectIds(
    std::vector<unsigned int> &objectIds) const
{
    MapPoint userPosition;
    g_pUserPane->GetMapPosition(&userPosition);

    if (g_pUserPane->m_actionMode == 2)
    {
        MapRect visibleBounds;
        GetClampedVisibleTileBounds(&visibleBounds);

        for (int row = visibleBounds.top; row < visibleBounds.bottom; ++row)
        {
            List *objects = m_objectList->GetFrontRowBucket(row);
            for (int index = 0; index < objects->GetCount(); ++index)
            {
                ObjectPane *object =
                    *static_cast<ObjectPane **>(objects->GetElementAt(index));
                MapPoint objectPosition;
                object->GetMapPosition(&objectPosition);

                bool includeObject = false;
                switch (g_pUserPane->m_facing)
                {
                case 0:
                    includeObject = objectPosition.y < userPosition.y &&
                        (objectPosition.x == userPosition.x ||
                         (g_pUserPane->m_includeAdjacentMovementTargets == true &&
                          (objectPosition.x == userPosition.x - 1 ||
                           objectPosition.x == userPosition.x + 1)));
                    break;

                case 1:
                    includeObject = objectPosition.x > userPosition.x &&
                        (objectPosition.y == userPosition.y ||
                         (g_pUserPane->m_includeAdjacentMovementTargets == true &&
                          (objectPosition.y == userPosition.y - 1 ||
                           objectPosition.y == userPosition.y + 1)));
                    break;

                case 2:
                    includeObject = objectPosition.y > userPosition.y &&
                        (objectPosition.x == userPosition.x ||
                         (g_pUserPane->m_includeAdjacentMovementTargets == true &&
                          (objectPosition.x == userPosition.x - 1 ||
                           objectPosition.x == userPosition.x + 1)));
                    break;

                case 3:
                    includeObject = objectPosition.x < userPosition.x &&
                        (objectPosition.y == userPosition.y ||
                         (g_pUserPane->m_includeAdjacentMovementTargets == true &&
                          (objectPosition.y == userPosition.y - 1 ||
                           objectPosition.y == userPosition.y + 1)));
                    break;
                }

                if (includeObject)
                    objectIds.push_back(object->m_objectId);
            }
        }
        return;
    }

    ObjectPane *target = m_objectList->FindByObjectId(s_selectObjectTargetId);
    if (target != NULL)
        objectIds.push_back(target->m_objectId);

    if (g_pUserPane->m_includeAdjacentMovementTargets == true)
    {
        MapPoint targetPosition;
        target->GetMapPosition(&targetPosition);

        MapRect visibleBounds;
        GetClampedVisibleTileBounds(&visibleBounds);
        for (int row = visibleBounds.top; row < visibleBounds.bottom; ++row)
        {
            List *objects = m_objectList->GetFrontRowBucket(row);
            for (int index = 0; index < objects->GetCount(); ++index)
            {
                ObjectPane *object =
                    *static_cast<ObjectPane **>(objects->GetElementAt(index));
                MapPoint objectPosition;
                object->GetMapPosition(&objectPosition);
                if (objectPosition.x >= targetPosition.x - 1 &&
                    objectPosition.x <= targetPosition.x + 1 &&
                    objectPosition.y >= targetPosition.y - 1 &&
                    objectPosition.y <= targetPosition.y + 1 &&
                    (objectPosition.x != targetPosition.x ||
                     objectPosition.y != targetPosition.y))
                {
                    objectIds.push_back(object->m_objectId);
                }
            }
        }
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 7 - `0004QD` `by-memory/0x0050b990-0x0050bbb0.MapPaneSortMovementTargetObjectIdsByDistance.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void MapPane::SortMovementTargetObjectIdsByDistance(
    std::vector<unsigned int> &objectIds) const
{
    MapPoint userPosition;
    g_pUserPane->GetMapPosition(&userPosition);

    for (std::vector<unsigned int>::size_type first = 0;
         first + 1 < objectIds.size(); ++first)
    {
        std::vector<unsigned int>::size_type nearest = first;
        ObjectPane *nearestObject =
            m_objectList->FindByObjectId(objectIds[nearest]);
        MapPoint nearestPosition;
        nearestObject->GetMapPosition(&nearestPosition);
        int deltaX = nearestPosition.x - userPosition.x;
        int deltaY = nearestPosition.y - userPosition.y;
        int nearestDistance = deltaX * deltaX + deltaY * deltaY;

        for (std::vector<unsigned int>::size_type candidate = first + 1;
             candidate < objectIds.size(); ++candidate)
        {
            ObjectPane *candidateObject =
                m_objectList->FindByObjectId(objectIds[candidate]);
            MapPoint candidatePosition;
            candidateObject->GetMapPosition(&candidatePosition);
            deltaX = candidatePosition.x - userPosition.x;
            deltaY = candidatePosition.y - userPosition.y;
            const int candidateDistance = deltaX * deltaX + deltaY * deltaY;
            if (candidateDistance < nearestDistance)
            {
                nearest = candidate;
                nearestDistance = candidateDistance;
            }
        }

        if (nearest != first)
            std::swap(objectIds[first], objectIds[nearest]);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 8 - `0004QE` `by-memory/0x0050bbb0-0x0050bcd8.MapPaneChangeMap.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void MapPane::ChangeMap(
    unsigned short mapId,
    short mapWidth,
    short mapHeight,
    unsigned char weatherMode,
    unsigned char transitionState,
    int loadOption)
{
    const bool mapChanged = mapId != m_mapId;
    if (mapChanged)
    {
        SaveCompressedMapFile();
        if (g_pConfig->m_musicSourceMode == 0)
            g_pSoundManager->StopStreamAndResetZone(3000);
    }

    if (m_objectList != NULL)
    {
        m_objectList->DetachAll(m_activeObjectPane);
        delete m_objectList;
    }

    m_objectList = new ObjectList(m_visibleTileColumns, m_visibleTileRows);
    m_mapWidth = mapWidth;
    m_mapHeight = mapHeight;
    m_mapTransitionState = transitionState;
    m_mapId = mapId;
    SetMapState(m_weatherType, weatherMode);

    if (mapChanged)
        LoadCompressedMapFile(mapId, loadOption);

    DrawVisibleTiles();
    InvalidateRect(&m_bounds);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 9 - UID0003UI `by-memory/0x005a8cf0-0x005a8e67.UserPaneSendMovementPacket.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void UserPane::SendMovementPacket(unsigned char direction)
{
    m_lastMovementInputTick = g_pTimerMgr->currentTick;
    std::vector<unsigned int> objectIds;
    g_pActiveMapPane->CollectMovementTargetObjectIds(objectIds);
    g_pActiveMapPane->SortMovementTargetObjectIdsByDistance(objectIds);

    unsigned char packet[60];
    unsigned int packetSize = 0;
    packet[packetSize++] = 0x13;
    if (direction != 0 || objectIds.empty())
    {
        packet[packetSize++] = 4;
    }
    else
    {
        packet[packetSize++] =
            static_cast<unsigned char>(2 + (m_actionMode == 2));
        unsigned int elapsed =
            (m_lastMovementInputTick - m_lastMovementSendTick) / 125;
        if (elapsed > 40)
            elapsed = 40;
        packet[packetSize++] = static_cast<unsigned char>(elapsed);
        packet[packetSize++] = static_cast<unsigned char>(objectIds.size());
        for (std::vector<unsigned int>::size_type index = 0;
             index < objectIds.size() && index < 9; ++index)
        {
            PacketBufferWriteUInt32BE(objectIds[index], packet + packetSize);
            packetSize += 4;
        }
    }

    packet[packetSize] = 0;
    g_packetSender->QueueAndSendPacket(
        packet, static_cast<short>(packetSize));
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

## Final Recommendation

- Applied after supervisor Gate 1: UID00037X is a `90/92` non-reconstructable, ownerless, non-emitting split index, all 15 exact managed destinations are present byte-for-byte, and all seven children emit source, including the two retained standalone methods whose inbound routes remain unrecovered.
- All seven children remain under owner/emitter UID00007Q MapPane and UID0000L3 `NexusTK/map/MapPane.cpp`; UID0003UI, three class friendships, ObjectList declarations, selected-id linkage, and timer case 5 are corrected consistently.
- Only UID00037X, UID0003UI, UID0002AB, and the seven new children received the accepted scores; all other scores/routes/formals remain preserved except the exact destination edits.
- Remaining uncertainty is lexical or route-only and is already reflected in scores/liveness notes. No target body, protocol edge, layout dependency, source disposition, or source-placement blocker remains.

## Recommended Target Doc Changes

- Applied/verified: `by-memory/0x0050b080-0x0050bcd8.MapPaneInteractionMapChangeCore.md` changed from historical `85/89`, UID00007Q owner/emitter, reconstructable true, blank Item Summary, and `Nested:8` to `90/92`, owner none, reconstructable false, blank emitter/position/Destination 1, exact split-index Item Summary, and `Nested:0`.
- The full parent SHA-256, seven-child inventory, modeled/unmodeled/table/padding boundaries, callers/callees/xrefs, source owner/file, nesting, retained-source and compiler-only no-code decisions, positive/negative evidence, compiler exclusions, historical assumptions, and rejected alternatives from C01-C35 are incorporated.
- Serial registration completed without pre-reference: `0004Q8`, `0004Q9`, `0004QA`, `0004QB`, `0004QC`, `0004QD`, and `0004QE`; no token remains.

## Recommended Support Doc Changes

- Created and validated seven exact source-method children at `[b080,b139)`, `[b140,b18c)`, `[b190,b1a7)`, `[b1b0,b2af)`, `[b2b0,b990)`, `[b990,bbb0)`, and `[bbb0,bcd8)` with the scores, owner/emitter UID00007Q, blank optional position, Item Summaries, evidence, nesting, and Destinations 2-8 recorded in the inventory/source matrix.
- Destination 9 and `90/92` are applied to UID0003UI; Destinations 10-13 are applied to the complete UserPane/ObjectList/ObjectPane/LivingObjectPane class blocks at unchanged class scores; Destination 14 and `89/91` are applied to UID0002AB; Destination 15 is applied to UID0003ZS at unchanged score.
- UID00007Q/UID0000L3/UID00042K are synchronized with seven-method source order, `FlashMapColor`/`FinishVisibleObjectRefresh` method surface, `m_mapFlashColor`/`m_visibleObjectRefreshPending` fields, exact missing-route caveats, and unchanged support scores/formals. UID0003TO/UID00037V and UID0001B1/UID0003TK/UID0001AW carry the accepted inline analog, consumer, map-state, and producer lifecycle evidence with scores/routes/formals preserved.
- UID0000P1/UID0000M4/UID0000M5/UID0000KU/UID0000OH, UID0001AT/UID00037Y, and `by-memory/-ignored.md` are synchronized at the specified report-level detail with unrelated/concurrent content and all historical/negative evidence preserved.
- The named stable ObjectStatusBlob, PacketBuffer, Socket, TimerHandler, Pane invalidation, Surface presentation, `g_pScreenPane`, SoundManager, config, load/save, ObjectList method, and global dependency pages were verified read-only; no exact callback-time contradiction required an edit.

## Score And Metadata Recommendation

- UID00037X: `85/89` -> `90/92`; owner UID00007Q -> `NONE`; reconstructable true -> false; emitter UID00007Q -> blank; position/formal remain blank; `Nested:8` -> `0`.
- New children: screen point `91/93`; FlashMapColor `90/92`; FinishVisibleObjectRefresh `90/92`; interaction `92/94`; collector `91/93`; sorter `91/93`; ChangeMap `91/93`. All seven use owner/emitter UID00007Q with blank optional position. First child uses validator syntax `Nested:4`; later children use `Nested:0`.
- UID0003UI: `86/88` -> `90/92`, other metadata unchanged. UID0002AB: `88/90` -> `89/91`, other metadata unchanged except the one external-linkage definition. All other support scores remain unchanged.
- Improvements are justified by resolved split, Item Summary/formals, two retained-source dispositions, packet ABI, object/status/timer/flash/refresh fields, collector/sorter semantics, selected-id linkage, class access/declarations, map-change ABI/order, caller edge cases, missing-route evidence, unique-body/inline-analog checks, and compiler/table disposition. Missing original symbols and indirect routes cap scores below final certainty.

## Open Questions With Attempted Resolution

- Original private spellings remain stripped. Current caller/sibling vocabulary and behavior provide implementation-ready descriptive names; impact is confidence only.
- Exhaustive function/xref/pointer/vtable/table/generated-route checks found no inbound route for either unmodeled start. Independent compiler shapes, unique bytes, nontrivial policy, field lifecycles, and source-parallel inline analogs resolve both as retained standalone methods with complete formals; missing routes remain liveness and lexical-confidence facts only.
- ChangeMap has no ordinary start caller, but its complete receiver/state/EH/callee shape supports a normal member definition and likely indirect dispatch; this caps route confidence only.
- Direct MapPane consumption disproves static linkage for `s_selectObjectTargetId`. The established spelling is retained and only linkage changes; a symbol-bearing original header would be required to prove a different prefix.
- The adjacent-target byte is exactly compared to 1 and controls both lane widening and neighbor scan, supporting bool. The stale-target null dereference and full-count/nine-ID mismatch are confirmed binary edges and must not be normalized.
- No unresolved question blocks metadata, child registration, destination C++, source placement, or score improvement.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Read-only comparison covered `by-memory/-coverage-report.md` for UID00037X/UID0002AB and absent UID0003UI/new-child rows; `by-class/-coverage-report.md` for UID00007Q/00009Q/0000FQ/00009R/00007B; `by-file/-coverage-report.md` for UID0000L3/0000P1/0000M4/0000M5/0000KU/0000OH; and `by-type/by-struct/-coverage-report.md` for UID00042K. UID0003TO, UID00037V, UID0001B1, UID0003TK, and UID0001AW received detailed ordinary-doc synchronization while keeping scores/formals; their existing manual rows remain verify-only because path/title/score/reconstructable descriptions do not change.
- Exact supervisor replacement for UID00037X:
        - [UID:00037X][0x0050b080-0x0050bcd8.MapPaneInteractionMapChangeCore](by-memory/0x0050b080-0x0050bcd8.MapPaneInteractionMapChangeCore.md) 0x0050b080-0x0050bcd8 | split index | MapPaneInteractionMapChangeCore : not reconstructable : 90% : very strong : Non-emitting MapPane interaction/map-change split index over seven exact source methods, attached direction-switch data, and explicit internal alignment; exact children carry source and cumulative nesting decisions, including two independently compiled methods whose inbound routes remain unrecovered.
- Exact child insertions under that row, after serial UID issuance:
            - [UID:0004Q8][0x0050b080-0x0050b139.MapPaneGetObjectScreenPoint](by-memory/0x0050b080-0x0050b139.MapPaneGetObjectScreenPoint.md) 0x0050b080-0x0050b139 | method | MapPaneGetObjectScreenPoint : reconstructable : 91% : very strong : Source-ready MapPane object-to-screen point helper with exact tile-origin conversion, tile-pixel globals, LivingObjectPane movement interpolation, callers, access contract, and formal body.
            - [UID:0004Q9][0x0050b140-0x0050b18c.MapPaneFlashMapColor](by-memory/0x0050b140-0x0050b18c.MapPaneFlashMapColor.md) 0x0050b140-0x0050b18c | method | MapPaneFlashMapColor : reconstructable : 90% : very strong : Source-ready standalone MapPane map-flash-color method with an independent thiscall prologue/epilogue; stores and clears m_mapFlashColor around two whole-pane invalidation and Surface presentation passes with a 100 ms sleep; unique out-of-line body and opcode-0x29 inline analog preserve the absent-entry liveness caveat.
            - [UID:0004QA][0x0050b190-0x0050b1a7.MapPaneFinishVisibleObjectRefresh](by-memory/0x0050b190-0x0050b1a7.MapPaneFinishVisibleObjectRefresh.md) 0x0050b190-0x0050b1a7 | method | MapPaneFinishVisibleObjectRefresh : reconstructable : 90% : very strong : Source-ready standalone MapPane visible-object refresh completion method with an independent thiscall prologue/epilogue; calls ObjectList::RemoveMarkedVisibleObjects and clears m_visibleObjectRefreshPending; unique out-of-line body, MapRefreshDimmer inline analog, and producer lifecycle preserve the absent-entry liveness caveat.
            - [UID:0004QB][0x0050b1b0-0x0050b2af.MapPaneInteractWithObject](by-memory/0x0050b1b0-0x0050b2af.MapPaneInteractWithObject.md) 0x0050b1b0-0x0050b2af | method | MapPaneInteractWithObject : reconstructable : 92% : very strong : Source-ready MapPane interaction sender with exact six-byte 0x43/0x01/object-id packet, ObjectStatusBlob human gate, timer-id-5 cooldown, nonhuman immediate send, five call sites, and value-first packet ABI.
            - [UID:0004QC][0x0050b2b0-0x0050b990.MapPaneCollectMovementTargetObjectIds](by-memory/0x0050b2b0-0x0050b990.MapPaneCollectMovementTargetObjectIds.md) 0x0050b2b0-0x0050b990 | method plus switch table | MapPaneCollectMovementTargetObjectIds : reconstructable : 91% : very strong : Source-ready movement-target ID collector with directional visible-row lanes, selected-id fallback, optional eight-neighbor expansion, attached jump table, external selected-id linkage, and preserved stale-id null edge.
            - [UID:0004QD][0x0050b990-0x0050bbb0.MapPaneSortMovementTargetObjectIdsByDistance](by-memory/0x0050b990-0x0050bbb0.MapPaneSortMovementTargetObjectIdsByDistance.md) 0x0050b990-0x0050bbb0 | method | MapPaneSortMovementTargetObjectIdsByDistance : reconstructable : 91% : very strong : Source-ready ascending squared-distance selection sorter with stable ties, unchecked valid-id precondition, no deduplication/compaction, and exact UserPane caller pairing.
            - [UID:0004QE][0x0050bbb0-0x0050bcd8.MapPaneChangeMap](by-memory/0x0050bbb0-0x0050bcd8.MapPaneChangeMap.md) 0x0050bbb0-0x0050bcd8 | method | MapPaneChangeMap : reconstructable : 91% : very strong : Source-ready MapPane change method with conditional cache save/music stop, ObjectList detach/delete/recreate, exact map/weather/transition stores, conditional load, draw/invalidate tail, EH exclusions, and preserved failure/order semantics.
- Exact UID0003UI insertion near address order:
        - [UID:0003UI][0x005a8cf0-0x005a8e67.UserPaneSendMovementPacket](by-memory/0x005a8cf0-0x005a8e67.UserPaneSendMovementPacket.md) 0x005a8cf0-0x005a8e67 | method | UserPaneSendMovementPacket : reconstructable : 90% : very strong : Source-ready UserPane opcode-0x13 movement-target sender using MapPane collect/sort helpers, subtype 4 or action-mode subtype 2/3, elapsed/125 capped at 40, full vector count with only nine serialized IDs, local-only terminator, value-first writes, and no handwritten range-check lowering.
- Exact UID0002AB replacement:
    - [UID:0002AB][0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals](by-memory/0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals.md) 0x0069bf20-0x0069bf34 | global-data cluster | TargetSelectionSavedTargetGlobals : reconstructable : 89% : very strong : Five contiguous target-selection IDs remain defined under TargetSelectionInputPanes; direct MapPane movement-target collection proves s_selectObjectTargetId requires external linkage, while the other four definitions stay file-local and the unresolved fifth-slot spelling remains a confidence cap.
- Exact class replacements:
  - [UID:00007Q][MapPane](by-class/MapPane.md) : reconstructable : 89% : very-strong : Live game-world pane class with blank broad class formal and child-only source emission; UID00037X is now a non-emitting seven-child interaction/map-change split with seven source-ready methods, exact packet/object-list/target/global/weather/flash/refresh fields, switch-table/padding evidence, missing-route liveness caps, and load/save/draw ordering.
  - [UID:00009Q][ObjectList](by-class/ObjectList.md) : reconstructable : 90% : very-strong : Complete LObject-derived 0x44 ObjectList declaration routed to NexusTK/map/ObjectList.cpp with ObjectListKey, exact lifecycle/dispatch/find/predicate/accessor/private lookup declarations, newly synchronized DetachAll and RemoveMarkedVisibleObjects declarations for MapPane change/prune consumers, semantic storage, child-only emission, and compiler exclusions.
  - [UID:0000FQ][UserPane](by-class/UserPane.md) : reconstructable : 92% : very-strong : Complete local-player UserPane declaration at exact size 0x13eb84 with movement/packet/server method inventory, corrected opcode-0x13 movement-target sender, MapPane friendship, action mode, exact +0x13eb3e adjacent-target bool split, and preserved full field/record/size-guard surface.
  - [UID:00009R][ObjectPane](by-class/ObjectPane.md) : reconstructable : 92% : very-strong : Complete abstract 0x128 ObjectPane declaration over Pane with exact ObjectPaneType constants 0..11, byte type ABI, ObjectList and MapPane friendship for binary-proven direct type/id access, preserved inline GetObjectId accessor, exact id/map/bounds/attachment/sound/transient layout, methods/default virtuals, implicit padding, and compiler vtable coverage.
  - [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md) : reconstructable : 92% : very-strong : Complete 0x20c LivingObjectPane declaration with ObjectStatusBlob, linked objects/effects/movement/render/timer surface, nested BoxRotator, exact moving/facing/frame fields, MapPane friendship for binary-proven screen interpolation, size guard, child-only method emission, and compiler exclusions.
- Exact file replacements:
  - [UID:0000L3][MapPane](by-file/MapPane.md) : reconstructable : 89% : very-strong : Major NexusTK/map/MapPane.cpp source root with source-ready compressed-map load/save and UID00037X interaction/map-change child family: seven exact definitions including route-negative FlashMapColor and FinishVisibleObjectRefresh, selected-target external declaration, ObjectList lifecycle, packet/timer/global/weather/render dependencies, attached switch table, exact source order, and compiler-artifact exclusions.
  - [UID:0000P1][UserPane](by-file/UserPane.md) : reconstructable : 91% : very-strong : NexusTK/ui/panels/UserPane.cpp source root with complete UserPane class/method families and corrected opcode-0x13 movement-target sender using MapPane collect/sort, exact count-versus-nine cap/local terminator behavior, action/adjacent-target fields, packet ABI, and preserved movement-history/server/caller evidence.
  - [UID:0000M4][ObjectList](by-file/ObjectList.md) : reconstructable : 90% : very-strong : NexusTK/map/ObjectList.cpp source root with complete ObjectList header/class route, semantic storage taxonomy, exact lifecycle/dispatch/accessor/private key methods, DetachAll and RemoveMarkedVisibleObjects declarations/MapPane consumers, child-only emission, and compiler table/cookie/vtable/scalar-wrapper exclusions.
  - [UID:0000M5][ObjectPane](by-file/ObjectPane.md) : reconstructable : 91% : very-strong : NexusTK/map/ObjectPane.cpp and reconstructed ObjectPane.h route for the complete 0x128 declaration, ObjectPaneType enum, ObjectList/MapPane friendship, exact child methods/layout/default virtuals, SoundObjectPane ownership, and compiler-only vtables without by-file reconstruction metadata.
  - [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md) : reconstructable : 90% : very-strong : NexusTK/map/LivingObjectPane.cpp source root with complete class/BoxRotator declaration, linked/effect/movement/render/timer/packet families, MapPane friendship for exact moving-screen interpolation, static pool/global evidence, source-order boundaries, and compiler-artifact exclusions.
  - [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md) : reconstructable : 90% : strong : Target-selection source root with spell/item/object panes, packet helpers, five saved-target definitions, and externally linked s_selectObjectTargetId required by direct MapPane collection while the other four globals stay file-local; exact producer/consumer ownership, raw-helper/thunk policy, and historical static-linkage assumption are preserved.
- Exact UID00042K replacement:
  - [UID:00042K][MapPaneLayout](by-type/by-struct/MapPaneLayout.md) : reconstructable : 84% : strong : Focused MapPane layout support with canonical dimensions/tile/origin/object-list fields plus exact interaction timer +0x3f1, transition/weather +0x40c/+0x40d/+0x410/+0x414, map-flash color +0x4c8, and visible-object-refresh-pending +0x4cd roles; broader field ledger and no standalone class emission remain preserved.
- These rows are supervisor-owned manual text. B005 must not apply them. The auto-generated tracker remains validator/lifecycle-owned and receives no manual row edit.

## Follow-Up Actions

- Supervisor Gate 1 accepted the exact C01-C35 scope, and B005 completed serial registration, one-page edit/validate/release batches, the final waited generated refresh, and this report reconciliation.
- Manual coverage application, Gate 2, execution, and archival remain supervisor-owned external state. They are not pending B005 report work, and this report issues no future lifecycle directive.
- No further UID00037X research is required. Broader ObjectList raw splits and complete MapPane header work remain independent future targets, not blockers deferred by this report.

## Confidence

- Recommendation confidence: very strong for split, exact behavior, owner/file, body order, packet/global/layout edges, retained-source disposition, and metadata direction.
- Score confidence: strong; scores deliberately distinguish routed bodies from unreferenced but independently compiled methods and preserve stripped lexical uncertainty.
- Remaining uncertainty: original private names, the historical `s_` prefix, two missing inbound routes, and ChangeMap indirect dispatch. These cap confidence only and are fully dispositioned.

## Validator Results

- Historical report-only phase: no implementation validator or lease ran before Gate 1. Callback phase: 31 changed ordinary pages passed scoped file validation under serial one-file leases; every lease was released immediately after its page validator. All timestamps below are `2026-07-14` America/New_York; every listed command returned `exit 0`, `ok:1`.

| Changed ordinary page | Validator command ID and time | Result / lease disposition |
| --- | --- | --- |
| UID00037X parent | `000000012152` @ `20:09:27-04:00` | passed; released |
| UID0004Q8 GetObjectScreenPoint | registration `000000012132` @ `19:56:09-04:00`; nesting refresh `000000012154` @ `20:09:54-04:00`; final `000000012196` @ `20:27:50-04:00` | passed; real UID issued before reference; released |
| UID0004Q9 FlashMapColor | registration `000000012135` @ `19:59:18-04:00`; corrected-reference validation `000000012137` @ `19:59:37-04:00` | passed; initial screen-pane link was corrected before release; released |
| UID0004QA FinishVisibleObjectRefresh | `000000012139` @ `20:01:03-04:00` | passed; released |
| UID0004QB InteractWithObject | registration `000000012141` @ `20:02:37-04:00`; final Item Summary validation `000000012190` @ `20:25:36-04:00` | passed; released |
| UID0004QC CollectMovementTargetObjectIds | registration `000000012143` @ `20:04:24-04:00`; final Item Summary validation `000000012191` @ `20:26:06-04:00` | passed; released |
| UID0004QD SortMovementTargetObjectIdsByDistance | registration `000000012146` @ `20:05:45-04:00`; final Item Summary validation `000000012193` @ `20:26:35-04:00` | passed; released |
| UID0004QE ChangeMap | registration `000000012147` @ `20:07:08-04:00`; final Item Summary validation `000000012194` @ `20:27:02-04:00` | passed; released |
| UID0003UI UserPaneSendMovementPacket | `000000012155` @ `20:10:58-04:00` | passed; released |
| UID0000FQ UserPane class | `000000012156` @ `20:12:07-04:00` | passed; released |
| UID00009Q ObjectList class | `000000012157` @ `20:12:49-04:00` | passed; released |
| UID00009R ObjectPane class | initial `000000012158` @ `20:13:31-04:00`; exact block-order correction `000000012201` @ `20:32:27-04:00` | passed; Destination 12 exact; released |
| UID00007B LivingObjectPane class | `000000012159` @ `20:14:19-04:00` | passed; released |
| UID0002AB selected-target globals | `000000012160` @ `20:15:14-04:00` | passed; released |
| UID0003ZS MapPane timer handler | `000000012161` @ `20:15:50-04:00` | passed; released |
| UID00007Q MapPane class | `000000012162` @ `20:16:38-04:00` | passed; released |
| UID0000L3 MapPane file | `000000012164` @ `20:17:08-04:00` | passed; released |
| UID00042K MapPaneLayout | `000000012165` @ `20:18:01-04:00` | passed; released |
| UID0000P1 UserPane file | `000000012166` @ `20:18:35-04:00` | passed; released |
| UID0000M4 ObjectList file | `000000012167` @ `20:19:08-04:00` | passed; released |
| UID0000M5 ObjectPane file | `000000012168` @ `20:19:33-04:00` | passed; released |
| UID0000KU LivingObjectPane file | `000000012170` @ `20:20:00-04:00` | passed; released |
| UID0000OH TargetSelectionInputPanes file | `000000012171` @ `20:20:31-04:00` | passed; released |
| UID0001AT broad MapPane parent | `000000012173` @ `20:21:08-04:00` | passed; released |
| UID00037Y following MapPane row | `000000012175` @ `20:21:41-04:00` | passed; released |
| UID0003TO flash inline analog | `000000012179` @ `20:22:09-04:00` | passed; released |
| UID00037V flash render consumer | `000000012181` @ `20:22:45-04:00` | passed; released |
| UID0001B1 refresh inline analog | `000000012183` @ `20:23:14-04:00` | passed; released |
| UID0003TK refresh/map-state consumer | `000000012185` @ `20:23:46-04:00` | passed; released |
| UID0001AW refresh producer aggregate | `000000012186` @ `20:24:14-04:00` | passed; released |
| `by-memory/-ignored.md` | `000000012188` @ `20:24:57-04:00` | passed; four rows added, existing boundary rows not duplicated; released |

- Scoped validators deferred generated output as designed. Existing project-level `missing_ref_uid` warnings and generated child-marker/emitter warnings were non-blocking; no changed target failed. Validator `000000012154` refreshed `by-memory/-coverage-report.md` metadata as a validator-owned side effect. Registry/reference/project-statistics and generated/manual-coverage timestamps may likewise reflect validator-owned side effects; B005 did not manually edit those restricted files.
- First waited readback `000000012197` @ `20:28:19-04:00` passed. The exact block audit then found only Destination 12 declaration/friend ordering; after scoped correction `000000012201`, authoritative waited refresh `000000012202` @ `20:32:35-04:00` returned `exit 0`, `ok:1`, rebuilt `4920` metadata nodes/`3972` edges, and completed generation. Generated files dated `20:32:44`-`20:32:48-04:00`, later than the command timestamp.
- B005 waited-refresh hashes from command `000000012202`: `MapPane.cpp` `F2C89E427F86A7448C2CC7AA96C3EEFD529E8730E3855DC06B7877A64F73D087` (`64318` bytes); `UserPane.cpp` `32D52030D8C826D59C6F565EBFB5B1A42DAFB4AEB8DBE59EFF23D401CEEBD1C3` (`60021`); `ObjectList.cpp` `FCB37E665EE5FF9162A98680E31A5F8AEEF13C2D7D242E463AEF10BDF7784BB4`; `ObjectPane.cpp` `F3F845743DEBD36C5ABCE5141C115FCD0AB8398427A559FBC02CB9B5EE706FC6`; `LivingObjectPane.cpp` `E0F225DB3220858F585BC00965DE6B1A6D15596A7864B9800DDE6714982FA3B9`; `TargetSelectionInputPanes.cpp` `6AEDF56FE0250F6E889B120998627A98F48CC2AF7A785BF42D0FB50E3894B332`.
- Later read-only concurrency check: another validator-owned foreground refresh, command `000000012217` at `20:47:39-04:00`, rewrote generated headers after B005 released all leases. Current hashes became `MapPane.cpp` `6DF86D0602B2421AA2DBA90E82052EE72F6611165356F23C5098D5CDB047E447`, `UserPane.cpp` `9C9FA1F4E0AB4981C77EDAB026981629D2B1F069C05349797ABA8DB285008008`, `ObjectList.cpp` `69BE7228A9F0C9FDF0CCDEADDA10977E4C06AA38B35A0791D976FC7C87B25E3D`, `ObjectPane.cpp` `176DE45475F8E9D8B810AD7775E6B4A17B0B532B6CDA15AED76A4C71C91B9589`, `LivingObjectPane.cpp` `4D3BFF201DABEB3CA00AC21A80E253290BB6BA6FF161512D3EA2801765438B17`, and `TargetSelectionInputPanes.cpp` `835A5C2D03C5F405E3A86089DB62CC01172E308441B2D3CA8F338B957C3FAE1A`. File lengths and all target assertions remained unchanged; this is concurrent validator provenance, not a B005 command or manual edit.
- Generated assertions passed: MapPane method starts occur once and in accepted order at lines `1156`, `1185`, `1197`, `1204`, `1231`, `1330`, and `1371`; both formerly raw methods are nonempty source definitions; UID00037X and brace-token counts are zero; UID0003UI occurs once at UserPane line `757`; class unions/declarations/fields are present; selected-id output has one non-static definition and no static definition; the seven-method region has no EH handler, security-cookie, range-check failure, explicit delete, or goto lowering.

Exact normalized managed-block SHA-256 values, each independently compared equal to the accepted report block:

| Destination | SHA-256 |
| --- | --- |
| D1 | `CA40B93B6569C6F5127EE922903894943A86E38CB071968DB2A2260DC2E3F396` |
| D2 | `C59E568C7B417E1A277AAEFC2ABCBDDFD8C430F14926E12B17CF03DEBC2AAFEF` |
| D3 | `7DB857F77F35CC4F24DBC8519037E004FB2E1553A12D9074BA47FE7DE79047BC` |
| D4 | `FA41ED3AE195EA739BE579B733001685A468C277E50095E74CD58BE4763F5346` |
| D5 | `CE6CB702AB8E2A34950EFD68EB0B361C6529A7C704AF147E96DAD51D54468216` |
| D6 | `DCF4E2D537DD3541152AED7F1DEB4DA4F39893D523E12C3F8F7881D3A4A0DBBF` |
| D7 | `61043551F4D5355FD9EC1568331591654A752D72D91CB078C607DAF90F6E5326` |
| D8 | `3ACD1EB04F333269C8F3478FB88B4EAAE6F753AC3B12D8107A9AC993C9B45F22` |
| D9 | `25CD0E87287D2298C32DF885442E084C21AD921DB95DC0624B8B87B768407DC4` |
| D10 | `F7CC6F9F8B8FA66CF8ED13E2F0D8AA8C287B57D2F1D5E60097D569466D8126AF` |
| D11 | `3AF2B4B76F304A59337597EE80321AD59BC9F231C9259EACBE4D734901CE5A37` |
| D12 | `F8199A48BBEB2DF6996ED5163C52E973BE134B281A787AA036143C9C5A236E84` |
| D13 | `496756A1961837647960EA8335EEC5EF1310A980E8919F7B8CA1DFF98CCBED00` |
| D14 | `F1F5C3D6ED5134E34F94DCD868DE1CFC84BD3EF74FDC4BD6FF9F32D3773DCD49` |
| D15 | `6867BC568E09F936FA79DA6567102B0F243961E50BF03A564C863D56094A045C` |

## Changed Files

- Report artifact created during research and updated in place for callback proof: `tools/leaser/Agents/Agent-B005/research/00037X-MapPaneInteractionMapChangeCore-source-quality.md`.
- Ordinary by-memory changes: UID00037X; new UID0004Q8/0004Q9/0004QA/0004QB/0004QC/0004QD/0004QE; UID0003UI; UID0002AB; UID0003ZS; UID0001AT; UID00037Y; UID0003TO; UID00037V; UID0001B1; UID0003TK; UID0001AW; and `by-memory/-ignored.md`.
- Ordinary by-class changes: `UserPane.md`, `ObjectList.md`, `ObjectPane.md`, `LivingObjectPane.md`, and `MapPane.md`.
- Ordinary by-file changes: `MapPane.md`, `UserPane.md`, `ObjectList.md`, `ObjectPane.md`, `LivingObjectPane.md`, and `TargetSelectionInputPanes.md`.
- Ordinary type change: `by-type/by-struct/MapPaneLayout.md`. Total ordinary changed pages: `31`; every page appears in the validator matrix above.

### Exact Changed Paths

- `by-memory/0x0050b080-0x0050bcd8.MapPaneInteractionMapChangeCore.md`
- `by-memory/0x0050b080-0x0050b139.MapPaneGetObjectScreenPoint.md`
- `by-memory/0x0050b140-0x0050b18c.MapPaneFlashMapColor.md`
- `by-memory/0x0050b190-0x0050b1a7.MapPaneFinishVisibleObjectRefresh.md`
- `by-memory/0x0050b1b0-0x0050b2af.MapPaneInteractWithObject.md`
- `by-memory/0x0050b2b0-0x0050b990.MapPaneCollectMovementTargetObjectIds.md`
- `by-memory/0x0050b990-0x0050bbb0.MapPaneSortMovementTargetObjectIdsByDistance.md`
- `by-memory/0x0050bbb0-0x0050bcd8.MapPaneChangeMap.md`
- `by-memory/0x005a8cf0-0x005a8e67.UserPaneSendMovementPacket.md`
- `by-memory/0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals.md`
- `by-memory/0x00509030-0x00509439.MapPaneMovementTimerHandler.md`
- `by-memory/0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md`
- `by-memory/0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore.md`
- `by-memory/0x00511c90-0x00511dae.MapPaneHandleObjectMoveEffectPacket.md`
- `by-memory/0x00509470-0x0050a4fd.MapPaneRenderViewCore.md`
- `by-memory/0x00514920-0x00514a0d.MapRefreshDimmerMethods.md`
- `by-memory/0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket.md`
- `by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md`
- `by-memory/-ignored.md`
- `by-class/UserPane.md`
- `by-class/ObjectList.md`
- `by-class/ObjectPane.md`
- `by-class/LivingObjectPane.md`
- `by-class/MapPane.md`
- `by-file/MapPane.md`
- `by-file/UserPane.md`
- `by-file/ObjectList.md`
- `by-file/ObjectPane.md`
- `by-file/LivingObjectPane.md`
- `by-file/TargetSelectionInputPanes.md`
- `by-type/by-struct/MapPaneLayout.md`

- Verify-only/no-edit C33 dependencies: UID0001AV, UID0002QJ, UID0002QK, UID00009S/UID0000M6 ObjectStatusBlob, UID0003YJ PacketBuffer, UID0001HU Socket, UID0001K8 TimerHandler wrappers, Pane invalidation, Surface presentation, `g_pScreenPane`, SoundManager/config/tile-dimension/movement-scale globals, exact ObjectList method pages, and current load/draw/state children.

### Exact Verify-Only Paths

- `by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md`
- `by-memory/0x00504b90-0x00504df1.MapPaneLoadCompressedMapFile.md`
- `by-memory/0x00504e00-0x00505075.MapPaneSaveCompressedMapFile.md`
- `by-class/ObjectStatusBlob.md`
- `by-file/ObjectStatusBlob.md`
- `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`
- `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`
- `by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md`
- `by-class/Pane.md`
- `by-file/Pane.md`
- `by-memory/0x00557140-0x00557377.SurfaceRenderPresentation.md`
- `by-file/Surface.md`
- `by-global/g_pScreenPane.md`
- `by-class/SoundManager.md`
- `by-file/SoundManager.md`
- `by-memory/0x0067a7d0-0x0067a7d4.g_pSoundManager.md`
- `by-class/Config.md`
- `by-file/Config.md`
- `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`
- `by-global/g_movementSubstepScale.md`
- `by-memory/0x0066da96-0x0066da97.g_movementSubstepScale.md`
- `by-memory/0x0066da9c-0x0066da9e.g_mapTilePixelWidth.md`
- `by-memory/0x0066daa0-0x0066daa2.g_mapTilePixelHeight.md`
- `by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md`
- `by-memory/0x00530ee0-0x00531473.ObjectListLifecycle.md`

- Renamed/moved/archived: none. B005 manually changed no manual coverage, generated, tracker, audit, supervisor, validator-state, queue/lock, or lifecycle file. Validator-owned refresh side effects are disclosed above.
- Report execution: not run; no execute/probe/count/move/archive/lifecycle command was issued. The generated lease report contained zero B005 rows after the final release.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor Gate 1 validation completed before implementation.
- [x] C01-C02 applied to UID00037X: exact `90/92` owner-none false/blank split index, Item Summary, range/hash/inventory/nesting/history/evidence.
- [x] Seven exact child pages registered serially in address order; every real UID replaced its token before cross-linking.
- [x] Destinations 2-8 and exact child scores/owners/emitters/Item Summaries/nesting/bodies applied without compression, including complete FlashMapColor and FinishVisibleObjectRefresh source and missing-route liveness caps.
- [x] Destination 9 and `90/92` applied to UID0003UI with exact collect/sort, subtype, elapsed, full-count/nine-cap, local-terminator, value-first ABI, and compiler-exclusion facts.
- [x] Destinations 10-13 applied byte-for-byte to complete UserPane/ObjectList/ObjectPane/LivingObjectPane class unions with unrelated/current content preserved.
- [x] Destination 14 and `89/91` applied to UID0002AB; four static definitions preserved, only selected-id linkage corrected, and UID0000OH synchronized.
- [x] Destination 15 applied to UID0003ZS and timer-id-5 set/clear chain synchronized at unchanged score.
- [x] UID00007Q/UID0000L3/UID00042K, UID0003TO/UID00037V/UID0001B1/UID0003TK/UID0001AW, UID0000P1/UID0000M4/UID0000M5/UID0000KU, UID0001AT/UID00037Y, and four internal ignored spans synchronized with unrelated/concurrent content preserved.
- [x] All bytes/hashes/instructions/CFG/EH/caller/callee/xref/table/padding/field/global/resource evidence, route negatives, inline analogs, producer/consumer lifecycles, null/count quirks, history, rejected alternatives, compiler exclusions, and lexical caps preserved.
- [x] C33 stable dependencies verified without edit because reread exposed no exact contradiction.
- [x] All accepted C++/declaration content remains exclusively in 15 exact managed destination blocks; no third-party import applies.
- [x] Exact supervisor-owned manual coverage text preserved; B005 did not manually edit coverage or validator-owned generated/tracker state.
- [x] Every ordinary page was leased, reread, edited, scoped-validated, and released serially; real UIDs and validator command IDs/timestamps/exits/ok/warnings/side effects are recorded.
- [x] Authoritative waited generated refresh `000000012202` completed and exact MapPane/UserPane/class/global definition/marker/count/order/compiler-exclusion assertions passed.
- [x] C01-C35 use legal terminal states with destination/validator/generated proof and the report is reconciled to archive-neutral callback truth.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation.
- [x] All C01-C35 claims are `applied` or `already-present`; no accepted item is blocked.
- [x] Seven real child UIDs recorded and all brace tokens replaced before references.
- [x] All 15 managed blocks applied exactly to named destinations and all normalized hashes recorded.
- [x] All target/support evidence incorporated at report-level detail with unrelated/current content preserved.
- [x] Scoped validators and authoritative waited generated refresh recorded and successful.
- [x] Changed/verify-only paths, generated hashes/counts/order/markers, and every lease release recorded.
- [x] Generated lease report contains zero B005 rows.
- [x] No execute_report/probe/lifecycle/move/archive, IDA mutation, or manual coverage/generated/tracker/audit/supervisor/validator-state edit performed.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000012308","destination_path":"executed-b-agent-research/B005/00037X-MapPaneInteractionMapChangeCore-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/00037X-MapPaneInteractionMapChangeCore-source-quality.md","timestamp":"2026-07-14T21:35:20-04:00","uid":"00037X"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
