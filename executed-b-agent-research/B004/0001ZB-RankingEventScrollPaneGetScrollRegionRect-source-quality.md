** TARGET-REPORT-UID:0001ZB **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# 0001ZB RankingEventScrollPaneGetScrollRegionRect Source-Quality Research


## Finalized Report / Current Recommendation

- Current recommendation: implemented. [UID:0001ZB] now carries the full source-authored private method `void RankingEventScrollPane::GetPartRect(RankingScrollPart part, RectBounds *outRect)` using the exact Gate 1-managed C++ block.
- Final disposition: target range, UID, `RankingEventScrollPane` owner/emitter, reconstructable state, blank emitter position, and `NexusTK/ui/dialogs/RankingDialog.cpp` source route remain unchanged; target score moved from `86/90` to `89/91`.
- Required action: no implementation item remains. Target, class, layout, and file-route details are synchronized and scoped-validated; supervisor-owned report execution/archive state remains external to B004.
- Confidence: high for the exact machine behavior, boundary, callers, callees, fields, argument order, and owner/source route; medium-high for the implementation-ready source-facing names because the stripped IDB has no preserved Ranking-specific UDT or enum.

## Supporting Research

- MCP evidence was collected on 2026-07-12 through streamable endpoint `http://127.0.0.1:13337/mcp`, transport session `afe803e9-169f-4354-a72a-da4af9dd99d1`, and NexusTK IDB database `bf5519ae`. `idb_list` request `62003` returned that database and worker PID 14356; `server_health` request `62004` reported status `ok`, imagebase `0x00400000`, and ready auto-analysis, Hex-Rays, and string cache. These are evidence-time facts, not an assertion of indefinite session availability.
- Target MCP requests were `lookup_funcs` `62006`, `analyze_function` `62007`, complete decompilation reads `62008` and `62016`, `type_query` `62013`, `xrefs_to` `62017`, `callees` `62018`, and boundary `get_bytes` `62019`.
- Source-family comparison requests `62014-62015` checked `ScrollCollectionPane::GetPartRect` at `0x00562bf0`. It has the same 39-block, cyclomatic-11 geometry shape and the same three direct callees, but uses a skin-indexed vertical span at `0x00624144`; this corroborates the method family without replacing Ranking-specific literal `38` behavior.
- Existing source-ready [UID:0000Y4] `HitTestPart` independently duplicates the target's five-part geometry, field names, y/x convention, vertical drag clamp, literal `38`, and horizontal height-based span. [UID:0000Y3] and [UID:0001ZA] already call `GetPartRect` in formal C++.
- The source-ready FittingRoom counterpart [UID:0002D7] confirms the human-source method name/signature family and output-pointer/void disposition, but its leading/trailing cap geometry and skin-indexed vertical span differ. Those differences were preserved rather than copied into this target.
- Exact-report searches found no prior UID0001ZB research report. The executed B003 UID0000Y3 and UID0001ZA reports, executed B004 UID0000Y4 report, and executed B006 RankingDialog family report were treated as corroborating leads and checked against the current target binary rather than copied as authority.
- Gate 1 accepted exact report SHA256 `1EE84348BCBB99F49649536529ED4DBCBF15E30FAACD46AED663DA084ABAA915`. Callback validators `000000008486`, `000000008489`, `000000008491`, `000000008494`, phrase-only current-state refresh `000000008498`, and final waited refresh `000000008500` all exited `0` with `ok: 1`.
- B004's waited refresh completed as command `000000008500` at `2026-07-12T18:59:26-04:00`. At a post-callback read-only check, a newer concurrent validator refresh had advanced the generated header to command `000000008504` / `2026-07-12T19:01:28-04:00`; `RankingDialog.cpp` still contained one UID0001ZB marker, one `void RankingEventScrollPane::GetPartRect(...)` definition, and zero UID0001ZB Empty Emitter Markers. B004 did not run command `8504`; later global header movement does not invalidate the B004-owned waited command or the content counts.

## Target

