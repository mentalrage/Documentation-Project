** TARGET-REPORT-UID:0001FW **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# UID0001FW RegionAndMotionRect Source-Quality Report

** TARGET-DOC:** `by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md`
** ASSIGNMENT-MODE:** Medium B-agent report-only research; implementation callback applied after Gate 1
** REPORT-PATH:** `tools/leaser/Agents/Agent-B014/research/0001FW-RegionAndMotionRect-source-quality.md`
** STATUS:** Implementation callback applied; ready for supervisor execution review. B014 edited only accepted by-* docs plus this report, ran scoped file validators, did not manually edit generated files, coverage reports, validator state, lifecycle/archive files, or supervisor ledgers, and did not run `execute_report`.

## Finalized Report / Current Recommendation

- Current recommendation: UID0001FW has been implemented as source-ready for `NexusTK/ui/core/Region.cpp`, with target metadata now `90/91`, owner/emitter metadata preserved as `0000N3`, and the target formal C++ block populated with the source-shaped Region/Motion rectangle helper bodies in this report.
- Final disposition: callback implementation complete and ready for supervisor Gate 2 / execution review. The previous blank-C++ state is superseded in the target/support docs; remaining uncertainties are confidence caps, not blockers.
- Required action: supervisor should verify the changed docs claim-by-claim and then run the supervisor-owned report lifecycle command if Gate 2 passes. B014 must not run `execute_report` or move/archive this report.
- Confidence: high for behavior, range, owner/emitter, and source placement; medium-high for exact source spellings because IDA did not recover local `Region`, `Motion`, or project `RectBounds` UDT/source names.

## Executive Recommendation

UID0001FW is source-ready with a first-draft formal C++ block for the Region/Motion dirty-rectangle helpers in `NexusTK/ui/core/Region.cpp`. The current blank-C++ state is no longer justified by the live MCP evidence: every named modeled function in `0x00554680-0x00554b38` has straightforward rectangle-helper behavior, strong caller coverage, stable helper semantics, and a consistent `RectBounds` layout.

Implemented target metadata after supervisor callback:

| Field | Current | Recommended |
| --- | --- | --- |
| `COMPLETION` | `86` | `90` |
| `CONFIDENCE` | `88` | `91` |
| `CANONICAL_OWNER` | `0000N3` | keep `0000N3` |
| `RECONSTRUCTABLE` | `TRUE` | keep `TRUE` |
| `EMITTER_UIDS` | `0000N3` | keep `0000N3` |
| `EMITTER_POSITION_OPTIONAL` | blank | keep blank |

The score should not go higher yet because IDA still has no recovered local `Region`, `Motion`, or project `RectBounds` UDT records, the exact original source spelling for a few methods is inferred, and the four raw helper children already emit direct bodies through their child pages. These are confidence caps, not blockers to a source-shaped first draft.

## Supervisor Active Recheck

This report began as the current Agent-B014 `goal.md` Medium report-only assignment for UID0001FW and later received a supervisor implementation callback after Gate 1 passed. The MCP evidence remains from the accepted report pass; the callback phase incorporated those accepted facts into the target/support docs.

B014 complied with the relevant phase boundaries:

| Check | Result |
| --- | --- |
| Current IDA MCP available | Yes |
| Fallback-only report | No |
| by-* docs edited | Report-only phase: no; implementation callback: yes, accepted target/support docs only |
| generated files edited | Manual edits: no; validator refreshed generated output |
| coverage reports edited | No |
| validator state edited | Manual edits: no; scoped validators reported registry/stat side effects |
| report lifecycle / `execute_report` run | No |
| IDA process/session management mutation | No |
| subagents spawned | No |
| implementation callback by-* edits | Yes, only accepted target/support docs |
| scoped file validators | Yes, changed by-* docs only |

MCP session evidence:

| MCP call | Result |
| --- | --- |
| `idb_list` | Active session `nexustk_supervisor_20260704`, backend `worker`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active/adopted, worker PID `10024`, not analyzing |
| `server_health` | `status: ok`; active module `NexusTK.exe`; imagebase `0x400000`; `auto_analysis_ready: true`; `hexrays_ready: true`; strings cache ready |

## Target

Target path: `by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md`

