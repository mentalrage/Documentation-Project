*** UID:0000KA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/inventory/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# InventoryPane

## Status

- Confidence: 94/94 after the accepted whole-file reconstruction. The exact legacy `InventoryPane` and alternate `InventoryPane2` authored inventory, bytes, boundaries, callers/xrefs, source order, owner/emitter routes, formal source, declarations, compiler exclusions, resource/data inventory, complete gap/padding map, and inherited `GrafPort::m_visibleBounds` source identity are closed at report-level detail. `NewInventoryPane`, `ScrollInventoryPane`, and `BackPane` remain evidence-backed exclusions from this file.
- Proposed module folder: `ui/inventory/`
- Emitted files: `NexusTK/ui/inventory/InventoryPane.cpp` and `NexusTK/ui/inventory/InventoryPane.h`.
- Separate owner files: `NexusTK/ui/inventory/NewInventoryPane.cpp` and `NexusTK/ui/inventory/InventoryScrollPane.cpp`; these are support evidence and do not emit into this file.
- Evidence basis: targeted IDA MCP boundary checks on 2026-05-23, the 2026-06-01 inventory aggregate refresh, companion vtable/resource data, exact source-emitting [UID:00031V][0x004ee650-0x004ee6a7.InventoryPane2RawConstructor](by-memory/0x004ee650-0x004ee6a7.InventoryPane2RawConstructor.md), repaired non-emitting split parent [UID:0002SU][0x004ee6b0-0x004ef510.InventoryPane2CoreAndHelpers](by-memory/0x004ee6b0-0x004ef510.InventoryPane2CoreAndHelpers.md), its exact children [UID:00048P][0x004ee6b0-0x004ee6cf.InventoryPane2Destructor](by-memory/0x004ee6b0-0x004ee6cf.InventoryPane2Destructor.md) through [UID:00048X][0x004ef460-0x004ef50b.InventoryPane2SendDragDropItemPacketRaw](by-memory/0x004ef460-0x004ef50b.InventoryPane2SendDragDropItemPacketRaw.md), the Batch 248 exact tail children under [UID:0002SV][0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor](by-memory/0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor.md), and B004 UID0003ER evidence that the scalar deleting destructor wrapper is class-owned compiler support rather than an additional source body.

## Hypothesis

The item inventory panes form a coherent gameplay UI subsystem. They should not be grouped with generic control panes, item image libraries, or cash-shop item catalog code.

The accepted reconstruction structure keeps legacy `InventoryPane` and alternate `InventoryPane2` together while retaining the newer pane and its scrollbar as separate modules:

```text
ui/inventory/InventoryPane.cpp
ui/inventory/NewInventoryPane.cpp
ui/inventory/InventoryScrollPane.cpp
```

Historical pre-callback alternatives included one broad file containing all variants and one-class generated staging files. The accepted owner evidence rejects both: only legacy `InventoryPane` plus `InventoryPane2` emit through this file; NewInventoryPane and InventoryScrollPane remain separate.

## Proposed Contents

| Entity | Current range | Accepted source file | Role |
| --- | --- | --- | --- |
| `InventoryPane` | `0x004ea130-0x004efb41` | `NexusTK/ui/inventory/InventoryPane.cpp` | Legacy item inventory pane with list/grid view, paging, item activation, drag packet, and tooltip message handling; emits A01-A13. |
| `NewInventoryPane` | `0x004eb420-0x004efbb6` | `NexusTK/ui/inventory/NewInventoryPane.cpp` | Updated item inventory pane with scrollbar, list/grid layouts, tab buttons, hover, drag/drop, and compact/expanded state; excluded from UID0000KA. |
| `InventoryPane2` | `0x004ee650-0x004efa94`; exact confirmed children are source-emitting [UID:00031V][0x004ee650-0x004ee6a7.InventoryPane2RawConstructor](by-memory/0x004ee650-0x004ee6a7.InventoryPane2RawConstructor.md), [UID:0002SU][0x004ee6b0-0x004ef510.InventoryPane2CoreAndHelpers](by-memory/0x004ee6b0-0x004ef510.InventoryPane2CoreAndHelpers.md) with exact source children [UID:00048P][0x004ee6b0-0x004ee6cf.InventoryPane2Destructor](by-memory/0x004ee6b0-0x004ee6cf.InventoryPane2Destructor.md) through [UID:00048X][0x004ef460-0x004ef50b.InventoryPane2SendDragDropItemPacketRaw](by-memory/0x004ef460-0x004ef50b.InventoryPane2SendDragDropItemPacketRaw.md), and exact tail helpers/support split under [UID:0002SV][0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor](by-memory/0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor.md); [UID:0003ER][0x004efa40-0x004efa95.InventoryPane2ScalarDeletingDestructor](by-memory/0x004efa40-0x004efa95.InventoryPane2ScalarDeletingDestructor.md) is non-emitting scalar-delete support | `NexusTK/ui/inventory/InventoryPane.cpp` | Alternate smaller inventory pane with dual list/grid layout and selector buttons; exact children emit A14-A28, UID0003ER emits no marker, and BackPane V3 plus legacy/new destructor adjustor thunks stay excluded. |
| `ScrollInventoryPane` | `0x00563260-0x0056470c` | `NexusTK/ui/inventory/InventoryScrollPane.cpp` | Private/companion scrollbar used by the newer item inventory UI; excluded from UID0000KA. |

## Behavior Summary

- Legacy inventory draws up to 15 entries per page in list or grid mode and responds to Page Up/Page Down.
- New inventory supports list and 3-column grid layouts, a child scrollbar, slot filtering, hover highlighting, drag/drop, context menu/right-click paths, sound stopping, and view-mode toggling.
- `InventoryPane2` is an alternate compact visual style with fixed button rectangles and a 9-slot grid/list hit-test path. Its retained `GetSlotRect(short, RectBounds *) const` source body uses the same low-word ABI/one-final-`InitRectBounds` pattern as legacy InventoryPane, while live `HitTestSlot` inlines the complete compact geometry. Its button family uses a signed-short const-member rectangle selector and signed-short y/x hit test; OnMouseEvent inlines the first-hit loop, and the retained raw definition remains source despite zero raw-start xrefs.
- `ScrollInventoryPane` owns the EPF-backed scrollbar track, thumb, arrow regions, timer repeat, and highlight state.

## InventoryPane2 Core Children

`InventoryPane2` is implemented in the existing InventoryPane source family at `NexusTK/ui/inventory/InventoryPane.cpp`. UID00031V carries the accepted `InventoryPane2::InventoryPane2()` definition at position `200`; the complete exact child chain emits positions `210-340`. A separate `InventoryPane2.cpp` split is rejected because current class/file evidence and the completed generated module support the shared InventoryPane route.

[UID:0003EL][0x004ef720-0x004ef794.InventoryPane2SlotRectBuilderRaw](by-memory/0x004ef720-0x004ef794.InventoryPane2SlotRectBuilderRaw.md) emits A25 at position `310`. Its exact 116-byte body reads a logical `short`, preserves the unsigned nine-slot guard, selects list or 3x3 grid edges from dword `m_viewMode`, and calls free `InitRectBounds` exactly once after all paths converge. The target H channel remains blank; [UID:00006S][InventoryPane2](by-class/InventoryPane2.md) owns the sole corrected declaration. [UID:0003EO][0x004ef890-0x004ef962.InventoryPane2SlotHitTest](by-memory/0x004ef890-0x004ef962.InventoryPane2SlotHitTest.md) inlines the same geometry at runtime and has three mouse/event callers, so zero direct routes to the retained A25 copy do not imply source absence.

[UID:0003EJ][0x004ef630-0x004ef702.InventoryPane2ButtonRectHelper](by-memory/0x004ef630-0x004ef702.InventoryPane2ButtonRectHelper.md) emits A24 at position `300` as a non-static const member with a signed-short selector, four explicit exact rectangle cases, all-minus-one default, and InitRectBounds construction. All five observed calls prepare the InventoryPane2 receiver in ECX; the following switch table is compiler lowering, not a static rectangle source.

[UID:0003EM][0x004ef7a0-0x004ef86d.InventoryPane2ButtonHitTestRaw](by-memory/0x004ef7a0-0x004ef86d.InventoryPane2ButtonHitTestRaw.md) emits A26 at position `320`. Its exact 205-byte/78-instruction body has SHA256 `800405216457402D4E1558484AF61A2AA78968AF38F980EE3D4DB9EF330B9054`, consumes y at stack `+0x08` and x at `+0x0c`, carries a signed-short SI/AX loop and return, constructs one local RectBounds through the A24 abstraction, returns the first hit id or `-1`, and has zero inbound raw-start code/data xrefs. UID00048U contains source-equivalent inlined hover and four-id left-down behavior; the adjacent UID0003EN table is compiler lowering of the inlined A24 call.

[UID:0003BW][0x0061c86c-0x0061c8f8.InventoryPane2VtableData](by-memory/0x0061c86c-0x0061c8f8.InventoryPane2VtableData.md) is not an additional source body in this file. It is class-owned but non-reconstructable/non-emitting compiler-generated RTTI/vtable data for `InventoryPane2`; real source behavior emits through the constructor, destructor, activation, paint, key, mouse, server-message, and packet/helper children below. Verified generated `InventoryPane.cpp` contains no UID0003BW empty marker; the compiler regenerates that table from the class declaration and virtual methods.

[UID:0003ER][0x004efa40-0x004efa95.InventoryPane2ScalarDeletingDestructor](by-memory/0x004efa40-0x004efa95.InventoryPane2ScalarDeletingDestructor.md) is likewise not an additional source body in this file. MCP session `43ccf853` proves it is the `InventoryPane2` compiler scalar-delete wrapper reached from the primary vtable cell `0x0061c870` and secondary/tertiary adjustor thunks. Verified generated source contains the normal `InventoryPane2` constructor/destructor/method bodies and no UID0003ER empty emitter marker.

