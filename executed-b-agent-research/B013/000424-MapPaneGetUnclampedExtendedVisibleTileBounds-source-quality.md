** TARGET-REPORT-UID:000424 **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000424 MapPaneGetUnclampedExtendedVisibleTileBounds Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:000424] as a reconstructable, MapPane-owned, non-emitting raw helper; improve the target page with current MCP-backed range, byte, no-route, sibling, field, and no-code proof.
- Final disposition: `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank formal `RECONSTRUCTION_CPP CODE` should remain. Do not insert a C++ body for this pass.
- Required action: update the target/support docs with the current 2026-06-29 evidence and raise the target from `85/85` to `87/89` if the supervisor accepts the report.
- Confidence: high for behavior, range, owner, and current no-route proof; lower for original source declaration and final output route because no modeled function, caller, pointer, or table route exists.

## Supporting Research

## Target

- Target UID: `000424`
- Target path: `by-memory/0x005053f0-0x0050542d.MapPaneGetUnclampedExtendedVisibleTileBounds.md`
- Assignment ID: `B013-report-000424-MapPaneGetUnclampedExtendedVisibleTileBounds-source-quality-20260629`
- Source queue row: `auto-generated/-ag-research-tracker.md` -> `by-memory` -> `Not-Covered Files - Reconstructable`; row lists `85/85`, combined `85.0`, reconstructable `true`, reports `0`.
- Current generated coverage: `auto-generated/-ag-coverage-report-by-memory.md` lists UID000424 as `emits_code:false`; `auto-generated/-ag-memory-coverage.md` lists it as `non-emits`, owner `00007Q`, no emitters, no code.

## Current Target State

- Existing metadata: `COMPLETION:85`, `CONFIDENCE:85`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++ block, `Nested:0`.
- Existing summary: raw source-shaped MapPane helper that builds extended visible bounds without dimension clipping; no current IDA function, xref, or pointer route is known.
- Existing direct owner: [UID:00007Q] `MapPane`.
- Existing source/file route context: [UID:0000L3] `MapPane` / `NexusTK/map/MapPane.cpp`, through the MapPane class owner. This target should not emit through that route until entry reachability is proven.
- Parent aggregate: [UID:0001AP] `0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore`.
- Related support docs checked: [UID:000423] `MapPaneGetExtendedVisibleTileBounds`, [UID:000420] `MapPaneGetClampedVisibleTileBounds`, [UID:000421] `MapPaneGetVisibleTileBounds`, [UID:000422] `MapPaneGetVisibleTileSpan`, [UID:00042K] `MapPaneLayout`, [UID:00007Q] `MapPane`, [UID:0000L3] `MapPane`.

## Executive Recommendation

The best direct semantic owner is still [UID:00007Q] `MapPane`: the raw body receives `this` in `ECX`, reads established MapPane layout offsets `+0x3fc/+0x400/+0x404/+0x408`, and writes the same four-int `MapRect` shape used by the adjacent visible-bounds helpers.

The best output disposition is still non-emitting. Current MCP rechecked the exact raw range and found no IDA function at `0x005053f0`, no incoming xrefs, no absolute VA/pointer-byte hits, no named entity in the range, and decompilation failure at the raw start. Emitting a `MapPane::GetUnclampedExtendedVisibleTileBounds` body now would create a generated `MapPane.cpp` method with no proven original callsite, address-taken route, vtable route, table route, or modeled function entry. That would improve apparent coverage by inventing reachability.

## Supervisor Active Recheck

- The assignment specifically required rechecking `0x005053f0-0x0050542d`, no-function status, xrefs, pointer/literal VA searches, raw bytes, sibling [UID:000423], MapPane offsets, owner route through [UID:00007Q], parent [UID:0001AP], and C++/no-code disposition.
- This is report-only research. No by-* docs, generated files, validator state, lock files, IDA DB, or support docs were edited.
- No split repair is required. The target range remains a single raw half-open code range `0x005053f0-0x0050542d`, followed by `0x0050542d-0x00505430` alignment already recorded in `by-memory/-ignored.md`.

## Inference Research Guidance Check

- Direct IDA/MCP facts are separated below from documentation evidence and inference.
- Current by-structure rules allow a page to have a concrete owner but no emitter when ownership is known and generated-output routing is not ready or not applicable.
- The current code-entry gate is not met because the page has no confirmed nonblank `EMITTER_UIDS`; the average score alone is not sufficient.
- Stale Wave2/Wave3 material was not used as proof. Old reports were used only as leads and checked against current MCP evidence.

## Heuristic / Inference Reanalysis And Validation

- Raw helper liveness: current MCP validates B009's earlier classification. `0x005053f0` is not an IDA function, but `insn_query` shows a normal prologue/body/epilogue and MapPane field reads/writes. The range is source-authored code, not padding or a generated alignment artifact.
- Source-facing name: `MapPaneGetUnclampedExtendedVisibleTileBounds` remains the best documentation name because the body matches [UID:000423] `MapPaneGetExtendedVisibleTileBounds` before the clamp phase and omits only the dimension-bound clamping. This is better than raw `sub_` wording and more specific than a generic rectangle helper.
- Field/type inference: `ECX` is `MapPane *`; `[ebp+8]` is an output `MapRect *`; offsets `+0x3fc/+0x400/+0x404/+0x408` are the accepted tile origin and visible tile span fields. This inference is validated by [UID:00042K] `MapPaneLayout`, [UID:000420], [UID:000421], [UID:000422], [UID:000423], and the current raw instruction sequence.
- Owner inference: MapPane is the narrowest true semantic owner. The parent aggregate and file route explain source placement, but they do not replace the class owner. ObjectList, MapPaneSpatialIndex, sibling callers, and generated output are rejected as owners because UID000424 has no object-list access, no caller surface, and no narrower non-MapPane receiver evidence.
- C++ readiness: behavior is source-quality enough to describe, but not enough to emit. Current evidence lacks the source declaration/reachability route required for a formal C++ block. Blank C++ is a target-specific no-code proof, not an original-name deferral.
- Score blocker resolution: the named blockers are resolved as follows: no modeled function confirmed; no xref/pointer route confirmed; owner and field names resolved; no split/range repair needed; first-draft C++ rejected with exact no-code proof; support-doc updates are implementation-ready.
- Rejected alternatives: emit through [UID:00007Q] anyway, route through [UID:0000L3] directly, merge with [UID:000423], classify as ignored padding, leave the target at generic no-route wording, or set no-owner. Each would either invent reachability, lose a real raw code body, or obscure the current owner/source-shape evidence.

## Evidence Checked

- Required workflow files: `Agent-B013/goal.md`, `ntk-b-agent-workflow` skill, `b-agent-research-and-implementation-workflow.md`, `score-blocker-audit-standard.md`, `b-agent-report-template.md`, `by-structure.md` relevant MCP/metadata sections.
- Current IDA MCP endpoint: `http://127.0.0.1:13337/mcp`.
- Current IDA database session used: `B005_00049P_20260629`, created by another client after initial `idb_list` returned no sessions. B013 did not call `idb_open`, start, stop, restart, or kill MCP/IDA/Python processes.
- MCP health: `server_health` returned `status:"ok"`, `idb_path:"E:\NTK\Resources\NexusTK\NexusTK.exe.i64"`, `module:"NexusTK.exe"`, `input_path:"C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe"`, `imagebase:"0x400000"`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.
- MCP calls: `lookup_funcs`, `get_bytes`, `insn_query`, `xrefs_to`, `xref_query`, `find_bytes`, `entity_query`, `decompile`, and `int_convert`.
- Old-report search terms: `000424`, `0x005053f0`, `0x5053f0`, `MapPaneGetUnclampedExtendedVisibleTileBounds`, `GetUnclampedExtendedVisibleTileBounds`, `UnclampedExtended`, `0x00505370`, `MapPaneGetExtendedVisibleTileBounds`, `00007Q`, `0001AP`, `MapPaneWeatherCoordinateObjectCore`, `visible bounds`, `extended visible`.
- Matching old reports opened: `executed-b-agent-research/B009/0001AP-MapPaneWeatherCoordinateObjectCore-source-quality.md`, `executed-b-agent-research/B007/00035C-SurfacePaletteCallbackForwarderRaw-empty-emitter-source-quality.md`, and `executed-b-agent-research/B005/0001AR-DrawVisibleTilesHelper-source-quality.md` excerpts.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C001 | UID000424 is currently `85/85`, owner `00007Q`, reconstructable, blank emitter, blank C++. | High | Target page header and tracker row. | Target Status / metadata; target Changes | incorporate | applied |
| C002 | Current MCP session `B005_00049P_20260629` is healthy and backed by NexusTK IDB. | High | `server_health` structured output. | Target `Current MCP Evidence` / Changes | incorporate | applied |
| C003 | `lookup_funcs` reports no function at `0x005053f0` or `0x0050542d`; adjacent modeled functions are `0x00505370` and `0x00505430`. | High | MCP `lookup_funcs` result. | Target `Current MCP Evidence`; `No-Route And No-Code Proof`; parent row | incorporate | applied |
| C004 | The target bytes are source-shaped code, not padding: prologue, MapPane field reads, output writes, epilogue, `retn 4`. | High | MCP `get_bytes` and `insn_query` over `0x005053f0-0x0050542d`. | Target `Range And Bytes`; target `Behavior` | incorporate | applied |
| C005 | The half-open target body is `0x3d` / 61 bytes, followed by `0x0050542d-0x00505430` alignment. | High | MCP `insn_query`; `int_convert` for `0x3d` = 61. | Target `Range And Bytes`; `by-memory/-ignored.md` already-present reason | incorporate | applied |
| C006 | Behavior fills an unclamped extended `MapRect`: left/top are origin minus one; right adds visible columns plus two; bottom adds visible rows plus ten. | High | MCP instruction sequence and sibling decompile comparison. | Target `Behavior`; class/file/parent UID000424 notes | incorporate | applied |
| C007 | Field names `m_tileOriginX`, `m_tileOriginY`, `m_visibleTileColumns`, and `m_visibleTileRows` are already supported by MapPane layout docs. | High | [UID:00042K], [UID:00007Q], and sibling child pages. | Target `Behavior`; `by-type/by-struct/MapPaneLayout.md` left unchanged as already present | incorporate / already-present | applied |
| C008 | `xrefs_to 0x005053f0` returns zero incoming refs; `xref_query both` shows only local fallthrough from `0x5053f0` to `0x5053f1`. | High | MCP `xrefs_to`, `xref_query`. | Target `Current MCP Evidence`; `No-Route And No-Code Proof`; support notes | incorporate | applied |
| C009 | Little-endian absolute VA searches for `F0 53 50 00` and boundary-related patterns returned zero matches. | High | MCP `find_bytes`. | Target `Current MCP Evidence`; `No-Route And No-Code Proof`; support notes | incorporate | applied |
| C010 | Sibling [UID:000423] is a modeled function with six code xrefs and formal C++; UID000424 differs by omitting map-dimension clamps and having no route. | High | MCP `decompile 0x00505370`, `xrefs_to 0x00505370`; sibling page. | Target `Behavior`; class/file/parent visible-bounds notes | incorporate | applied |
| C011 | Best owner remains [UID:00007Q] `MapPane`; direct file owner and other owners are too broad or only dependencies/consumers. | High | ECX receiver field use, MapPane docs, parent aggregate. | Target `Ownership And Source Placement`; class/file support notes | incorporate | applied |
| C012 | Blank `EMITTER_UIDS` and blank formal C++ should remain; no formal C++ insertion text is recommended. | High | No modeled entry, no xrefs, no pointer route, no generated output entry. | Target metadata; target `No-Route And No-Code Proof`; class/file/parent notes | incorporate | applied |
| C013 | `by-memory/-ignored.md` already records `0x005053e4-0x005053f0` and `0x0050542d-0x00505430` as raw-helper-adjacent alignment, not the target body. | High | `rg` of `by-memory/-ignored.md`. | Target `Range And Bytes`; `by-memory/-ignored.md` unchanged | already-present | already-present |
| C014 | Generated coverage currently lists UID000424 as non-emitting, and generated `MapPane.cpp` contains no UID000424 insertion. | High | `rg` of generated MapPane.cpp and generated coverage. | Target `Current MCP Evidence`; generated-refresh checklist note | incorporate | applied |
| C015 | Target detail can improve from `85/85` to `87/89`, but not higher because route/source declaration remains unresolved. | Medium-high | Current MCP proof plus unresolved emitter/source declaration. | Target metadata; target `Status`; target `Changes`; validator `000000001223` | incorporate | applied |

