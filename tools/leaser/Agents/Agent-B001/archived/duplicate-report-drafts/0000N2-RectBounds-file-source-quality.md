# 0000N2 RectBounds Whole-File Source-Quality Research

** TARGET-REPORT-UID:0000N2 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

## Finalized Report / Current Recommendation

- Current recommendation: retain [UID:0000N2] as the reconstructable owner and sole `NexusTK/ui/core/RectBounds.cpp` source root, retain [UID:0000BU] as the `RectBounds.h` class/layout owner, and close the whole-file source route with the exact child nesting and source order in this report.
- Final disposition: the compilation unit owns thirty authored functions, the `Point` and `RectBounds` declarations, one compiler-pooled quarter literal, references to the shared half literal, three file-local anchor helpers plus their axis helper, compiler-generated switch tables, and 34 exact no-code alignment spans. It owns no vtable, RTTI, resource, string, import, singleton, or mutable global.
- Required action: incorporate the complete inventory and evidence into the target/support pages; nest [UID:00015R] beneath [UID:00015Q] and reparent [UID:00015T] beneath [UID:00015S] to restore address/source order while preserving UID00015T's existing formal CPP/H; make [UID:00040U] and [UID:0001VP] non-emitting evidence pages; remove the generated empty-emitter marker; preserve LineClip under [UID:0000OC] `Surface.cpp`; apply the complete ten-function define/rename/type/comment handoff in Section 21; and apply the manual-coverage handoff below.
- Confidence: very high for behavior, boundaries, class/layout, file ownership, source order, formal source, and the safe staged IDA handoff; high for inferred private/static helper spellings. Exact original private spellings and a rebuilt-binary comparison are unavailable, so code-emitting scores should not exceed the 95 barrier.

## Supporting Research

The current by-file, by-class, by-memory, by-type, generated CPP/H, source-tree, manual-coverage, and matching archived-report evidence was reconciled against fresh live read-only IDA MCP evidence. Matching archived reports for [UID:0000BU], [UID:00022G], [UID:00015Q], [UID:00015R], [UID:00022H], [UID:00015S], [UID:00015T], and [UID:00022I] were treated as leads and independently rechecked.

The decisive whole-file facts are:

- the exact owned code family is the thirty authored functions listed in Section 14, spanning retained source bodies from `0x004b7670` through `0x004b83ae` with unrelated code explicitly excluded;
- the raw starts are complete retained functions rather than one larger aggregate body, and their source-facing signatures are recoverable from instruction behavior and callers even where IDA has no modeled function;
- the generated CPP already contains every behaviorally complete body but emits `Inset` and `RectArea` out of address/source order;
- the dated command `000000025640` generated H omitted `RectArea`; the physically reread command `000000025893` H contains UID00015T's existing formal `int RectArea(const RectBounds *bounds);` declaration, so callback work must preserve that declaration and only repair its ownership/source-order route;
- [UID:0001VP] duplicates the exact `RectBounds` layout already emitted by [UID:0000BU] and should document, not emit, that layout;
- [UID:00040U] is a compiler-pooled `0.25f` literal with two reads from `InsetByQuarter`; source should use the human literal rather than emit an artificial global;
- the shared `0.5f` pool item at `0x006104b0` has sixty reads project-wide and is not owned by this file even though three of those reads occur in the quarter/half helpers;
- LineClip is render-owned: `ClipLineToRect` is called only from a Surface-family path and `SoftwareRenderRgb565LineCallback`, while `ClipLineParameter` is called only by `ClipLineToRect`.

## Target

- Target UID: `0000N2`.
- Additional target UIDs: none. Related UIDs are support pages and do not receive report-coverage credit from this report.
- Target path: `by-file/RectBounds.md`.
- Source queue/report row: uncovered by-file queue entry, current score `90/85`, reconstructable metadata blank, zero direct/additional reports at assignment.
- Current supervisor classification: complete whole-file B-agent source-quality audit.
- Current scores and parent state: target `90/85`; [UID:0000BU] is current class child/owner route; all listed by-memory and by-type pages route directly or indirectly to this file.
- Inferred compilation-unit boundary: `NexusTK/ui/core/RectBounds.cpp` and `NexusTK/ui/core/RectBounds.h`. The source unit includes the `RectBounds` value type, public/member geometry operations, free geometry operations, and private anchor helpers. It excludes unrelated `WideStringHashHelper`, `PathUtil`, `FieldMapPane`, the successor `GeneralPurposePanel`, and render-owned LineClip.

## Current Target State

- Existing metadata: `COMPLETION:90`, `CONFIDENCE:85`, `CANONICAL_OWNER:FILE`, blank `RECONSTRUCTABLE`, source path `NexusTK/ui/core/`, and the current class child route.
- Existing owner/emitter state: [UID:0000N2] is the correct file root and [UID:0000BU] is the correct class/H owner, but [UID:00015R] and [UID:00015T] currently route as later siblings instead of nesting at their physical insertion points. UID00015T is currently `88/92` and already contains exact formal CPP and H. [UID:00040U] and [UID:0001VP] retain emitting routes despite requiring no authored source.
- Existing C++/emitter state: all thirty CPP bodies and the UID00015T `RectArea` H declaration exist, but `Inset` is emitted after `ClampWithin` rather than between `Offset` and `IntersectWith`; `RectArea` is emitted after `RectContainsRect` rather than after `InitRectBoundsFromSize`; and [UID:0001VP] produces an empty-emitter marker.
- Existing open questions/stale assumptions: the target leaves `ui/core` versus `util` open, leaves LineClip in a review bucket, treats the quarter constant as a possible source object, carries duplicate layout emission, and understates the raw anchor-helper boundaries/tables. Fresh evidence resolves each issue below.
- Related docs checked: [UID:0000BU], [UID:00022G], [UID:00015Q], [UID:00015R], [UID:00022H], [UID:00040U], [UID:00015S], [UID:00015T], [UID:00022I], [UID:00022L], [UID:0001VP], predecessor `FramePartPane`, [UID:00022J], [UID:00022K], [UID:00015U], `by-memory/-ignored.md`, [UID:00016H], [UID:0000OC], and `by-project-structure/proposed-source-tree.md`.
- Complete inventory status: thirty authored functions, two source types, two pooled floating literals, four embedded switch/table islands, 34 exact no-code alignment spans, and twenty enumerated ordinary-document destinations (one target plus nineteen support/boundary/ownership pages) are accounted for in Sections 13-25. Six excluded inventory rows comprise four neighboring source families, one boundary-padding row, and the LineClip ownership candidate. Thirty-three spans are pure `0xcc`; `0x004b83ae-0x004b83b0` is the two-byte `66 90` NOP.
- Current generated source: the dated research snapshot physically reread for this assignment is validator command `000000025893`, refreshed `2026-08-18T01:10:04-04:00`. The dated CPP identity is SHA256 `0478FE3CC06606B0699883F92FC6AFB6941995E2D927E23E46A7F3362F300EEA`, 15,542 bytes/500 physical lines; the H identity is SHA256 `EF94AA962829B3C8FBABD2DB82288FDDB6352FE7215987D2B4414F4F3666912D`, 2,404 bytes/57 physical lines. Its H contains UID00015T at `88/92` and the exact `RectArea` declaration. Commands `000000025616`, `000000025640`, and `000000025804` remain earlier dated snapshots; `000000025640` records the superseded missing-H defect. No receipt is permanent current authority; callback/final validation must reread then-current command metadata, hashes, and physical semantics.
- Current report lifecycle authority is the artifact's current path plus validator-owned status/history metadata. This report-only body makes no execution/archive-state claim.

## Executive Recommendation

Keep the current file and class ownership, but repair the emitter tree instead of creating new code pages. Insert [UID:00015R] through a `[[CHILDREN]]` marker in [UID:00015Q] between `Offset` and `IntersectWith`; reparent [UID:00015T] through a `[[CHILDREN]]` marker in [UID:00015S] between `InitRectBoundsFromSize` and `IntersectRects` while preserving its existing formal CPP and `RectArea` H declaration; assign deterministic source positions to the direct children; clear the emitter routes of [UID:00040U] and [UID:0001VP]; and update the source-tree disposition to make `ui/core/RectBounds.cpp/.h` final while preserving LineClip under `Surface.cpp`.

No new exact by-memory page is needed: every authored code range already has a page. No by-memory page should absorb unrelated code merely to make the physical address span contiguous.

## Supervisor Active Recheck

- The triggering instruction assigns [UID:0000N2] as a complete whole-file report-only source-quality task.
- Split repair is required only in the emitter graph and source-order composition; the existing by-memory page boundaries already isolate every authored source function or coherent helper cluster.
- Every source-bearing child is inventoried and has exact formal CPP/H or compiler-covered/no-code disposition. No source body is deferred.

## Inference Research Guidance Check

- Binary behavior, exact bytes, function/raw boundaries, current IDA state, callers/xrefs, data refs, and UDT layouts are direct IDA facts.
- Existing by-* pages, generated source, archived reports, manual coverage, and proposed source tree are documentation evidence and were not treated as authority where they conflict with live evidence.
- Source-facing private/static names, the original `.cpp/.h` split, and source order are inference. They are supported by contiguous locality, member/free-function shape, current subsystem conventions, caller use, and the already coherent generated bodies.
- Decompiler labels are not retained in final source merely because original symbols are absent. The report uses the most plausible project-consistent human names and explicitly marks them inferred.
- Stale Wave2/Wave3 material was not used as evidence.

## Heuristic / Inference Reanalysis And Validation

| Issue | Reanalysis and result | Classification |
| --- | --- | --- |
| `ui/core` versus `util` placement | The value type is a pervasive UI/render geometry primitive; the current class/file routes and generated includes already converge on `NexusTK/ui/core/RectBounds.h`. Moving it to `util` would churn established includes without binary or source-tree evidence. | `ui/core` accepted; `util` rejected. |
| Raw retained starts | Ten raw starts have exact coherent prologues, bounded source behavior, no competing ownership, literal current raw prestates, and complete fail-closed define/rename/type/comment contracts. Zero direct xrefs do not prove dead code in an optimized static-link build. | Retained authored functions; source signatures inferred; safe IDA modeling handoff completed in Section 21. |
| Member/free/static split | Explicit `this`-relative field use identifies fourteen members; pointer-only operations identify twelve free helpers; address-local call flow identifies four file-local anchor helpers. | Resolved. |
| `Inset` and `RectArea` order | Physical address order places `Inset` inside the broader methods cluster and `RectArea` inside the free-helper sequence. Current sibling emission moves both later. | Nested child-route repair required. |
| Quarter constant | `0x0061a880` is exactly `0.25f`, has two reads only from `InsetByQuarter`, and has no source symbol/type/comment proof. | Compiler literal; evidence page remains non-emitting. |
| Half constant | `0x006104b0` is exactly `0.5f` with sixty project-wide refs. Three RectBounds reads do not establish ownership. | Shared pool data, not file-owned source. |
| Anchor jump tables | Tables at `0x004b7fe0`, `0x004b80ac`, `0x004b8170`, and `0x004b83b0` are compiler lowering inside their owning functions. | Covered/no authored C++. |
| Duplicate `RectBoundsLayout` | It repeats the exact four-int layout already owned by the class page and is absent as a distinct IDA UDT. | Non-emitting support page. |
| LineClip ownership | Its only direct callers are render/Surface routes; `ClipLineParameter` is private to `ClipLineToRect`. | Remains [UID:0000OC] `Surface.cpp`; removed from RectBounds review bucket. |
| Final names | Existing descriptive names match behavior and subsystem style. `Transpose3x3AnchorIndex`, `AdjustRectPairForAnchor`, `AdjustRectPairForAnchorWithOffsets`, and `AdjustRectAnchorAxis` are inferred, not original-symbol proof. | Accepted human-source names; no decompiler labels in formal C++. |
| Final C++ blocker | At dated command `000000025893`, output contained all thirty behavior bodies and `int RectArea(const RectBounds *bounds);`, composition/ownership order was wrong, and UID0001VP emitted an empty marker. Command `000000025640` is dated historical missing-H evidence only. | Preserve the declaration and apply the exact route/order repair supplied in Section 22. |

No investigable blocker remains in the report: the former missing raw-function modeling investigation is now closed by item-specific read-only evidence and complete fail-closed staged contracts. Actual IDA mutation remains a supervisor Gate 2B role boundary, not deferred B-agent research. The only confidence limits are original private spelling and absence of a rebuilt-binary equivalence result; neither blocks complete human-written source.

## Evidence Standards Used

- Strongest evidence: fresh path/session-bound MCP runtime attestation, exact function/item boundaries, instruction/decompile behavior, bytes and SHA256, complete low-count xref sets, terminal broad xref counts, stack frames, UDT layouts, constant decoding, and neighboring boundaries.
- Corroboration: current by-* metadata and prose, formal reconstruction blocks, generated CPP/H, matching archived reports, manual coverage, and source-tree structure.
- Negative evidence: zero-function/raw status, zero direct xrefs for retained raw starts, absence of separate vtable/RTTI/import/resource/string/global families, absence of a `RectBoundsLayout` UDT, and exclusion of unrelated neighboring code.
- Confidence is capped below certainty because no original PDB/source tree or compiler-equivalent rebuilt binary is available.

## Evidence Checked

- IDA MCP: `idb_list`, `runtime_attestation`, `lookup_funcs`, `inspect_items`, `decompile`, `func_profile`, `stack_frame`, `get_comments`, `get_bytes`, `xref_query`, `xrefs_to`, `callees`, UDT/type inspection, and bounded instruction queries across every inventory start, both literals, table heads, all 34 exact alignment spans, predecessor/successor code, and LineClip candidates.
- Live MCP snapshot, 2026-08-18: `idb_list` identified active canonical session `supervisor_uid0000hf_i0505_discard_retry_20260818` at exact path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; schema-1 runtime attestation passed with `ok:true` at listener time `2026-08-18T05:40:25.593172+00:00` and worker time `2026-08-18T05:40:25.706876+00:00`. `server_health` then returned `status:ok`, exact IDB path, Hex-Rays ready, string cache ready, and `auto_analysis_ready:false`; bounded valid reads succeeded, so the documented readiness flag did not constitute an outage. B001 re-enumerated `idb_list` before bounded query groups and used `inspect_items`, `lookup_funcs`, `get_comments`, `stack_frame`, `decompile`, `get_bytes`, `xref_query`, `callees`, `insn_query`, `entity_query`, and `type_inspect` to recheck all thirty bodies, ten raw starts, modeled frames and four channels, complete terminal xref counts/manifests, five table items, both literals, all 34 alignment spans, three source-type queries, neighboring boundaries, and LineClip callers. Session IDs are evidence-time context only, not permanent transaction prerequisites; every supervisor transaction must resolve and attest its own fresh canonical session dynamically.
- Docs: the target and all nineteen support/boundary/ownership destinations listed individually in Section 25, including `FramePartPane`, `WideStringHashHelper`, `FileExists`, `BuildFieldMapTextPath`, `by-memory/-ignored.md`, [UID:00016H]/[UID:0000OC] LineClip/Surface ownership, and the proposed source tree; generated RectBounds CPP/H; manual coverage rows; and matching archived child reports.
- Completeness searches: every modeled function and raw code start from `0x004b7670` through `0x004b83c5`; every item/table boundary and all 34 exact internal/boundary alignment spans; both floating literals; all related UID/name/address matches; generated definition/declaration counts; and neighboring functions through `0x004b83d0`.
- Negative checks: no authored vtable/RTTI/resource/import/string/global, no second RectBounds type, no distinct RectBoundsLayout UDT, no LineClip caller route back to this compilation unit, no inbound xref to any of the 34 alignment starts, and no unaccounted source-bearing gap.
- No validator was run and no IDA or ordinary document was mutated in this report-only phase.

## Claim And Incorporation Ledger

All 173 claims are report-only proposals and remain unchecked in this research artifact. Later ordinary implementation, supervisor-owned IDA/manual-coverage verification, validation, and lifecycle authority are represented only by their eventual physical artifacts and validator-owned metadata, not by mutable status assertions in this report-first snapshot.

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C001 | 0000N2 | The inferred RectBounds.cpp/.h unit owns exactly the thirty authored functions, four bounded compiler-table islands, and 34 no-code alignment spans in the complete inventory. | Very high | Complete range/item/source audit. | UID0000N2 whole-file inventory | incorporate | proposed |
| C002 | 00022G | 0x004b7670 RectBounds::IsEmptyOrInvalid is an authored const member. | High | Bytes, behavior, boundaries, docs and source route. | 00022G behavior/formal source | incorporate | proposed |
| C003 | 00022G | 0x004b7690 RectBounds::HasSameSizeAs is a retained raw const member. | High | Bytes, behavior, boundaries, docs and source route. | 00022G behavior/formal source | incorporate | proposed |
| C004 | 00022G | 0x004b76d0 RectBounds::ContainsPoint uses source parameter order y, x. | High | Bytes, behavior, boundaries, docs and source route. | 00022G behavior/formal source | incorporate | proposed |
| C005 | 00022G | 0x004b7700 RectBounds::ContainsRect is a retained raw const member. | High | Bytes, behavior, boundaries, docs and source route. | 00022G behavior/formal source | incorporate | proposed |
| C006 | 00022G | 0x004b7780 RectBounds::IntersectInto is a retained raw const member with optional output. | High | Bytes, behavior, boundaries, docs and source route. | 00022G behavior/formal source | incorporate | proposed |
| C007 | 00022G | 0x004b7830 RectBounds::UnionInto is a retained raw const member. | High | Bytes, behavior, boundaries, docs and source route. | 00022G behavior/formal source | incorporate | proposed |
| C008 | 00015Q | 0x004b78d0 RectBounds::SetLTRB writes the four exact fields. | High | Bytes, behavior, boundaries, docs and source route. | 00015Q behavior/formal source | incorporate | proposed |
| C009 | 00015Q | 0x004b78f0 RectBounds::Offset translates all four edges. | High | Bytes, behavior, boundaries, docs and source route. | 00015Q behavior/formal source | incorporate | proposed |
| C010 | 00015R | 0x004b7910 RectBounds::Inset shrinks and midpoint-collapses inverted axes. | High | Bytes, behavior, boundaries, docs and source route. | 00015R behavior/formal source | incorporate | proposed |
| C011 | 00015Q | 0x004b7960 RectBounds::IntersectWith mutates to intersection or zero. | High | Bytes, behavior, boundaries, docs and source route. | 00015Q behavior/formal source | incorporate | proposed |
| C012 | 00015Q | 0x004b7a00 RectBounds::UnionWith mutates and returns this. | High | Bytes, behavior, boundaries, docs and source route. | 00015Q behavior/formal source | incorporate | proposed |
| C013 | 00015Q | 0x004b7a80 RectBounds::ClampWithin translates the rectangle into limits. | High | Bytes, behavior, boundaries, docs and source route. | 00015Q behavior/formal source | incorporate | proposed |
| C014 | 00022H | 0x004b7af0 RectBounds::InsetByQuarter uses 0.25f and 0.5f rounding. | High | Bytes, behavior, boundaries, docs and source route. | 00022H behavior/formal source | incorporate | proposed |
| C015 | 00022H | 0x004b7b90 RectBounds::OutsetByHalf uses the shared 0.5f literal. | High | Bytes, behavior, boundaries, docs and source route. | 00022H behavior/formal source | incorporate | proposed |
| C016 | 00015S | 0x004b7c30 InitPointPair writes y then x. | High | Bytes, behavior, boundaries, docs and source route. | 00015S behavior/formal source | incorporate | proposed |
| C017 | 00015S | 0x004b7c50 InitRectBounds writes left, top, right, bottom. | High | Bytes, behavior, boundaries, docs and source route. | 00015S behavior/formal source | incorporate | proposed |
| C018 | 00015S | 0x004b7c70 InitRectBoundsFromSize computes right and bottom. | High | Bytes, behavior, boundaries, docs and source route. | 00015S behavior/formal source | incorporate | proposed |
| C019 | 00015T | 0x004b7ca0 RectArea multiplies signed width and height without validity clamp. | High | Bytes, behavior, boundaries, docs and source route. | 00015T behavior/formal source | incorporate | proposed |
| C020 | 00015S | 0x004b7cc0 IntersectRects implements nullable-output half-open intersection. | High | Bytes, behavior, boundaries, docs and source route. | 00015S behavior/formal source | incorporate | proposed |
| C021 | 00015S | 0x004b7d70 UnionRects implements empty-rectangle identity. | High | Bytes, behavior, boundaries, docs and source route. | 00015S behavior/formal source | incorporate | proposed |
| C022 | 00015S | 0x004b7e10 OffsetRect translates all four edges. | High | Bytes, behavior, boundaries, docs and source route. | 00015S behavior/formal source | incorporate | proposed |
| C023 | 00015S | 0x004b7e30 InsetRect mirrors member Inset midpoint collapse. | High | Bytes, behavior, boundaries, docs and source route. | 00015S behavior/formal source | incorporate | proposed |
| C024 | 00015S | 0x004b7e80 PointInRect uses y, x and half-open bounds. | High | Bytes, behavior, boundaries, docs and source route. | 00015S behavior/formal source | incorporate | proposed |
| C025 | 00015S | 0x004b7eb0 IsRectEmptyOrInvalid is the free predicate. | High | Bytes, behavior, boundaries, docs and source route. | 00015S behavior/formal source | incorporate | proposed |
| C026 | 00015S | 0x004b7ed0 RectsEquivalent treats two invalid rectangles as equivalent. | High | Bytes, behavior, boundaries, docs and source route. | 00015S behavior/formal source | incorporate | proposed |
| C027 | 00015S | 0x004b7f30 RectContainsRect uses inner, outer source order. | High | Bytes, behavior, boundaries, docs and source route. | 00015S behavior/formal source | incorporate | proposed |
| C028 | 00022I | 0x004b7f90 Transpose3x3AnchorIndex is a retained file-local raw helper. | High | Bytes, behavior, boundaries, docs and source route. | 00022I behavior/formal source | incorporate | proposed |
| C029 | 00022I | 0x004b8010 AdjustRectPairForAnchor is a retained file-local raw helper. | High | Bytes, behavior, boundaries, docs and source route. | 00022I behavior/formal source | incorporate | proposed |
| C030 | 00022I | 0x004b80d0 AdjustRectPairForAnchorWithOffsets is a retained file-local raw helper. | High | Bytes, behavior, boundaries, docs and source route. | 00022I behavior/formal source | incorporate | proposed |
| C031 | 00022L | 0x004b8290 AdjustRectAnchorAxis is the file-local axis implementation. | High | Bytes, behavior, boundaries, docs and source route. | 00022L behavior/formal source | incorporate | proposed |
| C032 | 0000BU | Point is 8 bytes with y@0 and x@4; RectBounds is 16 bytes with left/top/right/bottom at 0/4/8/12. | Very high | Live UDT layouts and field accesses. | UID0000BU formal H/layout | incorporate | proposed |
| C033 | 00040U | 0x0061a880 is compiler-pooled 0.25f with exactly two reads from InsetByQuarter and no authored global. | Very high | Exact bytes, decoded value and xrefs. | UID00040U literal evidence/no-code | incorporate | proposed |
| C034 | 00022H | 0x006104b0 is shared pooled 0.5f with sixty project-wide refs and is not RectBounds-owned source. | Very high | Exact bytes and terminal xref count. | UID00022H dependency evidence | incorporate | proposed |
| C035 | 00022I | The four anchor switch tables and terminal padding are compiler lowering covered by their owning helpers. | Very high | Exact item heads, refs and bounded bytes. | UID00022I/00022L range analysis | incorporate | proposed |
| C036 | 0000N2 | 0x004b81a0-0x004b8284 and 0x004b83d0 onward are unrelated neighboring source and excluded. | Very high | Distinct functions/docs and successor boundary. | UID0000N2 exclusions | incorporate | proposed |
| C037 | 00016H | LineClip remains Surface.cpp-owned and must leave the RectBounds review bucket. | Very high | Exclusive render callers and private helper calls. | UID00016H/UID0000OC/source-tree | reject-stale | proposed |
| C038 | 0000BU | UID0000BU remains the sole RectBounds class and header owner; no vtable or RTTI is invented. | Very high | UDT, absence checks and current route. | UID0000BU ownership/formal H | incorporate | proposed |
| C039 | 00015R | Nest UID00015R under UID00015Q at the marker between Offset and IntersectWith. | Very high | Exact address/source order. | UID00015Q CPP route | incorporate | proposed |
| C040 | 00015T | Preserve UID00015T's existing formal CPP/H and reparent its emitter beneath UID00015S after InitRectBoundsFromSize without recreating or overwriting its H declaration. | Very high | Current UID00015T is 88/92 with exact formal CPP/H; only ownership/source order remains wrong. | UID00015S/00015T CPP/H route | incorporate | proposed |
| C041 | 00040U | Clear UID00040U emitter metadata while retaining reconstructable literal evidence. | Very high | Compiler-pool/no-authored-symbol proof. | UID00040U metadata/no-code | incorporate | proposed |
| C042 | 0001VP | Clear UID0001VP emitter metadata and retain it as a duplicate layout support page. | Very high | No distinct UDT or source body. | UID0001VP metadata/no-code | incorporate | proposed |
| C043 | 0000N2 | Assign deterministic source positions to direct and nested children so generated order matches addresses. | Very high | Dated command 000000025893 generated misordering. | UID0000N2/0000BU child tables | incorporate | proposed |
| C044 | 0000N2 | Generate RectBounds.cpp with exactly thirty complete definitions in the accepted order and no empty marker. | Very high | Complete formal CPP and generated audit. | UID0000N2 generated closure | incorporate | proposed |
| C045 | 0000BU | Generate RectBounds.h with complete Point/RectBounds/free declarations including RectArea and one guard. | Very high | Complete formal H and generated audit. | UID0000BU generated closure | incorporate | proposed |
| C046 | 0000N2 | Finalize ui/core placement and historicalize the util/LineClip review alternatives in proposed-source-tree.md. | High | Subsystem and caller evidence. | proposed-source-tree RectBounds row | historicalize | proposed |
| C047 | 0000N2 | Preserve prior hypotheses and corrected generated defects as dated historical evidence rather than deleting them. | High | Current docs and archived reports. | UID0000N2 Historical Assumptions | historicalize | proposed |
| C048 | 0000N2 | Raise target/support scores only to the evidence-backed values in Section 26 and apply metadata changes exactly. | High | Resolved blockers and remaining limits. | Target/support metadata | incorporate | proposed |
| C049 | 0000N2 | Apply the exact supervisor-owned manual coverage replacements/inserts in Section 28. | High | Current manual rows physically inspected. | Manual coverage reports | incorporate | proposed |
| C050 | 0000N2 | During callback validate every changed ordinary page, perform one waited generated refresh, and physically verify final CPP/H. | Very high | Whole-file callback standard. | Validator/generated verification | incorporate | proposed |
| C051 | 0000BU | Protect the exact Point and RectBounds UDT layouts from mutation. | Very high | Live type inspection. | Section 21 P01 | incorporate | proposed |
| C052 | 00040U | Protect the quarter literal item, bytes, zero source type/comments, and two-xref set. | Very high | Live item/bytes/xrefs. | Section 21 P02 | incorporate | proposed |
| C053 | 00022H | Protect the shared half literal item, bytes, and sixty-ref project ownership. | Very high | Live item/bytes/xrefs. | Section 21 P03 | incorporate | proposed |
| C054 | 00022I | Protect all anchor switch-table heads/bytes/refs and all 34 exact alignment ranges/bytes/zero-inbound-xref starts. | Very high | Live items, bounded bytes and fresh per-span xref queries. | Section 21 P04A-P04E/P04G01-P04G34 | incorporate | proposed |
| C055 | 0000N2 | Define exact function [0x004b7690,0x004b76c8) for RectBounds::HasSameSizeAs. | High | Literal raw prestate, exact body hash/prologue/boundaries, zero xrefs and deterministic I01 readback. | Section 21 I01 define stage | incorporate | proposed |
| C056 | 0000N2 | Define exact function [0x004b7700,0x004b7775) for RectBounds::ContainsRect. | High | Literal raw prestate, exact body hash/prologue/boundaries, zero xrefs and deterministic I02 readback. | Section 21 I02 define stage | incorporate | proposed |
| C057 | 0000N2 | Define exact function [0x004b7780,0x004b782a) for RectBounds::IntersectInto. | High | Literal raw prestate, exact body hash/prologue/boundaries, zero xrefs and deterministic I03 readback. | Section 21 I03 define stage | incorporate | proposed |
| C058 | 0000N2 | Define exact function [0x004b7830,0x004b78c8) for RectBounds::UnionInto. | High | Literal raw prestate, exact body hash/prologue/boundaries, zero xrefs and deterministic I04 readback. | Section 21 I04 define stage | incorporate | proposed |
| C059 | 0000N2 | Define exact function [0x004b7960,0x004b79f7) for RectBounds::IntersectWith. | High | Literal raw prestate, exact body hash/prologue/boundaries, zero xrefs and deterministic I05 readback. | Section 21 I05 define stage | incorporate | proposed |
| C060 | 0000N2 | Define exact function [0x004b7af0,0x004b7b88) for RectBounds::InsetByQuarter. | High | Literal raw prestate, exact body hash/prologue/literal refs/boundaries, zero xrefs and deterministic I06 readback. | Section 21 I06 define stage | incorporate | proposed |
| C061 | 0000N2 | Define exact function [0x004b7b90,0x004b7c21) for RectBounds::OutsetByHalf. | High | Literal raw prestate, exact body hash/prologue/literal refs/boundaries, zero xrefs and deterministic I07 readback. | Section 21 I07 define stage | incorporate | proposed |
| C062 | 0000N2 | Define exact function [0x004b7f90,0x004b7fe0) for Transpose3x3AnchorIndex. | High | Literal raw prestate, exact body hash/prologue/table/boundaries, zero xrefs and deterministic I08 readback. | Section 21 I08 define stage | incorporate | proposed |
| C063 | 0000N2 | Define exact function [0x004b8010,0x004b80ac) for AdjustRectPairForAnchor. | High | Literal raw prestate, exact body hash/prologue/calls/table/boundary, zero xrefs and deterministic I09 readback. | Section 21 I09 define stage | incorporate | proposed |
| C064 | 0000N2 | Define exact function [0x004b80d0,0x004b8170) for AdjustRectPairForAnchorWithOffsets. | High | Literal raw prestate, exact body hash/prologue/calls/tables/boundaries, zero xrefs and deterministic I10 readback. | Section 21 I10 define stage | incorporate | proposed |
| C065 | 0000N2 | Pure-rename defined 0x004b7690 to RectBounds__HasSameSizeAs while preserving its define-stage type/frame/body/xrefs. | High | Literal I11 post-define prestate, destination collision gate and exact rename readback. | Section 21 I11 rename stage | incorporate | proposed |
| C066 | 0000N2 | Pure-rename defined 0x004b7700 to RectBounds__ContainsRect while preserving its define-stage type/frame/body/xrefs. | High | Literal I12 post-define prestate, destination collision gate and exact rename readback. | Section 21 I12 rename stage | incorporate | proposed |
| C067 | 0000N2 | Pure-rename defined 0x004b7780 to RectBounds__IntersectInto while preserving its define-stage type/frame/body/xrefs. | High | Literal I13 post-define prestate, destination collision gate and exact rename readback. | Section 21 I13 rename stage | incorporate | proposed |
| C068 | 0000N2 | Pure-rename defined 0x004b7830 to RectBounds__UnionInto while preserving its define-stage type/frame/body/xrefs. | High | Literal I14 post-define prestate, destination collision gate and exact rename readback. | Section 21 I14 rename stage | incorporate | proposed |
| C069 | 0000N2 | Pure-rename defined 0x004b7960 to RectBounds__IntersectWith while preserving its define-stage type/frame/body/xrefs. | High | Literal I15 post-define prestate, destination collision gate and exact rename readback. | Section 21 I15 rename stage | incorporate | proposed |
| C070 | 0000N2 | Pure-rename defined 0x004b7af0 to RectBounds__InsetByQuarter while preserving its define-stage type/frame/body/xrefs. | High | Literal I16 post-define prestate, destination collision gate and exact rename readback. | Section 21 I16 rename stage | incorporate | proposed |
| C071 | 0000N2 | Pure-rename defined 0x004b7b90 to RectBounds__OutsetByHalf while preserving its define-stage type/frame/body/xrefs. | High | Literal I17 post-define prestate, destination collision gate and exact rename readback. | Section 21 I17 rename stage | incorporate | proposed |
| C072 | 0000N2 | Pure-rename defined 0x004b7f90 to Transpose3x3AnchorIndex while preserving its define-stage type/frame/body/xrefs. | High | Literal I18 post-define prestate, destination collision gate and exact rename readback. | Section 21 I18 rename stage | incorporate | proposed |
| C073 | 0000N2 | Pure-rename defined 0x004b8010 to AdjustRectPairForAnchor while preserving its define-stage type/frame/body/xrefs. | High | Literal I19 post-define prestate, destination collision gate and exact rename readback. | Section 21 I19 rename stage | incorporate | proposed |
| C074 | 0000N2 | Pure-rename defined 0x004b80d0 to AdjustRectPairForAnchorWithOffsets while preserving its define-stage type/frame/body/xrefs. | High | Literal I20 post-define prestate, destination collision gate and exact rename readback. | Section 21 I20 rename stage | incorporate | proposed |
| C075 | 0000N2 | Pure-rename modeled function 0x004b7670 to RectBounds__IsEmptyOrInvalid under its exact persisted-IDB/decompiler/public-presentation contract. | High | Three-channel I21 pre/post evidence, behavior, docs and source route. | Section 21 RectBounds__IsEmptyOrInvalid rename | incorporate | proposed |
| C076 | 0000N2 | Pure-rename modeled function 0x004b76d0 to RectBounds__ContainsPoint under its exact persisted-IDB/decompiler/public-presentation contract. | High | Three-channel I22 pre/post evidence, behavior, docs and source route. | Section 21 RectBounds__ContainsPoint rename | incorporate | proposed |
| C077 | 0000N2 | Pure-rename modeled function 0x004b78d0 to RectBounds__SetLTRB under its exact persisted-IDB/decompiler/public-presentation contract. | High | Three-channel I23 pre/post evidence, behavior, docs and source route. | Section 21 RectBounds__SetLTRB rename | incorporate | proposed |
| C078 | 0000N2 | Pure-rename modeled function 0x004b7910 to RectBounds__Inset under its exact persisted-IDB/decompiler/public-presentation contract. | High | Three-channel I24 pre/post evidence, behavior, docs and source route. | Section 21 RectBounds__Inset rename | incorporate | proposed |
| C079 | 0000N2 | Pure-rename modeled function 0x004b7a00 to RectBounds__UnionWith under its exact persisted-IDB/decompiler/public-presentation contract. | High | Three-channel I25 pre/post evidence, behavior, docs and source route. | Section 21 RectBounds__UnionWith rename | incorporate | proposed |
| C080 | 0000N2 | Pure-rename modeled function 0x004b7a80 to RectBounds__ClampWithin under its exact persisted-IDB/decompiler/public-presentation contract. | High | Three-channel I26 pre/post evidence, behavior, docs and source route. | Section 21 RectBounds__ClampWithin rename | incorporate | proposed |
| C081 | 0000N2 | Pure-rename modeled function 0x004b7c70 to InitRectBoundsFromSize under its exact persisted-IDB/decompiler/public-presentation contract. | High | Three-channel I27 pre/post evidence, behavior, docs and source route. | Section 21 InitRectBoundsFromSize rename | incorporate | proposed |
| C082 | 0000N2 | Pure-rename modeled function 0x004b7ca0 to RectArea under its exact persisted-IDB/decompiler/public-presentation contract. | High | Three-channel I28 pre/post evidence, behavior, docs and source route. | Section 21 RectArea rename | incorporate | proposed |
| C083 | 0000N2 | Pure-rename modeled function 0x004b7e30 to InsetRect under its exact persisted-IDB/decompiler/public-presentation contract. | High | Three-channel I29 pre/post evidence, behavior, docs and source route. | Section 21 InsetRect rename | incorporate | proposed |
| C084 | 0000N2 | Pure-rename modeled function 0x004b7f30 to RectContainsRect under its exact persisted-IDB/decompiler/public-presentation contract. | High | Three-channel I30 pre/post evidence, behavior, docs and source route. | Section 21 RectContainsRect rename | incorporate | proposed |
| C085 | 0000N2 | Pure-rename modeled function 0x004b8290 to AdjustRectAnchorAxis under its exact persisted-IDB/decompiler/public-presentation contract. | High | Three-channel I31 pre/post evidence, behavior, docs and source route. | Section 21 AdjustRectAnchorAxis rename | incorporate | proposed |
| C086 | 0000N2 | Apply the exact source-quality function type for RectBounds__IsEmptyOrInvalid at 0x004b7670 with protected frame deltas. | High | Calling convention, body and current frame. | Section 21 RectBounds__IsEmptyOrInvalid type | incorporate | proposed |
| C087 | 0000N2 | Apply the exact source-quality function type for RectBounds__ContainsPoint at 0x004b76d0 with protected frame deltas. | High | Calling convention, body and current frame. | Section 21 RectBounds__ContainsPoint type | incorporate | proposed |
| C088 | 0000N2 | Apply the exact source-quality function type for RectBounds__SetLTRB at 0x004b78d0 with protected frame deltas. | High | Calling convention, body and current frame. | Section 21 RectBounds__SetLTRB type | incorporate | proposed |
| C089 | 0000N2 | Apply the exact source-quality function type for RectBounds__Inset at 0x004b7910 with protected frame deltas. | High | Calling convention, body and current frame. | Section 21 RectBounds__Inset type | incorporate | proposed |
| C090 | 0000N2 | Apply the exact source-quality function type for RectBounds__UnionWith at 0x004b7a00 with protected frame deltas. | High | Calling convention, body and current frame. | Section 21 RectBounds__UnionWith type | incorporate | proposed |
| C091 | 0000N2 | Apply the exact source-quality function type for RectBounds__ClampWithin at 0x004b7a80 with protected frame deltas. | High | Calling convention, body and current frame. | Section 21 RectBounds__ClampWithin type | incorporate | proposed |
| C092 | 0000N2 | Apply the exact source-quality function type for InitRectBoundsFromSize at 0x004b7c70 with protected frame deltas. | High | Calling convention, body and current frame. | Section 21 InitRectBoundsFromSize type | incorporate | proposed |
| C093 | 0000N2 | Apply the exact source-quality function type for RectArea at 0x004b7ca0 with protected frame deltas. | High | Calling convention, body and current frame. | Section 21 RectArea type | incorporate | proposed |
| C094 | 0000N2 | Apply the exact source-quality function type for InsetRect at 0x004b7e30 with protected frame deltas. | High | Calling convention, body and current frame. | Section 21 InsetRect type | incorporate | proposed |
| C095 | 0000N2 | Apply the exact source-quality function type for RectContainsRect at 0x004b7f30 with protected frame deltas. | High | Calling convention, body and current frame. | Section 21 RectContainsRect type | incorporate | proposed |
| C096 | 0000N2 | Apply the exact source-quality function type for AdjustRectAnchorAxis at 0x004b8290 with protected frame deltas. | High | Calling convention, body and current frame. | Section 21 AdjustRectAnchorAxis type | incorporate | proposed |
| C097 | 0000N2 | Apply the exact repeatable source-role comment for RectBounds__HasSameSizeAs at 0x004b7690. | High | Complete post-type state and exact behavior. | Section 21 I43 comment stage | incorporate | proposed |
| C098 | 0000N2 | Apply the exact repeatable source-role comment for RectBounds__ContainsRect at 0x004b7700. | High | Complete post-type state and exact behavior. | Section 21 I44 comment stage | incorporate | proposed |
| C099 | 0000N2 | Apply the exact repeatable source-role comment for RectBounds__IntersectInto at 0x004b7780. | High | Complete post-type state and exact behavior. | Section 21 I45 comment stage | incorporate | proposed |
| C100 | 0000N2 | Apply the exact repeatable source-role comment for RectBounds__UnionInto at 0x004b7830. | High | Complete post-type state and exact behavior. | Section 21 I46 comment stage | incorporate | proposed |
| C101 | 0000N2 | Apply the exact repeatable source-role comment for RectBounds__IntersectWith at 0x004b7960. | High | Complete post-type state and exact behavior. | Section 21 I47 comment stage | incorporate | proposed |
| C102 | 0000N2 | Apply the exact repeatable source-role comment for RectBounds__InsetByQuarter at 0x004b7af0. | High | Complete post-type state, exact literal behavior and boundaries. | Section 21 I48 comment stage | incorporate | proposed |
| C103 | 0000N2 | Apply the exact repeatable source-role comment for RectBounds__OutsetByHalf at 0x004b7b90. | High | Complete post-type state, exact literal behavior and boundaries. | Section 21 I49 comment stage | incorporate | proposed |
| C104 | 0000N2 | Apply the exact repeatable source-role comment for Transpose3x3AnchorIndex at 0x004b7f90. | High | Complete post-type state, exact table behavior and boundaries. | Section 21 I50 comment stage | incorporate | proposed |
| C105 | 0000N2 | Apply the exact repeatable source-role comment for AdjustRectPairForAnchor at 0x004b8010. | High | Complete post-type state, exact calls/table behavior and boundaries. | Section 21 I51 comment stage | incorporate | proposed |
| C106 | 0000N2 | Apply the exact repeatable source-role comment for AdjustRectPairForAnchorWithOffsets at 0x004b80d0. | High | Complete post-type state, exact calls/table behavior and boundaries. | Section 21 I52 comment stage | incorporate | proposed |
| C107 | 0000N2 | Apply the exact repeatable source-role comment for RectBounds__IsEmptyOrInvalid at 0x004b7670. | High | Resolved source role and boundary. | Section 21 RectBounds__IsEmptyOrInvalid comment | incorporate | proposed |
| C108 | 0000N2 | Apply the exact repeatable source-role comment for RectBounds__ContainsPoint at 0x004b76d0. | High | Resolved source role and boundary. | Section 21 RectBounds__ContainsPoint comment | incorporate | proposed |
| C109 | 0000N2 | Apply the exact repeatable source-role comment for RectBounds__SetLTRB at 0x004b78d0. | High | Resolved source role and boundary. | Section 21 RectBounds__SetLTRB comment | incorporate | proposed |
| C110 | 0000N2 | Apply the exact repeatable source-role comment for RectBounds__Inset at 0x004b7910. | High | Resolved source role and boundary. | Section 21 RectBounds__Inset comment | incorporate | proposed |
| C111 | 0000N2 | Apply the exact repeatable source-role comment for RectBounds__UnionWith at 0x004b7a00. | High | Resolved source role and boundary. | Section 21 RectBounds__UnionWith comment | incorporate | proposed |
| C112 | 0000N2 | Apply the exact repeatable source-role comment for RectBounds__ClampWithin at 0x004b7a80. | High | Resolved source role and boundary. | Section 21 RectBounds__ClampWithin comment | incorporate | proposed |
| C113 | 0000N2 | Apply the exact repeatable source-role comment for InitRectBoundsFromSize at 0x004b7c70. | High | Resolved source role and boundary. | Section 21 InitRectBoundsFromSize comment | incorporate | proposed |
| C114 | 0000N2 | Apply the exact repeatable source-role comment for RectArea at 0x004b7ca0. | High | Resolved source role and boundary. | Section 21 RectArea comment | incorporate | proposed |
| C115 | 0000N2 | Apply the exact repeatable source-role comment for InsetRect at 0x004b7e30. | High | Resolved source role and boundary. | Section 21 InsetRect comment | incorporate | proposed |
| C116 | 0000N2 | Apply the exact repeatable source-role comment for RectContainsRect at 0x004b7f30. | High | Resolved source role and boundary. | Section 21 RectContainsRect comment | incorporate | proposed |
| C117 | 0000N2 | Apply the exact repeatable source-role comment for AdjustRectAnchorAxis at 0x004b8290. | High | Resolved source role and boundary. | Section 21 AdjustRectAnchorAxis comment | incorporate | proposed |
| C118 | 0000N2 | Preserve already-present source-quality identity RectBounds_Offset at 0x004b78f0; no mutation is recommended. | Very high | Exact current name/type/comments/readback. | Section 21 RectBounds_Offset protection | already-present | proposed |
| C119 | 0000N2 | Preserve already-present source-quality identity InitPointPair at 0x004b7c30; no mutation is recommended. | Very high | Exact current name/type/comments/readback. | Section 21 InitPointPair protection | already-present | proposed |
| C120 | 0000N2 | Preserve already-present source-quality identity InitRectBounds at 0x004b7c50; no mutation is recommended. | Very high | Exact current name/type/comments/readback. | Section 21 InitRectBounds protection | already-present | proposed |
| C121 | 0000N2 | Preserve already-present source-quality identity IntersectRects at 0x004b7cc0; no mutation is recommended. | Very high | Exact current name/type/comments/readback. | Section 21 IntersectRects protection | already-present | proposed |
| C122 | 0000N2 | Preserve already-present source-quality identity UnionRects at 0x004b7d70; no mutation is recommended. | Very high | Exact current name/type/comments/readback. | Section 21 UnionRects protection | already-present | proposed |
| C123 | 0000N2 | Preserve already-present source-quality identity NexusTK_OffsetRect at 0x004b7e10; no mutation is recommended. | Very high | Exact current name/type/comments/readback. | Section 21 NexusTK_OffsetRect protection | already-present | proposed |
| C124 | 0000N2 | Preserve the already-present PointInRect function identity at 0x004b7e80 while applying only the exact I64-I66 physical-frame repairs. | Very high | Exact current name/type/comments/readback. | Section 21 PointInRect protection | already-present | proposed |
| C125 | 0000N2 | Preserve already-present source-quality identity IsRectEmptyOrInvalid at 0x004b7eb0; no mutation is recommended. | Very high | Exact current name/type/comments/readback. | Section 21 IsRectEmptyOrInvalid protection | already-present | proposed |
| C126 | 0000N2 | Preserve already-present source-quality identity RectsEquivalent at 0x004b7ed0; no mutation is recommended. | Very high | Exact current name/type/comments/readback. | Section 21 RectsEquivalent protection | already-present | proposed |
| C127 | 00015S | Rename PointInRect stack row to y without changing its int type or offset. | Very high | Function tinfo says y while physical stack metadata says row. | Section 21 I64 | incorporate | proposed |
| C128 | 00015S | Rename PointInRect stack column to x without changing its int type or offset. | Very high | Function tinfo says x while physical stack metadata says column. | Section 21 I65 | incorporate | proposed |
| C129 | 00015S | Retype PointInRect stack bounds from const MapRect * to const RectBounds * without changing its name/offset. | Very high | Exact function tinfo and field behavior contradict stale stack metadata. | Section 21 I66 | incorporate | proposed |
| C130 | 0000N2 | Preserve `0x004b7661-0x004b7670` as 15-byte `cc` predecessor alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and boundary pages. | UID0000N2 inventory; FramePartPane boundary; by-memory/-ignored.md | incorporate | proposed |
| C131 | 00022G | Preserve `0x004b7685-0x004b7690` as 11-byte `cc` internal alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and UID00022G boundaries. | UID00022G Range/Boundary; by-memory/-ignored.md | incorporate | proposed |
| C132 | 00022G | Preserve `0x004b76c8-0x004b76d0` as 8-byte `cc` internal alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and UID00022G boundaries. | UID00022G Range/Boundary; by-memory/-ignored.md | incorporate | proposed |
| C133 | 00022G | Preserve `0x004b76f8-0x004b7700` as 8-byte `cc` internal alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and UID00022G boundaries. | UID00022G Range/Boundary; by-memory/-ignored.md | incorporate | proposed |
| C134 | 00022G | Preserve `0x004b7775-0x004b7780` as 11-byte `cc` internal alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and UID00022G boundaries. | UID00022G Range/Boundary; by-memory/-ignored.md | incorporate | proposed |
| C135 | 00022G | Preserve `0x004b782a-0x004b7830` as 6-byte `cc` internal alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and UID00022G boundaries. | UID00022G Range/Boundary; by-memory/-ignored.md | incorporate | proposed |
| C136 | 00022G | Preserve `0x004b78c8-0x004b78d0` as 8-byte `cc` UID00022G-to-UID00015Q boundary alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and support boundaries. | UID00022G Range/Boundary; by-memory/-ignored.md | incorporate | proposed |
| C137 | 00015Q | Preserve `0x004b78ee-0x004b78f0` as 2-byte `cc` member alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and UID00015Q boundaries. | UID00015Q Range/Boundary; by-memory/-ignored.md | incorporate | proposed |
| C138 | 00015Q | Preserve `0x004b7908-0x004b7910` as 8-byte `cc` UID00015Q-to-UID00015R boundary alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and nested-child boundaries. | UID00015Q/UID00015R Range/Boundary; by-memory/-ignored.md | incorporate | proposed |
| C139 | 00015R | Preserve `0x004b795e-0x004b7960` as 2-byte `cc` UID00015R-to-UID00015Q boundary alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and nested-child boundaries. | UID00015R/UID00015Q Range/Boundary; by-memory/-ignored.md | incorporate | proposed |
| C140 | 00015Q | Preserve `0x004b79f7-0x004b7a00` as 9-byte `cc` member alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and UID00015Q boundaries. | UID00015Q Range/Boundary; by-memory/-ignored.md | incorporate | proposed |
| C141 | 00015Q | Preserve `0x004b7a77-0x004b7a80` as 9-byte `cc` member alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and UID00015Q boundaries. | UID00015Q Range/Boundary; by-memory/-ignored.md | incorporate | proposed |
| C142 | 00015Q | Preserve `0x004b7ae8-0x004b7af0` as 8-byte `cc` UID00015Q-to-UID00022H boundary alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and support boundaries. | UID00015Q/UID00022H Range/Boundary; by-memory/-ignored.md | incorporate | proposed |
| C143 | 00022H | Preserve `0x004b7b88-0x004b7b90` as 8-byte `cc` helper alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and UID00022H boundaries. | UID00022H Range/Boundary; by-memory/-ignored.md | incorporate | proposed |
| C144 | 00022H | Preserve `0x004b7c21-0x004b7c30` as 15-byte `cc` UID00022H-to-UID00015S boundary alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and support boundaries. | UID00022H/UID00015S Range/Boundary; by-memory/-ignored.md | incorporate | proposed |
| C145 | 00015S | Preserve `0x004b7c43-0x004b7c50` as 13-byte `cc` geometry-helper alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and UID00015S ranges. | UID00015S Function Inventory/Range; by-memory/-ignored.md | incorporate | proposed |
| C146 | 00015S | Preserve `0x004b7c6f-0x004b7c70` as 1-byte `cc` geometry-helper alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and UID00015S ranges. | UID00015S Function Inventory/Range; by-memory/-ignored.md | incorporate | proposed |
| C147 | 00015S | Preserve `0x004b7c95-0x004b7ca0` as 11-byte `cc` UID00015S-to-UID00015T boundary alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and nested-child boundaries. | UID00015S/UID00015T Range; by-memory/-ignored.md | incorporate | proposed |
| C148 | 00015T | Preserve `0x004b7cb6-0x004b7cc0` as 10-byte `cc` UID00015T-to-UID00015S boundary alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and nested-child boundaries. | UID00015T/UID00015S Range; by-memory/-ignored.md | incorporate | proposed |
| C149 | 00015S | Preserve `0x004b7d69-0x004b7d70` as 7-byte `cc` geometry-helper alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and UID00015S ranges. | UID00015S Function Inventory/Range; by-memory/-ignored.md | incorporate | proposed |
| C150 | 00015S | Preserve `0x004b7e03-0x004b7e10` as 13-byte `cc` geometry-helper alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and UID00015S ranges. | UID00015S Function Inventory/Range; by-memory/-ignored.md | incorporate | proposed |
| C151 | 00015S | Preserve `0x004b7e29-0x004b7e30` as 7-byte `cc` geometry-helper alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and UID00015S ranges. | UID00015S Function Inventory/Range; by-memory/-ignored.md | incorporate | proposed |
| C152 | 00015S | Preserve `0x004b7e7f-0x004b7e80` as 1-byte `cc` geometry-helper alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and UID00015S ranges. | UID00015S Function Inventory/Range; by-memory/-ignored.md | incorporate | proposed |
| C153 | 00015S | Preserve `0x004b7ea7-0x004b7eb0` as 9-byte `cc` geometry-helper alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and UID00015S ranges. | UID00015S Function Inventory/Range; by-memory/-ignored.md | incorporate | proposed |
| C154 | 00015S | Preserve `0x004b7ecd-0x004b7ed0` as 3-byte `cc` geometry-helper alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and UID00015S ranges. | UID00015S Function Inventory/Range; by-memory/-ignored.md | incorporate | proposed |
| C155 | 00015S | Preserve `0x004b7f22-0x004b7f30` as 14-byte `cc` geometry-helper alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and UID00015S ranges. | UID00015S Function Inventory/Range; by-memory/-ignored.md | incorporate | proposed |
| C156 | 00015S | Preserve `0x004b7f87-0x004b7f90` as 9-byte `cc` UID00015S-to-UID00022I boundary alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and support boundaries. | UID00015S/UID00022I Range/Boundary; by-memory/-ignored.md | incorporate | proposed |
| C157 | 00022I | Preserve `0x004b8004-0x004b8010` as 12-byte `cc` helper/table-tail alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and UID00022I boundaries. | UID00022I Range/Boundary; by-memory/-ignored.md | incorporate | proposed |
| C158 | 00022I | Preserve `0x004b8194-0x004b81a0` as 12-byte `cc` UID00022I-to-UID00022J boundary alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and support boundaries. | UID00022I/UID00022J Range/Boundary; by-memory/-ignored.md | incorporate | proposed |
| C159 | 00022J | Preserve `0x004b81eb-0x004b81f0` as 5-byte `cc` UID00022J-to-UID00022K boundary alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and support boundaries. | UID00022J/UID00022K Range/Boundary; by-memory/-ignored.md | incorporate | proposed |
| C160 | 00022K | Preserve `0x004b821e-0x004b8220` as 2-byte `cc` UID00022K-to-UID00015U boundary alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and support boundaries. | UID00022K/UID00015U Range/Boundary; by-memory/-ignored.md | incorporate | proposed |
| C161 | 00015U | Preserve `0x004b8284-0x004b8290` as 12-byte `cc` UID00015U-to-UID00022L boundary alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and support boundaries. | UID00015U/UID00022L Range/Boundary; by-memory/-ignored.md | incorporate | proposed |
| C162 | 00022L | Preserve `0x004b83ae-0x004b83b0` as exact `66 90` two-byte NOP alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and UID00022L body/table boundary. | UID00022L Range/Boundary | incorporate | proposed |
| C163 | 00022L | Preserve `0x004b83c5-0x004b83d0` as 11-byte `cc` successor alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and successor boundary. | UID00022L Range/Boundary; by-memory/-ignored.md | incorporate | proposed |
| C164 | 0000N2 | Apply the exact source-quality type/frame for RectBounds__HasSameSizeAs. | High | Exact signature, calling convention, define-stage frame, body and zero-xref evidence. | Section 21 I11T type stage | incorporate | proposed |
| C165 | 0000N2 | Apply the exact source-quality type/frame for RectBounds__ContainsRect. | High | Exact signature, calling convention, define-stage frame, body and zero-xref evidence. | Section 21 I12T type stage | incorporate | proposed |
| C166 | 0000N2 | Apply the exact source-quality type/frame for RectBounds__IntersectInto. | High | Exact signature, calling convention, define-stage frame, body and zero-xref evidence. | Section 21 I13T type stage | incorporate | proposed |
| C167 | 0000N2 | Apply the exact source-quality type/frame for RectBounds__UnionInto. | High | Exact signature, calling convention, define-stage frame, body and zero-xref evidence. | Section 21 I14T type stage | incorporate | proposed |
| C168 | 0000N2 | Apply the exact source-quality type/frame for RectBounds__IntersectWith. | High | Exact signature, calling convention, define-stage frame, body and zero-xref evidence. | Section 21 I15T type stage | incorporate | proposed |
| C169 | 0000N2 | Apply the exact source-quality type/frame for RectBounds__InsetByQuarter. | High | Exact signature, calling convention, define-stage frame, literal refs and zero-xref evidence. | Section 21 I16T type stage | incorporate | proposed |
| C170 | 0000N2 | Apply the exact source-quality type/frame for RectBounds__OutsetByHalf. | High | Exact signature, calling convention, define-stage frame, literal refs and zero-xref evidence. | Section 21 I17T type stage | incorporate | proposed |
| C171 | 0000N2 | Apply the exact source-quality type/frame for Transpose3x3AnchorIndex. | High | Exact cdecl signature, define-stage frame, switch table and zero-xref evidence. | Section 21 I18T type stage | incorporate | proposed |
| C172 | 0000N2 | Apply the exact source-quality type/frame for AdjustRectPairForAnchor. | High | Exact cdecl signature, define-stage frame, call/table and zero-xref evidence. | Section 21 I19T type stage | incorporate | proposed |
| C173 | 0000N2 | Apply the exact source-quality type/frame for AdjustRectPairForAnchorWithOffsets. | High | Exact cdecl signature, define-stage frame, call/table and zero-xref evidence. | Section 21 I20T type stage | incorporate | proposed |

## Positive Evidence Summary

- Exact field accesses prove the four-int `RectBounds` layout and distinguish member functions from pointer-based free helpers.
- Exact contiguous ordering, raw-body bounds, intra-family calls, table refs, and the absence of a competing owner prove the authored family and source order.
- Every accepted body has a human-source formal implementation matching the binary's half-open geometry rules, empty-rectangle conventions, midpoint collapse, signed area, and anchor clipping behavior.
- The dated command `000000025893` generated output independently corroborates the thirty-function family and the existing `RectArea` H declaration while exposing composition/order and empty-emitter defects, not missing behavior; the command `000000025640` declaration omission is historical/superseded.
- The strongest inference chain is: exact behavior and calling convention -> member/free/static role -> established UI-core type ownership -> deterministic child nesting -> complete CPP/H output. No alternative explains the same full inventory with fewer artificial files or duplicate declarations.

## IDA MCP Facts

- Runtime: the dated 2026-08-18 research snapshot used active canonical session `supervisor_uid0000hf_i0505_discard_retry_20260818`; schema-1 exact-path attestation passed at listener `2026-08-18T05:40:25.593172+00:00` and worker `2026-08-18T05:40:25.706876+00:00`. This is evidence-time context, not permanent transaction authority; the supervisor must dynamically resolve and attest a fresh canonical session at Gate 2B.
- Function state at the dated evidence-time readback: twenty starts are modeled functions and ten retained starts are currently unmodeled raw code. Every start, end, size, current name/type/comment state, frame where modeled, body hash and boundary was checked; Section 21 now supplies complete item-specific define, rename, source-quality type/frame, comment and protected-poststate contracts for all ten raw starts rather than treating current raw state as a final disposition.
- Data state: `0x0061a880` is four bytes `00 00 80 3e` (`0.25f`) with two refs; `0x006104b0` is four bytes `00 00 00 3f` (`0.5f`) with sixty refs.
- Type state: `Point` is an exact 8-byte UDT (`y@0`, `x@4`); `RectBounds` is an exact 16-byte UDT (`left@0`, `top@4`, `right@8`, `bottom@12`); no distinct `RectBoundsLayout` UDT exists.
- Table/alignment state: `0x004b7fe0`, `0x004b80ac`, `0x004b8170`, `0x004b83b0`, and `0x004b83bc` each have one exact owning dispatch ref. Section 14 itemizes all 34 exact no-code alignment spans: 33 pure `cc` ranges and the `66 90` NOP at `0x004b83ae-0x004b83b0`; every span start has zero inbound xrefs. The terminal axis body ends at `0x004b83ae`, and `0x004b83c5-0x004b83d0` is the final successor padding.
- Negative state: no file-owned vtable, RTTI, import, string, resource, singleton, mutable global, or constructor/destructor family was found.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004b7670-0x004b7685` | 00022G | `RectBounds::IsEmptyOrInvalid` | yes | 0000BU | 91/90 | Complete CPP/H member; modeled. |
| `0x004b7690-0x004b76c8` | 00022G | `RectBounds::HasSameSizeAs` | yes | 0000BU | 91/90 | Complete CPP/H member; retained raw start. |
| `0x004b76d0-0x004b76f8` | 00022G | `RectBounds::ContainsPoint(y,x)` | yes | 0000BU | 91/90 | Complete CPP/H member; modeled. |
| `0x004b7700-0x004b7775` | 00022G | `RectBounds::ContainsRect` | yes | 0000BU | 91/90 | Complete CPP/H member; retained raw start. |
| `0x004b7780-0x004b782a` | 00022G | `RectBounds::IntersectInto` | yes | 0000BU | 91/90 | Complete CPP/H member; retained raw start. |
| `0x004b7830-0x004b78c8` | 00022G | `RectBounds::UnionInto` | yes | 0000BU | 91/90 | Complete CPP/H member; retained raw start. |
| `0x004b78d0-0x004b78ee` | 00015Q | `RectBounds::SetLTRB` | yes | 0000BU | 91/91 | Complete CPP/H member; modeled. |
| `0x004b78f0-0x004b7908` | 00015Q | `RectBounds::Offset` | yes | 0000BU | 91/91 | Complete CPP/H member; modeled/source-named. |
| `0x004b7910-0x004b795e` | 00015R | `RectBounds::Inset` | yes | proposed 00015Q | 90/92 | Complete CPP/H child; current sibling route misorders it. |
| `0x004b7960-0x004b79f7` | 00015Q | `RectBounds::IntersectWith` | yes | 0000BU | 91/91 | Complete CPP/H member; retained raw start. |
| `0x004b7a00-0x004b7a77` | 00015Q | `RectBounds::UnionWith` | yes | 0000BU | 91/91 | Complete CPP/H member; modeled. |
| `0x004b7a80-0x004b7ae8` | 00015Q | `RectBounds::ClampWithin` | yes | 0000BU | 91/91 | Complete CPP/H member; modeled. |
| `0x004b7af0-0x004b7b88` | 00022H | `RectBounds::InsetByQuarter` | yes | 0000BU | 89/90 | Complete CPP/H member; retained raw start. |
| `0x004b7b90-0x004b7c21` | 00022H | `RectBounds::OutsetByHalf` | yes | 0000BU | 89/90 | Complete CPP/H member; retained raw start. |
| `0x004b7c30-0x004b7c43` | 00015S | `InitPointPair` | yes | 0000N2 | 92/93 | Complete CPP/H free helper; modeled/source-named. |
| `0x004b7c50-0x004b7c6f` | 00015S | `InitRectBounds` | yes | 0000N2 | 92/93 | Complete CPP/H free helper; modeled/source-named. |
| `0x004b7c70-0x004b7c95` | 00015S | `InitRectBoundsFromSize` | yes | 0000N2 | 92/93 | Complete CPP/H free helper; modeled. |
| `0x004b7ca0-0x004b7cb6` | 00015T | `RectArea` | yes | proposed 00015S | 88/92 | Complete CPP body and exact formal H declaration are present; current sibling route alone misorders them. |
| `0x004b7cc0-0x004b7d69` | 00015S | `IntersectRects` | yes | 0000N2 | 92/93 | Complete CPP/H free helper; modeled/source-named. |
| `0x004b7d70-0x004b7e03` | 00015S | `UnionRects` | yes | 0000N2 | 92/93 | Complete CPP/H free helper; modeled/source-named. |
| `0x004b7e10-0x004b7e29` | 00015S | `OffsetRect` | yes | 0000N2 | 92/93 | Complete CPP/H free helper; modeled/source-named. |
| `0x004b7e30-0x004b7e7f` | 00015S | `InsetRect` | yes | 0000N2 | 92/93 | Complete CPP/H free helper; modeled. |
| `0x004b7e80-0x004b7ea7` | 00015S | `PointInRect(y,x,bounds)` | yes | 0000N2 | 92/93 | Complete CPP/H free helper; modeled/source-named. |
| `0x004b7eb0-0x004b7ecd` | 00015S | free `IsRectEmptyOrInvalid` | yes | 0000N2 | 92/93 | Complete CPP/H free helper; modeled/source-named. |
| `0x004b7ed0-0x004b7f22` | 00015S | `RectsEquivalent` | yes | 0000N2 | 92/93 | Complete CPP/H free helper; modeled/source-named. |
| `0x004b7f30-0x004b7f87` | 00015S | `RectContainsRect(inner,outer)` | yes | 0000N2 | 92/93 | Complete CPP/H free helper; modeled. |
| `0x004b7f90-0x004b8004` | 00022I | `Transpose3x3AnchorIndex` plus table | yes | 0000N2 | 89/90 | Complete private CPP; no H; retained raw start. |
| `0x004b8010-0x004b80d0` | 00022I | `AdjustRectPairForAnchor` plus table | yes | 0000N2 | 89/90 | Complete private CPP; no H; retained raw start. |
| `0x004b80d0-0x004b8194` | 00022I | `AdjustRectPairForAnchorWithOffsets` plus table | yes | 0000N2 | 89/90 | Complete private CPP; no H; retained raw start. |
| `0x004b8290-0x004b83c5` | 00022L | `AdjustRectAnchorAxis`, tables and alignment | yes | 0000N2 | 89/90 | Complete private CPP; no H; modeled. |
| `0x0061a880-0x0061a884` | 00040U | pooled `0.25f` | evidence only | 00022H | 86/92 | Compiler-regenerated literal; blank CPP/H and no emitter. |
| `0x006104b0-0x006104b4` | shared data item | pooled `0.5f` | evidence only | external/shared | n/a | Three local reads, sixty total; no RectBounds ownership. |
| `Point` | 0000BU formal H | exact 8-byte source struct | yes | 0000BU | 91/90 | Emit once in RectBounds.h. |
| `RectBounds` | 0000BU formal H | exact 16-byte source struct | yes | 0000BU | 91/90 | Emit once in RectBounds.h; no vtable/RTTI. |
| `RectBoundsLayout` | 0001VP | duplicate layout evidence | evidence only | 0000BU | 85/88 | No distinct source/type; clear emitter. |
| `0x004b7fe0-0x004b8004` | compiler island | transpose switch table/tail | no authored code | 00022I | n/a | Covered by helper; no separate source. |
| `0x004b80ac-0x004b80d0` | compiler island | first anchor switch table/tail | no authored code | 00022I | n/a | Covered by helper; no separate source. |
| `0x004b8170-0x004b8194` | compiler island | offset-anchor switch table/tail | no authored code | 00022I | n/a | Covered by helper; no separate source. |
| `0x004b83ae-0x004b83c5` | compiler island | alignment plus axis switch tables | no authored code | 00022L | n/a | Covered by helper; no separate source. |
| `0x004b81a0-0x004b81eb` | 00022J | `WideStringHashHelper` | excluded | other file | n/a | Unrelated behavior/page. |
| `0x004b81f0-0x004b821e` | 00022K | `FileExists`/PathUtil | excluded | other file | n/a | Unrelated behavior/page. |
| `0x004b8220-0x004b8284` | 00015U | FieldMap path helper | excluded | FieldMapPane | n/a | Unrelated owner/page. |
| `0x004b83c5-0x004b83d0` | padding | successor alignment | excluded | boundary | n/a | Not source-bearing. |
| `0x004b83d0...` | GeneralPurposePanel | successor source family | excluded | other file | n/a | Exact next-function boundary. |
| `0x004bb2e0-0x004bb575` | 00016H | LineClip family | excluded | 0000OC Surface | 90/91 | Render-only callers; formal Surface.cpp source. |

Exact alignment/padding inventory; every range is half-open, compiler-generated/no-code, and protected from authored-source emission:

| Gap key / claim twin | Exact range | Exact bytes / class | Ownership and boundary role | Incoming xref evidence | Exact support destination and source disposition |
| --- | --- | --- | --- | --- | --- |
| G01 / ledger C130 | `0x004b7661-0x004b7670` | 15 bytes, all `cc` | predecessor `FramePartPane` end to UID00022G first member | zero to `0x004b7661` | `by-memory/0x004b73b0-0x004b7661.FramePartPane.md` Range/Boundary plus `by-memory/-ignored.md` alignment entry; compiler alignment, no CPP/H |
| G02 / ledger C131 | `0x004b7685-0x004b7690` | 11 bytes, all `cc` | UID00022G member-to-member gap | zero to `0x004b7685` | `by-memory/0x004b7670-0x004b78c8.RectBoundsPredicateAndCombinationMethods.md` Range/Boundary plus `by-memory/-ignored.md`; compiler alignment, no CPP/H |
| G03 / ledger C132 | `0x004b76c8-0x004b76d0` | 8 bytes, all `cc` | UID00022G member-to-member gap | zero to `0x004b76c8` | same UID00022G Range/Boundary and `by-memory/-ignored.md`; compiler alignment, no CPP/H |
| G04 / ledger C133 | `0x004b76f8-0x004b7700` | 8 bytes, all `cc` | UID00022G member-to-member gap | zero to `0x004b76f8` | same UID00022G Range/Boundary and `by-memory/-ignored.md`; compiler alignment, no CPP/H |
| G05 / ledger C134 | `0x004b7775-0x004b7780` | 11 bytes, all `cc` | UID00022G member-to-member gap | zero to `0x004b7775` | same UID00022G Range/Boundary and `by-memory/-ignored.md`; compiler alignment, no CPP/H |
| G06 / ledger C135 | `0x004b782a-0x004b7830` | 6 bytes, all `cc` | UID00022G member-to-member gap | zero to `0x004b782a` | same UID00022G Range/Boundary and `by-memory/-ignored.md`; compiler alignment, no CPP/H |
| G07 / ledger C136 | `0x004b78c8-0x004b78d0` | 8 bytes, all `cc` | UID00022G end to UID00015Q `SetLTRB` | zero to `0x004b78c8` | same UID00022G Range/Boundary and `by-memory/-ignored.md`; compiler alignment, no CPP/H |
| G08 / ledger C137 | `0x004b78ee-0x004b78f0` | 2 bytes, all `cc` | UID00015Q `SetLTRB` to `Offset` | zero to `0x004b78ee` | `by-memory/0x004b78d0-0x004b7ae8.RectBoundsMethods.md` Range/Boundary plus `by-memory/-ignored.md`; compiler alignment, no CPP/H |
| G09 / ledger C138 | `0x004b7908-0x004b7910` | 8 bytes, all `cc` | UID00015Q `Offset` to nested UID00015R `Inset` | zero to `0x004b7908` | UID00015Q Range/Boundary, `by-memory/0x004b7910-0x004b795e.RectBoundsInset.md` boundary, and `by-memory/-ignored.md`; compiler alignment, no CPP/H |
| G10 / ledger C139 | `0x004b795e-0x004b7960` | 2 bytes, all `cc` | UID00015R `Inset` back to UID00015Q `IntersectWith` | zero to `0x004b795e` | UID00015R/UID00015Q Range/Boundary plus `by-memory/-ignored.md`; compiler alignment, no CPP/H |
| G11 / ledger C140 | `0x004b79f7-0x004b7a00` | 9 bytes, all `cc` | UID00015Q `IntersectWith` to `UnionWith` | zero to `0x004b79f7` | UID00015Q Range/Boundary plus `by-memory/-ignored.md`; compiler alignment, no CPP/H |
| G12 / ledger C141 | `0x004b7a77-0x004b7a80` | 9 bytes, all `cc` | UID00015Q `UnionWith` to `ClampWithin` | zero to `0x004b7a77` | UID00015Q Range/Boundary plus `by-memory/-ignored.md`; compiler alignment, no CPP/H |
| G13 / ledger C142 | `0x004b7ae8-0x004b7af0` | 8 bytes, all `cc` | UID00015Q end to UID00022H quarter helper | zero to `0x004b7ae8` | UID00015Q/`by-memory/0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers.md` boundary plus `by-memory/-ignored.md`; compiler alignment, no CPP/H |
| G14 / ledger C143 | `0x004b7b88-0x004b7b90` | 8 bytes, all `cc` | UID00022H quarter helper to half helper | zero to `0x004b7b88` | UID00022H Range/Boundary plus `by-memory/-ignored.md`; compiler alignment, no CPP/H |
| G15 / ledger C144 | `0x004b7c21-0x004b7c30` | 15 bytes, all `cc` | UID00022H end to UID00015S geometry helper island | zero to `0x004b7c21` | UID00022H/`by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md` boundary plus `by-memory/-ignored.md`; compiler alignment, no CPP/H |
| G16 / ledger C145 | `0x004b7c43-0x004b7c50` | 13 bytes, all `cc` | UID00015S `InitPointPair` to `InitRectBounds` | zero to `0x004b7c43` | UID00015S Function Inventory/Range and `by-memory/-ignored.md`; compiler alignment, no CPP/H |
| G17 / ledger C146 | `0x004b7c6f-0x004b7c70` | 1 byte `cc` | UID00015S `InitRectBounds` to `InitRectBoundsFromSize` | zero to `0x004b7c6f` | UID00015S Function Inventory/Range and `by-memory/-ignored.md`; compiler alignment, no CPP/H |
| G18 / ledger C147 | `0x004b7c95-0x004b7ca0` | 11 bytes, all `cc` | UID00015S `InitRectBoundsFromSize` to nested UID00015T `RectArea` | zero to `0x004b7c95` | UID00015S Function Inventory/Range, `by-memory/0x004b7ca0-0x004b7cb6.RectArea.md` boundary, and `by-memory/-ignored.md`; compiler alignment, no CPP/H |
| G19 / ledger C148 | `0x004b7cb6-0x004b7cc0` | 10 bytes, all `cc` | UID00015T `RectArea` back to UID00015S `IntersectRects` | zero to `0x004b7cb6` | UID00015T/UID00015S Range and `by-memory/-ignored.md`; compiler alignment, no CPP/H |
| G20 / ledger C149 | `0x004b7d69-0x004b7d70` | 7 bytes, all `cc` | UID00015S `IntersectRects` to `UnionRects` | zero to `0x004b7d69` | UID00015S Function Inventory/Range and `by-memory/-ignored.md`; compiler alignment, no CPP/H |
| G21 / ledger C150 | `0x004b7e03-0x004b7e10` | 13 bytes, all `cc` | UID00015S `UnionRects` to `OffsetRect` | zero to `0x004b7e03` | UID00015S Function Inventory/Range and `by-memory/-ignored.md`; compiler alignment, no CPP/H |
| G22 / ledger C151 | `0x004b7e29-0x004b7e30` | 7 bytes, all `cc` | UID00015S `OffsetRect` to `InsetRect` | zero to `0x004b7e29` | UID00015S Function Inventory/Range and `by-memory/-ignored.md`; compiler alignment, no CPP/H |
| G23 / ledger C152 | `0x004b7e7f-0x004b7e80` | 1 byte `cc` | UID00015S `InsetRect` to `PointInRect` | zero to `0x004b7e7f` | UID00015S Function Inventory/Range and `by-memory/-ignored.md`; compiler alignment, no CPP/H |
| G24 / ledger C153 | `0x004b7ea7-0x004b7eb0` | 9 bytes, all `cc` | UID00015S `PointInRect` to `IsRectEmptyOrInvalid` | zero to `0x004b7ea7` | UID00015S Function Inventory/Range and `by-memory/-ignored.md`; compiler alignment, no CPP/H |
| G25 / ledger C154 | `0x004b7ecd-0x004b7ed0` | 3 bytes, all `cc` | UID00015S empty predicate to `RectsEquivalent` | zero to `0x004b7ecd` | UID00015S Function Inventory/Range and `by-memory/-ignored.md`; compiler alignment, no CPP/H |
| G26 / ledger C155 | `0x004b7f22-0x004b7f30` | 14 bytes, all `cc` | UID00015S `RectsEquivalent` to `RectContainsRect` | zero to `0x004b7f22` | UID00015S Function Inventory/Range and `by-memory/-ignored.md`; compiler alignment, no CPP/H |
| G27 / ledger C156 | `0x004b7f87-0x004b7f90` | 9 bytes, all `cc` | UID00015S end to UID00022I anchor helper island | zero to `0x004b7f87` | UID00015S/`by-memory/0x004b7f90-0x004b8194.RectAnchorTransformHelpers.md` boundary plus `by-memory/-ignored.md`; compiler alignment, no CPP/H |
| G28 / ledger C157 | `0x004b8004-0x004b8010` | 12 bytes, all `cc` | UID00022I first table-tail to next raw helper | zero to `0x004b8004` | UID00022I Range/Boundary plus `by-memory/-ignored.md`; compiler alignment, no CPP/H |
| G29 / ledger C158 | `0x004b8194-0x004b81a0` | 12 bytes, all `cc` | UID00022I end to excluded UID00022J `WideStringHashHelper` | zero to `0x004b8194` | UID00022I/`by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md` boundary plus `by-memory/-ignored.md`; compiler alignment, no CPP/H |
| G30 / ledger C159 | `0x004b81eb-0x004b81f0` | 5 bytes, all `cc` | excluded UID00022J to excluded UID00022K `FileExists` | zero to `0x004b81eb` | UID00022J/`by-memory/0x004b81f0-0x004b821e.FileExists.md` boundary plus `by-memory/-ignored.md`; compiler alignment, no CPP/H |
| G31 / ledger C160 | `0x004b821e-0x004b8220` | 2 bytes, all `cc` | excluded UID00022K to excluded UID00015U FieldMap helper | zero to `0x004b821e` | UID00022K/`by-memory/0x004b8220-0x004b8284.BuildFieldMapTextPath.md` boundary plus `by-memory/-ignored.md`; compiler alignment, no CPP/H |
| G32 / ledger C161 | `0x004b8284-0x004b8290` | 12 bytes, all `cc` | excluded UID00015U end to UID00022L axis helper | zero to `0x004b8284` | UID00015U/`by-memory/0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper.md` boundary plus `by-memory/-ignored.md`; compiler alignment, no CPP/H |
| G33 / ledger C162 | `0x004b83ae-0x004b83b0` | 2-byte NOP `66 90` | UID00022L modeled body end to its two axis switch tables | zero to `0x004b83ae` | UID00022L Range/Boundary; compiler instruction alignment covered by helper, no separate CPP/H |
| G34 / ledger C163 | `0x004b83c5-0x004b83d0` | 11 bytes, all `cc` | UID00022L table-tail end to successor `GeneralPurposePanel` | zero to `0x004b83c5` | UID00022L Range/Boundary plus `by-memory/-ignored.md`; compiler successor alignment, no CPP/H |

Inventory totals: 30 authored functions, 14 class members, 12 non-member public/file functions, 4 file-local anchor helpers, 2 source structs, 2 pooled literals, 4 compiler-table islands containing 5 physical data items, 34 exact alignment spans, 20 enumerated ordinary-document destinations (1 target plus 19 support/boundary/ownership pages), and 6 explicitly excluded inventory candidates. Every authored function has a CPP disposition; all externally used types/functions have an H disposition; private anchor helpers, compiler tables, and every alignment span have exact no-H/no-code reasons.

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004b7670` | 7 inbound: `0x496cf6,0x496e30,0x497104,0x49723e,0x4c789d,0x538ef5,0x539435`; no callees | Live member predicate. |
| `0x004b7690` | 0 direct inbound; no modeled callee set | Retained raw member; zero direct xrefs is preserved liveness evidence, not deletion proof. |
| `0x004b76d0` | 4 inbound: `0x499df9,0x4b2e00,0x4b2e48,0x4b39bf`; no callees | Live member point test. |
| `0x004b7700` | 0 direct inbound | Retained raw member. |
| `0x004b7780` | 0 direct inbound | Retained raw member. |
| `0x004b7830` | 0 direct inbound | Retained raw member. |
| `0x004b78d0` | terminal count 208, complete canonical manifest SHA256 `94B9965401B5DACEB29BC7B28460565BCD5F34D641D4C318C01E1B1232D87679`; first ten `0x41bb44,0x41bc9a,0x41f69b,0x451f27,0x4521fd,0x452504,0x455ffd,0x456152,0x45623b,0x46934a`; no callees | Widely live initializer/mutator. |
| `0x004b78f0` | terminal count 209, complete canonical manifest SHA256 `33C5F9583616FB2AC5F4A90BCC0ABA75B6BA9013D87A1817565AD2E3F50FA5A8`; first ten `0x4611ff,0x461240,0x46c047,0x483842,0x48d685,0x48d6b9,0x48d81a,0x48d84e,0x48d8d7,0x48dfbb`; no callees | Widely live translation member. |
| `0x004b7910` | 3 inbound: `0x53bcb7,0x53bcd8,0x53bcf9`; no callees | Live member inset. |
| `0x004b7960` | 0 direct inbound | Retained raw member. |
| `0x004b7a00` | terminal count 33, complete canonical manifest SHA256 `051A654B00A2272C4300D209BC3504E90174DE06D9AC5D019EF0859048681F50`; first ten `0x4d6dec,0x4d6e1b,0x4d6e4a,0x4d6e73,0x4d6ea2,0x4d6ed1,0x4d6f00,0x4d6f2f,0x4d6f86,0x4d7202`; no callees | Live mutating union member. |
| `0x004b7a80` | 2 inbound: `0x5c3767,0x5c37c9`; no callees | Live clamp member. |
| `0x004b7af0` | 0 direct inbound; reads quarter at `0x4b7b15/0x4b7b43` and half at `0x4b7b21/0x4b7b4f` | Retained raw quarter helper with exact literal route. |
| `0x004b7b90` | 0 direct inbound; reads half at `0x4b7b93` | Retained raw half helper. |
| `0x004b7c30` | terminal count 102, complete canonical manifest SHA256 `D1A32963A7E1DCA21221BFA8BFAC7361B0D54EC7DCAFA0B5CD13CA74446EA776`; no callees | Widely live Point writer. |
| `0x004b7c50` | terminal count 1,731, complete canonical manifest SHA256 `5251B755FF879798D7094CCDCA6A6D49D8A3043C1F2A269F8C9DC6298BAC82F5`; no callees | Core RectBounds initializer. |
| `0x004b7c70` | terminal count 38, complete canonical manifest SHA256 `5C1CD35B479E4A1208282FDF2922E4FEE64B51A29F0C882A4F2CE9AE385ED8E0`; no callees | Live size initializer. |
| `0x004b7ca0` | 4 inbound: `0x4580de,0x4581da,0x45833d,0x4b621a`; no callees | Live signed area helper. |
| `0x004b7cc0` | terminal count 91, complete canonical manifest SHA256 `CB74C26E358A4DBEEB79B51D5F9DF29D55FA836FE0C982F9162678FA21355F6A`; no modeled callees | Live free intersection helper. |
| `0x004b7d70` | terminal count 37, complete canonical manifest SHA256 `EA93A818A0E1BDC6DD80D5F8238E9B55A972AC75A97E9BB814E5448475923B8E`; no modeled callees | Live free union helper. |
| `0x004b7e10` | terminal count 368, complete canonical manifest SHA256 `1BDDD190B37AE5646AAC0FD33F9DDBF490EEEF4FF4DBCE4BD5D482559550C40E`; no callees | Widely live free translation helper. |
| `0x004b7e30` | terminal count 32, complete canonical manifest SHA256 `362626B99F1F93514ED611E889B3B16E221606FCD8F88CABB50E586A009149E1`; no callees | Live free inset helper. |
| `0x004b7e80` | terminal count 270, complete canonical manifest SHA256 `715E26A19D1BAC52D1F1A3F8BAA83946A3F8FE12420F156AE10701A2C44AE21D`; no callees | Widely live free point predicate. |
| `0x004b7eb0` | terminal count 32, complete canonical manifest SHA256 `F2CC4329E8B46448AADFD6E02907292C57FE4CCCA6D9139971E0EB230D783B55`; no callees | Live free empty predicate. |
| `0x004b7ed0` | 7 inbound exact terminal set, canonical manifest SHA256 `D274207B10C1285EDF8E431E720EAED5642A63BA9EDB3AFC5324E844C5B30515`; calls the free empty predicate semantically | Live equivalence helper. |
| `0x004b7f30` | 2 inbound: `0x554a4a,0x554a83`; uses free empty predicate semantics | Live containment helper. |
| `0x004b7f90` | 0 direct inbound; table `0x4b7fe0` has sole ref `0x4b7f9b` | Retained file-local transpose helper/table. |
| `0x004b8010` | 0 direct inbound; calls axis at `0x4b803e/0x4b809f`; table `0x4b80ac` sole ref `0x4b804b` | Retained file-local anchor helper. |
| `0x004b80d0` | 0 direct inbound; calls axis at `0x4b80ff/0x4b8161`; table `0x4b8170` sole ref `0x4b810c` | Retained file-local offset-anchor helper. |
| `0x004b8290` | 4 inbound: `0x4b803e,0x4b809f,0x4b80ff,0x4b8161`; no callees; table refs `0x4b82d6->0x4b83b0`, `0x4b82cf->0x4b83bc` | Private axis helper called only by the two anchor-pair helpers. |
| `0x0061a880` | 2 data refs: `0x4b7b15,0x4b7b43` | File-local compiler pooling of `0.25f`; no authored global. |
| `0x006104b0` | 60 terminal data refs, including local `0x4b7b21,0x4b7b4f,0x4b7b93` | Shared pooled `0.5f`, not file-owned. |
| 34 alignment starts | zero inbound xrefs at each exact start: `{0x4b7661,0x4b7685,0x4b76c8,0x4b76f8,0x4b7775,0x4b782a,0x4b78c8,0x4b78ee,0x4b7908,0x4b795e,0x4b79f7,0x4b7a77,0x4b7ae8,0x4b7b88,0x4b7c21,0x4b7c43,0x4b7c6f,0x4b7c95,0x4b7cb6,0x4b7d69,0x4b7e03,0x4b7e29,0x4b7e7f,0x4b7ea7,0x4b7ecd,0x4b7f22,0x4b7f87,0x4b8004,0x4b8194,0x4b81eb,0x4b821e,0x4b8284,0x4b83ae,0x4b83c5}` | Exact negative evidence for C130-C163; each full range/byte class/owner/support destination is itemized in Section 14. |
| LineClip | `ClipLineToRect` callers `0x4bbc81` and `0x4c0b71`; `ClipLineParameter` callers `0x4bb46b,0x4bb492` only | Exclusive render/Surface ownership; no RectBounds-unit caller. |

For broad fanout functions, the terminal live count plus canonical SHA256 over the complete lexical comma-joined `source-address:ref-kind` set is the exact inventory contract; representative first-ten addresses are display aids only. Low-count sets are literal and complete. The supervisor Gate 2B preflight must reread the complete current set before any mutation.

## Documentation Evidence And IDA Status

- Supporting current docs already contain strong behavioral reconstructions and formal bodies for all thirty functions.
- At report-only evidence time, stale/incomplete docs were the target's placement/LineClip uncertainty, [UID:00015Q]/[UID:00015S] missing child markers, [UID:00015T]'s sibling ownership/source-order route, [UID:00040U]/[UID:0001VP] emitting routes, dated command `000000025893` generated ordering, and stale manual coverage rows. UID00015T's formal H observed in that snapshot is preservation evidence; later authority is established by dynamic reread.
- Current IDA retains ten raw starts and eleven generic `sub_` names; nine functions already have stable source-quality names. Source reconstruction does not depend on IDA mutation, but Section 21 supplies deterministic improvement/protection rows.
- Generated commands `000000025616`, `000000025640`, and `000000025804` are earlier dated leads; command `000000025893` is the dated research snapshot physically reread here. The `25640` H omission is superseded history, while `25893` proves the declaration exists. Callback validation must establish the then-current output and prove preserved declaration, repaired order, and empty-marker removal.

## Ranked Ownership Analysis

### 1. `NexusTK/ui/core/RectBounds.cpp/.h`
- Evidence for: current owner/emitter graph, exact value-type role, contiguous member/free/helper family, widespread UI/render callers, established generated files, and minimal source-tree churn.
- Evidence against: none beyond the absence of original source-path symbols.
- Decision: accepted final placement.

### 2. `NexusTK/util/RectBounds.cpp/.h`
- Evidence for: geometry operations are generally reusable.
- Evidence against: current project ownership and includes are UI-core; no binary/path evidence indicates `util`; migration would be speculative churn.
- Decision: rejected and retained only as historical alternative.

### 3. Fold LineClip into RectBounds
- Evidence for: both manipulate rectangles.
- Evidence against: LineClip's callers are exclusively render/Surface paths and its parameter helper is private to that render operation.
- Decision: rejected. LineClip remains [UID:0000OC] `Surface.cpp`.

### Proposed new file/grouping, if applicable
- No new file is proposed. The repair closes the existing `RectBounds.cpp/.h` root and removes stale review ambiguity.

## Source Placement

- Recommended placement: `NexusTK/ui/core/RectBounds.h` for `Point`, `RectBounds`, and public free declarations; `NexusTK/ui/core/RectBounds.cpp` for all thirty definitions and private anchor helpers.
- The file order follows the exact binary/source sequence. Static anchor helpers remain CPP-private; no declaration leaks into H.
- `0.25f` and `0.5f` remain literals in expressions rather than artificial global declarations.
- Rejected placements: `util` lacks direct evidence; `Surface.cpp` owns only LineClip; `FieldMapPane` and PathUtil are unrelated adjacent code.
- Remaining placement uncertainty: original exact path capitalization/spelling is not symbol-proven, but current project-wide route is sufficiently established for final source.

## Range / Split / Padding / Reclassification Analysis

- Exact authored ranges are the thirty function rows in Section 14. The 34 separately itemized complement spans close every function-to-function, nested-child, excluded-neighbor, table-tail, and successor boundary without being absorbed into authored C++; existing page ranges are sufficient and no new by-memory file is required.
- [UID:00015R] must become an emitter child of [UID:00015Q], not a later file/class sibling. [UID:00015T] must become an emitter child of [UID:00015S]. This is an emitter/source-order repair, not a byte-range merge.
- Switch tables at `0x004b7fe0`, `0x004b80ac`, `0x004b8170`, `0x004b83b0`, and `0x004b83bc` are compiler artifacts covered by their functions; they receive no authored C++.
- All 34 Section 14 alignment spans remain documented/no-code at their exact support destinations. Thirty-three are pure `cc`; `0x004b83ae-0x004b83b0` is exact `66 90`. Every start has zero inbound xrefs, so no span is an omitted function/data head.
- [UID:00040U] and [UID:0001VP] are reclassified from empty emitters to non-emitting evidence/support pages; neither is deleted.
- Parent impact: [UID:0000N2]/[UID:0000BU] retain ownership, but direct child positions and nested routes become deterministic.

## Negative Evidence Summary

- No original PDB/source path or exact private helper spellings were recovered.
- Zero direct xrefs to ten raw starts do not establish deletion: the bodies are coherent, bounded, already documented, and compatible with unreferenced retained source or optimized call folding.
- Data proximity does not prove source ownership: the shared `0.5f` pool has sixty refs and is excluded as a global.
- Address proximity does not absorb `WideStringHashHelper`, PathUtil, FieldMapPane, successor padding, or GeneralPurposePanel.
- Semantic similarity does not absorb LineClip; direct callers place it in render/Surface.
- No vptr writes, vtable, RTTI, constructor/destructor, dynamic allocation, resource, import, or string family supports making RectBounds polymorphic or giving this source file runtime-owned state.
- No separate IDA UDT supports emitting `RectBoundsLayout` as another source struct.

## IDA Rename / Type / Comment Recommendations

This is a declarative supervisor handoff. B001 performed no mutation or save. Every literal request binds `database:"<fresh runtime-attested canonical session ID>"`, where the supervisor substitutes only the canonical session returned by a new `idb_list` and exact-path schema-1 attestation immediately before Gate 2B; the dated evidence session is not a permanent prerequisite. `AR`, `AP`, `FR`, and `FP` mean address regular, address repeatable, function regular, and function repeatable comments. Every channel is independent. Every I01-I66 and I11T-I20T action row is independently `Classification: apply`; P01-P13 and P04A-P04E/P04G01-P04G34 are no-change protections. Required global endpoint order is I01-I10 define, I11-I20 pure rename, I11T-I20T function type, I21-I31 pure rename, I32-I42 function type, I43-I63 function-repeatable comment, then I64-I66 PointInRect stack repair. Every action requires a fresh collision/prestate reread, immediate post-action readback, and unsaved worker discard on any mismatch; only the supervisor may save.

Public endpoint contracts:

| Classification | Exact current-schema request | Required immediate readback |
| --- | --- | --- |
| define-function | `define_func({database:"<fresh runtime-attested canonical session ID>",items:{addr:ADDR,end:END}})` | exactly one function `[ADDR,END)` with deterministic `sub_...` name; persisted function type absent; public `inspect_items` type absent; Hex-Rays succeeds for that exact range/body; complete row-specific physical frame; AR absent; AP absent; FR absent; FP absent; exact bytes/hash/xrefs and predecessor/successor/table boundaries unchanged |
| rename-pure | `rename({database:"<fresh runtime-attested canonical session ID>",batch:{func:[{addr:ADDR,name:NAME}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}})` | destination collision absent before; unique new lookup after; persisted IDB function type unchanged; decompiler prototype and public `inspect_items` presentation must equal the row-specific permitted forms; complete frame/comments/range/hash/xrefs unchanged |
| function-type | one `set_type({database:"<fresh runtime-attested canonical session ID>",edits:[{addr:ADDR,kind:"function",signature:SIG}]})` | exact function type plus complete frame/comments/range/hash/xrefs |
| function-repeatable-comment | `set_repeatable_comments({database:"<fresh runtime-attested canonical session ID>",items:[{addr:ADDR,comment:TEXT}]})` | FP equals TEXT; AR/AP/FR and every non-comment field unchanged |
| stack-rename | `rename({database:"<fresh runtime-attested canonical session ID>",batch:{stack:[{func_addr:ADDR,old:OLD,new:NEW}],allow_overwrite:false,dry_run:false,stop_on_error:true}})` | complete frame with only the named row changed |
| stack-type | `set_type({database:"<fresh runtime-attested canonical session ID>",edits:[{addr:ADDR,kind:"stack",name:NAME,ty:TYPE}]})` | complete frame with only the named type changed |

### Literal raw-function define stages

The 2026-08-18 bounded read-only repair pass reconfirmed that every start is a one-byte code item with name absent and type absent, no function, AR absent, AP absent, FR not applicable, FP not applicable, `stack_frame` returning `No function found`, and zero inbound xrefs. Exact prologues, stack allocation, returns, body hashes, and neighboring table/alignment boundaries now support deterministic fail-closed `define_func` contracts. The immediate frames below intentionally contain only IDA's represented saved-register/return rows; source arguments are added only by the independent type stage. Hex-Rays success means one non-error decompilation for the exact new function/name/range with the listed body role; its inferred display is not persisted type authority.

| ID | Exact current raw prestate | Exact define request | Required immediate define readback |
| --- | --- | --- | --- |
| I01 | Classification: apply; `[0x004b7690,0x004b7691)` size1 code, name absent; type absent; no function/frame; AR absent; AP absent; FR not applicable; FP not applicable; body `[0x004b7690,0x004b76c8)` SHA256 `F5390A22C1B14C8FCF33BADB759A2C6DAF0457BDB5BA1904C21B2AC6AE40F7F4`; xrefs `{}`; predecessor `cc` `[0x004b7685,0x004b7690)`, successor `cc` `[0x004b76c8,0x004b76d0)` | `define_func({database:"<fresh runtime-attested canonical session ID>",items:{addr:"0x004b7690",end:"0x004b76c8"}})` | one function `[0x004b7690,0x004b76c8)` named `sub_4B7690`; persisted type absent; public `inspect_items.type` absent; Hex-Rays succeeds as the width/height comparison body; frame exactly `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *`, no other rows; AR absent; AP absent; FR absent; FP absent; body `[0x004b7690,0x004b76c8)` SHA256 `F5390A22C1B14C8FCF33BADB759A2C6DAF0457BDB5BA1904C21B2AC6AE40F7F4`; xrefs `{}`; predecessor remains `cc` `[0x004b7685,0x004b7690)` and successor remains `cc` `[0x004b76c8,0x004b76d0)`. |
| I02 | Classification: apply; `[0x004b7700,0x004b7701)` size1 code, name absent; type absent; no function/frame; AR absent; AP absent; FR not applicable; FP not applicable; body `[0x004b7700,0x004b7775)` SHA256 `A86D0E0E4F5585EC031315B115FFDEAF6EE2FC55A05BB3F01B49E2E65D0ECD8E`; xrefs `{}`; predecessor `cc` `[0x004b76f8,0x004b7700)`, successor `cc` `[0x004b7775,0x004b7780)` | `define_func({database:"<fresh runtime-attested canonical session ID>",items:{addr:"0x004b7700",end:"0x004b7775"}})` | one function `[0x004b7700,0x004b7775)` named `sub_4B7700`; persisted type absent; public type absent; Hex-Rays succeeds as the rectangle-containment body; frame exactly `__saved_registers@0x14/4:_DWORD; __return_address@0x18/4:_UNKNOWN *`, no other rows; AR absent; AP absent; FR absent; FP absent; body `[0x004b7700,0x004b7775)` SHA256 `A86D0E0E4F5585EC031315B115FFDEAF6EE2FC55A05BB3F01B49E2E65D0ECD8E`; xrefs `{}`; predecessor remains `cc` `[0x004b76f8,0x004b7700)` and successor remains `cc` `[0x004b7775,0x004b7780)`. |
| I03 | Classification: apply; `[0x004b7780,0x004b7781)` size1 code, name absent; type absent; no function/frame; AR absent; AP absent; FR not applicable; FP not applicable; body `[0x004b7780,0x004b782a)` SHA256 `7AE269077D1C4C3E0D613B86878052616C32829EF015B00A95EF2B63543699EE`; xrefs `{}`; predecessor `cc` `[0x004b7775,0x004b7780)`, successor `cc` `[0x004b782a,0x004b7830)` | `define_func({database:"<fresh runtime-attested canonical session ID>",items:{addr:"0x004b7780",end:"0x004b782a"}})` | one function `[0x004b7780,0x004b782a)` named `sub_4B7780`; persisted type absent; public type absent; Hex-Rays succeeds as the optional-output intersection body; frame exactly `__saved_registers@0x24/4:_DWORD; __return_address@0x28/4:_UNKNOWN *`, no other rows; AR absent; AP absent; FR absent; FP absent; body `[0x004b7780,0x004b782a)` SHA256 `7AE269077D1C4C3E0D613B86878052616C32829EF015B00A95EF2B63543699EE`; xrefs `{}`; predecessor remains `cc` `[0x004b7775,0x004b7780)` and successor remains `cc` `[0x004b782a,0x004b7830)`. |
| I04 | Classification: apply; `[0x004b7830,0x004b7831)` size1 code, name absent; type absent; no function/frame; AR absent; AP absent; FR not applicable; FP not applicable; body `[0x004b7830,0x004b78c8)` SHA256 `4D329ABFFF21BB0DDCDB23C9B5FB3B3972B5F4A5BBA8300B589145A0C66FB229`; xrefs `{}`; predecessor `cc` `[0x004b782a,0x004b7830)`, successor `cc` `[0x004b78c8,0x004b78d0)` | `define_func({database:"<fresh runtime-attested canonical session ID>",items:{addr:"0x004b7830",end:"0x004b78c8"}})` | one function `[0x004b7830,0x004b78c8)` named `sub_4B7830`; persisted type absent; public type absent; Hex-Rays succeeds as the separate-output bounding-union body; frame exactly `__saved_registers@0x14/4:_DWORD; __return_address@0x18/4:_UNKNOWN *`, no other rows; AR absent; AP absent; FR absent; FP absent; body `[0x004b7830,0x004b78c8)` SHA256 `4D329ABFFF21BB0DDCDB23C9B5FB3B3972B5F4A5BBA8300B589145A0C66FB229`; xrefs `{}`; predecessor remains `cc` `[0x004b782a,0x004b7830)` and successor remains `cc` `[0x004b78c8,0x004b78d0)`. |
| I05 | Classification: apply; `[0x004b7960,0x004b7961)` size1 code, name absent; type absent; no function/frame; AR absent; AP absent; FR not applicable; FP not applicable; body `[0x004b7960,0x004b79f7)` SHA256 `B30A96040C9354609990CAAB536DA058418CEE87E0056D7859338DEC25B89141`; xrefs `{}`; predecessor `cc` `[0x004b795e,0x004b7960)`, successor `cc` `[0x004b79f7,0x004b7a00)` | `define_func({database:"<fresh runtime-attested canonical session ID>",items:{addr:"0x004b7960",end:"0x004b79f7"}})` | one function `[0x004b7960,0x004b79f7)` named `sub_4B7960`; persisted type absent; public type absent; Hex-Rays succeeds as the in-place intersection/clear body; frame exactly `__saved_registers@0x20/4:_DWORD; __return_address@0x24/4:_UNKNOWN *`, no other rows; AR absent; AP absent; FR absent; FP absent; body `[0x004b7960,0x004b79f7)` SHA256 `B30A96040C9354609990CAAB536DA058418CEE87E0056D7859338DEC25B89141`; xrefs `{}`; predecessor remains `cc` `[0x004b795e,0x004b7960)` and successor remains `cc` `[0x004b79f7,0x004b7a00)`. |
| I06 | Classification: apply; `[0x004b7af0,0x004b7af1)` size1 code, name absent; type absent; no function/frame; AR absent; AP absent; FR not applicable; FP not applicable; body `[0x004b7af0,0x004b7b88)` SHA256 `AFBA7653829F20377858C09F8831798163E18AAB7758B83B65F7DE3B91DFECAB`; xrefs `{}`; predecessor `cc` `[0x004b7ae8,0x004b7af0)`, successor `cc` `[0x004b7b88,0x004b7b90)` | `define_func({database:"<fresh runtime-attested canonical session ID>",items:{addr:"0x004b7af0",end:"0x004b7b88"}})` | one function `[0x004b7af0,0x004b7b88)` named `sub_4B7AF0`; persisted type absent; public type absent; Hex-Rays succeeds as the quarter-inset output body; frame exactly `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *`, no other rows; AR absent; AP absent; FR absent; FP absent; body `[0x004b7af0,0x004b7b88)` SHA256 `AFBA7653829F20377858C09F8831798163E18AAB7758B83B65F7DE3B91DFECAB`; xrefs `{}`; literal refs exact; predecessor remains `cc` `[0x004b7ae8,0x004b7af0)` and successor remains `cc` `[0x004b7b88,0x004b7b90)`. |
| I07 | Classification: apply; `[0x004b7b90,0x004b7b91)` size1 code, name absent; type absent; no function/frame; AR absent; AP absent; FR not applicable; FP not applicable; body `[0x004b7b90,0x004b7c21)` SHA256 `E78EA8100376B90E0F9430A62D054A9E7AA997723CC5391EE8BAEB17FF705FD3`; xrefs `{}`; predecessor `cc` `[0x004b7b88,0x004b7b90)`, successor `cc` `[0x004b7c21,0x004b7c30)` | `define_func({database:"<fresh runtime-attested canonical session ID>",items:{addr:"0x004b7b90",end:"0x004b7c21"}})` | one function `[0x004b7b90,0x004b7c21)` named `sub_4B7B90`; persisted type absent; public type absent; Hex-Rays succeeds as the half-outset output body; frame exactly `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *`, no other rows; AR absent; AP absent; FR absent; FP absent; body `[0x004b7b90,0x004b7c21)` SHA256 `E78EA8100376B90E0F9430A62D054A9E7AA997723CC5391EE8BAEB17FF705FD3`; xrefs `{}`; literal refs exact; predecessor remains `cc` `[0x004b7b88,0x004b7b90)` and successor remains `cc` `[0x004b7c21,0x004b7c30)`. |
| I08 | Classification: apply; `[0x004b7f90,0x004b7f91)` size1 code, name absent; type absent; no function/frame; AR absent; AP absent; FR not applicable; FP not applicable; body `[0x004b7f90,0x004b7fe0)` SHA256 `6CA2AB80C534F281162C1AC736F2706F2A90E6B74EB4774DC5ACF24379621FEF`; xrefs `{}`; predecessor `cc` `[0x004b7f87,0x004b7f90)`, switch table `[0x004b7fe0,0x004b8004)`, successor `cc` `[0x004b8004,0x004b8010)` | `define_func({database:"<fresh runtime-attested canonical session ID>",items:{addr:"0x004b7f90",end:"0x004b7fe0"}})` | one function `[0x004b7f90,0x004b7fe0)` named `sub_4B7F90`; persisted type absent; public type absent; Hex-Rays succeeds as the nine-case transpose body; frame exactly `__return_address@0x0/4:_UNKNOWN *`, no other rows; AR absent; AP absent; FR absent; FP absent; body `[0x004b7f90,0x004b7fe0)` SHA256 `6CA2AB80C534F281162C1AC736F2706F2A90E6B74EB4774DC5ACF24379621FEF`; xrefs `{}`; predecessor remains `cc` `[0x004b7f87,0x004b7f90)`, table remains `[0x004b7fe0,0x004b8004)`, successor remains `cc` `[0x004b8004,0x004b8010)`. |
| I09 | Classification: apply; `[0x004b8010,0x004b8011)` size1 code, name absent; type absent; no function/frame; AR absent; AP absent; FR not applicable; FP not applicable; body `[0x004b8010,0x004b80ac)` SHA256 `EC65D44AB83AFEE724EA63C8E07D1050E35B4F510AEFDF8CAA8EE3011B9335AB`; xrefs `{}`; predecessor `cc` `[0x004b8004,0x004b8010)`, switch table `[0x004b80ac,0x004b80d0)` | `define_func({database:"<fresh runtime-attested canonical session ID>",items:{addr:"0x004b8010",end:"0x004b80ac"}})` | one function `[0x004b8010,0x004b80ac)` named `sub_4B8010`; persisted type absent; public type absent; Hex-Rays succeeds as the zero-offset pair-anchor body; frame exactly `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *`, no other rows; AR absent; AP absent; FR absent; FP absent; body `[0x004b8010,0x004b80ac)` SHA256 `EC65D44AB83AFEE724EA63C8E07D1050E35B4F510AEFDF8CAA8EE3011B9335AB`; xrefs `{}`; predecessor remains `cc` `[0x004b8004,0x004b8010)`, both axis-helper calls and table `[0x004b80ac,0x004b80d0)` remain exact. |
| I10 | Classification: apply; `[0x004b80d0,0x004b80d1)` size1 code, name absent; type absent; no function/frame; AR absent; AP absent; FR not applicable; FP not applicable; body `[0x004b80d0,0x004b8170)` SHA256 `DB24FE8A1CCEA3E9C45B8A67B8AEE22F81164613FE5C830E9E1C909780C736AB`; xrefs `{}`; predecessor table `[0x004b80ac,0x004b80d0)`, switch table `[0x004b8170,0x004b8194)`, successor `cc` `[0x004b8194,0x004b81a0)` | `define_func({database:"<fresh runtime-attested canonical session ID>",items:{addr:"0x004b80d0",end:"0x004b8170"}})` | one function `[0x004b80d0,0x004b8170)` named `sub_4B80D0`; persisted type absent; public type absent; Hex-Rays succeeds as the offset pair-anchor body; frame exactly `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *`, no other rows; AR absent; AP absent; FR absent; FP absent; body `[0x004b80d0,0x004b8170)` SHA256 `DB24FE8A1CCEA3E9C45B8A67B8AEE22F81164613FE5C830E9E1C909780C736AB`; xrefs `{}`; predecessor table remains `[0x004b80ac,0x004b80d0)`, both axis-helper calls remain exact, table remains `[0x004b8170,0x004b8194)`, successor remains `cc` `[0x004b8194,0x004b81a0)`. |

### Raw-function pure rename stages

Each rename is independently collision-gated and runs only after its exact I01-I10 define readback. Persisted type remains absent, public `inspect_items.type` remains absent, Hex-Rays remains non-error for the exact body under the new name, and only the function name may change.

| ID | Exact post-define prestate | Exact pure rename request | Exact rename readback |
| --- | --- | --- | --- |
| I11 | Classification: apply; [0x004b7690,0x004b76c8) `sub_4B7690`; persisted type absent; public type absent; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *`; AR absent; AP absent; FR absent; FP absent; body SHA `F5390A22C1B14C8FCF33BADB759A2C6DAF0457BDB5BA1904C21B2AC6AE40F7F4`; xrefs `{}`; destination `RectBounds__HasSameSizeAs` absent; boundaries `cc` [0x004b7685,0x004b7690) and [0x004b76c8,0x004b76d0) | `rename({database:"<fresh runtime-attested canonical session ID>",batch:{func:[{addr:"0x004b7690",name:"RectBounds__HasSameSizeAs"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}})` | [0x004b7690,0x004b76c8) `RectBounds__HasSameSizeAs`; persisted type absent; public type absent; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *`; AR absent; AP absent; FR absent; FP absent; body SHA `F5390A22C1B14C8FCF33BADB759A2C6DAF0457BDB5BA1904C21B2AC6AE40F7F4`; xrefs `{}`; boundaries remain `cc` [0x004b7685,0x004b7690) and [0x004b76c8,0x004b76d0). |
| I12 | Classification: apply; [0x004b7700,0x004b7775) `sub_4B7700`; persisted type absent; public type absent; frame `__saved_registers@0x14/4:_DWORD; __return_address@0x18/4:_UNKNOWN *`; AR absent; AP absent; FR absent; FP absent; body SHA `A86D0E0E4F5585EC031315B115FFDEAF6EE2FC55A05BB3F01B49E2E65D0ECD8E`; xrefs `{}`; destination `RectBounds__ContainsRect` absent; boundaries `cc` [0x004b76f8,0x004b7700) and [0x004b7775,0x004b7780) | `rename({database:"<fresh runtime-attested canonical session ID>",batch:{func:[{addr:"0x004b7700",name:"RectBounds__ContainsRect"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}})` | [0x004b7700,0x004b7775) `RectBounds__ContainsRect`; persisted type absent; public type absent; frame `__saved_registers@0x14/4:_DWORD; __return_address@0x18/4:_UNKNOWN *`; AR absent; AP absent; FR absent; FP absent; body SHA `A86D0E0E4F5585EC031315B115FFDEAF6EE2FC55A05BB3F01B49E2E65D0ECD8E`; xrefs `{}`; boundaries remain `cc` [0x004b76f8,0x004b7700) and [0x004b7775,0x004b7780). |
| I13 | Classification: apply; [0x004b7780,0x004b782a) `sub_4B7780`; persisted type absent; public type absent; frame `__saved_registers@0x24/4:_DWORD; __return_address@0x28/4:_UNKNOWN *`; AR absent; AP absent; FR absent; FP absent; body SHA `7AE269077D1C4C3E0D613B86878052616C32829EF015B00A95EF2B63543699EE`; xrefs `{}`; destination `RectBounds__IntersectInto` absent; boundaries `cc` [0x004b7775,0x004b7780) and [0x004b782a,0x004b7830) | `rename({database:"<fresh runtime-attested canonical session ID>",batch:{func:[{addr:"0x004b7780",name:"RectBounds__IntersectInto"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}})` | [0x004b7780,0x004b782a) `RectBounds__IntersectInto`; persisted type absent; public type absent; frame `__saved_registers@0x24/4:_DWORD; __return_address@0x28/4:_UNKNOWN *`; AR absent; AP absent; FR absent; FP absent; body SHA `7AE269077D1C4C3E0D613B86878052616C32829EF015B00A95EF2B63543699EE`; xrefs `{}`; boundaries remain `cc` [0x004b7775,0x004b7780) and [0x004b782a,0x004b7830). |
| I14 | Classification: apply; [0x004b7830,0x004b78c8) `sub_4B7830`; persisted type absent; public type absent; frame `__saved_registers@0x14/4:_DWORD; __return_address@0x18/4:_UNKNOWN *`; AR absent; AP absent; FR absent; FP absent; body SHA `4D329ABFFF21BB0DDCDB23C9B5FB3B3972B5F4A5BBA8300B589145A0C66FB229`; xrefs `{}`; destination `RectBounds__UnionInto` absent; boundaries `cc` [0x004b782a,0x004b7830) and [0x004b78c8,0x004b78d0) | `rename({database:"<fresh runtime-attested canonical session ID>",batch:{func:[{addr:"0x004b7830",name:"RectBounds__UnionInto"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}})` | [0x004b7830,0x004b78c8) `RectBounds__UnionInto`; persisted type absent; public type absent; frame `__saved_registers@0x14/4:_DWORD; __return_address@0x18/4:_UNKNOWN *`; AR absent; AP absent; FR absent; FP absent; body SHA `4D329ABFFF21BB0DDCDB23C9B5FB3B3972B5F4A5BBA8300B589145A0C66FB229`; xrefs `{}`; boundaries remain `cc` [0x004b782a,0x004b7830) and [0x004b78c8,0x004b78d0). |
| I15 | Classification: apply; [0x004b7960,0x004b79f7) `sub_4B7960`; persisted type absent; public type absent; frame `__saved_registers@0x20/4:_DWORD; __return_address@0x24/4:_UNKNOWN *`; AR absent; AP absent; FR absent; FP absent; body SHA `B30A96040C9354609990CAAB536DA058418CEE87E0056D7859338DEC25B89141`; xrefs `{}`; destination `RectBounds__IntersectWith` absent; boundaries `cc` [0x004b795e,0x004b7960) and [0x004b79f7,0x004b7a00) | `rename({database:"<fresh runtime-attested canonical session ID>",batch:{func:[{addr:"0x004b7960",name:"RectBounds__IntersectWith"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}})` | [0x004b7960,0x004b79f7) `RectBounds__IntersectWith`; persisted type absent; public type absent; frame `__saved_registers@0x20/4:_DWORD; __return_address@0x24/4:_UNKNOWN *`; AR absent; AP absent; FR absent; FP absent; body SHA `B30A96040C9354609990CAAB536DA058418CEE87E0056D7859338DEC25B89141`; xrefs `{}`; boundaries remain `cc` [0x004b795e,0x004b7960) and [0x004b79f7,0x004b7a00). |
| I16 | Classification: apply; [0x004b7af0,0x004b7b88) `sub_4B7AF0`; persisted type absent; public type absent; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *`; AR absent; AP absent; FR absent; FP absent; body SHA `AFBA7653829F20377858C09F8831798163E18AAB7758B83B65F7DE3B91DFECAB`; xrefs `{}`; destination `RectBounds__InsetByQuarter` absent; literal refs protected; boundaries `cc` [0x004b7ae8,0x004b7af0) and [0x004b7b88,0x004b7b90) | `rename({database:"<fresh runtime-attested canonical session ID>",batch:{func:[{addr:"0x004b7af0",name:"RectBounds__InsetByQuarter"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}})` | [0x004b7af0,0x004b7b88) `RectBounds__InsetByQuarter`; persisted type absent; public type absent; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *`; AR absent; AP absent; FR absent; FP absent; body SHA `AFBA7653829F20377858C09F8831798163E18AAB7758B83B65F7DE3B91DFECAB`; xrefs `{}`; literal refs exact; boundaries remain `cc` [0x004b7ae8,0x004b7af0) and [0x004b7b88,0x004b7b90). |
| I17 | Classification: apply; [0x004b7b90,0x004b7c21) `sub_4B7B90`; persisted type absent; public type absent; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *`; AR absent; AP absent; FR absent; FP absent; body SHA `E78EA8100376B90E0F9430A62D054A9E7AA997723CC5391EE8BAEB17FF705FD3`; xrefs `{}`; destination `RectBounds__OutsetByHalf` absent; literal refs protected; boundaries `cc` [0x004b7b88,0x004b7b90) and [0x004b7c21,0x004b7c30) | `rename({database:"<fresh runtime-attested canonical session ID>",batch:{func:[{addr:"0x004b7b90",name:"RectBounds__OutsetByHalf"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}})` | [0x004b7b90,0x004b7c21) `RectBounds__OutsetByHalf`; persisted type absent; public type absent; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *`; AR absent; AP absent; FR absent; FP absent; body SHA `E78EA8100376B90E0F9430A62D054A9E7AA997723CC5391EE8BAEB17FF705FD3`; xrefs `{}`; literal refs exact; boundaries remain `cc` [0x004b7b88,0x004b7b90) and [0x004b7c21,0x004b7c30). |
| I18 | Classification: apply; [0x004b7f90,0x004b7fe0) `sub_4B7F90`; persisted type absent; public type absent; frame `__return_address@0x0/4:_UNKNOWN *`; AR absent; AP absent; FR absent; FP absent; body SHA `6CA2AB80C534F281162C1AC736F2706F2A90E6B74EB4774DC5ACF24379621FEF`; xrefs `{}`; destination `Transpose3x3AnchorIndex` absent; predecessor `cc` [0x004b7f87,0x004b7f90), table [0x004b7fe0,0x004b8004), successor `cc` [0x004b8004,0x004b8010) | `rename({database:"<fresh runtime-attested canonical session ID>",batch:{func:[{addr:"0x004b7f90",name:"Transpose3x3AnchorIndex"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}})` | [0x004b7f90,0x004b7fe0) `Transpose3x3AnchorIndex`; persisted type absent; public type absent; frame `__return_address@0x0/4:_UNKNOWN *`; AR absent; AP absent; FR absent; FP absent; body SHA `6CA2AB80C534F281162C1AC736F2706F2A90E6B74EB4774DC5ACF24379621FEF`; xrefs `{}`; predecessor remains `cc` [0x004b7f87,0x004b7f90), table remains [0x004b7fe0,0x004b8004), successor remains `cc` [0x004b8004,0x004b8010). |
| I19 | Classification: apply; [0x004b8010,0x004b80ac) `sub_4B8010`; persisted type absent; public type absent; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *`; AR absent; AP absent; FR absent; FP absent; body SHA `EC65D44AB83AFEE724EA63C8E07D1050E35B4F510AEFDF8CAA8EE3011B9335AB`; xrefs `{}`; destination `AdjustRectPairForAnchor` absent; predecessor `cc` [0x004b8004,0x004b8010), two axis-helper calls and table [0x004b80ac,0x004b80d0) protected | `rename({database:"<fresh runtime-attested canonical session ID>",batch:{func:[{addr:"0x004b8010",name:"AdjustRectPairForAnchor"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}})` | [0x004b8010,0x004b80ac) `AdjustRectPairForAnchor`; persisted type absent; public type absent; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *`; AR absent; AP absent; FR absent; FP absent; body SHA `EC65D44AB83AFEE724EA63C8E07D1050E35B4F510AEFDF8CAA8EE3011B9335AB`; xrefs `{}`; predecessor remains `cc` [0x004b8004,0x004b8010), both axis-helper calls and table [0x004b80ac,0x004b80d0) remain exact. |
| I20 | Classification: apply; [0x004b80d0,0x004b8170) `sub_4B80D0`; persisted type absent; public type absent; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *`; AR absent; AP absent; FR absent; FP absent; body SHA `DB24FE8A1CCEA3E9C45B8A67B8AEE22F81164613FE5C830E9E1C909780C736AB`; xrefs `{}`; destination `AdjustRectPairForAnchorWithOffsets` absent; predecessor table [0x004b80ac,0x004b80d0), two axis-helper calls, table [0x004b8170,0x004b8194), successor `cc` [0x004b8194,0x004b81a0) protected | `rename({database:"<fresh runtime-attested canonical session ID>",batch:{func:[{addr:"0x004b80d0",name:"AdjustRectPairForAnchorWithOffsets"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}})` | [0x004b80d0,0x004b8170) `AdjustRectPairForAnchorWithOffsets`; persisted type absent; public type absent; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *`; AR absent; AP absent; FR absent; FP absent; body SHA `DB24FE8A1CCEA3E9C45B8A67B8AEE22F81164613FE5C830E9E1C909780C736AB`; xrefs `{}`; predecessor remains table [0x004b80ac,0x004b80d0), both axis-helper calls remain exact, table remains [0x004b8170,0x004b8194), successor remains `cc` [0x004b8194,0x004b81a0). |

### Raw-function source-quality type and frame stages

These independent rows run after I11-I20. The only permitted frame delta is addition of the source-visible stack arguments shown; ECX `this` never materializes, prologue-local storage remains an unrepresented protected gap, and every saved-register/return row stays exact.

| ID | Exact post-rename prestate and request | Exact post-type public/Hex-Rays/frame readback |
| --- | --- | --- |
| I11T | Classification: apply; [0x004b7690,0x004b76c8) `RectBounds__HasSameSizeAs`; persisted type absent; public type absent; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *`; AR absent; AP absent; FR absent; FP absent; body SHA256 `F5390A22C1B14C8FCF33BADB759A2C6DAF0457BDB5BA1904C21B2AC6AE40F7F4`; xrefs exactly `{}`; boundaries `cc` [0x004b7685,0x004b7690) and [0x004b76c8,0x004b76d0); `set_type({database:"<fresh runtime-attested canonical session ID>",edits:[{addr:"0x004b7690",kind:"function",signature:"bool __thiscall RectBounds__HasSameSizeAs(const RectBounds *this, const RectBounds *bounds)"}]})` | [0x004b7690,0x004b76c8) `RectBounds__HasSameSizeAs`; persisted/public/Hex-Rays type exactly `bool __thiscall RectBounds__HasSameSizeAs(const RectBounds *this, const RectBounds *bounds)`; frame exactly `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; bounds@0x8/4:const RectBounds *`; AR absent; AP absent; FR absent; FP absent; body SHA256 `F5390A22C1B14C8FCF33BADB759A2C6DAF0457BDB5BA1904C21B2AC6AE40F7F4`; xrefs `{}`; boundaries remain `cc` [0x004b7685,0x004b7690) and [0x004b76c8,0x004b76d0). |
| I12T | Classification: apply; [0x004b7700,0x004b7775) `RectBounds__ContainsRect`; persisted type absent; public type absent; frame `__saved_registers@0x14/4:_DWORD; __return_address@0x18/4:_UNKNOWN *`; AR absent; AP absent; FR absent; FP absent; body SHA256 `A86D0E0E4F5585EC031315B115FFDEAF6EE2FC55A05BB3F01B49E2E65D0ECD8E`; xrefs exactly `{}`; boundaries `cc` [0x004b76f8,0x004b7700) and [0x004b7775,0x004b7780); `set_type({database:"<fresh runtime-attested canonical session ID>",edits:[{addr:"0x004b7700",kind:"function",signature:"bool __thiscall RectBounds__ContainsRect(const RectBounds *this, const RectBounds *bounds)"}]})` | [0x004b7700,0x004b7775) `RectBounds__ContainsRect`; persisted/public/Hex-Rays type exactly `bool __thiscall RectBounds__ContainsRect(const RectBounds *this, const RectBounds *bounds)`; frame exactly `__saved_registers@0x14/4:_DWORD; __return_address@0x18/4:_UNKNOWN *; bounds@0x1c/4:const RectBounds *`; the local 0x0c allocation remains unrepresented; AR absent; AP absent; FR absent; FP absent; body SHA256 `A86D0E0E4F5585EC031315B115FFDEAF6EE2FC55A05BB3F01B49E2E65D0ECD8E`; xrefs `{}`; boundaries remain `cc` [0x004b76f8,0x004b7700) and [0x004b7775,0x004b7780). |
| I13T | Classification: apply; [0x004b7780,0x004b782a) `RectBounds__IntersectInto`; persisted type absent; public type absent; frame `__saved_registers@0x24/4:_DWORD; __return_address@0x28/4:_UNKNOWN *`; AR absent; AP absent; FR absent; FP absent; body SHA256 `7AE269077D1C4C3E0D613B86878052616C32829EF015B00A95EF2B63543699EE`; xrefs exactly `{}`; boundaries `cc` [0x004b7775,0x004b7780) and [0x004b782a,0x004b7830); `set_type({database:"<fresh runtime-attested canonical session ID>",edits:[{addr:"0x004b7780",kind:"function",signature:"bool __thiscall RectBounds__IntersectInto(const RectBounds *this, const RectBounds *bounds, RectBounds *outBounds)"}]})` | [0x004b7780,0x004b782a) `RectBounds__IntersectInto`; persisted/public/Hex-Rays type exactly `bool __thiscall RectBounds__IntersectInto(const RectBounds *this, const RectBounds *bounds, RectBounds *outBounds)`; frame exactly `__saved_registers@0x24/4:_DWORD; __return_address@0x28/4:_UNKNOWN *; bounds@0x2c/4:const RectBounds *; outBounds@0x30/4:RectBounds *`; the local 0x18 allocation remains unrepresented; AR absent; AP absent; FR absent; FP absent; body SHA256 `7AE269077D1C4C3E0D613B86878052616C32829EF015B00A95EF2B63543699EE`; xrefs `{}`; boundaries remain `cc` [0x004b7775,0x004b7780) and [0x004b782a,0x004b7830). |
| I14T | Classification: apply; [0x004b7830,0x004b78c8) `RectBounds__UnionInto`; persisted type absent; public type absent; frame `__saved_registers@0x14/4:_DWORD; __return_address@0x18/4:_UNKNOWN *`; AR absent; AP absent; FR absent; FP absent; body SHA256 `4D329ABFFF21BB0DDCDB23C9B5FB3B3972B5F4A5BBA8300B589145A0C66FB229`; xrefs exactly `{}`; boundaries `cc` [0x004b782a,0x004b7830) and [0x004b78c8,0x004b78d0); `set_type({database:"<fresh runtime-attested canonical session ID>",edits:[{addr:"0x004b7830",kind:"function",signature:"void __thiscall RectBounds__UnionInto(const RectBounds *this, const RectBounds *bounds, RectBounds *outBounds)"}]})` | [0x004b7830,0x004b78c8) `RectBounds__UnionInto`; persisted/public/Hex-Rays type exactly `void __thiscall RectBounds__UnionInto(const RectBounds *this, const RectBounds *bounds, RectBounds *outBounds)`; frame exactly `__saved_registers@0x14/4:_DWORD; __return_address@0x18/4:_UNKNOWN *; bounds@0x1c/4:const RectBounds *; outBounds@0x20/4:RectBounds *`; the local 0x0c allocation remains unrepresented; AR absent; AP absent; FR absent; FP absent; body SHA256 `4D329ABFFF21BB0DDCDB23C9B5FB3B3972B5F4A5BBA8300B589145A0C66FB229`; xrefs `{}`; boundaries remain `cc` [0x004b782a,0x004b7830) and [0x004b78c8,0x004b78d0). |
| I15T | Classification: apply; [0x004b7960,0x004b79f7) `RectBounds__IntersectWith`; persisted type absent; public type absent; frame `__saved_registers@0x20/4:_DWORD; __return_address@0x24/4:_UNKNOWN *`; AR absent; AP absent; FR absent; FP absent; body SHA256 `B30A96040C9354609990CAAB536DA058418CEE87E0056D7859338DEC25B89141`; xrefs exactly `{}`; boundaries `cc` [0x004b795e,0x004b7960) and [0x004b79f7,0x004b7a00); `set_type({database:"<fresh runtime-attested canonical session ID>",edits:[{addr:"0x004b7960",kind:"function",signature:"bool __thiscall RectBounds__IntersectWith(RectBounds *this, const RectBounds *bounds)"}]})` | [0x004b7960,0x004b79f7) `RectBounds__IntersectWith`; persisted/public/Hex-Rays type exactly `bool __thiscall RectBounds__IntersectWith(RectBounds *this, const RectBounds *bounds)`; frame exactly `__saved_registers@0x20/4:_DWORD; __return_address@0x24/4:_UNKNOWN *; bounds@0x28/4:const RectBounds *`; the local 0x14 allocation remains unrepresented; AR absent; AP absent; FR absent; FP absent; body SHA256 `B30A96040C9354609990CAAB536DA058418CEE87E0056D7859338DEC25B89141`; xrefs `{}`; boundaries remain `cc` [0x004b795e,0x004b7960) and [0x004b79f7,0x004b7a00). |
| I16T | Classification: apply; [0x004b7af0,0x004b7b88) `RectBounds__InsetByQuarter`; persisted type absent; public type absent; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *`; AR absent; AP absent; FR absent; FP absent; body SHA256 `AFBA7653829F20377858C09F8831798163E18AAB7758B83B65F7DE3B91DFECAB`; xrefs exactly `{}`; boundaries `cc` [0x004b7ae8,0x004b7af0) and [0x004b7b88,0x004b7b90); literal refs protected; `set_type({database:"<fresh runtime-attested canonical session ID>",edits:[{addr:"0x004b7af0",kind:"function",signature:"RectBounds *__thiscall RectBounds__InsetByQuarter(const RectBounds *this, RectBounds *outBounds)"}]})` | [0x004b7af0,0x004b7b88) `RectBounds__InsetByQuarter`; persisted/public/Hex-Rays type exactly `RectBounds *__thiscall RectBounds__InsetByQuarter(const RectBounds *this, RectBounds *outBounds)`; frame exactly `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; outBounds@0x8/4:RectBounds *`; AR absent; AP absent; FR absent; FP absent; body SHA256 `AFBA7653829F20377858C09F8831798163E18AAB7758B83B65F7DE3B91DFECAB`; xrefs `{}`; literal refs exact; boundaries remain `cc` [0x004b7ae8,0x004b7af0) and [0x004b7b88,0x004b7b90). |
| I17T | Classification: apply; [0x004b7b90,0x004b7c21) `RectBounds__OutsetByHalf`; persisted type absent; public type absent; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *`; AR absent; AP absent; FR absent; FP absent; body SHA256 `E78EA8100376B90E0F9430A62D054A9E7AA997723CC5391EE8BAEB17FF705FD3`; xrefs exactly `{}`; boundaries `cc` [0x004b7b88,0x004b7b90) and [0x004b7c21,0x004b7c30); literal refs protected; `set_type({database:"<fresh runtime-attested canonical session ID>",edits:[{addr:"0x004b7b90",kind:"function",signature:"RectBounds *__thiscall RectBounds__OutsetByHalf(const RectBounds *this, RectBounds *outBounds)"}]})` | [0x004b7b90,0x004b7c21) `RectBounds__OutsetByHalf`; persisted/public/Hex-Rays type exactly `RectBounds *__thiscall RectBounds__OutsetByHalf(const RectBounds *this, RectBounds *outBounds)`; frame exactly `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; outBounds@0x8/4:RectBounds *`; AR absent; AP absent; FR absent; FP absent; body SHA256 `E78EA8100376B90E0F9430A62D054A9E7AA997723CC5391EE8BAEB17FF705FD3`; xrefs `{}`; literal refs exact; boundaries remain `cc` [0x004b7b88,0x004b7b90) and [0x004b7c21,0x004b7c30). |
| I18T | Classification: apply; [0x004b7f90,0x004b7fe0) `Transpose3x3AnchorIndex`; persisted type absent; public type absent; frame `__return_address@0x0/4:_UNKNOWN *`; AR absent; AP absent; FR absent; FP absent; body SHA256 `6CA2AB80C534F281162C1AC736F2706F2A90E6B74EB4774DC5ACF24379621FEF`; xrefs exactly `{}`; predecessor `cc` [0x004b7f87,0x004b7f90), switch table [0x004b7fe0,0x004b8004), successor `cc` [0x004b8004,0x004b8010); `set_type({database:"<fresh runtime-attested canonical session ID>",edits:[{addr:"0x004b7f90",kind:"function",signature:"int __cdecl Transpose3x3AnchorIndex(int anchor)"}]})` | [0x004b7f90,0x004b7fe0) `Transpose3x3AnchorIndex`; persisted/public/Hex-Rays type exactly `int __cdecl Transpose3x3AnchorIndex(int anchor)`; frame exactly `__return_address@0x0/4:_UNKNOWN *; anchor@0x4/4:int`; AR absent; AP absent; FR absent; FP absent; body SHA256 `6CA2AB80C534F281162C1AC736F2706F2A90E6B74EB4774DC5ACF24379621FEF`; xrefs `{}`; predecessor remains `cc` [0x004b7f87,0x004b7f90), switch table remains [0x004b7fe0,0x004b8004), successor remains `cc` [0x004b8004,0x004b8010). |
| I19T | Classification: apply; [0x004b8010,0x004b80ac) `AdjustRectPairForAnchor`; persisted type absent; public type absent; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *`; AR absent; AP absent; FR absent; FP absent; body SHA256 `EC65D44AB83AFEE724EA63C8E07D1050E35B4F510AEFDF8CAA8EE3011B9335AB`; xrefs exactly `{}`; predecessor `cc` [0x004b8004,0x004b8010), switch table [0x004b80ac,0x004b80d0), two axis-helper calls protected; `set_type({database:"<fresh runtime-attested canonical session ID>",edits:[{addr:"0x004b8010",kind:"function",signature:"void __cdecl AdjustRectPairForAnchor(const RectBounds *firstBounds, const RectBounds *secondBounds, int anchor, RectBounds *outFirstBounds, RectBounds *outSecondBounds)"}]})` | [0x004b8010,0x004b80ac) `AdjustRectPairForAnchor`; persisted/public/Hex-Rays type exactly `void __cdecl AdjustRectPairForAnchor(const RectBounds *firstBounds, const RectBounds *secondBounds, int anchor, RectBounds *outFirstBounds, RectBounds *outSecondBounds)`; frame exactly `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; firstBounds@0x8/4:const RectBounds *; secondBounds@0xc/4:const RectBounds *; anchor@0x10/4:int; outFirstBounds@0x14/4:RectBounds *; outSecondBounds@0x18/4:RectBounds *`; AR absent; AP absent; FR absent; FP absent; body SHA256 `EC65D44AB83AFEE724EA63C8E07D1050E35B4F510AEFDF8CAA8EE3011B9335AB`; xrefs `{}`; predecessor remains `cc` [0x004b8004,0x004b8010), two axis-helper calls remain exact, switch table remains [0x004b80ac,0x004b80d0). |
| I20T | Classification: apply; [0x004b80d0,0x004b8170) `AdjustRectPairForAnchorWithOffsets`; persisted type absent; public type absent; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *`; AR absent; AP absent; FR absent; FP absent; body SHA256 `DB24FE8A1CCEA3E9C45B8A67B8AEE22F81164613FE5C830E9E1C909780C736AB`; xrefs exactly `{}`; predecessor table [0x004b80ac,0x004b80d0), switch table [0x004b8170,0x004b8194), successor `cc` [0x004b8194,0x004b81a0), two axis-helper calls protected; `set_type({database:"<fresh runtime-attested canonical session ID>",edits:[{addr:"0x004b80d0",kind:"function",signature:"void __cdecl AdjustRectPairForAnchorWithOffsets(const RectBounds *firstBounds, const RectBounds *secondBounds, int anchor, int horizontalOffset, int verticalOffset, RectBounds *outFirstBounds, RectBounds *outSecondBounds)"}]})` | [0x004b80d0,0x004b8170) `AdjustRectPairForAnchorWithOffsets`; persisted/public/Hex-Rays type exactly `void __cdecl AdjustRectPairForAnchorWithOffsets(const RectBounds *firstBounds, const RectBounds *secondBounds, int anchor, int horizontalOffset, int verticalOffset, RectBounds *outFirstBounds, RectBounds *outSecondBounds)`; frame exactly `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; firstBounds@0x8/4:const RectBounds *; secondBounds@0xc/4:const RectBounds *; anchor@0x10/4:int; horizontalOffset@0x14/4:int; verticalOffset@0x18/4:int; outFirstBounds@0x1c/4:RectBounds *; outSecondBounds@0x20/4:RectBounds *`; AR absent; AP absent; FR absent; FP absent; body SHA256 `DB24FE8A1CCEA3E9C45B8A67B8AEE22F81164613FE5C830E9E1C909780C736AB`; xrefs `{}`; predecessor table remains [0x004b80ac,0x004b80d0), two axis-helper calls remain exact, switch table remains [0x004b8170,0x004b8194), successor remains `cc` [0x004b8194,0x004b81a0). |

### Modeled-function evidence summary retained from the rejected combined contract

All eleven modeled rows were freshly reread. AR absent; AP absent; FR absent; FP absent for every row. The full xref manifests below are terminal (`more:false`) and must remain byte-for-byte set-equivalent after every stage. The combined rename/type cells in this retained evidence table are superseded shorthand and are not executable action declarations; authoritative, independently staged I21-I42 contracts follow immediately after it.

| Entry | Exact current identity/type/frame | Exact immutable xref set and body | Rename/type stages | Exact expected type-stage readback |
| --- | --- | --- | --- | --- |
| 0x004b7670 | [0x004b7670,0x004b7685) `sub_4B7670`; type `bool __thiscall(_DWORD *this)`; frame `__return_address@0x0/4:_UNKNOWN *`; AR/AP/FR/FP absent | SHA256 CC1ADFECB4B1B4900F002BD7789AFDC2A8A5A27CB34D388565E9754BFC66DA70; 7 refs exactly {0x496cf6:code, 0x496e30:code, 0x497104:code, 0x49723e:code, 0x4c789d:code, 0x538ef5:code, 0x539435:code}; more:false | I21 `rename({database:"<fresh runtime-attested canonical session ID>",batch:{func:[{addr:"0x004b7670",name:"RectBounds__IsEmptyOrInvalid"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}})`; I32 `set_type({database:"<fresh runtime-attested canonical session ID>",edits:[{addr:"0x004b7670",kind:"function",signature:"bool __thiscall RectBounds__IsEmptyOrInvalid(const RectBounds *this)"}]})` | exact name/signature; complete physical frame remains `__return_address@0x0/4:_UNKNOWN *`; all channels absent; range/hash/xref set unchanged |
| 0x004b76d0 | [0x004b76d0,0x004b76f8) `sub_4B76D0`; type `bool __thiscall(_DWORD *this, int, int)`; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; arg_0@0x8/4:_DWORD; arg_4@0xc/4:_DWORD`; AR/AP/FR/FP absent | SHA256 3AAB471767B3F1109BDA8C17FD50891B1DFBC090E0CF1FB6BEA309CA310AE664; 4 refs exactly {0x499df9:code, 0x4b2e00:code, 0x4b2e48:code, 0x4b39bf:code}; more:false | I22 `rename({database:"<fresh runtime-attested canonical session ID>",batch:{func:[{addr:"0x004b76d0",name:"RectBounds__ContainsPoint"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}})`; I33 `set_type({database:"<fresh runtime-attested canonical session ID>",edits:[{addr:"0x004b76d0",kind:"function",signature:"bool __thiscall RectBounds__ContainsPoint(const RectBounds *this, int y, int x)"}]})` | exact name/signature; complete physical frame becomes `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; y@0x8/4:int; x@0xc/4:int`; all channels absent; range/hash/xref set unchanged |
| 0x004b78d0 | [0x004b78d0,0x004b78ee) `sub_4B78D0`; type `int __thiscall(_DWORD *this, int, int, int, int)`; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; arg_0@0x8/4:_DWORD; arg_4@0xc/4:_DWORD; arg_8@0x10/4:_DWORD; arg_C@0x14/4:_DWORD`; AR/AP/FR/FP absent | SHA256 98BA7875DEAD4691B1E62A6E502A194D10125F65841C18AEAB502D35A72A009A; 208 refs exactly {0x41bb44:code, 0x41bc9a:code, 0x41f69b:code, 0x451f27:code, 0x4521fd:code, 0x452504:code, 0x455ffd:code, 0x456152:code, 0x45623b:code, 0x46934a:code, 0x46c027:code, 0x46c123:code, 0x46c271:code, 0x46d15a:code, 0x46d1d0:code, 0x46d25e:code, 0x46e34b:code, 0x46e3cb:code, 0x46e45b:code, 0x46e509:code, 0x46e526:code, 0x46e53d:code, 0x46e56a:code, 0x46e587:code, 0x46e59e:code, 0x46e5ca:code, 0x46e600:code, 0x46ffe6:code, 0x477897:code, 0x4778ef:code, 0x477937:code, 0x477988:code, 0x477a09:code, 0x477d58:code, 0x477dad:code, 0x477df8:code, 0x477e4c:code, 0x477ecd:code, 0x4781a4:code, 0x4b1621:code, 0x4b1674:code, 0x4b1712:code, 0x4b17b2:code, 0x4b64c1:code, 0x4b86ec:code, 0x4b87bc:code, 0x4b8a1e:code, 0x4b9a35:code, 0x4bb1ff:code, 0x4c8cac:code, 0x4c8d01:code, 0x4c8dea:code, 0x4c8f6a:code, 0x4c8fcb:code, 0x4c90cf:code, 0x4c912b:code, 0x4c91ed:code, 0x4c9249:code, 0x4c9344:code, 0x4c93b5:code, 0x4c941f:code, 0x4c9839:code, 0x4c98af:code, 0x4c9a19:code, 0x4c9a8f:code, 0x4c9bf9:code, 0x4c9c6f:code, 0x4c9dd9:code, 0x4c9e4f:code, 0x4c9fb9:code, 0x4ca02f:code, 0x4ca199:code, 0x4ca20f:code, 0x4ca379:code, 0x4ca3ef:code, 0x4ca559:code, 0x4ca5cf:code, 0x4ca739:code, 0x4ca7af:code, 0x4ca919:code, 0x4ca98f:code, 0x4caaf9:code, 0x4cab6f:code, 0x4cacc2:code, 0x4cad33:code, 0x4caeb2:code, 0x4caf21:code, 0x4cafde:code, 0x4cb1d5:code, 0x4cb25a:code, 0x4cb2e0:code, 0x4cb348:code, 0x4cb515:code, 0x4cb59a:code, 0x4cb620:code, 0x4cb688:code, 0x4cb6f5:code, 0x4cb756:code, 0x4cb7b7:code, 0x4cb818:code, 0x4cb9e5:code, 0x4cba6a:code, 0x4cbaf0:code, 0x4cbb58:code, 0x4cbbc5:code, 0x4cbc26:code, 0x4cbc87:code, 0x4cbce8:code, 0x4cbeb5:code, 0x4cbf3a:code, 0x4cbfc0:code, 0x4cc028:code, 0x4cc095:code, 0x4cc0f6:code, 0x4cc157:code, 0x4cc1b8:code, 0x4cc385:code, 0x4cc40a:code, 0x4cc490:code, 0x4cc4f8:code, 0x4cc565:code, 0x4cc5c6:code, 0x4cc627:code, 0x4cc688:code, 0x4cc855:code, 0x4cc8da:code, 0x4cc960:code, 0x4cc9c8:code, 0x4cca35:code, 0x4cca96:code, 0x4ccaf7:code, 0x4ccb58:code, 0x4d6d77:code, 0x4e326e:code, 0x4e34c1:code, 0x4e3af2:code, 0x4e3d52:code, 0x4e99ca:code, 0x4eb654:code, 0x4ebd30:code, 0x4ec329:code, 0x4ec36d:code, 0x4f4cb8:code, 0x4f4db2:code, 0x4f51a7:code, 0x4ffbd3:code, 0x50dc7a:code, 0x521f83:code, 0x5226af:code, 0x528eef:code, 0x528f51:code, 0x528f8e:code, 0x528fd8:code, 0x529026:code, 0x529063:code, 0x5290cc:code, 0x52911a:code, 0x529157:code, 0x5291c0:code, 0x529255:code, 0x5292a6:code, 0x5293ba:code, 0x5293f7:code, 0x529447:code, 0x529484:code, 0x5294ce:code, 0x52951c:code, 0x52956d:code, 0x5295bb:code, 0x529618:code, 0x52a7c0:code, 0x52a821:code, 0x52c5e7:code, 0x52c648:code, 0x52f9ec:code, 0x52fa43:code, 0x52fa9a:code, 0x52fb06:code, 0x52fb7b:code, 0x52fbcc:code, 0x52fc1d:code, 0x52fca6:code, 0x52fcfd:code, 0x52fd57:code, 0x52fdc3:code, 0x52fe38:code, 0x52fe89:code, 0x52feda:code, 0x52ff57:code, 0x53d932:code, 0x53d977:code, 0x53d987:code, 0x53d99d:code, 0x53dbdb:code, 0x549736:code, 0x5497b7:code, 0x569d14:code, 0x56ccc4:code, 0x57d194:code, 0x57d624:code, 0x5a28f3:code, 0x5a2bf4:code, 0x5a7d8b:code, 0x5abd44:code, 0x5c3748:code, 0x5c37aa:code, 0x5c399f:code, 0x5c3bee:code}; more:false | I23 `rename({database:"<fresh runtime-attested canonical session ID>",batch:{func:[{addr:"0x004b78d0",name:"RectBounds__SetLTRB"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}})`; I34 `set_type({database:"<fresh runtime-attested canonical session ID>",edits:[{addr:"0x004b78d0",kind:"function",signature:"void __thiscall RectBounds__SetLTRB(RectBounds *this, int leftValue, int topValue, int rightValue, int bottomValue)"}]})` | exact name/signature; complete physical frame becomes `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; leftValue@0x8/4:int; topValue@0xc/4:int; rightValue@0x10/4:int; bottomValue@0x14/4:int`; all channels absent; range/hash/xref set unchanged |
| 0x004b7910 | [0x004b7910,0x004b795e) `sub_4B7910`; type `int __thiscall(int *this, int, int)`; frame `__saved_registers@0xc/4:_DWORD; __return_address@0x10/4:_UNKNOWN *; arg_0@0x14/4:_DWORD; arg_4@0x18/4:_DWORD`; AR/AP/FR/FP absent | SHA256 FEF40B7E2D1B870673A814D47DC3311EC6B7A5FBA057B70FDCA47405707BA0C9; 3 refs exactly {0x53bcb7:code, 0x53bcd8:code, 0x53bcf9:code}; more:false | I24 `rename({database:"<fresh runtime-attested canonical session ID>",batch:{func:[{addr:"0x004b7910",name:"RectBounds__Inset"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}})`; I35 `set_type({database:"<fresh runtime-attested canonical session ID>",edits:[{addr:"0x004b7910",kind:"function",signature:"void __thiscall RectBounds__Inset(RectBounds *this, int dx, int dy)"}]})` | exact name/signature; complete physical frame becomes `__saved_registers@0xc/4:_DWORD; __return_address@0x10/4:_UNKNOWN *; dx@0x14/4:int; dy@0x18/4:int`; all channels absent; range/hash/xref set unchanged |
| 0x004b7a00 | [0x004b7a00,0x004b7a77) `sub_4B7A00`; type `_DWORD *__thiscall(_DWORD *this, int *)`; frame `var_4@0x8/4:_DWORD; __saved_registers@0xc/4:_DWORD; __return_address@0x10/4:_UNKNOWN *; arg_0@0x14/4:_DWORD`; AR/AP/FR/FP absent | SHA256 8349772D4644A0481E2021C674B65A526220D165F705EF7013BAE3BD7E6E7F2D; 33 refs exactly {0x4d6dec:code, 0x4d6e1b:code, 0x4d6e4a:code, 0x4d6e73:code, 0x4d6ea2:code, 0x4d6ed1:code, 0x4d6f00:code, 0x4d6f2f:code, 0x4d6f86:code, 0x4d7202:code, 0x4d7249:code, 0x4d7290:code, 0x4d72d7:code, 0x4d731e:code, 0x4d7365:code, 0x4d73ac:code, 0x4d73ea:code, 0x4d7471:code, 0x4d74d7:code, 0x4d756e:code, 0x4d75df:code, 0x4e3087:code, 0x4e3352:code, 0x4e33af:code, 0x4e3957:code, 0x4e3c86:code, 0x4e3cd4:code, 0x4e4030:code, 0x4e4403:code, 0x4e446a:code, 0x4e4bcc:code, 0x598fac:code, 0x5990cc:code}; more:false | I25 `rename({database:"<fresh runtime-attested canonical session ID>",batch:{func:[{addr:"0x004b7a00",name:"RectBounds__UnionWith"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}})`; I36 `set_type({database:"<fresh runtime-attested canonical session ID>",edits:[{addr:"0x004b7a00",kind:"function",signature:"RectBounds *__thiscall RectBounds__UnionWith(RectBounds *this, const RectBounds *bounds)"}]})` | exact name/signature; complete physical frame becomes `var_4@0x8/4:_DWORD; __saved_registers@0xc/4:_DWORD; __return_address@0x10/4:_UNKNOWN *; bounds@0x14/4:const RectBounds *`; all channels absent; range/hash/xref set unchanged |
| 0x004b7a80 | [0x004b7a80,0x004b7ae8) `sub_4B7A80`; type `int __thiscall(int *this, int, int, int, int)`; frame `__saved_registers@0x8/4:_DWORD; __return_address@0xc/4:_UNKNOWN *; arg_0@0x10/4:_DWORD; arg_4@0x14/4:_DWORD; arg_8@0x18/4:_DWORD; arg_C@0x1c/4:_DWORD`; AR/AP/FR/FP absent | SHA256 E00162FFCF7A7802134C247A60681CA9F29D1E1815696636E223671B445D1588; 2 refs exactly {0x5c3767:code, 0x5c37c9:code}; more:false | I26 `rename({database:"<fresh runtime-attested canonical session ID>",batch:{func:[{addr:"0x004b7a80",name:"RectBounds__ClampWithin"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}})`; I37 `set_type({database:"<fresh runtime-attested canonical session ID>",edits:[{addr:"0x004b7a80",kind:"function",signature:"void __thiscall RectBounds__ClampWithin(RectBounds *this, int leftLimit, int topLimit, int rightLimit, int bottomLimit)"}]})` | exact name/signature; complete physical frame becomes `__saved_registers@0x8/4:_DWORD; __return_address@0xc/4:_UNKNOWN *; leftLimit@0x10/4:int; topLimit@0x14/4:int; rightLimit@0x18/4:int; bottomLimit@0x1c/4:int`; all channels absent; range/hash/xref set unchanged |
| 0x004b7c70 | [0x004b7c70,0x004b7c95) `sub_4B7C70`; type `int __cdecl(_DWORD *, int, int, int, int)`; frame `__saved_registers@0x4/4:_DWORD; __return_address@0x8/4:_UNKNOWN *; arg_0@0xc/4:_DWORD; arg_4@0x10/4:_DWORD; arg_8@0x14/4:_DWORD; arg_C@0x18/4:_DWORD; arg_10@0x1c/4:_DWORD`; AR/AP/FR/FP absent | SHA256 E3FEB5168886A48FD06A13AEEB62B4FB0F502ACEEBE1496F749FEF32DC53B310; 38 refs exactly {0x41c1c9:code, 0x41cd92:code, 0x41d182:code, 0x41d1a2:code, 0x41d1bc:code, 0x41d1d9:code, 0x41d1f3:code, 0x41d20d:code, 0x41d244:code, 0x41d261:code, 0x42442c:code, 0x458894:code, 0x459368:code, 0x459385:code, 0x4593a5:code, 0x4593c2:code, 0x4593df:code, 0x4593fc:code, 0x459419:code, 0x45b358:code, 0x45b543:code, 0x45b812:code, 0x45bd3a:code, 0x45dc4c:code, 0x45dc9b:code, 0x45e6bc:code, 0x45ea52:code, 0x46abc9:code, 0x46b4dc:code, 0x46b511:code, 0x47d383:code, 0x47d40e:code, 0x49a382:code, 0x4c68d2:code, 0x5402d1:code, 0x540306:code, 0x540339:code, 0x54036e:code}; more:false | I27 `rename({database:"<fresh runtime-attested canonical session ID>",batch:{func:[{addr:"0x004b7c70",name:"InitRectBoundsFromSize"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}})`; I38 `set_type({database:"<fresh runtime-attested canonical session ID>",edits:[{addr:"0x004b7c70",kind:"function",signature:"void __cdecl InitRectBoundsFromSize(RectBounds *bounds, int left, int top, int width, int height)"}]})` | exact name/signature; complete physical frame becomes `__saved_registers@0x4/4:_DWORD; __return_address@0x8/4:_UNKNOWN *; bounds@0xc/4:RectBounds *; left@0x10/4:int; top@0x14/4:int; width@0x18/4:int; height@0x1c/4:int`; all channels absent; range/hash/xref set unchanged |
| 0x004b7ca0 | [0x004b7ca0,0x004b7cb6) `sub_4B7CA0`; type `int __cdecl(_DWORD *)`; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; arg_0@0x8/4:_DWORD`; AR/AP/FR/FP absent | SHA256 163710594CCDDC680B855D28D4CDD027E1EDF64AD557EBB23225C51A41ACBB68; 4 refs exactly {0x4580de:code, 0x4581da:code, 0x45833d:code, 0x4b621a:code}; more:false | I28 `rename({database:"<fresh runtime-attested canonical session ID>",batch:{func:[{addr:"0x004b7ca0",name:"RectArea"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}})`; I39 `set_type({database:"<fresh runtime-attested canonical session ID>",edits:[{addr:"0x004b7ca0",kind:"function",signature:"int __cdecl RectArea(const RectBounds *bounds)"}]})` | exact name/signature; complete physical frame becomes `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; bounds@0x8/4:const RectBounds *`; all channels absent; range/hash/xref set unchanged |
| 0x004b7e30 | [0x004b7e30,0x004b7e7f) `sub_4B7E30`; type `int __cdecl(int *, int, int)`; frame `__saved_registers@0xc/4:_DWORD; __return_address@0x10/4:_UNKNOWN *; arg_0@0x14/4:_DWORD; arg_4@0x18/4:_DWORD; arg_8@0x1c/4:_DWORD`; AR/AP/FR/FP absent | SHA256 A81AC6D7E55C4D42090AF94E22F93F4F1136229BE2E83DDF4CA74765512FB102; 32 refs exactly {0x424153:code, 0x46af38:code, 0x46af6a:code, 0x46af91:code, 0x46afd0:code, 0x46aff7:code, 0x46dc4c:code, 0x46dc7e:code, 0x46dcaa:code, 0x46dcd1:code, 0x4952f9:code, 0x498ad5:code, 0x498f80:code, 0x498fa7:code, 0x49f11b:code, 0x49f14b:code, 0x49f177:code, 0x49f19e:code, 0x49fe8a:code, 0x4fce5c:code, 0x500cc7:code, 0x500cf9:code, 0x500d25:code, 0x500d4c:code, 0x506a96:code, 0x509712:code, 0x50fc3d:code, 0x5115c7:code, 0x53915b:code, 0x5391e9:code, 0x545d94:code, 0x5a31c9:code}; more:false | I29 `rename({database:"<fresh runtime-attested canonical session ID>",batch:{func:[{addr:"0x004b7e30",name:"InsetRect"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}})`; I40 `set_type({database:"<fresh runtime-attested canonical session ID>",edits:[{addr:"0x004b7e30",kind:"function",signature:"void __cdecl InsetRect(RectBounds *bounds, int dx, int dy)"}]})` | exact name/signature; complete physical frame becomes `__saved_registers@0xc/4:_DWORD; __return_address@0x10/4:_UNKNOWN *; bounds@0x14/4:RectBounds *; dx@0x18/4:int; dy@0x1c/4:int`; all channels absent; range/hash/xref set unchanged |
| 0x004b7f30 | [0x004b7f30,0x004b7f87) `sub_4B7F30`; type `bool __cdecl(_DWORD *, _DWORD *)`; frame `__saved_registers@0x8/4:_DWORD; __return_address@0xc/4:_UNKNOWN *; arg_0@0x10/4:_DWORD; arg_4@0x14/4:_DWORD`; AR/AP/FR/FP absent | SHA256 24A3CF15F60046C64256E895BF3CF0804F1775FBFAC06C39633A1065B11481D5; 2 refs exactly {0x554a4a:code, 0x554a83:code}; more:false | I30 `rename({database:"<fresh runtime-attested canonical session ID>",batch:{func:[{addr:"0x004b7f30",name:"RectContainsRect"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}})`; I41 `set_type({database:"<fresh runtime-attested canonical session ID>",edits:[{addr:"0x004b7f30",kind:"function",signature:"bool __cdecl RectContainsRect(const RectBounds *innerBounds, const RectBounds *outerBounds)"}]})` | exact name/signature; complete physical frame becomes `__saved_registers@0x8/4:_DWORD; __return_address@0xc/4:_UNKNOWN *; innerBounds@0x10/4:const RectBounds *; outerBounds@0x14/4:const RectBounds *`; all channels absent; range/hash/xref set unchanged |
| 0x004b8290 | [0x004b8290,0x004b83ae) `sub_4B8290`; type `int *__cdecl(int *, int, int *, int *, int *, int *)`; frame `var_10@0xc/4:_DWORD; var_C@0x10/4:_DWORD; var_8@0x14/4:_DWORD; var_4@0x18/4:_DWORD; __saved_registers@0x1c/4:_DWORD; __return_address@0x20/4:_UNKNOWN *; arg_0@0x24/4:_DWORD; arg_4@0x28/4:_DWORD; arg_8@0x2c/4:_DWORD; arg_C@0x30/4:_DWORD; arg_10@0x34/4:_DWORD; arg_14@0x38/4:_DWORD`; AR/AP/FR/FP absent | SHA256 2AEC81E39738637C5E9B1D3D0AA050D26BBA66F59590867E105CAB965F6B0D16; 4 refs exactly {0x4b803e:code, 0x4b809f:code, 0x4b80ff:code, 0x4b8161:code}; more:false | I31 `rename({database:"<fresh runtime-attested canonical session ID>",batch:{func:[{addr:"0x004b8290",name:"AdjustRectAnchorAxis"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}})`; I42 `set_type({database:"<fresh runtime-attested canonical session ID>",edits:[{addr:"0x004b8290",kind:"function",signature:"void __cdecl AdjustRectAnchorAxis(int anchor, int offset, int *firstLow, int *firstHigh, int *secondLow, int *secondHigh)"}]})` | exact name/signature; complete physical frame becomes `var_10@0xc/4:_DWORD; var_C@0x10/4:_DWORD; var_8@0x14/4:_DWORD; var_4@0x18/4:_DWORD; __saved_registers@0x1c/4:_DWORD; __return_address@0x20/4:_UNKNOWN *; anchor@0x24/4:int; offset@0x28/4:int; firstLow@0x2c/4:int *; firstHigh@0x30/4:int *; secondLow@0x34/4:int *; secondHigh@0x38/4:int *`; all channels absent; range/hash/xref set unchanged |

### Authoritative pure-rename stages I21-I31

For broad terminal xref sets, the exact xref state is identified by count, `more:false`, and SHA256 over the lowercase ascending comma-joined `source-address:kind` manifest; small sets are enumerated literally. Every rename row uses the public pure-function rename endpoint and changes only the persisted name. The persisted IDB function type must remain byte-for-byte text-equivalent to the row's current `func_profile` type. Hex-Rays may refresh immediately to the exact row-specific renamed decompiler prototype, and public `inspect_items` may return only the exact row-specific name-elided persisted/normalized form listed in that row. Any other persisted type, decompiler prototype, public type presentation, frame, comment, body, range, or xref result is a hard stop. The later I32-I42 `set_type` actions remain required and are not weakened by accepting these presentation-only rename-stage normalizations.

| ID | Exact literal prestate | Exact action | Exact deterministic poststate / next-stage prestate |
| --- | --- | --- | --- |
| I21 | Classification: apply; [0x004b7670,0x004b7685) `sub_4B7670`; persisted IDB type `bool __thiscall(_DWORD *this)`; decompiler `bool __thiscall sub_4B7670(_DWORD *this)`; public `inspect_items` type `bool __thiscall(_DWORD *this)`; frame `__return_address@0x0/4:_UNKNOWN *`; AR absent; AP absent; FR absent; FP absent; body SHA256 CC1ADFECB4B1B4900F002BD7789AFDC2A8A5A27CB34D388565E9754BFC66DA70; xrefs exactly 7 `{0x496cf6:code, 0x496e30:code, 0x497104:code, 0x49723e:code, 0x4c789d:code, 0x538ef5:code, 0x539435:code}`, more:false | `rename({database:"<fresh runtime-attested canonical session ID>",batch:{func:[{addr:"0x004b7670",name:"RectBounds__IsEmptyOrInvalid"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}})` | [0x004b7670,0x004b7685) `RectBounds__IsEmptyOrInvalid`; persisted IDB type remains `bool __thiscall(_DWORD *this)`; decompiler must be `bool __thiscall RectBounds__IsEmptyOrInvalid(_DWORD *this)`; public `inspect_items` type permitted set is exactly `{bool __thiscall(_DWORD *this)}`; frame/comments/body and exact 7-xref set remain unchanged. |
| I22 | Classification: apply; [0x004b76d0,0x004b76f8) `sub_4B76D0`; persisted IDB type `bool __thiscall(_DWORD *this, int, int)`; decompiler `bool __thiscall sub_4B76D0(_DWORD *this, int a2, int a3)`; public type `bool __thiscall(_DWORD *this, int, int)`; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; arg_0@0x8/4:_DWORD; arg_4@0xc/4:_DWORD`; AR absent; AP absent; FR absent; FP absent; body SHA256 3AAB471767B3F1109BDA8C17FD50891B1DFBC090E0CF1FB6BEA309CA310AE664; xrefs exactly 4 `{0x499df9:code, 0x4b2e00:code, 0x4b2e48:code, 0x4b39bf:code}`, more:false | `rename({database:"<fresh runtime-attested canonical session ID>",batch:{func:[{addr:"0x004b76d0",name:"RectBounds__ContainsPoint"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}})` | [0x004b76d0,0x004b76f8) `RectBounds__ContainsPoint`; persisted IDB type remains `bool __thiscall(_DWORD *this, int, int)`; decompiler must be `bool __thiscall RectBounds__ContainsPoint(_DWORD *this, int a2, int a3)`; public permitted set exactly `{bool __thiscall(_DWORD *this, int, int)}`; complete frame/comments/body and exact 4-xref set remain unchanged. |
| I23 | Classification: apply; [0x004b78d0,0x004b78ee) `sub_4B78D0`; persisted IDB type `int __thiscall(_DWORD *this, int, int, int, int)`; decompiler `int __thiscall sub_4B78D0(_DWORD *this, int a2, int a3, int a4, int a5)`; public type `int __thiscall(_DWORD *this, int, int, int, int)`; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; arg_0@0x8/4:_DWORD; arg_4@0xc/4:_DWORD; arg_8@0x10/4:_DWORD; arg_C@0x14/4:_DWORD`; AR absent; AP absent; FR absent; FP absent; body SHA256 98BA7875DEAD4691B1E62A6E502A194D10125F65841C18AEAB502D35A72A009A; xrefs exactly 208, manifest SHA256 94B9965401B5DACEB29BC7B28460565BCD5F34D641D4C318C01E1B1232D87679, more:false | `rename({database:"<fresh runtime-attested canonical session ID>",batch:{func:[{addr:"0x004b78d0",name:"RectBounds__SetLTRB"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}})` | [0x004b78d0,0x004b78ee) `RectBounds__SetLTRB`; persisted IDB type remains `int __thiscall(_DWORD *this, int, int, int, int)`; decompiler must be `int __thiscall RectBounds__SetLTRB(_DWORD *this, int a2, int a3, int a4, int a5)`; public permitted set exactly `{int __thiscall(_DWORD *this, int, int, int, int)}`; complete frame/comments/body and exact 208-xref manifest remain unchanged. |
| I24 | Classification: apply; [0x004b7910,0x004b795e) `sub_4B7910`; persisted IDB type `int __thiscall(int *this, int, int)`; decompiler `int __thiscall sub_4B7910(int *this, int a2, int a3)`; public type `int __thiscall(int *this, int, int)`; frame `__saved_registers@0xc/4:_DWORD; __return_address@0x10/4:_UNKNOWN *; arg_0@0x14/4:_DWORD; arg_4@0x18/4:_DWORD`; AR absent; AP absent; FR absent; FP absent; body SHA256 FEF40B7E2D1B870673A814D47DC3311EC6B7A5FBA057B70FDCA47405707BA0C9; xrefs exactly 3 `{0x53bcb7:code, 0x53bcd8:code, 0x53bcf9:code}`, more:false | `rename({database:"<fresh runtime-attested canonical session ID>",batch:{func:[{addr:"0x004b7910",name:"RectBounds__Inset"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}})` | [0x004b7910,0x004b795e) `RectBounds__Inset`; persisted IDB type remains `int __thiscall(int *this, int, int)`; decompiler must be `int __thiscall RectBounds__Inset(int *this, int a2, int a3)`; public permitted set exactly `{int __thiscall(int *this, int, int)}`; complete frame/comments/body and exact 3-xref set remain unchanged. |
| I25 | Classification: apply; [0x004b7a00,0x004b7a77) `sub_4B7A00`; persisted IDB type `_DWORD *__thiscall(_DWORD *this, int *)`; decompiler `int *__thiscall sub_4B7A00(int *this, int *a2)`; public type `_DWORD *__thiscall(_DWORD *this, int *)`; frame `var_4@0x8/4:_DWORD; __saved_registers@0xc/4:_DWORD; __return_address@0x10/4:_UNKNOWN *; arg_0@0x14/4:_DWORD`; AR absent; AP absent; FR absent; FP absent; body SHA256 8349772D4644A0481E2021C674B65A526220D165F705EF7013BAE3BD7E6E7F2D; xrefs exactly 33, manifest SHA256 051A654B00A2272C4300D209BC3504E90174DE06D9AC5D019EF0859048681F50, more:false | `rename({database:"<fresh runtime-attested canonical session ID>",batch:{func:[{addr:"0x004b7a00",name:"RectBounds__UnionWith"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}})` | [0x004b7a00,0x004b7a77) `RectBounds__UnionWith`; persisted IDB type remains `_DWORD *__thiscall(_DWORD *this, int *)`; decompiler must be `int *__thiscall RectBounds__UnionWith(int *this, int *a2)`; public permitted set exactly `{_DWORD *__thiscall(_DWORD *this, int *), int *__thiscall(int *this, int *)}`; complete frame/comments/body and exact 33-xref manifest remain unchanged. |
| I26 | Classification: apply; [0x004b7a80,0x004b7ae8) `sub_4B7A80`; persisted IDB type `int __thiscall(int *this, int, int, int, int)`; decompiler `int __thiscall sub_4B7A80(int *this, int a2, int a3, int a4, int a5)`; public type `int __thiscall(int *this, int, int, int, int)`; frame `__saved_registers@0x8/4:_DWORD; __return_address@0xc/4:_UNKNOWN *; arg_0@0x10/4:_DWORD; arg_4@0x14/4:_DWORD; arg_8@0x18/4:_DWORD; arg_C@0x1c/4:_DWORD`; AR absent; AP absent; FR absent; FP absent; body SHA256 E00162FFCF7A7802134C247A60681CA9F29D1E1815696636E223671B445D1588; xrefs exactly 2 `{0x5c3767:code, 0x5c37c9:code}`, more:false | `rename({database:"<fresh runtime-attested canonical session ID>",batch:{func:[{addr:"0x004b7a80",name:"RectBounds__ClampWithin"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}})` | [0x004b7a80,0x004b7ae8) `RectBounds__ClampWithin`; persisted IDB type remains `int __thiscall(int *this, int, int, int, int)`; decompiler must be `int __thiscall RectBounds__ClampWithin(int *this, int a2, int a3, int a4, int a5)`; public permitted set exactly `{int __thiscall(int *this, int, int, int, int)}`; complete frame/comments/body and exact 2-xref set remain unchanged. |
| I27 | Classification: apply; [0x004b7c70,0x004b7c95) `sub_4B7C70`; persisted IDB type `int __cdecl(_DWORD *, int, int, int, int)`; decompiler `int __cdecl sub_4B7C70(_DWORD *a1, int a2, int a3, int a4, int a5)`; public type `int __cdecl(_DWORD *, int, int, int, int)`; frame `__saved_registers@0x4/4:_DWORD; __return_address@0x8/4:_UNKNOWN *; arg_0@0xc/4:_DWORD; arg_4@0x10/4:_DWORD; arg_8@0x14/4:_DWORD; arg_C@0x18/4:_DWORD; arg_10@0x1c/4:_DWORD`; AR absent; AP absent; FR absent; FP absent; body SHA256 E3FEB5168886A48FD06A13AEEB62B4FB0F502ACEEBE1496F749FEF32DC53B310; xrefs exactly 38, manifest SHA256 5C1CD35B479E4A1208282FDF2922E4FEE64B51A29F0C882A4F2CE9AE385ED8E0, more:false | `rename({database:"<fresh runtime-attested canonical session ID>",batch:{func:[{addr:"0x004b7c70",name:"InitRectBoundsFromSize"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}})` | [0x004b7c70,0x004b7c95) `InitRectBoundsFromSize`; persisted IDB type remains `int __cdecl(_DWORD *, int, int, int, int)`; decompiler must be `int __cdecl InitRectBoundsFromSize(_DWORD *a1, int a2, int a3, int a4, int a5)`; public permitted set exactly `{int __cdecl(_DWORD *, int, int, int, int)}`; complete frame/comments/body and exact 38-xref manifest remain unchanged. |
| I28 | Classification: apply; [0x004b7ca0,0x004b7cb6) `sub_4B7CA0`; persisted IDB type `int __cdecl(_DWORD *)`; decompiler `int __cdecl sub_4B7CA0(_DWORD *a1)`; public type `int __cdecl(_DWORD *)`; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; arg_0@0x8/4:_DWORD`; AR absent; AP absent; FR absent; FP absent; body SHA256 163710594CCDDC680B855D28D4CDD027E1EDF64AD557EBB23225C51A41ACBB68; xrefs exactly 4 `{0x4580de:code, 0x4581da:code, 0x45833d:code, 0x4b621a:code}`, more:false | `rename({database:"<fresh runtime-attested canonical session ID>",batch:{func:[{addr:"0x004b7ca0",name:"RectArea"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}})` | [0x004b7ca0,0x004b7cb6) `RectArea`; persisted IDB type remains `int __cdecl(_DWORD *)`; decompiler must be `int __cdecl RectArea(_DWORD *a1)`; public permitted set exactly `{int __cdecl(_DWORD *)}`; complete frame/comments/body and exact 4-xref set remain unchanged. |
| I29 | Classification: apply; [0x004b7e30,0x004b7e7f) `sub_4B7E30`; persisted IDB type `int __cdecl(int *, int, int)`; decompiler `int __cdecl sub_4B7E30(int *a1, int a2, int a3)`; public type `int __cdecl(int *, int, int)`; frame `__saved_registers@0xc/4:_DWORD; __return_address@0x10/4:_UNKNOWN *; arg_0@0x14/4:_DWORD; arg_4@0x18/4:_DWORD; arg_8@0x1c/4:_DWORD`; AR absent; AP absent; FR absent; FP absent; body SHA256 A81AC6D7E55C4D42090AF94E22F93F4F1136229BE2E83DDF4CA74765512FB102; xrefs exactly 32, manifest SHA256 362626B99F1F93514ED611E889B3B16E221606FCD8F88CABB50E586A009149E1, more:false | `rename({database:"<fresh runtime-attested canonical session ID>",batch:{func:[{addr:"0x004b7e30",name:"InsetRect"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}})` | [0x004b7e30,0x004b7e7f) `InsetRect`; persisted IDB type remains `int __cdecl(int *, int, int)`; decompiler must be `int __cdecl InsetRect(int *a1, int a2, int a3)`; public permitted set exactly `{int __cdecl(int *, int, int)}`; complete frame/comments/body and exact 32-xref manifest remain unchanged. |
| I30 | Classification: apply; [0x004b7f30,0x004b7f87) `sub_4B7F30`; persisted IDB type `bool __cdecl(_DWORD *, _DWORD *)`; decompiler `bool __cdecl sub_4B7F30(_DWORD *a1, _DWORD *a2)`; public type `bool __cdecl(_DWORD *, _DWORD *)`; frame `__saved_registers@0x8/4:_DWORD; __return_address@0xc/4:_UNKNOWN *; arg_0@0x10/4:_DWORD; arg_4@0x14/4:_DWORD`; AR absent; AP absent; FR absent; FP absent; body SHA256 24A3CF15F60046C64256E895BF3CF0804F1775FBFAC06C39633A1065B11481D5; xrefs exactly 2 `{0x554a4a:code, 0x554a83:code}`, more:false | `rename({database:"<fresh runtime-attested canonical session ID>",batch:{func:[{addr:"0x004b7f30",name:"RectContainsRect"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}})` | [0x004b7f30,0x004b7f87) `RectContainsRect`; persisted IDB type remains `bool __cdecl(_DWORD *, _DWORD *)`; decompiler must be `bool __cdecl RectContainsRect(_DWORD *a1, _DWORD *a2)`; public permitted set exactly `{bool __cdecl(_DWORD *, _DWORD *)}`; complete frame/comments/body and exact 2-xref set remain unchanged. |
| I31 | Classification: apply; [0x004b8290,0x004b83ae) `sub_4B8290`; persisted IDB type `int *__cdecl(int *, int, int *, int *, int *, int *)`; decompiler `int *__cdecl sub_4B8290(int *a1, int a2, int *a3, int *a4, int *a5, int *a6)`; public type `int *__cdecl(int *, int, int *, int *, int *, int *)`; frame `var_10@0xc/4:_DWORD; var_C@0x10/4:_DWORD; var_8@0x14/4:_DWORD; var_4@0x18/4:_DWORD; __saved_registers@0x1c/4:_DWORD; __return_address@0x20/4:_UNKNOWN *; arg_0@0x24/4:_DWORD; arg_4@0x28/4:_DWORD; arg_8@0x2c/4:_DWORD; arg_C@0x30/4:_DWORD; arg_10@0x34/4:_DWORD; arg_14@0x38/4:_DWORD`; AR absent; AP absent; FR absent; FP absent; body SHA256 2AEC81E39738637C5E9B1D3D0AA050D26BBA66F59590867E105CAB965F6B0D16; xrefs exactly 4 `{0x4b803e:code, 0x4b809f:code, 0x4b80ff:code, 0x4b8161:code}`, more:false | `rename({database:"<fresh runtime-attested canonical session ID>",batch:{func:[{addr:"0x004b8290",name:"AdjustRectAnchorAxis"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}})` | [0x004b8290,0x004b83ae) `AdjustRectAnchorAxis`; persisted IDB type remains `int *__cdecl(int *, int, int *, int *, int *, int *)`; decompiler must be `int *__cdecl AdjustRectAnchorAxis(int *a1, int a2, int *a3, int *a4, int *a5, int *a6)`; public permitted set exactly `{int *__cdecl(int *, int, int *, int *, int *, int *)}`; complete frame/comments/body and exact 4-xref set remain unchanged. |

### Authoritative function-type stages I32-I42

The `type` field in each I32-I42 action row is the exact persisted IDB function type, not an assertion that Hex-Rays or `inspect_items` must print the same spelling after pure rename. The following item-specific presentation preconditions complete each corresponding row before `set_type`; they are mandatory and do not replace any range/name/frame/comment/body/xref field in the action table.

| Type row | Required rename-stage persisted IDB type | Required exact Hex-Rays prototype | Exact permitted public `inspect_items` type set |
| --- | --- | --- | --- |
| I32 | `bool __thiscall(_DWORD *this)` | `bool __thiscall RectBounds__IsEmptyOrInvalid(_DWORD *this)` | `{bool __thiscall(_DWORD *this)}` |
| I33 | `bool __thiscall(_DWORD *this, int, int)` | `bool __thiscall RectBounds__ContainsPoint(_DWORD *this, int a2, int a3)` | `{bool __thiscall(_DWORD *this, int, int)}` |
| I34 | `int __thiscall(_DWORD *this, int, int, int, int)` | `int __thiscall RectBounds__SetLTRB(_DWORD *this, int a2, int a3, int a4, int a5)` | `{int __thiscall(_DWORD *this, int, int, int, int)}` |
| I35 | `int __thiscall(int *this, int, int)` | `int __thiscall RectBounds__Inset(int *this, int a2, int a3)` | `{int __thiscall(int *this, int, int)}` |
| I36 | `_DWORD *__thiscall(_DWORD *this, int *)` | `int *__thiscall RectBounds__UnionWith(int *this, int *a2)` | `{_DWORD *__thiscall(_DWORD *this, int *), int *__thiscall(int *this, int *)}` |
| I37 | `int __thiscall(int *this, int, int, int, int)` | `int __thiscall RectBounds__ClampWithin(int *this, int a2, int a3, int a4, int a5)` | `{int __thiscall(int *this, int, int, int, int)}` |
| I38 | `int __cdecl(_DWORD *, int, int, int, int)` | `int __cdecl InitRectBoundsFromSize(_DWORD *a1, int a2, int a3, int a4, int a5)` | `{int __cdecl(_DWORD *, int, int, int, int)}` |
| I39 | `int __cdecl(_DWORD *)` | `int __cdecl RectArea(_DWORD *a1)` | `{int __cdecl(_DWORD *)}` |
| I40 | `int __cdecl(int *, int, int)` | `int __cdecl InsetRect(int *a1, int a2, int a3)` | `{int __cdecl(int *, int, int)}` |
| I41 | `bool __cdecl(_DWORD *, _DWORD *)` | `bool __cdecl RectContainsRect(_DWORD *a1, _DWORD *a2)` | `{bool __cdecl(_DWORD *, _DWORD *)}` |
| I42 | `int *__cdecl(int *, int, int *, int *, int *, int *)` | `int *__cdecl AdjustRectAnchorAxis(int *a1, int a2, int *a3, int *a4, int *a5, int *a6)` | `{int *__cdecl(int *, int, int *, int *, int *, int *)}` |

If persisted type, decompiler prototype, or public presentation is outside the exact corresponding row above, the supervisor must stop before I32-I42 rather than treating the rename as a type action. If all three match, the exact source-quality `set_type` request and complete post-type frame in I32-I42 remain mandatory.

| ID | Exact literal prestate after rename | Exact action | Exact deterministic poststate / comment-stage prestate |
| --- | --- | --- | --- |
| I32 | Classification: apply; [0x004b7670,0x004b7685) `RectBounds__IsEmptyOrInvalid`; type `bool __thiscall(_DWORD *this)`; frame `__return_address@0x0/4:_UNKNOWN *`; AR absent; AP absent; FR absent; FP absent; body SHA256 CC1ADFECB4B1B4900F002BD7789AFDC2A8A5A27CB34D388565E9754BFC66DA70; xrefs exactly 7 `{0x496cf6:code, 0x496e30:code, 0x497104:code, 0x49723e:code, 0x4c789d:code, 0x538ef5:code, 0x539435:code}`, more:false | `set_type({database:"<fresh runtime-attested canonical session ID>",edits:[{addr:"0x004b7670",kind:"function",signature:"bool __thiscall RectBounds__IsEmptyOrInvalid(const RectBounds *this)"}]})` | [0x004b7670,0x004b7685) `RectBounds__IsEmptyOrInvalid`; type `bool __thiscall RectBounds__IsEmptyOrInvalid(const RectBounds *this)`; frame `__return_address@0x0/4:_UNKNOWN *`; AR absent; AP absent; FR absent; FP absent; body SHA256 CC1ADFECB4B1B4900F002BD7789AFDC2A8A5A27CB34D388565E9754BFC66DA70; xrefs exactly 7 `{0x496cf6:code, 0x496e30:code, 0x497104:code, 0x49723e:code, 0x4c789d:code, 0x538ef5:code, 0x539435:code}`, more:false. |
| I33 | Classification: apply; [0x004b76d0,0x004b76f8) `RectBounds__ContainsPoint`; type `bool __thiscall(_DWORD *this, int, int)`; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; arg_0@0x8/4:_DWORD; arg_4@0xc/4:_DWORD`; AR absent; AP absent; FR absent; FP absent; body SHA256 3AAB471767B3F1109BDA8C17FD50891B1DFBC090E0CF1FB6BEA309CA310AE664; xrefs exactly 4 `{0x499df9:code, 0x4b2e00:code, 0x4b2e48:code, 0x4b39bf:code}`, more:false | `set_type({database:"<fresh runtime-attested canonical session ID>",edits:[{addr:"0x004b76d0",kind:"function",signature:"bool __thiscall RectBounds__ContainsPoint(const RectBounds *this, int y, int x)"}]})` | [0x004b76d0,0x004b76f8) `RectBounds__ContainsPoint`; type `bool __thiscall RectBounds__ContainsPoint(const RectBounds *this, int y, int x)`; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; y@0x8/4:int; x@0xc/4:int`; AR absent; AP absent; FR absent; FP absent; body SHA256 3AAB471767B3F1109BDA8C17FD50891B1DFBC090E0CF1FB6BEA309CA310AE664; xrefs exactly 4 `{0x499df9:code, 0x4b2e00:code, 0x4b2e48:code, 0x4b39bf:code}`, more:false. |
| I34 | Classification: apply; [0x004b78d0,0x004b78ee) `RectBounds__SetLTRB`; type `int __thiscall(_DWORD *this, int, int, int, int)`; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; arg_0@0x8/4:_DWORD; arg_4@0xc/4:_DWORD; arg_8@0x10/4:_DWORD; arg_C@0x14/4:_DWORD`; AR absent; AP absent; FR absent; FP absent; body SHA256 98BA7875DEAD4691B1E62A6E502A194D10125F65841C18AEAB502D35A72A009A; xrefs exactly 208, canonical manifest SHA256 94B9965401B5DACEB29BC7B28460565BCD5F34D641D4C318C01E1B1232D87679, more:false | `set_type({database:"<fresh runtime-attested canonical session ID>",edits:[{addr:"0x004b78d0",kind:"function",signature:"void __thiscall RectBounds__SetLTRB(RectBounds *this, int leftValue, int topValue, int rightValue, int bottomValue)"}]})` | [0x004b78d0,0x004b78ee) `RectBounds__SetLTRB`; type `void __thiscall RectBounds__SetLTRB(RectBounds *this, int leftValue, int topValue, int rightValue, int bottomValue)`; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; leftValue@0x8/4:int; topValue@0xc/4:int; rightValue@0x10/4:int; bottomValue@0x14/4:int`; AR absent; AP absent; FR absent; FP absent; body SHA256 98BA7875DEAD4691B1E62A6E502A194D10125F65841C18AEAB502D35A72A009A; xrefs exactly 208, canonical manifest SHA256 94B9965401B5DACEB29BC7B28460565BCD5F34D641D4C318C01E1B1232D87679, more:false. |
| I35 | Classification: apply; [0x004b7910,0x004b795e) `RectBounds__Inset`; type `int __thiscall(int *this, int, int)`; frame `__saved_registers@0xc/4:_DWORD; __return_address@0x10/4:_UNKNOWN *; arg_0@0x14/4:_DWORD; arg_4@0x18/4:_DWORD`; AR absent; AP absent; FR absent; FP absent; body SHA256 FEF40B7E2D1B870673A814D47DC3311EC6B7A5FBA057B70FDCA47405707BA0C9; xrefs exactly 3 `{0x53bcb7:code, 0x53bcd8:code, 0x53bcf9:code}`, more:false | `set_type({database:"<fresh runtime-attested canonical session ID>",edits:[{addr:"0x004b7910",kind:"function",signature:"void __thiscall RectBounds__Inset(RectBounds *this, int dx, int dy)"}]})` | [0x004b7910,0x004b795e) `RectBounds__Inset`; type `void __thiscall RectBounds__Inset(RectBounds *this, int dx, int dy)`; frame `__saved_registers@0xc/4:_DWORD; __return_address@0x10/4:_UNKNOWN *; dx@0x14/4:int; dy@0x18/4:int`; AR absent; AP absent; FR absent; FP absent; body SHA256 FEF40B7E2D1B870673A814D47DC3311EC6B7A5FBA057B70FDCA47405707BA0C9; xrefs exactly 3 `{0x53bcb7:code, 0x53bcd8:code, 0x53bcf9:code}`, more:false. |
| I36 | Classification: apply; [0x004b7a00,0x004b7a77) `RectBounds__UnionWith`; type `_DWORD *__thiscall(_DWORD *this, int *)`; frame `var_4@0x8/4:_DWORD; __saved_registers@0xc/4:_DWORD; __return_address@0x10/4:_UNKNOWN *; arg_0@0x14/4:_DWORD`; AR absent; AP absent; FR absent; FP absent; body SHA256 8349772D4644A0481E2021C674B65A526220D165F705EF7013BAE3BD7E6E7F2D; xrefs exactly 33, canonical manifest SHA256 051A654B00A2272C4300D209BC3504E90174DE06D9AC5D019EF0859048681F50, more:false | `set_type({database:"<fresh runtime-attested canonical session ID>",edits:[{addr:"0x004b7a00",kind:"function",signature:"RectBounds *__thiscall RectBounds__UnionWith(RectBounds *this, const RectBounds *bounds)"}]})` | [0x004b7a00,0x004b7a77) `RectBounds__UnionWith`; type `RectBounds *__thiscall RectBounds__UnionWith(RectBounds *this, const RectBounds *bounds)`; frame `var_4@0x8/4:_DWORD; __saved_registers@0xc/4:_DWORD; __return_address@0x10/4:_UNKNOWN *; bounds@0x14/4:const RectBounds *`; AR absent; AP absent; FR absent; FP absent; body SHA256 8349772D4644A0481E2021C674B65A526220D165F705EF7013BAE3BD7E6E7F2D; xrefs exactly 33, canonical manifest SHA256 051A654B00A2272C4300D209BC3504E90174DE06D9AC5D019EF0859048681F50, more:false. |
| I37 | Classification: apply; [0x004b7a80,0x004b7ae8) `RectBounds__ClampWithin`; type `int __thiscall(int *this, int, int, int, int)`; frame `__saved_registers@0x8/4:_DWORD; __return_address@0xc/4:_UNKNOWN *; arg_0@0x10/4:_DWORD; arg_4@0x14/4:_DWORD; arg_8@0x18/4:_DWORD; arg_C@0x1c/4:_DWORD`; AR absent; AP absent; FR absent; FP absent; body SHA256 E00162FFCF7A7802134C247A60681CA9F29D1E1815696636E223671B445D1588; xrefs exactly 2 `{0x5c3767:code, 0x5c37c9:code}`, more:false | `set_type({database:"<fresh runtime-attested canonical session ID>",edits:[{addr:"0x004b7a80",kind:"function",signature:"void __thiscall RectBounds__ClampWithin(RectBounds *this, int leftLimit, int topLimit, int rightLimit, int bottomLimit)"}]})` | [0x004b7a80,0x004b7ae8) `RectBounds__ClampWithin`; type `void __thiscall RectBounds__ClampWithin(RectBounds *this, int leftLimit, int topLimit, int rightLimit, int bottomLimit)`; frame `__saved_registers@0x8/4:_DWORD; __return_address@0xc/4:_UNKNOWN *; leftLimit@0x10/4:int; topLimit@0x14/4:int; rightLimit@0x18/4:int; bottomLimit@0x1c/4:int`; AR absent; AP absent; FR absent; FP absent; body SHA256 E00162FFCF7A7802134C247A60681CA9F29D1E1815696636E223671B445D1588; xrefs exactly 2 `{0x5c3767:code, 0x5c37c9:code}`, more:false. |
| I38 | Classification: apply; [0x004b7c70,0x004b7c95) `InitRectBoundsFromSize`; type `int __cdecl(_DWORD *, int, int, int, int)`; frame `__saved_registers@0x4/4:_DWORD; __return_address@0x8/4:_UNKNOWN *; arg_0@0xc/4:_DWORD; arg_4@0x10/4:_DWORD; arg_8@0x14/4:_DWORD; arg_C@0x18/4:_DWORD; arg_10@0x1c/4:_DWORD`; AR absent; AP absent; FR absent; FP absent; body SHA256 E3FEB5168886A48FD06A13AEEB62B4FB0F502ACEEBE1496F749FEF32DC53B310; xrefs exactly 38, canonical manifest SHA256 5C1CD35B479E4A1208282FDF2922E4FEE64B51A29F0C882A4F2CE9AE385ED8E0, more:false | `set_type({database:"<fresh runtime-attested canonical session ID>",edits:[{addr:"0x004b7c70",kind:"function",signature:"void __cdecl InitRectBoundsFromSize(RectBounds *bounds, int left, int top, int width, int height)"}]})` | [0x004b7c70,0x004b7c95) `InitRectBoundsFromSize`; type `void __cdecl InitRectBoundsFromSize(RectBounds *bounds, int left, int top, int width, int height)`; frame `__saved_registers@0x4/4:_DWORD; __return_address@0x8/4:_UNKNOWN *; bounds@0xc/4:RectBounds *; left@0x10/4:int; top@0x14/4:int; width@0x18/4:int; height@0x1c/4:int`; AR absent; AP absent; FR absent; FP absent; body SHA256 E3FEB5168886A48FD06A13AEEB62B4FB0F502ACEEBE1496F749FEF32DC53B310; xrefs exactly 38, canonical manifest SHA256 5C1CD35B479E4A1208282FDF2922E4FEE64B51A29F0C882A4F2CE9AE385ED8E0, more:false. |
| I39 | Classification: apply; [0x004b7ca0,0x004b7cb6) `RectArea`; type `int __cdecl(_DWORD *)`; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; arg_0@0x8/4:_DWORD`; AR absent; AP absent; FR absent; FP absent; body SHA256 163710594CCDDC680B855D28D4CDD027E1EDF64AD557EBB23225C51A41ACBB68; xrefs exactly 4 `{0x4580de:code, 0x4581da:code, 0x45833d:code, 0x4b621a:code}`, more:false | `set_type({database:"<fresh runtime-attested canonical session ID>",edits:[{addr:"0x004b7ca0",kind:"function",signature:"int __cdecl RectArea(const RectBounds *bounds)"}]})` | [0x004b7ca0,0x004b7cb6) `RectArea`; type `int __cdecl RectArea(const RectBounds *bounds)`; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; bounds@0x8/4:const RectBounds *`; AR absent; AP absent; FR absent; FP absent; body SHA256 163710594CCDDC680B855D28D4CDD027E1EDF64AD557EBB23225C51A41ACBB68; xrefs exactly 4 `{0x4580de:code, 0x4581da:code, 0x45833d:code, 0x4b621a:code}`, more:false. |
| I40 | Classification: apply; [0x004b7e30,0x004b7e7f) `InsetRect`; type `int __cdecl(int *, int, int)`; frame `__saved_registers@0xc/4:_DWORD; __return_address@0x10/4:_UNKNOWN *; arg_0@0x14/4:_DWORD; arg_4@0x18/4:_DWORD; arg_8@0x1c/4:_DWORD`; AR absent; AP absent; FR absent; FP absent; body SHA256 A81AC6D7E55C4D42090AF94E22F93F4F1136229BE2E83DDF4CA74765512FB102; xrefs exactly 32, canonical manifest SHA256 362626B99F1F93514ED611E889B3B16E221606FCD8F88CABB50E586A009149E1, more:false | `set_type({database:"<fresh runtime-attested canonical session ID>",edits:[{addr:"0x004b7e30",kind:"function",signature:"void __cdecl InsetRect(RectBounds *bounds, int dx, int dy)"}]})` | [0x004b7e30,0x004b7e7f) `InsetRect`; type `void __cdecl InsetRect(RectBounds *bounds, int dx, int dy)`; frame `__saved_registers@0xc/4:_DWORD; __return_address@0x10/4:_UNKNOWN *; bounds@0x14/4:RectBounds *; dx@0x18/4:int; dy@0x1c/4:int`; AR absent; AP absent; FR absent; FP absent; body SHA256 A81AC6D7E55C4D42090AF94E22F93F4F1136229BE2E83DDF4CA74765512FB102; xrefs exactly 32, canonical manifest SHA256 362626B99F1F93514ED611E889B3B16E221606FCD8F88CABB50E586A009149E1, more:false. |
| I41 | Classification: apply; [0x004b7f30,0x004b7f87) `RectContainsRect`; type `bool __cdecl(_DWORD *, _DWORD *)`; frame `__saved_registers@0x8/4:_DWORD; __return_address@0xc/4:_UNKNOWN *; arg_0@0x10/4:_DWORD; arg_4@0x14/4:_DWORD`; AR absent; AP absent; FR absent; FP absent; body SHA256 24A3CF15F60046C64256E895BF3CF0804F1775FBFAC06C39633A1065B11481D5; xrefs exactly 2 `{0x554a4a:code, 0x554a83:code}`, more:false | `set_type({database:"<fresh runtime-attested canonical session ID>",edits:[{addr:"0x004b7f30",kind:"function",signature:"bool __cdecl RectContainsRect(const RectBounds *innerBounds, const RectBounds *outerBounds)"}]})` | [0x004b7f30,0x004b7f87) `RectContainsRect`; type `bool __cdecl RectContainsRect(const RectBounds *innerBounds, const RectBounds *outerBounds)`; frame `__saved_registers@0x8/4:_DWORD; __return_address@0xc/4:_UNKNOWN *; innerBounds@0x10/4:const RectBounds *; outerBounds@0x14/4:const RectBounds *`; AR absent; AP absent; FR absent; FP absent; body SHA256 24A3CF15F60046C64256E895BF3CF0804F1775FBFAC06C39633A1065B11481D5; xrefs exactly 2 `{0x554a4a:code, 0x554a83:code}`, more:false. |
| I42 | Classification: apply; [0x004b8290,0x004b83ae) `AdjustRectAnchorAxis`; type `int *__cdecl(int *, int, int *, int *, int *, int *)`; frame `var_10@0xc/4:_DWORD; var_C@0x10/4:_DWORD; var_8@0x14/4:_DWORD; var_4@0x18/4:_DWORD; __saved_registers@0x1c/4:_DWORD; __return_address@0x20/4:_UNKNOWN *; arg_0@0x24/4:_DWORD; arg_4@0x28/4:_DWORD; arg_8@0x2c/4:_DWORD; arg_C@0x30/4:_DWORD; arg_10@0x34/4:_DWORD; arg_14@0x38/4:_DWORD`; AR absent; AP absent; FR absent; FP absent; body SHA256 2AEC81E39738637C5E9B1D3D0AA050D26BBA66F59590867E105CAB965F6B0D16; xrefs exactly 4 `{0x4b803e:code, 0x4b809f:code, 0x4b80ff:code, 0x4b8161:code}`, more:false | `set_type({database:"<fresh runtime-attested canonical session ID>",edits:[{addr:"0x004b8290",kind:"function",signature:"void __cdecl AdjustRectAnchorAxis(int anchor, int offset, int *firstLow, int *firstHigh, int *secondLow, int *secondHigh)"}]})` | [0x004b8290,0x004b83ae) `AdjustRectAnchorAxis`; type `void __cdecl AdjustRectAnchorAxis(int anchor, int offset, int *firstLow, int *firstHigh, int *secondLow, int *secondHigh)`; frame `var_10@0xc/4:_DWORD; var_C@0x10/4:_DWORD; var_8@0x14/4:_DWORD; var_4@0x18/4:_DWORD; __saved_registers@0x1c/4:_DWORD; __return_address@0x20/4:_UNKNOWN *; anchor@0x24/4:int; offset@0x28/4:int; firstLow@0x2c/4:int *; firstHigh@0x30/4:int *; secondLow@0x34/4:int *; secondHigh@0x38/4:int *`; AR absent; AP absent; FR absent; FP absent; body SHA256 2AEC81E39738637C5E9B1D3D0AA050D26BBA66F59590867E105CAB965F6B0D16; xrefs exactly 4 `{0x4b803e:code, 0x4b809f:code, 0x4b80ff:code, 0x4b8161:code}`, more:false. |

The function-type rows state complete post-type frames. Every local, saved-register row, return-address row, offset and width is protected; only the listed generic argument rows may become the source-named/type rows shown in that row's expected readback. Any omitted, additional or differently normalized delta fails closed before save. I64-I66 are separate row-local corrections for the already source-typed `PointInRect` frame.

### Exact repeatable-comment stages

I43-I52 run after the corresponding I11T-I20T type stages. Each row independently repeats the complete final function state and changes only the function-repeatable comment. I53-I63 run after their modeled-function rename/type dependencies. Every row independently repeats its literal range, final name/type, complete frame, four channel prestates, body hash, terminal exact xref identity, action, full expected readback, and protected state; no dependency shorthand supplies a missing field.

| ID | Exact prestate | Exact action or disposition | Expected readback |
| --- | --- | --- | --- |
| I43 | Classification: apply; [0x004b7690,0x004b76c8) `RectBounds__HasSameSizeAs`; type `bool __thiscall RectBounds__HasSameSizeAs(const RectBounds *this, const RectBounds *bounds)`; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; bounds@0x8/4:const RectBounds *`; AR absent; AP absent; FR absent; FP absent; body SHA256 F5390A22C1B14C8FCF33BADB759A2C6DAF0457BDB5BA1904C21B2AC6AE40F7F4; xrefs exactly `{}`; boundaries `cc` [0x004b7685,0x004b7690) and [0x004b76c8,0x004b76d0) | `set_repeatable_comments({database:"<fresh runtime-attested canonical session ID>",items:[{addr:"0x004b7690",comment:"Source-facing RectBounds::HasSameSizeAs; compares signed width and height spans."}]})` | [0x004b7690,0x004b76c8) `RectBounds__HasSameSizeAs`; type `bool __thiscall RectBounds__HasSameSizeAs(const RectBounds *this, const RectBounds *bounds)`; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; bounds@0x8/4:const RectBounds *`; AR absent; AP absent; FR absent; FP exactly `Source-facing RectBounds::HasSameSizeAs; compares signed width and height spans.`; body SHA256 F5390A22C1B14C8FCF33BADB759A2C6DAF0457BDB5BA1904C21B2AC6AE40F7F4; xrefs exactly `{}`; boundaries remain `cc` [0x004b7685,0x004b7690) and [0x004b76c8,0x004b76d0); every unlisted field protected. |
| I44 | Classification: apply; [0x004b7700,0x004b7775) `RectBounds__ContainsRect`; type `bool __thiscall RectBounds__ContainsRect(const RectBounds *this, const RectBounds *bounds)`; frame `__saved_registers@0x14/4:_DWORD; __return_address@0x18/4:_UNKNOWN *; bounds@0x1c/4:const RectBounds *`; AR absent; AP absent; FR absent; FP absent; body SHA256 A86D0E0E4F5585EC031315B115FFDEAF6EE2FC55A05BB3F01B49E2E65D0ECD8E; xrefs exactly `{}`; boundaries `cc` [0x004b76f8,0x004b7700) and [0x004b7775,0x004b7780) | `set_repeatable_comments({database:"<fresh runtime-attested canonical session ID>",items:[{addr:"0x004b7700",comment:"Source-facing RectBounds::ContainsRect; empty input succeeds, otherwise this rectangle must contain all four edges."}]})` | [0x004b7700,0x004b7775) `RectBounds__ContainsRect`; type `bool __thiscall RectBounds__ContainsRect(const RectBounds *this, const RectBounds *bounds)`; frame `__saved_registers@0x14/4:_DWORD; __return_address@0x18/4:_UNKNOWN *; bounds@0x1c/4:const RectBounds *`; AR absent; AP absent; FR absent; FP exactly `Source-facing RectBounds::ContainsRect; empty input succeeds, otherwise this rectangle must contain all four edges.`; body SHA256 A86D0E0E4F5585EC031315B115FFDEAF6EE2FC55A05BB3F01B49E2E65D0ECD8E; xrefs exactly `{}`; boundaries remain `cc` [0x004b76f8,0x004b7700) and [0x004b7775,0x004b7780); every unlisted field protected. |
| I45 | Classification: apply; [0x004b7780,0x004b782a) `RectBounds__IntersectInto`; type `bool __thiscall RectBounds__IntersectInto(const RectBounds *this, const RectBounds *bounds, RectBounds *outBounds)`; frame `__saved_registers@0x24/4:_DWORD; __return_address@0x28/4:_UNKNOWN *; bounds@0x2c/4:const RectBounds *; outBounds@0x30/4:RectBounds *`; AR absent; AP absent; FR absent; FP absent; body SHA256 7AE269077D1C4C3E0D613B86878052616C32829EF015B00A95EF2B63543699EE; xrefs exactly `{}`; boundaries `cc` [0x004b7775,0x004b7780) and [0x004b782a,0x004b7830) | `set_repeatable_comments({database:"<fresh runtime-attested canonical session ID>",items:[{addr:"0x004b7780",comment:"Source-facing RectBounds::IntersectInto; writes a non-empty intersection when requested and clears output on failure."}]})` | [0x004b7780,0x004b782a) `RectBounds__IntersectInto`; type `bool __thiscall RectBounds__IntersectInto(const RectBounds *this, const RectBounds *bounds, RectBounds *outBounds)`; frame `__saved_registers@0x24/4:_DWORD; __return_address@0x28/4:_UNKNOWN *; bounds@0x2c/4:const RectBounds *; outBounds@0x30/4:RectBounds *`; AR absent; AP absent; FR absent; FP exactly `Source-facing RectBounds::IntersectInto; writes a non-empty intersection when requested and clears output on failure.`; body SHA256 7AE269077D1C4C3E0D613B86878052616C32829EF015B00A95EF2B63543699EE; xrefs exactly `{}`; boundaries remain `cc` [0x004b7775,0x004b7780) and [0x004b782a,0x004b7830); every unlisted field protected. |
| I46 | Classification: apply; [0x004b7830,0x004b78c8) `RectBounds__UnionInto`; type `void __thiscall RectBounds__UnionInto(const RectBounds *this, const RectBounds *bounds, RectBounds *outBounds)`; frame `__saved_registers@0x14/4:_DWORD; __return_address@0x18/4:_UNKNOWN *; bounds@0x1c/4:const RectBounds *; outBounds@0x20/4:RectBounds *`; AR absent; AP absent; FR absent; FP absent; body SHA256 4D329ABFFF21BB0DDCDB23C9B5FB3B3972B5F4A5BBA8300B589145A0C66FB229; xrefs exactly `{}`; boundaries `cc` [0x004b782a,0x004b7830) and [0x004b78c8,0x004b78d0) | `set_repeatable_comments({database:"<fresh runtime-attested canonical session ID>",items:[{addr:"0x004b7830",comment:"Source-facing RectBounds::UnionInto; copies the non-empty operand or writes the four-edge bounding union."}]})` | [0x004b7830,0x004b78c8) `RectBounds__UnionInto`; type `void __thiscall RectBounds__UnionInto(const RectBounds *this, const RectBounds *bounds, RectBounds *outBounds)`; frame `__saved_registers@0x14/4:_DWORD; __return_address@0x18/4:_UNKNOWN *; bounds@0x1c/4:const RectBounds *; outBounds@0x20/4:RectBounds *`; AR absent; AP absent; FR absent; FP exactly `Source-facing RectBounds::UnionInto; copies the non-empty operand or writes the four-edge bounding union.`; body SHA256 4D329ABFFF21BB0DDCDB23C9B5FB3B3972B5F4A5BBA8300B589145A0C66FB229; xrefs exactly `{}`; boundaries remain `cc` [0x004b782a,0x004b7830) and [0x004b78c8,0x004b78d0); every unlisted field protected. |
| I47 | Classification: apply; [0x004b7960,0x004b79f7) `RectBounds__IntersectWith`; type `bool __thiscall RectBounds__IntersectWith(RectBounds *this, const RectBounds *bounds)`; frame `__saved_registers@0x20/4:_DWORD; __return_address@0x24/4:_UNKNOWN *; bounds@0x28/4:const RectBounds *`; AR absent; AP absent; FR absent; FP absent; body SHA256 B30A96040C9354609990CAAB536DA058418CEE87E0056D7859338DEC25B89141; xrefs exactly `{}`; boundaries `cc` [0x004b795e,0x004b7960) and [0x004b79f7,0x004b7a00) | `set_repeatable_comments({database:"<fresh runtime-attested canonical session ID>",items:[{addr:"0x004b7960",comment:"Source-facing RectBounds::IntersectWith; mutates this to the non-empty intersection and clears it on failure."}]})` | [0x004b7960,0x004b79f7) `RectBounds__IntersectWith`; type `bool __thiscall RectBounds__IntersectWith(RectBounds *this, const RectBounds *bounds)`; frame `__saved_registers@0x20/4:_DWORD; __return_address@0x24/4:_UNKNOWN *; bounds@0x28/4:const RectBounds *`; AR absent; AP absent; FR absent; FP exactly `Source-facing RectBounds::IntersectWith; mutates this to the non-empty intersection and clears it on failure.`; body SHA256 B30A96040C9354609990CAAB536DA058418CEE87E0056D7859338DEC25B89141; xrefs exactly `{}`; boundaries remain `cc` [0x004b795e,0x004b7960) and [0x004b79f7,0x004b7a00); every unlisted field protected. |
| I48 | Classification: apply; [0x004b7af0,0x004b7b88) `RectBounds__InsetByQuarter`; type `RectBounds *__thiscall RectBounds__InsetByQuarter(const RectBounds *this, RectBounds *outBounds)`; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; outBounds@0x8/4:RectBounds *`; AR absent; AP absent; FR absent; FP absent; body SHA256 AFBA7653829F20377858C09F8831798163E18AAB7758B83B65F7DE3B91DFECAB; xrefs exactly `{}`; quarter-literal reads at 0x004b7b15 and 0x004b7b43; half-literal reads at 0x004b7b21 and 0x004b7b4f; boundaries `cc` [0x004b7ae8,0x004b7af0) and [0x004b7b88,0x004b7b90) | `set_repeatable_comments({database:"<fresh runtime-attested canonical session ID>",items:[{addr:"0x004b7af0",comment:"Source-facing RectBounds::InsetByQuarter; writes a centered quarter-inset result using 0.25f and 0.5f rounding."}]})` | [0x004b7af0,0x004b7b88) `RectBounds__InsetByQuarter`; type `RectBounds *__thiscall RectBounds__InsetByQuarter(const RectBounds *this, RectBounds *outBounds)`; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; outBounds@0x8/4:RectBounds *`; AR absent; AP absent; FR absent; FP exactly `Source-facing RectBounds::InsetByQuarter; writes a centered quarter-inset result using 0.25f and 0.5f rounding.`; body SHA256 AFBA7653829F20377858C09F8831798163E18AAB7758B83B65F7DE3B91DFECAB; xrefs exactly `{}`; quarter-literal reads remain at 0x004b7b15 and 0x004b7b43; half-literal reads remain at 0x004b7b21 and 0x004b7b4f; boundaries remain `cc` [0x004b7ae8,0x004b7af0) and [0x004b7b88,0x004b7b90); every unlisted field protected. |
| I49 | Classification: apply; [0x004b7b90,0x004b7c21) `RectBounds__OutsetByHalf`; type `RectBounds *__thiscall RectBounds__OutsetByHalf(const RectBounds *this, RectBounds *outBounds)`; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; outBounds@0x8/4:RectBounds *`; AR absent; AP absent; FR absent; FP absent; body SHA256 E78EA8100376B90E0F9430A62D054A9E7AA997723CC5391EE8BAEB17FF705FD3; xrefs exactly `{}`; half-literal read at 0x004b7b93; boundaries `cc` [0x004b7b88,0x004b7b90) and [0x004b7c21,0x004b7c30) | `set_repeatable_comments({database:"<fresh runtime-attested canonical session ID>",items:[{addr:"0x004b7b90",comment:"Source-facing RectBounds::OutsetByHalf; writes a centered half-span outset result using the shared 0.5f literal."}]})` | [0x004b7b90,0x004b7c21) `RectBounds__OutsetByHalf`; type `RectBounds *__thiscall RectBounds__OutsetByHalf(const RectBounds *this, RectBounds *outBounds)`; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; outBounds@0x8/4:RectBounds *`; AR absent; AP absent; FR absent; FP exactly `Source-facing RectBounds::OutsetByHalf; writes a centered half-span outset result using the shared 0.5f literal.`; body SHA256 E78EA8100376B90E0F9430A62D054A9E7AA997723CC5391EE8BAEB17FF705FD3; xrefs exactly `{}`; half-literal read remains at 0x004b7b93; boundaries remain `cc` [0x004b7b88,0x004b7b90) and [0x004b7c21,0x004b7c30); every unlisted field protected. |
| I50 | Classification: apply; [0x004b7f90,0x004b7fe0) `Transpose3x3AnchorIndex`; type `int __cdecl Transpose3x3AnchorIndex(int anchor)`; frame `__return_address@0x0/4:_UNKNOWN *; anchor@0x4/4:int`; AR absent; AP absent; FR absent; FP absent; body SHA256 6CA2AB80C534F281162C1AC736F2706F2A90E6B74EB4774DC5ACF24379621FEF; xrefs exactly `{}`; predecessor `cc` [0x004b7f87,0x004b7f90); switch table [0x004b7fe0,0x004b8004); successor `cc` [0x004b8004,0x004b8010) | `set_repeatable_comments({database:"<fresh runtime-attested canonical session ID>",items:[{addr:"0x004b7f90",comment:"File-local Transpose3x3AnchorIndex; transposes row-major 3x3 anchor indices and preserves out-of-range input."}]})` | [0x004b7f90,0x004b7fe0) `Transpose3x3AnchorIndex`; type `int __cdecl Transpose3x3AnchorIndex(int anchor)`; frame `__return_address@0x0/4:_UNKNOWN *; anchor@0x4/4:int`; AR absent; AP absent; FR absent; FP exactly `File-local Transpose3x3AnchorIndex; transposes row-major 3x3 anchor indices and preserves out-of-range input.`; body SHA256 6CA2AB80C534F281162C1AC736F2706F2A90E6B74EB4774DC5ACF24379621FEF; xrefs exactly `{}`; predecessor remains `cc` [0x004b7f87,0x004b7f90); switch table remains [0x004b7fe0,0x004b8004); successor remains `cc` [0x004b8004,0x004b8010); every unlisted field protected. |
| I51 | Classification: apply; [0x004b8010,0x004b80ac) `AdjustRectPairForAnchor`; type `void __cdecl AdjustRectPairForAnchor(const RectBounds *firstBounds, const RectBounds *secondBounds, int anchor, RectBounds *outFirstBounds, RectBounds *outSecondBounds)`; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; firstBounds@0x8/4:const RectBounds *; secondBounds@0xc/4:const RectBounds *; anchor@0x10/4:int; outFirstBounds@0x14/4:RectBounds *; outSecondBounds@0x18/4:RectBounds *`; AR absent; AP absent; FR absent; FP absent; body SHA256 EC65D44AB83AFEE724EA63C8E07D1050E35B4F510AEFDF8CAA8EE3011B9335AB; xrefs exactly `{}`; axis-helper calls at 0x004b803e and 0x004b809f; table [0x004b80ac,0x004b80d0) with sole ref 0x004b804b; predecessor `cc` [0x004b8004,0x004b8010) | `set_repeatable_comments({database:"<fresh runtime-attested canonical session ID>",items:[{addr:"0x004b8010",comment:"File-local AdjustRectPairForAnchor; copies two rectangles and applies zero-offset horizontal and transposed vertical anchor adjustment."}]})` | [0x004b8010,0x004b80ac) `AdjustRectPairForAnchor`; type `void __cdecl AdjustRectPairForAnchor(const RectBounds *firstBounds, const RectBounds *secondBounds, int anchor, RectBounds *outFirstBounds, RectBounds *outSecondBounds)`; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; firstBounds@0x8/4:const RectBounds *; secondBounds@0xc/4:const RectBounds *; anchor@0x10/4:int; outFirstBounds@0x14/4:RectBounds *; outSecondBounds@0x18/4:RectBounds *`; AR absent; AP absent; FR absent; FP exactly `File-local AdjustRectPairForAnchor; copies two rectangles and applies zero-offset horizontal and transposed vertical anchor adjustment.`; body SHA256 EC65D44AB83AFEE724EA63C8E07D1050E35B4F510AEFDF8CAA8EE3011B9335AB; xrefs exactly `{}`; axis-helper calls remain at 0x004b803e and 0x004b809f; table remains [0x004b80ac,0x004b80d0) with sole ref 0x004b804b; predecessor remains `cc` [0x004b8004,0x004b8010); every unlisted field protected. |
| I52 | Classification: apply; [0x004b80d0,0x004b8170) `AdjustRectPairForAnchorWithOffsets`; type `void __cdecl AdjustRectPairForAnchorWithOffsets(const RectBounds *firstBounds, const RectBounds *secondBounds, int anchor, int horizontalOffset, int verticalOffset, RectBounds *outFirstBounds, RectBounds *outSecondBounds)`; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; firstBounds@0x8/4:const RectBounds *; secondBounds@0xc/4:const RectBounds *; anchor@0x10/4:int; horizontalOffset@0x14/4:int; verticalOffset@0x18/4:int; outFirstBounds@0x1c/4:RectBounds *; outSecondBounds@0x20/4:RectBounds *`; AR absent; AP absent; FR absent; FP absent; body SHA256 DB24FE8A1CCEA3E9C45B8A67B8AEE22F81164613FE5C830E9E1C909780C736AB; xrefs exactly `{}`; axis-helper calls at 0x004b80ff and 0x004b8161; predecessor table [0x004b80ac,0x004b80d0); table [0x004b8170,0x004b8194) with sole ref 0x004b810c; successor `cc` [0x004b8194,0x004b81a0) | `set_repeatable_comments({database:"<fresh runtime-attested canonical session ID>",items:[{addr:"0x004b80d0",comment:"File-local AdjustRectPairForAnchorWithOffsets; copies two rectangles and applies caller-provided horizontal and vertical anchor offsets."}]})` | [0x004b80d0,0x004b8170) `AdjustRectPairForAnchorWithOffsets`; type `void __cdecl AdjustRectPairForAnchorWithOffsets(const RectBounds *firstBounds, const RectBounds *secondBounds, int anchor, int horizontalOffset, int verticalOffset, RectBounds *outFirstBounds, RectBounds *outSecondBounds)`; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; firstBounds@0x8/4:const RectBounds *; secondBounds@0xc/4:const RectBounds *; anchor@0x10/4:int; horizontalOffset@0x14/4:int; verticalOffset@0x18/4:int; outFirstBounds@0x1c/4:RectBounds *; outSecondBounds@0x20/4:RectBounds *`; AR absent; AP absent; FR absent; FP exactly `File-local AdjustRectPairForAnchorWithOffsets; copies two rectangles and applies caller-provided horizontal and vertical anchor offsets.`; body SHA256 DB24FE8A1CCEA3E9C45B8A67B8AEE22F81164613FE5C830E9E1C909780C736AB; xrefs exactly `{}`; axis-helper calls remain at 0x004b80ff and 0x004b8161; predecessor table remains [0x004b80ac,0x004b80d0); table remains [0x004b8170,0x004b8194) with sole ref 0x004b810c; successor remains `cc` [0x004b8194,0x004b81a0); every unlisted field protected. |
| I53 | Classification: apply; [0x004b7670,0x004b7685) `RectBounds__IsEmptyOrInvalid`; type `bool __thiscall RectBounds__IsEmptyOrInvalid(const RectBounds *this)`; frame `__return_address@0x0/4:_UNKNOWN *`; AR absent; AP absent; FR absent; FP absent; body SHA256 CC1ADFECB4B1B4900F002BD7789AFDC2A8A5A27CB34D388565E9754BFC66DA70; xrefs exactly 7 `{0x496cf6:code, 0x496e30:code, 0x497104:code, 0x49723e:code, 0x4c789d:code, 0x538ef5:code, 0x539435:code}`, more:false | `set_repeatable_comments({database:"<fresh runtime-attested canonical session ID>",items:[{addr:"0x004b7670",comment:"Source-facing RectBounds::IsEmptyOrInvalid; true when bottom <= top or right <= left."}]})` | [0x004b7670,0x004b7685) `RectBounds__IsEmptyOrInvalid`; type `bool __thiscall RectBounds__IsEmptyOrInvalid(const RectBounds *this)`; frame `__return_address@0x0/4:_UNKNOWN *`; AR absent; AP absent; FR absent; FP exactly `Source-facing RectBounds::IsEmptyOrInvalid; true when bottom <= top or right <= left.`; body SHA256 CC1ADFECB4B1B4900F002BD7789AFDC2A8A5A27CB34D388565E9754BFC66DA70; xrefs exactly 7 `{0x496cf6:code, 0x496e30:code, 0x497104:code, 0x49723e:code, 0x4c789d:code, 0x538ef5:code, 0x539435:code}`, more:false; every unlisted field protected. |
| I54 | Classification: apply; [0x004b76d0,0x004b76f8) `RectBounds__ContainsPoint`; type `bool __thiscall RectBounds__ContainsPoint(const RectBounds *this, int y, int x)`; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; y@0x8/4:int; x@0xc/4:int`; AR absent; AP absent; FR absent; FP absent; body SHA256 3AAB471767B3F1109BDA8C17FD50891B1DFBC090E0CF1FB6BEA309CA310AE664; xrefs exactly 4 `{0x499df9:code, 0x4b2e00:code, 0x4b2e48:code, 0x4b39bf:code}`, more:false | `set_repeatable_comments({database:"<fresh runtime-attested canonical session ID>",items:[{addr:"0x004b76d0",comment:"Source-facing RectBounds::ContainsPoint(int y, int x); half-open containment."}]})` | [0x004b76d0,0x004b76f8) `RectBounds__ContainsPoint`; type `bool __thiscall RectBounds__ContainsPoint(const RectBounds *this, int y, int x)`; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; y@0x8/4:int; x@0xc/4:int`; AR absent; AP absent; FR absent; FP exactly `Source-facing RectBounds::ContainsPoint(int y, int x); half-open containment.`; body SHA256 3AAB471767B3F1109BDA8C17FD50891B1DFBC090E0CF1FB6BEA309CA310AE664; xrefs exactly 4 `{0x499df9:code, 0x4b2e00:code, 0x4b2e48:code, 0x4b39bf:code}`, more:false; every unlisted field protected. |
| I55 | Classification: apply; [0x004b78d0,0x004b78ee) `RectBounds__SetLTRB`; type `void __thiscall RectBounds__SetLTRB(RectBounds *this, int leftValue, int topValue, int rightValue, int bottomValue)`; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; leftValue@0x8/4:int; topValue@0xc/4:int; rightValue@0x10/4:int; bottomValue@0x14/4:int`; AR absent; AP absent; FR absent; FP absent; body SHA256 98BA7875DEAD4691B1E62A6E502A194D10125F65841C18AEAB502D35A72A009A; xrefs exactly 208, canonical manifest SHA256 94B9965401B5DACEB29BC7B28460565BCD5F34D641D4C318C01E1B1232D87679, more:false | `set_repeatable_comments({database:"<fresh runtime-attested canonical session ID>",items:[{addr:"0x004b78d0",comment:"Source-facing RectBounds::SetLTRB; write left, top, right, bottom in that order."}]})` | [0x004b78d0,0x004b78ee) `RectBounds__SetLTRB`; type `void __thiscall RectBounds__SetLTRB(RectBounds *this, int leftValue, int topValue, int rightValue, int bottomValue)`; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; leftValue@0x8/4:int; topValue@0xc/4:int; rightValue@0x10/4:int; bottomValue@0x14/4:int`; AR absent; AP absent; FR absent; FP exactly `Source-facing RectBounds::SetLTRB; write left, top, right, bottom in that order.`; body SHA256 98BA7875DEAD4691B1E62A6E502A194D10125F65841C18AEAB502D35A72A009A; xrefs exactly 208, canonical manifest SHA256 94B9965401B5DACEB29BC7B28460565BCD5F34D641D4C318C01E1B1232D87679, more:false; every unlisted field protected. |
| I56 | Classification: apply; [0x004b7910,0x004b795e) `RectBounds__Inset`; type `void __thiscall RectBounds__Inset(RectBounds *this, int dx, int dy)`; frame `__saved_registers@0xc/4:_DWORD; __return_address@0x10/4:_UNKNOWN *; dx@0x14/4:int; dy@0x18/4:int`; AR absent; AP absent; FR absent; FP absent; body SHA256 FEF40B7E2D1B870673A814D47DC3311EC6B7A5FBA057B70FDCA47405707BA0C9; xrefs exactly 3 `{0x53bcb7:code, 0x53bcd8:code, 0x53bcf9:code}`, more:false | `set_repeatable_comments({database:"<fresh runtime-attested canonical session ID>",items:[{addr:"0x004b7910",comment:"Source-facing RectBounds::Inset; positive deltas shrink and inverted axes collapse to signed midpoints."}]})` | [0x004b7910,0x004b795e) `RectBounds__Inset`; type `void __thiscall RectBounds__Inset(RectBounds *this, int dx, int dy)`; frame `__saved_registers@0xc/4:_DWORD; __return_address@0x10/4:_UNKNOWN *; dx@0x14/4:int; dy@0x18/4:int`; AR absent; AP absent; FR absent; FP exactly `Source-facing RectBounds::Inset; positive deltas shrink and inverted axes collapse to signed midpoints.`; body SHA256 FEF40B7E2D1B870673A814D47DC3311EC6B7A5FBA057B70FDCA47405707BA0C9; xrefs exactly 3 `{0x53bcb7:code, 0x53bcd8:code, 0x53bcf9:code}`, more:false; every unlisted field protected. |
| I57 | Classification: apply; [0x004b7a00,0x004b7a77) `RectBounds__UnionWith`; type `RectBounds *__thiscall RectBounds__UnionWith(RectBounds *this, const RectBounds *bounds)`; frame `var_4@0x8/4:_DWORD; __saved_registers@0xc/4:_DWORD; __return_address@0x10/4:_UNKNOWN *; bounds@0x14/4:const RectBounds *`; AR absent; AP absent; FR absent; FP absent; body SHA256 8349772D4644A0481E2021C674B65A526220D165F705EF7013BAE3BD7E6E7F2D; xrefs exactly 33, canonical manifest SHA256 051A654B00A2272C4300D209BC3504E90174DE06D9AC5D019EF0859048681F50, more:false | `set_repeatable_comments({database:"<fresh runtime-attested canonical session ID>",items:[{addr:"0x004b7a00",comment:"Source-facing RectBounds::UnionWith; mutate this rectangle and return this."}]})` | [0x004b7a00,0x004b7a77) `RectBounds__UnionWith`; type `RectBounds *__thiscall RectBounds__UnionWith(RectBounds *this, const RectBounds *bounds)`; frame `var_4@0x8/4:_DWORD; __saved_registers@0xc/4:_DWORD; __return_address@0x10/4:_UNKNOWN *; bounds@0x14/4:const RectBounds *`; AR absent; AP absent; FR absent; FP exactly `Source-facing RectBounds::UnionWith; mutate this rectangle and return this.`; body SHA256 8349772D4644A0481E2021C674B65A526220D165F705EF7013BAE3BD7E6E7F2D; xrefs exactly 33, canonical manifest SHA256 051A654B00A2272C4300D209BC3504E90174DE06D9AC5D019EF0859048681F50, more:false; every unlisted field protected. |
| I58 | Classification: apply; [0x004b7a80,0x004b7ae8) `RectBounds__ClampWithin`; type `void __thiscall RectBounds__ClampWithin(RectBounds *this, int leftLimit, int topLimit, int rightLimit, int bottomLimit)`; frame `__saved_registers@0x8/4:_DWORD; __return_address@0xc/4:_UNKNOWN *; leftLimit@0x10/4:int; topLimit@0x14/4:int; rightLimit@0x18/4:int; bottomLimit@0x1c/4:int`; AR absent; AP absent; FR absent; FP absent; body SHA256 E00162FFCF7A7802134C247A60681CA9F29D1E1815696636E223671B445D1588; xrefs exactly 2 `{0x5c3767:code, 0x5c37c9:code}`, more:false | `set_repeatable_comments({database:"<fresh runtime-attested canonical session ID>",items:[{addr:"0x004b7a80",comment:"Source-facing RectBounds::ClampWithin; translate without resizing into the supplied limits."}]})` | [0x004b7a80,0x004b7ae8) `RectBounds__ClampWithin`; type `void __thiscall RectBounds__ClampWithin(RectBounds *this, int leftLimit, int topLimit, int rightLimit, int bottomLimit)`; frame `__saved_registers@0x8/4:_DWORD; __return_address@0xc/4:_UNKNOWN *; leftLimit@0x10/4:int; topLimit@0x14/4:int; rightLimit@0x18/4:int; bottomLimit@0x1c/4:int`; AR absent; AP absent; FR absent; FP exactly `Source-facing RectBounds::ClampWithin; translate without resizing into the supplied limits.`; body SHA256 E00162FFCF7A7802134C247A60681CA9F29D1E1815696636E223671B445D1588; xrefs exactly 2 `{0x5c3767:code, 0x5c37c9:code}`, more:false; every unlisted field protected. |
| I59 | Classification: apply; [0x004b7c70,0x004b7c95) `InitRectBoundsFromSize`; type `void __cdecl InitRectBoundsFromSize(RectBounds *bounds, int left, int top, int width, int height)`; frame `__saved_registers@0x4/4:_DWORD; __return_address@0x8/4:_UNKNOWN *; bounds@0xc/4:RectBounds *; left@0x10/4:int; top@0x14/4:int; width@0x18/4:int; height@0x1c/4:int`; AR absent; AP absent; FR absent; FP absent; body SHA256 E3FEB5168886A48FD06A13AEEB62B4FB0F502ACEEBE1496F749FEF32DC53B310; xrefs exactly 38, canonical manifest SHA256 5C1CD35B479E4A1208282FDF2922E4FEE64B51A29F0C882A4F2CE9AE385ED8E0, more:false | `set_repeatable_comments({database:"<fresh runtime-attested canonical session ID>",items:[{addr:"0x004b7c70",comment:"Source-facing InitRectBoundsFromSize; compute right=left+width and bottom=top+height."}]})` | [0x004b7c70,0x004b7c95) `InitRectBoundsFromSize`; type `void __cdecl InitRectBoundsFromSize(RectBounds *bounds, int left, int top, int width, int height)`; frame `__saved_registers@0x4/4:_DWORD; __return_address@0x8/4:_UNKNOWN *; bounds@0xc/4:RectBounds *; left@0x10/4:int; top@0x14/4:int; width@0x18/4:int; height@0x1c/4:int`; AR absent; AP absent; FR absent; FP exactly `Source-facing InitRectBoundsFromSize; compute right=left+width and bottom=top+height.`; body SHA256 E3FEB5168886A48FD06A13AEEB62B4FB0F502ACEEBE1496F749FEF32DC53B310; xrefs exactly 38, canonical manifest SHA256 5C1CD35B479E4A1208282FDF2922E4FEE64B51A29F0C882A4F2CE9AE385ED8E0, more:false; every unlisted field protected. |
| I60 | Classification: apply; [0x004b7ca0,0x004b7cb6) `RectArea`; type `int __cdecl RectArea(const RectBounds *bounds)`; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; bounds@0x8/4:const RectBounds *`; AR absent; AP absent; FR absent; FP absent; body SHA256 163710594CCDDC680B855D28D4CDD027E1EDF64AD557EBB23225C51A41ACBB68; xrefs exactly 4 `{0x4580de:code, 0x4581da:code, 0x45833d:code, 0x4b621a:code}`, more:false | `set_repeatable_comments({database:"<fresh runtime-attested canonical session ID>",items:[{addr:"0x004b7ca0",comment:"Source-facing RectArea; signed width times signed height with no empty clamp."}]})` | [0x004b7ca0,0x004b7cb6) `RectArea`; type `int __cdecl RectArea(const RectBounds *bounds)`; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; bounds@0x8/4:const RectBounds *`; AR absent; AP absent; FR absent; FP exactly `Source-facing RectArea; signed width times signed height with no empty clamp.`; body SHA256 163710594CCDDC680B855D28D4CDD027E1EDF64AD557EBB23225C51A41ACBB68; xrefs exactly 4 `{0x4580de:code, 0x4581da:code, 0x45833d:code, 0x4b621a:code}`, more:false; every unlisted field protected. |
| I61 | Classification: apply; [0x004b7e30,0x004b7e7f) `InsetRect`; type `void __cdecl InsetRect(RectBounds *bounds, int dx, int dy)`; frame `__saved_registers@0xc/4:_DWORD; __return_address@0x10/4:_UNKNOWN *; bounds@0x14/4:RectBounds *; dx@0x18/4:int; dy@0x1c/4:int`; AR absent; AP absent; FR absent; FP absent; body SHA256 A81AC6D7E55C4D42090AF94E22F93F4F1136229BE2E83DDF4CA74765512FB102; xrefs exactly 32, canonical manifest SHA256 362626B99F1F93514ED611E889B3B16E221606FCD8F88CABB50E586A009149E1, more:false | `set_repeatable_comments({database:"<fresh runtime-attested canonical session ID>",items:[{addr:"0x004b7e30",comment:"Source-facing InsetRect; free-function mirror of member Inset with midpoint collapse."}]})` | [0x004b7e30,0x004b7e7f) `InsetRect`; type `void __cdecl InsetRect(RectBounds *bounds, int dx, int dy)`; frame `__saved_registers@0xc/4:_DWORD; __return_address@0x10/4:_UNKNOWN *; bounds@0x14/4:RectBounds *; dx@0x18/4:int; dy@0x1c/4:int`; AR absent; AP absent; FR absent; FP exactly `Source-facing InsetRect; free-function mirror of member Inset with midpoint collapse.`; body SHA256 A81AC6D7E55C4D42090AF94E22F93F4F1136229BE2E83DDF4CA74765512FB102; xrefs exactly 32, canonical manifest SHA256 362626B99F1F93514ED611E889B3B16E221606FCD8F88CABB50E586A009149E1, more:false; every unlisted field protected. |
| I62 | Classification: apply; [0x004b7f30,0x004b7f87) `RectContainsRect`; type `bool __cdecl RectContainsRect(const RectBounds *innerBounds, const RectBounds *outerBounds)`; frame `__saved_registers@0x8/4:_DWORD; __return_address@0xc/4:_UNKNOWN *; innerBounds@0x10/4:const RectBounds *; outerBounds@0x14/4:const RectBounds *`; AR absent; AP absent; FR absent; FP absent; body SHA256 24A3CF15F60046C64256E895BF3CF0804F1775FBFAC06C39633A1065B11481D5; xrefs exactly 2 `{0x554a4a:code, 0x554a83:code}`, more:false | `set_repeatable_comments({database:"<fresh runtime-attested canonical session ID>",items:[{addr:"0x004b7f30",comment:"Source-facing RectContainsRect(innerBounds, outerBounds); empty inner succeeds and empty outer fails."}]})` | [0x004b7f30,0x004b7f87) `RectContainsRect`; type `bool __cdecl RectContainsRect(const RectBounds *innerBounds, const RectBounds *outerBounds)`; frame `__saved_registers@0x8/4:_DWORD; __return_address@0xc/4:_UNKNOWN *; innerBounds@0x10/4:const RectBounds *; outerBounds@0x14/4:const RectBounds *`; AR absent; AP absent; FR absent; FP exactly `Source-facing RectContainsRect(innerBounds, outerBounds); empty inner succeeds and empty outer fails.`; body SHA256 24A3CF15F60046C64256E895BF3CF0804F1775FBFAC06C39633A1065B11481D5; xrefs exactly 2 `{0x554a4a:code, 0x554a83:code}`, more:false; every unlisted field protected. |
| I63 | Classification: apply; [0x004b8290,0x004b83ae) `AdjustRectAnchorAxis`; type `void __cdecl AdjustRectAnchorAxis(int anchor, int offset, int *firstLow, int *firstHigh, int *secondLow, int *secondHigh)`; frame `var_10@0xc/4:_DWORD; var_C@0x10/4:_DWORD; var_8@0x14/4:_DWORD; var_4@0x18/4:_DWORD; __saved_registers@0x1c/4:_DWORD; __return_address@0x20/4:_UNKNOWN *; anchor@0x24/4:int; offset@0x28/4:int; firstLow@0x2c/4:int *; firstHigh@0x30/4:int *; secondLow@0x34/4:int *; secondHigh@0x38/4:int *`; AR absent; AP absent; FR absent; FP absent; body SHA256 2AEC81E39738637C5E9B1D3D0AA050D26BBA66F59590867E105CAB965F6B0D16; xrefs exactly 4 `{0x4b803e:code, 0x4b809f:code, 0x4b80ff:code, 0x4b8161:code}`, more:false | `set_repeatable_comments({database:"<fresh runtime-attested canonical session ID>",items:[{addr:"0x004b8290",comment:"File-local source helper AdjustRectAnchorAxis; preserve exact clipping and switch behavior."}]})` | [0x004b8290,0x004b83ae) `AdjustRectAnchorAxis`; type `void __cdecl AdjustRectAnchorAxis(int anchor, int offset, int *firstLow, int *firstHigh, int *secondLow, int *secondHigh)`; frame `var_10@0xc/4:_DWORD; var_C@0x10/4:_DWORD; var_8@0x14/4:_DWORD; var_4@0x18/4:_DWORD; __saved_registers@0x1c/4:_DWORD; __return_address@0x20/4:_UNKNOWN *; anchor@0x24/4:int; offset@0x28/4:int; firstLow@0x2c/4:int *; firstHigh@0x30/4:int *; secondLow@0x34/4:int *; secondHigh@0x38/4:int *`; AR absent; AP absent; FR absent; FP exactly `File-local source helper AdjustRectAnchorAxis; preserve exact clipping and switch behavior.`; body SHA256 2AEC81E39738637C5E9B1D3D0AA050D26BBA66F59590867E105CAB965F6B0D16; xrefs exactly 4 `{0x4b803e:code, 0x4b809f:code, 0x4b80ff:code, 0x4b8161:code}`, more:false; every unlisted field protected. |

### PointInRect physical-stack correction

Current `0x004b7e80` identity is `PointInRect`, type `bool __cdecl(int y, int x, const RectBounds *bounds)`, AR absent, AP absent, FR `Half-open containment test: bounds->left <= x < bounds->right and bounds->top <= y < bounds->bottom.`, FP absent. Complete current frame is `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; row@0x8/4:int; column@0xc/4:int; bounds@0x10/4:const MapRect *`. The exact function is `[0x004b7e80,0x004b7ea7)`, body SHA256 `EA5046055A47A9903359495176EC27AC0259C78711E1AD60A5B9055F1CF65B4E`, with exactly 270 inbound xrefs represented by terminal manifest SHA256 `715E26A19D1BAC52D1F1A3F8BAA83946A3F8FE12420F156AE10701A2C44AE21D`.

| ID | Exact literal prestate | Exact request | Exact immediate poststate |
| --- | --- | --- | --- |
| I64 | Classification: apply; `[0x004b7e80,0x004b7ea7)` `PointInRect`; type `bool __cdecl(int y, int x, const RectBounds *bounds)`; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; row@0x8/4:int; column@0xc/4:int; bounds@0x10/4:const MapRect *`; destination row name `y` absent; AR absent; AP absent; FR exactly `Half-open containment test: bounds->left <= x < bounds->right and bounds->top <= y < bounds->bottom.`; FP absent; body SHA256 `EA5046055A47A9903359495176EC27AC0259C78711E1AD60A5B9055F1CF65B4E`; 270-xref terminal manifest SHA256 `715E26A19D1BAC52D1F1A3F8BAA83946A3F8FE12420F156AE10701A2C44AE21D` | `rename({database:"<fresh runtime-attested canonical session ID>",batch:{stack:[{func_addr:"0x004b7e80",old:"row",new:"y"}],allow_overwrite:false,dry_run:false,stop_on_error:true}})` | `[0x004b7e80,0x004b7ea7)` `PointInRect`; same type; frame exactly `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; y@0x8/4:int; column@0xc/4:int; bounds@0x10/4:const MapRect *`; AR absent; AP absent; same exact FR; FP absent; body hash and complete 270-xref manifest unchanged; only `row` changed to `y`. |
| I65 | Classification: apply; `[0x004b7e80,0x004b7ea7)` `PointInRect`; type `bool __cdecl(int y, int x, const RectBounds *bounds)`; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; y@0x8/4:int; column@0xc/4:int; bounds@0x10/4:const MapRect *`; destination row name `x` absent; AR absent; AP absent; FR exactly `Half-open containment test: bounds->left <= x < bounds->right and bounds->top <= y < bounds->bottom.`; FP absent; body SHA256 `EA5046055A47A9903359495176EC27AC0259C78711E1AD60A5B9055F1CF65B4E`; 270-xref terminal manifest SHA256 `715E26A19D1BAC52D1F1A3F8BAA83946A3F8FE12420F156AE10701A2C44AE21D` | `rename({database:"<fresh runtime-attested canonical session ID>",batch:{stack:[{func_addr:"0x004b7e80",old:"column",new:"x"}],allow_overwrite:false,dry_run:false,stop_on_error:true}})` | `[0x004b7e80,0x004b7ea7)` `PointInRect`; same type; frame exactly `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; y@0x8/4:int; x@0xc/4:int; bounds@0x10/4:const MapRect *`; AR absent; AP absent; same exact FR; FP absent; body hash and complete 270-xref manifest unchanged; only `column` changed to `x` relative to I64. |
| I66 | Classification: apply; `[0x004b7e80,0x004b7ea7)` `PointInRect`; type `bool __cdecl(int y, int x, const RectBounds *bounds)`; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; y@0x8/4:int; x@0xc/4:int; bounds@0x10/4:const MapRect *`; AR absent; AP absent; FR exactly `Half-open containment test: bounds->left <= x < bounds->right and bounds->top <= y < bounds->bottom.`; FP absent; body SHA256 `EA5046055A47A9903359495176EC27AC0259C78711E1AD60A5B9055F1CF65B4E`; 270-xref terminal manifest SHA256 `715E26A19D1BAC52D1F1A3F8BAA83946A3F8FE12420F156AE10701A2C44AE21D` | `set_type({database:"<fresh runtime-attested canonical session ID>",edits:[{addr:"0x004b7e80",kind:"stack",name:"bounds",ty:"const RectBounds *"}]})` | `[0x004b7e80,0x004b7ea7)` `PointInRect`; same function type; complete final frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; y@0x8/4:int; x@0xc/4:int; bounds@0x10/4:const RectBounds *`; AR absent; AP absent; same exact FR; FP absent; body hash and complete 270-xref manifest unchanged; only the `bounds` row type changed relative to I65. |

### Protected no-change entities

| ID | Exact current state | Required unchanged readback |
| --- | --- | --- |
| P01 | `Point` UDT size 8: `y@0 size4 int; x@4 size4 int`; `RectBounds` UDT size 16: `left@0; top@4; right@8; bottom@12`, each size4 int | Both declarations/layouts remain exact; no vtable, inheritance, padding member, or duplicate `RectBoundsLayout` UDT is created. |
| P02 | `0x0061a880` item `dword_61A880`, size4 data, type absent, AR absent, AP absent, FR not applicable, FP not applicable, bytes `00 00 80 3e`, refs exactly `{0x4b7b15:data,0x4b7b43:data}` | Every field remains exact; no authored global/type/name/comment is created. |
| P03 | `0x006104b0` item `dword_6104B0`, size4 data, type absent, AR absent, AP absent, FR not applicable, FP not applicable, bytes `00 00 00 3f`, terminal xref count 60 including local refs `0x4b7b21,0x4b7b4f,0x4b7b93` | Item/name/type/channels/bytes and complete 60-ref set remain exact; no RectBounds ownership rename is applied. |
| P04A | item `[0x004b7fe0,0x004b8004)` size36 `jpt_4B7F9B`, type absent, data/non-code; AR `jump table for switch statement`; AP absent; FR not applicable; FP not applicable; bytes `a2 7f 4b 00 b4 7f 4b 00 c9 7f 4b 00 a6 7f 4b 00 bb 7f 4b 00 d0 7f 4b 00 ad 7f 4b 00 c2 7f 4b 00 d7 7f 4b 00`; SHA256 `8C86CFABA1F59EC8330290189186E44864866DC5AE299BE1AC9FCCFB57D10D3C`; inbound `{0x4b7f9b:data}`; outbound `{0x4b7fa2:data,0x4b7fa6:data,0x4b7fad:data,0x4b7fb4:data,0x4b7fbb:data,0x4b7fc2:data,0x4b7fc9:data,0x4b7fd0:data,0x4b7fd7:data}`; no code xref | Preserve every literal field, all ten directional xrefs, the table/data classification, and adjacent `[0x004b7f90,0x004b7fe0)` body plus `[0x004b8004,0x004b8010)` alignment boundaries. No mutation is authorized. |
| P04B | item `[0x004b80ac,0x004b80d0)` size36 `jpt_4B804B`, type absent, data/non-code; AR `jump table for switch statement`; AP absent; FR not applicable; FP not applicable; bytes `52 80 4b 00 64 80 4b 00 79 80 4b 00 56 80 4b 00 6b 80 4b 00 80 80 4b 00 5d 80 4b 00 72 80 4b 00 87 80 4b 00`; SHA256 `B47AE1B372DF9D6E71B84C355F61EE2AAB8663F5C65EDB5C4CD38EF5F397D9BE`; inbound `{0x4b804b:data}`; outbound `{0x4b8052:data,0x4b8056:data,0x4b805d:data,0x4b8064:data,0x4b806b:data,0x4b8072:data,0x4b8079:data,0x4b8080:data,0x4b8087:data}`; no code xref | Preserve every literal field, all ten directional xrefs, the table/data classification, and adjacent `[0x004b8010,0x004b80ac)` and `[0x004b80d0,0x004b8170)` function boundaries. No mutation is authorized. |
| P04C | item `[0x004b8170,0x004b8194)` size36 `jpt_4B810C`, type absent, data/non-code; AR `jump table for switch statement`; AP absent; FR not applicable; FP not applicable; bytes `13 81 4b 00 25 81 4b 00 3a 81 4b 00 17 81 4b 00 2c 81 4b 00 41 81 4b 00 1e 81 4b 00 33 81 4b 00 48 81 4b 00`; SHA256 `C619577E07E8AA0AA923FA65E7D55EB4610531E35BDEFCA787746822179DA34F`; inbound `{0x4b810c:data}`; outbound `{0x4b8113:data,0x4b8117:data,0x4b811e:data,0x4b8125:data,0x4b812c:data,0x4b8133:data,0x4b813a:data,0x4b8141:data,0x4b8148:data}`; no code xref | Preserve every literal field, all ten directional xrefs, the table/data classification, and adjacent `[0x004b80d0,0x004b8170)` body plus `[0x004b8194,0x004b81a0)` alignment boundaries. No mutation is authorized. |
| P04D | item `[0x004b83b0,0x004b83bc)` size12 `jpt_4B82D6`, type absent, data/non-code; AR `jump table for switch statement`; AP absent; FR not applicable; FP not applicable; bytes `dd 82 4b 00 e1 82 4b 00 ec 82 4b 00`; SHA256 `4E435D838C517EECD9C679A1332FEC87931A0F1011E3709743FE1FFA454D2636`; inbound `{0x4b82d6:data}`; outbound `{0x4b82dd:data,0x4b82e1:data,0x4b82ec:data}`; no code xref | Preserve every literal field, all four directional xrefs, the table/data classification, and adjacent `[0x004b8290,0x004b83ae)` body plus `[0x004b83ae,0x004b83b0)` alignment boundaries. No mutation is authorized. |
| P04E | item `[0x004b83bc,0x004b83c5)` size9 `byte_4B83BC`, type absent, data/non-code; AR `indirect table for switch statement`; AP absent; FR not applicable; FP not applicable; bytes `00 01 02 00 01 02 00 01 02`; SHA256 `FC9D4FE9658C7285776A8E3297F25041918E0A1BAB1663AF46176AD8A3BE9A13`; inbound `{0x4b82cf:data}`; outbound `{}`; no code xref | Preserve every literal field, the sole inbound xref, zero outbound/code xrefs, table/data classification, and adjacent `[0x004b83b0,0x004b83bc)` table plus `[0x004b83c5,0x004b83d0)` alignment boundaries. No mutation is authorized. |

Literal alignment protections; each row is an independent no-change item and every listed start has inbound xrefs `{}`:

| ID / Claim | Exact current prestate | Required unchanged readback |
| --- | --- | --- |
| P04G01 / C130 | `[0x004b7661,0x004b7670)` 15 bytes all `cc`; SHA256 `54CC9DD9593316E80CCAF5D10856E6502A0D75F20473A92FA01D63228EF1624C`; FramePartPane-to-first-member boundary | Exact range/bytes/hash/zero-xref start and boundary remain; no code, function, name, type, or comment is created. |
| P04G02 / C131 | `[0x004b7685,0x004b7690)` 11 bytes all `cc`; SHA256 `3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943`; member-to-member boundary | Exact range/bytes/hash/zero-xref start and boundary remain; no authored item is created. |
| P04G03 / C132 | `[0x004b76c8,0x004b76d0)` 8 bytes all `cc`; SHA256 `3D2F424783DF5853C8D7121B1371650C04241F318E1B0CD46BEDBC805B9164C3`; member-to-member boundary | Exact range/bytes/hash/zero-xref start and boundary remain; no authored item is created. |
| P04G04 / C133 | `[0x004b76f8,0x004b7700)` 8 bytes all `cc`; SHA256 `3D2F424783DF5853C8D7121B1371650C04241F318E1B0CD46BEDBC805B9164C3`; member-to-member boundary | Exact range/bytes/hash/zero-xref start and boundary remain; no authored item is created. |
| P04G05 / C134 | `[0x004b7775,0x004b7780)` 11 bytes all `cc`; SHA256 `3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943`; member-to-member boundary | Exact range/bytes/hash/zero-xref start and boundary remain; no authored item is created. |
| P04G06 / C135 | `[0x004b782a,0x004b7830)` 6 bytes all `cc`; SHA256 `33CC4A00A0F04735602819132DA3E3FAC4CDEB8EC7AEE92551DC79BA8488E722`; member-to-member boundary | Exact range/bytes/hash/zero-xref start and boundary remain; no authored item is created. |
| P04G07 / C136 | `[0x004b78c8,0x004b78d0)` 8 bytes all `cc`; SHA256 `3D2F424783DF5853C8D7121B1371650C04241F318E1B0CD46BEDBC805B9164C3`; cluster-to-SetLTRB boundary | Exact range/bytes/hash/zero-xref start and boundary remain; no authored item is created. |
| P04G08 / C137 | `[0x004b78ee,0x004b78f0)` 2 bytes all `cc`; SHA256 `E3966E3275BE536A16092EC0CADF1638F718218E616FBBE8FF1C5E67FFF4DEF2`; SetLTRB-to-Offset boundary | Exact range/bytes/hash/zero-xref start and boundary remain; no authored item is created. |
| P04G09 / C138 | `[0x004b7908,0x004b7910)` 8 bytes all `cc`; SHA256 `3D2F424783DF5853C8D7121B1371650C04241F318E1B0CD46BEDBC805B9164C3`; Offset-to-Inset boundary | Exact range/bytes/hash/zero-xref start and boundary remain; no authored item is created. |
| P04G10 / C139 | `[0x004b795e,0x004b7960)` 2 bytes all `cc`; SHA256 `E3966E3275BE536A16092EC0CADF1638F718218E616FBBE8FF1C5E67FFF4DEF2`; Inset-to-IntersectWith boundary | Exact range/bytes/hash/zero-xref start and boundary remain; no authored item is created. |
| P04G11 / C140 | `[0x004b79f7,0x004b7a00)` 9 bytes all `cc`; SHA256 `57C1D0AAEF1222FC7F655F011049271D3A843395335212156E61D3850BEB51CE`; IntersectWith-to-UnionWith boundary | Exact range/bytes/hash/zero-xref start and boundary remain; no authored item is created. |
| P04G12 / C141 | `[0x004b7a77,0x004b7a80)` 9 bytes all `cc`; SHA256 `57C1D0AAEF1222FC7F655F011049271D3A843395335212156E61D3850BEB51CE`; UnionWith-to-ClampWithin boundary | Exact range/bytes/hash/zero-xref start and boundary remain; no authored item is created. |
| P04G13 / C142 | `[0x004b7ae8,0x004b7af0)` 8 bytes all `cc`; SHA256 `3D2F424783DF5853C8D7121B1371650C04241F318E1B0CD46BEDBC805B9164C3`; methods-to-quarter-helper boundary | Exact range/bytes/hash/zero-xref start and boundary remain; no authored item is created. |
| P04G14 / C143 | `[0x004b7b88,0x004b7b90)` 8 bytes all `cc`; SHA256 `3D2F424783DF5853C8D7121B1371650C04241F318E1B0CD46BEDBC805B9164C3`; quarter-to-half-helper boundary | Exact range/bytes/hash/zero-xref start and boundary remain; no authored item is created. |
| P04G15 / C144 | `[0x004b7c21,0x004b7c30)` 15 bytes all `cc`; SHA256 `54CC9DD9593316E80CCAF5D10856E6502A0D75F20473A92FA01D63228EF1624C`; member-to-free-helper boundary | Exact range/bytes/hash/zero-xref start and boundary remain; no authored item is created. |
| P04G16 / C145 | `[0x004b7c43,0x004b7c50)` 13 bytes all `cc`; SHA256 `0D0BB866505BC0E2D4276FCDEE1AFDC8887662D04CCE9E4BBB4C10FBA6D0F1CE`; free-helper boundary | Exact range/bytes/hash/zero-xref start and boundary remain; no authored item is created. |
| P04G17 / C146 | `[0x004b7c6f,0x004b7c70)` 1 byte `cc`; SHA256 `1DD8312636F6A0BF3D21FA2855E63072507453E93A5CED4301B364E91C9D87D6`; free-helper boundary | Exact range/byte/hash/zero-xref start and boundary remain; no authored item is created. |
| P04G18 / C147 | `[0x004b7c95,0x004b7ca0)` 11 bytes all `cc`; SHA256 `3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943`; InitRectBoundsFromSize-to-RectArea boundary | Exact range/bytes/hash/zero-xref start and boundary remain; no authored item is created. |
| P04G19 / C148 | `[0x004b7cb6,0x004b7cc0)` 10 bytes all `cc`; SHA256 `22E52BBA61DA8AD6732BE550205A10B89A1BB3B0EA491BE07DE9294F0EB6F045`; RectArea-to-IntersectRects boundary | Exact range/bytes/hash/zero-xref start and boundary remain; no authored item is created. |
| P04G20 / C149 | `[0x004b7d69,0x004b7d70)` 7 bytes all `cc`; SHA256 `F145ECA66705DE68FF53C6D80E34D8F9A5B535FFA157194AA98BDB68AEA4368D`; free-helper boundary | Exact range/bytes/hash/zero-xref start and boundary remain; no authored item is created. |
| P04G21 / C150 | `[0x004b7e03,0x004b7e10)` 13 bytes all `cc`; SHA256 `0D0BB866505BC0E2D4276FCDEE1AFDC8887662D04CCE9E4BBB4C10FBA6D0F1CE`; UnionRects-to-OffsetRect boundary | Exact range/bytes/hash/zero-xref start and boundary remain; no authored item is created. |
| P04G22 / C151 | `[0x004b7e29,0x004b7e30)` 7 bytes all `cc`; SHA256 `F145ECA66705DE68FF53C6D80E34D8F9A5B535FFA157194AA98BDB68AEA4368D`; OffsetRect-to-InsetRect boundary | Exact range/bytes/hash/zero-xref start and boundary remain; no authored item is created. |
| P04G23 / C152 | `[0x004b7e7f,0x004b7e80)` 1 byte `cc`; SHA256 `1DD8312636F6A0BF3D21FA2855E63072507453E93A5CED4301B364E91C9D87D6`; InsetRect-to-PointInRect boundary | Exact range/byte/hash/zero-xref start and boundary remain; no authored item is created. |
| P04G24 / C153 | `[0x004b7ea7,0x004b7eb0)` 9 bytes all `cc`; SHA256 `57C1D0AAEF1222FC7F655F011049271D3A843395335212156E61D3850BEB51CE`; PointInRect-to-predicate boundary | Exact range/bytes/hash/zero-xref start and boundary remain; no authored item is created. |
| P04G25 / C154 | `[0x004b7ecd,0x004b7ed0)` 3 bytes all `cc`; SHA256 `E668F0A1B72560CED14C54488A25335D11336448950BB6485267EBC5EB3FECEE`; predicate boundary | Exact range/bytes/hash/zero-xref start and boundary remain; no authored item is created. |
| P04G26 / C155 | `[0x004b7f22,0x004b7f30)` 14 bytes all `cc`; SHA256 `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356`; RectsEquivalent-to-RectContainsRect boundary | Exact range/bytes/hash/zero-xref start and boundary remain; no authored item is created. |
| P04G27 / C156 | `[0x004b7f87,0x004b7f90)` 9 bytes all `cc`; SHA256 `57C1D0AAEF1222FC7F655F011049271D3A843395335212156E61D3850BEB51CE`; free-helper-to-anchor-island boundary | Exact range/bytes/hash/zero-xref start and boundary remain; no authored item is created. |
| P04G28 / C157 | `[0x004b8004,0x004b8010)` 12 bytes all `cc`; SHA256 `A0D08A155AA4E9AADD5DA959565DE99ACC8DC9DBDA96EC3852DDE76C97330902`; table-tail-to-anchor-helper boundary | Exact range/bytes/hash/zero-xref start and boundary remain; no authored item is created. |
| P04G29 / C158 | `[0x004b8194,0x004b81a0)` 12 bytes all `cc`; SHA256 `A0D08A155AA4E9AADD5DA959565DE99ACC8DC9DBDA96EC3852DDE76C97330902`; anchor-island-to-WideStringHashHelper boundary | Exact range/bytes/hash/zero-xref start and boundary remain; no authored item is created. |
| P04G30 / C159 | `[0x004b81eb,0x004b81f0)` 5 bytes all `cc`; SHA256 `992CF51486F901AA1AA7D1F63E18C150C9156166E08E0B9E59CC3FAF98177329`; excluded-neighbor boundary | Exact range/bytes/hash/zero-xref start and boundary remain; no authored item is created. |
| P04G31 / C160 | `[0x004b821e,0x004b8220)` 2 bytes all `cc`; SHA256 `E3966E3275BE536A16092EC0CADF1638F718218E616FBBE8FF1C5E67FFF4DEF2`; excluded-neighbor boundary | Exact range/bytes/hash/zero-xref start and boundary remain; no authored item is created. |
| P04G32 / C161 | `[0x004b8284,0x004b8290)` 12 bytes all `cc`; SHA256 `A0D08A155AA4E9AADD5DA959565DE99ACC8DC9DBDA96EC3852DDE76C97330902`; FieldMap-helper-to-axis-helper boundary | Exact range/bytes/hash/zero-xref start and boundary remain; no authored item is created. |
| P04G33 / C162 | `[0x004b83ae,0x004b83b0)` bytes `66 90`; SHA256 `88174BA925C5691BFF5CF2698A670490725C2F586FD946282B314EA52D9C24CE`; axis-body-to-table boundary | Exact range/bytes/hash/zero-xref start and boundary remain; no authored item is created. |
| P04G34 / C163 | `[0x004b83c5,0x004b83d0)` 11 bytes all `cc`; SHA256 `3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943`; axis-table-to-GeneralPurposePanel boundary | Exact range/bytes/hash/zero-xref start and boundary remain; no authored item is created. |

Already-present function protections:

For large fanout sets, `xref-manifest SHA256` is computed over the complete terminal set sorted lexically as comma-joined `source-address:ref-kind` records. The exact count plus digest is the deterministic whole-set contract; the seven-reference set for P13 is also listed literally.

| ID | Exact current state | Required unchanged readback |
| --- | --- | --- |
| P05 | [0x004b78f0,0x004b7908) `RectBounds_Offset`; type `void __thiscall(RectBounds *this, int deltaX, int deltaY)`; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; deltaX@0x8/4:int; deltaY@0xc/4:int`; AR absent; AP absent; FR `Source void RectBounds::Offset(int deltaX, int deltaY); incidental EAX is compiler lowering, not a return contract.`; FP absent; body SHA256 `73B3B310B04C3E8A4F07A8C314842C6BFE60C0A3B2C4DBDFE1ED0B131762D76D`; 209 inbound xrefs; xref-manifest SHA256 `33C5F9583616FB2AC5F4A90BCC0ABA75B6BA9013D87A1817565AD2E3F50FA5A8` | Preserve the literal range/name/type/frame/four channels/body and exact 209-record xref manifest. No mutation is authorized. |
| P06 | [0x004b7c30,0x004b7c43) `InitPointPair`; type `void __cdecl(Point *point, int y, int x)`; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; point@0x8/4:Point *; y@0xc/4:int; x@0x10/4:int`; AR absent; AP absent; FR `Initializes Point in the project source order { y, x }; the first scalar is y and the second is x.`; FP absent; body SHA256 `84E31D75F4D12E280D48D1BA8FDE30289D5E365F7E541922CDDB951147C3A4B0`; 102 inbound xrefs; xref-manifest SHA256 `D1A32963A7E1DCA21221BFA8BFAC7361B0D54EC7DCAFA0B5CD13CA74446EA776` | Preserve the literal range/name/type/frame/four channels/body and exact 102-record xref manifest. No mutation is authorized. |
| P07 | [0x004b7c50,0x004b7c6f) `InitRectBounds`; type `void __cdecl(struct RectBounds *bounds, int left, int top, int right, int bottom)`; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; bounds@0x8/4:struct RectBounds *; left@0xc/4:int; top@0x10/4:int; right@0x14/4:int; bottom@0x18/4:int`; AR absent; AP absent; FR `Initializes RectBounds fields in left, top, right, bottom order.`; FP absent; body SHA256 `B3F0737F09A5EDDFEE628A4B9CAE13148F226BDD086B16EF46FFE7B61A8364FA`; 1,731 inbound xrefs; xref-manifest SHA256 `5251B755FF879798D7094CCDCA6A6D49D8A3043C1F2A269F8C9DC6298BAC82F5` | Preserve the literal range/name/type/frame/four channels/body and exact 1,731-record xref manifest. No mutation is authorized. |
| P08 | [0x004b7cc0,0x004b7d69) `IntersectRects`; type `bool __cdecl(const struct RectBounds *firstBounds, const struct RectBounds *secondBounds, struct RectBounds *outBounds)`; frame `var_18@0xc/16:_OWORD; var_4@0x20/4:_DWORD; __saved_registers@0x24/4:_DWORD; __return_address@0x28/4:_UNKNOWN *; firstBounds@0x2c/4:const struct RectBounds *; secondBounds@0x30/4:const struct RectBounds *; outBounds@0x34/4:struct RectBounds *`; AR absent; AP absent; FR `IntersectRects(firstBounds, secondBounds, outBounds); rejects empty inputs/results and returns whether a valid intersection was produced.`; FP absent; body SHA256 `368305BDFB1C13174C3B4F96CA69F4AC3AA353991BE78C641BF54459CD7C738A`; 91 inbound xrefs; xref-manifest SHA256 `CB74C26E358A4DBEEB79B51D5F9DF29D55FA836FE0C982F9162678FA21355F6A` | Preserve the literal range/name/type/frame/four channels/body and exact 91-record xref manifest. No mutation is authorized. |
| P09 | [0x004b7d70,0x004b7e03) `UnionRects`; type `void __cdecl(const RectBounds *left, const RectBounds *right, RectBounds *outBounds)`; frame `var_C@0x8/4:_DWORD; var_8@0xc/4:_DWORD; var_4@0x10/4:_DWORD; __saved_registers@0x14/4:_DWORD; __return_address@0x18/4:_UNKNOWN *; left@0x1c/4:const RectBounds *; right@0x20/4:const RectBounds *; outBounds@0x24/4:RectBounds *`; AR absent; AP absent; FR `Shared source-facing rectangle bounding-union helper used as UnionRects(left, right, outBounds).`; FP absent; body SHA256 `042A31FED298F47D670C6B8278FA423B45936DEE642A5B3AB2CFD5FAF8692855`; 37 inbound xrefs; xref-manifest SHA256 `EA93A818A0E1BDC6DD80D5F8238E9B55A972AC75A97E9BB814E5448475923B8E` | Preserve the literal range/name/type/frame/four channels/body and exact 37-record xref manifest. No mutation is authorized. |
| P10 | [0x004b7e10,0x004b7e29) `NexusTK_OffsetRect`; type `void __cdecl(RectBounds *bounds, int deltaX, int deltaY)`; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; bounds@0x8/4:RectBounds *; deltaX@0xc/4:int; deltaY@0x10/4:int`; AR absent; AP absent; FR `Source rectangle helper OffsetRect(RectBounds *, int, int). Adds deltaX/deltaY to both edges; incidental EAX is not a source return contract.<newline>IDA uses NexusTK_OffsetRect only to avoid collision with the imported Win32 OffsetRect symbol at 0x0060d400. The recovered source-facing spelling for this project-local RectBounds helper is OffsetRect.`; FP absent; body SHA256 `408F1D0F4ECBB761BD2216A98F1AE73BD92B59DD491453F4FC21315A80688D84`; 368 inbound xrefs; xref-manifest SHA256 `1BDDD190B37AE5646AAC0FD33F9DDBF490EEEF4FF4DBCE4BD5D482559550C40E` | Preserve the literal range/name/type/frame/four channels/body and exact 368-record xref manifest. No mutation is authorized. `<newline>` denotes the literal embedded line break in FR. |
| P11 | [0x004b7e80,0x004b7ea7) `PointInRect`; type `bool __cdecl(int y, int x, const RectBounds *bounds)`; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; row@0x8/4:int; column@0xc/4:int; bounds@0x10/4:const MapRect *`; AR absent; AP absent; FR `Half-open containment test: bounds->left <= x < bounds->right and bounds->top <= y < bounds->bottom.`; FP absent; body SHA256 `EA5046055A47A9903359495176EC27AC0259C78711E1AD60A5B9055F1CF65B4E`; 270 inbound xrefs; xref-manifest SHA256 `715E26A19D1BAC52D1F1A3F8BAA83946A3F8FE12420F156AE10701A2C44AE21D` | Preserve the literal range/name/type/four channels/body and exact 270-record xref manifest. Permit only I64-I66's row-local frame changes, ending with the complete final frame in I66. |
| P12 | [0x004b7eb0,0x004b7ecd) `IsRectEmptyOrInvalid`; type `bool __cdecl(const struct RectBounds *bounds)`; frame `__saved_registers@0x0/4:_DWORD; __return_address@0x4/4:_UNKNOWN *; bounds@0x8/4:const struct RectBounds *`; AR absent; AP absent; FR `Returns true when bottom <= top or right <= left.`; FP absent; body SHA256 `4A34AC2FA53027D2CAF71C076C38210A5C2431E0B89F65CC11B2C845161E85BA`; 32 inbound xrefs; xref-manifest SHA256 `F2CC4329E8B46448AADFD6E02907292C57FE4CCCA6D9139971E0EB230D783B55` | Preserve the literal range/name/type/frame/four channels/body and exact 32-record xref manifest. No mutation is authorized. |
| P13 | [0x004b7ed0,0x004b7f22) `RectsEquivalent`; type `bool __cdecl(const RectBounds *firstBounds, const RectBounds *secondBounds)`; frame `__saved_registers@0x8/4:_DWORD; __return_address@0xc/4:_UNKNOWN *; firstBounds@0x10/4:const RectBounds *; secondBounds@0x14/4:const RectBounds *`; AR absent; AP absent; FR `Source rectangle equivalence predicate used after virtual GetScreenBounds; treats two empty rectangles as equivalent and otherwise compares all four edges.`; FP absent; body SHA256 `71EBA573E1AC2E9BDCFE975F56BA66E7B2BFB4A1A2242618F81E2FE281D6DC67`; xrefs exactly `{0x4561ef:code,0x4b8e68:code,0x4f1771:code,0x4f184f:code,0x53778b:code,0x554ac3:code,0x5a5b90:code}`; xref-manifest SHA256 `D274207B10C1285EDF8E431E720EAED5642A63BA9EDB3AFC5324E844C5B30515` | Preserve the literal range/name/type/frame/four channels/body and exact seven-record xref set. No mutation is authorized. |

Safety rule: no destination collision, literal prestate drift, mutation-response error, persisted-IDB type drift, decompiler/public presentation outside the row-specific permitted set, body/range/hash/xref/table/alignment/type-layout drift, non-permitted frame delta, or comment-channel drift is acceptable. The supervisor must stop immediately on the first mismatch, perform no later endpoint, perform no save, and discard the unsaved worker. After I66, one complete final reread must prove that the only changes from the fresh transaction prestate are ten exact function definitions, twenty-one exact function names, twenty-one exact function declarations with only their enumerated frame deltas, twenty-one exact FP comments, and PointInRect's two exact stack names plus one exact stack type. It must separately reconfirm every protected function body/range/hash/xref set, every unaffected frame row/offset/width, all independent AR/AP/FR channels, all unmodified FP channels, both UDTs, both literals, five compiler-data items, all 34 alignment spans, destination-name uniqueness, and all predecessor/successor boundaries. This report does not authorize B001 to mutate or save IDA.

## First-Draft C++ Recommendation

- Eligible: all thirty authored source functions and the complete public H surface.
- CPP disposition: exact complete expected `NexusTK/ui/core/RectBounds.cpp` source follows. Owning formal channels may partition this text across the accepted pages, but the generated concatenation and order must match this block exactly.
- H disposition: exact complete expected `NexusTK/ui/core/RectBounds.h` source follows. [UID:0000BU] owns the guard/types/member declarations; [UID:00015S] and nested [UID:00015T] provide the free declarations.
- Compiler-covered/no-code: pooled literals, switch tables, alignment/padding, [UID:0001VP], and LineClip exclusion emit no source in this module.

Formal `RECONSTRUCTION_CPP CODE` target:

```cpp
#include "RectBounds.h"

bool RectBounds::IsEmptyOrInvalid() const
{
    return bottom <= top || right <= left;
}

bool RectBounds::HasSameSizeAs(const RectBounds *bounds) const
{
    return right - left == bounds->right - bounds->left &&
           bottom - top == bounds->bottom - bounds->top;
}

bool RectBounds::ContainsPoint(int y, int x) const
{
    return left <= x && x < right &&
           top <= y && y < bottom;
}

bool RectBounds::ContainsRect(const RectBounds *bounds) const
{
    if (bounds->IsEmptyOrInvalid()) {
        return true;
    }

    if (IsEmptyOrInvalid()) {
        return false;
    }

    return left <= bounds->left &&
           bounds->right <= right &&
           top <= bounds->top &&
           bounds->bottom <= bottom;
}

bool RectBounds::IntersectInto(const RectBounds *bounds, RectBounds *outBounds) const
{
    if (IsEmptyOrInvalid() || bounds->IsEmptyOrInvalid()) {
        if (outBounds != 0) {
            outBounds->left = 0;
            outBounds->top = 0;
            outBounds->right = 0;
            outBounds->bottom = 0;
        }
        return false;
    }

    RectBounds result;
    result.left = (left <= bounds->left) ? bounds->left : left;
    result.top = (top <= bounds->top) ? bounds->top : top;
    result.right = (right <= bounds->right) ? right : bounds->right;
    result.bottom = (bottom <= bounds->bottom) ? bottom : bounds->bottom;

    if (result.IsEmptyOrInvalid()) {
        if (outBounds != 0) {
            outBounds->left = 0;
            outBounds->top = 0;
            outBounds->right = 0;
            outBounds->bottom = 0;
        }
        return false;
    }

    if (outBounds != 0) {
        *outBounds = result;
    }
    return true;
}

void RectBounds::UnionInto(const RectBounds *bounds, RectBounds *outBounds) const
{
    if (IsEmptyOrInvalid()) {
        *outBounds = *bounds;
        return;
    }

    if (bounds->IsEmptyOrInvalid()) {
        *outBounds = *this;
        return;
    }

    outBounds->left = (left <= bounds->left) ? left : bounds->left;
    outBounds->top = (top <= bounds->top) ? top : bounds->top;
    outBounds->right = (right <= bounds->right) ? bounds->right : right;
    outBounds->bottom = (bottom <= bounds->bottom) ? bounds->bottom : bottom;
}

void RectBounds::SetLTRB(int leftValue, int topValue, int rightValue, int bottomValue)
{
    left = leftValue;
    top = topValue;
    right = rightValue;
    bottom = bottomValue;
}

void RectBounds::Offset(int dx, int dy)
{
    left += dx;
    top += dy;
    right += dx;
    bottom += dy;
}

void RectBounds::Inset(int dx, int dy)
{
    left += dx;
    right -= dx;
    top += dy;
    bottom -= dy;

    if (left > right) {
        left = right = (left + right) / 2;
    }

    if (top > bottom) {
        top = bottom = (top + bottom) / 2;
    }
}

bool RectBounds::IntersectWith(const RectBounds *bounds)
{
    if (bottom <= top || right <= left ||
        bounds->bottom <= bounds->top || bounds->right <= bounds->left) {
        left = 0;
        top = 0;
        right = 0;
        bottom = 0;
        return false;
    }

    const int newLeft = (left <= bounds->left) ? bounds->left : left;
    const int newTop = (top <= bounds->top) ? bounds->top : top;
    const int newRight = (right <= bounds->right) ? right : bounds->right;
    const int newBottom = (bottom <= bounds->bottom) ? bottom : bounds->bottom;

    if (newBottom <= newTop || newRight <= newLeft) {
        left = 0;
        top = 0;
        right = 0;
        bottom = 0;
        return false;
    }

    left = newLeft;
    top = newTop;
    right = newRight;
    bottom = newBottom;
    return true;
}

RectBounds *RectBounds::UnionWith(const RectBounds *bounds)
{
    if (IsEmptyOrInvalid()) {
        *this = *bounds;
        return this;
    }

    if (!bounds->IsEmptyOrInvalid()) {
        if (bounds->top < top) {
            top = bounds->top;
        }
        if (bounds->left < left) {
            left = bounds->left;
        }
        if (bottom < bounds->bottom) {
            bottom = bounds->bottom;
        }
        if (right < bounds->right) {
            right = bounds->right;
        }
    }

    return this;
}

void RectBounds::ClampWithin(int leftLimit, int topLimit, int rightLimit, int bottomLimit)
{
    if (left < leftLimit) {
        right += leftLimit - left;
        left = leftLimit;
    } else if (rightLimit < right) {
        left += rightLimit - right;
        right = rightLimit;
    }

    if (top < topLimit) {
        bottom += topLimit - top;
        top = topLimit;
    } else if (bottomLimit < bottom) {
        top += bottomLimit - bottom;
        bottom = bottomLimit;
    }
}

RectBounds *RectBounds::InsetByQuarter(RectBounds *outBounds) const
{
    const float quarterWidth = static_cast<float>(this->right - this->left) * 0.25f;
    const float quarterHeight = static_cast<float>(this->bottom - this->top) * 0.25f;

    outBounds->left = static_cast<int>(static_cast<float>(this->left) + quarterWidth + 0.5f);
    outBounds->top = static_cast<int>(static_cast<float>(this->top) + quarterHeight + 0.5f);
    outBounds->right = static_cast<int>(static_cast<float>(this->right) - quarterWidth);
    outBounds->bottom = static_cast<int>(static_cast<float>(this->bottom) - quarterHeight);
    return outBounds;
}

RectBounds *RectBounds::OutsetByHalf(RectBounds *outBounds) const
{
    const float halfWidth = static_cast<float>(this->right - this->left) * 0.5f;
    const float halfHeight = static_cast<float>(this->bottom - this->top) * 0.5f;

    outBounds->left = static_cast<int>(static_cast<float>(this->left) - halfWidth - 0.5f);
    outBounds->top = static_cast<int>(static_cast<float>(this->top) - halfHeight - 0.5f);
    outBounds->right = static_cast<int>(static_cast<float>(this->right) + halfWidth);
    outBounds->bottom = static_cast<int>(static_cast<float>(this->bottom) + halfHeight);
    return outBounds;
}

void InitPointPair(Point *point, int y, int x)
{
    point->y = y;
    point->x = x;
}

void InitRectBounds(RectBounds *bounds, int left, int top, int right, int bottom)
{
    bounds->left = left;
    bounds->top = top;
    bounds->right = right;
    bounds->bottom = bottom;
}

void InitRectBoundsFromSize(RectBounds *bounds, int left, int top, int width, int height)
{
    bounds->left = left;
    bounds->top = top;
    bounds->right = left + width;
    bounds->bottom = top + height;
}

int RectArea(const RectBounds *bounds)
{
    return (bounds->right - bounds->left) * (bounds->bottom - bounds->top);
}

bool IntersectRects(const RectBounds *firstBounds, const RectBounds *secondBounds, RectBounds *outBounds)
{
    if (firstBounds->bottom <= firstBounds->top ||
        firstBounds->right <= firstBounds->left ||
        secondBounds->bottom <= secondBounds->top ||
        secondBounds->right <= secondBounds->left) {
        if (outBounds != 0) {
            InitRectBounds(outBounds, 0, 0, 0, 0);
        }
        return false;
    }

    RectBounds result;
    result.left = (firstBounds->left <= secondBounds->left) ? secondBounds->left : firstBounds->left;
    result.top = (firstBounds->top <= secondBounds->top) ? secondBounds->top : firstBounds->top;
    result.right = (firstBounds->right <= secondBounds->right) ? firstBounds->right : secondBounds->right;
    result.bottom = (firstBounds->bottom <= secondBounds->bottom) ? firstBounds->bottom : secondBounds->bottom;

    if (result.bottom <= result.top || result.right <= result.left) {
        if (outBounds != 0) {
            InitRectBounds(outBounds, 0, 0, 0, 0);
        }
        return false;
    }

    if (outBounds != 0) {
        *outBounds = result;
    }
    return true;
}

void UnionRects(const RectBounds *firstBounds, const RectBounds *secondBounds, RectBounds *outBounds)
{
    if (firstBounds->bottom <= firstBounds->top ||
        firstBounds->right <= firstBounds->left) {
        *outBounds = *secondBounds;
        return;
    }

    if (secondBounds->bottom <= secondBounds->top ||
        secondBounds->right <= secondBounds->left) {
        *outBounds = *firstBounds;
        return;
    }

    outBounds->left = (firstBounds->left <= secondBounds->left) ? firstBounds->left : secondBounds->left;
    outBounds->top = (firstBounds->top <= secondBounds->top) ? firstBounds->top : secondBounds->top;
    outBounds->right = (firstBounds->right <= secondBounds->right) ? secondBounds->right : firstBounds->right;
    outBounds->bottom = (firstBounds->bottom <= secondBounds->bottom) ? secondBounds->bottom : firstBounds->bottom;
}

void OffsetRect(RectBounds *bounds, int dx, int dy)
{
    bounds->left += dx;
    bounds->top += dy;
    bounds->right += dx;
    bounds->bottom += dy;
}

void InsetRect(RectBounds *bounds, int dx, int dy)
{
    bounds->left += dx;
    bounds->right -= dx;
    bounds->top += dy;
    bounds->bottom -= dy;

    if (bounds->left > bounds->right) {
        const int midpoint = (bounds->left + bounds->right) / 2;
        bounds->left = midpoint;
        bounds->right = midpoint;
    }

    if (bounds->top > bounds->bottom) {
        const int midpoint = (bounds->top + bounds->bottom) / 2;
        bounds->top = midpoint;
        bounds->bottom = midpoint;
    }
}

bool PointInRect(int y, int x, const RectBounds *bounds)
{
    return bounds->left <= x && x < bounds->right &&
           bounds->top <= y && y < bounds->bottom;
}

bool IsRectEmptyOrInvalid(const RectBounds *bounds)
{
    return bounds->bottom <= bounds->top || bounds->right <= bounds->left;
}

bool RectsEquivalent(const RectBounds *firstBounds, const RectBounds *secondBounds)
{
    if (IsRectEmptyOrInvalid(firstBounds) && IsRectEmptyOrInvalid(secondBounds)) {
        return true;
    }

    return firstBounds->left == secondBounds->left &&
           firstBounds->top == secondBounds->top &&
           firstBounds->right == secondBounds->right &&
           firstBounds->bottom == secondBounds->bottom;
}

bool RectContainsRect(const RectBounds *innerBounds, const RectBounds *outerBounds)
{
    if (IsRectEmptyOrInvalid(innerBounds)) {
        return true;
    }

    if (IsRectEmptyOrInvalid(outerBounds)) {
        return false;
    }

    return outerBounds->left <= innerBounds->left &&
           innerBounds->right <= outerBounds->right &&
           outerBounds->top <= innerBounds->top &&
           innerBounds->bottom <= outerBounds->bottom;
}

static void AdjustRectAnchorAxis(int anchor, int offset, int *firstLow, int *firstHigh, int *secondLow, int *secondHigh);

static int Transpose3x3AnchorIndex(int anchor)
{
    switch (anchor) {
    case 0:
        return 0;
    case 1:
        return 3;
    case 2:
        return 6;
    case 3:
        return 1;
    case 4:
        return 4;
    case 5:
        return 7;
    case 6:
        return 2;
    case 7:
        return 5;
    case 8:
        return 8;
    default:
        return anchor;
    }
}

static void AdjustRectPairForAnchor(const RectBounds *firstBounds, const RectBounds *secondBounds, int anchor, RectBounds *outFirstBounds, RectBounds *outSecondBounds)
{
    *outFirstBounds = *firstBounds;
    *outSecondBounds = *secondBounds;

    AdjustRectAnchorAxis(anchor, 0, &outFirstBounds->left, &outFirstBounds->right, &outSecondBounds->left, &outSecondBounds->right);

    const int transposedAnchor = Transpose3x3AnchorIndex(anchor);
    AdjustRectAnchorAxis(transposedAnchor, 0, &outFirstBounds->top, &outFirstBounds->bottom, &outSecondBounds->top, &outSecondBounds->bottom);
}

static void AdjustRectPairForAnchorWithOffsets(const RectBounds *firstBounds, const RectBounds *secondBounds, int anchor, int horizontalOffset, int verticalOffset, RectBounds *outFirstBounds, RectBounds *outSecondBounds)
{
    *outFirstBounds = *firstBounds;
    *outSecondBounds = *secondBounds;

    AdjustRectAnchorAxis(anchor, horizontalOffset, &outFirstBounds->left, &outFirstBounds->right, &outSecondBounds->left, &outSecondBounds->right);

    const int transposedAnchor = Transpose3x3AnchorIndex(anchor);
    AdjustRectAnchorAxis(transposedAnchor, verticalOffset, &outFirstBounds->top, &outFirstBounds->bottom, &outSecondBounds->top, &outSecondBounds->bottom);
}

static void AdjustRectAnchorAxis(int anchor, int offset, int *firstLow, int *firstHigh, int *secondLow, int *secondHigh)
{
    const int originalSecondLow = *secondLow;
    const int originalSecondHigh = *secondHigh;
    const int secondSpan = originalSecondHigh - originalSecondLow;
    const int originalFirstLow = *firstLow;
    const int firstSpan = *firstHigh - originalFirstLow;
    const int spanDelta = firstSpan - secondSpan;

    int anchorOffset;
    switch (anchor) {
    case 0:
    case 3:
    case 6:
        anchorOffset = 0;
        break;
    case 1:
    case 4:
    case 7:
        anchorOffset = spanDelta / 2;
        break;
    case 2:
    case 5:
    case 8:
        anchorOffset = spanDelta;
        break;
    default:
        return;
    }

    if (offset < anchorOffset - firstSpan) {
        *firstLow = *firstHigh;
        *secondHigh -= secondSpan;
        return;
    }

    if (spanDelta <= 0) {
        if (offset < anchorOffset) {
            *firstLow = anchorOffset + originalFirstLow - offset;
            *secondHigh += offset + spanDelta - anchorOffset;
            return;
        }

        if (offset < anchorOffset - spanDelta) {
            *secondLow = offset + originalSecondLow - anchorOffset;
            *secondHigh += offset + spanDelta - anchorOffset;
            return;
        }
    } else {
        if (offset < anchorOffset - spanDelta) {
            *firstLow = anchorOffset + originalFirstLow - offset;
            *secondHigh += offset + spanDelta - anchorOffset;
            return;
        }

        if (offset < anchorOffset) {
            *firstLow = anchorOffset + originalFirstLow - offset;
            *firstHigh += anchorOffset - spanDelta - offset;
            return;
        }
    }

    if (offset >= anchorOffset + secondSpan) {
        *secondLow = originalSecondHigh;
        *firstHigh -= firstSpan;
    } else {
        *secondLow = offset + originalSecondLow - anchorOffset;
        *firstHigh += anchorOffset - spanDelta - offset;
    }
}
```

Formal `RECONSTRUCTION_H CODE` target:

```h
#ifndef NEXUSTK_UI_CORE_RECTBOUNDS_H
#define NEXUSTK_UI_CORE_RECTBOUNDS_H

struct Point
{
    int y;
    int x;
};

struct RectBounds
{
    int left;
    int top;
    int right;
    int bottom;

    bool IsEmptyOrInvalid() const;
    bool HasSameSizeAs(const RectBounds *bounds) const;
    bool ContainsPoint(int y, int x) const;
    bool ContainsRect(const RectBounds *bounds) const;
    bool IntersectInto(const RectBounds *bounds, RectBounds *outBounds) const;
    void UnionInto(const RectBounds *bounds, RectBounds *outBounds) const;
    void SetLTRB(int leftValue, int topValue, int rightValue, int bottomValue);
    void Offset(int dx, int dy);
    void Inset(int dx, int dy);
    bool IntersectWith(const RectBounds *bounds);
    RectBounds *UnionWith(const RectBounds *bounds);
    void ClampWithin(int leftLimit, int topLimit,
                     int rightLimit, int bottomLimit);
    RectBounds *InsetByQuarter(RectBounds *outBounds) const;
    RectBounds *OutsetByHalf(RectBounds *outBounds) const;
};

void InitPointPair(Point *point, int y, int x);
void InitRectBounds(RectBounds *bounds, int left, int top, int right, int bottom);
void InitRectBoundsFromSize(RectBounds *bounds, int left, int top, int width, int height);
int RectArea(const RectBounds *bounds);
bool IntersectRects(const RectBounds *first, const RectBounds *second, RectBounds *result);
void UnionRects(const RectBounds *first, const RectBounds *second, RectBounds *result);
void OffsetRect(RectBounds *bounds, int dx, int dy);
void InsetRect(RectBounds *bounds, int dx, int dy);
bool PointInRect(int y, int x, const RectBounds *bounds);
bool IsRectEmptyOrInvalid(const RectBounds *bounds);
bool RectsEquivalent(const RectBounds *first, const RectBounds *second);
bool RectContainsRect(const RectBounds *inner, const RectBounds *outer);

#endif
```

The source preserves exact half-open bounds, signed integer behavior, output-zeroing, midpoint collapse, floating conversion/rounding, switch defaults, and anchor clipping. It uses ordinary class/free/static functions and literals rather than IDA labels, synthetic raw wrappers, or artificial constant globals. Names follow the established project convention; private helper spellings remain explicitly inferred. The complete code is plausible Visual C++-era human source and contains no compiler-authored jump-table/vtable/RTTI bodies.

## Final Recommendation

- Keep [UID:0000N2] as `NexusTK/ui/core/RectBounds.cpp/.h` owner and set it reconstructable.
- Retain all thirty authored function ranges and exact existing page splits; do not merge across unrelated code.
- Repair source order through nested child markers: [UID:00015R] under [UID:00015Q], [UID:00015T] under [UID:00015S].
- Make [UID:00040U] and [UID:0001VP] non-emitting while preserving their evidence.
- Preserve the existing formal H declaration for `RectArea` while reparenting it; preserve private anchor helpers in CPP only.
- Preserve all 34 exact alignment spans as compiler-generated/no-code evidence at their Section 14 support destinations; do not emit them or create artificial by-memory source children.
- Historicalize `util` placement and LineClip review. Keep LineClip under Surface.
- Apply Sections 21 and 28 only through supervisor-owned Gate 2B/manual-coverage work after exact report acceptance. Section 21 includes forty independent raw-function actions in addition to the modeled-function actions: ten exact defines, ten pure renames, ten source-quality type/frame stages and ten repeatable comments, each with literal fail-closed readback and protection.
- The prior unattempted raw-modeling blocker is closed by exact item/boundary/prologue/body/xref evidence and the complete staged contracts. No future source research is deferred inside this assignment. A rebuilt-binary comparison is a later project-wide verification activity, not an unresolved ownership/source-shape question.

## Recommended Target Doc Changes

Target: `by-file/RectBounds.md`.

- Replace the sampled/current summary with the complete Section 14 inventory and Section 15 xref/caller disposition.
- Record final `NexusTK/ui/core/RectBounds.cpp/.h` placement and reject the `util` alternative as historical.
- Record exact member/free/static split, the ten evidence-time raw retained starts plus their complete staged IDA modeling handoff, compiler tables, literal ownership, unrelated neighbors, and LineClip exclusion.
- Incorporate the complete 34-row alignment inventory, exact byte classes, zero-inbound-xref evidence, owner/boundary roles, and no-code destinations C130-C163.
- Add the complete dated generated defect/repair history: command `25640` omitted `RectArea` from H; command `25804` contains it; at callback-readback command `25893`, composition misordered `Inset`/`RectArea` and the duplicate-layout page emitted an empty marker. Latest generated authority must be reread dynamically during implementation and later lifecycle verification.
- Install deterministic child/source positions and nested routes described in Section 25.
- Replace formal root composition with exact include/class/free/anchor child routes that generate the Section 22 CPP/H.
- Set `COMPLETION:95`, `CONFIDENCE:93`, `RECONSTRUCTABLE:TRUE`; retain `CANONICAL_OWNER:FILE` and the correct file-root emitter relationship.
- Preserve prior uncertain hypotheses in a dated `Historical / Superseded Assumptions` section with the evidence that rejected them.

## Recommended Support Doc Changes

| Support path | Exact incorporation/change |
| --- | --- |
| `by-class/RectBounds.md` [UID:0000BU] | Incorporate complete type/member/source-order evidence; retain sole class/H ownership; add deterministic children; update to 95/94; retain exact formal H/CPP composition. |
| `by-memory/0x004b7670-0x004b78c8.RectBoundsPredicateAndCombinationMethods.md` [UID:00022G] | Incorporate six-function literal inventory, raw/model state, exact behavior/xrefs/hashes, complete four-function staged IDA handoff and formal source; update to 95/92. |
| `by-memory/0x004b78d0-0x004b7ae8.RectBoundsMethods.md` [UID:00015Q] | Add `[[CHILDREN]]` between Offset and IntersectWith, child UID00015R position 10, complete method evidence; update to 95/94. |
| `by-memory/0x004b7910-0x004b795e.RectBoundsInset.md` [UID:00015R] | Reparent emitter to UID00015Q, retain exact formal member body/declaration and midpoint evidence; update to 95/94. |
| `by-memory/0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers.md` [UID:00022H] | Incorporate exact literal dependencies, raw bounds, source signatures, complete two-function staged IDA handoff and no-global disposition; update to 95/92. |
| `by-memory/0x0061a880-0x0061a884.RectBoundsQuarterScaleConstant.md` [UID:00040U] | Retain exact bytes/refs and historical named-constant possibility, set emitter blank, formal CPP/H blank, explain compiler literal regeneration; update to 94/96. |
| `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md` [UID:00015S] | Add nested `[[CHILDREN]]` after InitRectBoundsFromSize in CPP and H, child UID00015T position 10, complete twelve-function island accounting; update to 95/95. |
| `by-memory/0x004b7ca0-0x004b7cb6.RectArea.md` [UID:00015T] | Preserve the existing formal CPP and H `int RectArea(const RectBounds *bounds);`, reparent emitter to UID00015S without recreating/overwriting either channel, retain exact signed behavior; update from current 88/92 to 95/93. |
| `by-memory/0x004b7f90-0x004b8194.RectAnchorTransformHelpers.md` [UID:00022I] | Incorporate exact three raw helper/code-table boundaries, calls, hashes, inferred static names, complete three-function staged IDA handoff and formal private CPP; update to 95/92. |
| `by-memory/0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper.md` [UID:00022L] | Incorporate exact code/table/padding split, four callers, frame/type recommendation and private CPP; update to 95/93. |
| `by-memory/0x004b73b0-0x004b7661.FramePartPane.md` | Preserve its exact end and record C130 as the 15-byte `cc` boundary after it, owned as compiler alignment rather than source continuation; no score/emitter change. |
| `by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md` [UID:00022J] | Preserve unrelated ownership and record C158/C159 as exact leading/trailing `cc` boundary alignment; no source/emitter change. |
| `by-memory/0x004b81f0-0x004b821e.FileExists.md` [UID:00022K] | Preserve PathUtil ownership and record C159/C160 as exact leading/trailing `cc` boundary alignment; no source/emitter change. |
| `by-memory/0x004b8220-0x004b8284.BuildFieldMapTextPath.md` [UID:00015U] | Preserve FieldMap ownership and record C160/C161 as exact leading/trailing `cc` boundary alignment; no source/emitter change. |
| `by-memory/-ignored.md` | Preserve and normalize the exact compiler-alignment entries for C130-C161/C163 at their current address-order anchors; retain `0x004b83ae-0x004b83b0` under UID00022L because it is in-range NOP alignment, not an ignored external span. Do not merge any listed span into authored C++. |
| `by-type/by-struct/RectBoundsLayout.md` [UID:0001VP] | Retain duplicate-layout evidence/history, clear emitter, keep formal CPP/H blank, link sole class owner; update to 94/95. |
| `by-memory/0x004bb2e0-0x004bb5a5.LineClipHelpers.md` [UID:00016H] | Preserve current Surface ownership and exact render caller evidence; no source/emitter change. |
| `by-file/Surface.md` [UID:0000OC] | Preserve LineClip route; add cross-reference rejecting RectBounds ownership only if missing. |
| `by-project-structure/proposed-source-tree.md` | Finalize RectBounds under `NexusTK/ui/core`; remove current-facing LineClip review-bucket wording and retain it as dated history; state LineClip belongs to Surface.cpp. Dated inspected identity: SHA256 `5A16870BFECEA170D65DE8912E22856229E03A3A3F29BD07BC7F1AD0F533B34A`, 328,274 bytes/2,161 lines. Later callback must reread current identity. |

No by-global, by-resource, by-item, by-enum, or by-vtable page requires creation: exhaustive searches found no file-owned entity of those kinds.

## Score And Metadata Recommendation

| UID | Current | Recommended | Owner/emitter/reconstructable disposition | Reason not higher |
| --- | --- | --- | --- | --- |
| 0000N2 | 90/85 | 95/93 | FILE root; reconstructable true | Code-emitting 95 ceiling; original private spellings/rebuilt binary absent. |
| 0000BU | 91/90 | 95/94 | owner/emitter 0000N2 retained | Same code-emitting ceiling. |
| 00022G | 91/90 | 95/92 | class/file route retained | Code-emitting 95 ceiling; four inferred source names lack original symbols. |
| 00015Q | 91/91 | 95/94 | route retained; nested 00015R | Code-emitting 95 ceiling. |
| 00015R | 90/92 | 95/94 | emitter changes to 00015Q | Code-emitting 95 ceiling; original member spelling not symbol-proven. |
| 00022H | 89/90 | 95/92 | route retained | Code-emitting 95 ceiling; two source spellings inferred. |
| 00040U | 86/92 | 94/96 | owner 0000N2 retained; emitter blank | Original compiler pooling/source literal spelling not recoverable. |
| 00015S | 92/93 | 95/95 | route retained; nested 00015T | Code-emitting 95 ceiling. |
| 00015T | 88/92 | 95/93 | emitter changes to 00015S; existing formal CPP/H preserved | Code-emitting 95 ceiling; original free-helper spelling not symbol-proven. |
| 00022I | 89/90 | 95/92 | file route retained | Code-emitting 95 ceiling; three static-helper spellings inferred. |
| 00022L | 89/90 | 95/93 | file route retained | Code-emitting 95 ceiling; static-helper spelling inferred. |
| 0001VP | 85/88 | 94/95 | owner 0000N2 retained; emitter blank | Duplicate support page, not independent source. |
| 00016H | 90/91 | unchanged | owner/emitter 0000OC retained | Support-only exclusion; no target change. |

Score-improvement work resolved placement, ownership, complete inventory, raw-role, member/free/static split, constants, every one of the 34 exact table/alignment complements, source order, the historical missing-H defect and current declaration-preservation requirement, duplicate emitter, LineClip ownership, and the prior raw-function modeling blocker. All code-emitting pages with complete formal source and staged IDA handoff reach the 95 completion ceiling; confidence remains below certainty only for inferred private spellings and absent rebuilt-binary comparison. Scores are not held down by unattempted research.

## Open Questions With Attempted Resolution

| Question found | Evidence checked | Best supported resolution |
| --- | --- | --- |
| `ui/core` or `util`? | Current routes/includes, source-tree conventions, consumers, neighboring modules | `ui/core` final; `util` historical/rejected. |
| Are zero-xref raw starts dead? | Exact bodies, boundaries, pointer/immediate routes, neighboring padding, generated source | Retained authored functions; no deletion/no-code evidence. Zero xrefs are a confidence fact, not a reason to leave them unmodeled. |
| Can all ten raw starts be modeled safely? | Literal raw item state, exact body hashes, prologues, ends, adjacent alignment/table items, zero-xref sets, public endpoint schema and deterministic frame rules | Yes. Section 21 supplies an independent fail-closed define, pure rename, source-quality type/frame and repeatable-comment contract for each start. Actual mutation remains a supervisor Gate 2B role boundary, not deferred B-agent research. |
| Is 0.25f an authored global? | Exact bytes, two use sites, absent type/comments, compiler pooling | Inline source literal; data page non-emitting. |
| Is 0.5f file-owned? | Complete sixty-ref set | No; shared pooled literal. |
| Is RectBoundsLayout independent source? | UDT search, class H, duplicate fields | No; non-emitting support only. |
| Does LineClip belong here? | Complete direct caller/callee routes and current Surface source | No; Surface-owned. |
| Are anchor tables source arrays? | Dispatch refs, embedded positions, switch behavior | No; compiler-lowered jump/index tables. |
| Do internal gaps hide source/data items? | Exact bytes for all 34 half-open spans, every adjacent function/table boundary, and inbound xref query at every span start | No; 33 spans are pure `cc`, one is `66 90`, all starts have zero inbound xrefs, and every span is compiler alignment with an exact support destination. |
| What are exact private helper names? | Behavior, call graph, existing docs, project style | Use the descriptive names in Section 22; mark inferred. Do not retain `sub_` names in source. |

No investigable source-quality question remains open. Exact original private spelling, compiler identity and future rebuilt-binary comparison are confidence limits, not unresolved implementation work; the ten current raw starts now have complete item-specific staged modeling contracts.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

The following are literal supervisor-owned replacements/inserts. B001 must not edit any manual coverage report.

`by-file/-coverage-report.md`: replace the existing UID0000N2 row between UID0000N1 and UID0000N3 with:

`- [UID:0000N2][RectBounds](by-file/RectBounds.md) : reconstructable : 95% : very-strong : Complete NexusTK/ui/core/RectBounds.cpp/.h geometry unit with exact thirty-function member/free/static inventory, exact Point/RectBounds layouts, complete staged IDA handoff for all ten evidence-time raw starts, quarter/shared-half literal dispositions, four compiler-covered anchor-table islands and 34 exact no-code alignment spans, deterministic child/source order, complete formal CPP/H including RectArea, non-emitting duplicate layout/literal support, generated closure contract, and render-owned LineClip exclusion.`

`by-class/-coverage-report.md`: replace UID0000BU between UID0000BT and UID0000BV with:

`- [UID:0000BU][RectBounds](by-class/RectBounds.md) : reconstructable : 95% : very-strong : Exact 16-byte four-int RectBounds and 8-byte Point declarations emitted once through NexusTK/ui/core/RectBounds.h, with complete fourteen-member API, y-before-x contracts, exact member-child ordering, free/static helpers outside the class, no vtable/RTTI/constructor invention, and complete duplicate-free CPP/H route.`

`by-memory/-coverage-report.md`: replace the existing rows at their current address-order positions with:

`    - [UID:00022G][0x004b7670-0x004b78c8.RectBoundsPredicateAndCombinationMethods](by-memory/0x004b7670-0x004b78c8.RectBoundsPredicateAndCombinationMethods.md) 0x004b7670-0x004b78c8 | class-method-cluster | RectBoundsPredicateAndCombinationMethods : reconstructable : 95% : very-strong : Exact six-member predicate/contain/intersect/union cluster with complete formal CPP/H, modeled and raw boundaries, complete staged IDA handoff for all four raw members, full behavior, literal xref/no-xref evidence, exact hashes, source signatures, all six exact internal/end cc alignment spans, and class/file route.`

`    - [UID:00015Q][0x004b78d0-0x004b7ae8.RectBoundsMethods](by-memory/0x004b78d0-0x004b7ae8.RectBoundsMethods.md) 0x004b78d0-0x004b7ae8 | class-method-cluster | RectBoundsMethods : reconstructable : 95% : very-strong : Complete SetLTRB/Offset/Inset/IntersectWith/UnionWith/ClampWithin member sequence with exact formal CPP/H, UID00015R nested at its physical source position, exact callers/frames/hashes, all six exact cc member/boundary alignment spans, and deterministic RectBounds class route.`

`        - [UID:00015R][0x004b7910-0x004b795e.RectBoundsInset](by-memory/0x004b7910-0x004b795e.RectBoundsInset.md) 0x004b7910-0x004b795e | class-method | RectBoundsInset : reconstructable : 95% : very-strong : Exact RectBounds::Inset body with three callers, four-int mutation, signed midpoint collapse, complete formal member declaration/definition, and nested source-order emission through UID00015Q.`

`    - [UID:00022H][0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers](by-memory/0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers.md) 0x004b7af0-0x004b7c21 | raw-function-cluster | RectBoundsQuarterScaleHelpers : reconstructable : 95% : very-strong : Exact InsetByQuarter/OutsetByHalf bodies and bounds with formal CPP/H, complete two-function staged IDA handoff, literal 0.25f/0.5f behavior, no-xref retained-source evidence, exact helper/end cc alignment spans, and compiler-pooled constant disposition.`

`    - [UID:00015S][0x004b7c30-0x004b7f87.RectGeometryHelpers](by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md) 0x004b7c30-0x004b7f87 | function-cluster | RectGeometryHelpers : reconstructable : 95% : very-strong : Complete twelve-function Point/RectBounds free-helper island with exact behavior/callers/types, all twelve exact cc complement spans, formal CPP/H, UID00015T RectArea nested at physical source order, and complete generated declaration/definition contract.`

`        - [UID:00015T][0x004b7ca0-0x004b7cb6.RectArea](by-memory/0x004b7ca0-0x004b7cb6.RectArea.md) 0x004b7ca0-0x004b7cb6 | free-helper | RectArea : reconstructable : 95% : very-strong : Exact signed width-times-height helper with four callers, complete CPP definition and H declaration, literal frame/hash evidence, and nested emission through UID00015S.`

`    - [UID:00022I][0x004b7f90-0x004b8194.RectAnchorTransformHelpers](by-memory/0x004b7f90-0x004b8194.RectAnchorTransformHelpers.md) 0x004b7f90-0x004b8194 | raw-function-cluster | RectAnchorTransformHelpers : reconstructable : 95% : very-strong : Complete three-function file-local 3x3 anchor transform family with exact code/table boundaries, complete staged IDA handoff, both exact in-range/end cc alignment spans, axis-helper calls, hashes, source-facing inferred names, formal private CPP, and compiler-covered switch data.`

`    - [UID:00022L][0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper](by-memory/0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper.md) 0x004b8290-0x004b83c5 | function-with-switch-data | RectAnchorAxisAdjustHelper : reconstructable : 95% : very-strong : Complete file-local axis adjustment helper with four exact callers, full clipping behavior/formal CPP, exact frame/hash, two compiler switch tables, exact 66 90 body-to-table alignment, and exact cc successor boundary.`

Replace the current UID00016H row with the current documented support truth:

`    - [UID:00016H][0x004bb2e0-0x004bb5a5.LineClipHelpers](by-memory/0x004bb2e0-0x004bb5a5.LineClipHelpers.md) : reconstructable : 90% : very-strong : Exact render-owned ClipLineToRect/ClipLineParameter family with complete Liang-Barsky behavior, exclusive Surface/software-render caller route, formal Surface.cpp source, and explicit rejection from RectBounds ownership.`

Insert the absent UID00040U row directly after UID0002NH `FramePartPaneVtableData` and before UID0002V4 `PanelGrafPortVtableData` at the exact `0x0061a880-0x0061a884` address boundary:

`        - [UID:00040U][0x0061a880-0x0061a884.RectBoundsQuarterScaleConstant](by-memory/0x0061a880-0x0061a884.RectBoundsQuarterScaleConstant.md) 0x0061a880-0x0061a884 | read-only-float-constant | RectBoundsQuarterScaleConstant : reconstructable : 94% : very-strong : Exact 0.25f bytes and two InsetByQuarter refs with physical-neighbor exclusions, compiler-pooled inline-literal source disposition, retained evidence page, blank formal CPP/H, and no emitter.`

`by-type/by-struct/-coverage-report.md`: replace the existing UID0001VP row at its current struct-list position between `PaneLayout` and `ScheduledTimerEvent`:

`- [UID:0001VP][RectBoundsLayout](by-type/by-struct/RectBoundsLayout.md) : reconstructable : 94% : very-strong : Exact duplicate four-int RectBounds layout support with left/top/right/bottom at +0/+4/+8/+0c, sole declaration ownership in UID0000BU, no distinct IDA UDT/source entity, blank formal CPP/H, and no emitter.`

## Follow-Up Actions

- Supervisor: perform exact Gate 1 review; if accepted, issue the ordinary implementation callback for C001-C048/C050 and alignment/documentation claims C130-C163; verify generated CPP/H; apply C049 manual coverage; then execute the complete Section 21 Gate 2B transaction, including C055-C074/C097-C106/C164-C173, with fresh preflight/backup/rollback/save discipline.
- A-agent actions: none.
- B001 role disposition: ordinary implementation occurs only under an explicit callback for this artifact; manual coverage, Gate 2B, execution, movement, and archival remain supervisor-owned. This durable role statement makes no prediction about later reassignment.
- Lifecycle authority remains supervisor/validator-owned; this report contains no readiness marker.

## Confidence

- Recommendation confidence: very high.
- Score confidence: high; every prior blocker, all ten raw-function modeling paths, and every internal alignment span were investigated, and the remaining caps are explicit.
- Remaining uncertainty: exact original private helper spellings and bit-for-bit rebuilt-binary equivalence. Neither changes behavior, ownership, source order, formal declarations, complete source disposition, or the deterministic staged IDA handoff.

## Validator Results

- Commands run: none; report-only phase explicitly forbids validators.
- Results: not applicable in report-only research.
- Callback plan: scoped `--mode file --apply` validation for every changed ordinary page, then one coherent `--wait-generated` refresh from `source-3/project-documentation`, followed by physical current reread of RectBounds.cpp/.h.
- Generated acceptance: exactly thirty complete definitions in Section 14 order; complete H with one guard and `RectArea`; no duplicate declaration, stub, placeholder, TODO, empty-emitter marker, compiler-table body, or missing child fragment.
- Dated research output commands `000000025616`, `000000025640`, and `000000025804` are historical evidence only; `000000025893` is the snapshot physically observed in this assignment and proves the existing `RectArea` H declaration. Latest generated metadata/hashes are dynamic and must be reread during callback/final validation.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B001/research/0000N2-RectBounds-file-source-quality.md` only.
- Renamed: none.
- Report lifecycle boundary: execution/archive status is supervisor-owned and authoritative only from the artifact's current path plus validator-owned status/history metadata. During this report-only creation pass B001 ran no validator or report lifecycle command and did not move the artifact.

## Implementation Tracking Checklist

Exact ledger twin. All 173 report-only rows remain unchecked and `proposed`; no ordinary, IDA, manual-coverage, validator, or lifecycle action is claimed.

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [ ] | C001 | 0000N2 | The inferred RectBounds.cpp/.h unit owns exactly the thirty authored functions, four bounded compiler-table islands, and 34 no-code alignment spans in the complete inventory. | Very high | Complete range/item/source audit. | UID0000N2 whole-file inventory | incorporate | proposed |
| [ ] | C002 | 00022G | 0x004b7670 RectBounds::IsEmptyOrInvalid is an authored const member. | High | Bytes, behavior, boundaries, docs and source route. | 00022G behavior/formal source | incorporate | proposed |
| [ ] | C003 | 00022G | 0x004b7690 RectBounds::HasSameSizeAs is a retained raw const member. | High | Bytes, behavior, boundaries, docs and source route. | 00022G behavior/formal source | incorporate | proposed |
| [ ] | C004 | 00022G | 0x004b76d0 RectBounds::ContainsPoint uses source parameter order y, x. | High | Bytes, behavior, boundaries, docs and source route. | 00022G behavior/formal source | incorporate | proposed |
| [ ] | C005 | 00022G | 0x004b7700 RectBounds::ContainsRect is a retained raw const member. | High | Bytes, behavior, boundaries, docs and source route. | 00022G behavior/formal source | incorporate | proposed |
| [ ] | C006 | 00022G | 0x004b7780 RectBounds::IntersectInto is a retained raw const member with optional output. | High | Bytes, behavior, boundaries, docs and source route. | 00022G behavior/formal source | incorporate | proposed |
| [ ] | C007 | 00022G | 0x004b7830 RectBounds::UnionInto is a retained raw const member. | High | Bytes, behavior, boundaries, docs and source route. | 00022G behavior/formal source | incorporate | proposed |
| [ ] | C008 | 00015Q | 0x004b78d0 RectBounds::SetLTRB writes the four exact fields. | High | Bytes, behavior, boundaries, docs and source route. | 00015Q behavior/formal source | incorporate | proposed |
| [ ] | C009 | 00015Q | 0x004b78f0 RectBounds::Offset translates all four edges. | High | Bytes, behavior, boundaries, docs and source route. | 00015Q behavior/formal source | incorporate | proposed |
| [ ] | C010 | 00015R | 0x004b7910 RectBounds::Inset shrinks and midpoint-collapses inverted axes. | High | Bytes, behavior, boundaries, docs and source route. | 00015R behavior/formal source | incorporate | proposed |
| [ ] | C011 | 00015Q | 0x004b7960 RectBounds::IntersectWith mutates to intersection or zero. | High | Bytes, behavior, boundaries, docs and source route. | 00015Q behavior/formal source | incorporate | proposed |
| [ ] | C012 | 00015Q | 0x004b7a00 RectBounds::UnionWith mutates and returns this. | High | Bytes, behavior, boundaries, docs and source route. | 00015Q behavior/formal source | incorporate | proposed |
| [ ] | C013 | 00015Q | 0x004b7a80 RectBounds::ClampWithin translates the rectangle into limits. | High | Bytes, behavior, boundaries, docs and source route. | 00015Q behavior/formal source | incorporate | proposed |
| [ ] | C014 | 00022H | 0x004b7af0 RectBounds::InsetByQuarter uses 0.25f and 0.5f rounding. | High | Bytes, behavior, boundaries, docs and source route. | 00022H behavior/formal source | incorporate | proposed |
| [ ] | C015 | 00022H | 0x004b7b90 RectBounds::OutsetByHalf uses the shared 0.5f literal. | High | Bytes, behavior, boundaries, docs and source route. | 00022H behavior/formal source | incorporate | proposed |
| [ ] | C016 | 00015S | 0x004b7c30 InitPointPair writes y then x. | High | Bytes, behavior, boundaries, docs and source route. | 00015S behavior/formal source | incorporate | proposed |
| [ ] | C017 | 00015S | 0x004b7c50 InitRectBounds writes left, top, right, bottom. | High | Bytes, behavior, boundaries, docs and source route. | 00015S behavior/formal source | incorporate | proposed |
| [ ] | C018 | 00015S | 0x004b7c70 InitRectBoundsFromSize computes right and bottom. | High | Bytes, behavior, boundaries, docs and source route. | 00015S behavior/formal source | incorporate | proposed |
| [ ] | C019 | 00015T | 0x004b7ca0 RectArea multiplies signed width and height without validity clamp. | High | Bytes, behavior, boundaries, docs and source route. | 00015T behavior/formal source | incorporate | proposed |
| [ ] | C020 | 00015S | 0x004b7cc0 IntersectRects implements nullable-output half-open intersection. | High | Bytes, behavior, boundaries, docs and source route. | 00015S behavior/formal source | incorporate | proposed |
| [ ] | C021 | 00015S | 0x004b7d70 UnionRects implements empty-rectangle identity. | High | Bytes, behavior, boundaries, docs and source route. | 00015S behavior/formal source | incorporate | proposed |
| [ ] | C022 | 00015S | 0x004b7e10 OffsetRect translates all four edges. | High | Bytes, behavior, boundaries, docs and source route. | 00015S behavior/formal source | incorporate | proposed |
| [ ] | C023 | 00015S | 0x004b7e30 InsetRect mirrors member Inset midpoint collapse. | High | Bytes, behavior, boundaries, docs and source route. | 00015S behavior/formal source | incorporate | proposed |
| [ ] | C024 | 00015S | 0x004b7e80 PointInRect uses y, x and half-open bounds. | High | Bytes, behavior, boundaries, docs and source route. | 00015S behavior/formal source | incorporate | proposed |
| [ ] | C025 | 00015S | 0x004b7eb0 IsRectEmptyOrInvalid is the free predicate. | High | Bytes, behavior, boundaries, docs and source route. | 00015S behavior/formal source | incorporate | proposed |
| [ ] | C026 | 00015S | 0x004b7ed0 RectsEquivalent treats two invalid rectangles as equivalent. | High | Bytes, behavior, boundaries, docs and source route. | 00015S behavior/formal source | incorporate | proposed |
| [ ] | C027 | 00015S | 0x004b7f30 RectContainsRect uses inner, outer source order. | High | Bytes, behavior, boundaries, docs and source route. | 00015S behavior/formal source | incorporate | proposed |
| [ ] | C028 | 00022I | 0x004b7f90 Transpose3x3AnchorIndex is a retained file-local raw helper. | High | Bytes, behavior, boundaries, docs and source route. | 00022I behavior/formal source | incorporate | proposed |
| [ ] | C029 | 00022I | 0x004b8010 AdjustRectPairForAnchor is a retained file-local raw helper. | High | Bytes, behavior, boundaries, docs and source route. | 00022I behavior/formal source | incorporate | proposed |
| [ ] | C030 | 00022I | 0x004b80d0 AdjustRectPairForAnchorWithOffsets is a retained file-local raw helper. | High | Bytes, behavior, boundaries, docs and source route. | 00022I behavior/formal source | incorporate | proposed |
| [ ] | C031 | 00022L | 0x004b8290 AdjustRectAnchorAxis is the file-local axis implementation. | High | Bytes, behavior, boundaries, docs and source route. | 00022L behavior/formal source | incorporate | proposed |
| [ ] | C032 | 0000BU | Point is 8 bytes with y@0 and x@4; RectBounds is 16 bytes with left/top/right/bottom at 0/4/8/12. | Very high | Live UDT layouts and field accesses. | UID0000BU formal H/layout | incorporate | proposed |
| [ ] | C033 | 00040U | 0x0061a880 is compiler-pooled 0.25f with exactly two reads from InsetByQuarter and no authored global. | Very high | Exact bytes, decoded value and xrefs. | UID00040U literal evidence/no-code | incorporate | proposed |
| [ ] | C034 | 00022H | 0x006104b0 is shared pooled 0.5f with sixty project-wide refs and is not RectBounds-owned source. | Very high | Exact bytes and terminal xref count. | UID00022H dependency evidence | incorporate | proposed |
| [ ] | C035 | 00022I | The four anchor switch tables and terminal padding are compiler lowering covered by their owning helpers. | Very high | Exact item heads, refs and bounded bytes. | UID00022I/00022L range analysis | incorporate | proposed |
| [ ] | C036 | 0000N2 | 0x004b81a0-0x004b8284 and 0x004b83d0 onward are unrelated neighboring source and excluded. | Very high | Distinct functions/docs and successor boundary. | UID0000N2 exclusions | incorporate | proposed |
| [ ] | C037 | 00016H | LineClip remains Surface.cpp-owned and must leave the RectBounds review bucket. | Very high | Exclusive render callers and private helper calls. | UID00016H/UID0000OC/source-tree | reject-stale | proposed |
| [ ] | C038 | 0000BU | UID0000BU remains the sole RectBounds class and header owner; no vtable or RTTI is invented. | Very high | UDT, absence checks and current route. | UID0000BU ownership/formal H | incorporate | proposed |
| [ ] | C039 | 00015R | Nest UID00015R under UID00015Q at the marker between Offset and IntersectWith. | Very high | Exact address/source order. | UID00015Q CPP route | incorporate | proposed |
| [ ] | C040 | 00015T | Preserve UID00015T's existing formal CPP/H and reparent its emitter beneath UID00015S after InitRectBoundsFromSize without recreating or overwriting its H declaration. | Very high | Current UID00015T is 88/92 with exact formal CPP/H; only ownership/source order remains wrong. | UID00015S/00015T CPP/H route | incorporate | proposed |
| [ ] | C041 | 00040U | Clear UID00040U emitter metadata while retaining reconstructable literal evidence. | Very high | Compiler-pool/no-authored-symbol proof. | UID00040U metadata/no-code | incorporate | proposed |
| [ ] | C042 | 0001VP | Clear UID0001VP emitter metadata and retain it as a duplicate layout support page. | Very high | No distinct UDT or source body. | UID0001VP metadata/no-code | incorporate | proposed |
| [ ] | C043 | 0000N2 | Assign deterministic source positions to direct and nested children so generated order matches addresses. | Very high | Dated command 000000025893 generated misordering. | UID0000N2/0000BU child tables | incorporate | proposed |
| [ ] | C044 | 0000N2 | Generate RectBounds.cpp with exactly thirty complete definitions in the accepted order and no empty marker. | Very high | Complete formal CPP and generated audit. | UID0000N2 generated closure | incorporate | proposed |
| [ ] | C045 | 0000BU | Generate RectBounds.h with complete Point/RectBounds/free declarations including RectArea and one guard. | Very high | Complete formal H and generated audit. | UID0000BU generated closure | incorporate | proposed |
| [ ] | C046 | 0000N2 | Finalize ui/core placement and historicalize the util/LineClip review alternatives in proposed-source-tree.md. | High | Subsystem and caller evidence. | proposed-source-tree RectBounds row | historicalize | proposed |
| [ ] | C047 | 0000N2 | Preserve prior hypotheses and corrected generated defects as dated historical evidence rather than deleting them. | High | Current docs and archived reports. | UID0000N2 Historical Assumptions | historicalize | proposed |
| [ ] | C048 | 0000N2 | Raise target/support scores only to the evidence-backed values in Section 26 and apply metadata changes exactly. | High | Resolved blockers and remaining limits. | Target/support metadata | incorporate | proposed |
| [ ] | C049 | 0000N2 | Apply the exact supervisor-owned manual coverage replacements/inserts in Section 28. | High | Current manual rows physically inspected. | Manual coverage reports | incorporate | proposed |
| [ ] | C050 | 0000N2 | During callback validate every changed ordinary page, perform one waited generated refresh, and physically verify final CPP/H. | Very high | Whole-file callback standard. | Validator/generated verification | incorporate | proposed |
| [ ] | C051 | 0000BU | Protect the exact Point and RectBounds UDT layouts from mutation. | Very high | Live type inspection. | Section 21 P01 | incorporate | proposed |
| [ ] | C052 | 00040U | Protect the quarter literal item, bytes, zero source type/comments, and two-xref set. | Very high | Live item/bytes/xrefs. | Section 21 P02 | incorporate | proposed |
| [ ] | C053 | 00022H | Protect the shared half literal item, bytes, and sixty-ref project ownership. | Very high | Live item/bytes/xrefs. | Section 21 P03 | incorporate | proposed |
| [ ] | C054 | 00022I | Protect all anchor switch-table heads/bytes/refs and all 34 exact alignment ranges/bytes/zero-inbound-xref starts. | Very high | Live items, bounded bytes and fresh per-span xref queries. | Section 21 P04A-P04E/P04G01-P04G34 | incorporate | proposed |
| [ ] | C055 | 0000N2 | Define exact function [0x004b7690,0x004b76c8) for RectBounds::HasSameSizeAs. | High | Literal raw prestate, exact body hash/prologue/boundaries, zero xrefs and deterministic I01 readback. | Section 21 I01 define stage | incorporate | proposed |
| [ ] | C056 | 0000N2 | Define exact function [0x004b7700,0x004b7775) for RectBounds::ContainsRect. | High | Literal raw prestate, exact body hash/prologue/boundaries, zero xrefs and deterministic I02 readback. | Section 21 I02 define stage | incorporate | proposed |
| [ ] | C057 | 0000N2 | Define exact function [0x004b7780,0x004b782a) for RectBounds::IntersectInto. | High | Literal raw prestate, exact body hash/prologue/boundaries, zero xrefs and deterministic I03 readback. | Section 21 I03 define stage | incorporate | proposed |
| [ ] | C058 | 0000N2 | Define exact function [0x004b7830,0x004b78c8) for RectBounds::UnionInto. | High | Literal raw prestate, exact body hash/prologue/boundaries, zero xrefs and deterministic I04 readback. | Section 21 I04 define stage | incorporate | proposed |
| [ ] | C059 | 0000N2 | Define exact function [0x004b7960,0x004b79f7) for RectBounds::IntersectWith. | High | Literal raw prestate, exact body hash/prologue/boundaries, zero xrefs and deterministic I05 readback. | Section 21 I05 define stage | incorporate | proposed |
| [ ] | C060 | 0000N2 | Define exact function [0x004b7af0,0x004b7b88) for RectBounds::InsetByQuarter. | High | Literal raw prestate, exact body hash/prologue/literal refs/boundaries, zero xrefs and deterministic I06 readback. | Section 21 I06 define stage | incorporate | proposed |
| [ ] | C061 | 0000N2 | Define exact function [0x004b7b90,0x004b7c21) for RectBounds::OutsetByHalf. | High | Literal raw prestate, exact body hash/prologue/literal refs/boundaries, zero xrefs and deterministic I07 readback. | Section 21 I07 define stage | incorporate | proposed |
| [ ] | C062 | 0000N2 | Define exact function [0x004b7f90,0x004b7fe0) for Transpose3x3AnchorIndex. | High | Literal raw prestate, exact body hash/prologue/table/boundaries, zero xrefs and deterministic I08 readback. | Section 21 I08 define stage | incorporate | proposed |
| [ ] | C063 | 0000N2 | Define exact function [0x004b8010,0x004b80ac) for AdjustRectPairForAnchor. | High | Literal raw prestate, exact body hash/prologue/calls/table/boundary, zero xrefs and deterministic I09 readback. | Section 21 I09 define stage | incorporate | proposed |
| [ ] | C064 | 0000N2 | Define exact function [0x004b80d0,0x004b8170) for AdjustRectPairForAnchorWithOffsets. | High | Literal raw prestate, exact body hash/prologue/calls/tables/boundaries, zero xrefs and deterministic I10 readback. | Section 21 I10 define stage | incorporate | proposed |
| [ ] | C065 | 0000N2 | Pure-rename defined 0x004b7690 to RectBounds__HasSameSizeAs while preserving its define-stage type/frame/body/xrefs. | High | Literal I11 post-define prestate, destination collision gate and exact rename readback. | Section 21 I11 rename stage | incorporate | proposed |
| [ ] | C066 | 0000N2 | Pure-rename defined 0x004b7700 to RectBounds__ContainsRect while preserving its define-stage type/frame/body/xrefs. | High | Literal I12 post-define prestate, destination collision gate and exact rename readback. | Section 21 I12 rename stage | incorporate | proposed |
| [ ] | C067 | 0000N2 | Pure-rename defined 0x004b7780 to RectBounds__IntersectInto while preserving its define-stage type/frame/body/xrefs. | High | Literal I13 post-define prestate, destination collision gate and exact rename readback. | Section 21 I13 rename stage | incorporate | proposed |
| [ ] | C068 | 0000N2 | Pure-rename defined 0x004b7830 to RectBounds__UnionInto while preserving its define-stage type/frame/body/xrefs. | High | Literal I14 post-define prestate, destination collision gate and exact rename readback. | Section 21 I14 rename stage | incorporate | proposed |
| [ ] | C069 | 0000N2 | Pure-rename defined 0x004b7960 to RectBounds__IntersectWith while preserving its define-stage type/frame/body/xrefs. | High | Literal I15 post-define prestate, destination collision gate and exact rename readback. | Section 21 I15 rename stage | incorporate | proposed |
| [ ] | C070 | 0000N2 | Pure-rename defined 0x004b7af0 to RectBounds__InsetByQuarter while preserving its define-stage type/frame/body/xrefs. | High | Literal I16 post-define prestate, destination collision gate and exact rename readback. | Section 21 I16 rename stage | incorporate | proposed |
| [ ] | C071 | 0000N2 | Pure-rename defined 0x004b7b90 to RectBounds__OutsetByHalf while preserving its define-stage type/frame/body/xrefs. | High | Literal I17 post-define prestate, destination collision gate and exact rename readback. | Section 21 I17 rename stage | incorporate | proposed |
| [ ] | C072 | 0000N2 | Pure-rename defined 0x004b7f90 to Transpose3x3AnchorIndex while preserving its define-stage type/frame/body/xrefs. | High | Literal I18 post-define prestate, destination collision gate and exact rename readback. | Section 21 I18 rename stage | incorporate | proposed |
| [ ] | C073 | 0000N2 | Pure-rename defined 0x004b8010 to AdjustRectPairForAnchor while preserving its define-stage type/frame/body/xrefs. | High | Literal I19 post-define prestate, destination collision gate and exact rename readback. | Section 21 I19 rename stage | incorporate | proposed |
| [ ] | C074 | 0000N2 | Pure-rename defined 0x004b80d0 to AdjustRectPairForAnchorWithOffsets while preserving its define-stage type/frame/body/xrefs. | High | Literal I20 post-define prestate, destination collision gate and exact rename readback. | Section 21 I20 rename stage | incorporate | proposed |
| [ ] | C075 | 0000N2 | Pure-rename modeled function 0x004b7670 to RectBounds__IsEmptyOrInvalid under its exact persisted-IDB/decompiler/public-presentation contract. | High | Three-channel I21 pre/post evidence, behavior, docs and source route. | Section 21 RectBounds__IsEmptyOrInvalid rename | incorporate | proposed |
| [ ] | C076 | 0000N2 | Pure-rename modeled function 0x004b76d0 to RectBounds__ContainsPoint under its exact persisted-IDB/decompiler/public-presentation contract. | High | Three-channel I22 pre/post evidence, behavior, docs and source route. | Section 21 RectBounds__ContainsPoint rename | incorporate | proposed |
| [ ] | C077 | 0000N2 | Pure-rename modeled function 0x004b78d0 to RectBounds__SetLTRB under its exact persisted-IDB/decompiler/public-presentation contract. | High | Three-channel I23 pre/post evidence, behavior, docs and source route. | Section 21 RectBounds__SetLTRB rename | incorporate | proposed |
| [ ] | C078 | 0000N2 | Pure-rename modeled function 0x004b7910 to RectBounds__Inset under its exact persisted-IDB/decompiler/public-presentation contract. | High | Three-channel I24 pre/post evidence, behavior, docs and source route. | Section 21 RectBounds__Inset rename | incorporate | proposed |
| [ ] | C079 | 0000N2 | Pure-rename modeled function 0x004b7a00 to RectBounds__UnionWith under its exact persisted-IDB/decompiler/public-presentation contract. | High | Three-channel I25 pre/post evidence, behavior, docs and source route. | Section 21 RectBounds__UnionWith rename | incorporate | proposed |
| [ ] | C080 | 0000N2 | Pure-rename modeled function 0x004b7a80 to RectBounds__ClampWithin under its exact persisted-IDB/decompiler/public-presentation contract. | High | Three-channel I26 pre/post evidence, behavior, docs and source route. | Section 21 RectBounds__ClampWithin rename | incorporate | proposed |
| [ ] | C081 | 0000N2 | Pure-rename modeled function 0x004b7c70 to InitRectBoundsFromSize under its exact persisted-IDB/decompiler/public-presentation contract. | High | Three-channel I27 pre/post evidence, behavior, docs and source route. | Section 21 InitRectBoundsFromSize rename | incorporate | proposed |
| [ ] | C082 | 0000N2 | Pure-rename modeled function 0x004b7ca0 to RectArea under its exact persisted-IDB/decompiler/public-presentation contract. | High | Three-channel I28 pre/post evidence, behavior, docs and source route. | Section 21 RectArea rename | incorporate | proposed |
| [ ] | C083 | 0000N2 | Pure-rename modeled function 0x004b7e30 to InsetRect under its exact persisted-IDB/decompiler/public-presentation contract. | High | Three-channel I29 pre/post evidence, behavior, docs and source route. | Section 21 InsetRect rename | incorporate | proposed |
| [ ] | C084 | 0000N2 | Pure-rename modeled function 0x004b7f30 to RectContainsRect under its exact persisted-IDB/decompiler/public-presentation contract. | High | Three-channel I30 pre/post evidence, behavior, docs and source route. | Section 21 RectContainsRect rename | incorporate | proposed |
| [ ] | C085 | 0000N2 | Pure-rename modeled function 0x004b8290 to AdjustRectAnchorAxis under its exact persisted-IDB/decompiler/public-presentation contract. | High | Three-channel I31 pre/post evidence, behavior, docs and source route. | Section 21 AdjustRectAnchorAxis rename | incorporate | proposed |
| [ ] | C086 | 0000N2 | Apply the exact source-quality function type for RectBounds__IsEmptyOrInvalid at 0x004b7670 with protected frame deltas. | High | Calling convention, body and current frame. | Section 21 RectBounds__IsEmptyOrInvalid type | incorporate | proposed |
| [ ] | C087 | 0000N2 | Apply the exact source-quality function type for RectBounds__ContainsPoint at 0x004b76d0 with protected frame deltas. | High | Calling convention, body and current frame. | Section 21 RectBounds__ContainsPoint type | incorporate | proposed |
| [ ] | C088 | 0000N2 | Apply the exact source-quality function type for RectBounds__SetLTRB at 0x004b78d0 with protected frame deltas. | High | Calling convention, body and current frame. | Section 21 RectBounds__SetLTRB type | incorporate | proposed |
| [ ] | C089 | 0000N2 | Apply the exact source-quality function type for RectBounds__Inset at 0x004b7910 with protected frame deltas. | High | Calling convention, body and current frame. | Section 21 RectBounds__Inset type | incorporate | proposed |
| [ ] | C090 | 0000N2 | Apply the exact source-quality function type for RectBounds__UnionWith at 0x004b7a00 with protected frame deltas. | High | Calling convention, body and current frame. | Section 21 RectBounds__UnionWith type | incorporate | proposed |
| [ ] | C091 | 0000N2 | Apply the exact source-quality function type for RectBounds__ClampWithin at 0x004b7a80 with protected frame deltas. | High | Calling convention, body and current frame. | Section 21 RectBounds__ClampWithin type | incorporate | proposed |
| [ ] | C092 | 0000N2 | Apply the exact source-quality function type for InitRectBoundsFromSize at 0x004b7c70 with protected frame deltas. | High | Calling convention, body and current frame. | Section 21 InitRectBoundsFromSize type | incorporate | proposed |
| [ ] | C093 | 0000N2 | Apply the exact source-quality function type for RectArea at 0x004b7ca0 with protected frame deltas. | High | Calling convention, body and current frame. | Section 21 RectArea type | incorporate | proposed |
| [ ] | C094 | 0000N2 | Apply the exact source-quality function type for InsetRect at 0x004b7e30 with protected frame deltas. | High | Calling convention, body and current frame. | Section 21 InsetRect type | incorporate | proposed |
| [ ] | C095 | 0000N2 | Apply the exact source-quality function type for RectContainsRect at 0x004b7f30 with protected frame deltas. | High | Calling convention, body and current frame. | Section 21 RectContainsRect type | incorporate | proposed |
| [ ] | C096 | 0000N2 | Apply the exact source-quality function type for AdjustRectAnchorAxis at 0x004b8290 with protected frame deltas. | High | Calling convention, body and current frame. | Section 21 AdjustRectAnchorAxis type | incorporate | proposed |
| [ ] | C097 | 0000N2 | Apply the exact repeatable source-role comment for RectBounds__HasSameSizeAs at 0x004b7690. | High | Complete post-type state and exact behavior. | Section 21 I43 comment stage | incorporate | proposed |
| [ ] | C098 | 0000N2 | Apply the exact repeatable source-role comment for RectBounds__ContainsRect at 0x004b7700. | High | Complete post-type state and exact behavior. | Section 21 I44 comment stage | incorporate | proposed |
| [ ] | C099 | 0000N2 | Apply the exact repeatable source-role comment for RectBounds__IntersectInto at 0x004b7780. | High | Complete post-type state and exact behavior. | Section 21 I45 comment stage | incorporate | proposed |
| [ ] | C100 | 0000N2 | Apply the exact repeatable source-role comment for RectBounds__UnionInto at 0x004b7830. | High | Complete post-type state and exact behavior. | Section 21 I46 comment stage | incorporate | proposed |
| [ ] | C101 | 0000N2 | Apply the exact repeatable source-role comment for RectBounds__IntersectWith at 0x004b7960. | High | Complete post-type state and exact behavior. | Section 21 I47 comment stage | incorporate | proposed |
| [ ] | C102 | 0000N2 | Apply the exact repeatable source-role comment for RectBounds__InsetByQuarter at 0x004b7af0. | High | Complete post-type state, exact literal behavior and boundaries. | Section 21 I48 comment stage | incorporate | proposed |
| [ ] | C103 | 0000N2 | Apply the exact repeatable source-role comment for RectBounds__OutsetByHalf at 0x004b7b90. | High | Complete post-type state, exact literal behavior and boundaries. | Section 21 I49 comment stage | incorporate | proposed |
| [ ] | C104 | 0000N2 | Apply the exact repeatable source-role comment for Transpose3x3AnchorIndex at 0x004b7f90. | High | Complete post-type state, exact table behavior and boundaries. | Section 21 I50 comment stage | incorporate | proposed |
| [ ] | C105 | 0000N2 | Apply the exact repeatable source-role comment for AdjustRectPairForAnchor at 0x004b8010. | High | Complete post-type state, exact calls/table behavior and boundaries. | Section 21 I51 comment stage | incorporate | proposed |
| [ ] | C106 | 0000N2 | Apply the exact repeatable source-role comment for AdjustRectPairForAnchorWithOffsets at 0x004b80d0. | High | Complete post-type state, exact calls/table behavior and boundaries. | Section 21 I52 comment stage | incorporate | proposed |
| [ ] | C107 | 0000N2 | Apply the exact repeatable source-role comment for RectBounds__IsEmptyOrInvalid at 0x004b7670. | High | Resolved source role and boundary. | Section 21 RectBounds__IsEmptyOrInvalid comment | incorporate | proposed |
| [ ] | C108 | 0000N2 | Apply the exact repeatable source-role comment for RectBounds__ContainsPoint at 0x004b76d0. | High | Resolved source role and boundary. | Section 21 RectBounds__ContainsPoint comment | incorporate | proposed |
| [ ] | C109 | 0000N2 | Apply the exact repeatable source-role comment for RectBounds__SetLTRB at 0x004b78d0. | High | Resolved source role and boundary. | Section 21 RectBounds__SetLTRB comment | incorporate | proposed |
| [ ] | C110 | 0000N2 | Apply the exact repeatable source-role comment for RectBounds__Inset at 0x004b7910. | High | Resolved source role and boundary. | Section 21 RectBounds__Inset comment | incorporate | proposed |
| [ ] | C111 | 0000N2 | Apply the exact repeatable source-role comment for RectBounds__UnionWith at 0x004b7a00. | High | Resolved source role and boundary. | Section 21 RectBounds__UnionWith comment | incorporate | proposed |
| [ ] | C112 | 0000N2 | Apply the exact repeatable source-role comment for RectBounds__ClampWithin at 0x004b7a80. | High | Resolved source role and boundary. | Section 21 RectBounds__ClampWithin comment | incorporate | proposed |
| [ ] | C113 | 0000N2 | Apply the exact repeatable source-role comment for InitRectBoundsFromSize at 0x004b7c70. | High | Resolved source role and boundary. | Section 21 InitRectBoundsFromSize comment | incorporate | proposed |
| [ ] | C114 | 0000N2 | Apply the exact repeatable source-role comment for RectArea at 0x004b7ca0. | High | Resolved source role and boundary. | Section 21 RectArea comment | incorporate | proposed |
| [ ] | C115 | 0000N2 | Apply the exact repeatable source-role comment for InsetRect at 0x004b7e30. | High | Resolved source role and boundary. | Section 21 InsetRect comment | incorporate | proposed |
| [ ] | C116 | 0000N2 | Apply the exact repeatable source-role comment for RectContainsRect at 0x004b7f30. | High | Resolved source role and boundary. | Section 21 RectContainsRect comment | incorporate | proposed |
| [ ] | C117 | 0000N2 | Apply the exact repeatable source-role comment for AdjustRectAnchorAxis at 0x004b8290. | High | Resolved source role and boundary. | Section 21 AdjustRectAnchorAxis comment | incorporate | proposed |
| [ ] | C118 | 0000N2 | Preserve already-present source-quality identity RectBounds_Offset at 0x004b78f0; no mutation is recommended. | Very high | Exact current name/type/comments/readback. | Section 21 RectBounds_Offset protection | already-present | proposed |
| [ ] | C119 | 0000N2 | Preserve already-present source-quality identity InitPointPair at 0x004b7c30; no mutation is recommended. | Very high | Exact current name/type/comments/readback. | Section 21 InitPointPair protection | already-present | proposed |
| [ ] | C120 | 0000N2 | Preserve already-present source-quality identity InitRectBounds at 0x004b7c50; no mutation is recommended. | Very high | Exact current name/type/comments/readback. | Section 21 InitRectBounds protection | already-present | proposed |
| [ ] | C121 | 0000N2 | Preserve already-present source-quality identity IntersectRects at 0x004b7cc0; no mutation is recommended. | Very high | Exact current name/type/comments/readback. | Section 21 IntersectRects protection | already-present | proposed |
| [ ] | C122 | 0000N2 | Preserve already-present source-quality identity UnionRects at 0x004b7d70; no mutation is recommended. | Very high | Exact current name/type/comments/readback. | Section 21 UnionRects protection | already-present | proposed |
| [ ] | C123 | 0000N2 | Preserve already-present source-quality identity NexusTK_OffsetRect at 0x004b7e10; no mutation is recommended. | Very high | Exact current name/type/comments/readback. | Section 21 NexusTK_OffsetRect protection | already-present | proposed |
| [ ] | C124 | 0000N2 | Preserve the already-present PointInRect function identity at 0x004b7e80 while applying only the exact I64-I66 physical-frame repairs. | Very high | Exact current name/type/comments/readback. | Section 21 PointInRect protection | already-present | proposed |
| [ ] | C125 | 0000N2 | Preserve already-present source-quality identity IsRectEmptyOrInvalid at 0x004b7eb0; no mutation is recommended. | Very high | Exact current name/type/comments/readback. | Section 21 IsRectEmptyOrInvalid protection | already-present | proposed |
| [ ] | C126 | 0000N2 | Preserve already-present source-quality identity RectsEquivalent at 0x004b7ed0; no mutation is recommended. | Very high | Exact current name/type/comments/readback. | Section 21 RectsEquivalent protection | already-present | proposed |
| [ ] | C127 | 00015S | Rename PointInRect stack row to y without changing its int type or offset. | Very high | Function tinfo says y while physical stack metadata says row. | Section 21 I64 | incorporate | proposed |
| [ ] | C128 | 00015S | Rename PointInRect stack column to x without changing its int type or offset. | Very high | Function tinfo says x while physical stack metadata says column. | Section 21 I65 | incorporate | proposed |
| [ ] | C129 | 00015S | Retype PointInRect stack bounds from const MapRect * to const RectBounds * without changing its name/offset. | Very high | Exact function tinfo and field behavior contradict stale stack metadata. | Section 21 I66 | incorporate | proposed |
| [ ] | C130 | 0000N2 | Preserve `0x004b7661-0x004b7670` as 15-byte `cc` predecessor alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and boundary pages. | UID0000N2 inventory; FramePartPane boundary; by-memory/-ignored.md | incorporate | proposed |
| [ ] | C131 | 00022G | Preserve `0x004b7685-0x004b7690` as 11-byte `cc` internal alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and UID00022G boundaries. | UID00022G Range/Boundary; by-memory/-ignored.md | incorporate | proposed |
| [ ] | C132 | 00022G | Preserve `0x004b76c8-0x004b76d0` as 8-byte `cc` internal alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and UID00022G boundaries. | UID00022G Range/Boundary; by-memory/-ignored.md | incorporate | proposed |
| [ ] | C133 | 00022G | Preserve `0x004b76f8-0x004b7700` as 8-byte `cc` internal alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and UID00022G boundaries. | UID00022G Range/Boundary; by-memory/-ignored.md | incorporate | proposed |
| [ ] | C134 | 00022G | Preserve `0x004b7775-0x004b7780` as 11-byte `cc` internal alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and UID00022G boundaries. | UID00022G Range/Boundary; by-memory/-ignored.md | incorporate | proposed |
| [ ] | C135 | 00022G | Preserve `0x004b782a-0x004b7830` as 6-byte `cc` internal alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and UID00022G boundaries. | UID00022G Range/Boundary; by-memory/-ignored.md | incorporate | proposed |
| [ ] | C136 | 00022G | Preserve `0x004b78c8-0x004b78d0` as 8-byte `cc` UID00022G-to-UID00015Q boundary alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and support boundaries. | UID00022G Range/Boundary; by-memory/-ignored.md | incorporate | proposed |
| [ ] | C137 | 00015Q | Preserve `0x004b78ee-0x004b78f0` as 2-byte `cc` member alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and UID00015Q boundaries. | UID00015Q Range/Boundary; by-memory/-ignored.md | incorporate | proposed |
| [ ] | C138 | 00015Q | Preserve `0x004b7908-0x004b7910` as 8-byte `cc` UID00015Q-to-UID00015R boundary alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and nested-child boundaries. | UID00015Q/UID00015R Range/Boundary; by-memory/-ignored.md | incorporate | proposed |
| [ ] | C139 | 00015R | Preserve `0x004b795e-0x004b7960` as 2-byte `cc` UID00015R-to-UID00015Q boundary alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and nested-child boundaries. | UID00015R/UID00015Q Range/Boundary; by-memory/-ignored.md | incorporate | proposed |
| [ ] | C140 | 00015Q | Preserve `0x004b79f7-0x004b7a00` as 9-byte `cc` member alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and UID00015Q boundaries. | UID00015Q Range/Boundary; by-memory/-ignored.md | incorporate | proposed |
| [ ] | C141 | 00015Q | Preserve `0x004b7a77-0x004b7a80` as 9-byte `cc` member alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and UID00015Q boundaries. | UID00015Q Range/Boundary; by-memory/-ignored.md | incorporate | proposed |
| [ ] | C142 | 00015Q | Preserve `0x004b7ae8-0x004b7af0` as 8-byte `cc` UID00015Q-to-UID00022H boundary alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and support boundaries. | UID00015Q/UID00022H Range/Boundary; by-memory/-ignored.md | incorporate | proposed |
| [ ] | C143 | 00022H | Preserve `0x004b7b88-0x004b7b90` as 8-byte `cc` helper alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and UID00022H boundaries. | UID00022H Range/Boundary; by-memory/-ignored.md | incorporate | proposed |
| [ ] | C144 | 00022H | Preserve `0x004b7c21-0x004b7c30` as 15-byte `cc` UID00022H-to-UID00015S boundary alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and support boundaries. | UID00022H/UID00015S Range/Boundary; by-memory/-ignored.md | incorporate | proposed |
| [ ] | C145 | 00015S | Preserve `0x004b7c43-0x004b7c50` as 13-byte `cc` geometry-helper alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and UID00015S ranges. | UID00015S Function Inventory/Range; by-memory/-ignored.md | incorporate | proposed |
| [ ] | C146 | 00015S | Preserve `0x004b7c6f-0x004b7c70` as 1-byte `cc` geometry-helper alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and UID00015S ranges. | UID00015S Function Inventory/Range; by-memory/-ignored.md | incorporate | proposed |
| [ ] | C147 | 00015S | Preserve `0x004b7c95-0x004b7ca0` as 11-byte `cc` UID00015S-to-UID00015T boundary alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and nested-child boundaries. | UID00015S/UID00015T Range; by-memory/-ignored.md | incorporate | proposed |
| [ ] | C148 | 00015T | Preserve `0x004b7cb6-0x004b7cc0` as 10-byte `cc` UID00015T-to-UID00015S boundary alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and nested-child boundaries. | UID00015T/UID00015S Range; by-memory/-ignored.md | incorporate | proposed |
| [ ] | C149 | 00015S | Preserve `0x004b7d69-0x004b7d70` as 7-byte `cc` geometry-helper alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and UID00015S ranges. | UID00015S Function Inventory/Range; by-memory/-ignored.md | incorporate | proposed |
| [ ] | C150 | 00015S | Preserve `0x004b7e03-0x004b7e10` as 13-byte `cc` geometry-helper alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and UID00015S ranges. | UID00015S Function Inventory/Range; by-memory/-ignored.md | incorporate | proposed |
| [ ] | C151 | 00015S | Preserve `0x004b7e29-0x004b7e30` as 7-byte `cc` geometry-helper alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and UID00015S ranges. | UID00015S Function Inventory/Range; by-memory/-ignored.md | incorporate | proposed |
| [ ] | C152 | 00015S | Preserve `0x004b7e7f-0x004b7e80` as 1-byte `cc` geometry-helper alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and UID00015S ranges. | UID00015S Function Inventory/Range; by-memory/-ignored.md | incorporate | proposed |
| [ ] | C153 | 00015S | Preserve `0x004b7ea7-0x004b7eb0` as 9-byte `cc` geometry-helper alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and UID00015S ranges. | UID00015S Function Inventory/Range; by-memory/-ignored.md | incorporate | proposed |
| [ ] | C154 | 00015S | Preserve `0x004b7ecd-0x004b7ed0` as 3-byte `cc` geometry-helper alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and UID00015S ranges. | UID00015S Function Inventory/Range; by-memory/-ignored.md | incorporate | proposed |
| [ ] | C155 | 00015S | Preserve `0x004b7f22-0x004b7f30` as 14-byte `cc` geometry-helper alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and UID00015S ranges. | UID00015S Function Inventory/Range; by-memory/-ignored.md | incorporate | proposed |
| [ ] | C156 | 00015S | Preserve `0x004b7f87-0x004b7f90` as 9-byte `cc` UID00015S-to-UID00022I boundary alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and support boundaries. | UID00015S/UID00022I Range/Boundary; by-memory/-ignored.md | incorporate | proposed |
| [ ] | C157 | 00022I | Preserve `0x004b8004-0x004b8010` as 12-byte `cc` helper/table-tail alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and UID00022I boundaries. | UID00022I Range/Boundary; by-memory/-ignored.md | incorporate | proposed |
| [ ] | C158 | 00022I | Preserve `0x004b8194-0x004b81a0` as 12-byte `cc` UID00022I-to-UID00022J boundary alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and support boundaries. | UID00022I/UID00022J Range/Boundary; by-memory/-ignored.md | incorporate | proposed |
| [ ] | C159 | 00022J | Preserve `0x004b81eb-0x004b81f0` as 5-byte `cc` UID00022J-to-UID00022K boundary alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and support boundaries. | UID00022J/UID00022K Range/Boundary; by-memory/-ignored.md | incorporate | proposed |
| [ ] | C160 | 00022K | Preserve `0x004b821e-0x004b8220` as 2-byte `cc` UID00022K-to-UID00015U boundary alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and support boundaries. | UID00022K/UID00015U Range/Boundary; by-memory/-ignored.md | incorporate | proposed |
| [ ] | C161 | 00015U | Preserve `0x004b8284-0x004b8290` as 12-byte `cc` UID00015U-to-UID00022L boundary alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and support boundaries. | UID00015U/UID00022L Range/Boundary; by-memory/-ignored.md | incorporate | proposed |
| [ ] | C162 | 00022L | Preserve `0x004b83ae-0x004b83b0` as exact `66 90` two-byte NOP alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and UID00022L body/table boundary. | UID00022L Range/Boundary | incorporate | proposed |
| [ ] | C163 | 00022L | Preserve `0x004b83c5-0x004b83d0` as 11-byte `cc` successor alignment with zero inbound xrefs and no authored source. | Very high | Fresh exact bytes/xref query and successor boundary. | UID00022L Range/Boundary; by-memory/-ignored.md | incorporate | proposed |
| [ ] | C164 | 0000N2 | Apply the exact source-quality type/frame for RectBounds__HasSameSizeAs. | High | Exact signature, calling convention, define-stage frame, body and zero-xref evidence. | Section 21 I11T type stage | incorporate | proposed |
| [ ] | C165 | 0000N2 | Apply the exact source-quality type/frame for RectBounds__ContainsRect. | High | Exact signature, calling convention, define-stage frame, body and zero-xref evidence. | Section 21 I12T type stage | incorporate | proposed |
| [ ] | C166 | 0000N2 | Apply the exact source-quality type/frame for RectBounds__IntersectInto. | High | Exact signature, calling convention, define-stage frame, body and zero-xref evidence. | Section 21 I13T type stage | incorporate | proposed |
| [ ] | C167 | 0000N2 | Apply the exact source-quality type/frame for RectBounds__UnionInto. | High | Exact signature, calling convention, define-stage frame, body and zero-xref evidence. | Section 21 I14T type stage | incorporate | proposed |
| [ ] | C168 | 0000N2 | Apply the exact source-quality type/frame for RectBounds__IntersectWith. | High | Exact signature, calling convention, define-stage frame, body and zero-xref evidence. | Section 21 I15T type stage | incorporate | proposed |
| [ ] | C169 | 0000N2 | Apply the exact source-quality type/frame for RectBounds__InsetByQuarter. | High | Exact signature, calling convention, define-stage frame, literal refs and zero-xref evidence. | Section 21 I16T type stage | incorporate | proposed |
| [ ] | C170 | 0000N2 | Apply the exact source-quality type/frame for RectBounds__OutsetByHalf. | High | Exact signature, calling convention, define-stage frame, literal refs and zero-xref evidence. | Section 21 I17T type stage | incorporate | proposed |
| [ ] | C171 | 0000N2 | Apply the exact source-quality type/frame for Transpose3x3AnchorIndex. | High | Exact cdecl signature, define-stage frame, switch table and zero-xref evidence. | Section 21 I18T type stage | incorporate | proposed |
| [ ] | C172 | 0000N2 | Apply the exact source-quality type/frame for AdjustRectPairForAnchor. | High | Exact cdecl signature, define-stage frame, call/table and zero-xref evidence. | Section 21 I19T type stage | incorporate | proposed |
| [ ] | C173 | 0000N2 | Apply the exact source-quality type/frame for AdjustRectPairForAnchorWithOffsets. | High | Exact cdecl signature, define-stage frame, call/table and zero-xref evidence. | Section 21 I20T type stage | incorporate | proposed |