- Target UID: `0001ZB`.
- Target path: `by-memory/0x0045a710-0x0045a98a.RankingEventScrollPaneGetScrollRegionRect.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`.
- Current supervisor classification: Gate 1-accepted implementation callback completed for the reconstructable source-authored helper; Gate 2 review is external to B004.
- Current scores and parent state: `89/91`, `CANONICAL_OWNER:0000BO`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000BO`, blank emitter position, zero nested children.

## Current Target State

- Existing metadata: exact stable physical page range `0x0045a710-0x0045a98a`; source-facing method direction `GetPartRect`; historical filename/title wording `GetScrollRegionRect` retained for link stability.
- Existing owner/emitter/reconstructable state: correct and unchanged. [UID:0000BO] `RankingEventScrollPane` is the semantic owner/emitter and [UID:0000MZ] `RankingDialog` is the source-file route.
- Existing C++/emitter state: the target managed block contains the exact complete method from this report. Historical pre-callback generated output had an Empty Emitter Marker at `86/90`; at the recorded post-callback read-only check, validator-generated output under header command `000000008504` contained one UID0001ZB method body at `89/91` and no target empty marker.
- Existing blocker: resolved. The target preserves the earlier UID0000Y4 declaration-only deferral explicitly as historical provenance while stating that the UID0001ZB full-body callback supersedes it.
- Existing open naming questions: exact historical spellings are not symbol-proven, but `GetPartRect`, `RankingScrollPart`, `RectBounds`, the six part values, field aliases, `Point`, `GetCursorPosition`, `GetScreenOffset`, and `InitRectBounds` are already accepted across the directly interacting pages and geometry support.
- Related target/support docs checked: UID0000Y3, UID0001ZA, UID0000Y4, UID0000Y5, UID0000Y6, UID0000Y7, UID0000BO, UID0001VO, UID0000MZ, broad UID0000XZ RankingDialog, UID00015S RectGeometryHelpers, UID0002D7 FittingRoom counterpart, generated RankingDialog output, coverage, and tracker.
- Current artifact/lifecycle status: implementation and validators are complete. B004 itself performed no execute, lifecycle, move, or archive command; supervisor-owned lifecycle state is external and must be read from validator headers/history and the artifact's current path. No implementation item remains.

## Executive Recommendation

- The exact method body now emits through `RankingEventScrollPane`, using the accepted Ranking-local enum, field, point, and rectangle vocabulary.
- Keep one modeled function and one target page. Do not split orientation branches, part cases, or the cursor/sentinel prefix into helper pages.
- Keep the target's historical filename/title for stable UID/path references while using `GetPartRect` as the source-facing method name.
- Treat absent original symbols and the incomplete whole-class declaration as score caps only. They do not block a first-draft method body under the active combined-score/emitter rule.

## Supervisor Active Recheck

- The supervisor accepted Gate 1 SHA256 `1EE84348BCBB99F49649536529ED4DBCBF15E30FAACD46AED663DA084ABAA915` and authorized C01-C24 implementation in exactly four named by-* documents.
- Split repair is not required. MCP reports exactly one modeled function from `0x0045a710` to exclusive end `0x0045a98b`, with clean alignment padding on both sides.
- Every source-bearing behavior in the target range is represented by the implemented single method body; no child, ignored subrange, table, or mixed-owner island remains inside it.

## Inference Research Guidance Check

- Binary facts, documentation facts, and source-shape inference are kept separate. Addresses, branches, field offsets, constants, xrefs, and writes are IDA facts; accepted names are documentation-backed inference; the `void` method declaration and structured local-variable shape are source reconstruction.
- The target page's declaration-only deferral was treated as uncertain and revalidated. It is now superseded by complete current decompilation, xref/callee checks, boundary bytes, accepted sibling geometry, and source-family comparison.
- `by-structure.md` discipline supports one class method under the established class/file route, not a generic rectangle owner or one child per branch.
- No Wave2/Wave3 artifact was used. Any such stale artifacts encountered by broader search were excluded unless represented by current by-* documentation or current IDB evidence.

## Heuristic / Inference Reanalysis And Validation

- Generated function name: IDA calls the function `sub_45A710`. The source-facing `GetPartRect` name is inferred, not original-symbol proof, but it is already used by formal UID0000Y3/UID0001ZA C++, the class/layout contract, the directly analogous FittingRoom and ScrollCollection methods, and the target's accepted declaration.
- Return type: Hex-Rays renders an incidental integer return. All meaningful results flow through `outRect`; all 15 callers consume the buffer and ignore EAX; analogous source-family methods use an output pointer. Resolve the source return as `void`.
- Argument order/type: the binary receives a byte-sized part value followed by the output rectangle pointer. Resolve this as `RankingScrollPart part, RectBounds *outRect`, matching accepted caller bodies and enum use. Do not reverse the arguments or return a rectangle by value.
- Rectangle and point types: `RectBounds` is four signed ints in left/top/right/bottom order. `Point` is y at offset 0 and x at +4. The cursor and origin calls fill `Point` values; both coordinates are localized before orientation logic, although only `cursor.y` participates in this target's drag branch.
- Sentinel: the function returns without writing `outRect` only when both origin components equal `-1000`. It does not return when either component alone equals the sentinel, initialize a fallback rectangle, or validate `outRect`.
- Part enum: values 0 through 4 are leading, page-before-thumb, thumb, page-after-thumb, and trailing; `0xff` is the separate no-part value used by interaction state. This method has no explicit `None` case.
- Bounds/field names: inherited `m_bounds` at `+0x44`, `m_thumbDragActive` `+0xfb`, `m_orientation` `+0xfc`, signed-short `m_scrollPosition` `+0xfe`, signed-short `m_scrollRange` `+0x100`, byte `m_enabled` `+0x102`, and `m_thumbDragOffset.y/.x` `+0x108/+0x10c` are implementation-ready inferred names validated across UID0000Y3/Y4/Y5/Y6 and UID0001ZA/VO.
- Horizontal geometry: nonzero orientation uses the control height, `bottom - top`, as thumb span. Leading and trailing parts are zero-width collapsed edges, not 38-pixel arrow rectangles. Enabled/range-positive thumb position is `left + position * (width - thumbSpan) / range`; active drag state is intentionally ignored in this branch.
- Vertical geometry: zero orientation uses literal `38` as `kRankingScrollThumbSpan`. Leading and trailing are zero-height collapsed edges. Enabled/range-positive normal position uses `top + position * (bottom - 38 - top) / range`.
- Vertical drag geometry: when `m_thumbDragActive` is set, thumb top is `top + localCursorY - m_thumbDragOffset.y`, then clamped first upward to `top` and second downward to `bottom - 38`. Preserve this order: on a pathologically shorter-than-38 bounds rectangle the second clamp can leave the result at the upper limit below `top`.
- Disabled/no-range behavior: part 2 returns the inner track after insetting by the orientation span. Parts 1 and 3 call `InitRectBounds(outRect, 0, 0, 0, 0)`. Leading/trailing remain collapsed edges. Other values return without writing.
- Invalid part behavior: in enabled/range-positive state, the function copies full bounds before the part tests, so an unrecognized non-0/non-4 value returns full bounds. In disabled/no-range state, such a value leaves the output untouched. The formal body preserves this asymmetry.
- Source placement: the method is feature-local `RankingEventScrollPane` behavior routed through `RankingDialog.cpp`. Generic RectBounds, EventMan, Pane, FittingRoom, and ScrollCollection code are dependencies/comparators, not owners.
- Rejected code shapes: reject calling UID0000Y4 from this method, factoring a generic scroll geometry helper, making horizontal drag use cursor.x, using 38 horizontally, using control height vertically, turning caps into fixed-width buttons, initializing output before the sentinel, or copying the FittingRoom end-cap/table behavior.
- Remaining unresolved issue: only exact original spellings and final class declaration integration remain unresolved. Current binary/source-family evidence makes the chosen names defensible for first-draft code; those caveats cap confidence and prevent final-audit scores but do not require blank C++.

## Evidence Standards Used

- Highest-weight evidence: current IDA MCP function boundary, complete decompilation, raw bytes, 15 direct xrefs, direct callee set, and field/branch behavior.
- Corroboration: formal source-ready callers, the independently reconstructed UID0000Y4 inline duplicate, canonical RectGeometry types/order, class/layout docs, and two analogous scrollbar `GetPartRect` families.
- Negative evidence: no preserved Ranking UDT/enum, no extra target callees, no vtable/data xref to the private helper, no internal table, no second function at `0x0045a990`, and no source evidence for generic or FittingRoom ownership.
- This evidence is sufficient for a first draft because the behavior is closed over one modeled function and every externally visible write/branch is resolved. Lack of original symbols and rebuild comparison prevents stronger final-source confidence.

## Evidence Checked

- IDA MCP/manual-disassembly/raw-byte checks performed: session list/health; target start/interior/end/successor lookup; full analyze/decompile; all xrefs; all callees; predecessor/successor bytes; type search; analogous `0x00562bf0` function analysis/decompile.
- by-* docs checked: target, class, layout, source-file route, broad RankingDialog island, six named interacting UIDs, RectGeometryHelpers, and FittingRoom counterpart.
- Generated/tracker checks: historical pre-callback target empty marker, auto memory coverage `emits`/not-coded row, and tracker `86/90`/zero-report row were recorded; post-callback read-only generated output under header command `000000008504` contained one target body and no target empty marker.
- Old-report checks: no exact UID0001ZB report; neighboring executed UID0000Y3, UID0001ZA, UID0000Y4, and RankingDialog-family reports used only as leads.
- Negative checks performed: no target split, no extra callee, no preserved Ranking type, no horizontal drag branch, no vertical skin table, no target-owned resource/global, and no direct evidence for alternate owner or return-by-value signature.
- Failed/unavailable/intentionally skipped checks: no source archive contains the original RankingEventScrollPane implementation; no IDA DB mutation or compiler rebuild was performed. Validators/generated refresh were intentionally deferred until the accepted callback and then completed as recorded below.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | Source method is `void RankingEventScrollPane::GetPartRect(RankingScrollPart part, RectBounds *outRect)`; historical page title/path stays stable. | High | MCP body/callers; accepted callers; source-family comparators | Target Status/Source-Shape/C++ | Applied | Target `8486`; B004 wait `8500`; read-only header `8504` |
| C02 | Exact modeled range is `0x0045a710-0x0045a98b`; physical page ends at inclusive byte `0x0045a98a`; pads are `CC` at `0x45a70c-0x45a70f` and `0x45a98b-0x45a98f`. | High | `lookup_funcs` 62006; `get_bytes` 62019 | Target IDA evidence | Applied | Target validator `8486` |
| C03 | Exactly 15 direct call sites exist across UID0000Y3, UID0001ZA, UID0000Y5, UID0000Y6, and UID0000Y7. | High | `xrefs_to` 62017 | Target caller inventory | Applied/preserved | Target validator `8486` |
| C04 | Only direct callees are cursor lookup `0x4a9090`, screen offset `0x5447c0`, and empty-rect initializer `0x4b7c50`. | High | `callees` 62018; decompile | Target callee evidence | Applied/preserved | Target validator `8486` |
| C05 | Cursor/origin use y/x Point order; both coordinates localize; both origin components must be `-1000` for the no-write early return. | High | Decompile; UID00015S; UID0000Y4 | Target behavior/C++ | Applied | Target validator `8486`; exact block match |
| C06 | Part values are leading 0, page-before 1, thumb 2, page-after 3, trailing 4, and none `0xff`. | High | Branch constants; accepted sibling docs | Target enum/source shape | Applied/preserved | Target validator `8486` |
| C07 | Use accepted fields at `+0x44/+0xfb/+0xfc/+0xfe/+0x100/+0x102/+0x108/+0x10c`; position/range are signed shorts. | High | MCP field reads; UID0001VO/Y3/Y4/Y6 | Target/layout | Applied/preserved | Target `8486`; layout `8491` |
| C08 | Horizontal leading/trailing parts collapse to left/right zero-width edges; horizontal span is control height. | High | Decompile/disassembly; UID0000Y4 | Target behavior/C++ | Applied | Target validator `8486` |
| C09 | Horizontal enabled thumb/page geometry uses proportional left/right split and does not use drag state. | High | Decompile; negative branch check | Target behavior/C++ | Applied | Target validator `8486` |
| C10 | Horizontal disabled/no-range thumb is inset by control height; page regions 1/3 are empty. | High | Decompile; empty-rect callee | Target behavior/C++ | Applied | Target validator `8486` |
| C11 | Vertical leading/trailing parts collapse to top/bottom zero-height edges; vertical span is literal 38. | High | Decompile; UID0000Y4 | Target behavior/C++ | Applied | Target validator `8486` |
| C12 | Vertical non-drag thumb/page geometry uses proportional top/bottom split over `bottom - 38 - top`. | High | Decompile | Target behavior/C++ | Applied | Target validator `8486` |
| C13 | Vertical drag top uses localized cursor y minus drag offset y and ordered clamp to `[top, bottom - 38]`. | High | Decompile; UID0000Y4 | Target behavior/C++ | Applied | Target validator `8486` |
| C14 | Vertical disabled/no-range thumb is inset by 38; page regions 1/3 are empty. | High | Decompile; empty-rect callee | Target behavior/C++ | Applied | Target validator `8486` |
| C15 | Enabled invalid part returns copied full bounds; disabled invalid part leaves output untouched; sentinel also leaves output untouched. | High | Complete control-flow review | Target caveat/C++ | Applied | Target validator `8486`; exact block match |
| C16 | Keep UID0000BO owner/emitter, reconstructable true, blank position, zero nested children, and UID0000MZ source route. | High | Local call/field family; class/file docs | Target metadata | Confirmed unchanged | Target `8486`; support validators |
| C17 | Populate the exact complete managed C++ block in this report; no import directive or no-code comment applies. | High | C01-C15 | Target formal C++ | Applied byte-for-byte | Target `8486`; B004 wait `8500`; read-only header `8504` |
| C18 | Raise only target `86/90 -> 89/91`; do not claim final rebuild equivalence or original symbol recovery. | Medium-high | Blocker closure plus remaining caps | Target metadata/rationale | Applied | Target `8486`; B004 wait `8500`; read-only header `8504` |
| C19 | Update UID0000BO method row/evidence to identify UID0001ZB as source-ready while keeping class `87/89` and class C++ blank under its separate whole-class proof. | High | Class page and target result | by-class/RankingEventScrollPane.md | Applied; metadata/C++ preserved | Class `8489`, phrase refresh `8498` |
| C20 | Add target body confirmation to UID0001VO without changing `85/89`, owner/emitter, layout C++, or accepted offsets/names. | High | Layout agreement | RankingEventScrollPaneLayout.md | Applied; metadata/C++ preserved | Layout validator `8491` |
| C21 | Update UID0000MZ proposed contents/boundary notes to include source-ready UID0001ZB through the existing file route; keep `88/91` and file route unchanged. | High | File page and owner analysis | by-file/RankingDialog.md | Applied; metadata/path preserved | File `8494`, B004 final wait `8500`, read-only header `8504` |
| C22 | UID0000Y3, UID0001ZA, and UID0000Y4 already carry same-or-greater `GetPartRect` dependency, enum, field, and geometry detail. | High | Direct document read | Those three pages | Already present; no edit | Reverified read-only after callback |
| C23 | UID0000Y5, UID0000Y6, and UID0000Y7 already carry exact calls/dependency edges; their raw/helper-specific blank-C++ decisions remain independent. | High | Direct document read | Those three pages | Already present; no edit | Reverified read-only after callback |
| C24 | Preserve rejection of generic owner, FittingRoom behavior copy, horizontal drag, 38-pixel horizontal caps, split children, return-by-value, and early output initialization. | High | Positive/negative binary and comparator evidence | Target reconstruction caveat | Applied/preserved | Target `8486`; support text validated |

## Positive Evidence Summary

- MCP resolves one complete modeled function, exact clean boundaries, all 15 callers, only three direct callees, and every output-writing branch.
- Formal neighboring source already establishes `GetPartRect`, Ranking part constants, fields, `Point`, and `RectBounds`; UID0000Y4 duplicates the same geometry independently.
- Two source-family analogs establish the same output-pointer helper role and method naming while exposing which geometry details are family-specific.
- The chosen owner/source route matches every target caller and field access and requires no new parent, split, or generated-only abstraction.
- The strongest inference chain is: exact binary body -> accepted same-class callers/inline duplicate -> canonical geometry contract -> analogous human-source method family. That is sufficient for a first-draft body despite stripped symbols.

## IDA MCP Facts

- Function/range facts: `sub_45A710`, size `0x27b`, start `0x0045a710`, exclusive end `0x0045a98b`; `0x0045a98a` is inside; `0x0045a98b` and `0x0045a990` are not modeled functions.
- Data/table/padding facts: no target table/data island; four `CC` bytes precede the prologue at `0x0045a70c-0x0045a70f`; five `CC` bytes follow the return at `0x0045a98b-0x0045a98f`.
- Xref facts: 15 code refs, zero documented data/vtable refs to this private helper entry.
- Global/type facts: `g_pEventMan` supplies cursor position; no Ranking-specific UDT/enum survived `type_query`; RectBounds/Point contracts come from accepted geometry docs and raw writes.
- Negative IDA facts: no second function, no hidden child, no extra callee, no horizontal drag use, no vertical span table, and no resource/packet/global ownership signal.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0045a710-0x0045a98a` observed / `0x0045a710-0x0045a98b` modeled | UID0001ZB target | Full five-part rectangle method | Yes | UID0000BO | `86/90 -> 89/91` | Formal body recommended |
| `0x0045a70c-0x0045a70f` | no child | Pre-padding | No | n/a | n/a | Leave padding |
| `0x0045a98b-0x0045a98f` | no child | Post-padding | No | n/a | n/a | Leave padding |
| `0x0045a990` onward | UID0000Y5 | Separate raw hover/drag island | Yes, own caveat | UID0000BO | `86/90` | Outside target; unchanged |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00459ad7`, `0x00459b75`, `0x00459b8d`, `0x00459bac`, `0x00459c4e` | UID0000Y3 OnMouseEvent | Hover/press/thumb/reset rectangle consumers |
| `0x0045a336` | UID0001ZA OnPaint | Binary thumb rectangle call; source draft also uses helper for track parts |
| `0x0045a9bc`, `0x0045a9d8`, `0x0045aa31`, `0x0045aa49`, `0x0045aa68`, `0x0045ab0a`, `0x0045abea` | UID0000Y5 raw hover/drag island | Seven raw rectangle consumers with no enclosing IDA function object |
| `0x0045ac35` | UID0000Y6 DragToPosition | Thumb rectangle used for drag conversion |
| `0x0045ae06` | UID0000Y7 raw reset | Stale hover rectangle invalidation |
| `0x0045a723 -> 0x004a9090` | EventMan cursor lookup | Fills cursor Point |
| `0x0045a72e -> 0x005447c0` | Pane screen offset | Fills origin Point |
| `0x0045a97a -> 0x004b7c50` | InitRectBounds | Clears disabled/no-range page regions |

## Documentation Evidence And IDA Status

- Existing docs supporting the conclusion: target already records the correct declaration, owner, all callers, field offsets, and orientation behavior; UID0000Y3/ZA formal code calls `GetPartRect`; UID0000Y4 formal code duplicates the target geometry; UID0001VO fixes layout and enum names; UID00015S fixes Point/RectBounds order.
- Historical stale/incomplete claim: the prior UID0000Y4 support pass left target formal C++ blank. The target now preserves that statement only as dated historical provenance and explicitly supersedes it with the UID0001ZB full body.
- Current support state: UID0000BO marks UID0001ZB source-ready while preserving `87/89`/blank class C++; UID0001VO records exact target-consumed layout evidence at unchanged `85/89`; UID0000MZ records source-ready routing at unchanged `88/91`.
- Generated/coverage state: historical pre-callback empty-marker/not-coded/tracker rows were validator-owned snapshots. B004's waited refresh `000000008500` completed; post-callback read-only header `000000008504` retained one target body and zero target empty markers.

## Ranked Ownership Analysis

### 1. [UID:0000BO] RankingEventScrollPane through [UID:0000MZ] RankingDialog

- Evidence for: every field is local/inherited pane state; all callers are RankingEventScrollPane mouse/paint/drag/reset paths; same-class UID0000Y4 duplicates geometry; class/file docs already establish this route.
- Evidence against: exact original filename and private method spelling are stripped.
- Decision: retain as semantic owner/emitter and source-file route. The stripped spellings do not outweigh the closed local evidence.

### 2. Generic scrollbar/ScrollCollection implementation

- Evidence for: `0x00562bf0` is a close structural analog with the same complexity and callees.
- Evidence against: it uses a different owner, skin-indexed vertical span, and separate source route; no target call/xref points to a shared geometry implementation.
- Decision: comparator/dependency only, not owner and not a source body to copy.

### 3. FittingRoomScrollPane or RectBounds/EventMan support

- Evidence for: FittingRoom has the same method family; RectBounds/EventMan supply data/helper APIs.
- Evidence against: FittingRoom cap/span behavior differs; shared geometry/input helpers do not own feature state or callers.
- Decision: reject semantic/source ownership. Preserve only their corroborating contracts.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: no new owner or path. Keep `NexusTK/ui/dialogs/RankingDialog.cpp` through UID0000MZ.
- Likely full contents: this private method alongside the already documented RankingEventScrollPane methods and raw helper behavior.
- Candidate related items that belong: no new child; existing UID0000Y3/Y4/Y5/Y6/Y7 and UID0001ZA remain separate exact pages under the same class.
- Candidate related items rejected: generic scroll geometry, FittingRoom, ScrollCollection, RectBounds, and EventMan source bodies.
- Standalone, narrow, or broad source-file inference: narrow class-method target within an established broad feature source file.

## Source Placement

- Recommended source file/class/global/module placement: private method of `RankingEventScrollPane` in the existing UID0000MZ `NexusTK/ui/dialogs/RankingDialog.cpp` route.
- Why this placement fits: caller closure, field closure, class vtable/layout family, source-ready siblings, and the file's private ranking-control grouping all agree.
- Rejected placements: generic ScrollBar, FittingRoom, ScrollCollection, RectBounds, EventMan, and direct broad UID0000XZ emission. Each is either comparator/dependency or non-emitting broad support rather than this method's semantic owner.
- Remaining placement uncertainty: only whether the historical project used a separate `class_RankingEventScrollPane.cpp`; current reconstruction intentionally retains the accepted compact RankingDialog source route.

## Range / Split / Padding / Reclassification Analysis

- Exact range/boundary facts: modeled `[0x0045a710,0x0045a98b)`, physical inclusive filename endpoint `0x0045a98a`, prior four-byte `CC` pad, following five-byte `CC` pad.
- Children/subranges: create none; split none; merge none; leave the successor raw island UID0000Y5 separate.
- Padding/table/data/code distinctions: all target bytes are one code function; both adjacent gaps are alignment padding; there is no internal table or data object.
- Parent/container impact: keep direct UID0000BO ownership and UID0000MZ source routing; no broad parent score or range change.

## Negative Evidence Summary

- No preserved source symbol proves historical spellings; this limits confidence but does not erase the accepted same-class naming contract.
- No horizontal branch reads `m_thumbDragActive`, cursor.x, or drag offset x after localization. Adding horizontal drag behavior would be invented.
- No target read uses `m_scrollSkinIndex` or a span table. Vertical span is literal 38; horizontal span is current control height.
- No evidence supports fixed-size leading/trailing arrow rectangles. Both orientations collapse those parts to a zero-area edge.
- No output initialization occurs before the sentinel return. A defensive default rectangle would change observable behavior.
- No common helper call implements the geometry; UID0000Y4 duplicates it inline. Factoring or delegating would be speculative source refactoring.
- No alternate owner has direct caller, field, vtable, source-route, or resource evidence. Analogs remain comparators only.
- No split is justified: the function is modeled, contiguous, source-coherent, and free of mixed code/data.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing names/types/comments: document source method `GetPartRect`, enum `RankingScrollPart`, output `RectBounds *`, local `Point cursor/origin`, accepted fields, and `kRankingScrollThumbSpan = 38`.
- Evidence: accepted same-class formal callers, UID0000Y4 duplicate geometry, UID0001VO layout, UID00015S geometry contract, and source-family analogs.
- Items intentionally unchanged: physical page filename/title `GetScrollRegionRect`, IDA label `sub_45A710`, and the database's missing Ranking UDT/enum. Stable paths and report-only scope outweigh a database rename.
- IDA DB edits: not requested and not performed.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. The method is source-authored, modeled, owner/emitter attached, above the active combined-score gate at applied `89/91`, behavior-complete, and emitted by final generated refresh.
- Recommended code: insert this complete literal managed block into the target after supervisor approval:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void RankingEventScrollPane::GetPartRect(RankingScrollPart part, RectBounds *outRect)
{
    Point cursor;
    Point origin;

    g_pEventMan->GetCursorPosition(&cursor);
    GetScreenOffset(&origin);

    if (origin.y == -1000 && origin.x == -1000) {
        return;
    }

    cursor.y -= origin.y;
    cursor.x -= origin.x;

    const RectBounds bounds = m_bounds;

    if (m_orientation != 0) {
        const int thumbSpan = bounds.bottom - bounds.top;

        if (part == kRankingScrollPartLeading) {
            *outRect = bounds;
            outRect->right = outRect->left;
            return;
        }
        if (part == kRankingScrollPartTrailing) {
            *outRect = bounds;
            outRect->left = outRect->right;
            return;
        }

        if (m_enabled && m_scrollRange > 0) {
            const int thumbLeft = bounds.left +
                (m_scrollPosition *
                 (bounds.right - bounds.left - thumbSpan)) /
                    m_scrollRange;
            const int thumbRight = thumbLeft + thumbSpan;

            *outRect = bounds;
            if (part == kRankingScrollPartThumb) {
                outRect->left = thumbLeft;
                outRect->right = thumbRight;
            } else if (part == kRankingScrollPartPageBeforeThumb) {
                outRect->right = thumbLeft;
            } else if (part == kRankingScrollPartPageAfterThumb) {
                outRect->left = thumbRight;
            }
            return;
        }

        if (part == kRankingScrollPartThumb) {
            *outRect = bounds;
            outRect->left += thumbSpan;
            outRect->right -= thumbSpan;
        } else if (part == kRankingScrollPartPageBeforeThumb ||
                   part == kRankingScrollPartPageAfterThumb) {
            InitRectBounds(outRect, 0, 0, 0, 0);
        }
        return;
    }

    if (part == kRankingScrollPartLeading) {
        *outRect = bounds;
        outRect->bottom = outRect->top;
        return;
    }
    if (part == kRankingScrollPartTrailing) {
        *outRect = bounds;
        outRect->top = outRect->bottom;
        return;
    }

    if (m_enabled && m_scrollRange > 0) {
        const int thumbLimit = bounds.bottom - kRankingScrollThumbSpan;
        int thumbTop;

        if (m_thumbDragActive) {
            thumbTop = bounds.top + cursor.y - m_thumbDragOffset.y;
            if (thumbTop < bounds.top) {
                thumbTop = bounds.top;
            }
            if (thumbTop > thumbLimit) {
                thumbTop = thumbLimit;
            }
        } else {
            thumbTop = bounds.top +
                (m_scrollPosition * (thumbLimit - bounds.top)) /
                    m_scrollRange;
        }

        const int thumbBottom = thumbTop + kRankingScrollThumbSpan;
        *outRect = bounds;
        if (part == kRankingScrollPartThumb) {
            outRect->top = thumbTop;
            outRect->bottom = thumbBottom;
        } else if (part == kRankingScrollPartPageBeforeThumb) {
            outRect->bottom = thumbTop;
        } else if (part == kRankingScrollPartPageAfterThumb) {
            outRect->top = thumbBottom;
        }
        return;
    }

    if (part == kRankingScrollPartThumb) {
        *outRect = bounds;
        outRect->top += kRankingScrollThumbSpan;
        outRect->bottom -= kRankingScrollThumbSpan;
    } else if (part == kRankingScrollPartPageBeforeThumb ||
               part == kRankingScrollPartPageAfterThumb) {
        InitRectBounds(outRect, 0, 0, 0, 0);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Third-party import directive: not applicable; this is NexusTK source-authored class code.
- Reason it preserves exact original behavior: it preserves sentinel no-write return, unconditional point localization, orientation split, exact spans, integer arithmetic order, vertical-only drag path, ordered clamps, full-bounds invalid-part behavior, disabled empty-page behavior, and untouched-output cases.
- Reason it matches plausible original source shape: ordinary private class method, accepted project-era pointer/output conventions, local copies and if/else part selection, and no decompiler labels or address-suffixed names.
- Inferred names/types/fields: `RankingScrollPart`, part constants, `RectBounds`, `Point`, `m_bounds`, `m_orientation`, `m_enabled`, `m_scrollPosition`, `m_scrollRange`, `m_thumbDragActive`, `m_thumbDragOffset`, and `kRankingScrollThumbSpan`.
- Naming/style evidence: direct same-class formal methods and canonical RectGeometry support already use this vocabulary and brace/pointer style.
- Reason code should remain blank: not applicable.
- Exact no-code proof: not applicable; all prior body blockers are resolved to first-draft level.

## Final Recommendation

- Exact changes applied: target score `86/90 -> 89/91`; complete managed C++ body above; target Status, Behavior, MCP Evidence, Source-Shape Notes, and Changes now carry C01-C18/C24 at report-level detail.
- Exact parent assignments: retain UID0000BO owner/emitter and UID0000MZ source-file route; retain reconstructable true, blank position, and zero nested count.
- Exact items left no-owner/non-emitting: none inside the target. Adjacent padding remains non-source; UID0000Y5 is a separate already-owned raw island.
- Exact future work outside scope: whole-class declaration/enum/field compile integration remains on UID0000BO; UID0000Y5/Y6/Y7 keep their independent source-quality decisions; final rebuild equivalence and historical identifier recovery remain later audit work. No UID0001ZB implementation item remains.

## Recommended Target Doc Changes

- Target path: `by-memory/0x0045a710-0x0045a98a.RankingEventScrollPaneGetScrollRegionRect.md`.
- Exact facts incorporated: evidence-time MCP database and request IDs; exact start/size/end/padding; all 15 callers and three callees; `void` output-pointer signature; y/x point/sentinel contract; full horizontal and vertical branch behavior; disabled/no-range and invalid-part asymmetries; analogous-family corroboration; rejected alternatives.
- Metadata/C++ applied: `COMPLETION:89`, `CONFIDENCE:91`, exact managed C++ block above. Owner/emitter/reconstructable/position/nested/range/path remain unchanged.
- Historical/stale evidence to preserve: retain the stable historical `GetScrollRegionRect` path/title, prior declaration-support history, all caller/raw-island caveats, and rejected exact-name certainty. Explicitly mark declaration-only deferral as historical/superseded rather than deleting its provenance.

## Recommended Support Doc Changes

- Support path: `by-class/RankingEventScrollPane.md`.
- Exact facts applied: method row is source-ready `void GetPartRect(RankingScrollPart, RectBounds *)`; exact body/boundary/caller/callee/geometry summary is present; separate whole-class declaration proof remains explicit.
- Metadata/C++: keep `87/89`, UID0000MZ owner/emitter, reconstructable true, and blank class C++.

- Support path: `by-type/by-struct/RankingEventScrollPaneLayout.md`.
- Exact facts applied: target body confirmation covers accepted offsets/types, vertical literal 38, horizontal height span, y-only vertical drag use, and signed short range/position arithmetic.
- Metadata/C++: keep `85/89`, UID0000BO owner/emitter, reconstructable true, and blank layout C++.

- Support path: `by-file/RankingDialog.md`.
- Exact facts applied: source-ready UID0001ZB is in the RankingEventScrollPane contents/boundary narrative; the older sentence now separates accepted Y3/ZA/Y4/ZB bodies from UID0000Y6/raw independent decisions; class declaration compile-integration caveat is preserved.
- Metadata/path: keep `88/91`, `CANONICAL_OWNER:FILE`, and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"`.

