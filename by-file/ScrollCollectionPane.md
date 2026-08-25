*** UID:0000NG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/core/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ScrollCollectionPane

## Status

- Confidence: very strong for class behavior, CollectionPane construction/callbacks, exact split, natural layout, vtable ownership, and dedicated `ui/core` source/header placement; strong for inferred source spellings.
- Accepted module folder: `NexusTK/ui/core/`.
- Accepted source/header: `NexusTK/ui/core/ScrollCollectionPane.cpp` and `ScrollCollectionPane.h`.
- Evidence basis: existing scrollbar notes from [UID:0000CL][ScrollNewGroupPane](by-class/ScrollNewGroupPane.md), direct child docs, and live IDA MCP vtable/layout/caller checks through 2026-06-14.

## Hypothesis

`ScrollCollectionPane` is a dedicated 272-byte / `0x110` `Pane`-derived EPF-backed scrollbar implementation in `ui/core`. `CollectionPane` constructs and consumes the control, but the class owns independent vtables, a closed method graph, natural tail layout, event/timer facets, and themed rendering; it therefore remains a dedicated source/header rather than collection-private or generic-ScrollBar code.

IDA still lacks modeled function objects and static entry routes for raw starts `0x00561e60`, `0x00561e90`, `0x00561f70`, `0x00561f90`, `0x00562e80`, `0x00562ef0`, and `0x00563200`, but exact child pages now preserve every bounded body and its no-route evidence. Generated output is complete: all nineteen exact child methods emit once under the dedicated class/file route, including hit-test, shared geometry, both raw interaction methods, drag/update helpers, and enum-typed `ResetScrollState()`. Older generated omissions are retained only in the historical change log below and are not current source blockers.

IDA MCP recheck on 2026-06-01 confirms this as a self-contained sibling themed scrollbar class rather than a collection-private helper or older `ScrollBar.cpp` merge: constructor `0x00561db0` installs `ScrollCollectionPane` vtables `0x00623fa4`, `0x00623ff0`, and `0x00624020`; `CollectionPane` calls only the constructor/range/position/show APIs; the internal hit-test, geometry, draw, highlight, drag, reset-state, and clear helpers call each other within `0x00561db0-0x0056325c`; and `0x00563260` is the next scrollbar class constructor.

2026-06-14 live IDA MCP on database `b001_0003gy` reconfirmed this file root as the current source container: `lookup_funcs` reports constructor `0x00561db0` size `0xa1`, hit-test `0x005628d0` size `0x31d`, raw helper starts at `0x00562e80`, `0x00562ef0`, and `0x00563200`, modeled drag helpers at `0x00562fb0` size `0xc0` and `0x00563070` size `0x18d`, and successor `0x00563260` size `0xa1`. Xrefs show the only constructor caller at `CollectionPane::CollectionPane` (`0x0056e9b6`), range/position/show calls from `CollectionPane`, and constructor vtable stores to `0x00623fa4`, `0x00623ff0`, and `0x00624020`.

## Historical Partial Contents (Superseded)

The following table is retained from the earlier six-child/partial-model state for audit history. It is superseded by the complete accepted inventory and routing that follows.

