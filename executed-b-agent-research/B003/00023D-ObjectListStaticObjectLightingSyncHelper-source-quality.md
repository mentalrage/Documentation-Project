** TARGET-REPORT-UID:00023D **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# Agent-B003 source-quality report: [UID:00023D] ObjectList Static Object Lighting Sync Helper

## Finalized Report / Current Recommendation

- Keep [UID:00023D] as one exact source-bearing `ObjectList` method over `0x00530d00-0x00530ed9`, owned by [UID:00009Q] `ObjectList` and emitted through [UID:0000M4] `NexusTK/map/ObjectList.cpp`.
- Current source-facing method: `void ObjectList::RefreshStaticObjectLighting(unsigned short staticObjectId)`.
- The completed ordinary callback placed the target at `COMPLETION:94` / `CONFIDENCE:93` while preserving `CANONICAL_OWNER:00009Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009Q`, literal blank `EMITTER_POSITION_OPTIONAL:`, and `Nested:0`. The dated accepted baseline was `85/90`.
- The target now has the exact nonblank CPP body from Section 22 and blank H. The declaration is present in the class-owned [UID:00009Q] `ObjectList` H channel.
- Current documentation uses the proven inherited `ObjectPane::InvalidateRect(NULL)` interpretation for virtual slot `+0x20`; the former detach/disable interpretation is retained only as corrected history.
- Current `StaticObjEntry` and consumer documentation uses `lightImageIndex`. The former `lightIntensity` name is retained only as superseded history; the signed value removes or suppresses lighting when negative and is passed unchanged to `LightingObjectPane` construction or `SetLightImageIndex` when nonnegative.
- The ordinary callback installed the target body, ObjectList declaration/includes, LightingObjectPane and StaticObjectPane H migrations, the StaticObjImageLib owning-header/H route while preserving later Singleton/EBO/packing work, and external tile-dimension definitions plus H declarations. These are current physical results, not future actions.
- The only direct binary caller is the exact raw `MapPane::RefreshStaticObjectLighting` wrapper at `0x0050e300-0x0050e317`. Its current-PE route remains negative, which caps confidence but does not invalidate either retained source-authored body.

## Supporting Research

- During the dated report-only research phase, mandatory read-only IDA MCP was available through session/database snapshot `supervisor-b007-uid0002YJ-rollback-fresh-20260811`; `server_health` returned `status:ok`, Hex-Rays ready, strings cache ready, and `auto_analysis_ready:false`. Bounded live queries succeeded, so the false auto-analysis flag was recorded as context rather than treated as an outage.
- In that report-only phase, the target, direct wrapper, boundaries, stack frame, function comments, direct xrefs, helper callees, singleton storage, and tile globals were re-read without IDA mutation, backup, save, validator, lifecycle command, report execution, generated refresh, or target/support edit.
- After Gate 1 acceptance, the ordinary callback edited and physically reread the target and 15 support destinations, then ran one scoped validator per final ordinary destination. Section 31 records all 16 command IDs, timestamps, hashes, warnings, and generated-refresh-disabled results. No IDA mutation, report execution/lifecycle command, coverage edit, or generated refresh occurred during that callback.
- Current by-* documentation was re-opened during the callback for the target, ObjectList class/file, LightingObjectPane class/file, StaticObjectPane class/file, StaticObjImageLib class/file/local cluster/global/storage, StaticObjEntry, tile dimensions, the MapPane wrapper aggregate, and the MapPane static-object creator.
- Matching executed-report leads were searched by `00023D`, `0x00530d00`, `RefreshStaticObjectLighting`, `lightIntensity`, `lightImageIndex`, and `g_pStaticObjImageLib`. The useful leads were B005 `00037Y`, B008 `0000M4`, B007 `0000E2`, B003 `0003TJ`, and B003 `0001DM`; every target-critical claim below was rechecked against the live IDB or current by-* source contracts.

## Target

- UID: `00023D`.
- Additional target UIDs: none.
- Declared-target inventory:

| Declared UID | Exact by-* path | Report role |
| --- | --- | --- |
| `00023D` | `by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md` | Primary and sole report target; exact ObjectList static-object lighting synchronization method. |

- Document: `by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md`.
- Exact half-open range: `0x00530d00-0x00530ed9`, length `0x1d9` / `473` bytes.
- Current persisted IDA name/type: `ObjectList_RefreshStaticObjectLighting`, `int __thiscall(ObjectList *this, unsigned __int16)`; the source-facing `void` ABI remains in formal C++ rather than an IDA prototype rewrite.
- Current source entity: `void ObjectList::RefreshStaticObjectLighting(unsigned short staticObjectId)` in `NexusTK/map/ObjectList.cpp`.
- Current physical target metadata: `COMPLETION:94`, `CONFIDENCE:93`, `CANONICAL_OWNER:00009Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009Q`, literal blank `EMITTER_POSITION_OPTIONAL:`, `Nested:0`, nonblank CPP containing the exact Section 22 body, and blank H because the class page owns the declaration.
- Dated accepted pre-callback baseline: `COMPLETION:85`, `CONFIDENCE:90`, the same owner/reconstructable/emitter/blank-position/`Nested:0` route, blank CPP, and blank H. It is retained as implementation history, not current state.

## Current Target State

- Physical metadata is exactly `COMPLETION:94`, `CONFIDENCE:93`, `CANONICAL_OWNER:00009Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009Q`, literal blank `EMITTER_POSITION_OPTIONAL:`, and `Nested:0`; CPP is nonblank with the exact complete method body and H is blank under the ObjectList class declaration.
- The page documents the exact static-row scan, `StaticObjEntry` dependency, attached lighting object, negative-value removal path, setter path, missing-light creation path, helper inventory, source order, wrapper boundary, route-negative caveat, and historical corrections.
- The ordinary callback repaired the former slot `+0x20` detach/disable wording, provisional wrapper-name caveat, intensity/index inconsistency, blank target formal body, CPP-only support declarations, and missing shared extern declarations. Those defects remain only in explicitly dated historical evidence.
- Existing owner/emitter routing is correct and does not require a split, merge, range change, new UID, or ownership reassignment.
- The ordinary callback did not manually edit generated output. The later supervisor-owned coherent refresh/readback completed under command `000000022770`: current generated `ObjectList.cpp` and `ObjectList.h` contain the complete routed method/declaration and no UID00023D empty-emitter marker or raw IDA label in the target body.

## Executive Recommendation

Treat this function as a normal retained `ObjectList` maintenance method. It synchronizes every live `StaticObjectPane` whose `m_staticObjectId` matches the changed table entry: invalidate the pane, inspect its attached light, remove/delete a light when the entry index becomes negative, update an existing light when the index remains valid, or create/register/attach a new `LightingObjectPane` when lighting becomes enabled. The exact caller wrapper is MapPane-owned, but the loop and ObjectList storage accesses make the callee unambiguously ObjectList-owned.

The reconstructed body should preserve observed behavior rather than decompiler shape: no metadata null check, signed index tests, `m_gridHeight + 12` row bound, list pointer-slot dereference, unconditional pane invalidation after id match, remove-at-before-detach-before-delete ordering, ordinary `new`, `AddObjectPane` before `AttachObject`, and exact tile-height offset arithmetic.

## Supervisor Active Recheck

- The ordinary UID00023D implementation callback and the independently credited supervisor IDA, manual-coverage, generated-readback, and no-change work are complete. All 63 claim rows are checked: 60 are `applied` and the three protected no-change/boundary rows are `already-present`.
- The persisted supervisor Gate 2B receipt records four function renames, ten occupied-row stack renames, four function comments plus the map-position comment and two tile-global comments, exact no-change proof for the raw wrapper and singleton storage, one save, and a distinct-session persisted reread.
- Manual coverage commands `000000022765` through `000000022769` applied and validated all 16 exact UID-keyed rows. Coherent command `000000022770` refreshed and physically verified the generated ObjectList and support CPP/H outputs.
- Exact-artifact gate truth remains authoritative only from the external supervisor audit ledger. Report lifecycle/archive state remains authoritative only from the current report path and validator-owned status/history metadata; historical execution `000000022771` and invalidation `000000022775` are facts about earlier artifact movement, not a self-declared current lifecycle state.
- The prior UID00041S report remains frozen and was not read, edited, moved, or executed during this assignment.

## Inference Research Guidance Check

- Binary facts are separated from inferred source shape. Addresses, bytes, xrefs, calls, offsets, branches, list operations, vtable slots, and range boundaries are direct facts. Method/member spellings and exact header organization are evidence-backed source reconstruction.
- Compiler artifacts are not copied into final source. The `int` return, SEH state, `Block`, `v30`, raw vtable calls, pointer arithmetic, and allocation-null lowering are compiler/decompiler artifacts; the human source is a `void` method with ordinary methods, locals, and `new`/`delete`.
- Lack of original symbols does not justify `sub_`, `unk_`, `a2`, `v27`, or `lightIntensity` in final source. Names are selected from established subsystem vocabulary and direct behavior.
- No Wave2/Wave3 material was used as authority.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Best current resolution | Rejected alternative |
| --- | --- | --- | --- |
| Method name | Exact MapPane wrapper, B005 wrapper analysis, ObjectList body/storage, current project naming | `ObjectList::RefreshStaticObjectLighting` | `SyncStaticObjectLighting` is understandable but less consistent with the established wrapper and refresh vocabulary |
| Return type | Tail wrapper source shape, all paths, no semantic return consumer | `void` | IDA `int` is incidental EAX carry from calls/loop state |
| Slot `+0x20` | Current ObjectPane formal vtable contract and call argument zero | `InvalidateRect(NULL)` | Detach/disable has the wrong slot and wrong argument contract |
| Entry `+0x00` | Signed branch, constructor final argument, setter name/body, MapPane attach helper | `int lightImageIndex` | Intensity/radius/color do not explain table selection or `SetLightImageIndex` |
| Entry `+0x04` | Height arithmetic in target and MapPane creator | `unsigned char lightHeightClass` | Palette group is not used by either consumer |
| Attached object | Exact `this[70]` accessor, ObjectPane `+0x118` contract, LightingObjectPane anchor relationship | `ObjectPane::GetAttachedObject()` cast to `LightingObjectPane *` | Raw field load or generic interface obscures the established type |
| Negative path | Lighting list pointer equality, `RemoveAt(index,1)`, static-pane detach, deleting destructor flags 1 | Remove from ObjectList light list, detach anchor, then `delete` | Suppress-only, setter-to-`-1`, or delete-before-list-removal changes behavior |
| Positive existing path | Exact call to `0x0053c980` | `SetLightImageIndex(entry->lightImageIndex)` | Direct member write skips detach/rebind semantics |
| Positive missing path | Allocation `0x138`, exact constructor, MapPoint row/column, tile globals, Add/Attach order | ordinary `new LightingObjectPane(...)`, register, attach | Manual allocation/vtable writes are compiler lowering |
| Wrapper liveness | One xref into target; zero xrefs/pointer hits into wrapper | Retained route-negative source wrapper; confidence cap only | Calling target dead/compiler-generated is unsupported by source-shaped body and subsystem fit |
| Header route | Current generated/header inventory and class CPP/H channels | Move existing declarations to H and include them from ObjectList.cpp | Forward-declaring classes is insufficient for `new`, methods, fields, and delete |

## Evidence Standards Used

- Direct current-IDB evidence for code/data identity, range, bytes, function model, decompilation, xrefs, stack frame, comments, singleton state, and helper relationships.
- Current by-* formal declarations as source-contract evidence only where they already have stronger supporting research.
- Cross-consumer triangulation for `lightImageIndex`, `lightHeightClass`, ObjectPane attachment, and shared tile globals.
- Negative searches for caller routes and pointer references, used only as bounded negative evidence rather than proof of absence from original source.
- Historical report material used as leads and contradiction history, never as a substitute for current evidence.

## Evidence Checked

- IDA MCP: `server_health`, `inspect_items`, `get_bytes`, `lookup_funcs`, `analyze_function`, `decompile`, `xrefs_to`, `get_comments`, and `stack_frame` on the target, wrapper, singleton, tile globals, and direct helpers.
- Target and direct source roots: `by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md`, `by-class/ObjectList.md`, `by-file/ObjectList.md`.
- Source contracts: `by-class/ObjectPane.md`, `by-class/LightingObjectPane.md`, `by-file/LightingObjectPane.md`, `by-class/StaticObjectPane.md`, `by-file/StaticObjectPane.md`, `by-class/StaticObjImageLib.md`, `by-file/StaticObjImageLib.md`, `by-type/by-struct/StaticObjEntry.md`, and `by-global/MapTilePixelDimensions.md`.
- Direct support pages: `by-memory/0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster.md`, `by-global/g_pStaticObjImageLib.md`, `by-memory/0x0069b448-0x0069b44c.g_pStaticObjImageLib.md`, and `by-memory/0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile.md`.
- Executed leads: B005 `00037Y-MapPaneTileObjectGridRenderCore`, B008 `0000M4-ObjectList-empty-emitter-family`, B007 `0000E2-StaticObjImageLib-class`, B003 `0003TJ-MapPaneRefreshStaticObjectTileRegion`, and B003 `0001DM-LightingObjectPaneScalarDeletingDestructor`.

## Claim And Incorporation Ledger

Parity contract: Section 11 and Section 33 must match exactly after normalizing the Section 33 `Done` column. Parity includes Claim ID, Target UID, Claim, Confidence, Evidence, Destination doc/section, Action, and Verification state. All 63 rows are checked after ordinary callback verification plus externally credited supervisor IDA/manual-coverage/generated/no-change closure.

