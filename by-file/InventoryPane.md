*** UID:0000KA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# InventoryPane

## Status

- Confidence: strong for inventory UI module ownership, medium for exact legacy/new split.
- Proposed module folder: `ui/inventory/`
- Candidate files: `ui/inventory/InventoryPane.cpp`, `ui/inventory/NewInventoryPane.cpp`, and `ui/inventory/ScrollInventoryPane.cpp`
- Current generated sources: `class_InventoryPane.cpp`, `class_InventoryPane2.cpp`, `class_NewInventoryPane.cpp`, and `class_ScrollInventoryPane.cpp`.
- Evidence basis: Wave3 metadata and targeted IDA MCP boundary checks on 2026-05-23.

## Hypothesis

The item inventory panes form a coherent gameplay UI subsystem. They should not be grouped with generic control panes, item image libraries, or cash-shop item catalog code.

The likely original structure had separate source files for the legacy inventory and newer inventory panel:

```text
ui/inventory/InventoryPane.cpp
ui/inventory/NewInventoryPane.cpp
ui/inventory/ScrollInventoryPane.cpp
```

An alternate compact layout is a single `ui/inventory/InventoryPane.cpp` containing the old, alternate, and new variants plus the private scrollbar. The generated one-class files should be treated as reconstruction staging, not final original layout evidence.

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| `InventoryPane` | `0x004ea130-0x004efb41` | `class_InventoryPane.cpp` | Legacy item inventory pane with list/grid view, paging, item activation, drag packet, and tooltip message handling. |
| `NewInventoryPane` | `0x004eb420-0x004efbb6` | `class_NewInventoryPane.cpp` | Updated item inventory pane with scrollbar, list/grid layouts, tab buttons, hover, drag/drop, and compact/expanded state. |
| `InventoryPane2` | `0x004ee650-0x004efa94` | `class_InventoryPane2.cpp` | Alternate smaller inventory pane with dual list/grid layout and arrow buttons. |
| `ScrollInventoryPane` | `0x00563260-0x0056470c` | `class_ScrollInventoryPane.cpp` | Private/companion scrollbar used by the newer item inventory UI. |

## Behavior Summary

- Legacy inventory draws up to 15 entries per page in list or grid mode and responds to Page Up/Page Down.
- New inventory supports list and 3-column grid layouts, a child scrollbar, slot filtering, hover highlighting, drag/drop, context menu/right-click paths, sound stopping, and view-mode toggling.
- `InventoryPane2` appears to be an alternate compact visual style with fixed button rectangles and a 9-slot grid/list hit-test path.
- `ScrollInventoryPane` owns the EPF-backed scrollbar track, thumb, arrow regions, timer repeat, and highlight state.

## IDA MCP Evidence

Targeted checks on 2026-05-23 confirmed:

- `0x004ea130-0x004ea202`, `0x004ea2a0-0x004ea945`, `0x004ea9d0-0x004eac88`, and `0x004eac90-0x004eae02` for legacy inventory construction, paint, mouse, and message handling.
- `0x004eb420-0x004eb510`, `0x004ebb20-0x004ec913`, `0x004ecb50-0x004ed9c4`, and `0x004ee230-0x004ee3b7` for the updated inventory constructor, paint, mouse, and hit test.
- `0x004ee6f0-0x004eee5c`, `0x004eeee0-0x004ef27a`, and `0x004efa40-0x004efa95` for the alternate inventory render/mouse/delete paths.
- `0x00563260-0x00563301`, `0x005636a0-0x00563d80`, and `0x005640a0-0x00564327` for the item inventory scrollbar.

IDA reports no function at Wave3's `InventoryPane2::InventoryPane2` start `0x004ee650` and no function at `ScrollInventoryPane::ResetScrollState` start `0x005646b0`; both are tracked in [wave3_data_issues](../wave3_data_issues.md).

## File-Split Guidance

Use these working files for future migration planning:

```text
ui/inventory/InventoryPane.cpp
ui/inventory/NewInventoryPane.cpp
ui/inventory/ScrollInventoryPane.cpp
```

Keep [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md) separate. Item inventory and spell inventory share UI patterns and scrollbar code shape, but their data sources, activation paths, and input panes are different enough to justify separate original files.

## Cross-References

- [UID:00006R][InventoryPane](by-class/InventoryPane.md)
- [UID:00006S][InventoryPane2](by-class/InventoryPane2.md)
- [UID:000093][NewInventoryPane](by-class/NewInventoryPane.md)
- [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md)
- [UID:00018J][0x004ea130-0x004efbb7.InventoryPanes](by-memory/0x004ea130-0x004efbb7.InventoryPanes.md)
- [UID:0001GZ][0x00563260-0x0056470c.ScrollInventoryPane](by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md)
- [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:80` and `CONFIDENCE:76`.
  - Summary/evidence: legacy/new/alternate inventory pane roles, scrollbar companion, behavior summary, representative IDA boundaries, and file-split guidance are documented; confidence is capped by exact legacy/new split, raw starts, and Wave3 data issues.
