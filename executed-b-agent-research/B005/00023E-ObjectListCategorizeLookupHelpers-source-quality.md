** TARGET-REPORT-UID:00023E **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# 00023E ObjectListCategorizeLookupHelpers Source-Quality Report


## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00023E] as an `ObjectList` aggregate/container over exact child pages, refresh the aggregate evidence with the current IDA MCP session `1f24c222`, and raise the target from `85/88` to `88/90`.
- Final disposition: source-bearing aggregate route remains `CANONICAL_OWNER:00009Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009Q`; the aggregate formal C++ remains the existing child-routing marker, not a duplicate method body.
- Required action after supervisor Gate 1 acceptance: update only the target by-memory aggregate unless the supervisor wants optional support-doc touchups; class/file/layout support docs already contain the child-level source names and caveats at same-or-greater detail.
- Confidence: strong for range, child inventory, ObjectList owner/emitter, and no-duplicate-body disposition; confidence stays below final audit because exact original spelling for some child APIs, enum labels, and tier field names remains inferred.

## Target

- Target UID: `00023E`
- Target path: `by-memory/0x00531480-0x00532530.ObjectListCategorizeLookupHelpers.md`
- Target name: `ObjectListCategorizeLookupHelpers`
- Tracker row/source: `auto-generated/-ag-research-tracker.md`, `## by-memory` -> `### Not-Covered Files - Reconstructable`, row `00023E`, current `85/88`, combined `86.5`, reconstructable `true`, `Reports:0`.
- Current queue classification: not-covered reconstructable by-memory item, report-only Medium assignment.
- Current metadata: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:00009Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009Q`, formal aggregate C++ block with `[[CHILDREN]]`.
- Direct owner/emitter path: [UID:00009Q] `by-class/ObjectList.md` -> [UID:0000M4] `by-file/ObjectList.md`, `NexusTK/map/ObjectList.cpp`.
- Current oddity to repair: `Nested:-4` is stale/inconsistent for an aggregate that now has seven exact child pages; recommend `Nested:7`.

## Current Target State

- The target already describes a real ObjectList helper cluster from `0x00531480` through `0x00532530`, not one monolithic source method.
- Existing formal C++ is correct in shape:

```cpp
// ObjectList categorize and lookup aggregate; exact child pages own emitted method bodies.
[[CHILDREN]]
```

- Exact children already own emitted bodies or raw-helper first-draft bodies:
  - [UID:0002C8] `0x00531480-0x00531498.ObjectListOriginInitializedCheck.md` emits `ObjectList::HasValidGridOrigin()`, `88/91`.
  - [UID:0002C9] `0x005314a0-0x00531c10.ObjectListTypeDispatchInsertCategorize.md` emits `ObjectList::AddObjectPane(ObjectPane *object)`, `88/90`.
  - [UID:0002CA] `0x00531c10-0x00532180.ObjectListTypeDispatchRemove.md` emits `ObjectList::RemoveObjectPane(ObjectPane *object)`, `88/90`.
  - [UID:0002CB] `0x00532180-0x005322d0.ObjectListEncodedKeyResolve.md` emits `ObjectList::ResolveObjectListKey(unsigned int key)`, `88/91`.
  - [UID:0002CC] `0x005322d0-0x00532370.ObjectListTypeSpecificIndexDispatch.md` emits `ObjectList::GetTypedObjectKey(ObjectPane *object)`, `90/90`.
  - [UID:0002CD] `0x00532370-0x00532443.ObjectListFindByObjectId.md` emits `ObjectList::FindByObjectId(int objectId)`, `90/91`.
  - [UID:0002CE] `0x00532450-0x00532530.ObjectListTypeIndexExistsSwitchHelper.md` emits `ObjectList::ContainsTypedObject(ObjectPane *object)`, `88/89`.
- Existing support docs checked: `by-class/ObjectList.md`, `by-file/ObjectList.md`, and `by-type/by-struct/ObjectListLayout.md` already record the child-level source names, ObjectList route, raw `ContainsTypedObject` no-route caveat, `MapPaneSpatialIndex` rejected/search-alias status, and field/tier caveats.
- Existing open issues are now aggregate-level documentation freshness issues, not child blockers: target score has not caught up to the accepted child reports; `Nested:-4` is stale; current IDA session evidence is absent from the aggregate; original spellings for some source-facing child APIs and enum/tier labels remain inferred.

## Evidence Checked

- Required local instructions:
  - `tools/leaser/Agents/Agent-B005/goal.md`
  - `E:/NTK/GhidraBridge/.codex/skills/ntk-b-agent-workflow/SKILL.md`
  - `E:/NTK/GhidraBridge/.codex/skills/ntk-b-agent-workflow/references/b-agent-research-and-implementation-workflow.md`
  - `E:/NTK/GhidraBridge/.codex/skills/ntk-b-agent-workflow/references/score-blocker-audit-standard.md`
  - `E:/NTK/GhidraBridge/.codex/skills/ntk-b-agent-workflow/references/b-agent-report-template.md`
  - `by-structure.md`, especially IDA MCP Output Discipline and by-memory reconstruction/aggregate rules.
- Target and support docs:
  - `by-memory/0x00531480-0x00532530.ObjectListCategorizeLookupHelpers.md`
  - `by-memory/0x00531480-0x00531498.ObjectListOriginInitializedCheck.md`
  - `by-memory/0x005314a0-0x00531c10.ObjectListTypeDispatchInsertCategorize.md`
  - `by-memory/0x00531c10-0x00532180.ObjectListTypeDispatchRemove.md`
  - `by-memory/0x00532180-0x005322d0.ObjectListEncodedKeyResolve.md`
  - `by-memory/0x005322d0-0x00532370.ObjectListTypeSpecificIndexDispatch.md`
  - `by-memory/0x00532370-0x00532443.ObjectListFindByObjectId.md`
  - `by-memory/0x00532450-0x00532530.ObjectListTypeIndexExistsSwitchHelper.md`
  - `by-class/ObjectList.md`
  - `by-file/ObjectList.md`
  - `by-type/by-struct/ObjectListLayout.md`
- Tracker/state evidence:
  - `auto-generated/-ag-research-tracker.md` row `00023E`: `85/88`, combined `86.5`, reconstructable `true`, reports `0`.
- Existing report search terms:
  - `00023E`, `0x00531480`, `0x00532530`, `ObjectListCategorizeLookupHelpers`, `ObjectListTypeDispatchInsertCategorize`, `ObjectListTypeIndexExistsSwitchHelper`, `ContainsTypedObject`, `AddObjectPane`, `RemoveObjectPane`, `ResolveObjectListKey`, `GetTypedObjectKey`, `FindByObjectId`.
- Relevant executed/archived report matches:
  - B005 reports for [UID:0002C8], [UID:0002C9], and [UID:0002CB].
  - B008 report for [UID:0002CA].
  - B006 reports for [UID:0002CC] and [UID:0002CE].
  - B009 report for [UID:0002CD].
  - B010 [UID:00023F] extended ObjectList helper-family report.
  - B012 [UID:0001D2] ObjectList accessor-method/MapPaneSpatialIndex reclassification report.
  - B011 [UID:00042C] MapPane cleanup report, as consumer evidence for `ObjectList::RemoveObjectPane`.
- Current IDA MCP evidence, all using active database session `1f24c222` from `idb_list`, not stale session names:
  - JSON-RPC `initialize` id `1`: protocol `2025-06-18`.
  - `tools/list` id `2`: schema contains `server_health`, `idb_list`, `lookup_funcs`, `xrefs_to`, `xref_query`, `analyze_function`, `decompile`, `disasm`, `get_bytes`, and `callees`.
  - `idb_list` id `3`: active session `1f24c222`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_analyzing:false`, worker pid `13460`.
  - `server_health` id `10`: `status:ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.
  - `lookup_funcs` id `11`: confirmed modeled starts and sizes for `0x00531480` `0x18`, `0x005314a0` `0x73c`, `0x00531c10` `0x532`, `0x00532180` `0x11e`, `0x005322d0` `0x71`, `0x00532370` `0xd3`, and successor `0x00532530` `0x4`; confirmed `0x00531473`, `0x00531498`, `0x00532443`, and `0x00532450` are not IDA functions.
  - `xrefs_to` ids `12` and `13`: current code xref counts are `1` to `0x00531480`, `18` to `0x005314a0`, `12` to `0x00531c10`, `6` to `0x00532180`, `6` to `0x005322d0`, `33` to `0x00532370`, and `0` to `0x00532450`.
  - `analyze_function` ids `20` through `24`: reconfirmed switch/callee/caller facts for `sub_5314A0`, `sub_531C10`, `sub_532180`, `sub_5322D0`, and `sub_532370`.
  - `disasm` id `25`: bounded `max_instructions=80` at `0x00532450` confirmed a raw prologue, `ObjectPane::m_objectType` byte load at `+0xf8`, nine-case switch, calls to `sub_535DF0`, `sub_535EC0`, `sub_535F90`, `sub_535FD0`, `sub_536010`, `sub_5360E0`, `sub_5361B0`, `sub_5361F0`, and `sub_536230`, each comparing against `0xffffffff` and returning `setnz`; default returns false; table starts at `0x0053250c`.
  - `xrefs_to` id `27`: switch-table data refs confirmed to `0x00531bdc`, `0x00532144`, `0x005322a0`, `0x00532344`, and `0x0053250c`.
  - `get_bytes` id `28`: schema-current `regions` call for `0x00532443` size `237` confirmed thirteen `0xcc` bytes, raw helper body bytes, NOP alignment, and the nine-dword table through `0x00532530`.
- Failed/retried MCP check:
  - A prior `get_bytes` call with old `addr`/`size` schema failed with `missing required parameters: ['regions']`; it was immediately retried as a bounded schema-current `regions` call and succeeded. The failed call was bounded, not broad.

## Positive Evidence Summary

- Current IDA session `1f24c222` confirms the exact aggregate starts, child starts, successor start, and IDA-missed `0x00532450` status.
- Current xrefs match the child docs: the aggregate contains live/called ObjectList helpers plus one retained raw boolean helper with no direct static xrefs.
- Current `analyze_function` facts match existing accepted child conclusions:
  - `0x005314a0` is a 12-case typed add/insert dispatcher with 18 callers and helper callees `sub_5374D0`, `sub_4B7C50`, and `sub_4B7E80`.
  - `0x00531c10` is a 12-case typed remove dispatcher with 12 xrefs, the same position/bounds helpers, `sub_537210`, and List virtual access.
  - `0x00532180` decodes an ObjectList key through `sub_535CE0`, dispatches 10 cases, and returns object pointers from selected lists.
  - `0x005322d0` dispatches `ObjectPane::m_objectType` cases `0..8` to the typed encoded-key helper family and returns `0xffffffff` by default.
  - `0x00532370` scans ObjectList storage lists and compares object offset `+0xfc`, matching `FindByObjectId`.
- Current raw disassembly and bytes for `0x00532450` support the accepted `ContainsTypedObject` predicate and its confidence cap: real source-shaped code, no IDA function object, no current xrefs to the helper start.
- [UID:00009Q] `ObjectList`, [UID:0000M4] `ObjectList`, and [UID:0001VG] `ObjectListLayout` already align with the ObjectList route and child-level names. No current support doc contradicts the aggregate recommendation.
- The existing aggregate `[[CHILDREN]]` C++ marker is the correct source-emission mechanism under by-structure rules: child pages own actual method bodies; the aggregate should not duplicate them.

## IDA MCP Facts

- Availability/provenance: MCP endpoint `http://127.0.0.1:13337/mcp`; active database `1f24c222`; health `ok`; `auto_analysis_ready:true`; `hexrays_ready:true`; imagebase `0x400000`.
- Function/range facts:
  - `0x00531480`: `sub_531480`, size `0x18`.
  - `0x005314a0`: `sub_5314A0`, size `0x73c`.
  - `0x00531c10`: `sub_531C10`, size `0x532`.
  - `0x00532180`: `sub_532180`, size `0x11e`.
  - `0x005322d0`: `sub_5322D0`, size `0x71`.
  - `0x00532370`: `sub_532370`, size `0xd3`.
  - `0x00532450`: not an IDA-modeled function, but bounded disassembly shows a full function-shaped helper.
  - `0x00532530`: successor `sub_532530`, size `0x4`.
