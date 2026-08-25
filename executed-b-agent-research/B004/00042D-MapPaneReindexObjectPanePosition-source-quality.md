** TARGET-REPORT-UID:00042D **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# UID00042D MapPane ReindexObjectPanePosition Source-Quality Research

** AGENT: Agent-B004 **
** REPORT-SCOPE: implementation callback complete; target by-memory doc edited and validated; no execute_report run **
** TARGET_UID: 00042D **
** TARGET_DOC: by-memory/0x00505940-0x005059cb.MapPaneReindexObjectPanePosition.md **
** TARGET_RANGE: 0x00505940-0x005059cb **
** MCP_SESSION_USED: nexustk_supervisor_20260704 **

## Finalized Report / Current Recommendation

The accepted implementation callback has been applied. [UID:00042D][by-memory/0x00505940-0x005059cb.MapPaneReindexObjectPanePosition.md] now records `COMPLETION:88` / `CONFIDENCE:91`, preserving `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, blank `EMITTER_POSITION_OPTIONAL`, `Nested:0`, and the existing formal `MapPane::ReindexObjectPanePosition(ObjectPane *objectPane, int removeRow, int removeColumn, int addRow, int addColumn)` C++ body.

The target is a source-ready MapPane helper. Current MCP evidence confirms a modeled `sub_505940` function at `0x00505940` with exact size `0x8b` / 139 bytes, a normal `retn 14h` thiscall body, eight direct code callers, no end xrefs, no VA/RVA pointer-pattern hits for the start/end addresses, unique full-range signature, and exact compiler padding on both sides. The behavior is to guard `m_objectList` at `this+0x424`, call `ObjectList::HasValidGridOrigin()`, save the `ObjectPane` map position, temporarily write remove/add coordinate pairs at `ObjectPane+0x100/+0x104`, call `ObjectList::RemoveObjectPane(objectPane)` then `ObjectList::AddObjectPane(objectPane)`, and restore the saved coordinate pair.

The callback updated the target evidence and item summary at report-level detail. Support docs were inspected and found already present at same-or-greater route/dependency detail: `by-class/MapPane.md`, `by-file/MapPane.md`, `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`, ObjectList/ObjectPane dependency docs, and LivingObjectPane caller docs. A separate stale-documentation issue exists in FittingRoom docs: unrelated FittingRoom pages reuse UID00042D and link it to this MapPane target while describing FittingRoom no-route initializer behavior. Per supervisor instruction, that collision was recorded as stale/excluded and not edited in this callback.

## Supporting Research

- Read the assigned Agent-B004 `goal.md` and project `ntk-b-agent-workflow` skill, including the B-agent research/implementation workflow, score blocker audit standard, report template, and `by-structure.md` IDA MCP output discipline.
- Read the target file and current MapPane/ObjectList/ObjectPane support docs using local `rg`/bounded file reads.
- Rechecked current MCP availability after supervisor resume. `idb_list` request `20` returned one active worker session, `nexustk_supervisor_20260704`, for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_active=true`, `is_analyzing=false`, worker pid `10024`.
- `server_health` request `30` returned `status=ok`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
- Used narrow MCP calls only: `lookup_funcs`, `xrefs_to`, `analyze_function`, `decompile`, `callees`, `basic_blocks`, `get_bytes`, `insn_query`, `find_bytes`, and `make_signature_for_range` over the target and immediate dependency addresses.
- During the implementation callback, only the target by-memory doc was edited among by-* docs. Generated/project-level changes were validator refresh side effects, not manual edits.

## Target