| Entity | Range | Historical file/state | Role at that pass |
| --- | --- | --- | --- |
| [UID:0000CG][ScrollCollectionPane](by-class/ScrollCollectionPane.md) | `0x00561db0-0x0056325c` | `class_ScrollCollectionPane.cpp` | Scrollbar constructor, range/position setters, input handling, paint, part-rect geometry, highlight state. |
| [UID:0003MX][0x00562e80-0x00562ef0.ScrollCollectionPaneSetHighlightedRegionRaw](by-memory/0x00562e80-0x00562ef0.ScrollCollectionPaneSetHighlightedRegionRaw.md) | `0x00562e80-0x00562ef0` | child method body | Source-ready `ScrollCollectionPane::SetHighlightedPart(ScrollCollectionPart part)` first-draft C++ under the current `ScrollCollectionPane.cpp` route; invalidates old/new part rectangles through `GetPartRect` / inherited `InvalidateRect`, stores `m_highlightPart`, and preserves the raw no-entrypoint caveat. |
| [UID:0003MY][0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw](by-memory/0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw.md) | `0x00562ef0-0x00562fb0` | child method body | Source-ready `ScrollCollectionPane::BeginPartInteraction(ScrollCollectionPart part, int mouseY, int mouseX)` first-draft C++ under the current `ScrollCollectionPane.cpp` route; forces thumb highlight when needed, initializes `m_thumbDragOffset`, stores `m_activePart`, calls `UpdateDragScroll`, schedules the 200 ms repeat update, and preserves the raw no-entrypoint caveat. |
| [UID:0001GW][0x00562fb0-0x00563070.ScrollCollectionPaneUpdateDragScroll](by-memory/0x00562fb0-0x00563070.ScrollCollectionPaneUpdateDragScroll.md) | `0x00562fb0-0x00563070` | child method body | Source-ready `ScrollCollectionPane::UpdateDragScroll()` first-draft C++ under the current `ScrollCollectionPane.cpp` route; updates active/highlight part state, handles direct thumb drags, and clears stale highlight state. |
| [UID:0001GX][0x00563070-0x005631fd.ScrollCollectionPaneUpdatePositionFromCursor](by-memory/0x00563070-0x005631fd.ScrollCollectionPaneUpdatePositionFromCursor.md) | `0x00563070-0x005631fd` | child method body | Source-ready `ScrollCollectionPane::UpdatePositionFromCursor(int localY, int localX)` first-draft C++ under the current `ScrollCollectionPane.cpp` route; uses thumb geometry, cursor/origin sentinel checks, `m_thumbDragOffset` y/x mapping, range scaling, and the `CollectionPane` owner callback. |
| [UID:0001GY][0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw](by-memory/0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw.md) | `0x00563200-0x0056325c` | child method body | Source-facing `ScrollCollectionPane::ResetScrollState()` raw helper; no IDA function/static route, but exact child C++ now emits through the class. |
| [UID:0001VZ][ScrollCollectionPaneLayout](by-type/by-struct/ScrollCollectionPaneLayout.md) | offsets `+0xfc` through `+0x108` | type docs | Orientation, position/range, enabled/highlight/active part, and drag offset fields. |
| [UID:0001YP][ScrollCollectionPaneVtables](by-type/by-vtable/ScrollCollectionPaneVtables.md) | vtables `0x00623fa4`, `0x00623ff0`, `0x00624020` | type docs | Primary, secondary, and tertiary pane views. |
| [UID:0001GU][0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion](by-memory/0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion.md) | `0x005628d0-0x00562bed` | child method body | Source-ready `ScrollCollectionPane::HitTestScrollRegion(int localY, int localX)` first-draft C++ under the current `ScrollCollectionPane.cpp` route; loops over the five `ScrollCollectionPart` values, handles cursor/origin sentinel state, builds vertical/horizontal part rectangles inline, and returns the first `PointInRect(localY, localX, &rect)` match or `kScrollCollectionPartNone`. |
| scroll resources | data globals | generated global-data aliases | `g_scrollBitmapResource`, `g_scrollThumbResource`, masks, blend modes, and size table. |

## Accepted Contents And Routing

