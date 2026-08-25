** TARGET-REPORT-UID:00015S **
** AUTHOR-AGENT-ID:B015 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00015S RectGeometryHelpers Source-Quality Report

## Finalized Report / Current Recommendation
UID00015S remains a reconstructable, file-level helper island under by-file UID0000N2 (`NexusTK/ui/core/RectBounds.cpp`). The implementation callback has repaired the prior source-quality blocker: the target page now has a formal `RECONSTRUCTION_CPP CODE` body, and validator-refreshed `auto-generated/NexusTK/ui/core/RectBounds.cpp` now emits UID00015S helper code instead of only an empty marker.

UID00015S now contains first-draft C++ for the free geometry helpers in `0x004b7c30-0x004b7f87`, except `RectArea` at `0x004b7ca0`, which remains owned/emitted by child page UID00015T. The C++ is source-facing rather than raw wrapper labels and preserves the IDA-confirmed argument order for `PointInRect(int y, int x, const RectBounds *bounds)` and `RectContainsRect(const RectBounds *innerBounds, const RectBounds *outerBounds)`.

Applied metadata is `Completion: 90 / Confidence: 91`. The report-level source-shape blockers are resolved for this target: the formal block uses `struct Point { int y; int x; }` for the two-int point support type, uses `InsetRect` as the source-facing name for `0x004b7e30`, historicalizes `InflateRect_4B7E30` as a stale address-suffixed alias only, and preserves `PointInRect(int y, int x, const RectBounds *bounds)`. The score remains capped at `90/91` because exact original symbol spellings are still not recovered and downstream caller pages with stale point-call order are separate owner-page cleanup, not UID00015S target work.

## Supporting Research
The target was selected from `auto-generated/-ag-research-tracker.md`, `## by-memory`, `### Not-Covered Files - Reconstructable`, row UID00015S. The target file is `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md`.

I checked active B-agent report directories, executed B-agent research, archived paths, target/support docs, generated C++ output, tracker/coverage reports, and current IDA MCP evidence. No active root report for UID00015S was found before this report. Relevant executed reports found were B001 RectBounds class/source-quality, B001 RectBounds quarter-scale helper work, B003 RectAnchorTransformHelpers, B005 TabPane rectangle builder, B006 RectArea, and B008 Region raw rectangle helpers. The strongest incorporated prior-result dependencies are B001 for RectBounds source placement and helper inventory, B006 for preserving `RectArea` as child UID00015T, and B008 for the corrected `RectContainsRect(innerBounds, outerBounds)` argument order.

The local `source-3/simroot_v2` lead referenced by some older workflow examples was not present in this workspace. This is not a blocker because current validator-generated output under `auto-generated/NexusTK/ui/core/RectBounds.cpp`, current coverage/tracker rows, and live IDA MCP evidence were available.

## Target
- UID: `00015S`
- Target page: `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md`
- Current owner/emitter: `0000N2` (`by-file/RectBounds.md`)
- Source path: `NexusTK/ui/core/RectBounds.cpp`
- Current score: `Completion: 90`, `Confidence: 91`
- Current reconstructable state: `true`
- Current generated state: validator-refreshed UID00015S output in `auto-generated/NexusTK/ui/core/RectBounds.cpp`, latest observed header `validator-command-id: 000000007469`

## Current Target State
The target page already documents the helper island as a dense RectBounds geometry range covering point/rect initialization, area, intersection, union, offset, inset/inflate-style resizing, point hit-test, empty/equivalence checks, and containment. It correctly places the range under RectBounds ownership and separates it from Region and from the following anchor-transform range.

The ownership gap was already resolved before this callback; the callback addressed source realization. UID00015S now has a C++ body for the non-RectArea helpers. Validator-refreshed `RectBounds.cpp` confirms UID00015S emits `Point`, `InsetRect`, `PointInRect`, and `RectContainsRect`, while UID00015T continues to own and emit `RectArea`.

The target and support files were edited only after supervisor callback approval and their scoped validator batches completed.

## Heuristic / Inference Reanalysis And Validation
The original grouping heuristic is validated. The range is not a feature-local rectangle helper for TabPane, Region, render, or map code. The helpers have broad cross-file caller fanout and operate directly on the common four-int `RectBounds` layout. IDA MCP xref counts show heavy shared use: `InitRectBounds` has 1731 code xrefs, `OffsetRect` has 368, `PointInRect` has 270, and `IntersectRects` has 91.

The helper body inference is also validated. Each function start in the target range resolves to a compact `sub_4B7...` function with no callees. Decompilation shows direct field reads/writes against the `left, top, right, bottom` layout already documented by `RectBoundsLayout.md`. The range signature for `0x004b7c30-0x004b7f87` is unique, and `0x004b7f90` is not a function, supporting the current split boundary before the anchor-transform helpers.

One source-facing naming heuristic needs correction. `0x004b7e30` is not a conventional positive-delta inflate operation. Its positive deltas move left/top inward and right/bottom inward, then clamp inverted axes to their midpoint. The source-facing name for UID00015S should be exactly `InsetRect(RectBounds *bounds, int dx, int dy)`. The existing `InflateRect_4B7E30` wording should be kept only as historical/search provenance in notes where useful; it should not remain the primary helper name and should not be emitted as a duplicate wrapper or alias in the formal C++.

The point support type is resolved for this target. Current by-* docs do not contain an authoritative standalone `Point` or `PointPair` by-type page. The stronger current source-facing evidence favors `Point`: `by-class/ScrollVolumePane.md` forward-declares `struct Point` and stores `Point m_thumbDragOffset`; `by-type/by-struct/ScrollCollectionPaneLayout.md` records `Point m_thumbDragOffset` in project `y,x` order; and `by-class/ScrollNewGroupPane.md` names the shared helper as `InitPointPair(Point *out, int y, int x)`. `PointPair` remains useful descriptive wording in older/support layout notes, especially `ScrollVolumePaneLayout.md`, but it is not the best emitted type name for UID00015S. The formal C++ should define `struct Point { int y; int x; };` in the RectBounds geometry support block and should use `void InitPointPair(Point *point, int y, int x)`.