- Target doc: `by-memory/0x00505940-0x005059cb.MapPaneReindexObjectPanePosition.md`.
- Current target metadata after callback: `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, blank optional emitter position, `Nested:0`.
- The formal C++ was preserved exactly with no signature/body change.
- Historical pre-callback metadata was `COMPLETION:86`, `CONFIDENCE:88`.
- Current generated output `auto-generated/NexusTK/map/MapPane.cpp` header shows generated refresh command `000000006321`, refreshed `2026-07-04T13:15:16-04:00`; UID00042D now appears as `Completion:88 | Confidence:91` while emitting `MapPane::ReindexObjectPanePosition(...)`.

## Current Target State

The by-memory target is now reconstructable, source-emitting, and callback-synchronized at `88/91`. It retains the accepted B009 formal C++ block and B005 support sync for `ObjectList::HasValidGridOrigin()`. The B004 callback added current live MCP evidence for the exact function object, callees, callers, bytes, padding, pointer-negative checks, unique signature, restore behavior, source placement, and rejected alternatives.

The target doc now enumerates the eight direct code xrefs, zero end xrefs, current session `nexustk_supervisor_20260704`, function size `0x8b`, exact pre/post padding, unique signature, and no VA/RVA pointer-pattern evidence. Named support docs were inspected and left unchanged because their MapPane route, ObjectList/ObjectPane dependency names, and LivingObjectPane old/new ordering evidence were already present.

## Executive Recommendation

Keep UID00042D as a MapPane-owned exact child method emitted through [UID:00007Q][by-class/MapPane.md]. Preserve the formal C++ and update the evidence. Do not move ownership to ObjectList, ObjectPane, LivingObjectPane, AttachmentAnchorResolver, the broad [UID:0001AP] aggregate, or any FittingRoom source family.

The existing method name `ReindexObjectPanePosition` is source-facing enough and more precise than the caller-side `MoveObject` alias seen in some LivingObjectPane docs. The helper is not a general movement method; it temporarily rewrites `ObjectPane` coordinate fields solely to remove and reinsert an object in MapPane's `m_objectList`, then restores the saved object position.

## Supervisor Active Recheck

- MCP active session: `nexustk_supervisor_20260704`.
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Health: `status=ok`, Hex-Rays ready, auto-analysis ready.
- `lookup_funcs` request `31` resolved `0x00505940` to `sub_505940` size `0x8b`; `0x0050593e` and `0x005059cb` are not functions; `0x005059d0` is successor `sub_5059D0` size `0x228`.
- `analyze_function` request `34` and `decompile` request `36` returned the expected body shape, callees, callers, and four basic blocks.
- No MCP fallback-only conclusions are used.

## Inference Research Guidance Check

This target is not a raw no-route leaf and not an empty-emitter candidate. IDA models it as a normal function, Hex-Rays decompiles it, and there are eight static code xrefs into the entry. The target clears the source-quality gate because behavior, owner, source placement, callees, caller set, and formal C++ are all supported by current live evidence and prior accepted MapPane/ObjectList/ObjectPane docs.

Inference remains capped below `95/95` because exact original public/private spelling is not proven, `ReindexObjectPanePosition` is an accepted source-facing name rather than a symbol-recovered name, and `ObjectPane` coordinate field vocabulary has minor `m_mapX/m_mapY` versus `m_mapColumn/m_mapRow` naming caveats across docs.

## Heuristic / Inference Reanalysis And Validation

Helper/source-quality blockers were rechecked. The target has a real function object, direct callers, and source-shaped dependencies, so the stale "raw helper" or "aggregate-only" blocker does not apply. The target should not be lowered or blanked because generated output already emits one coherent MapPane method body and current MCP revalidates that route.

Scalar-wrapper or compiler-generated separation is not relevant. The function has a normal prologue and `retn 14h`, no delete flag, no vtable restore, no EH-only body, no switch-table-only body, and no helper thunk shape. Preceding bytes `0x0050593e-0x00505940` are `cc cc`; following bytes `0x005059cb-0x005059d0` are `cc cc cc cc cc`.

Global/singleton ownership is rejected. The receiver is `MapPane *this`; the object list is reached from `this+0x424`; the target has no global receiver or singleton publish/clear behavior.

Source placement remains `MapPane.cpp` / [UID:00007Q][by-class/MapPane.md]. ObjectList owns `HasValidGridOrigin`, `RemoveObjectPane`, and `AddObjectPane`; ObjectPane owns map coordinate storage and `GetMapPosition`; LivingObjectPane callers own higher-level actor movement/warp logic. UID00042D only coordinates these dependencies for MapPane's object index.

## Evidence Standards Used

- Current live MCP evidence must support the active recommendation.
- Existing by-* docs are evidence only when they align with current MCP or accepted executed reports.
- Formal C++ is recommended only when owner, signature, behavior, callees, and caller route are sufficiently proven.
- Broad aggregate docs should not duplicate exact child C++ bodies.
- Generated output is read-only evidence; Agent-B004 did not hand-edit generated files or coverage reports.
- Any stale duplicate UID or cross-family doc issue must be reported, not silently folded into the MapPane implementation.

## Evidence Checked

- `by-memory/0x00505940-0x005059cb.MapPaneReindexObjectPanePosition.md`: target metadata, formal C++ body, status, evidence, cross-references, and change history.
- `by-class/MapPane.md`: MapPane object ownership/indexing family, `m_objectList` field at `+0x424`, exact child inventory including UID00042D, and accepted B009 aggregate split.
- `by-file/MapPane.md`: MapPane source-file route and MapPane.cpp ownership family.
- `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`: parent aggregate row for UID00042D and B009 split evidence.
- `by-class/ObjectList.md`, `by-file/ObjectList.md`, `by-memory/0x00531480-0x00531498.ObjectListOriginInitializedCheck.md`, `by-memory/0x005314a0-0x00531c10.ObjectListTypeDispatchInsertCategorize.md`, and `by-memory/0x00531c10-0x00532180.ObjectListTypeDispatchRemove.md`: dependency method names and ownership.
- `by-class/ObjectPane.md` and `by-file/ObjectPane.md`: `ObjectPane` map coordinate field ownership and `GetMapPosition` child route.
- `by-memory/0x005a5a90-0x005a5b79.LivingObjectPaneWarpToPosition.md`, `by-memory/0x0053c390-0x0053c5da.LivingObjectPaneTryStepForward.md`, and `by-memory/0x0053bec0-0x0053c367.LivingObjectPaneLinkedPositionAndModeHelpers.md`: caller-side old/new coordinate ordering and naming caveats.
- `auto-generated/NexusTK/map/MapPane.cpp`: read-only generated freshness and current UID00042D emission.
- FittingRoom support docs containing stale/duplicate UID00042D references were searched and recorded as a support hygiene issue, not edited.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
|---|---:|---|---|---|---|---|
| 42D-001 | Current active MCP proof source is `nexustk_supervisor_20260704`, not an older session. | High | `idb_list` request `20`; `server_health` request `30`, status ok, Hex-Rays ready. | Target `## Evidence`; report audit note. | incorporate | applied - target line 51 records session/health proof. |
| 42D-002 | `0x00505940` is a modeled function `sub_505940` of size `0x8b`; boundaries `0x0050593e` and `0x005059cb` are not functions. | High | `lookup_funcs` request `31`. | Target status/evidence. | incorporate | applied - target line 38 summary and line 52 evidence record `sub_505940`, `0x8b`, and boundary facts. |
| 42D-003 | Exact range bytes are unique and bounded by padding: `cc cc` before and five `cc` bytes after. | High | `get_bytes` request `39`; `make_signature_for_range` request `42`, unique true. | Target evidence and range/split notes. | incorporate | applied - target line 53 records exact range, `cc` padding, and unique signature. |
| 42D-004 | Formal C++ should remain `MapPane::ReindexObjectPanePosition(ObjectPane *, int, int, int, int)` with no body change. | High | Existing target formal block; `analyze_function` request `34`; caller argument ordering in LivingObjectPane support. | Target formal `RECONSTRUCTION_CPP CODE`. | already-present | already-present - target formal block was preserved exactly; no C++ diff was introduced. |
| 42D-005 | `this+0x424` is `m_objectList` and the target returns when it is null. | High | Disasm `mov ecx,[eax+424h]`, `jz`; MapPane class field row for `+0x424`. | Target evidence; `by-class/MapPane.md` if stale. | incorporate | applied - target lines 38 and 56 record `m_objectList` at `this+0x424`; class support already-present at `by-class/MapPane.md:127`. |
| 42D-006 | Guard call at `0x00505955` is `ObjectList::HasValidGridOrigin()`. | High | `callees` request `37`; ObjectList origin predicate doc says single caller at `0x00505955`. | Target evidence; ObjectList docs already present. | incorporate | applied - target lines 38 and 57 record the guard; ObjectList proof already-present at `by-memory/0x00531480-0x00531498.ObjectListOriginInitializedCheck.md:53`. |
| 42D-007 | The body saves the current ObjectPane coordinate pair through `ObjectPane::GetMapPosition`. | High | Decompile request `36`; ObjectPane class/file docs name `0x005374d0` as `GetMapPosition`, copying `+0x100/+0x104`. | Target evidence. | incorporate | applied - target lines 38 and 58 record `GetMapPosition`; ObjectPane proof already-present at `by-class/ObjectPane.md:35` and `by-file/ObjectPane.md:37`. |
| 42D-008 | The body temporarily writes remove coordinates then add coordinates at ObjectPane `+0x100/+0x104`. | High | `insn_query` request `40`: stores at `0x50597b`, `0x505984`, `0x505998`, `0x5059a1`. | Target evidence and item summary. | incorporate | applied - target lines 38 and 58 record temporary writes at `+0x100/+0x104`. |
| 42D-009 | The target calls `ObjectList::RemoveObjectPane` at `0x00505990` and `ObjectList::AddObjectPane` at `0x005059b1`. | High | `callees` request `37`; ObjectList add/remove child docs. | Target evidence; dependency docs already present. | incorporate | applied - target lines 38 and 59 record remove/add calls; ObjectList support already-present at `by-file/ObjectList.md:40`, `by-memory/0x00531c10-0x00532180.ObjectListTypeDispatchRemove.md:10`, and `by-memory/0x005314a0-0x00531c10.ObjectListTypeDispatchInsertCategorize.md:10`. |
| 42D-010 | The body restores saved coordinates at return using saved row/column values. | High | `insn_query` request `40`: `mov [ebx+104h], edi` and `mov [ebx+100h], esi`; formal C++ restore lines. | Target evidence and item summary. | incorporate | applied - target lines 38 and 60 record saved-coordinate restore. |
| 42D-011 | There are eight direct code xrefs to the target entry and zero xrefs to the exclusive end. | High | `xrefs_to` request `32`: callers at `0x5378d0`, `0x53bef0`, `0x53c0dc`, `0x53c148`, `0x53c444`, `0x53c4b9`, `0x53c527`, `0x5a5aff`; end xrefs zero. | Target cross-reference/evidence section. | incorporate | applied - target lines 38 and 54 enumerate the eight entry callers and zero end xrefs. |
| 42D-012 | VA/RVA pointer-pattern searches for start and end addresses return no hits. | High | `find_bytes` request `41` for `40 59 50 00`, `40 59 10 00`, `CB 59 50 00`, `CB 59 10 00`. | Target negative evidence. | incorporate | applied - target lines 38 and 55 record no VA/RVA pointer-pattern hits. |
| 42D-013 | Owner/emitter remains MapPane UID00007Q; ObjectList, ObjectPane, LivingObjectPane, and broad aggregate ownership are rejected. | High | Receiver is MapPane `this`; `m_objectList` at `+0x424`; dependencies own only called methods/fields. | Target status/source placement; `by-class/MapPane.md`; `by-file/MapPane.md`. | incorporate | applied - target lines 48 and 61 preserve/reinforce MapPane owner and rejected alternatives; MapPane class/file route already-present at `by-class/MapPane.md:18` and `by-file/MapPane.md:4`. |
| 42D-014 | Score should raise to `COMPLETION:88`, `CONFIDENCE:91` while retaining reconstructable and emitter. | Medium-high | Current modeled function, C++ body, callers, and dependencies are strong; confidence capped by original-name/private-public and field-name caveats. | Target metadata. | incorporate | applied - target lines 2-7 show `88/91`, owner `00007Q`, reconstructable true, emitter `00007Q`, blank optional position. |
| 42D-015 | `by-class/MapPane.md` and parent aggregate already contain UID00042D, but may need a brief current-session/specific-evidence sync if callback scope allows. | Medium-high | `by-class/MapPane.md` line with accepted B009 child inventory; parent row names helper behavior tersely. | Support docs. | incorporate | already-present - `by-class/MapPane.md:163` lists UID00042D in exact child inventory; parent aggregate row already-present at `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md:68`; no stale support edit needed. |
| 42D-016 | ObjectList/ObjectPane docs already carry same-or-greater dependency names and field evidence; edit only if direct staleness appears during callback. | High | ObjectList class/file and exact child docs name `HasValidGridOrigin`, `AddObjectPane`, `RemoveObjectPane`; ObjectPane class/file name `GetMapPosition` and `+0x100/+0x104`. | Support docs. | already-present | already-present - ObjectList proof at `by-file/ObjectList.md:40`, `by-class/ObjectList.md:65`, `by-memory/0x00531480-0x00531498.ObjectListOriginInitializedCheck.md:53`, add/remove child pages; ObjectPane proof at `by-class/ObjectPane.md:35` and `by-file/ObjectPane.md:37`. |
| 42D-017 | Caller docs support old/new coordinate argument order; do not rename target to generic `MoveObject`. | Medium-high | `LivingObjectPaneWarpToPosition` records old Y/X then new Y/X; `TryStepForward` uses caller-side `MoveObject` wording. | Target naming note; caller support docs if stale. | incorporate | applied - target line 61 rejects LivingObjectPane ownership/no-code alternatives; caller proof already-present at `by-memory/0x005a5a90-0x005a5b79.LivingObjectPaneWarpToPosition.md:77` and `:86`, with caller-side `MoveObject` wording at `by-memory/0x0053c390-0x0053c5da.LivingObjectPaneTryStepForward.md:35`. |
| 42D-018 | FittingRoom docs contain stale duplicate UID00042D/cross-family references and should not be treated as MapPane evidence. | High | `rg` found duplicate `*** UID:00042D ***` in `0x004219f0-0x00421a20.FittingRoomCatalogEntryNoRouteInitializer.md` and FittingRoom support rows linking FittingRoom behavior to the MapPane target. | Report open question; supervisor/targeted support repair if authorized. | reject-stale | excluded-with-reason - supervisor explicitly banned FittingRoom duplicate/cross-link edits in this callback; stale proof remains at `by-memory/0x004219f0-0x00421a20.FittingRoomCatalogEntryNoRouteInitializer.md:1`, `by-file/FittingRoom.md:61`, and `by-memory/0x00422ba0-0x00422e91.FittingRoomDialogItemStateLoadCategoryFromJson.md:113`. |
| 42D-019 | Generated MapPane.cpp emitted UID00042D at old `86/88` before callback and should refresh only through validator/supervisor flow. | High | Read-only generated header command `000000006307`, refreshed `2026-07-04T12:41:41-04:00`; UID00042D pre-callback emission found. | Report validator/generated freshness notes. | not-applicable | applied - scoped validator command `000000006316` deferred generated refresh; current `auto-generated/NexusTK/map/MapPane.cpp` header shows command `000000006321` at `2026-07-04T13:15:16-04:00` and UID00042D at `88/91` on generated line 579. |

