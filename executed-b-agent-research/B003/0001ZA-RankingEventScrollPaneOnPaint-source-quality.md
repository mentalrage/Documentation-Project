** TARGET-REPORT-UID:0001ZA **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

# 0001ZA RankingEventScrollPaneOnPaint Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: retain the implemented UID0001ZA disposition: owned and emitted by [UID:0000BO] `RankingEventScrollPane`, routed through [UID:0000MZ] `RankingDialog`, `RECONSTRUCTABLE:TRUE`, exact range unchanged, formal first-draft C++ populated.
- Final disposition: callback implementation applied. UID0001ZA now emits `void RankingEventScrollPane::OnPaint()` at `89/91`; the accepted target and four support destinations contain the report details at Rule 26 specificity.
- Required action status: complete. Stale no-code wording was replaced, binary and negative evidence were preserved, current MCP evidence was added, support docs were synchronized, all five scoped validators passed, and generated output was verified read only.
- Confidence: high for owner, emitter, boundary, control flow, resources, frame ids, geometry, field offsets, helper roles, and first-draft source shape; medium-high for exact original spellings of inferred members, enum values, and the slot-7 pane-region wrapper.

## Supporting Research

- Historical callback fact: B003 implemented and validated the accepted checklist in place and did not run report execution, lifecycle, move, or archive commands. This report does not assert any later supervisor validation/execution state or archive location; validator-owned history owns those states.
- Assignment source: `tools/leaser/Agents/Agent-B003/goal.md`, UID0001ZA from `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`.
- MCP transport session: `171e684e-a919-4155-aa8e-dde54e17127e`, initialized successfully against `ida-pro-mcp` protocol `2025-06-18`.
- Active IDB session: `359c7886`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active worker PID `13016` at the time of the evidence pass.
- `server_health` request id `4`: `status:"ok"`, module `NexusTK.exe`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
- Current generated-output observation, read only: `auto-generated/NexusTK/ui/dialogs/RankingDialog.cpp` command `000000008196`, refreshed `2026-07-12T16:15:18-04:00`, emits UID0001ZA at `Completion:89 | Confidence:91` with `RankingEventScrollPane::OnPaint()`; no empty marker remains.

## Target

- Target UID: `0001ZA`.
- Target path: `by-memory/0x00459ce0-0x0045a3f5.RankingEventScrollPaneOnPaint.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` row 1566, score `86/90`, combined `88.0`, reconstructable true, direct B-report count `0` before this report.
- Current callback classification: accepted implementation complete; independent claim-by-claim verification can proceed.
- Current scores and parent state: target `89/91`; direct class owner [UID:0000BO] remains `87/89`; file route [UID:0000MZ] remains `88/91`. All ownership/emitter gates remain satisfied.

## Current Target State

- Current metadata after callback: `COMPLETION:89`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000BO`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000BO`, blank `EMITTER_POSITION_OPTIONAL`.
- Current C++/emitter state: the formal block contains the accepted `RankingEventScrollPane::OnPaint()` body and generated `RankingDialog.cpp` emits it through the unchanged owner/file route.
- Existing behavior coverage: strong live-IDA-era documentation for the paint boundary, vtable-only route, two track passes, thumb pass, resources, direct calls, field offsets, and disabled/no-range behavior.
- Resolved blocker: the target's stale graphics/helper/member no-code wording was replaced with current accepted helper contracts and UID0000Y2/UID0000Y3 Ranking-specific field/enum evidence.
- Artifact-state wording: this report records the completed B003 callback and validation proof only. It intentionally leaves subsequent validation/execution/archive state and location to validator-owned history.

## Heuristic / Inference Reanalysis And Validation