- UID0000Y3, UID0001ZA, UID0000Y4, UID0000Y5, UID0000Y6, UID0000Y7, and broad UID0000XZ: no edits recommended. Their exact dependency/caller/geometry facts are already present at same-or-greater detail, and their independent score/C++ dispositions must not be changed by this target callback.
- Generated RankingDialog.cpp, auto coverage, and tracker: no manual edits. B004's scoped waited refresh was `000000008500`; a post-callback read-only check used newer concurrent header `000000008504` with unchanged target counts.

## Score And Metadata Recommendation

- Historical pre-callback score/metadata: `86/90`, owner/emitter UID0000BO, reconstructable true, blank position, blank formal C++, zero nested children.
- Current applied score/metadata: `89/91`, same owner/emitter/reconstructable/position/nested/range/source route, populated full formal C++.
- Score rationale: completion gains three points because the full body, return/signature, branch asymmetries, names/types, and managed insertion are resolved. Confidence gains one point because current MCP and two analog families reconfirm the prior evidence without recovering original symbols.
- Reason not higher: no preserved Ranking-specific symbols/UDT/enum, no original source file, no accepted whole-class declaration block, and no rebuilt binary comparison. These cap confidence below final audit and completion below compile-complete source, but do not justify blank method code.
- Score-improvement attempts: range/padding resolved; all callers/callees resolved; return/arguments resolved; enum/fields/types resolved to implementation-ready inference; horizontal/vertical/disabled/drag/invalid behavior resolved; owner/source placement resolved; split rejected; C++ body completed; only original spelling and whole-class/final-build caps remain.
- Metadata fields unchanged: UID, canonical owner, reconstructable, emitter, emitter position, range/title/path, nested count, and source route.