- Xref facts:
  - `HasValidGridOrigin`: one caller at `0x00505955`.
  - `AddObjectPane`: 18 code xrefs.
  - `RemoveObjectPane`: 12 code xrefs.
  - `ResolveObjectListKey`: six code xrefs in MapPane traversal wrappers.
  - `GetTypedObjectKey`: six code xrefs in the paired MapPane traversal wrappers.
  - `FindByObjectId`: 33 code xrefs across MapPane/update/timer consumers.
  - `ContainsTypedObject`: zero direct xrefs to `0x00532450`.
- Data/table facts:
  - Insert table `0x00531bdc` has data xref from `0x005314d0`.
  - Remove table `0x00532144` has data xref from `0x00531c43`.
  - Resolve table `0x005322a0` has data xref from `0x005321aa`.
  - Typed-key table `0x00532344` has data xref from `0x005322e2`.
  - Raw predicate table `0x0053250c` has data xref from `0x00532466`.
- Negative IDA facts:
  - `0x00532450` still has no IDA function object and no direct xrefs.
  - No current MCP fact supports moving the aggregate to MapPane or MapPaneSpatialIndex.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00531480-0x00531498` | [UID:0002C8] `by-memory/0x00531480-0x00531498.ObjectListOriginInitializedCheck.md` | `ObjectList::HasValidGridOrigin()` sentinel predicate | TRUE | [UID:00023E] | `88/91` | Exact child emits formal body. |
| `0x00531498-0x005314a0` | [UID:0000VN] `by-memory/-ignored.md` | alignment | FALSE | [UID:00023E] context | ignored | Eight `0xcc` bytes. |
| `0x005314a0-0x00531c10` | [UID:0002C9] `by-memory/0x005314a0-0x00531c10.ObjectListTypeDispatchInsertCategorize.md` | `ObjectList::AddObjectPane(ObjectPane *object)` | TRUE | [UID:00023E] | `88/90` | Exact child emits formal body and owns table/alignment. |
| `0x00531c10-0x00532180` | [UID:0002CA] `by-memory/0x00531c10-0x00532180.ObjectListTypeDispatchRemove.md` | `ObjectList::RemoveObjectPane(ObjectPane *object)` | TRUE | [UID:00023E] | `88/90` | Exact child emits formal body and owns table/alignment. |
| `0x00532180-0x005322d0` | [UID:0002CB] `by-memory/0x00532180-0x005322d0.ObjectListEncodedKeyResolve.md` | `ObjectList::ResolveObjectListKey(unsigned int key)` | TRUE | [UID:00023E] | `88/91` | Exact child emits formal resolver body. |
| `0x005322d0-0x00532370` | [UID:0002CC] `by-memory/0x005322d0-0x00532370.ObjectListTypeSpecificIndexDispatch.md` | `ObjectList::GetTypedObjectKey(ObjectPane *object)` | TRUE | [UID:00023E] | `90/90` | Exact child emits formal key-producing body. |
| `0x00532370-0x00532443` | [UID:0002CD] `by-memory/0x00532370-0x00532443.ObjectListFindByObjectId.md` | `ObjectList::FindByObjectId(int objectId)` | TRUE | [UID:00023E] | `90/91` | Exact child emits formal id lookup body. |
| `0x00532443-0x00532450` | [UID:0000VN] `by-memory/-ignored.md` | alignment | FALSE | [UID:00023E] context | ignored | Thirteen `0xcc` bytes. |
| `0x00532450-0x00532530` | [UID:0002CE] `by-memory/0x00532450-0x00532530.ObjectListTypeIndexExistsSwitchHelper.md` | `ObjectList::ContainsTypedObject(ObjectPane *object)` retained raw predicate | TRUE | [UID:00023E] | `88/89` | Exact child emits formal predicate body; confidence capped by no inbound static route and no IDA function object. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00531480` | one caller from `0x00505955` in `sub_505940` | MapPane reindex guard consumes ObjectList origin state; consumer does not own helper. |
| `0x005314a0` | 18 code xrefs, including `sub_505940`, `sub_505E00`, `sub_50DFA0`, `sub_512D60`, `sub_530D00` | Active add/categorize dispatcher. |
| `0x00531c10` | 12 code xrefs, including MapPane create/remove/update paths | Active remove dispatcher. |
| `0x00532180` | six paired traversal-wrapper xrefs | Resolves moved ObjectList keys to `ObjectPane *`. |
| `0x005322d0` | six paired traversal-wrapper xrefs | Produces typed ObjectList key before `MoveKeyTo...` helpers. |
| `0x00532370` | 33 code xrefs | Broad MapPane/object-update id lookup consumer surface. |
| `0x00532450` | zero direct xrefs | Retained/source-shaped raw predicate; no route does not prove a different owner. |
| `0x0053250c` | data xref from `0x00532466` | Raw predicate switch table belongs to the `0x00532450` child, not successor accessors. |

