** TARGET-REPORT-UID:00042J **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 00042J MapPaneRefreshNearbyObjectRows Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00042J] as a reconstructable, MapPane-owned, non-emitting raw helper; improve the target page with current MCP-backed range, byte, no-route, behavior, source-placement, and no-code proof.
- Final disposition: keep `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank formal `RECONSTRUCTION_CPP CODE`. Do not insert a C++ body for this pass.
- Required action if accepted: update the target/support docs with the current 2026-07-01 evidence and raise the target from `85/85` to `87/89`.
- Implementation callback status: accepted 2026-07-01 items were applied to the target and three required support docs. `by-type/by-struct/MapPaneLayout.md` and `by-memory/-ignored.md` were explicitly excluded because they already carry same-or-greater `+0x424` and adjacent-padding evidence.
- Confidence: high for range, raw-code liveness, MapPane semantic owner, ObjectList dependency role, and current no-route proof; lower for original source declaration/reachability because no modeled function, caller, pointer, table, or generated-output route exists.

## Target

- Target UID: `00042J`
- Target path: `by-memory/0x005061e0-0x005062e5.MapPaneRefreshNearbyObjectRows.md`
- Assignment ID: `B003-report-00042J-MapPaneRefreshNearbyObjectRows-by-memory-20260701`
- Source queue row: `auto-generated/-ag-research-tracker.md` -> `by-memory` -> `Not-Covered Files - Reconstructable`; row lists `85/85`, combined `85.0`, reconstructable `true`, reports `0`.
- Current generated coverage: `auto-generated/-ag-coverage-report-by-memory.md` lists UID00042J as `emits_code:false`; `auto-generated/-ag-memory-coverage.md` lists it as `non-emits`, owner `00007Q`, no emitters, no code.

## Current Target State

- Existing metadata: `COMPLETION:85`, `CONFIDENCE:85`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++ block, `Nested:0`.
- Existing summary: raw no-function MapPane nearby object-row refresh helper ending with `0x005062e2` `retn 8`; source-shaped but currently non-emitting due no route/xref/pointer evidence.
- Existing direct owner: [UID:00007Q] `MapPane`.
- Existing source/file route context: [UID:0000L3] `MapPane` / `NexusTK/map/MapPane.cpp`, through the MapPane class owner. This target should not emit through that route until entry reachability is proven.
- Parent aggregate: [UID:0001AP] `0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore`.
- Related support docs checked: [UID:000420] `MapPaneGetClampedVisibleTileBounds`, [UID:0002QN] `MapPaneCreateOrUpdateObjectPane`, [UID:0002QP] `MapPaneDetachObjectPane`, [UID:0002QQ] `MapPaneFindObjectIntersectingRect`, [UID:0001D2] `ObjectListAccessorMethods`, [UID:00042K] `MapPaneLayout`, [UID:00007Q] `MapPane`, [UID:0000L3] `MapPane`, and `by-memory/-ignored.md`.

## Executive Recommendation

The best semantic owner remains [UID:00007Q] `MapPane`: the raw body receives `this` in `ECX`, reads `MapPane +0x424` as `m_objectList`, checks byte `+0x3f0`, calls the MapPane visible-bounds helper at `0x00505290`, and uses MapPane/object-pane virtual rectangle callbacks before refreshing nearby visible object rows. ObjectList is a dependency/provider, not the direct owner, because the receiver and gating state are MapPane-owned and the helper orchestrates MapPane visible-object refresh policy.

The best output disposition remains non-emitting. Current MCP rechecked the exact raw range and found no IDA function at `0x005061e0`, no incoming xrefs to the raw start, no absolute VA/RVA pointer-byte hits for the raw start or boundary addresses, no name in the local range, and decompilation failure at the raw start. Emitting `MapPane::RefreshNearbyObjectRows` now would create a generated `MapPane.cpp` method with no proven callsite, address-taken route, vtable route, table route, or modeled function entry. That would invent reachability.

## Supervisor Active Recheck

- The assignment required rechecking raw helper liveness, route/xref/pointer evidence, owner/emitter route, nearby object-row refresh semantics, object-list dependencies, source-placement candidates, first-draft C++ readiness, and whether the blank-emitter state can be improved.
- During the report-only research pass, no by-* docs, generated files, coverage reports, validator state, lock files, IDA DB, or support docs were edited. During the accepted implementation callback, only the accepted target/support by-* docs were edited, plus this report ledger/checklist; validators updated projected stats.
- No split repair is recommended. The target remains a single half-open raw code range `0x005061e0-0x005062e5`, with adjacent `0x005061d3-0x005061e0` and `0x005062e5-0x005062f0` alignment already recorded in `by-memory/-ignored.md`.

## Inference Research Guidance Check

- Direct IDA/MCP facts are separated below from documentation evidence and inference.
- Current by-structure rules allow a page to have a concrete owner but no emitter when ownership is known and generated-output routing is not ready or not applicable.
- The current code-entry gate is not met because the target has no confirmed nonblank emitter route and no source reachability route.
- Stale Wave2/Wave3 material was not used as proof. The accepted B009 report was used as lead material and checked against current MCP evidence.

## Heuristic / Inference Reanalysis And Validation

- Raw helper liveness: current MCP validates B009's classification. `0x005061e0` is not an IDA function, but `insn_query` shows a normal prologue, security-cookie body, MapPane receiver save, object-list/visible-row loop, object-pane rectangle callbacks, security-cookie epilogue, and `retn 8`. The range is source-authored code, not padding or a generated alignment artifact.
- Source-facing name: `MapPaneRefreshNearbyObjectRows` remains the best documentation name. The body clamps a supplied row range against visible tile bounds, iterates ObjectList row buckets, tests objects within one tile of the supplied coordinate, and refreshes overlapping visible object rectangles. This is more specific than a generic raw helper label and fits the adjacent object create/detach/intersection helpers.
- Parameter/type inference: `ECX` is `MapPane *`; `[ebp+8]` and `[ebp+0Ch]` are row/tile coordinates or row-window inputs, with `retn 8` proving two stack arguments. The helper compares an object's map Y coordinate against `[ebp+8]` with an absolute-difference <= 1 test and iterates `[ebp+0Ch]` upward until the clamped bottom row.
- Field/type inference: `MapPane +0x424` is `m_objectList` from [UID:00042K], [UID:0002QN], [UID:0002QP], and [UID:0002QQ]. The byte at `+0x3f0` is a MapPane transient refresh/local-object gate known from object-update logic; the helper exits when it is set. `sub_5326D0` is [UID:0001D2] `ObjectList::GetBackRowBucket(int row)`. `sub_5374D0` is an object-pane map-position accessor used widely by MapPane/ObjectList consumers. `sub_4B8E00` is [UID:000161] `BackPane::GetBounds`, used here through an object pane receiver as a rectangle/bounds accessor dependency rather than a BackPane ownership signal.
- Owner inference: MapPane is the narrowest true semantic owner. The parent aggregate and file route explain source placement, but they do not replace the class owner. ObjectList owns the row-bucket accessor and storage layout; object-pane classes own their rectangle/map-position virtual methods. Those are dependencies, not the source home of this coordinator helper.
- C++ readiness: behavior is now source-quality enough to document, but not enough to emit. Current evidence lacks the source declaration/reachability route required for a formal C++ block. Blank C++ is a target-specific no-code proof, not a generic unknown deferral.
- Score blocker resolution: the named blockers are resolved as follows: no modeled function confirmed; no xref/pointer route confirmed; owner and key field/helper names resolved; no split/range repair needed; first-draft C++ rejected with exact no-code proof; support-doc updates are implementation-ready.
- Rejected alternatives: emit through [UID:00007Q] anyway, route through [UID:0000L3] directly, assign to ObjectList, assign to BackPane/ObjectPane, mark ignored padding, merge with predecessor/successor helpers, or leave the target at generic no-route wording. Each would either invent reachability, misassign a dependency as owner, lose a real raw code body, or obscure current evidence.

## Evidence Checked

- Required workflow files: `Agent-B003/goal.md`, `ntk-b-agent-workflow` skill, `b-agent-research-and-implementation-workflow.md`, `score-blocker-audit-standard.md`, `b-agent-report-template.md`, and `by-structure.md` IDA MCP Output Discipline.
- Current IDA MCP endpoint: `http://127.0.0.1:13337/mcp`.
- Current IDA database session used: `supervisor_resume_20260629`.
- MCP health: `server_health` returned `status:"ok"`, `idb_path:"E:\NTK\Resources\NexusTK\NexusTK.exe.i64"`, `module:"NexusTK.exe"`, `input_path:"C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe"`, `imagebase:"0x400000"`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.
- MCP calls: `idb_list`, `server_health`, `lookup_funcs`, `xrefs_to`, `xref_query`, `find_bytes`, `get_bytes`, `insn_query`, `make_signature_for_range`, `int_convert`, `decompile`, and `entity_query`.
- Old-report search terms: `00042J`, `0x005061e0`, `0x005062e5`, `MapPaneRefreshNearbyObjectRows`, `NearbyObjectRows`, `MapPane`, and `0x005062e2`.
- Matching old reports opened: `executed-b-agent-research/B009/0001AP-MapPaneWeatherCoordinateObjectCore-source-quality.md`; related source-family reports/summaries checked by exact terms include MapPane class/file reports and the accepted raw-child pattern for [UID:000424].
- by-* docs checked: target page, [UID:0001AP], [UID:00007Q], [UID:0000L3], [UID:000420], [UID:0002QN], [UID:0002QP], [UID:0002QQ], [UID:0001D2], [UID:00042K], and `by-memory/-ignored.md`.
- Generated/tracker files checked read-only: `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, `auto-generated/-ag-memory-coverage.md`, `auto-generated/NexusTK/map/MapPane.cpp`, and `project-level/-auto-completion-stats.md`.
- Negative checks performed: no function at raw start/end; no incoming xrefs to start; no VA/RVA pointer-byte hits for start/end/return boundary; no local name in range; decompilation failed at raw start; generated coverage remains non-emitting.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C001 | UID00042J is currently `85/85`, owner `00007Q`, reconstructable, blank emitter, blank C++. | High | Target page header, tracker row, generated coverage. | Target Status / metadata; target Changes | incorporate | applied: target is now `87/89` and still owner `00007Q`, reconstructable, blank emitter, blank C++. |
| C002 | Current MCP session `supervisor_resume_20260629` is healthy and backed by NexusTK IDB. | High | `idb_list` and `server_health` structured output. | Target `Current MCP Evidence` / Changes | incorporate | applied: target `Current MCP Evidence` names the session and health-backed IDB state. |
| C003 | `lookup_funcs` reports no function at `0x005061e0`, `0x005062e2`, or `0x005062e5`; adjacent functions are predecessor `sub_506170` and successor `sub_5062F0`. | High | MCP `lookup_funcs` result. | Target `Current MCP Evidence`; `No-Route And No-Code Proof`; parent row | incorporate | applied: target records no-function/decompile proof; aggregate row records current no-route state. |
| C004 | The target bytes are source-shaped code, not padding: prologue, security cookie, MapPane field reads, row-bucket loop, object-pane calls, epilogue, `retn 8`. | High | MCP `get_bytes`, `insn_query`, `make_signature_for_range`. | Target `Range And Bytes`; target `Behavior` | incorporate | applied: target range/behavior sections describe the source-shaped body and `retn 8`. |
| C005 | The half-open target body is `0x105` / 261 bytes (Verified with MCP `int_convert`), followed by `0x005062e5-0x005062f0` alignment. | High | MCP `int_convert`, `get_bytes`, `insn_query`, `by-memory/-ignored.md`. | Target `Range And Bytes`; `by-memory/-ignored.md` already-present reason | incorporate | applied: target range section records `0x105` / `261`; `by-memory/-ignored.md` excluded because padding was already present. |
| C006 | Behavior exits when `m_objectList` is null or byte `MapPane +0x3f0` is set, then gets clamped visible tile bounds and clamps the input row window to at most `inputRow + 7`. | High | MCP instruction scan and [UID:000420]/[UID:00042K] docs. | Target `Behavior`; parent/class/file notes | incorporate | applied: target and support docs now include the `m_objectList`, `+0x3f0`, clamped bounds, and row-window behavior. |
| C007 | Behavior iterates `ObjectList::GetBackRowBucket(row)`, reads each object pane, gets map position, filters to object rows within one tile of the input row, gets object bounds, calls a bounds/refresh helper, then invokes virtual slot `+0x20` with the refreshed rectangle. | Medium-high | MCP instruction scan; [UID:0001D2], [UID:0002QN], [UID:0002QQ], ObjectPane/BackPane support docs. | Target `Behavior`; target `Dependency Roles` | incorporate | applied: target behavior/dependency roles and support summaries preserve row-bucket, object-position, bounds, and refresh virtual-path evidence. |
| C008 | Best owner remains [UID:00007Q] `MapPane`; ObjectList/ObjectPane/BackPane are dependencies or callees, not owners. | High | ECX receiver, MapPane fields, parent aggregate, support docs. | Target `Ownership And Source Placement`; class/file support notes | incorporate | applied: target dependency roles and class/file notes keep MapPane owner and dependency-owner rejection. |
| C009 | `xrefs_to 0x005061e0` returns zero incoming refs; `xref_query both` shows only internal local flow from `0x5061e0` to `0x5061e1`. | High | MCP `xrefs_to`, `xref_query`. | Target `Current MCP Evidence`; `No-Route And No-Code Proof`; support notes | incorporate | applied: target and support notes record no incoming start xrefs and no route. |
| C010 | Little-endian VA/RVA searches for `0x005061e0`, plus boundary patterns for `0x005062e2` and `0x005062e5`, returned zero pointer-byte matches. | High | MCP `find_bytes` for `E0 61 50 00`, `E0 61 10 00`, `E2 62 50 00`, `E5 62 50 00`. | Target `Current MCP Evidence`; `No-Route And No-Code Proof`; support notes | incorporate | applied: target/support notes record zero VA/RVA pointer-byte route. |
| C011 | A short security-cookie prologue pattern is not unique, but the full raw range signature is unique. | Medium-high | MCP `find_bytes` first 16 bytes returned 14 matches; `make_signature_for_range` over full range returned `unique:true`. | Target `Range And Bytes`; target evidence caveat | incorporate | applied: target and aggregate row preserve the unique-full-range-but-not-reachable caveat. |
| C012 | Blank `EMITTER_UIDS` and blank formal C++ should remain; no formal C++ insertion text is recommended. | High | No modeled entry, no xrefs, no pointer route, no local name, no generated output entry. | Target metadata; target `No-Route And No-Code Proof`; class/file/parent notes | incorporate | applied: target emitter/formal C++ remain blank; support docs explicitly keep non-emitting disposition. |
| C013 | `by-memory/-ignored.md` already records `0x005061d3-0x005061e0` and `0x005062e5-0x005062f0` as raw-helper-adjacent alignment, not the target body. | High | `rg` of `by-memory/-ignored.md`; MCP `get_bytes`. | Target `Range And Bytes`; `by-memory/-ignored.md` unchanged | already-present | excluded-with-reason: `by-memory/-ignored.md` was not edited because the adjacent padding spans were already present and correct. |
| C014 | Generated coverage currently lists UID00042J as non-emitting, and generated `MapPane.cpp` contains no UID00042J insertion. | High | `rg` of generated MapPane.cpp and generated coverage. | Target `Current MCP Evidence`; generated-refresh checklist note | incorporate | applied: target no-code proof records no generated-output route; validators reported generated refresh deferred and projected stats updates only. |
| C015 | Target detail can improve from `85/85` to `87/89`, but not higher because route/source declaration remains unresolved. | Medium-high | Current MCP proof plus unresolved emitter/source declaration. | Target metadata; target `Status`; target `Changes` | incorporate | applied: target metadata is `87/89`; score rationale documents the route/source-declaration cap. |

## Positive Evidence Summary

- The target is a real raw code body:
  - `0x5061e0 push ebp`; `0x5061e1 mov ebp, esp`; `0x5061e3 sub esp, 5Ch`.
  - Security-cookie setup at `0x5061e6-0x5061ed`.
  - `0x5061f1 mov ebx, ecx`, saving the MapPane receiver.
  - Null-object-list exit at `0x5061f6 cmp dword ptr [ebx+424h], 0` / `0x5061fd jz`.
  - Refresh-gate exit at `0x506203 cmp byte ptr [ebx+3F0h], 0` / `0x50620a jnz`.
  - Calls `MapPane::GetClampedVisibleTileBounds` at `0x506221`.
  - Calls `ObjectList::GetBackRowBucket` at `0x506248`.
  - Iterates bucket entries through virtual slot `+0x10` and object-pane rectangle virtual slots `+0x28` and `+0x20`.
  - Ends at `0x5062e2 retn 8`, followed by `0xcc` alignment.
- The body length is `0x105` / 261 bytes (Verified with MCP `int_convert`).
- The full target signature over `0x005061e0-0x005062e5` is unique with operand wildcarding disabled.
- The semantic owner is MapPane because the receiver is saved from `ECX`, MapPane-owned fields gate the body, and the helper coordinates MapPane visible-object refresh over ObjectList data.

## IDA MCP Facts

- Active MCP session:
  - `idb_list`: active `supervisor_resume_20260629`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, not analyzing.
  - `server_health`: `status:"ok"`, Hex-Rays ready, auto-analysis ready.
- Function/range facts:
  - `lookup_funcs 0x005061d0` resolves inside predecessor `sub_506170`, size `0x63`.
  - `lookup_funcs 0x005061e0` -> `Not a function`.
  - `lookup_funcs 0x005062e2` -> `Not a function`.
  - `lookup_funcs 0x005062e5` -> `Not a function`.
  - `lookup_funcs 0x005062f0` -> successor `sub_5062F0`, size `0x8a`.
  - `entity_query(functions, 0x005061d0-0x00506300)` returned only successor `0x5062f0`; `entity_query(names, same range)` returned no names.
  - `decompile 0x005061e0` returned `code:null`, `error:"Decompilation failed at 0x5061e0"`.
- Byte/padding facts:
  - `get_bytes 0x005061d3 size 13` returned all `0xcc`.
  - `get_bytes 0x005062e5 size 11` returned all `0xcc`.
  - `get_bytes 0x005062e2` begins `c2 08 00 cc...`, proving the `retn 8` and the following padding.
- Xref facts:
  - `xrefs_to 0x005061e0` returned zero incoming refs.
  - `xrefs_to 0x005062e5` returned zero incoming refs.
  - `xrefs_to 0x005062e2` returned a single code xref from `0x5062e1`, the local `pop ebp` flow into the return, not an entry route.
  - `xref_query both 0x005061e0` showed only internal local flow from `0x5061e0` to `0x5061e1`.
- Pointer/search facts:
  - `find_bytes E0 61 50 00`, `E0 61 10 00`, `E2 62 50 00`, and `E5 62 50 00` returned zero matches.
  - `find_bytes` for the first 16 bytes of the security-cookie prologue returned 14 matches, so that short pattern is not unique; the full range signature is unique and should be used for identity.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00506170-0x005061d3` | [UID:0002QP] `MapPaneDetachObjectPane` | Modeled object pane detach/delete helper | TRUE | [UID:00007Q] | `88/90` | emits through MapPane |
