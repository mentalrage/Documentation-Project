** TARGET-REPORT-UID:0000Y4 **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0000Y4 RankingEventScrollPane HitTestPart Source-Quality Research


## Finalized Report / Current Recommendation

- Implemented disposition: UID0000Y4 emits first-draft `RankingScrollPart RankingEventScrollPane::HitTestPart(int y, int x)` through the existing [UID:0000BO] `RankingEventScrollPane` route into [UID:0000MZ] `RankingDialog.cpp`.
- Final disposition: the former blank formal C++ block was replaced. The target is a modeled `0x30c`-byte private class helper with four local code xrefs, a complete five-part algorithm, stable field roles, stable shared geometry contracts, and accepted sibling `HitTestPart` naming precedents.
- Applied action: the target page is `by-memory/0x0045a400-0x0045a70b.RankingEventScrollPaneHitTestPart.md`; it contains the exact formal C++ below plus the accepted target and support evidence corrections.
- Metadata: UID0000Y4 is `89/91`; `CANONICAL_OWNER:0000BO`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000BO`, and blank emitter position remain unchanged.
- Confidence: high for behavior, range, class ownership, source route, method role, formal first draft, fields, part values, and coordinate order; medium-high for exact original spellings.

## Supporting Research

- Artifact record: the supervisor accepted the Gate 1 report at SHA256 `4CD25679472FB6B5CD7E2420DE545E5610CB046288E4AD05E39CB4C3529340DF`; the accepted implementation callback was then applied and verified. Report execution/archive lifecycle state is intentionally not asserted here.
- Evidence-pass IDA MCP transport session: `266b97dd-c230-44e7-afd6-bc852f1102f7`.
- Evidence-pass active IDB session: `359c7886`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active worker PID `13016` at the evidence-pass start.
- `server_health` returned `status:ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`.
- Generated verification: validator refresh command `000000008206` emits UID0000Y4 in `auto-generated/NexusTK/ui/dialogs/RankingDialog.cpp` as `RankingEventScrollPane::HitTestPart(int y, int x)` at `89/91`; the former empty marker is absent.
- Validator-owned coverage/tracker state was refreshed only through scoped validators. No generated output, tracker, coverage, validator state, lifecycle file, or archive was manually edited.
- Matching report search found no prior UID0000Y4 report. Matching support reports were UID0000Y2, UID0000Y3, the RankingDialog reports, and accepted sibling hit-test reports. Those were treated as leads and checked against current MCP evidence.

## Target

- Target UID: `0000Y4`.
- Current target path: `by-memory/0x0045a400-0x0045a70b.RankingEventScrollPaneHitTestPart.md`.
- Previous target path: `by-memory/0x0045a400-0x0045a70b.RankingEventScrollPaneHitTest.md`; validator command `000000008202` registered the rename and updated live reverse links.
- Address range: modeled function `0x0045a400-0x0045a70c` end-exclusive; filename range remains inclusive `0x0045a400-0x0045a70b`.
- Historical source queue before callback: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`.
- Current classification: reconstructable, class-owned, routed, and formal-body emitting.
- Current score and parent state: target `89/91`; direct class parent [UID:0000BO] remains `87/89`; file route [UID:0000MZ] remains `88/91`.

## Current Target State

