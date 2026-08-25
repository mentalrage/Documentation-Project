*** UID:0000KB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/inventory/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# InventoryScrollPane

## NewInventoryPane Consumer Synchronization - 2026-08-16

- This remains the standalone `NexusTK/ui/inventory/InventoryScrollPane.cpp/.h` source root with its existing 19 definitions.
- [UID:000093][NewInventoryPane](by-class/NewInventoryPane.md) constructs the sole observed instance, owns its pointer, inserts/removes it as a child pane, reads its private signed range/position, and receives `OnScrollPositionChanged`.
- The exact formal-H friendship in [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md) legalizes those private reads without changing ownership, visibility, method bodies, or this file's `90/92` score.
- The older private-fold proposal remains superseded history: constructor consumption and callbacks do not override the complete distant island, dedicated layout/vtables, and standalone generated pair.

## UID0000KA Whole-File Boundary - 2026-08-15

The exhaustive InventoryPane.cpp audit proves `[0x00563260,0x0056470c)` is the separate `ScrollInventoryPane` family and a private/companion route of `NewInventoryPane`, not a legacy `InventoryPane` or `InventoryPane2` source island. Its constructor has the sole direct NewInventoryPane relationship, its distant executable range and primary/secondary/tertiary vtables remain independent, and its EPF-backed track/thumb/arrow/timer/reset behavior does not enter the 28-definition UID0000KA map.

The former question of standalone `InventoryScrollPane.cpp` versus a private fold into `NewInventoryPane.cpp` is retained as historical audit context; the exhaustive file audit resolves standalone `InventoryScrollPane.cpp/.h`. The UID0000KA conclusion remains exact exclusion: no scrollbar definition, compiler body, or data object may emit into `InventoryPane.cpp`. The path and file owner remain unchanged.

## Status

- Confidence: very strong for the complete 19-method source island, exact boundaries, layout/vtables, standalone module placement, and the constructor/callback consumer relationship.
- Accepted module pair: `ui/inventory/InventoryScrollPane.cpp` and `ui/inventory/InventoryScrollPane.h`, containing the `ScrollInventoryPart` enum and `ScrollInventoryPane` class.
- Projected reconstruction folder: `NexusTK/ui/inventory/`
- Evidence basis: live IDA MCP lookup/caller checks on 2026-05-24, 2026-06-05, 2026-06-11, 2026-06-14, and B007 session `aa3930bd` on 2026-07-04.

## File Role

`InventoryScrollPane.cpp/.h` owns the item-inventory private scrollbar. It handles EPF-backed track/thumb geometry, signed range and position, mouse/timer repeat behavior, highlight/active/drag state, owner callback, and reset-to-idle state for the newer item inventory UI.

`NewInventoryPane` is the sole known constructor consumer and receives `OnScrollPositionChanged`, but the closed class island, three independent vtables, complete header, and accepted equal-length specialized sibling make it a consumer rather than source owner. The former private-fold hypothesis is retained below only as corrected historical evidence.

## Historical Sampled Contents (Superseded)

This early table sampled the island before exact child splitting and used the stale `UpdateFromDrag(int localX,int localY)` identity. It is preserved only as historical context; the accepted exhaustive inventory follows below.