| Child | Source role |
| --- | --- |
| [UID:00048P][0x004ee6b0-0x004ee6cf.InventoryPane2Destructor](by-memory/0x004ee6b0-0x004ee6cf.InventoryPane2Destructor.md) | Source destructor body. |
| [UID:00048Q][0x004ee6d0-0x004ee6dc.InventoryPane2RefreshEmbeddedPane](by-memory/0x004ee6d0-0x004ee6dc.InventoryPane2RefreshEmbeddedPane.md) | Packet-ignored activation override that invalidates inherited `GrafPort::m_visibleBounds` at `+0x44`; the old `RefreshEmbeddedPane` slug and pane-local bounds interpretation are historical provenance only. |
| [UID:00048R][0x004ee6e0-0x004ee6e1.InventoryPane2SourceEmptyVirtual](by-memory/0x004ee6e0-0x004ee6e1.InventoryPane2SourceEmptyVirtual.md) | Source-empty virtual/no-code child. |
| [UID:00048S][0x004ee6f0-0x004eee5c.InventoryPane2OnPaint](by-memory/0x004ee6f0-0x004eee5c.InventoryPane2OnPaint.md) | List/grid drawing, pagination, hotkeys, and selector button drawing. |
| [UID:00048T][0x004eee60-0x004eeedc.InventoryPane2OnKeyEvent](by-memory/0x004eee60-0x004eeedc.InventoryPane2OnKeyEvent.md) | Page Up/Page Down handling. |
| [UID:00048U][0x004eeee0-0x004ef290.InventoryPane2OnMouseEvent](by-memory/0x004eeee0-0x004ef290.InventoryPane2OnMouseEvent.md) | Hover, selector press state, view-mode changes, item use, double-click use, and drag/drop. |
| [UID:00048V][0x004ef290-0x004ef3fc.InventoryPane2OnServerMessage](by-memory/0x004ef290-0x004ef3fc.InventoryPane2OnServerMessage.md) | Opcode `0x59` item-help popup handling. |
| [UID:00048W][0x004ef400-0x004ef460.InventoryPane2SendUseItemSlotPacketRaw](by-memory/0x004ef400-0x004ef460.InventoryPane2SendUseItemSlotPacketRaw.md) | Retained raw use-item packet helper, opcode `0x1c`, send length `2`. |
| [UID:00048X][0x004ef460-0x004ef50b.InventoryPane2SendDragDropItemPacketRaw](by-memory/0x004ef460-0x004ef50b.InventoryPane2SendDragDropItemPacketRaw.md) | Retained raw drag/drop packet helper, opcode `0x66`, send length `10`. |

Packet byte writers, packet buffers, socket/queue senders, and protocol helpers are dependencies of the two raw packet builders, not the source owners of these feature-specific InventoryPane2 methods.

## Strict-Gate Attachments

[UID:00006R][InventoryPane](by-class/InventoryPane.md) and [UID:00006S][InventoryPane2](by-class/InventoryPane2.md) attach through their exact accepted emitter routes to this source root, now scored `94/94`. This does not make broad [UID:00018J][0x004ea130-0x004efbb7.InventoryPanes](by-memory/0x004ea130-0x004efbb7.InventoryPanes.md) attachable: that aggregate still spans legacy inventory, NewInventoryPane, InventoryPane2, BackPane, and compiler-only rows.

## IDA MCP Evidence

Targeted checks on 2026-05-23 confirmed:

- `0x004ea130-0x004ea202`, `0x004ea2a0-0x004ea945`, `0x004ea9d0-0x004eac88`, and `0x004eac90-0x004eae02` for legacy inventory construction, paint, mouse, and message handling.
- `0x004eb420-0x004eb510`, `0x004ebb20-0x004ec913`, `0x004ecb50-0x004ed9c4`, and `0x004ee230-0x004ee3b7` for the updated inventory constructor, paint, mouse, and hit test.
- `0x004ee6f0-0x004eee5c`, `0x004eeee0-0x004ef290`, `0x004ef400-0x004ef50b`, and `0x004efa40-0x004efa95` for the alternate inventory render/mouse/raw-packet/delete paths. [UID:00031V][0x004ee650-0x004ee6a7.InventoryPane2RawConstructor](by-memory/0x004ee650-0x004ee6a7.InventoryPane2RawConstructor.md), [UID:0002SU][0x004ee6b0-0x004ef510.InventoryPane2CoreAndHelpers](by-memory/0x004ee6b0-0x004ef510.InventoryPane2CoreAndHelpers.md), and the exact children under [UID:0002SV][0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor](by-memory/0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor.md) record the confirmed InventoryPane2 constructor/method/helper islands while excluding the interleaved BackPane V3 helper and legacy/new inventory thunk support.
- `0x00563260-0x00563301`, `0x005636a0-0x00563d80`, and `0x005640a0-0x00564327` for the item inventory scrollbar.
- 2026-06-11 A008 rechecked the legacy [UID:00006R][InventoryPane](by-class/InventoryPane.md) class with IDA MCP. `lookup_funcs` confirms its constructor/destructor/paint/key/mouse/server-message/button/slot/helper/scalar-delete methods from `0x004ea130` through `0x004efb42`, `xrefs_to` confirms the `InventoryPane` vtable stores/restores at `0x004ea172/0x004ea17c`, `0x004ea241/0x004ea24b`, and `0x004efad8/0x004efae2`, and decompilation confirms its page/view/effect fields, list/grid rendering, navigation buttons, slot hit-tests, drag packet, and tooltip packet handling.

Historical pre-callback evidence: the 2026-06-16 A002 live IDA MCP refresh on session `c001_midiplayer_rdata_20260615` rechecked the then-remaining source-quality blockers. Later accepted callbacks resolved their source/emitter dispositions while retaining the raw-start caveats:

- `lookup_funcs` reconfirmed representative legacy/new/alternate/scrollbar anchors: `0x004ea130`, `0x004eb420`, `0x004ee6b0`, `0x004ee6f0`, `0x004eeee0`, `0x004ef630`, `0x004efa40`, `0x004efb50`, and `0x00563260`.
- IDA still reports no function at raw starts `0x004ee650`, `0x004ef720`, `0x004ef7a0`, and `0x005646b0`; `xrefs_to 0x004ee650` and `xrefs_to 0x005646b0` remain empty, so the raw constructor/reset-helper reachability caveats are real rather than skipped.
- `get_bytes` reconfirmed thirteen `0xcc` bytes before `0x004ee650`, the exact constructor-shaped byte body at `0x004ee650-0x004ee6a7`, and nine `0xcc` bytes before `0x004ee6b0`. It also reconfirmed `0x005646b0-0x0056470c` as method-shaped reset bytes after padding from the previous function.
- `xrefs_to 0x004eb420` reports the `NewInventoryPane` constructor call at `0x004b84a1` from `GeneralPurposePanel`, and `xrefs_to 0x00563260` reports only the `NewInventoryPane` constructor call at `0x004eb4e4`; these support the current `NewInventoryPane.cpp` / private scrollbar split but do not prove whether the scrollbar was a standalone original file.
- Vtable data refs reconfirm the child routes: NewInventoryPane vtables `0x0061c7e4/0x0061c834/0x0061c864`, InventoryPane2 vtables `0x0061c870/0x0061c8c0/0x0061c8f0`, and ScrollInventoryPane vtables `0x0062402c/0x00624078/0x006240a8`.
- Decompilation of `0x004ee6f0` and `0x004eeee0` reconfirmed `InventoryPane2` list/grid drawing, page state at `+0xf8/+0xf9`, view/button state at `+0xfc/+0x100/+0x104`, opcode `0x66` drag packet construction, and item-use dispatch through the shared inventory/player-data helpers.
- B006 resolves the shared inventory record helper as [UID:0003U9][0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress](by-memory/0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress.md). Legacy, new, and alternate inventory panes consume `LocalInventorySlotRecord` entries from the local-player table at `+0x133f08`, stride `0x1fc`; they own visible-index mapping, drawing, hit-test, drag/drop, and activation behavior, not the storage accessor itself.
- 2026-07-03 B012 callback evidence on MCP session `3a33af0b` resolves the UID00031V empty-emitter blocker for this source route: the raw constructor start still has no IDA function, no raw-start xrefs, and no raw-start VA/RVA pointer-byte hits, but exact bytes/padding, `PanelPane` construction, three compiler-lowered `InventoryPane2` vtable stores, and state-field clears support formal first-draft `InventoryPane2::InventoryPane2()` C++. The no direct raw-start route caveat remains documented and does not justify a separate `InventoryPane2.cpp` split.
- 2026-07-05 B004 callback evidence on MCP session `supervisor_recovery_20260705` resolves the UID0003BW generated-marker blocker for this source route: exact `0x0061c86c-0x0061c8f8` RTTI/vtable bytes, decorated `InventoryPane2` table names, constructor/destructor/scalar-deleting vptr-store xrefs, local slot mapping, adjacent `ITEMINV.EPD` boundary, pointer-scan negatives, and no local `InventoryPane2` UDT prove class-owned generated-binary support, not a raw source function or table body.
- 2026-07-07 B004 callback evidence on MCP session `43ccf853` resolves the UID0003ER empty-marker blocker for this source route: exact `0x004efa40-0x004efa95` range/padding/signature, primary vtable cell `0x0061c870 -> 0x004efa40`, adjustor routes from `0x004ef9f4/0x004ef9ff`, vtable restores, base cleanup, flag-gated optional free, guard-check support, pointer-pattern negatives, and UID00048P source-destructor comparison prove class-owned compiler wrapper support, not a separate source method or marker.
- 2026-08-15 B006 UID0003EL callback evidence closes the slot-rectangle family ABI and call shape. UID0003EL is exactly `[0x004ef720,0x004ef794)`, 116 bytes / 45 instruction heads, with exact predecessor/successor hashes, a low-word short ABI, unsigned guard, dword `m_viewMode`, one final `InitRectBounds`, zero direct/pointer/branch routes, and complete live inlining in UID0003EO at three event call sites. Legacy UID00051B has the same 116-byte low-word/one-call template, and modeled NewInventoryPane `0x004ee0a0` independently uses `__int16` with the same compact grid constants.

## File-Split Guidance

Use these working files for future migration planning:

```text
ui/inventory/InventoryPane.cpp
ui/inventory/NewInventoryPane.cpp
ui/inventory/InventoryScrollPane.cpp
```

Keep [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md) separate. Item inventory and spell inventory share UI patterns and scrollbar code shape, but their data sources, activation paths, and input panes are different enough to justify separate original files.

The current owner/emitter decisions remain unchanged after the 2026-06-16 review. [UID:00006R][InventoryPane](by-class/InventoryPane.md) and [UID:00006S][InventoryPane2](by-class/InventoryPane2.md) route to this file; [UID:000093][NewInventoryPane](by-class/NewInventoryPane.md) remains under [UID:0000LS][NewInventoryPane](by-file/NewInventoryPane.md); and [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md) remains under [UID:0000KB][InventoryScrollPane](by-file/InventoryScrollPane.md), with a documented fold candidate into `NewInventoryPane.cpp`.

## Cross-References

