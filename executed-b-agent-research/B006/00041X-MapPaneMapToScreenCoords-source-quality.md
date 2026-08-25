** TARGET-REPORT-UID:00041X **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# UID00041X MapPaneMapToScreenCoords Source-Quality Report


## Finalized Report / Current Recommendation

- Current recommendation/status: implementation callback is complete for [UID:00041X][0x00505130-0x0050516a.MapPaneMapToScreenCoords](../../../by-memory/0x00505130-0x0050516a.MapPaneMapToScreenCoords.md). The target now remains a source-emitting `MapPane` method through [UID:00007Q][MapPane](../../../by-class/MapPane.md) at `COMPLETION:88`, `CONFIDENCE:91`, with MCP session `60724697` evidence incorporated.
- Final disposition: source-ready exact by-memory child. No split, merge, rename, owner change, emitter change, or formal C++ rewrite was applied. The existing formal `MapPane::MapToScreenCoords(MapPoint *point) const` block remains behavior-correct and source-shaped.
- Implemented action: updated the target evidence and score, preserved the existing formal C++ block unchanged, synced stale support wording that used the older `MapCoordsToScreen` alias where it directly referred to UID00041X, ran scoped validators for every changed by-* doc, and stopped without `execute_report`.
- Confidence: high for range, body, ownership, caller set, emitter route, and current C++; capped below final-audit quality because original symbol spelling and exact source type/member names remain inferred.

## Supporting Research

- Lifecycle/status notes: the original report-only pass is complete and supervisor Gate 1 passed; this current artifact records the completed implementation callback. B006 edited only the accepted target/support by-* docs and this report, ran scoped file validators, did not manually edit generated files or coverage reports, and did not run `execute_report`, lifecycle/probing variants, archive moves, registry commands, or supervisor-ledger edits. Current state is awaiting supervisor Gate 2 verification and supervisor-owned execution.
- MCP incident context: the immediately prior pass paused because MCP had a listener but no usable IDB session. That is historical incident context only. Current evidence below was redone against restored live session `60724697`.
- Current MCP basis: `idb_list` reported active worker session `60724697` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `server_health` returned `status:"ok"`, `auto_analysis_ready:true`, `hexrays_ready:true`, module `NexusTK.exe`, imagebase `0x400000`, and strings cache ready.
- Local documentation basis: target page, [UID:0001AP][MapPaneWeatherCoordinateObjectCore](../../../by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md), [UID:00007Q][MapPane](../../../by-class/MapPane.md), [UID:0000L3][MapPane](../../../by-file/MapPane.md), [UID:0000T7][MapTilePixelDimensions](../../../by-global/MapTilePixelDimensions.md), and direct caller support pages were checked. Prior executed reports B009/0001AP and B008/0003UH were used as historical leads only and rechecked against current MCP where they affect this target.

## Target

- Target UID: `00041X`.
- Target path: `by-memory/0x00505130-0x0050516a.MapPaneMapToScreenCoords.md`.
- Source queue/report row before callback: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`; the pre-callback row showed `86/88`, reconstructable true, no executed report. Scoped target validation `000000006224` removed the row from the generated not-covered stats list and recommended occasional full stats rescore.
- Current supervisor classification: implementation callback complete after Gate 1 pass; waiting for supervisor Gate 2 verification and supervisor-owned `execute_report`.
- Current scores and parent state after callback: `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, blank optional position, nonblank formal C++ unchanged.

## Current Target State

- Current metadata: `88/91`, direct owner/emitter [UID:00007Q][MapPane](../../../by-class/MapPane.md), reconstructable true.
- Current owner/emitter/reconstructable state: correct and unchanged. `MapPane` is the direct semantic owner because the body reads `this+0x3fc` and `this+0x400` tile origin fields. The class routes to [UID:0000L3][MapPane](../../../by-file/MapPane.md), which stages `auto-generated/NexusTK/map/MapPane.cpp`.
- Current C++/emitter state: generated `auto-generated/NexusTK/map/MapPane.cpp` now includes UID00041X at validator command `000000006227`, refreshed `2026-07-04T11:50:08-04:00`, with `Completion:88`, `Confidence:91`, and emits `MapPane::MapToScreenCoords`.
- Remaining open questions/blockers: the current target/support docs now contain the MCP `60724697` range/body/xref/no-data-route evidence, return-unused proof, and broad ten-callsite caller set. Exact original source symbol/type/member spelling remains an evidence-backed confidence cap only. Direct `MapCoordsToScreen` support wording that referred to UID00041X was synced/historicalized in the edited support docs.
- Related target/support docs checked: target by-memory page, MapPane class/file pages, `MapPaneWeatherCoordinateObjectCore`, `MapTilePixelDimensions`, `ScaleDirectionOffsetToPixels`, `MapPaneScreenToMapCoords`, `LivingObjectPaneUpdateScreenPosition`, `FlyingObjectPaneGetBoundingRect`, `AttachedObjectPane`, `AttachmentAnchorResolver`, generated MapPane.cpp, generated memory coverage, research tracker, and prior executed B reports matching UID/address/name.
- Current artifact/lifecycle status: this report is active in `tools/leaser/Agents/Agent-B006/research/`, implementation callback is complete, scoped validators ran, no `execute_report` ran, and the artifact awaits supervisor Gate 2 verification/execution.

## Executive Recommendation

- Best direct owner: [UID:00007Q][MapPane](../../../by-class/MapPane.md).
- Source route: [UID:00007Q][MapPane](../../../by-class/MapPane.md) through [UID:0000L3][MapPane](../../../by-file/MapPane.md) into `NexusTK/map/MapPane.cpp`.
- Target treatment: source-ready method child, not a no-code helper. `COMPLETION:88`, `CONFIDENCE:91` are applied; owner/emitter/reconstructable metadata and the formal C++ block remain unchanged.
- Support treatment: target and UID00041X aggregate/support rows now carry current MCP evidence. MapPane class/file support received concise current UID00041X route evidence. LivingObjectPane formal C++ now calls `MapToScreenCoords`; AttachedObjectPane historicalizes the older `MapCoordsToScreen` alias.
- Condition before execution: supervisor Gate 2 verification and supervisor-owned `execute_report`. B006 must not execute or move the report.

## Supervisor Active Recheck

