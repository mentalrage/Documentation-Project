** TARGET-REPORT-UID:0001D3 **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# 0001D3 ObjectListAccessorsAndSweeps Source-Quality Research


## Finalized Report / Current Recommendation
- Current recommendation: keep [UID:0001D3] as an `ObjectList` aggregate/child-routing page, preserve direct owner/emitter [UID:00009Q][ObjectList](../../../../by-class/ObjectList.md), retain `RECONSTRUCTABLE:TRUE`, and raise the aggregate from `85/88` to `87/90` after adding the current MCP session facts and exact split plan for the four later helpers.
- Final disposition: implementation-ready documentation improvement, not report execution. The aggregate should not receive a handwritten `ShowInfoList`-style body or any aggregate body for the later helpers; its formal block should remain the existing child-routing marker.
- Required action after Gate 1 acceptance: update the target page and, if wording needs synchronization, [by-class/ObjectList.md](../../../../by-class/ObjectList.md) and [by-file/ObjectList.md](../../../../by-file/ObjectList.md). Exact new child pages for the four later helper ranges are recommended as a follow-up/callback split, but this report-only pass does not create them.
- Confidence: high for ObjectList ownership, range boundaries, padding, caller/callee role, source placement, and no aggregate-body policy; medium-high for final public names of the later helpers.

## Supporting Research

## Target
- Target UID: `0001D3`
- Target path: `by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md`
- Source queue/report row: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`, row `85/88`, combined `86.5`, `Reports:0` at assignment time.
- Current scores and parent state: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:00009Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009Q`.
- Current formal C++ state: the page emits only `// ObjectList accessor and sweep aggregate; exact child pages own emitted method bodies.` plus `[[CHILDREN]]`.
- Parent/source route: [UID:00009Q][ObjectList](../../../../by-class/ObjectList.md) -> [UID:0000M4][ObjectList](../../../../by-file/ObjectList.md) -> `NexusTK/map/ObjectList.cpp`.

## Current Target State
- Existing metadata: `85/88`, owner/emitter `00009Q`, reconstructable true, no emitter-position override.
- Existing target content already records the full function inventory, the exact [UID:0001D2][ObjectListAccessorMethods](../../../../by-memory/0x00532530-0x0053272e.ObjectListAccessorMethods.md) child, predecessor [UID:0002CE] switch-table ownership, successor [UID:00023F] boundary agreement, and the B008 child-routing marker policy.
- Existing blocker: the four later methods at `0x00532730`, `0x00532b80`, `0x00532e20`, and `0x00532eb0` still appear only as rows inside the aggregate rather than exact child pages with source-quality method documentation.
- Related support docs checked: [by-class/ObjectList.md](../../../../by-class/ObjectList.md), [by-file/ObjectList.md](../../../../by-file/ObjectList.md), [by-class/MapPaneSpatialIndex.md](../../../../by-class/MapPaneSpatialIndex.md) via search evidence, generated `-ag-*` tracker/coverage rows, and relevant executed B reports listed below.

## Executive Recommendation
- Keep [UID:0001D3] as the broad `ObjectList` accessor/sweep aggregate and child-routing node. The current owner/emitter route through [UID:00009Q] is correct and should not move to `MapPane`, `MapPaneSpatialIndex`, `List`, `ObjectPane`, or a geometry helper file.
- Raise target metadata to `87/90` after adding current MCP session `1f24c222` facts, exact boundary/padding proof, direct caller windows, and split/readiness rationale.
- Preserve the formal block as the exact aggregate marker:

```cpp
// ObjectList accessor and sweep aggregate; exact child pages own emitted method bodies.
[[CHILDREN]]
```

- Recommended split plan: create exact child pages for `0x00532730-0x00532b72` (`ObjectListShiftAll`), `0x00532b80-0x00532e11` (`ObjectListDetachAll`), `0x00532e20-0x00532eae` (`ObjectListPruneMarkedRowObjects`), and `0x00532eb0-0x00532f67` (`ObjectListFindObjectAt` or a more precise accepted hit-test name). These children should carry method-level first-draft C++ only after their own callback/split pages exist and validator UIDs are assigned.

## Supervisor Active Recheck
- This is the current Agent-B006 report-only Medium assignment for `[UID:0001D3] ObjectListAccessorsAndSweeps`.
- The current `goal.md` requires IDA MCP, report-only mode, exact core headings, no by-* edits, no generated/coverage/project-level edits, and no `execute_report` or lifecycle/archive command.
- The user instructed this resumed pass to use current IDA MCP session `1f24c222` from `idb_list`; no stale session names were used for the current MCP evidence.