| Range | Current method family | Notes |
| --- | --- | --- |
| `0x00563260-0x00563300` | constructor / [UID:0001GZ][0x00563260-0x0056470c.ScrollInventoryPane](by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md) aggregate | Initializes orientation and scrollbar state. The full UID0001GZ executable aggregate is now `91/93` and marker-only: exact method bodies emit from exact child pages routed through [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md), not as one broad aggregate body. |
| `0x00563370-0x00563419` | range/position/enable helpers | Clamps scroll range and position; invalidates affected pane regions. |
| `0x00563460-0x00563692` | mouse/timer handlers | Handles drag/click interactions and auto-repeat. |
| `0x005636a0-0x00563d7f` | paint | Draws `SLIDEBG.EPF`/`SCRBUTT.EPF` track, thumb, and buttons. |
| `0x005640a0-0x0056439f` | region/highlight helpers | Computes arrow/track/thumb rectangles and updates highlighted part. |
| `0x00564520-0x005646ad` | [UID:0001H0][0x00564520-0x005646ad.ScrollInventoryPaneUpdateFromDrag](by-memory/0x00564520-0x005646ad.ScrollInventoryPaneUpdateFromDrag.md) | Superseded historical `ScrollInventoryPane::UpdateFromDrag(int localX, int localY)` approximation. The accepted source is `UpdatePositionFromCursor(int localY, int localX)`, retains the exact geometry/callback behavior, and emits through the resolved standalone module. |
| `0x005646b0-0x0056470c` | [UID:0001H1][0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw](by-memory/0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw.md) | Source-facing `ScrollInventoryPane::ResetScrollState()`: source-shaped raw helper with no direct static route, no VA/RVA literal, no external branch into span, no vtable slot, and rejected unaligned pointer artifacts; removes pending timers through the class `+0xa4` TimerHandler view, clears `m_activePart`, invalidates/clears old `m_highlightPart`, and is directly owned/emitted by class [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md) with this file as source-file route. |
| [UID:0001W0][ScrollInventoryPaneLayout](by-type/by-struct/ScrollInventoryPaneLayout.md) | offsets `+0xf8` through `+0x10f` | Packed scroll style, orientation, current/range words, enabled/hover/active state, and drag point. |
| [UID:0001YQ][ScrollInventoryPaneVtables](by-type/by-vtable/ScrollInventoryPaneVtables.md) | `0x0062402c`, `0x00624078`, `0x006240a8` | Three pane views for paint, mouse input, and timer/repeat callbacks. |

## Boundary Notes

This is not the generic [UID:0000NF][ScrollBar](by-file/ScrollBar.md) module. It is a feature-specific companion used by [UID:0000LS][NewInventoryPane](by-file/NewInventoryPane.md) unless later evidence proves reuse outside item inventory.

Recovered source output contains polluted helper labels from fitting-room/ranking-event/control code. Treat those as shared render/control helper names, not ownership evidence.

Historical generated-metadata checkpoint: an older snapshot reported `vtable_count: 0` even though IDA confirmed three `ScrollInventoryPane` vtable bases. That stale count is superseded by the accepted three-table inventory in [UID:0001YQ][ScrollInventoryPaneVtables](by-type/by-vtable/ScrollInventoryPaneVtables.md) and is not current data debt.

## 2026-06-14 C001 IDA MCP Refresh

Live IDA 9.1 evidence on session `a001_goal2_class_batch` reconfirmed the file-root grouping without closing the standalone-versus-folded source question:

- `lookup_funcs` reports modeled scrollbar bodies at `0x00563260` (`0xa1`), `0x00563370` (`0x5b`), `0x005633d0` (`0x27`), `0x00563400` (`0x1a`), `0x00563460` (`0x1e1`), `0x00563660` (`0x33`), `0x005636a0` (`0x6e0`), `0x005640a0` (`0x287`), `0x00564460` (`0xc0`), and `0x00564520` (`0x18d`), with the next neighboring scrollbar-class constructor at `0x00564710`.
- IDA still reports `0x00564330`, `0x005643a0`, and `0x005646b0` as non-function raw helper starts, matching the aggregate memory page's reset/highlight caveat.
- `xrefs_to 0x00563260` reports the single constructor call at `0x004eb4e4` inside `0x004eb420`. That relationship historically motivated a private [UID:0000LS][NewInventoryPane](by-file/NewInventoryPane.md) fold hypothesis, but the hypothesis is superseded; standalone `InventoryScrollPane.cpp/.h` placement is accepted.
- `xrefs_to` the three vtable bases reports only the constructor stores at `0x005632b1`, `0x005632b7`, and `0x005632c1`, matching [UID:0001YQ][ScrollInventoryPaneVtables](by-type/by-vtable/ScrollInventoryPaneVtables.md).
- The allocation size remains `0x110` / `272` bytes (verified with `tools/int_convert.py`), matching [UID:0001W0][ScrollInventoryPaneLayout](by-type/by-struct/ScrollInventoryPaneLayout.md).