Canonical mechanics after this additive repair: 63 claims; Action counts are `incorporate:59`, `historicalize:1`, `not-applicable:3`, and zero for every other allowed Action; Verification-state counts are `applied:60`, `already-present:3`, and zero for every other allowed state; checklist allocation is 63 checked / 0 unchecked.

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C23D-001 | 00023D | Preserve exact target range and adjacent padding. Implementation detail: Document `0x00530d00-0x00530ed9`, preceding 9 CC bytes, following 7 CC bytes, and no split. | very strong | Current items and bytes. Callback receipt: physical SHA256 E198B1ADB57021B731D855C6DB3249680846D5697AD9A6DF5B2D97BADDEDDFCF; validator 000000022245 exit 0, ok 1. | by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md | incorporate | applied |
| C23D-002 | 00023D | Correct the source ABI to a void ObjectList method with unsigned-short id. Implementation detail: Set source-facing signature to `void ObjectList::RefreshStaticObjectLighting(unsigned short staticObjectId)`. | strong | Wrapper tail-call and complete target flow. Callback receipt: physical SHA256 E198B1ADB57021B731D855C6DB3249680846D5697AD9A6DF5B2D97BADDEDDFCF; validator 000000022245 exit 0, ok 1. | by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md | incorporate | applied |
| C23D-003 | 00023D | Record the exact extended-row and per-row object scan. Implementation detail: Document `m_gridHeight + 12`, static row lists, cached counts, and pointer-slot dereference. | very strong | Target decompilation and ObjectList layout. Callback receipt: physical SHA256 E198B1ADB57021B731D855C6DB3249680846D5697AD9A6DF5B2D97BADDEDDFCF; validator 000000022245 exit 0, ok 1. | by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md | incorporate | applied |
| C23D-004 | 00023D | Record exact static-object id filtering. Implementation detail: Document unsigned `m_staticObjectId` comparison before all lighting work. | very strong | `+0x128` read and StaticObjectPane declaration. Callback receipt: physical SHA256 E198B1ADB57021B731D855C6DB3249680846D5697AD9A6DF5B2D97BADDEDDFCF; validator 000000022245 exit 0, ok 1. | by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md | incorporate | applied |
| C23D-005 | 00023D | Correct virtual slot `+0x20` to pane invalidation. Implementation detail: Replace detach/disable wording with `InvalidateRect(NULL)` and preserve call order. | strong | ObjectPane vtable contract and zero argument. Callback receipt: physical SHA256 E198B1ADB57021B731D855C6DB3249680846D5697AD9A6DF5B2D97BADDEDDFCF; validator 000000022245 exit 0, ok 1. | by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md | incorporate | applied |
| C23D-006 | 00023D | Resolve attached-light access. Implementation detail: Name `sub_5376C0` as `ObjectPane::GetAttachedObject()` over `+0x118`. | very strong | Exact one-instruction accessor and ObjectPane layout. Callback receipt: physical SHA256 E198B1ADB57021B731D855C6DB3249680846D5697AD9A6DF5B2D97BADDEDDFCF; validator 000000022245 exit 0, ok 1. | by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md | incorporate | applied |
| C23D-007 | 00023D | Preserve negative-index list removal behavior. Implementation detail: Document pointer scan and `m_lightingObjects->RemoveAt(lightIndex, 1)`. | very strong | Target branch and List contract. Callback receipt: physical SHA256 E198B1ADB57021B731D855C6DB3249680846D5697AD9A6DF5B2D97BADDEDDFCF; validator 000000022245 exit 0, ok 1. | by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md | incorporate | applied |
| C23D-008 | 00023D | Preserve detach then delete ordering. Implementation detail: Document `staticObjectPane->DetachObject(); delete lightingObjectPane;` after list removal. | very strong | Exact virtual calls and deleting-destructor flags. Callback receipt: physical SHA256 E198B1ADB57021B731D855C6DB3249680846D5697AD9A6DF5B2D97BADDEDDFCF; validator 000000022245 exit 0, ok 1. | by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md | incorporate | applied |
| C23D-009 | 00023D | Preserve existing-light index update. Implementation detail: Emit `SetLightImageIndex` for nonnegative entries with an existing attachment. | very strong | Direct call to `0x0053c980`. Callback receipt: physical SHA256 E198B1ADB57021B731D855C6DB3249680846D5697AD9A6DF5B2D97BADDEDDFCF; validator 000000022245 exit 0, ok 1. | by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md | incorporate | applied |
| C23D-010 | 00023D | Preserve missing-light construction and attachment. Implementation detail: Document exact constructor arguments, `AddObjectPane`, then `AttachObject`. | strong | Target decompilation and twin MapPane helper. Callback receipt: physical SHA256 E198B1ADB57021B731D855C6DB3249680846D5697AD9A6DF5B2D97BADDEDDFCF; validator 000000022245 exit 0, ok 1. | by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md | incorporate | applied |
| C23D-011 | 00023D | Replace intensity semantics with signed image-index semantics. Implementation detail: Rename `lightIntensity` to `lightImageIndex` and retain the former name as rejected history. | strong | Signed sentinel and two image-index consumers. Callback receipt: later valid packing/type drift preserved; current physical SHA256 34495C232C538EDE62F569C31717AE416FCD8B5075EB0AE7307B53AC8D53C388 at 90/94; B003 validator 000000022253 and independent supervisor Gate 2A validator 000000022389 both exited 0, ok 1. | by-type/by-struct/StaticObjEntry.md | incorporate | applied |
| C23D-012 | 00023D | Retain and strengthen height-class semantics. Implementation detail: Document `lightHeightClass` as the byte used in exact tile-height offset arithmetic. | strong | Target and MapPane creator. Callback receipt: later valid packing/type drift preserved; current physical SHA256 34495C232C538EDE62F569C31717AE416FCD8B5075EB0AE7307B53AC8D53C388 at 90/94; B003 validator 000000022253 and independent supervisor Gate 2A validator 000000022389 both exited 0, ok 1. | by-type/by-struct/StaticObjEntry.md | incorporate | applied |
| C23D-013 | 00023D | Resolve the direct MapPane wrapper name and exact range. Implementation detail: Record `MapPane::RefreshStaticObjectLighting` at `0x0050e300-0x0050e317` and tail-call target. | very strong | Exact bytes and current wrapper review. Callback receipt: physical SHA256 2A20508CB7FCFB1884992E8A068B6D1204D1706A9A1FCA32AF2F007AEE6B252A; validator 000000022252 exit 0, ok 1. | by-memory/0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore.md | incorporate | applied |
| C23D-014 | 00023D | Preserve route-negative liveness evidence without suppressing source. Implementation detail: Record one incoming tail jump, zero wrapper-start xrefs, and zero VA/RVA pointer hits as confidence cap. | very strong | Current xrefs and bounded byte searches. Callback receipt: physical SHA256 E198B1ADB57021B731D855C6DB3249680846D5697AD9A6DF5B2D97BADDEDDFCF; validator 000000022245 exit 0, ok 1. | by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md | incorporate | applied |
| C23D-015 | 00023D | Record complete direct helper inventory. Implementation detail: Add lookup, getter, constructor, setter, map-position, list-add, allocation, and list virtual roles. | very strong | Current analyze/decompile/xrefs. Callback receipt: physical SHA256 E198B1ADB57021B731D855C6DB3249680846D5697AD9A6DF5B2D97BADDEDDFCF; validator 000000022245 exit 0, ok 1. | by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md | incorporate | applied |
| C23D-016 | 00023D | Preserve exact target routing, placement, and nesting metadata. Implementation detail: Change only `85/90` to `94/93`; preserve owner `00009Q`, reconstructable true, emitter `00009Q`, literal blank position, and `Nested:0`. | very strong | Physical target header, `this` fields, and file route. Callback receipt: physical SHA256 E198B1ADB57021B731D855C6DB3249680846D5697AD9A6DF5B2D97BADDEDDFCF; validator 000000022245 exit 0, ok 1. | by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md | incorporate | applied |
| C23D-017 | 00023D | Close source placement without changing the file-page schema. Implementation detail: Replace provisional target wording; preserve `92/93`, owner `FILE`, path `NexusTK/map/`; reconstructable/emitter/position/Nested/formal channels remain N/A because this by-file schema physically has none. | very strong | Wrapper, ObjectList storage evidence, and current file header. Callback receipt: physical SHA256 30AC7D8A65FAF74D0DF861EF35FC58694411897203223895FBA11E23109E0AAB; final validator 000000022251 exit 0, ok 1. | by-file/ObjectList.md | incorporate | applied |
| C23D-018 | 00023D | Emit the complete target formal CPP body. Implementation detail: Insert the exact Section 22 method body; keep H blank. | strong | Full target behavior and support contracts. Callback receipt: physical SHA256 E198B1ADB57021B731D855C6DB3249680846D5697AD9A6DF5B2D97BADDEDDFCF; validator 000000022245 exit 0, ok 1. | by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md | incorporate | applied |
| C23D-019 | 00023D | Keep declaration responsibility on ObjectList H. Implementation detail: State that target H remains blank because class UID00009Q declares the method. | very strong | Existing emitter architecture. Callback receipt: physical SHA256 E198B1ADB57021B731D855C6DB3249680846D5697AD9A6DF5B2D97BADDEDDFCF; validator 000000022245 exit 0, ok 1. | by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md | incorporate | applied |
| C23D-020 | 00023D | Add ObjectList public declaration while preserving exact class metadata. Implementation detail: Insert `void RefreshStaticObjectLighting(unsigned short staticObjectId);`; preserve `92/93`, owner `0000M4`, reconstructable true, emitter `0000M4`, blank position, schema-absent/N/A Nested, and nonblank CPP/nonblank H disposition. | very strong | MapPane wrapper, current class header, and public access requirement. Callback receipt: physical SHA256 9DFCCC3D34C28A207DD87D1B41FB124F0DE798166F18270344C72E51EF582455; validator 000000022247 exit 0, ok 1. | by-class/ObjectList.md | incorporate | applied |
| C23D-021 | 00023D | Add exact ObjectList source includes. Implementation detail: Replace CPP include block with the Section 22 include set before `[[CHILDREN]]`. | strong | Complete-type and global visibility requirements. Callback receipt: physical SHA256 9DFCCC3D34C28A207DD87D1B41FB124F0DE798166F18270344C72E51EF582455; validator 000000022247 exit 0, ok 1. | by-class/ObjectList.md | incorporate | applied |
| C23D-022 | 00023D | Synchronize ObjectList family prose under exact file metadata. Implementation detail: Replace stale caveats and add behavior/source route; preserve `92/93`, owner `FILE`, path `NexusTK/map/`, with reconstructable/emitter/position/Nested/formal channels N/A because the by-file header has none. | strong | Current report closure and physical file header. Callback receipt: physical SHA256 30AC7D8A65FAF74D0DF861EF35FC58694411897203223895FBA11E23109E0AAB; final validator 000000022251 exit 0, ok 1. | by-file/ObjectList.md | incorporate | applied |
| C23D-023 | 00023D | Correct wrapper aggregate boundary without changing support metadata. Implementation detail: Correct end to `0x0050e317`; preserve `87/89`, owner `00007Q`, reconstructable true, emitter `00007Q`, blank position, `Nested:-4`, nonblank CPP, blank H. | very strong | Last instruction, route-negative evidence, and physical support header. Callback receipt: physical SHA256 2A20508CB7FCFB1884992E8A068B6D1204D1706A9A1FCA32AF2F007AEE6B252A; validator 000000022252 exit 0, ok 1. | by-memory/0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore.md | incorporate | applied |
| C23D-024 | 00023D | Upgrade StaticObjEntry documentation and exact metadata. Implementation detail: Preserve the dated accepted `85/88 -> 90/92` callback step, the later valid packing/type work, and the current `90/94`; preserve owner `0000E2`, reconstructable true, emitter `0000E2`, blank position, schema-absent/N/A Nested, blank CPP, and blank H because the parent class H owns the full declaration. | strong | Cross-consumer closure and physical type header. Callback receipt: later valid packing/type drift preserved; current physical SHA256 34495C232C538EDE62F569C31717AE416FCD8B5075EB0AE7307B53AC8D53C388 at 90/94; independent supervisor Gate 2A validator 000000022389 exited 0, ok 1. | by-type/by-struct/StaticObjEntry.md | incorporate | applied |
| C23D-025 | 00023D | Move StaticObjImageLib declaration to H under exact class metadata. Implementation detail: Apply the accepted H and owning-header CPP route while preserving later valid Singleton/EBO/packing additions; final state is `92/96`, owner `0000O7`, reconstructable true, emitter `0000O7`, blank position, schema-absent/N/A Nested, CPP nonblank, and H nonblank. | strong | Complete-type need and physical class header. Callback remediation receipt: SHA256 0D036C1E88AE932A925475BF02B9F40E798AB89DEBB13CD03490DEABB8A03D14; validator 000000022436 exit 0, ok 1; generated refresh skipped. Current read-only physical SHA256 C28BC94256BD6FD1F826E5A856790508A0FFD2DF510A40B8F504F19AA098117E preserves the complete 92/96 owning-header, ImageFrameTable/MemoryMan/CRT, Singleton/EBO, packed-entry, lifecycle, method, layout, and singleton-extern formal state reproduced in Section 22. | by-class/StaticObjImageLib.md | incorporate | applied |
| C23D-026 | 00023D | Synchronize StaticObjImageLib file documentation under exact file metadata. Implementation detail: Preserve the accepted field/header prose and later valid current `90/94`, owner `FILE`, path `NexusTK/render/`; `88/88` remains the dated callback baseline, and reconstructable/emitter/position/Nested/formal channels are N/A because this by-file header has none. | strong | Target, setter research, and physical file header. Independent Gate 2A snapshot SHA256 55BDB10D5DD0E8BE990AD865EC62C2175F03FFE10D0645D157435B02122242A8; validator 000000022391 exit 0, ok 1. Current read-only physical SHA256 9B8981EEB3E289F75D8C786F972997EEAB7ED45A7A7365B3E856B1F8B5797616 retains 90/94 and the accepted UID00023D field/header/source-route facts after later valid additive file work. | by-file/StaticObjImageLib.md | incorporate | applied |
| C23D-027 | 00023D | Synchronize local image-library helper documentation without changing its non-emitting route. Implementation detail: Preserve accepted index/caller prose and later valid current `90/95`, owner `NONE`, reconstructable false, blank emitter, blank position, `Nested:-4`, blank CPP, and blank H; `86/91` remains the dated callback baseline. | strong | `0x004dda30` evidence and physical support header. Callback receipt: later valid score drift preserved; current physical SHA256 7484661816E3D72199889E8F44151CA11F8D0F3B988B175DC16A2475CEEAC804 at 90/95; independent supervisor Gate 2A validator 000000022392 exited 0, ok 1. | by-memory/0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster.md | incorporate | applied |
| C23D-028 | 00023D | Correct MapPane creator field name under exact metadata. Implementation detail: Replace two identifiers; preserve `90/93`, owner `00007Q`, reconstructable true, emitter `00007Q`, blank position, `Nested:0`, nonblank CPP, blank H. | very strong | Shared metadata flow and physical support header. Callback receipt: physical SHA256 F2834C4867E8CB4B46AC13B37545EBA3305A99E1A69644D0333CEC2CDAC759B4; validator 000000022262 exit 0, ok 1. | by-memory/0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile.md | incorporate | applied |
| C23D-029 | 00023D | Move LightingObjectPane declaration to H under exact class metadata. Implementation detail: Apply Section 22 H payload; preserve `90/93`, owner `0000KO`, reconstructable true, emitter `0000KO`, blank position, schema-absent/N/A Nested; CPP stays nonblank and H changes blank to nonblank. | very strong | Complete-type need and physical class header. Callback receipt: physical SHA256 183905BC66588EC57D8B10AB5F74DA1939822F36AA4010885B671DE3A0222E33; validator 000000022264 exit 0, ok 1. | by-class/LightingObjectPane.md | incorporate | applied |
| C23D-030 | 00023D | Synchronize LightingObjectPane file route under exact file metadata. Implementation detail: Add header/ObjectList consumer prose; preserve `89/91`, owner `FILE`, path `NexusTK/map/`; reconstructable/emitter/position/Nested/formal channels are N/A because this by-file header has none. | strong | Existing class contract and physical file header. Callback receipt: physical SHA256 D21C51C88C995A91A99DF87889C7A4779D346F5200F639453A905B72355C4398; validator 000000022265 exit 0, ok 1. | by-file/LightingObjectPane.md | incorporate | applied |
| C23D-031 | 00023D | Move StaticObjectPane declaration to H under exact class metadata. Implementation detail: Apply Section 22 H payload; preserve `90/92`, owner `0000O6`, reconstructable true, emitter `0000O6`, blank position, schema-absent/N/A Nested; CPP stays nonblank and H changes blank to nonblank. | very strong | Complete-type need and physical class header. Callback receipt: physical SHA256 F2A760FB7FB214404C06D159AD0686BB88023D6BF22163A4AB0563EC93DF2F05; validator 000000022277 exit 0, ok 1. | by-class/StaticObjectPane.md | incorporate | applied |
| C23D-032 | 00023D | Synchronize StaticObjectPane file route under exact file metadata. Implementation detail: Add header/ObjectList consumer prose; preserve `90/91`, owner `FILE`, path `NexusTK/map/`; reconstructable/emitter/position/Nested/formal channels are N/A because this by-file header has none. | strong | Existing class contract and physical file header. Callback receipt: physical SHA256 2E7FACC0A3D6AFBFF68E455EEBA7F4BD400E54D928465041633A513D851DAFC0; validator 000000022279 exit 0, ok 1. | by-file/StaticObjectPane.md | incorporate | applied |
| C23D-033 | 00023D | Give tile dimensions external linkage under exact global metadata. Implementation detail: Remove `static`, add H externs; preserve `91/92`, owner `0000L3`, reconstructable true, emitter `0000L3`, blank position, schema-absent/N/A Nested; CPP stays nonblank and H changes blank to nonblank. | very strong | 89/94 consumers and physical global header. Callback receipt: physical SHA256 65F0A9682982680C26C333A454D851058FED3960757AFFA5C0C0C29B1F956B96; validator 000000022280 exit 0, ok 1. | by-global/MapTilePixelDimensions.md | incorporate | applied |
| C23D-034 | 00023D | Preserve singleton source/storage split and both exact metadata records. Implementation detail: Preserve later valid lifecycle drift: global is `92/96`, owner `0000O7`, reconstructable true, emitter `0000O7`, blank position, schema-absent/N/A Nested, nonblank CPP/blank H; storage is `93/97`, owner `0000SD`, reconstructable false, blank emitter/position, `Nested:0`, blank CPP/H. Add UID00023D prose only. | very strong | Four zero bytes, 13 xrefs, and both physical headers. Callback receipt: later valid drift preserved; current global SHA256 DBC0FB5811C056CBCAD52CEF9088753F3A1FF4E6CFD247CBEE415F06668C4FDE at 92/96 and current storage SHA256 0F6BD0A7DD634AAFC70CE252B1C4E31F876EA67E709E0E8BE782FE850CCEC48A at 93/97 non-emitting; independent supervisor Gate 2A validators 000000022399 and 000000022400 exited 0, ok 1. | by-global/g_pStaticObjImageLib.md; by-memory/0x0069b448-0x0069b44c.g_pStaticObjImageLib.md | incorporate | applied |
| C23D-035 | 00023D | Pure-rename and narrow-comment target in IDA without type/frame mutation. Implementation detail: Supervisor applied I23D-01 and persisted `ObjectList_RefreshStaticObjectLighting` plus the exact function-regular comment while preserving type, complete frame, range, bytes, callers, and other comment channels. | strong | Primary-supervisor Gate 2B receipt `2026-08-12T11:52:00-04:00`; distinct-session persistence readback passed. | IDA 0x00530d00 | incorporate | applied |
| C23D-036 | 00023D | Preserve raw MapPane wrapper IDA model as an explicit no-change disposition. Implementation detail: Supervisor verified I23D-02 without defining, renaming, typing, or commenting the raw wrapper. | very strong | Persisted readback: exact raw `0x0050e300-0x0050e317` code/padding, no function/name/type/comments, zero start xrefs. | IDA 0x0050e300 | not-applicable | already-present |
| C23D-037 | 00023D | Pure-rename and narrow-comment StaticObjImageLib accessor without type/frame mutation. Implementation detail: Supervisor persisted `StaticObjImageLib_GetStaticObjectEntry` and the exact function-regular comment while preserving type, range, bytes, two callers, frame, and other channels. | strong | Primary-supervisor Gate 2B receipt and distinct-session persistence readback. | IDA 0x004dda30 | incorporate | applied |
| C23D-038 | 00023D | Pure-rename and narrow-comment attached-object getter without type/frame mutation. Implementation detail: Supervisor persisted `ObjectPane_GetAttachedObject` and the exact function-regular comment while preserving type, range, bytes, sole caller, frame, and other channels. | very strong | Primary-supervisor Gate 2B receipt and distinct-session persistence readback. | IDA 0x005376c0 | incorporate | applied |
| C23D-039 | 00023D | Pure-rename and narrow-comment LightingObjectPane constructor without type/frame mutation. Implementation detail: Supervisor persisted `LightingObjectPane_Constructor` and the exact function-regular comment while preserving type, range, bytes, callers, complete frame, and other channels. | strong | Primary-supervisor Gate 2B receipt and distinct-session persistence readback. | IDA 0x0053c5e0 | incorporate | applied |
| C23D-040 | 00023D | Preserve singleton IDA storage as an explicit no-change disposition. Implementation detail: Supervisor verified I23D-06 without materializing, renaming, typing, or commenting the current head. | very strong | Persisted readback: one-byte `unk_69B448` unknown head, no type/code/data, four zero bytes, 13 xrefs, blank comments. | IDA 0x0069b448 | not-applicable | already-present |
| C23D-041 | 00023D | Apply only ten exact occupied-row stack renames. Implementation detail: Supervisor persisted I23D-07A..J with all 17 offsets, widths, types, order, and protected names unchanged. | strong | Dry runs passed without collision; distinct-session frame readback reproduced the ten semantic names and seven protected rows. | IDA 0x00530d00 stack frame | incorporate | applied |
| C23D-042 | 00023D | Repair three narrow comments and preserve every protected entity. Implementation detail: Supervisor persisted the I23D-08A function-regular map-position comment and I23D-08B/C address-regular tile-global comments while preserving all protected names/types/frames/comments/bytes/xrefs. | strong | Primary-supervisor Gate 2B receipt; exact channel and distinct-session readbacks passed. | IDA target dependencies | incorporate | applied |
| C23D-043 | 00023D | Raise justified target score without crossing 95/95 while preserving exact metadata. Implementation detail: Set `85/90 -> 94/93`; preserve owner `00009Q`, reconstructable true, emitter `00009Q`, blank position, `Nested:0`; CPP becomes nonblank and H remains blank. | strong | Complete behavior/source route; route-negative confidence cap. Callback receipt: physical SHA256 E198B1ADB57021B731D855C6DB3249680846D5697AD9A6DF5B2D97BADDEDDFCF; validator 000000022245 exit 0, ok 1. | by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md | incorporate | applied |
| C23D-044 | 00023D | Preserve corrected historical intensity rationale. Implementation detail: Move `lightIntensity` into explicit superseded-history wording rather than deleting it. | strong | Rule 26 no-loss correction policy. Callback receipt: physical sweep confirms current formal/prose uses lightImageIndex and every retained lightIntensity occurrence is explicitly superseded or rejected history. | by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md; by-class/ObjectList.md; by-file/ObjectList.md; by-memory/0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore.md; by-type/by-struct/StaticObjEntry.md; by-class/StaticObjImageLib.md; by-file/StaticObjImageLib.md; by-memory/0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster.md; by-memory/0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile.md; by-class/LightingObjectPane.md; by-file/LightingObjectPane.md; by-class/StaticObjectPane.md; by-file/StaticObjectPane.md; by-global/MapTilePixelDimensions.md; by-global/g_pStaticObjImageLib.md; by-memory/0x0069b448-0x0069b44c.g_pStaticObjImageLib.md | historicalize | applied |
| C23D-045 | 00023D | Replace the stale UID00023D target manual coverage row in place. Implementation detail: Supervisor applied the exact Section 28 UID00023D replacement once with no insertion or deletion. | strong | Command `000000022765` exit 0, ok 1; exact row reread; by-memory closure SHA256 `F4F52F9AFD0147986EDF38F26666553A7E792CE36027CFDA4F15EC56E3EC0BBD`. | by-memory/-coverage-report.md UID00023D | incorporate | applied |
| C23D-046 | 00023D | Validate every changed ordinary page during callback. Implementation detail: Run one scoped file validator with `--apply --no-generated-refresh --queue-timeout 240`. | very strong | Skill callback contract. Callback receipt: all 16 ordinary destinations passed scoped validation with generated refresh disabled, and narrow class remediation validator 000000022436 also exited 0, ok 1 with generated refresh skipped; original command IDs 000000022245, 000000022247, 000000022251, 000000022252, 000000022253, 000000022259, 000000022261, 000000022262, 000000022264, 000000022265, 000000022277, 000000022279, 000000022280, 000000022282, 000000022283, and 000000022284. | by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md; by-class/ObjectList.md; by-file/ObjectList.md; by-memory/0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore.md; by-type/by-struct/StaticObjEntry.md; by-class/StaticObjImageLib.md; by-file/StaticObjImageLib.md; by-memory/0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster.md; by-memory/0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile.md; by-class/LightingObjectPane.md; by-file/LightingObjectPane.md; by-class/StaticObjectPane.md; by-file/StaticObjectPane.md; by-global/MapTilePixelDimensions.md; by-global/g_pStaticObjImageLib.md; by-memory/0x0069b448-0x0069b44c.g_pStaticObjImageLib.md | incorporate | applied |
| C23D-047 | 00023D | Verify regenerated ObjectList source and required headers. Implementation detail: Supervisor completed coherent generated refresh/readback after ordinary validation. | strong | Command `000000022770`: ObjectList.cpp SHA `83417F5E7CA213DD2122B480F60110B92375642AFAC4CB5F08B35807C9C4DCB2`, ObjectList.h SHA `ECEE3FDD26130BA9B99EA7B8B5A61A38602F0D32BE2DF1DAB8CD624FFC3EDE98`; exact body/declarations/includes and no raw target labels. | auto-generated/NexusTK/map/ObjectList.cpp and sibling headers | incorporate | applied |
| C23D-048 | 00023D | Protect non-target structure, Gate 2B persistence, and lifecycle boundaries. Implementation detail: Agent boundaries, no split/new UID, canonical authority, durable backup, one-save boundary, protected readbacks, fresh-session persistence, and validator-owned lifecycle authority were all observed. | very strong | Gate 2B canonical/post-save proof plus validator-owned historical commands `000000022771` and `000000022775`; current lifecycle truth remains path/history authoritative. | Project state and supervisor Gate 2B boundary | not-applicable | already-present |
| C23D-049 | 00023D | Replace the stale ObjectList class manual coverage row in place. Implementation detail: Supervisor applied the exact UID00009Q Section 28 row once with no insertion/deletion. | very strong | Command `000000022766` exit 0, ok 1; exact row reread; by-class closure SHA `8289C8590BD6AA470CC4FDC056C1D0302903FC197581A3ACB2B85CF7C5E4511C`. | by-class/-coverage-report.md UID00009Q | incorporate | applied |
| C23D-050 | 00023D | Replace the stale ObjectList file manual coverage row in place. Implementation detail: Supervisor applied the exact UID0000M4 Section 28 row once with no insertion/deletion. | very strong | Command `000000022767` exit 0, ok 1; exact row reread; by-file closure SHA `DA924F99DFAA33578DEF3A5A320B7BD088682007A0560337722FAD3D54FDF387`. | by-file/-coverage-report.md UID0000M4 | incorporate | applied |
| C23D-051 | 00023D | Replace the under-detailed MapPane aggregate manual coverage row in place. Implementation detail: Supervisor applied the exact UID00037Y Section 28 row once with no insertion/deletion. | very strong | Command `000000022765` exit 0, ok 1; exact row reread; by-memory closure SHA `F4F52F9AFD0147986EDF38F26666553A7E792CE36027CFDA4F15EC56E3EC0BBD`. | by-memory/-coverage-report.md UID00037Y | incorporate | applied |
| C23D-052 | 00023D | Replace the stale StaticObjEntry manual coverage row in place. Implementation detail: Supervisor applied the exact UID0001W8 Section 28 row once with no insertion/deletion. | very strong | Command `000000022768` exit 0, ok 1; exact row reread; by-struct closure SHA `65023D2F84F1F4F7160947B95B0CF29E09B9A5F224BD477036A9EE57F7E7F937`. | by-type/by-struct/-coverage-report.md UID0001W8 | incorporate | applied |
| C23D-053 | 00023D | Replace the stale StaticObjImageLib class manual coverage row in place. Implementation detail: Supervisor applied the exact UID0000E2 Section 28 row once with no insertion/deletion. | very strong | Command `000000022766` exit 0, ok 1; exact row reread; by-class closure SHA `8289C8590BD6AA470CC4FDC056C1D0302903FC197581A3ACB2B85CF7C5E4511C`. | by-class/-coverage-report.md UID0000E2 | incorporate | applied |
| C23D-054 | 00023D | Replace the stale StaticObjImageLib file manual coverage row in place. Implementation detail: Supervisor applied the exact UID0000O7 Section 28 row once with no insertion/deletion. | very strong | Command `000000022767` exit 0, ok 1; exact row reread; by-file closure SHA `DA924F99DFAA33578DEF3A5A320B7BD088682007A0560337722FAD3D54FDF387`. | by-file/-coverage-report.md UID0000O7 | incorporate | applied |
| C23D-055 | 00023D | Replace the stale StaticObjImageLib local-cluster manual coverage row in place. Implementation detail: Supervisor applied the exact UID00017H Section 28 row once with no insertion/deletion. | very strong | Command `000000022765` exit 0, ok 1; exact row reread; by-memory closure SHA `F4F52F9AFD0147986EDF38F26666553A7E792CE36027CFDA4F15EC56E3EC0BBD`. | by-memory/-coverage-report.md UID00017H | incorporate | applied |
| C23D-056 | 00023D | Replace the under-detailed MapPane creator manual coverage row in place. Implementation detail: Supervisor applied the exact UID0003TI Section 28 row once with no insertion/deletion. | very strong | Command `000000022765` exit 0, ok 1; exact row reread; by-memory closure SHA `F4F52F9AFD0147986EDF38F26666553A7E792CE36027CFDA4F15EC56E3EC0BBD`. | by-memory/-coverage-report.md UID0003TI | incorporate | applied |
| C23D-057 | 00023D | Replace the stale LightingObjectPane class manual coverage row in place. Implementation detail: Supervisor applied the exact UID000075 Section 28 row once with no insertion/deletion. | very strong | Command `000000022766` exit 0, ok 1; exact row reread; by-class closure SHA `8289C8590BD6AA470CC4FDC056C1D0302903FC197581A3ACB2B85CF7C5E4511C`. | by-class/-coverage-report.md UID000075 | incorporate | applied |
| C23D-058 | 00023D | Replace the stale LightingObjectPane file manual coverage row in place. Implementation detail: Supervisor applied the exact UID0000KO Section 28 row once with no insertion/deletion. | very strong | Command `000000022767` exit 0, ok 1; exact row reread; by-file closure SHA `DA924F99DFAA33578DEF3A5A320B7BD088682007A0560337722FAD3D54FDF387`. | by-file/-coverage-report.md UID0000KO | incorporate | applied |
| C23D-059 | 00023D | Replace the under-detailed StaticObjectPane class manual coverage row in place. Implementation detail: Supervisor applied the exact UID0000E1 Section 28 row once with no insertion/deletion. | very strong | Command `000000022766` exit 0, ok 1; exact row reread; by-class closure SHA `8289C8590BD6AA470CC4FDC056C1D0302903FC197581A3ACB2B85CF7C5E4511C`. | by-class/-coverage-report.md UID0000E1 | incorporate | applied |
| C23D-060 | 00023D | Replace the under-detailed StaticObjectPane file manual coverage row in place. Implementation detail: Supervisor applied the exact UID0000O6 Section 28 row once with no insertion/deletion. | very strong | Command `000000022767` exit 0, ok 1; exact row reread; by-file closure SHA `DA924F99DFAA33578DEF3A5A320B7BD088682007A0560337722FAD3D54FDF387`. | by-file/-coverage-report.md UID0000O6 | incorporate | applied |
| C23D-061 | 00023D | Replace the stale MapTilePixelDimensions manual coverage row in place. Implementation detail: Supervisor applied the exact UID0000T7 Section 28 row once with no insertion/deletion. | very strong | Command `000000022769` exit 0, ok 1; exact row reread; by-global closure SHA `5913D983A1ABB08FDF9CF6BD7DEC31708390FF487932936FAA1C862E80A971A1`. | by-global/-coverage-report.md UID0000T7 | incorporate | applied |
| C23D-062 | 00023D | Replace the stale g_pStaticObjImageLib manual coverage row in place. Implementation detail: Supervisor applied the exact UID0000SD Section 28 row once with no insertion/deletion. | very strong | Command `000000022769` exit 0, ok 1; exact row reread; by-global closure SHA `5913D983A1ABB08FDF9CF6BD7DEC31708390FF487932936FAA1C862E80A971A1`. | by-global/-coverage-report.md UID0000SD | incorporate | applied |
| C23D-063 | 00023D | Replace the stale singleton-storage manual coverage row in place. Implementation detail: Supervisor applied the exact UID0001PP Section 28 row once with no insertion/deletion. | very strong | Command `000000022765` exit 0, ok 1; exact row reread; by-memory closure SHA `F4F52F9AFD0147986EDF38F26666553A7E792CE36027CFDA4F15EC56E3EC0BBD`. | by-memory/-coverage-report.md UID0001PP | incorporate | applied |