## Positive Evidence Summary

- The bytes at `0x005053f0` are real code-shaped instructions:

```text
55 8b ec 56 8b b1 00 04 00 00 57 8b 7d 08 4e 89
77 04 8b 91 fc 03 00 00 4a 89 17 8b 81 08 04 00
00 83 c0 0a 03 c6 89 47 0c 8b 81 04 04 00 00 83
c0 02 03 c2 89 47 08 5f 5e 5d c2 04 00
```

- Instruction scan:
  - `0x5053f0 push ebp`; `0x5053f1 mov ebp, esp`.
  - `0x5053f4 mov esi, [ecx+400h]`; `0x5053fe dec esi`; `0x5053ff mov [edi+4], esi`.
  - `0x505402 mov edx, [ecx+3FCh]`; `0x505408 dec edx`; `0x505409 mov [edi], edx`.
  - `0x50540b mov eax, [ecx+408h]`; `0x505411 add eax, 0Ah`; `0x505414 add eax, esi`; `0x505416 mov [edi+0Ch], eax`.
  - `0x505419 mov eax, [ecx+404h]`; `0x50541f add eax, 2`; `0x505422 add eax, edx`; `0x505424 mov [edi+8], eax`.
  - `0x505427-0x50542a` restores registers/frame and returns with `retn 4`.