## Inference Research Guidance Check
- `by-structure.md` requires exact-address MCP workflows, bounded disassembly, formal-block-only C++ recommendations, and no parent aggregate bodies for child ranges.
- The target is a by-memory aggregate with real code children. Its source identity is still reconstructable ObjectList code, but by-structure says method bodies belong on exact child pages, not on the aggregate.
- Current docs and old reports were treated as leads. Current IDA MCP facts from `1f24c222` are the direct evidence for boundaries, xrefs, callees, and behavior.
- No Wave2/Wave3 artifacts were used as evidence.

## Heuristic / Inference Reanalysis And Validation
- Helper role: current MCP validates that the later part of the range is not miscellaneous padding or a stale alias. It contains four real ObjectList method bodies after the exact accessor child: shift all object panes by pixel deltas, release/detach stored object panes, prune row-bucket objects marked with `+0x13c == -1`, and find an object in the extended/back row bucket by map coordinates.
- Source placement: all four later helpers use the same `ObjectList` layout fields as the constructor/destructor and existing child methods. `MapPane` calls through `MapPane +0x424`; it does not own the storage or helper source.
- Owner/emitter candidates: [UID:00009Q] `ObjectList` remains the best direct owner and emitter. [UID:0000M4] is the source-file route. `MapPane` is a caller, `MapPaneSpatialIndex` is a superseded/generated alias, `List` is only the contained generic collection type, and `ObjectPane`/rectangle helpers are dependencies.
- Type/name direction: `ShiftAll` is now strong enough for source-facing use because the one caller computes pixel-scaled direction deltas and the body offsets every stored object rectangle. `DetachAll` is strong but public spelling remains inferred; it releases all stored panes and optionally preserves one supplied object. `PruneMarkedRowObjects` is clearer than the current lowercase "prune marked objects" row because MCP shows only row arrays `+0x1c/+0x20` and marker field `+0x13c`. `FindObjectAt` remains acceptable, but `FindBackRowObjectAt` or `FindObjectAtTile` could be considered when the exact child is created because the body uses `+0x28` extended/back row lists and compares map-coordinate order through `ObjectPane::GetMapPosition`.
- Raw/caller evidence: direct xrefs and call-site windows show `ShiftAll` from `MapPane::ScrollViewportByDirection`, `DetachAll` from cleanup/change/effect paths, `PruneMarkedRowObjects` from a visible-object refresh path, and `FindObjectAt` from hit-test/raw cleanup consumers.
- Rejected alternatives: aggregate handwritten C++ is rejected by by-structure and B008/B012 precedent; `MapPaneSpatialIndex` ownership is rejected by current support docs and old B012/B010 evidence; no-code/no-owner is rejected because the four helpers are modeled functions with live callers; broad unrelated source-file ownership is rejected by layout and receiver evidence.
- Final C++ readiness: the aggregate is not eligible for a method body because exact child pages own method bodies. The current pass makes the split implementation-ready, but it does not provide child formal bodies because new child pages and UIDs are not yet created in this report-only phase.

## Evidence Standards Used
- Evidence types used: current IDA MCP `initialize`, `tools/list`, `idb_list`, `server_health`, `lookup_funcs`, `get_bytes`, `xref_query`, `callees`, `decompile`, and bounded `disasm`; current target/support docs; generated tracker/coverage rows; executed B reports; negative ownership/source-placement checks.
- Strength: direct MCP evidence proves modeled starts/endpoints, boundary padding, caller/callee roles, field offsets, virtual list/object operations, and source ownership direction.
- Confidence cap: exact original public names and child-level formal C++ remain below final audit until the four exact child pages are created and each body is reviewed in isolation.

