** TARGET-REPORT-UID:0003TL **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0003TL MapPaneHandleMapInfoTileRegionPacket Source-Quality Research


## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003TL] as the exact source-bearing `MapPane` opcode `0x06` map-info/tile-region packet handler at `0x00510960-0x00511347`.
- Final disposition for supervisor execute readiness: direct owner/emitter stays [UID:00007Q] `MapPane`, file route stays [UID:0000L3] `MapPane`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, score is `90/90`, and the formal first-draft C++ is present in the target's `RECONSTRUCTION_CPP CODE` block.
- Gate 1 callback status: accepted target/support doc details were applied or verified in the current by-* docs, the ledger/checklist below records exact states, scoped validators were run, and B011 stopped before `execute_report`.
- Confidence: high for exact range, dispatcher route, owner/emitter, tile-region behavior, support-only PaletteLib dependency, two static-object refresh calls, and six-byte tile-record layout; medium-high for inferred source-facing field/helper/type spellings.

## Supporting Research

- Current report lifecycle/status: accepted report in `tools/leaser/Agents/Agent-B011/research/` with B011 implementation callback completed. It is not executed or archived; B011 is returning it for supervisor Gate 2/execute handling.
- Historical stale-artifact note: the previous body of this report read as if Gate 1 had already passed and an implementation callback had been applied. That stale current-state wording is superseded here. Any prior callback/validator text is treated only as historical/current-doc context, not as proof that this current report artifact passed Gate 1.
- Current user/supervisor instruction: use the `ntk-b-agent-workflow` skill, apply accepted report details to target/support by-* docs only, update this report's ledger/checklist, run scoped validators, release leases, do not run `execute_report` or lifecycle/registry commands, and stop if MCP is unavailable.
- MCP availability for this pass: `initialize`, `tools/list`, `idb_list`, `server_health`, and narrow read-only MCP calls succeeded against `http://127.0.0.1:13337/mcp`. Active IDB session used: `b001-0001I5`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `15332`, active/adopted/owned.
- MCP health: `server_health(database=b001-0001I5)` returned `status:ok`, module `NexusTK.exe`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, `strings_cache_size:2067`.
- Read gates/evidence read: `goal.md`, `ntk-b-agent-workflow/SKILL.md`, `b-agent-research-and-implementation-workflow.md`, `b-agent-report-template.md`, `score-blocker-audit-standard.md`, `by-structure.md` relevant metadata/C++ gates, `by-memory/-guidance.md`, `by-type/-guidance.md`, `by-type/by-struct/-guidance.md`, target/support docs named in the assignment, generated tracker/coverage rows, ignored-padding ledger rows, and matching old B reports.
- Callback scope observed: only target/support by-* docs and this B011-owned report were manually edited; generated files/project stats were changed only by scoped validator refresh. No coverage reports, validator state, supervisor ledgers, report archives, lifecycle files, or generated files were manually edited.

## Target