- [UID:00006R][InventoryPane](by-class/InventoryPane.md)
- [UID:00006S][InventoryPane2](by-class/InventoryPane2.md)
- [UID:000093][NewInventoryPane](by-class/NewInventoryPane.md)
- [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md)
- [UID:00018J][0x004ea130-0x004efbb7.InventoryPanes](by-memory/0x004ea130-0x004efbb7.InventoryPanes.md)
- [UID:00031V][0x004ee650-0x004ee6a7.InventoryPane2RawConstructor](by-memory/0x004ee650-0x004ee6a7.InventoryPane2RawConstructor.md)
- [UID:00051B][0x004eb140-0x004eb1b4.InventoryPaneSlotRectBuilderRaw](by-memory/0x004eb140-0x004eb1b4.InventoryPaneSlotRectBuilderRaw.md)
- [UID:00051H][0x004eb1c0-0x004eb291.InventoryPaneButtonHitTestRaw](by-memory/0x004eb1c0-0x004eb291.InventoryPaneButtonHitTestRaw.md)
- [UID:0002SU][0x004ee6b0-0x004ef510.InventoryPane2CoreAndHelpers](by-memory/0x004ee6b0-0x004ef510.InventoryPane2CoreAndHelpers.md)
- [UID:00048P][0x004ee6b0-0x004ee6cf.InventoryPane2Destructor](by-memory/0x004ee6b0-0x004ee6cf.InventoryPane2Destructor.md)
- [UID:00048Q][0x004ee6d0-0x004ee6dc.InventoryPane2RefreshEmbeddedPane](by-memory/0x004ee6d0-0x004ee6dc.InventoryPane2RefreshEmbeddedPane.md)
- [UID:00048R][0x004ee6e0-0x004ee6e1.InventoryPane2SourceEmptyVirtual](by-memory/0x004ee6e0-0x004ee6e1.InventoryPane2SourceEmptyVirtual.md)
- [UID:00048S][0x004ee6f0-0x004eee5c.InventoryPane2OnPaint](by-memory/0x004ee6f0-0x004eee5c.InventoryPane2OnPaint.md)
- [UID:00048T][0x004eee60-0x004eeedc.InventoryPane2OnKeyEvent](by-memory/0x004eee60-0x004eeedc.InventoryPane2OnKeyEvent.md)
- [UID:00048U][0x004eeee0-0x004ef290.InventoryPane2OnMouseEvent](by-memory/0x004eeee0-0x004ef290.InventoryPane2OnMouseEvent.md)
- [UID:00048V][0x004ef290-0x004ef3fc.InventoryPane2OnServerMessage](by-memory/0x004ef290-0x004ef3fc.InventoryPane2OnServerMessage.md)
- [UID:00048W][0x004ef400-0x004ef460.InventoryPane2SendUseItemSlotPacketRaw](by-memory/0x004ef400-0x004ef460.InventoryPane2SendUseItemSlotPacketRaw.md)
- [UID:00048X][0x004ef460-0x004ef50b.InventoryPane2SendDragDropItemPacketRaw](by-memory/0x004ef460-0x004ef50b.InventoryPane2SendDragDropItemPacketRaw.md)
- [UID:0002SV][0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor](by-memory/0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor.md)
- [UID:0003EJ][0x004ef630-0x004ef702.InventoryPane2ButtonRectHelper](by-memory/0x004ef630-0x004ef702.InventoryPane2ButtonRectHelper.md)
- [UID:0003EL][0x004ef720-0x004ef794.InventoryPane2SlotRectBuilderRaw](by-memory/0x004ef720-0x004ef794.InventoryPane2SlotRectBuilderRaw.md)
- [UID:0003EM][0x004ef7a0-0x004ef86d.InventoryPane2ButtonHitTestRaw](by-memory/0x004ef7a0-0x004ef86d.InventoryPane2ButtonHitTestRaw.md)
- [UID:0003EO][0x004ef890-0x004ef962.InventoryPane2SlotHitTest](by-memory/0x004ef890-0x004ef962.InventoryPane2SlotHitTest.md)
- [UID:0003EP][0x004ef970-0x004ef9f4.InventoryPane2VisibleIndexToInventorySlot](by-memory/0x004ef970-0x004ef9f4.InventoryPane2VisibleIndexToInventorySlot.md)
- [UID:0003ER][0x004efa40-0x004efa95.InventoryPane2ScalarDeletingDestructor](by-memory/0x004efa40-0x004efa95.InventoryPane2ScalarDeletingDestructor.md)
- [UID:0001GZ][0x00563260-0x0056470c.ScrollInventoryPane](by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md)
- [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md)

## Accepted Whole-File Inventory

### Authored Item Evidence And Exact Emitter Crosswalk

The following 28 rows are the complete authored-definition set. `CPP position` is an exact, single destination in the final `InventoryPane.cpp` assembly; there is no alternative class-owned route. The two class declarations are emitted once through UID00006R formal H position `010` and UID00006S formal H position `020`; every method row names the declaration owner separately from its sole CPP-definition owner.

| # | Exact range / source definition | Item-specific evidence, behavior, and material route | Owner and sole formal route | Destination / claim |
| --- | --- | --- | --- | --- |
| A01 | `[4EA130,4EA202)` `InventoryPane::InventoryPane` | Modeled function body; no direct inbound code xref; PanelPane construction, InterfaceEfx allocation, `ITEMEFX.EPD`/`INTEFX.PAD`, page/list/effect initialization. | UID00006R; CPP UID00006R position `010`; H UID00006R position `010`. | `by-class/InventoryPane.md`, UID00018J; C05. |
| A02 | `[4EA210,4EA271)` `InventoryPane::~InventoryPane` | Modeled ordinary destructor; no direct inbound code xref; marks the InterfaceEfx for deletion then reaches PanelPane teardown. | UID00006R; CPP UID00006R position `020`; H UID00006R position `010`. | `by-class/InventoryPane.md`, UID00018J; C05. |
| A03 | `[4EA280,4EA28C)` `InventoryPane::OnActivate` | Exact 12 bytes/hash in I01; data xref exactly `61C7A0`, no code xref; ignores packet and invalidates inherited `GrafPort::m_visibleBounds` at `+0x44`. | UID00006R; CPP UID00006R position `030`; H UID00006R position `010`. | UID00006R/UID0003BU; C06/C51/C52. |
| A04 | `[4EA290,4EA29B)` `InventoryPane::PlayItemEffect` | Modeled 11-byte companion; zero inbound xrefs; direct InterfaceEfx playback and paired position before paint. | UID00006R; CPP UID00006R position `040`; H UID00006R position `010`. | UID00006R; C07. |
| A05 | `[4EA2A0,4EA945)` `InventoryPane::OnPaint` | Complete body/refs: vtable data xref `61C79C`; `g_pEPFLib`, UserPane inventory accessor, ItemObjImageLib glyph/draw methods, GrafPort text/tile calls, UID00006R geometry, security-cookie check; 15-entry list or 3x5 grid and legacy controls. | UID00006R; CPP UID00006R position `050`; H UID00006R position `010`. | UID00006R/UID0003BX/resource docs; C08/C31-C33. |
| A06 | `[4EA950,4EA9CC)` `InventoryPane::OnKeyEvent` | Complete body; vtable data xref `61C7B0`; EventMan key translation and bounds invalidation; Page Up/Page Down only under key-down/IME gate. | UID00006R; CPP UID00006R position `060`; H UID00006R position `010`. | UID00006R/Event support; C09/C33. |
| A07 | `[4EA9D0,4EAC88)` `InventoryPane::OnMouseEvent` | Complete body; vtable data xref `61C7AC`; calls button/slot/ordinal geometry, RectBounds point test, UserPane use, PacketBuffer writers, Socket queue/send; click mode and opcode `0x66` drag. | UID00006R; CPP UID00006R position `070`; H UID00006R position `010`. | UID00006R/PacketBuffer/Socket; C10/C33. |
| A08 | `[4EAC90,4EAE02)` `InventoryPane::OnServerMessage` | Complete body; vtable data xref `61C7B8`; PacketBuffer BE16 reads, ACP conversion, range-check route, bounds, prior-help close, SimpleHelpPane construction; bounded opcode `0x59`. | UID00006R; CPP UID00006R position `080`; H UID00006R position `010`. | UID00006R/HelpPanes/PacketBuffer; C11/C33. |
| A09 | `[4EB050,4EB126)` `InventoryPane::GetButtonRect` | Modeled helper; code refs exactly `4EA832,4EA893,4EA8EC,4EABB7`; fixed four rectangles, switch lowering follows. | UID00006R; CPP UID00006R position `090`; H UID00006R position `010`. | UID00006R/UID00018J; C12. |
| A10 | `[4EB140,4EB1B4)` `InventoryPane::GetSlotRect(short, RectBounds *) const` | Raw 116-byte body SHA256 `C86D444B068644FB103DE7CBDC6E83C029FB4AC898EC8AB4BAF51241A5C5D144`; zero inbound raw-start xrefs; low-word slot ABI, unsigned 15-slot guard, exact list/3x5 geometry, invalid rectangle, and one final `InitRectBounds` call establish source role. | UID00051B; CPP UID00051B position `100`; H UID00006R position `010`. | UID00051B plus UID00006R; coordinated UID0003EL family correction. |
| A11 | `[4EB1C0,4EB291)` `InventoryPane::HitTestButton` | Raw 209-byte body/hash in I06; zero inbound raw-start xrefs; exact four-button geometry and `-1` miss duplicate live mouse behavior. | UID00006R; CPP UID00006R position `110`; H UID00006R position `010`. | new exact by-memory child plus UID00006R; C14/C26/C55. |
| A12 | `[4EB2B0,4EB382)` `InventoryPane::HitTestSlot` | Modeled helper; code refs exactly `4EAA3C,4EAB39,4EAC4A`; calls slot geometry and RectBounds point test for 15 visible cells. | UID00006R; CPP UID00006R position `120`; H UID00006R position `010`. | UID00006R/UID00018J; C15. |
| A13 | `[4EB390,4EB414)` `InventoryPane::VisibleOrdinalToInventorySlot` | Modeled helper; code refs exactly `4EAA6B,4EAB68`; scans one-based UserPane slots and decrements only for active records. | UID00006R; CPP UID00006R position `130`; H UID00006R position `010`. | UID00006R/UserPane; C15/C32. |
| A14 | `[4EE650,4EE6A7)` `InventoryPane2::InventoryPane2` | Raw 87-byte body/hash in I07; zero direct xrefs; PanelPane construction, three compiler vptr stores, page/view/button initialization, exact CC fences. | UID00031V; CPP UID00031V position `200`; H UID00006S position `020`. | `0x004ee650-...RawConstructor.md`; C16/C26/C56. |
| A15 | `[4EE6B0,4EE6CF)` `InventoryPane2::~InventoryPane2` | Modeled ordinary destructor; no direct inbound code xref; PanelPane teardown; independently separated from scalar deletion. | UID00048P; CPP UID00048P position `210`; H UID00006S position `020`. | `0x004ee6b0-...Destructor.md`; C16. |
| A16 | `[4EE6D0,4EE6DC)` `InventoryPane2::OnActivate` | Exact 12 bytes/hash in I03; data xref exactly `61C8B8`, no code xref; identical pure activation hook, stale RefreshEmbeddedPane identity rejected. | UID00048Q; CPP UID00048Q position `220`; H UID00006S position `020`. | UID00048Q/UID0003BW; C18/C44/C47/C53/C54. |
| A17 | `[4EE6E0,4EE6E1)` `InventoryPane2::PlayItemEffect` | One-byte `ret`; zero inbound xrefs; paired source position and legacy counterpart prove an intentional authored empty method, not an emitter placeholder. | UID00048R; CPP UID00048R position `230`; H UID00006S position `020`. | `0x004ee6e0-...SourceEmptyVirtual.md`; C07/C19. |
| A18 | `[4EE6F0,4EEE5C)` `InventoryPane2::OnPaint` | Complete body; data xref `61C8B4`; ImageLib/EPFTileContext, GrafPort, ItemObjImageLib, UserPane accessor, hotkey/text, exact geometry and button resources; security-cookie check. | UID00048S; CPP UID00048S position `240`; H UID00006S position `020`. | UID00048S/resource docs; C20/C31-C33. |
| A19 | `[4EEE60,4EEEDC)` `InventoryPane2::OnKeyEvent` | Complete body; data xref `61C8C8`; EventMan key translation and inherited invalidation; bounded page changes. | UID00048T; CPP UID00048T position `250`; H UID00006S position `020`. | UID00048T/Event support; C21/C33. |
| A20 | `[4EEEE0,4EF27A)` `InventoryPane2::OnMouseEvent` | Function body ends before two-byte NOP/table; data xref `61C8C4`; direct id-2/id-3 hover rectangle checks and `[4EF030,4EF075)` source-equivalent four-id button-hit inlining use Event y at `+0x08` then x at `+0x0c`; slot/ordinal helpers, UserPane use, hover/pressed state, click policy, packet-helper semantics remain complete. There is no binary direct xref to retained A26. | UID00048U; CPP UID00048U position `260`; H UID00006S position `020`. | UID00048U plus table child; accepted UID0003EM C21/C31. |
| A21 | `[4EF290,4EF3FC)` `InventoryPane2::OnServerMessage` | Complete body; data xref `61C8D0`; PacketBuffer BE16 reads, ACP conversion, length/range failure route, help close/construction; same bounded opcode `0x59` contract. | UID00048V; CPP UID00048V position `270`; H UID00006S position `020`. | UID00048V/HelpPanes/PacketBuffer; C23/C33. |
| A22 | `[4EF400,4EF460)` `InventoryPane2::SendUseItemSlotPacketRaw` | Raw 96-byte body/hash in I08; zero inbound raw-start xrefs; PacketBuffer/Socket path emits `1C slot` and sends length 2. | UID00048W; CPP UID00048W position `280`; H UID00006S position `020`. | UID00048W; C24/C26/C57. |
| A23 | `[4EF460,4EF50B)` `InventoryPane2::SendDragDropItemPacketRaw` | Raw 171-byte body/hash in I09; zero inbound raw-start xrefs; PacketBuffer/Socket path emits opcode `66`, drag source, slot and fixed fields, length 10. | UID00048X; CPP UID00048X position `290`; H UID00006S position `020`. | UID00048X; C24/C26/C57. |
| A24 | `[4EF630,4EF702)` `InventoryPane2::GetButtonRect` | Non-static const member; code refs exactly `4EEDA9,4EEDFF,4EEF7B,4EEF88,4EF04B`, all with ECX receiver; two-argument `retn 8`; logical signed-short selector; explicit cases write `(59,259)-(81,277)`, `(112,259)-(134,277)`, `(168,66)-(185,83)`, `(168,84)-(185,101)` and default all `-1` through InitRectBounds. The following table is compiler lowering, not a static rectangle array. | UID0003EJ; CPP UID0003EJ position `300`; H UID00006S position `020`. | UID0003EJ/UID0002SV; accepted UID0003EM C20. |
| A25 | `[4EF720,4EF794)` `InventoryPane2::GetSlotRect(short, RectBounds *) const` | Raw 116-byte/45-head body SHA256 `BCB9123318AD0FC11AFA976059BAEAB5D0D1433AE892F5E5203BD57A18E8EF3D`; zero inbound raw-start xrefs and zero pointer/external-branch routes; unsigned nine-slot guard, exact list/3x3 geometry, one final `InitRectBounds` call, and complete live UID0003EO inlining with callers `4EF09A/4EF165/4EF1A4`. | UID0003EL; CPP UID0003EL position `310`; H UID00006S position `020`. | UID0003EL/UID0003EO; corrected source and live-inline proof. |
| A26 | `[4EF7A0,4EF86D)` `InventoryPane2::HitTestButton` | Raw 205-byte/78-head body with exact SHA256 above; zero inbound raw-start code/data xrefs; no modeled function/name/type/frame; y then x stack order; signed-short loop/return; one local RectBounds; exact unshifted A24 rectangles; InitRectBounds and half-open PointInRect; first hit or `-1`; two security-cookie calls are compiler support. Its switch successor is A24 inlining, and A20 supplies source-equivalent live behavior. | UID0003EM; CPP UID0003EM position `320`; H UID00006S position `020`; target H blank. | UID0003EM/UID0003EN/UID00048U; accepted UID0003EM C01-C18/C22-C24/C27/C34-C38. |
| A27 | `[4EF890,4EF962)` `InventoryPane2::HitTestSlot` | Modeled helper; code refs exactly `4EF09A,4EF165,4EF1A4`; calls slot geometry and RectBounds point test for compact visible cells. | UID0003EO; CPP UID0003EO position `330`; H UID00006S position `020`. | UID0003EO; C25. |
| A28 | `[4EF970,4EF9F4)` `InventoryPane2::VisibleOrdinalToInventorySlot` | Modeled helper; code refs exactly `4EF0C8,4EF1D6`; one-based active UserPane slot scan. | UID0003EP; CPP UID0003EP position `340`; H UID00006S position `020`. | UID0003EP/UserPane; C25/C32. |

