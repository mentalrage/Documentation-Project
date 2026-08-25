** TARGET-REPORT-UID:0004H7 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0004H7 GrafPortScrollPixelBuffer Source-Quality Research


## Finalized Report / Current Recommendation

- Applied callback result: [UID:0004H7] is now source-ready `GrafPort::ScrollPixelBuffer(const RectBounds *scrollRect, int deltaX, int deltaY, Region *dirtyRegion)` at `92/94` rather than B010's deliberately blank exact child.
- Final disposition applied: exact range `0x004b9a70-0x004ba24a`, [UID:00005V] GrafPort owner, `RECONSTRUCTABLE:TRUE`, and `Nested:0` are retained; `EMITTER_UIDS:00005V` is set; optional position remains blank; and generated address order places the complete body after UID000166 and before UID000167.
- The previous helper/type blockers are closed. `sub_516030` is `GetMemoryMan`, `sub_516240` is `MemoryMan::MoveBufferMemory`, `sub_554700` is the Region-compatible `SetEmpty`, `sub_554800` is `UnionWithRect`, and `a5` is the caller-constructed `Region *dirtyRegion` boundary.
- The method is source-authored and returns `void`. Hex-Rays' `char` is incidental `AL` residue from void-documented helper calls; all three direct callers ignore it.
- No split, child, data, vtable, callback, duplicate-body, or internal-padding page is required. The 2,010-byte body is one 77-block function; only the 13-byte predecessor gap and six-byte successor gap are alignment padding outside the target.
- Report state: the supervisor-accepted implementation callback is complete across exactly seven by-* destinations. Scoped validators and the final waited generated refresh passed, generated proof is recorded below, every B001 lease is released, and no accepted claim remains blocked or unapplied. B001 did not manually edit generated/tracker/coverage/supervisor/validator/IDA files and performed no report execute, lifecycle, move, or archive command.

## Supporting Research

- Mandatory live research evidence used NexusTK IDB database `supervisor_nexustk_20260713`. At evidence time `2026-07-13T12:45:07-04:00`, fresh streamable-MCP client call `11` returned exactly one adopted worker, PID `2236`, `is_analyzing:false`; call `12` returned `status:ok`, image base `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready. This is evidence-time health, not an indefinite current-session assertion.
- Bounded live calls remained responsive through the final evidence window: function lookup `13`, valid byte read `41`, target decompile `61`, xref/callee/CFG calls `71/72/74`, exact-signature search `91`, caller decompiles `101-103`, helper lookup/decompiles `111-118`, and caller Region-lifetime rechecks `121-123`.
- Active roots searched for `TARGET-REPORT-UID:0004H7`, `UID:0004H7`, `0x004b9a70`, `sub_4B9A70`, `GrafPortScrollPixelBuffer`, and `ScrollPixelBuffer`: `tools/leaser/Agents/Agent-B001` through `Agent-B005`, including each `goal.md` and `research/` directory. The only active match was this assignment in `Agent-B001/goal.md`; B002-B005 had no target report or goal match.
- Executed root searched with the same terms: `executed-b-agent-research/`. Exact matching reports opened and classified:
  - `executed-b-agent-research/B010/000165-SurfacePaintHelpers-source-quality.md`, SHA256 `EC8DC4E7E24DDF34391AE35140766D4EEEAECF6D69FF24E38D285FDDE32C9106`: direct child-creation provenance and family-level support. It intentionally left UID0004H7 blank because helpers, `a5`, return type, and complete body were unresolved; it is not completed direct target coverage.
  - `executed-b-agent-research/B009/0001BI-Memmove0Wrapper-source-quality.md`, SHA256 `45F8316C83B46A3A3590EC76D5DBF8E2688758B7A96E07F11EC28082AD5E9A0D`: direct callee/callsite support. It records all four target calls to `MemoryMan::MoveBufferMemory` and the `GetMemoryMan()` receiver protocol.
  - `executed-b-agent-research/B007/0001BC-GetMemoryMan-source-quality.md`, SHA256 `C1748AA02C5C2F2AA79B609E31D085F5647F3F6811B31BD2793CFADAAC5A3858`: direct singleton-accessor dependency support only.
  - `executed-b-agent-research/B014/0001FW-RegionAndMotionRect-source-quality.md`, SHA256 `1609D20BCD1C1A5CFA26DF630D5F2802C9D44323923E5C5BEED5E2B0DDC1E6AB`: direct `Region` construction and Region/Motion-compatible `SetEmpty` / `UnionWithRect` protocol support only.
  - `executed-b-agent-research/B015/00015S-RectGeometryHelpers-source-quality.md`, SHA256 `310764EA6AFE1D7E78B3E04CB563589F43FC43052C53A0E6DA856CDE4092A804`: direct `RectBounds`, initialization, intersection, and empty-test dependency support only.
  - `executed-b-agent-research/B006/000166-ForwardToTileFrameBlitHelper-source-quality.md`: predecessor boundary and 13-byte padding support only.
  - `executed-b-agent-research/B003/000167-SurfaceSpriteBlitHelper-source-quality.md`: successor boundary and six-byte padding support only.
  - Remaining matches in Overlay/AboveFrame/Chatting/FlyingParcel/CompositePixels/Surface raw-helper reports mention UID000165 or its range only as an adjacent render dependency; none analyzes UID0004H7.
- Archive roots checked: `executed-b-agent-research/invalidated/`, `tools/leaser/Agents/Older-Research/`, and `tools/leaser/Agents/SpecialReports/`; none contained a UID0004H7 or exact-target report match.
- Historical non-B report opened: `by-memory/-report.old.md`, lines around the `0x004B9A70` entry. It directly identifies scrolling, 16-bit moves, exposed-strip clearing, three callers, and `Region *`, but its Wave2 `FolderTreePane` owner and `bool` return are stale caller-biased conclusions rejected by current receiver and caller evidence.
- Explicit search conclusion: no active, executed, invalidated, legacy-archive, or special report has `TARGET-REPORT-UID:0004H7`. B010 created the page as incomplete family work; this artifact is the first dedicated direct target reanalysis.
- Read-only generated baseline: `auto-generated/NexusTK/render/GrafPort.cpp`, validator command `000000009875`, refreshed `2026-07-13T12:30:47-04:00`, emits UID0004H6, UID000166, then UID000167. UID0004H7 is absent because its emitter and formal block are blank. That absence is historical pre-callback state, not a continued no-code recommendation.

## Target

- Target UID: `0004H7`.
- Target path: `by-memory/0x004b9a70-0x004ba24a.GrafPortScrollPixelBuffer.md`.
- Pre-edit target SHA256: `5A1FCBDBC63154005D0E889E241004CA152DE547088DBEE99041F13C58C74F1B`.
- Source queue/report row at assignment time: validator-refreshed `auto-generated/-ag-research-tracker.md`, `## by-memory` -> `### Not-Covered Files - Reconstructable`, `86/90`, reports `0`.
- Historical assignment classification: dedicated report-only Rule 26/source-quality reanalysis before Gate 1; the same-report implementation callback was subsequently authorized and completed.
- Current parent state: exact source-ready child of non-emitting split index [UID:000165] `0x004b9820-0x004ba24a.SurfacePaintHelpers`; that parent is now `89/92` and remains non-reconstructable/non-emitting.

## Current Target State