## Ranked Ownership Analysis

### 1. ObjectList Class [UID:00009Q]

- Evidence for: every source-bearing child reads/writes ObjectList layout fields, dispatches ObjectPane entries through ObjectList storage tiers, or transforms ObjectList keys; support docs and current MCP agree the cluster bridges ObjectList lifecycle to ObjectList accessors and extended helper families.
- Evidence against: many callers are MapPane-facing and some helper names are inferred, but caller/consumer xrefs alone do not outweigh receiver/layout ownership.
- Decision: keep as direct canonical owner and emitter route.

### 2. ObjectList File [UID:0000M4]

- Evidence for: correct source root is `NexusTK/map/ObjectList.cpp`; class emitter chain surfaces through this file; file doc already lists this helper cluster.
- Evidence against: by-structure prefers the direct class owner for class methods/helpers when the class route clears the gate.
- Decision: keep as source module through the ObjectList class, not direct `CANONICAL_OWNER`.

### 3. MapPane / MapPaneSpatialIndex

- Evidence for: MapPane is a major consumer of object lookup, add/remove, traversal, and id-lookup behavior; legacy docs/search aliases mentioned `MapPaneSpatialIndex`.
- Evidence against: current B012 reclassification rejects `MapPaneSpatialIndex` as source-facing owner; ObjectList owns the storage layout, constructor/destructor lifecycle, accessors, key helpers, and helper bodies; no child requires MapPane receiver state for ownership.
- Decision: reject as owner. Preserve as consumer/search-alias context only where existing support docs already do.

