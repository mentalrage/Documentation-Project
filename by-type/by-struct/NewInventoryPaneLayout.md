*** UID:00054F | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000093 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# NewInventoryPane Layout
## Status

- Entity kind: exact non-duplicating object-layout support.
- Covered class: [UID:000093][NewInventoryPane](by-class/NewInventoryPane.md).
- Source root: [UID:0000LS][NewInventoryPane](by-file/NewInventoryPane.md).
- Total size: `0x158`, proved by allocation and constructor/cross-method access.
- Emission: blank here. The class formal H owns the real fields; this page documents offsets without emitting a duplicate struct.

## Exact Layout

| Offset | Size | Source-facing member | Evidence and role |
| ---: | ---: | --- | --- |
| `0x000` | `0xf8` | `PanelPane` base | inherited prefix |
| `0x0f8` | 1 | `m_scrollPosition` | signed current list/grid scroll position |
| `0x0f9` | 1 | `m_inventoryListCount` | active collapsed-list entry count |
| `0x0fa` | 2 | `m_reservedFA` | alignment/reserved bytes; no semantic claim |
| `0x0fc` | 4 | `m_viewMode` | list/grid enum |
| `0x100` | 4 | `m_unusedState` | storage is exact; current source role remains unproved |
| `0x104` | 4 | `m_listButtonState` | list control visual state |
| `0x108` | 4 | `m_gridButtonState` | grid control visual state |
| `0x10c` | 4 | `m_expandButtonState` | expand control visual state |
| `0x110` | 4 | `m_actionButtonState` | mix/action control visual state |
| `0x114` | 4 | `m_scrollPane` | owned ScrollInventoryPane pointer |
| `0x118` | 53 | `m_visibleInventorySlots` | one-based active-slot map, indexes 1..52 |
| `0x14d` | 1 | `m_hoverInventorySlot` | signed hover/drop target |
| `0x14e` | 1 | `m_selectedInventorySlot` | signed pressed/drag source |
| `0x14f` | 1 | `m_reserved14F` | natural alignment |
| `0x150` | 4 | `m_activeRepeatTimer` | active repeat-scroll timer id |
| `0x154` | 1 | `m_draggedSincePress` | drag transition flag |
| `0x155` | 1 | `m_expanded` | collapsed/expanded layout flag |
| `0x156` | 2 | `m_tailPadding` | tail alignment to `0x158` |

## Evidence And Constraints

- Constructor field writes, all 26 child bodies, three vtable views, and the exact `0x158` allocation agree on these offsets and widths.
- The four former aggregate button-state slots are individually named because paint/input cross-method evidence proves their roles.
- `m_unusedState` intentionally remains neutral. No current method proves a stronger original lexical identity.
- Do not emit this page as another type declaration, reorder fields, publicize companion private state, or replace proven roles with decompiler offsets.

## Score Rationale

- Completion `94`: exact size, base extent, every tail offset/width, source role or bounded unknown, and declaration owner are documented.
- Confidence `95`: allocator, constructor, cross-method reads/writes, and vtable/class evidence agree. Final compile/layout assertion retains the cap.
