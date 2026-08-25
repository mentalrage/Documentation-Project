** TARGET-REPORT-UID:00042B **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 00042B MapPaneRawDirectionBoundsScratch By-Memory Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00042B][0x00505750-0x005057c8.MapPaneRawDirectionBoundsScratch](../../../by-memory/0x00505750-0x005057c8.MapPaneRawDirectionBoundsScratch.md) as reconstructable MapPane source-shaped raw code with canonical owner [UID:00007Q][MapPane](../../../by-class/MapPane.md), but keep `EMITTER_UIDS` blank and keep formal C++ empty because current live MCP still proves no entry route, no modeled function, no incoming raw-start xref, no start-pointer hit, and no externally committed effect.
- Final disposition: target-specific no-code proof, not first-draft C++.
- Required action if accepted: update only the target page with the 2026-07-01 live MCP recheck, exact range/table/byte/behavior proof, stale duplicate UID caveat, rejected owner/source routes, and metadata `COMPLETION:86`, `CONFIDENCE:88`; leave MapPane parent/support docs unchanged as already present unless the supervisor explicitly wants a one-line support sync.
- Confidence: strong for no-route/non-emitting disposition and MapPane ownership; intentionally below final-source confidence because the raw helper has no function object, no caller/source declaration, no recoverable original name/signature, and a separate stale duplicate-UID support trail exists in Ranking docs.

## Target

- Target UID: `00042B`
- Target path: `by-memory/0x00505750-0x005057c8.MapPaneRawDirectionBoundsScratch.md`
- Source queue/report row: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`, score `85/85`, combined `85.0`, reconstructable `true`, reports `0`.
- Current supervisor assignment: `B008-report-00042B-MapPaneRawDirectionBoundsScratch-by-memory-20260701`, report-only target-specific research.
- Current generated memory state: `auto-generated/-ag-memory-coverage.md` lists UID00042B as `non-emits`, owner `00007Q`, path `by-memory/0x00505750-0x005057c8.MapPaneRawDirectionBoundsScratch.md`.
- Current generated C++ lead: `auto-generated/NexusTK/map/MapPane.cpp` header `validator-command-id: 000000004059`, `validator-refreshed-at: 2026-07-01T17:13:44-04:00`; it emits neighboring UID000423 and UID000428 bodies but contains no UID00042B marker/body, which agrees with the non-emitting route.

## Current Target State

Existing target metadata:

- `COMPLETION:85`
- `CONFIDENCE:85`
- `CANONICAL_OWNER:00007Q`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:` blank
- `EMITTER_POSITION_OPTIONAL:` blank
- formal `RECONSTRUCTION_CPP CODE` inline and multiline blocks blank

Current target prose already records the accepted B009 0001AP result: UID00042B is a raw no-function MapPane direction/bounds scratch body; accepted evidence said `lookup_funcs 0x00505750` was not a function, `xrefs_to 0x00505750` returned zero incoming refs, absolute pointer search `50 57 50 00` returned zero matches, the body calls [UID:000423][MapPaneGetExtendedVisibleTileBounds](../../../by-memory/0x00505370-0x005053e4.MapPaneGetExtendedVisibleTileBounds.md), owns switch-table bytes `0x005057b8-0x005057c8`, and has no known external effect or call route.

The current page is accurate but thin for the current queue standard. It should preserve B009's conclusion while adding live 2026-07-01 proof for the raw range, switch table behavior, local-only writes, rejected route candidates, and stale duplicate-UID caveat.

## Evidence Checked

IDA MCP was required and available.

- `initialize` succeeded against `ida-pro-mcp 1.0.0`, protocol `2025-06-18`.
- `idb_list` showed active session `supervisor_resume_20260629`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `14860`, `is_analyzing:false`, `owned:true`, `adopted:true`.
- `server_health(database=supervisor_resume_20260629)` returned `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, `strings_cache_size:2067`.
- `tools/list` was checked for current schemas before using `lookup_funcs`, `entity_query`, `xrefs_to`, `xref_query`, `find_bytes`, `get_bytes`, `insn_query`, `decompile`, and `callees`.

Target-specific MCP checks performed:

- `lookup_funcs` for `0x00505740`, `0x00505743`, `0x00505750`, `0x005057b8`, `0x005057c8`, `0x005057d0`, `0x00505370`, `0x00505650`, and `0x005058b0`.
- `entity_query(kind=functions, min_addr=0x00505730, max_addr=0x005057d0)`.
- `xrefs_to` for `0x00505750`, `0x005057b8`, `0x005057c8`, `0x00505370`, `0x00505650`, and `0x005058b0`.
- `xref_query(direction=both)` for `0x00505750`, `0x005057b8`, and `0x005057c8`.
- `find_bytes` for little-endian absolute pointer patterns `50 57 50 00`, `B8 57 50 00`, `C8 57 50 00`, and `D0 57 50 00`.
- `get_bytes` for prepad `0x00505743` size `13`, target range `0x00505750` size `120`, table `0x005057b8` size `16`, and postpad `0x005057c8` size `8`.
- `insn_query` for `0x00505750-0x005057b8`, `0x005057b8-0x005057c8`, and a bounded call/jump scan inside `0x00505750-0x005057b8`.
- `decompile 0x00505750`, which failed as expected for a non-function raw start.
- `callees 0x00505750`, which returned `No function found`.
- `lookup_funcs` and `decompile` for `0x004b7c50` to verify the local rectangle helper called by the raw body; the decompile stores a four-dword rect as left/top/right/bottom.

Documentation and generated inputs checked:

- Target page `by-memory/0x00505750-0x005057c8.MapPaneRawDirectionBoundsScratch.md`.
- Parent aggregate [UID:0001AP][MapPaneWeatherCoordinateObjectCore](../../../by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md).
- Source file page [UID:0000L3][MapPane](../../../by-file/MapPane.md).
- Class page [UID:00007Q][MapPane](../../../by-class/MapPane.md).
- Neighbor helpers [UID:000423][MapPaneGetExtendedVisibleTileBounds](../../../by-memory/0x00505370-0x005053e4.MapPaneGetExtendedVisibleTileBounds.md), [UID:000428][MapPaneGetAdjacentVisibleTileBounds](../../../by-memory/0x00505650-0x00505730.MapPaneGetAdjacentVisibleTileBounds.md), and [UID:00041W][MapPaneDirectionToTileOffset](../../../by-memory/0x00505080-0x00505100.MapPaneDirectionToTileOffset.md).
- `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, and generated `auto-generated/NexusTK/map/MapPane.cpp`.
- Executed report [B009 0001AP MapPaneWeatherCoordinateObjectCore](../../../executed-b-agent-research/B009/0001AP-MapPaneWeatherCoordinateObjectCore-source-quality.md).
- Existing report and doc searches with `00042B`, `0x00505750`, `0x005057c8`, `MapPaneRawDirectionBoundsScratch`, `DirectionBounds`, `MapPane`, `raw helper`, and related raw-helper/source-family terms.

