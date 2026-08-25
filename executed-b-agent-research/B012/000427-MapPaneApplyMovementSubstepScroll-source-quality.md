** TARGET-REPORT-UID:000427 **
** AUTHOR-AGENT-ID:B012 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **

# 000427 MapPaneApplyMovementSubstepScroll Source Quality

## Executive Recommendation

For exact target path `by-memory/0x005055e0-0x00505645.MapPaneApplyMovementSubstepScroll.md`, keep UID000427 as a source-bearing `MapPane` method under [UID:00007Q][MapPane](../../../../../by-class/MapPane.md), emitted through [UID:0000L3][MapPane](../../../../../by-file/MapPane.md) / `NexusTK/map/MapPane.cpp`. Current MCP session `60724697` validates the existing formal C++ behavior, the exact `0x005055e0-0x00505645` range, the two `UserPane`/local-player animation call sites inside `0x005a83b0`, the `DirectionToTileOffset` and shifted-invalidation callees, and the `g_movementSubstepScale` / tile-dimension dependencies.

Callback-applied outcome: exact target `by-memory/0x005055e0-0x00505645.MapPaneApplyMovementSubstepScroll.md` now has `COMPLETION:88`, `CONFIDENCE:91`; preserves `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, and blank `EMITTER_POSITION_OPTIONAL`; and keeps the formal C++ source-bearing block below. The implementation synchronized documentation/source quality rather than splitting or converting to no-code: target/support prose now binds physical field order as `+0xb0` = column/X pixel origin and `+0xac` = row/Y pixel origin, because the inherited shorthand "`+0xac/+0xb0` as X/Y" was reversed if read as ordered offset-to-name mapping.

## Supervisor Active Recheck

Gate 1 passed and the implementation callback has been applied for exact UID000427 target path `by-memory/0x005055e0-0x00505645.MapPaneApplyMovementSubstepScroll.md`. B012 edited only the accepted target/support by-* docs and this report, with validator-owned projected stats updates from scoped `--apply` validation. B012 did not manually edit generated files, coverage reports, validator state, lifecycle/archive files, or supervisor ledgers. B012 did not run `execute_report`, any execute/probe/dry-run lifecycle variant, any validator lifecycle command, or any IDA DB/process/session-management mutation.

The active read-only MCP evidence pass used session `60724697`, found by `idb_list` as the sole active IDB-backed NexusTK session. `server_health` returned `status:ok`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`.

## Finalized Report / Current Recommendation

UID000427 at exact path `by-memory/0x005055e0-0x00505645.MapPaneApplyMovementSubstepScroll.md` is not an empty emitter and was not downgraded to blank C++. The existing method-level source shape remains valid: convert a direction byte to a tile delta, scale row/column by global tile dimensions and `4 * g_movementSubstepScale`, update MapPane pixel-origin state, and invalidate the shifted pane region with negated deltas.

The formal source-bearing C++ was retained, and the target/support docs now carry current MCP proof plus corrected field-order wording. The exact source-facing names `MapPoint::row`, `MapPoint::column`, `m_viewportPixelX`, `m_viewportPixelY`, and `InvalidateShiftedMapArea` remain inferred but are coherent with existing MapPane support now that the physical offset order is documented as `+0xb0` for X/column and `+0xac` for Y/row.

## Supporting Research

This pass rechecked exact target `by-memory/0x005055e0-0x00505645.MapPaneApplyMovementSubstepScroll.md` rather than relying on the UID alone, because historical material also uses UID000427 for unrelated `by-memory/0x004597b0-0x00459804.RankingDialogInvalidateActionButtons.md`. All claims below bind to the exact MapPane path and address range.

Current documentation basis:

- Target page `by-memory/0x005055e0-0x00505645.MapPaneApplyMovementSubstepScroll.md`.
- Parent aggregate [UID:0001AP][0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore](../../../../../by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md).
- Direct class/file parents [UID:00007Q][MapPane](../../../../../by-class/MapPane.md) and [UID:0000L3][MapPane](../../../../../by-file/MapPane.md).
- Support pages [UID:00041W][0x00505080-0x00505100.MapPaneDirectionToTileOffset](../../../../../by-memory/0x00505080-0x00505100.MapPaneDirectionToTileOffset.md), [UID:0002QM][0x005059d0-0x00505bf8.MapPaneRecenterAndSendPosition](../../../../../by-memory/0x005059d0-0x00505bf8.MapPaneRecenterAndSendPosition.md), [UID:00042K][MapPaneLayout](../../../../../by-type/by-struct/MapPaneLayout.md), [UID:0002CF][g_movementSubstepScale](../../../../../by-global/g_movementSubstepScale.md), [UID:0000T7][MapTilePixelDimensions](../../../../../by-global/MapTilePixelDimensions.md), and [UID:0003UH][0x005a88d0-0x005a89c9.LivingObjectPaneUpdateScreenPosition](../../../../../by-memory/0x005a88d0-0x005a89c9.LivingObjectPaneUpdateScreenPosition.md).
- Generated output was read-only: `auto-generated/NexusTK/map/MapPane.cpp` currently includes UID000427 with the existing formal body at validator header `000000006160` / `2026-07-04T05:57:51-04:00`.