- Triggering instruction: supervisor restored MCP and instructed B006 to resume UID00041X with live session `60724697`, redo/update MCP-backed evidence, avoid fallback-only evidence, avoid generated/coverage edits, and stop when the report is ready for Gate 1 or blocked.
- Split requirement: no split is required. Current MCP confirms a modeled function at `0x00505130` size `0x3a` / `58`, ending at `0x0050516a`, followed by six `0xcc` bytes before the inverse conversion helper at `0x00505170`.
- Source-bearing child status: UID00041X already exists as the exact child page and already has formal C++. This report recommends a source-quality/evidence/score refresh, not child creation.

## Inference Research Guidance Check

- `by-structure.md` code-entry rules support retaining the formal block because the target is reconstructable, has nonblank emitter UID `00007Q`, clears the combined score gate, and has a live source route through `MapPane.cpp`.
- Existing documentation assumptions treated as uncertain: exact original method spelling, `MapPoint` source declaration/member names, whether the original source saw the helper as `MapToScreenCoords` or `MapCoordsToScreen`, and the decompiler's apparent `int` return.
- IDA fact: current MCP proves the exact function range, one-block body, no callees, global reads, ten code xrefs, zero data xrefs, and VA/RVA pointer-pattern negatives.
- Documentation evidence: MapPane class/file pages and the aggregate page already place this target in the MapPane coordinate conversion surface and identify `+0x3fc/+0x400` as `m_tileOriginX/m_tileOriginY`.
- Inference: the source method should remain `void MapPane::MapToScreenCoords(MapPoint *point) const`; EAX contains the stored row value as a compiler artifact, and all checked direct call sites ignore/overwrite the return.
- Wave2/Wave3 material: generated output and old reports were used as leads only. No current Wave2/Wave3 instruction overrides the live MCP facts.

## Heuristic / Inference Reanalysis And Validation

- Function role: the body mutates a two-int coordinate pair in place from map-tile coordinates to screen-pixel coordinates. Current disassembly reads width from `word_66DA9C`, subtracts `MapPane+0x3fc` from pair element 1, adds the one-tile bias, multiplies by width, subtracts `MapPane+0x400` from pair element 0, adds the same bias, multiplies by height from `word_66DAA0`, and writes both results back.
- Pair naming: current project docs use row/column to preserve the observed storage convention. Pair element 0 is row/Y-like and pair element 1 is column/X-like; this is corroborated by `ObjectPane::GetMapPosition`, `ScaleDirectionOffsetToPixels`, `MapTilePixelDimensions`, and the LivingObjectPane local-player screen-position consumer.
- Return type: Hex-Rays reports `int __thiscall(_DWORD *this, int *)` because EAX holds the final row pixel value. Current caller-window disassembly proves the return is not consumed: call sites either immediately load from the mutated pair, continue with unrelated state, or overwrite EAX before returning. The existing `void` source signature is therefore the best mid-2000s source representation.
- Caller/reachability: ten direct code xrefs prove liveness through MapPane mouse/input code, FlyingObjectPane bounds, AttachedObjectPane shared attached-position helper, AttachmentAnchorResolver anchor/bounds helpers, and LivingObjectPane local-player screen-position update.
- Ownership/source placement: consumer xrefs are not ownership. The receiver fields are MapPane fields and direct calls set ECX to a MapPane pointer or `g_activeMapPane`, so MapPane remains the method owner. FlyingObjectPane, AttachedObjectPane, AttachmentAnchorResolver, and LivingObjectPane are consumers.
- Range/padding: the function is exact and no mixed ownership exists inside the range. `0x00505124-0x00505130` is 12 bytes of `0xcc` alignment before the target, and `0x0050516a-0x00505170` is six bytes of `0xcc` alignment before `sub_505170`.
- Rejected alternatives: raw decompiler-shaped C++, `int` return source API, file-level free helper ownership, global `MapTilePixelDimensions` ownership, caller ownership by object/attachment/living panes, parent aggregate emission, split/merge/range adjustment, and blank/no-code treatment.
- Remaining unresolved issue: exact original method/type spelling is not recovered. This is a confidence cap only; the current formal code uses established project names and has exact behavior.

## Evidence Standards Used