## Positive Evidence Summary

- The exact target is an IDA-modeled `0x1d9` function with 26 blocks and cyclomatic complexity 11; it is bounded by discrete CC padding and the following ObjectList constructor.
- Every meaningful access resolves against current class/type contracts: `m_gridHeight`, `m_staticObjectRows`, `m_lightingObjects`, `StaticObjectPane::m_staticObjectId`, `ObjectPane::GetAttachedObject`, `LightingObjectPane::SetLightImageIndex`, and the exact constructor tail.
- The positive and negative metadata branches are complete and mutually coherent. The same signed value selects remove, update, or create behavior.
- Independent MapPane creation code passes the same entry field to the explicitly named `lightImageIndex` parameter, resolving the historical intensity/index ambiguity.
- The raw wrapper accesses `MapPane + 0x424`, null-checks the ObjectList, preserves the unsigned-short stack argument, and tail-jumps to the target.
- `g_pStaticObjImageLib` is a live zero-initialized singleton slot with 13 current xrefs, including this target and the MapPane static-object creator.

## IDA MCP Facts

| Entity | Current fact |
| --- | --- |
| Target function | `ObjectList_RefreshStaticObjectLighting`, `0x00530d00`, size `0x1d9`, persisted type `int __thiscall(ObjectList *, unsigned __int16)` |
| Target boundaries | `0x00530cf7-0x00530d00` is 9-byte data padding; final instruction `0x00530ed6-0x00530ed9`; `0x00530ed9-0x00530ee0` is 7-byte data padding |
| Following function | `ObjectList__Constructor` starts exactly at `0x00530ee0` |
| Wrapper bytes | `0x0050e300-0x0050e317`: frame setup, load `[ecx+0x424]`, null test, tail jump at `0x0050e30e`, null return; CC padding begins `0x0050e317` |
| Target xrefs | Exactly one direct code xref at `0x0050e30e`; caller function metadata is absent |
| Wrapper xrefs | Zero incoming xrefs at `0x0050e300`; bounded VA/RVA pointer-pattern searches returned zero |
| Entry accessor | `StaticObjImageLib_GetStaticObjectEntry`, size `0x27`; id must be nonzero and less than count, then returns table slot `id - 1` |
| Attached getter | `ObjectPane_GetAttachedObject`, size `0x7`; returns `this[70]`, exact offset `+0x118` |
| Lighting constructor | `LightingObjectPane_Constructor`, size `0x60`; creates object type 10, stores index/offsets/anchor, installs three vtable views |
| Setter | `LightingObjectPane_SetLightImageIndex`, size `0x35`; current type/comment already source-quality |
| ObjectList add | `ObjectList_AddObjectPane`, size `0x73c`, 18 direct callers including target at `0x00530e8f` |
| Singleton | `0x0069b448` current one-byte non-code/non-data head named `unk_69B448`; four physical bytes are zero; 13 xrefs |
| Tile globals | `g_mapTilePixelWidth` and `g_mapTilePixelHeight` are signed 16-bit data at `0x0066da9c`/`0x0066daa0`, 89/94 xrefs |
| Persisted function comments | Function-regular comments are exact at the target, entry accessor, attached getter, and lighting constructor; `ObjectPane_GetMapPosition` has exactly `Copy this ObjectPane map position as row followed by column.` Other channels remain blank except the retained narrow target address comments. |
| Persisted target frame | Ten rows are renamed to `staticObjectId`, `extendedRowCount`, `staticObjectRow`, `staticObjectCount`, `lightingObjectStorage`, `mapPosition`, `rowIndex`, `staticObjEntry`, `objectIndex`, and `objectList`; all 17 offsets, widths, types, order, and protected names remain exact. |
| Persisted tile comments | Address-regular comments at `0x0066da9c`/`0x0066daa0` now describe the signed map-tile pixel width/height shared by layout, coordinate conversion, rendering, centering, and object-light placement; repeatable channels remain blank. |

Historical pre-Gate2B prestates are preserved in Section 21: the four functions formerly carried `sub_530D00`, `sub_4DDA30`, `sub_5376C0`, and `sub_53C5E0`; the ten target frame rows used their compiler-generated names; the four function-regular channels, map-position replacement channel, and two replacement tile-global comment channels had the exact old values recorded there. Those are dated handoff facts, not current IDA state.

## Function / Child Inventory

| Address/range | Proposed source entity | Target relationship | Disposition |
| --- | --- | --- | --- |
| `0x0050e300-0x0050e317` | `MapPane::RefreshStaticObjectLighting` | Sole tail-jump wrapper caller | MapPane-owned retained route-negative method; not target owner |
| `0x00530d00-0x00530ed9` | `ObjectList::RefreshStaticObjectLighting` | Assigned target | Exact source-bearing method; formal CPP here |
| `0x004dda30-0x004dda57` | `StaticObjImageLib::GetStaticObjectEntry` | Metadata lookup | Existing class method in StaticObjImageLib source family |
| `0x005376c0-0x005376c7` | `ObjectPane::GetAttachedObject` | Attached-light lookup | Existing ObjectPane accessor |
| `0x0053c5e0-0x0053c640` | `LightingObjectPane::LightingObjectPane` | Missing-light creation | Existing LightingObjectPane lifecycle child |
| `0x0053c980-0x0053c9b5` | `LightingObjectPane::SetLightImageIndex` | Existing-light update | Existing exact child; no source change beyond consumers |
| `0x005314a0` | `ObjectList::AddObjectPane` | Registers newly created light | Existing exact ObjectList method |
| `0x005374d0` | `ObjectPane::GetMapPosition` | Supplies row/column | Existing exact ObjectPane accessor |
| `0x0069b448-0x0069b44c` | `g_pStaticObjImageLib` storage | Lookup receiver | Existing singleton definition/storage route; explicit I23D-06 no-mutation disposition: do not materialize, rename, type, or comment the current one-byte head, and preserve the four-byte storage interval, bytes, xrefs, neighbors, and formal source route unchanged |

No target-internal split is justified. Compiler EH/cookie scaffolding and ordinary-new lowering stay covered by the human method body rather than separate children.

## Direct Xref / Caller Inventory

- `0x00530d00` has exactly one incoming code reference, the `jmp` at `0x0050e30e`.
- The wrapper start `0x0050e300` has no code/data xrefs and no current function object. Searches for wrapper VA `00 E3 50 00`, wrapper RVA `00 E3 10 00`, target VA `00 0D 53 00`, and target RVA `00 0D 13 00` produced no pointer-table hits beyond the direct branch relationship.
- `0x004dda30` has two callers: MapPane static-object creation at `0x0050f0be` and the target at `0x00530d36`.
- `0x005376c0` has one caller, the target at `0x00530da9`.
- `0x0053c5e0` has two callers: `MapPane_AttachObjectLighting` at `0x0050a9a5` and the target at `0x00530e79`.
- `0x0053c980` has two callers: the target at `0x00530dbe` and the effect-object update path at `0x00538a90`.
- `g_pStaticObjImageLib` has 13 current xrefs spanning construction/destruction/cleanup, MapPane static-object creation, this target, StaticObjectPane methods, and PhotoPane construction.

## Documentation Evidence And IDA Status

- Current ObjectPane documentation proves `InvalidateRect`, `AttachObject`, `DetachObject`, `GetMapPosition`, and `GetAttachedObject` source surfaces and offsets.
- Current LightingObjectPane documentation rejects intensity, proves `m_lightImageIndex`, local offsets, borrowed anchor, constructor/destructor/setter behavior, and owns the complete guarded H declaration used by ObjectList.
- Current StaticObjectPane documentation proves the exact `0x12c` layout, inline unsigned-short `GetStaticObjectId()`, guarded H declaration, and ObjectList consumer route.
- Current StaticObjImageLib class/file/type/local-cluster documentation uses `lightImageIndex`, exposes `GetStaticObjectEntry` and the singleton through H, and preserves later valid Singleton/EBO/packing/lifecycle work. `lightIntensity` remains only in explicitly rejected or superseded historical text.
- Current MapPane static-object creator has a complete formal body whose two active field tokens are `entry->lightImageIndex`; its former `lightIntensity` tokens are documented only as corrected history.
- The target, ObjectList class/file, support headers, tile-global external linkage, singleton consumer prose, and source-facing historical corrections were implemented and scoped-validated. No ordinary documentation defect from the accepted callback remains pending.
- Supervisor-owned IDA work C23D-035..C23D-042 is complete under the persisted Gate 2B receipt at `2026-08-12T11:52:00-04:00`: the four bounded function renames/comments, ten occupied-row stack renames, map-position and tile-global comment repairs, explicit wrapper/singleton-storage no-change dispositions, complete protected readbacks, one save, and distinct-session persistence verification all passed. B003 performed no IDA mutation and receives no supervisor action credit.

## Ranked Ownership Analysis

1. **ObjectList / UID00009Q: accepted.** The target reads only ObjectList grid/list fields, iterates ObjectList-owned rows and light list, and calls ObjectList registration. This is direct class-method ownership.
2. **MapPane wrapper: caller only.** `0x0050e300` owns the MapPane null-check and object-list field access, then delegates the operation. It does not own the loop body or target source.
3. **LightingObjectPane: payload class only.** It owns construction, rebinding, and destruction behavior, not the list-wide synchronization loop.
4. **StaticObjImageLib: metadata provider only.** It owns the table and accessor, not ObjectList traversal.
5. **StaticObjectPane: matched anchor type only.** It owns the id and attachment APIs, not the synchronization method.

Rejected placements include MapPane.cpp for the target body, LightingObjectPane.cpp, StaticObjImageLib.cpp, StaticObjectPane.cpp, a generic lighting manager, or a standalone helper file.

## Source Placement

- Target body: `NexusTK/map/ObjectList.cpp` through [UID:00009Q] -> [UID:0000M4].
- Target declaration: `NexusTK/map/ObjectList.h` on [UID:00009Q].
- Wrapper body: `NexusTK/map/MapPane.cpp`; the broad UID00037Y page remains its current physical aggregate until a dedicated child is created by a separate split decision.
- `LightingObjectPane`, `StaticObjectPane`, and `StaticObjImageLib` complete declarations belong in their own `.h` files. Their former pre-callback CPP-only placement is not a defensible cross-file visibility route.
- Shared tile globals remain MapPane-owned but require external definitions and declarations visible through the MapPane header route.

## Range / Split / Padding / Reclassification Analysis

- Target start is exact: the prior function returns at `0x00530cf4-0x00530cf7`, followed by nine CC bytes through `0x00530cff`.
- Target end is exact: `retn 4` occupies `0x00530ed6-0x00530ed9`; seven CC bytes occupy `0x00530ed9-0x00530ee0`; ObjectList constructor starts at `0x00530ee0`.
- The target is one function, not a mixed aggregate. Internal branches share one frame, one argument, common row/object loops, and one metadata record.
- Wrapper exact half-open body is `0x0050e300-0x0050e317`, not stale `...e316`; its final `retn 4` head is `0x0050e314` and ends at `0x0050e317`.
- No new target split, merge, range extension, padding child, or UID is required. The wrapper remains support scope under UID00037Y unless the supervisor separately authorizes a child split.

## Negative Evidence Summary

- No direct route reaches wrapper start `0x0050e300` in the current PE, and no bounded address-pattern search found a stored wrapper/target pointer. Do not claim live invocation from current static evidence.
- No original symbols prove exact private names. Final source still must use plausible human names rather than raw IDA labels.
- No evidence supports a semantic `int` return from the target.
- No evidence supports `lightIntensity`, direct light-index field writes, generic light interfaces, or a separate lighting-manager owner.
- No evidence supports a metadata null check in the target. Adding one would alter original behavior.
- No evidence supports combining wrapper and target into one source method or assigning the target to MapPane.
- No evidence supports hand-emitting EH records, vptr stores, scalar-delete flags, allocation-null lowering, or CC padding.

## IDA Rename / Type / Comment Recommendations