- Paint virtual identity: the only incoming xref to `0x00459ce0` is primary vtable cell `0x00610a90`; there are no direct code callers. The body is therefore best represented as ordinary `RankingEventScrollPane::OnPaint()`, not a free helper or raw-address function.
- EPF context setup: `0x00459d03 -> 0x00457a60` initializes the 40-byte `EPFTileContext`; current support names this `InitTileContext`. This is implementation-ready and broadly shared, not Ranking-owned.
- Clip setup: `0x00459d0e -> 0x004b96c0` is accepted formal `GrafPort::GetClipRect(RectBounds *)`. The target clip local is implementation-ready as `RectBounds clipRect`.
- Rectangle helpers: `0x004b7c50`, `0x004b7cc0`, and `0x004b7e10` are accepted file-level `InitRectBounds`, `IntersectRects`, and `OffsetRect` helpers. Raw `sub_` names must not appear in target C++.
- Draw-state and pane-region calls: `0x004b9660` is accepted `GrafPort::SetDrawColor`; direct `this+0x70 = 0` is project-standard inferred `m_drawMode = 0`; slot `0x0069b3fc` is shared fill/invalidation/presentation infrastructure. Source-facing `PreparePaneRegion` is accepted by current scroll-pane and paint precedents; generated `g_pfnLockSurface` is rejected.
- Resource lookup and rendering: `0x004d02f0` is accepted `ResourceLayoutTable::LookupLayoutEntry`, and `0x004b9980` is accepted `GrafPort::RenderTileFrame`. Both have formal first-draft support and broad non-feature-local fan-in.
- Resource names: current MCP byte reads directly decode UTF-16 `SLIDEBG.EPF`, `SLIDEBG.PAL`, `SCRBUTT.EPF`, and `BUTTON.PAL`. The partial IDA label/string `aBu` is rejected as a typing artifact.
- Frame mapping: current disassembly proves vertical track fill/caps `1/0/2`, horizontal track fill/caps `4/3/5`, and thumb frames `0/1`, with frame `1` selected only when `m_highlightPart == kRankingScrollPartThumb`.
- Geometry source shape: the binary inlines page-before/page-after rectangle calculation and directly calls `GetPartRect` only for part `2` (thumb). Accepted `FittingRoomScrollPane::OnDraw`, `ScrollPane::OnDraw`, and `ScrollNewGroupPane::OnPaint` first drafts use the sibling part-rectangle helper for all track parts. Reusing `GetPartRect` here is behavior-preserving, plausible optimized C++, and avoids decompiler-shaped duplicated coordinate algebra.
- Ranking-specific fields: accepted names are `m_scrollStyle +0xfa`, `m_thumbDragActive +0xfb`, `m_orientation +0xfc`, `m_scrollPosition +0xfe`, `m_scrollRange +0x100`, `m_enabled +0x102`, `m_highlightPart +0x103`, `m_activePart +0x104`, and `m_thumbDragOffset +0x108/+0x10c`. The first draft directly names only fields needed at paint-source level; `GetPartRect` consumes the remaining geometry state.
- Part enum: use `RankingScrollPart` with `kRankingScrollPartLeading`, `kRankingScrollPartPageBeforeThumb`, `kRankingScrollPartThumb`, `kRankingScrollPartPageAfterThumb`, `kRankingScrollPartTrailing`, and `kRankingScrollPartNone`. Numeric roles `0,1,2,3,4,0xff` are evidence-backed; exact original spellings are inferred.
- Disabled/no-range path: when `!m_enabled || m_scrollRange <= 0`, the body clears the clip only if `m_scrollStyle == 0`. It sets draw color `0`, clears `m_drawMode`, dispatches the pane-region callback, and does not restore color `0x80` on that terminal path.
- Rejected alternatives: retain blank C++ under the old 95/95 policy; use direct file ownership; move to generic `ScrollPane`; emit raw decompiler geometry; use generated helper-owner aliases; split/merge the range; or leave no-owner/non-emitting.

## Evidence Standards Used

- Direct IDA MCP facts: live session health, current function lookup, decompilation, three bounded disassembly pages, complete scoped call-instruction query, xrefs, vtable/boundary bytes, resource bytes, resource xrefs, and type-catalog negative checks.
- Documentation evidence: current target/support by-* pages and accepted formal helper bodies were used to choose source-facing names after current MCP confirmed the target's raw call sites.
- Source-quality inference: accepted sibling scrollbar first drafts and plausible Visual C++ 6/7-era optimized class-method shape were used to replace inline decompiler algebra with `GetPartRect` calls.
- Negative evidence: no direct target callers, no target-specific IDA UDT/enum, no split boundary issue, broad shared resource/helper fan-in, and the generated empty marker.
- Strength assessment: direct target behavior and helper addresses are high confidence; exact original source spellings remain inferred and cap confidence below final-audit levels without blocking first-draft C++.

## Evidence Checked

