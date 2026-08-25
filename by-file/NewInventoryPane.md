*** UID:0000LS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/inventory/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# NewInventoryPane
## Current Exhaustive Source Contract - 2026-08-16

- Canonical source root: `NexusTK/ui/inventory/NewInventoryPane.cpp`; canonical owner remains `FILE`.
- The source unit owns exactly 26 authored NewInventoryPane definitions in positions 10 through 260. [UID:000093][NewInventoryPane](by-class/NewInventoryPane.md) owns the complete `0x158` declaration and emits each exact child below.
- [UID:0000KB][InventoryScrollPane](by-file/InventoryScrollPane.md) remains a separate 19-definition companion source file. NewInventoryPane constructs and owns one ScrollInventoryPane instance and receives its callback, but does not absorb its definitions.
- [UID:00018L][0x004ede80-0x004edfa4.BackPaneHelpPacketDisplayV2](by-memory/0x004ede80-0x004edfa4.BackPaneHelpPacketDisplayV2.md) is a foreign physical interleave. Three switch tables, 27 in-family alignment spans, `nullsub_34`, two destructor adjustors, the scalar-deleting wrapper, vtable storage, and pooled literals are compiler/dead/data evidence rather than handwritten definitions.
- The generated source must contain all 26 definitions once, no Empty Emitter Marker, and no body from BackPane, InventoryPane2, compiler wrappers, tables, or padding.

## Exact Source Order