## 2026-06-18 B003 Reset Helper Route

[UID:0001H1][0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw](by-memory/0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw.md) is rerouted from direct file ownership to direct class ownership [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md). This file remains the accepted standalone generated source route for that class. B003 confirmed the raw helper has exact boundary bytes, no direct caller, no VA/RVA literal, no external direct branch into the span, no vtable slot, and no real interior pointer-table route; the only pointer-looking hits were unaligned instruction-byte artifacts. The helper body and dependencies support `ScrollInventoryPane::ResetScrollState()` with `m_highlightPart`, `m_activePart`, the `+0xa4` TimerHandler view, `GetPartRect`, and Pane invalidation. The former possible fold into [UID:0000LS][NewInventoryPane](by-file/NewInventoryPane.md) is retained only as a superseded historical source-organization hypothesis; standalone `InventoryScrollPane.cpp/.h` placement is accepted.

## 2026-07-04 B007 Aggregate Marker Route

[UID:0001GZ][0x00563260-0x0056470c.ScrollInventoryPane](by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md) is now `91/93` and emits only a formal no-standalone-body marker through [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md). This replaces stale blank/old-parent-blocker wording: the aggregate already has direct class owner/emitter routing, while exact method source belongs on exact child pages such as [UID:0001H1][0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw](by-memory/0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw.md).

B007's `aa3930bd` MCP pass reconfirmed active/healthy NexusTK IDB provenance, modeled functions and raw helper starts inside the aggregate, the single constructor caller at `0x004eb4e4`, the `272`-byte allocation/caller context in `NewInventoryPane::NewInventoryPane`, constructor vtable refs to `0x0062402c/0x00624078/0x006240a8`, UID0001H0 dispatcher/update xrefs at `0x005644bb/0x005644e4`, zero xrefs to `0x005646b0`, boundary bytes/padding before `0x00564710`, and zero VA/RVA dword hits for the target/update/reset starts. Direct `NewInventoryPane` ownership, generic `ScrollBar` ownership, no-owner/non-emitting treatment, broad aggregate body, `[[CHILDREN]]` insertion, and copied child C++ remain rejected. The historical B007 checkpoint intentionally left UID0001H0 source/C++ untouched for B008; B008 has now populated UID0001H0 on the exact child page.

## 2026-07-04 B008 UID0001H0 Source-Ready Route

[UID:0001H0][0x00564520-0x005646ad.ScrollInventoryPaneUpdateFromDrag](by-memory/0x00564520-0x005646ad.ScrollInventoryPaneUpdateFromDrag.md) is now `91/93` and emits the accepted `ScrollInventoryPane::UpdatePositionFromCursor(int localY, int localX)` definition through [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md). The standalone InventoryScrollPane route is current; the former possible private fold into [UID:0000LS][NewInventoryPane](by-file/NewInventoryPane.md) is retained only as historical file-organization evidence.

B008's accepted report and implementation record `aa3930bd` MCP evidence for exact range `0x00564520-0x005646ad`, size `0x18d`, dispatcher callers `0x005644bb/0x005644e4`, helper callees `0x005640a0`, `0x004a9090`, `0x005447c0`, callback `0x004eba00`, fields `+0xfc/+0xfe/+0x100/+0x108/+0x10c`, three `0xcc` bytes before raw reset start `0x005646b0`, and no xrefs to the reset start. The update helper rejects direct `NewInventoryPane` method ownership, generic scrollbar ownership, no-owner/no-code treatment, sibling reset merge, and padding/range extension.