Numeric conversions:

- `0x78` = decimal `120` bytes (Verified with `tools/int_convert.py`).
- `0x10` = decimal `16` bytes (Verified with `tools/int_convert.py`).
- `0x00505750` = decimal `5265232`, little-endian bytes `50 57 50 00` (Verified with `tools/int_convert.py`).
- `0x005057b8` = decimal `5265336`, little-endian bytes `b8 57 50 00` (Verified with `tools/int_convert.py`).
- `0x005057c8` = decimal `5265352`, little-endian bytes `c8 57 50 00` (Verified with `tools/int_convert.py`).

Skipped or failed checks:

- One overly broad combined MCP `insn_query` attempt that included an `op_any` broad scan over `.text` exceeded the 60 second local shell timeout after returning the bounded target-range result. This was not treated as MCP outage because the listener remained healthy and narrowed replacement calls succeeded. The final recommendation does not rely on that broad scan.

## Positive Evidence Summary

Direct IDA/MCP facts supporting the chosen disposition:

- `lookup_funcs 0x00505750` still returns `Not a function`.
- The only modeled functions in `0x00505730-0x005057d0` are predecessor no-op hooks `nullsub_12` at `0x00505730` and `nullsub_41` at `0x00505740`; UID00042B itself is not modeled.
- `get_bytes 0x00505750 size 120` shows a full prologue, 0x24-byte stack frame, security-cookie setup/check, call to `sub_505370`, local `movups` copy between stack rectangles, switch dispatch, two calls to `sub_4B7C50` on the default path, `retn 4`, two-byte alignment at `0x005057b6`, and a 16-byte switch table from `0x005057b8`.
- `insn_query 0x00505750-0x005057b8` decodes 37 instructions and confirms the same source-shaped raw body. The call sites are `0x00505764 -> sub_505370`, `0x0050578d -> sub_4B7C50`, `0x0050579e -> sub_4B7C50`, and `0x005057ab -> __security_check_cookie`.
- `xrefs_to 0x00505370` includes a code reference from raw address `0x00505764` with `fn:null`, proving this raw body reaches the accepted `MapPane::GetExtendedVisibleTileBounds` child even though the raw body itself has no function object.
- `xrefs_to 0x005057b8` reports one internal data xref from `0x0050577a`; `xref_query` shows the table itself references `0x005057a6`. This proves `0x005057b8-0x005057c8` is local switch data owned by UID00042B, not padding and not an external route.
- `find_bytes B8 57 50 00` finds only `0x0050577d`, the immediate table base inside UID00042B's own switch instruction. `find_bytes 50 57 50 00`, `C8 57 50 00`, and `D0 57 50 00` return no matches.
- `get_bytes 0x00505743 size 13` and `get_bytes 0x005057c8 size 8` are all `0xcc`, matching the current parent aggregate and ignored-padding ledger.
- `decompile 0x004b7c50` confirms the called helper writes `a1[0]=left`, `a1[1]=top`, `a1[2]=right`, `a1[3]=bottom`. Thus UID00042B's default path only zeroes local stack rectangles.

Documentation evidence supporting the chosen disposition:

- [UID:0001AP][MapPaneWeatherCoordinateObjectCore](../../../by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md) already identifies UID00042B as a raw no-route direction-bounds scratch body, owns switch-table bytes `0x005057b8-0x005057c8`, and records adjacent `0xcc` spans in [UID:0000VN][-ignored](../../../by-memory/-ignored.md).
- [UID:0000L3][MapPane](../../../by-file/MapPane.md) and [UID:00007Q][MapPane](../../../by-class/MapPane.md) already record the accepted B009 split and state that UID00042B remains source-shaped MapPane evidence, not ignored padding, but non-emitting until a route or retained-helper emission policy is proven.
- [UID:000423][MapPaneGetExtendedVisibleTileBounds](../../../by-memory/0x00505370-0x005053e4.MapPaneGetExtendedVisibleTileBounds.md) already names the raw `0x00505750` scratch body as one of its callers.
- Generated `auto-generated/NexusTK/map/MapPane.cpp` currently emits neighboring reached helpers but does not emit UID00042B, matching the blank emitter route.

## Negative Evidence Summary

Current negative route evidence:

- No IDA function object exists at `0x00505750`, `0x005057b8`, `0x005057c8`, or `0x005057d0`.
- `xrefs_to 0x00505750` returns zero incoming refs and the message `No cross-references to this address`.
- `xref_query 0x00505750 direction=both` finds only an internal fall-through/code flow edge from `0x00505750` to `0x00505751`, not any caller or data route.
- `find_bytes 50 57 50 00` returns zero absolute VA pointer matches to the raw start.
- `find_bytes C8 57 50 00` returns zero matches to the target end, and `find_bytes D0 57 50 00` returns zero matches to the successor raw helper start.
- The sole `B8 57 50 00` hit is inside the UID00042B switch instruction itself (`0x0050577d`), not a cross-reference from another code/data owner.
- `decompile 0x00505750` fails with `Decompilation failed at 0x505750`.
- `callees 0x00505750` returns `No function found`.
- The valid direction cases all dispatch through table entries to `0x005057a6`, the epilogue path. No valid case writes a result to a caller-visible out parameter, object field, global, or return register.
- The invalid/default path calls `sub_4B7C50` twice to clear local stack rectangles only; it then returns with no committed side effect.
- No vtable slot, function pointer, static table, generated output route, or source-declaration route was found in current docs or generated source.