### Compiler-Covered Item Crosswalk

| ID / exact range | Item-specific evidence and xref disposition | Owner / no-code route | Destination / claim |
| --- | --- | --- | --- |
| G01 `[4EF9F4,4EF9FF)` | Pane2 secondary-view destructor adjustor; vtable/thunk-only route, no independent authored caller contract. | UID00006S; compiler regenerates from class declaration/destructor; no formal CPP/H body. | UID0002SV/UID0003BW; C27. |
| G02 `[4EF9FF,4EFA0A)` | Pane2 tertiary-view destructor adjustor; same vtable-only adjusted-this lowering. | UID00006S; compiler-covered, no source definition. | UID0002SV/UID0003BW; C27. |
| G03 `[4EFA0A,4EFA15)` | Legacy secondary-view destructor adjustor; vtable-only adjusted-this route. | UID00006R; compiler-covered, no source definition. | UID00018J/UID0003BU; C27. |
| G04 `[4EFA15,4EFA20)` | Legacy tertiary-view destructor adjustor; vtable-only adjusted-this route. | UID00006R; compiler-covered, no source definition. | UID00018J/UID0003BU; C27. |
| G05 `[4EFA40,4EFA95)` | UID0003ER Pane2 scalar deleting destructor; ordinary dtor call plus flag-gated free, reached through ABI lifecycle slots. | UID00006S; compiler-covered marker only, no emitted body. | UID0003ER/UID0002SV; C16/C27. |
| G06 `[4EFAA0,4EFB42)` | Legacy scalar deleting destructor; vptr/base teardown plus flag-gated free, no handwritten caller contract. | UID00006R; compiler-covered marker only, no emitted body. | UID00018J/UID0003BU; C27. |

### Data And Resource Crosswalk

The complete crosswalk contains 24 physical rows: five switch tables, two RTTI/vtable families, thirteen literal/resource entries (including the zero-xref overlapping suffix view), and four internal zero-padding spans. Each row has an exact range and an explicit source/no-code disposition.