### 4. No-Owner / Non-Emitting

- Evidence for: `0x00532450` has no current inbound xrefs and no IDA function object.
- Evidence against: the aggregate and six other child starts are live ObjectList source, and the raw helper is exact source-shaped ObjectList code with accepted child C++; by-structure supports reconstructable retained code with confidence caveats.
- Decision: reject. The aggregate remains owned/emitting through ObjectList with child routing.

## Source Placement

- Recommended source placement: `ObjectList` class methods/helpers emitted through `NexusTK/map/ObjectList.cpp`.
- Why this placement fits: constructor/destructor/layout/accessor docs define ObjectList storage fields used by the children; the cluster sits between ObjectList lifecycle (`0x00530ee0-0x00531473`) and ObjectList accessors/sweeps (`0x00532530-0x00532f67`); the later extended helper family continues the same ObjectList key/tier system.
- Rejected placements:
  - `MapPane.cpp`: consumers call into ObjectList but do not own the storage or key encoding.
  - `MapPaneSpatialIndex`: stale/generated compatibility alias, rejected by current accessor-method reclassification.
  - file-static free helper route: possible for exact original access labels of some children, but current receiver shape and support docs are stronger for ObjectList member-style documentation.
- Remaining source-placement uncertainty: exact public/private access labels and original names for some child helper APIs are not symbol-proven; this limits confidence but does not change the aggregate owner/emitter.