- Field offsets are the accepted MapPane layout:
  - `+0x3fc` = `m_tileOriginX`.
  - `+0x400` = `m_tileOriginY`.
  - `+0x404` = `m_visibleTileColumns`.
  - `+0x408` = `m_visibleTileRows`.
- The raw body is a direct unclamped sibling of `0x00505370`:
  - `0x00505370` decompiles as the clamped extended bounds helper.
  - UID000424 has the same top/left/right/bottom construction but omits the `top/left >= 0` and `bottom/right <= map dimensions` clamp branches.

## IDA MCP Facts

- `lookup_funcs` in `0x00505280-0x00505440` reports only these functions:
  - `0x00505290 sub_505290 size 0x74`
  - `0x00505310 sub_505310 size 0x3d`
  - `0x00505350 sub_505350 size 0x1b`
  - `0x00505370 sub_505370 size 0x74`
  - `0x00505430 sub_505430 size 0x19a`
- `lookup_funcs 0x005053f0` -> `Not a function`.
- `lookup_funcs 0x0050542d` -> `Not a function`.
- `entity_query(kind=functions, min_addr=0x00505280, max_addr=0x00505440)` returns the same five modeled functions and no UID000424 function.
- `entity_query(kind=names, min_addr=0x00505280, max_addr=0x00505440)` returns no named entities.
- `decompile 0x005053f0` returns `code:null`, `error:"Decompilation failed at 0x5053f0"`.
- `xrefs_to 0x005053f0` returns `xref_count:0`.
- `find_bytes` with `F0 53 50 00` returns zero matches.
- Generated `auto-generated/NexusTK/map/MapPane.cpp` is refreshed at validator command `000000001210` and has no UID000424 block.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00505370-0x005053e4` | [UID:000423] `MapPaneGetExtendedVisibleTileBounds` | Modeled clamped extended visible-bounds method | TRUE | [UID:00007Q] | `88/90` | emits through MapPane |
| `0x005053e4-0x005053f0` | [UID:0000VN] ignored ledger | `0xcc` alignment | FALSE | n/a | n/a | already documented padding |
| `0x005053f0-0x0050542d` | [UID:000424] target | Raw no-route unclamped extended visible-bounds helper | TRUE | [UID:00007Q] | current `85/85`, recommend `87/89` | keep non-emitting |
| `0x0050542d-0x00505430` | [UID:0000VN] ignored ledger | `0xcc` alignment | FALSE | n/a | n/a | already documented padding |
| `0x00505430-0x005055ca` | [UID:000425] `MapPaneCheckMovementCollision` | Modeled movement collision method | TRUE | [UID:00007Q] | `86/87` | emits through MapPane |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x005053f0` | zero incoming xrefs | No modeled call, jump, data, table, or pointer route into target start. |
| `0x005053f0 -> 0x005053f1` | local fallthrough only in `xref_query both` | Internal code-flow fact, not reachability. |
| `0x00505370` | six incoming code xrefs from `0x505764`, `0x505bce`, `0x510dc3`, `0x510ddc`, `0x5112b3`, `0x5112cc` | Positive-control sibling is reachable and therefore emits. |
| `0x00505430` | nine incoming code xrefs from tile/path/object consumers | Next modeled function is reachable and separate from UID000424. |

