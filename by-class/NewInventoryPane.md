*** UID:000093 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# NewInventoryPane

## Status

- Confidence: strong for behavior, inventory-module placement, companion scrollbar ownership, and vtable/resource-data relationship; medium for final field names and source-quality class declaration.
- Likely source file: [UID:0000LS][NewInventoryPane](by-file/NewInventoryPane.md), under the [UID:0000KA][InventoryPane](by-file/InventoryPane.md) umbrella
- Address range: [UID:00018J][0x004ea130-0x004efbb7.InventoryPanes](by-memory/0x004ea130-0x004efbb7.InventoryPanes.md)
- Current recovered file: `source-3/simroot_v2/class_NewInventoryPane.cpp`

## Autogen Status

- Reconstructable: true; this is NexusTK-owned source class code and should be rebuilt as part of the item-inventory UI.
- Autogen parent: [UID:0000LS][NewInventoryPane](by-file/NewInventoryPane.md). The file page now has a projected `NexusTK/ui/inventory/` path and records the same IDA-backed constructor, paint, input, scrollbar, and vtable/resource evidence.
- C++ emission: none. The class declaration, exact fields, and final method names remain below the `95+` source-emission gate.

## Class Purpose

`NewInventoryPane` is the newer player item inventory pane. It owns an embedded [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md), builds filtered visible slot lists, supports list/grid layouts, paints item icons/names/counts/tab buttons, and handles hover, drag/drop, right-click context, scroll wheel, and view-mode toggling.

## Method Families

| Family | Representative methods | Role |
| --- | --- | --- |
| Lifecycle/layout | `NewInventoryPane`, `OnRefresh`, `OnResize`, `OnLayout`, `OnShow`, `ScalarDeletingDestructor` | Creates child scrollbar and keeps layout/visibility synchronized. |
| Slot model | `RebuildSlotList`, `TransformCoordinates`, `MapVisualToPhysicalSlot`, `HitTestSlot` | Maps visible slots to physical inventory slots and supports list/grid layouts. |
| Rendering | `OnPaint`, `GetButtonRect`, `GetSlotRect` | Draws slots, item icons, text, counts, and tab buttons. |
| Input | `OnKeyEvent`, `OnMouseEvent`, `OnScrollPositionChanged`, `ScrollToDirection` | Handles keyboard paging, mouse interactions, scrollbar sync, and repeat scrolling. |
| Audio/view mode | `StopSound`, `ToggleViewMode` | Stops item sound and toggles list/grid display. |

## Evidence Notes

- IDA MCP confirms `0x004eb420-0x004eb510`, `0x004ebb20-0x004ec913`, `0x004ecb50-0x004ed9c4`, and `0x004ee230-0x004ee3b7`.
- Wave3 notes describe a 344-byte `PanelPane`-derived object with scrollbar pointer at `0x114`, slot-map array around `0x118-0x14c`, hover slot at `0x14d`, and compact/expanded toggle byte around `0x155`.
- The class remains incomplete in Wave3 due to low automated grade, so method names are useful but not final for rename-heavy work.
- [UID:00018J][0x004ea130-0x004efbb7.InventoryPanes](by-memory/0x004ea130-0x004efbb7.InventoryPanes.md) records the exact inventory-pane function inventory, keeps BackPane packet helpers out of this class, and assigns the `0x004eb420-0x004ee595` subrange to `NewInventoryPane`.
- [UID:0001GZ][0x00563260-0x0056470c.ScrollInventoryPane](by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md) records that `NewInventoryPane::NewInventoryPane` is the only observed direct constructor caller for the owned scrollbar pane.
- [UID:00025L][0x0061c7a8-0x0061c9c8.InventoryPaneReadOnlyData](by-memory/0x0061c7a8-0x0061c9c8.InventoryPaneReadOnlyData.md) records the `NewInventoryPane` primary, secondary, and tertiary vtables at `0x0061c7e4`, `0x0061c834`, and `0x0061c864`.
- Fresh IDA MCP was unavailable on 2026-06-03, and `wave3.py inspect class NewInventoryPane` timed out. The score update is based on already written IDA-backed documentation, not new Wave3 output.

## Score Rationale

| Field | Value | Rationale |
| --- | --- | --- |
| Completion | `76` | Purpose, method families, source placement, owned scrollbar relationship, aggregate boundaries, and vtable/resource data are documented. Completion is capped by missing exact field layout, final method names, and source-quality class declaration. |
| Confidence | `80` | Multiple IDA-backed pages agree on the constructor/paint/input ranges, source folder, companion scrollbar ownership, and vtable data. Confidence remains at the attachment threshold because fresh IDA/Wave3 checks were unavailable and final field names are unresolved. |

## Cross-References

- [UID:0000LS][NewInventoryPane](by-file/NewInventoryPane.md)
- [UID:0000KA][InventoryPane](by-file/InventoryPane.md)
- [UID:00018J][0x004ea130-0x004efbb7.InventoryPanes](by-memory/0x004ea130-0x004efbb7.InventoryPanes.md)
- [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md)
- [UID:0001GZ][0x00563260-0x0056470c.ScrollInventoryPane](by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md)
- [UID:00025L][0x0061c7a8-0x0061c9c8.InventoryPaneReadOnlyData](by-memory/0x0061c7a8-0x0061c9c8.InventoryPaneReadOnlyData.md)

## Changes

- Before: completion/confidence metadata were `0/0` while the page already summarized class purpose, major method families, evidence, and cross-references.
- Changed to: `COMPLETION:72` and `CONFIDENCE:74`.
- Evidence: behavior, embedded scrollbar ownership, visible-slot model, rendering, input, and field-offset leads are documented; confidence remains medium because final method names, full field layout, and exact source split are not fully resolved.
- 2026-06-03 confidence and autogen pass:
  - Before: the page was scored `72/74` with blank reconstructable and parent metadata.
  - Changed to: `76/80`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000LS`, while leaving C++ blank.
  - Evidence: the [UID:00018J][0x004ea130-0x004efbb7.InventoryPanes](by-memory/0x004ea130-0x004efbb7.InventoryPanes.md) aggregate, [UID:0001GZ][0x00563260-0x0056470c.ScrollInventoryPane](by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md), and [UID:00025L][0x0061c7a8-0x0061c9c8.InventoryPaneReadOnlyData](by-memory/0x0061c7a8-0x0061c9c8.InventoryPaneReadOnlyData.md) support the class owner, source file, companion scrollbar, and vtable data; exact field names and final class declaration are still not source-emission ready.