- MCP setup/status: `initialize` id `1`, `tools/list` ids `2/6`, `idb_list` id `3`, and `server_health` id `4`.
- MCP target facts: `lookup_funcs` id `5`; `analyze_function` id `7`; `xref_query` id `8`; `callees` id `9`; boundary/vtable `get_bytes` id `10`; full `decompile` ids `11/12`; full target and FittingRoom comparator byte read id `13`; bounded `disasm` ids `14`, `19`, `20`, `21`; scoped target call inventory `insn_query` id `15`; resource/name and type negative checks ids `16/17`; UTF-16 resource byte read id `18`; resource xrefs id `22`.
- Target/support docs read: UID0001ZA target; [UID:0000BO] class; [UID:0000MZ] file; [UID:0000Y2] raw ctor/setters; [UID:0000Y3] mouse handler; [UID:0001ZB] part-rectangle helper; [UID:0001VO] layout; [UID:0001RK] resources; EPFTileContext, RectBounds, GrafPort draw-state/clip/render, ResourceLayout lookup, and Surface callback support pages.
- Source-shape precedents read: `FittingRoomScrollPane::OnDraw`, generic `ScrollPane::OnDraw`, and `ScrollNewGroupPane::OnPaint` formal first drafts.
- Generated/read-only state checked: research tracker, by-memory generated coverage, current generated `RankingDialog.cpp`, and its command/timestamp header.
- Old report search terms: `0001ZA`, `0x00459ce0`, `RankingEventScrollPaneOnPaint`, `RankingEventScrollPane::OnPaint`, and `RankingDialog.*OnPaint` across `executed-b-agent-research` and `tools/leaser/Agents`.
- Matching reports opened narrowly: B001 `0000XZ-RankingDialog-source-quality.md`, B004 `0000Y2-RankingEventScrollPaneRawCtorAndSetters-source-quality.md`, B006 `0000MZ-RankingDialog-empty-emitter-family-source-quality.md`, and B003 `0000Y3-RankingEventScrollPaneOnMouseEvent-source-quality.md`.
- Numeric checks: `0x716 = 1814`, `0x26 = 38`, `0x80 = 128`, and `0x110 = 272` were verified with `tools/int_convert.py`.
- Failed/unavailable checks: none required for acceptance. MCP remained healthy during the evidence pass.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID0001ZA remains owned/emitted by UID0000BO and reconstructable. | High | vtable cell `0x00610a90`, class/file route, current metadata. | target metadata/status; class/file support | already-present | already-present: target header retains UID0000BO/TRUE; class/file routes unchanged |
| C02 | Exact modeled range is `0x00459ce0-0x0045a3f6`, size `0x716`; filename inclusive end `0x0045a3f5` is correct. | High | MCP ids 5, 7, 10, 14/19-21. | target Status/Live IDA Evidence | incorporate | applied: target Status and `2026-07-12 Current MCP Recheck` |
| C03 | Target should rise from `86/90` to `89/91`. | High | current MCP pass plus resolved source-name/code blocker. | target metadata/score rationale | incorporate | applied: target headers and generated UID0001ZA row read `89/91` |
| C04 | Formal C++ should emit `void RankingEventScrollPane::OnPaint()` using the exact block below. | High | full decompile/disassembly, accepted helper contracts, sibling paint precedents. | target formal C++ block | incorporate | applied: target BEGIN/END block; generated `RankingDialog.cpp:306` |
| C05 | Track frames are vertical `fill 1, caps 0/2` and horizontal `fill 4, caps 3/5`. | High | resource-call windows at `0x459eeb`, `0x459f84`, `0x459ff5`, `0x45a1f1`, `0x45a290`, `0x45a30d`. | target behavior/C++/source notes | incorporate | applied: target Behavior, C++, current MCP section, class/file support |
| C06 | Thumb uses `SCRBUTT.EPF` frame `1` only when highlight part is `2`, otherwise frame `0`, with `BUTTON.PAL`. | High | disassembly `0x45a383-0x45a3af`, UTF-16 bytes id 18. | target behavior/C++ | incorporate | applied: target Behavior/C++/current MCP evidence and class/file support |
| C07 | Source-facing shared helpers are implementation-ready and raw/generated aliases must be rejected. | Medium-high | formal support pages plus target call inventory id 15. | target helper/source-shape notes | incorporate | applied: target Source-Shape Notes and formal C++; raw aliases retained only in evidence |
| C08 | Accepted Ranking fields/enum names are implementation-ready first-draft names. | Medium-high | UID0000Y2/UID0000Y3, layout UID0001VO, current target offsets. | target; class/layout/part-rect support | incorporate | applied: target Source-Shape, class Evidence Notes, layout table/enum, UID0001ZB contract |
| C09 | Disabled/no-range clip clear is conditional on `m_scrollStyle == 0` and does not restore draw color. | High | decompile tail and disassembly `0x45a3c4-0x45a3e6`. | target behavior/C++ | incorporate | applied: target Behavior, formal terminal branch, current MCP section |
| C10 | No split, merge, rename, or owner/emitter change is warranted. | High | exact boundary/padding, single vtable xref, coherent class family. | target range/ownership sections | already-present | already-present: headers/path/range preserved; no split/rename files created |
| C11 | Class/file support must record UID0001ZA as first-draft-ready and preserve the separate class-declaration compile-support gap. | Medium-high | generated UID0000BO empty marker and emitted UID0000Y3 precedent. | `by-class/RankingEventScrollPane.md`; `by-file/RankingDialog.md` | incorporate | applied: class method/evidence/change notes; file Proposed Contents/boundary/follow-up/change notes |
| C12 | Layout support should normalize accepted `m_*` names; UID0001ZB should adopt `GetPartRect`/Ranking enum naming and remove its stale target-blocker wording without changing its own formal C++ in this callback. | Medium-high | current support content and accepted UID0000Y3 names. | layout UID0001VO; part-rect UID0001ZB | incorporate | applied: UID0001VO field/enum tables and UID0001ZB status/part/source-shape; scores/C++ unchanged |
| C13 | Shared EPF/RectBounds/GrafPort/ResourceLayout/Surface/resource docs already contain same-or-greater detail and need no callback edit. | High | formal helper blocks and resource matrix/xrefs. | named support docs | already-present | already-present: reviewed and deliberately unchanged |
| C14 | Validator/autogen should replace UID0001ZA's generated empty marker after an authorized callback; generated files remain validator-owned. | High | pre-callback command `000000008164`; target formal block. | report/checklist and callback validation record | incorporate | applied: validator `000000008191`; generated header advanced to `000000008196` and emits body |

## Positive Evidence Summary

- Current MCP confirms a real `0x716`-byte primary-vtable paint method with one incoming data xref and no ordinary direct callers.
- The live body has complete, bounded resource, geometry, clip, draw-state, and render call evidence; the target is not blocked by unknown control flow.
- UID0000Y2 and UID0000Y3 have already accepted the Ranking field and enum naming direction needed by this body.
- Shared helper pages now carry formal source-facing APIs, removing the target's old graphics-wrapper blocker.
- Three accepted scrollbar paint bodies establish the same readable source shape and exact frame/resource mapping.

## IDA MCP Facts