## Positive Evidence Summary

- Modeled IDA function at `0x00505940`, size `0x8b`, exact exclusive end `0x005059cb`.
- Hex-Rays decompile matches the target's existing formal C++ shape.
- Four basic blocks and normal `retn 14h` thiscall cleanup.
- Eight direct code xrefs into the entry, all from object/attachment movement/update paths.
- `m_objectList` receiver field at `this+0x424` is established by MapPane class/file docs.
- Guard call is the established `ObjectList::HasValidGridOrigin()` predicate.
- `ObjectPane::GetMapPosition` and coordinate fields at `+0x100/+0x104` are established by ObjectPane docs.
- Remove/readd calls resolve to accepted `ObjectList::RemoveObjectPane` and `ObjectList::AddObjectPane` children.
- Unique target range signature and no start/end pointer-pattern hits support exact child boundaries.
- Existing generated output already emits one coherent MapPane method body.

## IDA MCP Facts

`lookup_funcs` request `31`:

- `0x005058b0`: `sub_5058B0`, size `0x8e`.
- `0x0050593e`: no function.
- `0x00505940`: `sub_505940`, size `0x8b`.
- `0x005059cb`: no function.
- `0x005059d0`: `sub_5059D0`, size `0x228`.
- `0x00531480`: `sub_531480`, size `0x18`.
- `0x005314a0`: `sub_5314A0`, size `0x73c`.
- `0x00531c10`: `sub_531C10`, size `0x532`.
- `0x005374d0`: `sub_5374D0`, size `0x1b`.