## Open Questions With Attempted Resolution

- Was the historical method name `GetScrollRegionRect`? Checked target title history, formal callers, class docs, FittingRoom and ScrollCollection analogs. Best supported source name is `GetPartRect`; keep historical wording only in the stable page title/path.
- Is the return type integer? Checked complete decompile and all callers. EAX is incidental; the source method is `void` with an output pointer.
- Should drag alter horizontal geometry? Checked the entire horizontal branch and analog behavior. The target binary does not consume drag state there; do not add it.
- Are leading/trailing parts arrow-sized buttons? Checked all branch writes and UID0000Y4. They collapse to edges in this Ranking control; FittingRoom's fixed caps are a different implementation.
- Should invalid or sentinel cases initialize output? Checked complete control flow. No; preserve untouched-output paths and the enabled invalid-part full-bounds result.
- Should the method be split or moved to a generic owner? Checked function boundary, caller closure, fields, analogs, class/file docs, and negative xrefs. No.
- Remaining unresolved: exact historical spellings and final whole-class declaration/build equivalence. Required future evidence would be original symbols/source or a completed declaration and rebuilt comparison. Impact: confidence/final-audit cap only; no first-draft C++ blocker.

## Follow-Up Actions

- Supervisor/validator-owned state: report validation, execution, count, path, move, and archive status are external to this artifact; this report neither asserts nor directs any of those lifecycle states or actions.
- A-agent actions: none requested.
- B004 future actions: none for implementation. B004 performed no report execution/lifecycle command.