| Exact item | Evidence / xrefs and behavior | Owner / source or no-code route | Destination / claim |
| --- | --- | --- | --- |
| `[4EB128,4EB13C)` | Five-entry switch table immediately after A09; sole data xref exactly `4EB062` in A09; control-flow data for exact button rectangles. | UID00006R compiler lowering; no data definition. | UID00018J/UID00006R; C03/C27. |
| `[4EB294,4EB2A8)` | Five-entry switch table immediately after A11; sole data xref exactly `4EB1E1` inside raw A11; control-flow data for hit test. | UID00006R compiler lowering; no data definition. | UID00018J/UID00006R; C03/C27. |
| `[4EF27C,4EF290)` | Five-entry switch table after A20's true end `4EF27A`; sole data xref exactly `4EEF2F` in A20. | UID00006S compiler lowering; no data definition. | UID00048U/UID0002SU; C04/C27. |
| `[4EF704,4EF718)` | Five-entry switch table after A24; sole data xref exactly `4EF642` in A24; exact button-rectangle lowering. | UID00006S compiler lowering; no data definition. | UID0003EJ/UID0002SV; C04/C27. |
| `[4EF870,4EF884)` | Five-entry switch table after A26; 20 bytes, SHA256 `6FCD267F3BE4A21003EC3BBAF2A03040E1037A54ABCA6CFBCEE4BC152738C740`; sole inbound data xref `4EF7C1`; outbound targets `4EF80C`, `4EF7C8`, `4EF7DA`, `4EF7EC`, `4EF7FC`; no inbound code xref. | UID00006S compiler lowering of A24 inlined into A26; no rectangle-array definition. | UID0003EM/UID0003EN/UID0002SV; accepted UID0003EM C13-C16/C26. |
| `[61C754,61C7E0)` | InventoryPane RTTI/three vtable views; family head `61C754` has zero direct xrefs; activation slot `61C7A0` has the exact A03 data xref, and lifecycle store triads establish the views; former `61C7A4` start underbroad. | UID0003BU/UID00006R; compiler generated from H/virtual definitions, no arrays. | UID00025L/UID0003BU/UID0003BT; C27/C43. |
| `[61C86C,61C8F8)` | InventoryPane2 RTTI/three vtable views; family head `61C86C` has zero direct xrefs; activation slot `61C8B8` has the exact A16 data xref, while paint/key/mouse/server slots and lifecycle stores establish the views. | UID0003BW/UID00006S; compiler generated, no arrays. | UID0003BW; C27/C44. |
| `[61C8F8,61C910)` `ITEMINV.EPD` | Exact 24-byte UTF-16 object; sole xref `4EA2F7` in A05. The overlapping suffix head at `61C900` is not a second allocation. | Shared UID0003BX literal; source operand only at the exact consumer. | UID0003BX/resource docs; C31. |
| `[61C900,61C910)` `INV.EPD` suffix view | Exact overlapping 16-byte suffix-compatible view; zero direct xrefs and no independent owner/caller route. | UID0003BX physical decode only; no additional source literal or data definition. | UID0003BX; C31. |
| `[61C910,61C924)` `NPAL6.PAL` | Exact 20-byte UTF-16 object; all seven xrefs are `4EA303,4EA854,4EA8AF,4EA911,57C494,57C672,57C6DC`. | Shared UID0003BX palette literal at A05 and resource-loader consumers. | UID0003BX/resource docs; C31. |
| `[61C924,61C92E)` `%c: ` | Exact 10-byte UTF-16 format object; xrefs exactly `4EA4D2` in A05 and `4EE910` in A18. | Source format operand at both exact consumers; no standalone data definition. | UID0003BX; C31. |
| `[61C92E,61C930)` | Two zero bytes, zero xrefs. | UID0003BX literal alignment; no code/data source statement. | UID0003BX gap evidence; C27/C31. |
| `[61C930,61C94A)` `SPELLBUT.EPD` | Exact 26-byte UTF-16 object; all five xrefs are `4EA846,4EA8A3,4EA905,57C666,57C6D0`. | Shared UID0003BX operand at A05 and loader consumers. | UID0003BX/resource docs; C31. |
| `[61C94A,61C94C)` | Two zero bytes, zero xrefs. | UID0003BX literal alignment; no source statement. | UID0003BX gap evidence; C27/C31. |
| `[61C94C,61C964)` `ITEMINV.EPF` | Exact 24-byte UTF-16 object; all four xrefs are `4EBBC7,4EC10C,4EE754,4EEA95`; only the latter two are A18. | Shared UID0003BX operand emitted at exact NewInventoryPane/Pane2 consumers. | UID0003BX/resource docs; C29/C31. |
| `[61C964,61C97C)` `ITEMINV.PAL` | Exact 24-byte UTF-16 object; 12 total xrefs. Inventory refs are `4EBBDF,4EC124,4EE760,4EEAA1`; the other eight are `56757A,56CEB9,56EE2B,56FDF9,57D4B1,57EB44,588DB3,5B8CDC`. | Shared UID0003BX palette operand; only `4EE760/4EEAA1` belong to A18 and no file-private data object exists. | UID0003BX/resource docs; C31. |
| `[61C97C,61C996)` `ITEMINVE.EPF` | Exact 26-byte UTF-16 object; all four xrefs are `4EBBCD,4EC112,56CF42,57D4A4`; no legacy or Pane2 xref. | Shared UID0003BX literal excluded from UID0000KA source; NewInventoryPane/later consumers emit it. | UID0003BX/UID0000LS; C29/C31. |
| `[61C996,61C998)` | Two zero bytes, zero xrefs. | UID0003BX literal alignment; no source statement. | UID0003BX gap evidence; C27/C31. |
| `[61C998,61C9A8)` `...(%d)` | Exact 16-byte UTF-16 object; sole xref `4EBF49` in NewInventoryPane and no UID0000KA authored-body xref. | UID0000LS use-site; UID0003BX physical map only. | UID0003BX/UID0000LS; C29/C31. |
| `[61C9A8,61C9C2)` `INVENBUT.EPF` | Exact 26-byte UTF-16 object; 24 total xrefs. NewInventoryPane uses `4EC67F,4EC6DE,4EC739,4EC7FF,4EC868,4EC8D1`; A18 uses `4EEDC5,4EEE1C`; the other 16 are `5412C4,5412D9,5412EE,541303,541318,54132D,567929,567984,568A80,568B07,568B64,56D960,56D98C,57D885,5A14EB,5A1537`. | Shared UID0003BX operand emitted only at exact consumer sites. | UID0003BX/resource docs; C31. |
| `[61C9C2,61C9C4)` | Two zero bytes, zero xrefs; successor at `61C9C4` is KeySpeedMgr RTTI/vtable data. | UID0003BX terminal alignment; no source statement. | UID0003BX/UID00031P boundary; C27/C31. |
| `[61C6C0,61C6D6)` `INTEFX.PAD` | Exact 22-byte UTF-16 object; all seven xrefs are `4E9D94,4E9DD8,4E9E20,4E9F83,4E9FCA,4EA1AC,57C349`; A01 owns only `4EA1AC`. | UID0003BT/interface-efx-resources shared operand; A01 preserves it at its use site. | InterfaceEfx resource docs/UID00006R; C05/C33. |
| `[61C708,61C720)` `ITEMEFX.EPD` | Exact 24-byte UTF-16 object; xrefs exactly `4E9E38` and A01 `4EA1C4`. | UID0003BT shared operand; A01 emits its source use and does not define storage. | InterfaceEfx resource docs/UID00006R; C05/C33. |
| `[60DDF8,60DE0E)` `BUTTON.PAL` | Exact 22-byte UTF-16 shared literal; 29 total xrefs. A18 consumes it exactly at `4EEDD1,4EEE28`; the other 27 are cross-module render consumers and explicitly reject UID0000KA-private ownership. | Existing shared render/resource owner; source operand only at UID00048S use sites. | UID00048S/render resource docs; C20/C33. |

### Explicit Exclusion Crosswalk

| Exact range/item | Evidence / xref disposition | Owner and disposition | Destination / claim |
| --- | --- | --- | --- |
| `[4EAF20,4EB044)` | Complete BackPane help V1 body between legacy islands; own help callers/semantics. | UID00018K/BackPane; no UID0000KA code. | UID00018J split; C28. |
| `[4EDE80,4EDFA4)` | Complete BackPane help V2 body, not contiguous with an InventoryPane class island. | UID00018L/BackPane; excluded. | UID00018J split; C28. |
| `[4EF510,4EF62E)` | Complete BackPane help V3 body after Pane2 packet island. | UID00018M/BackPane; excluded. | UID00018J/UID0002SU split; C28. |
| `[4EB420,4EE643)` plus `[4EFB50,4EFBB7)` | NewInventoryPane authored family and its scalar wrapper, with independent constructor/caller/resource route. | UID0000LS/UID000093; separate `NewInventoryPane.cpp`. | UID0000LS boundary; C29. |
| `[563260,56470C)` | ScrollInventoryPane family; sole NewInventoryPane companion/caller relationship. | UID0000KB/UID0000CK; separate `InventoryScrollPane.cpp`. | UID0000KB boundary; C30. |
| `[4EFA20,4EFA2B)`, `[4EFA2B,4EFA36)` | NewInventoryPane secondary/tertiary destructor adjustors. | UID000093 compiler coverage under UID0000LS; excluded. | UID00018J/UID0000LS; C27/C29. |
| `[4EFB50,4EFBB7)` | NewInventoryPane scalar deleting destructor. | UID000093 compiler coverage under UID0000LS; excluded. | UID00018J/UID0000LS; C27/C29. |
| `[61C7E0,61C86C)` | NewInventoryPane RTTI/vtable family between legacy and Pane2 data. | UID0003BV/UID000093 compiler data; excluded. | UID00025L/UID0000LS; C27/C29. |
| `[61C750,61C754)` | Unreferenced compiler-adjacent dword before corrected legacy COL. | No source definition; remain outside UID0003BU. | UID0003BT/UID00025L history; C43. |
| `61C9C4 successor` | KeySpeedMgr COL begins at the exclusive end of UID0003BX. | KeySpeedMgr owner; excluded. | UID0003BX boundary; C31. |

### Complete Gap, Padding, Table, And Duplicate-Body Inventory

Every byte span between the item heads above receives a source disposition. The two release duplicate packet bodies are preserved as byte/evidence rows but do not create definitions A29/A30: A07 already contains their exact behavior inline, their starts have no inbound route, and emitting separate helpers would duplicate release behavior not represented by a caller.

| Exact span | Bytes/classification | Owner / source disposition | Covered by / claim |
| --- | --- | --- | --- |
| `[4EA202,4EA210)` | 14 `CC` bytes | legacy alignment, no code/data source | A01/A02 boundary; C03. |
| `[4EA271,4EA280)` | 15 `CC` bytes | legacy alignment | A02/A03; C03. |
| `[4EA28C,4EA290)` | 4 `CC` bytes | legacy alignment | A03/A04; C03. |
| `[4EA29B,4EA2A0)` | 5 `CC` bytes | legacy alignment | A04/A05; C03. |
| `[4EA945,4EA950)` | 11 `CC` bytes | legacy alignment | A05/A06; C03. |
| `[4EA9CC,4EA9D0)` | 4 `CC` bytes | legacy alignment | A06/A07; C03. |
| `[4EAC88,4EAC90)` | 8 `CC` bytes | legacy alignment | A07/A08; C03. |
| `[4EAE02,4EAE10)` | 14 `CC` bytes | end-of-island alignment | A08/duplicate helper; C03. |
| `[4EAE10,4EAE70)` | 96-byte raw opcode `0x1C`/length-2 packet body; zero retained route | release duplicate raw body; no extra definition, behavior covered inline by A07 and PacketBuffer/Socket dependencies | UID00018J history; C03/C10/C26. |
| `[4EAE70,4EAF14)` | 164-byte raw opcode `0x66`/length-10 packet body; zero retained route | release duplicate raw body; no extra definition, behavior covered inline by A07 | UID00018J history; C03/C10/C26. |
| `[4EAF14,4EAF20)` | 12 `CC` bytes | fence before BackPane V1 | A08/UID00018K boundary; C28. |
| `[4EAF20,4EB044)` | BackPane V1 source body | excluded source, UID00018K | exclusion row; C28. |
| `[4EB044,4EB050)` | 12 `CC` bytes | fence before A09 | UID00018K/A09; C03/C28. |
| `[4EB126,4EB128)` | `66 90` two-byte NOP | compiler alignment | A09 table boundary; C27. |
| `[4EB128,4EB13C)` | five-entry switch table | compiler control-flow data | A09; C27. |
| `[4EB13C,4EB140)` | 4 `CC` bytes | alignment | A09/A10; C03. |
| `[4EB1B4,4EB1C0)` | 12 `CC` bytes | raw-helper alignment | A10/A11; C03. |
| `[4EB291,4EB294)` | `0F 1F 00` three-byte NOP | compiler alignment | A11/table; C27. |
| `[4EB294,4EB2A8)` | five-entry switch table | compiler control-flow data | A11; C27. |
| `[4EB2A8,4EB2B0)` | 8 `CC` bytes | alignment | table/A12; C03. |
| `[4EB382,4EB390)` | 14 `CC` bytes | alignment | A12/A13; C03. |
| `[4EB414,4EB420)` | 12 `CC` bytes | end-of-legacy-island fence | A13/NewInventoryPane; C03/C29. |
| `[4EE643,4EE650)` | 13 `CC` bytes | fence before Pane2 ctor | UID0000LS/A14; C04. |
| `[4EE6A7,4EE6B0)` | 9 `CC` bytes | Pane2 alignment | A14/A15; C04. |
| `[4EE6CF,4EE6D0)` | 1 `CC` byte | Pane2 alignment | A15/A16; C04. |
| `[4EE6DC,4EE6E0)` | 4 `CC` bytes | Pane2 alignment | A16/A17; C04. |
| `[4EE6E1,4EE6F0)` | 15 `CC` bytes | Pane2 alignment | A17/A18; C04. |
| `[4EEE5C,4EEE60)` | 4 `CC` bytes | Pane2 alignment | A18/A19; C04. |
| `[4EEEDC,4EEEE0)` | 4 `CC` bytes | Pane2 alignment | A19/A20; C04. |
| `[4EF27A,4EF27C)` | two-byte NOP | A20 end alignment | A20/table; C27. |
| `[4EF27C,4EF290)` | five-entry switch table | A20 compiler lowering | UID00048U; C27. |
| `[4EF3FC,4EF400)` | 4 `CC` bytes | alignment | A21/A22; C04. |
| `[4EF50B,4EF510)` | 5 `CC` bytes | fence before BackPane V3 | A23/UID00018M; C04/C28. |
| `[4EF510,4EF62E)` | BackPane V3 source body | excluded source, UID00018M | exclusion row; C28. |
| `[4EF62E,4EF630)` | 2 `CC` bytes | fence after BackPane V3 | UID00018M/A24; C04/C28. |
| `[4EF702,4EF704)` | two-byte NOP | A24 end alignment | A24/table; C27. |
| `[4EF704,4EF718)` | five-entry switch table | A24 compiler lowering | UID0003EJ; C27. |
| `[4EF718,4EF720)` | 8 `CC` bytes | alignment | table/A25; C04. |
| `[4EF794,4EF7A0)` | 12 `CC` bytes | raw-helper alignment | A25/A26; C04. |
| `[4EF86D,4EF870)` | three-byte NOP, SHA256 `019F07BFE6BD5747F9F3B65F5A095DB04A0418D5F11C6FEEC58EAFF709860B66` | A26 end alignment | A26/UID0003EN; accepted UID0003EM C13. |
| `[4EF870,4EF884)` | five-entry switch table, exact hash above | A26 compiler lowering of inlined A24 | UID0003EM/UID0003EN; accepted UID0003EM C13-C16/C26. |
| `[4EF884,4EF890)` | 12 `CC` bytes, SHA256 `A0D08A155AA4E9AADD5DA959565DE99ACC8DC9DBDA96EC3852DDE76C97330902` | alignment | UID0003EN/A27; accepted UID0003EM C13. |
| `[4EF962,4EF970)` | 14 `CC` bytes | alignment | A27/A28; C04. |
| `[4EF9F4,4EFA20)` | four 11-byte destructor adjustors | G01-G04 compiler bodies, no source definitions | class/vtable coverage; C27. |
| `[4EFA20,4EFA36)` | two NewInventoryPane 11-byte adjustors | excluded UID000093 compiler bodies | UID0000LS; C27/C29. |
| `[4EFA36,4EFA40)` | 10 `CC` bytes | compiler-wrapper alignment | excluded adjustors/G05; C27. |
| `[4EFA40,4EFA95)` | Pane2 scalar deleting destructor | G05 compiler body | UID0003ER; C16/C27. |
| `[4EFA95,4EFAA0)` | 11 `CC` bytes | compiler-wrapper alignment | G05/G06; C27. |
| `[4EFAA0,4EFB42)` | legacy scalar deleting destructor | G06 compiler body | UID00006R; C27. |
| `[4EFB42,4EFB50)` | 14 `CC` bytes | compiler-wrapper fence | G06/New scalar; C27/C29. |
| `[4EFB50,4EFBB7)` | NewInventoryPane scalar deleting destructor | excluded UID000093 compiler body | UID0000LS; C27/C29. |
| `[4EFBB7,4EFBC0)` | 9 `CC` bytes | final compiler-wrapper alignment | successor boundary; C27/C29. |
| `[61C92E,61C930)` | two zero bytes | UID0003BX UTF-16 literal alignment, zero xrefs, no source statement | `%c: `/`SPELLBUT.EPD` boundary; C27/C31. |
| `[61C94A,61C94C)` | two zero bytes | UID0003BX UTF-16 literal alignment, zero xrefs, no source statement | `SPELLBUT.EPD`/`ITEMINV.EPF` boundary; C27/C31. |
| `[61C996,61C998)` | two zero bytes | UID0003BX UTF-16 literal alignment, zero xrefs, no source statement | `ITEMINVE.EPF`/`...(%d)` boundary; C27/C31. |
| `[61C9C2,61C9C4)` | two zero bytes | UID0003BX terminal literal alignment, zero xrefs, no source statement | `INVENBUT.EPF`/KeySpeedMgr boundary; C27/C31. |