`xrefs_to` request `32`:

- Entry xrefs to `0x00505940`: `0x5378d0`, `0x53bef0`, `0x53c0dc`, `0x53c148`, `0x53c444`, `0x53c4b9`, `0x53c527`, `0x5a5aff`.
- Exclusive-end xrefs to `0x005059cb`: zero.
- Dependency xref to `0x00531480` from target call site `0x00505955`.

`analyze_function` request `34`:

- Prototype shape: `void __thiscall(_DWORD *this, _DWORD *, int, int, int, int)`.
- Size: `139`.
- Basic blocks: `4`.
- Cyclomatic complexity: `3`.
- Callees: `sub_531480`, `sub_5374D0`, `sub_531C10`, `sub_5314A0`.
- Callers: `sub_5378A0`, `sub_53BEC0`, `sub_53C070`, `sub_53C390`, `sub_5A5A90`.

## Function / Child Inventory

| Address/range | Current IDA fact | Source-quality disposition |
|---|---|---|
| `0x005058b0-0x0050593e` | Modeled prior function `sub_5058B0`, size `0x8e`. | Prior sibling, not part of UID00042D. |
| `0x0050593e-0x00505940` | `cc cc` padding. | Boundary proof only. |
| `0x00505940-0x005059cb` | Modeled function `sub_505940`, size `0x8b`, four blocks. | UID00042D, source-ready `MapPane::ReindexObjectPanePosition`. |
| `0x005059cb-0x005059d0` | Five `cc` bytes. | Boundary proof only. |
| `0x005059d0-0x00505bf8` | Modeled successor family starting `sub_5059D0`, size `0x228`. | Separate MapPane child. |