Stale generated/caller-signature cleanup is exact and bounded. The UID00015S callback canonicalized the helper signature and point type in the RectBounds target/support docs only. It did not edit downstream caller target pages such as FittingRoom, TabPane, MenuVariety, VoteMenu, ScrollBar, SelfLookPane, or TargetSelectionInput panes. Evidence: searches found generated/current call forms such as `auto-generated/NexusTK/ui/panels/TabPane.cpp:117` using `PointInRect(&rect, x, y)`, `auto-generated/NexusTK/ui/menu/VoteMenuPane.cpp:205` using `PointInRect(rect, x, y)`, and `auto-generated/NexusTK/ui/controls/ScrollVolumePane.cpp:127` using `PointInRect(x, y, &rect)`, while `RectBoundsLayout.md`, B001 RectBounds, B006 MapPane, B006 ScrollCollection, B011 render, and B012 Icons/MainMenu evidence support the canonical `PointInRect(y, x, bounds)` helper. Those downstream generated files are validator output from their own by-memory sources; the UID00015S scoped validators refreshed `auto-generated/NexusTK/ui/core/RectBounds.cpp` but did not repair unrelated caller C++ blocks.

## Evidence Standards Used
This report uses live IDA MCP evidence as the controlling source for function existence, range boundaries, decompiled behavior, callee absence, xref counts, and signature uniqueness. Project docs and executed B-agent reports are used as incorporation evidence only where they match live MCP facts or document prior supervisor-accepted source placement decisions.

Generated files and coverage/tracker reports were read-only evidence during the research phase. During the callback, generated/project-level changes occurred only through the required scoped validators; no generated file was manually edited. No lifecycle, move, execute_report, dry-run execute, probing execute, manual validator-state, or supervisor-ledger command was run.