- [UID:0000CG][ScrollCollectionPane](by-class/ScrollCollectionPane.md) owns the class CPP/H shell: includes, `ScrollCollectionPart`, natural fields, virtual declarations, and child insertion points. Its CPP imports `kScrollPanePartExtentBySkin` through `ScrollBar.h`; it does not own or redeclare that shared storage.
- Exact children at positions `5,10,12,14,16,18,20,22,24,26,28,30,40,45,50,60,70,80,90` own constructor, configuration, state, EventHandler, TimerHandler, paint, hit-test, geometry, interaction, drag, position callback, and reset definitions.
- Layout [UID:0001VZ][ScrollCollectionPaneLayout](by-type/by-struct/ScrollCollectionPaneLayout.md), vtable [UID:0001YP][ScrollCollectionPaneVtables](by-type/by-vtable/ScrollCollectionPaneVtables.md), and exact vtable-data [UID:0003CN][0x00623fa0-0x00624028.ScrollCollectionPaneVtableData](by-memory/0x00623fa0-0x00624028.ScrollCollectionPaneVtableData.md) are evidence/support pages and do not duplicate class source.
- `CollectionPane.cpp` is rejected because consumer calls do not establish implementation ownership. Generic `ScrollBar.cpp` is rejected as the home for `ScrollCollectionPane` methods because sibling scrollbar classes have independent vtables/ranges and no binary evidence merges their implementations; [UID:0000NF][ScrollBar](by-file/ScrollBar.md) nevertheless remains the correct owner of the one cross-family constant object imported by this file.
- Older possible-merge guidance remains below only as historical audit context. The current deterministic route is `NexusTK/ui/core/ScrollCollectionPane.{h,cpp}`.

## Imported ScrollBar Constant

- [UID:0003CQ][0x00624138-0x00624168.ScrollPaneScrollbarConstantData](by-memory/0x00624138-0x00624168.ScrollPaneScrollbarConstantData.md) owns the exact `0x00624144` object `const int kScrollPanePartExtentBySkin[3] = {38,38,38}` through UID0000NF. Generic, spell, group, collection, and inventory scrollbar code all reference that single address.
- This file's paint, hit-test, and part-rectangle children consume the table at `0x005622f7`, `0x005625f6`, `0x00562a5c`, and `0x00562d4b`, indexed by `m_scrollSkinIndex`. Consumption is a source dependency, not storage ownership.
- `ScrollCollectionPane.cpp` includes `ScrollBar.h`; `ScrollCollectionPane.h` carries no private duplicate declaration. This preserves one external definition in the current multi-file route while keeping all class methods in the dedicated class source.
- Historical accepted-contents wording that placed the `{38,38,38}` definition in this class file came from duplicate generated shell output. It is superseded by the exact one-address, 22-xref, cross-family ownership graph and remains rejected history rather than a second source object.

## Compiler ABI / Source File Boundary

The accepted file emits the ordinary `ScrollCollectionPane` class declaration and nineteen method definitions. It does not emit physical vtable or RTTI data. B002's independent UID0003CN audit resolves the exact compiler boundary:

- [UID:0003CN][0x00623fa0-0x00624028.ScrollCollectionPaneVtableData](by-memory/0x00623fa0-0x00624028.ScrollCollectionPaneVtableData.md) is exactly `0x88` bytes with primary, EventHandler, and TimerHandler COL/table views at complete-object offsets `+0`, `+0xa0`, and `+0xa4`.
- The three tables contain 18, 11, and 2 callable slots. Constructor [UID:0004X3][0x00561db0-0x00561e51.ScrollCollectionPaneConstructor](by-memory/0x00561db0-0x00561e51.ScrollCollectionPaneConstructor.md) is the sole writer of table bases `0x00623fa4`, `0x00623ff0`, and `0x00624020`, at `0x00561e01`, `0x00561e07`, and `0x00561e11`.
- Source-owned virtual bodies are exactly pointer/mouse [UID:0004XL][0x00561fb0-0x00562191.ScrollCollectionPaneHandlePointerOrMouseEvent](by-memory/0x00561fb0-0x00562191.ScrollCollectionPaneHandlePointerOrMouseEvent.md), key/text false-return [UID:0004XM][0x005621a0-0x005621a5.ScrollCollectionPaneHandleKeyOrTextEvent](by-memory/0x005621a0-0x005621a5.ScrollCollectionPaneHandleKeyOrTextEvent.md), timer [UID:0004XN][0x005621b0-0x005621e3.ScrollCollectionPaneOnTimer](by-memory/0x005621b0-0x005621e3.ScrollCollectionPaneOnTimer.md), and paint [UID:0004XO][0x005621f0-0x005628d0.ScrollCollectionPaneOnPaint](by-memory/0x005621f0-0x005628d0.ScrollCollectionPaneOnPaint.md). The remaining callable entries are inherited base methods or shared compiler deleting wrappers/adjustors.
- Shared wrapper `0x00421480` and `this-0xa0` / `this-0xa4` adjustors `0x004213f8` / `0x00421403` are reused across eight vtable families. They are not methods to place in this source file.
- The wrapper performs only inherited `Pane` teardown and optional scalar deletion. The best human-source reconstruction keeps the current implicit destructor behavior instead of adding an unsupported explicit empty destructor.
- UID0003CN and vtable support UID0001YP are intentionally nonreconstructable/nonemitting with blank formals. This file/class route is sufficient to regenerate them through the compiler.