## Direct Xref / Caller Inventory

| Caller site | Function | Source role |
|---|---|---|
| `0x005378d0` | `sub_5378A0` | ObjectPane-family map-position update path. |
| `0x0053bef0` | `sub_53BEC0` | LivingObjectPane linked-position helper; caller docs use `g_pActiveMapPane->MoveObject(...)`. |
| `0x0053c0dc` | `sub_53C070` | LivingObjectPane linked/refresh position path. |
| `0x0053c148` | `sub_53C070` | Second call in same linked/refresh path. |
| `0x0053c444` | `sub_53C390` | LivingObjectPane step-forward path. |
| `0x0053c4b9` | `sub_53C390` | Second call in step-forward path. |
| `0x0053c527` | `sub_53C390` | Third call in step-forward path. |
| `0x005a5aff` | `sub_5A5A90` | `LivingObjectPane::WarpToPosition`, explicitly records old Y/X then new Y/X ordering. |

## Documentation Evidence And IDA Status

The target name and formal body are already present in the by-memory target and generated MapPane.cpp. MapPane docs route object indexing helpers through MapPane, while ObjectList docs own the list operations. ObjectPane docs own the map-coordinate fields and `GetMapPosition`.

The main documentation defect found during research is not on the MapPane target itself. `by-memory/0x004219f0-0x00421a20.FittingRoomCatalogEntryNoRouteInitializer.md` also has `*** UID:00042D ***`, and FittingRoom docs incorrectly link FittingRoom no-route initializer/thunk split text to `by-memory/0x00505940-0x005059cb.MapPaneReindexObjectPanePosition.md`. That is stale support/UID collision evidence and should not be incorporated into MapPane semantics.

## Ranked Ownership Analysis

1. [UID:00007Q][MapPane] is the owner/emitter. The receiver is `this`, the object-list pointer is `this+0x424`, and callers are MapPane/LivingObjectPane/ObjectPane movement and update paths that ask MapPane to reindex an object.
2. [UID:00009Q][ObjectList] is a dependency owner only. It owns `HasValidGridOrigin`, `RemoveObjectPane`, and `AddObjectPane`; UID00042D only calls them.
3. [UID:00009R][ObjectPane] is a dependency owner only. It owns coordinate storage and `GetMapPosition`; UID00042D temporarily mutates those fields to drive MapPane object-list reindexing.
4. [UID:00007B][LivingObjectPane] and object/attachment subclasses are caller owners only. They pass old/new coordinate pairs but do not own the MapPane method body.
5. [UID:0001AP] broad MapPane aggregate is a split/index support page. It should not emit or duplicate this exact child body.
6. FittingRoom docs are unrelated stale UID/cross-link evidence and must not affect UID00042D MapPane ownership.

## Source Placement

Place and emit the method through MapPane, under `NexusTK/map/MapPane.cpp`, via [UID:00007Q][by-class/MapPane.md] and [UID:0000L3][by-file/MapPane.md]. Do not move it to `ObjectList.cpp`; ObjectList already owns the called list methods. Do not move it to `ObjectPane.cpp`; ObjectPane owns fields and getters but not MapPane's object-index orchestration. Do not create a separate source file.