| Position | Child | Source identity | Role |
| ---: | --- | --- | --- |
| 10 | [UID:00053P][0x004eb420-0x004eb510.NewInventoryPaneConstructor](by-memory/0x004eb420-0x004eb510.NewInventoryPaneConstructor.md) | `NewInventoryPane` | constructor |
| 20 | [UID:00053Q][0x004eb510-0x004eb545.NewInventoryPaneDestructor](by-memory/0x004eb510-0x004eb545.NewInventoryPaneDestructor.md) | `~NewInventoryPane` | ordinary destructor |
| 30 | [UID:00053R][0x004eb550-0x004eb567.NewInventoryPaneOnActivate](by-memory/0x004eb550-0x004eb567.NewInventoryPaneOnActivate.md) | `OnActivate` | activation override |
| 40 | [UID:00053S][0x004eb580-0x004eb608.NewInventoryPaneUpdateRenderRegion](by-memory/0x004eb580-0x004eb608.NewInventoryPaneUpdateRenderRegion.md) | `UpdateRenderRegion` | render-region override |
| 50 | [UID:00053T][0x004eb610-0x004eb6b5.NewInventoryPaneSetBounds](by-memory/0x004eb610-0x004eb6b5.NewInventoryPaneSetBounds.md) | `SetBounds` | fixed bounds override |
| 60 | [UID:00053U][0x004eb6c0-0x004eb9f9.NewInventoryPaneRebuildInventoryList](by-memory/0x004eb6c0-0x004eb9f9.NewInventoryPaneRebuildInventoryList.md) | `RebuildInventoryList` | visible-slot and scroll synchronization |
| 70 | [UID:00053V][0x004eba00-0x004eba8d.NewInventoryPaneOnScrollPositionChanged](by-memory/0x004eba00-0x004eba8d.NewInventoryPaneOnScrollPositionChanged.md) | `OnScrollPositionChanged` | scrollbar callback |
| 80 | [UID:00053W][0x004eba90-0x004ebaf6.NewInventoryPaneAddToLayer](by-memory/0x004eba90-0x004ebaf6.NewInventoryPaneAddToLayer.md) | `AddToLayer` | layer insertion override |
| 90 | [UID:00053X][0x004ebb00-0x004ebb16.NewInventoryPaneRemoveFromLayer](by-memory/0x004ebb00-0x004ebb16.NewInventoryPaneRemoveFromLayer.md) | `RemoveFromLayer` | layer removal override |
| 100 | [UID:00053Y][0x004ebb20-0x004ec913.NewInventoryPaneOnPaint](by-memory/0x004ebb20-0x004ec913.NewInventoryPaneOnPaint.md) | `OnPaint` | complete renderer |
| 110 | [UID:00053Z][0x004ec920-0x004ecb44.NewInventoryPaneHandleKeyOrTextEvent](by-memory/0x004ec920-0x004ecb44.NewInventoryPaneHandleKeyOrTextEvent.md) | `HandleKeyOrTextEvent` | key/text override |
| 120 | [UID:000540][0x004ecb50-0x004ed9c4.NewInventoryPaneHandlePointerOrMouseEvent](by-memory/0x004ecb50-0x004ed9c4.NewInventoryPaneHandlePointerOrMouseEvent.md) | `HandlePointerOrMouseEvent` | complete pointer/mouse state machine |
| 130 | [UID:000541][0x004ed9f0-0x004edb62.NewInventoryPaneHandlePacketEvent](by-memory/0x004ed9f0-0x004edb62.NewInventoryPaneHandlePacketEvent.md) | `HandlePacketEvent` | packet/help override |
| 140 | [UID:000542][0x004edb70-0x004edcc5.NewInventoryPaneOnTimer](by-memory/0x004edb70-0x004edcc5.NewInventoryPaneOnTimer.md) | `OnTimer` | repeat timer override |
| 150 | [UID:000543][0x004edcd0-0x004edd39.NewInventoryPaneSendUseItemSlotPacket](by-memory/0x004edcd0-0x004edd39.NewInventoryPaneSendUseItemSlotPacket.md) | `SendUseItemSlotPacket` | private static packet helper |
| 160 | [UID:000544][0x004edd40-0x004eddc5.NewInventoryPaneSendDropItemPacket](by-memory/0x004edd40-0x004eddc5.NewInventoryPaneSendDropItemPacket.md) | `SendDropItemPacket` | private static packet helper |
| 170 | [UID:000545][0x004eddd0-0x004ede74.NewInventoryPaneSendItemToObjectPacket](by-memory/0x004eddd0-0x004ede74.NewInventoryPaneSendItemToObjectPacket.md) | `SendItemToObjectPacket` | private static retained packet helper |
| 180 | [UID:000546][0x004edfb0-0x004ee080.NewInventoryPaneGetButtonRect](by-memory/0x004edfb0-0x004ee080.NewInventoryPaneGetButtonRect.md) | `GetButtonRect` | file-local geometry helper |
| 190 | [UID:000547][0x004ee0a0-0x004ee13c.NewInventoryPaneBuildInventorySlotRect](by-memory/0x004ee0a0-0x004ee13c.NewInventoryPaneBuildInventorySlotRect.md) | `BuildInventorySlotRect` | private geometry member |
| 200 | [UID:000548][0x004ee140-0x004ee20b.NewInventoryPaneHitTestButton](by-memory/0x004ee140-0x004ee20b.NewInventoryPaneHitTestButton.md) | `HitTestButton` | file-local hit-test helper |
| 210 | [UID:000549][0x004ee230-0x004ee3b7.NewInventoryPaneHitTestInventorySlot](by-memory/0x004ee230-0x004ee3b7.NewInventoryPaneHitTestInventorySlot.md) | `HitTestInventorySlot` | private hit-test member |
| 220 | [UID:00054A][0x004ee3c0-0x004ee464.NewInventoryPaneResolveVisibleInventorySlot](by-memory/0x004ee3c0-0x004ee464.NewInventoryPaneResolveVisibleInventorySlot.md) | `ResolveVisibleInventorySlot` | private one-based slot mapper |
| 230 | [UID:00054B][0x004ee470-0x004ee4ee.NewInventoryPaneSendSwapItemPacket](by-memory/0x004ee470-0x004ee4ee.NewInventoryPaneSendSwapItemPacket.md) | `SendSwapItemPacket` | private static packet helper |
| 240 | [UID:00054C][0x004ee4f0-0x004ee56f.NewInventoryPaneBuildInventorySlotOrigin](by-memory/0x004ee4f0-0x004ee56f.NewInventoryPaneBuildInventorySlotOrigin.md) | `BuildInventorySlotOrigin` | private point helper |
| 250 | [UID:00054D][0x004ee570-0x004ee595.NewInventoryPaneStopActiveRepeatTimer](by-memory/0x004ee570-0x004ee595.NewInventoryPaneStopActiveRepeatTimer.md) | `StopActiveRepeatTimer` | private timer helper |
| 260 | [UID:00054E][0x004ee5a0-0x004ee643.NewInventoryPaneToggleExpandedMode](by-memory/0x004ee5a0-0x004ee643.NewInventoryPaneToggleExpandedMode.md) | `ToggleExpandedMode` | private relayout helper |