## Accepted Whole-File Closure

- Exact source island: `[0x00563260,0x0056470c)`, length `0x14ac` / 5292 bytes, SHA256 `0a13dff3ec18ec9fbe5a5398e08cd6cd1a669ecfa3665ed18025b07c6949d443`.
- Exact inventory: nineteen authored methods, sixteen alignment spans, one natural `0x110` layout, one six-value enum, three compiler-generated vtables, five shared data/resource dependencies, and successor `0x00564710` excluded.
- Sibling comparison: the equal-length ScrollCollectionPane island matches 5138/5292 bytes; only 154 bytes in 77 runs differ (`97.090%`), supporting the accepted human C++03 source shape while retaining Inventory-specific owner callback and vtable/resource addresses.
- Source root: this file -> [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md) -> nineteen exact children. UID0001GZ is marker-only and never duplicates definitions.
- Header closure: UID0000CK owns `InventoryScrollPane.h` with `ScrollInventoryPart`, all public/protected/private declarations, and exact tail fields. No literal vtable/RTTI/EH product, padding, duplicate shared constant/resource, or invented destructor is emitted.

## Corrected Source Contract

- The complete file route remains UID0000KB -> UID0000CK -> nineteen exact method children. UID0001GZ remains marker-only; vtables, alignment and shared resource/global objects remain non-source or externally owned.
- A source-contract audit found that the earlier generated `94/95` checkpoint used project-incompatible APIs: Pane-local `m_bounds`, direct Event payload aliases, `kEventPointerMove`, free EPF initialization, an unqualified fill helper, a four-argument render wrapper, and incomplete EventMan/Pane/NewInventoryPane headers.
- The accepted callback replaces those with inherited `GrafPort::m_visibleBounds`, `Event::m_payload.m_pointer`, `kEventCursorMove`, `EPFTileContext::Initialize`, `g_pfnFillRect`, six-argument GrafPort `RenderTileFrame`, EventMan `GetCursorPosition(Point *)`, Pane mouse-capture declarations, and the complete normal 0x158 NewInventoryPane declaration/callback.
- This correction does not change binary ranges, ownership, source placement, child order, behavior, clone metrics, shared constant/resource ownership, or compiler exclusions. The invalid generated bodies remain historical evidence rather than current source.
- Dated generated-history receipts: command `000000023807` at `2026-08-15T00:17:34-04:00` produced the incomplete pre-callback output with only UID0001H0/UID0001H1 source plus marker material and no `InventoryScrollPane.h`; command `000000024087` at `2026-08-15T06:39:15-04:00` closed the 19-definition inventory and supplied the BlackHole-equivalent header-creation closure by generating the previously absent complete `InventoryScrollPane.h` from the accepted H channel; command `000000024668` at `2026-08-16T01:38:06-04:00` revalidated the corrected CPP/H contract after the Gate 2A prose repair. These are dated historical receipts, not permanent current generated authority; any later gate must reread validator-owned output dynamically.
- Third-party import disposition: no third-party import applies. `InventoryScrollPane.cpp/.h` is project-owned reconstructed NexusTK UI source, not a vetted static third-party embed from `third_party_embeds`, so no import directive or third-party source replacement is valid for UID0000KB.

### Exact Method Children

