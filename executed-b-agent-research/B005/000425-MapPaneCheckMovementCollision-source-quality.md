** TARGET-REPORT-UID:000425 **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# 000425 MapPaneCheckMovementCollision Source-Quality Report


## Finalized Report / Current Recommendation
- Current recommendation: accepted callback details have been implemented in the by-* docs. UID000425 is a source-ready `MapPane::CheckMovementCollision(int mapColumn, int mapRow, unsigned char direction)` child with corrected target C++ and support-symbol sync.
- Final disposition: target remains a reconstructable MapPane method under [UID:00007Q] with output through [UID:00007Q] / [UID:0000L3], now at `COMPLETION:88`, `CONFIDENCE:90`, with the corrected formal C++ block applied.
- Required action status: applied. The target by-memory page now carries current MCP session `e63ee655` evidence, the incorrect nullable guard around `m_activeObjectPane` was removed, and [UID:00027O] now emits direction-mask support names matching generated `MapPane.cpp`.
- Confidence: high for range, ownership, callers, callees, `-1/0/1` returns, and source placement; medium-high for final original spellings of local helper names and tile-layer field names.

## Supporting Research
- Historical research-pass note: UID000425 began as a report-only assignment, and no by-* docs were edited during that initial pass. After Gate 1 passed, this same report was continued for implementation callback and the accepted by-* edits below were applied.
- The report uses current MCP session `e63ee655` for all fresh IDA evidence. Stale session `6a4af54d` was discarded after it disappeared and returned `Session not found`.
- Existing executed B009 report `executed-b-agent-research/B009/0001AP-MapPaneWeatherCoordinateObjectCore-source-quality.md` is useful historical lead material because it created this exact child, but its MCP evidence is not treated as current proof.
- Existing support docs already place this helper in the MapPane coordinate/object/movement family and already record the `+0x418` active/local object pointer, `+0x424` object list, `g_objectRecordCount`, `g_objectNationMap`, and direction-mask tables.