## Complete Ownership And Dependencies

- Class/layout authority: [UID:000093][NewInventoryPane](by-class/NewInventoryPane.md) and [UID:00054F][NewInventoryPaneLayout](by-type/by-struct/NewInventoryPaneLayout.md).
- Companion scrollbar: [UID:0000KB][InventoryScrollPane](by-file/InventoryScrollPane.md), [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md).
- Exact pooled data support: [UID:0003BV][0x0061c7e0-0x0061c86c.NewInventoryPaneVtableData](by-memory/0x0061c7e0-0x0061c86c.NewInventoryPaneVtableData.md) and [UID:0003BX][0x0061c8f8-0x0061c9c4.InventoryResourceStrings](by-memory/0x0061c8f8-0x0061c9c4.InventoryResourceStrings.md).
- Cross-file source dependency: [UID:00054G][0x005a4de0-0x005a4e3d.UserPaneOpenMixItemDialog](by-memory/0x005a4de0-0x005a4e3d.UserPaneOpenMixItemDialog.md) emits through UserPane; this file only calls the declared member.
- The four no-receiver packet serializers are private static NewInventoryPane members. `GetButtonRect` and `HitTestButton` are file-local. All remaining helpers are private instance members.

## Current Score Rationale

- Completion `94`: the complete source inventory, exact children, order, owner/emitter route, formal source/header shape, support routes, exclusions, and historical hypotheses are documented and emitted.
- Confidence `95`: exact bounded bytes, vtables, field offsets, call graph, packet formats, geometry, and physical source order agree. Final lexical spellings and compile-equivalence audit retain the cap.

## Historical Assumptions Preserved

The former scrollbar-fold hypothesis, broad-family sufficiency, future exact-child backlog, raw-no-route no-code policy, and acceptable empty-emitter state are superseded. They remain below as dated provenance; the current contract above is authoritative.

## UID0000KA Whole-File Boundary - 2026-08-15

The exhaustive InventoryPane.cpp audit preserves this file as the sole source route for the independent `NewInventoryPane` authored family at `[0x004eb420,0x004ee643)` plus its compiler scalar-delete wrapper `[0x004efb50,0x004efbb7)`. Its constructor has an independent `GeneralPurposePanel` caller, its primary/secondary/tertiary RTTI/vtable family is `[0x0061c7e0,0x0061c86c)`, and its resource use includes `ITEMINV.EPF`, `ITEMINV.PAL`, `ITEMINVE.EPF`, `...(%d)`, and `INVENBUT.EPF` at the exact NewInventoryPane sites documented by UID0003BX.

None of those definitions, destructor adjustors at `[0x004efa20,0x004efa36)`, compiler tables, or literals emit into UID0000KA `InventoryPane.cpp`. Physical interleaving with legacy/Pane2 code is address-layout evidence only. Completion/confidence and this file's existing owner/path remain unchanged.

## Historical Status Before Exhaustive B007 Closure

- Confidence: strong for newer item-inventory behavior, `NexusTK/ui/inventory/` placement, and the consumer relationship with the separately reconstructed inventory scrollbar.
- Proposed module: `ui/inventory/NewInventoryPane.cpp`
- Companion module: [UID:0000KB][InventoryScrollPane](by-file/InventoryScrollPane.md) / `ui/inventory/InventoryScrollPane.cpp` and `InventoryScrollPane.h`.
- Current generated source label: `source-3/simroot_v2/class_NewInventoryPane.cpp` (non-authoritative for final names).
- Evidence basis: live IDA MCP lookup/xref/callee/raw-byte checks through 2026-06-16, plus exact support pages.
- Autogen root: `auto-generated/NexusTK/ui/inventory/NewInventoryPane.cpp`

## Historical File Role Before Exact Children

`NewInventoryPane.cpp` should own the updated item inventory pane: filtered visible slot list, list/grid layouts, tab buttons, hover/highlight state, drag/drop and right-click item actions, scroll-wheel handling, sound stop behavior, and view-mode toggling.

The pane owns one [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md) instance through its pointer at `+0x114`. IDA-backed documentation shows the scrollbar constructor `0x00563260` called from `NewInventoryPane::NewInventoryPane` at `0x004eb4e4` and the scrollbar notifying `NewInventoryPane::OnScrollPositionChanged`. This proves construction and callback consumption, not source-file ownership.

