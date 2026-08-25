** TARGET-REPORT-UID:0002DU **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **

# 0002DU FittingRoomListPaneSlotLayoutRawHelpers Source-Quality Report

## Finalized Report / Current Recommendation

Current recommendation: raise UID0002DU from `86/88` to `88/90`, keep `CANONICAL_OWNER:000053`, keep `RECONSTRUCTABLE:TRUE`, keep `EMITTER_UIDS:000053`, keep `EMITTER_POSITION_OPTIONAL` blank, and keep the target source-bearing through `FittingRoomListPane` into `NexusTK/cashshop/FittingRoom.cpp`.

Final disposition: source-ready raw helper island with retained raw-start/no-route caveats. The formal C++ block should remain populated, but the callback should refresh it to the exact formal block in this report so the `+0x124` field spelling is consistent with the accepted constructor field name `m_pendingSlotTimer`. The exact original helper names, `Point` field order/spelling, and `+0x124` member spelling remain confidence caps only.

Implementation callback result: B003 applied the accepted target metadata/C++/evidence refresh, updated the stale UID0000WR aggregate support row, marked class/file/constructor support facts already-present, ran scoped validators for both edited by-* docs, released leases, and did not run supervisor-owned lifecycle/report execution commands.

Confidence: strong source-quality recommendation. MCP session `73c77998` confirms the byte/range/xref/disassembly facts, while the raw starts still have no modeled function objects or direct caller route.

## Supporting Research

This artifact began as the report-only output for the Agent-B003 UID0002DU assignment. After supervisor Gate 1 passed, B003 completed the implementation callback in the same report: the target by-memory doc and UID0000WR aggregate support doc were edited under short leases, scoped validators were run, and the report ledger/checklist were updated.

B003 did not edit generated files, coverage reports, validator state, report lifecycle files, archives, supervisor ledgers, or IDA database state manually.

Historical context: B003 previously produced and the supervisor executed `executed-b-agent-research/B003/0002DT-0002DP-0002DU-FittingRoomListPaneSlotGeometry-source-quality.md`. That report established the source-ready slot-geometry interpretation, but this report redoes the live IDA evidence pass with the current MCP session and focuses only on UID0002DU.

Current MCP incident context: earlier stale/no-session checks are historical only. The current live NexusTK IDB session is `73c77998`, found by `idb_list`, with worker PID `12416` and `is_active:true`.

## Target

- Target UID: `0002DU`
- Target path: `by-memory/0x00420d50-0x00420dd5.FittingRoomListPaneSlotLayoutRawHelpers.md`
- Source queue: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`
- Report path: `tools/leaser/Agents/Agent-B003/research/0002DU-FittingRoomListPaneSlotLayoutRawHelpers-source-quality.md`
- Current supervisor classification: Gate 1 passed; implementation callback completed for supervisor Gate 2 review.
- Current scores and parent state: target is `COMPLETION:86`, `CONFIDENCE:88`, class-owned by UID000053, reconstructable, emitting through UID000053.

## Current Target State

Existing metadata:

- `COMPLETION:86`
- `CONFIDENCE:88`
- `CANONICAL_OWNER:000053`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:000053`
- `EMITTER_POSITION_OPTIONAL:` blank

Existing C++/emitter state: the formal `RECONSTRUCTION_CPP CODE` block is already populated with `FittingRoomListPane::GetItemSlotOrigin(Point*, FittingRoomSlotIndex)` and `FittingRoomListPane::CancelPendingSlotTimer()`. The source shape is still valid, but the timer field should be harmonized to `m_pendingSlotTimer` to match the accepted constructor field map while preserving the exact-original-spelling cap.

Existing stale or contradictory text:

- The item summary still says "scratch-resource reset via `0x00597610`"; current evidence shows targeted `TimerHandler` cancellation.
- The item summary still says "blank parent due attachment threshold"; the current target metadata already has owner/emitter UID000053 and the class/file docs clear the source-emission route.
- The score rationale cites older evidence and does not cite current MCP session `73c77998`.
- The raw code section cites 2026-06-05 MCP facts but should be refreshed with current function/range/size, bytes/signature, xref, disassembly, and PE route evidence.

Related docs checked: `by-class/FittingRoomListPane.md`, `by-file/FittingRoom.md`, `by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md`, `by-memory/0x0041eb90-0x0041ecbd.FittingRoomListPaneConstructor.md`, `by-memory/0x00420950-0x00420b60.FittingRoomListPaneSlotRectRawHelpers.md`, `by-memory/0x00420b60-0x00420cf9.FittingRoomListPaneHitTestSlot.md`, and the prior executed B003 slot-geometry report.

Current artifact/lifecycle status: implementation callback completed in the Agent-B003 research artifact. B003 stopped before supervisor-owned report execution/lifecycle commands.

## Executive Recommendation

UID0002DU should remain a `FittingRoomListPane` child and source emitter through UID000053. It should not be split into new child pages now: the two raw helper bodies are compact, adjacent, source-compatible, and already represented by one formal target C++ block.

The current score should move to `88/90` because the current MCP pass confirms every previous positive claim and removes stale parent/emitter wording as a blocker. It should not move higher because no current evidence proves direct liveness for the raw starts, exact original helper names, exact original `+0x124` member spelling, or project-wide `Point` member order.

## Supervisor Active Recheck

The supervisor initially instructed Agent-B003 to read the current goal, use `ntk-b-agent-workflow`, produce a Medium report-only artifact for UID0002DU, and not edit by-* docs or run lifecycle/execute commands. The supervisor later overrode the MCP state, directing B003 to discard stale sessions, rerun `idb_list`, and use the current active NexusTK session. After Gate 1 passed, the supervisor authorized this implementation callback for the target and listed support docs.

B003 rechecked MCP manually. `idb_list` returned active session `73c77998` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; `server_health` returned `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`.

## Inference Research Guidance Check

The inference discipline was applied by separating these evidence classes:

- IDA MCP facts: current session status, function lookup, byte ranges, signature uniqueness, xrefs, decompile failures, disassembly, rendered listing search hits, and constructor-side field initialization.
- Local executable facts: read-only PE route scan for direct rel32 calls/jumps and non-text VA/RVA pointer hits.
- Documentation evidence: current target/support docs and the prior executed B003 slot-geometry report.
- Inference: source-facing method/member/type names and the source placement within `FittingRoomListPane`.

Wave/history references were treated as stale leads unless reconfirmed by current docs or session `73c77998`. The older "blank parent", "95/95 gate", and "scratch resource" explanations are no longer valid current-state claims.

## Heuristic / Inference Reanalysis And Validation

Range and body shape: `lookup_funcs` confirms `0x00420d50`, `0x00420db0`, and `0x00420dd5` are not modeled function starts. `get_bytes` confirms the target half-open range `0x00420d50-0x00420dd5` is `0x85` bytes / 133 decimal. The first helper is `0x60` bytes / 96 decimal (`0x00420d50-0x00420db0`); the second is `0x25` bytes / 37 decimal (`0x00420db0-0x00420dd5`). `0x00420dd5-0x00420de0` is eleven `0xcc` bytes before successor function `sub_420DE0`.

Raw helper status: IDA still does not model either raw start as a function, and decompilation fails at both `0x00420d50` and `0x00420db0`. Bounded xref checks find zero incoming xrefs to `0x00420d50`, `0x00420db0`, or `0x00420dd5`. A local PE route scan found no direct rel32 call/jump hits and no non-text VA/RVA pointer hits to either raw start. This preserves the no-route confidence cap.

Origin helper interpretation: disassembly at `0x00420d50` reads `this+0x10c`, branches on display mode, calls `sub_4B7C30` at `0x00420d6a` and `0x00420d87`, and applies row/grid offset formulas. The row/list branch uses base `(30,20)` and `slot * 20`; the grid branch uses base `(21,17)`, six columns, `(slot % 6) * 96`, and `(slot / 6) * 112`. This supports `GetItemSlotOrigin` / `GetVisibleItemSlotOrigin`.

Timer cleanup interpretation: disassembly at `0x00420db0` reads `[this+0x124]`, returns if zero, passes the stored value to `sub_597610` with `ecx=this+0xa4`, then clears `[this+0x124]`. Search over `0x0041eb90-0x00421480` found only constructor initialization at `0x0041ec17`, the helper read at `0x00420db3`, and the helper clear at `0x00420dc9` for `124h`. Constructor disassembly shows `xor eax,eax` before `mov [edi+124h], eax`, so the current local evidence proves zero initialization and clear, not a nonzero producer. The helper is a targeted timer/event cancellation helper, not a resource free, destructor helper, or generic runtime cleanup loop.

Source-facing names: `GetItemSlotOrigin`, `CancelPendingSlotTimer`, `FittingRoomSlotIndex`, `FittingRoomListDisplayMode_Rows/Grid`, `m_displayMode`, `m_timerHandler`, and `m_pendingSlotTimer` are source-quality inferred names. They are not original-symbol proof. The prior `m_pendingSlotTimerEventId` wording is behaviorally precise, but the accepted constructor formal C++ uses `m_pendingSlotTimer`; this report recommends using `m_pendingSlotTimer` in the target C++ for consistency while preserving the source-spelling cap in prose.

Point/coordinate cap: the disassembly writes through raw first/second point coordinates after `sub_4B7C30` calls. The formal source may keep the existing `point->x` / `point->y` convention, but support prose should preserve the raw coordinate evidence and keep exact `Point` member order as a confidence cap.

Generated-output pollution: target is source-bearing and has formal C++; generated output should refresh from the by-* page after a normal scoped validator callback. No generated files should be edited manually.

Rejected alternatives:

- Padding/no-code treatment is rejected because the bytes contain two valid helper-shaped bodies and a unique range signature.
- Raw `sub_` naming is rejected for source-facing docs/C++; use behavior names and keep IDA labels only as evidence.
- `FittingRoomScrollPane` ownership is rejected because the target reads list-pane display mode and list-pane timer facet state, not scroll-pane part geometry.
- Generic `TimerHandler` ownership is rejected because `0x00597610` is a callee dependency; the caller helper belongs to the list pane.
- Generic point-helper ownership is rejected because `0x004b7c30` only initializes a caller-provided point used by fitting-room slot-origin formulas.
- `FittingRoomDialog`, `FittingRoomDialogItemState`, `FittingEquipmentState`, and `ItemCatalog` direct ownership are rejected because they do not own this list-pane layout/timer receiver state.
- Parent aggregate emission is rejected because UID0000WR is a mixed UI-core index/container; exact children should carry source output.

## Evidence Standards Used

MCP evidence used: `idb_list`, `server_health`, `lookup_funcs`, `int_convert`, `get_bytes`, `make_signature_for_range`, `xref_query`, `decompile`, `disasm`, and bounded `search_text`.

Non-MCP evidence used: read-only PE byte/pointer/rel32 scan against `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`; current by-* docs; prior executed B003 source-quality report.

Evidence ladder: exact bytes/ranges/function status and xrefs are treated as hard facts. Source-facing names, field names, and source placement are inferences from receiver state, sibling methods, current class/file docs, and local call/callee behavior. Negative evidence is preserved where bounded current checks find no function object, no caller/xref route, no non-text pointer route, and no nonzero `+0x124` producer.

Why confidence is not higher: current IDA still has no modeled function records for the two helper starts, decompilation fails at the starts, no direct raw-start caller route is proven, exact original method/member spelling is absent, and `Point` layout naming remains inferred.

## Evidence Checked

IDA MCP/manual-disassembly/raw-byte checks performed:

- `idb_list` id `102`: active session `73c77998`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_analyzing:false`, worker PID `12416`.
- `server_health` id `111`: `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, Hex-Rays ready, strings cache ready.
- `lookup_funcs` id `112`: `0x00420d50`, `0x00420db0`, and `0x00420dd5` are not functions; predecessor `0x00420d00` is `sub_420D00` size `0x50`; successor `0x00420de0` is `sub_420DE0` size `0x10a`; callees `0x004b7c30` and `0x00597610` are functions.
- `int_convert` id `113`: `0x85=133`, `0x60=96`, `0x70=112`, `0x25=37`, `0x0b=11`, `0x124=292`, `0x10c=268`, `0xa4=164`, `0x14=20`, `0x1e=30`, `0x15=21`, `0x11=17`.
- `get_bytes` id `121`: predecessor tail `5d c2 04 00`, target bytes, second helper bytes, and `0x00420dd5` padding/prologue window.
- `make_signature_for_range` id `122`: exact `0x00420d50-0x00420dd5` signature is unique.
- `xref_query` id `123`: zero xrefs to `0x00420d50`, `0x00420db0`, and `0x00420dd5`; three xrefs to successor `0x00420de0`, proving the xref tool is returning local xrefs where present.
- `xref_query` id `124`: raw-start "from" queries only report internal next-head flow and no function owner.
- `decompile` ids `131` and `132`: decompilation failed at both raw starts.
- `disasm` ids `133` and `141`: rendered no-function disassembly for the origin and timer-cancel helpers.
- `search_text` ids `134`, `135`, `142`: `sub_4B7C30` calls at `0x00420d6a` and `0x00420d87`; `sub_597610` call at `0x00420dc4`.
- `search_text` ids `136`/`143`: `124h` hits only at constructor initialization `0x0041ec17`, helper read `0x00420db3`, and helper clear `0x00420dc9` in the checked list-pane range.
- `search_text` id `137`: `10Ch` hits include constructor display-mode init and UID0002DU display-mode read at `0x00420d53`.
- `search_text` id `138`: `0A4h` hits include UID0002DU timer-facet adjustment at `0x00420dbe`.
- `disasm` id `151`: constructor `0x0041eb90` shows `xor eax,eax`, display-mode init, `mov [edi+124h], eax`, and the accepted field map context.

Docs/reports checked:

- Target doc `by-memory/0x00420d50-0x00420dd5.FittingRoomListPaneSlotLayoutRawHelpers.md`
- Support docs `by-class/FittingRoomListPane.md`, `by-file/FittingRoom.md`, `by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md`, `by-memory/0x0041eb90-0x0041ecbd.FittingRoomListPaneConstructor.md`
- Sibling docs `by-memory/0x00420950-0x00420b60.FittingRoomListPaneSlotRectRawHelpers.md` and `by-memory/0x00420b60-0x00420cf9.FittingRoomListPaneHitTestSlot.md`
- Prior executed B003 slot-geometry source-quality report

Negative checks performed:

- Zero MCP xrefs to raw starts.
- Failed decompilation at raw starts.
- No local PE direct rel32 call/jump hits to `0x00420d50` or `0x00420db0`.
- No local PE non-text VA/RVA pointer hits to `0x00420d50` or `0x00420db0`.
- No nonzero `+0x124` producer found in the checked `0x0041eb90-0x00421480` list-pane range.