Rejected source placements remain preserved: no `ScrollCollectionPaneVtableData.cpp`, literal function-pointer array, decorated RTTI source, covered-by placeholder, `CollectionPane.cpp` ownership, or broad `ScrollPaneReadOnlyData` source unit is warranted.

## Complete Method And Resource Inventory

| Position | UID | Method / role |
| ---: | --- | --- |
| 5 | [UID:0004X3][0x00561db0-0x00561e51.ScrollCollectionPaneConstructor](by-memory/0x00561db0-0x00561e51.ScrollCollectionPaneConstructor.md) | Constructor, Pane base, three facets, natural `0x110` initialization. |
| 10/12 | [UID:0004X4][0x00561e60-0x00561e87.ScrollCollectionPaneSetSkinIndexRaw](by-memory/0x00561e60-0x00561e87.ScrollCollectionPaneSetSkinIndexRaw.md), [UID:0004X6][0x00561e90-0x00561eb4.ScrollCollectionPaneSetScrollStyleRaw](by-memory/0x00561e90-0x00561eb4.ScrollCollectionPaneSetScrollStyleRaw.md) | Raw skin-word and style-byte setters; no static routes. |
| 14/16 | [UID:0004X7][0x00561ec0-0x00561f1b.ScrollCollectionPaneSetMaxRange](by-memory/0x00561ec0-0x00561f1b.ScrollCollectionPaneSetMaxRange.md), [UID:0004X8][0x00561f20-0x00561f47.ScrollCollectionPaneSetScrollPosition](by-memory/0x00561f20-0x00561f47.ScrollCollectionPaneSetScrollPosition.md) | Signed range clamp and signed position setter. |
| 18/20/22 | [UID:0004X9][0x00561f50-0x00561f6a.ScrollCollectionPaneEnable](by-memory/0x00561f50-0x00561f6a.ScrollCollectionPaneEnable.md), [UID:0004XA][0x00561f70-0x00561f8a.ScrollCollectionPaneDisableRaw](by-memory/0x00561f70-0x00561f8a.ScrollCollectionPaneDisableRaw.md), [UID:0004XB][0x00561f90-0x00561faa.ScrollCollectionPaneCanScrollRaw](by-memory/0x00561f90-0x00561faa.ScrollCollectionPaneCanScrollRaw.md) | Enable, raw Disable, and real raw `CanScroll`. |
| 24/26/28 | [UID:0004XL][0x00561fb0-0x00562191.ScrollCollectionPaneHandlePointerOrMouseEvent](by-memory/0x00561fb0-0x00562191.ScrollCollectionPaneHandlePointerOrMouseEvent.md), [UID:0004XM][0x005621a0-0x005621a5.ScrollCollectionPaneHandleKeyOrTextEvent](by-memory/0x005621a0-0x005621a5.ScrollCollectionPaneHandleKeyOrTextEvent.md), [UID:0004XN][0x005621b0-0x005621e3.ScrollCollectionPaneOnTimer](by-memory/0x005621b0-0x005621e3.ScrollCollectionPaneOnTimer.md) | Pointer/mouse, key/text false, and timer virtuals. |
| 30 | [UID:0004XO][0x005621f0-0x005628d0.ScrollCollectionPaneOnPaint](by-memory/0x005621f0-0x005628d0.ScrollCollectionPaneOnPaint.md) | Clip-aware SLIDEBG/SCRBUTT rendering with `SLIDEBG.PAL`/`BUTTON.PAL`. |
| 40/45 | [UID:0001GU][0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion](by-memory/0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion.md), [UID:0004XP][0x00562bf0-0x00562e77.ScrollCollectionPaneGetPartRect](by-memory/0x00562bf0-0x00562e77.ScrollCollectionPaneGetPartRect.md) | Five-part hit-test and shared rectangle geometry. |
| 50/60 | [UID:0003MX][0x00562e80-0x00562ef0.ScrollCollectionPaneSetHighlightedRegionRaw](by-memory/0x00562e80-0x00562ef0.ScrollCollectionPaneSetHighlightedRegionRaw.md), [UID:0003MY][0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw](by-memory/0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw.md) | Raw highlight transition and interaction/drag setup. |
| 70/80/90 | [UID:0001GW][0x00562fb0-0x00563070.ScrollCollectionPaneUpdateDragScroll](by-memory/0x00562fb0-0x00563070.ScrollCollectionPaneUpdateDragScroll.md), [UID:0001GX][0x00563070-0x005631fd.ScrollCollectionPaneUpdatePositionFromCursor](by-memory/0x00563070-0x005631fd.ScrollCollectionPaneUpdatePositionFromCursor.md), [UID:0001GY][0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw](by-memory/0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw.md) | Drag update, signed cursor-to-position callback, and raw state reset. |