## Documentation Evidence And IDA Status

- [UID:0001AP] already records UID000424 as a raw no-route MapPane child and records adjacent alignment spans.
- [UID:00007Q] and [UID:0000L3] already establish MapPane coordinate/visible-bounds source placement under `NexusTK/map/MapPane.cpp`.
- [UID:00042K] `MapPaneLayout` already records the required offset vocabulary.
- [UID:000423] emits the clamped extended helper with formal C++; UID000424 is the unclamped raw sibling.
- B009 is still accurate as lead material for UID000424, but the target page should now carry the current target-specific evidence rather than only referring to the accepted parent report.

## Ranked Ownership Analysis

### 1. [UID:00007Q] MapPane class

- Evidence for: `ECX` receiver; field offsets are established MapPane layout; sibling bounds helpers are MapPane methods; parent aggregate and class/file docs place coordinate and visible-bounds helpers under MapPane.
- Evidence against: no modeled function entry or caller proves a source declaration site for this exact raw helper.
- Decision: keep as `CANONICAL_OWNER:00007Q`; do not use owner as an emitter route without reachability.

### 2. [UID:0000L3] MapPane file

- Evidence for: MapPane class routes to `NexusTK/map/MapPane.cpp`; adjacent coordinate helpers live in this source family.
- Evidence against: direct owner should be the class, not the file, because the raw body is `thiscall`-shaped and reads MapPane fields.
- Decision: source-placement context only; do not change `CANONICAL_OWNER` to `0000L3`.

### 3. [UID:0001AP] parent aggregate

- Evidence for: exact containment and already accepted split inventory.
- Evidence against: aggregate is an index over children, not the direct semantic owner or an appropriate source emitter for a child method body.
- Decision: keep as parent/support evidence. Do not route UID000424 through the aggregate.

### 4. ObjectList / MapPaneSpatialIndex / caller-owner alternatives