## Target
- Target UID: `000425`
- Target path: `by-memory/0x00505430-0x005055ca.MapPaneCheckMovementCollision.md`
- Historical assignment-time source queue/report row: before callback, `auto-generated/-ag-research-tracker.md` listed the target under `## by-memory` / `### Not-Covered Files - Reconstructable` at `86/87`, combined `86.5`, reconstructable `true`, reports `0`. This was the research assignment input, not the current post-callback target state.
- Callback classification: implementation callback completed by B005; subsequent verification, execution, and archival decisions are supervisor-owned lifecycle steps outside this report's edits.
- Current scores and parent state after callback: `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, blank optional position, nonblank corrected formal C++.

## Current Target State
- Current metadata after callback: `88/90`, owner/emitter [UID:00007Q], reconstructable true.
- Existing owner/emitter/reconstructable state: correct. [UID:00007Q] is the narrow class owner; [UID:0000L3] remains the file root reached through the class page.
- Current C++/emitter state after callback: the target emits the corrected formal C++ body. The previous source-quality defects were repaired: the unsupported `m_activeObjectPane != NULL` guard was removed, and generated `MapPane.cpp` now emits [UID:00027O] declarations as `s_objectDirectionMasks` / `s_objectReverseDirectionMasks`.
- Existing open questions, blockers, placeholder names, stale assumptions, or contradictory claims: final original names for the tile-layer result struct and the active-object bypass predicate are inferred, not symbol-proven. This no longer blocks first-draft C++, but it caps score below final-audit levels.
- Related target/support docs checked: `by-class/MapPane.md`, `by-file/MapPane.md`, [UID:0001AP] aggregate, [UID:00027O] direction masks, [UID:0000Q3] `g_objectNationMap`, [UID:0000Q4] `g_objectRecordCount`, [UID:0003ZM] legacy map-tile remap constants, [UID:0003IO] shared `GM` string, [UID:0001KM] local-player extension aggregate, and generated `auto-generated/NexusTK/map/MapPane.cpp`.
- Lifecycle note: B005 completed the accepted implementation callback and did not run `execute_report` or lifecycle/archive commands. This report records B005's research and callback incorporation without asserting a future supervisor lifecycle state.

## Executive Recommendation
- Keep direct owner [UID:00007Q] `MapPane`; keep the emitter route through [UID:00007Q] to [UID:0000L3] `NexusTK/map/MapPane.cpp`.
- Do not split, merge, rename, or reclassify the target range. MCP confirms the modeled function starts at `0x00505430`, size `0x19a`, ending at `0x005055ca`, with successor function `0x005055d0`.
- Applied target score `88/90`, formal C++ replacement, and support sync for [UID:00027O] mask symbol names. Generated `MapPane.cpp` now contains UID000425 at `88/90` and declares `s_objectDirectionMasks` / `s_objectReverseDirectionMasks` for [UID:00027O].

## Supervisor Active Recheck
- Supervisor assigned UID000425 as a new report-only task and later resumed MCP with live session `e63ee655`.
- No split repair is required. The exact child page already exists and the immediate successor boundary is documented.
- Every source-bearing item in this assignment has either a current recommendation or an evidence-backed support-sync requirement. No fallback-only report was produced.

## Inference Research Guidance Check
- `by-structure.md` owner/emitter rules support the current class owner because the function is a `thiscall` MapPane method reading MapPane fields at `+0x3f4`, `+0x3f6`, `+0x418`, and `+0x424`.
- Wave2/Wave3/generated names were treated as lead material only. The generated C++ helped expose the mask-symbol mismatch, but MCP and by-* docs were used for behavioral proof.
- Direct IDA facts: range, callers, callees, branch conditions, field offsets, globals, and data xrefs.
- Documentation evidence: accepted MapPane split docs, MapPane field glossary, global/mask support pages, and prior executed B reports.
- Inference: source-facing method/field names such as `CheckMovementCollision`, `m_activeObjectPane`, `AllowsMovementCollisionBypass`, `MapTileLayerIds`, `objectNation`, and direction-mask table names.

## Heuristic / Inference Reanalysis And Validation
- Function range: MCP `lookup_funcs` reports `0x00505430 -> sub_505430`, size `0x19a`; `0x005055ca` is not a function; `0x005055d0 -> sub_5055D0`, size `0xb`. This validates the existing half-open range.
- Receiver and field names: disassembly uses `ECX` as `this`, reads `word [edi+0x3f4]` / `word [edi+0x3f6]` for map width/height, `[edi+0x418]` for active/local object, and `[edi+0x424]` for `m_objectList`. Existing MapPane class docs already support these field names.
- Active-object bypass: the binary performs `mov eax, [edi+418h]` and `cmp byte ptr [eax+1340FCh], 0`; it does not null-check the pointer. The current source null guard is a defensive decompiler-era artifact and should be removed from formal C++.
- Object blocker semantics: the object-list lookup uses `sub_533090(m_objectList, nextColumn, nextRow)`. If an object is present, the function scans a UTF-16 name area, compares a suffix/pointer against shared `L"GM"`, and returns `0` only when the object is not GM and byte `+0x1d2` is clear. The source-facing names `GetObjectName()` and `IsMovementPassable()` remain inferred but match current by-* terminology.
- Tile-layer data: two `sub_50C120` calls fetch current and next tile-layer ids. The target can keep `GetLegacyAwareMapTileLayerIds`; [UID:00027I] and [UID:0003ZM] already support that helper role.
- Direction masks: MCP proves `byte_66DD50[direction]` tests the current tile's compact object-nation byte and `byte_66DD58[direction]` tests the next tile's byte. The current target names `s_objectDirectionMasks` / `s_objectReverseDirectionMasks` are more source-facing than support-page `A/B`, but support formal declarations must be synchronized to those names.
- Return semantics: direct branches return `1` for active-object bypass and allowed mask/tile movement, `0` for blocking non-GM non-passable object, and `-1` for out-of-bounds or failed tile/mask checks. This supports the existing `int` return rather than `bool`.
- Rejected alternatives: ObjectList owns lookup internals, not the MapPane helper; global mask/count pages own data declarations, not this method; LivingObjectPane/UserPane are callers or receiver-state providers, not owners of this method; the broad [UID:0001AP] aggregate remains an index, not a monolithic function body.

## Evidence Standards Used
- Evidence types used: MCP `server_health`, `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, `xrefs_to`, `entity_query`; current target/support by-* docs; generated `MapPane.cpp`; executed B-report searches; generated tracker/coverage rows.
- The evidence is strong enough for a C++ repair because decompilation and disassembly agree on all material control-flow branches, field offsets, callee set, global/mask references, and return values.
- Confidence is kept below 95 because no recovered original symbols prove the exact source spellings for the predicate method, tile-layer struct fields, or mask table names.