Exact raw geometry:

- Legacy buttons: 0 `(59,259)-(81,277)`; 1 `(112,259)-(134,277)`; 2 `(81,259)-(103,277)`; 3 `(104,259)-(112,277)`.
- Legacy slots: list indices 0..14 `(30,46+13i)-(160,59+13i)`; grid `(40+45c,40+41r)-(75+45c,75+41r)`.
- Pane2 buttons for drawing and event-space hit testing: 0 `(59,259)-(81,277)`; 1 `(112,259)-(134,277)`; 2 `(168,66)-(185,83)`; 3 `(168,84)-(185,101)`. No `+256` y translation occurs.
- Pane2 slots: list indices 0..8 `(2,23+23i)-(160,46+23i)`; grid `(9+51c,18+51r)-(57+51c,66+51r)`.

Both retained slot-rectangle bodies load only the low word of the logical slot, zero-extend it for the range guard, sign-extend it only for accepted-coordinate arithmetic, and converge invalid/list/grid paths on one free `InitRectBounds` call. The former source drafts used `int` and valid-path `RectBounds::SetLTRB`; those forms are historical and rejected because `SetLTRB` is a distinct real function not called by either raw body. `InventoryPane2::m_viewMode` remains a dword-sized `int`: zero is `kListView` and any nonzero value selects the grid path; `kGridView` is source vocabulary, not evidence for narrowing the field to an enum.

Historical pre-UID0003EM source modeled A24/A26 as static int helpers, called A26 x-first, invented rectangle arrays, treated generated calls as direct binary xrefs, and shifted button 2/3 y coordinates by `+256`. Those forms are superseded by the accepted member ABI, exact unshifted values, local control-flow tables, and A20 inlining; they remain dated history and do not alter the 28-definition inventory or source route.

## Direct Xref / Caller Inventory

| Item | Complete inbound/source relationship and material callees |
| --- | --- |
| Legacy ctor/dtor | No ordinary direct inbound xrefs; construction is vtable/factory-lowered. Callees: PanelPane construction/teardown, allocator, InterfaceEfx construction/lifetime. |
| `4EA280` | One data xref from primary vtable `61C7A0`; indirect invalidate only. |
| `4EA290` | Zero inbound xrefs; calls InterfaceEfx playback and is retained by paired source-order evidence. |
| Legacy paint | Data xref `61C79C`; material calls resource lookup, EPD/palette rendering, UserPane slot accessor, image/text/rect helpers, GetButtonRect, security-cookie check. |
| Legacy key | Data xref `61C7B0`; calls event-key translation and pane invalidation. |
| Legacy mouse | Data xref `61C7AC`; calls GetButtonRect, HitTestSlot, visible map, PointInRect, UserPane item use, packet byte/BE16 writers, Socket queue/send. |
| Legacy server | Data xref `61C7B8`; calls narrow-char lowering, BE16 reads, MultiByteToWideChar, range-check failure, bounds, prior-help close, allocation, SimpleHelpPane constructor. |
| `4EB050` | Code refs `4EA832`, `4EA893`, `4EA8EC`, `4EABB7`; rect construction/PointInRect. |
| `4EB140`, `4EB1C0` | Zero inbound xrefs each; source role established by exact duplicated geometry and surrounding helper family. |
| `4EB2B0` | Code refs `4EAA3C`, `4EAB39`, `4EAC4A`; rect and PointInRect. |
| `4EB390` | Code refs `4EAA6B`, `4EAB68`; UserPane slot accessor. |
| Pane2 raw ctor/dtor | No direct inbound xrefs; constructor has PanelPane call and vptr/state stores; destructor calls base teardown. |
| `4EE6D0` | One data xref `61C8B8`; indirect invalidate only. |
| `4EE6E0` | Zero inbound xrefs; intentional empty counterpart. |
| Pane2 paint | Data xref `61C8B4`; resource lookup/render, UserPane slot accessor, image/text/button geometry, security cookie. |
| Pane2 key | Data xref `61C8C8`; key translation/invalidation. |
| Pane2 mouse | Data xref `61C8C4`; direct A24 calls at `4EEF7B/4EEF88` for hover and inlined four-id button-hit source route `[4EF030,4EF075)` with A24 call `4EF04B` and PointInRect `4EF05A`; Event y/x order, slot geometry, active-slot map, item use, and raw packet semantics. No direct A26 raw-start xref. |
| Pane2 server | Data xref `61C8D0`; same bounded help dependency set as legacy. |
| `4EF400`, `4EF460` | Zero inbound raw-start xrefs; direct packet writers and Socket sender behavior. |
| `4EF630` | Refs `4EEDA9`, `4EEDFF`, `4EEF7B`, `4EEF88`, `4EF04B`; every call prepares the InventoryPane2 receiver in ECX. |
| `4EF720`, `4EF7A0` | Zero inbound raw-start xrefs; UID0003EO and UID00048U respectively inline the complete source behavior, so retained copies remain authored definitions rather than dead/compiler-only bodies. |
| `4EF890` | Refs `4EF09A`, `4EF165`, `4EF1A4`. |
| `4EF970` | Refs `4EF0C8`, `4EF1D6`; UserPane slot accessor. |
| Compiler wrappers | Vtable/thunk-only routes; no authored caller contract. |
| Resource strings | `ITEMINV.EPD`, `NPAL6.PAL`, `%c: `, `SPELLBUT.EPD`, `ITEMINV.EPF`, `ITEMINV.PAL`, `ITEMINVE.EPF`, `...(%d)`, `INVENBUT.EPF` cross legacy/new/Pane2/resource consumers; use-site literals, not one owner object. |

## Documentation Evidence And IDA Status

- Current target/class/aggregate docs preserve exact ranges, hashes, behavior, ABI, ownership research, and the implemented 28-definition/two-declaration source route. UID0003EL's short-slot/one-final-InitRectBounds correction and UID0003EM's signed-short y/x/member/inlining correction coexist in the complete owner H and fixed source order. Superseded final-source blockers and the broad-file alternative are retained only in dated history.
- Existing Pane2 exact children remain the sole definition emitters at positions `200-340`. UID00048Q is implemented as `InventoryPane2::OnActivate(const unsigned char *)`; UID00048R's intentional source-empty `PlayItemEffect` body remains valid.
- UID0003BU and UID00025L omit the primary legacy RTTI/vtable view because they begin at `0x61C7A4`. The corrected start is `0x61C754`; `0x61C750-0x61C754` remains an unreferenced compiler-adjacent dword and must not be silently absorbed into the string literal.
- Generated-output contract is source-complete: one `InventoryPane.cpp` contains all 28 authored definitions in positions `010-340`, one `InventoryPane.h` contains both complete declarations, and no class empty marker remains. UID0003EM callback verification additionally requires one corrected A24 definition, one corrected A26 definition, y/x A20 call expressions, no duplicate, no static rectangle array, and the exact three owner declarations; the pre-callback int/static/x-first source is historical evidence only.
- Manual coverage rows are stale snapshots and remain supervisor-owned. Generated/autogen reports are validator-owned and were not edited.

## Ranked Ownership Analysis

### 1. UID0000KA InventoryPane.cpp

- Evidence for: both legacy and Pane2 use PanelPane, the same inventory record/accessor, page/view model, item resource family, help protocol, three-view pane ABI, source-adjacent method order, and the existing single by-file route.
- Evidence against: stripped symbols cannot prove the retail filename, and Pane2 has no direct constructor xref.
- Decision: strongest owner for the 28 authored items. Raw constructor liveness uncertainty does not outweigh class/source cohesion.