- Target UID: `0003TL`.
- Target path: `source-3/project-documentation/by-memory/0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket.md`.
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B011/research/0003TL-MapPaneHandleMapInfoTileRegionPacket-source-quality.md`.
- Assignment queue row at creation: `auto-generated/-ag-research-tracker.md` listed [UID:0003TL] as `86/89`, combined `87.5`, reconstructable `true`, reports `0`.
- Current generated tracker row read during this repair: [UID:0003TL] is `90/90`, combined `90.0`, reconstructable `true`, reports `0`; the report count still confirms this unexecuted report remains the lifecycle artifact.
- Current supervisor classification: B-agent source-quality report first; no implementation until supervisor Gate 1 callback.
- Current owner/emitter route: [UID:00007Q] `MapPane`; file route [UID:0000L3] `MapPane`.

## Current Target State

- Assignment baseline metadata: `COMPLETION:86`, `CONFIDENCE:89`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, blank formal C++.
- Current by-* doc state read during this repair: target now records `COMPLETION:90`, `CONFIDENCE:90`, same owner/reconstructable/emitter fields, and formal `MapPane::HandleMapInfoTileRegionPacket(const unsigned char *packet)` first-draft C++.
- Current generated state read-only: `auto-generated/-ag-memory-coverage.md` lists UID0003TL as `coded`; `auto-generated/NexusTK/map/MapPane.cpp` contains the UID0003TL code and UID0004HP `MapPaneTileRecord`; `auto-generated/-ag-coverage-report-by-memory.md` lists the memory row as `emits_code:true`.
- Current artifact/lifecycle status: this report is unexecuted and repaired for Gate 1; the current by-* docs already contain earlier B011 implementation-style changes, but this pass did not touch them.
- Existing target behavior summary: exact MapPane opcode `0x06` handler, dispatcher xref `0x00507ffa`, map/resource string and tile descriptor mutation, PaletteLib dependency through `sub_50D8E0`, two calls to [UID:0003TJ], and padding `0x00511347-0x00511350`.
- Source-quality blockers in scope: exact range/padding, dispatcher route/opcode naming, packet payload/map-name/resource fields, tile rectangle clipping, six-byte tile descriptor layout, dirty-region helpers, static-object refresh calls, PaletteLib support-only dependency, MapPane owner/emitter route, and first-draft C++ eligibility. This report resolves all of them to implementation-ready target/support doc actions.
- Related target/support docs checked: [UID:00007Q] `by-class/MapPane.md`; [UID:0000L3] `by-file/MapPane.md`; [UID:0001AW] `by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md`; [UID:0001SO] `by-type/by-enum/MapServerPacketOpcode.md`; [UID:0003TJ] `by-memory/0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md`; [UID:0001E9] `by-memory/0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers.md`; [UID:0004HP] `by-type/by-struct/MapPaneTileRecord.md`; `by-type/by-struct/MapPaneLayout.md`; helper docs [UID:0003YK], [UID:0003YN], [UID:0001BH], [UID:000423]; `by-memory/-ignored.md`; generated tracker/coverage reports; matching old reports listed under `Evidence Checked`.

## Heuristic / Inference Reanalysis And Validation

- Exact function range: resolved. MCP `lookup_funcs` reports `sub_510960` at `0x00510960`, size `0x9e7`. `lookup_funcs` reports `0x00510958`, `0x00511347`, and `0x00511350` are not function starts. The target body ends at `0x00511347` end-exclusive.
- Padding: resolved. MCP `get_bytes(0x00510958,8)` returns eight `0xcc` bytes before this function. `get_bytes(0x00511347,9)` returns nine `0xcc` bytes after this function. Raw bytes at `0x00511350` still begin with a prologue-shaped sequence, but `xrefs_to 0x00511350` returns zero xrefs, so it is not part of UID0003TL.
- Dispatcher route: resolved. Bounded `search_text` over `0x00507c90-0x00508f60` found exactly one `call sub_510960` at `0x00507ffa`. `disasm(0x00507c90, offset=205)` labels `loc_507FF3` as `jumptable 00507CE2 case 6`; the case pushes the packet pointer, loads `ecx = [esi-0A0h]`, calls `sub_510960`, and jumps to the dispatcher return. `xrefs_to 0x00510960` returns exactly that one code xref.
- Branching layout selector: resolved as an in-function layout/compatibility branch, not a split. `decompile(0x00510960)` branches on `byte_66DA97 == 1`; both arms parse the same logical variable-length packet, update the same MapPane fields, clip and write tile records, call the same dirty/static-object helpers, and return success. The source-shape recommendation is one handler with a branch, not two children.
- Packet source shape: use `MapInfoTileRegionPacketView` as the documentation/source-facing packet cursor view and `bool MapPane::HandleMapInfoTileRegionPacket(const unsigned char *packet)` as the best-defensible method signature. Do not use a fixed packed packet struct because optional strings make the tile rectangle and records variable-offset. The packet pointer includes opcode byte `0x06`; offset `+1` is the flags byte.
- Packet fields: close the layout as `flags` bit `0x01` = map-name string present, bit `0x02` = resource/palette-name string present, and bit `0x04` = map-resource/mode byte present. Each present string is one byte length plus bytes copied by `sub_516220` and converted with `MultiByteToWideChar`. After optional fields, the cursor reads `uint16 originTileX`, `uint16 originTileY`, `uint8 tileWidth`, `uint8 tileHeight`, then `tileWidth * tileHeight` tile records as three big-endian packet words per clipped tile.
- MapPane field names/types: use these best-defensible source-facing names: `this+276` = `m_mapResourceMode`; `this+1008` = `m_hasRenderableMap`; `this+1012` = `m_mapWidthTiles`; `this+1014` = `m_mapHeightTiles`; `this+1016` = `m_mapTileRecords`; `this+1230` = `m_refreshWholeVisibleMap`; `this+1244` = `m_mapName[256]`; `this+1756` = `m_mapNameLength`; `this+1758` = `m_mapResourceName[256]`; `this+2270` = `m_mapResourceNameLength`; `this+2316/+2318` = deferred map-surface refresh dirty flags. These are inferred source-facing names, not original-symbol proof.
- Map/resource string storage: MCP decompilation stores converted map text at `this+1244` with count at `this+1756`; converted resource/palette text at `this+1758` with count at `this+2270`. It appends `.EPF` from `0x0061a44c` and `.PAL` from `0x0061ea24`. `get_string(0x0061a44c)` truncates to `.E`, but `get_bytes` returns UTF-16 bytes for `.EPF`, so docs should cite bytes for the EPF suffix.
- Map-mode side effect: close `this+276` as `m_mapResourceMode`; when the incoming mode byte differs from the saved byte, the handler calls `sub_5040A0(this)`. Source-facing support name should be `MapPane::ResetMapResourceStateForModeChange`.
- Tile rectangle clipping: resolved. Decompilation uses `sub_4B7C50` and `sub_4B7CC0` over four-edge rectangle locals to clamp the incoming rectangle against `m_mapWidthTiles` / `m_mapHeightTiles`. Use source-facing names `SetRectBounds` and `IntersectRectBounds` over `MapRect`/`RectBounds`.
- Tile record type: resolved as `MapPaneTileRecord`, a six-byte live MapPane tile-buffer record with three 16-bit words: word `0` = `groundTileId`, word `1` = `flags` with bit `0` merged from the packet, word `2` = `staticObjectId`. Do not reuse [UID:0001V3] `MapTileRecord`, which is a different four-byte MapTileImageLib resource record.
- Dirty/refresh helper names: close source-facing names as `MapPane::GetExtendedVisibleTileBounds(MapRect *outBounds) const` for `sub_505370`, `MapPane::DrawTileAt(int tileX, int tileY, bool beginPaint)` for `sub_50D8E0`, and `MapPane::RefreshStaticObjectTileRegion(const MapRect &tileBounds)` for UID0003TJ `sub_50F130`. The `__userpurge` hidden `EDI` scalar in UID0003TJ decompilation is helper-internal carry-through, not a UID0003TL source argument.
- Static-object refresh calls: resolved. `xrefs_to 0x0050f130` returns four code xrefs, two from UID0003TL at `0x00510e28` and `0x00511318`. `analyze_function(0x0050f130)` confirms rectangle iteration, descriptor fetch through `sub_50C120`, static-object id read at descriptor byte offset `+4`, ObjectList lookup/removal, and replacement creation through `sub_50F030`.
- PaletteLib dependency: resolved as support-only. `analyze_function(0x0050d8e0)` shows `sub_50D8E0` calls `sub_543F60(g_pPaletteLib,1)` at `0x0050d94f` before in-bounds tile drawing and restores `sub_543F60(g_pPaletteLib,0)` at `0x0050d99f`. The packet handler calls the MapPane draw helper; it does not own PaletteLib filter state.
- Owner/emitter route: resolved. This body parses a MapPane packet and mutates MapPane tile, map-resource, dirty-region, and object-list state. StaticObjectPane, ObjectList, PaletteLib, Socket/protocol tables, suffix literal pages, FieldMapPane/WorldMapPane suffix users, and raw `0x00511350` are support or dependency contexts only.

## Evidence Standards Used

- IDA MCP facts were treated as highest evidence for function boundaries, xrefs, disassembly switch annotations, decompilation, bytes, strings, and helper behavior.
- Current by-* docs were used as durable project-state evidence for UIDs, owner/emitter routes, score state, support-page status, and existing generated-output route.
- Generated reports were used as read-only current queue/coverage state, not as authority over IDA facts.
- Old B reports were search-gated and used as leads or historical context. Reports carrying `REPORT-VALIDATION-STATUS: needs-revalidation` were not used as accepted coverage proof.
- Inference was kept below direct evidence: field/helper/type names are recommended where caller/callee behavior and source-shape context make them stable enough for first-draft C++, and each remains labeled as inferred rather than original-symbol proven.

## Evidence Checked

- MCP availability/session checks: `initialize`, `tools/list`, `idb_list`, and `server_health(database=b001-0001I5)` succeeded.
- MCP exact-function checks: `lookup_funcs` for `0x00507c90`, `0x00507ffa`, `0x005104d0`, `0x00510958`, `0x00510960`, `0x00511347`, `0x00511350`, `0x00511420`, `0x00511430`, `0x00511440`, `0x0050f130`, `0x0050d8e0`, `0x00543f60`, `0x00543f80`, `0x0050c120`, and `0x00505370`.
- MCP target analysis: `analyze_function(0x00510960, include_asm=false)` and `decompile(0x00510960, include_addresses=true)` confirmed the two-branch packet parser, string handling, rectangle clipping, tile writes, `sub_50D8E0`, `sub_505370`, `sub_50F130`, deferred flags, and final return.
- MCP route/xref checks: `search_text` bounded to `0x00507c90-0x00508f60` for `call sub_510960`; `disasm(0x00507c90, offset=205, max_instructions=35)`; `xrefs_to` for `0x00510960`, `0x00511350`, `0x0050f130`, `0x0050d8e0`, `0x00543f60`, `0x00543f80`, `0x0061a44c`, and `0x0061ea24`.
- MCP byte/string checks: `get_bytes` for `0x00510958`, `0x00511347`, `0x00511340`, `0x00511350`, `0x0061a44c`, `0x0061ea24`, and `0x0061ea30`; `get_string` for `0x0061a44c`, `0x0061ea24`, `0x0061ea30`, and `0x0061ea48`.
- MCP helper checks: `analyze_function(0x0050d8e0)` and `analyze_function(0x0050f130)`.
- Current by-* docs checked: target UID0003TL; MapPane class/file; MapPane packet-handler container; MapServerPacketOpcode; UID0003TJ static-object refresh; UID0001E9 PaletteLib helpers; UID0004HP MapPaneTileRecord; MapPaneLayout; helper docs for packet-buffer scalar/cursor reads, MemoryMan memmove, and extended visible bounds; by-memory ignored padding rows.
- Generated reports checked: `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, `auto-generated/-ag-memory-coverage.md`, and `auto-generated/NexusTK/map/MapPane.cpp`.
- Required old-report search terms/results:

| Search term | Direct result |
| --- | --- |
| `TARGET-REPORT-UID:0003TL` | No executed UID0003TL report found; matches are the active B011 report/goal and supervisor audit material. |
| `0003TL` | Relevant executed leads: B001 batch6/batch7 MapPane split, B004 MapPane empty-emitter family, B014/B012 PaletteLib, B003 suffix reports. |
| `0x00510960` | Relevant executed leads: B001 batch5/batch6 split/route reports, B004 empty-emitter, B014/B012 PaletteLib, B003 suffix reports. |
| `0x00511347` | Relevant executed leads: B001 batch6/batch7 padding/range notes, B004 empty-emitter, B014 PaletteLib context. |
| `MapPaneHandleMapInfoTileRegionPacket` | Relevant executed leads: B001 batch6/batch7, B004 empty-emitter, B014 PaletteLib, B003 suffix reports. |
| `MapInfoTileRegion` | Same direct context set; no standalone executed UID0003TL source-quality report. |
| `MapPane` | Broad context; opened only matching MapPane packet/file/class/source-family reports. |
| `MapServerPacketOpcode` | Relevant dispatcher/enum support: B015 UID00037T dispatcher, B001 split batches, B002/B004 MapPane class/file reports. |
| `opcode 0x06` | No direct UID0003TL executed report; relevant route proof in B001 split report and current docs, plus unrelated LivingObjectPane raw waypoint hit. |
| `0x00507ffa` | Relevant: B001 batch5/batch6, B004 context, B003 suffix reports. |
| `sub_510960` | Relevant: B001 split reports, B004 context, B003 suffix reports. |
| `MapPaneRefreshStaticObjectTileRegion` | Relevant: B001 batch5/batch6, B002 movement/object update, B005 tile-grid, B010/ObjectList context. |
| `PaletteLibPaletteFilterHelpers` | Relevant: B014/B012 UID0001E9 PaletteLib reports, B005 Surface/MapPane tile-grid, B001 PaletteCollection lead. |
| `sub_50D8E0` | Relevant: B014/B012 UID0001E9, B005 tile-grid, B001 batch6. |
| `00007Q` | Broad MapPane class context; opened relevant MapPane class/file and packet split reports. |
| `0000L3` | Broad MapPane file context; opened B004 MapPane and current file docs. |
| `0001AW` | Relevant: B001 split batches, B004 aggregate conversion, B015 dispatcher support. |
| `0001SO` | Relevant: enum/dispatcher support in B015, B001/B002/B004 reports. |
| `0003TJ` | Relevant: B001 batch5/batch6, B005 tile-grid, B002 movement/object update, B010/ObjectList context. |
| `0001E9` | Relevant: B014/B012 PaletteLib reports, B005 Surface, B001 PaletteCollection lead. |

- Old reports opened as matching leads: B001 `0001AW-mappane-packet-source-split-continuation-batch5.md`, B001 `0001AW-mappane-packet-source-split-continuation-batch6.md`, B001 `0001AW-mappane-packet-source-split-continuation-batch7.md`, B004 `0000L3-MapPane-empty-emitter-family-source-quality.md`, B014 `0001E9-PaletteLibPaletteFilterHelpers-source-quality.md`, B012 `0001E9-PaletteLibPaletteFilterHelpers-source-quality.md`, B005 `00037Y-MapPaneTileObjectGridRenderCore-source-quality.md`, B002 `0002QG-0002QL-0002QM-0002QN-MapPaneMovementObjectUpdate-source-quality.md`, B015 `00037T-MapPanePacketDispatcher-source-quality.md`, B003 `0003P9-SharedEpfSuffixString-current-source-routing.md`, and B003 `0003JG-SharedMapPaletteSuffixString-current-no-owner-research.md`.
- Reports with lifecycle caveat: B003 suffix reports `0003P9` and `0003JG` carry `REPORT-VALIDATION-STATUS: needs-revalidation`; they were used only as address/use-site leads and were rechecked against current MCP before use.
- Negative checks: no xrefs to `0x00511350`; no function object at `0x00510958`, `0x00511347`, or `0x00511350`; no evidence to reassign the target to PaletteLib, ObjectList, StaticObjectPane, suffix literals, or the protocol enum; no executed UID0003TL report counted in generated tracker.
- Failed or skipped checks: no MCP availability failure occurred. `execute_report`, registry lifecycle commands, manual archive/report moves, generated edits, and coverage edits were intentionally skipped by role boundary. Scoped validators run during callback are recorded under `Validator Results`.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C001 | UID0003TL remains exact range `0x00510960-0x00511347`; adjacent `0xcc` ranges are padding/raw successor, not part of the handler. | high | MCP `lookup_funcs`, `get_bytes`, `xrefs_to`; `by-memory/-ignored.md` | Target Address Range / IDA MCP Evidence; ignored ledger note | incorporate | applied/verified in target; `-ignored` already contained padding coverage, no edit needed |
| C002 | Dispatcher route is opcode/case `0x06` at `0x00507ff3 -> 0x00507ffa`. | high | MCP bounded `search_text`, dispatcher `disasm` case 6, `xrefs_to 0x00510960` | Target Status / IDA MCP Evidence; MapServerPacketOpcode evidence note | incorporate | applied/verified in target, enum, class, file, and packet aggregate with session `b001-0001I5` |
| C003 | Packet source shape is a variable-length `MapInfoTileRegionPacketView`: opcode byte, flags byte, optional length-prefixed map/resource strings, optional mode byte, tile rectangle, then three packet words per tile. | medium-high | MCP decompile addresses `0x5109f1-0x510bb6` and `0x510edb-0x5110a0`; packet helper docs | Target Behavior / Score Rationale / C++ block | incorporate | applied/verified in target behavior and formal C++ |
| C004 | Map/resource strings are converted to `m_mapName` and `m_mapResourceName`; `.EPF` bytes at `0x0061a44c` and `.PAL` at `0x0061ea24` are use-site suffixes. | high | MCP decompile, `get_bytes`, `get_string`, `xrefs_to` suffix addresses | Target Behavior / IDA MCP Evidence; suffix docs as support leads | incorporate | applied/verified in target behavior/evidence; suffix pages left as support-only leads |
| C005 | `this+276` is best documented as `m_mapResourceMode`; changed values call `sub_5040A0`. | medium-high | MCP decompile mode branch and support field table | Target Behavior; MapPane class/layout support | incorporate | applied/verified in target; class/layout support already carried field candidate |
| C006 | Tile bounds are clipped through `sub_4B7C50` / `sub_4B7CC0` before tile writes and static-object refresh. | high | MCP decompile both branches | Target Behavior / C++ block | incorporate | applied/verified in target behavior and formal C++ |
| C007 | The live MapPane tile buffer record is a six-byte `MapPaneTileRecord` with `groundTileId`, `flags`, and `staticObjectId`. | high | MCP decompile tile loop; UID0003TJ reads offset `+4`; UID0004HP current doc | Target Behavior / support type doc | incorporate | applied/verified in target and UID0004HP support type with session `b001-0001I5` |
| C008 | Existing [UID:0001V3] `MapTileRecord` must not be reused because it is a four-byte MapTileImageLib resource record. | high | Current UID0004HP doc and support docs | Target Behavior / support type doc | incorporate | applied/verified in target and UID0004HP support type |
| C009 | Changed ground tile id calls `sub_50D8E0` at `0x00510d6f` and `0x0051125f`, best named `MapPane::DrawTileAt`. | high | MCP decompile and `xrefs_to 0x0050d8e0` | Target Behavior / helper-name notes | incorporate | applied/verified in target behavior/evidence and support route notes |
| C010 | PaletteLib filter toggling belongs inside `sub_50D8E0`; UID0003TL should mention it as support-only dependency. | high | MCP `analyze_function(0x0050d8e0)`, B014/B012 UID0001E9 reports | Target IDA MCP Evidence; PaletteLib support remains owner | incorporate | applied/verified in target as support-only dependency; PaletteLib owner doc unchanged |
| C011 | UID0003TL calls UID0003TJ at `0x00510e28` and `0x00511318`; source-facing call should be `RefreshStaticObjectTileRegion(refreshBounds)`. | high | MCP `xrefs_to 0x0050f130`, target decompile, UID0003TJ analysis | Target Behavior; UID0003TJ support note | incorporate | applied/verified in target and UID0003TJ support note with session `b001-0001I5` |
| C012 | `sub_505370` should be treated as `MapPane::GetExtendedVisibleTileBounds(MapRect *outBounds) const`. | high | Current UID000423 doc; target decompile callsites | Target C++ block / helper references | already-present | verified present in target formal C++ and cross-references; UID000423 support doc unchanged |
| C013 | `sub_575480` and `sub_575730` map to scalar and cursor `PacketBufferReadUInt16BE` helper docs. | high | Current UID0003YK/UID0003YN docs; target decompile | Target C++ block / cross-references | already-present | verified present in target formal C++ and cross-references; helper docs unchanged |
| C014 | `sub_516220` maps to `MemoryMan::MemmoveWrapper`; target string copies should reference it. | high | Current UID0001BH doc; target decompile | Target C++ block / cross-references | already-present | verified present in target formal C++ and cross-references; UID0001BH unchanged |
| C015 | Direct owner/emitter stays [UID:00007Q] `MapPane`; file route stays [UID:0000L3] `MapPane`. | high | Dispatcher receiver setup, field mutations, target/support docs | Metadata and owner sections | incorporate | applied/verified in target metadata and class/file support docs |
| C016 | StaticObjectPane, ObjectList, PaletteLib, protocol enum, suffix literals, and raw `0x00511350` are dependency/support contexts, not owners. | high | MCP xrefs/callees, support docs, old reports | Rejected-owner/negative evidence sections | incorporate | applied/verified in target rejected-owner/score sections and support docs |
| C017 | Formal first-draft C++ is eligible because current score/emitter gate is satisfied and all material blockers have implementation-ready source names or documented inferred-name caveats. | medium-high | by-structure C++ gate, MCP-backed source-shape resolution, current target route | Target `RECONSTRUCTION_CPP CODE` block | incorporate | applied/verified: target formal C++ populated; generated MapPane.cpp refreshed to validator command `000000007667` |