## Evidence Checked
- `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md`
- `by-file/RectBounds.md`
- `by-class/RectBounds.md`
- `by-type/by-struct/RectBoundsLayout.md`
- `by-memory/0x004b7ca0-0x004b7cb6.RectArea.md`
- `by-memory/0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers.md`
- `by-memory/0x004b7f90-0x004b8194.RectAnchorTransformHelpers.md`
- `by-memory/0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper.md`
- `by-file/Region.md`
- `by-project-structure/proposed-source-tree.md`
- `by-meta/client_ui_core.md`
- `auto-generated/NexusTK/ui/core/RectBounds.cpp`
- `auto-generated/-ag-research-tracker.md`
- `auto-generated/-ag-coverage-report-by-memory.md`
- Executed B-agent research for B001, B003, B005, B006, and B008 where matching UID/range evidence existed
- Point-type and caller-cleanup searches over `by-class`, `by-type`, `by-memory`, `by-file`, `auto-generated/NexusTK`, and `executed-b-agent-research` for `Point`, `PointPair`, `InitPointPair`, `PointInRect`, `InsetRect`, `InsetRectBounds`, and `InflateRect_4B7E30`
- Live IDA MCP session `supervisor_recovery_20260705`

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| 00015S-C01 | UID00015S remains owned/emitted by file UID0000N2, `NexusTK/ui/core/RectBounds.cpp`. | High | `by-file/RectBounds.md`, `by-class/RectBounds.md`, `by-meta/client_ui_core.md`, B001 RectBounds report, MCP broad xref fanout. | Target `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md` metadata/status; support `by-file/RectBounds.md` Status/File Role. | incorporate | applied - target metadata preserved `CANONICAL_OWNER:0000N2`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N2`; `by-file/RectBounds.md` File Role updated; validators `000000007465` and `000000007467` exited 0. |
| 00015S-C02 | Range `0x004b7c30-0x004b7f87` is a coherent free RectBounds geometry helper island. | High | MCP `lookup_funcs` confirms twelve helper starts; `0x004b7f90` is not a function; range signature unique; padding before/after documented. | Target Range/Split/Padding section and helper table; support `by-file/RectBounds.md` Proposed Contents. | incorporate | applied - target Evidence Notes now record all twelve starts, `0x004b7f90` non-function boundary, no-callee facts, and unique range signature; `by-file/RectBounds.md` Proposed Contents now names UID00015S free-helper bodies. |
| 00015S-C03 | Do not split remaining UID00015S helpers into Region, TabPane, render, map, or feature-local owners. | High | Xref counts across unrelated systems; Region docs separate dirty-region wrappers from lower-level RectBounds helpers; B001 rejected feature-local/util fallbacks. | Target Ranked Ownership Analysis and Source Placement; support `by-file/RectBounds.md` Source-Structure Decision. | incorporate | applied - target Source-Quality Decisions and support docs keep the range as file-level RectBounds helpers; no Region, TabPane, render, map, or feature-local target pages were edited. |
| 00015S-C04 | Preserve child UID00015T as the sole `RectArea(const RectBounds *bounds)` emitter and omit `RectArea` from UID00015S C++. | High | `by-memory/0x004b7ca0-0x004b7cb6.RectArea.md`, B006 RectArea report, current generated `RectBounds.cpp` already emits UID00015T. | Target C++ block note and Function/Child Inventory; support `by-file/RectBounds.md` Proposed Contents/Generated Output Caveats. | incorporate | applied - UID00015S C++ block omits `RectArea`; target Item Summary and `by-file/RectBounds.md` Generated Output Caveats preserve UID00015T as separate `RectArea` emitter. |
| 00015S-C05 | Use exact formal first-draft C++ for all non-RectArea helpers in UID00015S. | High | MCP decompiles for all helper bodies; all helpers have zero callees; generated output previously had UID00015S empty marker. | Target `RECONSTRUCTION_CPP CODE` block. | incorporate | applied - target `RECONSTRUCTION_CPP CODE` now contains the accepted non-RectArea helper block; validator `000000007465` refreshed `auto-generated/NexusTK/ui/core/RectBounds.cpp` so UID00015S is no longer an empty marker. |
| 00015S-C06 | Use `struct Point { int y; int x; };` and `InitPointPair(Point *point, int y, int x)` in UID00015S. | Medium-high | No standalone by-type `Point`/`PointPair` page found; `ScrollVolumePane.md` forward-declares `struct Point`; `ScrollCollectionPaneLayout.md` uses `Point m_thumbDragOffset`; `ScrollNewGroupPane.md` names `InitPointPair(Point *out, int y, int x)`; MCP decompile stores first component then second/+4. | Target C++ block and helper inventory; support `by-file/RectBounds.md` Proposed Contents; support `by-class/RectBounds.md` file-level helper list; support `by-type/by-struct/RectBoundsLayout.md` Semantics. | incorporate | applied - target formal block emits `struct Point` and `InitPointPair(Point *point, int y, int x)`; all three support docs record `Point` y/x and historical/descriptive-only `PointPair` treatment where relevant. |
| 00015S-C07 | Use `InsetRect(RectBounds *bounds, int dx, int dy)` as the primary source-facing name for `0x004b7e30`. | High | MCP decompile shows positive deltas inset/shrink and midpoint-clamp inverted axes; B002 SelectBox already uses `InsetRect`; B001 RectBounds report recorded `InflateRect`/`InsetRect` caveat. | Target helper row, C++ block, notes; support `by-file/RectBounds.md` Proposed Contents; support `by-class/RectBounds.md` helper fanout list; support `by-type/by-struct/RectBoundsLayout.md` Semantics. | incorporate | applied - target helper row, C++ block, Evidence Notes, Source-Quality Decisions, and all three support docs now use primary `InsetRect(RectBounds *bounds, int dx, int dy)` wording. |
| 00015S-C07A | Retain `InflateRect_4B7E30` only as a historical/stale address-suffixed alias, not as emitted helper code. | High | Current by-file/target docs still carried `InflateRect_4B7E30`; live MCP behavior and accepted SelectBox usage support `InsetRect` instead. | Target notes and support `by-file/RectBounds.md` / `by-class/RectBounds.md` historical alias wording. | historicalize | applied - target and support docs describe `InflateRect_4B7E30` as stale/search or historical alias only; generated UID00015S output emits `InsetRect` and no `InflateRect_4B7E30` wrapper. |
| 00015S-C08 | Preserve `PointInRect(int y, int x, const RectBounds *bounds)` as canonical. | High | MCP decompile compares second argument to left/right and first to top/bottom; `RectBoundsLayout.md` rejects x/y order; accepted B001/B006/B011/B012 reports use y/x order. | Target C++ block and evidence notes; support `RectBoundsLayout.md` Semantics; support `by-file/RectBounds.md` Proposed Contents; support `by-class/RectBounds.md` helper list. | incorporate | applied - target C++ and evidence notes use `PointInRect(int y, int x, const RectBounds *bounds)`; `by-file`, `by-class`, and layout support docs repeat canonical y/x order. |
| 00015S-C09 | Do not edit downstream caller target pages for stale `PointInRect` order in this UID00015S implementation. | High | Search found stale/inconsistent examples in TabPane, VoteMenu, MenuVariety, FittingRoom, ScrollBar, SelfLookPane, and target-selection outputs; those are generated from separate by-memory/source-owner pages and require owner-specific coordinate audits. | Implementation checklist; Recommended Support Doc Changes; downstream by-memory caller pages. | exclude | excluded-with-reason - no downstream caller by-memory pages or generated caller files were manually edited; target and support docs record that caller repair belongs to separate owner-page audits. |
| 00015S-C10 | Preserve `RectContainsRect(const RectBounds *innerBounds, const RectBounds *outerBounds)` argument order. | High | MCP decompile of `0x004b7f30` returns true for empty first/inner and otherwise checks second/outer contains first; B008 Region report supplies corrected two-callsite order. | Target C++ block and Function/Child Inventory; support `by-file/RectBounds.md` Proposed Contents. | incorporate | applied - target C++ emits `RectContainsRect(const RectBounds *innerBounds, const RectBounds *outerBounds)` and target/support notes record inner/outer order and empty-inner behavior. |
| 00015S-C11 | Update `by-file/RectBounds.md` to record UID00015S as emitting free helper bodies, with UID00015T still separate and `InflateRect_4B7E30` retained only as historical alias. | High | Current `by-file/RectBounds.md` named UID00015S in Proposed Contents, still said `OffsetRect`, `InflateRect_4B7E30`, and generated-output caveat said UID00015S was empty. | Support `by-file/RectBounds.md` Proposed Contents and Generated Output Caveats. | incorporate | applied - `by-file/RectBounds.md` Proposed Contents and Generated Output Caveats now record UID00015S free-helper emission, UID00015T `RectArea` separation, `InsetRect`, canonical `PointInRect`, and generated-output caveats; validator `000000007467` exited 0. |
| 00015S-C12 | Update `by-class/RectBounds.md` only to clarify these are file-level/free helpers, not class methods, and to prefer `InsetRect`/canonical point order in the helper list. | Medium-high | Class page already separates class methods from free helpers but still listed `InflateRect` in the free helper fanout note. | Support `by-class/RectBounds.md` Status/Source-quality/helper inventory. | incorporate | applied - `by-class/RectBounds.md` now keeps UID00015S helpers in the file-level/free-helper section, uses `InsetRect`, and records canonical point/order decisions without converting helpers into class methods; validator `000000007468` exited 0. |
| 00015S-C13 | Update `by-type/by-struct/RectBoundsLayout.md` to preserve the canonical `PointInRect(y, x, bounds)`, add the UID00015S `Point {y,x}` support-type decision, and retain inset midpoint semantics. | Medium-high | Layout page already records y/x order and inset midpoint semantics; it lacked the final UID00015S point-type decision. | Support `by-type/by-struct/RectBoundsLayout.md` Semantics/Changes. | incorporate | applied - layout Semantics now record the UID00015S `Point { y; x; }` decision, canonical `PointInRect(y, x, bounds)`, `RectContainsRect(innerBounds, outerBounds)`, and midpoint-clamping `InsetRect`; validator `000000007469` exited 0. |
| 00015S-C14 | Do not manually edit `auto-generated/NexusTK/**` generated C++ files. | High | Workflow generated-file rule; current generated caller files are validator output and include stale examples owned by other source pages. | `auto-generated/NexusTK/ui/core/RectBounds.cpp` and all other `auto-generated/NexusTK/**` files. | exclude | excluded-with-reason - no manual generated C++ edits were made; `auto-generated/NexusTK/ui/core/RectBounds.cpp` changed only through authorized validator deferred-generated refresh, latest header `validator-command-id: 000000007469`. |
| 00015S-C15 | Do not manually edit generated tracker/coverage reports. | High | Workflow generated/coverage rule; UID00015S tracker/coverage rows are validator-owned. | `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, any `-coverage-report.md`. | exclude | excluded-with-reason - no manual generated tracker or coverage report edits were made; scoped validators were the only commands allowed to update generated/project-level outputs. |
| 00015S-C16 | Do not edit lifecycle/archive files, validator state, supervisor ledgers, or report execution state in this phase. | High | User/supervisor boundary; B-agent role excludes execute_report, lifecycle commands, validator state, and supervisor ledger edits. | `executed-b-agent-research/**`, `tools/validator.ini`, queue/lock state, lifecycle/archive files, supervisor ledgers. | exclude | excluded-with-reason - no execute_report, dry-run/probing execute, lifecycle, archive, report-move, supervisor-ledger, or manual validator-state edits were run; command IDs came only from the required scoped validators. |
| 00015S-C17 | After implementation callback, run scoped file validators only for the edited target/support docs and verify generated freshness from validator output rather than hand-editing generated files. | High | Workflow validation rule; generated `RectBounds.cpp` freshness matters because UID00015S previously appeared as an empty marker. | Validator Results and Implementation Tracking Checklist. | incorporate | applied - all four scoped validators ran with `--apply`, exited 0, and reported deferred generated refresh; generated freshness check shows `RectBounds.cpp` header `000000007469` and UID00015S emits `Point`, `InsetRect`, `PointInRect`, and `RectContainsRect`. |

## Positive Evidence Summary
Live IDA MCP confirms every expected helper start in the range exists and has compact behavior matching RectBounds field operations. All twelve helper starts have no callees. The range-level signature is unique. The following range starts are confirmed: `0x004b7c30`, `0x004b7c50`, `0x004b7c70`, `0x004b7ca0`, `0x004b7cc0`, `0x004b7d70`, `0x004b7e10`, `0x004b7e30`, `0x004b7e80`, `0x004b7eb0`, `0x004b7ed0`, and `0x004b7f30`.

The ownership evidence is strong. `RectBounds.cpp` already emits adjacent/class helpers and the exact child `RectArea`; support docs consistently describe RectBounds as the common lower-level rectangle geometry source. Coverage/tracker output identifies UID00015S as reconstructable with report count 0 and currently not emitting code.

## Negative Evidence Summary
No direct symbol names are present in IDA for the helper starts; the functions remain `sub_4B7...`, so source-facing names are reconstructed from behavior and existing project usage. That prevents a high-90s confidence score.

Generated C++ currently contains inconsistent downstream usage for some helper names and signatures, especially `PointInRect` order in stale generated callers and aliases around the `0x004b7e30` inset/inflate helper. This is negative evidence against a higher score, but it is not an implementation blocker for UID00015S once the target/support docs canonicalize the helper signatures. UID00015S does not own the formal C++ blocks for TabPane, FittingRoom, VoteMenu, MenuVariety, ScrollBar, SelfLookPane, PowerDialog, or TargetSelectionInput pages; those must be corrected in their own target/support pages if and when the supervisor assigns them. The UID00015S callback should not hand-edit generated caller files.

There is no evidence that Region owns these helpers. Region consumes or wraps lower-level rectangle operations; it does not own the common four-int RectBounds geometry island.

## Ranked Ownership Analysis
1. `NexusTK/ui/core/RectBounds.cpp` / UID0000N2: best owner. The helper bodies operate on `RectBounds` layout, have broad fanout, are documented by current RectBounds file/class/type pages, and already sit among adjacent RectBounds helper ranges in generated output.
2. `RectBounds` class UID0000BU: partial conceptual owner only. Some adjacent helpers are class methods, but the functions in UID00015S are cdecl/free helpers with broad callsites and no `this` parameter. They should stay file-level under UID0000N2, not become class methods.
3. `Region.cpp`: rejected. Region docs identify higher-level dirty-region operations and wrappers; MCP/body evidence shows UID00015S is lower-level common geometry.
4. Feature-local UI/render/map files: rejected. The xref distribution is too broad and the helper bodies are generic RectBounds math.
5. Generic `util/Geometry` fallback: rejected unless future source import proves a separate original module. Current project structure places this island in `ui/core/RectBounds.cpp`.

## Source Placement
Keep UID00015S in `NexusTK/ui/core/RectBounds.cpp`, near the existing RectBounds free helper declarations and the already emitted UID00015T `RectArea`. The first-draft helper declarations should be available to other generated files through the same RectBounds support surface used by current generated callers.

The target page should remain a by-memory aggregate for the range. No new child pages are required for this report. The already-existing `RectArea` child page should remain authoritative for `0x004b7ca0`.

## IDA Rename / Type / Comment Recommendations
No IDA database edits were requested or made during this callback.

Source-facing type/name recommendations for by-* docs and formal C++:
- `struct Point { int y; int x; };` should be defined in the UID00015S formal C++ block as the current best shared geometry point type. Do not use `PointPair` in the formal UID00015S block; preserve `PointPair` only as historical/descriptive support wording where older layout pages already use it.
- `InitPointPair(Point *point, int y, int x)` should remain the helper name/signature for `0x004b7c30`; it stores the first/vertical component at offset `0` and the second/horizontal component at `+4`.
- `InsetRect(RectBounds *bounds, int dx, int dy)` should be the helper name/signature for `0x004b7e30`. Replace primary `InflateRect_4B7E30` target/support wording with `InsetRect`; retain `InflateRect_4B7E30` only in historical/search notes if needed.
- `PointInRect(int y, int x, const RectBounds *bounds)` is canonical. Do not change it to `PointInRect(x, y, bounds)` or `PointInRect(bounds, x, y)` in UID00015S.
- `RectContainsRect(const RectBounds *innerBounds, const RectBounds *outerBounds)` is canonical.

## Range / Split / Padding / Reclassification Analysis
The current range `0x004b7c30-0x004b7f87` is valid. `0x004b7c21-0x004b7c30` is padding after the preceding quarter-scale helper range, and `0x004b7f87-0x004b7f90` is padding before the anchor-transform range. Live MCP lookup reports `0x004b7f90` is not a function, matching the documented split before `0x004b7f90-0x004b8194.RectAnchorTransformHelpers.md`.

No split is recommended inside UID00015S for this phase. `RectArea` already has child UID00015T and can continue to emit separately; the rest of the range is coherent enough to remain under a single RectGeometryHelpers aggregate because all helpers operate on the same four-int rectangle/point geometry layer and share the same owner.

No reclassification to compiler-generated, thunk, dead code, no-owner, or no-emitter is supported.

## Function / Child Inventory
| Address | IDA function | Size | Recommended source-facing role | Calls |
|---|---:|---:|---|---:|
| `0x004b7c30` | `sub_4B7C30` | `0x13` | `InitPointPair(Point *point, int y, int x)` | 0 |
| `0x004b7c50` | `sub_4B7C50` | `0x1f` | `InitRectBounds(RectBounds *bounds, int left, int top, int right, int bottom)` | 0 |
| `0x004b7c70` | `sub_4B7C70` | `0x25` | `InitRectBoundsFromSize(RectBounds *bounds, int left, int top, int width, int height)` | 0 |
| `0x004b7ca0` | `sub_4B7CA0` | `0x16` | `RectArea(const RectBounds *bounds)`; child UID00015T already emits | 0 |
| `0x004b7cc0` | `sub_4B7CC0` | `0xa9` | `IntersectRects(const RectBounds *firstBounds, const RectBounds *secondBounds, RectBounds *outBounds)` | 0 |
| `0x004b7d70` | `sub_4B7D70` | `0x93` | `UnionRects(const RectBounds *firstBounds, const RectBounds *secondBounds, RectBounds *outBounds)` | 0 |
| `0x004b7e10` | `sub_4B7E10` | `0x19` | `OffsetRect(RectBounds *bounds, int dx, int dy)` | 0 |
| `0x004b7e30` | `sub_4B7E30` | `0x4f` | `InsetRect(RectBounds *bounds, int dx, int dy)` with midpoint clamp | 0 |
| `0x004b7e80` | `sub_4B7E80` | `0x27` | `PointInRect(int y, int x, const RectBounds *bounds)` | 0 |
| `0x004b7eb0` | `sub_4B7EB0` | `0x1d` | `IsRectEmptyOrInvalid(const RectBounds *bounds)` | 0 |
| `0x004b7ed0` | `sub_4B7ED0` | `0x52` | `RectsEquivalent(const RectBounds *firstBounds, const RectBounds *secondBounds)` | 0 |
| `0x004b7f30` | `sub_4B7F30` | `0x57` | `RectContainsRect(const RectBounds *innerBounds, const RectBounds *outerBounds)` | 0 |

## Direct Xref / Caller Inventory
Live MCP `xref_query` returned the following code-xref counts and sample callers:

| Address | Count | Sample refs |
|---|---:|---|
| `0x004b7c30` | 102 | `0x41d9d3`, `0x41e872`, `0x41edb0`, `0x41edc2`, `0x41f580` |
| `0x004b7c50` | 1731 | `0x41c7c8`, `0x41c7d9`, `0x41c856`, `0x41c867`, `0x41c8e6` |
| `0x004b7c70` | 38 | `0x41c1c9`, `0x41cd92`, `0x41d182`, `0x41d1a2`, `0x41d1bc` |
| `0x004b7ca0` | 4 | `0x4580de`, `0x4581da`, `0x45833d`, `0x4b621a` |
| `0x004b7cc0` | 91 | `0x41dc53`, `0x41df56`, `0x41e115`, `0x459e7d`, `0x45a183` |
| `0x004b7d70` | 37 | `0x4d5d89`, `0x4d69e6`, `0x4d8595`, `0x4d85a0`, `0x4d85ae` |
| `0x004b7e10` | 368 | `0x41c75b`, `0x41c777`, `0x41c7ee`, `0x41c834`, `0x41c884` |
| `0x004b7e30` | 32 | `0x424153`, `0x46af38`, `0x46af6a`, `0x46af91`, `0x46afd0` |
| `0x004b7e80` | 270 | `0x41d913`, `0x41e4ac`, `0x41fd39`, `0x420b08`, `0x420bfe` |
| `0x004b7eb0` | 32 | `0x46827a`, `0x468449`, `0x468780`, `0x468a31`, `0x4b9064` |
| `0x004b7ed0` | 7 | `0x4561ef`, `0x4b8e68`, `0x4f1771`, `0x4f184f`, `0x53778b` |
| `0x004b7f30` | 2 | `0x554a4a`, `0x554a83` |

The counts support a shared geometry helper island rather than a feature-local helper.

## IDA MCP Facts
MCP endpoint used: `http://127.0.0.1:13337/mcp`.

Active database session:
- `session_id`: `supervisor_recovery_20260705`
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Module: `NexusTK.exe`
- Imagebase: `0x400000`
- Server status: `ok`
- Auto-analysis ready: `true`
- Hex-Rays ready: `true`
- Strings cache ready: `true`

Tool facts gathered:
- `lookup_funcs` confirmed all twelve target helper starts and reported `0x004b7f90` as not a function.
- `callees` returned no callees for all twelve helper starts.
- `decompile` confirmed the field-level behavior of each helper body.
- `xref_query` confirmed broad caller fanout and the two-callsite containment helper.
- `make_signature_for_range` for `0x004b7c30-0x004b7f87` returned `unique: true`.

Selected decompile facts:
- `0x004b7c30` writes two 32-bit fields: first argument value at offset `0`, second at offset `4`, matching a y/x point-pair initializer.
- `0x004b7c50` writes `left, top, right, bottom`.
- `0x004b7c70` writes `right = left + width` and `bottom = top + height`.
- `0x004b7cc0` rejects empty input rectangles, computes max left/top and min right/bottom, rejects empty result, and zeroes optional output on failure.
- `0x004b7d70` copies the non-empty rectangle if either input is empty, otherwise computes min left/top and max right/bottom.
- `0x004b7e30` positive deltas inset the rectangle and clamp inverted axes to signed midpoints.
- `0x004b7e80` checks `left <= x < right` and `top <= y < bottom` with argument order `y, x, bounds`.
- `0x004b7f30` returns true for an empty inner rectangle and otherwise tests whether outer contains inner.

## First-Draft C++ Recommendation
The following block was applied to UID00015S during the implementation callback. It intentionally omits `RectArea`, because UID00015T already owns and emits that exact helper. The block has no unresolved placeholders: it chooses `Point` as the emitted two-int type, `InsetRect` as the emitted helper name for `0x004b7e30`, and canonical y/x argument order for point helpers.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct Point
{
    int y;
    int x;
};

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

bool IntersectRects(const RectBounds *firstBounds, const RectBounds *secondBounds, RectBounds *outBounds)
{
    if (firstBounds->bottom <= firstBounds->top ||
        firstBounds->right <= firstBounds->left ||
        secondBounds->bottom <= secondBounds->top ||
        secondBounds->right <= secondBounds->left) {
        if (outBounds != nullptr) {
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
        if (outBounds != nullptr) {
            InitRectBounds(outBounds, 0, 0, 0, 0);
        }
        return false;
    }

    if (outBounds != nullptr) {
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
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Implementation notes:
- The `Point` definition is intentional for this UID00015S draft. Current project docs have no authoritative standalone point by-type page, and the strongest current class/layout docs already use `Point` in project `y,x` order.
- Do not emit `InflateRect_4B7E30` as a wrapper or alias in this C++ block. Historical docs may mention it only as the previous address-suffixed name for `InsetRect`.
- Do not try to repair unrelated generated caller C++ from this target. The UID00015S scoped validators refreshed `auto-generated/NexusTK/ui/core/RectBounds.cpp`; other generated files remain governed by their own by-memory/source pages.

## Final Recommendation
UID00015S is ready for renewed supervisor Gate 1 review as an applied source-quality correction. The callback updated only the UID00015S target and the listed RectBounds support docs authorized by the supervisor; generated output changed only through scoped validators. The target page now has the formal helper C++ block above, preserves UID00015T as the separate `RectArea` child, records live MCP evidence, defines/uses `Point` for the two-int point support type, and uses `InsetRect` as the primary `0x004b7e30` helper name.

Do not reassign ownership, do not move this to Region, and do not split the remaining helper bodies unless future original-source evidence requires it.

## Recommended Target Doc Changes
- Added the exact first-draft `RECONSTRUCTION_CPP CODE` block from this report to `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md`, excluding `RectArea`.
- Updated the target notes to cite the current MCP session facts: all helper starts confirmed, all no-callee, `0x004b7f90` not a function, range signature unique, and broad xref counts.
- Renamed the primary `0x004b7e30` helper row and notes to `InsetRect`. Preserved `InflateRect_4B7E30` only as historical/stale alias text, not as the emitted helper name.
- Recorded the point-type decision: `struct Point` with `y` at offset `0` and `x` at `+4`; `PointPair` is not the formal UID00015S type.
- Preserved `PointInRect(int y, int x, const RectBounds *bounds)` and `RectContainsRect(const RectBounds *innerBounds, const RectBounds *outerBounds)` argument order.
- Raised the target score to `Completion: 90`, `Confidence: 91`.

## Recommended Support Doc Changes
- `by-file/RectBounds.md`: updated Proposed Contents so UID00015S free helpers are source-ready and `0x004b7e30` is `InsetRect`, with `InflateRect_4B7E30` historicalized. Updated Generated Output Caveats so UID00015S emits after scoped validation, while UID00015T still owns `RectArea`.
- `by-class/RectBounds.md`: kept these helpers described as file-level/free helpers, not class methods. Updated the helper/fanout wording to prefer `InsetRect` and canonical `PointInRect(y, x, bounds)`.
- `by-type/by-struct/RectBoundsLayout.md`: preserved the `left, top, right, bottom` layout and half-open hit-test semantics; added the UID00015S point decision that the shared source-facing `Point` type is `y,x` for this helper block.
- Downstream caller by-memory/source pages are out of scope for this UID00015S implementation. Do not edit TabPane, FittingRoom, MenuVariety, VoteMenu, ScrollBar, SelfLookPane, PowerDialog, TargetSelectionInput, or other caller pages solely because generated C++ currently has stale `PointInRect` order. Those pages require owner-specific coordinate audits.
- Do not manually edit `auto-generated/-ag-research-tracker.md`, coverage reports, generated C++ output, validator state, lifecycle/archive files, or supervisor ledgers.

## Score And Metadata Recommendation
Applied after implementation:
- `COMPLETION: 90`
- `CONFIDENCE: 91`
- `RECONSTRUCTABLE: true`
- `OWNER_UID: 0000N2`
- `EMITTER_UID: 0000N2`
- `EMITTER_POSITION_OPTIONAL`: unchanged/blank

Rationale: body-level MCP evidence is strong, source placement is mature, the point type is resolved to `Point` for this target, and the `0x004b7e30` helper name is resolved to `InsetRect` with the old `InflateRect_4B7E30` name historicalized. `90/91` is justified because UID00015S now owns source-ready formal helper C++ and exact MCP-backed helper behavior.

Reason not higher: IDA still has no original symbols for the helpers, so names such as `InitPointPair`, `IntersectRects`, `UnionRects`, `InsetRect`, and `RectsEquivalent` remain inferred/source-facing rather than proven original spellings. Downstream caller pages contain stale or inconsistent `PointInRect` forms, but those are separate target/source-owner cleanup items and should not block UID00015S from reaching `90/91`. They do prevent treating the shared point/caller ecosystem as final/high-90s.

## Open Questions With Attempted Resolution
Question: Should `0x004b7e30` be called `InflateRect`, `InflateRect_4B7E30`, `InsetRectBounds`, or `InsetRect`?

Resolved direction: use `InsetRect`. MCP decompile shows positive deltas shrink/inset and negative deltas expand; the body also clamps inverted axes to signed midpoints. B002 SelectBoxControlPane already used `InsetRect(&frame, 1, 1)` for this behavior, while `by-file/RectBounds.md` and the UID00015S target previously retained the older `InflateRect_4B7E30` address alias. The implementation replaced the primary helper name with `InsetRect` in UID00015S and RectBounds support docs, preserved `InflateRect_4B7E30` only as a historical/search alias, and did not emit an `InflateRect_4B7E30` wrapper.

Question: Should UID00015S define `Point`, `PointPair`, or avoid a struct for `0x004b7c30`?

Resolved direction: define and use `Point`. No authoritative standalone by-type `Point`/`PointPair` page was found. Current support docs are mixed, but the stronger emitted/declaration-facing pattern is `Point`: `by-class/ScrollVolumePane.md` forward-declares `struct Point` and stores `Point m_thumbDragOffset`; `by-type/by-struct/ScrollCollectionPaneLayout.md` uses `Point m_thumbDragOffset` in project `y,x` order; `by-class/ScrollNewGroupPane.md` names `InitPointPair(Point *out, int y, int x)`. `PointPair` should remain descriptive/historical where older layout notes use it, not the UID00015S formal type. The formal block now keeps `struct Point { int y; int x; };`.

Question: Should UID00015S implementation repair stale generated or downstream caller `PointInRect` order?

Resolved direction: no, except for RectBounds support docs that define the helper contract. UID00015S now canonicalizes `PointInRect(int y, int x, const RectBounds *bounds)` in the target, `by-file/RectBounds.md`, `by-class/RectBounds.md`, and `by-type/by-struct/RectBoundsLayout.md`. It did not edit unrelated caller pages or generated caller output. Evidence searches found examples such as generated TabPane `PointInRect(&rect, x, y)`, generated VoteMenu/MenuVariety `PointInRect(rect, x, y)`, generated ScrollVolume `PointInRect(x, y, &rect)`, and by-memory FittingRoom pages with old rect-first forms. Those are independent source pages whose local coordinate names and formal C++ require owner-specific review. The UID00015S validators refreshed `auto-generated/NexusTK/ui/core/RectBounds.cpp`; they did not rewrite those other caller docs.

Question: Should the range be split into per-helper child docs?

Resolved direction: no. `RectArea` is already split and emits. The remaining helpers are compact no-callee common geometry helpers with shared ownership and coherent source placement. An aggregate C++ block is sufficient.

## Validator Results
Implementation callback validators were run only after the relevant by-* file lease/edit batch, from `E:\NTK\GhidraBridge\source-3\project-documentation`.

| File | Command | command_id | command_timestamp | Exit code | ok count | Warnings | Generated freshness state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md` | `python .\tools\validator.py --mode file --file by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md --apply --queue-timeout 240` | `000000007465` | `2026-07-05T23:34:25-04:00` | 0 | 1 | none | `generated_refresh: deferred`; `generated_refresh_command_id: 000000007465`; `generated_refresh_timestamp: 2026-07-05T23:34:25-04:00`; target validator also reported `completion_update 00015S 90`, `confidence_update 00015S 91`, and `autogen registry blank -> block`. |
| `by-file/RectBounds.md` | `python .\tools\validator.py --mode file --file by-file/RectBounds.md --apply --queue-timeout 240` | `000000007467` | `2026-07-05T23:35:26-04:00` | 0 | 1 | `missing_ref_uid: 4` for pre-existing `00040U` references not present in `validator.ini`. | `generated_refresh: deferred`; `generated_refresh_command_id: 000000007467`; `generated_refresh_timestamp: 2026-07-05T23:35:26-04:00`. |
| `by-class/RectBounds.md` | `python .\tools\validator.py --mode file --file by-class/RectBounds.md --apply --queue-timeout 240` | `000000007468` | `2026-07-05T23:36:23-04:00` | 0 | 1 | none | `generated_refresh: deferred`; `generated_refresh_command_id: 000000007468`; `generated_refresh_timestamp: 2026-07-05T23:36:23-04:00`. |
| `by-type/by-struct/RectBoundsLayout.md` | `python .\tools\validator.py --mode file --file by-type/by-struct/RectBoundsLayout.md --apply --queue-timeout 240` | `000000007469` | `2026-07-05T23:36:58-04:00` | 0 | 1 | none | `generated_refresh: deferred`; `generated_refresh_command_id: 000000007469`; `generated_refresh_timestamp: 2026-07-05T23:36:58-04:00`. |

Generated freshness check after the final validator:
- `auto-generated/NexusTK/ui/core/RectBounds.cpp` header reports `validator-command-id: 000000007469`, `validator-refreshed-at: 2026-07-05T23:36:58-04:00`, and `validator-refresh-source: deferred-generated-refresh`.
- UID00015S is no longer an empty emitter marker in that generated file. The refreshed output contains `struct Point` at line 252, `InsetRect` at line 339, `PointInRect` at line 359, and `RectContainsRect` at line 382.

Lease record:
- `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md`: lease success, edit, validator `000000007465`, unlease success.
- `by-file/RectBounds.md`: lease success, edit, validator `000000007467`, unlease success.
- `by-class/RectBounds.md`: lease success, edit, validator `000000007468`, unlease success.
- `by-type/by-struct/RectBoundsLayout.md`: lease success, edit, validator `000000007469`, unlease success.
- `tools/leaser/Agents/current_leases.md` checked after callback: no active leases.

No `execute_report`, dry-run/probing execute variant, report move, lifecycle, archive, manual generated edit, manual coverage edit, manual validator-state edit, or supervisor-ledger edit was run.

## Changed Files
Manual B015 edits:
- `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md`
- `by-file/RectBounds.md`
- `by-class/RectBounds.md`
- `by-type/by-struct/RectBoundsLayout.md`
- `tools/leaser/Agents/Agent-B015/research/00015S-RectGeometryHelpers-source-quality.md`

Validator/tool-generated side effects from the required scoped `--apply` validators:
- `auto-generated/NexusTK/ui/core/RectBounds.cpp` refreshed by validator, latest header command `000000007469`.
- `project-level/-auto-completion-stats.md` updated by validator stats rows/projection handling.

Leaser-generated state side effect from required lease/unlease operations:
- `tools/leaser/Agents/current_leases.md` updated by leaser commands and checked afterward; final state is no active leases.

No downstream caller by-memory pages were manually edited. No generated C++, generated tracker/coverage report, coverage report, validator state, lifecycle/archive file, report execution registry, or supervisor ledger was manually edited.

## Implementation Tracking Checklist
- [x] applied - Supervisor Gate 1 approved the repaired report at SHA256 `7E9F210BC6679238F7518B114530290D5F53F89EDA763E7649001644D8506C65` before by-* implementation.
- [x] applied - Target edit completed in `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md` after leasing the file; target validator `000000007465` exited 0; lease was released.
- [x] applied - Target metadata set `COMPLETION:90`, `CONFIDENCE:91`; `CANONICAL_OWNER:0000N2`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N2`, and blank/unchanged `EMITTER_POSITION_OPTIONAL` were preserved.
- [x] applied - Target C++ insertion contains the exact accepted formal block except `RectArea`: `struct Point`, `InitPointPair`, `InitRectBounds`, `InitRectBoundsFromSize`, `IntersectRects`, `UnionRects`, `OffsetRect`, `InsetRect`, `PointInRect`, `IsRectEmptyOrInvalid`, `RectsEquivalent`, and `RectContainsRect`.
- [x] applied - Target C++ exclusion preserved UID00015T as the separate `RectArea(const RectBounds *bounds)` emitter; UID00015S does not duplicate `RectArea`.
- [x] applied - Target source-name cleanup uses `InsetRect` as the primary `0x004b7e30` helper name and keeps `InflateRect_4B7E30` only as stale/search historical alias text.
- [x] applied - Target type cleanup documents `Point` as the formal two-int y/x support type and does not use `PointPair` in the formal C++ block.
- [x] applied - Target caller-contract cleanup records canonical `PointInRect(y, x, bounds)` and `RectContainsRect(innerBounds, outerBounds)` argument order with MCP/session evidence.
- [x] applied - `by-file/RectBounds.md` Proposed Contents and Generated Output Caveats now record UID00015S free-helper emission, UID00015T separate `RectArea`, `InsetRect`, canonical `PointInRect`, `RectContainsRect`, and generated-output caveats; validator `000000007467` exited 0.
- [x] applied - `by-class/RectBounds.md` keeps UID00015S as file-level/free helpers, not class methods; records `InsetRect` and canonical point-helper order; validator `000000007468` exited 0.
- [x] applied - `by-type/by-struct/RectBoundsLayout.md` records `Point` y/x, half-open `PointInRect(y, x, bounds)`, `RectContainsRect(innerBounds, outerBounds)`, and midpoint-clamping `InsetRect`; validator `000000007469` exited 0.
- [x] excluded-with-reason - Downstream caller pages were not edited: TabPane, FittingRoom, MenuVariety, VoteMenu, ScrollBar, ScrollVolumePane, SelfLookPane, PowerDialog, TargetSelectionInput, map/dialog input, and other caller pages remain out of scope because they own their own formal C++ and coordinate-name audits.
- [x] excluded-with-reason - No manual edit was made to `auto-generated/NexusTK/ui/core/RectBounds.cpp` or any other `auto-generated/NexusTK/**` file; `RectBounds.cpp` changed only through required validator refresh.
- [x] excluded-with-reason - No manual edit was made to generated tracker/coverage files, `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, or any manual/generated `-coverage-report.md`.
- [x] excluded-with-reason - No lifecycle/archive, execute_report, dry-run/probing execute, report-move, supervisor-ledger, queue/lock, or manual validator-state edit was performed; scoped validators only produced their own command metadata.
- [x] applied - Target scoped validator ran: `python .\tools\validator.py --mode file --file by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md --apply --queue-timeout 240`, command `000000007465`, timestamp `2026-07-05T23:34:25-04:00`, exit 0, ok 1.
- [x] applied - `by-file/RectBounds.md` scoped validator ran: command `000000007467`, timestamp `2026-07-05T23:35:26-04:00`, exit 0, ok 1, warning `missing_ref_uid: 4` for pre-existing `00040U`.
- [x] applied - `by-class/RectBounds.md` scoped validator ran: command `000000007468`, timestamp `2026-07-05T23:36:23-04:00`, exit 0, ok 1, no warnings.
- [x] applied - `by-type/by-struct/RectBoundsLayout.md` scoped validator ran: command `000000007469`, timestamp `2026-07-05T23:36:58-04:00`, exit 0, ok 1, no warnings.
- [x] applied - Validator reporting now records every command, command_id, command_timestamp, exit code, ok count, warning state, generated refresh state, lease state, and generated freshness proof in this report.
- [x] applied - Generated freshness check confirms `auto-generated/NexusTK/ui/core/RectBounds.cpp` header `validator-command-id: 000000007469`, `validator-refreshed-at: 2026-07-05T23:36:58-04:00`, `validator-refresh-source: deferred-generated-refresh`; UID00015S emits `struct Point`, `InsetRect`, `PointInRect`, and `RectContainsRect`.
- [x] applied - Claim ledger callback state updated for every accepted row as `applied` or `excluded-with-reason` with proof; no row remains `proposed`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B015","command_id":"000000007478","destination_path":"executed-b-agent-research/B015/00015S-RectGeometryHelpers-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B015/research/00015S-RectGeometryHelpers-source-quality.md","timestamp":"2026-07-06T00:09:22-04:00","uid":"00015S"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