- Active IDB session `359c7886`; health `ok`; `NexusTK.exe`; imagebase `0x400000`; analysis/Hex-Rays/string cache ready.
- `lookup_funcs` id `5`: `0x00459ce0 -> sub_459CE0`, size `0x716`; `0x0045a3f6` is not a function; successor `0x0045a400 -> sub_45A400`.
- `analyze_function` id `7`: 53 basic blocks, cyclomatic complexity 32, no direct callers, data xref from `0x00610a90`, and direct shared-helper callee set.
- `xref_query` id `8`: exactly one incoming xref, data cell `0x00610a90`; no direct code xrefs.
- `get_bytes` id `10`: predecessor `sub_459CD0` ends at `0x00459cd5`, followed by eleven `0xcc` bytes through `0x00459cdf`; target returns at `0x0045a3f5`, followed by ten `0xcc` bytes through `0x0045a3ff`; vtable bytes at `0x00610a90` encode target pointer `0x00459ce0`.
- Bounded disassembly ids `14/19-21`: 578 total instructions; exact enabled/range gate at `0x00459d13-0x00459d29`; orientation branch at `0x00459d6a`; thumb call `0x0045a336`; terminal style test at `0x0045a3c4`.
- `insn_query` id `15`: 44 calls in the function, including three pane-region callbacks, seven `LookupLayoutEntry` calls, seven `RenderTileFrame` calls, four `OffsetRect` calls, three `IntersectRects` calls, and one `GetPartRect` thumb call.
- Type query id `17`: no preserved `RankingEventScrollPane` or `RankingScroll` UDT/enum in current IDA; source-facing names remain evidence-backed inference.
- Resource bytes id `18`: direct UTF-16 decode gives `SLIDEBG.EPF`, `SLIDEBG.PAL`, `SCRBUTT.EPF`, and `BUTTON.PAL`.
- Resource xrefs id `22`: totals are 42, 42, 7, and 29 respectively; target contributes six, six, one, and one data refs. This supports shared art, not generic source ownership.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00459cd0-0x00459cd4` | [UID:0001Z9] | predecessor false-return virtual | TRUE | UID0000BO | 91/92 | emitted support |
| `0x00459cd5-0x00459cdf` | padding | eleven `0xcc` bytes | FALSE | none | n/a | boundary only |
| `0x00459ce0-0x0045a3f5` | [UID:0001ZA] target | primary paint virtual | TRUE | UID0000BO | recommend 89/91 | first-draft C++ |
| `0x0045a3f6-0x0045a3ff` | padding | ten `0xcc` bytes | FALSE | none | n/a | boundary only |
| `0x0045a400-0x0045a70b` | [UID:0000Y4] | hit-test helper | TRUE | UID0000BO | 86/90 | support unchanged |
| `0x0045a710-0x0045a98a` | [UID:0001ZB] | part-rectangle helper | TRUE | UID0000BO | 86/90 | naming/support sync recommended |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00610a90 -> 0x00459ce0` | sole incoming data xref | primary virtual paint slot; no direct callers |
| `0x00459d03 -> 0x00457a60` | direct call | initialize local `EPFTileContext` |
| `0x00459d0e -> 0x004b96c0` | direct call | `GetClipRect` |
| `0x00459d3a/0x0045a020 -> 0x004a9090` | direct calls | current cursor position for drag-aware inline geometry |
| `0x00459d45/0x0045a02b -> 0x005447c0` | direct calls | pane screen offset/origin |
| `0x00459e7d`, `0x0045a183`, `0x0045a345` | `IntersectRects` | clip before each draw pass |
| `0x00459ea0`, `0x0045a1a6`, `0x0045a369` | slot `0x0069b3fc` | pane-region fill/invalidation/presentation for two track passes and thumb |
| `0x00459eeb` through `0x0045a30d` | six track layout calls | vertical/horizontal fill and cap frames |
| `0x00459f27` through `0x0045a329` | six track render calls | repeated strip and cap rendering |
| `0x0045a336 -> 0x0045a710` | direct call with part `2` | thumb rectangle |
| `0x0045a393/0x0045a3af` | thumb lookup/render | `SCRBUTT.EPF` with `BUTTON.PAL` |
| `0x0045a3d1/0x0045a3e0` | terminal clear calls | clear disabled/no-range clip only when style byte is zero |

## Documentation Evidence And IDA Status

- The target page already records most binary behavior correctly, including the two inline track passes and single thumb-helper call.
- The stale part is source readiness: shared helper docs have since advanced to formal first-draft APIs, and UID0000Y2/UID0000Y3 accepted the Ranking-specific names.
- [UID:0000BO] correctly owns the method and routes through [UID:0000MZ], but its OnPaint row still reflects the old blank-code state.
- [UID:0001VO] has all offsets but mixes generic labels with the accepted `m_*` names now used by UID0000Y3.
- [UID:0001ZB] has exact geometry and caller evidence but still says its method/enum names are provisional. It should accept `GetPartRect(RankingScrollPart, RectBounds *)` as the declaration-level source-facing contract required by UID0000Y3 and UID0001ZA; its own full body remains outside this target callback.
- [UID:0001RK] already has exact resources, package provenance, shared-consumer caveats, and current xref totals. No edit is required.
- Shared EPFTileContext, RectBounds, GrafPort, ResourceLayout, and Surface pages already contain same-or-greater helper contracts and should not receive duplicate Ranking-specific text.

## Ranked Ownership Analysis

### 1. [UID:0000BO] RankingEventScrollPane

- Evidence for: primary vtable slot `0x00610a90`, receiver-local fields, local helper family, class construction/vtable evidence, and existing canonical owner/emitter metadata.
- Evidence against: no direct callers; class-level declaration block remains empty.
- Decision: retain as direct semantic owner and emitter. Vtable-only reachability is expected and the class declaration gap is a compile-support issue, not an ownership defect.