1. [UID:00051C][0x00563260-0x00563301.ScrollInventoryPaneConstructor](by-memory/0x00563260-0x00563301.ScrollInventoryPaneConstructor.md), `0x00563260-0x00563301`.
2. [UID:00051D][0x00563310-0x00563337.ScrollInventoryPaneSetSkinIndexRaw](by-memory/0x00563310-0x00563337.ScrollInventoryPaneSetSkinIndexRaw.md), `0x00563310-0x00563337`, retained raw/no-start-route.
3. [UID:00051E][0x00563340-0x00563364.ScrollInventoryPaneSetScrollStyleRaw](by-memory/0x00563340-0x00563364.ScrollInventoryPaneSetScrollStyleRaw.md), `0x00563340-0x00563364`, retained raw/no-start-route.
4. [UID:00051F][0x00563370-0x005633cb.ScrollInventoryPaneSetMaxRange](by-memory/0x00563370-0x005633cb.ScrollInventoryPaneSetMaxRange.md), `0x00563370-0x005633cb`.
5. [UID:00051G][0x005633d0-0x005633f7.ScrollInventoryPaneSetScrollPosition](by-memory/0x005633d0-0x005633f7.ScrollInventoryPaneSetScrollPosition.md), `0x005633d0-0x005633f7`.
6. [UID:00051I][0x00563400-0x0056341a.ScrollInventoryPaneEnable](by-memory/0x00563400-0x0056341a.ScrollInventoryPaneEnable.md), `0x00563400-0x0056341a`.
7. [UID:00051J][0x00563420-0x0056343a.ScrollInventoryPaneDisableRaw](by-memory/0x00563420-0x0056343a.ScrollInventoryPaneDisableRaw.md), `0x00563420-0x0056343a`, retained raw/no-start-route.
8. [UID:00051K][0x00563440-0x0056345a.ScrollInventoryPaneCanScrollRaw](by-memory/0x00563440-0x0056345a.ScrollInventoryPaneCanScrollRaw.md), `0x00563440-0x0056345a`, retained raw/no-start-route.
9. [UID:00051L][0x00563460-0x00563641.ScrollInventoryPaneHandlePointerOrMouseEvent](by-memory/0x00563460-0x00563641.ScrollInventoryPaneHandlePointerOrMouseEvent.md), `0x00563460-0x00563641`.
10. [UID:00051M][0x00563650-0x00563655.ScrollInventoryPaneHandleKeyOrTextEvent](by-memory/0x00563650-0x00563655.ScrollInventoryPaneHandleKeyOrTextEvent.md), `0x00563650-0x00563655`.
11. [UID:00051N][0x00563660-0x00563693.ScrollInventoryPaneOnTimer](by-memory/0x00563660-0x00563693.ScrollInventoryPaneOnTimer.md), `0x00563660-0x00563693`.
12. [UID:00051O][0x005636a0-0x00563d80.ScrollInventoryPaneOnPaint](by-memory/0x005636a0-0x00563d80.ScrollInventoryPaneOnPaint.md), `0x005636a0-0x00563d80`.
13. [UID:00051P][0x00563d80-0x0056409d.ScrollInventoryPaneHitTestScrollRegion](by-memory/0x00563d80-0x0056409d.ScrollInventoryPaneHitTestScrollRegion.md), `0x00563d80-0x0056409d`.
14. [UID:00051Q][0x005640a0-0x00564327.ScrollInventoryPaneGetPartRect](by-memory/0x005640a0-0x00564327.ScrollInventoryPaneGetPartRect.md), `0x005640a0-0x00564327`.
15. [UID:00051R][0x00564330-0x005643a0.ScrollInventoryPaneSetHighlightedPartRaw](by-memory/0x00564330-0x005643a0.ScrollInventoryPaneSetHighlightedPartRaw.md), `0x00564330-0x005643a0`, retained raw/no-start-route.
16. [UID:00051S][0x005643a0-0x0056445f.ScrollInventoryPaneBeginPartInteractionRaw](by-memory/0x005643a0-0x0056445f.ScrollInventoryPaneBeginPartInteractionRaw.md), `0x005643a0-0x0056445f`, retained raw/no-start-route.
17. [UID:00051T][0x00564460-0x00564520.ScrollInventoryPaneUpdateDragScroll](by-memory/0x00564460-0x00564520.ScrollInventoryPaneUpdateDragScroll.md), `0x00564460-0x00564520`.
18. [UID:0001H0][0x00564520-0x005646ad.ScrollInventoryPaneUpdateFromDrag](by-memory/0x00564520-0x005646ad.ScrollInventoryPaneUpdateFromDrag.md), `0x00564520-0x005646ad`, with project-order `localY,localX` and callback only on changed value.
19. [UID:0001H1][0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw](by-memory/0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw.md), `0x005646b0-0x0056470c`, retained raw/no-start-route.