## Positive Evidence Summary

- Direct IDA/MCP facts support the chosen range and route: `sub_510960` starts at `0x00510960`, size `0x9e7`; `0x00511347` and `0x00511350` are not functions; only one code xref reaches the target at dispatcher call `0x00507ffa`; disassembly labels the surrounding target as jump-table case `6`.
- Direct IDA/MCP decompilation supports the behavior: optional strings, mode byte, rectangle clipping, tile-buffer writes, changed-tile redraw calls, refresh-bound computation, UID0003TJ calls, and deferred surface dirty flags all occur inside one MapPane method body.
- Current by-* support corroborates the owner/emitter route: MapPane class/file docs own the packet handler family, UID0001AW is a non-emitting split/container, UID0001SO indexes opcode `0x06`, UID0003TJ owns static-object reconciliation, UID0001E9 owns PaletteLib filter helpers, and UID0004HP documents the six-byte tile record.
- The strongest inference chain is sufficient for first-draft C++: binary evidence proves behavior and layout; support docs provide stable helper names; unresolved original spellings are source-facing inferred names with a `90/90` cap rather than blockers.

## IDA MCP Facts

- Session: `b001-0001I5`; `server_health` ok, Hex-Rays ready, strings cache ready.
- Function facts: `sub_507C90` at `0x00507c90`, size `0x1176`; `sub_510960` at `0x00510960`, size `0x9e7`; `sub_50F130` at `0x0050f130`, size `0x13d`; `sub_50D8E0` at `0x0050d8e0`, size `0x10b`; `sub_543F60` at `0x00543f60`, size `0x10`.
- Padding/data facts: `0x00510958-0x00510960` is eight `0xcc` bytes; `0x00511347-0x00511350` is nine `0xcc` bytes; `0x00511350` begins raw prologue-shaped bytes but is not a function and has zero xrefs.
- Xref facts: `xrefs_to 0x00510960` has exactly one code xref at `0x00507ffa`; `xrefs_to 0x0050f130` has four code refs, including UID0003TL refs at `0x00510e28` and `0x00511318`; `xrefs_to 0x0050d8e0` includes UID0003TL refs at `0x00510d6f` and `0x0051125f`; `xrefs_to 0x00543f60` includes PaletteLib toggles inside `sub_50D8E0` at `0x0050d94f` and `0x0050d99f`.
- String/suffix facts: `get_bytes(0x0061a44c,12)` gives UTF-16 `.EPF` bytes despite string-cache truncation to `.E`; `get_bytes/get_string(0x0061ea24)` gives `.PAL`; both suffix literals have direct refs from `sub_510960`.
- Negative IDA facts: no xrefs to `0x00511350`; no target evidence for PaletteLib, ObjectList, StaticObjectPane, suffix literals, or MapServerPacketOpcode as canonical owner of this packet handler.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x005104d0-0x00510958` | [UID:0003TK] `MapPaneHandleEffectMapStatePacket` | Prior exact sibling packet handler | true | [UID:00007Q] MapPane | current support | Ends before eight-byte padding. |
| `0x00510958-0x00510960` | ignored ledger | Alignment padding | false | [UID:0001AW] / [UID:0003TK]/[UID:0003TL] context | 100/strong | Eight `0xcc` bytes. |
| `0x00510960-0x00511347` | [UID:0003TL] target | Opcode `0x06` map-info/tile-region handler | true | [UID:00007Q] MapPane | recommend/current `90/90` | Source-bearing exact method. |
| `0x00511347-0x00511350` | ignored ledger | Alignment padding | false | [UID:0003TL] / [UID:0001AW] context | 100/strong | Nine `0xcc` bytes. |
| `0x00511350` raw body | no UID target here | Raw prologue-shaped no-function/no-xref successor | unresolved outside scope | none | not scored here | Not part of UID0003TL. |
| `0x00511420` / `0x00511430` | modeled true-return stubs | Adjacent no-caller sibling stubs | out of scope | MapPane packet family | support only | Not part of UID0003TL. |
| `0x00511440-0x00511703` | [UID:0003TM] | Next source-bearing packet handler | true | [UID:00007Q] MapPane | support only | Separate function starts after ignored/stub regions. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00507ff3` | `loc_507FF3`; `jumptable 00507CE2 case 6` | Dispatcher case for opcode `0x06`. |
| `0x00507ffa` | `call sub_510960` from `sub_507C90` | Only direct code xref to UID0003TL. |
| `0x00510d6f` | call `sub_50D8E0` from target first branch | Changed ground tile redraw. |
| `0x0051125f` | call `sub_50D8E0` from target second branch | Changed ground tile redraw. |
| `0x00510e28` | call `sub_50F130` from target first branch | Static-object tile-region reconciliation. |
| `0x00511318` | call `sub_50F130` from target second branch | Static-object tile-region reconciliation. |
| `0x0050d94f` / `0x0050d99f` | calls `sub_543F60` inside `sub_50D8E0` | PaletteLib filter toggle belongs to draw helper. |
| `0x0061a44c` | refs at `0x00510b2f` and `0x00511019` inside target | `.EPF` suffix use site. |
| `0x0061ea24` | refs at `0x00510b57` and `0x00511041` inside target | `.PAL` suffix use site. |

## Documentation Evidence And IDA Status