During the initial report-only pass, no validators were run. During the implementation callback, scoped validators were run for the two changed by-memory docs and are recorded in `## Validator Results`.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0002DU-001 | UID0002DU exact range is `0x00420d50-0x00420dd5`, size `0x85` / 133 bytes, containing two raw helper bodies. | High | MCP `lookup_funcs`, `get_bytes`, `int_convert`, `disasm`; unique signature id `122`. | Target Summary, Raw Code Evidence, Score Rationale | incorporate | applied - target Summary/Raw Code Evidence/Score Rationale now cite session `73c77998`, exact range, `0x85` / 133 size, and two subranges. |
| C-0002DU-002 | `0x00420d50`, `0x00420db0`, and `0x00420dd5` remain non-functions with failed raw-start decompilation and zero incoming xrefs. | High | MCP ids `112`, `123`, `131`, `132`; local PE route scan. | Target Raw Code Evidence, Negative Evidence | incorporate | applied - target Raw Code Evidence and Source-Quality Resolution preserve non-function/decompile-failure/zero-xref/local PE no-route proof. |
| C-0002DU-003 | `0x00420d50-0x00420db0` is a slot-origin helper using display mode `this+0x10c`, `SetPoint` callee `0x004b7c30`, row base `(30,20)`, grid base `(21,17)`, six columns, `96` horizontal stride, and `112` vertical stride. | High | MCP disasm id `133`, search_text id `134`, int_convert id `113`. | Target Behavior, First-Draft C++ | incorporate | applied - target Behavior and formal C++ record the formulas and keep `Point` spelling/order as a confidence cap. |
| C-0002DU-004 | `0x00420db0-0x00420dd5` cancels a pending timer/event through `this+0xa4` and `0x00597610`, then clears `this+0x124`. | High | MCP disasm id `141`, search_text ids `142` and `138`, bytes id `121`. | Target Behavior, Source-Quality Resolution, support docs | incorporate | applied - target Behavior/Raw Code Evidence/Source-Quality Resolution and UID0000WR row replace scratch-resource wording with targeted timer/event cancellation. |
| C-0002DU-005 | `+0x124` is initialized to zero in the constructor and cleared by UID0002DU; no nonzero local producer was found. | Medium-high | MCP disasm id `151`, search_text id `143`, constructor support doc. | Target Score Rationale and Open Questions; constructor support proof | incorporate | applied - target Behavior/Raw Code Evidence/Score Rationale record zero-init/read/clear and no nonzero producer; constructor doc was already present at same-or-greater detail. |
| C-0002DU-006 | Owner/emitter route remains UID000053 / `FittingRoomListPane`, emitted through UID0000JE / `FittingRoom.cpp`. | High | Current target metadata, class/file docs, receiver fields `+0x10c/+0xa4/+0x124`, sibling list-pane docs. | Target metadata and Source Placement; by-class/by-file support notes | incorporate | applied - target metadata preserved owner/emitter/reconstructable route; by-class and by-file already contained the class/file source route. |
| C-0002DU-007 | Target should move from `86/88` to `88/90` while preserving owner/emitter/reconstructable metadata. | Medium-high | Current MCP evidence plus current support docs; remaining no-route and name caps. | Target metadata and Score Rationale | incorporate | applied - target header now `COMPLETION:88`, `CONFIDENCE:90`; validator `000000006137` recorded completion/confidence updates. |
| C-0002DU-008 | Formal C++ is eligible and should be present as exact formal block text; use `m_pendingSlotTimer` for consistency with the accepted constructor, with exact original spelling capped. | Medium-high | Existing target C++; constructor formal C++; disasm read/clear of `+0x124`. | Target `RECONSTRUCTION_CPP CODE` block | incorporate | applied - target formal block now uses `m_pendingSlotTimer`, with exact original spelling still capped in prose. |
| C-0002DU-009 | Target stale summary phrases "scratch-resource reset" and "blank parent due attachment threshold" should be removed or historicalized. | High | Target current item summary conflicts with current evidence and metadata. | Target Item Summary, Changes | incorporate | applied - Item Summary no longer carries those current-state phrases; dated history labels old scratch-resource wording as superseded. |
| C-0002DU-010 | Parent aggregate `FittingRoomUiCore` child row is stale where it says UID0002DU "resets scratch resource state". | High | `rg` hit in `by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md` line 76. | Parent aggregate child inventory/evidence notes | incorporate | applied - UID0000WR covered-range row and change note now describe row/grid slot origins and targeted timer/event cancellation while preserving aggregate non-emitting status. |
| C-0002DU-011 | `by-class/FittingRoomListPane.md` and `by-file/FittingRoom.md` already carry the core timer-cancel/source-placement facts but lack current session `73c77998` detail. | Medium-high | Current support docs read; they already state timer facet `this+0xa4`, `+0x124` provisional timer/event id, and source route. | Support docs | already-present | already-present - by-class method row and by-file source-route note already preserve timer facet `this+0xa4`, provisional `+0x124`, first-draft/source route, and raw no-route caveat; constructor doc already names `m_pendingSlotTimer`. |
| C-0002DU-012 | Rejected alternatives must be preserved: padding/no-code, raw `sub_` names, TimerHandler/generic point-helper direct ownership, scroll-pane/dialog/item-state/catalog ownership, and parent aggregate emission. | High | Current MCP body facts and source-placement analysis. | Target and support negative evidence | incorporate | applied - target Source-Quality Resolution and Raw Code Evidence preserve no-route/non-padding/code facts; UID0000WR change preserves aggregate non-emitting index policy. |

## Positive Evidence Summary

- The range is byte-exact and unique: MCP signature for `0x00420d50-0x00420dd5` is unique, and the local PE scan also found the full body only at `0x00420d50`.
- The first helper reads list-pane `m_displayMode` at `this+0x10c` and implements the documented row/grid origin formulas.
- The second helper uses list-pane timer facet state: it reads `this+0x124`, calls `0x00597610` with `ecx=this+0xa4`, and clears `this+0x124`.
- Constructor evidence corroborates the field map: `+0x10c` initialized to grid mode, `+0xa4` is a vtable-backed secondary/timer facet, and `+0x124` is initialized from zero.
- Current class/file docs already route the source through `FittingRoomListPane` and `FittingRoom.cpp`, and sibling UID0002DT/UID0002DP docs confirm the same slot-geometry family and display-mode formulas.

## IDA MCP Facts

Function/range facts:

- `0x00420d50`, `0x00420db0`, `0x00420dd5`: not functions.
- `0x00420d00`: `sub_420D00`, size `0x50`, predecessor selection-index validator.
- `0x00420de0`: `sub_420DE0`, size `0x10a`, successor function start after padding.
- `0x004b7c30`: `sub_4B7C30`, size `0x13`, point setup helper.
- `0x00597610`: `sub_597610`, size `0x16`, TimerHandler cancel wrapper candidate in current docs.

Data/table/padding facts:

- `0x00420d4c-0x00420d50`: predecessor tail `5d c2 04 00`.
- `0x00420d50-0x00420dd5`: exact 133-byte target body, unique signature.
- `0x00420dd5-0x00420de0`: eleven `0xcc` bytes, followed by successor prologue `55 8b ec 83 ec`.

Xref facts:

- Zero incoming xrefs to `0x00420d50`, `0x00420db0`, and `0x00420dd5`.
- Successor `0x00420de0` has three code xrefs, proving the current xref query can return nearby xrefs.
- Local PE scan found no direct rel32 call/jump hits and no non-text VA/RVA pointer hits to `0x00420d50` or `0x00420db0`.

Negative IDA facts:

- Decompile failed at both raw starts.
- IDA function ownership is `<no function>` in bounded disassembly at both raw starts.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00420d50-0x00420db0` | part of UID0002DU target | `FittingRoomListPane::GetItemSlotOrigin` / `GetVisibleItemSlotOrigin` raw helper | Yes | UID000053 | Recommend target `88/90` | Source-ready, no IDA function/caller route |
| `0x00420db0-0x00420dd5` | part of UID0002DU target | `FittingRoomListPane::CancelPendingSlotTimer` raw helper | Yes | UID000053 | Recommend target `88/90` | Source-ready, no IDA function/caller route |
| `0x00420dd5-0x00420de0` | padding inside target boundary context | Alignment gap before successor | No source | N/A | N/A | Eleven `0xcc` bytes |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00420d50` | Zero incoming xrefs; no local PE direct call/jmp or non-text pointer route | Raw helper start is not proven live/reachable by current tooling. |
| `0x00420db0` | Zero incoming xrefs; no local PE direct call/jmp or non-text pointer route | Timer cleanup helper is source-shaped but still no-route. |
| `0x00420d6a`, `0x00420d87` | Calls `0x004b7c30` | Point setup for row/grid base origins. |
| `0x00420dc4` | Calls `0x00597610` | Targeted timer cancel through adjusted `this+0xa4`. |
| `0x0041ec17` | Constructor writes `[edi+124h]` from zeroed `eax` | `+0x124` zero initialization. |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- Target doc already has owner/emitter UID000053, reconstructable true, formal C++, row/grid origin formulas, and timer-cancel behavior in the main body.
- `by-class/FittingRoomListPane.md` already lists UID0002DU as slot origin and pending timer cleanup raw helpers through `this+0xa4` and provisional `this+0x124`.
- `by-file/FittingRoom.md` already states UID0002DU emits through `FittingRoom.cpp` with row/grid origin formulas and timer/event cancellation.
- Constructor doc already records `this+0xa4` as timer facet and `this+0x124` as `m_pendingSlotTimer`.

Existing docs that are stale, incomplete, or contradicted:

- Target item summary still says "scratch-resource reset" and "blank parent due attachment threshold".
- Parent aggregate UID0000WR child row still says UID0002DU "resets scratch resource state".
- The target does not cite current MCP session `73c77998` evidence.
- The target formal C++ uses `m_pendingSlotTimerEventId`, while the accepted constructor uses `m_pendingSlotTimer`.

Generated/coverage report state: no generated/coverage files were manually edited. During callback validation, the scoped validators reported deferred generated refresh and projected stats/autogen registry side effects; details are recorded in `## Validator Results`.

## Ranked Ownership Analysis

### 1. UID000053 `FittingRoomListPane`

Evidence for: target reads `this+0x10c`, uses the list-pane timer facet at `this+0xa4`, reads/clears `this+0x124`, is adjacent to list-pane input/slot geometry helpers, and is already linked by class/file docs.

Evidence against: raw helper starts lack direct caller/xref routes, so liveness is inferred from retained code and neighborhood rather than direct call evidence.

Decision: keep as canonical owner and emitter. The no-route state caps confidence but does not block source-ready formal C++.

### 2. UID0000JE `FittingRoom` file route

Evidence for: the class and sibling target docs place the whole fitting-room list-pane family in `NexusTK/cashshop/FittingRoom.cpp`; no narrower source file is established.

Evidence against: file-level ownership alone would be too broad because receiver state belongs to `FittingRoomListPane`.

Decision: keep as source module route through UID000053 emission, not as direct canonical owner for the target.

### 3. Generic `TimerHandler`

Evidence for: the cleanup helper calls `0x00597610` with `ecx=this+0xa4`.

Evidence against: `TimerHandler` is the callee/facet dependency. The actual helper reads and clears list-pane field `+0x124`.

Decision: reject direct ownership; preserve as dependency and field-layout evidence.

### 4. Rejected UI/dialog/catalog owners

`FittingRoomScrollPane`, `FittingRoomDialog`, `FittingRoomDialogItemState`, `FittingEquipmentState`, `ItemCatalog`, generic point/rect helpers, and parent aggregate UID0000WR are rejected as direct owners. They either own neighboring feature state, generic helper callees, or aggregate/index coverage rather than this list-pane receiver behavior.

## Source Placement

Recommended source placement: `FittingRoomListPane` methods emitted through UID000053 into `NexusTK/cashshop/FittingRoom.cpp` via UID0000JE.

Why this placement fits: the target uses list-pane display mode, list-pane timer-facet state, and sibling slot-geometry semantics already grouped under `FittingRoomListPane`. The broader file route is the accepted fitting-room feature file.

Rejected placements: generic UI geometry helpers, `TimerHandler`, `FittingRoomScrollPane`, `FittingRoomDialog`, `FittingRoomDialogItemState`, `FittingEquipmentState`, `ItemCatalog`, and aggregate UID0000WR.

Remaining placement uncertainty: exact original helper names and `+0x124` member spelling are not symbol-proven, but ownership/source module are strong.

## Range / Split / Padding / Reclassification Analysis

Exact range/boundary facts:

- Target half-open range stays `0x00420d50-0x00420dd5`.
- Internal helper split is `0x00420d50-0x00420db0` and `0x00420db0-0x00420dd5`.
- Predecessor `0x00420d00-0x00420d50` is modeled `sub_420D00`.
- Successor begins at `0x00420de0`; `0x00420dd5-0x00420de0` is eleven `0xcc` bytes.

Children/subranges: no new child pages are recommended. Keeping both compact raw helpers in UID0002DU is acceptable because they share class owner, source file, raw-start no-route state, and current formal C++ destination.

Padding/table/data/code distinctions: `0x00420dd5-0x00420de0` is padding. The target body bytes are code, not padding or data. No jump table belongs to UID0002DU.

Parent/container impact: UID0000WR should remain a non-emitting parent aggregate/index, but its child row should stop describing UID0002DU as scratch-resource reset.

## Negative Evidence Summary

- No modeled function objects at `0x00420d50`, `0x00420db0`, or `0x00420dd5`.
- No incoming MCP xrefs to the raw starts.
- No local PE direct rel32 call/jmp or non-text VA/RVA pointer route to the raw starts.
- Decompilation fails at both raw starts.
- No nonzero producer write to `+0x124` was found in the checked list-pane range.
- The helper does not restore vtables, delete children, free heap memory, release image/text resources, or perform base teardown; destructor/resource-cleanup interpretations are rejected.
- Callee labels `sub_4B7C30` and `sub_597610` are evidence labels only and should not appear as source-facing names in final prose or C++.

## IDA Rename / Type / Comment Recommendations

Proposed source-facing names/types/comments:

- `FittingRoomListPane::GetItemSlotOrigin(Point* point, FittingRoomSlotIndex slotIndex)`: supported by display-mode read, point helper calls, and row/grid origin formulas.
- `FittingRoomListPane::CancelPendingSlotTimer()`: supported by `+0x124` read/test, `TimerHandler` cancel call with `ecx=this+0xa4`, and `+0x124` clear.
- `FittingRoomSlotIndex`: supported by sibling UID0002DP hit-test return/miss sentinel and the 16-bit slot operand at `0x00420d5f`.
- `FittingRoomListDisplayMode_Rows` / `FittingRoomListDisplayMode_Grid`: supported by `+0x10c` constructor init and branch behavior across slot helpers.
- `m_displayMode`, `m_timerHandler`, `m_pendingSlotTimer`: supported by accepted constructor field map and UID0002DU body use.
- `SetPoint`: acceptable source-facing wrapper name for `0x004b7c30`, but it remains a dependency, not a UID0002DU-owned function.

Items intentionally left unchanged or capped:

- Do not source-name the target as `sub_420D50`, `sub_420DB0`, `sub_4B7C30`, or `sub_597610`.
- Do not create IDA functions at the raw starts from this report alone; current direct-route evidence is still negative.
- Keep exact `Point` member order/spelling, exact original helper names, and exact original `+0x124` field spelling as confidence caps.
- Keep raw IDA DB labels unchanged; IDA DB edits were not requested in the report-only pass or the implementation callback.

Whether IDA DB edits are safe: not requested. Source documentation can use inferred names, but function creation/rename/comment work would need a separate supervisor-approved IDA pass because raw-start reachability remains negative.

## First-Draft C++ Recommendation

Eligible for draft C++: yes. UID0002DU is already source-bearing and the source shape is current-session backed. The exact formal block to insert or preserve after callback is:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void FittingRoomListPane::GetItemSlotOrigin(Point* point, FittingRoomSlotIndex slotIndex)
{
    if (m_displayMode == FittingRoomListDisplayMode_Rows) {
        SetPoint(point, 30, 20);
        point->y += slotIndex * 20;
    } else {
        const int row = slotIndex / 6;
        const int column = slotIndex % 6;

        SetPoint(point, 21, 17);
        point->x += column * 96;
        point->y += row * 112;
    }
}