## Evidence Checked
- IDA MCP checks:
  - `server_health(e63ee655)` returned `status=ok`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis/Hex-Rays/strings ready.
  - `lookup_funcs` for `0x00505430`, `0x005055ca`, `0x005055d0`, `0x00505080`, `0x0050c120`, `0x0050c790`, `0x0050d010`, and `0x005a2e00`.
  - `analyze_function`, `decompile`, and `disasm` for `0x00505430`.
  - `xrefs_to` for `0x00505430`, `0x0069b4bc`, `0x0069b4c0`, `0x0066dd50`, `0x0066dd58`, and `0x0061e6f8`.
  - `decompile` for callers `0x0050c790`, `0x0050d010`, and `0x005a2e00` as caller-context evidence.
  - `entity_query` over `0x005055c0-0x005055d8` found no local names at the boundary.
- Docs and reports checked: target by-memory page, MapPane class/file pages, [UID:0001AP], [UID:00027O], [UID:0000Q3], [UID:0000Q4], [UID:0003ZM], [UID:0003IO], [UID:0001KM], B009 `0001AP`, B004 `0002XQ`, B005 `0002XR`, B002 `00027I`, and generated `auto-generated/NexusTK/map/MapPane.cpp`.
- Negative checks performed: rejected stale session `6a4af54d`; confirmed no function at `0x005055ca` or `0x005055cf`; confirmed no names in the immediate successor/padding interval; confirmed support mask symbol mismatch in generated C++.
- Historical research-pass skipped checks: no validators were run during the initial report-only pass because no by-* files were edited then. Implementation validators were run during the callback; see `Validator Results`.

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID000425 is exact function `0x00505430-0x005055ca`, size `0x19a`; successor `0x005055d0` is separate. | High | MCP calls 12, 15, 26; ignored padding docs. | Target Evidence / Range section | applied | Target evidence records `e63ee655`, size `0x19a`, half-open end, successor `0x005055d0`, and padding boundary. |
| C02 | Owner/emitter [UID:00007Q] remain correct; source route is MapPane class to MapPane file. | High | Disasm field reads, MapPane docs, caller family. | Target metadata/status; class/file support | applied | Target kept owner/emitter; class/file pages record MapPane route and rejected alternatives. |
| C03 | Current nullable active-object guard is behavior-shape drift; binary unconditionally dereferences `[this+0x418]` then byte `+0x1340fc`. | High | MCP disasm call 15 at `0x5054a5-0x5054ab`. | Target formal C++ and evidence | applied | Formal target C++ removes the null guard; target/class evidence records unconditional dereference. |
| C04 | Function returns `1`, `0`, or `-1`; it is not a bool. | High | MCP disasm return blocks and caller decompilation. | Target summary/status | applied | Target Item Summary and evidence preserve `-1/0/1`; formal C++ remains `int`. |
| C05 | Object blocker path compares against shared wide `GM` string and byte `+0x1d2`. | High | MCP decompile/disasm; `xrefs_to(0x0061e6f8)`. | Target evidence and negative evidence | applied | Target/class/file evidence documents object-list lookup, `GM` pass-through, and passability gate. |
| C06 | `g_objectRecordCount`/`g_objectNationMap` are support globals consumed here but not owners. | High | MCP xrefs; by-global docs. | Target evidence; support already-present notes | applied | Target, class, file, and aggregate support identify SOBJ globals as dependencies and reject global-data ownership. |
| C07 | Direction masks at `0x0066dd50`/`0x0066dd58` are consumed here and by raw accessors; target/support symbol names must be synchronized. | High | MCP xrefs; generated `MapPane.cpp`; [UID:00027O]. | Target C++; support doc [UID:00027O] | applied | [UID:00027O] formal declarations now use `s_objectDirectionMasks` / `s_objectReverseDirectionMasks`; generated output confirms matching names. |
| C08 | Callers are four sites in `0x0050c790`, four in `0x0050d010`, and one in `0x005a2e00`. | High | MCP `analyze_function` and `xrefs_to`. | Target callers; class/file support | applied | Target and class/file support record all nine caller sites and caller-family ownership limits. |
| C09 | No split or reclassification is needed. | High | MCP range/boundary; existing aggregate split. | Target score/range rationale | applied | Target remains exact child; aggregate row updated; no new child/split/reclassification applied. |
| C10 | Recommended target score is `88/90`; not higher due inferred names and support symbol/order sync. | Medium-high | Full evidence pass and generated output mismatch. | Target metadata; score rationale | applied | Target metadata is `88/90`; report and target preserve score caps for inferred original names. |