### Exact Alignment And Dependency Boundaries

- The sixteen non-source spans are `0x563301-0x563310`, `0x563337-0x563340`, `0x563364-0x563370`, `0x5633cb-0x5633d0`, `0x5633f7-0x563400`, `0x56341a-0x563420`, `0x56343a-0x563440`, `0x56345a-0x563460`, `0x563641-0x563650`, `0x563655-0x563660`, `0x563693-0x5636a0`, `0x56409d-0x5640a0`, `0x564327-0x564330`, `0x56445f-0x564460`, `0x5646ad-0x5646b0`, and successor alignment `0x56470c-0x564710`.
- Shared `kScrollPanePartExtentBySkin[3] = {38,38,38}` at `0x00624144` remains owned by [UID:0000NF][ScrollBar](by-file/ScrollBar.md). Paint imports shared `SLIDEBG.EPF`, `SLIDEBG.PAL`, `SCRBUTT.EPF`, and `BUTTON.PAL` resource names without defining them.
- Primary/EventHandler/TimerHandler vtables at `0x0062402c/0x00624078/0x006240a8` are compiler products described by [UID:0001YQ][ScrollInventoryPaneVtables](by-type/by-vtable/ScrollInventoryPaneVtables.md), not source arrays.

## Strict-Gate Status

This file is `90/92`: exact whole-file boundaries/hash, all nineteen methods, all sixteen gaps, standalone CPP/H route, natural layout, vtables, shared dependencies, consumer/callback relationship, corrected dependency/API contract, raw no-route caveats and successor exclusion are resolved. The earlier `94/95` source-complete checkpoint is historical because its generated bodies used rejected project APIs. Validator command `000000024570` completed coherent generated CPP/H verification; exact original spellings, raw-start static-liveness limits, and the absent rebuilt-binary comparison remain before a source-complete score can be restored.

## Cross-References

- [UID:0000KA][InventoryPane](by-file/InventoryPane.md)
- [UID:0000LS][NewInventoryPane](by-file/NewInventoryPane.md)
- [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md)
- [UID:0001GZ][0x00563260-0x0056470c.ScrollInventoryPane](by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md)
- [UID:0001W0][ScrollInventoryPaneLayout](by-type/by-struct/ScrollInventoryPaneLayout.md)
- [UID:0001YQ][ScrollInventoryPaneVtables](by-type/by-vtable/ScrollInventoryPaneVtables.md)

## Changes

- 2026-08-15 B005 accepted UID0000KB implementation callback:
  - Raised `86/88` to `94/95` and resolved the standalone module pair instead of retaining a current fold ambiguity.
  - Added all nineteen exact method children, sixteen alignment spans, whole-island hash/clone metrics, full CPP/H ownership, class layout/vtables, shared resource/constant boundaries, negative evidence and successor exclusion.
  - Corrected `UpdateFromDrag(int localX,int localY)` to source-facing `UpdatePositionFromCursor(int localY,int localX)` and preserved the old name/order only in historical text.
- 2026-08-15 B005 source-contract callback:
  - Preserved the exhaustive standalone inventory while replacing rejected bounds, Event, rendering, cursor, capture and owner-callback declarations across exact emitters and natural header owners.
  - Historicalized the invalid `94/95` generated checkpoint and adopted `90/92`; validator command `000000024570` then completed coherent regenerated CPP/H and dependency-output physical verification.