| Record | Declarative evidence / disposition |
| --- | --- |
| Archive | Exact removed request objects, runtime/backup/save/reopen/rollback sequencing, and operational envelopes are preserved only in [00023D-ObjectListStaticObjectLightingSyncHelper-source-quality-removed.md](./00023D-ObjectListStaticObjectLightingSyncHelper-source-quality-removed.md); that companion is non-authoritative and must never be executed. |
| Persisted receipt | public authority bound canonical session `supervisor-uid00048A-persist-20260812` to `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; durable prechange backup `NexusTK.exe.uid00023D-prechange-20260812T154050Z-1B8E6E1B96FD.i64` was 143,206,508 bytes with SHA256 `1B8E6E1B96FD984BCF06236B3500CB11C132B2F89F9866CE808EBF5437D60D78`. All four function and ten stack dry runs passed without collision, every listed mutation/no-change protection passed, exactly one save succeeded, and the canonical post-save IDB became 143,206,680 bytes with SHA256 `A95C3CF171A95F77AF9BBFF9247E81C53E7816059D203320E83E7B369ACD36F1`. Distinct session `supervisor-uid00023D-postsave-20260812T154552Z` reproduced every accepted/protected result from a byte-identical post-save copy. |

| ID | Entity/address | Literal dated pre-Gate2B pre-state | Dated accepted current-schema action or no-change disposition | Evidence and safety constraints | Persisted supervisor result / protected readback |
| --- | --- | --- | --- | --- | --- |
| I23D-01 | Function `0x00530d00` | Name `sub_530D00`; range `0x00530d00-0x00530ed9`; type `int __thiscall(ObjectList *this, unsigned __int16)`; all four comment channels absent | Rename function to `ObjectList_RefreshStaticObjectLighting`; set the function-regular comment to `Refresh lighting attachments for every StaticObjectPane with the supplied static-object id: invalidate it, remove a now-disabled light, update an existing light image index, or create/register/attach a new LightingObjectPane from StaticObjEntry metadata.` | Require exact range/padding, current name/type/comments, and no destination-name collision. Type and frame are protected; source-facing `void` remains documentation/formal C++ rather than an IDA type mutation in this handoff. | `lookup_funcs`, `inspect_items`, `get_comments`, and `stack_frame` on `0x00530d00` return exact new name and function-regular comment; original type, range, bytes, xrefs, frame offsets/types/widths, address comments, and function-repeatable comment remain unchanged |
| I23D-02 | Raw code `0x0050e300-0x0050e317` | No function object, name, or type; all address comment channels absent; zero xrefs to start; exact 23-byte body between a 12-byte leading CC run and following CC padding | No change: retain the raw wrapper without a function object, name, type, or comments; preserve its source wrapper only in ordinary documentation/formal support text. | Current route is negative and current public function-definition semantics were not independently proven for this raw aggregate member. A speculative function model is not required for source reconstruction. | `inspect_items`, `get_bytes`, `xrefs_to`, and `get_comments` reproduce the same raw code/padding, no function/name/type, zero start xrefs, and absent comments |
| I23D-03 | Function `0x004dda30` | Name `sub_4DDA30`; range size `0x27`; type `int __thiscall(_DWORD *this, unsigned __int16)`; all four comment channels absent; complete current frame: `__saved_registers` at `0x0`, size `0x4`, type `_DWORD`; `__return_address` at `0x4`, size `0x4`, type `_UNKNOWN *`; `arg_0` at `0x8`, size `0x2`, type `_WORD` | Rename function to `StaticObjImageLib_GetStaticObjectEntry`; set the function-regular comment to `Return the one-based StaticObjEntry for a valid nonzero static-object id, or NULL when the id is zero or outside the loaded table.` | Require exact current name/type/comments, two callers, complete three-row frame, and no destination collision. Preserve type and every frame row. | Exact new name/comment; current type, range, bytes, two callers, address comments, function-repeatable comment, and literal three-row frame remain unchanged |
| I23D-04 | Function `0x005376c0` | Name `sub_5376C0`; range size `0x7`; type `int __thiscall(_DWORD *this)`; all four comment channels absent; complete current frame: `__return_address` at `0x0`, size `0x4`, type `_UNKNOWN *` | Rename function to `ObjectPane_GetAttachedObject`; set the function-regular comment to `Return this pane's borrowed attached ObjectPane pointer.` | Require exact `this+0x118` body, sole target caller, current comments/type, complete one-row frame, and no destination collision. Preserve type and frame. | Exact new name/comment; current type, range, bytes, caller, address comments, function-repeatable comment, and literal one-row frame remain unchanged |
| I23D-05 | Function `0x0053c5e0` | Name `sub_53C5E0`; range size `0x60`; type `ObjectPane *__thiscall(ObjectPane *this, int, int mapY, int mapX, int, int, int)`; all four comment channels absent; complete current frame: `var_4` at `0x4`, size `0x4`, type `_DWORD`; `__saved_registers` at `0x8`, size `0x4`, type `_DWORD`; `__return_address` at `0xc`, size `0x4`, type `_UNKNOWN *`; `arg_0` at `0x10`, size `0x4`, type `_DWORD`; `mapY` at `0x14`, size `0x4`, type `int`; `mapX` at `0x18`, size `0x4`, type `int`; `arg_C` at `0x1c`, size `0x4`, type `_DWORD`; `arg_10` at `0x20`, size `0x4`, type `_DWORD`; `arg_14` at `0x24`, size `0x4`, type `_DWORD` | Rename function to `LightingObjectPane_Constructor`; set the function-regular comment to `Construct a LightingObjectPane anchored to the source pane at map row/column with local X/Y offsets and a signed light image index.` | Require two creator callers, allocation size `0x138`, exact tail stores, three vtable writes, current comments/type, complete nine-row frame, and no destination collision. Preserve type and every frame row. | Exact new name/comment; current type, range, bytes, callers, address comments, function-repeatable comment, and literal nine-row frame remain unchanged |
| I23D-06 | Physical slot `0x0069b448-0x0069b44c` | Current item head/end `0x0069b448-0x0069b449`; name `unk_69B448`; type absent; neither code nor data; four bytes `00 00 00 00`; 13 xrefs; comments absent | No change: retain the one-byte non-code/non-data head `unk_69B448`, absent type/comments, four zero bytes, and 13-xref physical interval; preserve the source definition/storage split in ordinary documentation. | A safe materialization sequence and complete consumed-neighbor contract were not proven. The protected source-storage interval is exactly `[0x0069b448,0x0069b44c)`; predecessor storage ends at `0x0069b448` and successor storage starts at `0x0069b44c`. The source global already has a formal owner, so speculative IDA reshaping is unnecessary. | Narrow no-change readback only: `inspect_items`, `get_bytes`, `xrefs_to`, and `get_comments` reproduce the same one-byte head, name/type/kind, four zero bytes, total xref count `13`, and absent comments. No claim is made here about individual xref identities or unmaterialized interior/neighbor item heads. |
| I23D-07A | Target stack offset `0x58` | `arg_0`, size `0x4`, type `_DWORD` | Rename occupied frame row `arg_0` to `staticObjectId` only. | Occupied argument row only; do not redeclare/retype it | Final name `staticObjectId`; offset `0x58`, width `0x4`, type `_DWORD`, and every other frame row unchanged |
| I23D-07B | Target stack offset `0x18` | `var_38`, size `0x4`, type `_DWORD` | Rename occupied frame row `var_38` to `extendedRowCount` only. | Stable loop-bound slot | Name only changes; offset/width/type unchanged |
| I23D-07C | Target stack offset `0x1c` | `var_34`, size `0x4`, type `_DWORD` | Rename occupied frame row `var_34` to `staticObjectRow` only. | Stable cached row-list slot | Name only changes; offset/width/type unchanged |
| I23D-07D | Target stack offset `0x20` | `var_30`, size `0x4`, type `_DWORD` | Rename occupied frame row `var_30` to `staticObjectCount` only. | Stable cached count slot | Name only changes; offset/width/type unchanged |
| I23D-07E | Target stack offset `0x24` | `Block`, size `0x4`, type `void *` | Rename occupied frame row `Block` to `lightingObjectStorage` only. | Exact allocation temporary | Name only changes; offset/width/type unchanged |
| I23D-07F | Target stack offset `0x28` | `var_28`, size `0x4`, type `_DWORD` | Rename occupied frame row `var_28` to `mapPosition` only. | Pointer to separate `position` row | Name only changes; offset/width/type unchanged |
| I23D-07G | Target stack offset `0x2c` | `var_24`, size `0x4`, type `_DWORD` | Rename occupied frame row `var_24` to `rowIndex` only. | Stable outer-loop index | Name only changes; offset/width/type unchanged |
| I23D-07H | Target stack offset `0x30` | `var_20`, size `0x4`, type `_DWORD` | Rename occupied frame row `var_20` to `staticObjEntry` only. | Stable metadata pointer | Name only changes; offset/width/type unchanged |
| I23D-07I | Target stack offset `0x34` | `var_1C`, size `0x4`, type `_DWORD` | Rename occupied frame row `var_1C` to `objectIndex` only. | Stable inner-loop index | Name only changes; offset/width/type unchanged |
| I23D-07J | Target stack offset `0x40` | `var_10`, size `0x4`, type `ObjectList *` | Rename occupied frame row `var_10` to `objectList` only. | Stable saved receiver | Name only changes; offset/width/type unchanged |
| I23D-08A | Function comment `0x005374d0` | Name `ObjectPane_GetMapPosition`; type `MapPoint *__thiscall(ObjectPane *this, MapPoint *position)`; address regular/repeatable absent; function regular exact text `Copy this effect pane map position as row followed by column.\nInherited ObjectPane accessor that copies the stored map position as row followed by column.`; function repeatable absent | Replace only the function-regular comment with `Copy this ObjectPane map position as row followed by column.` | Change only the function-regular channel; exact two-line prestate must match before replacement | Exact one-line function-regular text; name/type/xrefs and the other three comment channels unchanged |
| I23D-08B | Data comment `0x0066da9c` | Name `g_mapTilePixelWidth`; type `signed __int16`; width 2; value 48; 89 xrefs; regular comment `Signed source map-tile pixel width used for item-glyph centering.`; repeatable absent | Replace only the address-regular comment with `Signed map-tile pixel width shared by map layout, coordinate conversion, rendering, centering, and object-light placement.` | Change only address-regular channel; no rename/retype | Exact new regular comment; name/type/width/value/xrefs and repeatable channel unchanged |
| I23D-08C | Data comment `0x0066daa0` | Name `g_mapTilePixelHeight`; type `signed __int16`; width 2; value 48; 94 xrefs; regular comment `Signed source map-tile pixel height used for item-glyph centering.`; repeatable absent | Replace only the address-regular comment with `Signed map-tile pixel height shared by map layout, coordinate conversion, rendering, centering, and object-light placement.` | Change only address-regular channel; no rename/retype | Exact new regular comment; name/type/width/value/xrefs and repeatable channel unchanged |

| Offset | Dated pre-Gate2B name | Persisted name | Size | Type | Disposition |
| --- | --- | --- | ---: | --- | --- |
| `0x10` | `position` | `position` | `0x8` | `MapPoint` | protected |
| `0x18` | `var_38` | `extendedRowCount` | `0x4` | `_DWORD` | rename only |
| `0x1c` | `var_34` | `staticObjectRow` | `0x4` | `_DWORD` | rename only |
| `0x20` | `var_30` | `staticObjectCount` | `0x4` | `_DWORD` | rename only |
| `0x24` | `Block` | `lightingObjectStorage` | `0x4` | `void *` | rename only |
| `0x28` | `var_28` | `mapPosition` | `0x4` | `_DWORD` | rename only |
| `0x2c` | `var_24` | `rowIndex` | `0x4` | `_DWORD` | rename only |
| `0x30` | `var_20` | `staticObjEntry` | `0x4` | `_DWORD` | rename only |
| `0x34` | `var_1C` | `objectIndex` | `0x4` | `_DWORD` | rename only |
| `0x38` | `var_18` | `var_18` | `0x4` | `ObjectPane *` | protected multi-role slot |
| `0x3c` | `var_14` | `var_14` | `0x4` | `_DWORD` | protected multi-role slot |
| `0x40` | `var_10` | `objectList` | `0x4` | `ObjectList *` | rename only |
| `0x44` | `var_C` | `var_C` | `0x4` | `_DWORD` | protected compiler/multi-role slot |
| `0x4c` | `var_4` | `var_4` | `0x4` | `_DWORD` | protected compiler slot |
| `0x54` | `__return_address` | `__return_address` | `0x4` | `_UNKNOWN *` | protected |
| `0x58` | `arg_0` | `staticObjectId` | `0x4` | `_DWORD` | rename only; source type remains documented separately |
| `0x5c` | `arg_4` | `arg_4` | `0x4` | `_DWORD` | protected frame artifact; no source argument inferred |

| ID | Dated pre-Gate2B model | Persisted IDA model | Reason |
| --- | --- | --- | --- |
| I23D-01 | `int __thiscall(ObjectList *this, unsigned __int16)` | unchanged type/frame; name/comment only | Avoid prototype-to-frame projection while formal C++ carries the source ABI |
| I23D-02 | no function/name/type at raw wrapper | unchanged raw model | Definition semantics and route are not strong enough for mutation |
| I23D-03 | `int __thiscall(_DWORD *this, unsigned __int16)` | unchanged type/frame; name/comment only | Source return/receiver types remain formal documentation, not a Gate 2B frame mutation |
| I23D-04 | `int __thiscall(_DWORD *this)` | unchanged type/frame; name/comment only | Same conservative boundary |
| I23D-05 | `ObjectPane *__thiscall(ObjectPane *this, int, int mapY, int mapX, int, int, int)` | unchanged type/frame; name/comment only | Same conservative boundary |
| I23D-06 | one-byte non-code/non-data head `unk_69B448`, no type | unchanged physical model | No destructive materialization without a proven neighbor contract |

| Entity/address | Exact persisted state preserved | Reason |
| --- | --- | --- |
| `0x005314a0` | `ObjectList_AddObjectPane`, type `void __thiscall(ObjectList *this, ObjectPane *objectPane)`, regular function comment `ObjectList::AddObjectPane source-facing insertion used by MapPane::m_objectList.`, repeatable absent | Already source-quality; target is only a caller |
| `0x005374d0` name/type | `ObjectPane_GetMapPosition`, type `MapPoint *__thiscall(ObjectPane *this, MapPoint *position)` | Only I23D-08A comment replacement is authorized |
| `0x0053c980` | `LightingObjectPane_SetLightImageIndex`, type `void __thiscall(struct LightingObjectPane *this, int lightImageIndex)`, exact current source-quality regular function comment, repeatable absent | Already source-quality and independently validated |
| `0x0066da9c`/`0x0066daa0` names/types/widths | Existing `g_mapTilePixelWidth`/`g_mapTilePixelHeight`, signed 16-bit, two-byte data items, values 48 | Only I23D-08B/I23D-08C comments are authorized |
| Target and wrapper boundaries/padding | Target `0x00530d00-0x00530ed9`; wrapper `0x0050e300-0x0050e317`; all adjacent CC bytes as recorded | No undefine, patch, merge, boundary extension, or padding conversion is authorized |

## First-Draft C++ Recommendation

The following are exact formal CPP/H payloads for the accepted callback, not explanatory pseudocode.

Target-specific behavior preservation: the target body retains the original extended-row traversal, unsigned static-object-id filter, invalidation-before-lighting order, signed negative image-index sentinel, exact list removal followed by detach/delete, existing-light image-index update, and missing-light construction/register/attach sequence. It deliberately does not add a metadata null check, semantic return value, exception path, ownership transfer, or other branch absent from the binary evidence.

Plausible mid-2000s source shape: the reconstruction uses ordinary member methods, typed pane/image-library objects, explicit nested loops, local cached counts/pointers, and direct `new`/`delete` and list operations consistent with this client family's contemporary C++ style. It does not expose raw offsets, IDA labels, manual vtable dispatch, compiler EH records, scalar-delete flags, or decompiler temporaries in final source.

Naming and style rationale: `RefreshStaticObjectLighting`, `staticObjectId`, `StaticObjEntry`, `lightHeightClass`, `lightImageIndex`, and `LightingObjectPane` follow the strongest established ObjectList/ObjectPane/StaticObjImageLib vocabulary and distinguish image selection from intensity. Where original symbols are unavailable, these are the most contextually realistic human source names; behavioral fidelity and human-written source shape take priority, with project-wide naming consistency applied unless stronger direct evidence requires an exception.

Third-party import disposition: not applicable. UID00023D and every formal support declaration here are project-owned NexusTK map/render classes and globals, not source from `third_party_embeds/...`; no third-party import directive or blank-code import channel is appropriate.

Target [UID:00023D] CPP; target H remains blank:

```cpp
void ObjectList::RefreshStaticObjectLighting(unsigned short staticObjectId)
{
    StaticObjEntry *staticObjEntry =
        g_pStaticObjImageLib->GetStaticObjectEntry(staticObjectId);
    const short extendedRowCount =
        static_cast<short>(m_gridHeight + 12);

    for (int rowIndex = 0; rowIndex < extendedRowCount; ++rowIndex)
    {
        List *staticObjectRow = m_staticObjectRows[rowIndex];
        const int staticObjectCount = staticObjectRow->GetCount();

        for (int objectIndex = 0;
             objectIndex < staticObjectCount;
             ++objectIndex)
        {
            StaticObjectPane *staticObjectPane =
                *static_cast<StaticObjectPane **>(
                    staticObjectRow->GetElementAt(objectIndex));

            if (staticObjectPane->GetStaticObjectId() != staticObjectId)
                continue;

            staticObjectPane->InvalidateRect(NULL);
            LightingObjectPane *lightingObjectPane =
                static_cast<LightingObjectPane *>(
                    staticObjectPane->GetAttachedObject());

            if (lightingObjectPane != NULL)
            {
                if (staticObjEntry->lightImageIndex < 0)
                {
                    const int lightingObjectCount =
                        m_lightingObjects->GetCount();
                    for (int lightIndex = 0;
                         lightIndex < lightingObjectCount;
                         ++lightIndex)
                    {
                        LightingObjectPane *candidate =
                            *static_cast<LightingObjectPane **>(
                                m_lightingObjects->GetElementAt(lightIndex));
                        if (candidate == lightingObjectPane)
                        {
                            m_lightingObjects->RemoveAt(lightIndex, 1);
                            break;
                        }
                    }

                    staticObjectPane->DetachObject();
                    delete lightingObjectPane;
                }
                else
                {
                    lightingObjectPane->SetLightImageIndex(
                        staticObjEntry->lightImageIndex);
                }
            }
            else if (staticObjEntry->lightImageIndex >= 0)
            {
                MapPoint position;
                staticObjectPane->GetMapPosition(&position);

                lightingObjectPane = new LightingObjectPane(
                    staticObjectPane,
                    position.row,
                    position.column,
                    g_mapTilePixelWidth,
                    g_mapTilePixelHeight / 2 -
                        g_mapTilePixelHeight *
                            staticObjEntry->lightHeightClass,
                    staticObjEntry->lightImageIndex);

                AddObjectPane(lightingObjectPane);
                staticObjectPane->AttachObject(lightingObjectPane);
            }
        }
    }
}
```

[UID:00009Q] ObjectList CPP replacement and H insertion:

```cpp
#include "ObjectList.h"
#include "LightingObjectPane.h"
#include "MapPane.h"
#include "ObjectPane.h"
#include "StaticObjectPane.h"
#include "../render/StaticObjImageLib.h"
#include "../util/List.h"

[[CHILDREN]]
```

```cpp
    void RefreshStaticObjectLighting(unsigned short staticObjectId);
```

[UID:000075] LightingObjectPane CPP/H replacement:

```cpp
#include "LightingObjectPane.h"

[[CHILDREN]]
```

```cpp
#ifndef NEXUSTK_MAP_LIGHTINGOBJECTPANE_H
#define NEXUSTK_MAP_LIGHTINGOBJECTPANE_H

#include "ObjectPane.h"

class LightingObjectPane : public ObjectPane
{
public:
    LightingObjectPane(
        ObjectPane *anchorSource,
        int mapY,
        int mapX,
        int localOffsetX,
        int localOffsetY,
        int lightImageIndex);
    virtual ~LightingObjectPane();

    void SetLightImageIndex(int lightImageIndex);

private:
    int m_lightImageIndex;
    int m_localOffsetY;
    int m_localOffsetX;
    ObjectPane *m_anchorSource;
};

#endif
```

[UID:0000E1] StaticObjectPane CPP/H replacement:

```cpp
#include "StaticObjectPane.h"

[[CHILDREN]]
```

```cpp
#ifndef NEXUSTK_MAP_STATICOBJECTPANE_H
#define NEXUSTK_MAP_STATICOBJECTPANE_H

#include "ObjectPane.h"

class PaneEvent;
struct Rect;
struct StaticObjectDrawRequest;

class StaticObjectPane : public ObjectPane
{
public:
    StaticObjectPane(int tileX, int tileY, unsigned short staticObjectId);
    virtual ~StaticObjectPane() {}

    bool HitTestStaticObjectPixel(int localX, int localY) const;
    virtual Rect *CopyStaticObjectBounds(Rect *scratch, Rect *out) const;
    virtual bool RenderStaticObjectForTarget(
        int renderMode,
        StaticObjectDrawRequest *request);
    virtual bool HandleStaticObjectEvent(const PaneEvent *event);

    unsigned short GetStaticObjectId() const
    {
        return m_staticObjectId;
    }

private:
    void SendInteractionPacket();
    unsigned short m_staticObjectId;
};

typedef char StaticObjectPaneSizeMustBe0x12c[
    sizeof(StaticObjectPane) == 0x12c ? 1 : -1];

#endif
```

[UID:0000E2] StaticObjImageLib complete current no-loss CPP/H replacement. This supersedes the report's former partial replacement block: it preserves the owning-header include, `ImageFrameTable`/`MemoryMan`/CRT dependencies, `Singleton<StaticObjImageLib>` EBO base, two-byte `StaticObjEntry` packing, lifecycle declarations, current method surface, private layout, and singleton extern while retaining the UID00023D `lightImageIndex`/accessor contract:

```cpp
#include "StaticObjImageLib.h"
#include "ImageFrameTable.h"
#include "../util/MemoryMan.h"
#include <stdlib.h>

[[CHILDREN]]
```

```cpp
#ifndef NEXUSTK_RENDER_STATICOBJIMAGELIB_H
#define NEXUSTK_RENDER_STATICOBJIMAGELIB_H

#include "../util/LObject.h"
#include "../util/Singleton.h"

struct ArchiveMetadataTable;
struct Rect;
struct GrafPort;
struct StaticObjectDrawRequest;

struct TileClassEntry
{
    unsigned short tileFrameId;
    unsigned char allowPaletteFilter;
    unsigned char reserved;
};

#pragma pack(push, 2)
struct StaticObjEntry
{
    int lightImageIndex;
    unsigned char lightHeightClass;
    unsigned char layerCount;
    unsigned short reserved;
    StaticObjEntry *cacheChain;
    unsigned short tileIds[1];
};
#pragma pack(pop)

class StaticObjImageLib : public LObject,
                          public Singleton<StaticObjImageLib>
{
public:
    StaticObjImageLib();
    virtual ~StaticObjImageLib();

    char RenderStaticObject(GrafPort *target,
                            StaticObjectDrawRequest *request,
                            unsigned short staticObjectId,
                            void *overlayBuffer,
                            float overlayAlpha,
                            bool enableBlendClip);
    void GetStaticObjectBounds(unsigned short staticObjectId, Rect *outBounds) const;
    bool HitTestStaticObjectPixel(unsigned short staticObjectId,
                                  int localX,
                                  int localY) const;
    StaticObjEntry *GetStaticObjectEntry(unsigned short staticObjectId) const;

private:
    ArchiveMetadataTable *tileCatalog;
    TileClassEntry *tileClasses;
    StaticObjEntry **staticObjEntries;
    int staticObjCount;
};

extern StaticObjImageLib *g_pStaticObjImageLib;

#endif
```

[UID:0000T7] MapTilePixelDimensions CPP/H replacement:

```cpp
short g_mapTilePixelWidth = 48;
short g_mapTilePixelHeight = 48;
```

```cpp
extern short g_mapTilePixelWidth;
extern short g_mapTilePixelHeight;
```

[UID:0003TI] exact formal identifier substitution: replace both occurrences of `entry->lightIntensity` with `entry->lightImageIndex`; no control-flow or formatting change is authorized.

## Final Recommendation

The accepted ordinary documentation callback, narrow owning-header remediation, independent Gate 2A verification, supervisor Gate 2B persistence, 16 manual-coverage replacements, and coherent generated refresh/readback are complete at their recorded artifact identities. The target is source-ready, belongs to ObjectList, has the complete formal body, and no longer has a legitimate behavior, source-placement, formal CPP/H, support-header, IDA, manual-coverage, or generated-route blocker. Its physical documentation state is `94/93` with owner `00009Q`, reconstructable true, emitter `00009Q`, literal blank position, `Nested:0`, nonblank CPP, and blank H under the class-owned declaration. Route-negative caller evidence remains a confidence caveat, not a reason to leave the emitter empty. Section 21 preserves the dated IDA handoff and records the externally credited persisted closure; B003 performed no IDA action. Exact-artifact gate truth is determined by the external supervisor audit ledger, while execution/archive truth is determined only by current path and validator-owned history.