- Current target doc already contains the intended final state from an earlier unexecuted B011 callback-era edit: `90/90`, formal C++, UID0004HP support, and detailed IDA evidence. This report repair treats that as current doc state to verify or preserve during callback, not as lifecycle proof.
- Current MapPane class/file docs include UID0003TL route notes, field candidates, and formal C++ route text. The callback updated the UID0003TL B011 provenance to current session `b001-0001I5` while leaving unrelated B015 dispatcher-session evidence unchanged.
- Current generated reports show UID0003TL as coded and tracker reports `0`, so generated output reflects by-* content while report lifecycle remains unexecuted.
- Old B001/B004 reports explain the previous blank-C++/empty-emitter state and why packet/tile names were blockers then. Current MCP reanalysis resolves those blockers.
- Old B014/B012 PaletteLib reports support `sub_50D8E0` as a PaletteLib-filter consumer, but PaletteLib remains a callee/dependency owner only.

## Ranked Ownership Analysis

### 1. [UID:00007Q] MapPane

- Evidence for: dispatcher case loads the MapPane receiver (`ecx = [esi-0A0h]`), target mutates MapPane fields and tile buffer, calls MapPane dirty/static-object helpers, and lives inside the MapPane packet-handler family.
- Evidence against: target calls ObjectList/StaticObjectPane/PaletteLib-adjacent helpers, but those are downstream dependencies after MapPane state mutation.
- Decision: direct canonical owner and emitter should remain [UID:00007Q] `MapPane`.

### 2. [UID:0000L3] MapPane file

- Evidence for: file route is the generated source root for MapPane methods and current support docs route UID0003TL through `MapPane.cpp`.
- Evidence against: too broad as the direct semantic owner of a class method; class UID is narrower and already clears the gate.
- Decision: keep as file/source route through the class, not as direct canonical owner.

### 3. PaletteLib / ObjectList / StaticObjectPane / protocol enum / suffix literals

- Evidence for: target uses PaletteLib indirectly through `DrawTileAt`; UID0003TJ reconciles StaticObjectPane objects through ObjectList; opcode enum indexes route; suffix literals are referenced by the resource-name branch.
- Evidence against: none of these candidates receives the dispatcher packet as `this`; none owns the MapPane fields/tile buffer; each is a callee/support/source-use context.
- Decision: rejected as canonical owner/emitter candidates for UID0003TL.

### Proposed new file/grouping, if applicable

- No new source file/grouping is recommended. UID0003TL should emit as a `MapPane` method in the existing MapPane source route.

## Source Placement

- Recommended source file/class placement: `MapPane::HandleMapInfoTileRegionPacket(const unsigned char *packet)` emitted through [UID:00007Q] `MapPane` into [UID:0000L3] `MapPane.cpp`.
- Why this placement fits: the handler belongs to the map-scoped packet switch, reads an inbound map packet, updates MapPane map/resource/tile state, and calls MapPane-local helpers.
- Rejected placements: PaletteLib owns only filter state; StaticObjectPane owns constructed pane behavior; ObjectList owns collection operations; MapServerPacketOpcode owns only working constants/indexing; suffix literal pages are pooled data/use-site evidence; raw `0x00511350` is separate no-route body.
- Remaining placement uncertainty: exact original spellings for local helper/type/member names remain inferred, but placement is not blocked.

## Range / Split / Padding / Reclassification Analysis

- Exact range/boundary facts: `sub_510960` starts at `0x00510960`, size `0x9e7`, and ends at `0x00511347`. Preceding and following bytes are `0xcc` padding. `0x00511350` is raw prologue-shaped but not a function and has zero xrefs.
- Children/subranges to create, repair, merge, leave ignored, or leave no-owner: no UID0003TL split/merge is recommended. Keep ignored padding `0x00510958-0x00510960` and `0x00511347-0x00511350`. Leave raw `0x00511350` outside this target for separate no-route review.
- Padding/table/data/code distinctions: the padding bytes are compiler/linker alignment; `0x00511350` is not padding bytes but is also not part of this function. It should not extend UID0003TL.
- Parent/container impact: [UID:0001AW] remains a non-emitting MapPane packet-handler split/container; exact source-bearing child UID0003TL carries the method body.

## Negative Evidence Summary

- `xrefs_to 0x00511350` returns zero xrefs; raw successor bytes do not justify extending the target range.
- `lookup_funcs` does not model `0x00510958`, `0x00511347`, or `0x00511350` as function starts; no split should start or end inside the current UID0003TL body.
- PaletteLib xrefs occur inside the draw helper `sub_50D8E0`, not as ownership of the packet parser.
- StaticObjectPane and ObjectList are consumer/dependency contexts inside UID0003TJ, not owners of the packet handler.
- The protocol enum and packet-name/support docs identify opcode `0x06`, but route labels are not semantic ownership proof.
- B003 suffix reports carrying `needs-revalidation` cannot be counted as accepted coverage; current MCP rechecked the literal bytes and refs before any suffix claim was used.
- Broad generated state already showing coded output is not Gate 1 evidence for this report; the report must stand on its own text.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing names/types for documentation and first-draft C++: `MapPane::HandleMapInfoTileRegionPacket`, `MapInfoTileRegionPacketView`, `MapInfoTileRegionPacketFlags`, `MapPaneTileRecord`, `m_mapResourceMode`, `m_hasRenderableMap`, `m_mapWidthTiles`, `m_mapHeightTiles`, `m_mapTileRecords`, `m_refreshWholeVisibleMap`, `m_mapName`, `m_mapNameLength`, `m_mapResourceName`, `m_mapResourceNameLength`, `DrawTileAt`, `GetExtendedVisibleTileBounds`, and `RefreshStaticObjectTileRegion`.
- Evidence for names/types: receiver route, field offsets, helper docs, target decompilation, support type UID0004HP, packet-buffer helper docs, and MapPane class/file source-shape consistency.
- Items intentionally left inferred: exact original symbols for packet view, tile record, some MapPane fields, and deferred surface refresh helper remain unrecovered; document them as inferred source-facing names rather than IDA labels.
- IDA DB edits: no IDA rename/type/comment writes are requested or performed by B011 in either the research repair or implementation callback pass.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. The target is `RECONSTRUCTABLE:TRUE`, has confirmed nonblank `EMITTER_UIDS:00007Q` routing to MapPane output, current/recommended combined score is above the active code gate, and current MCP resolves route/range/source-shape blockers.
- Recommended code: use this exact formal `RECONSTRUCTION_CPP CODE` insertion text after supervisor acceptance. If current by-* docs remain in their current state, the implementation callback can verify this block is already present and update only stale session provenance as needed.