- Applied metadata: `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:00005V`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00005V`, blank optional position, complete formal C++, `Nested:0`.
- The target summary and prose now record the exact range/padding, resolved signature and helper identities, receiver layout, all three callers, four directional quadrants, edge cases, negative evidence, source placement, and score rationale.
- B010's 2026-07-04 no-code state and Wave2's FolderTreePane/`bool` conclusions remain as explicitly superseded historical provenance. The current target no longer presents those facts as blockers.
- UID000165, [UID:00005V] GrafPort, and [UID:0000JR] GrafPort now mark UID0004H7 source-ready. UID00037Y MapPane, UID0001GL ScrollablePane, and UID0001FW Region/Motion carry the accepted caller/type support without unrelated metadata or formal-C++ changes.
- Current report path/count/validation/execution/movement/archive state is external supervisor/validator-owned and is not asserted or directed by this artifact. B001's callback work and no-lifecycle boundary are complete.

## Executive Recommendation

- Applied direct semantic owner/emitter is [UID:00005V] GrafPort, with source file [UID:0000JR] `NexusTK/render/GrafPort.cpp`.
- One nonvirtual source method emits from the exact target page under the stable descriptive name `ScrollPixelBuffer`; `ScrollPixels` remains a rejected lower-probability alias.
- The applied signature returns `void` and takes `const RectBounds *scrollRect`, signed `int deltaX`, signed `int deltaY`, and `Region *dirtyRegion`.
- The emitted body preserves all four direction quadrants, overlap-safe row order, 16-bit pixel addressing, caller clip intersection, dirty accumulator clear/union sequence, zero-delta self-moves, oversized-delta clamping behavior, and the directly observed `deltaX > 0 && deltaY <= 0` four-bytes-per-pixel lower-strip clear anomaly.
- No implementation condition remains. Exact original private identifier spelling is not recoverable from stripped symbols, but that lexical confidence cap does not block the applied source body.

## Supervisor Active Recheck

- The historical supervisor instruction reopened UID0004H7 as a dedicated report-only target and forbade merely repeating B010's unresolved family-level no-code proof; Gate 1 then accepted exact report SHA `575A030BF6D42F38BECD82B420E920E2CF6D9E17EEAB2949DF9D560695BE022E` for this callback.
- The assignment does not require split repair. The exact function already has its own child page and coherent one-function range.
- Every source-bearing operation in scope is represented in the single complete target block. No internal source child, compiler child, data child, or ignored span inside the target is missing.
- Mandatory MCP remained available for valid research calls. No process start, stop, restart, kill, or MCP management action was performed, and the callback introduced no new binary uncertainty requiring additional IDA mutation or evidence.

## Inference Research Guidance Check

- `by-structure.md` and the workflow require receiver state, callers, source placement, and helper contracts to outweigh caller-biased generated names. That rule keeps GrafPort ownership even though one caller is ScrollablePane and two are MapPane methods.
- Existing documentation assumptions treated as uncertain were the blank-C++ disposition, exact signature, apparent `char` return, `a5` type, helper names, target use of `+0x44/+0x48`, and the Wave2 FolderTreePane owner.
- Direct IDA fact is used for ranges, bytes, CFG, stack cleanup, callsites, field offsets, branch arithmetic, row direction, clear sizes, and xrefs. Current by-* documentation supplies accepted source names/types. Inference is limited to source-facing method/local spelling and `void` source intent from caller/helper contracts.
- Wave2 material was found in `by-memory/-report.old.md`. Its behavior leads were rechecked, but its owner and return were ignored as stale where contradicted by current evidence. No Wave3 artifact was used as source authority.

## Heuristic / Inference Reanalysis And Validation

| Issue | Resolution | Evidence class |
| --- | --- | --- |
| Raw target name `sub_4B9A70` | Use project-stable `GrafPort::ScrollPixelBuffer`; it describes the complete active-buffer operation and is already established in current GrafPort docs. `ScrollPixels` is plausible but less stable. | descriptive/inferred spelling over direct behavior |
| Historical `FolderTreePane` owner | Reject. ECX is a GrafPort receiver in all callers; two calls use embedded `MapPane::m_viewportGrafPort` at `+0x428`, and the third uses the leading inherited GrafPort base of ScrollablePane. | direct caller/field fact |
| Hex-Rays `char` return | Use `void`. The epilogue is `retn 0x10`, but `AL` only carries residue from source-void `SetEmpty`, `IsRectEmptyOrInvalid`, or `UnionWithRect` paths; no caller tests or stores it. | direct ABI/caller fact plus documented helper contracts |
| `a2` `__int128 *` | Use `const RectBounds *scrollRect`; the target copies exactly four ordered dwords and all rectangle helpers use the accepted left/top/right/bottom layout. | direct layout/callee fact |
| `a3` / `a4` | Use signed `int deltaX` / `int deltaY`. Branches test positive versus non-positive, negative values select opposite source offsets, and ScrollablePane passes Point x then y. | direct branch/caller fact |
| `a5` `char *` | Use `Region *dirtyRegion`. Each caller constructs a local through `Region::Region` at `0x00554680`, passes its address, later destroys it, and the target uses the `+0x04` Region/Motion bounds layout through `SetEmpty` and `UnionWithRect`. | direct lifetime/layout fact plus accepted Region boundary convention |
| `sub_516030` | `GetMemoryMan()`. Exact six-byte global accessor; target preserves its result and reloads it as the receiver for every `MoveBufferMemory` call. | direct callee and accepted UID0001BC name |
| `sub_516240` | `MemoryMan::MoveBufferMemory(void *, const void *, size_t)`. It forwards to `memmove`, and overlap-safe row order plus `GetMemoryMan` receiver protocol are directly visible. | direct callee and accepted UID0001BI contract |
| `sub_554700` | Region-compatible `SetEmpty()`. It initializes receiver `m_bounds` at `+0x04` to four zeros. | direct callee plus UID0001FW |
| `sub_554800` | Region-compatible `UnionWithRect(const RectBounds *)`. It calls `UnionRects(input, this+4, this+4)`. | direct callee plus UID0001FW |
| `sub_4B7C50` | `InitRectBounds`. It writes left/top/right/bottom in four dwords. | direct body plus UID00015S |
| `sub_4B7CC0` | `IntersectRects`. Target uses in-place output and then tests the result rectangle. | direct body plus UID00015S |
| `sub_4B7EB0` | `IsRectEmptyOrInvalid`. It tests bottom <= top or right <= left. | direct body plus UID00015S |
| `sub_4B96C0` | `GrafPort::GetClipRect(RectBounds *)`. It is the accepted preceding GrafPort child UID000164. | direct callee plus current target page |
| Pixel pointer/stride/bounds | `m_surfaceContext.pixelData` at `+0x20`, signed `int rowStridePixels` at `+0x28`, bounds left/top at `+0x2c/+0x30`; two-byte scaling makes the active element type `unsigned short`. | direct operand arithmetic plus GrafPort layout docs |
| Draw guard | `m_drawEnabled` at `+0x71`; dirty output is cleared before this guard, so disabled drawing returns an empty region. | direct byte read/order |
| Point convention in ScrollablePane caller | Project `Point` stores y then x; virtual slot `+0x5c` returns the scroll delta, caller passes its second dword as `deltaX` and first dword as `deltaY`. | direct caller plus accepted UID0001GL contract |
| MapPane direction scaling | Direction pair component 1 multiplies `g_mapTilePixelWidth`; component 0 multiplies `g_mapTilePixelHeight`, then the resulting x/y pixel deltas are passed to this target. | direct callers plus UID0000T7 |
| Branch-specific four-byte clear | Preserve exactly. At `0x004b9e26`, the lower-strip branch computes `4 * clippedWidth` bytes per row and clamps row count against width, unlike all other two-byte pixel clears. Normalizing it would change observable writes. | direct decompile/disassembly arithmetic |
| Security cookie | Compiler-generated stack protection only; omit from source. | compiler pattern/epilogue fact |
| Local labels | Use `clippedRect`, `clipRect`, `dirtyRect`, `pixels`, `sourcePixels`, `destinationPixels`, `rectWidth`, `rectHeight`, `copyWidth`, `copyRows`, `clearWidth`, `clearRows`, `clearX`, `clearY`, and `row`; no `vNN`, `SrcX`, or `LABEL_83` survives. | descriptive source reconstruction |

Rejected alternatives:

- `bool`/`char` return is rejected because no caller consumes it and source-void helper residues explain `AL` on every exit.
- `Motion *dirtyRegion` is lower probability at this public call boundary. Current accepted project code uses `Region *` for constructed dirty accumulators while allowing Motion-named compatible methods.
- `Surface::ScrollPixelBuffer`, free helper, MapPane method, ScrollablePane method, and FolderTreePane method are rejected because receiver state is GrafPort and callers are heterogeneous consumers.
- A polished generic rectangle-copy algorithm is rejected if it removes zero-delta self-moves, oversized-delta behavior, invalid unions, or the four-byte lower-strip clear anomaly.
- Blank formal C++, comment-only formal C++, or continued empty-emitter treatment is rejected because all previously named blockers now have direct or accepted support evidence.

## Evidence Standards Used

- Highest rung: live MCP bytes, modeled function ranges, full Hex-Rays body, 77-block CFG, caller decompiles, xrefs, and helper bodies.
- Corroboration rung: current source-quality by-* pages and already executed direct helper reports with accepted source names/types.
- Historical lead rung: B010 and Wave2 prose, accepted only where current evidence independently confirms it.
- Inference is limited to human spellings and source expression, never range, branch condition, clear size, field offset, argument count, or ownership.
- Evidence is strong enough for source C++ because every raw label in the target has a resolved behavior/type, every inbound route is inventoried, and the final body preserves direct branch anomalies instead of idealizing them.

## Evidence Checked

- Live MCP: `idb_list`, `server_health`, `lookup_funcs`, valid `get_bytes`, `decompile`, `xrefs_to`, `callees`, `basic_blocks`, and `find_bytes`; target, three callers, all named callees, predecessor/successor, and caller Region lifetimes were checked.
- Project `tools/int_convert.py 0x7da` independently returned decimal `2010`, matching the modeled target size used throughout this report.
- Raw boundaries: `0x004b9a60-0x004b9a80` and `0x004ba240-0x004ba260`; exact target prologue bytes; exact `retn 0x10`; predecessor/successor `0xcc` padding.
- Current docs: target, UID000165, GrafPort class/file/layout, UID000164, UID0001BC, UID0001BI, UID00015S, UID0001FW, Region class, UID00037Y MapPane aggregate, UID0001GL ScrollablePane aggregate, UID0000T7 MapTilePixelDimensions, and generated GrafPort.cpp.
- Historical reports and old report results are path-classified under Supporting Research; no historical conclusion was copied without current recheck.
- Negative checks: no data xref to target, no vtable/pointer/callback route, no fourth caller, no internal function/data split, no exact full-prologue duplicate, no target allocation/free/throw/EH cleanup, no callback dispatch, no null check, and no target read of GrafPort `+0x44/+0x48`.
- Client limitations recorded honestly: one initial PowerShell request omitted `-UseBasicParsing`; subsequent client-local calls `2-6`, `14-15`, and `21-22` had malformed empty arguments or wrong `get_bytes` field names. They failed before yielding valid IDB evidence, did not indicate worker loss, and were corrected by `tools/list` schema inspection followed by successful valid call `41`. No valid bounded IDB-backed call failed.
- Historical report-only boundary: IDA rename/type/comment mutation, by-* edits, leases, validators, generated refresh, and lifecycle commands were intentionally skipped before Gate 1. The later authorized callback performed only the documented by-* leases/validators and generated refresh; IDA mutation and report lifecycle commands remained untouched.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C4H7-001 | Exact function is `0x004b9a70-0x004ba24a`, size `0x7da` / 2,010 bytes, 735 instructions. | very high | MCP lookup/decompile/disasm | target Status/Evidence | incorporate | applied |
| C4H7-002 | Predecessor padding is `0x004b9a63-0x004b9a70`; successor padding is `0x004ba24a-0x004ba250`. | very high | MCP bytes and adjacent functions | target Range section; UID000165 row | incorporate | applied |
| C4H7-003 | Target is one 77-block, cyclomatic-38 function with four direction quadrants and no internal split/data. | very high | MCP CFG/analyze | target CFG/range sections | incorporate | applied |
| C4H7-004 | Exactly three direct code xrefs exist at `0x0050bea3`, `0x0050da81`, and `0x0055eba6`. | very high | MCP xrefs | target callers; caller support docs | incorporate | applied |
| C4H7-005 | No data, vtable, pointer-table, callback, or duplicate entry route exists. | high | xrefs/signature/structure negative checks | target Negative Evidence | incorporate | applied |
| C4H7-006 | Canonical owner remains UID00005V GrafPort. | very high | receiver fields and heterogeneous callers | target metadata; class support | already-present | already-present |
| C4H7-007 | Source placement is UID0000JR `NexusTK/render/GrafPort.cpp`. | very high | class/file neighborhood | target prose; file support | already-present | already-present |
| C4H7-008 | Best source name is `GrafPort::ScrollPixelBuffer`; raw and FolderTreePane names are rejected. | high | stable docs plus exact behavior | target title/status/formal block | incorporate | applied |
| C4H7-009 | Source return is `void`, not Hex-Rays `char` or historical `bool`. | very high | all callers ignore AL; helper contracts | target signature/formal block | incorporate | applied |
| C4H7-010 | First argument is `const RectBounds *scrollRect`. | very high | four-dword copy and geometry helpers | target signature/formal block | incorporate | applied |
| C4H7-011 | Second/third arguments are signed `int deltaX`, `int deltaY`; Point/map callers establish order. | very high | branch arithmetic and caller order | target signature/caller evidence | incorporate | applied |
| C4H7-012 | Fourth argument is `Region *dirtyRegion`, cleared first and unioned with exposed strips. | very high | caller construction/destruction and +4 layout | target signature/behavior; Region support | incorporate | applied |
| C4H7-013 | `sub_516030` is `GetMemoryMan`; result is live as copy-helper receiver. | very high | direct helper body and four call sequences | target helper evidence | incorporate | applied |
| C4H7-014 | `sub_516240` is `MemoryMan::MoveBufferMemory` over `memmove`. | very high | direct helper body/accepted UID0001BI | target helper evidence | incorporate | applied |
| C4H7-015 | `sub_554700` is Region-compatible `SetEmpty`. | very high | direct body/UID0001FW | target helper evidence | incorporate | applied |
| C4H7-016 | `sub_554800` is Region-compatible `UnionWithRect`. | very high | direct body/UID0001FW | target helper evidence | incorporate | applied |
| C4H7-017 | `sub_4B7C50`, `sub_4B7CC0`, `sub_4B7EB0` map to Init/Intersect/empty-test helpers. | very high | direct bodies/UID00015S | target helper evidence | incorporate | applied |
| C4H7-018 | `sub_4B96C0` is `GrafPort::GetClipRect`. | very high | UID000164 and direct target call | target behavior | incorporate | applied |
| C4H7-019 | Pixel state is `pixelData +0x20`, `rowStridePixels +0x28`, bounds left/top `+0x2c/+0x30`, 16-bit elements. | very high | scaled field arithmetic/current layout | target layout/formal block | incorporate | applied |
| C4H7-020 | `m_drawEnabled +0x71` is checked after dirty output is cleared. | very high | entry instruction order | target behavior/formal block | incorporate | applied |
| C4H7-021 | Requested bounds are copied, clipped through GetClipRect/IntersectRects, and empty-clipped requests return empty dirty output. | very high | direct entry CFG | target behavior/formal block | incorporate | applied |
| C4H7-022 | Positive-X/positive-Y copies bottom-up, clears top then left, and unions both exposed strips. | very high | direct quadrant body | target behavior/formal block | incorporate | applied |
| C4H7-023 | Positive-X/nonpositive-Y copies top-down, clears left then lower strip, and unions both strips. | very high | direct quadrant body | target behavior/formal block | incorporate | applied |
| C4H7-024 | The latter quadrant clamps lower-strip rows against width and clears `4 * width` bytes per row; preserve as historical binary behavior. | very high | `0x004b9dF0-0x004b9e5b` | target edge cases/formal block | incorporate | applied |
| C4H7-025 | Nonpositive-X/positive-Y copies bottom-up, clears top then right, and unions both strips. | very high | direct quadrant body | target behavior/formal block | incorporate | applied |
| C4H7-026 | Nonpositive-X/nonpositive-Y copies top-down, clears right then bottom, and unions both strips. | very high | direct quadrant body | target behavior/formal block | incorporate | applied |
| C4H7-027 | Zero deltas follow the nonpositive branches, perform full self-moves, and generate only degenerate unions; do not optimize away. | high | direct conditions/arithmetic | target edge cases/formal block | incorporate | applied |
| C4H7-028 | Oversized deltas skip nonpositive copy dimensions, clamp clear widths/rows as observed, and may submit invalid/degenerate rectangles ignored by union logic. | high | direct guards/clamps/helper behavior | target edge cases/formal block | incorporate | applied |
| C4H7-029 | Target has no null checks, allocation, free, throw, EH cleanup, UpdateSurfaceInfo, or EndPaint; callers own paint and Region lifetime. | very high | complete callee/CFG/caller review | target negative/caller contract | incorporate | applied |
| C4H7-030 | Set target to `92/94`, emitter UID00005V, blank optional position; retain owner/reconstructable/Nested. | high | blocker closure and source readiness | target metadata | incorporate | applied |
| C4H7-031 | Replace blank target formal C++ with the one complete managed block in this report. | high | complete reconstructed body | target formal C++ | incorporate | applied |
| C4H7-032 | Replace historical no-code/current-summary wording while preserving B010 provenance as superseded history. | very high | current versus reanalysis | target prose/history | historicalize | applied |
| C4H7-033 | GrafPort class should describe the resolved signature/body and remove current pending-helper wording; keep score/formal class block unchanged. | high | current class contradiction | by-class/GrafPort.md | incorporate | applied |
| C4H7-034 | GrafPort file should mark UID0004H7 source-ready and update B010 historical wording; keep `89/88`. | high | current file contradiction/source order | by-file/GrafPort.md | incorporate | applied |
| C4H7-035 | UID000165 should mark UID0004H7 source-ready; raise split-index score `88/91 -> 89/92`, keep parent non-emitting. | high | final child blocker closed | UID000165 parent | incorporate | applied |
| C4H7-036 | UID00037Y should record both MapPane callers, embedded GrafPort `+0x428`, tile-pixel deltas, local Region, and ignored target return; no score/C++ change. | high | caller decompiles | MapPane aggregate | incorporate | applied |
| C4H7-037 | UID0001GL should record ApplyScrollPosition's exact call, Point y/x order, Region lifetime, and external paint lifecycle; no score/C++ change. | high | caller decompile/current slot contract | ScrollablePane aggregate | incorporate | applied |
| C4H7-038 | UID0001FW should add UID0004H7 as a concrete `Region *` consumer of Motion-named SetEmpty/UnionWithRect compatibility; no score/C++ change. | high | target/caller/helper chain | RegionAndMotionRect | incorporate | applied |
| C4H7-039 | UID0001BC, UID0001BI, UID00015S, UID000164, Region class, and UID0000T7 already contain the necessary helper/type facts; no edit is needed. | very high | current pages opened | listed support pages | already-present | already-present |
| C4H7-040 | Callback validation must refresh GrafPort.cpp and prove one UID/body in address order, no empty marker, and no aggregate duplicate. | high | generated baseline/emitter rules | validator/generated verification | incorporate | applied |

### Callback Verification Notes

| Claim ID | Detailed callback proof |
| --- | --- |
| C4H7-001 | UID0004H7 Status/Evidence now records the exact half-open range, `0x7da`/2,010-byte size, and 735-instruction body; target validator `000000009923` returned exit 0 and `ok:1`. |
| C4H7-002 | Target Status records both external padding spans, and UID000165's source-ready row records the same predecessor/successor boundaries; no ignored-page or range edit was required. |
| C4H7-003 | Target evidence records one 77-block source function, four directional quadrants, and explicit rejection of internal code/data/split children. |
| C4H7-004 | Target Callers records all three addresses; UID00037Y records `0x0050bea3`/`0x0050da81`, and UID0001GL records `0x0055eba6`. |
| C4H7-005 | Target Negative Evidence preserves the no-data/vtable/table/callback/alternate-entry findings; generated scan also found one target UID and one signature globally. |
| C4H7-006 | Owner UID00005V was already present and remains unchanged on the target; validator `000000009923` registered the new emitter edge without changing owner. |
| C4H7-007 | UID0000JR and the target already established `NexusTK/render/GrafPort.cpp`; callback preserved that path and generated refresh emitted there. |
| C4H7-008 | Target status/formal definition use `GrafPort::ScrollPixelBuffer`; historical FolderTreePane/raw alternatives are explicitly rejected in target/class/file history. |
| C4H7-009 | The applied managed block returns `void`; target and all caller support record ignored return use and historicalize `char`/`bool`. |
| C4H7-010 | The exact managed signature uses borrowed `const RectBounds *scrollRect`, and target signature/caller prose records the four-dword rectangle contract. |
| C4H7-011 | The managed signature uses signed `int deltaX`/`deltaY`; MapPane scaling and ScrollablePane Point y/x ordering are recorded at callsite detail. |
| C4H7-012 | The managed signature uses `Region *dirtyRegion`; target, UID00037Y, UID0001GL, and UID0001FW record construction, clear/union use, consumption, destruction, and no transfer. |
| C4H7-013 | Target helper mapping names `GetMemoryMan`, and the formal body uses its result as the receiver of every copy operation. |
| C4H7-014 | Target helper mapping names `MemoryMan::MoveBufferMemory`; generated target contains exactly four calls and the managed body matches exactly. |
| C4H7-015 | Target and UID0001FW record Region-compatible `SetEmpty`; generated target contains exactly one `dirtyRegion->SetEmpty()` call before draw gating. |
| C4H7-016 | Target and UID0001FW record Region-compatible `UnionWithRect`; generated target contains exactly eight dirty-strip union calls. |
| C4H7-017 | Target helper section and formal body use `InitRectBounds`, `IntersectRects`, and `IsRectEmptyOrInvalid`; UID00015S remained unchanged as accepted support. |
| C4H7-018 | Target helper section and formal body call accepted UID000164 `GrafPort::GetClipRect`; validator inserted the formal UID link. |
| C4H7-019 | Target receiver-layout section and class/file support record pixel data `+0x20`, pixel stride `+0x28`, bounds `+0x2c/+0x30`, and unsigned 16-bit element arithmetic. |
| C4H7-020 | Target behavior and exact managed body clear the Region before testing `m_drawEnabled`; no extra guard was introduced. |
| C4H7-021 | Target behavior and managed entry copy/clip the requested bounds, reject empty/invalid intersection, and leave the already-cleared dirty output. |
| C4H7-022 | The first managed quadrant retains bottom-up copy, top clear, left clear, and two exact unions; target prose mirrors it. |
| C4H7-023 | The second managed quadrant retains top-down copy, left clear, lower clear, and two exact unions; target prose mirrors it. |
| C4H7-024 | The second quadrant retains the width-based `clearRows` clamp and `memset(..., 4 * rectWidth)`; generated count is exactly one. |
| C4H7-025 | The third managed quadrant retains bottom-up copy, top clear, right clear, and two exact unions; target prose mirrors it. |
| C4H7-026 | The fourth managed quadrant retains top-down copy, right clear, bottom clear, and two exact unions; target prose mirrors it. |
| C4H7-027 | No zero-delta fast path was added; the exact nonpositive branches/self-move behavior remains in the managed and generated body. |
| C4H7-028 | Exact positive-dimension gates, width/row clamps, and unnormalized union endpoints remain in every managed branch. |
| C4H7-029 | Target negative evidence and caller support keep paint lifecycle/Region ownership outside the target; no null/allocation/free/throw/EH/paint call appears in the managed body. |
| C4H7-030 | Target is `92/94`, owner/reconstructable/Nested are retained, emitter is UID00005V, and optional position remains blank; validator `000000009923` recorded all changed metadata. |
| C4H7-031 | The report's one destination-specific managed block was copied exactly to UID0004H7; post-generation normalized comparison returned `managed_body_exact_match=True`. |
| C4H7-032 | Target Changes and Rejected Alternatives retain the B010/Wave2 facts as explicitly historical/superseded rather than current blockers. |
| C4H7-033 | UID00005V class narrative and Method Notes now carry the resolved signature/body/callers/anomaly; `88/90` and blank class block are unchanged; validator `000000009929` returned `ok:1`. |
| C4H7-034 | UID0000JR inventory/ownership/history now marks UID0004H7 source-ready and places it between UID000166/UID000167; `89/88` remains; validator `000000009932` returned `ok:1`. |
| C4H7-035 | UID000165 is `89/92`, remains UID0000OC-owned/non-reconstructable/non-emitting with blank formal block, and only the target row/history changed; validator `000000009927` returned `ok:1`. |
| C4H7-036 | UID00037Y records both callsites, embedded GrafPort `+0x428`, width/height scaling, local Region, ignored return, and no transfer; aggregate metadata/C++ stayed unchanged; validator `000000009936` returned `ok:1`. |
| C4H7-037 | UID0001GL records `0x0055eba6`, Point ordering, visible bounds, local Region, caller-owned UpdateSurfaceInfo/EndPaint/invalidation, ignored return, and no transfer; validator `000000009938` returned `ok:1`. |
| C4H7-038 | UID0001FW records UID0004H7's `Region *` boundary and Motion-named helper compatibility without score/formal/layout changes; validator `000000009939` returned `ok:1`. |
| C4H7-039 | UID0001BC, UID0001BI, UID00015S, UID000164, Region class, and UID0000T7 remained unedited; their accepted facts are referenced rather than duplicated. |
| C4H7-040 | Waited validator `000000009942` completed generated refresh; GrafPort.cpp has one UID/signature, exact managed body, 4 moves, 12 loops, 1 anomalous clear, order lines `257 < 282 < 574`, no target empty marker, and no wrong-owner duplicate. |

## Positive Evidence Summary

- Exact modeled function, exact stack cleanup, complete decompile, all 77 blocks, and three caller decompiles agree on a four-argument GrafPort method.
- Every target callee now has a current accepted source-facing contract. The former `a5` ambiguity is closed by matching constructor, +4 bounds layout, helper calls, and destructor in all callers.
- Four MoveBufferMemory calls correspond one-for-one to the four direction quadrants; loop direction is overlap-safe for each vertical sign.
- All address math scales by two and indexes from surface bounds and row stride, proving 16-bit active pixel storage.
- Current class/file neighborhood places the function between emitted GrafPort methods UID000166 and UID000167. No Surface/caller-owned state is required.
- Strongest inference chain: heterogeneous callers pass GrafPort receivers plus Region outputs; target touches only GrafPort state and shared geometry/memory/Region helpers; therefore GrafPort method ownership, Region output type, and GrafPort.cpp placement are coherent together.

## IDA MCP Facts

- Function/range: `sub_4B9A70`, size `0x7da`, start `0x004b9a70`, exclusive end `0x004ba24a`, 735 instructions, 77 blocks.
- ABI: prologue saves ECX receiver; four stack arguments; epilogue `retn 0x10`; security cookie is compiler glue.
- Padding: 13 `0xcc` bytes from predecessor end `0x004b9a63` to target; six `0xcc` bytes from target end to successor `0x004ba250`.
- Xrefs: exactly three code refs and zero data refs.
- Callees: `0x00516030`, `0x00554700`, `0x004b96c0`, `0x004b7cc0`, `0x004b7eb0`, `0x00516240`, `_memset`, `0x004b7c50`, `0x00554800`, and security-cookie support.
- Unique-body check: an exact 48-byte prologue/local-save sequence returned only `0x004b9a70`; a shorter wildcard cookie sequence was nonunique and was not used as duplicate proof.
- Negative IDA facts: no embedded function entry, data table, switch table, EH handler, vtable slot, callback table, or target-address pointer was found.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004b9a70-0x004ba24a` | UID0004H7 target | one source-authored GrafPort scroll/copy/clear method | true | UID00005V | current `86/90`; proposed `92/94` | emit complete body |
| `0x004b9a63-0x004b9a70` | existing ignored coverage | predecessor alignment | not source | UID000165 neighborhood | n/a | unchanged |
| `0x004ba24a-0x004ba250` | existing ignored coverage | successor alignment | not source | UID000165 neighborhood | n/a | unchanged |
| `0x00516030` | UID0001BC | GetMemoryMan dependency | true | MemoryMan file | `90/92` | already source-ready |
| `0x00516240` | UID0001BI | MoveBufferMemory dependency | true | MemoryMan class | `91/90` | already source-ready |
| `0x00554700`, `0x00554800` | UID0001FW | Region/Motion SetEmpty and UnionWithRect | true | Region file | `90/91` | already source-ready |
| `0x004b7c50`, `0x004b7cc0`, `0x004b7eb0` | UID00015S | rectangle primitives | true | RectGeometry file | `90/91` | already source-ready |
| `0x004b96c0` | UID000164 | GrafPort GetClipRect | true | UID00005V | `89/91` | already source-ready |