## Range / Split / Padding / Reclassification Analysis

- No new split is required. The aggregate already has exact children for every source-bearing function/table unit.
- Current IDA MCP confirms no hidden modeled function at `0x00531473`, `0x00531498`, `0x00532443`, or `0x00532450`; `0x00532450` remains raw function-shaped code.
- Padding/table distinctions to preserve:
  - `0x00531498-0x005314a0`: eight `0xcc` bytes before add dispatcher.
  - `0x00531bdc`: insert jump table, data ref from `0x005314d0`.
  - `0x00532144`: remove jump table, data ref from `0x00531c43`.
  - `0x005322a0`: resolver jump table, data ref from `0x005321aa`.
  - `0x00532344`: typed-key jump table, data ref from `0x005322e2`.
  - `0x00532443-0x00532450`: thirteen `0xcc` bytes before raw predicate.
  - `0x0053250c-0x00532530`: raw predicate jump table, data ref from `0x00532466`.
- Reclassification recommendation: reclassify stale aggregate `Nested:-4` to `Nested:7` because seven exact child pages now own the source-bearing subranges. Do not count ignored padding as source children.
- Parent/container impact: the parent aggregate should stay reconstructable because it is the ObjectList source-bearing grouping/emitter route for child bodies; its own formal block should remain a child marker only.

## Negative Evidence Summary

- No split/range issue was found. Current `lookup_funcs`, table xrefs, bounded raw disassembly, and byte evidence confirm the existing child boundaries and successor at `0x00532530`.
- No no-owner/non-emitting route is supported. Six modeled child starts are live ObjectList code; the raw `0x00532450` helper is source-shaped, already has accepted child C++, and negative xrefs only cap liveness confidence.
- Raw `0x00532450` no-route evidence does not apply to the whole aggregate. It applies only to [UID:0002CE], where it is already preserved as a confidence cap; it does not justify removing ObjectList owner/emitter from [UID:00023E].
- MapPane ownership was checked and rejected. MapPane callers are consumers of ObjectList storage and key helpers; no current evidence shows this cluster belongs to a MapPane receiver or MapPane source module.
- `MapPaneSpatialIndex` ownership was checked and rejected. Current B012/source docs treat it as a stale compatibility/search alias; [UID:0001D2] is now exact ObjectList accessor methods, and [UID:00023E] remains an ObjectList helper cluster.
- File-only ownership was checked and rejected as the direct owner. `by-file/ObjectList.md` is the source module, but by-structure requires the direct class owner when the helper belongs to ObjectList and the class route clears the gate.
- Duplicating child C++ into the aggregate was checked and rejected. By-memory aggregate rules prohibit parent C++ from containing outside child ranges; `[[CHILDREN]]` is the correct source-output shape.
- Collapsing [UID:0002CE] into a source call to [UID:0002CC] was checked and rejected for exact by-memory reconstruction. The binary contains a duplicate switch body at `0x00532450`; a later high-level source-factoring pass may reason about original source, but the exact child must preserve the observed body.
- Broad generic child-slot names were checked and rejected where better accepted names exist. The target should preserve `HasValidGridOrigin`, `AddObjectPane`, `RemoveObjectPane`, `ResolveObjectListKey`, `GetTypedObjectKey`, `FindByObjectId`, and `ContainsTypedObject`, while recording that final original spellings remain inferred.
- Remaining uncertainty: exact original method/API spelling, access labels, full `ObjectPaneType` enum names, and final semantic tier names are not symbol-proven. This affects confidence and prevents final-audit scores, but it does not block the aggregate score raise or child marker C++ disposition.

## Heuristic / Inference Reanalysis And Validation