- Current metadata is `CANONICAL_OWNER:0000BO`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000BO`, blank emitter position, with populated formal C++.
- Current documentation records the modeled function boundary, four call sites, part loop `0..4`, return `0xff`, local field offsets, local geometry/input callees, boundary padding, rejected alternatives, and current MCP session evidence.
- The former unresolved-name/`95/95` no-code rationale is retained as historical context and superseded by the current combined-score/emitter rule and accepted source-facing names.
- Class documentation now consistently uses `HitTestPart(int y, int x)` and records the full `RankingScrollPart` family and `kRankingScrollThumbSpan = 38` contract.
- UID0000Y3 formal C++ and evidence now follow [UID:00015S] y-first geometry: `PaneMouseEvent +8` is y, `+0x0c` is x, and related `PointInRect`, `HitTestPart`, `DragToPosition`, and drag-offset expressions use that order.
- No current split, owner, emitter, or raw-helper blocker remains for this modeled function.

## Executive Recommendation

- Use `RankingEventScrollPane::HitTestPart`, not `HitTestScrollPart`, `HitTest`, `BuildHitTestRectForPart`, or a generic `ScrollBar` helper.
- Use `RankingScrollPart` with values leading `0`, page-before `1`, thumb `2`, page-after `3`, trailing `4`, and none `-1`/stored `0xff`.
- Use y-first geometry APIs and parameters: `HitTestPart(int y, int x)` and `PointInRect(y, x, &partRect)`.
- Keep rectangle construction inline. The binary does not call sibling `GetPartRect`/`0x0045a710` from this function.
- Preserve the per-part cursor/origin refresh and sentinel branch rather than hoisting the cursor query or replacing the inline geometry with a call-through wrapper.
- Keep exact class ownership [UID:0000BO] and source placement under [UID:0000MZ] `NexusTK/ui/dialogs/RankingDialog.cpp`.

## Supervisor Active Recheck

- Trigger: resume Agent-B004 UID0000Y4 after supervisor restored and verified IDB session `359c7886`.
- Evidence-pass mode was report-only source-quality research; the later supervisor-accepted callback supplied the narrowly scoped by-* implementation permission recorded in this report.
- Split-first result: no split is needed. Current MCP proves one modeled function of size `0x30c`, clean preceding/following padding, and a separate successor function at `0x0045a710`.
- Source-bearing coverage: this target is the exact source-bearing function. The raw hover/drag helpers remain separate UID0000Y5 support, and `GetPartRect` remains separate UID0001ZB support.

## Inference Research Guidance Check

- IDA fact, documentation evidence, and source inference are separated throughout this report.
- Existing target assumptions were not copied forward: the no-code disposition, `HitTestScrollPart` name, x/y event spelling, and generic/shared-helper possibility were actively rechecked.
- `by-structure.md` current code-entry rule was applied: reconstructable true, nonblank confirmed emitter route, and combined score above 85 make first-draft code eligible when source-quality blockers are resolved.
- Current generated output and archived reports were used only as leads/state evidence, not as binary authority.
- Old Wave2/Wave3 material was excluded. Search results in `by-memory/-report.old.md` were intentionally not used as evidence.

## Heuristic / Inference Reanalysis And Validation

### Method name and return type

- Best name: `RankingEventScrollPane::HitTestPart`. UID0000Y3 already emits calls with this name, accepted FittingRoom, ScrollNewGroupPane, and ScrollVolumePane comparators use `HitTestPart`, and the function returns a part id rather than a boolean.
- Rejected `HitTestScrollPart`: redundant class context and contradicted by the accepted UID0000Y3 helper spelling.
- Rejected bare `HitTest`: less specific than every accepted sibling convention.
- Rejected `BuildHitTestRectForPart`: rectangle construction is internal behavior; the function's observable result is the hit part.
- Return type recommendation: `RankingScrollPart`. The machine return is byte-sized (`al`), the callers compare/store a byte, and sibling accepted source uses enum return types with a `-1` no-part sentinel.

### Part constants

- `0`: `kRankingScrollPartLeading`.
- `1`: `kRankingScrollPartPageBeforeThumb`.
- `2`: `kRankingScrollPartThumb`.
- `3`: `kRankingScrollPartPageAfterThumb`.
- `4`: `kRankingScrollPartTrailing`.
- `-1` / byte `0xff`: `kRankingScrollPartNone`.
- "Leading/trailing" is preferred over "arrow" because UID0000Y4 collapses those rectangles to zero-width/zero-height edges rather than constructing visible arrow-button extents.

### Point and rectangle types

- `RectBounds` is implementation-ready from [UID:00015S] and its layout support: `left, top, right, bottom` with half-open containment.
- `Point` is implementation-ready as y-first storage: `int y; int x;`.
- `PointInRect` is implementation-ready as `bool PointInRect(int y, int x, const RectBounds *bounds)`.
- `InitRectBounds` is implementation-ready for the disabled/no-range empty page regions.
- Target signature must be y-first. Current MCP call-site disassembly and `PointInRect` decompilation prove that the first explicit integer is the vertical/y coordinate and the second is horizontal/x.

### Orientation and geometry

- `m_orientation != 0` selects horizontal geometry; `m_orientation == 0` selects vertical geometry.
- Horizontal thumb span is the control height `m_bounds.bottom - m_bounds.top`.
- Vertical thumb span is literal `0x26` / 38 pixels. Recommend source constant `kRankingScrollThumbSpan = 38` in class/file declaration support.
- Leading/trailing parts collapse to the corresponding bounds edge.
- Enabled positive-range geometry derives thumb position from signed `m_scrollPosition / m_scrollRange` arithmetic.
- Disabled or nonpositive-range part `2` is the inset middle region; parts `1` and `3` become an empty rectangle.
- Only the vertical enabled/ranged branch consults `m_thumbDragActive`; it uses local cursor y and `m_thumbDragOffset.y`, then clamps the thumb top to `[bounds.top, bounds.bottom - 38]`.

### Loop, sentinel, and source shape

- The function loops exactly five values and calls cursor/origin helpers during every iteration.
- When origin is exactly `(-1000, -1000)`, binary control jumps directly to `PointInRect` without rebuilding `partRect`. The formal draft preserves that source shape by leaving `partRect` outside the loop and only assigning it in the valid-origin branch.
- Hoisting cursor/origin acquisition out of the loop is rejected because it changes observable call count and can change behavior if cursor/origin state changes during the helper.
- Calling `GetPartRect` is rejected because current `callees` and disassembly prove the geometry is duplicated inline.

### Ownership, placement, and raw liveness

- Four incoming code xrefs all originate in the RankingEventScrollPane mouse/raw interaction family.
- Two xrefs are in modeled UID0000Y3; two are in unmodeled UID0000Y5 raw bodies. Raw call sites do not weaken ownership; they are class-local private interaction code.
- No data/vtable xref reaches this helper, which is expected for a private nonvirtual method.
- Generic scrollbar ownership is rejected because the binary contains separate analogous implementations with different addresses, extents, callers, and owner callbacks.

### C++ readiness

- Resolved blockers: function boundary, caller set, callee set, point/rect contract, field roles, part map, orientation, thumb spans, range gates, drag math, method name, return enum, owner, emitter, and source file.
- Remaining exact-original-spelling uncertainty is a confidence cap, not a no-code blocker.
- A class declaration/enum support block remains necessary for generated compile completeness, but by-structure and the accepted UID0000Y3 precedent establish that this does not block the method body's formal first draft.

## Evidence Standards Used

- Primary authority: current IDA MCP session `359c7886` using exact-address `lookup_funcs`, `xrefs_to`, `callees`, `get_bytes`, `decompile`, `analyze_function`, and paged `disasm` calls.
- Binary evidence: exact function sizes, instruction-level branches, stack argument order, field offsets, return instructions, and padding bytes.
- Documentation evidence: current target/support by-* pages, current generated coverage/tracker state, canonical RectGeometry C++, and accepted sibling source-quality reports.
- Negative evidence: no data/vtable xref, no unrelated callers, no preserved target-specific type names, no function merge at either boundary, and no call from UID0000Y4 to `GetPartRect`.
- Evidence strength: sufficient for high-confidence first-draft source. Exact original identifiers remain unavailable because `type_query` returned no `Ranking*Scroll*Part`, `RectBounds`, or `PaneMouseEvent` preserved type metadata.

## Evidence Checked

- MCP initialization and tool schema refresh: HTTP `initialize` succeeded; current `tools/list` was read before tool calls.
- MCP IDB/status: request ids 5 and 6 (`idb_list`, `server_health`).
- Target inventory/xrefs/callees/bytes/types: ids 10, 11, 13, 14, and 15.
- Target decompile/analyze/disassembly: ids 16, 17, 18, and 19; disassembly was paged at 180 instructions and returned all 231 instructions.
- Caller/raw-call argument order: ids 20 through 24 for `0x00459a60`, `0x0045aa00`, and `0x0045ab50`.
- Sibling and dependency checks: ids 25 through 27.
- Fresh shared geometry/input decompiles: ids 28 through 32 for `InitPointPair`, `InitRectBounds`, `PointInRect`, `EventMan::GetCursorPosition`, and `GetScreenOffset`.
- One attempted `callers` request, id 12, returned `Method 'callers' not found`; current xrefs were obtained through schema-supported `xrefs_to`, and `analyze_function` independently listed modeled caller `sub_459A60` plus all four xrefs.
- Documentation read: target; `RankingEventScrollPane` class; `RankingDialog` file; layout; UID0000Y3 OnMouseEvent; UID0000Y5 raw hover/drag; UID0001ZB GetPartRect; UID0000Y6 DragToPosition; UID0001ZA OnPaint; RectGeometryHelpers; `g_pEventMan`; accepted UID0000Y2/UID0000Y3 reports; FittingRoom, ScrollNewGroupPane, and ScrollVolumePane hit-test pages; by-structure; tracker and generated coverage/output.
- Report search terms: `0000Y4`, `0x0045a400`, `RankingEventScrollPaneHitTest`, and `HitTestPart` across central executed reports and agent research folders.
- Intentionally skipped: old Wave2/Wave3 source and stale `by-memory/-report.old.md`; no current override permits their use.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | Exact function is `0x0045a400-0x0045a70c`, size `0x30c`, with ten pre-entry `cc` bytes and four post-end `cc` bytes. | confirmed | MCP ids 10, 14, 18-19 | renamed UID0000Y4 target, IDA evidence/range | incorporate | applied: target range/current MCP evidence; validator `000000008202` |
| C02 | Source method is `RankingEventScrollPane::HitTestPart(int y, int x)`. | high | ids 11, 16, 18-24; sibling docs | target C++/source-shape; class method inventory | incorporate | applied: target/class/file; generated command `000000008206` |
| C03 | Return family is `RankingScrollPart` values `0..4`, none `-1`/`0xff`. | confirmed numeric, high names | ids 16, 18-19; UID0000Y3 and siblings | target, class enum support, layout state values | incorporate | applied: target/class/layout |
| C04 | Canonical point order is y/x, not x/y. | confirmed | ids 23-24, 28-30; UID00015S | target C++; UID0000Y3 C++ and source notes; class/layout | incorporate | applied: target, UID0000Y3, UID0000Y5, class/layout/UID0001ZB |
| C05 | Horizontal geometry uses control height as thumb span and collapsed left/right edges. | confirmed | ids 16 and 18 | target behavior/C++ | incorporate | applied: exact formal body and target source-shape |
| C06 | Vertical geometry uses fixed 38-pixel span, collapsed top/bottom edges, and drag y-offset clamping. | confirmed | ids 16 and 18-19 | target behavior/C++; class constant support | incorporate | applied: target body, class/layout/UID0001ZB constant support |
| C07 | Enabled/range gates and fields are `m_thumbDragActive +0xfb`, `m_orientation +0xfc`, `m_scrollPosition +0xfe`, `m_scrollRange +0x100`, `m_enabled +0x102`, and `m_thumbDragOffset.y +0x108`. | high | ids 16, 18; layout and UID0000Y2/Y3 | target, class, layout | incorporate | applied: target body/evidence and layout field table |
| C08 | Four incoming code xrefs are `0x459b42`, `0x459c23`, `0x45aadf`, and `0x45abbf`; there is no data/vtable route. | confirmed | id 11 | target caller inventory; class support | incorporate | applied: target and class current MCP evidence |
| C09 | Direct callees are cursor, screen-offset, empty-rect, point-in-rect, and stack-cookie helpers; no `GetPartRect` call exists. | confirmed | ids 13, 16-19 | target callee/source-shape | incorporate | applied: target callee/source-shape and rejected-wrapper text |
| C10 | UID0000Y4 should emit through existing owner [UID:0000BO] into [UID:0000MZ] RankingDialog.cpp. | high | local xrefs, class/file docs, current metadata | target metadata and source placement | already-present | already-present and verified: owner/emitter unchanged; generated route is RankingDialog.cpp |
| C11 | Target score should become `89/91`; owner/emitter/reconstructable remain unchanged. | high | current evidence and scoring rules | target metadata/change log | incorporate | applied: target `89/91`; validator `000000008202` recorded both values |
| C12 | UID0000Y3 must correct `event+8/+0x0c` to y/x and swap related PointInRect/HitTestPart/DragToPosition/drag-offset source spelling. | confirmed | ids 20, 23-24, 28-30 | UID0000Y3 formal C++ and source notes | incorporate | applied: UID0000Y3; validator `000000008188` |
| C13 | Class/file/layout/raw-helper support pages need factual sync but no score or owner/emitter change. | high | current support content and target scope | listed support docs | incorporate | applied: class/file/layout/UID0000Y5/UID0001ZB; validators `000000008189`, `000000008203`-`000000008206` |
| C14 | Generated RankingDialog.cpp should replace UID0000Y4 empty marker after accepted callback validation; no manual tracker edit is required. | confirmed lifecycle expectation | current generated lines 425-429 and validator rules | validator-generated output | validator-generated | applied: command `000000008206` header and UID0000Y4 method at `89/91`; no manual generated edit |

## Positive Evidence Summary

- Current IDA models one real function at `0x0045a400`, size `0x30c`; all 231 instructions were retrieved.
- All four incoming refs are code calls from class-local RankingEventScrollPane interaction paths.
- The target loops `0..4`, tests each candidate through canonical half-open `PointInRect`, returns the byte part on hit, and returns `0xff` on miss.
- Every field used by the draft is corroborated by current class/layout and sibling helpers.
- Accepted sibling pages already emit the same `HitTestPart` source pattern and part naming family.
- UID0000Y3 already commits the ranking-local `RankingScrollPart`, `HitTestPart`, and field/helper naming direction, eliminating the previous target's naming blocker.

## IDA MCP Facts

- `lookup_funcs`: `sub_45A400`, address `0x45a400`, size `0x30c`; `0x45a70b` is inside; `0x45a70c` is not a function; successor `sub_45A710` starts `0x45a710`, size `0x27b`.
- `xrefs_to`: exactly four code xrefs, from `0x459b42`, `0x459c23`, `0x45aadf`, and `0x45abbf`; the raw sites have no enclosing IDA function.
- `callees`: `sub_4A9090`, `sub_5447C0`, `sub_4B7C50`, `sub_4B7E80`, and `@__security_check_cookie@4`.
- `analyze_function`: prototype `char __thiscall(int this, int, int)`, 42 basic blocks, cyclomatic complexity 24, modeled caller `sub_459A60`, and the same four xrefs.
- `get_bytes`: `0x0045a3f6-0x0045a3ff` are ten `cc` bytes; `0x0045a70c-0x0045a70f` are four `cc` bytes before the successor prologue.
- `type_query`: no preserved matching target enum, `RectBounds`, or `PaneMouseEvent` metadata.
- `PointInRect` fresh decompile: first integer is tested against top/bottom; second is tested against left/right.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0045a3f6-0x0045a3ff` | preceding alignment | `cc` padding after UID0001ZA | no | none | n/a | keep outside target |
| `0x0045a400-0x0045a70b` inclusive | UID0000Y4 | `RankingEventScrollPane::HitTestPart` | yes | UID0000BO | `86/90 -> 89/91` | emit first draft |
| `0x0045a70c-0x0045a70f` | following alignment | `cc` padding | no | none | n/a | keep outside target |
| `0x0045a710-0x0045a98a` inclusive | UID0001ZB | separate `GetPartRect` helper | yes | UID0000BO | `86/90` | separate target/support |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00459b42` | UID0000Y3 `OnMouseEvent` | initial event-point hit test |
| `0x00459c23` | UID0000Y3 `OnMouseEvent` | local cursor re-test for active non-thumb part |
| `0x0045aadf` | UID0000Y5 raw begin-interaction body | local cursor re-test before repeated action |
| `0x0045abbf` | UID0000Y5 raw refresh body | local cursor re-test during active interaction |
| `0x004a9090` | callee | `g_pEventMan->GetCursorPosition` role |
| `0x005447c0` | callee | pane `GetScreenOffset` role |
| `0x004b7c50` | callee | `InitRectBounds` for empty page regions |
| `0x004b7e80` | callee | y-first half-open `PointInRect` |

## Documentation Evidence And IDA Status

- Target facts about range, callers, part loop, and offsets are current and retained.
- Target no-code wording is stale under the current code-entry rule and accepted sibling/name evidence.
- UID0000Y3 is useful source-shape support but has a current coordinate-order defect in formal C++ and notes; this report does not treat that defect as binary authority.
- UID0001ZB correctly documents the duplicate orientation geometry and fixed 38-pixel vertical span, but its source-facing `GetPartRect` name remains behind the name already accepted in UID0000Y3/class docs.
- Generated coverage correctly reports UID0000Y4 as routed but non-emitting. It is state evidence, not behavioral evidence.

## Ranked Ownership Analysis

### 1. RankingEventScrollPane / UID0000BO

- Evidence for: all callers are in its modeled mouse handler or raw private interaction island; full-object `this` accesses match its layout; sibling methods share fields and immediate address family; class/file route is already above gate.
- Evidence against: no preserved original class symbol at the target entry.
- Decision: accepted direct semantic owner and emitter.

### 2. Generic ScrollBar or shared scrollbar base

- Evidence for: algorithm and field shape resemble FittingRoom, ScrollNewGroupPane, ScrollCollectionPane, and ScrollVolumePane.
- Evidence against: the executable contains distinct duplicated hit-test bodies with class-local callers, different fixed extents, and different owner callback paths. UID0000Y4 has no generic caller or vtable route.
- Decision: reject as target owner; use siblings only as naming/source-shape precedent.

### 3. RankingDialog file / UID0000MZ directly

- Evidence for: final source placement is `RankingDialog.cpp` and address locality is in the ranking feature island.
- Evidence against: UID0000BO is the narrower true class owner and clears the assignment gate.
- Decision: retain as file route, not direct semantic owner.

### 4. No-owner/non-emitting

- Evidence for: no original symbol and no vtable entry.
- Evidence against: four class-local calls, stable receiver layout, accepted class route, and complete behavior provide stronger positive ownership evidence.
- Decision: reject.

## Source Placement

- Recommended placement: private `RankingEventScrollPane` method in `NexusTK/ui/dialogs/RankingDialog.cpp`, with declaration and `RankingScrollPart` support in the corresponding ranking dialog header/class support surface.
- This fits the private feature-specific class, local caller family, current class/file ownership chain, and accepted UID0000Y3 output.
- Rejected placements: generic `ScrollBar.cpp`, `RectBounds.cpp`, raw helper file, standalone `RankingEventScrollPaneHitTest.cpp`, or direct free function.
- Remaining uncertainty: exact original physical filename could have been a compact feature split, but current file-level evidence strongly supports the accepted RankingDialog route and does not justify a new source file.

## Range / Split / Padding / Reclassification Analysis

- No split or merge is warranted.
- Predecessor UID0001ZA ends at `0x0045a3f6`; ten `cc` bytes separate it from UID0000Y4.
- UID0000Y4 ends exclusively at `0x0045a70c`; four `cc` bytes separate it from UID0001ZB at `0x0045a710`.
- The target is a modeled function, unlike later raw UID0000Y5 starts. It must not be merged into raw hover/drag coverage.
- The target remains reconstructable source code, not a container, thunk, padding range, or duplicate covered-by marker.

## Negative Evidence Summary

- No incoming data or vtable xref exists; this supports private nonvirtual method shape.
- No caller outside RankingEventScrollPane interaction code exists.
- No target call to `GetPartRect` exists; a wrapper-style reconstruction would be false.
- No preserved `RankingScrollPart`, `RectBounds`, or `PaneMouseEvent` IDA type exists.
- No fixed-extent lookup table is used by this target; vertical span is literal 38 and horizontal span is control height.
- No horizontal drag-active branch exists in UID0000Y4.
- No split boundary exists inside the function.
- Consumer similarity alone does not prove generic ownership; distinct sibling implementations reject that route.

## IDA Rename / Type / Comment Recommendations

- Source-facing method: `RankingEventScrollPane::HitTestPart`.
- Source-facing signature: `RankingScrollPart HitTestPart(int y, int x)`.
- Source-facing fields: `m_bounds`, `m_thumbDragActive`, `m_orientation`, `m_scrollPosition`, `m_scrollRange`, `m_enabled`, and `m_thumbDragOffset`.
- Source-facing helpers: `g_pEventMan->GetCursorPosition`, `GetScreenOffset`, `InitRectBounds`, and `PointInRect`.
- Source-facing constant: `kRankingScrollThumbSpan = 38`.
- IDA DB edits are not requested and were not performed. These recommendations are documentation/source output only.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. The target is reconstructable, routed, above the combined-score gate, and all material implementation blockers are resolved or bounded.
- Exact formal `RECONSTRUCTION_CPP CODE` insertion text:

```cpp
RankingScrollPart RankingEventScrollPane::HitTestPart(int y, int x)
{
    RectBounds partRect;

    for (int partValue = kRankingScrollPartLeading;
         partValue <= kRankingScrollPartTrailing;
         ++partValue) {
        const RankingScrollPart part = static_cast<RankingScrollPart>(partValue);
        Point cursor;
        Point origin;

        g_pEventMan->GetCursorPosition(&cursor);
        GetScreenOffset(&origin);

        if (origin.y != -1000 || origin.x != -1000) {
            cursor.y -= origin.y;
            cursor.x -= origin.x;
            partRect = m_bounds;

            if (m_orientation != 0) {
                const int thumbSpan = m_bounds.bottom - m_bounds.top;

                if (part == kRankingScrollPartLeading) {
                    partRect.right = partRect.left;
                } else if (part == kRankingScrollPartTrailing) {
                    partRect.left = partRect.right;
                } else if (m_enabled && m_scrollRange > 0) {
                    const int thumbLimit = m_bounds.right - thumbSpan;
                    const int thumbLeft = m_bounds.left +
                        (m_scrollPosition * (thumbLimit - m_bounds.left)) /
                            m_scrollRange;
                    const int thumbRight = thumbLeft + thumbSpan;

                    if (part == kRankingScrollPartThumb) {
                        partRect.left = thumbLeft;
                        partRect.right = thumbRight;
                    } else if (part == kRankingScrollPartPageBeforeThumb) {
                        partRect.right = thumbLeft;
                    } else if (part == kRankingScrollPartPageAfterThumb) {
                        partRect.left = thumbRight;
                    }
                } else if (part == kRankingScrollPartThumb) {
                    partRect.left += thumbSpan;
                    partRect.right -= thumbSpan;
                } else {
                    InitRectBounds(&partRect, 0, 0, 0, 0);
                }
            } else {
                const int thumbSpan = kRankingScrollThumbSpan;

                if (part == kRankingScrollPartLeading) {
                    partRect.bottom = partRect.top;
                } else if (part == kRankingScrollPartTrailing) {
                    partRect.top = partRect.bottom;
                } else if (m_enabled && m_scrollRange > 0) {
                    const int thumbLimit = m_bounds.bottom - thumbSpan;
                    int thumbTop;

                    if (m_thumbDragActive) {
                        thumbTop = m_bounds.top + cursor.y - m_thumbDragOffset.y;

                        if (thumbTop < m_bounds.top) {
                            thumbTop = m_bounds.top;
                        }
                        if (thumbTop > thumbLimit) {
                            thumbTop = thumbLimit;
                        }
                    } else {
                        thumbTop = m_bounds.top +
                            (m_scrollPosition * (thumbLimit - m_bounds.top)) /
                                m_scrollRange;
                    }

                    const int thumbBottom = thumbTop + thumbSpan;

                    if (part == kRankingScrollPartThumb) {
                        partRect.top = thumbTop;
                        partRect.bottom = thumbBottom;
                    } else if (part == kRankingScrollPartPageBeforeThumb) {
                        partRect.bottom = thumbTop;
                    } else if (part == kRankingScrollPartPageAfterThumb) {
                        partRect.top = thumbBottom;
                    }
                } else if (part == kRankingScrollPartThumb) {
                    partRect.top += thumbSpan;
                    partRect.bottom -= thumbSpan;
                } else {
                    InitRectBounds(&partRect, 0, 0, 0, 0);
                }
            }
        }

        if (PointInRect(y, x, &partRect)) {
            return part;
        }
    }

    return kRankingScrollPartNone;
}
```

- Behavior preservation: retains the five iterations, per-iteration cursor/origin calls, exact sentinel condition, inline horizontal/vertical geometry, signed position/range division, vertical-only drag branch, half-open y/x point test, and `-1` miss return.
- Plausible source shape: ordinary private class helper, era-appropriate loop/conditionals, no decompiler temporaries, no address labels, and naming consistent with accepted sibling scrollbar methods.
- Required declaration support: `RankingScrollPart` constants, `kRankingScrollThumbSpan`, `Point`, `RectBounds`, target method declaration, and current class fields/helper declarations.
- Exact no-code proof: not applicable; the former no-code rationale is superseded.

## Final Recommendation

- Implemented: UID0000Y4 is named/path-labeled `RankingEventScrollPaneHitTestPart`, preserves its UID and exact range, contains the accepted formal C++ body, and is scored `89/91`.
- Preserved: owner, emitter, reconstructable state, emitter position, source file, range, and all broad support-page scores.
- Corrected: UID0000Y3 coordinate order and drag-offset spelling now follow the canonical y/x contract without a score change.
- Synchronized: class/file/layout/raw-helper/GetPartRect support facts retain report-level detail and their prior metadata.
- Validator-owned generated output and coverage were refreshed only by the scoped validator commands recorded below.
- Future separate work outside this assignment: full class declaration emission and source-quality passes for UID0001ZA, UID0001ZB, UID0000Y5, and UID0000Y6.

## Recommended Target Doc Changes

- Renamed the target to `by-memory/0x0045a400-0x0045a70b.RankingEventScrollPaneHitTestPart.md` through validator-aware workflow.
- Set score `89/91`, preserved all other metadata, and inserted the exact C++ from this report.
- Updated title/status/source-shape references to `HitTestPart` and `RankingScrollPart`.
- Replaced stale `95/95` and unresolved-name no-code text with current code-entry and bounded confidence rationale.
- Added MCP session `359c7886`, exact size, four xrefs, 231-instruction disassembly, boundary bytes, callee set, y/x contract, sentinel behavior, and rejected wrapper/generic-owner routes.
- Preserved existing field/range/caller facts and historical change notes.

## Recommended Support Doc Changes

- `by-class/RankingEventScrollPane.md`: changed inventory `HitTestScrollPart` to `HitTestPart`; added exact signature, six-value `RankingScrollPart` family, `kRankingScrollThumbSpan = 38`, y/x Point contract, inline geometry disposition, four-call route, and source-ready UID0000Y4 state. Score remains `87/89`.
- `by-file/RankingDialog.md`: records UID0000Y4 as source-ready/emitting while preserving UID0000Y2 no-standalone status and the class declaration requirement. Score remains `88/91`.
- `by-type/by-struct/RankingEventScrollPaneLayout.md`: records `m_thumbDragActive`, `m_enabled`, y/x `m_thumbDragOffset` components, fixed vertical span, and the full named part family. Score remains `85/89`.
- UID0000Y3 now uses `event.y/event.x`, y/x `PointInRect`/`HitTestPart`/`DragToPosition`, and y/x drag offsets. Score remains `89/91`.
- UID0000Y5 records y-first raw calls and `+0x108` as the y component. Score remains `86/90`.
- UID0001ZB records source-facing `GetPartRect`, full part names, the y/x Point contract, and shared `kRankingScrollThumbSpan`; formal C++ remains blank and score remains `86/90`.
- [UID:00015S] RectGeometryHelpers and [UID:00028L] g_pEventMan were unchanged because they already contain same-or-greater canonical support.

## Score And Metadata Recommendation

- Target before callback: `86/90`, owner/emitter UID0000BO, reconstructable true, blank formal code.
- Target after callback: `89/91`, owner/emitter/reconstructable unchanged, formal C++ populated.
- Reason higher: all named source-quality blockers were rechecked; method/type/helper names are now supported; current MCP confirms exact range, all xrefs/callees, every branch, dependency contracts, caller argument order, and boundary bytes.
- Reason not higher: exact original enum/member/method spellings are not symbol-proven; the sentinel path intentionally retains an uninitialized/stale local rectangle source shape; class declaration output is not complete; adjacent ranking scrollbar methods remain separate empty emitters.
- Score-improvement attempts: resolved method naming, return enum, point/rectangle types, coordinate order, source placement, range/split, field names, constants, orientation, range gates, drag path, and C++ eligibility. No blocker remains deferred as generic future investigation.
- Support metadata: no score, owner, emitter, or reconstructable changes were made to broad support pages; accepted content corrections were applied.

## Open Questions With Attempted Resolution

- Exact original method spelling: no symbol/type survived; accepted local and sibling conventions make `HitTestPart` the best defensible name. This is a confidence cap only.
- Exact enum spelling: no preserved enum metadata; `RankingScrollPart` is already accepted by UID0000Y3 and fits local class scoping. Numeric values are confirmed.
- `kRankingScrollThumbSpan` declaration location: exact original header/file location is not recoverable. The accepted source-facing class/file support uses value 38; this does not block the method body.
- Sentinel-path local initialization: disassembly proves no rectangle rebuild when both origin components are `-1000`. The draft preserves this rather than inventing a safe return or initialization. A future source-match/compiler pass may refine declaration placement, but behavior and current first draft are implementation-ready.
- Full class declaration: the class page identifies it as separate generated compile-completeness work; it is not a reason to keep UID0000Y4 blank.
- Remaining unresolved evidence that could raise confidence: recovered original headers/PDB/type names or compiler source-match results. None is currently available, and none is required for the recommended first draft.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Not applicable. `auto-generated/-ag-research-tracker.md`, generated coverage, and generated C++ are validator-owned.
- No manual `-coverage-report.md` edit was made.

## Follow-Up Actions

- Implementation callback complete; independent supervisor validation, execution, and archive state is external to this report body and recorded by validator history; no pending lifecycle action is asserted.
- Separate future assignment: class declaration compile-completeness and first-draft reviews for remaining ranking scrollbar empty emitters.

## Confidence

- Recommendation confidence: high.
- Target score confidence: high for `89/91`; scores above 94 are not justified.
- Ownership/source placement confidence: high.
- C++ behavior confidence: high, with exact-spelling and source-match caveats explicitly bounded.
- Remaining uncertainty: exact original identifiers and declaration placement only.

## Validator Results

All commands used `python .\tools\validator.py --mode file --file <path> --apply --queue-timeout 240` and returned exit code `0`, `ok: 1`.

| File | Command ID | Timestamp |
| --- | --- | --- |
| UID0000Y3 `RankingEventScrollPaneOnMouseEvent.md` | `000000008188` | `2026-07-12T16:13:45-04:00` |
| UID0000Y5 `RankingEventScrollPaneRawHoverDragHelpers.md` | `000000008189` | `2026-07-12T16:13:54-04:00` |
| UID0000Y4 `RankingEventScrollPaneHitTestPart.md` | `000000008202` | `2026-07-12T16:19:46-04:00` |
| `by-class/RankingEventScrollPane.md` | `000000008203` | `2026-07-12T16:19:53-04:00` |
| `by-file/RankingDialog.md` | `000000008204` | `2026-07-12T16:20:01-04:00` |
| `by-type/by-struct/RankingEventScrollPaneLayout.md` | `000000008205` | `2026-07-12T16:20:09-04:00` |
| UID0001ZB `RankingEventScrollPaneGetScrollRegionRect.md` | `000000008206` | `2026-07-12T16:20:17-04:00` |

- Rename proof: command `000000008202` recorded `path_update 0000Y4`, changed blank-to-block autogen state, recorded `89/91`, and updated live UID reverse links.
- Generated proof: `auto-generated/NexusTK/ui/dialogs/RankingDialog.cpp` header is command `000000008206` at `2026-07-12T16:20:17-04:00`; UID0000Y4 emits `HitTestPart(int y, int x)` at `89/91`, and UID0000Y3 emits corrected y-first calls.
- Warnings: `by-file/RankingDialog.md` reported pre-existing missing references `0003X6`-`0003X9`; the command still returned `ok: 1`. No callback-specific validator error remains.

## Changed Files

- Renamed: `by-memory/0x0045a400-0x0045a70b.RankingEventScrollPaneHitTest.md` to `by-memory/0x0045a400-0x0045a70b.RankingEventScrollPaneHitTestPart.md`.
- Modified directly: the renamed UID0000Y4 target, `by-class/RankingEventScrollPane.md`, `by-file/RankingDialog.md`, `by-type/by-struct/RankingEventScrollPaneLayout.md`, UID0000Y3, UID0000Y5, UID0001ZB, and this agent-owned report.
- Validator-managed side effects: UID path registry/reverse-link updates, projected completion statistics, autogen registry state, generated coverage/tracker state, and `auto-generated/NexusTK/ui/dialogs/RankingDialog.cpp`. None was edited manually.
- Leases: every directly edited by-* file was leased only for its edit/validator interval; all B004 leases were released, and `current_leases.md` showed no active leases after release.
- Report execution boundary: B004 did not run `execute_report`, any dry-run/probing variant, lifecycle command, registry repair, archive move, or manual report move. This records agent action only and does not assert the report's external lifecycle location/state.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor Gate 1 accepted exact report SHA256 `4CD25679472FB6B5CD7E2420DE545E5610CB046288E4AD05E39CB4C3529340DF` before implementation.
- [x] Renamed UID0000Y4 target through validator-aware workflow; preserved UID/range.
- [x] Updated target `86/90 -> 89/91`; preserved owner/emitter/reconstructable/position metadata.
- [x] Inserted the exact formal `RankingEventScrollPane::HitTestPart(int y, int x)` C++ body.
- [x] Incorporated current MCP range/xref/callee/byte/disassembly/type-negative evidence at report-level detail.
- [x] Preserved the exact five-part loop, per-iteration cursor/origin calls, sentinel branch, orientation math, gates, vertical drag behavior, and y/x point contract.
- [x] Replaced stale target no-code/95-threshold/helper-name text while preserving it as historical context.
- [x] Updated class, file, layout, UID0000Y3, UID0000Y5, and UID0001ZB support exactly as accepted, with scores/metadata retained.
- [x] Kept [UID:00015S] and [UID:00028L] unchanged because canonical support was already sufficient.
- [x] Kept split/merge/reclassification and IDA DB state unchanged; preserved padding and separate neighbor boundaries.
- [x] Confirmed third-party import directive is not applicable.
- [x] Updated every Claim And Incorporation Ledger row with an applied or already-present verification state.
- [x] Ran one scoped validator per changed/renamed by-* file and recorded command IDs, timestamps, exit codes, and ok counts.
- [x] Verified generated `RankingDialog.cpp` replaced the UID0000Y4 empty marker and carries a current validator header.
- [x] Made no manual generated/tracker/coverage/validator/lifecycle/archive edits.
- [x] Preserved rejected generic-owner, direct-file-owner, wrapper, no-owner/non-emitting, split/merge, and x/y alternatives.
- [x] No accepted item remains unapplied; no blocker is being hidden.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support facts incorporated at report-level detail.
- [x] Target rename, metadata, formal C++, and historical/current-state text verified.
- [x] UID0000Y3 coordinate-order correction verified against MCP call sites and canonical UID00015S contract.
- [x] Claim And Incorporation Ledger verification states updated for every accepted claim.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly retained as accepted.
- [x] Historical assumptions, rejected alternatives, and negative evidence preserved.
- [x] Scoped validators run and results recorded.
- [x] Generated output/coverage freshness verified without manual generated edits.
- [x] All edit leases released immediately after the edit/validator batches.
- [x] Remaining unapplied accepted items: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000008231","destination_path":"executed-b-agent-research/B004/0000Y4-RankingEventScrollPaneHitTest-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0000Y4-RankingEventScrollPaneHitTest-source-quality.md","timestamp":"2026-07-12T16:34:33-04:00","uid":"0000Y4"} -->
<!-- {"agent":"B004","command_id":"000000008232","destination_path":"tools/leaser/Agents/Agent-B004/research/0000Y4-RankingEventScrollPaneHitTest-source-quality.md","details":"report returned to active agent research for rework","event":"de-executed-for-rework","source_path":"executed-b-agent-research/B004/0000Y4-RankingEventScrollPaneHitTest-source-quality.md","timestamp":"2026-07-12T16:35:34-04:00","uid":"0000Y4"} -->
<!-- {"agent":"B004","command_id":"000000008234","destination_path":"executed-b-agent-research/B004/0000Y4-RankingEventScrollPaneHitTest-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0000Y4-RankingEventScrollPaneHitTest-source-quality.md","timestamp":"2026-07-12T16:37:29-04:00","uid":"0000Y4"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