### 2. UID0000LS NewInventoryPane.cpp with UID0000KB scrollbar companion

- Evidence for: independent constructor caller, substantially different scroll/list behavior, private scrollbar allocation at `4EB4E4`, separate ScrollInventoryPane code/vtables/layout, established by-file routes.
- Evidence against: physical code/resource adjacency with legacy and Pane2.
- Decision: keep separate. Linker locality is not source ownership.

### 3. One broad InventoryPane.cpp or separate InventoryPane2.cpp

- Broad-file evidence: common subsystem/resources and physical neighborhood.
- Separate-Pane2 evidence: class variant and raw constructor island.
- Evidence against both: New/scroll independent routes defeat the broad file; Pane2 has no independent source caller/resource/data island and already shares the legacy file route.
- Decision: reject both alternatives.

### Proposed grouping

- `NexusTK/ui/inventory/InventoryPane.cpp`: `InventoryPane`, `InventoryPane2`, their authored helpers only.
- `NexusTK/ui/inventory/InventoryPane.h`: both complete class declarations.
- `NexusTK/ui/inventory/NewInventoryPane.cpp`: remains UID0000LS.
- `NexusTK/ui/inventory/InventoryScrollPane.cpp`: remains UID0000KB; a later evidence-backed private fold may target NewInventoryPane only.

## Source Placement

- Recommended placement is `NexusTK/ui/inventory/InventoryPane.cpp` plus sibling `InventoryPane.h`.
- Source order and routing are fixed, not optional: UID00006R formal CPP positions `010-130` emit A01-A13; UID00031V/UID00048P/UID00048Q/UID00048R/UID00048S/UID00048T/UID00048U/UID00048V/UID00048W/UID00048X/UID0003EJ/UID0003EL/UID0003EM/UID0003EO/UID0003EP formal CPP positions `200-340` emit A14-A28 in that order. UID00006R formal H position `010` and UID00006S formal H position `020` emit the only two class declarations. Compiler vtables/thunks/scalar destructors/tables/padding emit nowhere.
- Within that fixed order, UID00051B/A10 at `100` and UID0003EL/A25 at `310` each emit `GetSlotRect(short, RectBounds *) const` with a single final `InitRectBounds` call. Their target H channels stay blank; UID00006R and UID00006S own the two declarations.
- Shared Socket, UserPane, PanelPane, InterfaceEfx, SimpleHelpPane, packet-buffer, resource, and rendering declarations remain includes/forward declarations from their owning modules.
- Rejected placements: generic controls, HelpPanes, Socket/protocol, UserPane, NewInventoryPane, ScrollInventoryPane, one-class generated files, and an isolated raw-helper source.

## Range / Split / Padding / Reclassification Analysis

- Legacy authored-definition islands are `[4EA130,4EAE02)` and `[4EB050,4EB414)`. BackPane V1 is excluded. The byte-complete gap inventory above additionally classifies the two zero-route release duplicate packet bodies at `[4EAE10,4EAF14)` as non-emitted duplicates of A07 rather than silently treating them as padding or adding definitions 29/30.
- Pane2 source islands are `[4EE650,4EF50B)` and `[4EF630,4EF9F4)`. BackPane V3 `[4EF510,4EF62E)` and its two-byte fence are excluded; compiler tail begins at `4EF9F4`.
- NewInventoryPane code and scalar wrapper remain separate even where physically interleaved after Pane2/legacy wrappers.
- Legacy read-only data must be repaired additively: history records `0x61C7A4` as the former underbroad start; current evidence moves the exact family to `[0x61C754,0x61C7E0)` with three views.
- No source-authored global/static storage definition belongs to this file. The 13 source-only constants in the formal CPP are internal-linkage compile-time values, the resource strings remain use-site literal operands, and switch tables/vtables/RTTI are regenerated from control flow and class declarations.


Formal-source external-symbol closure:

| Former or retained symbol | Exact resolution and declaration owner |
| --- | --- |
| `InventoryImageSet`, `DrawInventoryGridItem`, `DrawInventoryListItem`, `DrawInventoryHotkey`, `DrawLegacyInventoryButton` | Removed from formal source. Their behavior is written directly in A05/A18 with `ItemObjImageLib`, `GrafPort`, `ImageLib`, and local stack values; no invented external interface remains. |
| `EpfFrame`, `LoadEpfFrame`, `DrawEpfFrame` | Removed. Formal source uses `EPFTileContext`, `ImageLib::CopyEntryTileContext`, and inherited `GrafPort::RenderTileFrame`, declared by UID00004I/UID00006E/UID00005V in `render/EPFTileContext.h`, `render/ImageLib.h`, and `render/GrafPort.h`. |
| `WritePacketByte`, `WritePacketUInt16BE`, `ReadPacketUInt16` | Removed. Exact declarations are `PacketBufferWriteUInt8`, `PacketBufferWriteUInt16BE`, and `PacketBufferReadUInt16BE` from UID0003YJ/UID0003YK in UID0000M8 `network/PacketBuffer.h`; value precedes destination. |
| `Rect`, `PtInRect`/wrong-form `PointInRect` | Removed. Formal source uses `RectBounds`, `InitRectBounds`, and `PointInRect(y,x,&bounds)` from UID0000BU/UID00015S in UID0000N2 `ui/core/RectBounds.h`. |
| `SlotIndexToHotkeyLetter` | Removed as an undeclared call. A05/A18 use the exact `0x005a4090` mapping inline: slots `1..26 -> a..z`, `27..52 -> A..Z`, otherwise space. |
| `NarrowInputEventByte` | Removed. A06/A19 call the exact existing member declaration `unsigned char EventMan::TranslateEventKey(unsigned char key, unsigned char modifiers)` at `0x004a8b10`; UID00004O owns the class and UID0000J6 emits that declaration plus `extern EventMan *g_pEventMan;` in `ui/core/Event.h`. This report does not invent a free narrow helper. |
| `PaneKeyEvent`, `PaneMouseEvent`, `ServerPaneMessage` | Replaced by the complete UID00004L `Event` declaration from UID0000J6 `ui/core/Event.h`: the formal source reads `m_type` and the exact `m_payload.m_key`, `m_payload.m_pointer`, and `m_payload.m_packet` union members; no local event proxy remains. |
| `g_pItemObjImageLib` and draw/glyph methods | UID0000RA/UID00006W own `extern ItemObjImageLib *g_pItemObjImageLib;`, `GetItemGlyphBounds`, `DrawItemImage`, and `DrawItemImageIn43x43Slot` in UID0000KH `render/ItemObjImageLib.h`, with the argument forms used by A05/A18. No file-local proxy remains. |
| `g_pEPFLib` and lookup/copy API | UID00006E/UID0000K2 own `extern ImageLib *g_pEPFLib;`, `ImageLib::GetBounds`, and `ImageLib::CopyEntryTileContext` in `render/ImageLib.h`; UID00004I owns `EPFTileContext` in `render/EPFTileContext.h`. No file-local resource wrapper remains. |
| inherited render/pane calls | UID00005V `render/GrafPort.h` supplies `MoveTo`, `SetTextColor`, `DrawWideText`, and `RenderTileFrame`; UID0000A4/UID0000ME PanelPane/Pane declarations supply `InvalidateRect(const RectBounds *)`, `NotifyPaneMessageHandled()`, and inherited `Close(bool)`. These are receiver-bearing inherited calls, not UID0000KA helpers. |
| `m_visibleBounds` | UID00005V `render/GrafPort.h` declares protected `RectBounds GrafPort::m_visibleBounds`; UID0000A2 `ui/core/Pane.h` includes that header and derives `Pane` from `GrafPort`, then UID0000A4 `PanelPane` and both inventory classes continue the public inheritance chain. The source uses the inherited `+0x44` member directly. Neither `InventoryPane` nor `InventoryPane2` declares a duplicate bounds field; the former pane-local embedded-bounds alias is rejected history. |
| `g_packetSender`/`Socket::QueueAndSendPacket` and `PacketBuffer` | UID0000Q5/UID0000DD emit the sender/global and `QueueAndSendPacket(PacketBuffer *, int)` through UID0000NS `network/Socket.h`. UID0003YJ/UID0003YK emit `PacketBuffer`, `PacketBufferWriteUInt8`, `PacketBufferWriteUInt16BE`, and `PacketBufferReadUInt16BE` through UID0000M8 `network/PacketBuffer.h`; scalar value precedes buffer destination exactly as used here. |
| `g_pUserPane`, `LocalInventorySlotRecord`, accessor/use methods | UID0000FQ/UID0000P1 `ui/panels/UserPane.h` supplies `extern UserPane *g_pUserPane;`, the complete `LocalInventorySlotRecord`, `LocalInventorySlotRecord *GetInventorySlotAddress(char inventorySlot)`, and `void UseInventorySlot(unsigned char slot)`. The same owner must expose the already-documented field-safe declaration `bool IsInputLocked() const` over `m_inputLocked`; the formal source never reads a raw UserPane offset. |
| `InterfaceEfx` | UID00006N/UID0000K9 `ui/InterfaceEfx.h` owns the constructor form used here, `void Play()`, and inherited lifetime call `MarkForDeletion()`; UID0000KA only stores and invokes the pointer. The accepted owner header supplies these declarations, so no local class or unresolved blank declaration remains. |
| `g_mainUiLayerSlots` | Current canonical UID0000T6/UID0000L1 MainUiGraph support owns `MainUiLayerSlots`, `extern MainUiLayerSlots g_mainUiLayerSlots;`, and declared `rootPaneLayerContext`. The callback corrected the report's historical Application-support binding to physical owner header `ui/MainUiGraph.h`; Application/BaramApp remains a lifecycle consumer, not the declaration owner. UID0000KA defines no storage. |
| `SimpleHelpPane`/`g_pSimpleHelpPane` | UID0000D6/UID0000JU physical owner header `ui/controls/HelpPanes.h` owns `SimpleHelpPane(const wchar_t *, Pane *, int, int, int)` and `Close(bool)`; UID0000S9 owns the singleton declaration `extern SimpleHelpPane *g_pSimpleHelpPane;`. The accepted callback corrected the earlier proposed `SimpleHelpPane.h` spelling to the validator's actual by-file header route; no local duplicate class/global is proposed. |
| `g_pConfig->m_doubleClickEnabled` | UID000031/UID0000IE `config/Config.h` owns the complete `Config` declaration containing `unsigned char m_doubleClickEnabled` and the existing `extern Config *g_pConfig;`; UID0000KA includes but never defines either. |
| CRT/Win32 calls | Standard `<wchar.h>`/Windows declarations own `wcslen` and `MultiByteToWideChar`; they are direct platform dependencies, not project helpers or emitted UID0000KA declarations. |

The external-symbol map is part of the callback contract: a validator-generated build must resolve every retained name from the stated owner header, and a missing declaration is a Gate 2A failure rather than permission to add another descriptive shim.

## Accepted Source Route And Generated Contract