## Historical Alternatives

- Earlier pages preserved a possible `ScrollBar.cpp` merge and `ui/controls` alternative because only six child bodies and partial raw-function modeling were available.
- The complete split, three class-specific vtables, dedicated file page, natural class declaration, and closed caller/helper graph supersede those active uncertainties. The alternatives are retained here as rejected history rather than deleted.

## Score Rationale

Completion is `91` because the page now records the accepted folder/source/header, complete class shell, all nineteen ordered exact children, natural layout/vtable support, caller/callback direction, event/timer/geometry/render responsibilities, resource identities, and rejected alternatives.

Confidence is `92` because class [UID:0000CG][ScrollCollectionPane](by-class/ScrollCollectionPane.md) and aggregate [UID:0001GT][0x00561db0-0x0056325c.ScrollCollectionPane](by-memory/0x00561db0-0x0056325c.ScrollCollectionPane.md) are `93/93`, all method bodies and padding are split, vtables and layout agree, and generated CPP/H now use this route. Original filename/spellings and rebuilt-binary comparison remain unavailable, so this is below final-audit level.

## Cross-References

- [UID:0000CG][ScrollCollectionPane](by-class/ScrollCollectionPane.md)
- [UID:0001GT][0x00561db0-0x0056325c.ScrollCollectionPane](by-memory/0x00561db0-0x0056325c.ScrollCollectionPane.md)
- [UID:0001VZ][ScrollCollectionPaneLayout](by-type/by-struct/ScrollCollectionPaneLayout.md)
- [UID:0001YP][ScrollCollectionPaneVtables](by-type/by-vtable/ScrollCollectionPaneVtables.md)
- [UID:0001GU][0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion](by-memory/0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion.md)
- [UID:0001GV][0x00562e80-0x00562fb0.ScrollCollectionPaneHighlightRawHelpers](by-memory/0x00562e80-0x00562fb0.ScrollCollectionPaneHighlightRawHelpers.md)
- [UID:0003MX][0x00562e80-0x00562ef0.ScrollCollectionPaneSetHighlightedRegionRaw](by-memory/0x00562e80-0x00562ef0.ScrollCollectionPaneSetHighlightedRegionRaw.md)
- [UID:0003MY][0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw](by-memory/0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw.md)
- [UID:0001GW][0x00562fb0-0x00563070.ScrollCollectionPaneUpdateDragScroll](by-memory/0x00562fb0-0x00563070.ScrollCollectionPaneUpdateDragScroll.md)
- [UID:0000IC][CollectionPane](by-file/CollectionPane.md)
- [UID:0000CL][ScrollNewGroupPane](by-class/ScrollNewGroupPane.md)
- [UID:0000NF][ScrollBar](by-file/ScrollBar.md)