## Recommended Target Doc Changes

- The completed ordinary callback changed the dated target baseline from `COMPLETION:85`, `CONFIDENCE:90`, `CANONICAL_OWNER:00009Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009Q`, blank `EMITTER_POSITION_OPTIONAL:`, `Nested:0`, blank CPP, and blank H to the current physical `COMPLETION:94`, `CONFIDENCE:93`, the same owner/reconstructable/emitter/blank position/`Nested:0`, nonblank CPP, and blank H.
- The exact target CPP body from Section 22 is already present. Target H remains blank because [UID:00009Q] owns the nonblank class declaration.
- Status/Behavior/Callers/Callees/Ownership/Source Placement/Source Quality/Score/Changes already contain the direct facts from Sections 12-20.
- The former slot `+0x20` detach/disable interpretation, intensity wording, provisional-name caveat, and blank-C++ rationale are explicitly corrected in current prose.
- Those former interpretations are retained as historical corrections with the reasons they were superseded.
- Direct helper, stack, range, padding, xref, no-route, and no-null-check evidence is already incorporated alongside the formal body; this section records the applied current state rather than requesting another target edit.

## Recommended Support Doc Changes

The table preserves the exact dated accepted pre-callback state and the current physical post-callback state for every touched support page; no broad "unchanged" shorthand substitutes for the physical fields:

| Support page | Dated accepted pre-callback metadata/formal state | Current physical post-callback metadata/formal state and accepted edit |
| --- | --- | --- |
| [UID:00009Q] `by-class/ObjectList.md` | `92/93`; owner `0000M4`; reconstructable true; emitter `0000M4`; blank position; Nested N/A because the class schema has no marker; CPP nonblank; H nonblank | Same metadata and channel occupancy; add public declaration, exact include block, semantics, and dependencies without duplicating the body |
| [UID:0000M4] `by-file/ObjectList.md` | `92/93`; owner `FILE`; path `NexusTK/map/`; reconstructable/emitter/position/Nested/formal channels N/A because this by-file schema physically has none | Same file metadata/schema; close provisional caveat, add source order/header dependencies, and record UID00023D method route |
| [UID:00037Y] MapPane aggregate | `87/89`; owner `00007Q`; reconstructable true; emitter `00007Q`; blank position; `Nested:-4`; CPP nonblank; H blank | Same exact metadata/formal state; correct wrapper end to `0x0050e317`, preserve route-negative source shape, and point to target body |
| [UID:0001W8] `StaticObjEntry` | `85/88`; owner `0000E2`; reconstructable true; emitter `0000E2`; blank position; Nested N/A because the by-type schema has no marker; CPP blank; H blank | Current `90/94`; all routing/position/Nested/formal fields preserved; accepted field/history/height repair plus later valid packing/type work are present; declaration stays in parent class H; current SHA256 `34495C232C538EDE62F569C31717AE416FCD8B5075EB0AE7307B53AC8D53C388` |
| [UID:0000E2] `StaticObjImageLib` class | Accepted snapshot `88/89`; owner `0000O7`; reconstructable true; emitter `0000O7`; blank position; Nested N/A because class schema has no marker; CPP nonblank; H blank | Current `92/96`; same routing/position/Nested; CPP physically includes `StaticObjImageLib.h`, `ImageFrameTable.h`, `MemoryMan.h`, and `<stdlib.h>` before children; H is nonblank and preserves Singleton/EBO, two-byte `StaticObjEntry` packing, lifecycle, current methods/layout, singleton extern, and the accepted UID00023D field/accessor route; callback-remediation SHA256 `0D036C1E88AE932A925475BF02B9F40E798AB89DEBB13CD03490DEABB8A03D14`, current read-only SHA256 `C28BC94256BD6FD1F826E5A856790508A0FFD2DF510A40B8F504F19AA098117E` after later valid additive work |
| [UID:0000O7] `StaticObjImageLib` file | `88/88`; owner `FILE`; path `NexusTK/render/`; reconstructable/emitter/position/Nested/formal channels N/A because this by-file schema physically has none | Current `90/94` under the same file schema; accepted field semantics, caller, accessor-name, header route, Singleton lifecycle, EBO/layout, resources, and compiler-support exclusions remain present; independent Gate 2A snapshot SHA256 `55BDB10D5DD0E8BE990AD865EC62C2175F03FFE10D0645D157435B02122242A8`, current read-only SHA256 `9B8981EEB3E289F75D8C786F972997EEAB7ED45A7A7365B3E856B1F8B5797616` after later valid additive work |
| [UID:00017H] local image-library cluster | `86/91`; owner `NONE`; reconstructable false; emitter blank; position blank; `Nested:-4`; CPP blank; H blank | Current `90/95` with the same non-emitting route/formal state; accepted index semantics, target caller, accessor name, and header route plus later valid score work are present; current SHA256 `7484661816E3D72199889E8F44151CA11F8D0F3B988B175DC16A2475CEEAC804` |
| [UID:0003TI] MapPane creator | `90/93`; owner `00007Q`; reconstructable true; emitter `00007Q`; blank position; `Nested:0`; CPP nonblank; H blank | Same exact metadata/formal state; replace only two formal identifiers plus supporting prose/history |
| [UID:000075] `LightingObjectPane` class | `90/93`; owner `0000KO`; reconstructable true; emitter `0000KO`; blank position; Nested N/A because class schema has no marker; CPP nonblank; H blank | Same score/routing/position/Nested; CPP remains nonblank; H becomes nonblank with exact Section 22 declaration |
| [UID:0000KO] `LightingObjectPane` file | `89/91`; owner `FILE`; path `NexusTK/map/`; reconstructable/emitter/position/Nested/formal channels N/A because this by-file schema physically has none | Same file metadata/schema; record header ownership and ObjectList consumer |
| [UID:0000E1] `StaticObjectPane` class | `90/92`; owner `0000O6`; reconstructable true; emitter `0000O6`; blank position; Nested N/A because class schema has no marker; CPP nonblank; H blank | Same score/routing/position/Nested; CPP remains nonblank; H becomes nonblank with exact Section 22 declaration |
| [UID:0000O6] `StaticObjectPane` file | `90/91`; owner `FILE`; path `NexusTK/map/`; reconstructable/emitter/position/Nested/formal channels N/A because this by-file schema physically has none | Same file metadata/schema; record header ownership and ObjectList consumer |
| [UID:0000T7] tile dimensions | `91/92`; owner `0000L3`; reconstructable true; emitter `0000L3`; blank position; Nested N/A because by-global schema has no marker; CPP nonblank; H blank | Same score/routing/position/Nested; CPP remains nonblank with external definitions; H becomes nonblank with exact extern declarations |
| [UID:0000SD] singleton global | Accepted snapshot `88/91`; owner `0000O7`; reconstructable true; emitter `0000O7`; blank position; Nested N/A because by-global schema has no marker; CPP nonblank; H blank | Current `92/96` after later valid lifecycle work; same route/formal occupancy; exact UID00023D consumer prose retained with one source definition; current SHA256 `DBC0FB5811C056CBCAD52CEF9088753F3A1FF4E6CFD247CBEE415F06668C4FDE` |
| [UID:0001PP] singleton storage | Accepted snapshot `88/91`; owner `0000SD`; reconstructable true; emitter `0000SD`; blank position; `Nested:0`; CPP nonblank; H blank | Current `93/97`; owner `0000SD`; reconstructable false; blank emitter/position; `Nested:0`; CPP/H blank; exact UID00023D consumer retained without duplicate definition or IDA reshape; current SHA256 `0F6BD0A7DD634AAFC70CE252B1C4E31F876EA67E709E0E8BE782FE850CCEC48A` |

## Score And Metadata Recommendation

| UID/page | Dated accepted pre-callback baseline | Current physical post-callback state | Owner/emitter/reconstructable/position/Nested/formal disposition |
| --- | --- | --- | --- |
| UID00023D target | `85/90`; CPP blank; H blank | `94/93`; CPP nonblank; H blank | owner `00009Q`; emitter `00009Q`; reconstructable true; blank position; `Nested:0`; declaration in UID00009Q H |
| UID00009Q ObjectList class | `92/93`; CPP/H nonblank | `92/93`; CPP/H nonblank with accepted include/declaration additions | owner `0000M4`; emitter `0000M4`; reconstructable true; blank position; Nested N/A/absent |
| UID0000M4 ObjectList file | `92/93` | `92/93` with accepted source-route/history additions | owner `FILE`; path `NexusTK/map/`; emitter/reconstructable/position/Nested/formal fields N/A/absent in by-file schema |
| UID00037Y MapPane aggregate | `87/89`; stale wrapper boundary | `87/89`; exact wrapper end `0x0050e317` | owner `00007Q`; emitter `00007Q`; reconstructable true; blank position; `Nested:-4`; CPP nonblank; H blank |
| UID0001W8 StaticObjEntry | `85/88`; intensity interpretation | `90/94`; `lightImageIndex` current, intensity historical, later packing/type work preserved | owner `0000E2`; emitter `0000E2`; reconstructable true; blank position; Nested N/A/absent; CPP/H blank, declaration in UID0000E2 H |
| UID0000E2 StaticObjImageLib class | accepted snapshot `88/89` | physical final `92/96` | owner `0000O7`; emitter `0000O7`; reconstructable true; blank position; Nested N/A/absent; CPP nonblank with owning-header include; H nonblank with accepted UID00023D declarations plus later Singleton/EBO/packing additions |
| UID0000O7 StaticObjImageLib file | `88/88` | `90/94` with accepted field/header/consumer route plus later valid score work | owner `FILE`; path `NexusTK/render/`; emitter/reconstructable/position/Nested/formal fields N/A/absent in by-file schema |
| UID00017H local cluster | `86/91`; stale index/caller prose | `90/95`; index/caller/header prose synchronized and later valid score work preserved | owner `NONE`; emitter blank; reconstructable false; blank position; `Nested:-4`; CPP/H blank |
| UID0003TI MapPane creator | `90/93`; two active `lightIntensity` tokens | `90/93`; both active tokens are `lightImageIndex` | owner `00007Q`; emitter `00007Q`; reconstructable true; blank position; `Nested:0`; CPP nonblank; H blank |
| UID000075 LightingObjectPane class | `90/93`; CPP nonblank; H blank | `90/93`; CPP nonblank; H nonblank | owner `0000KO`; emitter `0000KO`; reconstructable true; blank position; Nested N/A/absent |
| UID0000KO LightingObjectPane file | `89/91` | `89/91` with accepted H/ObjectList consumer route | owner `FILE`; path `NexusTK/map/`; emitter/reconstructable/position/Nested/formal fields N/A/absent in by-file schema |
| UID0000E1 StaticObjectPane class | `90/92`; CPP nonblank; H blank | `90/92`; CPP nonblank; H nonblank | owner `0000O6`; emitter `0000O6`; reconstructable true; blank position; Nested N/A/absent |
| UID0000O6 StaticObjectPane file | `90/91` | `90/91` with accepted H/ObjectList consumer route | owner `FILE`; path `NexusTK/map/`; emitter/reconstructable/position/Nested/formal fields N/A/absent in by-file schema |
| UID0000T7 tile dimensions | `91/92`; CPP definitions file-local; H blank | `91/92`; CPP definitions external; H has exact externs | owner `0000L3`; emitter `0000L3`; reconstructable true; blank position; Nested N/A/absent |
| UID0000SD singleton global | accepted snapshot `88/91` | physical final `92/96` | owner `0000O7`; emitter `0000O7`; reconstructable true; blank position; Nested N/A/absent; CPP nonblank; H blank |
| UID0001PP singleton storage | accepted snapshot `88/91` | physical final `93/97` | owner `0000SD`; emitter blank; reconstructable false; blank position; `Nested:0`; CPP blank; H blank |

The target remains below `95/95` because original private/local lexemes are inferred and current-PE reachability into the wrapper is not established.

## Open Questions With Attempted Resolution

- **Was the field intensity or an index? Resolved.** The value is passed unchanged to the LightingObjectPane constructor's final slot, stored as `m_lightImageIndex`, consumed by image-table rendering, and accepted by `SetLightImageIndex`; negative is an absence sentinel. `lightImageIndex` is the high-probability human source name.
- **What is slot `+0x20`? Resolved.** Current ObjectPane formal vtable ordering and the zero argument establish `InvalidateRect(NULL)`.
- **What is the target source name? Resolved.** The exact MapPane wrapper already has a high-quality `RefreshStaticObjectLighting` interpretation, and the target performs the same operation on ObjectList storage.
- **Is the target live? Bounded negative result, not deferred research.** Exhaustive current static routes found one tail jump into the target but no route into wrapper start and no stored VA/RVA pointer. This is exact current-PE evidence. It cannot prove original source removal, and the retained source-shaped wrapper/body remain reconstructable; confidence stays below final-audit level.
- **Should the wrapper become a new child now? Resolved for this assignment.** No. Its current aggregate already documents it, while this assignment has no authority to create a new UID. Correct its boundary and keep its source shape in support prose.
- **Can the target compile with current support channels? Resolved by exact callback plan.** Section 22 supplies complete H migrations, ObjectList includes/declaration, and tile-global external declarations.
- **Should a metadata null check be added? Resolved: no.** The binary dereferences the returned entry on every matched-pane path. A defensive check would change behavior.
- **Do stack temporaries all have safe names? Resolved conservatively.** Ten stable semantic slots receive names; multi-role/overlapping/compiler slots remain unchanged rather than receiving false precision.
- **Should IDA function types be rewritten now? Resolved: no.** Formal C++ carries the source-facing types, while I23D-01/I23D-03..05 preserve current IDA prototypes and complete frames. This avoids an unproven prototype-to-frame projection while still improving source-facing names and comments.
- **Should the raw wrapper be defined in IDA? Resolved: no change.** I23D-02 preserves the exact raw body because current route evidence is negative and function-definition semantics are unnecessary for the ordinary source reconstruction.
- **Should singleton storage be materialized in IDA? Resolved: no change.** I23D-06 preserves the one-byte physical head and four-byte zero storage because a destructive `make_data` neighbor contract was not proven; the formal global remains owned by UID0000SD.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

The dated read-only manual-coverage audit on 2026-08-12 produced the 16 exact replacement payloads preserved below. The supervisor subsequently applied every payload in place by UID, inserted/deleted no row, physically reread each exact row once, and validated the five aggregates with commands `000000022765` through `000000022769`, each exit `0` and `ok:1`. Closure snapshot identities were by-memory `F4F52F9AFD0147986EDF38F26666553A7E792CE36027CFDA4F15EC56E3EC0BBD`, by-class `8289C8590BD6AA470CC4FDC056C1D0302903FC197581A3ACB2B85CF7C5E4511C`, by-file `DA924F99DFAA33578DEF3A5A320B7BD088682007A0560337722FAD3D54FDF387`, by-type/by-struct `65023D2F84F1F4F7160947B95B0CF29E09B9A5F224BD477036A9EE57F7E7F937`, and by-global `5913D983A1ABB08FDF9CF6BD7DEC31708390FF487932936FAA1C862E80A971A1`. Commands 22765 and 22769 repeated unrelated existing missing-reference warnings. The payloads are retained as historical accepted text and current claim evidence; no further manual edit is requested unless a later physical audit finds drift.

1. `by-memory/-coverage-report.md`, UID00023D, snapshot line 2763: historical accepted replacement applied in place by the supervisor:

```text
    - [UID:00023D][0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper](by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md) 0x00530d00-0x00530ed9 | class method | ObjectListStaticObjectLightingSyncHelper : reconstructable : 94% : strong : Exact ObjectList::RefreshStaticObjectLighting body over StaticObjEntry lightImageIndex/lightHeightClass, static-row scan, InvalidateRect, attached-light remove/update/create flow, exact MapPane wrapper and route-negative liveness caveat, formal CPP/H source route, and direct ObjectList ownership.
```

2. `by-class/-coverage-report.md`, UID00009Q, snapshot line 375: historical accepted replacement applied in place by the supervisor:

```text
 - [UID:00009Q][ObjectList](by-class/ObjectList.md) : reconstructable : 92% : very-strong : Complete guarded ObjectList.h declaration for the direct LObject-derived 0x44 map-object index, preserving semantic storage, exact lifecycle/dispatch/accessor/private-key methods, typed FindStaticObjectPaneAt, and source-ready UID00023D RefreshStaticObjectLighting declaration with StaticObjEntry lookup, static-row traversal, invalidation, attached-light remove/update/create behavior, tile-dimension dependencies, and child-only ObjectList.cpp definitions; compiler RTTI/vtable/scalar-wrapper artifacts remain regenerated rather than handwritten.
```

3. `by-file/-coverage-report.md`, UID0000M4, snapshot line 193: historical accepted replacement applied in place by the supervisor:

```text
 - [UID:0000M4][ObjectList](by-file/ObjectList.md) : reconstructable : 92% : very-strong : NexusTK/map/ObjectList.h and ObjectList.cpp source root with the complete guarded ObjectList declaration, exact include/child definition route, semantic storage and method inventory, source-ready UID00023D RefreshStaticObjectLighting placement and dependencies, exact MapPane wrapper relationship, preserved remaining helper splits, and child-only emission; compiler RTTI/vtable/scalar-wrapper artifacts are regenerated rather than handwritten.
```

4. `by-memory/-coverage-report.md`, UID00037Y, snapshot line 2486: historical accepted replacement applied in place by the supervisor:

```text
    - [UID:00037Y][0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore](by-memory/0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore.md) 0x0050bce0-0x0050e320 | class aggregate | MapPaneTileObjectGridRenderCore : reconstructable : 87% : very strong : Comment-only MapPane method-cluster aggregate with exact helper inventory, field/type evidence, independently registered source children, and the exact internal route-negative MapPane::RefreshStaticObjectLighting wrapper at 0x0050e300-0x0050e317 tail-jumping to source-bearing UID00023D; wrapper-start xref/pointer-route absence remains a confidence caveat rather than a duplicate emitter.
```

5. `by-type/by-struct/-coverage-report.md`, UID0001W8, snapshot line 116: historical accepted replacement applied in place by the supervisor:

```text
 - [UID:0001W8][StaticObjEntry](by-type/by-struct/StaticObjEntry.md) : reconstructable : 90% : very-strong : Two-byte-packed variable-size SOBJ.TBL record assigned to StaticObjImageLib, with constructor allocation/read order, renderer reverse-layer walk, bounds extent, destructor cache-chain cleanup, signed lightImageIndex negative-sentinel semantics, lightHeightClass tile-height offset use, one-based accessor behavior, and both MapPane/UID00023D ObjectList consumers reconciled; the declaration is emitted once through the owning StaticObjImageLib H channel.
```

6. `by-class/-coverage-report.md`, UID0000E2, snapshot line 530: historical accepted replacement applied in place by the supervisor:

```text
 - [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md) : reconstructable : 92% : very-strong : Complete StaticObjImageLib class/header emitter for NexusTK/render/StaticObjImageLib.cpp with exact LObject plus Singleton<StaticObjImageLib> EBO hierarchy, two-byte-packed StaticObjEntry and TileClassEntry declarations, constructor/unwind/ordinary/scalar lifecycle, renderer/bounds/hit-test/accessor methods, private layout, singleton extern, ImageFrameTable/MemoryMan/CRT dependencies, resources, compiler-support exclusions, and UID00023D lightImageIndex/lightHeightClass consumer contract preserved through the owning CPP/H route.
```

7. `by-file/-coverage-report.md`, UID0000O7, snapshot line 270: historical accepted replacement applied in place by the supervisor:

```text
 - [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md) : reconstructable : 90% : very-strong : NexusTK/render/StaticObjImageLib.cpp source root with complete owning-header route, class-before-children placement, LObject/Singleton EBO and lifecycle, packed entry/table declarations, singleton definition/declaration split, SOBJ/TILEC resources, renderer/bounds/hit-test/accessor inventory, UID00023D ObjectList consumer semantics, and compiler-generated/runtime support exclusions.
```

8. `by-memory/-coverage-report.md`, UID00017H, snapshot line 1889: historical accepted replacement applied in place by the supervisor:

```text
    - [UID:00017H][0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster](by-memory/0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster.md) 0x004dcf60-0x004e6aa6 | class-method-cluster | StaticObjImageLib : not_reconstructable : 90% : very-strong : Non-emitting StaticObjImageLib aggregate/index with constructor, exact ordinary destructor child, renderer, bounds, archive-table, singleton-clear, scalar-delete, resource, ownership, and source-order evidence; the one-based GetStaticObjectEntry accessor and UID00023D lightImageIndex/lightHeightClass consumer are documented while exact source bodies emit through independently owned children/class routes.
```

9. `by-memory/-coverage-report.md`, UID0003TI, snapshot line 2504: historical accepted replacement applied in place by the supervisor:

```text
        - [UID:0003TI][0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile](by-memory/0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile.md) 0x0050f030-0x0050f130 | private method | MapPaneCreateStaticObjectPaneForTile : reconstructable : 90% : very-strong : Exact source-ready MapPane static-object creation helper with typed tile/id/skip-insertion ABI, StaticObjImageLib bounds and packed metadata, signed lightImageIndex/lightHeightClass lighting selection shared with UID00023D, preserved discarded IsRectEmptyOrInvalid call, ordinary-new StaticObjectPane pool lowering, screen-bounds update, ObjectList insertion gate, exact range/hash/caller, and compiler-only EH/pool cleanup exclusions.
```

10. `by-class/-coverage-report.md`, UID000075, snapshot line 282: historical accepted replacement applied in place by the supervisor:

```text
 - [UID:000075][LightingObjectPane](by-class/LightingObjectPane.md) : reconstructable : 90% : very-strong : Complete ObjectPane-derived LightingObjectPane CPP/H emitter with exact constructor/destructor callers, object type 10, lightImageIndex setter/storage, local offsets, anchor-source binding, three vtable views, adjustor thunks, UID00023D remove/update/create consumer behavior, class-before-children placement, and adjacent non-owner split preserved.
```

11. `by-file/-coverage-report.md`, UID0000KO, snapshot line 141: historical accepted replacement applied in place by the supervisor:

```text
 - [UID:0000KO][LightingObjectPane](by-file/LightingObjectPane.md) : reconstructable : 89% : strong : NexusTK/map/LightingObjectPane.cpp source root with complete owning header, constructor/destructor/setter children, lightImageIndex and four-field layout semantics, vtable stores, map-object placement, attached anchor, ObjectList UID00023D consumer route, exact class/child ownership, and AttachmentAnchorResolver exclusion.
```

12. `by-class/-coverage-report.md`, UID0000E1, snapshot line 529: historical accepted replacement applied in place by the supervisor:

```text
 - [UID:0000E1][StaticObjectPane](by-class/StaticObjectPane.md) : reconstructable : 90% : very-strong : Complete 0x12c ObjectPane-derived StaticObjectPane CPP/H declaration with constructor, inline virtual source destructor, bounds/render/event methods, private packet helper, inline static-object-id accessor, exact +0x128 field, attached-object interaction used by UID00023D, class-before-children order, and compiler-generated vtable/scalar-delete/pool mechanics excluded.
```

13. `by-file/-coverage-report.md`, UID0000O6, snapshot line 269: historical accepted replacement applied in place by the supervisor:

```text
 - [UID:0000O6][StaticObjectPane](by-file/StaticObjectPane.md) : reconstructable : 90% : very-strong : NexusTK/map/StaticObjectPane.cpp source root with complete owning header and 0x12c class declaration, source constructor/hit-test/bounds/render/event/packet methods, inline id accessor/destructor cause, UID00023D ObjectList invalidation/attachment consumer route, pool allocation/deletion lowering, and compiler-generated vtable/RTTI/adjustor/scalar-wrapper exclusions.
```

14. `by-global/-coverage-report.md`, UID0000T7, snapshot line 184: historical accepted replacement applied in place by the supervisor:

```text
 - [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md) : reconstructable : 91% : very-strong : MapPane-owned externally linked g_mapTilePixelWidth/g_mapTilePixelHeight pair with exact 48-valued short definitions, formal H extern declarations, 89/94 read-only consumers, rooted width/height by-memory children, coordinate/movement ownership, MainUiGraph bootstrap use, and UID00023D LightingObjectPane construction offsets.
```

15. `by-global/-coverage-report.md`, UID0000SD, snapshot line 148: historical accepted replacement applied in place by the supervisor:

```text
 - [UID:0000SD][g_pStaticObjImageLib](by-global/g_pStaticObjImageLib.md) : reconstructable : 92% : very-strong : StaticObjImageLib singleton source definition owned by StaticObjImageLib.cpp with exact storage child UID0001PP, constructor publish, ordinary/helper/scalar destruction clears, shutdown read, map/static-object/photo consumers including UID00023D, one-definition plus H-extern split, and later Singleton lifecycle/EBO evidence; raw storage remains non-emitting and is not duplicated or reshaped here.
```

16. `by-memory/-coverage-report.md`, UID0001PP, snapshot line 4808: historical accepted replacement applied in place by the supervisor:

```text
    - [UID:0001PP][0x0069b448-0x0069b44c.g_pStaticObjImageLib](by-memory/0x0069b448-0x0069b44c.g_pStaticObjImageLib.md) 0x0069b448-0x0069b44c | global pointer storage | g_pStaticObjImageLib : not_reconstructable : 93% : very-strong : Exact four-byte singleton storage evidence with initialized 0xffffffff sentinel history, 13 live xrefs, constructor publish/null clear, ordinary/helper/scalar destructor clears, startup/shutdown and map/static-object/photo consumers including UID00023D; source definition and extern emit only through UID0000SD/UID0000E2, so this raw storage page remains non-emitting with blank formal CPP/H and no destructive IDA reshape.
```

The supervisor performed all 16 in-place manual-coverage replacements and validations. B003 did not edit a coverage/tracker file and receives no action credit. C23D-045 and C23D-049..C23D-063 mirror these exact applied dispositions and closure snapshot identities.

## Follow-Up Actions

1. Preserve the completed ordinary, supervisor Gate 2B, manual-coverage, and generated closure receipts without transferring supervisor credit to B003 or converting dated artifact identities into permanently current tracker/lifecycle claims.
2. For every later exact artifact, Gate 1/Gate 2 truth remains authoritative only from the external supervisor audit ledger; no report sentence substitutes for that audit.
3. Execution/archive truth remains authoritative only from the current report path and validator-owned history. Historical command `000000022771` executed an earlier exact artifact and command `000000022775` returned it for this body repair; neither history entry is rewritten into a mutable current-status claim.
4. Any later physical drift in by-* documentation, IDA, manual coverage, or generated output requires a new bounded reconciliation rather than replaying the historical handoff or broadening scope.

## Confidence

- **Behavior:** very strong. Every branch, list operation, constructor argument, method call, and source-significant order is represented.
- **ABI/range:** very strong. Exact function item, stack argument, `retn 4`, neighboring padding, and following function are current-IDB facts.
- **Ownership/source placement:** very strong. ObjectList fields and source root are direct.
- **Names/types:** strong for formal source. Public/subsystem vocabulary and cross-consumer evidence resolve the human-facing names and C++ types; exact original private/local spellings remain inferred. IDA prototypes are intentionally protected rather than counted as repaired because this report does not prove safe prototype-to-frame projection.
- **IDA handoff:** strong for the narrow declarative outcomes actually retained. Function and occupied-frame name changes, exact comment-channel replacements, complete frame matrices, expected readbacks, and raw-wrapper/singleton no-change rows are all stated entity by entity; no report text supplies execution or persistence authority.
- **Liveness:** moderate. Target has one direct wrapper edge, but wrapper start is route-negative in the current PE.
- **Overall recommended confidence:** `93`, not higher for the two remaining evidence limits above.

## Validator Results

Every command used the scoped inline form `python .\tools\validator.py --mode file --file <relative-by-star-path> --apply --no-generated-refresh --queue-timeout 240` from `source-3/project-documentation`. Every command exited `0` with `ok: 1`; generated refresh was disabled. The first table preserves the dated B003 callback receipts as historical implementation evidence. The second table records the independent Gate 2A/current-identity reconciliation and the one narrow B003 class remediation. Validator-owned registry/reference and projected-stats side effects are recorded, but B003 made no manual generated/tracker edit.

| Command ID / timestamp | Destination | Resulting SHA256 | Warnings and tool-owned side effects |
| --- | --- | --- | --- |
| `000000022245` / `2026-08-11T15:26:28-04:00` | target UID00023D | `E198B1ADB57021B731D855C6DB3249680846D5697AD9A6DF5B2D97BADDEDDFCF` | No blocking warning; metadata/registry and projected-stats updates; generated refresh skipped |
| `000000022247` / `2026-08-11T15:27:20-04:00` | `by-class/ObjectList.md` | `9DFCCC3D34C28A207DD87D1B41FB124F0DE798166F18270344C72E51EF582455` | No blocking warning; registry/reference and projected-stats updates; generated refresh skipped |
| `000000022251` / `2026-08-11T15:28:54-04:00` | `by-file/ObjectList.md` | `30AC7D8A65FAF74D0DF861EF35FC58694411897203223895FBA11E23109E0AAB` | Existing missing UID `0003IO`; projected-stats update; generated refresh skipped |
| `000000022252` / `2026-08-11T15:29:50-04:00` | UID00037Y MapPane aggregate | `2A20508CB7FCFB1884992E8A068B6D1204D1706A9A1FCA32AF2F007AEE6B252A` | No blocking warning; registry/projected-stats updates; generated refresh skipped |
| `000000022253` / `2026-08-11T15:31:00-04:00` | `StaticObjEntry` | `5E5CE91D636B385434D23640C0B8A8DD5D2635BE188C50BF0D9972D805D6A7F2` | No blocking warning; metadata/registry/projected-stats updates; generated refresh skipped |
| `000000022284` / `2026-08-11T15:41:07-04:00` | `by-class/StaticObjImageLib.md` final drift reconciliation | `C65C7B13081C1D1F7F25ECB456E29A64E8D3C0C5677AA706011A7171721C1812` | Existing missing UID `0003M2` and stale UID000184 target path; metadata/registry/projected-stats updates; generated refresh skipped |
| `000000022259` / `2026-08-11T15:32:49-04:00` | `by-file/StaticObjImageLib.md` | `7E25E188F2E2E68E2CF29662AA452851945324CBB1C122063CEC4A40ABBA546D` | Existing missing UID `0003M2`; reference/projected-stats updates; generated refresh skipped |
| `000000022261` / `2026-08-11T15:34:48-04:00` | UID00017H local cluster | `4B404AD9A98ED835E0882858B70855CFEFB31761EA383726DBB1E40ED12EB25E` | Existing missing UID `0003M2`; projected-stats update; generated refresh skipped |
| `000000022262` / `2026-08-11T15:35:38-04:00` | UID0003TI MapPane creator | `F2834C4867E8CB4B46AC13B37545EBA3305A99E1A69644D0333CEC2CDAC759B4` | No blocking warning; registry/projected-stats updates; generated refresh skipped |
| `000000022264` / `2026-08-11T15:36:24-04:00` | `by-class/LightingObjectPane.md` | `183905BC66588EC57D8B10AB5F74DA1939822F36AA4010885B671DE3A0222E33` | No blocking warning; registry/reference/projected-stats updates; generated refresh skipped |
| `000000022265` / `2026-08-11T15:36:52-04:00` | `by-file/LightingObjectPane.md` | `D21C51C88C995A91A99DF87889C7A4779D346F5200F639453A905B72355C4398` | No blocking warning; reference/projected-stats updates; generated refresh skipped |
| `000000022277` / `2026-08-11T15:37:31-04:00` | `by-class/StaticObjectPane.md` | `F2A760FB7FB214404C06D159AD0686BB88023D6BF22163A4AB0563EC93DF2F05` | Existing missing UID `000388`; registry/reference/projected-stats updates; generated refresh skipped |
| `000000022279` / `2026-08-11T15:38:06-04:00` | `by-file/StaticObjectPane.md` | `2E7FACC0A3D6AFBFF68E455EEBA7F4BD400E54D928465041633A513D851DAFC0` | Existing missing UID `000388`; reference/projected-stats updates; generated refresh skipped |
| `000000022280` / `2026-08-11T15:38:41-04:00` | `MapTilePixelDimensions` | `65F0A9682982680C26C333A454D851058FED3960757AFFA5C0C0C29B1F956B96` | Existing missing UID `0003ZK`; registry/reference/stats updates; generated refresh skipped |
| `000000022282` / `2026-08-11T15:39:25-04:00` | `g_pStaticObjImageLib` | `90D0E2705E96A3BF1905F18C1070629563E5E4FDDC8059A1E2DD66FF5CF47C96` | Existing stale UID000184 target path; metadata/reference/stats updates; generated refresh skipped |
| `000000022283` / `2026-08-11T15:40:01-04:00` | exact singleton storage UID0001PP | `4A01188C9277464A1BB8BE80677EDECB1AA154587DFFAE13B1CCA2A894BEE387` | Existing stale UID000184 target path; metadata/registry/reference/projected-stats updates; generated refresh skipped |

Historical reconciliation/remediation receipts and current physical readback are deliberately separate:

| Command ID / timestamp | Destination | Historical receipt/snapshot SHA256 | Current physical SHA256 at this repair | Result, authority, and side effects |
| --- | --- | --- | --- | --- |
| `000000022389` / `2026-08-11T18:43:32-04:00` | `StaticObjEntry` | `34495C232C538EDE62F569C31717AE416FCD8B5075EB0AE7307B53AC8D53C388` | `34495C232C538EDE62F569C31717AE416FCD8B5075EB0AE7307B53AC8D53C388` | Independent supervisor Gate 2A receipt; exit 0, ok 1; current read-only state still preserves later valid 90/94 packing/type work; generated refresh skipped |
| `000000022436` / `2026-08-11T19:30:10-04:00` | `by-class/StaticObjImageLib.md` narrow owning-header remediation | `0D036C1E88AE932A925475BF02B9F40E798AB89DEBB13CD03490DEABB8A03D14` | `C28BC94256BD6FD1F826E5A856790508A0FFD2DF510A40B8F504F19AA098117E` | Historical B003 callback receipt; exit 0, ok 1; the later current physical artifact preserves that owning-header repair plus valid ImageFrameTable/MemoryMan/CRT, Singleton/EBO, packing, lifecycle, and method/layout additions; generated refresh was skipped for the historical command |
| `000000022391` / `2026-08-11T18:43:39-04:00` | `by-file/StaticObjImageLib.md` | `55BDB10D5DD0E8BE990AD865EC62C2175F03FFE10D0645D157435B02122242A8` | `9B8981EEB3E289F75D8C786F972997EEAB7ED45A7A7365B3E856B1F8B5797616` | Historical independent supervisor Gate 2A receipt; exit 0, ok 1; the current physical artifact retains 90/94 accepted field/header/source-route facts after later valid additive file work; generated refresh was skipped for the historical command |
| `000000022392` / `2026-08-11T18:43:43-04:00` | UID00017H local cluster | `7484661816E3D72199889E8F44151CA11F8D0F3B988B175DC16A2475CEEAC804` | `7484661816E3D72199889E8F44151CA11F8D0F3B988B175DC16A2475CEEAC804` | Independent supervisor Gate 2A receipt; exit 0, ok 1; current read-only 90/95 non-emitting route remains byte-identical; generated refresh skipped |
| `000000022399` / `2026-08-11T18:44:10-04:00` | singleton global UID0000SD | `DBC0FB5811C056CBCAD52CEF9088753F3A1FF4E6CFD247CBEE415F06668C4FDE` | `DBC0FB5811C056CBCAD52CEF9088753F3A1FF4E6CFD247CBEE415F06668C4FDE` | Independent supervisor Gate 2A receipt; exit 0, ok 1; current read-only 92/96 source owner remains byte-identical; generated refresh skipped |
| `000000022400` / `2026-08-11T18:44:14-04:00` | singleton storage UID0001PP | `0F6BD0A7DD634AAFC70CE252B1C4E31F876EA67E709E0E8BE782FE850CCEC48A` | `0F6BD0A7DD634AAFC70CE252B1C4E31F876EA67E709E0E8BE782FE850CCEC48A` | Independent supervisor Gate 2A receipt; exit 0, ok 1; current read-only 93/97 non-emitting storage remains byte-identical; generated refresh skipped |

Supervisor-owned closure receipts after the B003 callback:

| Command / authority | Scope | Verified result |
| --- | --- | --- |
| Gate 2B audit `2026-08-12T11:52:00-04:00` | C23D-035..C23D-042 and C23D-048 protections | Four function renames/comments, ten stack renames, map-position/tile-global comments, raw-wrapper/singleton no-change, one save, canonical SHA `A95C3CF171A95F77AF9BBFF9247E81C53E7816059D203320E83E7B369ACD36F1`, and distinct-session persistence all passed |
| `000000022765`..`000000022769` | C23D-045/C23D-049..C23D-063 | All 16 UID-keyed manual rows applied once and validated; closure snapshot hashes are recorded in Section 28 |
| `000000022770` | C23D-047 coherent generated refresh/readback | `ObjectList.cpp` SHA `83417F5E7CA213DD2122B480F60110B92375642AFAC4CB5F08B35807C9C4DCB2`, 31,584 bytes; `ObjectList.h` SHA `ECEE3FDD26130BA9B99EA7B8B5A61A38602F0D32BE2DF1DAB8CD624FFC3EDE98`, 2,753 bytes; exact target body/declarations/includes and no raw target labels |
| `000000022770` support readback | Routed support CPP/H | LightingObjectPane `13694331304D612354B815649D2B284BE4B67AE510B3FB21EEA6443BC154FF6F` / `C636816207CAD3785DC14C24A7D5ABA8B7706C7515357A29D2A8DE79B49CEA0`; StaticObjectPane `FDF0610C819AB08DEE625E6CA217B11FFA969AE4DF1DDA8A2135EC554078240E` / `790DD65D6472AFE1EF3353D5AF403821E00C0DD5FB8ED9C76D45699B4D8B8010`; StaticObjImageLib `9C982676FAF45DBDB04CCA6051F159E1559B9E4873E919334B8E92440674EBD5` / `84D31D853E2969F2C2E06E2AA797217CABBE16EE99ECCCE8994F15BFE6EC1A4A` |

No coverage validation, generated refresh/readback, IDA mutation, or report lifecycle command was run by B003; every later operation above is explicitly supervisor-attributed.

## Changed Files

- Created: none. No by-* page, generated file, coverage row, report companion, or lifecycle artifact was created by B003 for this work.
- Modified during the dated ordinary callback: target UID00023D; ObjectList class/file; UID00037Y wrapper aggregate; StaticObjEntry; StaticObjImageLib class/file/local cluster; UID0003TI MapPane creator; LightingObjectPane class/file; StaticObjectPane class/file; MapTilePixelDimensions; singleton global; and singleton storage. Their exact post-callback/current receipts are recorded in Validator Results.
- The StaticObjImageLib class and singleton pages contained later valid B005 lifecycle work. B003 preserved it, reconciled only the accepted UID00023D routes, and recorded the physical `92/96`, `92/96`, and `93/97` states rather than restoring stale accepted-report snapshots.
- Modified during the later narrow remediation: only `by-class/StaticObjImageLib.md`; its formal CPP now includes its own header immediately before `[[CHILDREN]]`, and validator `000000022436` produced SHA256 `0D036C1E88AE932A925475BF02B9F40E798AB89DEBB13CD03490DEABB8A03D14`. StaticObjEntry, the StaticObjImageLib file/local cluster, and singleton global/storage were read-only reconciliation destinations and retain the current hashes recorded above.
- Modified during this same-report Gate 1 repair: only this UID00023D report. No external destination was edited.
- Modified later by the supervisor, not B003: the canonical IDB received the exact persisted Gate 2B actions; five manual coverage aggregates received the 16 exact in-place rows; command `000000022770` coherently refreshed generated outputs. Those changes are recorded only as external receipts here.
- Renamed: none. No file path, UID, report, archive, or destination was renamed or moved by B003.
- No `-coverage-report.md`, generated/tracker file, audit/assignment file, IDA database, MCP process, lifecycle state, prior report, or `*-removed.md` archive was edited.
- Canonical lifecycle authority: current execution/archive truth is deferred to the current report path and validator-owned status/history metadata; report prose does not assert a current lifecycle result and cannot authorize execution, movement, or archival.
- The exact physical report SHA256, size, line count, heading count, parity, allocation, marker count, and lease state are returned to the supervisor after the final stable reread rather than embedded as a self-invalidating hash.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation. The dated pre-callback artifact received that authorization before the ordinary callback.
- [x] For a by-file target, exhaustive whole-file inventory completed and reconciled against IDA, all related by-* pages, generated output, and matching reports; every function and every other code/data/type/resource/range item has an evidence-backed disposition rather than a sampled-subset or generic future-work entry: not applicable because UID00023D is a by-memory target; the owning/support file routes were still exhaustively reconciled as dependencies.
- [x] For a by-file target, every file-owned inventory item has explicit behavior/role, ownership/emitter/source placement, CPP/H or no-code, metadata/score, destination doc, Claim And Incorporation Ledger, and Implementation Tracking Checklist coverage as applicable; excluded candidates have evidence-backed reasons: not applicable because UID00023D is a by-memory target; all target/support dependencies have explicit dispositions.
- [x] For a by-file target, current generated `.cpp`/`.h` audited against the inventory and every missing/incomplete function, code path, data definition, declaration/type/include/forward declaration, child route/order defect, stub/placeholder/empty marker, and required-but-missing header has an exact formal CPP/H repair or evidence-backed no-code/no-header disposition: not applicable as a by-file gate; generated ObjectList and support routing were nevertheless audited and exact CPP/H repairs were supplied.
- [x] Target/support docs to update: exact target and support destinations are enumerated in Sections 24 and 25 and mirrored claim by claim below.
- [x] Every declared additional UID has target-specific evidence, recommendation, ledger rows, destination docs, and planned validation: no additional target UID is declared; support UIDs are dependency destinations rather than additional targets.
- [x] Current target state and actual evidence checked recorded: Sections 3, 4, 9, 10, 12-16, and 31 preserve dated baselines separately from current physical state and receipts.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: all 63 IDs are present in canonical parity.
- [x] Metadata/score changes to apply: exact dated-to-current target/support metadata is recorded in Sections 24-26.
- [x] Score-limiting blockers researched to resolution, implementation-ready repair/split recommendation, or rare exact evidence-backed no-improvement proof after all reasonable current routes were exhausted: behavior, source placement, naming, frame, comment, storage, and route-negative evidence have explicit dispositions.
- [x] Owner/emitter/reconstructable changes to apply: no route change; every exact preservation disposition is recorded in Sections 24-26.
- [x] Split/rename/new-child changes to apply: no document split/new UID/file rename; the raw wrapper and singleton storage retain evidence-backed no-change dispositions.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable: Sections 18-21 provide exact placement/range and structured action/no-change rows.
- [x] Supervisor Gate 2B IDA handoff lists every exact address/entity, dated pre-state, accepted action, supporting type, safety constraint, and expected readback; the external supervisor receipt records completed I23D-01..I23D-08C action/no-change and distinct-session persistence verification without crediting B003.
- [x] First-draft CPP block text/no-code proof and H block text/no-header-code proof to apply: Section 22 preserves the exact target and support formal CPP/H payloads plus the target H no-code route.
- [x] Third-party import directive to apply or confirm not applicable, including exact `third_party_embeds/...` paths and confirmation that the multiline C++ block remains blank: target-specific N/A is proved in Section 22 because all code is project-owned; no import directive or third-party import code channel exists.
- [x] Exact target/support doc facts to incorporate at report-level detail: Sections 24-26 and C23D-001..C23D-034/C23D-043..C23D-044 enumerate them without summary loss.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: Sections 4, 9, 16, 20, and 27 preserve corrected `lightIntensity` and other rejected interpretations as history.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable: no operative Wave2/Wave3 routing is used; any such stage label is non-authoritative and ignored.
- [x] Open questions to close or document as evidence-backed unresolved: Section 27 confines residual uncertainty to exact original private names and current static-route limits without deferring required research.
- [x] Validators to run: exact scoped callback commands and receipts are recorded in Section 31; no validator is authorized in this report-only repair.
- [x] Generated report refresh and explicit manual supervisor-owned coverage text reconciled: commands 22765-22769 applied/validated all 16 exact rows and command 22770 coherently refreshed/read back ObjectList and support CPP/H; Sections 28 and 31 retain exact receipts.