No new child page is recommended. The target itself is the exact source body.

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0050bea3` | caller `sub_50BCE0`, UID00037Y | MapPane scroll/tile refresh constructs Region, updates embedded GrafPort at `this+0x428`, computes tile-pixel x/y deltas, gets its bounds, calls target, later destroys Region. |
| `0x0050da81` | caller `sub_50D9F0`, UID00037Y | second MapPane directional refresh path with the same embedded GrafPort/Region protocol. |
| `0x0055eba6` | caller `sub_55EAE0`, UID0001GL | `ScrollablePane::ApplyScrollPosition`: obtains Point delta through slot `+0x5c`, updates motion, opens leading inherited GrafPort, calls target with visible bounds `this+0x44`, ends paint, invalidates using Region. |
| `0x00516030` | callee `GetMemoryMan` | supplies receiver used for all four MoveBufferMemory calls. |
| `0x00516240` | callee `MemoryMan::MoveBufferMemory` | overlap-safe row move through memmove. |
| `0x00554700` / `0x00554800` | SetEmpty / UnionWithRect | resets and accumulates caller Region bounds. |
| `0x004b96c0` / geometry helpers | GetClipRect / IntersectRects / empty test / InitRectBounds | clip gate and dirty-strip construction. |

All callers ignore the target return register. No vtable or callback route supplements these three direct calls.

## Documentation Evidence And IDA Status

- UID00005V already maps all touched fields to GrafPort and explicitly keeps its class formal block blank to avoid an incomplete partial class declaration; exact method definitions belong on by-memory children.
- UID0000JR already orders methods by address in GrafPort.cpp. Generated output confirms UID000166 immediately precedes the missing target position and UID000167 immediately follows it.
- UID0001FW and Region class docs explicitly permit a `Region *dirtyRegion` source boundary while current helper names remain Motion-prefixed aliases over the shared +4 bounds layout.
- UID0001BI resolves the otherwise suspicious `GetMemoryMan` result: representative callers, including this target, load it as ECX for `MoveBufferMemory` even though the tiny wrapper body itself does not use ECX.
- Historical pre-callback contradictions were limited and actionable: target/parent/class/file repeated B010's old pending-helper wording, and caller aggregates omitted exact target linkage. The callback removed those contradictions in the seven accepted destinations.
- Historical generated baseline had no UID0004H7 marker or body because the emitter was blank. Current waited generated proof is one exact body in GrafPort.cpp, with no Surface.cpp or caller-source duplicate.

## Ranked Ownership Analysis

### 1. GrafPort

- Evidence for: ECX field set is entirely GrafPort; all three callers supply a GrafPort object; preceding/following source methods use the same class/file; clip/pixel/draw fields match current accepted layout.
- Evidence against: exact original private method spelling is stripped.
- Decision: canonical owner and emitter UID00005V; source UID0000JR.

### 2. Surface

- Evidence for: operation is low-level surface-buffer work and UID000165 is historically a Surface/GrafPort neighborhood.
- Evidence against: no separate Surface receiver, callback-table dispatch, or Surface-owned field is touched. Current project routing already assigns modeled receiver methods to GrafPort while Surface remains backend context.
- Decision: dependency/context only; no source ownership.

### 3. MapPane / ScrollablePane / FolderTreePane

- Evidence for: all direct calls originate in MapPane or ScrollablePane paths; historical Wave2 used FolderTreePane naming.
- Evidence against: callers pass either an embedded GrafPort or inherited leading GrafPort, and the same method serves multiple unrelated consumers. No target field belongs to a caller class.
- Decision: consumers only; FolderTreePane attribution is rejected stale caller pollution.

### Proposed new file/grouping, if applicable

- Not applicable. `NexusTK/render/GrafPort.cpp` already exists and is the coherent source destination. No new class, file, or grouping was invented.

## Source Placement

- Recommended placement: one `GrafPort::ScrollPixelBuffer` definition emitted by UID0004H7 through class UID00005V into by-file UID0000JR, `NexusTK/render/GrafPort.cpp`.
- Source order: after UID000166 `ForwardToTileFrameBlitHelper` and before UID000167 `GrafPort::BlitSurface`, matching exact address order. Leave optional position blank because existing surrounding GrafPort children use natural by-memory ordering.
- Rejected placements: Surface.cpp, MapPane.cpp, ScrollablePane.cpp, FolderTreePane.cpp, Region.cpp, MemoryMan.cpp, or a new buffer utility file. Those are dependencies/consumers, not the state-owning receiver source.
- Remaining placement uncertainty: none material. Only exact original private method spelling is inferred.

## Range / Split / Padding / Reclassification Analysis

- Exact target is one contiguous modeled function. Predecessor UID000166 ends with `retn 0x18` at `0x004b9a60-0x004b9a63`, followed by 13 `0xcc` bytes. Target ends with `retn 0x10` at `0x004ba247-0x004ba24a`, followed by six `0xcc` bytes before UID000167.
- MCP reports all 77 blocks. Complete block-start inventory grouped by role:

| Role | Exact block starts |
| --- | --- |
| entry, draw gate, clip gate | `4b9a70`, `4b9ab9`, `4b9af3` |
| `deltaX > 0`, `deltaY > 0` | `4b9b03`, `4b9b1a`, `4b9b74`, `4b9b8d`, `4b9b95`, `4b9bb8`, `4b9bd3`, `4b9c02`, `4b9c10`, `4b9c2a`, `4b9c33`, `4b9c8a`, `4b9c90`, `4b9caa`, `4b9cb0` |
| `deltaX > 0`, `deltaY <= 0` | `4b9cc2`, `4b9d14`, `4b9d2d`, `4b9d32`, `4b9d56`, `4b9d6e`, `4b9da1`, `4b9da6`, `4b9dc0`, `4b9dc6`, `4b9e01`, `4b9e0b`, `4b9e10`, `4b9e1d`, `4b9e30`, `4b9e4a`, `4b9e50` |
| nonpositive-X dispatch | `4b9e60` |
| `deltaX <= 0`, `deltaY > 0` | `4b9e77`, `4b9ed1`, `4b9eea`, `4b9ef2`, `4b9f15`, `4b9f30`, `4b9f60`, `4b9f68`, `4b9f82`, `4b9f8b`, `4b9fe3`, `4b9ffa`, `4ba007`, `4ba00b`, `4ba020`, `4ba03a`, `4ba043` |
| `deltaX <= 0`, `deltaY <= 0` | `4ba056`, `4ba0ad`, `4ba0c8`, `4ba0d0`, `4ba0f4`, `4ba0f7`, `4ba100`, `4ba124`, `4ba133`, `4ba13e`, `4ba14b`, `4ba155`, `4ba162`, `4ba17c`, `4ba1bc`, `4ba1c3`, `4ba1ca`, `4ba1e5`, `4ba1f3`, `4ba20d`, `4ba216` |
| shared dirty-union/epilogue | `4ba21d`, `4ba21f`, `4ba237` |

- Loop headers are `4b9b95`, `4b9c10`, `4b9c90`, `4b9d32`, `4b9da6`, `4b9e30`, `4b9ef2`, `4b9f68`, `4ba020`, `4ba0d0`, `4ba162`, and `4ba1f3`: one copy loop and two clear loops per quadrant.
- No branch enters from outside except the function start; no embedded bytes are addressed as data; no child starts exist. Split/child/data/padding reclassification inside UID0004H7 is rejected.
- UID000165 remains a non-emitting parent index. Its only impact is to historicalize the target's former no-code state and recognize the now-source-ready child.

## Negative Evidence Summary

- No direct target address appears in data/vtable/callback tables; no indirect caller route was recovered.
- No target instruction touches MapPane object-grid fields, ScrollablePane scrollbar fields, FolderTreePane state, Surface callback globals, DirectDraw interfaces, or PaletteLib. Those systems only prepare/consume the call.
- No target call allocates, frees, locks, unlocks, begins paint, ends paint, throws, or performs EH cleanup. Callers prepare the pixel context and own automatic Region lifetime.
- No target null-checks `scrollRect`, `dirtyRegion`, or `pixelData`; adding checks would change the caller contract and early-return effects.
- No evidence supports a separate horizontal helper, vertical helper, copy helper child, or compiler-generated classification. The repeated branches are ordinary optimized source control flow inside one function.
- The four-byte lower-strip clear is not a decompiler type guess: direct arithmetic computes four times clipped width before `_memset`. It must not be normalized to two bytes per pixel.
- The older target claim that `+0x44/+0x48` are read here is rejected by full operand review. The target uses `+0x2c/+0x30`; ScrollablePane independently passes its `+0x44` rectangle.

## IDA Rename / Type / Comment Recommendations

- Source-facing function type: `void __thiscall GrafPort::ScrollPixelBuffer(const RectBounds *, int, int, Region *)`.
- Source-facing argument names: `scrollRect`, `deltaX`, `deltaY`, `dirtyRegion`.
- Source-facing field names: `m_drawEnabled`, `m_surfaceContext.pixelData`, `m_surfaceContext.rowStridePixels`, `m_surfaceContext.bounds.left`, and `m_surfaceContext.bounds.top`.
- Source-facing helper names: `GetMemoryMan`, `MemoryMan::MoveBufferMemory`, `Region::SetEmpty`, `Region::UnionWithRect`, `GrafPort::GetClipRect`, `InitRectBounds`, `IntersectRects`, and `IsRectEmptyOrInvalid`.
- Preserve current IDA raw names as evidence only. No IDA mutation was requested or performed; source docs can use the names above without changing the shared database.
- A useful future IDA comment, if supervisor-owned IDA work is separately authorized, would identify the `0x004b9e26` four-byte-width lower-strip clear as observed behavior. This report does not request or perform that mutation.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. The target is a source-authored GrafPort method with complete range, signature, types, helper contracts, and branch behavior.
- Destination: `by-memory/0x004b9a70-0x004ba24a.GrafPortScrollPixelBuffer.md`. Replace the complete formal C++ block with exactly the following managed insertion shape:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void GrafPort::ScrollPixelBuffer(const RectBounds *scrollRect,
                                 int deltaX,
                                 int deltaY,
                                 Region *dirtyRegion)
{
    MemoryMan *memoryMan = GetMemoryMan();
    dirtyRegion->SetEmpty();

    if (!m_drawEnabled)
        return;

    RectBounds clipRect;
    GetClipRect(&clipRect);

    RectBounds clippedRect = *scrollRect;
    IntersectRects(&clippedRect, &clipRect, &clippedRect);
    if (IsRectEmptyOrInvalid(&clippedRect))
        return;

    unsigned short *pixels =
        static_cast<unsigned short *>(m_surfaceContext.pixelData);
    const int rowStridePixels = m_surfaceContext.rowStridePixels;
    const int surfaceLeft = m_surfaceContext.bounds.left;
    const int surfaceTop = m_surfaceContext.bounds.top;
    const int rectWidth = clippedRect.right - clippedRect.left;
    const int rectHeight = clippedRect.bottom - clippedRect.top;
    RectBounds dirtyRect;
    unsigned short *sourcePixels;
    unsigned short *destinationPixels;
    int copyWidth;
    int copyRows;
    int clearWidth;
    int clearRows;
    int clearX;
    int clearY;
    int row;

    if (deltaX > 0) {
        if (deltaY > 0) {
            copyWidth = rectWidth - deltaX;
            copyRows = rectHeight - deltaY;
            sourcePixels = pixels
                + (clippedRect.bottom - deltaY - 1 - surfaceTop)
                    * rowStridePixels
                + clippedRect.left - surfaceLeft;
            destinationPixels = pixels
                + (clippedRect.bottom - 1 - surfaceTop) * rowStridePixels
                + clippedRect.left + deltaX - surfaceLeft;

            if (copyRows > 0 && copyWidth > 0) {
                for (row = 0; row < copyRows; ++row) {
                    memoryMan->MoveBufferMemory(destinationPixels,
                                                sourcePixels,
                                                2 * copyWidth);
                    sourcePixels -= rowStridePixels;
                    destinationPixels -= rowStridePixels;
                }
            }

            clearRows = deltaY;
            if (rectHeight < clearRows)
                clearRows = rectHeight;
            destinationPixels = pixels
                + (clippedRect.top - surfaceTop) * rowStridePixels
                + clippedRect.left - surfaceLeft;
            if (clearRows > 0) {
                for (row = 0; row < clearRows; ++row) {
                    memset(destinationPixels, 0, 2 * rectWidth);
                    destinationPixels += rowStridePixels;
                }
            }
            InitRectBounds(&dirtyRect,
                           clippedRect.left,
                           clippedRect.top,
                           clippedRect.right,
                           clippedRect.top + clearRows);
            dirtyRegion->UnionWithRect(&dirtyRect);

            clearWidth = deltaX;
            if (rectWidth < clearWidth)
                clearWidth = rectWidth;
            copyRows = rectHeight - deltaY;
            destinationPixels = pixels
                + (clippedRect.top + deltaY - surfaceTop) * rowStridePixels
                + clippedRect.left - surfaceLeft;
            if (copyRows > 0) {
                for (row = 0; row < copyRows; ++row) {
                    memset(destinationPixels, 0, 2 * clearWidth);
                    destinationPixels += rowStridePixels;
                }
            }
            InitRectBounds(&dirtyRect,
                           clippedRect.left,
                           clippedRect.top + deltaY,
                           clippedRect.left + clearWidth,
                           clippedRect.bottom);
            dirtyRegion->UnionWithRect(&dirtyRect);
            return;
        }

        copyWidth = rectWidth - deltaX;
        copyRows = rectHeight + deltaY;
        sourcePixels = pixels
            + (clippedRect.top - deltaY - surfaceTop) * rowStridePixels
            + clippedRect.left - surfaceLeft;
        destinationPixels = pixels
            + (clippedRect.top - surfaceTop) * rowStridePixels
            + clippedRect.left + deltaX - surfaceLeft;

        if (copyRows > 0 && copyWidth > 0) {
            for (row = 0; row < copyRows; ++row) {
                memoryMan->MoveBufferMemory(destinationPixels,
                                            sourcePixels,
                                            2 * copyWidth);
                sourcePixels += rowStridePixels;
                destinationPixels += rowStridePixels;
            }
        }

        clearWidth = deltaX;
        if (rectWidth < clearWidth)
            clearWidth = rectWidth;
        destinationPixels = pixels
            + (clippedRect.top - surfaceTop) * rowStridePixels
            + clippedRect.left - surfaceLeft;
        if (copyRows > 0) {
            for (row = 0; row < copyRows; ++row) {
                memset(destinationPixels, 0, 2 * clearWidth);
                destinationPixels += rowStridePixels;
            }
        }
        InitRectBounds(&dirtyRect,
                       clippedRect.left,
                       clippedRect.top,
                       clippedRect.left + clearWidth,
                       clippedRect.bottom);
        dirtyRegion->UnionWithRect(&dirtyRect);

        clearRows = -deltaY;
        clearY = clippedRect.bottom + deltaY;
        if (rectWidth < clearRows) {
            clearRows = rectWidth;
            clearY = clippedRect.top;
        }
        destinationPixels = pixels
            + (clearY - surfaceTop) * rowStridePixels
            + clippedRect.left - surfaceLeft;
        if (clearRows > 0) {
            for (row = 0; row < clearRows; ++row) {
                // Preserve the original branch's four-byte clear width.
                memset(destinationPixels, 0, 4 * rectWidth);
                destinationPixels += rowStridePixels;
            }
        }
        InitRectBounds(&dirtyRect,
                       clippedRect.left,
                       clippedRect.bottom + deltaY,
                       clippedRect.right,
                       clippedRect.bottom);
        dirtyRegion->UnionWithRect(&dirtyRect);
        return;
    }

    if (deltaY > 0) {
        copyWidth = rectWidth + deltaX;
        copyRows = rectHeight - deltaY;
        sourcePixels = pixels
            + (clippedRect.bottom - deltaY - 1 - surfaceTop)
                * rowStridePixels
            + clippedRect.left - deltaX - surfaceLeft;
        destinationPixels = pixels
            + (clippedRect.bottom - 1 - surfaceTop) * rowStridePixels
            + clippedRect.left - surfaceLeft;

        if (copyRows > 0 && copyWidth > 0) {
            for (row = 0; row < copyRows; ++row) {
                memoryMan->MoveBufferMemory(destinationPixels,
                                            sourcePixels,
                                            2 * copyWidth);
                sourcePixels -= rowStridePixels;
                destinationPixels -= rowStridePixels;
            }
        }

        clearRows = deltaY;
        if (rectHeight < clearRows)
            clearRows = rectHeight;
        destinationPixels = pixels
            + (clippedRect.top - surfaceTop) * rowStridePixels
            + clippedRect.left - surfaceLeft;
        if (clearRows > 0) {
            for (row = 0; row < clearRows; ++row) {
                memset(destinationPixels, 0, 2 * rectWidth);
                destinationPixels += rowStridePixels;
            }
        }
        InitRectBounds(&dirtyRect,
                       clippedRect.left,
                       clippedRect.top,
                       clippedRect.right,
                       clippedRect.top + clearRows);
        dirtyRegion->UnionWithRect(&dirtyRect);

        clearWidth = -deltaX;
        clearX = clippedRect.right + deltaX;
        if (rectWidth < clearWidth) {
            clearWidth = rectWidth;
            clearX = clippedRect.left;
        }
        destinationPixels = pixels
            + (clippedRect.top + deltaY - surfaceTop) * rowStridePixels
            + clearX - surfaceLeft;
        if (copyRows > 0) {
            for (row = 0; row < copyRows; ++row) {
                memset(destinationPixels, 0, 2 * clearWidth);
                destinationPixels += rowStridePixels;
            }
        }
        InitRectBounds(&dirtyRect,
                       clippedRect.right + deltaX,
                       clippedRect.top + deltaY,
                       clippedRect.right,
                       clippedRect.bottom);
        dirtyRegion->UnionWithRect(&dirtyRect);
        return;
    }

    copyWidth = rectWidth + deltaX;
    copyRows = rectHeight + deltaY;
    sourcePixels = pixels
        + (clippedRect.top - deltaY - surfaceTop) * rowStridePixels
        + clippedRect.left - deltaX - surfaceLeft;
    destinationPixels = pixels
        + (clippedRect.top - surfaceTop) * rowStridePixels
        + clippedRect.left - surfaceLeft;

    if (copyRows > 0 && copyWidth > 0) {
        for (row = 0; row < copyRows; ++row) {
            memoryMan->MoveBufferMemory(destinationPixels,
                                        sourcePixels,
                                        2 * copyWidth);
            sourcePixels += rowStridePixels;
            destinationPixels += rowStridePixels;
        }
    }

    clearWidth = -deltaX;
    clearX = clippedRect.right + deltaX;
    if (rectWidth < clearWidth) {
        clearWidth = rectWidth;
        clearX = clippedRect.left;
    }
    destinationPixels = pixels
        + (clippedRect.top - surfaceTop) * rowStridePixels
        + clearX - surfaceLeft;
    if (copyRows > 0) {
        for (row = 0; row < copyRows; ++row) {
            memset(destinationPixels, 0, 2 * clearWidth);
            destinationPixels += rowStridePixels;
        }
    }
    InitRectBounds(&dirtyRect,
                   clippedRect.right + deltaX,
                   clippedRect.top,
                   clippedRect.right,
                   clippedRect.top + copyRows);
    dirtyRegion->UnionWithRect(&dirtyRect);

    clearRows = -deltaY;
    clearY = clippedRect.bottom + deltaY;
    if (rectHeight < clearRows) {
        clearRows = rectHeight;
        clearY = clippedRect.top;
    }
    destinationPixels = pixels
        + (clearY - surfaceTop) * rowStridePixels
        + clippedRect.left - surfaceLeft;
    if (clearRows > 0) {
        for (row = 0; row < clearRows; ++row) {
            memset(destinationPixels, 0, 2 * rectWidth);
            destinationPixels += rowStridePixels;
        }
    }
    InitRectBounds(&dirtyRect,
                   clippedRect.left,
                   clippedRect.bottom + deltaY,
                   clippedRect.right,
                   clippedRect.bottom);
    dirtyRegion->UnionWithRect(&dirtyRect);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Behavior fidelity: each branch uses the exact source/destination origin, positive copy-dimension gates, vertical traversal direction, clear clamp, and dirty rectangle endpoints. The anomalous four-byte clear and width-based row clamp are explicit.
- Period consistency: C++03-compatible declarations, explicit loops, `NULL`-era project types, `memset`, and current project helper/method conventions; no lambdas, `auto`, range iteration, or decompiler labels.
- Names/types replacing raw labels are listed under IDA Rename / Type / Comment Recommendations.
- No class declaration block is proposed. UID00005V intentionally keeps its class block blank because a partial declaration would omit unrelated GrafPort members; the exact child method definition is the established emission pattern.

## Final Recommendation

- C4H7-001 through C4H7-040 are applied or confirmed already present claim by claim, with no blocked or excluded claim.
- UID0004H7 metadata/body/prose, UID000165, GrafPort class/file, both caller aggregates, and Region/Motion support are updated at full evidence detail.
- All helper source pages, Region class, MapTilePixelDimensions, UID000164, and unrelated GrafPort siblings remain unchanged because the necessary facts were already present.
- No source item in this target remains no-owner or non-emitting. Only external alignment spans and compiler security-cookie lowering remain non-source.
- No out-of-scope future research is required for source readiness. Exact original private spelling remains a score cap only.

## Recommended Target Doc Changes

- Target path: `by-memory/0x004b9a70-0x004ba24a.GrafPortScrollPixelBuffer.md`.
- Applied metadata: `COMPLETION:92`, `CONFIDENCE:94`, retained `CANONICAL_OWNER:00005V`, retained `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00005V`, blank optional position, retained `Nested:0`.
- Applied formal C++: the former blank block contains the exact managed block above.
- Applied Item Summary: source-ready GrafPort method, clipped caller rectangle, overlap-safe 16-bit row shifts in four direction quadrants, exact exposed-strip clears including the legacy four-byte anomaly, and Region dirty-bound accumulation, without duplicated UID/range/score/owner metadata.
- Applied prose: exact range/padding/CFG, ABI, callers, helper names, Region protocol, field offsets/types, all four quadrants, edge cases, side effects, source placement, negative evidence, rejected alternatives, and score rationale.
- Applied history: B010 creation/no-code blocker is explicitly historical/superseded; Wave2 FolderTreePane/`bool` remains rejected historical provenance.

## Recommended Support Doc Changes

- Applied `by-memory/0x004b9820-0x004ba24a.SurfacePaintHelpers.md`: UID0004H7 row/current prose is source-ready; helper/Region/caller details are added; index is `89/92`; parent owner UID0000OC, non-reconstructable/non-emitting state, blank formal C++, `Nested:8`, UID00035C, and siblings are preserved.
- Applied `by-class/GrafPort.md`: class narrative and Method Notes contain the resolved signature, four-quadrant 16-bit behavior, Region output, and legacy anomaly; `88/90`, owner/emitter, blank class formal block, and unrelated methods are preserved.
- Applied `by-file/GrafPort.md`: inventory/history marks source-ready state and source placement between UID000166 and UID000167; `89/88`, path, and unrelated content are preserved.
- Applied `by-memory/0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore.md`: exact two-call protocol, embedded `m_viewportGrafPort +0x428`, `g_mapTilePixelWidth/Height` scaling, local Region lifetime, and ignored return are recorded; no score, metadata, aggregate formal C++, split, or method-name decision changed.
- Applied `by-memory/0x0055e660-0x0055f44f.ScrollablePaneCore.md`: exact `0x0055eae0` relationship, Point y/x order, visible bounds, Region lifetime, caller-owned UpdateSurfaceInfo/EndPaint, and ignored return are recorded; no score, metadata, aggregate formal C++, or B005/B001 contract changed.
- Applied `by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md`: UID0004H7 is a concrete `Region *dirtyRegion` consumer of Motion-named `SetEmpty`/`UnionWithRect`; `90/91`, owner/emitter, complete formal block, raw children, layout, and other consumers are preserved.
- Already-present/no-edit support: UID0001BC, UID0001BI, UID00015S, UID000164, by-class/Region, and by-global/MapTilePixelDimensions. Their current accepted contracts are evidence, not destinations for duplicated prose.

## Score And Metadata Recommendation

- Historical pre-callback target: `86/90`, GrafPort owner, reconstructable true, blank emitter/position/C++.
- Applied target: `92/94`, same owner/reconstructability/Nested, emitter UID00005V, blank optional position, complete body.
- Completion rises because signature, return, helper identities, argument object, every branch, edge behavior, and generated source route are closed. Confidence rises because live callers/helper bodies/layout docs mutually corroborate the form.
- Reason not higher: original private method/local spelling is stripped; `ScrollPixelBuffer` and local names remain highest-probability descriptive forms. The four-byte lower-strip behavior is exact binary fact, but whether it was an intentional source quirk or developer bug is unknowable and does not affect reproduction.
- Score-improvement attempts:
  - helper blocker: decompiled all named helpers and opened their accepted reports/pages; resolved all.
  - `a5` blocker: decompiled all callers through construction, call, use, and destruction; resolved as Region boundary.
  - return blocker: audited epilogue and all callers; resolved as source `void`.
  - field/type blocker: reconciled target offsets with current GrafPort/EPFTileContext docs; resolved to 16-bit pixels and pixel stride.
  - body blocker: audited complete target decompile and every CFG block; resolved four quadrants and all edge cases.
  - source placement blocker: checked neighborhood, class/file docs, generated order, and caller diversity; resolved to GrafPort.cpp.
  - duplicate/split blocker: xrefs, exact bytes, CFG, and neighboring padding show one unique body; no split.
- Parent UID000165: `88/91 -> 89/92` because its final named child blocker is closed, while raw UID00035C and exact lexical names keep the mixed index below target-level completion. All other support scores remain unchanged.

## Open Questions With Attempted Resolution

- Exact original method spelling: stripped symbols and entity/name searches provide no lexical proof. `ScrollPixelBuffer` is retained because it is current project-stable and exact semantically; `ScrollPixels` ranks second. This is a confidence cap, not a C++ blocker.
- Return type: resolved to source `void` after checking every caller and helper return contract; no open blocker remains.
- `a5` type: resolved to `Region *dirtyRegion` after all three caller lifetime checks and accepted Region/Motion layout compatibility; no open blocker remains.
- Point/order: resolved. ScrollablePane's Point is y/x in storage; second dword becomes target X and first becomes target Y. Map callers independently pass width-scaled X and height-scaled Y.
- Four-byte lower-strip clear: resolved as behavior that must be preserved. Its developer intent cannot be proven, but source reproduction must retain it rather than "fix" it.
- Oversized and zero deltas: resolved from exact branches and helper behavior; no defensive normalization should be added.
- Remaining unresolved questions with implementation impact: none. Unrecoverable lexical intent affects only the score cap.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Not applicable. Research tracker and generated coverage remain validator-owned. B001 made no manual tracker or coverage edit; scoped validators and the authorized waited refresh performed their normal owned side effects.

## Follow-Up Actions

- B001 callback scope is complete; no B001 implementation, validation, lease-release, generated-verification, or report-text work remains.
- No A-agent action is identified by this artifact.
- Report validation/execution/count/path/movement/archive state remains external supervisor/validator-owned and is neither asserted nor directed by this artifact. B001 ran no report execute, lifecycle, move, or archive command.

## Confidence

- Recommendation confidence: high to very high.
- Score confidence: high.
- Remaining uncertainty: exact original private identifiers and intent behind one directly observed legacy over-clear. Neither changes ABI, ownership, behavior, source placement, or body eligibility.

## Validator Results

- Preflight only: command `000000009914`, `2026-07-13T13:01:09-04:00`, exit `0`, displayed validator CLI help after an argument-discovery call. It had no `--mode file`, `--file`, or `--apply`, performed no validation, and changed no by-* page.
- UID0004H7 scoped validation: command `000000009923`, `2026-07-13T13:05:02-04:00`, exit `0`, `ok:1`; recorded `92/94`, emitter UID00005V, formal-block registration, and UID000164 link insertion; generated refresh deferred.
- UID000165 scoped validation: command `000000009927`, `2026-07-13T13:06:21-04:00`, exit `0`, `ok:1`; recorded `89/92`; generated refresh deferred.
- UID00005V scoped validation: command `000000009929`, `2026-07-13T13:07:24-04:00`, exit `0`, `ok:1`; reported three pre-existing `missing_ref_uid 0003XE` diagnostics and made no target claim invalid; generated refresh deferred.
- UID0000JR scoped validation: command `000000009932`, `2026-07-13T13:08:11-04:00`, exit `0`, `ok:1`; reported four pre-existing `missing_ref_uid 0003XE` diagnostics and made no target claim invalid; generated refresh deferred.
- UID00037Y scoped validation: command `000000009936`, `2026-07-13T13:09:56-04:00`, exit `0`, `ok:1`; inserted the UID0000T7 link and refreshed UID0000T7/UID0003TJ/UID0004H7 references; generated refresh deferred.
- UID0001GL scoped validation: command `000000009938`, `2026-07-13T13:10:42-04:00`, exit `0`, `ok:1`; added UID0004H7 reference indexing; generated refresh deferred.
- UID0001FW scoped validation: command `000000009939`, `2026-07-13T13:11:36-04:00`, exit `0`, `ok:1`; added UID0004H7 reference indexing; generated refresh deferred.
- Final authorized target validation: command `000000009942`, `2026-07-13T13:12:00-04:00`, exit `0`, `ok:1`, `--wait-generated`; registry rebuild completed and `generated_refresh:completed`. Relevant generated file write time is `2026-07-13T13:12:06.9264743-04:00`, after command start, proving freshness.
- Generated proof: `auto-generated/NexusTK/render/GrafPort.cpp`, SHA256 `191FE21644EC604690BA7599720DCE29917F2EA1F213BAD9B56259DB837EECAF`; normalized target managed body exactly matches the generated body; UID0004H7 count `1`; signature count `1`; `MoveBufferMemory` count `4`; row-loop count `12`; `SetEmpty` count `1`; `UnionWithRect` count `8`; anomalous `4 * rectWidth` count `1`; target Empty Emitter Marker count `0`; wrong-owner signature count `0` across all generated C++.
- Generated order proof: UID000166 marker line `257`, UID0004H7 marker line `282`, UID000167 marker line `574`; each neighboring UID occurs once across generated C++, so exact address order and surrounding-body continuity are intact. `Surface.cpp` contains zero UID0004H7 markers and zero `ScrollPixelBuffer` signatures.
- Validator-owned side effects: each scoped command updated projected stats/reference metadata as reported; final waited command rebuilt registry metadata and refreshed generated metadata. B001 manually edited none of those files. No validator returned nonzero or `ok:0`.

## Changed Files

- Same report updated: `tools/leaser/Agents/Agent-B001/research/0004H7-GrafPortScrollPixelBuffer-source-quality.md`.
- Changed target: `by-memory/0x004b9a70-0x004ba24a.GrafPortScrollPixelBuffer.md`.
- Changed support: `by-memory/0x004b9820-0x004ba24a.SurfacePaintHelpers.md`.
- Changed support: `by-class/GrafPort.md`.
- Changed support: `by-file/GrafPort.md`.
- Changed support: `by-memory/0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore.md`.
- Changed support: `by-memory/0x0055e660-0x0055f44f.ScrollablePaneCore.md`.
- Changed support: `by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md`.
- Renamed/created by-* pages: none. No split, child, ignored-row, or UID registration was needed.
- Manual generated/tracker/coverage/supervisor/validator/IDA edits: none. The validator-owned waited refresh generated the verified GrafPort.cpp artifact described above.
- Lease proof: every listed by-* page was leased alone immediately before its scoped edit/validation and unleased with `Success`; the target was re-leased alone for final waited validation and unleased with `Success`. Final `tools/leaser/Agents/current_leases.md` contains no B001 row.
- Report execution: not run. B001 ran no execute, lifecycle, move, archive, or equivalent report command.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor Gate 1 accepted this exact report at SHA `575A030BF6D42F38BECD82B420E920E2CF6D9E17EEAB2949DF9D560695BE022E` before implementation.
- [x] Callback edit scope remained exactly UID0004H7, UID000165, by-class/GrafPort, by-file/GrafPort, UID00037Y, UID0001GL, and UID0001FW.
- [x] Pre-edit target state, SHA, actual evidence, generated baseline, and historical no-code provenance are retained.
- [x] Claim And Incorporation Ledger keeps only allowed Action values; all C4H7-001 through C4H7-040 states are legal callback enums with separate proof.
- [x] Target `86/90 -> 92/94` and parent `88/91 -> 89/92` are applied; every listed support score is preserved.
- [x] Helpers, `a5`, signature/return, fields/types, callers, complete branches, edge cases, source placement, split, duplicates, and generated route were resolved before callback and applied without deferral.
- [x] Owner UID00005V/reconstructable true/Nested 0 are retained; target emitter is UID00005V; optional position remains blank.
- [x] No split/new child was introduced; stable `ScrollPixelBuffer` is retained; raw/FolderTreePane alternatives are historicalized.
- [x] GrafPort.cpp placement, exact range, external padding, and no-internal-reclassification disposition are applied.
- [x] Exactly one destination-specific managed C++ block remains in the report and is copied exactly to the target.
- [x] Third-party import directive is not applicable; this is NexusTK source-authored code with the accepted multiline body.
- [x] C4H7-001 through C4H7-040 were incorporated at report-level detail without compression.
- [x] B010 no-code, Wave2 FolderTreePane/`bool`, stale `+0x44/+0x48`, no vtable/callback/split/null/EH, and exact over-clear history/negative evidence are preserved.
- [x] Wave2 artifact is retained and rejected where stale; no Wave3 artifact was used as source authority.
- [x] Open questions are closed or bounded as nonblocking lexical confidence caps.
- [x] Seven scoped file validators ran one at a time under short leases, followed by final target `--wait-generated`.
- [x] GrafPort.cpp exact count/order/content and marker/duplicate absence are verified; no generated or coverage file was manually edited.

Implementation callback pass:

- [x] Report was accepted for implementation at exact SHA `575A030BF6D42F38BECD82B420E920E2CF6D9E17EEAB2949DF9D560695BE022E`.
- [x] Every destination was re-read after its one-file lease; no overlapping lease or claim-invalidating drift was encountered.
- [x] UID0004H7 metadata, exact formal block, complete behavior/evidence/history, summary, and score are applied.
- [x] UID000165 source-ready child row/history and `89/92` are applied without changing parent non-emitting disposition or siblings.
- [x] GrafPort class/file contradictions are replaced without partial class C++, unrelated score inflation, or sibling loss.
- [x] MapPane/ScrollablePane caller support and Region compatibility support are incorporated without aggregate C++ or metadata changes.
- [x] C4H7-001 through C4H7-040 use exact callback enums and have separate detailed proof.
- [x] Every changed ordinary by-* page passed its scoped validator; command IDs, timestamps, exits, `ok`, side effects, and lease release are recorded.
- [x] Final authorized waited refresh completed as command `000000009942`, with freshness proof recorded.
- [x] Generated GrafPort.cpp exact UID/body/helper/anomaly/order counts passed; Surface.cpp and all generated caller/owner scans contain no duplicate target body.
- [x] Historical assumptions, rejected alternatives, negative evidence, and substantive report research are retained without compression.
- [x] Remaining unapplied, excluded, or blocked accepted items: none.
- [x] All B001 leases were released before callback completion; the final lease report contains no B001 row.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000009980","destination_path":"executed-b-agent-research/B001/0004H7-GrafPortScrollPixelBuffer-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0004H7-GrafPortScrollPixelBuffer-source-quality.md","timestamp":"2026-07-13T13:26:38-04:00","uid":"0004H7"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