- Aggregate source shape: best interpreted as an ObjectList method/helper island in `ObjectList.cpp`, not as one original function body. This inference is validated by exact child starts, jump tables, padding, source-owned receiver fields, and the `[[CHILDREN]]` emission pattern.
- Source-facing names: accepted child reports now provide strong inferred names. The aggregate should not revive stale labels such as `InsertByType`, `ObjectListTypeIndexExistsSwitchHelper` as a preferred API, `MapPaneSpatialIndex`, or generic `TypeSpecificIndexDispatch` except as search/history labels.
- Raw helper liveness: the `0x00532450` no-route fact is real and must remain visible. It is not a score blocker for this aggregate because the raw child carries the exact caveat and source body; the parent only routes children.
- Field/type names: structural ObjectList fields and `ObjectPane::m_objectType`/`m_objectId` are strong enough for child docs and aggregate summary. Full enum labels and some semantic tier names remain outside this aggregate pass.
- Score blocker reanalysis: the current `85/88` score lags behind accepted child reports and current MCP. The blocker is not ownership or C++; it is stale aggregate evidence/metadata. Updating evidence, score rationale, negative evidence, and `Nested` is implementation-ready.
- Wave2/Wave3 handling: any generated or stale `MapPaneSpatialIndex`/placeholder labels were treated as search aliases only and rejected against current by-doc and MCP evidence.

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion:
  - Target doc already identifies exact children and child-routing formal block.
  - `by-class/ObjectList.md` lists [UID:00023E] as ObjectList helper cluster and records child-level source names.
  - `by-file/ObjectList.md` places the range under `NexusTK/map/ObjectList.cpp`.
  - `by-type/by-struct/ObjectListLayout.md` records the field offsets consumed by the child helpers.
- Existing docs that are stale/incomplete:
  - Target `COMPLETION:85` and `CONFIDENCE:88` do not reflect the current child-source-quality state and active MCP refresh.
  - Target `Nested:-4` conflicts with the seven exact child pages and should be repaired.
  - Target evidence should add the current `1f24c222` MCP session instead of relying only on earlier A/B sessions.
- Generated/coverage state:
  - Generated tracker still reports `Reports:0` for [UID:00023E] before this report.
  - This report does not edit generated tracker/coverage files; supervisor lifecycle execution later owns generated report refresh.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes, but only as an aggregate child-routing marker.
- Recommended exact formal block content to preserve:

```cpp
// ObjectList categorize and lookup aggregate; exact child pages own emitted method bodies.
[[CHILDREN]]
```

- Reason it preserves exact original behavior: all behavior-bearing code lives on exact child pages; this aggregate emits no duplicate source logic and preserves child insertion order.
- Reason it matches plausible original source shape: this range is a clustered ObjectList helper island with method-level children, not one human-written monolithic function.
- Inferred source-facing names used by the aggregate: child pages own `HasValidGridOrigin`, `AddObjectPane`, `RemoveObjectPane`, `ResolveObjectListKey`, `GetTypedObjectKey`, `FindByObjectId`, and `ContainsTypedObject`.
- Reason not to paste child bodies here: by-structure forbids parent aggregate C++ from containing source for outside child ranges; duplicating child C++ would create duplicate emitted methods and range ownership errors.
- Third-party import directive: not applicable; this is NexusTK-owned ObjectList code.

## Recommended Target Doc Changes

- Target path: `by-memory/0x00531480-0x00532530.ObjectListCategorizeLookupHelpers.md`
- Metadata changes:
  - `COMPLETION:85` -> `88`
  - `CONFIDENCE:88` -> `90`
  - Keep `CANONICAL_OWNER:00009Q`
  - Keep `RECONSTRUCTABLE:TRUE`
  - Keep `EMITTER_UIDS:00009Q`
  - Change `Nested:-4` -> `Nested:7`
- C++ disposition:
  - Preserve the existing formal C++ block exactly as the aggregate child-routing marker.
- Evidence/detail changes to incorporate:
  - Add current IDA MCP session `1f24c222` provenance, health, active IDB, lookup facts, xref counts, selected `analyze_function` facts, switch-table data xrefs, bounded raw `0x00532450` disassembly, and schema-current byte check.
  - Update score rationale to explain why the aggregate rises to `88/90` and why it does not exceed `90`.
  - Preserve negative evidence: no aggregate split issue, no no-owner/non-emitting route, MapPane/MapPaneSpatialIndex rejected, file-only owner rejected, child C++ duplication rejected, raw helper no-route caveat isolated to [UID:0002CE].
  - Preserve remaining uncertainty about exact original method/API spellings, object-type enum names, and tier semantic names.
  - Preserve child inventory with seven source-bearing children and two ignored alignment spans.

## Recommended Support Doc Changes

- `by-class/ObjectList.md`: already-present. It already records the [UID:00023E] helper cluster, child source names, raw `ContainsTypedObject` no-route caveat, `MapPaneSpatialIndex` rejected/search-alias status, and support evidence at same-or-greater detail. No required edit for this report.
- `by-file/ObjectList.md`: already-present. It already places `0x00531480-0x00532530` under `NexusTK/map/ObjectList.cpp` and records the child split. No required edit for this report.
- `by-type/by-struct/ObjectListLayout.md`: already-present. It already records field-offset support from [UID:0002C8], [UID:0002C9], [UID:0002CC], [UID:0002CD], and [UID:0002CE]. No required edit for this report.
- Manual coverage/tracker files: do not edit. Generated tracker refresh is supervisor/validator-owned after report execution.