## Target

- UID: `000427`, with historical collision caution.
- Exact target path: `by-memory/0x005055e0-0x00505645.MapPaneApplyMovementSubstepScroll.md`.
- Exact address range: `0x005055e0-0x00505645`.
- IDA function: `sub_5055E0`.
- Current IDA size: `0x65` / 101 bytes, verified through MCP session `60724697`.
- Current source-facing name: `MapPane::ApplyMovementSubstepScroll(unsigned char direction)`.
- Current owner/emitter route: [UID:00007Q][MapPane](../../../../../by-class/MapPane.md) -> [UID:0000L3][MapPane](../../../../../by-file/MapPane.md) / `NexusTK/map/MapPane.cpp`.

## Current Target State

Current exact target metadata in `by-memory/0x005055e0-0x00505645.MapPaneApplyMovementSubstepScroll.md`:

| Field | Current value |
| --- | --- |
| `COMPLETION` | `88` |
| `CONFIDENCE` | `91` |
| `CANONICAL_OWNER` | `00007Q` |
| `RECONSTRUCTABLE` | `TRUE` |
| `EMITTER_UIDS` | `00007Q` |
| Formal C++ | populated |

The current formal C++ is source-shaped and materially matches current MCP behavior. The target prose has been updated from inherited B009 0001AP-only evidence to current target-specific proof and now explains the physical order proven by this target and the recenter sibling: width/column/X writes go to `+0xb0`, while height/row/Y writes go to `+0xac`.

## Heuristic / Inference Reanalysis And Validation

The in-scope blocker was not whether the helper could emit code; it already emits. The blocker was whether the existing C++ and documentation are source-quality accurate enough to count without a direct target report. Current MCP resolves the body:

- `0x005055e0` is a modeled `__thiscall` function with one basic block, cyclomatic complexity 1, and no strings.
- The function calls `0x00505080` (`DirectionToTileOffset`) and `0x005549d0` (inferred shifted-region invalidation helper through `this + 4`).
- It reads `byte_66DA96` (`g_movementSubstepScale`), shifts by two to form `4 * scale`, reads signed tile width `word_66DA9C` and tile height `word_66DAA0`, and performs signed `idiv` for both deltas.
- Decompile and disassembly agree that the column/width delta writes to `MapPane+0xb0`; the row/height delta writes to `MapPane+0xac`.
- The call to `sub_5549D0(this + 1, -columnDelta, -rowDelta)` validates `InvalidateShiftedMapArea(-deltaX, -deltaY)` as the source-level intent, while preserving that `sub_5549D0` is an inferred helper name.
- Caller context at `0x005a8589` in `sub_5A83B0` places this helper in the user/local-player movement animation step, between direction/object-position handling and `MapPaneScrollViewportByDirection` at `0x005058b0`.

The existing formal block remains behaviorally correct if support docs define `m_viewportPixelX` as the `+0xb0` column/X pixel origin and `m_viewportPixelY` as the `+0xac` row/Y pixel origin. Leaving support docs with ordered shorthand "`+0xac/+0xb0` = X/Y" is the remaining source-quality defect.

## Inference Research Guidance Check

Current evidence resolves every score/source-quality blocker in scope:

- Owner/emitter route: resolved to MapPane class/file route by `thiscall` receiver, parent aggregate membership, direct MapPane support pages, and generated `MapPane.cpp` output.
- Range/split/padding: resolved; `0x005055e0` is a 0x65-byte function, `0x00505645` is not a function, `0x00505645-0x00505650` is alignment padding, and `0x00505650` is the next modeled helper.
- C++ readiness: resolved; formal source is appropriate and should remain in the target. The report provides exact formal insertion text below.
- Field/type blocker: resolved to an implementation-ready documentation correction. The formal source can keep `m_viewportPixelX/Y`, but target/support docs must state the physical offset mapping explicitly.
- Historical UID collision: resolved by binding this report to exact target path and range; unrelated RankingDialog UID000427 material is negative evidence only.

No rare no-improvement exception is claimed. The report recommends concrete target/support improvements and a modest score increase.

## Evidence Standards Used

MCP facts come from bounded read-only calls in active session `60724697`. Current by-* docs are used as support documentation and source-route evidence, not as substitutes for the MCP pass. Executed and active reports are used only as leads when they match current target path/range and current MCP facts. Inferred names are labeled where original symbols are not recovered.

## Evidence Checked