Stale/contradictory support-state evidence:

- A separate live by-memory file, `by-memory/0x0045c1b0-0x0045c1cb.RankingCategoryRecordSetTitleText.md`, also contains header `UID:00042B` and documents a different raw RankingCategoryRecord setter at `0x0045c1b0-0x0045c1cb`, owner/emitter `0000BL`, with formal `RankingCategoryRecord::SetTitleText` C++.
- [UID:0000BL][RankingCategoryRecord](../../../by-class/RankingCategoryRecord.md) and [UID:0000MZ][RankingDialog](../../../by-file/RankingDialog.md) still contain links whose UID text is `00042B` but whose path points to the MapPane UID00042B page while describing the Ranking setter address/body.
- Executed report [B001 0000XZ RankingDialog](../../../executed-b-agent-research/B001/0000XZ-RankingDialog-source-quality.md) is the historical lead for the Ranking setter duplicate. It is not current evidence for the MapPane target's body or route.
- This duplicate/stale UID state is validator/supervisor lifecycle territory. It should be preserved in this report as a risk and rejected as MapPane target evidence, not repaired manually by B008 during this report-only pass.

## IDA MCP Facts

### Function And Range Facts

| Address/range | Live MCP result | Meaning |
| --- | --- | --- |
| `0x00505730` | `nullsub_12`, size `0x1` | Predecessor one-byte no-op, not part of UID00042B. |
| `0x00505740` | `nullsub_41`, size `0x3` | Predecessor no-op callback, not part of UID00042B. |
| `0x00505743-0x00505750` | 13 bytes all `0xcc` | Alignment before UID00042B, already documented in ignored padding. |
| `0x00505750` | `lookup_funcs`: `Not a function` | UID00042B raw body start, no IDA function object. |
| `0x00505750-0x005057b8` | `insn_query`: 37 decoded instructions | Raw prologue/body/epilogue with no function metadata. |
| `0x005057b8-0x005057c8` | 16-byte table, four dwords all `0x005057a6` | Local switch table owned by UID00042B. |
| `0x005057c8-0x005057d0` | 8 bytes all `0xcc` | Alignment after UID00042B, already documented in ignored padding. |
| `0x005057d0` | `lookup_funcs`: `Not a function` | Successor raw helper start, not part of UID00042B. |

### Instruction Facts

The raw body begins with `push ebp`, creates a `0x24` byte stack frame, initializes a security cookie from `___security_cookie`, and passes `&localRectA` to `sub_505370` at `0x00505764`. It then copies 16 bytes from `localRectA` to `localRectB` through SSE `movups`, reads the signed direction byte from `[ebp+8]`, and switches on values `0..3`.

For direction values `0..3`, every switch-table entry points to `0x005057a6`, which immediately begins epilogue/security-cookie verification. For values greater than `3`, the default path at `0x00505781` calls `sub_4B7C50` twice with all-zero coordinates, once for `localRectA` and once for `localRectB`, then returns.

Because both rectangles are stack locals and there is no out-pointer argument, object field write, global write, return-value computation, or external call after local clearing, the decoded behavior has no committed external effect beyond executing `MapPane::GetExtendedVisibleTileBounds` and local-only scratch setup.

### Xref Facts

| Target | Live MCP result | Meaning |
| --- | --- | --- |
| `0x00505750` | `xrefs_to`: 0 | No incoming code/data route to raw start. |
| `0x00505750` | `xref_query both`: one internal flow edge `0x505750 -> 0x505751` | Not a caller or data pointer. |
| `0x005057b8` | `xrefs_to`: one data xref from `0x50577a`; `xref_query` also shows table entry to `0x5057a6` | Local switch table only. |
| `0x005057c8` | `xrefs_to`: 0; `xref_query both`: 0 | No route to table end/successor boundary. |
| `0x00505370` | `xrefs_to`: includes `0x505764` with `fn:null` plus reached modeled callers | UID00042B calls accepted visible-bounds helper, but no caller reaches UID00042B. |
| `0x00505650` | two code refs from modeled callers | Neighbor helper has real route, contrasting UID00042B. |
| `0x005058b0` | one code ref from modeled caller | Successor modeled helper has real route, contrasting UID00042B and successor raw 00042C. |

### Byte/Pointer Facts

| Pattern/check | Result | Meaning |
| --- | --- | --- |
| `50 57 50 00` | 0 matches | No absolute pointer to raw start `0x00505750`. |
| `B8 57 50 00` | one match at `0x50577d` | Switch table base immediate inside UID00042B. |
| `C8 57 50 00` | 0 matches | No absolute pointer to end boundary `0x005057c8`. |
| `D0 57 50 00` | 0 matches | No absolute pointer to successor raw start `0x005057d0`. |
| `0x00505743` size 13 | all `0xcc` | Pre-target alignment. |
| `0x005057c8` size 8 | all `0xcc` | Post-target alignment. |

## Function / Child Inventory