Pre-callback, the target was a reconstructable, owned, blank-C++ aggregate for the Region/Motion dirty-rectangle helper island at `86/88`. Post-callback, B014 updated it to `COMPLETION:90`, `CONFIDENCE:91`, preserved `CANONICAL_OWNER:0000N3`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N3`, and blank emitter position, and inserted the formal source C++ block from this report.

The target table and notes now incorporate current MCP evidence, the missing padding row at `0x00554715-0x00554720`, the stale `Motion::GetNormalizedRect` replacement with `Motion::IntersectWithRect`, the predicate nature of `Region::IntersectsRect`, scalar-deleting-wrapper evidence for source `Region::~Region()`, child-body non-duplication, rejected alternatives, and confidence caps.

## Supporting Research

This report used current MCP-backed evidence plus existing local documentation. Historical reports were used only as leads unless they had already been executed into by-* pages.

Direct local support reviewed:

| Document | Relevance |
| --- | --- |
| `by-file/Region.md` | Source placement already routes dirty-region Region/Motion helpers to `NexusTK/ui/core/Region.cpp`; callback updated it to mark UID0001FW source-ready while preserving caveats. |
| `by-class/Region.md` | Region class support, vtable/source placement, and scalar-deleting destructor context; callback removed the UID0001FW blank-C++ blocker while preserving class caveats. |
| `by-file/Motion.md` | Distinguishes dirty-region `Motion` helpers from timer/animation `Motion`; callback records this dirty-rectangle island as source-ready through UID0001FW. |
| `by-class/Motion.md` | Method inventory for dirty-region rectangle methods; callback reconciles inferred source names with current target rows. |
| `by-memory/0x00554a20-0x00554adb.RegionRawRectangleHelpers.md` | Existing aggregate for raw helper pocket created by UID0002R9; confirms the raw child helpers are separate child emitters and should not be duplicated in UID0001FW formal C++. |
| `by-memory/0x00554a20-0x00554a3c.MotionIntersectsRaw.md` | Already emits `Motion::Intersects(const Motion&) const` via child page. |
| `by-memory/0x00554a40-0x00554a56.MotionContainsRectRaw.md` | Already emits `Motion::ContainsRect(const RectBounds*) const` via child page. |
| `by-memory/0x00554a60-0x00554a9b.MotionContainsMotionRaw.md` | Already emits `Motion::Contains(const Motion&) const` via child page. |
| `by-memory/0x00554aa0-0x00554adb.MotionSameBoundsRaw.md` | Already emits `Motion::HasSameBoundsAs(const Motion&) const` via child page. |
| `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md` | Confirms helper semantics for init/intersect/union/offset/empty/contains/equivalent rectangle routines. |
| `by-type/by-struct/RectBoundsLayout.md`, `by-class/RectBounds.md`, `by-file/RectBounds.md` | Confirms `RectBounds` as four 32-bit fields `left/top/right/bottom` with size `0x10`. |

Historical research leads reviewed:

| Report | Use in this report |
| --- | --- |
| `executed-b-agent-research/B008/0002R9-RegionRawRectangleHelpers-source-quality.md` | Executed prior work. Confirms raw child split, child helper C++, and support sync. Used as accepted history, not as a substitute for current MCP evidence. |
| `tools/leaser/Agents/Agent-B012/research/0003A3-ScreenPanePresentationTraversal-source-quality.md` | Stale/unexecuted lead only. Its Region/Motion dirty-region observations align with current docs but are not relied on for scoring. |
| `tools/leaser/Agents/Agent-B002/research/0002QG-0002QL-0002QM-0002QN-MapPaneQueue...md` | Historical lead only. The old report had MCP limitations; current by-* pages and fresh MCP evidence carry this report. |

## Current Target State

Pre-callback, the target was source-bearing but still emitted an empty marker. Historical generated output `auto-generated/NexusTK/ui/core/Region.cpp` was last seen with validator command `000000006307`, refreshed `2026-07-04T12:41:41-04:00`, and contained direct child bodies for UID00042Q/UID00042R/UID00042S/UID00042T plus an empty UID0001FW marker.

Post-callback, scoped validators refreshed generated `auto-generated/NexusTK/ui/core/Region.cpp` with header `validator-command-id: 000000006426`, `validator-refreshed-at: 2026-07-04T18:25:34-04:00`. The generated file contains one UID0001FW body at `90/91` and one copy each of UID00042Q, UID00042R, UID00042S, and UID00042T child bodies.

The current target child table is mostly accurate but needs these callback changes:

| Range | Current issue | Recommended state |
| --- | --- | --- |
| `0x00554715-0x00554720` | Padding gap omitted | Add explicit `0xcc` boundary padding row. |
| `0x005547e0-0x005547f7` | Current/source name says `Motion::GetNormalizedRect` | Historicalize/reject this name; decompile is in-place raw-rect intersection, recommended source-facing name `Motion::IntersectWithRect`. |
| `0x00554a00-0x00554a18` | Current/source name can read like mutating intersection | Record predicate semantics: `Region::IntersectsRect(const RectBounds*) const`; output pointer is `NULL`. |
| `0x00554a20-0x00554adb` | Raw helper pocket already split to child emitters | Preserve child direct bodies; do not duplicate them in UID0001FW formal C++. |
| `0x00554b00-0x00554b38` | Binary is scalar-deleting wrapper | Source should be empty `Region::~Region()` body; wrapper mechanics remain compiler-output evidence, not hand-written source. |

## Evidence Standards Used

This report used the current B-agent evidence ladder: direct MCP facts first, current by-* docs and generated output as local project evidence, executed B-agent reports as accepted history, and unexecuted reports only as leads. Inferred source names/types were accepted only where direct behavior, layout, callers, and support docs converged.

Evidence standards applied:

| Standard | Application to UID0001FW |
| --- | --- |
| Direct binary range evidence | `lookup_funcs` and `get_bytes` define function starts, ends, successor boundary `0x00554b40`, raw child pocket boundaries, and padding bytes. |
| Direct behavior evidence | Hex-Rays decompile and callee lists identify the helper calls and exact read/write pattern for each modeled Region/Motion method. |
| Direct reachability evidence | `xrefs_to` counts show broad live use for the modeled constructor and Motion/Region helpers; destructor route is tied to the Region vtable slot. |
| Vtable/RTTI evidence | Region vtable bytes and RTTI names support Region ownership and destructor source route. |
| Negative IDA evidence | `type_query` and local `entity_query` did not recover local project UDTs or source-quality function names, so names/types remain inferred. |
| Documentation evidence | Current Region/Motion/RectBounds docs and executed UID0002R9 child-split report corroborate source placement and child body ownership. |
| Generated-output evidence | Generated Region.cpp still has a UID0001FW empty marker while child raw helper bodies already emit, proving the callback must fill UID0001FW without duplicating children. |
| Tool limitation handling | Missing UDT/source-name recovery is a confidence cap. It is not treated as proof that source-shaped C++ is impossible. |

The evidence is strong enough for formal first-draft C++ because every non-child behavior is a simple wrapper around already-documented rectangle helpers and a stable `RectBounds` layout. Confidence is held at `91`, rather than higher, because exact original spelling for a few names remains inferred.

## Evidence Checked

Current MCP evidence is from active session `nexustk_supervisor_20260704` with healthy Hex-Rays.

Function/range evidence from `lookup_funcs`:

| Start | IDA name | Size | End | Source-facing disposition |
| --- | --- | --- | --- | --- |
| `0x00554680` | `sub_554680` | `0x61` | `0x005546e1` | `Region::Region()` |
| `0x005546f0` | `sub_5546F0` | `0x0d` | `0x005546fd` | `Motion::IsEmpty() const` |
| `0x00554700` | `sub_554700` | `0x15` | `0x00554715` | `Motion::SetEmpty()` |
| `0x00554720` | `sub_554720` | `0x3b` | `0x0055475b` | `Motion::SetRect(const RectBounds*)` |
| `0x00554760` | `sub_554760` | `0x3e` | `0x0055479e` | `Motion::CopyRectFrom(const Motion&)` |
| `0x005547a0` | `sub_5547A0` | `0x3c` | `0x005547dc` | `Motion::IntersectWith(const Motion&)` |
| `0x005547e0` | `sub_5547E0` | `0x17` | `0x005547f7` | `Motion::IntersectWithRect(const RectBounds*)` |
| `0x00554800` | `sub_554800` | `0x17` | `0x00554817` | `Motion::UnionWithRect(const RectBounds*)` |
| `0x00554820` | `sub_554820` | `0x3c` | `0x0055485c` | `Motion::UnionWith(const Motion&)` |
| `0x00554860` | `sub_554860` | `0xa7` | `0x00554907` | `Motion::SubtractRect(const RectBounds*)` |
| `0x00554910` | `sub_554910` | `0xbb` | `0x005549cb` | `Motion::SubtractRectFrom(const Motion&)` |
| `0x005549d0` | `sub_5549D0` | `0x28` | `0x005549f8` | `Motion::Offset(int,int)` |
| `0x00554a00` | `sub_554A00` | `0x18` | `0x00554a18` | `Region::IntersectsRect(const RectBounds*) const` |
| `0x00554a20` | no function | raw child | `0x00554a3c` | child UID00042Q already emits |
| `0x00554a40` | no function | raw child | `0x00554a56` | child UID00042R already emits |
| `0x00554a60` | `sub_554A60` | `0x3b` | `0x00554a9b` | child UID00042S already emits |
| `0x00554aa0` | no function | raw child | `0x00554adb` | child UID00042T already emits |
| `0x00554ae0` | `sub_554AE0` | `0x11` | `0x00554af1` | `Motion::GetRect(RectBounds*) const` |
| `0x00554b00` | `sub_554B00` | `0x38` | `0x00554b38` | source destructor `Region::~Region()`; scalar deleting mechanics are compiler output |
| `0x00554b40` | `sub_554B40` | `0x56` | outside target | Successor outside UID0001FW |

Boundary and padding evidence from `get_bytes`:

| Range | Bytes/evidence |
| --- | --- |
| `0x00554675-0x00554680` | eleven `0xcc` bytes before target start |
| `0x005546e1-0x005546f0` | fifteen `0xcc` bytes |
| `0x005546fd-0x00554700` | three `0xcc` bytes |
| `0x00554715-0x00554720` | eleven `0xcc` bytes; missing from current target table |
| `0x0055475b-0x00554760` | five `0xcc` bytes |
| `0x0055479e-0x005547a0` | two `0xcc` bytes |
| `0x005547dc-0x005547e0` | four `0xcc` bytes |
| `0x005547f7-0x00554800` | nine `0xcc` bytes |
| `0x00554817-0x00554820` | nine `0xcc` bytes |
| `0x0055485c-0x00554860` | four `0xcc` bytes |
| `0x00554907-0x00554910` | nine `0xcc` bytes |
| `0x005549cb-0x005549d0` | five `0xcc` bytes |
| `0x005549f8-0x00554a00` | eight `0xcc` bytes |
| `0x00554a18-0x00554ae0` | raw helper pocket and padding: raw child starts at `0x00554a20`, `0x00554a40`, `0x00554a60`, `0x00554aa0`; inter-child `0xcc` padding preserved |
| `0x00554af1-0x00554b00` | fifteen `0xcc` bytes |
| `0x00554b38-0x00554b40` | eight `0xcc` bytes before successor |

Decompile and callee evidence:

| Address | Behavior |
| --- | --- |
| `0x00554680` | Calls `LObject` base constructor at `0x004f4a80`, stores Region vtable, initializes `m_bounds` with `InitRectBounds(&m_bounds,0,0,0,0)`. |
| `0x005546f0` | Returns `IsRectEmptyOrInvalid(&m_bounds)`. |
| `0x00554700` | Clears bounds through `InitRectBounds(&m_bounds,0,0,0,0)`. |
| `0x00554720` | If input rect is empty/invalid, clears this bounds; otherwise copies the 16-byte rect. |
| `0x00554760` | Same as `SetRect`, but source is another Motion object's bounds. |
| `0x005547a0` | Stack-copies the source Motion bounds and intersects it with this bounds, writing back to this bounds. |
| `0x005547e0` | Intersects raw input bounds with this bounds in place. No normalized-output getter behavior appears. |
| `0x00554800` | Unions raw input bounds into this bounds. |
| `0x00554820` | Stack-copies source Motion bounds and unions into this bounds. |
| `0x00554860` | Clips/subtracts a raw bounds rectangle from this bounds, then clears if invalid. |
| `0x00554910` | Stack-copies source Motion bounds and applies the same subtract-from logic, then clears if invalid. |
| `0x005549d0` | If this bounds is non-empty, offsets by `(dx,dy)` through `OffsetRect`. |
| `0x00554a00` | Returns `IntersectRects(&m_bounds,bounds,NULL)` as a predicate; no output buffer. |
| `0x00554ae0` | Copies this bounds to caller-supplied output pointer. |
| `0x00554b00` | Calls base teardown and optional delete helper depending on scalar-deleting flags; source body should remain empty destructor. |

Xref evidence:

| Address | Current xref summary |
| --- | --- |
| `0x00554680` | 90 xrefs; broad UI/render construction fanout confirms live constructor use. |
| `0x005546f0` | 19 xrefs. |
| `0x00554700` | 10 xrefs. |
| `0x00554720` | 17 xrefs. |
| `0x00554760` | 21 xrefs. |
| `0x005547a0` | 11 xrefs. |
| `0x005547e0` | 37 xrefs. |
| `0x00554800` | 16 xrefs. |
| `0x00554820` | 13 xrefs. |
| `0x00554860` | 8 xrefs. |
| `0x00554910` | 3 xrefs. |
| `0x005549d0` | 32 xrefs. |
| `0x00554a00` | 51 xrefs. |
| `0x00554a20`, `0x00554a40`, `0x00554aa0` | zero direct xrefs; already handled as raw child helpers in UID0002R9. |
| `0x00554a60` | 4 xrefs, including in-range use from subtract/union helpers. |
| `0x00554ae0` | 10 xrefs. |
| `0x00554b00` | 1 data ref from Region vtable slot at `0x00622f58`. |
| `0x00622f58` | data xref from constructor vtable store at `0x005546c1`. |

Type/name evidence:

| Query | Result |
| --- | --- |
| `entity_query` over `0x00554600-0x00554b80` | No source-quality names in the local target text range; IDA still has raw `sub_` labels for the modeled functions. |
| `type_query filter=*Region*` | No local project UDT record. |
| `type_query filter=*Motion*` | No local project UDT record. |
| `type_query filter=*Rect*` | Windows/DirectDraw/RECT-related types only; no local project `RectBounds` UDT recovered in IDA. |
| `entity_query regex Region|Motion|Rect` | RTTI/vtable names exist for `Region` and `Motion`, including `??_7Region@@6B@` at `0x00622f58`; these support ownership but do not recover source declarations. |

Region vtable bytes at `0x00622f54` show the COL pointer followed by vtable slots: `0x0064ebbc`, `0x00554b00`, `0x004f4b10`, `0x0041b6c0`. This supports `0x00554b00` as Region destructor route and `0x00554680` as the vtable-publishing constructor.

## Inference Research Guidance Check

The formal C++ below uses source-quality inference where IDA lacks exact original source names. That is appropriate under current B-agent rules because behavior, field layout, helper semantics, and caller coverage are strong. Missing exact original spellings are recorded as confidence caps, not as blank-C++ blockers.

Inference decisions:

| Decision | Evidence | Caveat |
| --- | --- | --- |
| Use `Region.cpp` for both `Region` and dirty-region `Motion` helpers | Current by-file/class docs and UID0002R9 support route this helper island to `NexusTK/ui/core/Region.cpp`. | Timer/animation `Motion` remains a separate source concept and must not absorb this range. |
| Use `RectBounds m_bounds` at offset `+0x04` | Decompile reads/writes four contiguous 32-bit fields after object header; RectBounds support docs define `left/top/right/bottom` size `0x10`. | No local IDA `RectBounds` UDT recovered. |
| Rename `0x005547e0` as `Motion::IntersectWithRect` | Decompile is `IntersectRects(rawBounds,&m_bounds,&m_bounds)`, a mutating intersection. | Exact original name unknown; current `GetNormalizedRect` row should be historicalized. |
| Rename/present `0x00554a00` as `Region::IntersectsRect` | Decompile calls `IntersectRects(&m_bounds,bounds,NULL)` and returns boolean result. | Exact original name unknown; source-facing predicate spelling can be adjusted by supervisor if better evidence exists. |
| Emit empty `Region::~Region()` rather than scalar-deleting wrapper code | `0x00554b00` has scalar-deleting flag logic and optional delete helper, but source route is virtual destructor. | Compiler wrapper mechanics should remain documentation evidence, not hand-written C++. |
| Exclude raw child bodies from UID0001FW formal block | UID00042Q/R/S/T child pages already emit direct bodies into Region.cpp. | If supervisor later reroutes child emitters through aggregate `[[CHILDREN]]`, child emitter ownership must be changed consistently; this report does not recommend that during UID0001FW callback. |

## Heuristic / Inference Reanalysis And Validation

This target required source-quality inference because current IDA labels remain raw `sub_` names and no local project `Region`, `Motion`, or `RectBounds` UDTs were recovered. The inference was validated against current MCP behavior, by-* source-placement docs, executed UID0002R9 child-split history, and generated output.

| Issue | Reanalysis and validation | Result |
| --- | --- | --- |
| Generated/raw function names | `entity_query` in the local text range found no source-quality names. Names in this report were inferred from decompile behavior and surrounding docs, not accepted from IDA. | Use source-facing names in target/support docs; document them as inferred. |
| `RectBounds` type and fields | Decompile repeatedly reads/writes four 32-bit fields at object offset `+0x04`; current RectBounds docs define `left/top/right/bottom` size `0x10`. | Use `RectBounds m_bounds` in the formal C++ block; record no local IDA UDT recovered. |
| Region/Motion layout split | Constructor stores Region vtable and initializes bounds; Motion methods operate on the same bounds layout without their own vtable in this range. | Keep the existing Region.cpp dirty-rectangle helper grouping and do not move to timer/animation Motion. |
| `0x005547e0` stale name | Current row/name suggests `Motion::GetNormalizedRect`, but decompile mutates this bounds by intersecting raw input bounds. | Reject stale name; recommend `Motion::IntersectWithRect`. |
| `0x00554a00` source role | Current wording can imply a mutating Region intersection, but decompile passes output `NULL` and returns predicate. | Recommend `Region::IntersectsRect(const RectBounds*) const`. |
| Raw helper pocket `0x00554a20-0x00554adb` | Executed UID0002R9 already split exact child emitters; generated Region.cpp already contains their bodies. | Exclude child bodies from UID0001FW formal C++; preserve child direct emitters. |
| `0x00554b00` destructor wrapper | Binary has scalar-deleting flags and delete helper, but vtable slot and source shape imply a virtual destructor body. | Emit empty `Region::~Region()` and document wrapper mechanics as compiler output. |
| Padding/range gaps | `get_bytes` confirms several `0xcc` gaps; target table currently misses `0x00554715-0x00554720`. | Add padding row and keep successor `0x00554b40` outside target. |
| Owner/source placement | Region vtable/RTTI, constructor vtable store, current by-file docs, and UID0002R9 all point to `NexusTK/ui/core/Region.cpp`. | Preserve `CANONICAL_OWNER:0000N3` and `EMITTER_UIDS:0000N3`. |
| Score cap | Behavior is strong, but exact source spelling and local UDTs are not recovered. | Raise to `90/91`, not higher. |

Rejected alternatives were rechecked rather than copied forward: blank C++ is no longer defensible, child helper duplication would create duplicate generated definitions, scalar-deleting wrapper source would be decompiler-shaped, and RectBounds helper ownership would invert dependency direction.

## Source Placement

Recommended source placement is `NexusTK/ui/core/Region.cpp` through owner/emitter UID `0000N3`.

Evidence for this placement:

| Evidence | Meaning |
| --- | --- |
| Region constructor at `0x00554680` stores Region vtable and initializes the bounds field. | Region ownership is direct, not merely a consumer relationship. |
| Region vtable slot at `0x00622f58` references `0x00554b00`. | Destructor route belongs to Region source. |
| Existing Region/Motion support docs route dirty-rectangle `Motion` helper records to Region.cpp. | The helper grouping is already project-local convention. |
| Executed UID0002R9 raw helper split kept raw children in Region.cpp. | Parent and child routes are consistent. |
| Rect geometry helpers are callees only. | They are dependencies, not owners of the object methods. |

Rejected placements:

| Placement | Reason rejected |
| --- | --- |
| Timer/animation `Motion.cpp` | It is a different Motion concept; this range is dirty-region rectangle state tied to Region.cpp support docs. |
| `RectBounds`/Rect helper file | The target methods operate on Region/Motion objects and call Rect helper functions; helper callees do not own callers. |
| No-owner/non-emitting | Existing owner/emitter route is supported and the target is reconstructable with formal source C++. |

## Range / Split / Padding / Reclassification Analysis

The target range should remain `0x00554680-0x00554b38`. The modeled non-child functions in this range should be documented and emitted by UID0001FW, while the raw helper pocket should remain split to existing child pages.

| Range / item | Decision | Evidence |
| --- | --- | --- |
| `0x00554680-0x00554a18` modeled functions | Keep in UID0001FW and emit source-shaped bodies. | `lookup_funcs`, decompile, xrefs, and helper semantics all support direct source reconstruction. |
| `0x00554a20-0x00554adb` raw helper pocket | Keep exact child pages UID00042Q/R/S/T as direct emitters; do not duplicate in parent. | Executed UID0002R9 split and generated Region.cpp child bodies. |
| `0x00554ae0-0x00554af1` getter | Keep in UID0001FW and emit `Motion::GetRect`. | Decompile copies `m_bounds` into caller output. |
| `0x00554b00-0x00554b38` destructor wrapper | Keep in UID0001FW evidence and emit source destructor body. | Region vtable slot and scalar-deleting wrapper pattern. |
| Padding gaps | Record explicitly, especially `0x00554715-0x00554720`. | Current `get_bytes` evidence shows `0xcc` bytes. |
| Successor `0x00554b40` | Leave outside UID0001FW. | `lookup_funcs` reports separate successor function. |

## First-Draft C++ Recommendation

Insert the following exact formal block into `by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md`. It intentionally excludes the four raw child helper bodies already emitted by UID00042Q/UID00042R/UID00042S/UID00042T.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
Region::Region()
{
    InitRectBounds(&m_bounds, 0, 0, 0, 0);
}

Region::~Region()
{
}

bool Motion::IsEmpty() const
{
    return IsRectEmptyOrInvalid(&m_bounds);
}

void Motion::SetEmpty()
{
    InitRectBounds(&m_bounds, 0, 0, 0, 0);
}

void Motion::SetRect(const RectBounds *bounds)
{
    if (IsRectEmptyOrInvalid(bounds))
    {
        SetEmpty();
        return;
    }

    m_bounds = *bounds;
}

void Motion::CopyRectFrom(const Motion &motion)
{
    if (IsRectEmptyOrInvalid(&motion.m_bounds))
    {
        SetEmpty();
        return;
    }

    m_bounds = motion.m_bounds;
}

bool Motion::IntersectWith(const Motion &motion)
{
    RectBounds bounds = motion.m_bounds;
    return IntersectRects(&bounds, &m_bounds, &m_bounds);
}

bool Motion::IntersectWithRect(const RectBounds *bounds)
{
    return IntersectRects(bounds, &m_bounds, &m_bounds);
}

void Motion::UnionWithRect(const RectBounds *bounds)
{
    UnionRects(bounds, &m_bounds, &m_bounds);
}

void Motion::UnionWith(const Motion &motion)
{
    RectBounds bounds = motion.m_bounds;
    UnionRects(&bounds, &m_bounds, &m_bounds);
}

void Motion::SubtractRect(const RectBounds *bounds)
{
    if (bounds->top > m_bounds.top || m_bounds.bottom > bounds->bottom)
    {
        if (bounds->left <= m_bounds.left && m_bounds.right <= bounds->right)
        {
            if (bounds->top > m_bounds.top)
            {
                if (m_bounds.bottom <= bounds->bottom)
                    m_bounds.bottom = bounds->top - 1;
            }
            else if (m_bounds.bottom <= bounds->bottom)
            {
                SetEmpty();
            }
            else
            {
                m_bounds.top = bounds->bottom + 1;
            }
        }
    }
    else if (bounds->left <= m_bounds.left)
    {
        if (m_bounds.right > bounds->right)
            m_bounds.left = bounds->right + 1;
        else
            SetEmpty();
    }
    else if (m_bounds.right <= bounds->right)
    {
        m_bounds.right = bounds->left - 1;
    }

    if (IsRectEmptyOrInvalid(&m_bounds))
        SetEmpty();
}

void Motion::SubtractRectFrom(const Motion &motion)
{
    RectBounds bounds = motion.m_bounds;

    if (bounds.top > m_bounds.top || m_bounds.bottom > bounds.bottom)
    {
        if (bounds.left <= m_bounds.left && m_bounds.right <= bounds.right)
        {
            if (bounds.top > m_bounds.top)
            {
                if (m_bounds.bottom <= bounds.bottom)
                    m_bounds.bottom = bounds.top - 1;
            }
            else if (m_bounds.bottom <= bounds.bottom)
            {
                SetEmpty();
            }
            else
            {
                m_bounds.top = bounds.bottom + 1;
            }
        }
    }
    else if (bounds.left <= m_bounds.left)
    {
        if (m_bounds.right > bounds.right)
            m_bounds.left = bounds.right + 1;
        else
            SetEmpty();
    }
    else if (m_bounds.right <= bounds.right)
    {
        m_bounds.right = bounds.left - 1;
    }

    if (IsRectEmptyOrInvalid(&m_bounds))
        SetEmpty();
}

void Motion::Offset(int dx, int dy)
{
    if (!IsEmpty())
        OffsetRect(&m_bounds, dx, dy);
}

bool Region::IntersectsRect(const RectBounds *bounds) const
{
    return IntersectRects(&m_bounds, bounds, NULL);
}

void Motion::GetRect(RectBounds *bounds) const
{
    *bounds = m_bounds;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

## Final Recommendation

Apply the report as a source-quality callback for UID0001FW:

1. Update `by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md` to `COMPLETION:90`, `CONFIDENCE:91`, with `CANONICAL_OWNER:0000N3`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N3`, and blank emitter position preserved.
2. Insert the exact formal `RECONSTRUCTION_CPP CODE` block in this report for the modeled non-child Region/Motion methods.
3. Preserve UID00042Q/UID00042R/UID00042S/UID00042T child bodies as direct child emitters and do not duplicate them in UID0001FW.
4. Update direct Region/Motion support docs where stale so the blank-C++ blocker, stale `Motion::GetNormalizedRect` name, and scalar-deleting-wrapper source ambiguity are resolved at report-level detail.
5. Leave manual coverage/tracker files, generated files, validator state, lifecycle/archive files, and supervisor ledgers untouched by B014.
6. Treat remaining source-name and UDT uncertainty as score caps only, not blockers to callback implementation.