- MCP `idb_list`: active session `60724697`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker backend, not analyzing.
- MCP `server_health`: `status:ok`, `module:NexusTK.exe`, `imagebase:0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.
- MCP `lookup_funcs` for `0x005055e0`, `0x00505645`, `0x00505650`, `0x00505080`, `0x00505100`, `0x005058b0`, `0x005549d0`, `0x005a83b0`, `0x005a8524`, `0x005a8589`, and boundary addresses inside the target.
- MCP `analyze_function 0x005055e0`, `decompile 0x005055e0`, and paged `disasm 0x005055e0`.
- MCP paged `disasm 0x005a83b0` around call site `0x005a8589`.
- MCP paged `disasm 0x005059d0` around pixel-origin stores to cross-check `+0xac/+0xb0` order.
- MCP `get_bytes` for `0x00505640` size 32 and `0x005055db` size 16.
- MCP `int_convert` for `0x65`, `0xac`, `0xb0`, `0x5055e0`, `0x505645`, `0x66da96`, `0x30`, and `0x4`.
- Current docs checked: exact target page, MapPane class/file pages, UID0001AP aggregate, UID00041W direction helper, UID0002QM recenter helper, UID00042K layout support, g_movementSubstepScale, MapTilePixelDimensions, generated `MapPane.cpp`, project completion stats, generated research tracker, and generated memory coverage.
- Prior-report search terms: `000427`, `0x005055e0`, `0x00505645`, `MapPaneApplyMovementSubstepScroll`, `ApplyMovementSubstepScroll`, `0001AP`, and exact target path. Relevant match opened/used: executed B009 `0001AP-MapPaneWeatherCoordinateObjectCore-source-quality.md`. Unrelated UID collision match: executed B001 `0000XZ-RankingDialog-source-quality.md` created a different UID000427 page at `0x004597b0-0x00459804`, rejected for this target.

## IDA MCP Facts

- `lookup_funcs`: `0x005055e0` -> `sub_5055E0`, size `0x65`; `0x00505645` -> not a function; `0x00505650` -> `sub_505650`, size `0xce`.
- `lookup_funcs`: `0x00505080` -> `sub_505080`, size `0x6b`; `0x00505100` -> `sub_505100`, size `0x24`; `0x005058b0` -> `sub_5058B0`, size `0x8e`; `0x005549d0` -> `sub_5549D0`, size `0x28`; `0x005a83b0` -> `sub_5A83B0`, size `0x3fd`.
- `analyze_function 0x005055e0`: prototype `char __thiscall(_DWORD *this, char)`, size 101, one basic block, callers `sub_5A83B0`, callees `sub_505080` and `sub_5549D0`, xrefs to target at `0x5a8524` and `0x5a8589`.
- `decompile 0x005055e0`: calls `sub_505080(&local, direction)`, computes `v4 = 4 * byte_66DA96`, computes `v5 = offset[1] * word_66DA9C / v4`, computes `v7 = offset[0] * word_66DAA0 / v4`, adds `v5` to `this[44]`, adds `v7` to `this[43]`, and returns `sub_5549D0(this + 1, -v5, -v7)`.
- `disasm 0x005055e0`: `0x5055f7 movsx esi, byte_66DA96`; `0x5055fe shl esi, 2`; `0x505606 movsx eax, word_66DA9C`; `0x505611 idiv esi`; `0x50561f add [ebx+0B0h], ecx`; `0x505615/0x505628` height path; `0x50562a add [ebx+0ACh], eax`; `0x505637 call sub_5549D0`; `0x505642 retn 4`.
- Boundary bytes at `0x00505640`: `e5 5d c2 04 00 cc cc cc cc cc cc cc cc cc cc cc 55 8b ec ...`; this proves the target's `retn 4` ends before padding and the next function prologue begins at `0x00505650`.
- Pre-target bytes at `0x005055db`: five `0xcc` bytes before the target prologue at `0x005055e0`.
- Recenter sibling `0x005059d0` disassembly cross-check: current/EPF pixel-origin setup stores tile width-derived X/column values to `[ebx+0B0h]` at `0x505a81` / `0x505a99`, and tile height-derived Y/row values to `[ebx+0ACh]` at `0x505aad`.

## Function / Child Inventory

| Exact range/path | Role | Owner/emitter | Current disposition | Recommendation |
| --- | --- | --- | --- | --- |
| `by-memory/0x005055e0-0x00505645.MapPaneApplyMovementSubstepScroll.md` | Source-bearing movement substep scroll method | `00007Q` / `00007Q` | `86/88`, formal C++ populated | Raise to `88/91`; keep source-bearing formal C++; add current MCP proof and field-order caveat |
| `0x005055db-0x005055e0` | Pre-target padding | none | already in `by-memory/-ignored.md` | No child page; preserve as alignment |
| `0x00505645-0x00505650` | Post-target padding | none | already in `by-memory/-ignored.md` | No child page; preserve as alignment |
| `0x00505650-...` | Successor `MapPaneGetAdjacentVisibleTileBounds` | `00007Q` | separate child UID000428 | Not part of UID000427 |
| `0x004597b0-0x00459804.RankingDialogInvalidateActionButtons.md` | Historical unrelated UID000427 collision | RankingDialog | unrelated executed B001 child | Reject as evidence for this MapPane target |

## Direct Xref / Caller Inventory

Current MCP reports two code xrefs/call sites to exact target `0x005055e0`, both inside `sub_5A83B0`:

| Call site | Function | Target-specific meaning |
| --- | --- | --- |
| `0x005a8524` | `sub_5A83B0` | Earlier movement path call recorded by `analyze_function` xrefs; belongs to the same user/local-player animation-step function. |
| `0x005a8589` | `sub_5A83B0` | Paged disassembly shows `mov ecx, [edi+134054h]`, push direction byte, call `sub_5055E0`, then call `sub_5058B0`; this is the direct movement substep scroll path into MapPane. |

No data xrefs or vtable/table dispatch route are needed for this target because it is an ordinary direct-called `MapPane` method. The direct caller is a consumer and not an owner; it obtains the active MapPane pointer and dispatches to MapPane movement helpers.

## Documentation Evidence And IDA Status

Current target docs correctly identify the behavior at a high level and already contain formal C++. Current MapPane class/file docs correctly route the coordinate/movement helper surface through `NexusTK/map/MapPane.cpp`; UID0001AP correctly lists UID000427 as an exact child and records the helper's use of `DirectionToTileOffset`, `g_movementSubstepScale`, tile dimensions, and shifted invalidation. Generated `MapPane.cpp` emits UID000427 as source-bearing code.

The documentation gap is target-specific detail. The current target page still depends on the accepted 0001AP report instead of current MCP `60724697` proof and does not state the physical field order. MapPaneLayout and the target page list `+0xac/+0xb0` followed by X/Y names; that shorthand is unsafe. Current target and recenter evidence prove the ordered mapping should be documented as `+0xb0` = X/column pixel origin and `+0xac` = Y/row pixel origin.

## Range / Split / Padding / Reclassification Analysis

The exact target range `0x005055e0-0x00505645` is correct. `lookup_funcs` reports `sub_5055E0` size `0x65`; `0x00505645` is not a function; `0x00505650` is the next modeled function `sub_505650`. Raw bytes show the target ends with `retn 4` bytes `c2 04 00`, followed by eleven `0xcc` padding bytes through `0x00505650`. The five bytes before the target (`0x005055db-0x005055e0`) are also `0xcc` padding.

No split or child creation is required. The target is already the correct child granularity under UID0001AP. Parent aggregate UID0001AP should remain an aggregate marker/index; emitting UID000427 through the aggregate would duplicate child output.

## IDA Rename / Type / Comment Recommendations

No IDA rename, type application, stack declaration, or comment mutation was performed or is required for Gate 1. If a future IDA annotation pass is allowed, useful non-mutating source-facing names are:

- `sub_5055E0` -> `MapPane::ApplyMovementSubstepScroll`.
- `sub_505080` -> `DirectionToTileOffset`.
- `sub_5549D0` -> inferred `InvalidateShiftedMapArea`.
- `byte_66DA96` -> `g_movementSubstepScale`.
- `word_66DA9C` / `word_66DAA0` -> `g_mapTilePixelWidth` / `g_mapTilePixelHeight`.
- `MapPane+0xb0` -> X/column pixel origin; `MapPane+0xac` -> Y/row pixel origin. Exact final member spellings may remain `m_viewportPixelX/m_viewportPixelY` or the sibling `m_pixelOriginX/m_pixelOriginY`, but docs must not imply `+0xac` is X.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual `-coverage-report.md` or tracker edit is required from B012. If the supervisor wants a manual note after callback, use:

`UID000427 exact target by-memory/0x005055e0-0x00505645.MapPaneApplyMovementSubstepScroll.md rechecked with MCP session 60724697; source-bearing MapPane method remains owner/emitter 00007Q with formal C++, raised to 88/91 after documenting direct 0x005a83b0 callers, exact 0x65-byte range, 0x00505645-0x00505650 padding, DirectionToTileOffset/g_movementSubstepScale/tile-dimension dependencies, and corrected physical pixel-origin order (+0xb0 X/column, +0xac Y/row).`

## Follow-Up Actions

Implementation callback is complete. Current follow-up is supervisor Gate 2 verification and supervisor-owned execution if accepted. No additional B012 implementation work remains unless Gate 2 finds a concrete defect. No report lifecycle or `execute_report` action belongs to B012.

## Confidence

Recommended confidence is `91`. Current MCP proves range, function status, boundary padding, body, direct callers, callee set, global reads, field writes, and sibling field-order cross-check. Confidence remains below final `95+` because exact original member spellings for the pixel-origin pair and exact original spelling for `InvalidateShiftedMapArea` remain inferred.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-000427-01 | Exact target path is `by-memory/0x005055e0-0x00505645.MapPaneApplyMovementSubstepScroll.md`; historical UID000427 RankingDialog material is unrelated. | High | Goal collision warning; rg found unrelated B001 RankingDialog UID000427 at `0x004597b0-0x00459804` | Target page Evidence; `by-class/MapPane.md`; `by-file/MapPane.md` | Applied exact path/range binding and rejected RankingDialog alias evidence | applied |
| C-000427-02 | `0x005055e0` is `sub_5055E0`, size `0x65` / 101 bytes; `0x00505645` is not a function; `0x00505650` starts successor `sub_505650`. | High | MCP `lookup_funcs`, `disasm`, `get_bytes` | Target page Evidence; UID0001AP covered-range row | Applied current MCP range and padding proof | applied |
| C-000427-03 | Function body is one-block `char __thiscall(_DWORD *this, char)` with callers from `sub_5A83B0` and callees `sub_505080` / `sub_5549D0`. | High | MCP `analyze_function`, `decompile`, `disasm` | Target page Evidence/Cross-References; `by-class/MapPane.md`; `by-file/MapPane.md`; UID0001AP row | Applied current body/caller/callee evidence | applied |
| C-000427-04 | Body computes `4 * g_movementSubstepScale`, width-scaled column delta, height-scaled row delta, then invalidates shifted area with negated deltas. | High | MCP decompile/disasm refs to `byte_66DA96`, `word_66DA9C`, `word_66DAA0`, `sub_5549D0` | Target formal `RECONSTRUCTION_CPP CODE` block and target prose | Formal block was already present and preserved; target prose now adds behavior rationale | applied |
| C-000427-05 | Physical pixel-origin order is `+0xb0` X/column and `+0xac` Y/row; existing ordered shorthand `+0xac/+0xb0` -> X/Y is stale/unsafe. | High | MCP target disasm writes `[ebx+0B0h]` for width and `[ebx+0ACh]` for height; recenter sibling repeats width to `+0xb0` and height to `+0xac` | Target page Evidence; `by-type/by-struct/MapPaneLayout.md`; `by-memory/0x005059d0-0x00505bf8.MapPaneRecenterAndSendPosition.md`; `by-class/MapPane.md`; `by-file/MapPane.md`; UID0001AP | Applied/historicalized stale field-order prose | applied |
| C-000427-06 | Existing formal C++ is source-shaped and can remain formal code once field-order support is clarified. | High | MCP behavior matches `DirectionToTileOffset`, divisor, deltas, and shifted invalidation | Target formal `RECONSTRUCTION_CPP CODE` header/block | Exact formal block was already present and preserved through validator `000000006238` | already-present/applied |
| C-000427-07 | Owner/emitter remains `00007Q`; source emits through `NexusTK/map/MapPane.cpp` under file UID0000L3. | High | `thiscall` receiver, MapPane class/file docs, UID0001AP split, generated MapPane.cpp | Target metadata; `by-class/MapPane.md`; `by-file/MapPane.md` | Preserved owner/emitter metadata and support route | applied |
| C-000427-08 | No split, merge, no-code disposition, raw-helper route, or aggregate C++ route is needed. | High | Exact child range, padding proof, direct caller proof, parent aggregate marker policy | Target page Status; UID0001AP aggregate | Preserved exact child disposition and no aggregate-body route | applied |
| C-000427-09 | Score should move to `88/91` after callback because current target-specific MCP evidence and field-order correction close the direct-report gap, while inferred names still cap final confidence. | Medium-high | Current report evidence and score rationale | Target metadata header | Applied `COMPLETION:88`, `CONFIDENCE:91`; validator `000000006238` confirmed completion/confidence updates | applied |
| C-000427-10 | Generated output was read-only during the original research pass and emitted UID000427 in `auto-generated/NexusTK/map/MapPane.cpp` at validator command `000000006160`; callback implementation did not manually edit generated output. | Medium | Read-only generated header/snippet; callback validators | Report Validator Results and callback generated-freshness note | No manual generated edit; scoped validators reported `generated_refresh: deferred` for commands `000000006238`-`000000006244` | applied |

## Positive Evidence Summary

- Exact target `by-memory/0x005055e0-0x00505645.MapPaneApplyMovementSubstepScroll.md` is a modeled function, not padding or a raw no-route helper.
- Current MCP decompile and disassembly match the existing source behavior: direction-to-tile offset, global movement substep scale, tile width/height globals, pixel-origin update, and shifted-area invalidation.
- Direct calls from `sub_5A83B0` at `0x005a8524` and `0x005a8589` place the helper in the user/local-player movement animation path; `0x005a8589` is directly followed by `MapPaneScrollViewportByDirection`.
- Parent and support docs already establish MapPane coordinate/movement helper ownership and source route through `NexusTK/map/MapPane.cpp`.
- Boundary bytes prove clean function end and alignment before successor `0x00505650`.

## Negative Evidence Summary

- UID-only references are unsafe: historical executed B001 report created a different UID000427 page for RankingDialog. This report rejects all such UID-only evidence for the MapPane target.
- No separate child should be created for padding at `0x00505645-0x00505650`; it is pure `0xcc` alignment.
- No ownership belongs to `UserPane` or `LivingObjectPane` just because `sub_5A83B0` calls this helper; those paths consume MapPane movement APIs.
- No ownership belongs to `MapTilePixelDimensions` or `g_movementSubstepScale`; those are dependencies consumed by this method.
- No monolithic UID0001AP aggregate C++ should absorb UID000427, because the exact child already owns the method body.
- Do not preserve the shorthand `+0xac/+0xb0` as ordered X/Y mapping; current MCP proves the physical X/Y order is reversed relative to that shorthand.

## Ranked Ownership Analysis

1. [UID:00007Q][MapPane](../../../../../by-class/MapPane.md), emitted through [UID:0000L3][MapPane](../../../../../by-file/MapPane.md): accepted. The function is `__thiscall`, updates MapPane pixel-origin fields, calls MapPane coordinate/region helpers, and belongs to the accepted UID0001AP MapPane child split.
2. [UID:0000L3][MapPane](../../../../../by-file/MapPane.md) directly: valid source file route but not the canonical child owner, because the function is an instance method and current target metadata already routes through class UID00007Q.
3. [UID:0001AP][0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore](../../../../../by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md): support/index parent only. It should not own a monolithic method body.
4. [UID:0000P1][UserPane](../../../../../by-file/UserPane.md) / `sub_5A83B0` caller family: rejected as owner; it passes the active MapPane pointer and direction into MapPane methods.
5. [UID:0002CF][g_movementSubstepScale](../../../../../by-global/g_movementSubstepScale.md) and [UID:0000T7][MapTilePixelDimensions](../../../../../by-global/MapTilePixelDimensions.md): rejected as owners; they are scalar/global dependencies.
6. No-owner/non-emitting: rejected. The target has a modeled function, direct callers, owner route, and valid formal C++.

## Source Placement

Keep source placement in `NexusTK/map/MapPane.cpp` as:

```cpp
bool MapPane::ApplyMovementSubstepScroll(unsigned char direction)
```

The method should sit with the MapPane coordinate/movement helper cluster near `AllowsMovementStatusTag`, `GetAdjacentVisibleTileBounds`, `ScrollViewportByDirection`, and related UID0001AP child helpers. It should not be moved to a standalone movement-globals file, the UserPane caller, or the UID0001AP aggregate marker.

## First-Draft C++ Recommendation

Keep or insert this exact formal header/block text for `by-memory/0x005055e0-0x00505645.MapPaneApplyMovementSubstepScroll.md`. This is the supervisor-owned insertion text for the target page, not an illustrative snippet:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool MapPane::ApplyMovementSubstepScroll(unsigned char direction)
{
    MapPoint offset;
    DirectionToTileOffset(&offset, direction);

    const int substepDivisor = 4 * g_movementSubstepScale;
    const int deltaX = offset.column * g_mapTilePixelWidth / substepDivisor;
    const int deltaY = offset.row * g_mapTilePixelHeight / substepDivisor;

    m_viewportPixelX += deltaX;
    m_viewportPixelY += deltaY;

    return InvalidateShiftedMapArea(-deltaX, -deltaY);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Implementation note for callback: do not change the source body to raw offsets. Instead, document that `m_viewportPixelX` maps to physical `MapPane+0xb0` and `m_viewportPixelY` maps to physical `MapPane+0xac`, matching this target and UID0002QM recenter evidence. If the project later standardizes on `m_pixelOriginX/m_pixelOriginY` instead of `m_viewportPixelX/m_viewportPixelY`, that should be a broader MapPane field-name cleanup, not a blocker for this exact target.

## Final Recommendation

Implementation callback was applied for exact target `by-memory/0x005055e0-0x00505645.MapPaneApplyMovementSubstepScroll.md`. UID000427 remains source-bearing, now at `88/91`, retains owner/emitter `00007Q`, keeps the formal C++ block, and carries current MCP/session evidence plus the physical field-order correction. Stale/under-specific support docs were synchronized; no manual generated, coverage, lifecycle, archive, validator-state, or supervisor-ledger edits were made.

## Recommended Target Doc Changes

For exact target `by-memory/0x005055e0-0x00505645.MapPaneApplyMovementSubstepScroll.md`:

- Set `COMPLETION:88`, `CONFIDENCE:91`.
- Preserve `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, and blank `EMITTER_POSITION_OPTIONAL`.
- Keep or insert the exact formal `RECONSTRUCTION_CPP CODE` header/block text from this report.
- Add MCP session `60724697` evidence: exact size `0x65` / 101 bytes, prototype `char __thiscall(_DWORD *this, char)`, one-block body, callers `0x005a8524` and `0x005a8589` inside `sub_5A83B0`, callees `0x00505080` and `0x005549d0`, and boundary padding `0x00505645-0x00505650`.
- Replace inherited-only "Accepted 0001AP report records..." prose with current target-specific proof while preserving B009 split history.
- Add field-order text: `0x005055e0` writes width/column delta to `MapPane+0xb0` and height/row delta to `MapPane+0xac`; these are source-facing X/column and Y/row pixel-origin fields respectively. Do not leave ordered shorthand implying `+0xac` is X and `+0xb0` is Y.
- Preserve negative evidence: unrelated historical UID000427 RankingDialog page is not evidence for this target; UserPane caller and scalar globals are consumers/dependencies, not owners; UID0001AP remains an aggregate marker.