### 2. [UID:0000MZ] RankingDialog file route

- Evidence for: accepted ranking feature source grouping and final generated path `NexusTK/ui/dialogs/RankingDialog.cpp`.
- Evidence against: file route is not the direct semantic class owner.
- Decision: retain as upstream file emitter through UID0000BO; do not assign the target directly to UID0000MZ.

### 3. Generic ScrollPane/FittingRoom/Group scrollbar owners

- Evidence for: highly similar field layout, resources, frame mapping, and first-draft paint shape.
- Evidence against: distinct vtables, construction routes, owners, and helper addresses; shared art/helpers do not prove shared class ownership.
- Decision: reject as owner; use only as source-shape and naming precedent.

### 4. Shared rendering/resource modules

- Evidence for: EPFTileContext, RectBounds, GrafPort, ResourceLayout, and Surface own direct callees and resources.
- Evidence against: dependency direction is from the feature paint virtual to broad shared helpers; target receiver and vtable remain Ranking-specific.
- Decision: reject as target owner.

### 5. No-owner/non-emitting

- Evidence for: no direct callers and current generated empty marker.
- Evidence against: valid vtable route, valid emitter chain, reconstructable source behavior, combined score above 85, and resolved source-facing APIs.
- Decision: reject. If forced away from the accepted owner, UID0000MZ would be the next route, but direct class ownership is substantially stronger.

## Source Placement

- Recommended placement: `RankingEventScrollPane::OnPaint()` in `NexusTK/ui/dialogs/RankingDialog.cpp`, emitted through UID0000BO -> UID0000MZ.
- Why this fits: the class is a private ranking event-list scrollbar; constructor/vtables/interaction/geometry/paint methods form one local class family inside the ranking feature range.
- Rejected placements: generic `ui/core/ScrollBar.cpp`, FittingRoom source, Group source, GrafPort/Surface render modules, resource modules, or a standalone address-derived file.
- Remaining uncertainty: the exact historical source filename could have been a smaller ranking control file. Current accepted project grouping still makes `RankingDialog.cpp` the best source route and no current evidence warrants route churn.

## Range / Split / Padding / Reclassification Analysis

- Exact range: modeled function `0x00459ce0-0x0045a3f6`, size `0x716` / 1814 bytes (Verified with `tools/int_convert.py`).
- Filename endpoint: `0x0045a3f5` is the final function byte; no filename correction is needed.
- Predecessor: UID0001Z9 ends at `0x00459cd5`, followed by eleven `0xcc` bytes before the target.
- Successor: target return ends at `0x0045a3f6`, followed by ten `0xcc` bytes before UID0000Y4 at `0x0045a400`.
- Split decision: no split, merge, child creation, rename, or reclassification. The target is one coherent primary virtual method.
- Inline geometry is compiler/source-shape evidence, not a reason to split track calculations into address children.

## Negative Evidence Summary

- No direct code callers exist; the sole incoming reference is the primary vtable data cell. This rejects ordinary helper/free-function reachability but supports virtual class ownership.
- No preserved Ranking-specific UDT/enum names exist in the current IDA type catalog. Exact spelling claims must remain inferred.
- Resource literals have broad cross-feature xrefs. They support visible behavior and frame selection, not generic scrollbar ownership.
- The current generated empty marker reflects the blank formal block, not a valid no-code proof.
- The older B006 report listed UID0001ZA among follow-up modeled bodies because names/APIs were unresolved at that time. It did not establish a permanent no-code disposition; current helper and UID0000Y2/UID0000Y3 work resolves those named blockers.
- Full-byte comparison with the same-sized FittingRoom paint routine was not identical and is not used as clone proof. The source-shape precedent rests on independently confirmed matching semantics/resources/frame mapping, not byte identity.

## IDA Rename / Type / Comment Recommendations

- No IDA DB edits are requested or authorized.
- Source-facing target method: `RankingEventScrollPane::OnPaint`.
- Source-facing type/helper names: `EPFTileContext`, `RectBounds`, `RankingScrollPart`, `GetPartRect`, `InitTileContext`, `GetClipRect`, `IntersectRects`, `OffsetRect`, `SetDrawColor`, `PreparePaneRegion`, `LookupLayoutEntry`, and `RenderTileFrame`.
- Source-facing fields: `m_scrollStyle`, `m_thumbDragActive`, `m_orientation`, `m_scrollPosition`, `m_scrollRange`, `m_enabled`, `m_highlightPart`, `m_activePart`, `m_thumbDragOffset`, `m_bounds`, and inherited `m_drawMode`.
- Exact original spellings remain inferred. Raw IDA labels and generated caller-biased helper names must remain evidence aliases only.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. UID0001ZA is reconstructable, has a nonblank valid emitter route, has combined score `88`, and current evidence resolves each named source-quality blocker into an accepted helper/name or explicit confidence cap.
- Recommended exact formal `RECONSTRUCTION_CPP CODE` insertion text:

```cpp
void RankingEventScrollPane::OnPaint()
{
    EPFTileContext tile;
    RectBounds clipRect;
    RectBounds partRect;
    RectBounds drawRect;
    RectBounds stripRect;

    InitTileContext(&tile);
    GetClipRect(&clipRect);

    if (m_enabled && m_scrollRange > 0) {
        const bool horizontal = (m_orientation != 0);
        const RankingScrollPart trackParts[2] = {
            kRankingScrollPartPageBeforeThumb,
            kRankingScrollPartPageAfterThumb
        };

        for (int i = 0; i < 2; ++i) {
            const RankingScrollPart part = trackParts[i];

            GetPartRect(part, &partRect);
            if (!IntersectRects(&drawRect, &partRect, &clipRect)) {
                continue;
            }

            m_drawMode = 0;
            SetDrawColor(0);
            PreparePaneRegion(&drawRect);
            SetDrawColor(0x80);

            const int fillFrame = horizontal ? 4 : 1;
            const int capFrame = horizontal
                ? (part == kRankingScrollPartPageBeforeThumb ? 3 : 5)
                : (part == kRankingScrollPartPageBeforeThumb ? 0 : 2);

            g_pEPFLib->LookupLayoutEntry(L"SLIDEBG.EPF", fillFrame, &tile);

            stripRect = drawRect;
            if (horizontal) {
                stripRect.right = stripRect.left + 1;
                while (stripRect.left < drawRect.right) {
                    RenderTileFrame(&tile,
                                    &tile.bounds,
                                    &stripRect,
                                    1,
                                    L"SLIDEBG.PAL",
                                    0);
                    OffsetRect(&stripRect, 1, 0);
                }
            } else {
                stripRect.bottom = stripRect.top + 1;
                while (stripRect.top < drawRect.bottom) {
                    RenderTileFrame(&tile,
                                    &tile.bounds,
                                    &stripRect,
                                    1,
                                    L"SLIDEBG.PAL",
                                    0);
                    OffsetRect(&stripRect, 0, 1);
                }
            }

            g_pEPFLib->LookupLayoutEntry(L"SLIDEBG.EPF", capFrame, &tile);
            RenderTileFrame(&tile,
                            &tile.bounds,
                            &drawRect,
                            1,
                            L"SLIDEBG.PAL",
                            0);
        }

        GetPartRect(kRankingScrollPartThumb, &partRect);
        if (IntersectRects(&drawRect, &partRect, &clipRect)) {
            m_drawMode = 0;
            SetDrawColor(0);
            PreparePaneRegion(&drawRect);
            SetDrawColor(0x80);

            const int frame =
                (m_highlightPart == kRankingScrollPartThumb) ? 1 : 0;
            g_pEPFLib->LookupLayoutEntry(L"SCRBUTT.EPF", frame, &tile);
            RenderTileFrame(&tile,
                            &tile.bounds,
                            &drawRect,
                            1,
                            L"BUTTON.PAL",
                            0);
        }

        return;
    }

    if (m_scrollStyle == 0) {
        SetDrawColor(0);
        m_drawMode = 0;
        PreparePaneRegion(&clipRect);
    }
}
```

- Behavior preservation: the body keeps the enabled/range gate, two clipped track passes, exact vertical/horizontal frame map, one-pixel strip tiling, thumb clip/draw pass, highlight-dependent frame, and terminal style-gated clip clear.
- Source-shape rationale: use of `GetPartRect` for constant track parts matches accepted sibling source and plausibly explains optimized inline track geometry while preserving one direct out-of-line thumb call in the binary.
- Original-source plausibility: ordinary class method, stack locals, fixed two-part loop, explicit resource names, and shared render APIs fit late-1990s/early-2000s human-written C++ substantially better than duplicated SSE/decompiler temporaries.
- Naming/coding convention: follows accepted UID0000Y3 `RankingScrollPart`/`m_*` names and accepted shared helper contracts.
- No-code proof: not applicable. The separate missing UID0000BO class declaration is a generated compile-completeness support requirement, not a valid reason to keep this exact eligible method blank.

## Final Recommendation