## Range / Split / Padding / Reclassification Analysis

The exact retained body is `0x00505940-0x005059cb`. Current MCP found a function object at the start and no function at the exclusive end. Bytes before and after are `0xcc` alignment. The target has a unique signature and direct caller set, so it should not be merged into its predecessor, successor, parent aggregate, ObjectList child, or ignored padding.

The successor `0x005059d0` is separate and modeled as `sub_5059D0`; it is not part of UID00042D. The generated/ignored padding docs that mention UID00042D adjacent to FittingRoom ranges are stale cross-family references, not valid split evidence for this MapPane target.

## Negative Evidence Summary

- No xrefs to exclusive end `0x005059cb`.
- No VA/RVA pointer-pattern hits for start `0x00505940` or end `0x005059cb`.
- No evidence for ObjectList ownership of the whole body.
- No evidence for ObjectPane ownership of the whole body.
- No evidence for LivingObjectPane ownership of the whole body.
- No evidence for a standalone file-static helper route.
- No need for a raw `sub_505940` name in source docs.
- No support for renaming the target to generic `MoveObject`; caller docs may use that alias, but the body is specifically a reindex-through-remove/add helper.
- No reason to blank the formal C++; the route is static and modeled.
- FittingRoom duplicate UID/cross-link references are stale and should be rejected for this target.

## IDA Rename / Type / Comment Recommendations

IDA DB edits were not requested in the research pass or implementation callback. If supervisor later authorizes IDA edits, safe candidate naming would be:

- Rename `sub_505940` to a MapPane-scoped equivalent of `MapPane::ReindexObjectPanePosition` or a local IDA name that clearly keeps MapPane ownership.
- Keep the first argument as `ObjectPane *objectPane`.
- Keep the four integer coordinate arguments in row/column order as currently reflected by accepted C++: `removeRow`, `removeColumn`, `addRow`, `addColumn`. The machine stores columns at `+0x100` and rows at `+0x104`, but callers pass old Y/X then new Y/X.
- Comment `this+0x424` as `m_objectList`.
- Comment ObjectPane `+0x100/+0x104` as map coordinate fields, with naming caveat that ObjectPane class docs prefer `m_mapX/m_mapY` while the current target C++ uses `m_mapColumn/m_mapRow`.

Items intentionally left unchanged:

- Do not rename the function to `MoveObject` without original-symbol evidence. That name is a caller-side abstraction in LivingObjectPane support, while `ReindexObjectPanePosition` describes the target body.
- Do not introduce a new `MapPoint` UDT or force IDA local types from this pass. Existing C++ already uses `MapPoint savedPosition` as source-facing documentation.
- Do not rename ObjectList callees from this target; their exact child pages already own `HasValidGridOrigin`, `RemoveObjectPane`, and `AddObjectPane`.
- Do not use FittingRoom UID00042D entries as rename/type/comment evidence.

## First-Draft C++ Recommendation