```cpp
namespace
{
    enum MapInfoTileRegionPacketFlags
    {
        kMapInfoTileRegionHasMapName = 0x01,
        kMapInfoTileRegionHasResourceName = 0x02,
        kMapInfoTileRegionHasResourceMode = 0x04
    };

    struct MapInfoTileRegionPacketView
    {
        explicit MapInfoTileRegionPacketView(const unsigned char *packetBytes)
            : bytes(packetBytes), cursor(1)
        {
        }

        unsigned char ReadByte()
        {
            return bytes[cursor++];
        }

        unsigned short ReadUInt16()
        {
            unsigned short value = PacketBufferReadUInt16BE(bytes + cursor);
            cursor += 2;
            return value;
        }

        unsigned short ReadTileWord()
        {
            return PacketBufferReadUInt16BE(bytes, &cursor);
        }

        int ReadAnsiString(char *buffer, int bufferCount)
        {
            int byteCount = ReadByte();
            int copyCount = byteCount;
            if (copyCount >= bufferCount)
                copyCount = bufferCount - 1;

            GetMemoryMan()->MemmoveWrapper(buffer, bytes + cursor, copyCount);
            buffer[copyCount] = '\0';
            cursor += byteCount;
            return copyCount;
        }

        const unsigned char *bytes;
        int cursor;
    };
}

bool MapPane::HandleMapInfoTileRegionPacket(const unsigned char *packet)
{
    char mapNameBytes[256];
    char resourceNameBytes[256];
    wchar_t epfResourceName[260];
    wchar_t palResourceName[260];

    MapInfoTileRegionPacketView packetView(packet);
    unsigned char oldResourceMode = m_mapResourceMode;
    unsigned char flags = packetView.ReadByte();

    m_mapNameLength = 0;
    m_mapResourceNameLength = 0;
    m_mapResourceMode = 0;

    if ((flags & kMapInfoTileRegionHasMapName) != 0)
    {
        int mapNameLength = packetView.ReadAnsiString(mapNameBytes, sizeof(mapNameBytes));
        m_mapNameLength = static_cast<unsigned char>(
            MultiByteToWideChar(CP_ACP, 0, mapNameBytes, mapNameLength, m_mapName, 256));
        m_mapName[m_mapNameLength] = L'\0';
    }

    if ((flags & kMapInfoTileRegionHasResourceName) != 0)
    {
        int resourceNameLength = packetView.ReadAnsiString(resourceNameBytes, sizeof(resourceNameBytes));
        m_mapResourceNameLength = static_cast<unsigned char>(
            MultiByteToWideChar(CP_ACP, 0, resourceNameBytes, resourceNameLength, m_mapResourceName, 256));
        m_mapResourceName[m_mapResourceNameLength] = L'\0';

        wcscpy_s(epfResourceName, _countof(epfResourceName), m_mapResourceName);
        wcscat_s(epfResourceName, _countof(epfResourceName), L".EPF");
        wcscpy_s(palResourceName, _countof(palResourceName), m_mapResourceName);
        wcscat_s(palResourceName, _countof(palResourceName), L".PAL");
    }

    if ((flags & kMapInfoTileRegionHasResourceMode) != 0)
        m_mapResourceMode = packetView.ReadByte();

    if (m_mapResourceMode != oldResourceMode)
        ResetMapResourceStateForModeChange();

    int originTileX = packetView.ReadUInt16();
    int originTileY = packetView.ReadUInt16();
    int tileWidth = packetView.ReadByte();
    int tileHeight = packetView.ReadByte();

    MapRect packetBounds;
    SetRectBounds(&packetBounds, originTileX, originTileY,
        originTileX + tileWidth, originTileY + tileHeight);

    MapRect mapBounds;
    SetRectBounds(&mapBounds, 0, 0, m_mapWidthTiles, m_mapHeightTiles);

    MapRect clippedBounds = packetBounds;
    IntersectRectBounds(&clippedBounds, &mapBounds);

    for (int tileY = clippedBounds.top; tileY < clippedBounds.bottom; ++tileY)
    {
        for (int tileX = clippedBounds.left; tileX < clippedBounds.right; ++tileX)
        {
            MapPaneTileRecord &tile = m_mapTileRecords[tileX + tileY * m_mapWidthTiles];
            unsigned short oldGroundTileId = tile.groundTileId;

            tile.groundTileId = packetView.ReadTileWord();
            unsigned short tileFlags = packetView.ReadTileWord();
            tile.flags = static_cast<unsigned short>((tile.flags & ~1) | (tileFlags & 1));
            tile.staticObjectId = packetView.ReadTileWord();

            if (tile.groundTileId != oldGroundTileId)
                DrawTileAt(tileX, tileY, true);
        }
    }

    MapRect refreshBounds;
    if (m_refreshWholeVisibleMap)
    {
        m_refreshWholeVisibleMap = false;
        GetExtendedVisibleTileBounds(&refreshBounds);
    }
    else if (m_hasRenderableMap)
    {
        SetRectBounds(&refreshBounds, 0, 0, 0, 0);
    }
    else
    {
        GetExtendedVisibleTileBounds(&refreshBounds);
        IntersectRectBounds(&refreshBounds, &clippedBounds);
    }

    RefreshStaticObjectTileRegion(refreshBounds);

    if (g_useEpfAssets)
        RefreshDeferredMapSurfacesForTileRegion();

    return true;
}
```

- Reason it preserves exact original behavior: it preserves the cursor order, optional string/mode flags, big-endian tile reads, clipping semantics, tile-word update policy, dirty redraw calls, refresh-bound selection, static-object reconciliation, deferred surface flags, and success return observed in MCP decompilation.
- Reason it matches plausible original source shape: it expresses the packet as a small cursor/view over a variable-length wire format, keeps MapPane state as member fields, uses existing packet-buffer and MemoryMan helper names, and avoids decompiler labels or artificial fixed structs for variable-offset payload data.
- Inferred names/types/fields used instead of IDA labels: listed in `IDA Rename / Type / Comment Recommendations`.
- Naming/coding convention used: late-1990s/mid-2000s C++ class-method style already used in current MapPane/MemoryMan/PaletteLib docs, with `m_` member fields and small local helper types.
- Reason code should remain blank, if applicable: not applicable for this target after current research.
- Exact no-code proof: not applicable.

## Final Recommendation

- Exact changes recommended: keep UID0003TL exact range, owner/emitter, reconstructable state, and MapPane source placement; record the current MCP session facts; retain/insert formal first-draft C++; document `MapInfoTileRegionPacketView`, `MapPaneTileRecord`, field offsets, helper names, route proof, padding proof, PaletteLib support-only disposition, and rejected owners.
- Exact parent assignments recommended: canonical owner [UID:00007Q] `MapPane`; emitter [UID:00007Q]; file route [UID:0000L3].
- Exact items left no-owner/non-emitting and why: none inside UID0003TL. Raw `0x00511350` remains outside this target and should not be folded into UID0003TL.
- Exact future work outside assignment scope: broader MapPane packet payload final names and dispatcher-case audits can continue separately; exact original spellings for inferred MapPane fields and helper names may improve with later class-layout work, but they no longer block UID0003TL first-draft source.

## Recommended Target Doc Changes

- Target path: `by-memory/0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket.md`.
- Metadata/score/owner/emitter/reconstructable/C++ changes: set or confirm `COMPLETION:90`, `CONFIDENCE:90`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, blank emitter position, and formal C++ block matching this report.
- Exact report facts to incorporate or confirm:
  - Current MCP session `b001-0001I5` health/session facts.
  - Exact range `0x00510960-0x00511347`, size `0x9e7`, preceding/following `0xcc` padding, and zero xrefs to `0x00511350`.
  - Dispatcher route `loc_507FF3` / case `6` / call `0x00507ffa`.
  - Variable-length `MapInfoTileRegionPacketView` layout and packet flag meanings.
  - Map/resource string conversion and `.EPF`/`.PAL` suffix byte evidence.
  - MapPane field offsets and inferred source-facing names from this report.
  - Six-byte `MapPaneTileRecord` writes and non-reuse of [UID:0001V3] `MapTileRecord`.
  - Dirty redraw `DrawTileAt`, extended visible bounds, and UID0003TJ static-object refresh callsites.
  - PaletteLib dependency is inside `sub_50D8E0` and support-only for UID0003TL.
- Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: B001/B004 blank-C++ state is historical/superseded; StaticObjectPane, ObjectList, PaletteLib, protocol enum, suffix literals, and raw `0x00511350` are rejected owners/source extensions.

## Recommended Support Doc Changes