## Score And Metadata Recommendation

- Current score/metadata: `85/88`, `CANONICAL_OWNER:00009Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009Q`, `Nested:-4`, child marker C++.
- Recommended score/metadata: `88/90`, keep owner/reconstructable/emitter, set `Nested:7`, preserve child marker C++.
- Score rationale:
  - Completion `88`: the aggregate has exact current MCP-backed range/child/table evidence, all seven children have accepted source-quality pages and formal child C++, support docs agree on ObjectList placement, and the only material target edits are stale aggregate evidence/score/nested metadata.
  - Confidence `90`: current IDA MCP and support docs strongly validate ownership and split/range decisions. Confidence does not go higher because original public/private source spelling, full object-type enum labels, and semantic tier names remain inferred, and raw [UID:0002CE] still has no current inbound static route.
- Score-improvement attempt:
  - Split/range blocker checked through current `lookup_funcs`, table xrefs, `disasm`, and `get_bytes`: resolved, no new split.
  - Ownership blocker checked through ObjectList class/file/layout docs, xrefs, receiver fields, and stale alias reports: resolved as ObjectList.
  - Raw-helper liveness blocker checked through current xrefs and bounded raw disassembly: remains a child confidence cap only.
  - C++ blocker checked against by-structure aggregate rules: resolved by preserving `[[CHILDREN]]`.
  - Support-doc blocker checked against class/file/layout support docs: no required edits; support already sufficient.
- Metadata fields to change or leave unchanged:
  - Change `COMPLETION`, `CONFIDENCE`, and `Nested`.
  - Leave `CANONICAL_OWNER`, `RECONSTRUCTABLE`, `EMITTER_UIDS`, and formal C++ unchanged.

## Open Questions With Attempted Resolution

- Exact original spellings of some child method/API names: checked current child reports, ObjectList support docs, and IDA names. Best current inferred names are strong enough for documentation and child C++, but not symbol-proven. Score impact: keeps confidence at `90`, not `95+`.
- Final `ObjectPaneType` enum labels: checked child docs and layout support. Numeric cases and structural tier names remain preferred until broader ObjectPane taxonomy proves labels. Score impact: no aggregate blocker; prevents final-audit confidence.
- Raw `0x00532450` liveness: checked current xrefs and bounded disassembly; no direct inbound route remains. Best resolution is retained/source-shaped `ContainsTypedObject` with child-level caveat. Score impact: confidence cap only.
- `Nested:-4`: checked target child inventory. Best resolution is `Nested:7`; no evidence supports a negative child count for the current aggregate.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C001 | [UID:00023E] remains ObjectList-owned and emitted through ObjectList class/file route. | High | Current target/support docs; MCP child receiver/helper facts; ObjectList class/file/layout docs. | Target metadata/status/ownership sections | already-present | already-present |
| C002 | Raise target score from `85/88` to `88/90`. | High | Current MCP `1f24c222` plus accepted child scores and support docs. | Target metadata and Score Rationale | incorporate | applied |
| C003 | Change `Nested:-4` to `Nested:7`. | Medium-high | Seven exact source-bearing child pages under aggregate; two ignored padding spans should not count as source children. | Target metadata/header | incorporate | applied |
| C004 | Preserve aggregate formal C++ as comment plus `[[CHILDREN]]`; do not paste child bodies. | High | by-structure aggregate C++ rules; current child formal bodies. | Target `RECONSTRUCTION_CPP CODE` block | already-present | already-present |
| C005 | Add current MCP session `1f24c222` evidence: health, lookup facts, xref counts, analyze facts, table xrefs, raw disassembly/bytes. | High | JSON-RPC ids `1-3`, `10-13`, `20-28`. | Target Evidence / Raw Code Evidence / Score Rationale | incorporate | applied |
| C006 | Preserve negative evidence rejecting MapPane, MapPaneSpatialIndex, file-only owner, no-owner/non-emitting, and aggregate child-code duplication. | High | Support docs, B012 reclassification, current MCP receiver/range facts, by-structure rules. | Target Ownership Decision / Negative Evidence / Score Rationale | incorporate | applied |
| C007 | Raw `0x00532450` no-route caveat remains child-specific and does not invalidate aggregate ownership/emission. | High | `xrefs_to` id `13`; `disasm` id `25`; [UID:0002CE] child doc. | Target Functions/Evidence/Negative Evidence | incorporate | applied |
| C008 | Support docs need no required edits because they already carry same-or-greater child/source detail. | High | `by-class/ObjectList.md`, `by-file/ObjectList.md`, `by-type/by-struct/ObjectListLayout.md` checked. | Report recommendation only | already-present | already-present |

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation. Proof: user callback states Gate 1 passed for SHA256 `904503459ED19C362ED789D1C4EAF61DA8A861407B7CC57D00A1495C1BDF70C9`.
- [x] Target/support docs to update: target `by-memory/0x00531480-0x00532530.ObjectListCategorizeLookupHelpers.md` updated; support docs `by-class/ObjectList.md`, `by-file/ObjectList.md`, and `by-type/by-struct/ObjectListLayout.md` verified already-present at same-or-greater detail and were not edited.
- [x] Current target state and actual evidence checked recorded: target Evidence section now includes current `1f24c222` MCP provenance, active IDB, health, lookup facts, xref counts, analyze facts, table xrefs, raw disassembly, and schema-current byte evidence.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: C001/C004/C008 marked `already-present`; C002/C003/C005/C006/C007 marked `applied`.
- [x] Metadata/score changes to apply: target metadata now has `COMPLETION:88`, `CONFIDENCE:90`, and `Nested:7`.
- [x] Owner/emitter/reconstructable changes to apply: no change required; target still has `CANONICAL_OWNER:00009Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009Q`.
- [x] Split/rename/new-child changes to apply: no new split, rename, or child page; target inventory preserves seven exact children and ignored alignment spans.
- [x] Source-placement, range/split/padding/reclassification changes to apply or confirm not applicable: target now records ObjectList class/file placement, no split defect, current padding/table facts, and `Nested:7` reclassification.
- [x] First-draft C++ or no-code proof to apply: target formal block preserved as `// ObjectList categorize and lookup aggregate; exact child pages own emitted method bodies.` plus `[[CHILDREN]]`; no child C++ pasted.
- [x] Third-party import directive to apply or confirm not applicable: not applicable.
- [x] Exact target/support doc facts to incorporate at report-level detail: target now carries current MCP facts, child inventory, negative evidence, support already-present proof, score rationale, and remaining uncertainty.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: target now rejects MapPane/MapPaneSpatialIndex, file-only owner, no-owner/non-emitting, aggregate child-body duplication, generic child-slot names, and documents raw no-route caveat as child-specific.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable: target now preserves `MapPaneSpatialIndex` as rejected/stale alias context through negative evidence and support-doc proof.
- [x] Open questions to close or document as evidence-backed unresolved: target score rationale and negative evidence preserve exact original API spelling, enum label, semantic tier, and raw-helper inbound-route uncertainty.
- [x] Validators to run after accepted implementation callback: ran `python .\tools\validator.py --mode file --file by-memory\0x00531480-0x00532530.ObjectListCategorizeLookupHelpers.md --apply --queue-timeout 240`; command `000000004758`, timestamp `2026-07-02T18:05:55-04:00`, exit `0`, `ok:1`.
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text to apply: no manual coverage/tracker edit applied. Validator reported `generated_refresh: deferred`, `generated_refresh_command_id: 000000004758`, `generated_refresh_timestamp: 2026-07-02T18:05:55-04:00`.