## Recommended Support Doc Changes

- `by-type/by-struct/MapPaneLayout.md`: update the `+0xac/+0xb0` row to avoid ordered X/Y ambiguity. Recommended wording: "`+0xb0` is the X/column pixel-origin field and `+0xac` is the Y/row pixel-origin field; older shorthand `+0xac/+0xb0` describes the pair only, not X/Y order."
- `by-memory/0x005059d0-0x00505bf8.MapPaneRecenterAndSendPosition.md`: update the touched-state/reconstruction notes where they currently say `m_pixelOriginX/m_pixelOriginY at +0xac/+0xb0`; current MCP shows width-derived X stored at `+0xb0` and height-derived Y stored at `+0xac`. Keep method behavior and formal body otherwise unchanged unless a broader MapPane field-name cleanup is assigned.
- `by-class/MapPane.md`: if stale/under-specific, add one sentence to the coordinate/movement helper surface noting UID000427 current MCP `60724697` proof and the `+0xb0` X / `+0xac` Y field-order caveat. No class score or class C++ change recommended.
- `by-file/MapPane.md`: if stale/under-specific, add one sentence under coordinate conversion or source-placement notes that UID000427 was rechecked as a source-bearing exact child and does not change `NexusTK/map/MapPane.cpp` ownership. No file score change recommended.
- `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`: if its UID000427 row remains only inherited B009 summary, append current evidence: size `0x65`, callers from `sub_5A83B0`, exact padding, and field-order caveat. No aggregate score or metadata change recommended.
- Do not edit generated `auto-generated/NexusTK/map/MapPane.cpp` manually. Validator-generated refresh after scoped validation is sufficient.