- `by-class/MapPane.md`: confirm/add current session `b001-0001I5` evidence for UID0003TL opcode case `0x06`, MapPane receiver route, map/resource string updates, tile-buffer mutation, dirty redraw, static-object reconciliation, and field-name candidates.
- `by-file/MapPane.md`: confirm/add current UID0003TL formal first-draft `MapPane::HandleMapInfoTileRegionPacket(const unsigned char *packet)` route and note that the old empty-emitter wording is superseded.
- `by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md`: confirm/update the UID0003TL child row to `90/90`, formal first-draft state, and current route proof `loc_507FF3` case `6` -> call `0x00507ffa`.
- `by-type/by-enum/MapServerPacketOpcode.md`: confirm/add evidence note for opcode `0x06` from current dispatcher disassembly. No enum score or formal enum C++ change is required.
- `by-type/by-struct/MapPaneLayout.md`: confirm/add offset rows/aliases for `m_mapResourceMode`, `m_hasRenderableMap`, `m_mapWidthTiles`, `m_mapHeightTiles`, `m_mapTileRecords`, `m_refreshWholeVisibleMap`, `m_mapName`, `m_mapNameLength`, `m_mapResourceName`, `m_mapResourceNameLength`, and deferred dirty flags.
- `by-type/by-struct/MapPaneTileRecord.md`: confirm/create this support type as the six-byte MapPane tile-buffer record. If current UID0004HP remains present, verify it already contains the three-field formal struct and non-reuse note for [UID:0001V3] `MapTileRecord`.
- `by-memory/0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md`: confirm/support the UID0003TL callsites `0x00510e28` and `0x00511318`, static-object id at tile-record byte offset `+4`, and source-facing `MapPane::RefreshStaticObjectTileRegion(const MapRect &tileBounds)` signature.
- `by-memory/0x00575480-0x00575574.PacketBufferScalarBigEndianReadHelpers.md` [UID:0003YK], `by-memory/0x00575710-0x005757c8.PacketBufferCursorReadBigEndianHelpers.md` [UID:0003YN], `by-memory/0x00516220-0x00516238.MemmoveWrapper.md` [UID:0001BH], and `by-memory/0x00505370-0x005053e4.MapPaneGetExtendedVisibleTileBounds.md` [UID:000423]: no content change required unless adding caller/cross-reference notes; each already supplies the source-facing helper needed by the target.
- `by-memory/0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers.md`: no required content change. It already owns `PaletteLib::SetPaletteFilterActive`; UID0003TL should only cite it as support evidence through `sub_50D8E0`.
- `by-memory/-ignored.md`: no required content change unless callback wants to add current `b001-0001I5` reconfirmation for existing padding rows.
- Shared suffix pages for `.EPF` and `.PAL`: no required change for UID0003TL. Existing B003 suffix reports with `needs-revalidation` should remain leads until separately repaired.

## Score And Metadata Recommendation

- Assignment baseline score/metadata: `86/89`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, blank C++.
- Current by-* doc score/metadata read during this repair: `90/90`, same owner/reconstructable/emitter fields, formal C++ present.
- Recommended score/metadata: `90/90`, same owner/reconstructable/emitter fields, formal C++ populated.
- Reason higher than assignment baseline: current MCP directly verifies active IDB health, dispatcher case `0x06`, one xref route, exact function size, adjacent padding, zero xrefs to raw successor `0x00511350`, suffix byte/ref facts, two tile-writing branches, dirty helper calls, PaletteLib support-only path, UID0003TJ callsites, best-defensible source-shape names, support type `MapPaneTileRecord`, and formal first-draft C++.
- Reason not higher: `90/90` is the appropriate first-draft ceiling because several names remain inferred rather than original-symbol proven: `MapInfoTileRegionPacketView`, `MapPaneTileRecord`, `m_hasRenderableMap`, deferred surface refresh flags, and `RefreshDeferredMapSurfacesForTileRegion`.
- Score-improvement attempt and result:
  - Range/padding blocker: resolved with `lookup_funcs`, `get_bytes`, and `xrefs_to`.
  - Dispatcher/opcode blocker: resolved with bounded `search_text` and dispatcher `disasm`.
  - Packet payload/map-name/palette/resource blocker: resolved to `MapInfoTileRegionPacketView` plus exact variable-length field order.
  - Tile rectangle/descriptor/dirty/static-object blocker: resolved to `MapPaneTileRecord`, helper names, and exact support pages.
  - PaletteLib dependency blocker: resolved as support-only through `sub_50D8E0`.
  - Owner/emitter confusion: resolved in favor of MapPane.
  - First-draft C++ blocker: resolved by supplying exact formal insertion text.