| `0x005061d3-0x005061e0` | [UID:0000VN] ignored ledger | `0xcc` alignment | FALSE | n/a | n/a | already documented padding |
| `0x005061e0-0x005062e5` | [UID:00042J] target | Raw no-route nearby object-row refresh helper | TRUE | [UID:00007Q] | current `85/85`, recommend `87/89` | keep non-emitting |
| `0x005062e5-0x005062f0` | [UID:0000VN] ignored ledger | `0xcc` alignment | FALSE | n/a | n/a | already documented padding |
| `0x005062f0-0x0050637a` | [UID:0002QQ] `MapPaneFindObjectIntersectingRect` | Modeled visible object intersection helper | TRUE | [UID:00007Q] | `88/90` | emits through MapPane |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x005061e0` | zero incoming xrefs | No modeled call, jump, data, table, or pointer route into target start. |
| `0x005061e0 -> 0x005061e1` | local flow only in `xref_query both` | Internal code-flow fact, not reachability. |
| `0x00505290` | callee from `0x506221` | MapPane clamped visible tile bounds builder used to bound row iteration. |
| `0x005326d0` | callee from `0x506248` | ObjectList back/extended row-bucket accessor; ObjectList dependency evidence. |
| `0x005374d0` | callee from `0x50626e` | Object/object-pane map-position accessor used before row-distance filtering. |
| `0x004b8e00` | callee from `0x50629e` | Rectangle/bounds accessor dependency used before virtual refresh; not ownership evidence. |
| virtual slot `+0x28` | calls at `0x506218` and `0x50628d` | Rectangle getter on MapPane/object panes. |
| virtual slot `+0x20` | call at `0x5062ab` | Refresh/invalidate/update callback with the adjusted rectangle. |

## Documentation Evidence And IDA Status

- [UID:0001AP] already records UID00042J as a raw no-route MapPane child and records adjacent alignment spans.
- [UID:00007Q] and [UID:0000L3] already establish MapPane coordinate/object helper source placement under `NexusTK/map/MapPane.cpp`.
- [UID:00042K] records `MapPane +0x424` as `m_objectList` and related object/refresh fields.
- [UID:000420] emits `MapPane::GetClampedVisibleTileBounds`, the direct callee at `0x506221`.
- [UID:0001D2] emits ObjectList row-bucket accessors and identifies `0x005326d0` as `ObjectList::GetBackRowBucket(int row)`.
- [UID:0002QN], [UID:0002QP], and [UID:0002QQ] establish the surrounding MapPane object-pane create/detach/intersection source family.
- B009's accepted report remains accurate lead material, but the target page should carry the current UID00042J-specific 2026-07-01 evidence rather than only referring to the parent split report.

## Ranked Ownership Analysis

### 1. [UID:00007Q] MapPane class

- Evidence for: `ECX` receiver saved as the main object; reads `MapPane +0x424` and `+0x3f0`; calls the MapPane visible-bounds helper; coordinates object-pane refresh against visible bounds; parent aggregate and class/file docs place this code in the MapPane coordinate/object family.
- Evidence against: no modeled function entry or caller proves a source declaration site for this exact raw helper.
- Decision: keep as `CANONICAL_OWNER:00007Q`; do not use owner as an emitter route without reachability.

### 2. [UID:0000L3] MapPane file

- Evidence for: MapPane class routes to `NexusTK/map/MapPane.cpp`; adjacent coordinate/object helpers live in this source family.
- Evidence against: direct owner should be the class, not the file, because the raw body is `thiscall`-shaped and reads MapPane fields.
- Decision: source-placement context only; do not change `CANONICAL_OWNER` to `0000L3`.

### 3. [UID:0001AP] parent aggregate

- Evidence for: exact containment and already accepted split inventory.
- Evidence against: aggregate is an index over children, not the direct semantic owner or an appropriate source emitter for a child method body.
- Decision: keep as parent/support evidence. Do not route UID00042J through the aggregate.

### 4. [UID:00009Q] / [UID:0000M4] ObjectList

- Evidence for: target reads `m_objectList`, calls `ObjectList::GetBackRowBucket`, and iterates row-bucket list entries.
- Evidence against: ObjectList owns the storage/accessor layout, not the MapPane receiver, visible bounds, refresh gate, or pane invalidation policy. The helper does not receive an ObjectList as `this`.
- Decision: reject as direct owner; retain as dependency/callee evidence.

### 5. ObjectPane / BackPane / List / caller-owner alternatives

- Evidence for: target calls rectangle/map-position virtuals and list iteration helpers.
- Evidence against: these are provider interfaces used by MapPane. There is no ObjectPane/BackPane/List receiver at the helper entry and no caller set that would assign source ownership to those classes.
- Decision: reject.

### 6. No-owner / unknown owner

- Evidence for: no source route.
- Evidence against: receiver and field evidence are strong enough to identify MapPane as semantic owner.
- Decision: reject no-owner. The blocker is emission route, not ownership.

## Source Placement

- Recommended source family: `NexusTK/map/MapPane.cpp`, through [UID:00007Q] -> [UID:0000L3].
- Recommended generated-output placement: none yet. Keep blank `EMITTER_UIDS`.
- Rejected generated-output placement: adding `EMITTER_UIDS:00007Q` now would make generated `MapPane.cpp` contain a method body with no proven source-use route.
- Remaining placement uncertainty: whether the raw body was a dead/private method, an optimized-away or orphaned helper whose references are not represented in current IDA, or a retained build-configuration body. Current evidence cannot choose among those safely.

## Range / Split / Padding / Reclassification Analysis

- Exact raw helper range remains `0x005061e0-0x005062e5`.
- The body length is `0x105` / 261 bytes (Verified with MCP `int_convert`).
- `0x005061d3-0x005061e0` and `0x005062e5-0x005062f0` are already documented pure alignment in `by-memory/-ignored.md`.
- No child split, merge, rename, or reclassification is recommended.
- Do not mark the raw body ignored: `insn_query` shows 99 real instructions and the full range signature is unique.

## Negative Evidence Summary

- No IDA function at the target start.
- No decompile result for the target start.
- No incoming xrefs to the target start.
- No absolute VA/RVA pointer-byte hits for `0x005061e0`.
- No pointer-byte hits for the `0x005062e2` return address or `0x005062e5` end boundary.
- No named entity in the immediate target range.
- No generated C++ insertion for UID00042J.
- No direct support for a vtable route, callback table route, import/thunk route, parent marker route, or source-visible declaration route.
- The successor `0x005062f0` is a modeled, emitting helper; its reachability does not transfer backward across the intervening CC padding to UID00042J.

## First-Draft C++ Recommendation

- Eligible for draft C++ now: no.
- Recommended code: none. No formal C++ insertion text is supplied because this report recommends blank C++.
- Exact no-code proof: current MCP proves the bytes are custom MapPane code but not a modeled function; no current caller/xref, pointer-byte route, local name, vtable, table, or generated-output route exists. The by-structure code gate also requires a confirmed nonblank emitter route before C++ can be entered. Therefore formal C++ should remain blank even though the behavior is now well understood.
- Reason this is not a generic "unknown" deferral: the report resolves behavior, dependency roles, owner, source placement, range, padding, generated state, and rejected alternatives. The only blocker is current source reachability/output route.

## Recommended Target Doc Changes

Target path: `by-memory/0x005061e0-0x005062e5.MapPaneRefreshNearbyObjectRows.md`

- Change metadata to:
  - `COMPLETION:87`
  - `CONFIDENCE:89`
  - Keep `CANONICAL_OWNER:00007Q`
  - Keep `RECONSTRUCTABLE:TRUE`
  - Keep blank `EMITTER_UIDS`
  - Keep blank `EMITTER_POSITION_OPTIONAL`
  - Keep formal C++ block blank
- Replace or expand the item summary with:
  - `Raw source-shaped MapPane helper that refreshes nearby visible object rows through m_objectList row buckets; current MCP confirms no modeled function, xref, pointer-byte, local-name, or emitter route, so it remains reconstructable but non-emitting.`
- Add current MCP evidence: session ID, health status, lookup result, raw bytes/instruction summary, xrefs result, pointer-byte search result, decompile failure, generated non-emits status.
- Add behavior detail: exits when `m_objectList` is null or `MapPane +0x3f0` is set; builds clamped visible bounds; clamps the row loop using `inputRow + 7`; calls `ObjectList::GetBackRowBucket`; scans row entries; filters objects within one tile of the input row; obtains object bounds and calls a visible-overlap refresh/invalidation virtual path.
- Add dependency roles: ObjectList row buckets and object-pane rectangle/map-position methods are providers; MapPane remains the source owner.
- Add a `Formal No-Code Proof` section preserving why blank C++ is intentional under current by-structure rules.
- Add rejected alternatives: emit through MapPane, direct file owner, ObjectList owner, ObjectPane/BackPane owner, no-owner, padding/ignored, successor merge, and generated-name-only treatment.

## Recommended Support Doc Changes

Support path: `by-class/MapPane.md`

- Refresh the 0001AP raw no-route child summary to identify UID00042J as the nearby visible object-row refresh helper with current 2026-07-01 no-function/no-xref/no-pointer/no-code proof.
- Preserve the distinction that UID00042J is owner-documented MapPane code but should not emit until a caller/pointer/table/source declaration route is found.
- No score change required for the class page.

Support path: `by-file/MapPane.md`

- In the 0001AP / coordinate-object helper source-family note, include UID00042J as a documented non-emitting raw helper in the MapPane.cpp source family, not an emitted method.
- Preserve the source-route distinction: `MapPane.cpp` is the source family, but UID00042J has no generated-output route yet.
- No score change required for the file page.

Support path: `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`

- Add a short 2026-07-01 UID00042J recheck note or update the UID00042J row to say current B003 MCP reconfirmed no function/xref/pointer/local-name route and refined the target-specific no-code proof.
- No score or metadata change required for the aggregate.

Support path: `by-type/by-struct/MapPaneLayout.md`

- No mandatory edit. The relevant `+0x424` object-list field is already present at same-or-greater detail. If implementation wants a cross-reference, add UID00042J to the `+0x424` evidence list, but this is optional.

Support path: `by-memory/-ignored.md`

- No edit required. The adjacent padding spans are already present and correctly exclude the raw helper body.

## Score And Metadata Recommendation

- Current target score/metadata: `85/85`, owner `00007Q`, reconstructable true, blank emitter and C++.
- Recommended target score/metadata: `87/89`, owner `00007Q`, reconstructable true, blank emitter and C++.
- Reason not lower: behavior, bytes, exact range, owner, adjacent padding, ObjectList dependency roles, generated non-emits state, and no-route evidence are now current and implementation-ready.
- Reason not higher: no modeled function entry, caller, pointer-byte route, source declaration, or generated-output route exists. This blocks formal C++ and prevents final-source confidence.
- Metadata fields to leave unchanged: owner, reconstructable, emitter fields, formal C++ block, nested count.

## Open Questions With Attempted Resolution

- Open question: Is this padding? Resolved no. It has normal prologue/body/epilogue instructions, MapPane field reads, row-bucket calls, object-pane virtual calls, and a unique full-range signature.
- Open question: Is the owner unknown? Resolved no. MapPane receiver and field offsets are sufficient for semantic owner.
- Open question: Should ObjectList own it? Resolved no. ObjectList owns row buckets and accessors, but the entry receiver and refresh policy are MapPane.
- Open question: Should it emit C++ through MapPane? Resolved no for current pass. No entry route is proven, and current rules require a confirmed emitter route.
- Remaining unresolved issue: the original reason this raw helper body exists in the binary. Evidence required to change the recommendation would be a direct branch/call, pointer/table entry, recovered source declaration, or other durable route into `0x005061e0`.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual `-coverage-report.md` or tracker edit is required. Generated reports should refresh through validator execution after accepted by-* edits.

## Follow-Up Actions

- Supervisor: validate this report and, if accepted, send B003 an implementation callback for the target/support docs listed above.
- B003 callback: edit only the accepted target/support docs under normal leases, keep C++ blank, run scoped validators, and update this report checklist.
- Future research trigger: only reopen C++ emission if a new route into `0x005061e0` is found.

## Confidence

- Recommendation confidence: high for non-emitting disposition.
- Score confidence: medium-high; `87/89` is justified by current target-specific evidence but should stay below 90/90 because no route exists.
- Remaining uncertainty: original source declaration and why this unreachable raw body remains in `.text`.

## Validator Results

- Report-only pass: no validators were run before supervisor acceptance.
- Implementation callback validators from project-doc root:
  - `B003-VAL-00042J-target`, timestamp `2026-07-01T21:49:21.8046854Z`, validator `command_id:000000004104`, exit `0`, `ok:1`. Applied target completion/confidence updates and exposed three dependency UID-link mistakes from new prose; this run was superseded after correction.
  - `B003-VAL-00042J-class`, timestamp `2026-07-01T21:49:57.0674545Z`, validator `command_id:000000004107`, exit `0`, `ok:1`. Warnings: `missing_ref_uid:89` pre-existing broad MapPane references; `generated_refresh:deferred`; projected stats updated.
  - `B003-VAL-00042J-file`, timestamp `2026-07-01T21:50:02.9427639Z`, validator `command_id:000000004108`, exit `0`, `ok:1`. Warnings: `missing_ref_uid:100` pre-existing broad MapPane references; `stats_row_update 0000L3`; `generated_refresh:deferred`; projected stats updated.
  - `B003-VAL-00042J-aggregate`, timestamp `2026-07-01T21:50:12.6693173Z`, validator `command_id:000000004109`, exit `0`, `ok:1`. No target-specific warnings; `stats_incremental_noop 0001AP`; `generated_refresh:deferred`; projected stats updated.
  - `B003-VAL-00042J-target-rerun`, timestamp `2026-07-01T21:50:21.7102962Z`, validator `command_id:000000004110`, exit `0`, `ok:1`. Confirmed corrected target and removed erroneous reference-index entries for `0001D2`, `0000TX`, and `0000MX`; `generated_refresh:deferred`; projected stats updated.
- Generated/coverage side effects: validators updated `project-level/-auto-completion-stats.md` projected stats. No manual generated or coverage files were edited. Generated refresh was deferred by every validator command.

## Changed Files

- Implementation callback by-* edits:
  - `by-memory/0x005061e0-0x005062e5.MapPaneRefreshNearbyObjectRows.md`
  - `by-class/MapPane.md`
  - `by-file/MapPane.md`
  - `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`
- Report ledger/checklist edit:
  - `tools/leaser/Agents/Agent-B003/research/00042J-MapPaneRefreshNearbyObjectRows-by-memory-source-quality.md`
- Validator side-effect:
  - `project-level/-auto-completion-stats.md`
- Explicitly not edited:
  - `by-type/by-struct/MapPaneLayout.md` because `+0x424 m_objectList` already records object-list create/update, remove/detach/intersect, movement collision, reindexing, and timer lookup usage at same-or-greater detail.
  - `by-memory/-ignored.md` because `0x005061d3-0x005061e0` and `0x005062e5-0x005062f0` adjacent padding spans were already present and correctly exclude the target body.
  - No generated C++/coverage/tracker files, IDA DB files, target-unrelated by-* docs, support-unlisted docs, queue files, or lock files were manually edited.
- Leases: B003 leased the four accepted by-* docs before editing, released all four immediately after the edit/validator batch, and verified `tools/leaser/lease.json` had no B003 or relevant-path entries.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: user supplied accepted implementation callback on 2026-07-01.
- [x] Target doc `by-memory/0x005061e0-0x005062e5.MapPaneRefreshNearbyObjectRows.md`: metadata is `87/89`, owner/reconstructable/blank emitter/blank C++ preserved, and target now includes current MCP evidence, raw range/instruction summary, dependency roles, no-route proof, no-code proof, rejected alternatives, generated-route caveat, and score rationale.
- [x] Support doc `by-class/MapPane.md`: UID00042J is refreshed as a non-emitting raw no-route nearby object-row refresh sibling; class C++ and score unchanged.
- [x] Support doc `by-file/MapPane.md`: UID00042J is refreshed as part of the `MapPane.cpp` source family but not a generated-output route; file score unchanged.
- [x] Support doc `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`: UID00042J covered-range row and change log now include the 2026-07-01 recheck; aggregate score/metadata unchanged.
- [x] Support doc `by-type/by-struct/MapPaneLayout.md`: excluded with proof because `+0x424 m_objectList` already carried same-or-greater detail.
- [x] Support doc `by-memory/-ignored.md`: excluded with proof because adjacent padding spans were already present and correct.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score changes applied: target `85/85` -> `87/89`; all other listed docs had no score change.
- [x] Score-limiting blockers preserved: no function, no xref/pointer/local-name route, no generated route, behavior/dependency roles, owner/source placement, and C++ no-code proof.
- [x] Owner/emitter/reconstructable disposition preserved: `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank C++.
- [x] Split/rename/new-child changes: none applied because none were accepted or recommended.
- [x] Source-placement/range/padding changes: MapPane source family and current non-emitting output route documented; no range or padding docs changed.
- [x] First-draft C++ or no-code proof: no-code proof applied; no C++ inserted.
- [x] Third-party import directive: not applicable.
- [x] Historical/stale assumptions and negative evidence preserved: B009 retained as lead only; current B003 MCP no-route evidence preserved.
- [x] Wave2/Wave3 mentions: no current Wave2/Wave3 override found; generated output used only as non-authoritative current state.
- [x] Validators run after accepted callback: target, MapPane class, MapPane file, aggregate, plus target rerun after dependency UID correction.
- [x] Generated report refresh: validators reported `generated_refresh:deferred`; no manual generated/coverage/tracker edit performed.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support doc details incorporated at report-level detail or summarized in required support docs.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly excluded with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale; only original reachability/source declaration remains unresolved because current route evidence is negative.
- [x] Validators run and results recorded with command IDs/timestamps/exits/warnings.
- [x] Generated report refresh status recorded: deferred by validators; projected stats updated.
- [x] Remaining unapplied accepted items: none. Optional layout and `-ignored` edits were excluded because evidence was already present.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/00042J-MapPaneRefreshNearbyObjectRows-by-memory-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/00042J-MapPaneRefreshNearbyObjectRows-by-memory-source-quality.md","timestamp":"2026-07-01T17:55:32","uid":"00042J"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