## Evidence Checked
- IDA MCP availability/schema: `initialize` succeeded; `tools/list` succeeded; `idb_list` returned exactly active session `1f24c222`, `NexusTK.exe.i64`, created `2026-07-02T17:42:54.839289`, `is_analyzing:false`, worker PID `13460`.
- IDA MCP health: `server_health` for `1f24c222` returned `status:ok`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, string cache ready with `2067` strings.
- Function/boundary checks: `lookup_funcs` on target starts/endpoints confirmed functions at `0x00532530`, `0x00532540`, `0x00532550`, `0x005325b0`, `0x00532610`, `0x00532670`, `0x005326d0`, `0x00532730`, `0x00532b80`, `0x00532e20`, and `0x00532eb0`; non-functions at `0x00532520`, `0x00532534`, `0x0053272e`, `0x00532b72`, `0x00532e11`, `0x00532eae`, `0x00532f67`, and `0x00532f70`.
- Raw bytes: `0x00532520-0x00532530` is a dword table (`6d 24 53 00 cd 24 53 00 dd 24 53 00 ed 24 53 00`) belonging to the predecessor switch helper, not target padding. `0x0053272e-0x00532730`, `0x00532b72-0x00532b80`, `0x00532e11-0x00532e20`, `0x00532eae-0x00532eb0`, and `0x00532f67-0x00532f70` are `0xcc` alignment.
- Xrefs: `0x00532730` has one code xref from `0x005058f9`; `0x00532b80` has three from `0x005045e6`, `0x0050bc1a`, and `0x005106a4`; `0x00532e20` has two from `0x00507032` and `0x0050f4b4`; `0x00532eb0` has two from `0x0050583e` and `0x0050f191`.
- Callees: `0x00532730` calls `sub_4B7E10` and security-cookie check; `0x00532b80` and `0x00532e20` have no ordinary direct callees because they use virtual list/object calls; `0x00532eb0` calls `sub_4B7C50`, `sub_5374D0`, and security-cookie check.
- Decompilation/manual facts: `0x00532730` iterates row/global list fields and calls object vslots `+0x28`/`+0x2c` around `sub_4B7E10`; `0x00532b80` releases stored objects through object vslot `+0`, with one skip object and type-byte condition in the first row loop; `0x00532e20` scans `+0x1c/+0x20` row arrays backward and releases objects whose field `+0x13c` is `-1`; `0x00532eb0` builds padded bounds, indexes `+0x28`, calls `sub_5374D0`, and returns the object whose reported coordinates match the two arguments.
- Caller windows: `0x005058b0` calls `0x00532730` with `ecx = [MapPane+0x424]` and pixel-scaled deltas from tile dimensions; `0x00504530` calls `0x00532b80` with `push 0`; `0x0050bbb0` and `0x005104d0` call `0x00532b80` with `push [MapPane+0x418]`; `0x00506df0` calls `0x00535900` then `0x00532e20` on `[esi+0x384]`; `0x0050f130` pushes two coordinate values then calls `0x00532eb0` through `[MapPane+0x424]`.
- Docs/reports searched with `rg`: terms included `0001D3`, `0x00532530-0x00532f67`, `ObjectListAccessorsAndSweeps`, `0x00532730`, `0x00532b80`, `0x00532e20`, `0x00532eb0`, `ObjectList::ShiftAll`, `ObjectList::DetachAll`, `ObjectList::FindObjectAt`, and `MapPaneSpatialIndex`.
- Relevant executed reports: B012 `0001D2-MapPaneSpatialIndex-source-quality.md` proves the accessor child and parent aggregate no-body policy; B002 movement report supports `ObjectList::ShiftAll`; B002 lifecycle report supports `ObjectList::DetachAll`; B011 raw cleanup report records `sub_532EB0` as an ObjectList lookup dependency; B010/B001 reports reject `MapPaneSpatialIndex` and generic `List` ownership for nearby ObjectList helper families.
- Generated inputs checked: `auto-generated/-ag-research-tracker.md` row remains `85/88`, combined `86.5`, `Reports:0`; `auto-generated/-ag-memory-coverage.md` routes UID0001D3 to generated `auto-generated/NexusTK/map/ObjectList.cpp`; `auto-generated/-ag-coverage-report-by-memory.md` records the B008 aggregate child-routing marker policy.
- Failed/skipped checks: no broad/unbounded MCP list/search/disassembly/callgraph/type/batch-analysis calls were used beyond required `tools/list` schema discovery. No validators were run because this is report-only and no by-* docs were edited.

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1 | UID0001D3 remains ObjectList-owned and routed through [UID:00009Q] / [UID:0000M4]. | High | Current target/support docs; MCP receiver/caller facts; constructor/layout support. | Target Status/Ownership; ObjectList class/file if sync needed | already-present | already-present - target metadata already had owner/emitter `00009Q`; support docs already routed through ObjectList/ObjectList.cpp and were synced only for later-helper detail. |
| C2 | Raise UID0001D3 from `85/88` to `87/90`. | Medium-high | Current MCP session `1f24c222` revalidated starts, endpoints, padding, xrefs, callees, and later-helper roles; remaining cap is exact child pages/names. | Target metadata and Score Rationale | incorporate | applied - target metadata now `COMPLETION:87`, `CONFIDENCE:90`; validator `000000004759` recorded completion/confidence updates and `ok:1`. |
| C3 | Keep `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:00009Q`, and `EMITTER_UIDS:00009Q`. | High | by-structure aggregate rules; source route already valid; no evidence for owner move. | Target metadata | already-present | already-present - target metadata retained `CANONICAL_OWNER:00009Q`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00009Q`; no owner/emitter changes were made. |
| C4 | Retain exact aggregate formal block with comment plus `[[CHILDREN]]`; do not add aggregate method bodies. | High | by-structure child-body rule; B008/B012 precedent; current mixed aggregate range. | Target formal C++ block / First-Draft C++ disposition | already-present | already-present - formal block remains exactly the aggregate comment plus `[[CHILDREN]]`; no method body was added. |
| C5 | Add current MCP session facts using `1f24c222` and avoid stale session names. | High | `idb_list`, `server_health`, current bounded calls. | Target Evidence/Changes | incorporate | applied - target Evidence and Changes now include current session `1f24c222`, health facts, PID, imagebase, analysis readiness, and bounded-call summary. |
| C6 | Record exact padding/table boundaries around the target and internal helper gaps. | High | `get_bytes`, `lookup_funcs`. | Target Evidence / Range analysis | incorporate | applied - target Evidence records predecessor table bytes and internal `0xcc` gaps; function/non-function endpoint facts incorporated. |
| C7 | Convert the four later-helper blocker into exact split recommendations. | Medium-high | Current decompilation/xrefs/call-site windows; by-structure exact-child rule. | Target Functions/Score Rationale; support method inventories | incorporate | applied - target Functions/Status/Changes and both ObjectList support docs now list future exact children and roles; child creation documented as future split work needing separate safe UID/validator batch. |
| C8 | Historicalize/supersede `MapPaneSpatialIndex` ownership for this range. | High | B012/B010 reports; current support docs; ObjectList field evidence. | Target Ownership/Changes; support docs if stale wording remains | already-present | already-present - target/support docs already kept `MapPaneSpatialIndex` as compatibility/search alias only; B006 ownership recheck preserved and reinforced that wording. |
| C9 | Reject no-owner/no-code route for the four later helpers, while retaining no aggregate-body policy. | High | Four modeled functions with live xrefs; formal block rules. | Target Negative Evidence / First-Draft C++ | incorporate | applied - target Evidence/Ownership/Changes now reject alternate owners and no-owner route while preserving aggregate no-body/child-routing policy. |

## Positive Evidence Summary
- Direct facts supporting the recommendation: all target functions are inside the `ObjectList` method island, use `ObjectList` fields `+0x14..+0x40`, and are called through MapPane's `ObjectList*` field rather than owned by MapPane.
- The exact early child [UID:0001D2] already carries accessor C++; the remaining four later helpers have current MCP evidence strong enough for method-level split planning.
- Strongest inference chain: ObjectList constructor/destructor/layout prove the storage fields; target functions read/sweep/shift/search those fields; callers pass `MapPane +0x424` as the receiver; neighboring ObjectList docs and old reports reject alias/source moves; by-structure requires exact child bodies. That chain supports owner/emitter retention, score improvement, and aggregate no-body policy.

## Negative Evidence Summary
- Checked and rejected `MapPane` ownership: MapPane supplies the receiver and arguments from fields `+0x418/+0x424`, but the bodies operate on ObjectList storage and internal list tiers.
- Checked and rejected `MapPaneSpatialIndex` ownership: current B012/B010 evidence and support docs keep it as a compatibility/search alias only; no current MCP fact shows a separate allocated class or source module.
- Checked and rejected generic `List` ownership: `List` supplies virtual `GetElementAt`, but the method semantics are ObjectList-specific sweeps over map-world object tiers.
- Checked and rejected `ObjectPane` ownership: object vslots are payload operations invoked by ObjectList loops, not the owner of the index/sweep logic.
- Checked and rejected rectangle/helper ownership: `sub_4B7C50`, `sub_4B7E10`, and `sub_5374D0` are dependencies used inside ObjectList methods, not owners of the caller range.
- Checked and rejected aggregate-body C++: the aggregate overlaps the exact accessor child and four child-worthy later helpers, so a handwritten aggregate body would duplicate child output and violate by-structure.
- Evidence capping confidence: exact original public names for the four later helpers are inferred, not symbol-proven, and child-level formal bodies need exact child pages before C++ insertion.

## IDA MCP Facts
- Current session: `1f24c222`, active `NexusTK.exe.i64`, not analyzing, worker PID `13460`.
- Function starts: `0x00532530`, `0x00532540`, `0x00532550`, `0x005325b0`, `0x00532610`, `0x00532670`, `0x005326d0`, `0x00532730`, `0x00532b80`, `0x00532e20`, `0x00532eb0`.
- Negative function facts: internal endpoints/padding starts and successor raw start `0x00532f70` are not IDA functions in this session.
- Xref facts: one `ShiftAll` caller, three `DetachAll` callers, two `PruneMarked` callers, two `FindObjectAt` callers.
- Vtable/type facts: later helpers use `List` vslot `+0x10` for element fetch and object vslot `+0` for release; `ShiftAll` uses object vslots `+0x28/+0x2c`.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00532530-0x0053272e` | [UID:0001D2][ObjectListAccessorMethods](../../../../by-memory/0x00532530-0x0053272e.ObjectListAccessorMethods.md) | Exact accessor child with formal C++ | true | UID0001D3 / ObjectList | `90/91` current page evidence | already split |
| `0x00532730-0x00532b72` | proposed `ObjectListShiftAll` child | Shifts every stored object rect by pixel deltas | true | UID0001D3 / ObjectList | recommend child-level review | split recommended |
| `0x00532b80-0x00532e11` | proposed `ObjectListDetachAll` child | Releases stored object panes, preserving optional object | true | UID0001D3 / ObjectList | recommend child-level review | split recommended |
| `0x00532e20-0x00532eae` | proposed `ObjectListPruneMarkedRowObjects` child | Releases row-bucket objects marked `+0x13c == -1` | true | UID0001D3 / ObjectList | recommend child-level review | split recommended |
| `0x00532eb0-0x00532f67` | proposed `ObjectListFindObjectAt` child | Searches extended/back row bucket by map coordinates | true | UID0001D3 / ObjectList | recommend child-level review | split recommended |
| `0x0053272e-0x00532730`, `0x00532b72-0x00532b80`, `0x00532e11-0x00532e20`, `0x00532eae-0x00532eb0`, `0x00532f67-0x00532f70` | internal gaps | `0xcc` alignment | false/padding | target boundary notes | n/a | document only |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x005058f9 -> 0x00532730` | `sub_5058B0` / MapPane scroll | Pixel-scaled tile deltas are passed to ObjectList `ShiftAll`. |
| `0x005045e6 -> 0x00532b80` | `sub_504530` / MapPane cleanup | Passes `0`; then obtains the `+0x40` list and releases remaining panes. |
| `0x0050bc1a -> 0x00532b80` | `sub_50BBB0` / map change | Passes `[MapPane+0x418]` as preserve object before deleting/replacing ObjectList. |
| `0x005106a4 -> 0x00532b80` | `sub_5104D0` / effect packet path | Same preserve-object cleanup pattern. |
| `0x00507032 -> 0x00532e20` | `sub_506DF0` | Calls `sub_535900` then prunes marked row objects. |
| `0x0050f4b4 -> 0x00532e20` | raw/unmodeled caller context | Confirms second static route; exact function metadata not modeled. |
| `0x0050583e -> 0x00532eb0` | raw cleanup sweep | ObjectList lookup dependency in raw MapPane cleanup range. |
| `0x0050f191 -> 0x00532eb0` | `sub_50F130` | Hit-test/coordinate caller passes two coordinates to ObjectList lookup. |

## Documentation Evidence And IDA Status
- Target doc already contains the correct aggregate marker and current owner/emitter route.
- [by-class/ObjectList.md](../../../../by-class/ObjectList.md) and [by-file/ObjectList.md](../../../../by-file/ObjectList.md) already list the four later helpers but still mark final public names provisional.
- B012 executed report is direct precedent: [UID:0001D3] should remain broad/blank while exact child pages carry source bodies.
- Generated `-ag-*` rows still show UID0001D3 at `85/88` and `Reports:0`; this report is the first current B report for UID0001D3.

## Ranked Ownership Analysis

### 1. ObjectList / map/ObjectList.cpp
- Evidence for: constructor/destructor/layout field agreement; target functions operate on fields initialized by ObjectList; callers use `MapPane+0x424` as receiver; support docs and old reports converge on this route.
- Evidence against: some public helper names remain inferred, and four later exact child pages do not exist yet.
- Decision: keep as direct owner/emitter and source route.

### 2. MapPane
- Evidence for: most live callers are MapPane methods.
- Evidence against: caller/consumer relationship only; `MapPane` passes an `ObjectList*` receiver and does not own the internal list fields.
- Decision: reject as owner; retain as caller context.

### 3. MapPaneSpatialIndex
- Evidence for: historical generated/source alias around the early accessor subset.
- Evidence against: B012 reclassified the exact early range as ObjectList accessors; current support docs keep the class alias ignored/non-emitting; no allocation/vtable/class evidence supports it.
- Decision: reject as owner, keep historical search alias only.

### 4. List / ObjectPane / geometry helpers
- Evidence for: target bodies call list and object vslots and use rectangle/map-position helpers.
- Evidence against: these are dependencies/payload operations, not the storage owner or receiver type.
- Decision: reject as owners.

## Source Placement
- Recommended source file/class/global/module placement: `ObjectList` class methods under `NexusTK/map/ObjectList.cpp`.
- Why this fits: the helper range is adjacent to ObjectList lifecycle/categorize/extended-helper islands, uses the same 68-byte layout, and is only consumed by map object-index clients.
- Rejected placements: `MapPane.cpp` hides the coherent object-index class; `List.cpp` overgeneralizes map-specific behavior; `MapPaneSpatialIndex.cpp` is a stale generated alias.
- Remaining uncertainty: exact public spelling of `DetachAll`, `PruneMarkedRowObjects`, and `FindObjectAt` should be settled on exact child pages.

## Range / Split / Padding / Reclassification Analysis
- Exact range facts: target begins at real function `0x00532530` immediately after predecessor table bytes ending at `0x00532530`; it ends at `0x00532f67`, followed by nine bytes of `0xcc` before successor raw helper family at `0x00532f70`.
- Internal padding facts: current MCP byte reads prove alignment at every later helper boundary listed in the child inventory.
- Child/subranges to create: exact children for `0x00532730-0x00532b72`, `0x00532b80-0x00532e11`, `0x00532e20-0x00532eae`, and `0x00532eb0-0x00532f67`.
- Parent/container impact: UID0001D3 should stay reconstructable and emitting through `[[CHILDREN]]`; exact children should own future method bodies.
- Reclassification: no owner reclassification needed. Historical `MapPaneSpatialIndex` wording should stay superseded.

## IDA Rename / Type / Comment Recommendations
- No IDA DB edits requested in this report-only pass.
- Source-facing names recommended for docs: `ObjectList::ShiftAll`, `ObjectList::DetachAll`, `ObjectList::PruneMarkedRowObjects`, and `ObjectList::FindObjectAt` with a child-level note that `FindBackRowObjectAt` / coordinate-order spelling may be better after hit-test context review.
- Items intentionally left unchanged: exact IDA function names and final type signatures, because report-only docs should not mutate the IDB and child pages do not yet exist.

## First-Draft C++ Recommendation
- Eligible for draft C++: UID0001D3 is reconstructable and has a valid emitter route, but it is a broad aggregate. It is not eligible for a handwritten method body because exact child pages own the source bodies.
- Recommended formal `RECONSTRUCTION_CPP CODE` insertion content for UID0001D3 after callback acceptance: retain exactly:

```cpp
// ObjectList accessor and sweep aggregate; exact child pages own emitted method bodies.
[[CHILDREN]]
```

- Reason it preserves exact original behavior: it prevents duplicate aggregate bodies while routing exact child method bodies into `ObjectList.cpp` when those children are documented.
- Reason it matches plausible original source shape: the original source would have individual `ObjectList` methods, not one monolithic aggregate function covering multiple unrelated compiled bodies and padding.
- Inferred names used instead of IDA labels: `ObjectList`, `ShiftAll`, `DetachAll`, `PruneMarkedRowObjects`, `FindObjectAt`, `ObjectPane`, and `List` are source-facing/inferred or already accepted local names; IDA labels such as `sub_532730` should remain evidence only.
- Exact no-code proof for the aggregate: UID0001D3 overlaps exact child UID0001D2 and four child-worthy later helper bodies. By-structure forbids putting child bodies into the aggregate formal block; the existing `[[CHILDREN]]` marker is the correct emitting representation.

## Final Recommendation
- Exact changes recommended: update UID0001D3 evidence/score/rationale with current `1f24c222` MCP facts; raise metadata to `87/90`; keep owner/emitter/reconstructable unchanged; preserve aggregate formal block; add split recommendations for the four later helpers.
- Exact parent assignments recommended: no owner/emitter move for UID0001D3. Future child pages should use `CANONICAL_OWNER:00009Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009Q` if supervisor creates them.
- Exact items left non-emitting: no target item is no-owner/non-emitting; only padding gaps are non-source alignment.
- Future work outside this report-only pass: create/validate exact child pages and then consider child-level formal C++ for each method.

## Recommended Target Doc Changes
- Target path: `by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md`.
- Facts to incorporate: current MCP session `1f24c222` health/session facts; lookup start/end results; byte table/padding results; xref and callee sets; decompiled roles for `ShiftAll`, `DetachAll`, `PruneMarkedRowObjects`, and `FindObjectAt`; caller windows; split plan; negative evidence rejecting MapPane/MapPaneSpatialIndex/List/ObjectPane/geometry ownership; score rationale.
- Metadata changes: `COMPLETION:85 -> 87`, `CONFIDENCE:88 -> 90`; no owner/emitter/reconstructable change.
- C++ changes: none beyond confirming the existing aggregate marker.
- Historical/stale assumptions to preserve: `MapPaneSpatialIndex`, `GetLayer0*`, `GetLayer1*`, and `GetInternalList` as historical/search aliases only.

## Recommended Support Doc Changes
- [by-class/ObjectList.md](../../../../by-class/ObjectList.md): update only if needed to reflect the four exact child split recommendations and sharpen the later helper row names/roles. No class-level formal body should be added.
- [by-file/ObjectList.md](../../../../by-file/ObjectList.md): update only if needed to mirror target/source placement details and exact split plan. No file-level method body should be added.
- No recommended edits to generated reports, manual `-coverage-report.md` files, validator state, queues, archives, or supervisor ledgers.

## Score And Metadata Recommendation
- Current score/metadata: `85/88`, `CANONICAL_OWNER:00009Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009Q`, formal child-routing marker.
- Recommended score/metadata: `87/90`, same owner/reconstructable/emitter, same formal marker.
- Score rationale: current MCP revalidated the whole target with current session facts and converted the named later-helper blocker into an exact split plan with function behavior, callers, callees, and padding boundaries. Completion should rise because the aggregate now has implementation-ready child boundaries/roles rather than vague later rows. Confidence should rise because current IDA agrees with existing docs and old-report precedent.
- Reason not higher: the four later helpers still lack exact child pages, stable validator UIDs, and child-level formal C++/final public name audit. This prevents `90+` completion and `95+` confidence.
- Reason not lower: owner, source route, range boundaries, padding, caller/callee roles, and no-body aggregate policy are strongly evidenced and already supported by multiple accepted reports.
- Score-improvement attempt: later-helper boundaries were checked with `lookup_funcs` and `get_bytes`; result resolved. Caller/callee context was checked with `xref_query`, `callees`, and bounded disassembly windows; result resolved. Helper behavior was checked with decompilation; result resolved to split-ready roles. Aggregate C++ blocker was checked against by-structure/B008/B012; result resolved to retained marker. Final public spelling remains evidence-backed unresolved and caps score.

## Open Questions With Attempted Resolution
- Exact original spelling of `DetachAll`: checked current docs, callers, and decompilation. Best supported current name is `DetachAll`, because callers use it for object-list teardown/replacement and the body releases stored panes. Original symbol proof is unavailable; child-level review can decide whether `ReleaseAll`/`ClearObjects` is more source-plausible.
- Exact spelling of `PruneMarkedRowObjects`: current target says "prune marked objects"; MCP shows only `+0x1c/+0x20` row arrays and marker `+0x13c == -1`. Recommended child name is descriptive and more precise.
- Exact coordinate order/name for `FindObjectAt`: decompilation compares `GetMapPosition` result `[1]` to first arg and `[0]` to second arg; caller pushes two coordinate values. This is sufficient for current row-level naming, but exact child C++ should verify final `x/y` parameter order.
- Whether to create children during this pass: explicitly excluded by report-only assignment. The report provides an implementation-ready split plan for supervisor callback instead.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text
- Not applicable for this report-only pass. Do not edit manual `by-memory/-coverage-report.md` or generated tracker/coverage files.

## Follow-Up Actions
- Supervisor Gate 1: validate this report's required sections and implementation checklist.
- Implementation callback if accepted: update target/support docs at report-level detail; run scoped validators with `--apply --queue-timeout 240`; do not run `execute_report`.
- Future split callback: create exact child pages for the four later helper ranges, validate UID assignment, then perform child-level first-draft C++ decisions.

## Confidence
- Recommendation confidence: high.
- Score confidence: medium-high.
- Remaining uncertainty: exact public helper spellings and child-level C++ details for four later methods.

## Validator Results
- `python .\tools\validator.py --mode file --file by-memory\0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md --apply --queue-timeout 240`: command_id `000000004759`, command_timestamp `2026-07-02T18:05:56-04:00`, exit code `0`, `ok:1`. Reported `completion_update 0001D3 ... 87`, `confidence_update 0001D3 ... 90`, four UID link insertions, `projected_stats_update:1`, and `generated_refresh: deferred`.
- `python .\tools\validator.py --mode file --file by-class\ObjectList.md --apply --queue-timeout 240`: command_id `000000004761`, command_timestamp `2026-07-02T18:06:01-04:00`, exit code `0`, `ok:1`. Reported three UID link insertions, `stats_row_update 00009Q project-level/-auto-completion-stats.md by-class_Reconstructable`, `projected_stats_update:1`, and `generated_refresh: deferred`.
- `python .\tools\validator.py --mode file --file by-file\ObjectList.md --apply --queue-timeout 240`: command_id `000000004763`, command_timestamp `2026-07-02T18:06:13-04:00`, exit code `0`, `ok:1`. Reported two UID link insertions, `projected_stats_update:1`, and `generated_refresh: deferred`; it also reported pre-existing/support warning `missing_ref_uid 0003IO by-file/ObjectList.md UID reference is not present in validator.ini`.
- Generated-refresh state: initial `python .\tools\validator.py --queue-status` command_id `000000004764`, command_timestamp `2026-07-02T18:06:27-04:00`, exit code `0`, reported generated refresh still in progress. Final queue-status command_id `000000004766`, command_timestamp `2026-07-02T18:08:08-04:00`, exit code `0`, reported worker running, queued jobs `0`, processing jobs `0`, queued generated refresh jobs `0`, and processing generated refresh jobs `0`. `auto-generated/-ag-memory-coverage.md` header shows validator-command-id `000000004767`, refreshed `2026-07-02T18:08:10-04:00`; `auto-generated/NexusTK/map/ObjectList.cpp` header shows validator-command-id `000000004763`, refreshed `2026-07-02T18:06:13-04:00`.
- Any unresolved validator warnings/errors: only the `missing_ref_uid 0003IO` warning from `by-file/ObjectList.md`; it is unrelated to UID0001D3 edits and was not repaired because validator state/lifecycle repair is out of callback scope.

## Changed Files
- Created: `tools/leaser/Agents/Agent-B006/research/0001D3-ObjectListAccessorsAndSweeps-source-quality.md`
- Modified during implementation callback: `by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md`, `by-class/ObjectList.md`, `by-file/ObjectList.md`, and this report file's ledger/checklist.
- Renamed: none.
- Report execution: not run. No `execute_report`, dry-run/status/probing variant, lifecycle/archive command, or manual report move was run.

## Implementation Tracking Checklist

- [x] Supervisor validation required before implementation. Proof: user reported Gate 1 passed in `tools/leaser/Agents/b-report-validation-audit.md` for SHA256 `944A0DBF99A4C9DA5FA7B20603AE4EB371C6E411361FBD4562EAB63B01BA4365`.
- [x] Target/support docs to update: `by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md`; support `by-class/ObjectList.md` and `by-file/ObjectList.md` only if wording needs sync. Proof: all three were updated; support docs needed split-plan/role sync.
- [x] Current target state and actual evidence checked recorded. Proof: target now records current MCP session `1f24c222`, lookup results, bytes, xrefs, callees, decompilation/manual roles, caller windows, split plan, and ownership rejection evidence.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim. Proof: C1-C9 now use callback states `applied` or `already-present` with proof.
- [x] Metadata/score changes to apply: UID0001D3 `85/88 -> 87/90`. Proof: target metadata changed; validator `000000004759` confirmed completion/confidence updates.
- [x] Score-limiting blockers researched to resolution, implementation-ready repair/split recommendation, or exact evidence-backed no-improvement proof. Proof: target and support docs now convert the four later helper blockers into exact future split recommendations with role evidence.
- [x] Owner/emitter/reconstructable changes to apply. Proof: no changes applied; target retained `CANONICAL_OWNER:00009Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009Q`.
- [x] Split/rename/new-child changes to apply. Proof: exact future child split recommendations were incorporated; new child pages were intentionally not created because this callback accepted incorporating the split plan and a separate safe split/UID validator batch is needed for new child creation.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable. Proof: target and support docs keep source placement `ObjectList` / `NexusTK/map/ObjectList.cpp`, document padding, and reject alternate owners; no IDA DB edits were made.
- [x] First-draft C++ or no-code proof to apply. Proof: aggregate formal marker retained exactly; no aggregate method body added.
- [x] Third-party import directive to apply or confirm not applicable. Proof: not applicable; no third-party source/import involved.
- [x] Exact target/support doc facts to incorporate at report-level detail. Proof: target Evidence/Score/Ownership/Changes and support docs now include MCP facts, padding, xrefs/callees/caller windows, helper roles, split plan, and score rationale.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve. Proof: docs preserve `MapPaneSpatialIndex` as historical/search-only and reject MapPane/List/ObjectPane/geometry ownership and aggregate handwritten body.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable. Proof: none used.
- [x] Open questions to close or document as evidence-backed unresolved. Proof: helper public spellings and `FindObjectAt` coordinate-order/name remain documented as child-level confidence caps.
- [x] Validators to run after accepted by-* implementation callback. Proof: scoped validators ran for all three changed by-* docs; command IDs/results recorded above.
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text to apply. Proof: no manual coverage/tracker text applied; generated refresh was deferred by validators, then final queue status `000000004766` showed no queued or processing generated refresh jobs. Generated headers checked: `-ag-memory-coverage.md` at `000000004767` and `ObjectList.cpp` at `000000004763`.

- [x] Report accepted by supervisor for implementation. Proof: user callback approved UID0001D3 and cited Gate 1 SHA256.
- [x] All accepted target/support doc details incorporated at report-level detail. Proof: target and both support docs updated as described above.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim. Proof: C1-C9 updated.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason. Proof: score applied; owner/emitter/reconstructable kept; aggregate marker retained; child creation excluded with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: target/support docs preserve alias and rejected-owner evidence.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale. Proof: final helper spelling and coordinate order are documented as child-level caps.
- [x] Validators run and results recorded. Proof: validators `000000004759`, `000000004761`, and `000000004763` recorded above.
- [x] Generated report refresh completed by validator or explicit manual supervisor-owned coverage/tracker text supplied/confirmed unchanged. Proof: validators reported `generated_refresh: deferred`; final queue status `000000004766` showed no queued or processing generated refresh jobs, and generated headers show `-ag-memory-coverage.md` refreshed by `000000004767` and `ObjectList.cpp` refreshed by `000000004763`. No manual supervisor-owned coverage/tracker text was needed or edited.
- [x] Remaining unapplied accepted items listed with exact blocker. Proof: only new child creation is unapplied; blocker is accepted scope/safety because child creation needs a separate split/UID validator batch and was not required by this callback.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004793","destination_path":"executed-b-agent-research/B006/0001D3-ObjectListAccessorsAndSweeps-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/0001D3-ObjectListAccessorsAndSweeps-source-quality.md","timestamp":"2026-07-02T18:17:55-04:00","uid":"0001D3"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