- Evidence for: nearby MapPane helper family uses ObjectList and map object indexing elsewhere.
- Evidence against: UID000424 does not read `m_objectList`, does not call object-list helpers, and has no caller set that would suggest a consumer owner.
- Decision: reject.

### 5. No-owner / unknown owner

- Evidence for: no source route.
- Evidence against: receiver and field evidence are strong enough to identify MapPane as the semantic owner.
- Decision: reject no-owner. The blocker is emission route, not ownership.

## Source Placement

- Recommended source family: `NexusTK/map/MapPane.cpp`, through [UID:00007Q] -> [UID:0000L3].
- Recommended generated-output placement: none yet. Keep blank `EMITTER_UIDS`.
- Rejected generated-output placement: adding `EMITTER_UIDS:00007Q` now would make generated `MapPane.cpp` contain a method body with no proven source-use route.
- Remaining placement uncertainty: whether the raw body was a dead/private method, an optimized-away address-taken helper whose reference was removed from current IDA modeling, or orphaned source bytes from a build configuration. Current evidence cannot choose among those safely.

## Range / Split / Padding / Reclassification Analysis

- Exact raw helper range remains `0x005053f0-0x0050542d`.
- The body length is `0x3d` / 61 bytes (Verified with `int_convert`).
- `0x005053e4-0x005053f0` and `0x0050542d-0x00505430` are already documented pure alignment in `by-memory/-ignored.md`.
- No child split, merge, rename, or reclassification is recommended.

## Negative Evidence Summary

- No IDA function at the target start.
- No decompile result for the target start.
- No incoming xrefs to the target start.
- No absolute pointer/literal-byte hits for `0x005053f0`.
- No named entity in the immediate target range.
- No generated C++ insertion for UID000424.
- No direct support for a vtable route, callback table route, import/thunk route, parent marker route, or source-visible declaration route.
- The sibling's six xrefs do not transfer to UID000424; they prove the sibling is reachable and UID000424 is different.

## IDA Rename / Type / Comment Recommendations

- Source-facing target name `MapPaneGetUnclampedExtendedVisibleTileBounds` remains the best documentation name.
- If this ever becomes emitting, the ordinary C++ declaration family would likely be a private `MapPane` method taking `MapRect *outBounds` and marked `const`, but this report does not recommend inserting that declaration or C++ body because the source-use route is unproven.
- Do not edit the IDA DB in this report-only pass.

## First-Draft C++ Recommendation

- Eligible for draft C++ now: no.
- Recommended code: none. No formal C++ insertion text is supplied because this report recommends blank C++.
- Exact no-code proof: current MCP proves the bytes are custom MapPane code but not a modeled function; no current caller/xref, pointer-byte/literal route, name, vtable, table, or generated-output route exists. The by-structure code gate also requires a confirmed nonblank emitter route before C++ can be entered. Therefore formal C++ should remain blank even though the behavior is now well understood.
- Reason this is not a generic "unknown" deferral: the report resolves behavior, field names, owner, sibling relationship, range, padding, generated state, and rejected alternatives. The only blocker is current source reachability/output route.

## Recommended Target Doc Changes

Target path: `by-memory/0x005053f0-0x0050542d.MapPaneGetUnclampedExtendedVisibleTileBounds.md`

- Change metadata to:
  - `COMPLETION:87`
  - `CONFIDENCE:89`
  - Keep `CANONICAL_OWNER:00007Q`
  - Keep `RECONSTRUCTABLE:TRUE`
  - Keep blank `EMITTER_UIDS`
  - Keep blank `EMITTER_POSITION_OPTIONAL`
  - Keep formal C++ block blank
- Replace or expand the item summary with:
  - `Raw source-shaped MapPane helper that fills an unclamped extended MapRect from tile origin and visible-span fields; current MCP confirms no modeled function, xref, pointer/literal VA, or emitter route, so it remains reconstructable but non-emitting.`
- Add current MCP evidence: session ID, health status, lookup result, raw bytes/instruction summary, xrefs result, pointer-byte search result, decompile failure, generated non-emits status.
- Add behavior detail: `outBounds->top = m_tileOriginY - 1`, `left = m_tileOriginX - 1`, `bottom = top + m_visibleTileRows + 10`, `right = left + m_visibleTileColumns + 2`, with no dimension clamps.
- Add sibling comparison with [UID:000423]: UID000423 performs the same extended rectangle construction plus clamps; UID000424 omits the clamps and has no route.
- Add a `Formal No-Code Proof` section preserving why blank C++ is intentional under current by-structure rules.
- Add rejected alternatives: emit through MapPane, direct file owner, no-owner, padding/ignored, sibling merge, and generated-name-only treatment.

## Recommended Support Doc Changes

Support path: `by-class/MapPane.md`

- In the coordinate/visible-bounds family, explicitly list [UID:000424] as the non-emitting raw no-route unclamped extended bounds sibling of [UID:000423].
- Record that UID000424 is owner-documented MapPane code but should not be emitted until a caller/pointer/table/source declaration route is found.
- No score change required for the class page.