Implementation callback pass:
- [x] Supervisor-owned IDA changes/no-change protections were independently applied or verified and persisted: C23D-035..C23D-042 are checked with external supervisor evidence; B003 performed no IDA action.
- [x] For a by-file target, all accepted whole-file inventory claims were incorporated and verified across the by-file page and every affected support page; no function or other file-owned code/data/type/resource item was silently omitted: not applicable as a by-file gate; the UID00023D target and every accepted support destination were verified claim by claim.
- [x] For a by-file target, every accepted missing/incomplete function/code/data/declaration/header/routing repair was applied through owning formal CPP/H channels; a coherent validator refresh completed; current generated `.cpp` and required `.h` were physically reread against the full inventory and contain no unresolved stub, placeholder, empty marker, partial implementation, missing declaration, or ordering defect. If no `.h` exists, the report contains a file-specific verified no-header disposition: not applicable as a by-file gate; ordinary formal target/support changes, the owning-header remediation, and supervisor command 22770 generated readback are recorded.
- [x] Report accepted by supervisor for implementation: the dated exact pre-callback artifact received Gate 1 acceptance before callback edits.
- [x] All accepted target/support doc details incorporated at report-level detail: C23D-001..C23D-034 and C23D-043..C23D-044 are physically applied and checked.
- [x] Every declared primary/additional UID verified independently against its ledger and destination docs: primary UID00023D was verified; no additional target UID is declared.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: both 63-row tables are canonical and parity-bound.
- [x] Metadata/score/owner/emitter/split/rename/CPP/H changes applied or explicitly not applied with reason: Sections 24-26 and the checked ordinary claims record exact current states.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: corrected names and unsupported interpretations remain explicitly historical/rejected.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale: Section 27 is reconciled to the current callback state.
- [x] Validators run and results recorded: Section 31 retains exact command IDs, timestamps, results, warnings, hashes, and tool-owned side effects.
- [x] Generated CPP/H refresh/readback completed by supervisor command `000000022770`; exact ObjectList and support identities and semantic readbacks are recorded in Section 31.
- [x] No accepted technical claim remains unapplied: ordinary rows, supervisor IDA/no-change rows, manual coverage, generated readback, and boundary protections all have actor-qualified evidence; lifecycle status itself remains external path/history authority rather than a report claim.
- [x] Report body is lifecycle-neutral: current execution/archive truth is deferred to the current path and validator-owned status/history metadata, and no body/checklist sentence will become false merely because the supervisor executes or invalidates the report.

Current external-gate state:

- [x] The authorized ordinary implementation callback is complete: C23D-001..C23D-034, C23D-043..C23D-044, and C23D-046 were physically verified and are checked below.
- [x] All ordinary scoped validators completed with exit `0`, `ok: 1`, generated refresh disabled, and receipts recorded in Section 31.
- [x] Exact-artifact Supervisor Gate 1 truth remains externally authoritative and must match the current report path/hash; this report does not self-assert that mutable gate state.
- [x] Supervisor Gate 2A verification of the completed ordinary callback is preserved as an external historical exact-artifact receipt; current gate truth remains audit-ledger authoritative.
- [x] Supervisor Gate 2B work C23D-035..C23D-042 completed with exact prestate/action/readback/one-save/distinct-session persistence verification; B003 performed no IDA action.
- [x] Supervisor-owned manual coverage C23D-045/C23D-049..C23D-063 and generated refresh/readback C23D-047 completed under commands 22765-22770.
- [x] C23D-048 boundaries were observed. Report execution/archive action remains supervisor-only; historical commands 22771/22775 are retained in validator history, and current lifecycle truth comes only from current path plus validator-owned metadata.

Parity contract: the claim table below mirrors Section 11 exactly after removing only the `Done` column. Parity includes Claim ID, Target UID, Claim, Confidence, Evidence, Destination doc/section, Action, and Verification state. All 63 rows are checked after ordinary callback verification plus externally credited supervisor IDA/manual-coverage/generated/no-change closure.