## Changes

- 2026-07-30 B002 accepted UID0003CQ support synchronization:
  - Changed the accepted contents from a class-owned extent-table definition to an imported `ScrollBar.h` dependency, with exact object/value, four class-consumer xrefs, cross-family ownership, and one-definition reasoning.
  - Preserved the dedicated `ScrollCollectionPane.{h,cpp}` method route, class contents, compiler/source boundary, rejected broad method merge, and `91/92` score.

- 2026-07-26 B002 accepted UID0003CN implementation callback:
  - Added exact physical/source boundary evidence for the three COL/table views, 18/11/2 slot counts, sole constructor stores, four source-owned overrides, inherited/shared compiler entries, and implicit-destructor inference.
  - Confirmed `NexusTK/ui/core/ScrollCollectionPane.{h,cpp}` remains unchanged as the sole human source route while UID0003CN/UID0001YP become compiler-only nonemitters.
  - Preserved rejection of literal vtable/RTTI source, covered-by markers, new ABI translation units, broad aggregate ownership, and class-specific source names for shared compiler thunks.

- 2026-07-26 B005 accepted UID0001GT implementation callback:
  - Before: `86/85`, dedicated path only a hypothesis, possible `ScrollBar.cpp` merge active, partial six-child inventory, and no complete header/source topology.
  - Changed to: `91/92`, accepted `NexusTK/ui/core/ScrollCollectionPane.{h,cpp}` route, complete class/header contents, nineteen ordered method children, resource and layout/vtable support, and rejected-alternative history.
  - Evidence: accepted B005 report plus validator-generated current ScrollCollectionPane CPP/H.

- 2026-06-27 B006 `HitTestScrollRegion` support sync:
  - Before: this file page listed [UID:0001GU][0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion](by-memory/0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion.md) as an omitted scoped method and described the `0x005628d0` helper as called by generated code but not emitted.
  - Changed to: hypothesis, proposed contents, and score rationale now record [UID:0001GU][0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion](by-memory/0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion.md) as source-ready first-draft `ScrollCollectionPane::HitTestScrollRegion(int localY, int localX)` C++ at position `40` under the current `ScrollCollectionPane.cpp` route. Score remains `86/85` because final standalone `ScrollCollectionPane.cpp` versus possible [UID:0000NF][ScrollBar](by-file/ScrollBar.md) placement is still the file-level cap.
  - Evidence: accepted B006 report `tools/leaser/Agents/Agent-B006/research/0001GU-ScrollCollectionPaneHitTestScrollRegion-source-quality.md` and implemented child page; live MCP session `b001_000241_20260627` reconfirmed the hit-test boundary, caller pair, inline geometry, accepted aliases, and sibling `GetPartRect` relationship.
- 2026-06-27 B002 `SetHighlightedPart` / `BeginPartInteraction` support sync:
  - Before: this file page mentioned the `0x00562e80`/`0x00562ef0` raw generated-output gaps but did not record the exact raw children as source-ready emitted child methods.
  - Changed to: proposed contents and source notes now record [UID:0003MX][0x00562e80-0x00562ef0.ScrollCollectionPaneSetHighlightedRegionRaw](by-memory/0x00562e80-0x00562ef0.ScrollCollectionPaneSetHighlightedRegionRaw.md) as `ScrollCollectionPane::SetHighlightedPart(ScrollCollectionPart part)` and [UID:0003MY][0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw](by-memory/0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw.md) as `ScrollCollectionPane::BeginPartInteraction(ScrollCollectionPart part, int mouseY, int mouseX)` under the current `ScrollCollectionPane.cpp` route. Score remains `86/85` because final standalone `ScrollCollectionPane.cpp` versus [UID:0000NF][ScrollBar](by-file/ScrollBar.md) placement is still the file-level cap.
  - Evidence: accepted B002 report `tools/leaser/Agents/Agent-B002/research/0001GV-ScrollCollectionPaneHighlightRawHelpers-source-quality.md` and implemented child pages; live MCP session `80de0a67` preserved the no-function/no-static-route caveat while supporting exact child C++ through the class/file emitter chain.