Keep the existing formal block exactly unless callback review discovers a direct contradiction. The target already contains the correct source-facing C++ and the callback should preserve it in this formal `RECONSTRUCTION_CPP CODE` header/block shape:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void MapPane::ReindexObjectPanePosition(ObjectPane *objectPane,
                                        int removeRow,
                                        int removeColumn,
                                        int addRow,
                                        int addColumn)
{
    if (m_objectList == NULL)
        return;

    if (!m_objectList->HasValidGridOrigin())
        return;

    MapPoint savedPosition;
    objectPane->GetMapPosition(&savedPosition);

    objectPane->m_mapColumn = removeColumn;
    objectPane->m_mapRow = removeRow;
    m_objectList->RemoveObjectPane(objectPane);

    objectPane->m_mapColumn = addColumn;
    objectPane->m_mapRow = addRow;
    m_objectList->AddObjectPane(objectPane);

    objectPane->m_mapColumn = savedPosition.column;
    objectPane->m_mapRow = savedPosition.row;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

This is mid-2000s human-source-shaped code: simple null/predicate guards, stack temporary for the saved coordinate pair, direct field assignment, and dependency calls rather than lambdas/templates/local helper abstractions. Do not emit ObjectList method bodies here.

## Final Recommendation

Implemented as a targeted evidence and score upgrade:

- Target metadata is now `COMPLETION:88`, `CONFIDENCE:91`.
- Owner/emitter/reconstructable/formal C++ were preserved.
- Target evidence now carries current MCP proof: session `nexustk_supervisor_20260704`, exact function size/range, unique signature, padding, callers, callees, disassembly behavior, pointer-pattern negatives, and source-placement reasoning.
- MapPane, ObjectList, ObjectPane, and LivingObjectPane support docs were inspected and found already present at adequate detail.
- Stale FittingRoom duplicate-UID/cross-link text was excluded from this MapPane callback per supervisor instruction.
- Scoped validator command `000000006316` passed for the edited target file.

## Recommended Target Doc Changes

Applied to `by-memory/0x00505940-0x005059cb.MapPaneReindexObjectPanePosition.md`:

- Changed `COMPLETION:86` to `COMPLETION:88`.
- Changed `CONFIDENCE:88` to `CONFIDENCE:91`.
- Kept `CANONICAL_OWNER:00007Q`.
- Kept `RECONSTRUCTABLE:TRUE`.
- Kept `EMITTER_UIDS:00007Q`.
- Kept blank `EMITTER_POSITION_OPTIONAL`.
- Kept `Nested:0`.
- Kept the existing formal C++ body unchanged.
- Expanded item summary/evidence with current MCP session `nexustk_supervisor_20260704`, modeled function size `0x8b`, exact range, padding, direct caller list, dependency calls, coordinate-field offsets, restore behavior, no end-xrefs, no pointer-pattern hits, unique signature, rejected owners, and confidence caps.

## Recommended Support Doc Changes

- `by-class/MapPane.md`: inspected and already-present at `by-class/MapPane.md:18`, `:127`, and `:163`; no support edit needed.
- `by-file/MapPane.md`: inspected and already-present for MapPane.cpp route at `by-file/MapPane.md:4`, `:123`, and `:229`; no support edit needed.
- `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`: inspected and already-present UID00042D row/child ownership at `:68` and `:215`; parent aggregate metadata unchanged.
- `by-class/ObjectList.md`, `by-file/ObjectList.md`, and exact ObjectList child pages: already-present for `HasValidGridOrigin`, `AddObjectPane`, and `RemoveObjectPane`; no support edit needed.
- `by-class/ObjectPane.md` and `by-file/ObjectPane.md`: already-present for `GetMapPosition` and `+0x100/+0x104`; no support edit needed.
- LivingObjectPane caller pages: already-present for old/new ordering and helper name; no caller support edit needed.
- FittingRoom docs with duplicate UID00042D references: excluded-with-reason per supervisor instruction; no FittingRoom edit made.

## Score And Metadata Recommendation

Applied target score: `COMPLETION:88`, `CONFIDENCE:91`.

Completion rationale: the target has a modeled function, static callers, accepted source owner, existing formal C++ body, direct dependency names, exact range, generated output emission, and current MCP confirmation. It does not reach `90+` because original method name and exact private/public declaration placement are inferred from source-quality evidence rather than symbol recovery, and the field-name vocabulary still has column/row versus X/Y aliases.

Confidence rationale: behavior and ownership are strong. Confidence remains below `92` because current source-facing name is reconstructed, not symbol-confirmed, and because duplicate UID00042D stale FittingRoom docs create documentation hygiene risk even though they do not undermine target semantics.

## Open Questions With Attempted Resolution

- Is `ReindexObjectPanePosition` the original method name? Not proven. It is still the best source-facing name because it describes the body more precisely than caller-side `MoveObject`.
- Are coordinate field names `m_mapColumn/m_mapRow` or `m_mapX/m_mapY`? ObjectPane docs prefer `m_mapX/m_mapY`; target C++ currently uses column/row. Keep current formal body for stability and document the alias caveat.
- Should FittingRoom duplicate UID00042D docs be repaired now? Not in this callback scope. They are stale and potentially harmful for UID lookup, but the supervisor explicitly prohibited editing them in this MapPane callback.
- Does generated MapPane.cpp need manual editing? No. It is read-only generated output and should refresh through validator/supervisor flow after by-* changes.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual coverage report edits are recommended or allowed. Historical pre-callback generated tracker state mapped UID00042D to the MapPane target at `86/88` with reports `0`; after the callback, scoped validator command `000000006316` updated projected stats and the deferred generated refresh moved `auto-generated/NexusTK/map/MapPane.cpp` to UID00042D `88/91`. Supervisor lifecycle remains authoritative for final tracker/report execution state. Do not hand-edit tracker, generated reports, coverage reports, or validator state.

## Follow-Up Actions

- Supervisor Gate 2 / execute review of this implemented report.
- Do not run `execute_report` from Agent-B004; supervisor owns final report execution.
- If supervisor wants the FittingRoom duplicate UID/cross-link issue repaired, issue a separate explicit support/UID hygiene callback; do not fold it silently into MapPane by-* edits.

## Confidence

Overall report confidence: high for target behavior, range, ownership, and current MCP evidence; medium-high for exact source-facing name and field spellings. Recommended metadata cap `88/91` reflects that split.

## Validator Results

Report-only phase: no validators were run before Gate 1.

Implementation callback validator:

> Executable block R001 was removed from this report and preserved verbatim in [00042D-MapPaneReindexObjectPanePosition-source-quality-removed.md](00042D-MapPaneReindexObjectPanePosition-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Command id: `000000006316`.
- Command timestamp: `2026-07-04T13:11:26-04:00`.
- Exit code: `0`.
- `ok`: `1`.
- Warnings/errors: none reported by validator.
- Target updates: `completion_update 00042D ... 88`; `confidence_update 00042D ... 91`.
- Validator side effects: `projected_stats_update: 1`, `stats_row_remove: 1`, `stats_rescore_recommended: 1`; `project-level/-auto-completion-stats.md` was updated by the validator and recommends occasional full/documented/rescore.
- Generated refresh: validator returned `generated_refresh: deferred`, `generated_refresh_command_id: 000000006316`, `generated_refresh_timestamp: 2026-07-04T13:11:26-04:00`.
- Generated freshness after deferred refresh: `auto-generated/NexusTK/map/MapPane.cpp` header now reports validator command `000000006321`, refreshed `2026-07-04T13:15:16-04:00`, source file UID `0000L3`; UID00042D generated line 579 now reports `Completion:88 | Confidence:91`.

## Changed Files

Edited by Agent-B004:

- `by-memory/0x00505940-0x005059cb.MapPaneReindexObjectPanePosition.md`
- `tools/leaser/Agents/Agent-B004/research/00042D-MapPaneReindexObjectPanePosition-source-quality.md`

Validator/leaser side effects observed:

- `auto-generated/NexusTK/map/MapPane.cpp` refreshed by validator deferred generated refresh.
- `project-level/-auto-completion-stats.md` updated by scoped validator projected stats.
- `tools/leaser/Agents/current_leases.md` updated by leaser lease/unlease report generation.

No support by-* docs were edited. FittingRoom duplicate UID/cross-link docs were explicitly excluded per supervisor instruction.

## Implementation Tracking Checklist

- [x] Target metadata: set `by-memory/0x00505940-0x005059cb.MapPaneReindexObjectPanePosition.md` to `COMPLETION:88`, `CONFIDENCE:91` (target lines 2-3; validator command `000000006316`).
- [x] Target ownership/emitter: verified and preserved `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, blank optional position, `Nested:0` (target lines 4-7 and 39).
- [x] Target formal C++: preserved existing `MapPane::ReindexObjectPanePosition(...)` body unchanged; no direct contradiction found.
- [x] Target evidence: added current MCP session `nexustk_supervisor_20260704`, function size `0x8b`, exact range/padding, unique signature, eight direct xrefs, zero end xrefs, and no VA/RVA pointer-pattern hits (target lines 38 and 51-55).
- [x] Target behavior: recorded `m_objectList` at `this+0x424`, `HasValidGridOrigin` guard, `GetMapPosition`, writes at `ObjectPane+0x100/+0x104`, remove/add calls, and final restore (target lines 56-60).
- [x] Target rejected alternatives: preserved rejection of ObjectList/ObjectPane/LivingObjectPane/aggregate/FittingRoom ownership, pointer-table route, no-code downgrade, and stale FittingRoom evidence (target line 61).
- [x] `by-class/MapPane.md`: inspected; already-present proof at `by-class/MapPane.md:18`, `:127`, and `:163`; no stale support edit made.
- [x] `by-file/MapPane.md`: inspected; already-present MapPane.cpp route/path proof at `by-file/MapPane.md:4`, `:123`, and `:229`; no stale support edit made.
- [x] `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`: inspected; already-present UID00042D row at `:68` and exact-child ownership note at `:215`; parent metadata unchanged.
- [x] ObjectList support docs: verified already-present `HasValidGridOrigin`, `RemoveObjectPane`, and `AddObjectPane` details at `by-file/ObjectList.md:40`, `by-class/ObjectList.md:65`, `by-memory/0x00531480-0x00531498.ObjectListOriginInitializedCheck.md:53`, `by-memory/0x00531c10-0x00532180.ObjectListTypeDispatchRemove.md:10`, and `by-memory/0x005314a0-0x00531c10.ObjectListTypeDispatchInsertCategorize.md:10`.
- [x] ObjectPane support docs: verified already-present `GetMapPosition` and coordinate offsets at `by-class/ObjectPane.md:35`, `by-class/ObjectPane.md:54`, and `by-file/ObjectPane.md:37`.
- [x] Caller docs: verified LivingObjectPane old/new coordinate ordering already-present at `by-memory/0x005a5a90-0x005a5b79.LivingObjectPaneWarpToPosition.md:77` and accepted helper-name note at `:86`; no caller support edit made.
- [x] FittingRoom duplicate UID/cross-link issue: excluded-with-reason per supervisor instruction; stale proof remains at `by-memory/0x004219f0-0x00421a20.FittingRoomCatalogEntryNoRouteInitializer.md:1`, `by-file/FittingRoom.md:61`, and `by-memory/0x00422ba0-0x00422e91.FittingRoomDialogItemStateLoadCategoryFromJson.md:113`.
- [x] Validators: ran scoped file validator for edited target only; command `000000006316`, timestamp `2026-07-04T13:11:26-04:00`, exit `0`, ok `1`, no validator warnings/errors.
- [x] Generated freshness: checked `auto-generated/NexusTK/map/MapPane.cpp`; current header command `000000006321` at `2026-07-04T13:15:16-04:00`, UID00042D now generated at `88/91`. Generated output was not hand-edited.
- [x] Report ledger/checklist: updated every accepted claim/checklist item to `applied`, `already-present`, or `excluded-with-reason` with proof; no blocked accepted item remains.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000006322","destination_path":"executed-b-agent-research/B004/00042D-MapPaneReindexObjectPanePosition-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/00042D-MapPaneReindexObjectPanePosition-source-quality.md","timestamp":"2026-07-04T13:20:14-04:00","uid":"00042D"} -->
<!-- {"agent":"B004","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00042D-MapPaneReindexObjectPanePosition-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/00042D-MapPaneReindexObjectPanePosition-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00042D"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