Support path: `by-file/MapPane.md`

- In the coordinate conversion / [UID:0001AP] helper split notes, include UID000424 as a documented non-emitting raw helper in the MapPane.cpp source family, not an emitted method.
- Preserve the source-route distinction: `MapPane.cpp` is the source family, but UID000424 has no generated-output route yet.
- No score change required for the file page.

Support path: `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`

- Add a short 2026-06-29 recheck note or update the UID000424 row to say current B013 MCP reconfirmed no function/xref/pointer route and refined the target-specific no-code proof.
- No score or metadata change required for the aggregate.

Support path: `by-type/by-struct/MapPaneLayout.md`

- No mandatory edit. The relevant offsets are already present at same-or-greater detail. If implementation wants a cross-reference, add UID000424 to the offsets `+0x3fc/+0x400/+0x404/+0x408` evidence list, but this is optional.

Support path: `by-memory/-ignored.md`

- No edit required. The adjacent padding spans are already present and correctly exclude the raw helper body.

## Score And Metadata Recommendation

- Current target score/metadata: `85/85`, owner `00007Q`, reconstructable true, blank emitter and C++.
- Recommended target score/metadata: `87/89`, owner `00007Q`, reconstructable true, blank emitter and C++.
- Reason not lower: behavior, bytes, exact range, owner, adjacent padding, sibling comparison, field names, generated non-emits state, and no-route evidence are now current and implementation-ready.
- Reason not higher: no modeled function entry, caller, pointer/literal route, source declaration, or generated-output route exists. This blocks formal C++ and prevents final-source confidence.
- Metadata fields to leave unchanged: owner, reconstructable, emitter fields, formal C++ block, nested count.

## Open Questions With Attempted Resolution

- Open question: Is this padding? Resolved no. It has normal prologue/body/epilogue instructions and MapPane field reads/writes.
- Open question: Is the owner unknown? Resolved no. MapPane receiver and field offsets are sufficient for semantic owner.
- Open question: Should it emit C++ through MapPane? Resolved no for current pass. No entry route is proven, and current rules require a confirmed emitter route.
- Open question: Is there a source-facing name/type? Resolved enough for documentation: `MapPaneGetUnclampedExtendedVisibleTileBounds`, `MapRect *outBounds`, and established MapPane field names. Not resolved enough for formal output because source declaration/reachability is missing.
- Remaining unresolved issue: the original reason this raw helper body exists in the binary. Evidence required to change the recommendation would be a direct branch/call, pointer/table entry, recovered source declaration, or other durable route into `0x005053f0`.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual `-coverage-report.md` or tracker edit is required. Generated reports should refresh through validator execution after accepted by-* edits.

## Follow-Up Actions

- Supervisor: validate this report and, if accepted, send B013 an implementation callback for the target/support docs listed above.
- B013 callback: edit only the accepted target/support docs under normal leases, keep C++ blank, run scoped validators, and update this report checklist.
- Future research trigger: only reopen C++ emission if a new route into `0x005053f0` is found.

## Confidence

- Recommendation confidence: high for non-emitting disposition.
- Score confidence: medium-high; `87/89` is justified by current target-specific evidence but should stay below 90/90 because no route exists.
- Remaining uncertainty: original source declaration and why this unreachable raw body remains in `.text`.

## Validator Results