- 2026-06-26 B001 `UpdatePositionFromCursor` implementation:
  - Before: this file page listed the class helper island but did not record [UID:0001GX][0x00563070-0x005631fd.ScrollCollectionPaneUpdatePositionFromCursor](by-memory/0x00563070-0x005631fd.ScrollCollectionPaneUpdatePositionFromCursor.md) as source-ready emitted child code.
  - Changed to: proposed contents and source notes now record `ScrollCollectionPane::UpdatePositionFromCursor(int localY, int localX)` as first-draft C++ under the current `ScrollCollectionPane.cpp` route, while preserving the possible later [UID:0000NF][ScrollBar](by-file/ScrollBar.md) merge caveat.
  - Evidence: accepted B001 report `tools/leaser/Agents/Agent-B001/research/0001GX-ScrollCollectionPaneUpdatePositionFromCursor-source-quality.md` and [UID:0001GX][0x00563070-0x005631fd.ScrollCollectionPaneUpdatePositionFromCursor](by-memory/0x00563070-0x005631fd.ScrollCollectionPaneUpdatePositionFromCursor.md) implementation; live MCP session `80de0a67` reconfirmed target boundary, callers/callees, branch math, and source-ready helper/field names.
- 2026-06-25 B014 source-quality implementation:
  - Before: this file page still used clear-helper wording for the terminal raw body and did not list the now-emitting exact child [UID:0001GY][0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw](by-memory/0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw.md).
  - Changed to: source notes and proposed contents now record `ScrollCollectionPane::ResetScrollState()` for [UID:0001GY][0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw](by-memory/0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw.md), while preserving the unresolved standalone `ScrollCollectionPane.cpp` versus possible `ScrollBar.cpp` migration caveat.
  - Evidence: B014 MCP session `80de0a67` and PE route scan kept the no-function/no-static-route caveat but supported exact child C++ through the class emitter.
- 2026-06-13 C001 Goal 2 barrier repair:
  - Before: this file page listed the `ScrollCollectionPane` executable aggregate as `0x00561db0-0x0056325b`, matching the stale by-memory filename that crossed the exact clear-highlight child.
  - Changed to: proposed contents and cross-reference now use `0x00561db0-0x0056325c`; source-file score is unchanged because the standalone-vs-`ScrollBar` module caveat still needs a broader scrollbar pass.
  - Evidence: live IDA MCP on session `a002_batch_clear_timer` verified the clear-highlight helper's last byte is `retn` at `0x0056325b`, padding begins at `0x0056325c`, and `sub_563260` starts the next scrollbar class at `0x00563260`.
- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `82` and confidence to `76`.
  - Evidence: document captures class role, proposed contents, layout/vtable refs, raw/helper gaps, migration notes, and generic-scrollbar caveats; confidence remains limited by unresolved standalone-vs-ScrollBar source placement and partial IDA function modeling.
- 2026-06-14 A001 Goal 2 file-parent refresh:
  - Before: `82/82`; the class/type children were stronger than the file page and the migration note still used old dry-run wording.
  - Changed to: `86/85`; current file parent retained as `ui/core/ScrollCollectionPane.cpp`, with an explicit `ScrollBar.cpp` caveat and no final C++.
  - Evidence: live IDA MCP database `b001_0003gy` reconfirmed constructor/setter/helper/successor boundaries, the sole `CollectionPane` allocation/enabling caller path, setter callback xrefs, vtable-store xrefs, raw helper no-function status, clear-highlight tail bytes, and a unique full-range signature for `0x00561db0-0x0056325c`.