- IDA MCP evidence: `initialize`, `tools/list`, `idb_list`, `server_health`, `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, `xrefs_to`, `xref_query`, `make_signature_for_range`, `find_bytes`, and `callees` against session `60724697`.
- Binary evidence strength: exact function start/size, unique target byte signature, exact pre/post padding signatures, one-basic-block disassembly, decompile refs to tile dimension globals, direct xref inventory, data-xref negative, pointer-pattern negative, and caller-window disassembly.
- Documentation evidence: target/support by-* pages and executed B009/B008 reports provide historical context for current naming and ownership. Current MCP was used to confirm facts rather than relying on those reports alone.
- Confidence cap: no PDB/source symbol proof for original names, and the `MapPoint` source declaration is inferred from binary pair order and project naming rather than recovered headers.

## Evidence Checked

- IDA MCP/manual-disassembly/raw-byte checks performed:
  - `idb_list`: active session `60724697`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `13932`, not analyzing.
  - `server_health`: `ok`, Hex-Rays ready, auto-analysis ready, imagebase `0x400000`.
  - `lookup_funcs`: `0x00505130 -> sub_505130`, size `0x3a`; `0x0050516a` not a function; `0x00505170 -> sub_505170`, size `0x4b`; `0x00505124` not a function.
  - `analyze_function 0x00505130`: size `58`, prototype `int __thiscall(_DWORD *this, int *)`, no callees, one basic block, callers `sub_507150`, `sub_537D80`, `sub_5386C0`, `sub_53C700`, `sub_53C810`, `sub_5A88D0`, and ten code xrefs.
  - `decompile 0x00505130`: reads `word_66DA9C` and `word_66DAA0`, subtracts `this[255]`/`this[256]`, mutates `a2[1]`/`a2[0]` in place.
  - `disasm 0x00505130`: 21 instructions, `movsx eax, word_66DA9C`, subtracts `[ecx+3fch]`, `movsx eax, word_66DAA0`, subtracts `[ecx+400h]`, `retn 4`.
  - `xrefs_to`/`xref_query`: ten code xrefs to start, zero data xrefs to start, zero xrefs to end `0x0050516a`, one code xref to successor `0x00505170`.
  - `make_signature_for_range`: pre-padding `0x00505124-0x00505130` is 12 `CC` bytes; target bytes are unique; post-padding `0x0050516a-0x00505170` is six `CC` bytes.
  - `find_bytes`: no little-endian VA/RVA dword pointer-pattern matches for start `0x00505130` (`30 51 50 00`, `30 51 10 00`) or end `0x0050516a` (`6A 51 50 00`, `6A 51 10 00`).
  - Caller-window disassembly around all ten direct xrefs checked for return usage.
- by-* docs, support docs, old reports, generated reports, and trackers checked:
  - Target by-memory page, MapPane class/file pages, MapPaneWeatherCoordinateObjectCore, MapTilePixelDimensions, ScaleDirectionOffsetToPixels, MapPaneScreenToMapCoords, LivingObjectPaneUpdateScreenPosition, FlyingObjectPaneGetBoundingRect, AttachedObjectPane, AttachmentAnchorResolver, generated MapPane.cpp, generated memory coverage, project completion stats, research tracker, executed B009/0001AP, and executed B008/0003UH.
- Negative checks performed: data xrefs to target start, pointer-pattern route to target start/end, callers consuming return value, evidence for caller ownership, evidence for raw/decompiler rewrite, and evidence for range split/merge.
- Failed, unavailable, or intentionally skipped checks and why: no IDA DB rename/type/comment edits were attempted. During the initial report-only pass no validators ran; during the implementation callback scoped validators ran for every changed by-* doc and are recorded in `Validator Results`.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| MAP-41X-001 | Current MCP session `60724697` is the evidence basis for UID00041X, superseding the prior no-session pause. | High | `idb_list`, `server_health` | Target Evidence / Changes; report Supporting Research | incorporate | applied - target evidence and report status name `60724697` as current/historical basis; validator `000000006224` ok |
| MAP-41X-002 | Target is modeled `sub_505130`, exact size `0x3a` / `58`, range `0x00505130-0x0050516a`. | High | `lookup_funcs`, `analyze_function` | Target Status/Evidence; aggregate row | incorporate | applied - target Evidence and aggregate UID00041X row record range/size |
| MAP-41X-003 | Exact bytes are unique and bounded by `0xcc` alignment: 12 bytes before and six bytes after. | High | `make_signature_for_range` | Target Evidence; Range/Split/Padding | incorporate | applied - target Evidence lists exact byte signature plus pre/post padding; aggregate row mirrors padding |
| MAP-41X-004 | Body converts in-place row/column map-tile coordinates to screen-pixel coordinates using `m_tileOriginX`, `m_tileOriginY`, `g_mapTilePixelWidth`, and `g_mapTilePixelHeight`. | High | `disasm`, `decompile`, MapPane/MapTile docs | Target Evidence; target Item Summary | incorporate | applied - target Item Summary/Evidence and class/file support describe field/global use |
| MAP-41X-005 | There are ten direct code xrefs from six modeled functions and zero data xrefs to the target start. | High | `xrefs_to`, `xref_query` | Target Evidence; aggregate row; support notes | incorporate | applied - target Evidence, aggregate row, and class/file route notes record ten code xrefs and zero data xrefs |
| MAP-41X-006 | VA/RVA dword pointer patterns for the target start/end were not found; reachability is direct call based, not table/vtable/data-pointer based. | Medium-high | `find_bytes` patterns | Target Negative Evidence | incorporate | applied - target Evidence records zero start/end pointer-pattern hits and direct-call reachability |
| MAP-41X-007 | Apparent Hex-Rays `int` return is incidental; all checked direct call sites ignore or overwrite EAX. | High | caller-window disassembly around ten xrefs | Target Evidence; First-Draft C++ Recommendation | incorporate | applied - target Evidence and aggregate/class/file notes preserve return-unused proof; formal C++ remains `void` |
| MAP-41X-008 | Existing formal `void MapPane::MapToScreenCoords(MapPoint *point) const` block should remain unchanged. | High | body/caller audit plus current generated output | Target RECONSTRUCTION_CPP CODE | already-present | already-present - target formal C++ was unchanged; generated MapPane.cpp `000000006227` emits UID00041X body at `88/91` |
| MAP-41X-009 | Direct owner remains [UID:00007Q] MapPane; consumers do not own the helper. | High | ECX field reads, caller contexts, MapPane docs | Target metadata; ownership/source placement sections | already-present | already-present - target kept `CANONICAL_OWNER:00007Q`, `EMITTER_UIDS:00007Q`; support notes classify callers as consumers |
| MAP-41X-010 | Recommended score is `COMPLETION:88`, `CONFIDENCE:91`; not higher because original symbol/type spelling remains inferred. | High | current evidence plus open-question cap | Target metadata | incorporate | applied - target metadata now `88/91`; validator `000000006224` reported completion/confidence updates |
| MAP-41X-011 | Parent aggregate [UID:0001AP] already lists UID00041X but should receive current `60724697` xref/body/no-data evidence if stale. | Medium-high | aggregate row checked; current MCP richer than row | `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md` | incorporate | applied - aggregate UID00041X row and Changes entry updated; validator `000000006225` ok |
| MAP-41X-012 | MapPane class/file pages already establish source route; only concise support sync is needed if supervisor wants current caller/body evidence visible there. | Medium-high | `rg`/doc review | `by-class/MapPane.md`; `by-file/MapPane.md` | incorporate | applied - concise current evidence added to both support pages; validators `000000006226` and `000000006227` ok |
| MAP-41X-013 | Direct caller support using `MapCoordsToScreen` as the live target name is stale relative to target/generated `MapToScreenCoords` and should be synced or historicalized as an alias. | Medium-high | `LivingObjectPaneUpdateScreenPosition` formal block; AttachedObjectPane dependency note; target/generated output | direct caller support docs | historicalize | applied - LivingObjectPane formal call changed to `MapToScreenCoords`; AttachedObjectPane marks `MapCoordsToScreen` historical alias; validators `000000006228` and `000000006229` ok |
| MAP-41X-014 | Reject raw/decompiler rewrite, `int` return API, no-code treatment, aggregate emission, global/tile-dimension ownership, and caller-owner alternatives. | High | body/caller/ownership evidence | Target Evidence/Rejected alternatives | incorporate | applied - target Evidence preserves rejected alternatives; parent/class/file support keep child-owned source route and consumer-only caller ownership |

## Positive Evidence Summary

- Direct facts supporting the chosen recommendation: current MCP proves a modeled one-block function at `0x00505130-0x0050516a`, unique exact bytes, no callees, direct calls from live MapPane/object/attachment/living-object paths, reads of MapPane tile-origin fields, and reads of tile dimension globals.
- Corroborating documentation/generated-report evidence: target already emits through `auto-generated/NexusTK/map/MapPane.cpp`; MapPane class/file pages list UID00041X in the coordinate conversion family; MapTilePixelDimensions records `g_mapTilePixelWidth`/`g_mapTilePixelHeight`; direct consumers document use of the helper for object and local-player screen placement.
- Strongest inference chain: binary receiver fields `this+0x3fc/+0x400` plus established MapPane field glossary plus caller setup through MapPane pointers prove MapPane ownership. The exact arithmetic and ignored return prove the existing void formal C++ is source-shaped.

## IDA MCP Facts

- Function/range facts: `sub_505130`, start `0x00505130`, size `0x3a` / `58`, exact target byte signature `55 8B EC 0F BF 05 9C DA 66 00 56 57 8B 7D 08 8B 57 04 2B 91 FC 03 00 00 8B 37 42 2B B1 00 04 00 00 0F AF D0 46 89 57 04 0F BF 05 A0 DA 66 00 0F AF C6 89 07 5F 5E 5D C2 04 00`.
- Data/table/padding facts: `0x00505124-0x00505130` is 12 bytes of `CC`; `0x0050516a-0x00505170` is six bytes of `CC`; successor `sub_505170` starts at `0x00505170`.
- Xref facts: ten direct code xrefs to `0x00505130`: `0x00507384`, `0x00537e28`, `0x00537e45`, `0x005386f9`, `0x00538794`, `0x0053c73b`, `0x0053c7c6`, `0x0053c85d`, `0x0053c8e6`, and `0x005a88f1`.
- Vtable/global/type facts: no vtable/data xref to the target start was found. Decompile/disassembly refs are only to tile-dimension globals `word_66DA9C` (`g_mapTilePixelWidth`) and `word_66DAA0` (`g_mapTilePixelHeight`).
- Negative IDA facts: zero data xrefs to `0x00505130`; zero xrefs to `0x0050516a`; zero VA/RVA dword pattern hits for `0x00505130` and `0x0050516a`; no callees; no string refs.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00505124-0x00505130` | ignored alignment span | 12 bytes of `0xcc` before target | false/padding | `by-memory/-ignored.md` coverage context | n/a | already classified in aggregate evidence |
| `0x00505130-0x0050516a` | [UID:00041X](../../../by-memory/0x00505130-0x0050516a.MapPaneMapToScreenCoords.md) | `MapPane::MapToScreenCoords` in-place coordinate conversion | true | [UID:00007Q][MapPane](../../../by-class/MapPane.md) | applied `88/91` | source-ready formal C++ unchanged |
| `0x0050516a-0x00505170` | ignored alignment span | six bytes of `0xcc` after target | false/padding | `by-memory/-ignored.md` coverage context | n/a | already classified in aggregate evidence |
| `0x00505170-0x005051bb` | [UID:00041Y](../../../by-memory/0x00505170-0x005051bb.MapPaneScreenToMapCoords.md) | inverse screen-to-map conversion | true | [UID:00007Q][MapPane](../../../by-class/MapPane.md) | `86/88` | positive successor control |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00507384` | [UID:00037S][MapPaneMouseEventCore](../../../by-memory/0x00507150-0x00507c90.MapPaneMouseEventCore.md) / `sub_507150` -> `sub_505130` | MapPane mouse/input path converts map position to screen state; return ignored and mutated pair is read. |
| `0x00537e28`, `0x00537e45` | [UID:0003HX][FlyingObjectPaneGetBoundingRect](../../../by-memory/0x00537d80-0x00537f1d.FlyingObjectPaneGetBoundingRect.md) / `sub_537D80` -> `sub_505130` | Flying object bounds convert start/end map positions to screen positions; target remains dependency, not owner. |
| `0x005386f9`, `0x00538794` | [UID:0001D8][AttachedObjectPane](../../../by-memory/0x005380b0-0x005387a3.AttachedObjectPane.md) / `sub_5386C0` -> `sub_505130` | Shared attached-position helper converts anchor/fallback coordinates through MapPane. |
| `0x0053c73b`, `0x0053c7c6` | [UID:0001DH][AttachmentAnchorResolver](../../../by-memory/0x0053c700-0x0053c92e.AttachmentAnchorResolver.md) / `sub_53C700` -> `sub_505130` | Anchor point resolver converts source ObjectPane coordinates through `g_activeMapPane`. |
| `0x0053c85d`, `0x0053c8e6` | [UID:0001DH][AttachmentAnchorResolver](../../../by-memory/0x0053c700-0x0053c92e.AttachmentAnchorResolver.md) / `sub_53C810` -> `sub_505130` | Bounds helper duplicates/resolves same map-to-screen coordinate conversion before offsetting local bounds. |
| `0x005a88f1` | [UID:0003UH][LivingObjectPaneUpdateScreenPosition](../../../by-memory/0x005a88d0-0x005a89c9.LivingObjectPaneUpdateScreenPosition.md) / `sub_5A88D0` -> `sub_505130` | Local-player screen-position update calls through cached `m_mapPane`, then applies movement interpolation and half-tile centering. |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion: target page already owns formal C++; MapPane class/file pages list UID00041X as coordinate conversion; MapPane aggregate row explains in-place conversion; MapTilePixelDimensions resolves the global pair; LivingObjectPane/FlyingObjectPane/AttachedObjectPane/AttachmentAnchorResolver docs all show target as a dependency/consumer helper.
- Existing docs that were stale, incomplete, or contradicted before callback: target page lacked current session `60724697`, exact byte signature, ten-xref caller list, no-data/no-pointer-route negatives, and return-unused proof; LivingObjectPane formal C++ called the helper as `MapCoordsToScreen`; AttachedObjectPane text also named `MapPane::MapCoordsToScreen` as the dependency. Current callback applied those fixes: target/support docs now incorporate the current evidence, LivingObjectPane calls `MapToScreenCoords`, and AttachedObjectPane marks the older `MapCoordsToScreen` wording as a historical alias only.
- Generated/coverage report state after callback: generated `auto-generated/NexusTK/map/MapPane.cpp` includes UID00041X as nonempty formal output with validator-command-id `000000006227`, refreshed `2026-07-04T11:50:08-04:00`, and shows `Completion:88`, `Confidence:91`. Generated `auto-generated/NexusTK/map/LivingObjectPane.cpp` has validator-command-id `000000006228`, refreshed `2026-07-04T11:50:17-04:00`, and the UID0003UH call site now uses `MapToScreenCoords`. Queue status command `000000006230` reported no queued or processing generated refresh jobs.

## Ranked Ownership Analysis

### 1. [UID:00007Q] MapPane

- Evidence for: body reads MapPane tile-origin fields `+0x3fc/+0x400`, caller contexts pass MapPane receivers or `g_activeMapPane`, class/file pages already define the coordinate conversion surface, and sibling inverse conversion UID00041Y is also MapPane-owned.
- Evidence against: several direct callers live in object/attachment/living-object families, but they call this helper as a coordinate service and do not own its receiver fields.
- Decision: accepted direct owner and emitter. Keep `CANONICAL_OWNER:00007Q` and `EMITTER_UIDS:00007Q`.

### 2. [UID:0000L3] MapPane file root

- Evidence for: final generated source route is `NexusTK/map/MapPane.cpp`; coordinate helpers and global tile dimensions are grouped in the MapPane file source family.
- Evidence against: UID00041X is not a receiverless file helper; it reads `this` MapPane fields and should be owned by the class page rather than bypassing the class owner.
- Decision: source route through class to file root, not direct canonical owner.

### 3. Object/attachment/living-object caller families

- Evidence for: direct callers include FlyingObjectPane, AttachedObjectPane shared position helper, AttachmentAnchorResolver, and LivingObjectPane update logic.
- Evidence against: those callers pass coordinates into a MapPane receiver helper and then continue their own object-specific placement logic. They do not define tile origin, tile dimensions, or MapPane coordinate policy.
- Decision: consumers only. Do not migrate target ownership.

### 4. MapTilePixelDimensions/global owner

- Evidence for: target reads `word_66DA9C` and `word_66DAA0`.
- Evidence against: the global pair is a dependency. The body's receiver-specific origin fields and method call sites are MapPane-specific.
- Decision: dependency only.

### 5. No-owner/non-emitting/raw helper fallback

- Evidence for: original symbol is not recovered, and generated/historical reports used several helper spellings.
- Evidence against: exact modeled function, live direct callers, source-shaped arithmetic, strong owner route, and existing generated C++ all clear the source-ready gate.
- Decision: rejected.

## Source Placement

- Recommended source file/class/global/module placement: `MapPane::MapToScreenCoords(MapPoint *point) const` under [UID:00007Q][MapPane](../../../by-class/MapPane.md), emitted through [UID:0000L3][MapPane](../../../by-file/MapPane.md) into `NexusTK/map/MapPane.cpp`.
- Why this placement fits source-tree and subsystem context: MapPane owns viewport origin, map tile/screen coordinate conversions, visible bounds, movement scroll, and object placement. UID00041X sits between sibling coordinate helpers `DirectionToTileOffset`, `ScaleDirectionOffsetToPixels`, and `ScreenToMapCoords`.
- Rejected placements and why: caller class placement confuses consumers with owner; direct by-file ownership bypasses the receiver class; by-global ownership treats dependencies as owner; no-owner/non-emitting ignores modeled liveness and existing source output.
- Remaining placement uncertainty: exact original method spelling and `MapPoint` declaration exposure remain inferred, not original-symbol proven.

## Range / Split / Padding / Reclassification Analysis

- Exact range/boundary facts: target is `0x00505130-0x0050516a`; `lookup_funcs` reports `sub_505130` size `0x3a`; `0x0050516a` is not a function; successor `sub_505170` starts at `0x00505170`.
- Children/subranges to create, repair, merge, leave ignored, or leave no-owner: none. UID00041X is already the exact child and should not be split or merged.
- Padding/table/data/code distinctions: `0x00505124-0x00505130` is 12 bytes of `0xcc` alignment after `ScaleDirectionOffsetToPixels`; `0x0050516a-0x00505170` is six bytes of `0xcc` alignment before `ScreenToMapCoords`. No table/data island belongs to UID00041X.
- Parent/container impact: parent aggregate [UID:0001AP] remains an index/aggregate with child-owned code. It should receive current UID00041X evidence only if its row is considered stale.

## Negative Evidence Summary

- No data xrefs to the target start were found by `xref_query`.
- No VA/RVA dword pointer-pattern matches for `0x00505130` or `0x0050516a` were found by `find_bytes`; reachability is direct-call based.
- No callees were found; this is a local arithmetic helper, not a wrapper around another API.
- No xrefs to `0x0050516a` were found; the end boundary is not a separate route.
- The ten caller families are consumers. Their xrefs do not prove ownership because the target reads MapPane fields and either receives ECX as a MapPane pointer or uses `g_activeMapPane`.
- The apparent decompiler `int` return is rejected as a source API because caller-window disassembly shows the returned EAX is not used.
- Parent aggregate emission is rejected because [UID:0001AP] spans many independent children; UID00041X already owns the exact body.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing names/types/comments: document the helper as `MapPane::MapToScreenCoords(MapPoint *point) const`; preserve `MapCoordsToScreen` as a historical/search alias only where needed for old reports or support text.
- Evidence for each proposed name/type/comment: existing target/generated output uses `MapToScreenCoords`; current body performs map-to-screen conversion; sibling inverse is `ScreenToMapCoords`; row/column pair convention is consistent with support docs.
- Items intentionally left unchanged and why: do not rename IDA function `sub_505130` or edit IDA DB comments/types in this B-agent pass. No MCP process or IDA DB management was requested.
- Whether IDA DB edits are safe, unsafe, or not requested: not requested. Report-only scope excludes IDA edits.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes; already source-emitting and eligible.
- Recommended code: keep the existing target formal block unchanged. If the supervisor accepts the report and wants the target block restated during callback, use this exact formal insertion shape:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void MapPane::MapToScreenCoords(MapPoint *point) const
{
    const int row = point->row - m_tileOriginY + 1;

    point->column = (point->column - m_tileOriginX + 1) * g_mapTilePixelWidth;
    point->row = row * g_mapTilePixelHeight;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Reason it preserves exact original behavior: the block performs the exact observed arithmetic and write order: column/pair element 1 subtracts origin X and multiplies by tile width; row/pair element 0 subtracts origin Y and multiplies by tile height.
- Reason it matches the most plausible original precompiled mid-2000s developer source shape: an in-place `void` coordinate conversion method is simpler and more human-shaped than an `int` helper that returns an ignored assignment artifact. The name pairs naturally with the existing inverse `ScreenToMapCoords`.
- Inferred source-facing names/types/fields used instead of IDA/decompiler labels: `MapPane`, `MapPoint`, `point`, `row`, `m_tileOriginX`, `m_tileOriginY`, `g_mapTilePixelWidth`, and `g_mapTilePixelHeight` replace raw `_DWORD *this`, `int *a2`, `this[255]`, `this[256]`, `word_66DA9C`, and `word_66DAA0`.
- Naming/coding style convention used and evidence for consistency: class method name uses the existing MapPane coordinate-helper style; fields match accepted MapPane field glossary; globals match `MapTilePixelDimensions`.
- Reason code should remain blank, if applicable: not applicable. Blank/no-code treatment is rejected.
- Exact no-code proof, if not eligible: not applicable.

## Final Recommendation

- Exact changes applied: UID00041X target is `COMPLETION:88`, `CONFIDENCE:91`; owner/emitter/reconstructable metadata was preserved; formal C++ stayed unchanged; current MCP `60724697` range/body/bytes/padding/xref/no-data/no-pointer/caller-return-unused evidence was added.
- Exact parent assignments applied: kept `CANONICAL_OWNER:00007Q`; kept `EMITTER_UIDS:00007Q`; kept blank optional position.
- Exact items left no-owner/non-emitting and why: none for UID00041X. No new children were recommended or created.
- Exact future work outside assignment scope: final original method/type/member spelling could be revisited if source headers or PDB-equivalent evidence appear. No current blocker remains for emitted C++.

## Recommended Target Doc Changes

- Target path: `by-memory/0x00505130-0x0050516a.MapPaneMapToScreenCoords.md`.
- Exact report facts incorporated:
  - Current MCP session `60724697`, server health OK, Hex-Rays ready.
  - `sub_505130`, size `0x3a` / `58`, exact bytes listed in this report, unique signature, pre-padding 12 `0xcc`, post-padding six `0xcc`.
  - Body reads `word_66DA9C` and `word_66DAA0`, reads MapPane `+0x3fc/+0x400`, mutates `MapPoint` in place.
  - Ten direct code xrefs from `0x00507384`, `0x00537e28`, `0x00537e45`, `0x005386f9`, `0x00538794`, `0x0053c73b`, `0x0053c7c6`, `0x0053c85d`, `0x0053c8e6`, and `0x005a88f1`; zero data xrefs; zero VA/RVA dword pointer-pattern hits for start/end.
  - Caller-window proof that the decompiler's `int` return is incidental and current `void` formal C++ is correct.
- Metadata/score/owner/emitter/reconstructable/C++ changes applied: set `COMPLETION:88`; set `CONFIDENCE:91`; kept `CANONICAL_OWNER:00007Q`; kept `RECONSTRUCTABLE:TRUE`; kept `EMITTER_UIDS:00007Q`; kept optional position blank; kept the current formal C++ unchanged.
- Historical/stale assumptions, rejected alternatives, and negative evidence preserved: raw `sub_505130`/decompiler-shaped C++ is rejected; `MapCoordsToScreen` remains only a historical/search alias unless supervisor deliberately standardizes on it; caller ownership, by-global ownership, aggregate emission, split/merge, no-code treatment, and `int` return source API are rejected.

## Recommended Support Doc Changes

- Support path: `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`.
  - Exact report facts incorporated: updated the UID00041X row/support text with current MCP session `60724697`, exact size/bytes/padding, ten direct code xrefs, zero data/pointer route, no callees, and return-unused proof. Kept aggregate metadata and marker-only policy unchanged.
  - Metadata/link/score/coverage/source-placement changes applied: no aggregate metadata change.
- Support path: `by-class/MapPane.md`.
  - Exact report facts incorporated: added a concise method note that UID00041X is source-ready with current `60724697` evidence, direct callers from MapPane input plus object/attachment/living-object consumers, and `+0x3fc/+0x400` tile-origin field use. Existing class route and field glossary remain intact.
  - Metadata/link/score/coverage/source-placement changes applied: no class metadata change.
- Support path: `by-file/MapPane.md`.
  - Exact report facts incorporated: kept UID00041X in the coordinate conversion subsystem and noted it emits through UID00007Q as `MapPane::MapToScreenCoords`; generated output route remains present.
  - Metadata/link/score/coverage/source-placement changes applied: no file metadata/path change.
- Support path: `by-memory/0x005a88d0-0x005a89c9.LivingObjectPaneUpdateScreenPosition.md`.
  - Exact report facts incorporated: direct caller support previously used the older live method spelling `MapCoordsToScreen` in its formal C++ while UID00041X and generated MapPane output use `MapToScreenCoords`; callback updated only this target-reference spelling and preserved all LivingObjectPane owner/field evidence.
  - Metadata/link/score/coverage/source-placement changes applied: no metadata change.
- Support path: `by-memory/0x005380b0-0x005387a3.AttachedObjectPane.md`.
  - Exact report facts incorporated: this support page's dependency note named `MapPane::MapCoordsToScreen`; callback historicalized that alias and names UID00041X as `MapPane::MapToScreenCoords`.
  - Metadata/link/score/coverage/source-placement changes applied: no aggregate metadata change.
- Support paths inspected and excluded from direct edit with reason: `by-memory/0x00507150-0x00507c90.MapPaneMouseEventCore.md`, `by-memory/0x00537d80-0x00537f1d.FlyingObjectPaneGetBoundingRect.md`, and `by-memory/0x0053c700-0x0053c92e.AttachmentAnchorResolver.md` were left unchanged because they correctly treat UID00041X as support/callee evidence or use broader `WorldToScreenCoords` source-shape language that should not be rewritten solely from this target report without a separate helper-naming decision.

## Score And Metadata Recommendation

- Current score/metadata: `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, blank optional position, nonblank formal C++.
- Recommended score/metadata: `COMPLETION:88`, `CONFIDENCE:91`, same owner/emitter/reconstructable metadata, same formal C++.
- Score rationale and reason not higher/lower:
  - Completion `88`: current report resolves live MCP body, exact bytes, padding, xrefs, data-route negatives, caller-return-use audit, owner/source placement, formal C++ readiness, and support-sync needs. It stays below final-audit quality because target/support docs do not yet contain this full evidence until callback and because original symbol/type spellings remain inferred.
  - Confidence `91`: current MCP and support docs strongly prove the target's behavior and route. It stays below `95+` because no original source name/header proof exists and some direct consumer support still uses older aliases.