void FittingRoomListPane::CancelPendingSlotTimer()
{
    if (m_pendingSlotTimer != 0) {
        m_timerHandler.CancelTimer(m_pendingSlotTimer);
        m_pendingSlotTimer = 0;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Reason it preserves behavior: the first method matches the branch on `this+0x10c`, the two `SetPoint` calls, the row stride `20`, six-column grid division/modulo, horizontal stride `96`, and vertical stride `112`. The second method matches the conditional read of `+0x124`, adjusted `TimerHandler` receiver at `+0xa4`, `CancelTimer` call, and clear of `+0x124`.

Reason it matches plausible original source: it expresses compact private/list-pane helpers rather than raw IDA scaffolding, keeps common mid-2000s C++ method structure, and uses existing project source-facing names already accepted in adjacent FittingRoomListPane docs.

Inferred names used instead of IDA labels: `GetItemSlotOrigin`, `CancelPendingSlotTimer`, `Point`, `FittingRoomSlotIndex`, `FittingRoomListDisplayMode_Rows`, `m_displayMode`, `m_timerHandler`, and `m_pendingSlotTimer`.

Remaining C++ caps: exact original function names, `Point` member order/spelling, and `m_pendingSlotTimer` spelling are inferred.

## Final Recommendation

Applied under the Gate 1 implementation callback:

- Target metadata: set `COMPLETION:88`, `CONFIDENCE:90`; keep owner/emitter/reconstructable metadata unchanged.
- Target C++: replace/refresh the formal block with the exact block in this report.
- Target evidence: add current MCP session `73c77998`, range/size/bytes/signature/xref/disasm/decompile/local PE route facts, and score-limiting caps.
- Target wording: replace "scratch-resource reset" with targeted timer/event cancellation and remove "blank parent due attachment threshold" from current-state prose.
- Support docs: update `by-class/FittingRoomListPane.md`, `by-file/FittingRoom.md`, and `by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md` only where current facts are stale/missing; mark already-present where same-or-greater detail exists.
- Leave no generated files, coverage reports, lifecycle files, and supervisor ledgers untouched by B003.

Future work outside this assignment: any IDA function promotion or rename/comment pass for raw starts would require separate supervisor approval and stronger route policy.

## Recommended Target Doc Changes

Target path: `by-memory/0x00420d50-0x00420dd5.FittingRoomListPaneSlotLayoutRawHelpers.md`

Exact report facts to incorporate:

- Current MCP session `73c77998`; active `NexusTK.exe.i64`, `server_health ok`.
- `0x00420d50-0x00420dd5` exact range, `0x85` / 133 bytes, unique signature.
- `0x00420d50`, `0x00420db0`, and `0x00420dd5` remain not-functions; decompile fails at raw starts; zero xrefs to raw starts.
- First helper `0x00420d50-0x00420db0`: display mode `[ecx+10Ch]`, point helper calls at `0x00420d6a` and `0x00420d87`, row base `(30,20)`, grid base `(21,17)`, six columns, strides `96` and `112`.
- Second helper `0x00420db0-0x00420dd5`: `[this+0x124]` read/test, `this+0xa4` adjusted receiver, `0x00597610` timer cancel call at `0x00420dc4`, clear at `0x00420dc9`.
- Constructor-side proof: `0x0041ec17` initializes `+0x124` from zero; no nonzero local producer found.
- Boundary proof: predecessor tail `5d c2 04 00`, padding `0x00420dd5-0x00420de0`, successor prologue at `0x00420de0`.
- Local PE negative route scan: no direct rel32 call/jmp hits and no non-text VA/RVA pointer hits to `0x00420d50` or `0x00420db0`.

Metadata/score/C++ changes:

- Set `COMPLETION:88`.
- Set `CONFIDENCE:90`.
- Keep `CANONICAL_OWNER:000053`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:000053`.
- Keep blank `EMITTER_POSITION_OPTIONAL`.
- Refresh formal C++ block to the exact block in `## First-Draft C++ Recommendation`.

Historical/stale assumptions to preserve as rejected:

- `scratch-resource reset` is stale; current behavior is targeted timer/event cancellation.
- `blank parent due attachment threshold` is stale; current owner/emitter route is valid.
- No raw `sub_` names, generic TimerHandler ownership, generic point-helper ownership, scroll-pane ownership, dialog/item-state/catalog ownership, aggregate emission, or padding/no-code treatment.

## Recommended Support Doc Changes

Support path: `by-class/FittingRoomListPane.md`

- Current method row already records UID0002DU as slot-origin and pending timer cleanup raw helpers through `this+0xa4` with `+0x124` as provisional timer/event id.
- If accepted, add a concise current-session `73c77998` evidence note only if the supervisor wants support docs to carry the fresh session. No class metadata raise is required from this single raw no-route refresh.

Support path: `by-file/FittingRoom.md`

- Current file route already records UID0002DU under `NexusTK/cashshop/FittingRoom.cpp` with row/grid origin formulas, pending timer/event cancellation through `this+0xa4`, provisional `+0x124`, first-draft C++ readiness, and raw-start no-route caveat.
- If accepted, add current-session `73c77998` detail only if absent/stale. No file metadata raise is required.

Support path: `by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md`

- Update the UID0002DU child row from "resets scratch resource state" to source-ready slot origin plus targeted pending timer/event cancellation through `TimerHandler` facet `this+0xa4`, clearing `+0x124`.
- Preserve the parent aggregate as a non-emitting index/container; do not move C++ emission to the aggregate.

Support path: `by-memory/0x0041eb90-0x0041ecbd.FittingRoomListPaneConstructor.md`

- Already present at same-or-greater detail for `this+0xa4` as embedded/adjusted `TimerHandler` facet and `this+0x124` as `m_pendingSlotTimer`, initialized to zero and used by UID0002DU. Mark already-present unless callback requires current-session cross-reference.

Review-only sibling paths:

- `by-memory/0x00420950-0x00420b60.FittingRoomListPaneSlotRectRawHelpers.md`
- `by-memory/0x00420b60-0x00420cf9.FittingRoomListPaneHitTestSlot.md`

These are sibling evidence, not required UID0002DU support edits. Do not edit them under this callback unless supervisor explicitly broadens scope.

## Score And Metadata Recommendation

Current score/metadata:

- `COMPLETION:86`
- `CONFIDENCE:88`
- `CANONICAL_OWNER:000053`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:000053`
- Blank `EMITTER_POSITION_OPTIONAL`

Recommended score/metadata:

- `COMPLETION:88`
- `CONFIDENCE:90`
- Keep `CANONICAL_OWNER:000053`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:000053`
- Keep blank `EMITTER_POSITION_OPTIONAL`

Score rationale: completion improves because current MCP session `73c77998` reconfirms the exact range, unique bytes, function/non-function boundaries, xrefs, decompile failures, disassembly, calls, field offsets, constructor initialization, and padding while current support docs already resolve the parent/emitter route. Confidence improves because old stale blockers are gone and local PE negative route evidence agrees with MCP xrefs.

Reason not higher: no modeled function object, no direct caller/xref/PE route to raw starts, exact original helper/member names are inferred, no nonzero `+0x124` producer was found, and exact `Point` source field order/spelling remains capped.

Score-improvement attempt:

- Raw-start liveness: checked MCP xrefs/decompile/disasm and local PE route scan; no route found, cap remains.
- Field role: checked constructor disassembly and local `124h` search; zero init/read/clear found, no nonzero producer, cap remains.
- Source placement: checked target/class/file/parent/sibling docs and current MCP receiver fields; owner/emitter route remains strong and unchanged.
- C++ readiness: checked existing formal block, sibling/constructor field names, and current body evidence; first-draft C++ remains appropriate with naming caps.

## Open Questions With Attempted Resolution

| Open question | Evidence checked | Best supported resolution | Remaining cap |
| --- | --- | --- | --- |
| Are the raw starts callable/live? | MCP xrefs, lookup, decompile, local PE direct call/jmp and non-text pointer scan. | No current route proven; treat as retained source-shaped raw helpers. | Caps confidence and forbids IDA function promotion from this report alone. |
| What is `+0x124`? | Constructor disasm, search_text `124h`, UID0002DU disasm, constructor doc. | Pending slot/layout timer id/handle, source-facing `m_pendingSlotTimer`. | No nonzero local producer and exact original spelling not proven. |
| Is `0x00597610` resource cleanup? | Disasm receiver `this+0xa4`, TimerHandler support docs, no delete/free/vtable restore. | Targeted TimerHandler cancel wrapper. | Exact wrapper source name remains support-doc inferred. |
| What are point member names/order? | UID0002DU raw writes and existing formal block/support names. | Keep existing source-facing `point->x`/`point->y` formal style. | Raw first/second coordinate mapping remains a confidence cap. |
| Should the target be split? | Internal range analysis and shared owner/source route. | No split needed; two compact helpers can stay in UID0002DU. | None for current target. |

## Follow-Up Actions

Supervisor actions: perform Gate 2 verification against this callback-complete report, changed docs, and validator output; run supervisor-owned execution only after Gate 2 passes.

B003 implementation callback actions if authorized: lease only edited by-* files, apply the target/support changes above, run scoped validators for each edited by-* file, update this report's ledger/checklist, release leases, and stop before lifecycle execution.

A-agent/IDA actions: none requested. IDA DB function promotion or rename/comment work is not requested by this report.

## Confidence

Recommendation confidence: strong.

Score confidence: `88/90` is appropriate for source-ready but no-route raw helper code.

Remaining uncertainty: raw-start reachability, exact original helper names, exact `+0x124` member spelling, and exact `Point` field order.

## Validator Results

Implementation-callback scoped validators run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

| File | Command | command_id | command_timestamp | Exit | ok | Warnings/errors | Generated refresh / side effects |
| --- | --- | --- | --- | ---: | ---: | --- | --- |
| `by-memory/0x00420d50-0x00420dd5.FittingRoomListPaneSlotLayoutRawHelpers.md` | `python .\tools\validator.py --mode file --file by-memory/0x00420d50-0x00420dd5.FittingRoomListPaneSlotLayoutRawHelpers.md --apply --queue-timeout 240` | `000000006137` | `2026-07-04T05:52:23-04:00` | `0` | `1` | none reported | `generated_refresh: deferred`; validator reported `autogen_registry_update: 1`, `completion_update: 1`, `confidence_update: 1`, `projected_stats_update: 1`, `stats_row_remove: 1`, and `stats_rescore_recommended: 1`. |
| `by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md` | `python .\tools\validator.py --mode file --file by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md --apply --queue-timeout 240` | `000000006138` | `2026-07-04T05:52:28-04:00` | `0` | `1` | none reported | `generated_refresh: deferred`; validator reported `projected_stats_update: 1` and `stats_incremental_noop: 1`. |

B003 did not manually edit generated files, project-level generated files, coverage reports, validator state, lifecycle/archive files, or supervisor ledgers. The generated/projected-stat updates listed above are validator-reported side effects of scoped file validation.

## Changed Files

Created:

- `tools/leaser/Agents/Agent-B003/research/0002DU-FittingRoomListPaneSlotLayoutRawHelpers-source-quality.md`

Modified:

- `by-memory/0x00420d50-0x00420dd5.FittingRoomListPaneSlotLayoutRawHelpers.md`
- `by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md`
- `tools/leaser/Agents/Agent-B003/research/0002DU-FittingRoomListPaneSlotLayoutRawHelpers-source-quality.md`

Validator-reported side effects: scoped validation reported deferred generated refresh and projected stats/autogen registry updates as listed in `## Validator Results`. B003 did not manually edit generated files or project-level generated reports.

Report execution: not run. B003 did not run `execute_report`, dry-run/probing variants, lifecycle/archive commands, registry commands, manual report moves, generated edits, coverage edits, or validator-state edits.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation.
- [x] Target/support docs to update listed with exact scope.
- [x] Current target state and actual evidence checked recorded.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every claim.
- [x] Metadata/score changes to apply recorded: target to `88/90`, owner/emitter/reconstructable unchanged.
- [x] Score-limiting blockers researched: raw-start route, `+0x124` producer, source names, point layout, owner/emitter route.
- [x] Owner/emitter/reconstructable changes to apply: none; keep UID000053/UID000053/TRUE.
- [x] Split/rename/new-child changes to apply: no split/new child; source-facing names only.
- [x] Source-placement, range/split/padding/reclassification, and IDA rename/type/comment recommendations recorded.
- [x] First-draft C++ to apply supplied as exact formal block.
- [x] Third-party import directive confirmed not applicable.
- [x] Exact target/support doc facts to incorporate at report-level detail recorded.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve recorded.
- [x] Wave2/Wave3/historical artifacts handled as historical context only.
- [x] Open questions closed or documented as evidence-backed confidence caps.
- [x] Validators to run after callback listed.
- [x] Generated report refresh expectation recorded; no manual generated/coverage edits recommended.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation: Gate 1 passed per supervisor callback for UID0002DU.
- [x] Lease target/support by-* files only immediately before editing: leased only the target and UID0000WR aggregate support doc; both leases released after validation.
- [x] Target metadata set to `COMPLETION:88`, `CONFIDENCE:90`; owner/emitter/reconstructable/optional emitter preserved.
- [x] Target formal C++ refreshed to exact block in this report, including `m_pendingSlotTimer`.
- [x] Target evidence updated with current MCP session `73c77998`, range/size/signature/xref/decompile/disasm/local PE facts.
- [x] Target stale "scratch-resource reset" and "blank parent due attachment threshold" wording removed from current-state text or labeled as superseded history.
- [x] Target negative evidence and confidence caps preserved: raw-start no-route, no function/decompile failure, no nonzero `+0x124` producer, inferred names, and `Point` field spelling/order caps.
- [x] `by-class/FittingRoomListPane.md` reviewed and marked already-present: method row already records slot-origin and pending timer cleanup through `this+0xa4` with `+0x124` provisional timer/event id.
- [x] `by-file/FittingRoom.md` reviewed and marked already-present: file route already records UID0002DU source readiness, `FittingRoom.cpp` placement, timer/event cancellation, provisional `+0x124`, and raw-start no-route caveat.
- [x] `by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md` child row/evidence refreshed: row now states row/grid origins plus targeted pending timer/event cancellation through `this+0xa4` / `0x00597610` and `this+0x124` clear; aggregate remains non-emitting.
- [x] `by-memory/0x0041eb90-0x0041ecbd.FittingRoomListPaneConstructor.md` marked already-present: it already records `this+0xa4` timer facet and `m_pendingSlotTimer` at `+0x124`, initialized to zero and consumed by UID0002DU.
- [x] Scoped validators run for every changed by-* file and command ids/timestamps/results recorded: `000000006137` and `000000006138`, both exit `0`, `ok: 1`.
- [x] Generated refresh/freshness state recorded from validator output; no generated/manual coverage edits performed. Both validator runs reported `generated_refresh: deferred`.
- [x] Claim And Incorporation Ledger verification states updated to `applied` or `already-present` with proof for every accepted claim.
- [x] Remaining unapplied accepted items listed with exact blocker: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000006172","destination_path":"executed-b-agent-research/B003/0002DU-FittingRoomListPaneSlotLayoutRawHelpers-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0002DU-FittingRoomListPaneSlotLayoutRawHelpers-source-quality.md","timestamp":"2026-07-04T06:04:14-04:00","uid":"0002DU"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