- Metadata fields to leave unchanged: `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, blank emitter position.

## Open Questions With Attempted Resolution

- No open question remains as a Gate 1 source-quality blocker. Remaining exact original spellings are explicitly documented inferred-name caveats with a `90/90` cap.
- Packet struct/type: current decompilation, dispatcher route, packet reader helper callees, opcode enum page, and prior B001/B004 reports were checked. Resolution: do not use a fixed packed packet struct; use `MapInfoTileRegionPacketView` over `const unsigned char *packet`.
- MapPane field names: MapPane class/file docs, target decompilation, UID0003TJ, UID00037Y, and MapPaneLayout were checked. Resolution: use the field-name table in this report as source-facing candidates; exact original spellings remain inferred, not blocking.
- Six-byte tile record: target write loop, UID0003TJ consumer, existing UID0004HP doc, and [UID:0001V3] were checked. Resolution: use/confirm `MapPaneTileRecord`; do not reuse `MapTileRecord`.
- Dirty/helper naming: target calls, UID000423, UID0003TJ, UID0001E9, and `analyze_function(0x0050d8e0)` were checked. Resolution: `sub_50D8E0` is MapPane `DrawTileAt`; UID0001E9 owns PaletteLib helper implementation only.
- Raw `0x00511350`: `lookup_funcs`, `xrefs_to`, and bytes were checked. Resolution: no split or merge into UID0003TL.
- Current by-* docs modified/verified in callback: treated as implementation evidence for supervisor Gate 2/execute handling, not as a substitute for this report's standalone Gate 1 content.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Not applicable. No manual `-coverage-report.md` or supervisor-owned tracker edit is recommended. Validator-owned generated tracker/coverage files should refresh from source by-* docs during normal scoped validation and eventual supervisor execution.

## Follow-Up Actions

- Supervisor Gate 1 action: audit this exact report artifact for required headings/content and either callback B011 for implementation verification/application or return exact repair notes.
- B011 callback action if accepted: verify or apply the target/support doc changes above, update checklist rows to checked/already-present/applied with proof, run scoped validators for changed by-* docs, and stop at `READY_FOR_SUPERVISOR_EXECUTE`.
- Supervisor final lifecycle action after Gate 2 only: run `execute_report` for B011/UID0003TL if Gate 1 and Gate 2 pass. B011 must not run it.

## Confidence

- Recommendation confidence: high.
- Score confidence: high for `90/90` as a first-draft source-quality state, with cap preserved for inferred names.
- Remaining uncertainty: exact original source spellings for several fields/helper/types remain unrecovered, but no range, owner, route, packet layout, support dependency, or C++ eligibility blocker remains.

## Validator Results

- Implementation callback scoped validators run from `source-3/project-documentation` after by-* edits:

| File | Command | command_id | command_timestamp | Exit | ok | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| `by-memory/0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket.md` | `python .\tools\validator.py --mode file --file by-memory/0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket.md --apply --queue-timeout 240` | `000000007661` | `2026-07-06T18:59:52-04:00` | 0 | 1 | `missing_ref_uid:4`; projected stats update; generated refresh deferred |
| `by-class/MapPane.md` | `python .\tools\validator.py --mode file --file by-class/MapPane.md --apply --queue-timeout 240` | `000000007662` | `2026-07-06T19:00:07-04:00` | 0 | 1 | `missing_ref_uid:87`; stats row/projected stats update; generated refresh deferred |
| `by-file/MapPane.md` | `python .\tools\validator.py --mode file --file by-file/MapPane.md --apply --queue-timeout 240` | `000000007663` | `2026-07-06T19:00:09-04:00` | 0 | 1 | `missing_ref_uid:98`; stats row/projected stats update; generated refresh deferred |
| `by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md` | `python .\tools\validator.py --mode file --file by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md --apply --queue-timeout 240` | `000000007664` | `2026-07-06T19:00:11-04:00` | 0 | 1 | `missing_ref_uid:107`; projected stats update; generated refresh deferred |
| `by-type/by-enum/MapServerPacketOpcode.md` | `python .\tools\validator.py --mode file --file by-type/by-enum/MapServerPacketOpcode.md --apply --queue-timeout 240` | `000000007665` | `2026-07-06T19:00:18-04:00` | 0 | 1 | `missing_ref_uid:4`; stats row/projected stats update; generated refresh deferred |
| `by-type/by-struct/MapPaneTileRecord.md` | `python .\tools\validator.py --mode file --file by-type/by-struct/MapPaneTileRecord.md --apply --queue-timeout 240` | `000000007666` | `2026-07-06T19:00:26-04:00` | 0 | 1 | no `missing_ref_uid`; projected stats update; generated refresh deferred |
| `by-memory/0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md` | `python .\tools\validator.py --mode file --file by-memory/0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md --apply --queue-timeout 240` | `000000007667` | `2026-07-06T19:00:36-04:00` | 0 | 1 | `missing_ref_uid:3`; projected stats update; generated refresh deferred |

- Generated refresh check: `python .\tools\validator.py --queue-status` returned command `000000007668` at `2026-07-06T19:00:52-04:00` with one generated-refresh job processing, then command `000000007669` at `2026-07-06T19:01:04-04:00` with zero queued/processing jobs.
- Generated freshness: `auto-generated/NexusTK/map/MapPane.cpp` and `auto-generated/-ag-memory-coverage.md` headers both read `validator-command-id: 000000007667`, `validator-refreshed-at: 2026-07-06T19:00:36-04:00`, `validator-refresh-source: deferred-generated-refresh`.
- Validator-generated side effects observed: projected stats and selected stats rows in `project-level/-auto-completion-stats.md`; generated MapPane.cpp and memory coverage refresh. No generated, coverage, validator state, lifecycle archive, or supervisor-ledger file was manually edited.
- Unresolved validator diagnostics: existing `missing_ref_uid` diagnostics remained on several docs; B011 did not run registry lifecycle commands or edit validator state.

## Changed Files

- Created: none.
- Modified in this implementation callback: `tools/leaser/Agents/Agent-B011/research/0003TL-MapPaneHandleMapInfoTileRegionPacket-source-quality.md`.
- By-* docs modified in this implementation callback:
  - `by-memory/0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket.md`
  - `by-class/MapPane.md`
  - `by-file/MapPane.md`
  - `by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md`
  - `by-type/by-enum/MapServerPacketOpcode.md`
  - `by-type/by-struct/MapPaneTileRecord.md`
  - `by-memory/0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md`
- Support docs verified but not modified because accepted facts were already present at report-level detail: `by-type/by-struct/MapPaneLayout.md`, helper cross-references UID0003YK/UID0003YN/UID0001BH/UID000423, PaletteLib owner context, and `by-memory/-ignored.md`.
- Generated/project-level side effects: scoped validators refreshed generated outputs and projected stats; no manual generated, coverage, validator-state, lifecycle-archive, supervisor-ledger, or report-archive edits were made.
- Report execution: not run. B agents must never run `tools/validator.py execute_report ... --apply`, dry-run/probing execute variants, registry lifecycle commands, manual report moves, or archive moves.

## Implementation Tracking Checklist

Implementation callback pass:
- [x] Supervisor Gate 1 callback received with accepted artifact SHA256 `A33E5545AFC27596BC3D44257E40C1EBA5203F4F6143AB52B633CC5BC7584933`; B011 did not run `execute_report`.
- [x] MCP mandatory check completed: `idb_list` found active IDB session `b001-0001I5`; `server_health(database=b001-0001I5)` returned `status:ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.
- [x] Target/support docs updated or confirmed: target UID0003TL; `by-class/MapPane.md`; `by-file/MapPane.md`; `by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md`; `by-type/by-enum/MapServerPacketOpcode.md`; `by-type/by-struct/MapPaneLayout.md`; `by-type/by-struct/MapPaneTileRecord.md`; `by-memory/0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md`; helper cross-references UID0003YK, UID0003YN, UID0001BH, and UID000423.
- [x] Claim And Incorporation Ledger updated with verification state for every accepted claim: C001-C017 are marked applied/verified or already-present/verified with destination proof.
- [x] Metadata/score confirmed: UID0003TL is `COMPLETION:90`, `CONFIDENCE:90`, owner `00007Q`, reconstructable `TRUE`, emitter `00007Q`, blank emitter position, and formal C++ populated.
- [x] Score-limiting blockers resolved/preserved: route/range, packet view, strings/suffixes, map-mode field, tile record, dirty/static-object helper shape, PaletteLib support-only path, owner confusion, first-draft C++ readiness, and inferred-name caveats are documented.
- [x] Owner/emitter/reconstructable changes confirmed: no owner/emitter/reconstructable change; retained [UID:00007Q] and `TRUE`.
- [x] Split/rename/new-child changes confirmed: no by-memory split/rename; support type `MapPaneTileRecord` continues as UID0004HP.
- [x] Source-placement/range/split/padding/reclassification confirmed: exact target range, ignored padding rows, no-route raw `0x00511350` exclusion, MapPane source placement, and inferred source-facing names preserved; no IDA DB writes requested.
- [x] First-draft C++ applied/verified: formal `MapPane::HandleMapInfoTileRegionPacket(const unsigned char *packet)` block remains in target and generated `auto-generated/NexusTK/map/MapPane.cpp` refreshed to command `000000007667`.
- [x] Third-party import directive not applicable: no static third-party source import used.
- [x] Exact target/support doc facts incorporated at report-level detail: route case 6, xrefs, bytes, packet view layout, field offsets/names, `MapPaneTileRecord` fields and non-reuse of [UID:0001V3], helper calls/names, formal C++ insertion, rejected owners, and score rationale.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: B001/B004 empty-emitter state superseded; no xrefs to `0x00511350`; suffix pages as use-site literals; PaletteLib support-only; StaticObjectPane/ObjectList dependencies only; old B003 suffix reports remain `needs-revalidation` leads only.
- [x] Wave2/Wave3 authority not used; generated C++/coverage used only as validator-owned current state.
- [x] Open questions closed or capped: no Gate 1 blocker remains; exact original spellings remain inferred-name caveats with `90/90` cap.
- [x] Scoped validators run for every changed by-* doc: commands `000000007661` through `000000007667`, all exit 0 with `ok:1`; generated-refresh queue idle at `000000007669`.
- [x] Generated report refresh/manual coverage state recorded: no manual coverage/tracker text; generated MapPane.cpp and memory coverage headers refreshed to `000000007667`; project stats side effects were validator-generated.
- [x] Leases released: B011 leased seven by-* docs for the immediate edit/validator batch and released them with `python .\tools\leaser\leaser.py B011 unlease`; post-release lease report showed no active B011 rows.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B011","command_id":"000000007721","destination_path":"executed-b-agent-research/B011/0003TL-MapPaneHandleMapInfoTileRegionPacket-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B011/research/0003TL-MapPaneHandleMapInfoTileRegionPacket-source-quality.md","timestamp":"2026-07-06T19:19:30-04:00","uid":"0003TL"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