- Score-improvement attempt: the prior score cap came from sparse target evidence and old B009 lead text. Current MCP removed the range/body/caller/return-use blockers. Remaining cap is original-name/type spelling, not behavior or source readiness.
- Metadata fields to change or leave unchanged: change only scores; leave owner, reconstructable, emitters, optional position, and formal C++ unchanged.

## Open Questions With Attempted Resolution

- Original method spelling:
  - Evidence checked: target/generated output uses `MapToScreenCoords`; B008 historical report listed both `MapCoordsToScreen` and `MapToScreenCoords`; support docs use both spellings.
  - Resolution: standardize current documentation for UID00041X on `MapToScreenCoords`, with `MapCoordsToScreen` as a historical/search alias.
  - Remaining uncertainty: exact original spelling unavailable. Score impact: confidence cap only.
- Source return type:
  - Evidence checked: Hex-Rays prototype, disassembly, and all direct caller windows.
  - Resolution: keep source `void`; return value is incidental and ignored/overwritten.
  - Remaining uncertainty: none material for source reconstruction.
- `MapPoint` field/member order:
  - Evidence checked: target body, ObjectPane map-position docs, `ScaleDirectionOffsetToPixels`, `MapTilePixelDimensions`, LivingObjectPane consumer.
  - Resolution: keep row/column convention and current formal C++. Exact original type declaration remains unrecovered.
  - Remaining uncertainty: original member names and header location. Score impact: confidence cap only.