| Range / item | UID / path | Role | Reconstructable | Direct parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00505370-0x005053e4` | [UID:000423](../../../by-memory/0x00505370-0x005053e4.MapPaneGetExtendedVisibleTileBounds.md) | Reached `MapPane::GetExtendedVisibleTileBounds` method | True | `00007Q` | `88/90` | Emits formal C++; UID00042B calls it. |
| `0x00505650-0x00505730` | [UID:000428](../../../by-memory/0x00505650-0x00505730.MapPaneGetAdjacentVisibleTileBounds.md) | Reached adjacent visible bounds helper with jump table | True | `00007Q` | `86/88` | Emits formal C++; has direct callers. |
| `0x00505730-0x00505731` | [UID:000429](../../../by-memory/0x00505730-0x00505731.MapPaneAfterLocalPlayerWarp.md) | One-byte no-op callback | True | `00007Q` | `86/88` | Separate predecessor child. |
| `0x00505740-0x00505743` | [UID:00042A](../../../by-memory/0x00505740-0x00505743.MapPaneObjectCallbackNoOp.md) | Three-byte no-op callback | True | `00007Q` | `86/87` | Separate predecessor child. |
| `0x00505743-0x00505750` | [UID:0000VN](../../../by-memory/-ignored.md) | Pure `0xcc` alignment | Ignored | none | `100` | Already ignored; no source body. |
| `0x00505750-0x005057c8` | [UID:00042B](../../../by-memory/0x00505750-0x005057c8.MapPaneRawDirectionBoundsScratch.md) | Raw direction/bounds scratch body plus local switch table | True | `00007Q` | proposed `86/88` | Non-emitting; formal C++ remains blank. |
| `0x005057c8-0x005057d0` | [UID:0000VN](../../../by-memory/-ignored.md) | Pure `0xcc` alignment | Ignored | none | `100` | Already ignored; no source body. |
| `0x005057d0-0x005058ac` | [UID:00042C](../../../by-memory/0x005057d0-0x005058ac.MapPaneRawObjectCleanupSweep.md) | Separate successor raw no-route helper | True | `00007Q` | `85/85` | Not part of this target. |

## Heuristic / Inference Reanalysis And Validation

### Raw Helper Liveness

The raw helper is live as binary code but not live as a currently routed source emitter. It is not padding: it has a conventional MSVC prologue/epilogue, security-cookie code, calls `MapPane::GetExtendedVisibleTileBounds`, materializes local rectangles, dispatches through a local switch table, and returns with `retn 4`. It is also not currently reachable: no function object, incoming xref, pointer pattern, generated source entry, or support doc route reaches `0x00505750`.

The best source-quality wording is therefore "source-shaped retained/raw MapPane scratch helper" rather than "padding", "generated dead bytes", or "MapPane method body ready for source emission".

### Direction/Bounds Semantics

The existing name `MapPaneRawDirectionBoundsScratch` remains the best descriptive name. The raw body accepts one stack byte argument, treats it as a direction selector, and starts from extended visible tile bounds. However, current instruction evidence shows all four valid direction cases point directly to the epilogue. The only active branch body is the invalid/default branch, and that branch only clears two local rectangles. A stronger method name such as `GetDirectionBounds`, `ClearDirectionBounds`, `GetAdjacentVisibleTileBounds`, or `BuildDirectionBounds` would overstate behavior and duplicate the actually reached [UID:000428][MapPaneGetAdjacentVisibleTileBounds](../../../by-memory/0x00505650-0x00505730.MapPaneGetAdjacentVisibleTileBounds.md).

### Switch-Table Handling

`0x005057b8-0x005057c8` is not padding. It is a 16-byte local switch table. All four dwords are `0x005057a6`, which is the epilogue/security-cookie path for cases `0..3`. The table has only internal xrefs: the switch instruction uses its base and the table points back into the same raw body. It does not prove an external route to UID00042B.

### Stale Duplicate UID Handling

The stale RankingCategoryRecord trail is important for supervisor awareness, but it does not change the MapPane raw-helper conclusion. It proves that the documentation state has a duplicate UID/stale link problem: one live by-memory file for a Ranking setter also claims `UID:00042B`, while the current generated tracker and assignment row point UID00042B to the MapPane path. B008 should not repair this by hand during a target-specific MapPane report; validator/supervisor lifecycle commands or a separate accepted cleanup are the safe route.

### No-Improvement Exception Versus Score Movement

This report does not use a no-improvement exception. The current target can be improved safely by adding fresh live evidence and raising documentation quality from `85/85` to `86/88`. The improvement is documentation/evidence quality only. It does not create a safe emitter route or final C++ body.

## Ranked Ownership Analysis

### 1. MapPane Class [UID:00007Q]

Evidence for:

- UID00042B lies inside the MapPane coordinate/object/timer aggregate [UID:0001AP].
- The raw body directly calls accepted MapPane method [UID:000423] `MapPane::GetExtendedVisibleTileBounds`.
- Parent [UID:0001AP], class [UID:00007Q], and file [UID:0000L3] already route this raw helper family to MapPane.
- Neighboring reached helpers in the same family are MapPane class/file helpers.

Evidence against:

- No caller proves an active non-static or virtual MapPane method declaration.
- The raw body has no external effect and no emitted route.

Decision:

- Keep `CANONICAL_OWNER:00007Q` as the documentation/source-family owner. Do not add `EMITTER_UIDS:00007Q` because ownership is not the same as a safe source emission route.

### 2. MapPane Source File [UID:0000L3]

Evidence for:

- [UID:0000L3][MapPane](../../../by-file/MapPane.md) is the source root for `NexusTK/map/MapPane.cpp`.
- If this retained helper ever receives a safe route, its source placement would remain in the MapPane.cpp coordinate-helper family.

Evidence against:

- The body uses MapPane receiver context through `sub_505370`, so class ownership is a better canonical owner than file-level ownership.
- No evidence proves a file-static helper declaration.

Decision:

- Use [UID:0000L3] only as source-file placement context, not direct canonical owner or emitter.

### 3. RectGeometryHelpers / RectBounds

Evidence for:

- The default path calls `sub_4B7C50`, the shared rectangle initializer.

Evidence against:

- Rectangle helper calls are dependencies only. The code starts from MapPane extended visible bounds and lives in the MapPane address cluster.
- The rectangle writes are only to UID00042B stack locals.

Decision:

- Reject as owner/emitter.

### 4. RankingCategoryRecord / RankingDialog

Evidence for:

- A stale duplicate by-memory file and support docs also use `UID:00042B` for `0x0045c1b0-0x0045c1cb.RankingCategoryRecordSetTitleText`.

Evidence against:

- Different address range, different function body, different owner/emitter, different source file, and different generated tracker row.
- Current assignment, generated memory coverage, and target path all identify UID00042B as MapPane raw range `0x00505750-0x005057c8`.

Decision:

- Reject as target evidence. Preserve as stale duplicate UID/lifecycle risk for supervisor cleanup.

### 5. No Canonical Owner

Evidence for:

- No active route/caller/source declaration exists.

Evidence against:

- Range context, callee, parent aggregate, class page, file page, and prior accepted report all consistently place the raw bytes in the MapPane source family.

Decision:

- Reject no-owner metadata. Keep owner `00007Q` but leave non-emitting.

## Source Placement

Recommended source placement if a future route is ever proven: `NexusTK/map/MapPane.cpp`, through class owner [UID:00007Q][MapPane](../../../by-class/MapPane.md) and file parent [UID:0000L3][MapPane](../../../by-file/MapPane.md).

Current source emission placement: none. UID00042B should remain absent from `auto-generated/NexusTK/map/MapPane.cpp` because adding a method body would fabricate an uncalled source routine with no committed observable behavior.

Rejected placements:

- `NexusTK/platform` or generic geometry helper files: rejected because `sub_4B7C50` is a dependency and the raw body calls MapPane-specific bounds code.
- RankingDialog/RankingCategoryRecord: rejected as stale duplicate UID state, not the assigned target.
- Ignored padding: rejected by full raw body, calls, prologue/security cookie, `retn 4`, and switch table.

## Range / Split / Padding / Reclassification Analysis

No split is recommended. The target range is already the correct half-open child:

- `0x00505743-0x00505750`: pure `0xcc` prepad, already ignored.
- `0x00505750-0x005057b8`: raw body instructions.
- `0x005057b8-0x005057c8`: local switch table, owned by the raw body.
- `0x005057c8-0x005057d0`: pure `0xcc` postpad, already ignored.

The child must keep table bytes through `0x005057c8`. Splitting the switch table into ignored data would be wrong because `xrefs_to 0x005057b8` and `insn_query` prove it is the switch table for UID00042B. Expanding into `0x005057d0` would be wrong because UID00042C is a separate raw helper start.

## First-Draft C++ / No-Code Proof

Eligible for draft C++: no.

Recommended formal `RECONSTRUCTION_CPP CODE` disposition: keep the target formal block exactly blank.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Exact no-code proof:

- The raw start is not an IDA function and decompilation fails.
- There are no incoming raw-start xrefs, no absolute raw-start pointer hits, no vtable/table route, no generated C++ route, and no source declaration evidence.
- The apparent signature would at best be an unproven MapPane receiver plus one direction byte, but there is no output parameter and no committed result.
- For valid direction values `0..3`, all switch entries jump directly to the epilogue.
- For invalid direction values, the only nontrivial work after the initial `GetExtendedVisibleTileBounds` call is clearing two stack-local rectangles through `sub_4B7C50`.
- No object field, global, caller-provided out parameter, heap object, packet, timer, object-list row, or return value is modified.
- Emitting a C++ function would invent a source-level declaration and create source output for a no-route, local-only scratch body. The target should instead document the raw no-route evidence in prose.

## Score And Metadata Recommendation

Current metadata:

- `COMPLETION:85`
- `CONFIDENCE:85`
- `CANONICAL_OWNER:00007Q`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:` blank
- formal C++ blank