- UID00006R is the owning emitter at position `010`. It emits authored definitions A01-A09 directly, inserts UID00051B at position `100` and UID00051H at position `110`, then emits A12-A13 directly. Its formal H channel supplies the first complete class declaration at header position `010`.
- UID00006S is the second owning emitter at position `020`. Its direct CPP body is intentionally only `[[CHILDREN]]`; UID00031V and UID00048P-UID00048X plus UID0003EJ/UID0003EL/UID0003EM/UID0003EO/UID0003EP emit A14-A28 at positions `200` through `340`. Its formal H channel supplies the second complete class declaration at header position `020`.
- The deterministic generated contract is one `NexusTK/ui/inventory/InventoryPane.cpp` with exactly 28 authored definitions in A01-A28 order and one `NexusTK/ui/inventory/InventoryPane.h` with exactly two complete declarations in `InventoryPane`, `InventoryPane2` order.
- Generated `InventoryPane.cpp` must contain exactly one corrected UID00051B definition and one corrected UID0003EL definition, both using logical `short` and one final `InitRectBounds`; neither may retain valid-path `SetLTRB`. Generated `InventoryPane.h` must declare the legacy and Pane2 `GetSlotRect(short, RectBounds *) const` methods exactly once each.
- Generated `InventoryPane.cpp` must also contain exactly one UID0003EJ definition with signed-short selector/const member/explicit cases, exactly one UID0003EM signed-short y/x const-member definition at position `320`, and y/x A20 call expressions. It must contain no UID0003EM static rectangle array, no `+256` button-2/3 coordinates, and no duplicate definitions. Generated `InventoryPane.h` must declare `GetButtonRect(short, RectBounds *) const`, `GetSlotRect(short, RectBounds *) const`, and `HitTestButton(int y, int x) const` exactly once in InventoryPane2.
- G01-G06 compiler thunks/tables/vtables/RTTI, all release-duplicate packet bodies, `BackPane`, `NewInventoryPane`, `ScrollInventoryPane`, and invented descriptive wrappers remain non-emitting. UID00048R emits a real intentional empty `InventoryPane2::PlayItemEffect` body; it is not an empty-emitter marker.
- The exact external-symbol closure above is binding for the formal source. Each symbol resolves through its documented owner header or accepted local declaration; no descriptive shim is introduced.

## Changes

- 2026-08-15 B001 UID0003EM accepted callback:
  - Preserved B006's complete UID0003EL short-slot/single-InitRectBounds work and reconciled A20/A24/A26 to the accepted non-static const-member, signed-short, y/x, first-hit, and inlined-table contract. Added exact target/successor hashes, geometry, xrefs, source order, historical static/int/x-first/static-array/`+256` dispositions, and deterministic CPP/H readback expectations. File score/owner/path and complete 28-definition/two-declaration route remain `94/94`, `FILE`, and `NexusTK/ui/inventory/`.
- 2026-08-15 B006 UID0003EL accepted callback:
  - Synchronized A25 and coordinated legacy A10 to the exact short-slot/one-final-InitRectBounds source contract; added UID0003EL binary identity, boundary and zero-route context, complete UID0003EO inline liveness, family analogs, fixed source positions/declaration owners, and deterministic generated CPP/H expectations. File score/owner/path remain `94/94`, `FILE`, and `NexusTK/ui/inventory/`.
- 2026-08-15 B001 UID0000KA accepted implementation callback:
  - Raised `86/88` to `94/94`; incorporated the complete 28-authored-definition, six-compiler-row, resource/data, exclusion, and 56-gap inventories; added permanent raw children UID00051B/UID00051H; and fixed the deterministic 28-definition/two-declaration owner/emitter contract.
  - Historical pre-callback generated one-class staging and provisional file-split statements are retained as dated history, not current source routing.
- 2026-08-15 B001 UID0000KA Gate 2A repair:
  - Corrected UID0003EP formal CPP closure, replaced stale active child/aggregate blockers with implemented source-ready dispositions, and refreshed the exact generated 28-definition/two-declaration closure. Historical no-function/no-xref and rejected-route evidence remains intact.
- 2026-08-15 B001 UID0000KA inherited-bounds source-identity repair:
  - Rebound every InventoryPane/InventoryPane2 `+0x44` bounds use to declared protected `GrafPort::m_visibleBounds`, documented the complete inheritance/header route, and rejected the former undeclared pane-local alias without adding a duplicate field to either class.

- 2026-06-21 Rule 26 support sync from B006 [UID:0003U9][0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress](by-memory/0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress.md):
  - Added the shared `LocalInventorySlotRecord` dependency for legacy/new/alternate inventory panes and kept accessor ownership with `LivingObjectPane`.
- 2026-07-03 B012 accepted implementation callback:
  - Changed to: UID00031V now has formal first-draft `InventoryPane2::InventoryPane2()` C++ under this `InventoryPane.cpp` source route; the file page preserves the no direct raw-start function/xref/pointer-route caveat and still rejects a separate `InventoryPane2.cpp` split.
  - Evidence: MCP session `3a33af0b` reconfirmed the exact constructor bytes/padding, `PanelPane` base call, `InventoryPane2` vtable store triad, state-field clears, and no raw-start route.
- 2026-07-05 B004 accepted implementation callback:
  - Changed to: documented UID0003BW as class-owned but non-reconstructable/non-emitting compiler-generated `InventoryPane2` RTTI/vtable data under the existing `InventoryPane.cpp` route. No file score or source split change was made.
  - Evidence: current MCP session `supervisor_recovery_20260705` confirmed exact UID0003BW byte/dword contents, constructor/destructor/scalar vptr-store xrefs, slot targets, adjacent string boundary, pointer-scan negatives, no local UDT, and the generated empty-marker symptom.
- 2026-07-07 B004 accepted implementation callback:
  - Changed to: documented UID0003ER as class-owned but non-reconstructable/non-emitting compiler scalar-delete wrapper support under the existing `InventoryPane.cpp` source route. No file score, path, or source split change was made.
  - Evidence: MCP session `43ccf853` confirmed exact wrapper range/padding/signature, primary vtable and adjustor routes, vtable restores, cleanup/free/guard behavior, pointer-pattern negatives, UID00048P as the ordinary source destructor body, and the pre-repair generated empty-marker symptom.
- 2026-06-27 B013 accepted implementation callback:
  - Added repaired [UID:0002SU][0x004ee6b0-0x004ef510.InventoryPane2CoreAndHelpers](by-memory/0x004ee6b0-0x004ef510.InventoryPane2CoreAndHelpers.md), exact child method/helper list `00048P`-`00048X`, rejected a separate `InventoryPane2.cpp` split, and recorded PacketBuffer/socket sender APIs as dependencies only for the raw packet helpers.
- 2026-06-16 A002 source-quality refresh:
  - Before: `COMPLETION:85`, `CONFIDENCE:86`.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`.
  - Summary/evidence: live IDA MCP reconfirmed representative legacy, new, alternate, and scrollbar method anchors; proved the raw `InventoryPane2` constructor and scrollbar reset-helper no-function/no-xref blockers remain real; rechecked constructor/reset bytes and padding; verified NewInventoryPane and ScrollInventoryPane vtable refs and the one-caller scrollbar relationship; and kept the existing file-vs-companion source split decisions unchanged. No B-agent escalation is indicated by this routine source-root evidence pass.
- 2026-06-12 A003 Batch 248 tail split repair:
  - Before: `InventoryPane2` tail ownership was represented only by broad [UID:0002SV][0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor](by-memory/0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor.md), which remained mixed and parentless.
  - Changed to: the file now points to the exact source-bearing `InventoryPane2` tail children and treats the broad tail page as a non-emitting audit container.
  - Evidence: live IDA MCP reconfirmed exact helper/destructor boundaries, raw no-function helper spans, vtable-backed destructor adjustors, local switch tables, and the legacy/NewInventoryPane thunk split inside the broad historical range.

- 2026-06-10 A002 constructor-child/gate refresh:
  - Raised `82/82` to `84/84`, linked exact raw constructor child [UID:00031V][0x004ee650-0x004ee6a7.InventoryPane2RawConstructor](by-memory/0x004ee650-0x004ee6a7.InventoryPane2RawConstructor.md), and updated the `InventoryPane2` evidence/gate text so the constructor is no longer described as an unsplit unresolved boundary.
  - Evidence: live IDA MCP reconfirmed no function/xrefs at `0x004ee650`, exact constructor bytes through `0x004ee6a7`, `0xcc` padding before `0x004ee650` and before `0x004ee6b0`, and `InventoryPane2` vtable stores from the raw constructor, setup helper, and scalar deleting destructor. The file remains below `85/85` because the final old/new/alternate source split and many helper/field names are still provisional.
- 2026-06-02: Set `PROPOSED_RECONSTRUCTION_PATH` to `NexusTK/ui/inventory/` and raised `80/76` to `82/82`.
  - Before: the page text proposed `ui/inventory/`, but validator metadata had no projected path and confidence stayed below the parent-attachment threshold.
  - After: projected path and confidence now match the written source-placement evidence; [UID:0002SU][0x004ee6b0-0x004ef510.InventoryPane2CoreAndHelpers](by-memory/0x004ee6b0-0x004ef510.InventoryPane2CoreAndHelpers.md) and [UID:0002SV][0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor](by-memory/0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor.md) record the exact confirmed `InventoryPane2` method/helper children while preserving the unresolved constructor-start caveat and excluding the interleaved BackPane helper.
  - Evidence: [UID:00018J][0x004ea130-0x004efbb7.InventoryPanes](by-memory/0x004ea130-0x004efbb7.InventoryPanes.md) records IDA function inventory and source-split ownership; [UID:00025L][0x0061c7a4-0x0061c9c4.InventoryPaneReadOnlyData](by-memory/0x0061c7a4-0x0061c9c4.InventoryPaneReadOnlyData.md) records inventory vtables and resource strings; [UID:0002SU][0x004ee6b0-0x004ef510.InventoryPane2CoreAndHelpers](by-memory/0x004ee6b0-0x004ef510.InventoryPane2CoreAndHelpers.md) and [UID:0002SV][0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor](by-memory/0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor.md) split the alternate-pane method islands.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:80` and `CONFIDENCE:76`.
  - Summary/evidence: legacy/new/alternate inventory pane roles, scrollbar companion, behavior summary, representative IDA boundaries, and file-split guidance are documented; confidence is capped by exact legacy/new split, raw starts, and Wave3 data issues.
- 2026-06-11 A008 Batch 155 parent-gate refresh:
  - Raised `84/84` to `85/86` and documented that [UID:00006R][InventoryPane](by-class/InventoryPane.md) now clears the strict gate for direct attachment to this file root.
  - Evidence: live IDA MCP rechecked the legacy class boundaries, vtable store/restore xrefs, constructor fields, `InterfaceEfx` allocation, list/grid draw and hit-test geometry, drag opcode, tooltip opcode, and scalar-delete cleanup. The score stays below final audit because the new/alternate split and many helper/field names are still provisional.