## Confidence

- Recommendation confidence: high.
- Score confidence: medium-high for `89/91`, aligned with source-ready same-class siblings while retaining explicit integration/name caps.
- Remaining uncertainty: original identifiers, exact historical file split, class declaration integration, and rebuild equivalence.

## Validator Results

- Target command: `python .\tools\validator.py --mode file --file by-memory/0x0045a710-0x0045a98a.RankingEventScrollPaneGetScrollRegionRect.md --apply --queue-timeout 240`; command ID `000000008486`; timestamp `2026-07-12T18:54:32-04:00`; exit `0`; `ok: 1`; score updates `89/91`; blank-to-block registry update; generated refresh deferred.
- Class command: `python .\tools\validator.py --mode file --file by-class/RankingEventScrollPane.md --apply --queue-timeout 240`; command ID `000000008489`; timestamp `2026-07-12T18:55:31-04:00`; exit `0`; `ok: 1`; generated refresh deferred.
- Layout command: `python .\tools\validator.py --mode file --file by-type/by-struct/RankingEventScrollPaneLayout.md --apply --queue-timeout 240`; command ID `000000008491`; timestamp `2026-07-12T18:56:03-04:00`; exit `0`; `ok: 1`; generated refresh deferred.
- File-route command: `python .\tools\validator.py --mode file --file by-file/RankingDialog.md --apply --wait-generated --queue-timeout 240`; command ID `000000008494`; timestamp `2026-07-12T18:56:52-04:00`; exit `0`; `ok: 1`; generated refresh completed.
- Archive-neutral wording correction: the post-refresh read-back found two callback-touched support sentences that still described method emission as future. B004 re-leased only those files, corrected the phrases, and reran scoped validation: class command ID `000000008498`, timestamp `2026-07-12T18:58:47-04:00`, exit `0`, `ok: 1`, deferred; final waited file-route command ID `000000008500`, timestamp `2026-07-12T18:59:26-04:00`, exit `0`, `ok: 1`, generated refresh completed.
- Generated freshness proof: B004 waited command `000000008500` completed at `2026-07-12T18:59:26-04:00`. A later read-only header had advanced through concurrent validator work to `validator-command-id: 000000008504`, `validator-refreshed-at: 2026-07-12T19:01:28-04:00`; counts remained UID0001ZB `1`, `void RankingEventScrollPane::GetPartRect(` definitions `1`, target Empty Emitter Markers `0`. Command `8504` was not run by B004.
- Unresolved target warnings/errors: none. Final validator output included unrelated project-wide informational counts (`autogen_children_fallback_insert: 17`, `autogen_children_marker_missing: 81`, `autogen_emitter_has_no_code: 220`) and validator-owned metadata/tracker refreshes; none names UID0001ZB as an error.