## Score And Metadata Recommendation

| Field | Current | Recommended | Rationale |
| --- | ---: | ---: | --- |
| `COMPLETION` | `86` | `88` | Current report supplies target-specific MCP proof for range, body, callers, callees, padding, source route, and the remaining field-order documentation defect. |
| `CONFIDENCE` | `88` | `91` | Current MCP validates the existing formal C++ behavior and exposes the exact physical field-order correction. Confidence remains below final because original member/helper spellings are inferred. |
| `CANONICAL_OWNER` | `00007Q` | `00007Q` | Correct direct class owner for `__thiscall` MapPane method. |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` | Custom game MapPane movement helper. |
| `EMITTER_UIDS` | `00007Q` | `00007Q` | Exact child emits through MapPane class/file route. |
| Formal C++ | populated | populated | Keep or insert the exact formal header/block text supplied in this report; no no-code proof needed. |

No parent aggregate score movement is recommended. The accepted callback improves coverage/completion by making UID000427 target-specific evidence self-contained and by correcting support docs for field order, not by changing the broader UID0001AP aggregate.

## Open Questions With Attempted Resolution

- Exact original name for `sub_5549D0`: not recovered. Resolution: keep inferred `InvalidateShiftedMapArea` in the formal `RECONSTRUCTION_CPP CODE` block because the call uses `this+4` and negated deltas after pixel-origin updates; this is a confidence cap, not a C++ blocker.
- Exact original field names for `+0xb0` and `+0xac`: not recovered. Resolution: keep existing source-facing names in the formal `RECONSTRUCTION_CPP CODE` block if the project wants stable generated output, but document physical order explicitly as `+0xb0` X/column and `+0xac` Y/row. A broader field-name cleanup can later choose between `m_viewportPixelX/Y` and `m_pixelOriginX/Y`.
- Exact MapPoint type declaration: not fully recovered here. Resolution: current support already uses row/column direction offsets; target code is safe using `offset.column` for width/X and `offset.row` for height/Y.
- Whether UID000427 should split from UID0001AP: resolved no. It already is the exact child; surrounding bytes are padding and successor helper belongs to UID000428.
- Historical UID000427 collision: resolved by exact path/range binding. Unrelated RankingDialog UID000427 material must not be incorporated into this MapPane target.

## Validator Results

Scoped validators were run from `source-3/project-documentation` for every changed by-* doc:

| Command | Command ID | Timestamp | Exit | OK | Warnings / notes | Generated refresh |
| --- | --- | --- | ---: | ---: | --- | --- |
| `python .\tools\validator.py --mode file --file by-memory/0x005055e0-0x00505645.MapPaneApplyMovementSubstepScroll.md --apply --queue-timeout 240` | `000000006238` | `2026-07-04T12:00:37-04:00` | `0` | `1` | `completion_update 88`, `confidence_update 91`, one UID link normalized to `MapTilePixelDimensions`, two reference-index adds, projected stats updated | `deferred` |
| `python .\tools\validator.py --mode file --file by-type/by-struct/MapPaneLayout.md --apply --queue-timeout 240` | `000000006239` | `2026-07-04T12:00:45-04:00` | `0` | `1` | four stats-row updates for UID00042K, projected stats updated | `deferred` |
| `python .\tools\validator.py --mode file --file by-memory/0x005059d0-0x00505bf8.MapPaneRecenterAndSendPosition.md --apply --queue-timeout 240` | `000000006240` | `2026-07-04T12:00:55-04:00` | `0` | `1` | stats incremental noop for UID0002QM, projected stats updated | `deferred` |
| `python .\tools\validator.py --mode file --file by-class/MapPane.md --apply --queue-timeout 240` | `000000006241` | `2026-07-04T12:01:03-04:00` | `0` | `1` | `missing_ref_uid:89` existing MapPane-class warnings, one stats-row update, projected stats updated | `deferred` |
| `python .\tools\validator.py --mode file --file by-file/MapPane.md --apply --queue-timeout 240` | `000000006243` | `2026-07-04T12:01:15-04:00` | `0` | `1` | `missing_ref_uid:100` existing MapPane-file warnings, one reference-index add for UID000427, one stats-row update, projected stats updated | `deferred` |
| `python .\tools\validator.py --mode file --file by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md --apply --queue-timeout 240` | `000000006244` | `2026-07-04T12:01:25-04:00` | `0` | `1` | stats incremental noop for UID0001AP, projected stats updated | `deferred` |

No `execute_report`, lifecycle, archive, dry-run/probe execute, generated manual edit, coverage-report edit, validator-state edit, or supervisor-ledger edit was performed.

## Changed Files

Implementation callback changed:

- `by-memory/0x005055e0-0x00505645.MapPaneApplyMovementSubstepScroll.md`
- `by-type/by-struct/MapPaneLayout.md`
- `by-memory/0x005059d0-0x00505bf8.MapPaneRecenterAndSendPosition.md`
- `by-class/MapPane.md`
- `by-file/MapPane.md`
- `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`
- `tools/leaser/Agents/Agent-B012/research/000427-MapPaneApplyMovementSubstepScroll-source-quality.md`

Validator-owned scoped `--apply` updates also refreshed projected stats in `project-level/-auto-completion-stats.md`. No manual generated files, coverage reports, validator state, lifecycle/archive files, or supervisor ledgers were edited.

## Implementation Tracking Checklist

- [x] Target `by-memory/0x005055e0-0x00505645.MapPaneApplyMovementSubstepScroll.md`: raised to `COMPLETION:88`, `CONFIDENCE:91`; preserved owner/emitter/reconstructable route and blank optional position.
- [x] Target: kept the exact formal `RECONSTRUCTION_CPP CODE` header/block text from this report.
- [x] Target: added MCP session `60724697` range/body/caller/callee/padding evidence at report-level detail.
- [x] Target: replaced inherited-only B009 0001AP evidence wording with current target-specific evidence while preserving split history.
- [x] Target/support: corrected field-order prose so `+0xb0` is X/column pixel origin and `+0xac` is Y/row pixel origin; historicalized the stale ordered shorthand `+0xac/+0xb0` -> X/Y.
- [x] Support `by-type/by-struct/MapPaneLayout.md`: updated the focused offset ledger row for physical order.
- [x] Support `by-memory/0x005059d0-0x00505bf8.MapPaneRecenterAndSendPosition.md`: updated touched-state/reconstruction notes for physical order while preserving formal C++.
- [x] Support `by-class/MapPane.md`, `by-file/MapPane.md`, and `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`: refreshed UID000427 current evidence; no score change applied to these support pages.
- [x] Preserved negative evidence: unrelated RankingDialog UID000427 collision, rejected UserPane/LivingObjectPane/scalar-global ownership, no split/no aggregate body/no padding child.
- [x] Ran scoped validators for every changed by-* doc and recorded command, command_id, command_timestamp, exit code, ok count, warnings, and generated-refresh status.
- [x] Did not manually edit generated files, `-coverage-report.md` files, validator state, lifecycle/archive files, or supervisor ledgers; did not run `execute_report` or lifecycle/probe variants.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B012","command_id":"000000006269","destination_path":"executed-b-agent-research/B012/000427-MapPaneApplyMovementSubstepScroll-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B012/research/000427-MapPaneApplyMovementSubstepScroll-source-quality.md","timestamp":"2026-07-04T12:12:37-04:00","uid":"000427"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