- Callback validators run from `E:\NTK\GhidraBridge\source-3\project-documentation`:
  - `python .\tools\validator.py --mode file --file by-memory/0x005053f0-0x0050542d.MapPaneGetUnclampedExtendedVisibleTileBounds.md --apply --queue-timeout 240`
    - `command_id: 000000001223`
    - `command_timestamp: 2026-06-29T21:22:59-04:00`
    - Exit code: `0`
    - `ok: 1`
    - Applied target metadata updates: `COMPLETION:87`, `CONFIDENCE:89`.
    - Validator side effects: `uid_link_insert` for UID000423, `reference_index_add` for UID0000L3/UID0000VN/UID00042K, projected stats update, and stats row removals for UID000424.
    - Generated refresh state: `generated_refresh: deferred`, `generated_refresh_command_id: 000000001223`, `generated_refresh_timestamp: 2026-06-29T21:22:59-04:00`.
  - `python .\tools\validator.py --mode file --file by-class/MapPane.md --apply --queue-timeout 240`
    - `command_id: 000000001224`
    - `command_timestamp: 2026-06-29T21:23:06-04:00`
    - Exit code: `0`
    - `ok: 1`
    - Warnings/diagnostics: `missing_ref_uid: 89` for preexisting MapPane references not present in `validator.ini`; not target-specific to UID000424.
    - Validator side effects: projected stats update; stats incremental noop for UID00007Q.
    - Generated refresh state: `generated_refresh: deferred`, `generated_refresh_command_id: 000000001224`, `generated_refresh_timestamp: 2026-06-29T21:23:06-04:00`.
  - `python .\tools\validator.py --mode file --file by-file/MapPane.md --apply --queue-timeout 240`
    - `command_id: 000000001225`
    - `command_timestamp: 2026-06-29T21:23:17-04:00`
    - Exit code: `0`
    - `ok: 1`
    - Warnings/diagnostics: `missing_ref_uid: 100` for preexisting MapPane file references not present in `validator.ini`; not target-specific to UID000424.
    - Validator side effects: `stats_row_update 0000L3 project-level/-auto-completion-stats.md Low_Confidence_Not_Reconstructable` and projected stats update.
    - Generated refresh state: `generated_refresh: deferred`, `generated_refresh_command_id: 000000001225`, `generated_refresh_timestamp: 2026-06-29T21:23:17-04:00`.
  - `python .\tools\validator.py --mode file --file by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md --apply --queue-timeout 240`
    - `command_id: 000000001226`
    - `command_timestamp: 2026-06-29T21:23:24-04:00`
    - Exit code: `0`
    - `ok: 1`
    - Validator side effects: `uid_link_insert` for UID000423, projected stats update, and stats incremental noop for UID0001AP.
    - Generated refresh state: `generated_refresh: deferred`, `generated_refresh_command_id: 000000001226`, `generated_refresh_timestamp: 2026-06-29T21:23:24-04:00`.
- Optional validator for `by-type/by-struct/MapPaneLayout.md` was not run because the optional layout cross-reference was excluded: the offset ledger already records `+0x3fc/+0x400` and `+0x404/+0x408` at sufficient detail.

## Changed Files

- Created by this report-only pass: `tools/leaser/Agents/Agent-B013/research/000424-MapPaneGetUnclampedExtendedVisibleTileBounds-source-quality.md`
- Modified during callback:
  - `by-memory/0x005053f0-0x0050542d.MapPaneGetUnclampedExtendedVisibleTileBounds.md`
  - `by-class/MapPane.md`
  - `by-file/MapPane.md`
  - `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`
  - `tools/leaser/Agents/Agent-B013/research/000424-MapPaneGetUnclampedExtendedVisibleTileBounds-source-quality.md`