- Retain the applied target C++ and `89/91` score.
- Keep `CANONICAL_OWNER:0000BO`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000BO`, blank optional position, filename, range, and source route unchanged.
- Retain the applied stale-language repair, current direct/negative evidence, and report-level support synchronization in UID0000BO, UID0000MZ, UID0001VO, and UID0001ZB.
- Generated files remain validator-owned; shared helper docs and unrelated Ranking methods remain deliberately unchanged.

## Recommended Target Doc Changes

- Implementation state: all accepted target recommendations below are applied.
- Target path: `by-memory/0x00459ce0-0x0045a3f5.RankingEventScrollPaneOnPaint.md`.
- Metadata: set `COMPLETION:89`, `CONFIDENCE:91`; leave owner/emitter/reconstructable/position unchanged.
- Formal source: insert the exact block from `First-Draft C++ Recommendation`.
- Item Summary: add current MCP IDB session `359c7886`, size/end, vtable-only xref, no direct callers, call count, exact resources/frame map, and first-draft-ready disposition.
- Status/Behavior/Live IDA Evidence: add current request facts; preserve inline geometry and disabled/no-range evidence.
- Source-Shape Notes: replace stale blank-code wording with accepted helper/name rationale, explicit inferred-name caveats, and class-declaration support dependency.
- Changes: add a dated callback entry describing before/after metadata, source insertion, evidence, and generated expectation.

## Recommended Support Doc Changes

- Implementation state: all four accepted support destinations below are applied; same-or-greater shared support docs were verified and left unchanged.
- `by-class/RankingEventScrollPane.md`: change the OnPaint method row from behavior-only wording to source-ready first-draft status; add accepted paint helper/resource/frame names; preserve class-level blank C++ as a separate declaration-support issue and list the method declaration needed for generated compile completeness.
- `by-file/RankingDialog.md`: the `RankingEventScrollPane` proposed-contents row and changes note now record UID0001ZA emission through the class/file route; UID0000BO declaration support remains a separate requirement.
- `by-type/by-struct/RankingEventScrollPaneLayout.md`: normalize local fields to accepted names `m_scrollSkinIndex`, `m_scrollStyle`, `m_thumbDragActive`, `m_orientation`, `m_scrollPosition`, `m_scrollRange`, `m_enabled`, `m_highlightPart`, `m_activePart`, and `m_thumbDragOffset`; add source-facing `RankingScrollPart` value names while preserving inferred-name caveats. Metadata can remain `85/89` unless callback review finds independently scoreable new evidence.
- `by-memory/0x0045a710-0x0045a98a.RankingEventScrollPaneGetScrollRegionRect.md`: record source-facing declaration/name direction `GetPartRect(RankingScrollPart part, RectBounds *outRect)` and replace wording that treats part enum/type naming as a UID0001ZA blocker. Keep its own formal C++ and `86/90` metadata unchanged in this callback because this report supplies target paint code, not the full helper body.
- `by-resource/ranking-ui-resources.md`: already same-or-greater detail for resource names, frame counts, package provenance, ownership boundaries, and xref totals; no edit.
- EPFTileContext, RectBounds, GrafPort draw-state/clip/render, ResourceLayout lookup, Surface callback, EventMan, and pane screen-offset support docs: already same-or-greater detail; no edit.
- `by-type/by-vtable/RankingEventScrollPaneVtables.md`: existing slot evidence is sufficient; no edit unless callback detects a direct contradiction.
- Generated `auto-generated/NexusTK/ui/dialogs/RankingDialog.cpp`, research tracker, and generated coverage: validator-owned refresh only; no manual edits.

## Score And Metadata Recommendation

- Pre-callback score/metadata: `86/90`, owner/emitter UID0000BO, reconstructable true, formal C++ blank.
- Applied score/metadata: `89/91`, owner/emitter/reconstructable/position unchanged, formal C++ populated.
- Reason higher: current MCP reconfirms all material target facts; resource decoding and frame mapping are exact; helper contracts are now formalized; Ranking field/enum names are accepted; first-draft code captures the full behavior.
- Reason not higher: exact original method/member/enum/helper spellings are not symbol-proven; target source intentionally uses helper calls where optimized binary track geometry is inline; UID0000BO declaration support and UID0001ZB full body remain incomplete for compile-complete final output.
- Score-improvement attempt: resolved every in-scope blocker named by the assignment. Resources, draw helpers, EPF setup, clip/intersect/offset helpers, pane-region call, orientation/frame math, field names, source placement, range, owner/emitter, and C++ readiness all have implementation-ready outcomes.
- No rare unchanged-score exception is used.

## Open Questions With Attempted Resolution

- Exact original paint name (`OnPaint` versus `OnDraw`): primary vtable behavior and current Ranking documentation support `OnPaint`; sibling source uses both conventions. Use `OnPaint` for project consistency; exact PDB spelling remains a confidence cap.
- Exact slot-7 wrapper name: current docs support `PreparePaneRegion` and some callers use `FillRect`. Scroll-pane paint precedents use `PreparePaneRegion`, so that is selected. Raw `dword_69B3FC` and `g_pfnLockSurface` are rejected.
- Exact part enum spelling: no IDA UDT exists. Numeric mapping and UID0000Y3 precedent justify `RankingScrollPart` names for first draft.
- Inline versus helper geometry: current binary inlines track math but calls the part helper for thumb. Accepted sibling source proves helper reuse is an implementation-ready, behavior-preserving first-draft shape; exact optimizer/source provenance remains a confidence cap.
- Class declaration support: UID0000BO remains an empty marker. Required support is concrete: declare `RankingScrollPart`, fields/method surface including `OnPaint` and `GetPartRect`, and inherited APIs needed by emitted children. This does not block target source insertion.
- Remaining unresolved questions: only exact historical spellings and original file split remain. Neither changes behavior, ownership, range, score recommendation, or current C++ eligibility.

## Follow-Up Actions

- Independent verification: compare C01-C14 against the five changed by-* docs, generated UID0001ZA body, validator outputs, and checked implementation checklist.
- Any later validation, execution, lifecycle-history, or archive-location state is outside this callback record and belongs to validator-owned history.

## Confidence

- Recommendation confidence: high.
- Score confidence: high for `89/91`; do not raise to `95+` while exact original names, optimized-source provenance, and class declaration completeness remain unverified.
- Remaining uncertainty: source spelling and historical file granularity, not target behavior or route.

## Validator Results

- Target: `python .\tools\validator.py --mode file --file by-memory/0x00459ce0-0x0045a3f5.RankingEventScrollPaneOnPaint.md --apply --queue-timeout 240 --wait-generated`
  - `command_id: 000000008191`; `command_timestamp: 2026-07-12T16:14:32-04:00`; exit `0`; `ok: 1`.
  - Applied completion `89`, confidence `91`, registry `blank -> block`, generated C++ update, tracker/coverage/projected-stat refresh, and completed generated refresh.
- Class: `python .\tools\validator.py --mode file --file by-class/RankingEventScrollPane.md --apply --queue-timeout 240`
  - `command_id: 000000008192`; `command_timestamp: 2026-07-12T16:14:54-04:00`; exit `0`; `ok: 1`; generated refresh deferred.
- File: `python .\tools\validator.py --mode file --file by-file/RankingDialog.md --apply --queue-timeout 240`
  - `command_id: 000000008193`; `command_timestamp: 2026-07-12T16:14:59-04:00`; exit `0`; `ok: 1`; generated refresh deferred.
  - Fourteen `missing_ref_uid` diagnostics for pre-existing UID0003X6/0003X7/0003X8/0003X9 references remain unrelated to UID0001ZA; no target-specific failure occurred and validator state was not hand-edited.
- Layout: `python .\tools\validator.py --mode file --file by-type/by-struct/RankingEventScrollPaneLayout.md --apply --queue-timeout 240`
  - `command_id: 000000008194`; `command_timestamp: 2026-07-12T16:15:08-04:00`; exit `0`; `ok: 1`; by-type stats row refreshed; generated refresh deferred.
- Part rectangle: `python .\tools\validator.py --mode file --file by-memory/0x0045a710-0x0045a98a.RankingEventScrollPaneGetScrollRegionRect.md --apply --queue-timeout 240`
  - `command_id: 000000008196`; `command_timestamp: 2026-07-12T16:15:18-04:00`; exit `0`; `ok: 1`; generated refresh deferred.
- Final generated freshness: `auto-generated/NexusTK/ui/dialogs/RankingDialog.cpp` header is command `000000008196`, timestamp `2026-07-12T16:15:18-04:00`, equal to the latest validator and newer than target command `000000008191`. UID0001ZA emits at generated lines `305-306+` with no empty marker.

## Changed Files

- Created earlier in the accepted report pass: `tools/leaser/Agents/Agent-B003/research/0001ZA-RankingEventScrollPaneOnPaint-source-quality.md`.
- Modified in callback: `by-memory/0x00459ce0-0x0045a3f5.RankingEventScrollPaneOnPaint.md`, `by-class/RankingEventScrollPane.md`, `by-file/RankingDialog.md`, `by-type/by-struct/RankingEventScrollPaneLayout.md`, `by-memory/0x0045a710-0x0045a98a.RankingEventScrollPaneGetScrollRegionRect.md`, and this report's ledger/checklist/proof sections.
- Renamed: none.
- Historical callback boundary: B003 ran no report execution, registry lifecycle, move, or archive command. Later lifecycle state/location is not asserted here.
- Generated/coverage files: changed only through the documented validator pipeline; no manual edits.
- Leases: all five accepted by-* files were leased as `B003` for the immediate edit/validator batch and successfully released after validation. Final lease report contains no B003 lease.

## Implementation Tracking Checklist

- [x] Accepted Gate 1 report SHA verified before implementation: `B69B7F728E27B94D05134D4BFA9F6FA06B33CF87BEB93C79B53BD9A4F41125BE`.
- [x] Leased only the exact five accepted by-* files for the immediate edit/validator batch; all five unlease commands returned `Success`, and final lease report has no B003 entries.
- [x] Updated UID0001ZA from `86/90` to `89/91`; owner/emitter/reconstructable/position/range remain unchanged.
- [x] Inserted the exact formal `RankingEventScrollPane::OnPaint()` block into UID0001ZA.
- [x] Replaced stale target no-code wording and added current MCP session `359c7886`, function/xref/boundary/call/resource/frame evidence.
- [x] Preserved target negative evidence: vtable-only reachability, no direct callers, no preserved UDT/enum, broad shared resource/helper fan-in, and rejected generic/no-owner routes.
- [x] Updated `by-class/RankingEventScrollPane.md` with first-draft OnPaint status, accepted helper/resource/frame names, and separate class declaration support requirement.
- [x] Updated `by-file/RankingDialog.md` with UID0001ZA output through UID0000BO while preserving class/file ownership distinction.
- [x] Updated `by-type/by-struct/RankingEventScrollPaneLayout.md` with accepted inferred `m_*` names and `RankingScrollPart` values without claiming recovered symbols.
- [x] Updated UID0001ZB with declaration-level `GetPartRect`/`RankingScrollPart` naming and removed stale UID0001ZA-blocker wording; its formal C++ and `86/90` score remain unchanged.
- [x] Confirmed ranking resources, EPFTileContext, RectBounds, GrafPort, ResourceLayout, Surface, EventMan, pane screen-offset, and vtable support already contain same-or-greater detail; no duplicate edits made.
- [x] Updated every C01-C14 ledger row to `applied` or `already-present` with path/section proof; no accepted claim is blocked or excluded.
- [x] Ran scoped validators for every edited by-* file; commands `000000008191`, `8192`, `8193`, `8194`, and `8196` all exited `0` with `ok: 1`.
- [x] Verified generated `RankingDialog.cpp` command/timestamp `000000008196` / `2026-07-12T16:15:18-04:00` is current and UID0001ZA no longer has an empty marker.
- [x] Confirmed no manual generated, coverage, tracker, validator-state, IDA DB, report lifecycle, move, or archive edits/commands occurred.
- [x] Callback implementation, report proof, scoped validation, generated-freshness review, and lease release are complete for independent verification.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000008223","destination_path":"executed-b-agent-research/B003/0001ZA-RankingEventScrollPaneOnPaint-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0001ZA-RankingEventScrollPaneOnPaint-source-quality.md","timestamp":"2026-07-12T16:32:03-04:00","uid":"0001ZA"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