Recommended metadata:

- `COMPLETION:86`
- `CONFIDENCE:88`
- Preserve `CANONICAL_OWNER:00007Q`
- Preserve `RECONSTRUCTABLE:TRUE`
- Preserve blank `EMITTER_UIDS`
- Preserve blank `EMITTER_POSITION_OPTIONAL`
- Preserve blank formal `RECONSTRUCTION_CPP CODE`

Score rationale:

- Completion can move to `86` because the target-specific report now rechecks current MCP, exact bytes, function/non-function status, xrefs, pointer patterns, local switch-table behavior, local-only side effects, support docs, generated output, old reports, source placement, and stale duplicate UID state. The target page can become implementation-ready for no-code proof.
- Confidence can move to `88` because route-negative evidence is strong and current, and MapPane ownership is corroborated by direct callee/context/support docs. It should not exceed this because no caller/source declaration exists, the raw helper has no decompilable function object, the original source name/signature is not recoverable, and duplicate UID/stale support state remains outside this target callback.

Reason not to assign `EMITTER_UIDS`:

- Owner confidence and emitter confidence are different gates. MapPane is the best owner, but no current route proves this raw body should be emitted as source.

Reason not to mark non-reconstructable:

- The bytes are custom game-client source-shaped code, not CRT, imported library code, padding, vtable data, or compiler-only metadata. They should remain reconstructable documentation even while non-emitting.

## Recommended Target Doc Changes

Target path: `by-memory/0x00505750-0x005057c8.MapPaneRawDirectionBoundsScratch.md`

Apply these exact classes of changes if the supervisor accepts the report:

- Change metadata from `COMPLETION:85`, `CONFIDENCE:85` to `COMPLETION:86`, `CONFIDENCE:88`.
- Preserve `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank formal C++.
- Update the `Item Summary` to record the 2026-07-01 live recheck: raw no-function MapPane direction/bounds scratch body, no raw-start xrefs or start-pointer hits, local switch table `0x005057b8-0x005057c8`, all valid switch entries go to epilogue, no external committed effect, non-emitting.
- Add a `2026-07-01 B008 Target-Specific Recheck` or equivalent section with:
  - MCP session/health proof.
  - `lookup_funcs`/`entity_query` results.
  - `xrefs_to`/`xref_query`/`find_bytes` results.
  - Exact byte/padding/table facts.
  - Instruction behavior and no-code proof.
  - Rejected owner/source/emitter alternatives.
  - Stale duplicate UID caveat for Ranking docs as a supervisor/validator lifecycle issue, not target evidence.
- Add a score rationale explaining `86/88` and why `EMITTER_UIDS` remains blank.
- Add a `Changes` bullet for the accepted B008 callback if implemented.

## Recommended Support Doc Changes

No support by-* edits are required for the first implementation callback.

Already-present support facts:

- [UID:0001AP][MapPaneWeatherCoordinateObjectCore](../../../by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md) already says UID00042B is a raw no-route direction-bounds scratch body, owns switch table `0x005057b8-0x005057c8`, has blank formal C++, and is surrounded by already-classified `0xcc` spans.
- [UID:00007Q][MapPane](../../../by-class/MapPane.md) already lists UID00042B among raw no-route children and states such pages remain reconstructable MapPane source-shaped evidence but do not emit C++ until a route or retained-helper emission policy is proven.
- [UID:0000L3][MapPane](../../../by-file/MapPane.md) already records the accepted B009 split and says UID00042B remains documented but non-emitting because `lookup_funcs`, `xrefs_to`, and pointer-pattern searches find no entry route.
- [UID:0000VN][-ignored](../../../by-memory/-ignored.md) already owns only the adjacent `0xcc` spans, not UID00042B or its switch table.

Optional support sync only if the supervisor widens callback scope:

- In [UID:0001AP][MapPaneWeatherCoordinateObjectCore](../../../by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md), append to the UID00042B row that B008 2026-07-01 live MCP reconfirmed all four switch-table entries point to the epilogue and no external effect exists.
- In [UID:00007Q][MapPane](../../../by-class/MapPane.md) or [UID:0000L3][MapPane](../../../by-file/MapPane.md), no metadata change is recommended; only an optional one-line history note would be needed.

Do not include RankingCategoryRecord or RankingDialog stale UID repair in the MapPane target callback unless the supervisor explicitly widens scope and authorizes lifecycle cleanup. The exact stale paths observed are:

- `by-memory/0x0045c1b0-0x0045c1cb.RankingCategoryRecordSetTitleText.md`
- `by-class/RankingCategoryRecord.md`
- `by-file/RankingDialog.md`

## Open Questions With Attempted Resolution

- Is `0x00505750` a hidden active method? Current answer: no safe route. `lookup_funcs`, `xrefs_to`, `xref_query`, `find_bytes`, `decompile`, `callees`, generated output, and support docs were checked. No current caller/pointer/emit route exists.
- Should a first-draft `MapPane` method be emitted anyway? Current answer: no. The body has no committed external effect and no source declaration/caller. Emitting it would create artificial source.
- Should the switch table be ignored or split? Current answer: no. It is child-owned switch data with an internal xref from the switch instruction and entries back into the body epilogue.
- Should UID00042B be reassigned to RankingCategoryRecord because of duplicate docs? Current answer: no for this assignment. The duplicate is stale/lifecycle evidence, while the current generated tracker row and target path are MapPane. The duplicate should be handled by validator/supervisor cleanup, not by changing this target's owner.
- What evidence would change the emitter recommendation? A current direct caller/xref to `0x00505750`, a source declaration route, a validated function pointer/table route outside the local switch table, a retained-helper emission policy that explicitly allows no-route/local-only scratch routines, or proof that the current raw body is actually embedded/entered through a nonstandard dispatch not visible to current xrefs.

## Validator Results

Implementation callback validator run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [00042B-MapPaneRawDirectionBoundsScratch-by-memory-source-quality-removed.md](00042B-MapPaneRawDirectionBoundsScratch-by-memory-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Exit code: `0`
- `command_id`: `000000004078`
- `command_timestamp`: `2026-07-01T17:29:41-04:00`
- `ok`: `1`
- `generated_refresh`: `completed`
- `generated_refresh_command_id`: `000000004078`
- `generated_refresh_timestamp`: `2026-07-01T17:29:41-04:00`
- Target metadata side effects: `completion_update 00042B ... 86`; `confidence_update 00042B ... 88`.
- Target reference side effects: validator normalized/inserted UID000423 links in the target page and added reference-index rows for referenced UIDs.
- Validator-owned generated/project side effects reported: `research_tracker_update`, `memory_auto_coverage_update`, `projected_stats_update`, `autogen_registry_rebuild`, generated metadata refresh, and validator autogen backups.
- Warnings: no target-specific validator failure. Broad preexisting/generated diagnostics remained, including `autogen_emitter_has_no_code`, `autogen_children_marker_missing`, and `autogen_children_fallback_insert` rows unrelated to UID00042B.

Generated-output verification after validator:

- `auto-generated/-ag-memory-coverage.md` header is `validator-command-id: 000000004078`, `validator-refreshed-at: 2026-07-01T17:29:41-04:00`, and its UID00042B row still lists `non-emits`, owner `00007Q`, with the target path.
- `auto-generated/NexusTK/map/MapPane.cpp` header is `validator-command-id: 000000004078`, `validator-refreshed-at: 2026-07-01T17:29:41-04:00`.
- Exact generated C++ search counts after refresh: `00042B` count `0`; `MapPaneRawDirectionBoundsScratch` count `0`. UID00042B still emits no generated C++ body or marker.

## Changed Files

- Manual B008 edits:
  - `by-memory/0x00505750-0x005057c8.MapPaneRawDirectionBoundsScratch.md`
  - `tools/leaser/Agents/Agent-B008/research/00042B-MapPaneRawDirectionBoundsScratch-by-memory-source-quality.md`
- Target/support by-* docs intentionally not edited:
  - `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`
  - `by-class/MapPane.md`
  - `by-file/MapPane.md`
  - `by-memory/-ignored.md`
  - stale Ranking duplicate UID docs
- Validator-owned side effects occurred through the scoped validator only: generated reports/C++ metadata, generated research tracker, projected stats, validator registry rebuild, and validator backups. B008 did not manually edit generated files, coverage-report files, project-level generated reports, validator/tool state, supervisor ledgers, archives, by-project-structure docs, or IDA DB.
- Lease proof: B008 leased `by-memory/0x00505750-0x005057c8.MapPaneRawDirectionBoundsScratch.md` before editing/validation, released it immediately after validator completion, and the current lease report shows no active B008 lease.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID00042B current queue state was `85/85`, reconstructable `true`, reports `0`, target path `by-memory/0x00505750-0x005057c8.MapPaneRawDirectionBoundsScratch.md`. | High | Target `Changes` now records score changed from `85/85` to `86/88`; validator `000000004078` updated the research tracker row to `86/88`, combined `87.0`. | Target `Changes` / `Score Rationale`; generated tracker by validator. | incorporate | applied |
| C02 | Live MCP was available in session `supervisor_resume_20260629`, IDB `NexusTK.exe.i64`, PID `14860`, health `ok`, Hex-Rays ready. | High | Target section `2026-07-01 B008 Target-Specific Recheck` records session, IDB path, worker PID, health, imagebase, and readiness fields. | Target evidence section. | incorporate | applied |
| C03 | `0x00505750` is still not an IDA function; `0x005057b8`, `0x005057c8`, and `0x005057d0` are also not functions. | High | Target `No-Route Proof` records the live `lookup_funcs` results. | Target no-route proof. | incorporate | applied |
| C04 | The only functions in `0x00505730-0x005057d0` are `nullsub_12` at `0x00505730` and `nullsub_41` at `0x00505740`; UID00042B is raw. | High | Target `No-Route Proof` records the `entity_query` result. | Target boundary evidence. | incorporate | applied |
| C05 | UID00042B's exact half-open range remains `0x00505750-0x005057c8`, 120 bytes; body through `0x005057b8`, table through `0x005057c8`. | High | Target `Range, Table, And Padding` records the half-open range, byte count, body/table split, and table ownership. | Target boundary/range section. | incorporate | applied |
| C06 | Adjacent `0x00505743-0x00505750` and `0x005057c8-0x005057d0` are pure `0xcc` alignment and already belong to ignored padding, not UID00042B. | High | Target `Range, Table, And Padding` records both adjacent alignment spans and points them to [UID:0000VN] `by-memory/-ignored.md`; support file was already sufficient and not edited. | Target range section; support already present. | incorporate | applied |
| C07 | `0x005057b8-0x005057c8` is a local switch table owned by UID00042B, not padding. | High | Target `Range, Table, And Padding` records the `xrefs_to`/`xref_query` switch-table proof and states it is not ignored padding. | Target switch-table evidence. | incorporate | applied |
| C08 | All four switch-table entries point to `0x005057a6`, the epilogue/security-cookie path; valid direction cases have no committed external effect. | High | Target `Range, Table, And Padding` and `Behavior` record all four dwords as `0x005057a6` and the valid-case no-effect result. | Target behavior/no-code proof. | incorporate | applied |
| C09 | Default/invalid direction path only clears two local stack rectangles through `sub_4B7C50`; no out parameter, field, global, packet, timer, object-list row, or return value is committed. | High | Target `Behavior` and `Formal C++ / No-Code Proof` record the default path, `sub_4B7C50` rectangle semantics, and no committed external side effect. | Target behavior/no-code proof. | incorporate | applied |
| C10 | `xrefs_to 0x00505750` has zero incoming refs; `find_bytes 50 57 50 00` has zero matches; no raw-start route is proven. | High | Target `No-Route Proof` records zero incoming refs and zero start-pointer matches. | Target no-route proof. | incorporate | applied |
| C11 | The sole `B8 57 50 00` match is the immediate switch-table base inside UID00042B, not an external pointer route. | High | Target `No-Route Proof` records the one hit at `0x0050577d` and explains it is the local switch-table base immediate. | Target rejected route evidence. | incorporate | applied |
| C12 | UID00042B calls [UID:000423] `MapPane::GetExtendedVisibleTileBounds` at raw address `0x00505764`; this supports MapPane ownership but not reachability into UID00042B. | High | Target `Behavior` records the call to `sub_505370`; validator normalized/inserted UID000423 links during command `000000004078`. | Target ownership/behavior evidence. | incorporate | applied |
| C13 | Best owner remains [UID:00007Q] MapPane; [UID:0000L3] MapPane file is source placement context, not direct emitter; RectGeometryHelpers and Ranking docs are rejected owners. | High | Target `Ownership And Source Placement` records accepted owner, file context, rejected RectGeometryHelpers, rejected Ranking ownership, and owner/emitter separation. | Target ranked ownership/source placement. | incorporate | applied |
| C14 | Formal C++ must remain blank and `EMITTER_UIDS` must remain blank; this is a target-specific no-code proof, not a first-draft C++ candidate. | High | Target header preserves blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank formal C++; target `Formal C++ / No-Code Proof` records the no-code rationale. | Target metadata/formal C++ block. | incorporate | applied |
| C15 | Score should improve to `COMPLETION:86`, `CONFIDENCE:88` while preserving owner/reconstructable/emitter blank. | Medium-high | Target header is now `86/88`; validator command `000000004078` reported `completion_update 00042B ... 86` and `confidence_update 00042B ... 88`; owner/reconstructable/emitter fields are preserved. | Target metadata/score rationale. | incorporate | applied |
| C16 | Parent aggregate [UID:0001AP], class [UID:00007Q], file [UID:0000L3], and ignored-padding docs already preserve the general UID00042B no-route/table/padding disposition at adequate support level. | High | Support docs were read before implementation and matched the report; goal instructed no support edits. Target cross-references and support-presence checklist record this as already present. | Support docs; no edit required. | already-present | already-present |
| C17 | A duplicate/stale UID00042B RankingCategoryRecord trail exists and must be treated as stale/lifecycle risk, not MapPane target evidence. | High | Target `Ownership And Source Placement` records the stale duplicate UID caveat for RankingCategoryRecord/RankingDialog and rejects it as MapPane target evidence. No Ranking docs were edited. | Target stale evidence caveat; supervisor lifecycle follow-up. | historicalize | applied |
| C18 | Generated `auto-generated/NexusTK/map/MapPane.cpp` had no UID00042B body/marker and should remain absent after refresh. | High | Generated C++ verified after validator: header `validator-command-id: 000000004078`, refreshed `2026-07-01T17:29:41-04:00`; exact search counts `00042B=0`, `MapPaneRawDirectionBoundsScratch=0`. | Generated-output expectation. | incorporate | applied |
| C19 | No generated reports, generated C++, manual coverage reports, validator/tool state, supervisor ledgers, archives, by-project-structure docs, unrelated target/support by-* docs, or IDA DB should be manually edited by B008. | High | Manual B008 edits were limited to target page and this report. Validator-owned generated/tool side effects are reported above. Current lease report shows no active B008 lease. | Report changed-files/write-scope proof. | not-applicable | applied |

## Implementation Tracking Checklist

- [x] Supervisor validation required before any by-* implementation. Proof: supervisor accepted this report and assigned callback `B008-implement-00042B-MapPaneRawDirectionBoundsScratch-by-memory-20260701`.
- [x] Edit `by-memory/0x00505750-0x005057c8.MapPaneRawDirectionBoundsScratch.md`: change `COMPLETION:85` to `COMPLETION:86` and `CONFIDENCE:85` to `CONFIDENCE:88`. Proof: target header now `86/88`; validator `000000004078` reported completion/confidence updates.
- [x] Edit `by-memory/0x00505750-0x005057c8.MapPaneRawDirectionBoundsScratch.md`: preserve `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank formal `RECONSTRUCTION_CPP CODE`. Proof: target header preserves all listed fields and the multiline formal C++ block remains empty.
- [x] Edit `by-memory/0x00505750-0x005057c8.MapPaneRawDirectionBoundsScratch.md`: update `Item Summary` to mention the 2026-07-01 live MCP no-function/no-xref/no-start-pointer proof, local switch table `0x005057b8-0x005057c8`, all valid entries to epilogue, local-only default clearing, and non-emitting disposition. Proof: target `Item Summary` was replaced with that text.
- [x] Edit `by-memory/0x00505750-0x005057c8.MapPaneRawDirectionBoundsScratch.md`: add target-specific live MCP evidence for session health, `lookup_funcs`, `entity_query`, `xrefs_to`, `xref_query`, `find_bytes`, `get_bytes`, `insn_query`, failed `decompile 0x00505750`, and `callees 0x00505750` returning no function. Proof: target sections `2026-07-01 B008 Target-Specific Recheck`, `No-Route Proof`, `Range, Table, And Padding`, and `Behavior`.
- [x] Edit `by-memory/0x00505750-0x005057c8.MapPaneRawDirectionBoundsScratch.md`: add range/table/padding proof that `0x00505743-0x00505750` and `0x005057c8-0x005057d0` are `0xcc` alignment, while `0x005057b8-0x005057c8` is child-owned switch data. Proof: target `Range, Table, And Padding`.
- [x] Edit `by-memory/0x00505750-0x005057c8.MapPaneRawDirectionBoundsScratch.md`: add behavior/no-code proof that valid direction cases jump to `0x005057a6`, invalid/default only clears local stack rectangles through `sub_4B7C50`, and no out parameter/object/global/packet/timer/object-list/return side effect is committed. Proof: target `Behavior` and `Formal C++ / No-Code Proof`.
- [x] Edit `by-memory/0x00505750-0x005057c8.MapPaneRawDirectionBoundsScratch.md`: add ranked ownership/source-placement rationale keeping owner `00007Q`, treating `0000L3` as source-file context only, rejecting RectGeometryHelpers and RankingCategoryRecord as owners, and explaining why owner does not imply emitter. Proof: target `Ownership And Source Placement`.
- [x] Edit `by-memory/0x00505750-0x005057c8.MapPaneRawDirectionBoundsScratch.md`: add stale duplicate UID caveat for `by-memory/0x0045c1b0-0x0045c1cb.RankingCategoryRecordSetTitleText.md`, `by-class/RankingCategoryRecord.md`, and `by-file/RankingDialog.md`; state this is supervisor/validator lifecycle risk, not MapPane target evidence and not part of the target callback unless explicitly widened. Proof: target `Ownership And Source Placement`; no Ranking docs edited.
- [x] Confirm `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md` already preserves UID00042B as a raw no-route child with switch table `0x005057b8-0x005057c8`, blank formal C++, and adjacent `0xcc` spans; no edit required in target-only callback. Proof: support doc read before edit; no blocking contradiction found; not edited.
- [x] Confirm `by-class/MapPane.md` already lists UID00042B among raw no-route children and says such pages remain reconstructable MapPane evidence but do not emit C++ until a route or retained-helper emission policy is proven; no edit required in target-only callback. Proof: support doc read before edit; no blocking contradiction found; not edited.
- [x] Confirm `by-file/MapPane.md` already records the B009 split and says UID00042B is documented but non-emitting because `lookup_funcs`, `xrefs_to`, and pointer-pattern searches find no entry route; no edit required in target-only callback. Proof: support doc read before edit; no blocking contradiction found; not edited.
- [x] Confirm `by-memory/-ignored.md` already owns only `0x00505743-0x00505750` and `0x005057c8-0x005057d0` as ignored `0xcc` padding, not UID00042B or its switch table; no edit required in target-only callback. Proof: accepted support state recorded by target page; no support edit required by goal.
- [x] Do not edit stale Ranking duplicate UID docs in the MapPane callback unless the supervisor explicitly widens scope and provides lifecycle/UID cleanup authorization. Proof: Ranking duplicate docs were not edited; target carries only the stale/lifecycle caveat.
- [x] Run target validator after accepted implementation: `python .\tools\validator.py --mode file --file by-memory/0x00505750-0x005057c8.MapPaneRawDirectionBoundsScratch.md --apply --queue-timeout 240 --wait-generated`. Proof: command `000000004078`, timestamp `2026-07-01T17:29:41-04:00`, exit `0`, `ok: 1`, generated refresh completed.
- [x] If optional support docs are edited by explicit widened scope, run matching scoped validators for each edited support file with `--wait-generated`. Excluded-with-reason: no optional support docs were edited and goal scope was target-only, so no support validators were required.
- [x] Verify generated output after validation: `auto-generated/-ag-memory-coverage.md` still lists UID00042B as `non-emits`, and `auto-generated/NexusTK/map/MapPane.cpp` still has no UID00042B or `MapPaneRawDirectionBoundsScratch` generated body/marker. Proof: `-ag-memory-coverage.md` row remains `non-emits`; generated `MapPane.cpp` exact search counts `00042B=0`, `MapPaneRawDirectionBoundsScratch=0`; both headers refreshed at command `000000004078`.
- [x] Update this report's Claim And Incorporation Ledger from `proposed` to callback states after implementation, with proof for each accepted row. Proof: ledger rows C01-C19 now end in `applied` or `already-present` with target/validator/generated proof.
- [x] Check off implemented checklist items after callback with target path/section proof, validator command id/timestamp/exit/ok count, generated freshness status, and any exact blocker. Proof: this checklist is now checked with proof; no blockers remain.
- [x] Do not edit generated files, generated reports, project-level reports, manual `-coverage-report.md` files, validator/tool state, queue files, archives, supervisor ledgers, by-project-structure docs, or IDA DB. Proof: B008 manual edits were limited to the target by-memory page and this report; validator-owned generated/tool side effects are recorded in `Validator Results`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/00042B-MapPaneRawDirectionBoundsScratch-by-memory-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/00042B-MapPaneRawDirectionBoundsScratch-by-memory-source-quality.md","timestamp":"2026-07-01T17:36:22","uid":"00042B"} -->
<!-- {"agent":"B008","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00042B-MapPaneRawDirectionBoundsScratch-by-memory-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B008/00042B-MapPaneRawDirectionBoundsScratch-by-memory-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00042B"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