- Not edited by B013 callback: `by-type/by-struct/MapPaneLayout.md` because the offset evidence was already present; `by-memory/-ignored.md` because adjacent padding wording was already correct; generated reports, generated C++, manual coverage reports, project-level generated files, and validator state were not manually edited.
- Leases: B013 leased the four edited by-* docs immediately before editing/validation and released them immediately after the validator batch. The post-release lease report showed no active leases.
- Validator-owned side effects were reported in the validator output: projected stats updates to `project-level/-auto-completion-stats.md`, reference/index updates reflected through `tools/validator.ini`, and deferred generated refresh state. No generated or coverage file was manually edited.
- Report execution: leave for supervisor after callback verification.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: supervisor accepted the report for implementation callback in the 2026-06-29 callback prompt.
- [x] Target doc `by-memory/0x005053f0-0x0050542d.MapPaneGetUnclampedExtendedVisibleTileBounds.md`: update metadata to `87/89`, keep owner/reconstructable/blank emitter/blank C++, replace item summary, add current MCP evidence, raw bytes/instruction summary, sibling comparison, no-route proof, no-code proof, rejected alternatives, generated non-emits state, and score rationale. Proof: target metadata now `87/89`; sections `Current MCP Evidence`, `Range And Bytes`, `Behavior`, `Ownership And Source Placement`, `No-Route And No-Code Proof`, `Rejected Alternatives`, and `Changes`; validator `000000001223`, exit `0`, `ok:1`.
- [x] Support doc `by-class/MapPane.md`: add/refresh UID000424 as a non-emitting raw no-route unclamped extended bounds sibling in the coordinate/visible-bounds family; keep class C++ blank and no score change. Proof: `2026-06-25 0001AP Helper Split` section now includes the B013 2026-06-29 UID000424 paragraph; `Changes` has the callback row; validator `000000001224`, exit `0`, `ok:1`.
- [x] Support doc `by-file/MapPane.md`: add/refresh UID000424 as part of the MapPane.cpp coordinate helper source family but not a generated-output route; no score change. Proof: `MapPane Subsystems` coordinate conversion row and the 0001AP source-family note both mention UID000424 as raw/non-emitting and not a generated-output route; `Changes` has the callback row; validator `000000001225`, exit `0`, `ok:1`.
- [x] Support doc `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`: add a 2026-06-29 UID000424 recheck note if supervisor accepts; no score/metadata change. Proof: covered-range row and `Changes` record the B013 recheck; validator `000000001226`, exit `0`, `ok:1`.
- [x] Support doc `by-type/by-struct/MapPaneLayout.md`: confirm offsets are already present; optional cross-reference only if supervisor wants it. Proof: no edit made; existing `Focused Offset Ledger` already documents `+0x3fc/+0x400` as `m_tileOriginX/m_tileOriginY` and `+0x404/+0x408` as `m_visibleTileColumns/m_visibleTileRows`; excluded as already-present/sufficient.
- [x] Support doc `by-memory/-ignored.md`: confirm adjacent padding spans already present; no edit needed unless supervisor asks for a wording sync. Proof: no edit made; target `Range And Bytes` points to existing [UID:0000VN][-ignored](by-memory/-ignored.md) padding spans and preserves the raw helper body as not padding.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim. Proof: rows C001-C015 are marked `applied` or `already-present`.
- [x] Metadata/score changes to apply: target `85/85` -> `87/89`; all other listed docs no score change. Proof: target header and validator `000000001223` show completion/confidence update; support doc headers unchanged by this callback.
- [x] Score-limiting blockers resolved in the docs: no function, no xref/pointer route, no generated route, source-facing names/fields, sibling relationship, and C++ no-code proof. Proof: target `Current MCP Evidence`, `Behavior`, `No-Route And No-Code Proof`, and support notes.
- [x] Owner/emitter/reconstructable changes to apply: keep `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank C++. Proof: target metadata preserved those fields; no formal C++ inserted.
- [x] Split/rename/new-child changes to apply: none. Proof: no new files, no range rename, no child split performed.
- [x] Source-placement/range/padding changes to apply: document MapPane source family and current non-emitting output route; no range or padding edits. Proof: target `Ownership And Source Placement`, file-page UID000424 source-family note, and unchanged `-ignored`.
- [x] First-draft C++ or no-code proof to apply: apply the exact no-code proof; do not insert C++. Proof: target `No-Route And No-Code Proof`; formal C++ block remains blank.
- [x] Third-party import directive: not applicable. Proof: no third-party source involved.
- [x] Historical/stale assumptions and negative evidence to preserve: B009 parent report was a lead; current B013 MCP reconfirms the no-route state. Preserve zero xrefs, zero pointer-byte hits, no function, no decompile, no generated output, and rejected emission alternatives. Proof: target evidence/no-code/rejected alternatives sections and parent aggregate note.
- [x] Wave2/Wave3 mentions: no current Wave2/Wave3 override found; generated output used only as non-authoritative current state. Proof: no Wave2/Wave3 edit introduced; target generated state is documented as current state, not source authority.
- [x] Open questions to close or document as evidence-backed unresolved: original source declaration/reachability remains unresolved; document evidence required to change disposition. Proof: target no-code proof and ownership/source placement sections document required future evidence.
- [x] Validators to run after accepted implementation: target and each changed support doc with `--mode file --apply --queue-timeout 240`; report command IDs, timestamps, exit codes, ok counts, and generated refresh state. Proof: validator results section records commands `000000001223` through `000000001226`.
- [x] Generated report refresh expected through validator; no manual coverage/tracker text required. Proof: each validator reported `generated_refresh: deferred`; no generated or manual coverage file was manually edited.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: callback prompt explicitly states `ACCEPTED FOR IMPLEMENTATION CALLBACK`.
- [x] All accepted target/support doc details incorporated at report-level detail. Proof: target/support paths and sections listed above; no accepted by-* item omitted.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim. Proof: rows C001-C015 updated.
- [x] Metadata/score/owner/emitter/C++ changes applied or explicitly not applied with reason. Proof: target changed to `87/89`; owner/reconstructable/blank emitter/blank C++ preserved; class/file/parent scores unchanged as accepted.
- [x] Historical assumptions, rejected alternatives, and negative evidence preserved. Proof: target `Rejected Alternatives` and `No-Route And No-Code Proof`; class/file/parent notes preserve non-emitting route.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale. Proof: target documents that source declaration/reachability remains unresolved and lists evidence required to change disposition.
- [x] Validators run and results recorded. Proof: validator results section records commands `000000001223`, `000000001224`, `000000001225`, and `000000001226`, all exit `0`, `ok:1`.
- [x] Generated report refresh completed by validator or explicit generated-refresh state reported. Proof: generated refresh was explicitly reported as deferred for each scoped validator; no manual generated/coverage edits.
- [x] Remaining unapplied accepted items listed with exact blocker. Proof: none. Optional MapPaneLayout cross-reference and `by-memory/-ignored.md` edits were excluded as already-present/sufficient, not unapplied accepted items.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B013","command_id":"000000004165","destination_path":"executed-b-agent-research/B013/000424-MapPaneGetUnclampedExtendedVisibleTileBounds-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B013/research/000424-MapPaneGetUnclampedExtendedVisibleTileBounds-source-quality.md","timestamp":"2026-06-29T21:30:17","uid":"000424"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