## Source Split Decision

Use `ui/inventory/NewInventoryPane.cpp` as the source root for the newer item-inventory pane. Keep [UID:0000KB][InventoryScrollPane](by-file/InventoryScrollPane.md) as the finalized standalone inventory-specific scrollbar source root. The accepted split is:

```text
ui/inventory/NewInventoryPane.cpp
ui/inventory/InventoryScrollPane.cpp
ui/inventory/InventoryScrollPane.h
```

Historical fold hypothesis: earlier revisions treated the single constructor caller and private pane use as grounds to possibly fold `ScrollInventoryPane` into `NewInventoryPane.cpp`. The complete `0x00563260-0x0056470c` 19-method island, dedicated three-vtable class, exact sibling source pattern, and validator-owned `InventoryScrollPane.cpp/.h` route supersede that hypothesis. `NewInventoryPane` remains a consumer and instance owner only.

Do not merge this page into the broad [UID:0000KA][InventoryPane](by-file/InventoryPane.md) root just because the executable ranges are interleaved. [UID:00018J][0x004ea130-0x004efbb7.InventoryPanes](by-memory/0x004ea130-0x004efbb7.InventoryPanes.md) is an address-neighborhood aggregate over legacy inventory, new inventory, alternate inventory, and three BackPane helper children; exact source ownership should use the child ranges and class/file pages instead of the aggregate alone.

## Historical Proposed Contents Before Exact Children

| Entity | Address evidence | Role |
| --- | --- | --- |
| [UID:000093][NewInventoryPane](by-class/NewInventoryPane.md) | `0x004eb420-0x004efbb6` | Newer item inventory pane and item-slot interaction owner. |
| [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md) | `0x00563260-0x0056470c` | Separately reconstructed companion scrollbar in `InventoryScrollPane.cpp/.h`; this file constructs and receives callbacks from it but does not own its definitions. |
| [UID:0003BV][0x0061c7e0-0x0061c86c.NewInventoryPaneVtableData](by-memory/0x0061c7e0-0x0061c86c.NewInventoryPaneVtableData.md) | `0x0061c7e0-0x0061c86c` | Exact `NewInventoryPane` RTTI/vtable island; source-declared/generated-binary data from class declarations. |

## Historical Broad Method Families

| Range | Current method family | Notes |
| --- | --- | --- |
| `0x004eb420-0x004ebb1f` | construction, refresh, resize, slot-list rebuild, scrollbar sync, layout/show | Constructs the pane, constructs `ScrollInventoryPane`, rebuilds visible inventory slots, and keeps the child scrollbar range/position synchronized. |
| `0x004ebb20-0x004ec913` | paint | Draws item slots, item icons, text/count overlays, view controls, and pane chrome. |
| `0x004ec920-0x004ed9c4` | keyboard/mouse input | Handles paging, selection, drag/drop, right-click context behavior, hover help, and scroll-wheel movement. |
| `0x004edb70-0x004ee5df` | scroll, hit-test, layout helper, view/audio helpers | Maps visual to physical slots, resolves button/slot rectangles, stops active item sound, and toggles list/grid mode. |
| `0x004efb50-0x004efbb6` | scalar deleting destructor | Dismisses child scrollbar and tears down the `PanelPane` base. |

## Evidence Notes