- Support caller naming:
  - Evidence checked: direct caller docs and generated MapPane output.
  - Resolution: implementation callback should update direct support docs only where older `MapCoordsToScreen` wording presents itself as the current target method spelling.
  - Remaining uncertainty: broader `WorldToScreenCoords` helper abstraction in AttachmentAnchorResolver may be a deliberate source-shape wrapper and should not be rewritten under this target without separate acceptance.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Not applicable. No manual `-coverage-report.md` edit is recommended or performed. Validator-owned generated outputs refreshed through scoped validators; queue-status `000000006230` showed no pending generated refresh jobs.

## Follow-Up Actions

- Supervisor actions: perform Gate 2 verification and, if accepted, run supervisor-owned `execute_report`.
- A-agent actions: none requested.
- B006 future research actions: none outside this completed callback. If the supervisor later wants broader coordinate-helper naming standardization, use a separate target/report covering all direct consumers and generated C++ consistency.

## Confidence

- Recommendation confidence: high.
- Score confidence: high for `88/91`.
- Remaining uncertainty: exact original source symbol/type spellings and whether old `MapCoordsToScreen` was a real original alias or only a report-era alternate name.

## Validator Results

- Commands run after implementation callback:
  - `python .\tools\validator.py --mode file --file by-memory/0x00505130-0x0050516a.MapPaneMapToScreenCoords.md --apply --queue-timeout 240`
    - `command_id: 000000006224`; `command_timestamp: 2026-07-04T11:49:41-04:00`; exit code `0`; `ok: 1`.
    - Tool-owned effects: `completion_update: 1`, `confidence_update: 1`, `uid_link_insert: 1`, `reference_index_add: 2`, `stats_row_remove: 1`, `stats_rescore_recommended: 1`, `projected_stats_update: 1`, `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-memory/0x00505130-0x0050516a.MapPaneMapToScreenCoords.md --apply --queue-timeout 240`
    - Final target repair revalidation after a validator-normalized duplicate-link typo was corrected.
    - `command_id: 000000006231`; `command_timestamp: 2026-07-04T11:56:45-04:00`; exit code `0`; `ok: 1`.
    - Tool-owned effects: `stats_incremental_noop: 1`, `projected_stats_update: 1`, `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md --apply --queue-timeout 240`
    - `command_id: 000000006225`; `command_timestamp: 2026-07-04T11:49:47-04:00`; exit code `0`; `ok: 1`.
    - Tool-owned effects: `stats_incremental_noop: 1`, `projected_stats_update: 1`, `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-class/MapPane.md --apply --queue-timeout 240`
    - `command_id: 000000006226`; `command_timestamp: 2026-07-04T11:49:58-04:00`; exit code `0`; `ok: 1`.
    - Warnings: `missing_ref_uid: 89` on pre-existing MapPane class references, with 79 suppressed rows reported by the validator. No UID00041X-specific failure.
    - Tool-owned effects: `stats_row_update: 1`, `projected_stats_update: 1`, `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-file/MapPane.md --apply --queue-timeout 240`
    - `command_id: 000000006227`; `command_timestamp: 2026-07-04T11:50:08-04:00`; exit code `0`; `ok: 1`.
    - Warnings: `missing_ref_uid: 100` on pre-existing broad MapPane file references, with 90 suppressed rows reported by the validator. No UID00041X-specific failure.
    - Tool-owned effects: `stats_row_update: 1`, `projected_stats_update: 1`, `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-memory/0x005a88d0-0x005a89c9.LivingObjectPaneUpdateScreenPosition.md --apply --queue-timeout 240`
    - `command_id: 000000006228`; `command_timestamp: 2026-07-04T11:50:17-04:00`; exit code `0`; `ok: 1`.
    - Warnings: `missing_ref_uid: 7` on pre-existing UID00037V/UID0003XP references. No UID00041X-specific failure.
    - Tool-owned effects: `autogen_registry_update: 1`, `reference_index_add: 1`, `stats_incremental_noop: 1`, `projected_stats_update: 1`, `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-memory/0x005380b0-0x005387a3.AttachedObjectPane.md --apply --queue-timeout 240`
    - `command_id: 000000006229`; `command_timestamp: 2026-07-04T11:50:24-04:00`; exit code `0`; `ok: 1`.
    - Tool-owned effects: `uid_link_update: 1`, `reference_index_add: 1`, `stats_incremental_noop: 1`, `projected_stats_update: 1`, `generated_refresh: deferred`.
