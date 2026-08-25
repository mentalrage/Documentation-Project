*** UID:0001VO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000BO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000BO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# RankingEventScrollPaneLayout

## Status

- Confidence: strong for local scrollbar fields and vtable view offsets; base `Pane`/`ControlPane` layout remains inherited.
- Likely owner: [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- Parent class: [UID:0000BO][RankingEventScrollPane](by-class/RankingEventScrollPane.md)
- Primary memory evidence: [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md)
- Vtable evidence: [UID:0001YK][RankingEventScrollPaneVtables](by-type/by-vtable/RankingEventScrollPaneVtables.md)
- Closest parallel: [UID:0001W2][ScrollVolumePaneLayout](by-type/by-struct/ScrollVolumePaneLayout.md)

## Layout Hypothesis

`RankingEventScrollPane` extends `Pane` and exposes three vtable views. The local scrollbar state matches the later `ScrollVolumePane` shape closely, with a feature-specific owner callback back into `RankingEventListPane`.

| Offset | Size | Observed field | Evidence |
| --- | --- | --- | --- |
| `+0x00` | 4 | primary vtable | Raw constructor and inline list-pane child setup write `0x00610a4c` after `Pane::Pane(1)`. |
| `+0x44` | 16 | pane bounds rectangle | `OnMouseEvent`, paint, hit-test, and dirty-rect helpers use this inherited rectangle. |
| `+0xa0` | 4 | secondary input/control vtable view | Constructor stores `0x00610a98`; `OnMouseEvent` receives this subobject pointer and subtracts `0xa0` to recover the full object. |
| `+0xa4` | 4 | tertiary event/update vtable view | Constructor stores `0x00610ac8`; the only confirmed local slot is the inherited/default `0x00544e90` event-update target. |
| `+0xf8` | 2 | inferred `m_scrollSkinIndex` / skin-index word | Constructor clears the packed `+0xf8` dword; [UID:0000Y2][0x004598b0-0x00459a59.RankingEventScrollPaneRawCtorAndSetters](by-memory/0x004598b0-0x00459a59.RankingEventScrollPaneRawCtorAndSetters.md) updates this low word and invalidates. B004 current MCP/source-family evidence supersedes stale current-position wording for this offset. |
| `+0xfa` | 1 | inferred `m_scrollStyle` / style-state byte | Constructor clears the packed `+0xf8` dword; the raw setter at `0x00459940` compares/stores this byte and invalidates. [UID:0001ZA][0x00459ce0-0x0045a3f5.RankingEventScrollPaneOnPaint](by-memory/0x00459ce0-0x0045a3f5.RankingEventScrollPaneOnPaint.md) reads it in the disabled/no-range draw path. |
| `+0xfb` | 1 | inferred `m_thumbDragActive` | Hit-test and part-rectangle math switch to drag-anchor mode when this byte is set; UID0000Y3 clears/sets it around mouse interaction. |
| `+0xfc` | 1 | inferred `m_orientation` | Constructor stores the orientation argument; `0` selects vertical and nonzero selects horizontal geometry/paint branches. |
| `+0xfe` | 2 | inferred signed `short m_scrollPosition` | Drag and range helpers read/write this word; UID0000Y6 snapshots it as the old position and compares it to the computed signed-short result. |
| `+0x100` | 2 | inferred signed `short m_scrollRange` | Set-range, paint, and drag helpers promote it to signed `int` for scaling; vertical UID0000Y6 math uses `m_scrollRange + 1` and caps back to this value. |
| `+0x102` | 1 | inferred `m_enabled` | Enable/disable raw helpers set this byte; mouse and paint gates require it to be nonzero. |
| `+0x103` | 1 | inferred `m_highlightPart` | Hover helper and OnPaint use this `RankingScrollPart` byte; `0xff` is none and part `2` selects the highlighted thumb frame. |
| `+0x104` | 1 | inferred `m_activePart` | Mouse handler and reset helper use this pressed/active `RankingScrollPart` byte and `0xff` as none. |
| `+0x108` | 4 | inferred `m_thumbDragOffset.y` | Canonical `Point` first component. Mouse press stores `event.y - thumbRect.top`; vertical hit-test/drag math subtracts this y offset. |
| `+0x10c` | 4 | inferred `m_thumbDragOffset.x` | Canonical `Point` second component. Mouse press stores `event.x - thumbRect.left`; horizontal drag conversion consumes this x offset. |

## State Values

Known scrollbar part codes:

| Code | Source-facing value | Meaning |
| --- | --- | --- |
| `0` | `kRankingScrollPartLeading` | collapsed leading edge/arrow region |
| `1` | `kRankingScrollPartPageBeforeThumb` | track/page region before thumb |
| `2` | `kRankingScrollPartThumb` | thumb |
| `3` | `kRankingScrollPartPageAfterThumb` | track/page region after thumb |
| `4` | `kRankingScrollPartTrailing` | collapsed trailing edge/arrow region |
| `0xff` | `kRankingScrollPartNone` | no hover/active part |

Vertical part geometry uses source-facing constant `kRankingScrollThumbSpan = 38`; nonzero-orientation horizontal geometry uses the control height as its thumb span. `Point`, `PointInRect`, `HitTestPart`, and `DragToPosition` follow the canonical y-first, x-second contract from [UID:00015S][0x004b7c30-0x004b7f87.RectGeometryHelpers](by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md).

## Drag-To-Position Layout Semantics

[UID:0000Y6][0x0045ac10-0x0045adc3.RankingEventScrollPaneDragToPosition](by-memory/0x0045ac10-0x0045adc3.RankingEventScrollPaneDragToPosition.md) resolves the remaining position/range/axis interaction:

- It obtains the thumb rectangle, samples cursor/origin twice, and initializes separate leading/trailing copies of inherited `m_bounds +0x44` only when the sampled origin is not the exact invalid pair `(-1000, -1000)`.
- Nonzero `m_orientation +0xfc` is horizontal: collapse `leading.right = leading.left` and `trailing.left = trailing.right`, then compute `x - m_thumbDragOffset.x + 1` using `+0x10c`.
- Zero orientation is vertical: collapse `leading.bottom = leading.top` and `trailing.top = trailing.bottom`, then compute `y - m_thumbDragOffset.y + 1` using `+0x108`.
- Both axes clamp the thumb start to the collapsed track start and to `trackEnd - thumbExtent`, then use signed `cdq; idiv`, truncating toward zero. Horizontal uses `m_scrollRange`; vertical uses `m_scrollRange + 1` and caps the signed-short result to `m_scrollRange`.
- No zero-span guard, nearest rounding, preclamp, or removal of the observed `+1` exists.
- On a changed value, the source factors expanded owner fields back into `GetOwnerPane()->SetScrollPosition(0, oldPosition, newPosition)`. Owner `RankingEventListPane +0x108/+0x10c` must not be confused with this scroll pane's `Point m_thumbDragOffset +0x108/+0x10c`.

## Interaction Tail Lifecycle

- [UID:0004J0][0x0045a990-0x0045a9ff.RankingEventScrollPaneSetHighlightedPartRaw](by-memory/0x0045a990-0x0045a9ff.RankingEventScrollPaneSetHighlightedPartRaw.md) treats `+0x103` as signed `m_highlightPart`: unchanged values do nothing; old/new non-none values resolve through `GetPartRect` and invalidate before the byte store.
- [UID:0004J1][0x0045aa00-0x0045ab48.RankingEventScrollPaneBeginPartInteractionRaw](by-memory/0x0045aa00-0x0045ab48.RankingEventScrollPaneBeginPartInteractionRaw.md) treats `+0x104` as signed `m_activePart`; thumb part `2` stores `mouseY - rect.top` at `m_thumbDragOffset.y +0x108` and `mouseX - rect.left` at `.x +0x10c`, then source-calls the active updater and schedules `(0,200,0,0)`.
- [UID:0004J2][0x0045ab50-0x0045ac0f.RankingEventScrollPaneUpdateActiveInteractionRaw](by-memory/0x0045ab50-0x0045ac0f.RankingEventScrollPaneUpdateActiveInteractionRaw.md) reads `m_activePart` to select unconditional thumb drag versus hit-equal non-thumb updates. It invalidates/clears `m_highlightPart` only after the non-thumb path; its thumb early return intentionally preserves highlight.
- [UID:0000Y7][0x0045add0-0x0045ae2b.RankingEventScrollPaneRawResetState](by-memory/0x0045add0-0x0045ae2b.RankingEventScrollPaneRawResetState.md) removes pending repeat timers through the inherited `+0xa4` handler, clears `m_activePart` to none, and conditionally invalidates/clears old `m_highlightPart`.
- Natural C++ alignment after byte `m_orientation +0xfc` supplies padding at `+0xfd` before signed short `m_scrollPosition +0xfe`; natural Point alignment supplies `+0x105..+0x107` before `m_thumbDragOffset +0x108`. These are padding, not undocumented state.
- The complete class tail remains size `0x18` beyond Pane's `0xf8`, yielding object size `0x110`; no field was added for the seven code-alignment bytes between UID0004J1 and UID0004J2.

## Evidence Notes

- Constructor bytes at `0x004598b0-0x0045990c` clear the packed `+0xf8` state dword (`m_scrollSkinIndex`, `m_scrollStyle`, and drag flag), clear `+0xfe/+0x100`, store `+0xfc`, initialize `+0x102 = 1`, and set `+0x103/+0x104` to `0xff`.
- IDA vtable/xref evidence confirms the three vtable bases at `+0x00`, `+0xa0`, and `+0xa4`. `RankingEventListPane` constructor `0x0045ae30` also allocates a `0x110`-byte scroll child and installs the same three vtables inline at `0x0045aeb2`, `0x0045aeb8`, and `0x0045aec2`; `0x110` was verified as 272 bytes with `tools/int_convert.py`.
- [UID:0000Y3][0x00459a60-0x00459ccd.RankingEventScrollPaneOnMouseEvent](by-memory/0x00459a60-0x00459ccd.RankingEventScrollPaneOnMouseEvent.md) uses the secondary-vtable subobject pointer and reads/writes hover, active, enabled, orientation, range, and drag fields.
- [UID:0000Y4][0x0045a400-0x0045a70b.RankingEventScrollPaneHitTestPart](by-memory/0x0045a400-0x0045a70b.RankingEventScrollPaneHitTestPart.md), [UID:0001ZB][0x0045a710-0x0045a98a.RankingEventScrollPaneGetScrollRegionRect](by-memory/0x0045a710-0x0045a98a.RankingEventScrollPaneGetScrollRegionRect.md), [UID:0001ZA][0x00459ce0-0x0045a3f5.RankingEventScrollPaneOnPaint](by-memory/0x00459ce0-0x0045a3f5.RankingEventScrollPaneOnPaint.md), and [UID:0000Y6][0x0045ac10-0x0045adc3.RankingEventScrollPaneDragToPosition](by-memory/0x0045ac10-0x0045adc3.RankingEventScrollPaneDragToPosition.md) agree on the same local offsets.
- Live IDA MCP `analyze_function` on 2026-06-13 reconfirmed field reads/writes at `+0x44`, `+0xfb`, `+0xfc`, `+0xfe`, `+0x100`, `+0x102`, `+0x103`, `+0x104`, `+0x108`, and `+0x10c` across mouse, paint, hit-test, rectangle, drag, and inline owner-construction paths. Decimal conversions for the key offsets were verified with `tools/int_convert.py`.
- 2026-07-09 B004 current MCP session `supervisor_nexustk_20260709` reconfirmed UID0000Y2's exact raw helper island and repaired the `+0xf8/+0xfa` field names from stale generic/current-position wording. The `+0xf8` word follows the accepted scroll-family skin-index role, while `+0xfa` remains an inferred style-state byte with a raw compare/store/invalidate helper and OnPaint disabled/no-range consumer. These names are source-facing inferences, not original-symbol proof.
- 2026-07-12 B003 current MCP session `359c7886` reconfirmed OnPaint reads `m_scrollStyle`, `m_thumbDragActive`, `m_orientation`, `m_scrollPosition`, `m_scrollRange`, `m_enabled`, `m_highlightPart`, and `m_thumbDragOffset` at the offsets above. Accepted UID0000Y3 and UID0001ZA first drafts now use the same `RankingScrollPart`/`m_*` naming direction. Current IDA has no preserved Ranking-specific UDT/enum, so these remain implementation-ready inferred names rather than recovered symbols.
- 2026-07-12 B004 UID0000Y4 current MCP session `359c7886` resolves the point components and span contract: `PaneMouseEvent +0x08/+0x0c` flow as y/x, `InitPointPair` stores top/y then left/x deltas at `+0x108/+0x10c`, vertical hit-test reads `+0x108`, and UID0000Y4 uses literal `38` vertically versus control height horizontally.
- 2026-07-12 B004 evidence-time MCP database `bf5519ae` resolves the complete [UID:0001ZB][0x0045a710-0x0045a98a.RankingEventScrollPaneGetScrollRegionRect](by-memory/0x0045a710-0x0045a98a.RankingEventScrollPaneGetScrollRegionRect.md) body. Requests `62006-62019` directly reconfirm inherited `m_bounds` `+0x44`, `m_thumbDragActive` `+0xfb`, `m_orientation` `+0xfc`, signed-short `m_scrollPosition` `+0xfe`, signed-short `m_scrollRange` `+0x100`, byte `m_enabled` `+0x102`, and y-first `m_thumbDragOffset.y` `+0x108`. The method localizes both Point components but consumes only y/`+0x108` in its vertical drag branch; its horizontal branch intentionally remains proportional even during drag.
- UID0001ZB also confirms the value/geometry interpretation: nonzero orientation uses `m_bounds.bottom - m_bounds.top` as horizontal thumb span; zero orientation uses `kRankingScrollThumbSpan = 38`; leading/trailing parts are collapsed edges; page-before/page-after are empty through `InitRectBounds` when disabled or range is nonpositive; and enabled proportional arithmetic promotes the signed-short position/range fields to integer expressions. No target read uses `m_scrollSkinIndex`, a vertical span table, `m_thumbDragOffset.x`, `m_highlightPart`, or `m_activePart`.

## Cross-References

- [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- [UID:0000BO][RankingEventScrollPane](by-class/RankingEventScrollPane.md)
- [UID:0001YK][RankingEventScrollPaneVtables](by-type/by-vtable/RankingEventScrollPaneVtables.md)
- [UID:0000Y2][0x004598b0-0x00459a59.RankingEventScrollPaneRawCtorAndSetters](by-memory/0x004598b0-0x00459a59.RankingEventScrollPaneRawCtorAndSetters.md)
- [UID:0000Y5][0x0045a990-0x0045ac0f.RankingEventScrollPaneRawHoverDragHelpers](by-memory/0x0045a990-0x0045ac0f.RankingEventScrollPaneRawHoverDragHelpers.md)
- [UID:0004J0][0x0045a990-0x0045a9ff.RankingEventScrollPaneSetHighlightedPartRaw](by-memory/0x0045a990-0x0045a9ff.RankingEventScrollPaneSetHighlightedPartRaw.md)
- [UID:0004J1][0x0045aa00-0x0045ab48.RankingEventScrollPaneBeginPartInteractionRaw](by-memory/0x0045aa00-0x0045ab48.RankingEventScrollPaneBeginPartInteractionRaw.md)
- [UID:0004J2][0x0045ab50-0x0045ac0f.RankingEventScrollPaneUpdateActiveInteractionRaw](by-memory/0x0045ab50-0x0045ac0f.RankingEventScrollPaneUpdateActiveInteractionRaw.md)
- [UID:0000Y7][0x0045add0-0x0045ae2b.RankingEventScrollPaneRawResetState](by-memory/0x0045add0-0x0045ae2b.RankingEventScrollPaneRawResetState.md)

## Changes

- 2026-07-12 B005 UID0000Y5 layout support callback:
  - Before: executed B003 narrow Y6 state `87/91`, with exact drag math but no source-ready Y5 child lifecycle or Y7 reset synchronization.
  - After: `88/91`, formal block still blank/non-emitting, with complete `+0x103/+0x104/+0x108/+0x10c` highlight/active/anchor lifecycle, timer/reset semantics, natural padding, and exact child links.
  - Preserved: owner/emitter UID0000BO, object size `0x110`, all prior Y2/Y3/Y4/ZA/ZB/Y6 geometry and signed-field evidence, and separation from RankingEventListPane owner `+0x108/+0x10c` fields.

- 2026-07-12 B003 UID0000Y6 layout support callback:
  - Before: `85/89`; position/range words and y/x offsets were identified, but exact signed arithmetic, axis clamps, sentinel-controlled bounds copies, `+1`, vertical cap, and owner/list offset distinction were not complete.
  - Changed to: `87/91`; formal C++ remains blank and owner/emitter/source route remain unchanged. Added exact signed-short types and full UID0000Y6 layout semantics.
  - Preservation: no class declaration, raw UID0000Y5/UID0000Y7 split, vtable, or B005-owned broader class work was changed.

- 2026-07-12 B004 UID0001ZB layout support sync:
  - Changed to: evidence text only; layout `85/89`, owner/emitter UID0000BO, reconstructable state, and blank formal C++ remain unchanged.
  - Evidence: accepted B004 UID0001ZB report SHA256 `1EE84348BCBB99F49649536529ED4DBCBF15E30FAACD46AED663DA084ABAA915` and evidence-time MCP database `bf5519ae` requests `62006-62019` confirm all target-consumed offsets/types, y/x Point localization, signed-short proportional arithmetic, horizontal height span, vertical literal `38`, and vertical-only drag-offset use.
  - Preserved: existing constructor/vtable/layout evidence, inferred-name caveats, sibling method findings, the absence of a stable whole-class declaration, and rejection of a target-specific skin table or horizontal drag-field consumer.

- 2026-07-12 B004 UID0000Y4 layout support sync:
  - Changed to: metadata remains `85/89`, owner/emitter UID0000BO, and formal C++ remains blank. Split `Point m_thumbDragOffset` into documented y/x components, added the canonical point/helper order, and added the fixed vertical/horizontal span rules.
  - Evidence: current MCP session `359c7886` call-site and helper decompilation for UID0000Y3/UID0000Y4/UID0000Y5 plus canonical UID00015S geometry support. Inherited base layout and exact original spellings remain score caps.

- 2026-07-12 B003 UID0001ZA support sync:
  - Changed to: metadata remains `85/89`, owner/emitter [UID:0000BO][RankingEventScrollPane](by-class/RankingEventScrollPane.md), and formal C++ remains blank. Normalized local fields and part codes to accepted UID0000Y3/UID0001ZA source-facing names.
  - Evidence: current MCP session `359c7886` confirms OnPaint offsets, orientation/frame branches, style-gated clear, highlighted thumb test, and no preserved Ranking UDT/enum. Exact spellings remain explicitly inferred.

- 2026-07-09 B004 UID0000Y2 support sync:
  - Before: `+0xf8` was a broad four-byte packed flags/state word whose setter was described as low/current state, and `+0xfa` was not listed as its own style-state byte.
  - After: split the packed state into `+0xf8` inferred `m_scrollSkinIndex`, `+0xfa` inferred `m_scrollStyle` / style-state byte, and `+0xfb` drag-tracking flag; metadata remains `85/89`, owner/emitter [UID:0000BO][RankingEventScrollPane](by-class/RankingEventScrollPane.md), and blank formal C++.
  - Evidence: accepted B004 UID0000Y2 report and current MCP session `supervisor_nexustk_20260709` confirm the raw compare/store/invalidate helpers at `0x00459910` and `0x00459940`, the constructor packed-state clear, sibling OnPaint `+0xfa` read, and scroll-family `m_scrollSkinIndex` naming precedent.
- 2026-06-13: Raised `COMPLETION` from `78` to `85` and `CONFIDENCE` from `86` to `89`.
  - Before: the page identified the major fields, but the score stayed below gate because the evidence did not explicitly reconcile all modeled helper consumers and the drag-anchor width.
  - After: the page records cross-helper agreement for the local scrollbar offsets, clarifies the two-word drag anchor at `+0x108/+0x10c`, and ties the `0x110` allocation plus three vtable-view offsets to live IDA.
  - Evidence: IDA MCP `analyze_function` on `0x00459a60`, `0x00459ce0`, `0x0045a400`, `0x0045a710`, `0x0045ac10`, and `0x0045ae30` confirmed the shared offset set; `xrefs_to` confirmed the vtable stores and helper callers; `tools/int_convert.py` verified the decimal sizes/offsets used in the writeup.
- 2026-05-31: Grading changed from `0/0` to `78/86`, marked reconstructable, and attached to [UID:0000BO][RankingEventScrollPane](by-class/RankingEventScrollPane.md).
  - Before: the page contained useful layout evidence but remained unevaluated to validator/stat tooling.
  - After: the score reflects IDA-verified vtable views, `0x110` child allocation, local field offsets, scroll-part state, and matching child method evidence while keeping final field names below final-audit status.
  - Evidence: IDA MCP `lookup_funcs`, vtable dword inspection, raw disassembly at unmodeled helper starts, decompilation of `0x00459a60`, `0x0045ac10`, and `0x0045ae30`, plus existing linked child memory pages.
