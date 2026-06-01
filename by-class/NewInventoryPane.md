*** UID:000093 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# NewInventoryPane

## Status

- Confidence: strong for behavior and inventory-module placement, medium for final file split.
- Likely source file: [UID:0000LS][NewInventoryPane](by-file/NewInventoryPane.md), under the [UID:0000KA][InventoryPane](by-file/InventoryPane.md) umbrella
- Address range: [UID:00018J][0x004ea130-0x004efbb7.InventoryPanes](by-memory/0x004ea130-0x004efbb7.InventoryPanes.md)
- Current recovered file: `source-3/simroot_v2/class_NewInventoryPane.cpp`

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

## Cross-References

- [UID:0000LS][NewInventoryPane](by-file/NewInventoryPane.md)
- [UID:0000KA][InventoryPane](by-file/InventoryPane.md)
- [UID:00018J][0x004ea130-0x004efbb7.InventoryPanes](by-memory/0x004ea130-0x004efbb7.InventoryPanes.md)
- [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md)

## Changes

- Before: completion/confidence metadata were `0/0` while the page already summarized class purpose, major method families, evidence, and cross-references.
- Changed to: `COMPLETION:72` and `CONFIDENCE:74`.
- Evidence: behavior, embedded scrollbar ownership, visible-slot model, rendering, input, and field-offset leads are documented; confidence remains medium because final method names, full field layout, and exact source split are not fully resolved.