- Generated freshness/read-only checks:
  - `auto-generated/NexusTK/map/MapPane.cpp` header is current at `validator-command-id: 000000006231`, `validator-refreshed-at: 2026-07-04T11:56:45-04:00`, and contains UID00041X at `Completion:88`, `Confidence:91`, emitting `MapPane::MapToScreenCoords`.
  - `auto-generated/NexusTK/map/LivingObjectPane.cpp` header is current at `validator-command-id: 000000006228`, `validator-refreshed-at: 2026-07-04T11:50:17-04:00`, and UID0003UH now calls `m_mapPane->MapToScreenCoords(&screenPos);`.
  - Final read-only `python .\tools\validator.py --queue-status` returned `command_id: 000000006232`, `command_timestamp: 2026-07-04T11:56:59-04:00`, `worker running: True`, `queued jobs: 0`, `processing jobs: 0`, `queued generated refresh jobs: 0`, `processing generated refresh jobs: 0`.
- Leases: B006 leased the six by-* docs for the edit/validator batch and released all six immediately after validation. B006 then leased the target alone to repair the duplicate-link typo, revalidated it with `000000006231`, and released that lease. Final `current_leases.md` showed no active B006 leases; B010 held unrelated EffectObjectPane/Effects leases.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B006/research/00041X-MapPaneMapToScreenCoords-source-quality.md` during the original report-only pass.
- Modified in this callback:
  - `by-memory/0x00505130-0x0050516a.MapPaneMapToScreenCoords.md`
  - `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`
  - `by-class/MapPane.md`
  - `by-file/MapPane.md`
  - `by-memory/0x005a88d0-0x005a89c9.LivingObjectPaneUpdateScreenPosition.md`
  - `by-memory/0x005380b0-0x005387a3.AttachedObjectPane.md`
  - `tools/leaser/Agents/Agent-B006/research/00041X-MapPaneMapToScreenCoords-source-quality.md`
- Renamed: none.
- Not edited: inspect-only support pages `by-memory/0x00507150-0x00507c90.MapPaneMouseEventCore.md`, `by-memory/0x00537d80-0x00537f1d.FlyingObjectPaneGetBoundingRect.md`, and `by-memory/0x0053c700-0x0053c92e.AttachmentAnchorResolver.md` were left unchanged because they did not contain a direct UID00041X contradiction requiring callback edit.
- Report execution: not run. B006 did not run `execute_report`, dry-run/probing variants, registry lifecycle commands, manual report moves, archive commands, manual generated edits, manual coverage-report edits, supervisor-ledger edits, or validator-state edits.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation. Proof: supervisor Gate 1 passed and sent implementation callback.
- [x] Target/support docs to update:
  - [x] `by-memory/0x00505130-0x0050516a.MapPaneMapToScreenCoords.md`: set `COMPLETION:88`, `CONFIDENCE:91`; kept `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, blank optional position; kept formal C++ unchanged; added `60724697` range/body/bytes/padding/xref/no-data/no-pointer/return-unused evidence and rejected alternatives. Validators `000000006224` and final repair revalidation `000000006231` ok.
  - [x] `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`: updated UID00041X row/support text with current evidence; kept aggregate metadata unchanged. Validator `000000006225` ok.
  - [x] `by-class/MapPane.md`: added concise current UID00041X source-ready evidence because the class page had only broader route/context detail. Validator `000000006226` ok with pre-existing missing-ref warnings.
  - [x] `by-file/MapPane.md`: synced UID00041X generated/source-route note with current source-ready evidence. Validator `000000006227` ok with pre-existing missing-ref warnings.
  - [x] `by-memory/0x005a88d0-0x005a89c9.LivingObjectPaneUpdateScreenPosition.md`: changed stale live formal call from `MapCoordsToScreen` to `MapToScreenCoords` and preserved LivingObjectPane evidence/metadata. Validator `000000006228` ok with pre-existing missing-ref warnings.
  - [x] `by-memory/0x005380b0-0x005387a3.AttachedObjectPane.md`: historicalized stale `MapPane::MapCoordsToScreen` dependency wording as an alias for current UID00041X `MapPane::MapToScreenCoords`. Validator `000000006229` ok.
  - [x] Inspect-only pages `MapPaneMouseEventCore`, `FlyingObjectPaneGetBoundingRect`, and `AttachmentAnchorResolver`: excluded-with-reason because no direct UID00041X contradiction was found; they remain caller/consumer evidence only.