- 2026-06-14 C001 Goal 2 by-file score refresh:
  - Before: `COMPLETION:85`, `CONFIDENCE:85`.
  - After: `COMPLETION:86`, `CONFIDENCE:88`.
  - Summary/evidence: live IDA MCP reconfirmed the modeled inventory-scrollbar function inventory, the raw non-function helper starts, the single `NewInventoryPane` constructor caller, constructor stores to all three vtable bases, and the `0x110` / `272`-byte object size (verified with `tools/int_convert.py`). No owner/emitter, path, or C++ reconstruction change was made because the original source split can still be either a standalone `InventoryScrollPane.cpp` or private `NewInventoryPane.cpp` support code.
- 2026-06-18 B003 support incorporation:
  - Updated the reset-helper proposed contents row and source-route section for [UID:0001H1][0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw](by-memory/0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw.md).
  - Evidence: B003 resolved direct class ownership, field/helper names, no-route evidence, rejected false pointer artifacts, and first-draft child C++ while keeping this file as the route and preserving the standalone-versus-folded source caveat.
- 2026-07-04 B007 UID0001GZ support incorporation:
  - Updated the aggregate/source-output note for [UID:0001GZ][0x00563260-0x0056470c.ScrollInventoryPane](by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md), which now routes through this file as a marker-only aggregate at `86/90`.
  - Evidence: B007 `aa3930bd` MCP recheck confirmed current IDB health, target function/raw inventory, one `NewInventoryPane` constructor caller, `272`-byte allocation/caller context, vtable refs, UID0001H0 xrefs, UID0001H1 no-xref state, boundary bytes/padding, generated Empty Emitter Marker state, and rejected direct owner/source-body alternatives.
- 2026-07-04 B008 UID0001H0 support incorporation:
  - Updated the proposed-contents row and source-route note for [UID:0001H0][0x00564520-0x005646ad.ScrollInventoryPaneUpdateFromDrag](by-memory/0x00564520-0x005646ad.ScrollInventoryPaneUpdateFromDrag.md), which now routes through this file as a source-ready exact child at `88/91`.
  - Evidence: B008 report SHA256 `69712D40417BB6D53A4351D1A350C5BCC1ED46F2CB06A8887B748A5E4E470908`, current target metadata/C++ insertion, exact range/caller/callee/field/callback/padding facts, and rejected direct `NewInventoryPane`, generic scrollbar, no-owner/no-code, sibling merge, and range-extension alternatives.
- 2026-06-05: Assigned projected reconstruction path `NexusTK/ui/inventory/` to resolve the by-file generated-root coverage error.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank even though the proposed source tree lists `InventoryScrollPane.cpp` under `ui/inventory/`.
  - After: set the validator path to `NexusTK/ui/inventory/` without changing completion/confidence or writing reconstruction C++.
  - Evidence: `by-project-structure/proposed-source-tree.md` places the item-inventory scrollbar file under `ui/inventory`, and live IDA MCP lookup on 2026-06-05 confirms the constructor anchor at `0x00563260` as a real function of size `0xa1`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:80`.
  - Summary/evidence: scrollbar role, range/position/mouse/timer/paint/highlight/drag helper groups, layout and vtable anchors, constructor caller, and feature-specific boundary are documented; confidence is capped by whether it was standalone or folded into `NewInventoryPane`.
- 2026-06-11 A008 Batch 155 strict-gate refresh:
  - Raised `84/80` to `85/85` so the direct [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md) parent chain can satisfy the temporary assignment rule.
  - Evidence: live IDA MCP rechecked the one direct constructor caller at `0x004eb4e4`, `NewInventoryPane` allocation of `272` bytes (`0x110`, verified with `int_convert.py`), constructor vtable stores to `0x0062402c/0x00624078/0x006240a8`, and the existing raw helper/reset caveats. Confidence remains capped by possible private folding into [UID:0000LS][NewInventoryPane](by-file/NewInventoryPane.md).