## Positive Evidence Summary
- MCP `e63ee655` confirms exact range, callee set, nine callers, direct globals, branch layout, and return values.
- Existing MapPane class/file docs already support the method's owner, field offsets, movement-helper family, active/local object pointer, object list, map dimensions, tile-buffer helper, and source file route.
- Existing global/mask docs already support the compact `SOBJ.TBL` object-nation cache and two direction-mask arrays consumed by this helper.
- The strongest inference chain is: MapPane method receiver and fields -> direction delta helper -> map-bounds check -> active-local-object bypass -> object-list blocking check -> tile-layer and object-nation mask gating -> movement status return. This is sufficient for a corrected formal C++ body.

## IDA MCP Facts
- Function/range facts: `0x00505430` function `sub_505430`, size `0x19a`; `0x005055ca` and `0x005055cf` are not functions; `0x005055d0` is `sub_5055D0`, size `0xb`.
- Data/table facts: `0x0069b4bc` count xref at `0x00505561`; `0x0069b4c0` map xref at `0x0050557e`; direction masks at `0x0066dd50` and `0x0066dd58` consumed at `0x0050558b` and `0x00505599`; shared `GM` string at `0x0061e6f8` used at `0x00505505`.
- Xref facts: nine callers to function start: `0x50c9fd`, `0x50cab1`, `0x50cb61`, `0x50cc15`, `0x50d2d3`, `0x50d35b`, `0x50d3e1`, `0x50d467`, and `0x5a3207`.
- Vtable/global/type facts: no vtable dispatch owns this helper; it is ordinary direct-call `thiscall` MapPane code. Global data pages own the count/map/masks, not this function body.
- Negative IDA facts: no modeled function or local name exists at the immediate end/padding addresses; no evidence supports moving this method to ObjectList, LivingObjectPane, or the broad aggregate.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00505430-0x005055ca` | [UID:000425] `by-memory/0x00505430-0x005055ca.MapPaneCheckMovementCollision.md` | MapPane movement collision/nation-mask helper | TRUE | [UID:00007Q] | current/applied `88/90` (historical pre-callback `86/87`) | source-ready with corrected C++ applied |
| `0x005055ca-0x005055d0` | [UID:0000VN] `by-memory/-ignored.md` | alignment padding | FALSE | n/a | n/a | already documented |
| `0x005055d0-0x005055db` | [UID:000426] `MapPaneAllowsMovementStatusTag` | successor movement-status predicate | TRUE | [UID:00007Q] | `87/90` | separate function |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0050c9fd`, `0x0050cab1`, `0x0050cb61`, `0x0050cc15` | caller `0x0050c790` | path-scan variant tests four movement directions and treats `>0` as pass except for current-cell special cases. |
| `0x0050d2d3`, `0x0050d35b`, `0x0050d3e1`, `0x0050d467` | caller `0x0050d010` | second path-scan variant uses the same movement status semantics. |
| `0x005a3207` | caller `0x005a2e00` | local-player movement path calls with current coordinates and direction; `0` triggers blocked packet/path behavior, `>0` proceeds with movement send/update. |
| `0x00505461` | callee `0x00505080` | converts direction byte to tile offset. |
| `0x0050548a` / `0x00505495` | callees `0x004b7c50` / `0x004b7e80` | builds and tests map bounds rect. |
| `0x005054d4` | callee `0x00533090` | object-list lookup at next coordinate. |
| `0x0050550e` | callee `__wcsicmp` with `0x0061e6f8` | GM object-name bypass. |
| `0x00505544`, `0x0050555c` | callee `0x0050c120` twice | current and next tile-layer id lookups. |

## Documentation Evidence And IDA Status
- Existing docs that support the conclusion: MapPane class/file docs, [UID:0001AP] aggregate, [UID:00027O] direction masks, [UID:0000Q3]/[UID:0000Q4] compact SOBJ globals, [UID:0003ZM] remap constants, [UID:0003IO] shared `GM` string.
- Historical pre-callback stale docs: target formal C++ had a nullable `m_activeObjectPane` guard not present in binary, and generated `MapPane.cpp` had a mask-symbol mismatch between target use and support declaration.
- Generated/coverage report state after callback: generated `MapPane.cpp` header reports validator-command-id `000000005484`, refreshed `2026-07-03T14:12:55-04:00`; UID000425 emits at `Completion:88 | Confidence:90`, uses `s_objectDirectionMasks/s_objectReverseDirectionMasks`, and UID00027O now declares those names.

## Ranked Ownership Analysis