Canonical mechanics after this additive repair: 63 claims; Action counts are `incorporate:59`, `historicalize:1`, `not-applicable:3`, and zero for every other allowed Action; Verification-state counts are `applied:60`, `already-present:3`, and zero for every other allowed state; checklist allocation is 63 checked / 0 unchecked.

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | C23D-001 | 00023D | Preserve exact target range and adjacent padding. Implementation detail: Document `0x00530d00-0x00530ed9`, preceding 9 CC bytes, following 7 CC bytes, and no split. | very strong | Current items and bytes. Callback receipt: physical SHA256 E198B1ADB57021B731D855C6DB3249680846D5697AD9A6DF5B2D97BADDEDDFCF; validator 000000022245 exit 0, ok 1. | by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md | incorporate | applied |
| [x] | C23D-002 | 00023D | Correct the source ABI to a void ObjectList method with unsigned-short id. Implementation detail: Set source-facing signature to `void ObjectList::RefreshStaticObjectLighting(unsigned short staticObjectId)`. | strong | Wrapper tail-call and complete target flow. Callback receipt: physical SHA256 E198B1ADB57021B731D855C6DB3249680846D5697AD9A6DF5B2D97BADDEDDFCF; validator 000000022245 exit 0, ok 1. | by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md | incorporate | applied |
| [x] | C23D-003 | 00023D | Record the exact extended-row and per-row object scan. Implementation detail: Document `m_gridHeight + 12`, static row lists, cached counts, and pointer-slot dereference. | very strong | Target decompilation and ObjectList layout. Callback receipt: physical SHA256 E198B1ADB57021B731D855C6DB3249680846D5697AD9A6DF5B2D97BADDEDDFCF; validator 000000022245 exit 0, ok 1. | by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md | incorporate | applied |
| [x] | C23D-004 | 00023D | Record exact static-object id filtering. Implementation detail: Document unsigned `m_staticObjectId` comparison before all lighting work. | very strong | `+0x128` read and StaticObjectPane declaration. Callback receipt: physical SHA256 E198B1ADB57021B731D855C6DB3249680846D5697AD9A6DF5B2D97BADDEDDFCF; validator 000000022245 exit 0, ok 1. | by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md | incorporate | applied |
| [x] | C23D-005 | 00023D | Correct virtual slot `+0x20` to pane invalidation. Implementation detail: Replace detach/disable wording with `InvalidateRect(NULL)` and preserve call order. | strong | ObjectPane vtable contract and zero argument. Callback receipt: physical SHA256 E198B1ADB57021B731D855C6DB3249680846D5697AD9A6DF5B2D97BADDEDDFCF; validator 000000022245 exit 0, ok 1. | by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md | incorporate | applied |
| [x] | C23D-006 | 00023D | Resolve attached-light access. Implementation detail: Name `sub_5376C0` as `ObjectPane::GetAttachedObject()` over `+0x118`. | very strong | Exact one-instruction accessor and ObjectPane layout. Callback receipt: physical SHA256 E198B1ADB57021B731D855C6DB3249680846D5697AD9A6DF5B2D97BADDEDDFCF; validator 000000022245 exit 0, ok 1. | by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md | incorporate | applied |
| [x] | C23D-007 | 00023D | Preserve negative-index list removal behavior. Implementation detail: Document pointer scan and `m_lightingObjects->RemoveAt(lightIndex, 1)`. | very strong | Target branch and List contract. Callback receipt: physical SHA256 E198B1ADB57021B731D855C6DB3249680846D5697AD9A6DF5B2D97BADDEDDFCF; validator 000000022245 exit 0, ok 1. | by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md | incorporate | applied |
| [x] | C23D-008 | 00023D | Preserve detach then delete ordering. Implementation detail: Document `staticObjectPane->DetachObject(); delete lightingObjectPane;` after list removal. | very strong | Exact virtual calls and deleting-destructor flags. Callback receipt: physical SHA256 E198B1ADB57021B731D855C6DB3249680846D5697AD9A6DF5B2D97BADDEDDFCF; validator 000000022245 exit 0, ok 1. | by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md | incorporate | applied |
| [x] | C23D-009 | 00023D | Preserve existing-light index update. Implementation detail: Emit `SetLightImageIndex` for nonnegative entries with an existing attachment. | very strong | Direct call to `0x0053c980`. Callback receipt: physical SHA256 E198B1ADB57021B731D855C6DB3249680846D5697AD9A6DF5B2D97BADDEDDFCF; validator 000000022245 exit 0, ok 1. | by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md | incorporate | applied |
| [x] | C23D-010 | 00023D | Preserve missing-light construction and attachment. Implementation detail: Document exact constructor arguments, `AddObjectPane`, then `AttachObject`. | strong | Target decompilation and twin MapPane helper. Callback receipt: physical SHA256 E198B1ADB57021B731D855C6DB3249680846D5697AD9A6DF5B2D97BADDEDDFCF; validator 000000022245 exit 0, ok 1. | by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md | incorporate | applied |
| [x] | C23D-011 | 00023D | Replace intensity semantics with signed image-index semantics. Implementation detail: Rename `lightIntensity` to `lightImageIndex` and retain the former name as rejected history. | strong | Signed sentinel and two image-index consumers. Callback receipt: later valid packing/type drift preserved; current physical SHA256 34495C232C538EDE62F569C31717AE416FCD8B5075EB0AE7307B53AC8D53C388 at 90/94; B003 validator 000000022253 and independent supervisor Gate 2A validator 000000022389 both exited 0, ok 1. | by-type/by-struct/StaticObjEntry.md | incorporate | applied |
| [x] | C23D-012 | 00023D | Retain and strengthen height-class semantics. Implementation detail: Document `lightHeightClass` as the byte used in exact tile-height offset arithmetic. | strong | Target and MapPane creator. Callback receipt: later valid packing/type drift preserved; current physical SHA256 34495C232C538EDE62F569C31717AE416FCD8B5075EB0AE7307B53AC8D53C388 at 90/94; B003 validator 000000022253 and independent supervisor Gate 2A validator 000000022389 both exited 0, ok 1. | by-type/by-struct/StaticObjEntry.md | incorporate | applied |
| [x] | C23D-013 | 00023D | Resolve the direct MapPane wrapper name and exact range. Implementation detail: Record `MapPane::RefreshStaticObjectLighting` at `0x0050e300-0x0050e317` and tail-call target. | very strong | Exact bytes and current wrapper review. Callback receipt: physical SHA256 2A20508CB7FCFB1884992E8A068B6D1204D1706A9A1FCA32AF2F007AEE6B252A; validator 000000022252 exit 0, ok 1. | by-memory/0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore.md | incorporate | applied |
| [x] | C23D-014 | 00023D | Preserve route-negative liveness evidence without suppressing source. Implementation detail: Record one incoming tail jump, zero wrapper-start xrefs, and zero VA/RVA pointer hits as confidence cap. | very strong | Current xrefs and bounded byte searches. Callback receipt: physical SHA256 E198B1ADB57021B731D855C6DB3249680846D5697AD9A6DF5B2D97BADDEDDFCF; validator 000000022245 exit 0, ok 1. | by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md | incorporate | applied |
| [x] | C23D-015 | 00023D | Record complete direct helper inventory. Implementation detail: Add lookup, getter, constructor, setter, map-position, list-add, allocation, and list virtual roles. | very strong | Current analyze/decompile/xrefs. Callback receipt: physical SHA256 E198B1ADB57021B731D855C6DB3249680846D5697AD9A6DF5B2D97BADDEDDFCF; validator 000000022245 exit 0, ok 1. | by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md | incorporate | applied |
| [x] | C23D-016 | 00023D | Preserve exact target routing, placement, and nesting metadata. Implementation detail: Change only `85/90` to `94/93`; preserve owner `00009Q`, reconstructable true, emitter `00009Q`, literal blank position, and `Nested:0`. | very strong | Physical target header, `this` fields, and file route. Callback receipt: physical SHA256 E198B1ADB57021B731D855C6DB3249680846D5697AD9A6DF5B2D97BADDEDDFCF; validator 000000022245 exit 0, ok 1. | by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md | incorporate | applied |
| [x] | C23D-017 | 00023D | Close source placement without changing the file-page schema. Implementation detail: Replace provisional target wording; preserve `92/93`, owner `FILE`, path `NexusTK/map/`; reconstructable/emitter/position/Nested/formal channels remain N/A because this by-file schema physically has none. | very strong | Wrapper, ObjectList storage evidence, and current file header. Callback receipt: physical SHA256 30AC7D8A65FAF74D0DF861EF35FC58694411897203223895FBA11E23109E0AAB; final validator 000000022251 exit 0, ok 1. | by-file/ObjectList.md | incorporate | applied |
| [x] | C23D-018 | 00023D | Emit the complete target formal CPP body. Implementation detail: Insert the exact Section 22 method body; keep H blank. | strong | Full target behavior and support contracts. Callback receipt: physical SHA256 E198B1ADB57021B731D855C6DB3249680846D5697AD9A6DF5B2D97BADDEDDFCF; validator 000000022245 exit 0, ok 1. | by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md | incorporate | applied |
| [x] | C23D-019 | 00023D | Keep declaration responsibility on ObjectList H. Implementation detail: State that target H remains blank because class UID00009Q declares the method. | very strong | Existing emitter architecture. Callback receipt: physical SHA256 E198B1ADB57021B731D855C6DB3249680846D5697AD9A6DF5B2D97BADDEDDFCF; validator 000000022245 exit 0, ok 1. | by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md | incorporate | applied |
| [x] | C23D-020 | 00023D | Add ObjectList public declaration while preserving exact class metadata. Implementation detail: Insert `void RefreshStaticObjectLighting(unsigned short staticObjectId);`; preserve `92/93`, owner `0000M4`, reconstructable true, emitter `0000M4`, blank position, schema-absent/N/A Nested, and nonblank CPP/nonblank H disposition. | very strong | MapPane wrapper, current class header, and public access requirement. Callback receipt: physical SHA256 9DFCCC3D34C28A207DD87D1B41FB124F0DE798166F18270344C72E51EF582455; validator 000000022247 exit 0, ok 1. | by-class/ObjectList.md | incorporate | applied |
| [x] | C23D-021 | 00023D | Add exact ObjectList source includes. Implementation detail: Replace CPP include block with the Section 22 include set before `[[CHILDREN]]`. | strong | Complete-type and global visibility requirements. Callback receipt: physical SHA256 9DFCCC3D34C28A207DD87D1B41FB124F0DE798166F18270344C72E51EF582455; validator 000000022247 exit 0, ok 1. | by-class/ObjectList.md | incorporate | applied |
| [x] | C23D-022 | 00023D | Synchronize ObjectList family prose under exact file metadata. Implementation detail: Replace stale caveats and add behavior/source route; preserve `92/93`, owner `FILE`, path `NexusTK/map/`, with reconstructable/emitter/position/Nested/formal channels N/A because the by-file header has none. | strong | Current report closure and physical file header. Callback receipt: physical SHA256 30AC7D8A65FAF74D0DF861EF35FC58694411897203223895FBA11E23109E0AAB; final validator 000000022251 exit 0, ok 1. | by-file/ObjectList.md | incorporate | applied |
| [x] | C23D-023 | 00023D | Correct wrapper aggregate boundary without changing support metadata. Implementation detail: Correct end to `0x0050e317`; preserve `87/89`, owner `00007Q`, reconstructable true, emitter `00007Q`, blank position, `Nested:-4`, nonblank CPP, blank H. | very strong | Last instruction, route-negative evidence, and physical support header. Callback receipt: physical SHA256 2A20508CB7FCFB1884992E8A068B6D1204D1706A9A1FCA32AF2F007AEE6B252A; validator 000000022252 exit 0, ok 1. | by-memory/0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore.md | incorporate | applied |
| [x] | C23D-024 | 00023D | Upgrade StaticObjEntry documentation and exact metadata. Implementation detail: Preserve the dated accepted `85/88 -> 90/92` callback step, the later valid packing/type work, and the current `90/94`; preserve owner `0000E2`, reconstructable true, emitter `0000E2`, blank position, schema-absent/N/A Nested, blank CPP, and blank H because the parent class H owns the full declaration. | strong | Cross-consumer closure and physical type header. Callback receipt: later valid packing/type drift preserved; current physical SHA256 34495C232C538EDE62F569C31717AE416FCD8B5075EB0AE7307B53AC8D53C388 at 90/94; independent supervisor Gate 2A validator 000000022389 exited 0, ok 1. | by-type/by-struct/StaticObjEntry.md | incorporate | applied |
| [x] | C23D-025 | 00023D | Move StaticObjImageLib declaration to H under exact class metadata. Implementation detail: Apply the accepted H and owning-header CPP route while preserving later valid Singleton/EBO/packing additions; final state is `92/96`, owner `0000O7`, reconstructable true, emitter `0000O7`, blank position, schema-absent/N/A Nested, CPP nonblank, and H nonblank. | strong | Complete-type need and physical class header. Callback remediation receipt: SHA256 0D036C1E88AE932A925475BF02B9F40E798AB89DEBB13CD03490DEABB8A03D14; validator 000000022436 exit 0, ok 1; generated refresh skipped. Current read-only physical SHA256 C28BC94256BD6FD1F826E5A856790508A0FFD2DF510A40B8F504F19AA098117E preserves the complete 92/96 owning-header, ImageFrameTable/MemoryMan/CRT, Singleton/EBO, packed-entry, lifecycle, method, layout, and singleton-extern formal state reproduced in Section 22. | by-class/StaticObjImageLib.md | incorporate | applied |
| [x] | C23D-026 | 00023D | Synchronize StaticObjImageLib file documentation under exact file metadata. Implementation detail: Preserve the accepted field/header prose and later valid current `90/94`, owner `FILE`, path `NexusTK/render/`; `88/88` remains the dated callback baseline, and reconstructable/emitter/position/Nested/formal channels are N/A because this by-file header has none. | strong | Target, setter research, and physical file header. Independent Gate 2A snapshot SHA256 55BDB10D5DD0E8BE990AD865EC62C2175F03FFE10D0645D157435B02122242A8; validator 000000022391 exit 0, ok 1. Current read-only physical SHA256 9B8981EEB3E289F75D8C786F972997EEAB7ED45A7A7365B3E856B1F8B5797616 retains 90/94 and the accepted UID00023D field/header/source-route facts after later valid additive file work. | by-file/StaticObjImageLib.md | incorporate | applied |
| [x] | C23D-027 | 00023D | Synchronize local image-library helper documentation without changing its non-emitting route. Implementation detail: Preserve accepted index/caller prose and later valid current `90/95`, owner `NONE`, reconstructable false, blank emitter, blank position, `Nested:-4`, blank CPP, and blank H; `86/91` remains the dated callback baseline. | strong | `0x004dda30` evidence and physical support header. Callback receipt: later valid score drift preserved; current physical SHA256 7484661816E3D72199889E8F44151CA11F8D0F3B988B175DC16A2475CEEAC804 at 90/95; independent supervisor Gate 2A validator 000000022392 exited 0, ok 1. | by-memory/0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster.md | incorporate | applied |
| [x] | C23D-028 | 00023D | Correct MapPane creator field name under exact metadata. Implementation detail: Replace two identifiers; preserve `90/93`, owner `00007Q`, reconstructable true, emitter `00007Q`, blank position, `Nested:0`, nonblank CPP, blank H. | very strong | Shared metadata flow and physical support header. Callback receipt: physical SHA256 F2834C4867E8CB4B46AC13B37545EBA3305A99E1A69644D0333CEC2CDAC759B4; validator 000000022262 exit 0, ok 1. | by-memory/0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile.md | incorporate | applied |
| [x] | C23D-029 | 00023D | Move LightingObjectPane declaration to H under exact class metadata. Implementation detail: Apply Section 22 H payload; preserve `90/93`, owner `0000KO`, reconstructable true, emitter `0000KO`, blank position, schema-absent/N/A Nested; CPP stays nonblank and H changes blank to nonblank. | very strong | Complete-type need and physical class header. Callback receipt: physical SHA256 183905BC66588EC57D8B10AB5F74DA1939822F36AA4010885B671DE3A0222E33; validator 000000022264 exit 0, ok 1. | by-class/LightingObjectPane.md | incorporate | applied |
| [x] | C23D-030 | 00023D | Synchronize LightingObjectPane file route under exact file metadata. Implementation detail: Add header/ObjectList consumer prose; preserve `89/91`, owner `FILE`, path `NexusTK/map/`; reconstructable/emitter/position/Nested/formal channels are N/A because this by-file header has none. | strong | Existing class contract and physical file header. Callback receipt: physical SHA256 D21C51C88C995A91A99DF87889C7A4779D346F5200F639453A905B72355C4398; validator 000000022265 exit 0, ok 1. | by-file/LightingObjectPane.md | incorporate | applied |
| [x] | C23D-031 | 00023D | Move StaticObjectPane declaration to H under exact class metadata. Implementation detail: Apply Section 22 H payload; preserve `90/92`, owner `0000O6`, reconstructable true, emitter `0000O6`, blank position, schema-absent/N/A Nested; CPP stays nonblank and H changes blank to nonblank. | very strong | Complete-type need and physical class header. Callback receipt: physical SHA256 F2A760FB7FB214404C06D159AD0686BB88023D6BF22163A4AB0563EC93DF2F05; validator 000000022277 exit 0, ok 1. | by-class/StaticObjectPane.md | incorporate | applied |
| [x] | C23D-032 | 00023D | Synchronize StaticObjectPane file route under exact file metadata. Implementation detail: Add header/ObjectList consumer prose; preserve `90/91`, owner `FILE`, path `NexusTK/map/`; reconstructable/emitter/position/Nested/formal channels are N/A because this by-file header has none. | strong | Existing class contract and physical file header. Callback receipt: physical SHA256 2E7FACC0A3D6AFBFF68E455EEBA7F4BD400E54D928465041633A513D851DAFC0; validator 000000022279 exit 0, ok 1. | by-file/StaticObjectPane.md | incorporate | applied |
| [x] | C23D-033 | 00023D | Give tile dimensions external linkage under exact global metadata. Implementation detail: Remove `static`, add H externs; preserve `91/92`, owner `0000L3`, reconstructable true, emitter `0000L3`, blank position, schema-absent/N/A Nested; CPP stays nonblank and H changes blank to nonblank. | very strong | 89/94 consumers and physical global header. Callback receipt: physical SHA256 65F0A9682982680C26C333A454D851058FED3960757AFFA5C0C0C29B1F956B96; validator 000000022280 exit 0, ok 1. | by-global/MapTilePixelDimensions.md | incorporate | applied |
| [x] | C23D-034 | 00023D | Preserve singleton source/storage split and both exact metadata records. Implementation detail: Preserve later valid lifecycle drift: global is `92/96`, owner `0000O7`, reconstructable true, emitter `0000O7`, blank position, schema-absent/N/A Nested, nonblank CPP/blank H; storage is `93/97`, owner `0000SD`, reconstructable false, blank emitter/position, `Nested:0`, blank CPP/H. Add UID00023D prose only. | very strong | Four zero bytes, 13 xrefs, and both physical headers. Callback receipt: later valid drift preserved; current global SHA256 DBC0FB5811C056CBCAD52CEF9088753F3A1FF4E6CFD247CBEE415F06668C4FDE at 92/96 and current storage SHA256 0F6BD0A7DD634AAFC70CE252B1C4E31F876EA67E709E0E8BE782FE850CCEC48A at 93/97 non-emitting; independent supervisor Gate 2A validators 000000022399 and 000000022400 exited 0, ok 1. | by-global/g_pStaticObjImageLib.md; by-memory/0x0069b448-0x0069b44c.g_pStaticObjImageLib.md | incorporate | applied |
| [x] | C23D-035 | 00023D | Pure-rename and narrow-comment target in IDA without type/frame mutation. Implementation detail: Supervisor applied I23D-01 and persisted `ObjectList_RefreshStaticObjectLighting` plus the exact function-regular comment while preserving type, complete frame, range, bytes, callers, and other comment channels. | strong | Primary-supervisor Gate 2B receipt `2026-08-12T11:52:00-04:00`; distinct-session persistence readback passed. | IDA 0x00530d00 | incorporate | applied |
| [x] | C23D-036 | 00023D | Preserve raw MapPane wrapper IDA model as an explicit no-change disposition. Implementation detail: Supervisor verified I23D-02 without defining, renaming, typing, or commenting the raw wrapper. | very strong | Persisted readback: exact raw `0x0050e300-0x0050e317` code/padding, no function/name/type/comments, zero start xrefs. | IDA 0x0050e300 | not-applicable | already-present |
| [x] | C23D-037 | 00023D | Pure-rename and narrow-comment StaticObjImageLib accessor without type/frame mutation. Implementation detail: Supervisor persisted `StaticObjImageLib_GetStaticObjectEntry` and the exact function-regular comment while preserving type, range, bytes, two callers, frame, and other channels. | strong | Primary-supervisor Gate 2B receipt and distinct-session persistence readback. | IDA 0x004dda30 | incorporate | applied |
| [x] | C23D-038 | 00023D | Pure-rename and narrow-comment attached-object getter without type/frame mutation. Implementation detail: Supervisor persisted `ObjectPane_GetAttachedObject` and the exact function-regular comment while preserving type, range, bytes, sole caller, frame, and other channels. | very strong | Primary-supervisor Gate 2B receipt and distinct-session persistence readback. | IDA 0x005376c0 | incorporate | applied |
| [x] | C23D-039 | 00023D | Pure-rename and narrow-comment LightingObjectPane constructor without type/frame mutation. Implementation detail: Supervisor persisted `LightingObjectPane_Constructor` and the exact function-regular comment while preserving type, range, bytes, callers, complete frame, and other channels. | strong | Primary-supervisor Gate 2B receipt and distinct-session persistence readback. | IDA 0x0053c5e0 | incorporate | applied |
| [x] | C23D-040 | 00023D | Preserve singleton IDA storage as an explicit no-change disposition. Implementation detail: Supervisor verified I23D-06 without materializing, renaming, typing, or commenting the current head. | very strong | Persisted readback: one-byte `unk_69B448` unknown head, no type/code/data, four zero bytes, 13 xrefs, blank comments. | IDA 0x0069b448 | not-applicable | already-present |
| [x] | C23D-041 | 00023D | Apply only ten exact occupied-row stack renames. Implementation detail: Supervisor persisted I23D-07A..J with all 17 offsets, widths, types, order, and protected names unchanged. | strong | Dry runs passed without collision; distinct-session frame readback reproduced the ten semantic names and seven protected rows. | IDA 0x00530d00 stack frame | incorporate | applied |
| [x] | C23D-042 | 00023D | Repair three narrow comments and preserve every protected entity. Implementation detail: Supervisor persisted the I23D-08A function-regular map-position comment and I23D-08B/C address-regular tile-global comments while preserving all protected names/types/frames/comments/bytes/xrefs. | strong | Primary-supervisor Gate 2B receipt; exact channel and distinct-session readbacks passed. | IDA target dependencies | incorporate | applied |
| [x] | C23D-043 | 00023D | Raise justified target score without crossing 95/95 while preserving exact metadata. Implementation detail: Set `85/90 -> 94/93`; preserve owner `00009Q`, reconstructable true, emitter `00009Q`, blank position, `Nested:0`; CPP becomes nonblank and H remains blank. | strong | Complete behavior/source route; route-negative confidence cap. Callback receipt: physical SHA256 E198B1ADB57021B731D855C6DB3249680846D5697AD9A6DF5B2D97BADDEDDFCF; validator 000000022245 exit 0, ok 1. | by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md | incorporate | applied |
| [x] | C23D-044 | 00023D | Preserve corrected historical intensity rationale. Implementation detail: Move `lightIntensity` into explicit superseded-history wording rather than deleting it. | strong | Rule 26 no-loss correction policy. Callback receipt: physical sweep confirms current formal/prose uses lightImageIndex and every retained lightIntensity occurrence is explicitly superseded or rejected history. | by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md; by-class/ObjectList.md; by-file/ObjectList.md; by-memory/0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore.md; by-type/by-struct/StaticObjEntry.md; by-class/StaticObjImageLib.md; by-file/StaticObjImageLib.md; by-memory/0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster.md; by-memory/0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile.md; by-class/LightingObjectPane.md; by-file/LightingObjectPane.md; by-class/StaticObjectPane.md; by-file/StaticObjectPane.md; by-global/MapTilePixelDimensions.md; by-global/g_pStaticObjImageLib.md; by-memory/0x0069b448-0x0069b44c.g_pStaticObjImageLib.md | historicalize | applied |
| [x] | C23D-045 | 00023D | Replace the stale UID00023D target manual coverage row in place. Implementation detail: Supervisor applied the exact Section 28 UID00023D replacement once with no insertion or deletion. | strong | Command `000000022765` exit 0, ok 1; exact row reread; by-memory closure SHA256 `F4F52F9AFD0147986EDF38F26666553A7E792CE36027CFDA4F15EC56E3EC0BBD`. | by-memory/-coverage-report.md UID00023D | incorporate | applied |
| [x] | C23D-046 | 00023D | Validate every changed ordinary page during callback. Implementation detail: Run one scoped file validator with `--apply --no-generated-refresh --queue-timeout 240`. | very strong | Skill callback contract. Callback receipt: all 16 ordinary destinations passed scoped validation with generated refresh disabled, and narrow class remediation validator 000000022436 also exited 0, ok 1 with generated refresh skipped; original command IDs 000000022245, 000000022247, 000000022251, 000000022252, 000000022253, 000000022259, 000000022261, 000000022262, 000000022264, 000000022265, 000000022277, 000000022279, 000000022280, 000000022282, 000000022283, and 000000022284. | by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md; by-class/ObjectList.md; by-file/ObjectList.md; by-memory/0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore.md; by-type/by-struct/StaticObjEntry.md; by-class/StaticObjImageLib.md; by-file/StaticObjImageLib.md; by-memory/0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster.md; by-memory/0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile.md; by-class/LightingObjectPane.md; by-file/LightingObjectPane.md; by-class/StaticObjectPane.md; by-file/StaticObjectPane.md; by-global/MapTilePixelDimensions.md; by-global/g_pStaticObjImageLib.md; by-memory/0x0069b448-0x0069b44c.g_pStaticObjImageLib.md | incorporate | applied |
| [x] | C23D-047 | 00023D | Verify regenerated ObjectList source and required headers. Implementation detail: Supervisor completed coherent generated refresh/readback after ordinary validation. | strong | Command `000000022770`: ObjectList.cpp SHA `83417F5E7CA213DD2122B480F60110B92375642AFAC4CB5F08B35807C9C4DCB2`, ObjectList.h SHA `ECEE3FDD26130BA9B99EA7B8B5A61A38602F0D32BE2DF1DAB8CD624FFC3EDE98`; exact body/declarations/includes and no raw target labels. | auto-generated/NexusTK/map/ObjectList.cpp and sibling headers | incorporate | applied |
| [x] | C23D-048 | 00023D | Protect non-target structure, Gate 2B persistence, and lifecycle boundaries. Implementation detail: Agent boundaries, no split/new UID, canonical authority, durable backup, one-save boundary, protected readbacks, fresh-session persistence, and validator-owned lifecycle authority were all observed. | very strong | Gate 2B canonical/post-save proof plus validator-owned historical commands `000000022771` and `000000022775`; current lifecycle truth remains path/history authoritative. | Project state and supervisor Gate 2B boundary | not-applicable | already-present |
| [x] | C23D-049 | 00023D | Replace the stale ObjectList class manual coverage row in place. Implementation detail: Supervisor applied the exact UID00009Q Section 28 row once with no insertion/deletion. | very strong | Command `000000022766` exit 0, ok 1; exact row reread; by-class closure SHA `8289C8590BD6AA470CC4FDC056C1D0302903FC197581A3ACB2B85CF7C5E4511C`. | by-class/-coverage-report.md UID00009Q | incorporate | applied |
| [x] | C23D-050 | 00023D | Replace the stale ObjectList file manual coverage row in place. Implementation detail: Supervisor applied the exact UID0000M4 Section 28 row once with no insertion/deletion. | very strong | Command `000000022767` exit 0, ok 1; exact row reread; by-file closure SHA `DA924F99DFAA33578DEF3A5A320B7BD088682007A0560337722FAD3D54FDF387`. | by-file/-coverage-report.md UID0000M4 | incorporate | applied |
| [x] | C23D-051 | 00023D | Replace the under-detailed MapPane aggregate manual coverage row in place. Implementation detail: Supervisor applied the exact UID00037Y Section 28 row once with no insertion/deletion. | very strong | Command `000000022765` exit 0, ok 1; exact row reread; by-memory closure SHA `F4F52F9AFD0147986EDF38F26666553A7E792CE36027CFDA4F15EC56E3EC0BBD`. | by-memory/-coverage-report.md UID00037Y | incorporate | applied |
| [x] | C23D-052 | 00023D | Replace the stale StaticObjEntry manual coverage row in place. Implementation detail: Supervisor applied the exact UID0001W8 Section 28 row once with no insertion/deletion. | very strong | Command `000000022768` exit 0, ok 1; exact row reread; by-struct closure SHA `65023D2F84F1F4F7160947B95B0CF29E09B9A5F224BD477036A9EE57F7E7F937`. | by-type/by-struct/-coverage-report.md UID0001W8 | incorporate | applied |
| [x] | C23D-053 | 00023D | Replace the stale StaticObjImageLib class manual coverage row in place. Implementation detail: Supervisor applied the exact UID0000E2 Section 28 row once with no insertion/deletion. | very strong | Command `000000022766` exit 0, ok 1; exact row reread; by-class closure SHA `8289C8590BD6AA470CC4FDC056C1D0302903FC197581A3ACB2B85CF7C5E4511C`. | by-class/-coverage-report.md UID0000E2 | incorporate | applied |
| [x] | C23D-054 | 00023D | Replace the stale StaticObjImageLib file manual coverage row in place. Implementation detail: Supervisor applied the exact UID0000O7 Section 28 row once with no insertion/deletion. | very strong | Command `000000022767` exit 0, ok 1; exact row reread; by-file closure SHA `DA924F99DFAA33578DEF3A5A320B7BD088682007A0560337722FAD3D54FDF387`. | by-file/-coverage-report.md UID0000O7 | incorporate | applied |
| [x] | C23D-055 | 00023D | Replace the stale StaticObjImageLib local-cluster manual coverage row in place. Implementation detail: Supervisor applied the exact UID00017H Section 28 row once with no insertion/deletion. | very strong | Command `000000022765` exit 0, ok 1; exact row reread; by-memory closure SHA `F4F52F9AFD0147986EDF38F26666553A7E792CE36027CFDA4F15EC56E3EC0BBD`. | by-memory/-coverage-report.md UID00017H | incorporate | applied |
| [x] | C23D-056 | 00023D | Replace the under-detailed MapPane creator manual coverage row in place. Implementation detail: Supervisor applied the exact UID0003TI Section 28 row once with no insertion/deletion. | very strong | Command `000000022765` exit 0, ok 1; exact row reread; by-memory closure SHA `F4F52F9AFD0147986EDF38F26666553A7E792CE36027CFDA4F15EC56E3EC0BBD`. | by-memory/-coverage-report.md UID0003TI | incorporate | applied |
| [x] | C23D-057 | 00023D | Replace the stale LightingObjectPane class manual coverage row in place. Implementation detail: Supervisor applied the exact UID000075 Section 28 row once with no insertion/deletion. | very strong | Command `000000022766` exit 0, ok 1; exact row reread; by-class closure SHA `8289C8590BD6AA470CC4FDC056C1D0302903FC197581A3ACB2B85CF7C5E4511C`. | by-class/-coverage-report.md UID000075 | incorporate | applied |
| [x] | C23D-058 | 00023D | Replace the stale LightingObjectPane file manual coverage row in place. Implementation detail: Supervisor applied the exact UID0000KO Section 28 row once with no insertion/deletion. | very strong | Command `000000022767` exit 0, ok 1; exact row reread; by-file closure SHA `DA924F99DFAA33578DEF3A5A320B7BD088682007A0560337722FAD3D54FDF387`. | by-file/-coverage-report.md UID0000KO | incorporate | applied |
| [x] | C23D-059 | 00023D | Replace the under-detailed StaticObjectPane class manual coverage row in place. Implementation detail: Supervisor applied the exact UID0000E1 Section 28 row once with no insertion/deletion. | very strong | Command `000000022766` exit 0, ok 1; exact row reread; by-class closure SHA `8289C8590BD6AA470CC4FDC056C1D0302903FC197581A3ACB2B85CF7C5E4511C`. | by-class/-coverage-report.md UID0000E1 | incorporate | applied |
| [x] | C23D-060 | 00023D | Replace the under-detailed StaticObjectPane file manual coverage row in place. Implementation detail: Supervisor applied the exact UID0000O6 Section 28 row once with no insertion/deletion. | very strong | Command `000000022767` exit 0, ok 1; exact row reread; by-file closure SHA `DA924F99DFAA33578DEF3A5A320B7BD088682007A0560337722FAD3D54FDF387`. | by-file/-coverage-report.md UID0000O6 | incorporate | applied |
| [x] | C23D-061 | 00023D | Replace the stale MapTilePixelDimensions manual coverage row in place. Implementation detail: Supervisor applied the exact UID0000T7 Section 28 row once with no insertion/deletion. | very strong | Command `000000022769` exit 0, ok 1; exact row reread; by-global closure SHA `5913D983A1ABB08FDF9CF6BD7DEC31708390FF487932936FAA1C862E80A971A1`. | by-global/-coverage-report.md UID0000T7 | incorporate | applied |
| [x] | C23D-062 | 00023D | Replace the stale g_pStaticObjImageLib manual coverage row in place. Implementation detail: Supervisor applied the exact UID0000SD Section 28 row once with no insertion/deletion. | very strong | Command `000000022769` exit 0, ok 1; exact row reread; by-global closure SHA `5913D983A1ABB08FDF9CF6BD7DEC31708390FF487932936FAA1C862E80A971A1`. | by-global/-coverage-report.md UID0000SD | incorporate | applied |
| [x] | C23D-063 | 00023D | Replace the stale singleton-storage manual coverage row in place. Implementation detail: Supervisor applied the exact UID0001PP Section 28 row once with no insertion/deletion. | very strong | Command `000000022765` exit 0, ok 1; exact row reread; by-memory closure SHA `F4F52F9AFD0147986EDF38F26666553A7E792CE36027CFDA4F15EC56E3EC0BBD`. | by-memory/-coverage-report.md UID0001PP | incorporate | applied |

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000022771","destination_path":"executed-b-agent-research/B003/00023D-ObjectListStaticObjectLightingSyncHelper-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/00023D-ObjectListStaticObjectLightingSyncHelper-source-quality.md","timestamp":"2026-08-12T11:57:52-04:00","uid":"00023D"} -->
<!-- {"agent":"B003","command_id":"000000022775","destination_path":"tools/leaser/Agents/Agent-B003/research/00023D-ObjectListStaticObjectLightingSyncHelper-source-quality.md","details":"report returned to active agent research for rework","event":"de-executed-for-rework","source_path":"executed-b-agent-research/B003/00023D-ObjectListStaticObjectLightingSyncHelper-source-quality.md","timestamp":"2026-08-12T12:15:16-04:00","uid":"00023D"} -->
<!-- {"agent":"B003","command_id":"000000022776","destination_path":"executed-b-agent-research/B003/00023D-ObjectListStaticObjectLightingSyncHelper-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/00023D-ObjectListStaticObjectLightingSyncHelper-source-quality.md","timestamp":"2026-08-12T12:34:00-04:00","uid":"00023D"} -->
<!-- {"agent":"B003","command_id":"000000023052","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00023D-ObjectListStaticObjectLightingSyncHelper-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/00023D-ObjectListStaticObjectLightingSyncHelper-source-quality.md","timestamp":"2026-08-13T03:35:41-04:00","uid":"00023D"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