## Score And Metadata Recommendation

Recommended target metadata:

| Field | Recommendation | Reason |
| --- | --- | --- |
| `COMPLETION` | `90` | Current MCP evidence supports source-shaped bodies for all modeled non-child functions, and raw helper children are already split/emitting. |
| `CONFIDENCE` | `91` | Behavior is strong, but exact original method names and project UDT declarations are inferred rather than recovered from IDA. |
| `CANONICAL_OWNER` | keep `0000N3` | Existing Region/Region.cpp owner matches vtable, RTTI, support docs, and UID0002R9 history. |
| `RECONSTRUCTABLE` | keep `TRUE` | The target is source-bearing and emits through owner `0000N3`. |
| `EMITTER_UIDS` | keep `0000N3` | Existing emitter route is correct. |
| `EMITTER_POSITION_OPTIONAL` | keep blank | No position change required by this report. |

The old blank-C++ blocker should be historicalized as a resolved source-quality issue. Remaining gaps are confidence caps: no recovered local UDT, inferred names for `Motion::IntersectWithRect` and `Region::IntersectsRect`, and child bodies emitted by child pages rather than the aggregate.

## Recommended Target Doc Changes

Implemented target doc changes for `by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md`:

1. Set `COMPLETION:90` and `CONFIDENCE:91`.
2. Preserve `CANONICAL_OWNER:0000N3`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N3`, and blank emitter position.
3. Insert the exact formal `RECONSTRUCTION_CPP CODE` block from this report.
4. Add the current MCP session facts: active session `nexustk_supervisor_20260704`, healthy server/Hex-Rays, exact ranges, decompile behaviors, xref counts, vtable/RTTI support, no local UDT/name records, and current generated empty-marker state.
5. Add explicit boundary/padding note for `0x00554715-0x00554720`.
6. Historicalize or replace `Motion::GetNormalizedRect` for `0x005547e0`; the current evidence supports `Motion::IntersectWithRect`.
7. Clarify `0x00554a00` as a boolean Region intersection predicate with no output buffer.
8. Preserve that UID00042Q/UID00042R/UID00042S/UID00042T raw child pages already emit their helper bodies.
9. Keep scalar-deleting wrapper mechanics for `0x00554b00` as compiler evidence while emitting source destructor `Region::~Region()`.

## Recommended Support Doc Changes

Implemented support synchronization after supervisor callback:

| Document | Recommended action |
| --- | --- |
| `by-file/Region.md` | Mark UID0001FW source-ready at `90/91`; note Region constructor/destructor and dirty-region Motion helpers now have formal C++; preserve raw child emitters. |
| `by-class/Region.md` | Remove UID0001FW blank-C++ blocker; preserve declaration/source-name caveats; record destructor source body vs scalar-deleting wrapper evidence. |
| `by-file/Motion.md` | Mark the dirty-region Motion helper island in Region.cpp source-ready; preserve distinction from timer/animation Motion. |
| `by-class/Motion.md` | Update method notes for `IntersectWithRect`, `SubtractRectFrom`, and direct child helpers; record missing exact original spelling as confidence cap only. |
| `by-memory/0x00554a20-0x00554adb.RegionRawRectangleHelpers.md` | If stale, add a parent note that UID0001FW is now source-ready but child helpers still emit on exact child pages. |
| Exact child pages UID00042Q/R/S/T | Verification only unless stale; do not duplicate their formal C++ in UID0001FW. |
| `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md` | Verification only unless stale; helper semantics already support this report. |
| `by-type/by-struct/RectBoundsLayout.md`, `by-class/RectBounds.md`, `by-file/RectBounds.md` | Verification only unless stale; no score change required by UID0001FW. |

## IDA Rename / Type / Comment Recommendations

B014 did not mutate the IDA database. These are documentation recommendations only unless a supervisor later authorizes IDA edits.

Suggested source-facing names for documentation and optional future IDA rename work:

| Address | Suggested name |
| --- | --- |
| `0x00554680` | `Region::Region` |
| `0x005546f0` | `Motion::IsEmpty` |
| `0x00554700` | `Motion::SetEmpty` |
| `0x00554720` | `Motion::SetRect` |
| `0x00554760` | `Motion::CopyRectFrom` |
| `0x005547a0` | `Motion::IntersectWith` |
| `0x005547e0` | `Motion::IntersectWithRect` |
| `0x00554800` | `Motion::UnionWithRect` |
| `0x00554820` | `Motion::UnionWith` |
| `0x00554860` | `Motion::SubtractRect` |
| `0x00554910` | `Motion::SubtractRectFrom` |
| `0x005549d0` | `Motion::Offset` |
| `0x00554a00` | `Region::IntersectsRect` |
| `0x00554ae0` | `Motion::GetRect` |
| `0x00554b00` | `Region::~Region` source route; scalar deleting destructor wrapper in binary |

Suggested type/comment guidance:

| Item | Recommendation |
| --- | --- |
| `Region` / `Motion` local UDTs | Do not claim recovered IDA UDTs; document inferred layout only unless future type recovery supplies exact definitions. |
| `RectBounds` | Use existing project documentation spelling and layout; no IDA type record was recovered in this pass. |
| Raw child helpers | Preserve exact child ownership and comments from UID0002R9. |

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual coverage or tracker text was recommended or applied by B014. Validator-owned generated/projected outputs refreshed through scoped validators where applicable. B014 did not manually edit any `-coverage-report.md`, generated tracker, validator state, or supervisor ledger file.

## Open Questions With Attempted Resolution

| Question | Evidence checked | Best supported resolution | Remaining impact / future evidence |
| --- | --- | --- | --- |
| Exact original spelling for `Motion::IntersectWithRect` | Current decompile, xrefs, stale target row, Region/Motion docs. | The behavior is an in-place raw-rect intersection, so `Motion::IntersectWithRect` is the best source-facing first draft. | Exact spelling remains a confidence cap until symbols/source are recovered. |
| Exact original spelling for `Region::IntersectsRect` | Current decompile of `0x00554a00`, helper call semantics, Region docs. | The function is a predicate because output is `NULL`; `Region::IntersectsRect` is defensible. | Exact spelling remains a confidence cap only. |
| Exact source declaration shape for `Region` and dirty-region `Motion` | `type_query`, `entity_query`, current by-class/by-file docs, RectBounds support. | Method bodies can use inferred `m_bounds` and documented `RectBounds`; no local IDA UDT exists. | Future UDT/source recovery could refine declarations, but not block target C++. |
| Whether UID0001FW should use `[[CHILDREN]]` for raw child helper bodies | Generated Region.cpp and UID0002R9 child pages. | Do not use `[[CHILDREN]]` now; child pages emit direct bodies. | Only revisit if supervisor deliberately reroutes child emitters and validates generated output. |
| Whether score can exceed `90/91` | MCP facts, support docs, generated output, type/name negative checks. | Not yet; current evidence supports source-ready but not exact-name/type certainty. | Higher confidence would need recovered UDTs/source symbols or stronger original-name proof. |

## Negative Evidence Summary

Negative checks and rejected evidence paths:

| Negative evidence | Result and impact |
| --- | --- |
| No local source-quality names in target text range | Prevents claiming exact original spellings; does not block inferred first-draft names. |
| No local IDA `Region`, `Motion`, or project `RectBounds` UDT records | Prevents claiming exact declaration recovery; does not block method bodies because layout and helper semantics are stable. |
| Raw starts `0x00554a20`, `0x00554a40`, and `0x00554aa0` have zero direct xrefs | Already resolved by UID0002R9 as raw children; not evidence to merge or duplicate child bodies. |
| Current generated output has UID0001FW empty marker | Confirms implementation gap; not evidence for no-code because MCP behavior is now strong. |
| `Motion::GetNormalizedRect` current/stale name | Rejected by decompile; the function mutates this bounds via `IntersectRects`. |
| Scalar-deleting wrapper body at `0x00554b00` | Rejected as hand-authored source because it is compiler-generated destructor glue. |
| Rect helper callees | Rejected as owner candidates because dependency direction runs from Region/Motion methods to Rect helpers. |
| Timer/animation Motion support | Rejected as source placement because this target belongs to the dirty-region rectangle subsystem already routed to Region.cpp. |

## Rejected Alternatives

| Alternative | Rejection reason |
| --- | --- |
| Leave UID0001FW blank-C++ | Rejected. Current MCP evidence supports source-shaped bodies for all modeled non-child functions. |
| Move dirty-region Motion helpers to timer/animation `Motion.cpp` | Rejected. Local docs and UID0002R9 route this helper island to `NexusTK/ui/core/Region.cpp`; timer/animation Motion is a separate concept. |
| Emit raw child helper bodies again in UID0001FW | Rejected. UID00042Q/R/S/T already emit direct child bodies; duplicate formal C++ would create duplicate generated definitions. |
| Hand-code scalar-deleting wrapper as source C++ | Rejected. `0x00554b00` is compiler wrapper evidence; source route should be `Region::~Region()` with empty body. |
| Move ownership to RectBounds helpers | Rejected. Rect geometry helpers are dependencies, not the owner of Region/Motion object methods. |
| Mark no-owner/non-emitting | Rejected. Existing owner/emitter `0000N3` is supported by Region vtable, RTTI, constructor vtable store, and by-file routing. |

## Validator Results

B014 ran scoped file validators from `source-3/project-documentation` for every changed by-* file. No report lifecycle, archive, dry-run execute, or `execute_report` command was run.

| File | Command | command_id | command_timestamp | Exit | ok | Warnings / side effects |
| --- | --- | --- | --- | ---: | ---: | --- |
| `by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md` | `python .\tools\validator.py --mode file --file by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md --apply --queue-timeout 240` | `000000006424` | `2026-07-04T18:25:30-04:00` | 0 | 1 | Updated completion/confidence to `90/91`; autogen registry hash/block update; `missing_ref_uid 0003A3` x3; removed stale reference index to UID000164; project stats update; generated refresh deferred. |
| `by-file/Region.md` | `python .\tools\validator.py --mode file --file by-file/Region.md --apply --queue-timeout 240` | `000000006425` | `2026-07-04T18:25:32-04:00` | 0 | 1 | Projected stats/stats-row updates; generated refresh deferred. |
| `by-class/Region.md` | `python .\tools\validator.py --mode file --file by-class/Region.md --apply --queue-timeout 240` | `000000006426` | `2026-07-04T18:25:34-04:00` | 0 | 1 | Projected stats/stats-row updates; generated refresh deferred. |
| `by-file/Motion.md` | `python .\tools\validator.py --mode file --file by-file/Motion.md --apply --queue-timeout 240` | `000000006427` | `2026-07-04T18:25:44-04:00` | 0 | 1 | Projected stats update; stats incremental noop for UID0000LL; generated refresh deferred. |
| `by-class/Motion.md` | `python .\tools\validator.py --mode file --file by-class/Motion.md --apply --queue-timeout 240` | `000000006428` | `2026-07-04T18:25:51-04:00` | 0 | 1 | Projected stats/stats-row updates; generated refresh deferred. |
| `by-memory/0x00554a20-0x00554adb.RegionRawRectangleHelpers.md` | `python .\tools\validator.py --mode file --file by-memory/0x00554a20-0x00554adb.RegionRawRectangleHelpers.md --apply --queue-timeout 240` | `000000006429` | `2026-07-04T18:26:00-04:00` | 0 | 1 | Projected stats update; stats incremental noop for UID0002R9; generated refresh deferred. |

Generated freshness checks:

| Check | Result |
| --- | --- |
| Queue status | `python .\tools\validator.py --queue-status`, command `000000006432`, timestamp `2026-07-04T18:26:31-04:00`; worker running, queued jobs `0`, processing jobs `0`, queued generated refresh jobs `0`, processing generated refresh jobs `0`. |
| `auto-generated/NexusTK/ui/core/Region.cpp` header | `validator-command-id: 000000006426`, `validator-refreshed-at: 2026-07-04T18:25:34-04:00`, source by-file UID `0000N3`; fresh enough for UID0001FW because it is newer than target command `000000006424` and Region file command `000000006425`. |
| UID0001FW generated body | Present once, with `Completion:90 | Confidence:91`, and contains `Region::Region()` plus the non-child Region/Motion methods from the target formal block. |
| Child body duplication | UID00042Q, UID00042R, UID00042S, and UID00042T each appear once; `Motion::Intersects`, `Motion::ContainsRect`, `Motion::Contains`, and `Motion::HasSameBoundsAs` each appear once. |

## Changed Files

Manual B014 edits:

| File | Change |
| --- | --- |
| `by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md` | Target metadata, formal C++, range table corrections, B014 evidence, and changes log. |
| `by-file/Region.md` | Source-ready UID0001FW support note, method-name corrections, confidence-cap notes, and changes log. |
| `by-class/Region.md` | Method notes and support evidence updated for `Region::IntersectsRect`, source destructor route, and UID0001FW source readiness. |
| `by-file/Motion.md` | Dirty-rectangle/animation split support updated to mark UID0001FW source-ready and historicalize `GetNormalizedRect`. |
| `by-class/Motion.md` | Dirty-rectangle non-conflict and source-ready support updated while preserving animation class ownership. |
| `by-memory/0x00554a20-0x00554adb.RegionRawRectangleHelpers.md` | Parent sync note confirming UID0001FW source-ready while raw children remain direct emitters. |
| `tools/leaser/Agents/Agent-B014/research/0001FW-RegionAndMotionRect-source-quality.md` | Report ledger/checklist/validator/changelog updated after callback implementation. |

Validator-managed side effects reported by scoped validators:

| File/category | Effect |
| --- | --- |
| `auto-generated/NexusTK/ui/core/Region.cpp` | Deferred generated refresh completed; UID0001FW now emits one body and raw child bodies remain single-copy. |
| `project-level/-auto-completion-stats.md` | Projected stats/stats rows updated by validator output. |
| validator autogen registry | Validator reported UID0001FW autogen registry hash/block updates. B014 did not edit validator state by hand. |

No coverage reports, manual generated files, lifecycle/archive files, supervisor ledgers, or report execution files were edited by B014.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | Target should move from `86/88` to `90/91`. | High | Current MCP decompile, xrefs, helper semantics, pre-callback generated empty marker, and no remaining blank-C++ blocker. | `by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md` metadata | incorporate | applied: target metadata updated; validator `000000006424` confirmed completion/confidence updates. |
| C02 | Owner/emitter routing remains `0000N3`; reconstructable remains true. | High | Existing docs route Region/Motion dirty-rectangle island to Region.cpp; Region vtable/RTTI and constructor store support Region ownership. | Target metadata | incorporate | applied: owner/emitter/reconstructable/blank position preserved on target. |
| C03 | Formal C++ block should be inserted exactly as provided. | High | Function-by-function decompile maps cleanly to source-shaped bodies; child helper bodies excluded to avoid duplicate emission. | Target `RECONSTRUCTION_CPP CODE` block | incorporate | applied: formal block inserted on target; generated Region.cpp contains one UID0001FW body. |
| C04 | MCP session `nexustk_supervisor_20260704` was active and healthy. | High | `idb_list` active worker; `server_health` ok, Hex-Rays ready. | Target evidence notes and report audit text | incorporate | applied: target B014 evidence section records session/health facts. |
| C05 | Function boundaries and sizes are current as listed in this report. | High | `lookup_funcs` for every start/end boundary and successor `0x00554b40`. | Target memory table/evidence | incorporate | applied: target B014 evidence table records modeled starts/sizes and successor. |
| C06 | Missing padding `0x00554715-0x00554720` should be recorded. | High | `get_bytes` shows eleven `0xcc` bytes. | Target memory table | incorporate | applied: covered-ranges table now includes `0x00554715-0x00554720` padding row. |
| C07 | `0x005547e0` is in-place `Motion::IntersectWithRect`, not `GetNormalizedRect`. | High | Decompile calls `IntersectRects(rawBounds,&m_bounds,&m_bounds)`. | Target row; `by-class/Motion.md`; `by-file/Motion.md` | reject-stale | applied: target and Motion support docs historicalize `GetNormalizedRect` and use `Motion::IntersectWithRect`. |
| C08 | `0x00554a00` is a predicate `Region::IntersectsRect`. | High | Decompile calls `IntersectRects(&m_bounds,bounds,NULL)` and returns the boolean result. | Target row; `by-class/Region.md`; `by-file/Region.md` | incorporate | applied: target and Region support docs now use predicate `Region::IntersectsRect`. |
| C09 | `0x00554b00` should emit as source destructor, not hand-coded scalar-deleting wrapper. | High | Vtable xref and decompile show scalar-deleting mechanics; source body is empty destructor. | Target C++; Region support docs | incorporate | applied: target formal C++ emits `Region::~Region()`; target/Region support docs preserve wrapper evidence. |
| C10 | UID00042Q/R/S/T child helper bodies are already direct emitters and must not be duplicated. | High | Executed UID0002R9 support and generated Region.cpp show child bodies already present. | Target notes; raw helper support docs; generated freshness expectation | already-present | applied: target excludes child C++; raw aggregate records parent sync; generated counts show each child UID/body once. |
| C11 | No recovered local Region/Motion/RectBounds UDTs were found in IDA. | High | `type_query` for Region/Motion/Rect and `entity_query` target range. | Target caveats; class/file support notes | incorporate | applied: target B014 evidence and Region/Motion support docs record no-local-UDT/name caveat. |
| C12 | Xref coverage is broad and supports live helper methods. | High | `xrefs_to` counts: constructor 90, predicate 51, offset 32, and multiple caller counts across Motion methods. | Target evidence; support source-readiness rationale | incorporate | applied: target B014 evidence records xref counts and source-ready rationale. |
| C13 | Region vtable/RTTI support ownership. | High | `??_7Region@@6B@` at `0x00622f58`; vtable bytes include destructor slot `0x00554b00`; constructor stores vtable. | Target evidence; Region support docs | incorporate | applied: target and Region support docs record vtable/RTTI/destructor evidence. |
| C14 | Dirty-region Motion helpers should stay in Region.cpp, not timer/animation Motion.cpp. | Medium-high | Current by-file/class docs and UID0002R9 accepted history. | `by-file/Motion.md`; `by-file/Region.md` | reject-invalid | applied: Motion file/class and Region file/class preserve split-owner guard and source-ready Region.cpp route. |
| C15 | Rect geometry helpers are dependencies, not ownership targets. | High | Callees point to `0x004b7c30-0x004b7f87` helper island; methods remain Region/Motion object methods. | Target rationale; Rect helper support docs | reject-invalid | applied: target rejected alternatives preserve dependency-owner distinction; Rect helper docs were verification-only and not edited. |
| C16 | Pre-callback generated output had a UID0001FW empty marker and needed refresh after callback. | High | Local generated `Region.cpp` command `000000006307`, refreshed `2026-07-04T12:41:41-04:00`. | Callback validator/generation freshness note | incorporate | applied: generated Region.cpp refreshed at command `000000006426`; UID0001FW body present once, no child duplicates. |
| C17 | No manual coverage/tracker edit is needed or allowed for B014. | High | Assignment and workflow boundary. | Report coverage/tracker section | not-applicable | excluded-with-reason: no manual coverage/tracker edit was needed; scoped validators reported generated/projected stats side effects only. |
| C18 | Support docs should remove UID0001FW blank-C++ blocker but preserve UDT/name confidence caps. | High | Current MCP supports formal C++; UDT/name records remain unrecovered. | Region/Motion by-file/by-class docs | incorporate | applied: Region/Motion file/class docs and raw-helper aggregate sync updated; exact child/Rect helper docs were already sufficient. |

## Positive Evidence Summary

Direct facts supporting the recommendation:

| Positive evidence | Why it supports source-ready UID0001FW |
| --- | --- |
| `lookup_funcs` maps every modeled start/end and successor boundary. | The target range and non-child function inventory are exact enough for callback. |
| Decompile for each non-child method is a simple rectangle-helper wrapper or field copy/update. | Behavior is source-shaped and not opaque algorithmic code. |
| Callees are stable helper routines: init, empty check, intersect, union, offset, base constructor/destructor, and delete helper. | Existing helper docs explain the semantics needed for C++. |
| Xref counts show broad live use across Region/Motion methods. | These are not dead orphan helpers requiring no-code treatment. |
| Region vtable/RTTI and constructor vtable store exist. | Owner/emitter `0000N3` and Region.cpp placement are corroborated. |
| Existing RectBounds docs define the four-field layout used by the binary. | Formal C++ can use source-facing `RectBounds` and `m_bounds` without raw pointer arithmetic. |
| Executed UID0002R9 raw child report already resolved the raw helper pocket. | UID0001FW can emit remaining methods without reopening the child split. |
| Generated Region.cpp already emits the raw child bodies but leaves UID0001FW empty. | The implementation callback has a precise generated-output expectation. |

Strongest inference chain: Region constructor/vtable evidence proves source placement, decompile proves bounds field behavior, RectBounds and Rect helper docs supply source-facing types/helpers, and the executed raw-child split prevents duplicate child C++. Together these justify a formal first-draft C++ block and a score increase while preserving exact caveats.

## Implementation Tracking Checklist

Callback state: implementation edits and scoped validation are complete. No lifecycle/archive/`execute_report` command was run by B014.

| Item | Destination | Callback verification state |
| --- | --- | --- |
| Set target `COMPLETION:90`, `CONFIDENCE:91`. | `by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md` | applied; validator `000000006424` reported completion/confidence updates. |
| Preserve owner/emitter metadata `0000N3`, `RECONSTRUCTABLE:TRUE`, blank position. | Target metadata | applied; metadata preserved. |
| Insert the exact formal `RECONSTRUCTION_CPP CODE` block from this report. | Target formal C++ block | applied; generated Region.cpp contains UID0001FW source body. |
| Add MCP session/health evidence and exact lookup/decompile/xref facts. | Target evidence sections | applied; B014 evidence section added to target. |
| Add missing `0x00554715-0x00554720` padding row. | Target child/range table | applied. |
| Replace/historicalize stale `Motion::GetNormalizedRect` name for `0x005547e0`. | Target, Motion class/file support | applied; target and Motion support docs use `Motion::IntersectWithRect` with historical caveat. |
| Clarify `0x00554a00` as `Region::IntersectsRect` predicate. | Target, Region class/file support | applied. |
| Preserve UID00042Q/R/S/T direct child emitter bodies and avoid duplicate C++. | Target notes, raw helper aggregate support | applied; generated counts show each child UID/body once. |
| Document `Region::~Region()` source body vs scalar-deleting wrapper evidence. | Target, Region class/file support | applied. |
| Update Region file/class support for UID0001FW source readiness and remaining caveats. | `by-file/Region.md`, `by-class/Region.md` | applied; no support score changes. |
| Update Motion file/class support for dirty-region helper source readiness and source-name caveats. | `by-file/Motion.md`, `by-class/Motion.md` | applied; animation ownership preserved. |
| Update raw-helper aggregate only if stale. | `by-memory/0x00554a20-0x00554adb.RegionRawRectangleHelpers.md` | applied; parent sync note added while non-emitting split-index metadata preserved. |
| Verify exact child pages and RectBounds/Rect helper docs. | UID00042Q/R/S/T, RectBounds/Rect helper docs | already-present; not edited because current child pages already emit and helper docs already support behavior. |
| Validate each changed by-* file with scoped file validator. | Validator commands from `source-3/project-documentation` | applied; commands `000000006424` through `000000006429`, all exit 0 / `ok:1`. |
| Check generated `auto-generated/NexusTK/ui/core/Region.cpp` freshness after validators. | Generated freshness check only; no manual edit | applied; queue-status command `000000006432` showed no queued/processing jobs, generated header `000000006426`, UID0001FW body present once, child bodies single-copy. |
| Lease files only during edit/validator batch and release immediately after. | by-* edit lease set | applied with caveat: lease acquisition succeeded for six by-* docs; release command returned `Rejected[No active lease]` for each, and current lease report confirmed no active leases. |
| Leave coverage reports, generated files, validator state, lifecycle/archive files, and supervisor ledgers untouched. | Project-wide boundary | applied manually; scoped validators reported generated/projected stats/autogen registry side effects, but B014 did not edit those files by hand. |

## Follow-Up Actions

Supervisor should perform Gate 2 claim-by-claim verification against the changed docs, validator outputs, generated freshness, and this updated ledger/checklist. If Gate 2 passes, supervisor owns the final report lifecycle/archive command. B014 did not run `execute_report`, any lifecycle/archive command, or manual report move.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B014","command_id":"000000006443","destination_path":"executed-b-agent-research/B014/0001FW-RegionAndMotionRect-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B014/research/0001FW-RegionAndMotionRect-source-quality.md","timestamp":"2026-07-04T18:43:09-04:00","uid":"0001FW"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