- IDA MCP confirms `0x004eb420` as a `0xf0`-byte constructor, `0x004ebb20` as a `0xdf3`-byte paint method, and `0x004ecb50` as a `0xe74`-byte mouse handler.
- IDA MCP `callees` for `0x004eb420` include `0x00563260` (`ScrollInventoryPane` constructor) and `0x00563400` (scrollbar enable/activation helper).
- IDA MCP `callers` for `0x00563260` show only `0x004eb4e4` inside the new item inventory constructor.
- [UID:0000KA][InventoryPane](by-file/InventoryPane.md) already projects inventory UI source to `NexusTK/ui/inventory/` and lists `NewInventoryPane.cpp` as a likely split file.
- [UID:00018J][0x004ea130-0x004efbb7.InventoryPanes](by-memory/0x004ea130-0x004efbb7.InventoryPanes.md) records the same `NewInventoryPane` subrange and the surrounding inventory source-split decision.
- [UID:00025L][0x0061c7a4-0x0061c9c4.InventoryPaneReadOnlyData](by-memory/0x0061c7a4-0x0061c9c4.InventoryPaneReadOnlyData.md) records the `NewInventoryPane` vtables and inventory resource strings.
- [UID:0001GZ][0x00563260-0x0056470c.ScrollInventoryPane](by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md) records the complete 19-child inventory-scrollbar island, standalone [UID:0000KB][InventoryScrollPane](by-file/InventoryScrollPane.md) ownership, and the separate constructor/callback consumer relationship retained here.
- The corrected read-only data page keeps the `NewInventoryPane` vtable island at `0x0061c7e4`, `0x0061c834`, and `0x0061c864` inside the inventory data span and excludes the following `KeySpeedMgr` locator at `0x0061c9c4`.
- 2026-06-11 A002 Batch216 live IDA MCP reconfirmed the `NewInventoryPane` method anchors at `0x004eb420-0x004eb510`, `0x004ebb20-0x004ec913`, `0x004ecb50-0x004ed9c4`, `0x004edb70-0x004edcc5`, and `0x004efb50-0x004efbb7`; the one direct `ScrollInventoryPane` constructor caller at `0x004eb4e4`; and the exact `NewInventoryPane` RTTI/vtable child [UID:0003BV][0x0061c7e0-0x0061c86c.NewInventoryPaneVtableData](by-memory/0x0061c7e0-0x0061c86c.NewInventoryPaneVtableData.md) from `0x0061c7e0` through `0x0061c86c`.
- 2026-06-16 A002 live IDA MCP reconfirmed a direct constructor xref from `0x004b84a1`, constructor callees to `PanelPane` `0x00545090`, allocator `0x004f4aa0`, `ScrollInventoryPane` constructor `0x00563260`, and activation helper `0x00563400`; one and only one xref to the scrollbar constructor at `0x004eb4e4`; and vtable store/restore refs to `0x0061c7e4`, `0x0061c834`, and `0x0061c864` from constructor/setup and scalar deleting destructor sites.
- The same pass reconfirmed `ScrollInventoryPane` raw helper starts `0x00563310`, `0x00563340`, `0x00563420`, `0x00563440`, `0x00564330`, `0x005643a0`, and `0x005646b0` are not IDA function objects, that `0x005646b0` still has zero xrefs, and that `0x004efbb7-0x004efbc0` is nine bytes of `0xcc` alignment. Those facts remain valid liveness/source-shape evidence but no longer imply a source fold.
- B006 resolves item slot records through [UID:0003U9][0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress](by-memory/0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress.md). `NewInventoryPane` builds filtered visible slot lists and paints names/icons/counts from `LocalInventorySlotRecord` fields, but `LivingObjectPane` owns the local-player storage accessor.
- Generated `class_NewInventoryPane.cpp` still has low automated fidelity and several unresolved dependency labels, so use the address ranges and docs rather than generated local type names for migration.

## Historical Score Rationale

- Completion is `86` because the page has a valid projected source path, file-role summary, method-family ranges, companion scrollbar ownership, source-split decision, aggregate boundary caveats, exact vtable child [UID:0003BV][0x0061c7e0-0x0061c86c.NewInventoryPaneVtableData](by-memory/0x0061c7e0-0x0061c86c.NewInventoryPaneVtableData.md), live constructor/xref/callee refresh, raw scrollbar-helper checks, and links to executable, scrollbar, and read-only data evidence.
- Confidence is `88` because the `ui/inventory/` placement matches [UID:0000KA][InventoryPane](by-file/InventoryPane.md), live IDA confirms the representative method ranges, the external constructor xref, the one-caller scrollbar constructor relationship, vtable store/restore refs, raw reset no-xref status, and the exact vtable-data child. It stays below higher audit quality because exact child method pages for `NewInventoryPane` are still mostly unsplit and generated method names are not final; the inventory-scrollbar source split itself is resolved.

## Cross-References

- [UID:0000KA][InventoryPane](by-file/InventoryPane.md)
- [UID:000093][NewInventoryPane](by-class/NewInventoryPane.md)
- [UID:00018J][0x004ea130-0x004efbb7.InventoryPanes](by-memory/0x004ea130-0x004efbb7.InventoryPanes.md)
- [UID:0001GZ][0x00563260-0x0056470c.ScrollInventoryPane](by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md)
- [UID:0003BV][0x0061c7e0-0x0061c86c.NewInventoryPaneVtableData](by-memory/0x0061c7e0-0x0061c86c.NewInventoryPaneVtableData.md)
- [UID:0000KB][InventoryScrollPane](by-file/InventoryScrollPane.md)