- [x] Current target state and actual evidence checked recorded: session `60724697`, `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, `xrefs_to`, `xref_query`, `make_signature_for_range`, `find_bytes`, `callees`, and caller-window audit facts are incorporated into target/support docs and ledger.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score changes applied: target only, `86/88` -> `88/91`; no owner/emitter/reconstructable changes.
- [x] Score-limiting blockers researched to resolution and incorporated: range/body/caller/return-use resolved; original spelling/type declaration left as evidence-backed confidence cap.
- [x] Owner/emitter/reconstructable changes: none; `00007Q` owner/emitter and reconstructable true preserved.
- [x] Split/rename/new-child changes: none.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes: no IDA edits; `MapToScreenCoords` recorded as current source name and `MapCoordsToScreen` historical/search alias where it directly referred to UID00041X.
- [x] First-draft C++ or no-code proof: exact target formal C++ block kept unchanged; no no-code proof because source-ready emission is supported.
- [x] Third-party import directive: not applicable.
- [x] Exact target/support doc facts incorporated at report-level detail: exact bytes, padding, body, globals, field offsets, caller xrefs, negative route proof, return-unused proof, owner/source route, and rejected alternatives are preserved.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: historical MCP no-session pause, old `MapCoordsToScreen` alias, no data/pointer route, no caller ownership, no aggregate emission, no raw/decompiler rewrite, no split/merge.
- [x] Wave2/Wave3 stale material: none applied; generated output used as validator-owned output/freshness evidence only.
- [x] Open questions documented as evidence-backed unresolved: original method spelling, original `MapPoint` declaration/member names, and broader `WorldToScreenCoords` abstraction in AttachmentAnchorResolver remain confidence caps, not blockers.
- [x] Validators run for every changed by-* file; command IDs `000000006224` through `000000006229` plus target repair revalidation `000000006231` recorded above.
- [x] Generated refresh checked: MapPane.cpp refreshed at `000000006231`; LivingObjectPane.cpp refreshed at `000000006228`; queue-status `000000006232` showed no pending generated jobs. No manual generated/coverage edits.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support doc details incorporated at report-level detail or excluded with reason.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale.
- [x] Validators run and results recorded.
- [x] Generated report refresh completed by validator where relevant and confirmed with headers/queue status.
- [x] Remaining unapplied accepted items listed with exact blocker: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000006254","destination_path":"executed-b-agent-research/B006/00041X-MapPaneMapToScreenCoords-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/00041X-MapPaneMapToScreenCoords-source-quality.md","timestamp":"2026-07-04T12:05:34-04:00","uid":"00041X"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