## Validator Results

- Target validator command: `python .\tools\validator.py --mode file --file by-memory\0x00531480-0x00532530.ObjectListCategorizeLookupHelpers.md --apply --queue-timeout 240`
- `command_id`: `000000004758`
- `command_timestamp`: `2026-07-02T18:05:55-04:00`
- Exit code: `0`
- Result: `ok: 1`
- Validator updates reported: `completion_update:1`, `confidence_update:1`, `uid_link_insert:4`, `reference_index_add:1`, `stats_row_remove:1`, `projected_stats_update:1`, `stats_rescore_recommended:1`.
- Warnings/errors: none reported for the scoped target validation.
- Generated refresh state: `generated_refresh: deferred`, `generated_refresh_command_id: 000000004758`, `generated_refresh_timestamp: 2026-07-02T18:05:55-04:00`.
- Support validators: not run because no support docs were edited.
- Report lifecycle/archive commands run: none. I did not run `execute_report`, any dry-run/status/probing variant, registry lifecycle command, report archive command, or supervisor-owned lifecycle move.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B005/research/00023E-ObjectListCategorizeLookupHelpers-source-quality.md`
- Modified: `by-memory/0x00531480-0x00532530.ObjectListCategorizeLookupHelpers.md`
- Modified: `tools/leaser/Agents/Agent-B005/research/00023E-ObjectListCategorizeLookupHelpers-source-quality.md`
- Validator-owned side effects reported by scoped validator: projected stats/reference updates and deferred generated refresh; no manual generated/project-level edits were made.
- Leases: leased `by-memory/0x00531480-0x00532530.ObjectListCategorizeLookupHelpers.md` for the immediate edit/validator batch and released it immediately after validation. No active B005 lease remained in `tools/leaser/Agents/current_leases.md` after release.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004775","destination_path":"executed-b-agent-research/B005/00023E-ObjectListCategorizeLookupHelpers-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/00023E-ObjectListCategorizeLookupHelpers-source-quality.md","timestamp":"2026-07-02T18:10:08-04:00","uid":"00023E"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