## Changes

- 2026-06-21 Rule 26 support sync from B006 [UID:0003U9][0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress](by-memory/0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress.md):
  - Added the local inventory slot record dependency for visible-slot filtering and painting while preserving NewInventoryPane source ownership over UI behavior only.
- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `78`, confidence `74`.
- Summary/evidence: the page documents pane role, companion scrollbar, method-family ranges, and IDA constructor/caller checks, but generated source has low fidelity and exact split from `InventoryPane`/scrollbar code remains open.
- 2026-06-03 projected-path and confidence pass:
  - Before: the page text proposed `ui/inventory/NewInventoryPane.cpp`, but `PROPOSED_RECONSTRUCTION_PATH` was blank and the validator reported this by-file root as an autogen error.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/inventory/"`, score `80/80`, and explicit autogen-root/score-rationale notes.
  - Summary/evidence: [UID:0000KA][InventoryPane](by-file/InventoryPane.md), [UID:00018J][0x004ea130-0x004efbb7.InventoryPanes](by-memory/0x004ea130-0x004efbb7.InventoryPanes.md), [UID:0001GZ][0x00563260-0x0056470c.ScrollInventoryPane](by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md), and [UID:00025L][0x0061c7a4-0x0061c9c4.InventoryPaneReadOnlyData](by-memory/0x0061c7a4-0x0061c9c4.InventoryPaneReadOnlyData.md) support the folder and class/file relationship while leaving final C++ and private-scrollbar split unresolved.
- 2026-06-07 A006 source-split and evidence refresh:
  - Before: the page had the projected path and core method ranges but did not explicitly describe how to use the `InventoryScrollPane` companion root or the mixed inventory aggregate when planning migration.
  - Changed to: score `82/82`, added a source-split decision, added the corrected `NewInventoryPane` vtable/read-only data row, and tied the score rationale to the strengthened scrollbar aggregate owner chain.
  - Summary/evidence: existing UID-linked pages now record the `NewInventoryPane` executable range, the one-caller scrollbar constructor relationship, the reviewed `InventoryScrollPane` companion source root, the corrected inventory read-only data span, and the aggregate warning that BackPane helper children are physically interleaved but not inventory-owned.
- 2026-06-11 A002 Batch216 parent-gate repair:
  - Before: score `82/82`, below the strict gate for assigning the exact `NewInventoryPane` vtable-data child.
  - Changed to: score `85/86`, with [UID:0003BV][0x0061c7e0-0x0061c86c.NewInventoryPaneVtableData](by-memory/0x0061c7e0-0x0061c86c.NewInventoryPaneVtableData.md) as exact read-only data evidence.
  - Summary/evidence: live IDA MCP reconfirmed representative `NewInventoryPane` method ranges, the one direct `ScrollInventoryPane` constructor caller, three vtable store/restore xref sets, and locator-backed child boundaries from `0x0061c7e0` to `0x0061c86c`.
- 2026-06-16 A002 file-quality refresh:
  - Before: score `85/86`.
  - Changed to: score `86/88`.
  - Summary/evidence: live IDA MCP reconfirmed constructor, paint, input, helper, destructor, and scrollbar method boundaries; the external constructor xref at `0x004b84a1`; the single scrollbar-constructor caller at `0x004eb4e4`; vtable store/restore refs; the raw scrollbar reset no-function/no-xref blocker; and trailing padding before `JpegScreenshotWriter`. Owner/emitter remain this file, with `InventoryScrollPane` kept as a private companion/fold candidate.
- 2026-08-15 B005 UID0000KB support callback:
  - Preserved `86/88` and the NewInventoryPane source inventory while finalizing [UID:0000KB][InventoryScrollPane](by-file/InventoryScrollPane.md) as a separate `InventoryScrollPane.cpp/.h` companion.
  - Historicalized the private-fold hypothesis. The constructor call at `0x004eb4e4`, member pointer at `+0x114`, and `OnScrollPositionChanged` callback prove consumption and instance ownership, while the complete 19-method island and three-vtable class establish separate source ownership.