### 1. [UID:00007Q] MapPane class
- Evidence for: `thiscall` receiver, MapPane field reads, MapPane object list, MapPane tile helper, MapPane caller family, direct class page field glossary, and accepted aggregate split.
- Evidence against: dependencies on ObjectList, globals, and local-player state are material but are callee/data dependencies, not ownership.
- Decision: best and current owner; keep.

### 2. [UID:0000L3] MapPane file
- Evidence for: final source route is `NexusTK/map/MapPane.cpp`; direction masks and compact SOBJ globals are MapPane file-local/support data.
- Evidence against: the function body is an instance method, so class page is the narrower canonical owner.
- Decision: keep as source root reached through [UID:00007Q], not direct canonical owner.

### 3. ObjectList / LivingObjectPane / UserPane alternatives
- Evidence for: ObjectList lookup is called, and the local-player movement caller at `0x005a2e00` consumes the result.
- Evidence against: ObjectList does not own MapPane dimensions, tile-layer helper, active-object field, or globals; LivingObjectPane/UserPane call into MapPane or provide the active object pointer but do not contain this method's state.
- Decision: rejected as owners.

### Proposed new file/grouping, if applicable
- No new file or grouping is recommended. `MapPane.cpp` already owns the movement helper surface.

## Source Placement
- Recommended source placement: `MapPane::CheckMovementCollision` in `NexusTK/map/MapPane.cpp` through [UID:00007Q].
- This placement fits the source tree because the method uses MapPane map dimensions, active local object pointer, object list, tile-layer access, and MapPane-owned compact SOBJ movement data.
- Rejected placements: ObjectList, LivingObjectPane/UserPane, GameServerConfig, StaticObjImageLib, and no-owner/non-emitting.
- Remaining placement uncertainty: exact original private/public declaration location is not proven; not material to by-memory owner/emitter state.

## Range / Split / Padding / Reclassification Analysis
- Exact range/boundary facts: function `0x00505430-0x005055ca`; immediate `0x005055ca-0x005055d0` alignment is already recorded in `by-memory/-ignored.md`; successor `0x005055d0-0x005055db` is [UID:000426].
- Children/subranges: no new child pages required.
- Padding/table/data/code distinctions: all code in target is modeled function body; padding and successor are outside.
- Parent/container impact: [UID:0001AP] aggregate remains source-range index; no parent score change required unless support sync is accepted.

## Negative Evidence Summary
- ObjectList ownership is rejected because the method only calls ObjectList after MapPane bounds/active-object checks and continues into MapPane tile/global logic.
- LivingObjectPane/UserPane ownership is rejected because `0x005a2e00` is a caller/consumer; it passes `MapPane *` loaded from the local player state into this method.
- Global data ownership is rejected for the method body because `g_objectRecordCount`, `g_objectNationMap`, and mask arrays are data dependencies with separate pages.
- Broad aggregate ownership is rejected because [UID:0001AP] is already a reviewed aggregate/index with exact children.
- Nullability inference is rejected for `m_activeObjectPane` inside this function because disassembly has no null branch before `[eax+0x1340fc]`.

## IDA Rename / Type / Comment Recommendations
- Proposed source-facing names/types:
  - Keep `MapPane::CheckMovementCollision(int mapColumn, int mapRow, unsigned char direction)`.
  - Keep `MapPoint`, `MapRect`, `MapTileLayerIds`, `m_activeObjectPane`, `m_objectList`, `g_objectRecordCount`, and `g_objectNationMap`.
  - Rename/synchronize [UID:00027O] formal arrays to `s_objectDirectionMasks` and `s_objectReverseDirectionMasks`, or update UID000425 to whatever names the mask page actually emits. The better source-facing choice is to rename the support arrays, because the target behavior proves current-vs-reverse direction semantics.
- Items intentionally left unchanged: no IDA DB rename/type/comment edits were requested by the accepted report or implementation callback.
- IDA DB edits: not requested and not performed.

## First-Draft C++ Recommendation
- Eligible for draft C++: yes. UID000425 has a confirmed emitter route, combined score above the code-entry gate, exact modeled function range, and current MCP-backed behavior.
- Applied code: the target formal `RECONSTRUCTION_CPP CODE` block was replaced with this exact text after Gate 1 approval:

```cpp
int MapPane::CheckMovementCollision(int mapColumn, int mapRow, unsigned char direction)
{
    MapPoint offset;
    DirectionToTileOffset(&offset, direction);

    const int nextColumn = mapColumn + offset.column;
    const int nextRow = mapRow + offset.row;

    MapRect mapBounds;
    SetRect(&mapBounds, 0, 0, m_mapWidth, m_mapHeight);
    if (!PointInRect(nextRow, nextColumn, &mapBounds))
        return -1;

    if (m_activeObjectPane->AllowsMovementCollisionBypass())
        return 1;

    ObjectPane *blockingObject = m_objectList->FindObjectAtMapPoint(nextColumn, nextRow);
    if (blockingObject != NULL) {
        if (_wcsicmp(blockingObject->GetObjectName(), L"GM") != 0 &&
            !blockingObject->IsMovementPassable()) {
            return 0;
        }
    }

    MapTileLayerIds currentTile;
    MapTileLayerIds nextTile;
    GetLegacyAwareMapTileLayerIds(&currentTile, mapColumn, mapRow);
    GetLegacyAwareMapTileLayerIds(&nextTile, nextColumn, nextRow);

    if ((g_objectRecordCount >= currentTile.objectNation ||
         g_objectRecordCount >= nextTile.objectNation) &&
        (g_objectNationMap[currentTile.objectNation] & s_objectDirectionMasks[direction]) == 0 &&
        (g_objectNationMap[nextTile.objectNation] & s_objectReverseDirectionMasks[direction]) == 0 &&
        nextTile.groundTileId != 0 &&
        (nextTile.flags & 0x10000) == 0) {
        return 1;
    }

    return -1;
}
```

- Reason it preserves exact original behavior: the code keeps the `-1/0/1` returns, no null check on `[this+0x418]`, same bounds check, same object-list lookup, same `GM`/passability gate, same two tile helper calls, same unusual OR count guard, same direction-mask tests, and same ground/flag checks.
- Reason it matches plausible mid-2000s source shape: it uses ordinary private method/helper calls and small POD structs instead of decompiler temporaries, raw offsets, or generated labels.
- Inferred names/types used: `MapPoint`, `MapRect`, `MapTileLayerIds`, `m_activeObjectPane`, `m_objectList`, `FindObjectAtMapPoint`, `AllowsMovementCollisionBypass`, `objectNation`, `groundTileId`, `flags`.
- Naming/coding style convention: existing MapPane child C++ uses class methods, `MapPoint`/`MapRect`, and private helper calls; this keeps that style.
- Reason code should remain blank: not applicable.
- Exact no-code proof: not applicable.