## Changed Files

- Created then updated: `tools/leaser/Agents/Agent-B004/research/0001ZB-RankingEventScrollPaneGetScrollRegionRect-source-quality.md`.
- Modified by B004: `by-memory/0x0045a710-0x0045a98a.RankingEventScrollPaneGetScrollRegionRect.md`, `by-class/RankingEventScrollPane.md`, `by-type/by-struct/RankingEventScrollPaneLayout.md`, and `by-file/RankingDialog.md`.
- Validator-owned side effects, not manually edited: generated RankingDialog.cpp, auto-generated coverage/metadata/tracker outputs, projected stats, reference index, and validator registry state refreshed through scoped commands.
- Renamed: none.
- Leases: B004 leased one by-* file at a time immediately before editing and received `Success` on every matching `unlease`. Target and layout used one lease cycle each; class and file route used a second short lease cycle solely for the archive-neutral phrase correction. Final lease report contains no B004 lease.
- Current by-* SHA256 proof: target `A6F166A4F67493A0657702D55EEDB6F4048EB2419B454E01E9BBE9A6C1B586A5`; class `47BBB4F6A86474BEE16DC9E97D69BA8E15A66CBFE028397B005CDB451421B757`; layout `A61C676F1EC20B356880D42AD745014A5902FE94DA80E3E080CC7B07C770FD3C`; file route `23ED87E604B1F13A6594CDAE46005F450F027C478939E1AEB4411EDE250DF0A2`.
- Report execution: B004 ran no `execute_report`, dry-run/probing execute variant, report lifecycle command, move, or archive command. Supervisor-owned lifecycle state is external and must be read from validator headers/history and the artifact's current path; no implementation item remains.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Gate 1 accepted exact report SHA256 `1EE84348BCBB99F49649536529ED4DBCBF15E30FAACD46AED663DA084ABAA915` before implementation.
- [x] Target/support scope fixed to target UID0001ZB, UID0000BO class, UID0001VO layout, and UID0000MZ file route only; named interacting method/raw pages verified already present and left unedited.
- [x] Current target state and actual evidence checked recorded: C01-C24, MCP database `bf5519ae` evidence-time requests `62003-62019`, exact docs/reports/generated/tracker checks, and negative checks.
- [x] Claim And Incorporation Ledger records destination and verification state for every accepted claim: C01-C21/C24 applied; C22-C23 already present.
- [x] Metadata/score disposition applied: target `86/90 -> 89/91` only; support scores unchanged.
- [x] Score-limiting blockers researched: exact body, boundaries, caller/callee set, signature, enum, field/type names, geometry, disabled behavior, drag clamp, owner, placement, and split resolved; original spelling/class-declaration/rebuild caps explicitly bounded.
- [x] Owner/emitter/reconstructable disposition confirmed unchanged: UID0000BO/UID0000BO/true and UID0000MZ route.
- [x] Split/rename/new-child disposition applied: no split/new child; `GetPartRect` source name emitted while stable physical path/title remains unchanged.
- [x] Source-placement/range/padding/reclassification/IDA disposition applied: exact range/pads and source placement preserved; no reclassification or IDA DB edit.
- [x] First-draft C++ applied byte-for-byte from the complete managed block under `First-Draft C++ Recommendation`.
- [x] Third-party import directive confirmed not applicable; this is project source-authored class code.
- [x] Exact target/support facts incorporated at report-level detail, including negative evidence and invalid-part behavior.
- [x] Historical/stale assumptions and rejected alternatives preserved: declaration-only deferral historicalized; path title retained; generic/FittingRoom/split/horizontal-drag/defensive-output alternatives rejected.
- [x] Wave2/Wave3 artifacts not used; any encountered stale artifact remained excluded.
- [x] Open questions closed at implementation level; only evidence-backed confidence/final-build caps remain.
- [x] Scoped validators completed with command IDs/timestamps/exit/ok recorded; short second class/file runs validated the archive-neutral wording correction.
- [x] Validator-owned generated refresh completed; target has one emitted body and no target Empty Emitter Marker; generated files were never manually edited.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation at the exact Gate 1 SHA.
- [x] All accepted target/support details incorporated at report-level detail.
- [x] C01-C24 ledger updated with exact destination and applied/already-present verification state.
- [x] Target score/C++ applied; owner/emitter/split/rename/support-score dispositions confirmed unchanged.
- [x] Historical assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions remain only as explicit confidence/final-build caps.
- [x] Scoped validators completed and proof recorded; every lease was released immediately after its edit/validator cycle.
- [x] B004 awaited generated refresh `000000008500`; post-callback read-only header `000000008504` had one emitted UID0001ZB method and no target Empty Emitter Marker.
- [x] Remaining unapplied accepted items: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000008554","destination_path":"executed-b-agent-research/B004/0001ZB-RankingEventScrollPaneGetScrollRegionRect-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0001ZB-RankingEventScrollPaneGetScrollRegionRect-source-quality.md","timestamp":"2026-07-12T19:18:31-04:00","uid":"0001ZB"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