## Final Recommendation
- Applied target changes: target is `COMPLETION:88`, `CONFIDENCE:90`; `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, and blank optional position were preserved; formal C++ was replaced with the corrected block; current MCP `e63ee655` evidence was added.
- Applied support changes: MapPane class/file and [UID:0001AP] notes now carry current `e63ee655` proof; [UID:00027O] direction-mask support now emits formal array names matching the target code.
- Exact future work outside this assignment: a broader generated-source ordering audit may still be useful because file-scope data appears after UID000425 in generated output, but this callback fixed the accepted symbol-name mismatch.

## Recommended Target Doc Changes
- Target path: `by-memory/0x00505430-0x005055ca.MapPaneCheckMovementCollision.md`
- Exact report facts to incorporate:
  - MCP session `e63ee655`, `server_health ok`, function range/size, callees/callers, branch facts, active-object no-null evidence, object/GM/passability gate, tile-layer helper calls, global/mask xrefs, and boundary facts.
  - Historical pre-callback generated-output caveat: target/support mask names were mismatched. Post-callback generated output now uses matching names.
- Metadata/score/owner/emitter/reconstructable/C++ changes:
  - `COMPLETION:88`
  - `CONFIDENCE:90`
  - keep owner `00007Q`
  - keep reconstructable `TRUE`
  - keep emitter `00007Q`
  - replace formal C++ with the recommended block above.
- Historical/stale assumptions to preserve: the prior B009 split was correct for ownership/range, but its formal C++ should be repaired for active-object nullability and support-symbol consistency.

## Recommended Support Doc Changes
- Support path: `by-class/MapPane.md`
  - Applied: added current UID000425 evidence that `e63ee655` confirms no-null `m_activeObjectPane` bypass, object-list blocker/GM check, two `GetLegacyAwareMapTileLayerIds` calls, SOBJ object-nation globals, direction-mask tables, and caller set.
- Support path: `by-file/MapPane.md`
  - Applied: confirmed UID000425 remains a MapPane.cpp method and that [UID:00027O] direction masks are file-local data consumed by the method.
- Support path: `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`
  - Applied: updated UID000425 row with current MCP evidence and corrected C++ disposition; no parent metadata change.
- Support path: `by-memory/0x0066dd50-0x0066dd60.MapObjectDirectionMasks.md`
  - Applied: formal C++ names now match target use, with `s_objectDirectionMasks` for `0x0066dd50` and `s_objectReverseDirectionMasks` for `0x0066dd58`, replacing `s_mapObjectDirectionMaskA/B`.
  - Excluded-with-reason: no emitter ordering/forward-declaration edit was made because the accepted implementation scope required symbol-name sync, not generator ordering redesign; generated output now has coherent names.

## Score And Metadata Recommendation
- Historical pre-callback score/metadata: `86/87`, owner/emitter [UID:00007Q], reconstructable true, formal C++ populated.
- Applied score/metadata: `88/90`, same owner/emitter/reconstructable, formal C++ corrected.
- Score rationale and reason not higher/lower: completion rose because the report resolved current range, caller set, active-object no-null behavior, exact global/mask consumers, generated symbol mismatch, and implementation-ready C++. Confidence rose because MCP disassembly/decompilation agree and support docs corroborate the owner/data route. Scores stay below 95 because original source spellings and some struct field names remain inferred; the accepted mask name sync is applied, while broader generated declaration ordering remains outside this callback's scope.
- Score-improvement attempts:
  - Range blocker: resolved by fresh `lookup_funcs`, disasm, and boundary query.
  - Caller blocker: resolved by `analyze_function`, `xrefs_to`, and caller decompile.
  - C++ blocker: resolved with exact formal replacement.
  - Support-symbol blocker: converted into an implementation-ready support sync.
  - Owner/source-placement blocker: resolved; no move recommended.
- Metadata fields to change or leave unchanged: change scores only; leave owner/reconstructable/emitter/optional unchanged.

## Open Questions With Attempted Resolution
- Exact original predicate name for byte `UserPane/LivingObjectPane +0x1340fc`: evidence proves the read and source role, but not the original symbol. `AllowsMovementCollisionBypass()` is a safe descriptive method name because it represents the byte read and returns early with allow status.
- Exact tile-layer struct field names: `objectNation`, `groundTileId`, and `flags` are inferred from `sub_50C120` consumers and support docs. No stronger original names were found in current docs/MCP; these names are source-quality enough for first draft but cap confidence.
- Direction-mask names: historical support C++ used `A/B`; target uses current/reverse descriptive names. MCP proves the first table is tested against the current tile object-nation byte and the second against the next tile object-nation byte, so descriptive current/reverse names were applied to [UID:00027O].
- Count guard semantics: the binary uses the unusual `(count >= current || count >= next)` guard before indexing both entries. This report preserves it exactly rather than "fixing" it to a safer-looking `&&`.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text
- Not applicable. No manual `-coverage-report.md` or supervisor-owned tracker edit is recommended. Validator-owned generated reports should refresh through validators after accepted implementation.

## Follow-Up Actions
- Supervisor actions: any verification, execution, or archival lifecycle actions remain supervisor-owned and are not performed by B005.
- A-agent actions: none.
- B005 future research actions: none; accepted callback implementation is complete.

## Confidence
- Recommendation confidence: high.
- Score confidence: medium-high; `88/90` reflects strong behavior evidence but not final original-symbol proof.
- Remaining uncertainty: exact original names for active-object bypass predicate, tile-layer result fields, and mask-table identifiers.

## Validator Results
- Commands run:
  - `python .\tools\validator.py --mode file --file by-memory/0x00505430-0x005055ca.MapPaneCheckMovementCollision.md --apply --queue-timeout 240`
    - `command_id: 000000005480`, `command_timestamp: 2026-07-03T14:12:10-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-class/MapPane.md --apply --queue-timeout 240`
    - `command_id: 000000005481`, `command_timestamp: 2026-07-03T14:12:28-04:00`, exit `0`, `ok: 1`, generated refresh deferred; existing unrelated `missing_ref_uid` warnings remained on the large class page.
  - `python .\tools\validator.py --mode file --file by-file/MapPane.md --apply --queue-timeout 240`
    - `command_id: 000000005482`, `command_timestamp: 2026-07-03T14:12:39-04:00`, exit `0`, `ok: 1`, generated refresh deferred; existing unrelated `missing_ref_uid` warnings remained on the large file page.
  - `python .\tools\validator.py --mode file --file by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md --apply --queue-timeout 240`
    - `command_id: 000000005483`, `command_timestamp: 2026-07-03T14:12:47-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-memory/0x0066dd50-0x0066dd60.MapObjectDirectionMasks.md --apply --queue-timeout 240 --wait-generated`
    - `command_id: 000000005484`, `command_timestamp: 2026-07-03T14:12:55-04:00`, exit `0`, `ok: 1`, generated refresh completed.
- Generated freshness: `auto-generated/NexusTK/map/MapPane.cpp` now reports `validator-command-id: 000000005484`, `validator-refreshed-at: 2026-07-03T14:12:55-04:00`, `validator-refresh-source: foreground-generated-refresh`. Read-only check confirms UID000425 emits at `88/90`, uses `s_objectDirectionMasks` / `s_objectReverseDirectionMasks`, and UID00027O declares those names.
- Warnings/errors: no target-specific errors. Class/file validators reported existing unrelated `missing_ref_uid` warnings; mask validator reported broad generated-refresh warnings such as child-marker and emitter-no-code rows outside this target.

## Changed Files
- Created: `tools/leaser/Agents/Agent-B005/research/000425-MapPaneCheckMovementCollision-source-quality.md` during the report-only pass.
- Modified by accepted callback:
  - `by-memory/0x00505430-0x005055ca.MapPaneCheckMovementCollision.md`
  - `by-class/MapPane.md`
  - `by-file/MapPane.md`
  - `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`
  - `by-memory/0x0066dd50-0x0066dd60.MapObjectDirectionMasks.md`
- Renamed: none.
- Validator-owned generated refresh occurred through command `000000005484`; B005 did not manually edit generated files, coverage reports, validator state, supervisor ledgers, archives, or lifecycle state.
- Lease notes: B005 leased the five accepted by-* files before editing per the callback. Historical callback observation: after validators, the attempted `release` command failed because this leaser uses `unlease`; the subsequent `unlease` attempt found the target and mask pages with no active lease and found the three MapPane support pages leased by B006 during the expired `2026-07-03T18:12:51Z` to `2026-07-03T18:17:51Z` window. B005 made no further by-* edits after that historical lease observation. Repair-time final lease check found no active B005/B006 matches for the UID000425 target/support files.
- Report execution: not run. B005 did not run `execute_report`, lifecycle commands, report moves, registry commands, or archive commands.

## Implementation Tracking Checklist
- [x] Supervisor Gate 1 validation completed before implementation; callback accepted report SHA256 `9095273E74686E3CAA299FD4868757FCDA0336D67EF6B19C541D9AA442E332FD`.
- [x] Target/support docs updated: target by-memory page; `by-class/MapPane.md`; `by-file/MapPane.md`; `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`; [UID:00027O] direction-mask page for symbol-name sync.
- [x] Current target state and actual evidence checked recorded: current `88/90`, owner/emitter [UID:00007Q], formal C++ corrected; MCP session `e63ee655` evidence recorded.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score changes applied: target `COMPLETION:88`, `CONFIDENCE:90`.
- [x] Score-limiting blockers researched to resolution or implementation-ready plan: range, caller, no-null bypass, mask support mismatch, owner route, and C++ body resolved; original symbol spellings remain score caps.
- [x] Owner/emitter/reconstructable changes confirmed not applicable: kept owner/emitter [UID:00007Q], reconstructable true.
- [x] Split/rename/new-child changes confirmed not applicable.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes confirmed: source placement unchanged; no IDA DB edits; support symbol rename applied in by-* docs only.
- [x] First-draft C++ applied: target formal C++ replaced with the exact corrected block.
- [x] Third-party import directive confirmed not applicable.
- [x] Exact target/support doc facts incorporated at report-level detail: MCP evidence, callers, callees, globals, masks, branch behavior, return semantics, range/boundary, generated symbol mismatch repair, rejected owners.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: nullable active-object guard rejected; ObjectList/LivingObjectPane/global/aggregate ownership rejected.
- [x] Wave2/Wave3 mentions or artifacts handled: generated output used only as mismatch/freshness evidence; old Wave material not used as proof.
- [x] Open questions documented as evidence-backed unresolved: final symbol spellings for predicate, tile-layer fields, and mask tables remain inferred with score impact.
- [x] Validators run for every changed by-* file; command IDs `000000005480` through `000000005484` recorded above.
- [x] Generated report refresh completed through validator command `000000005484`; no manual coverage/tracker text or generated-file edits were made.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000005519","destination_path":"executed-b-agent-research/B005/000425-MapPaneCheckMovementCollision-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/000425-MapPaneCheckMovementCollision-source-quality.md","timestamp":"2026-07-03T14:39:24-04:00","uid":"000425"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
